`timescale 1ns/1ps

module riscv_processor (
    input  logic        clk,
    input  logic        rst_n,
    output logic [63:0] imem_addr,
    input  logic [31:0] imem_instr,
    output logic [63:0] dmem_addr,
    output logic [63:0] dmem_wdata,
    input  logic [63:0] dmem_rdata,
    output logic        dmem_we,
    output logic [2:0]  dmem_size,
    output logic        halt
);

    // Register File: x0 is hardwired to 0
    logic [63:0] reg_file [31:0];

    // --- Pipeline Register Definitions ---
    struct packed { 
        logic [63:0] pc; 
        logic [31:0] instr; 
    } if_id;

    struct packed { 
        logic [63:0] pc, rs1_data, rs2_data, imm; 
        logic [4:0]  rd; 
        logic [2:0]  funct3; 
        logic [6:0]  funct7, opcode; 
        logic        reg_write, mem_to_reg, mem_write;
    } id_ex;

    struct packed { 
        logic [63:0] alu_result, rs2_data; 
        logic [4:0]  rd; 
        logic        reg_write, mem_to_reg, mem_write; 
        logic [2:0]  funct3; 
    } ex_mem;

    struct packed { 
        logic [63:0] wb_data; 
        logic [4:0]  rd; 
        logic        reg_write; 
    } mem_wb;

    // --- 1. Fetch (IF) ---
    logic [63:0] pc_reg;
    assign imem_addr = pc_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) 
            pc_reg <= 64'h0;
        else if (!halt) 
            pc_reg <= pc_reg + 4;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) if_id <= '0;
        else if (!halt) if_id <= '{pc: pc_reg, instr: imem_instr};
    end

    // --- 2. Decode (ID) ---
    wire [6:0] dec_opcode = if_id.instr[6:0];
    wire [2:0] dec_funct3 = if_id.instr[14:12];
    wire [6:0] dec_funct7 = if_id.instr[31:25];
    wire [4:0] dec_rs1    = if_id.instr[19:15];
    wire [4:0] dec_rs2    = if_id.instr[24:20];
    wire [4:0] dec_rd     = if_id.instr[11:7];

    logic [63:0] imm_gen;
    always_comb begin
        case (dec_opcode)
            7'h13, 7'h03, 7'h67: imm_gen = {{52{if_id.instr[31]}}, if_id.instr[31:20]};
            7'h23:               imm_gen = {{52{if_id.instr[31]}}, if_id.instr[31:25], if_id.instr[11:7]};
            7'h37, 7'h17:        imm_gen = {{32{if_id.instr[31]}}, if_id.instr[31:12], 12'b0};
            default:             imm_gen = 64'h0;
        endcase
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) id_ex <= '0;
        else begin
            id_ex.pc       <= if_id.pc;
            id_ex.rs1_data <= (dec_rs1 == 0) ? 64'h0 : reg_file[dec_rs1];
            id_ex.rs2_data <= (dec_rs2 == 0) ? 64'h0 : reg_file[dec_rs2];
            id_ex.imm      <= imm_gen;
            id_ex.rd       <= dec_rd;
            id_ex.funct3   <= dec_funct3;
            id_ex.funct7   <= dec_funct7;
            id_ex.opcode   <= dec_opcode;
            // Control Signals
            id_ex.reg_write <= (dec_opcode == 7'h33 || dec_opcode == 7'h13 || 
                    dec_opcode == 7'h03 || dec_opcode == 7'h37 || 
                    dec_opcode == 7'h17 || // Added AUIPC support
                    dec_opcode == 7'h3b);
            id_ex.mem_to_reg <= (dec_opcode == 7'h03);
            id_ex.mem_write  <= (dec_opcode == 7'h23);
        end
    end

    // --- 3. Execute (EX) ---
    logic [63:0] alu_out;
    always_comb begin
        // Default: ALU is an adder
        alu_out = id_ex.rs1_data + ((id_ex.opcode == 7'h33 || id_ex.opcode == 7'h3b) ? id_ex.rs2_data : id_ex.imm);
        
        // Zba Extension Logic: SH1ADD, SH2ADD, SH3ADD
        if (id_ex.opcode == 7'h33 && id_ex.funct7 == 7'h10) begin
            case (id_ex.funct3)
                3'h2: alu_out = (id_ex.rs1_data << 1) + id_ex.rs2_data;
                3'h4: alu_out = (id_ex.rs1_data << 2) + id_ex.rs2_data;
                3'h6: alu_out = (id_ex.rs1_data << 3) + id_ex.rs2_data;
                default: alu_out = id_ex.rs1_data + id_ex.rs2_data;
            endcase
        end
        // Zba Extension Logic: ADD.UW
        else if (id_ex.opcode == 7'h3b && id_ex.funct7 == 7'h04 && id_ex.funct3 == 3'h0) begin
            alu_out = {32'b0, id_ex.rs1_data[31:0]} + id_ex.rs2_data;
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) ex_mem <= '0;
        else ex_mem <= '{alu_result: alu_out, rs2_data: id_ex.rs2_data, rd: id_ex.rd, 
                         reg_write: id_ex.reg_write, mem_to_reg: id_ex.mem_to_reg, 
                         mem_write: id_ex.mem_write, funct3: id_ex.funct3};
    end

    // --- 4. Memory (MEM) ---
    assign dmem_addr  = ex_mem.alu_result;
    assign dmem_wdata = ex_mem.rs2_data;
    assign dmem_we    = ex_mem.mem_write;
    assign dmem_size  = ex_mem.funct3;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) mem_wb <= '0;
        else mem_wb <= '{wb_data: (ex_mem.mem_to_reg ? dmem_rdata : ex_mem.alu_result), 
                         rd: ex_mem.rd, reg_write: ex_mem.reg_write};
    end

    // --- 5. Writeback (WB) ---
    always_ff @(posedge clk) begin
        if (mem_wb.reg_write && mem_wb.rd != 5'd0) begin
            reg_file[mem_wb.rd] <= mem_wb.wb_data;
        end
    end

    // Halt when jump-to-self is detected (Standard for bare-metal termination)
    assign halt = (if_id.instr == 32'h0000006f); 

endmodule