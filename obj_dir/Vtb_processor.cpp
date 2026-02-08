// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_processor.h for the primary calling header

#include "Vtb_processor.h"
#include "Vtb_processor__Syms.h"

//==========

void Vtb_processor::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_processor::eval\n"); );
    Vtb_processor__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb_processor.sv", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtb_processor::_eval_initial_loop(Vtb_processor__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb_processor.sv", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtb_processor::_sequent__TOP__1(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_sequent__TOP__1\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__tb_processor__DOT__dut__DOT__pc_reg 
        = vlTOPp->tb_processor__DOT__dut__DOT__pc_reg;
    if (vlTOPp->rst_n) {
        if ((0x6fU == (0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) {
            vlTOPp->__Vdly__tb_processor__DOT__dut__DOT__pc_reg 
                = ((((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                     << 0x20U) | (QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U]))) 
                   + vlTOPp->tb_processor__DOT__dut__DOT__jal_imm);
        } else {
            if ((0x6fU != vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])) {
                vlTOPp->__Vdly__tb_processor__DOT__dut__DOT__pc_reg 
                    = (4ULL + vlTOPp->tb_processor__DOT__dut__DOT__pc_reg);
            }
        }
    } else {
        vlTOPp->__Vdly__tb_processor__DOT__dut__DOT__pc_reg = 0ULL;
    }
}

