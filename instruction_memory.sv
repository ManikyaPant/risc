`timescale 1ns/1ps
module instruction_memory (
    input  logic [63:0] addr,
    output logic [31:0] instr
);
    logic [7:0] mem [0:16383]; // 16KB Byte Memory

    initial begin
        for (int i = 0; i < 16384; i++) mem[i] = 8'h00; 
        if ($test$plusargs("IMEM_INIT") != 0) begin
            $display("Loading program.hex (Byte-Addressable)...");
            $readmemh("program.hex", mem);
        end
    end

    // Explicit Byte Reassembly (Little Endian)
    // We cast the index to 14 bits to silence Verilator warnings
    assign instr = { mem[14'(addr + 3)], 
                     mem[14'(addr + 2)], 
                     mem[14'(addr + 1)], 
                     mem[14'(addr)] };
endmodule