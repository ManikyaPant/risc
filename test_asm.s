.section .text
.global _start

_start:
    # --- Basic Integer Tests ---
    li x1, 10              # x1 = 10 (0xA)
    li x2, 20              # x2 = 20 (0x14)
    add x3, x1, x2         # x3 = 30 (0x1E)
    
    # --- Immediate Tests ---
    addi x4, x1, 5         # x4 = 15 (0xF)
    
    # --- Zba Extension Tests (SHxADD) ---
    # Formula: rd = rs2 + (rs1 << shift)
    
    # SH1ADD: x5 = 20 + (10 << 1) = 20 + 20 = 40
    .word 0x202122B3       # SH1ADD x5, x1, x2
    
    # SH2ADD: x6 = 20 + (10 << 2) = 20 + 40 = 60
    .word 0x20214333       # SH2ADD x6, x1, x2
    
    # SH3ADD: x7 = 20 + (10 << 3) = 20 + 80 = 100
    .word 0x202163B3       # SH3ADD x7, x1, x2

    # --- Halt Condition ---
loop:
    j loop                 # Infinite jump to self (Halt condition for DUT)