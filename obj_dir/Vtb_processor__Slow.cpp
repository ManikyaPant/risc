// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_processor.h for the primary calling header

#include "Vtb_processor.h"
#include "Vtb_processor__Syms.h"

//==========

VL_CTOR_IMP(Vtb_processor) {
    Vtb_processor__Syms* __restrict vlSymsp = __VlSymsp = new Vtb_processor__Syms(this, name());
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtb_processor::__Vconfigure(Vtb_processor__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vtb_processor::~Vtb_processor() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtb_processor::_initial__TOP__3(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_initial__TOP__3\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp3[3];
    // Body
    vlTOPp->tb_processor__DOT__halt_counter = 0U;
    vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x4000U, vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i)) {
        vlTOPp->tb_processor__DOT__imem__DOT__mem[(0x3fffU 
                                                   & vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i)] = 0U;
        vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i);
    }
    if (VL_UNLIKELY((0U != VL_TESTPLUSARGS_I("IMEM_INIT")))) {
        VL_WRITEF("Loading program.hex (Byte-Addressable)...\n");
        __Vtemp3[0U] = 0x2e686578U;
        __Vtemp3[1U] = 0x6772616dU;
        __Vtemp3[2U] = 0x70726fU;
        VL_READMEM_N(true, 8, 16384, 0, VL_CVT_PACK_STR_NW(3, __Vtemp3)
                     , vlTOPp->tb_processor__DOT__imem__DOT__mem
                     , 0, ~0ULL);
    }
}

void Vtb_processor::_settle__TOP__4(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_settle__TOP__4\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tb_processor__DOT__dut__DOT__alu_out = 
        ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
           << 0x27U) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                         << 7U) | ((QData)((IData)(
                                                   vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                   >> 0x19U))) + ((
                                                   (0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                         << 0x1dU) 
                                                        | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                           >> 3U)))) 
                                                   | (0x3bU 
                                                      == 
                                                      (0x7fU 
                                                       & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                           << 0x1dU) 
                                                          | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                             >> 3U)))))
                                                   ? 
                                                  (((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                                    << 0x27U) 
                                                   | (((QData)((IData)(
                                                                       vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                                       << 7U) 
                                                      | ((QData)((IData)(
                                                                         vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                                         >> 0x19U)))
                                                   : 
                                                  (((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                                    << 0x27U) 
                                                   | (((QData)((IData)(
                                                                       vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U])) 
                                                       << 7U) 
                                                      | ((QData)((IData)(
                                                                         vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U])) 
                                                         >> 0x19U)))));
    if (((0x33U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                              << 0x1dU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                           >> 3U)))) 
         & (0x10U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                << 0x16U) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                             >> 0xaU)))))) {
        vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
            = ((2U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                              << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                          >> 0x11U))))
                ? ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
                     << 0x28U) | (((QData)((IData)(
                                                   vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                                   << 8U) | (0xfffffffffeULL 
                                             & ((QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                                >> 0x18U)))) 
                   + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                       << 0x27U) | (((QData)((IData)(
                                                     vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                     << 7U) | ((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                               >> 0x19U))))
                : ((4U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                  << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                              >> 0x11U))))
                    ? ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
                         << 0x29U) | (((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                                       << 9U) | (0x1fffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                                    >> 0x17U)))) 
                       + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                           << 0x27U) | (((QData)((IData)(
                                                         vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                         << 7U) | ((QData)((IData)(
                                                                   vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                                   >> 0x19U))))
                    : ((6U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                      << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                  >> 0x11U))))
                        ? ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
                             << 0x2aU) | (((QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                                           << 0xaU) 
                                          | (0x3fffffffff8ULL 
                                             & ((QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                                >> 0x16U)))) 
                           + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                               << 0x27U) | (((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                             << 7U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                               >> 0x19U))))
                        : ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
                             << 0x27U) | (((QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                                           << 7U) | 
                                          ((QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                           >> 0x19U))) 
                           + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                               << 0x27U) | (((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                             << 7U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                               >> 0x19U)))))));
    } else {
        if ((((0x3bU == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                   << 0x1dU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                >> 3U)))) 
              & (4U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                  << 0x16U) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                               >> 0xaU))))) 
             & (0U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                              << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                          >> 0x11U)))))) {
            vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
                = ((QData)((IData)(((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U] 
                                     << 7U) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U] 
                                               >> 0x19U)))) 
                   + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                       << 0x27U) | (((QData)((IData)(
                                                     vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                     << 7U) | ((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                               >> 0x19U))));
        }
    }
    vlTOPp->tb_processor__DOT__dut__DOT__imm_gen = 
        ((0x40U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
          ? ((0x20U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
              ? ((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                  ? 0ULL : ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                             ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                        ? ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                            ? ((1U 
                                                & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                ? (
                                                   (0xfffffffffffff000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                              >> 0x1fU))))) 
                                                       << 0xcU)) 
                                                   | (QData)((IData)(
                                                                     (0xfffU 
                                                                      & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                          << 0xcU) 
                                                                         | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                            >> 0x14U))))))
                                                : 0ULL)
                                            : 0ULL)
                                        : 0ULL))) : 0ULL)
          : ((0x20U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
              ? ((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                  ? ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                      ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                 ? ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                     ? ((1U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                         ? (((QData)((IData)(
                                                             (- (IData)(
                                                                        (1U 
                                                                         & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                            >> 0x1fU)))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (0xfffff000U 
                                                               & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))))
                                         : 0ULL) : 0ULL)
                                 : 0ULL)) : ((8U & 
                                              vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                              ? 0ULL
                                              : ((4U 
                                                  & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                  ? 0ULL
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                    ? 
                                                   ((0xfffffffffffff000ULL 
                                                     & ((- (QData)((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                               >> 0x1fU))))) 
                                                        << 0xcU)) 
                                                    | (QData)((IData)(
                                                                      ((0xfe0U 
                                                                        & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                            << 0xcU) 
                                                                           | (0xfe0U 
                                                                              & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                                >> 0x14U)))) 
                                                                       | (0x1fU 
                                                                          & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                              << 0x19U) 
                                                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                                >> 7U)))))))
                                                    : 0ULL)
                                                   : 0ULL))))
              : ((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                  ? ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                      ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                 ? ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                     ? ((1U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                         ? (((QData)((IData)(
                                                             (- (IData)(
                                                                        (1U 
                                                                         & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                            >> 0x1fU)))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (0xfffff000U 
                                                               & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))))
                                         : 0ULL) : 0ULL)
                                 : ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                     ? ((1U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                         ? ((0xfffffffffffff000ULL 
                                             & ((- (QData)((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                       >> 0x1fU))))) 
                                                << 0xcU)) 
                                            | (QData)((IData)(
                                                              (0xfffU 
                                                               & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                   << 0xcU) 
                                                                  | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                     >> 0x14U))))))
                                         : 0ULL) : 0ULL)))
                  : ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                      ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                 ? 0ULL : ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                            ? ((1U 
                                                & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                ? (
                                                   (0xfffffffffffff000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                              >> 0x1fU))))) 
                                                       << 0xcU)) 
                                                   | (QData)((IData)(
                                                                     (0xfffU 
                                                                      & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                          << 0xcU) 
                                                                         | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                            >> 0x14U))))))
                                                : 0ULL)
                                            : 0ULL))))));
    vlTOPp->tb_processor__DOT__halt = (0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]);
}

