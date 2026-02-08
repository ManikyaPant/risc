// test.c - RV64I + Zba Test Program

void _exit_halt() {
    while(1) {
        asm volatile ("j ."); 
    }
}

int main() {
    // Basic Arithmetic: 15 + 25 = 40
    asm volatile (
        "addi x10, x0, 15\n"
        "addi x11, x0, 25\n"
        "add  x10, x10, x11\n"    // Result in x10
        ::: "x10", "x11"
    );

    // Store to memory
    asm volatile (
        "li   x11, 0x500\n"
        "sd   x10, 0(x11)\n"
        ::: "x11", "memory"
    );

    // Branch test (beq)
    asm volatile (
        "addi x16, x0, 10\n"
        "addi x17, x0, 10\n"
        "beq  x16, x17, branch_taken\n"
        "addi x18, x0, 99\n"
        "j    branch_done\n"
        "branch_taken:\n"
        "addi x18, x0, 42\n"
        "branch_done:\n"
        ::: "x16", "x17", "x18"
    );

    // Zba #1: sh1add (2-byte array indexing)
    asm volatile (
        "li   x14, 0x1000\n"
        "li   x15, 8\n"
        ".word 0x20E7A6B3\n"      // sh1add x13, x15, x14
        ::: "x13", "x14", "x15"
    );
    
    // Zba #2: sh2add (4-byte array indexing)
    asm volatile (
        "li   x14, 0x2000\n"
        "li   x15, 5\n"
        ".word 0x20E7C733\n"      // sh2add x14, x15, x14
        ::: "x14", "x15"
    );

    // Zba #3: sh3add (8-byte array indexing)
    asm volatile (
        "li   x19, 0x3000\n"
        "li   x20, 7\n"
        ".word 0x213A67B3\n"      // sh3add x15, x20, x19
        ::: "x15", "x19", "x20"
    );

    // Load from memory
    asm volatile (
        "li   x11, 0x500\n"
        "ld   x12, 0(x11)\n"
        ::: "x11", "x12", "memory"
    );

    _exit_halt();
    return 0;
}
