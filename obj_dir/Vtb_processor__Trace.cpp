// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_processor__Syms.h"


void Vtb_processor::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtb_processor::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+1,((0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])));
            tracep->chgQData(oldp+2,(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg),64);
            tracep->chgQData(oldp+4,((((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                        >> 0xbU)))),64);
            tracep->chgQData(oldp+6,((((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) 
                                        >> 0xbU)))),64);
            tracep->chgIData(oldp+8,(((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                       [(0x3fffU & 
                                         ((IData)(3U) 
                                          + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                       << 0x18U) | 
                                      ((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                        [(0x3fffU & 
                                          ((IData)(2U) 
                                           + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                        << 0x10U) | 
                                       ((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                         [(0x3fffU 
                                           & ((IData)(1U) 
                                              + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                         << 8U) | vlTOPp->tb_processor__DOT__imem__DOT__mem
                                        [(0x3fffU & (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg))])))),32);
            tracep->chgCData(oldp+9,((7U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])),3);
            tracep->chgBit(oldp+10,((1U & (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                           >> 3U))));
            tracep->chgWData(oldp+11,(vlTOPp->tb_processor__DOT__dut__DOT__if_id),96);
            tracep->chgWData(oldp+14,(vlTOPp->tb_processor__DOT__dut__DOT__id_ex),281);
            tracep->chgWData(oldp+23,(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem),139);
            tracep->chgWData(oldp+28,(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb),70);
            tracep->chgCData(oldp+31,((0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])),7);
            tracep->chgCData(oldp+32,((7U & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 0x14U) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 0xcU)))),3);
            tracep->chgCData(oldp+33,((0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                 << 7U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 0x19U)))),7);
            tracep->chgCData(oldp+34,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                 << 0x11U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 0xfU)))),5);
            tracep->chgCData(oldp+35,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                 << 0xcU) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 0x14U)))),5);
            tracep->chgCData(oldp+36,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                 << 0x19U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 7U)))),5);
            tracep->chgQData(oldp+37,(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen),64);
            tracep->chgQData(oldp+39,(vlTOPp->tb_processor__DOT__dut__DOT__alu_out),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+41,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[0]),64);
            tracep->chgQData(oldp+43,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[1]),64);
            tracep->chgQData(oldp+45,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[2]),64);
            tracep->chgQData(oldp+47,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[3]),64);
            tracep->chgQData(oldp+49,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[4]),64);
            tracep->chgQData(oldp+51,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[5]),64);
            tracep->chgQData(oldp+53,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[6]),64);
            tracep->chgQData(oldp+55,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[7]),64);
            tracep->chgQData(oldp+57,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[8]),64);
            tracep->chgQData(oldp+59,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[9]),64);
            tracep->chgQData(oldp+61,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[10]),64);
            tracep->chgQData(oldp+63,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[11]),64);
            tracep->chgQData(oldp+65,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[12]),64);
            tracep->chgQData(oldp+67,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[13]),64);
            tracep->chgQData(oldp+69,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[14]),64);
            tracep->chgQData(oldp+71,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[15]),64);
            tracep->chgQData(oldp+73,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[16]),64);
            tracep->chgQData(oldp+75,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[17]),64);
            tracep->chgQData(oldp+77,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[18]),64);
            tracep->chgQData(oldp+79,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[19]),64);
            tracep->chgQData(oldp+81,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[20]),64);
            tracep->chgQData(oldp+83,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[21]),64);
            tracep->chgQData(oldp+85,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[22]),64);
            tracep->chgQData(oldp+87,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[23]),64);
            tracep->chgQData(oldp+89,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[24]),64);
            tracep->chgQData(oldp+91,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[25]),64);
            tracep->chgQData(oldp+93,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[26]),64);
            tracep->chgQData(oldp+95,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[27]),64);
            tracep->chgQData(oldp+97,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[28]),64);
            tracep->chgQData(oldp+99,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[29]),64);
            tracep->chgQData(oldp+101,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[30]),64);
            tracep->chgQData(oldp+103,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[31]),64);
        }
        tracep->chgBit(oldp+105,(vlTOPp->clk));
        tracep->chgBit(oldp+106,(vlTOPp->rst_n));
        tracep->chgQData(oldp+107,(vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                   [(0x1ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                << 0x12U) 
                                               | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                  >> 0xeU)))]),64);
        tracep->chgIData(oldp+109,(vlTOPp->tb_processor__DOT__halt_counter),32);
        tracep->chgIData(oldp+110,(vlTOPp->tb_processor__DOT__unnamedblk1__DOT__i),32);
    }
}

void Vtb_processor::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
