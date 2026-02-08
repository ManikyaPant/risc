.section .text.start
.global _start

_start:
    .option push
    .option norelax
    # Set stack pointer to the end of data memory
    la sp, _stack_top
    .option pop

    # Call main
    jal ra, main

_halt:
    # This instruction (0x0000006f) triggers the 'halt' signal in RTL
    j _halt