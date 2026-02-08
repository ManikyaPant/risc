#include "Vtb_processor.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// Helper function for VCD time
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_processor* top = new Vtb_processor;

    // Enable Waveforms
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("processor.vcd");

    // Initialize Signals
    top->clk = 0;
    top->rst_n = 0; // Assert Reset initially

    // Simulation Loop
    while (!Verilated::gotFinish() && main_time < 200000) {
        
        // Reset Management: Hold Reset LOW for first 50 time units
        if (main_time < 50) {
            top->rst_n = 0;
        } else {
            top->rst_n = 1; // Release Reset
        }

        // Clock Generation (Toggle every 5 time units)
        if ((main_time % 5) == 0) {
            top->clk = !top->clk;
        }

        top->eval();          // Evaluate hardware
        tfp->dump(main_time); // Write to waveform file
        
        main_time++; // Advance time
    }

    tfp->close();
    delete top;
    return 0;
}