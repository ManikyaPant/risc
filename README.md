# RISC-V Processor Implementation

## Overview
5-stage pipelined RISC-V processor implementing RV64I base ISA with Zba extension.

## Features
- 5-stage pipeline: Fetch, Decode, Execute, Memory, Writeback
- Data forwarding for hazard mitigation
- Zba extension support: sh1add, sh2add, sh3add, add.uw
- Separate instruction and data memories

## Files
- `riscv_processor.sv` - Main processor module
- `instruction_memory.sv` - 16KB instruction memory
- `data_memory.sv` - 8KB data memory
- `tb_processor.sv` - Testbench
- `sim_main.cpp` - Verilator C++ wrapper
- `test.c` - Comprehensive test program
- `startup.s` - Assembly startup code
- `linker.ld` - Linker script
- `Makefile` - Build automation
- `build_commands.txt` - Toolchain reference

## Quick Start
```bash
make simulate
```

## Test Coverage
- Arithmetic operations (ADD, ADDI)
- Memory access (LD, SD)
- Branching (BEQ)
- Zba instructions (sh1add, sh2add, sh3add)

## Expected Results
- x10 = 0x28 (arithmetic test)
- x12 = 0x28 (memory load)
- x13 = 0x1010 (sh1add)
- x14 = 0x2014 (sh2add)
- x15 = 0x3038 (sh3add)