VL_INLINE_OPT void Vtb_processor::_sequent__TOP__2(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_sequent__TOP__2\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvset__tb_processor__DOT__dmem__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__tb_processor__DOT__dut__DOT__reg_file__v0 = 0U;
    if ((8U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) {
        vlTOPp->__Vdlyvval__tb_processor__DOT__dmem__DOT__mem__v0 
            = (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) 
                                           >> 0xbU)));
        vlTOPp->__Vdlyvset__tb_processor__DOT__dmem__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__tb_processor__DOT__dmem__DOT__mem__v0 
            = (0x1ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                          << 0x12U) | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                       >> 0xeU)));
    }
    if ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
         & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                             << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                          >> 1U)))))) {
        vlTOPp->__Vdlyvval__tb_processor__DOT__dut__DOT__reg_file__v0 
            = (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U])) 
                << 0x3aU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U])) 
                              << 0x1aU) | ((QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U])) 
                                           >> 6U)));
        vlTOPp->__Vdlyvset__tb_processor__DOT__dut__DOT__reg_file__v0 = 1U;
        vlTOPp->__Vdlyvdim0__tb_processor__DOT__dut__DOT__reg_file__v0 
            = (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                         << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                      >> 1U)));
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->rst_n) & vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U]) 
                     & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                                         << 0x1fU) 
                                        | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                           >> 1U))))))) {
        VL_WRITEF("WB: Time %0t | Reg[%0#] <= 0x%x\n",
                  64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))),
                  5,(0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                               << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                            >> 1U))),
                  64,(((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U])) 
                       << 0x3aU) | (((QData)((IData)(
                                                     vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U])) 
                                     << 0x1aU) | ((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U])) 
                                                  >> 6U))));
    }
    if (((IData)(vlTOPp->rst_n) & (0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) {
        if (VL_LIKELY(VL_GTS_III(1,32,32, 0xaU, vlTOPp->tb_processor__DOT__halt_counter))) {
            VL_WRITEF("Halt detected. Draining pipeline... Cycle %0d\n",
                      32,vlTOPp->tb_processor__DOT__halt_counter);
            vlTOPp->tb_processor__DOT__halt_counter 
                = ((IData)(1U) + vlTOPp->tb_processor__DOT__halt_counter);
        } else {
            VL_WRITEF("\n================ REGISTER DUMP ================\n");
            vlTOPp->tb_processor__DOT__unnamedblk1__DOT__i = 0x20U;
            VL_WRITEF("x00: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0U]);
            VL_WRITEF("x01: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [1U]);
            VL_WRITEF("x02: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [2U]);
            VL_WRITEF("x03: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [3U]);
            VL_WRITEF("\n");
            VL_WRITEF("x04: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [4U]);
            VL_WRITEF("x05: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [5U]);
            VL_WRITEF("x06: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [6U]);
            VL_WRITEF("x07: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [7U]);
            VL_WRITEF("\n");
            VL_WRITEF("x08: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [8U]);
            VL_WRITEF("x09: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [9U]);
            VL_WRITEF("x10: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xaU]);
            VL_WRITEF("x11: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xbU]);
            VL_WRITEF("\n");
            VL_WRITEF("x12: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xcU]);
            VL_WRITEF("x13: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xdU]);
            VL_WRITEF("x14: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xeU]);
            VL_WRITEF("x15: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0xfU]);
            VL_WRITEF("\n");
            VL_WRITEF("x16: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x10U]);
            VL_WRITEF("x17: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x11U]);
            VL_WRITEF("x18: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x12U]);
            VL_WRITEF("x19: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x13U]);
            VL_WRITEF("\n");
            VL_WRITEF("x20: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x14U]);
            VL_WRITEF("x21: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x15U]);
            VL_WRITEF("x22: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x16U]);
            VL_WRITEF("x23: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x17U]);
            VL_WRITEF("\n");
            VL_WRITEF("x24: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x18U]);
            VL_WRITEF("x25: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x19U]);
            VL_WRITEF("x26: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1aU]);
            VL_WRITEF("x27: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1bU]);
            VL_WRITEF("\n");
            VL_WRITEF("x28: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1cU]);
            VL_WRITEF("x29: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1dU]);
            VL_WRITEF("x30: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1eU]);
            VL_WRITEF("x31: 0x%x  ",64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                      [0x1fU]);
            VL_WRITEF("\n===============================================\n\n");
            if ((0x28ULL == vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                 [0xfU])) {
                VL_WRITEF("PASS: x15 = 40 (Addition Verified)\n");
            } else {
                VL_WRITEF("INFO: x15 = 0x%x (Expected 0x28 if using GCC default)\n",
                          64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                          [0xfU]);
            }
            if ((0x1010ULL == vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                 [0xdU])) {
                VL_WRITEF("PASS: x13 = 0x1010 (SH1ADD Verified)\n");
            } else {
                VL_WRITEF("FAIL: x13 = 0x%x (Expected 0x1010 - Check Forwarding!)\n",
                          64,vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                          [0xdU]);
            }
            VL_FINISH_MT("tb_processor.sv", 64, "");
        }
    }
}

VL_INLINE_OPT void Vtb_processor::_sequent__TOP__5(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_sequent__TOP__5\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp4[3];
    // Body
    __Vtemp4[1U] = ((0x3fU & ((IData)(((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])
                                        ? vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                       [(0x1ffU & (
                                                   (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                    << 0x12U) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                      >> 0xeU)))]
                                        : (((QData)((IData)(
                                                            vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                            << 0x35U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                               << 0x15U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                                 >> 0xbU))))) 
                              >> 0x1aU)) | (0xffffffc0U 
                                            & ((IData)(
                                                       (((0x10U 
                                                          & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])
                                                          ? 
                                                         vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                                         [
                                                         (0x1ffU 
                                                          & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                              << 0x12U) 
                                                             | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                                >> 0xeU)))]
                                                          : 
                                                         (((QData)((IData)(
                                                                           vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                                           << 0x35U) 
                                                          | (((QData)((IData)(
                                                                              vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                                              << 0x15U) 
                                                             | ((QData)((IData)(
                                                                                vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                                                >> 0xbU)))) 
                                                        >> 0x20U)) 
                                               << 6U)));
    if (vlTOPp->rst_n) {
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
            = ((0xffffffc0U & ((IData)(((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])
                                         ? vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                        [(0x1ffU & 
                                          ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                            << 0x12U) 
                                           | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                              >> 0xeU)))]
                                         : (((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                             << 0x35U) 
                                            | (((QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                                << 0x15U) 
                                               | ((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                                  >> 0xbU))))) 
                               << 6U)) | (0x3fU & (
                                                   (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
                                                    << 0x1bU) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                                      >> 5U))));
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
            = __Vtemp4[1U];
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U] 
            = (0x3fU & ((IData)((((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])
                                   ? vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                  [(0x1ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                               << 0x12U) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                 >> 0xeU)))]
                                   : (((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                        >> 0xbU)))) 
                                 >> 0x20U)) >> 0x1aU));
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
            = ((0xfffff800U & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__alu_in2) 
                               << 0xbU)) | ((0x7c0U 
                                             & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                 << 0x12U) 
                                                | (0x3ffc0U 
                                                   & (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                      >> 0xeU)))) 
                                            | ((0x20U 
                                                & (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                   << 3U)) 
                                               | ((0x10U 
                                                   & (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                      << 3U)) 
                                                  | ((8U 
                                                      & (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                         << 3U)) 
                                                     | (7U 
                                                        & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                            << 0xfU) 
                                                           | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                              >> 0x11U))))))));
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
            = ((0x7ffU & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__alu_in2) 
                          >> 0x15U)) | (0xfffff800U 
                                        & ((IData)(
                                                   (vlTOPp->tb_processor__DOT__dut__DOT__alu_in2 
                                                    >> 0x20U)) 
                                           << 0xbU)));
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
            = ((0x7ffU & ((IData)((vlTOPp->tb_processor__DOT__dut__DOT__alu_in2 
                                   >> 0x20U)) >> 0x15U)) 
               | (0xfffff800U & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__alu_out) 
                                 << 0xbU)));
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
            = ((0x7ffU & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__alu_out) 
                          >> 0x15U)) | (0xfffff800U 
                                        & ((IData)(
                                                   (vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
                                                    >> 0x20U)) 
                                           << 0xbU)));
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U] 
            = (0x7ffU & ((IData)((vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
                                  >> 0x20U)) >> 0x15U));
    } else {
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U] = 0U;
    }
    if (vlTOPp->rst_n) {
        if ((0x6fU == (0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) {
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[8U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[9U] = 0U;
        } else {
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U] 
                = ((7U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U]) 
                   | (0xfffffff8U & ((IData)((((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U])))) 
                                     << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[8U] 
                = ((7U & ((IData)((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U])))) 
                          >> 0x1dU)) | (0xfffffff8U 
                                        & ((IData)(
                                                   ((((QData)((IData)(
                                                                      vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U]))) 
                                                    >> 0x20U)) 
                                           << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[9U] 
                = (7U & ((IData)(((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U]))) 
                                  >> 0x20U)) >> 0x1dU));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U] 
                = ((7U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U]) 
                   | (0xfffffff8U & ((IData)(((0U == 
                                               (0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                      >> 0xfU))))
                                               ? 0ULL
                                               : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                              [(0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                      >> 0xfU)))])) 
                                     << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U] 
                = ((7U & ((IData)(((0U == (0x1fU & 
                                           ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                             << 0x11U) 
                                            | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                               >> 0xfU))))
                                    ? 0ULL : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                   [(0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 0x11U) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 0xfU)))])) 
                          >> 0x1dU)) | (0xfffffff8U 
                                        & ((IData)(
                                                   (((0U 
                                                      == 
                                                      (0x1fU 
                                                       & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                           << 0x11U) 
                                                          | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                             >> 0xfU))))
                                                      ? 0ULL
                                                      : 
                                                     vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                                     [
                                                     (0x1fU 
                                                      & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                          << 0x11U) 
                                                         | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                            >> 0xfU)))]) 
                                                    >> 0x20U)) 
                                           << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U] 
                = ((0xfffffff8U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U]) 
                   | (7U & ((IData)((((0U == (0x1fU 
                                              & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0xfU))))
                                       ? 0ULL : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                      [(0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0xfU)))]) 
                                     >> 0x20U)) >> 0x1dU)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U] 
                = ((7U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U]) 
                   | (0xfffffff8U & ((IData)(((0U == 
                                               (0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                      >> 0x14U))))
                                               ? 0ULL
                                               : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                              [(0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                      >> 0x14U)))])) 
                                     << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U] 
                = ((7U & ((IData)(((0U == (0x1fU & 
                                           ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                             << 0xcU) 
                                            | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                               >> 0x14U))))
                                    ? 0ULL : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                   [(0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 0xcU) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 0x14U)))])) 
                          >> 0x1dU)) | (0xfffffff8U 
                                        & ((IData)(
                                                   (((0U 
                                                      == 
                                                      (0x1fU 
                                                       & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                           << 0xcU) 
                                                          | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                             >> 0x14U))))
                                                      ? 0ULL
                                                      : 
                                                     vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                                     [
                                                     (0x1fU 
                                                      & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                          << 0xcU) 
                                                         | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                            >> 0x14U)))]) 
                                                    >> 0x20U)) 
                                           << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U] 
                = ((0xfffffff8U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U]) 
                   | (7U & ((IData)((((0U == (0x1fU 
                                              & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0xcU) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0x14U))))
                                       ? 0ULL : vlTOPp->tb_processor__DOT__dut__DOT__reg_file
                                      [(0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0xcU) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0x14U)))]) 
                                     >> 0x20U)) >> 0x1dU)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                = ((7U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U]) 
                   | (0xfffffff8U & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen) 
                                     << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U] 
                = ((7U & ((IData)(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen) 
                          >> 0x1dU)) | (0xfffffff8U 
                                        & ((IData)(
                                                   (vlTOPp->tb_processor__DOT__dut__DOT__imm_gen 
                                                    >> 0x20U)) 
                                           << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U] 
                = ((0xfffffff8U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U]) 
                   | (7U & ((IData)((vlTOPp->tb_processor__DOT__dut__DOT__imm_gen 
                                     >> 0x20U)) >> 0x1dU)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0x3fffffffU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0xc0000000U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                     << 0xfU)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                = ((0xfffffff8U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U]) 
                   | (7U & ((0x3fff8000U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                            << 0xfU)) 
                            | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                               >> 0x11U))));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xc1ffffffU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0x3e000000U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                     << 5U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfe0fffffU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0x1f00000U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                    << 0xdU)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfff1ffffU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0xe0000U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                  << 5U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfffe03ffU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0x1fc00U & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                   << 0x11U) | (0x1fc00U 
                                                & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 0xfU)))));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfffffc07U & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0x3f8U & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                << 3U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfffffffbU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0xfffffffcU & ((((((((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])) 
                                           | (0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                          | (3U == 
                                             (0x7fU 
                                              & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                         | (0x37U == 
                                            (0x7fU 
                                             & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                        | (0x17U == 
                                           (0x7fU & 
                                            vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                       | (0x6fU == 
                                          (0x7fU & 
                                           vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                      | (0x3bU == (0x7fU 
                                                   & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))) 
                                     << 2U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfffffffdU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0xfffffffeU & ((3U == (0x7fU 
                                             & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])) 
                                     << 1U)));
            vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                = ((0xfffffffeU & vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U]) 
                   | (0x23U == (0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])));
        }
    } else {
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[8U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__id_ex[9U] = 0U;
    }
    vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 = 
        ((((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
            >> 5U) & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
                                       << 0x1aU) | 
                                      (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                       >> 6U))))) & 
          ((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
                      << 0x1aU) | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                   >> 6U))) == (0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                    << 2U) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                      >> 0x1eU)))))
          ? (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
              << 0x35U) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                            << 0x15U) | ((QData)((IData)(
                                                         vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                         >> 0xbU)))
          : (((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
               & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                                   << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                                >> 1U))))) 
              & ((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                            << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                         >> 1U))) == 
                 (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                            << 2U) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                      >> 0x1eU)))))
              ? (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U])) 
                  << 0x3aU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U])) 
                                << 0x1aU) | ((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U])) 
                                             >> 6U)))
              : (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U])) 
                  << 0x3dU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[6U])) 
                                << 0x1dU) | ((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                                             >> 3U)))));
    vlTOPp->tb_processor__DOT__dut__DOT__alu_in2 = 
        ((((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
            >> 5U) & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
                                       << 0x1aU) | 
                                      (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                       >> 6U))))) & 
          ((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U] 
                      << 0x1aU) | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                   >> 6U))) == (0x1fU 
                                                & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                                    << 7U) 
                                                   | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                      >> 0x19U)))))
          ? (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
              << 0x35U) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                            << 0x15U) | ((QData)((IData)(
                                                         vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                         >> 0xbU)))
          : (((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
               & (0U != (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                                   << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                                >> 1U))))) 
              & ((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U] 
                            << 0x1fU) | (vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U] 
                                         >> 1U))) == 
                 (0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                            << 7U) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                      >> 0x19U)))))
              ? (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[2U])) 
                  << 0x3aU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[1U])) 
                                << 0x1aU) | ((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__mem_wb[0U])) 
                                             >> 6U)))
              : (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[5U])) 
                  << 0x3dU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[4U])) 
                                << 0x1dU) | ((QData)((IData)(
                                                             vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                                             >> 3U)))));
    if (vlTOPp->rst_n) {
        if (vlTOPp->tb_processor__DOT__dut__DOT__is_jal) {
            vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] = 0U;
            vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->tb_processor__DOT__halt)))) {
                vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                    = ((vlTOPp->tb_processor__DOT__imem__DOT__mem
                        [(0x3fffU & ((IData)(3U) + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                        << 0x18U) | ((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                      [(0x3fffU & ((IData)(2U) 
                                                   + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                      << 0x10U) | (
                                                   (vlTOPp->tb_processor__DOT__imem__DOT__mem
                                                    [
                                                    (0x3fffU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                                    << 8U) 
                                                   | vlTOPp->tb_processor__DOT__imem__DOT__mem
                                                   [
                                                   (0x3fffU 
                                                    & (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg))])));
                vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                    = (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg);
                vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U] 
                    = (IData)((vlTOPp->tb_processor__DOT__dut__DOT__pc_reg 
                               >> 0x20U));
            }
        }
    } else {
        vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] = 0U;
        vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U] = 0U;
    }
    if ((0x6fU == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                             << 0x1dU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                          >> 3U))))) {
        vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
            = (4ULL + (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[9U])) 
                        << 0x3dU) | (((QData)((IData)(
                                                      vlTOPp->tb_processor__DOT__dut__DOT__id_ex[8U])) 
                                      << 0x1dU) | ((QData)((IData)(
                                                                   vlTOPp->tb_processor__DOT__dut__DOT__id_ex[7U])) 
                                                   >> 3U))));
    } else {
        vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk1__DOT__op2_val 
            = (((0x33U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                     << 0x1dU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                  >> 3U)))) 
                | (0x3bU == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                       << 0x1dU) | 
                                      (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                       >> 3U))))) ? vlTOPp->tb_processor__DOT__dut__DOT__alu_in2
                : (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[3U])) 
                    << 0x3dU) | (((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__id_ex[2U])) 
                                  << 0x1dU) | ((QData)((IData)(
                                                               vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U])) 
                                               >> 3U))));
        vlTOPp->tb_processor__DOT__dut__DOT__alu_out 
            = (((0x33U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                     << 0x1dU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                  >> 3U)))) 
                & (0x10U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                       << 0x16U) | 
                                      (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                       >> 0xaU)))))
                ? ((2U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                  << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                              >> 0x11U))))
                    ? ((vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 
                        << 1U) + vlTOPp->tb_processor__DOT__dut__DOT__alu_in2)
                    : ((4U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                      << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                  >> 0x11U))))
                        ? ((vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 
                            << 2U) + vlTOPp->tb_processor__DOT__dut__DOT__alu_in2)
                        : ((6U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                          << 0xfU) 
                                         | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                            >> 0x11U))))
                            ? ((vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 
                                << 3U) + vlTOPp->tb_processor__DOT__dut__DOT__alu_in2)
                            : (vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 
                               + vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk1__DOT__op2_val))))
                : ((((0x3bU == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                          << 0x1dU) 
                                         | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                            >> 3U)))) 
                     & (4U == (0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                         << 0x16U) 
                                        | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                           >> 0xaU))))) 
                    & (0U == (7U & ((vlTOPp->tb_processor__DOT__dut__DOT__id_ex[1U] 
                                     << 0xfU) | (vlTOPp->tb_processor__DOT__dut__DOT__id_ex[0U] 
                                                 >> 0x11U)))))
                    ? ((QData)((IData)(vlTOPp->tb_processor__DOT__dut__DOT__alu_in1)) 
                       + vlTOPp->tb_processor__DOT__dut__DOT__alu_in2)
                    : (vlTOPp->tb_processor__DOT__dut__DOT__alu_in1 
                       + vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk1__DOT__op2_val)));
    }
    vlTOPp->tb_processor__DOT__dut__DOT__pc_reg = vlTOPp->__Vdly__tb_processor__DOT__dut__DOT__pc_reg;
    vlTOPp->tb_processor__DOT__dut__DOT__is_jal = (0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]));
    vlTOPp->tb_processor__DOT__halt = (0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]);
    vlTOPp->tb_processor__DOT__dut__DOT__jal_imm = 
        ((0xfffffffffff00000ULL & ((- (QData)((IData)(
                                                      (1U 
                                                       & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                          >> 0x1fU))))) 
                                   << 0x14U)) | (QData)((IData)(
                                                                ((0xff000U 
                                                                  & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]) 
                                                                 | ((0x800U 
                                                                     & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                        >> 9U)) 
                                                                    | (0x7feU 
                                                                       & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                           << 0xcU) 
                                                                          | (0xffeU 
                                                                             & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                                >> 0x14U)))))))));
    vlTOPp->tb_processor__DOT__dut__DOT__imm_gen = 
        ((0x40U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
          ? ((0x20U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
              ? ((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                  ? 0ULL : ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                             ? ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                 ? ((2U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                     ? ((1U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                         ? vlTOPp->tb_processor__DOT__dut__DOT__jal_imm
                                         : 0ULL) : 0ULL)
                                 : 0ULL) : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                             ? ((2U 
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
                                                                    (0xfffU 
                                                                     & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                         << 0xcU) 
                                                                        | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                           >> 0x14U))))))
                                                  : 0ULL)
                                                 : 0ULL)
                                             : 0ULL)))
              : 0ULL) : ((0x20U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                          ? ((0x10U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                              ? ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                  ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                             ? ((2U 
                                                 & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                  ? 
                                                 (((QData)((IData)(
                                                                   (- (IData)(
                                                                              (1U 
                                                                               & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                                >> 0x1fU)))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (0xfffff000U 
                                                                     & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))))
                                                  : 0ULL)
                                                 : 0ULL)
                                             : 0ULL))
                              : ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                  ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                             ? 0ULL
                                             : ((2U 
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
                                             ? ((2U 
                                                 & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                                  ? 
                                                 (((QData)((IData)(
                                                                   (- (IData)(
                                                                              (1U 
                                                                               & (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                                >> 0x1fU)))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (0xfffff000U 
                                                                     & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))))
                                                  : 0ULL)
                                                 : 0ULL)
                                             : ((2U 
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
                                                                    (0xfffU 
                                                                     & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                         << 0xcU) 
                                                                        | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                           >> 0x14U))))))
                                                  : 0ULL)
                                                 : 0ULL)))
                              : ((8U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                  ? 0ULL : ((4U & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])
                                             ? 0ULL
                                             : ((2U 
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
                                                                    (0xfffU 
                                                                     & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                                         << 0xcU) 
                                                                        | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                                           >> 0x14U))))))
                                                  : 0ULL)
                                                 : 0ULL))))));
}

VL_INLINE_OPT void Vtb_processor::_sequent__TOP__6(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_sequent__TOP__6\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__tb_processor__DOT__dmem__DOT__mem__v0) {
        vlTOPp->tb_processor__DOT__dmem__DOT__mem[vlTOPp->__Vdlyvdim0__tb_processor__DOT__dmem__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__tb_processor__DOT__dmem__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__tb_processor__DOT__dut__DOT__reg_file__v0) {
        vlTOPp->tb_processor__DOT__dut__DOT__reg_file[vlTOPp->__Vdlyvdim0__tb_processor__DOT__dut__DOT__reg_file__v0] 
            = vlTOPp->__Vdlyvval__tb_processor__DOT__dut__DOT__reg_file__v0;
    }
}

void Vtb_processor::_eval(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_eval\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

VL_INLINE_OPT QData Vtb_processor::_change_request(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_change_request\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtb_processor::_change_request_1(Vtb_processor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_change_request_1\n"); );
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtb_processor::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_processor::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
