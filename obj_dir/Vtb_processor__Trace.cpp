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
            tracep->chgIData(oldp+1,(vlTOPp->tb_processor__DOT__dmem__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+2,((0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])));
            tracep->chgQData(oldp+3,(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg),64);
            tracep->chgQData(oldp+5,((((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                        >> 0xbU)))),64);
            tracep->chgQData(oldp+7,((((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) 
                                        >> 0xbU)))),64);
            tracep->chgIData(oldp+9,(((vlTOPp->tb_processor__DOT__imem__DOT__mem
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
            tracep->chgCData(oldp+10,((7U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])),3);
            tracep->chgBit(oldp+11,((1U & (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                           >> 3U))));
            tracep->chgQData(oldp+12,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[0]),64);
            tracep->chgQData(oldp+14,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[1]),64);
            tracep->chgQData(oldp+16,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[2]),64);
            tracep->chgQData(oldp+18,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[3]),64);
            tracep->chgQData(oldp+20,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[4]),64);
            tracep->chgQData(oldp+22,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[5]),64);
            tracep->chgQData(oldp+24,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[6]),64);
            tracep->chgQData(oldp+26,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[7]),64);
            tracep->chgQData(oldp+28,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[8]),64);
            tracep->chgQData(oldp+30,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[9]),64);
            tracep->chgQData(oldp+32,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[10]),64);
            tracep->chgQData(oldp+34,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[11]),64);
            tracep->chgQData(oldp+36,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[12]),64);
            tracep->chgQData(oldp+38,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[13]),64);
            tracep->chgQData(oldp+40,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[14]),64);
            tracep->chgQData(oldp+42,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[15]),64);
            tracep->chgQData(oldp+44,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[16]),64);
            tracep->chgQData(oldp+46,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[17]),64);
            tracep->chgQData(oldp+48,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[18]),64);
            tracep->chgQData(oldp+50,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[19]),64);
            tracep->chgQData(oldp+52,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[20]),64);
            tracep->chgQData(oldp+54,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[21]),64);
            tracep->chgQData(oldp+56,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[22]),64);
            tracep->chgQData(oldp+58,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[23]),64);
            tracep->chgQData(oldp+60,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[24]),64);
            tracep->chgQData(oldp+62,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[25]),64);
            tracep->chgQData(oldp+64,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[26]),64);
            tracep->chgQData(oldp+66,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[27]),64);
            tracep->chgQData(oldp+68,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[28]),64);
            tracep->chgQData(oldp+70,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[29]),64);
            tracep->chgQData(oldp+72,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[30]),64);
            tracep->chgQData(oldp+74,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[31]),64);
            tracep->chgWData(oldp+76,(vlTOPp->tb_processor__DOT__dut__DOT__if_id),96);
            tracep->chgWData(oldp+79,(vlTOPp->tb_processor__DOT__dut__DOT__id_ex),291);
            tracep->chgWData(oldp+89,(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem),139);
            tracep->chgWData(oldp+94,(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb),70);
            tracep->chgCData(oldp+97,((0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])),7);
            tracep->chgCData(oldp+98,((7U & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 0x14U) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 0xcU)))),3);
            tracep->chgCData(oldp+99,((0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                 << 7U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                   >> 0x19U)))),7);
            tracep->chgCData(oldp+100,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0xfU)))),5);
            tracep->chgCData(oldp+101,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0xcU) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 0x14U)))),5);
            tracep->chgCData(oldp+102,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                                  << 0x19U) 
                                                 | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                    >> 7U)))),5);
            tracep->chgBit(oldp+103,((0x6fU == (0x7fU 
                                                & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))));
            tracep->chgQData(oldp+104,(vlTOPp->tb_processor__DOT__dut__DOT__jal_imm),64);
            tracep->chgQData(oldp+106,(((((QData)((IData)(
                                                          vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U]))) 
                                        + vlTOPp->tb_processor__DOT__dut__DOT__jal_imm)),64);
            tracep->chgQData(oldp+108,(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen),64);
            tracep->chgQData(oldp+110,(vlTOPp->tb_processor__DOT__dut__DOT__alu_in1),64);
            tracep->chgQData(oldp+112,(vlTOPp->tb_processor__DOT__dut__DOT__alu_in2),64);
            tracep->chgQData(oldp+114,(vlTOPp->tb_processor__DOT__dut__DOT__alu_out),64);
            tracep->chgQData(oldp+116,(vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk1__DOT__op2_val),64);
        }
        tracep->chgBit(oldp+118,(vlTOPp->clk));
        tracep->chgBit(oldp+119,(vlTOPp->rst_n));
        tracep->chgQData(oldp+120,(vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                   [(0x3ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                << 0x12U) 
                                               | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                  >> 0xeU)))]),64);
        tracep->chgIData(oldp+122,(vlTOPp->tb_processor__DOT__halt_counter),32);
        tracep->chgIData(oldp+123,(vlTOPp->tb_processor__DOT__unnamedblk1__DOT__i),32);
        tracep->chgIData(oldp+124,(vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk2__DOT__i),32);
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
    }
}
