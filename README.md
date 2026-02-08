# RISC-V 64I-Zba Processor

A complete 5-stage pipelined RISC-V processor implementation supporting the RV64I base integer instruction set with the Zba (address generation) extension.

## Overview

This project implements a fully functional RISC-V processor with:
- **Architecture**: 5-stage pipeline (IF, ID, EX, MEM, WB)
- **ISA**: RV64I base + Zba extension
- **Features**: 
  - Forwarding for data hazards
  - Stalling for load-use hazards
  - Flushing for control hazards
  - 32 general-purpose 64-bit registers
  - Separate instruction and data memories

## Directory Structure

```
.
├── riscv_processor.sv       # Main processor module
├── instruction_memory.sv    # Instruction memory (ROM)
├── data_memory.sv          # Data memory (RAM)
├── tb_processor.sv         # Comprehensive testbench
├── test.c                  # C test program
├── startup.s               # Bare-metal startup code
├── linker.ld               # Linker script
├── Makefile                # Build automation
├── build_commands.txt      # Manual build commands reference
├── DESIGN_DOCUMENT.txt     # Detailed design documentation
└── README.md               # This file
```

## Quick Start

### Prerequisites

1. **RISC-V Toolchain**
   ```bash
   # Option 1: Pre-built toolchain
   # Download from: https://github.com/riscv-collab/riscv-gnu-toolchain/releases
   
   # Option 2: Build from source
   git clone https://github.com/riscv/riscv-gnu-toolchain
   cd riscv-gnu-toolchain
   ./configure --prefix=/opt/riscv --with-arch=rv64i --with-abi=lp64
   make
   ```

2. **Simulator** (choose one)
   ```bash
   # Icarus Verilog (recommended for beginners)
   sudo apt-get install iverilog gtkwave
   
   # ModelSim (commercial, better performance)
   # Download from Intel/Mentor Graphics
   
   # Verilator (fastest, open-source)
   sudo apt-get install verilator
   ```

### Build and Run

**IMPORTANT**: Most RISC-V toolchains don't support Zba extension yet. We provide an assembly test with pre-encoded Zba instructions that works with any rv64i toolchain.

```bash
# Build everything and run simulation (uses assembly test)
make all

# Or step-by-step:
make compile_asm  # Assemble test program
make hex          # Extract machine code
make disasm       # Generate disassembly  
make simulate     # Run simulation

# View waveforms
make wave
```

**Alternative (C version - requires Zba-capable toolchain):**
```bash
make compile      # This will fail without Zba support
make hex_c
make simulate
```

## Project Components

### 1. RTL Design

#### riscv_processor.sv
Main processor module implementing:
- 5-stage pipeline with forwarding
- RV64I instruction execution
- Zba extension support (SH1ADD, SH2ADD, SH3ADD, ADD.UW)
- Hazard detection and resolution

#### instruction_memory.sv
- 4KB instruction memory (configurable)
- Word-aligned read-only access
- Initialized from program.hex

#### data_memory.sv
- 4KB data memory (configurable)
- Byte/half-word/word/double-word access
- Sign extension for signed loads

### 2. Test Program

#### test.c
Comprehensive test program demonstrating:
- Basic arithmetic operations
- Memory load/store operations
- Branching and control flow
- **Zba extension usage**:
  - SH1ADD: Array indexing with 16-bit elements
  - SH2ADD: Array indexing with 32-bit elements
  - SH3ADD: Array indexing with 64-bit elements
  - ADD.UW: Zero-extension addition

### 3. Verification

#### tb_processor.sv
Self-checking testbench with:
- Clock and reset generation
- Memory initialization
- Register value verification
- Assertions for correctness
- Waveform generation
- Timeout detection

## Zba Extension Details

The Zba extension provides optimized address generation instructions:

### Instructions Implemented

1. **SH1ADD rd, rs1, rs2**
   ```
   rd = (rs1 << 1) + rs2
   Use: Indexing 16-bit arrays
   Encoding: funct7=0x20, funct3=0x1, opcode=0x33
   ```

2. **SH2ADD rd, rs1, rs2**
   ```
   rd = (rs1 << 2) + rs2
   Use: Indexing 32-bit arrays
   Encoding: funct7=0x20, funct3=0x4, opcode=0x33
   ```

3. **SH3ADD rd, rs1, rs2**
   ```
   rd = (rs1 << 3) + rs2
   Use: Indexing 64-bit arrays
   Encoding: funct7=0x20, funct3=0x6, opcode=0x33
   ```

4. **ADD.UW rd, rs1, rs2**
   ```
   rd = zero_extend(rs1[31:0]) + rs2
   Use: 32-bit unsigned addition to 64-bit
   Encoding: funct7=0x08, funct3=0x1, opcode=0x3B
   ```

