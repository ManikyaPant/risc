`timescale 1ns/1ps

module tb_processor(
    input logic clk,    
    input logic rst_n   
);
    wire halt;
    wire [63:0] imem_addr, dmem_addr, dmem_wdata, dmem_rdata;
    wire [31:0] instr;
    wire [2:0]  dmem_size;
    wire        dmem_we;
    integer halt_counter = 0;

    // Processor instantiation
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

    // Memory instantiation
    instruction_memory imem (.addr(imem_addr), .instr(instr));
    data_memory dmem (.clk(clk), .addr(dmem_addr), .wdata(dmem_wdata), 
                      .rdata(dmem_rdata), .we(dmem_we));

    // Verification
    always @(posedge clk) begin
        if (rst_n && dut.mem_wb.reg_write && dut.mem_wb.rd != 0) begin
            $display("WB: Time %0t | Reg[%0d] <= 0x%h", 
                     $time, dut.mem_wb.rd, dut.mem_wb.wb_data);
        end

        if (rst_n && halt) begin
            if (halt_counter < 10) begin
                $display("Halt detected. Draining pipeline... Cycle %0d", halt_counter);
                halt_counter <= halt_counter + 1;
            end else begin
                $display("\n================ REGISTER DUMP ================");
                for (int i = 0; i < 32; i++) begin
                    $write("x%02d: 0x%h  ", i, dut.reg_file[i]);
                    if (i % 4 == 3) $display(""); 
                end
                $display("===============================================\n");

                // Test results
                if (dut.reg_file[10] == 64'h28) 
                    $display("PASS: x10 = 0x28 (Arithmetic test)");
                
                if (dut.reg_file[12] == 64'h28) 
                    $display("PASS: x12 = 0x28 (Memory load test)");
                
                if (dut.reg_file[13] == 64'h1010) 
                    $display("PASS: x13 = 0x1010 (sh1add test)");
                
                if (dut.reg_file[14] == 64'h2014) 
                    $display("PASS: x14 = 0x2014 (sh2add test)");
                
                if (dut.reg_file[15] == 64'h3038) 
                    $display("PASS: x15 = 0x3038 (sh3add test)");

                $finish;
            end
        end
    end
endmodule
