.section .text.start
.global _start

_start:
    .option push
    .option norelax
    la sp, _stack_top
    .option pop

    jal ra, main

_halt:
    j _halt
