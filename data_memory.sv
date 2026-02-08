module data_memory (
    input  logic        clk,
    input  logic [63:0] addr,
    input  logic [63:0] wdata,
    output logic [63:0] rdata,
    input  logic        we
);
    logic [63:0] mem [0:1023];  // 8KB memory
    
    initial begin
        for (int i = 0; i < 1024; i++) mem[i] = 64'h0;
    end
    
    always_ff @(posedge clk) begin
        if (we) mem[addr[12:3]] <= wdata;
    end
    
    assign rdata = mem[addr[12:3]];
endmodule
