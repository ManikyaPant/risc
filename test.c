// test.c - Bare-metal RV64I + Zba
void _exit_halt() {
    while(1) {
        // Infinite loop to trigger the 'halt' logic in RTL
        asm volatile ("j ."); 
    }
}

int main() {
    // Basic Arithmetic
    int a = 15, b = 25;
    int c = a + b;

    // Memory Access
    volatile long* mem_ptr = (long*)0x500; 
    *mem_ptr = (long)c; 

    // Zba Instructions (hardcoded for toolchain compatibility)
    long z1, z3;
    long base = 0x1000, index = 8;

    // sh1add
    asm volatile (".word 0x20E7A6B3" : "=r"(z1) : "r"(index), "r"(base));
    // add.uw
    asm volatile (".word 0x08E787BB" : "=r"(z3) : "r"(index), "r"(base));

    _exit_halt(); // Ensure we never exit main
    return 0;
}