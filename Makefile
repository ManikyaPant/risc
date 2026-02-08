VERILATOR = verilator
VFLAGS = --cc --exe --build -j 4 --trace --timescale 1ns/1ps -Wall \
         -Wno-UNUSED -Wno-UNDRIVEN -Wno-PINCONNECTEMPTY -Wno-SYNCASYNCNET \
         -Wno-CASEINCOMPLETE -Wno-WIDTH

simulate: clean
	riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 -ffreestanding -nostdlib \
		-static -Wl,-T,linker.ld startup.s test.c -o test.elf
	
	riscv64-unknown-elf-objcopy -O verilog --verilog-data-width=1 test.elf program.hex
	
	$(VERILATOR) $(VFLAGS) riscv_processor.sv instruction_memory.sv data_memory.sv \
		tb_processor.sv sim_main.cpp --top-module tb_processor
	./obj_dir/Vtb_processor +IMEM_INIT

clean:
	rm -rf obj_dir *.o *.elf *.hex *.vcd test.s
