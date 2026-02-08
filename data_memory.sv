module data_memory (
    input  logic        clk,
    input  logic [63:0] addr,
    input  logic [63:0] wdata,
    output logic [63:0] rdata,
    input  logic        we
);
    logic [63:0] mem [0:511];
    always_ff @(posedge clk) if (we) mem[addr[11:3]] <= wdata;
    assign rdata = mem[addr[11:3]];
endmodule