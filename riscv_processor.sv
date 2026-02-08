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

    logic [63:0] reg_file [31:0];

    // Pipeline Registers
    struct packed { 
        logic [63:0] pc; 
        logic [31:0] instr; 
    } if_id;
    
    struct packed { 
        logic [63:0] pc, rs1_data, rs2_data, imm; 
        logic [4:0]  rs1, rs2, rd;
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

    // Decode signals
    wire [6:0] dec_opcode = if_id.instr[6:0];
    wire [2:0] dec_funct3 = if_id.instr[14:12];
    wire [6:0] dec_funct7 = if_id.instr[31:25];
    wire [4:0] dec_rs1    = if_id.instr[19:15];
    wire [4:0] dec_rs2    = if_id.instr[24:20];
    wire [4:0] dec_rd     = if_id.instr[11:7];

    // Jump detection
    wire is_jal  = (dec_opcode == 7'h6F); 
    wire [63:0] jal_imm = {{44{if_id.instr[31]}}, if_id.instr[19:12], 
                           if_id.instr[20], if_id.instr[30:21], 1'b0};
    wire [63:0] jump_target = if_id.pc + jal_imm;

    // Stage 1: Fetch
    logic [63:0] pc_reg;
    assign imem_addr = pc_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) pc_reg <= 64'h0;
        else if (is_jal) pc_reg <= jump_target;
        else if (!halt) pc_reg <= pc_reg + 4;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) if_id <= '0;
        else if (is_jal) if_id <= '0;
        else if (!halt) if_id <= '{pc: pc_reg, instr: imem_instr};
    end

    // Stage 2: Decode
    logic [63:0] imm_gen;
    always_comb begin
        case (dec_opcode)
            7'h13, 7'h03, 7'h67: imm_gen = {{52{if_id.instr[31]}}, if_id.instr[31:20]};
            7'h23:               imm_gen = {{52{if_id.instr[31]}}, if_id.instr[31:25], if_id.instr[11:7]};
            7'h37, 7'h17:        imm_gen = {{32{if_id.instr[31]}}, if_id.instr[31:12], 12'b0};
            7'h6F:               imm_gen = jal_imm;
            default:             imm_gen = 64'h0;
        endcase
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) id_ex <= '0;
        else if (is_jal) id_ex <= '0;
        else begin
            id_ex.pc       <= if_id.pc;
            id_ex.rs1_data <= (dec_rs1 == 0) ? 64'h0 : reg_file[dec_rs1];
            id_ex.rs2_data <= (dec_rs2 == 0) ? 64'h0 : reg_file[dec_rs2];
            id_ex.imm      <= imm_gen;
            id_ex.rs1      <= dec_rs1;
            id_ex.rs2      <= dec_rs2;
            id_ex.rd       <= dec_rd;
            id_ex.funct3   <= dec_funct3;
            id_ex.funct7   <= dec_funct7;
            id_ex.opcode   <= dec_opcode;
            id_ex.reg_write  <= (dec_opcode == 7'h33 || dec_opcode == 7'h13 || 
                                 dec_opcode == 7'h03 || dec_opcode == 7'h37 || 
                                 dec_opcode == 7'h17 || dec_opcode == 7'h6F || 
                                 dec_opcode == 7'h3b);
            id_ex.mem_to_reg <= (dec_opcode == 7'h03);
            id_ex.mem_write  <= (dec_opcode == 7'h23);
        end
    end

    // Stage 3: Execute (with forwarding)
    logic [63:0] alu_in1, alu_in2;
    
    always_comb begin
        // Forwarding for input 1
        if (ex_mem.reg_write && ex_mem.rd != 0 && ex_mem.rd == id_ex.rs1)
            alu_in1 = ex_mem.alu_result;
        else if (mem_wb.reg_write && mem_wb.rd != 0 && mem_wb.rd == id_ex.rs1)
            alu_in1 = mem_wb.wb_data;
        else
            alu_in1 = id_ex.rs1_data;

        // Forwarding for input 2
        if (ex_mem.reg_write && ex_mem.rd != 0 && ex_mem.rd == id_ex.rs2)
            alu_in2 = ex_mem.alu_result;
        else if (mem_wb.reg_write && mem_wb.rd != 0 && mem_wb.rd == id_ex.rs2)
            alu_in2 = mem_wb.wb_data;
        else
            alu_in2 = id_ex.rs2_data;
    end

    logic [63:0] alu_out;
    always_comb begin
        if (id_ex.opcode == 7'h6F) begin
            alu_out = id_ex.pc + 4;
        end else begin
            logic [63:0] op2_val = (id_ex.opcode == 7'h33 || id_ex.opcode == 7'h3b) ? 
                                   alu_in2 : id_ex.imm;
            
            // Zba extension support
            if (id_ex.opcode == 7'h33 && id_ex.funct7 == 7'h10) begin
                case (id_ex.funct3)
                    3'h2: alu_out = (alu_in1 << 1) + alu_in2;  // sh1add
                    3'h4: alu_out = (alu_in1 << 2) + alu_in2;  // sh2add
                    3'h6: alu_out = (alu_in1 << 3) + alu_in2;  // sh3add
                    default: alu_out = alu_in1 + op2_val;
                endcase
            end else if (id_ex.opcode == 7'h3b && id_ex.funct7 == 7'h04 && id_ex.funct3 == 3'h0) begin
                alu_out = {32'b0, alu_in1[31:0]} + alu_in2;  // add.uw
            end else begin
                alu_out = alu_in1 + op2_val;
            end
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) ex_mem <= '0;
        else ex_mem <= '{alu_result: alu_out, rs2_data: alu_in2, rd: id_ex.rd, 
                         reg_write: id_ex.reg_write, mem_to_reg: id_ex.mem_to_reg, 
                         mem_write: id_ex.mem_write, funct3: id_ex.funct3};
    end

    // Stage 4: Memory
    assign dmem_addr  = ex_mem.alu_result;
    assign dmem_wdata = ex_mem.rs2_data;
    assign dmem_we    = ex_mem.mem_write;
    assign dmem_size  = ex_mem.funct3;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) mem_wb <= '0;
        else mem_wb <= '{wb_data: (ex_mem.mem_to_reg ? dmem_rdata : ex_mem.alu_result), 
                         rd: ex_mem.rd, reg_write: ex_mem.reg_write};
    end

    // Stage 5: Writeback
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 32; i++) reg_file[i] <= 64'h0;
        end else begin
            if (mem_wb.reg_write && mem_wb.rd != 5'd0) 
                reg_file[mem_wb.rd] <= mem_wb.wb_data;
        end
    end

    assign halt = (if_id.instr == 32'h0000006f); 
endmodule
