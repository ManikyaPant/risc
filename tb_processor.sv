`timescale 1ns/1ps

module tb_processor(
    input logic clk,    
    input logic rst_n   
);
    // Signals
    wire halt;
    wire [63:0] imem_addr, dmem_addr, dmem_wdata, dmem_rdata;
    wire [31:0] instr;
    wire [2:0]  dmem_size;
    wire        dmem_we;
    integer halt_counter = 0;

    // Core Instantiation
    riscv_processor dut (
        .clk(clk),
        .rst_n(rst_n),
        .imem_addr(imem_addr),
        .imem_instr(instr),
        .dmem_addr(dmem_addr),
        .dmem_wdata(dmem_wdata),
        .dmem_rdata(dmem_rdata),
        .dmem_we(dmem_we),
        .dmem_size(dmem_size),
        .halt(halt)
    );

    // Memory Instantiation
    instruction_memory imem (.addr(imem_addr), .instr(instr));
    data_memory dmem (.clk(clk), .addr(dmem_addr), .wdata(dmem_wdata), .rdata(dmem_rdata), .we(dmem_we));

    // --- Verification Logic ---
    always @(posedge clk) begin
        if (rst_n && dut.mem_wb.reg_write && dut.mem_wb.rd != 0) begin
            $display("WB: Time %0t | Reg[%0d] <= 0x%h", $time, dut.mem_wb.rd, dut.mem_wb.wb_data);
        end

        if (rst_n && halt) begin
            if (halt_counter < 10) begin
                $display("Halt detected. Draining pipeline... Cycle %0d", halt_counter);
                halt_counter <= halt_counter + 1;
            end
            else begin
                $display("\n================ REGISTER DUMP ================");
                for (int i = 0; i < 32; i++) begin
                    $write("x%02d: 0x%h  ", i, dut.reg_file[i]);
                    if (i % 4 == 3) $display(""); 
                end
                $display("===============================================\n");

                // Check x15 (GCC's choice for the addition result)
                if (dut.reg_file[15] == 64'h28) 
                    $display("PASS: x15 = 40 (Addition Verified)");
                else 
                    $display("INFO: x15 = 0x%h (Expected 0x28 if using GCC default)", dut.reg_file[15]);

                // Check x13 (Zba Result)
                if (dut.reg_file[13] == 64'h1010) 
                    $display("PASS: x13 = 0x1010 (SH1ADD Verified)");
                else 
                    $display("FAIL: x13 = 0x%h (Expected 0x1010 - Check Forwarding!)", dut.reg_file[13]);

                $finish;
            end
        end
    end
endmodule