### Example Usage

```c
// C code that generates Zba instructions
uint64_t array[100];
uint64_t index = 5;
uint64_t base = (uint64_t)array;

// This generates SH3ADD: addr = base + (index << 3)
uint64_t value = array[index];
```

## Pipeline Architecture

```
┌─────┐    ┌─────┐    ┌─────┐    ┌─────┐    ┌─────┐
│ IF  │ -> │ ID  │ -> │ EX  │ -> │ MEM │ -> │ WB  │
└─────┘    └─────┘    └─────┘    └─────┘    └─────┘
   │          │          │          │          │
   PC      Decode     ALU +      Memory    Register
  Incr    Register   Zba Logic   Access     Write
         File Read
```

### Hazard Handling

1. **Data Hazards**: Forwarding from EX/MEM and MEM/WB stages
2. **Load-Use Hazards**: 1-cycle stall
3. **Control Hazards**: 2-cycle flush on taken branches

## Testing

### Running Tests

```bash
# Run all tests
make all

# Check specific results
make disasm
grep "sh[123]add" test_disasm.txt
```

### Expected Results

The testbench performs self-checking verification:
- Register x1 = 0x0A (10 decimal)
- Register x2 = 0x14 (20 decimal)
- Register x3 = 0x1E (30 decimal, from ADD)
- Register x5 = 0x28 (40 decimal, from SH1ADD)
- Register x6 = 0x3C (60 decimal, from SH2ADD)
- Register x7 = 0x64 (100 decimal, from SH3ADD)

### Viewing Waveforms

```bash
make wave
# Opens GTKWave with processor.vcd
```

Key signals to observe:
- `pc_out`: Program counter
- `dut.registers[*]`: Register file contents
- `dut.if_id_inst`: Current instruction
- `dut.alu_result`: ALU output

## Build Commands Reference

See `build_commands.txt` for detailed manual compilation steps.

Quick reference:
```bash
# Compile to assembly
riscv64-unknown-elf-gcc -march=rv64i_zba -mabi=lp64 -O2 -S test.c -o test.s

# Assemble to object
riscv64-unknown-elf-as -march=rv64i_zba test.s -o test.o

# Link to ELF
riscv64-unknown-elf-ld -T linker.ld test.o -o test.elf

# Extract hex
riscv64-unknown-elf-objcopy -O verilog test.elf program.hex

# Disassemble
riscv64-unknown-elf-objdump -d test.elf > test_disasm.txt
```

## Design Documentation

See `DESIGN_DOCUMENT.txt` for:
- Detailed pipeline architecture
- Control signal descriptions
- Instruction encoding
- Zba implementation details
- Performance characteristics
- Design trade-offs

## Troubleshooting

### Common Issues

1. **Toolchain doesn't support Zba extension**
   - Error: `cc1: error: '-march=rv64i_zba': unsupported ISA subset 'z'`
   - Solution: Use the assembly version (default): `make all`
   - The test_asm.s file has Zba instructions pre-encoded

2. **No Zba instructions in output**
   - Solution: Increase optimization level `-O2` or `-O3`
   - Or use assembly version which has them pre-encoded
   - Check: `grep "sh[123]add" test_disasm.txt`

3. **Toolchain not found**
   - Solution: Add to PATH: `export PATH=/opt/riscv/bin:$PATH`
   - Verify: `riscv64-unknown-elf-gcc --version`

4. **Simulation fails**
   - Check: `make check` for syntax errors
   - Verify: `program.hex` exists and is not empty
   - Enable debug: Add `+define+DEBUG` to simulation

4. **Register mismatches**
   - Check disassembly for correct instruction encoding
   - Verify forwarding logic in waveforms
   - Check for pipeline stalls/flushes

## Performance

- **CPI**: ~1.2-1.5 (with hazards)
- **Pipeline Depth**: 5 stages
- **Frequency**: Depends on synthesis (typically 50-100 MHz on FPGA)
- **Throughput**: 1 instruction/cycle (ideal)

## Extensions

Possible enhancements:
- [ ] Add branch prediction
- [ ] Implement M extension (multiply/divide)
- [ ] Add cache memories
- [ ] Support interrupts and exceptions
- [ ] Implement CSR registers
- [ ] Add more Zba instructions (ADDUW, SLLI.UW)
- [ ] Performance counters

## References

- [RISC-V Specification](https://riscv.org/technical/specifications/)
- [Zba Extension Spec](https://github.com/riscv/riscv-bitmanip)
- [RISC-V Assembly Reference](https://github.com/riscv-non-isa/riscv-asm-manual)

## License

This is an educational project. Feel free to use and modify.

## Authors

Created for RISC-V Processor Design Challenge