void Vtb_processor::_eval_initial(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_eval_initial\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtb_processor::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::final\n"); );
    // Variables
    Vtb_processor__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtb_processor::_eval_settle(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_eval_settle\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtb_processor::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    tb_processor__DOT__halt = VL_RAND_RESET_I(1);
    tb_processor__DOT__halt_counter = VL_RAND_RESET_I(32);
    tb_processor__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            tb_processor__DOT__dut__DOT__reg_file[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    VL_RAND_RESET_W(96, tb_processor__DOT__dut__DOT__if_id);
    VL_RAND_RESET_W(281, tb_processor__DOT__dut__DOT__id_ex);
    VL_RAND_RESET_W(139, tb_processor__DOT__dut__DOT__ex_mem);
    VL_RAND_RESET_W(70, tb_processor__DOT__dut__DOT__mem_wb);
    tb_processor__DOT__dut__DOT__pc_reg = VL_RAND_RESET_Q(64);
    tb_processor__DOT__dut__DOT__imm_gen = VL_RAND_RESET_Q(64);
    tb_processor__DOT__dut__DOT__alu_out = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<16384; ++__Vi0) {
            tb_processor__DOT__imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<512; ++__Vi0) {
            tb_processor__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    __Vdlyvdim0__tb_processor__DOT__dut__DOT__reg_file__v0 = 0;
    __Vdlyvval__tb_processor__DOT__dut__DOT__reg_file__v0 = VL_RAND_RESET_Q(64);
    __Vdlyvset__tb_processor__DOT__dut__DOT__reg_file__v0 = 0;
    __Vdlyvdim0__tb_processor__DOT__dmem__DOT__mem__v0 = 0;
    __Vdlyvval__tb_processor__DOT__dmem__DOT__mem__v0 = VL_RAND_RESET_Q(64);
    __Vdlyvset__tb_processor__DOT__dmem__DOT__mem__v0 = 0;
    __Vdly__tb_processor__DOT__dut__DOT__pc_reg = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
