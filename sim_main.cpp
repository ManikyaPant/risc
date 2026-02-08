#include "Vtb_processor.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_processor* top = new Vtb_processor;

    // VCD waveform dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("processor.vcd");

    top->clk = 0;
    top->rst_n = 0;

    // Simulation loop
    while (!Verilated::gotFinish() && main_time < 200000) {
        if (main_time < 50) top->rst_n = 0;
        else top->rst_n = 1;

        if ((main_time % 5) == 0) top->clk = !top->clk;

        top->eval();
        tfp->dump(main_time);
        main_time++;
    }

    tfp->close();
    delete top;
    return 0;
}
