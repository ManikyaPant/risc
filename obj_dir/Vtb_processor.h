// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTB_PROCESSOR_H_
#define _VTB_PROCESSOR_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtb_processor__Syms;
class Vtb_processor_VerilatedVcd;


//----------

VL_MODULE(Vtb_processor) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ tb_processor__DOT__halt;
    IData/*31:0*/ tb_processor__DOT__halt_counter;
    IData/*31:0*/ tb_processor__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i;
    WData/*95:0*/ tb_processor__DOT__dut__DOT__if_id[3];
    WData/*280:0*/ tb_processor__DOT__dut__DOT__id_ex[9];
    WData/*138:0*/ tb_processor__DOT__dut__DOT__ex_mem[5];
    WData/*69:0*/ tb_processor__DOT__dut__DOT__mem_wb[3];
    QData/*63:0*/ tb_processor__DOT__dut__DOT__pc_reg;
    QData/*63:0*/ tb_processor__DOT__dut__DOT__imm_gen;
    QData/*63:0*/ tb_processor__DOT__dut__DOT__alu_out;
    QData/*63:0*/ tb_processor__DOT__dut__DOT__reg_file[32];
    CData/*7:0*/ tb_processor__DOT__imem__DOT__mem[16384];
    QData/*63:0*/ tb_processor__DOT__dmem__DOT__mem[512];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*4:0*/ __Vdlyvdim0__tb_processor__DOT__dut__DOT__reg_file__v0;
    CData/*0:0*/ __Vdlyvset__tb_processor__DOT__dut__DOT__reg_file__v0;
    CData/*0:0*/ __Vdlyvset__tb_processor__DOT__dmem__DOT__mem__v0;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst_n;
    SData/*8:0*/ __Vdlyvdim0__tb_processor__DOT__dmem__DOT__mem__v0;
    QData/*63:0*/ __Vdlyvval__tb_processor__DOT__dut__DOT__reg_file__v0;
    QData/*63:0*/ __Vdlyvval__tb_processor__DOT__dmem__DOT__mem__v0;
    QData/*63:0*/ __Vdly__tb_processor__DOT__dut__DOT__pc_reg;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtb_processor__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtb_processor);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtb_processor(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtb_processor();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtb_processor__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtb_processor__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtb_processor__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtb_processor__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtb_processor__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtb_processor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtb_processor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vtb_processor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtb_processor__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtb_processor__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtb_processor__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtb_processor__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtb_processor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
