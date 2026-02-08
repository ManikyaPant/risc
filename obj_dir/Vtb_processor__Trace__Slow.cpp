// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_processor__Syms.h"


//======================

void Vtb_processor::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtb_processor::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtb_processor::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtb_processor::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtb_processor::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+119,"clk", false,-1);
        tracep->declBit(c+120,"rst_n", false,-1);
        tracep->declBit(c+119,"tb_processor clk", false,-1);
        tracep->declBit(c+120,"tb_processor rst_n", false,-1);
        tracep->declBit(c+3,"tb_processor halt", false,-1);
        tracep->declQuad(c+4,"tb_processor imem_addr", false,-1, 63,0);
        tracep->declQuad(c+6,"tb_processor dmem_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"tb_processor dmem_wdata", false,-1, 63,0);
        tracep->declQuad(c+121,"tb_processor dmem_rdata", false,-1, 63,0);
        tracep->declBus(c+10,"tb_processor instr", false,-1, 31,0);
        tracep->declBus(c+11,"tb_processor dmem_size", false,-1, 2,0);
        tracep->declBit(c+12,"tb_processor dmem_we", false,-1);
        tracep->declBus(c+123,"tb_processor halt_counter", false,-1, 31,0);
        tracep->declBus(c+124,"tb_processor unnamedblk1 i", false,-1, 31,0);
        tracep->declBit(c+119,"tb_processor dut clk", false,-1);
        tracep->declBit(c+120,"tb_processor dut rst_n", false,-1);
        tracep->declQuad(c+4,"tb_processor dut imem_addr", false,-1, 63,0);
        tracep->declBus(c+10,"tb_processor dut imem_instr", false,-1, 31,0);
        tracep->declQuad(c+6,"tb_processor dut dmem_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"tb_processor dut dmem_wdata", false,-1, 63,0);
        tracep->declQuad(c+121,"tb_processor dut dmem_rdata", false,-1, 63,0);
        tracep->declBit(c+12,"tb_processor dut dmem_we", false,-1);
        tracep->declBus(c+11,"tb_processor dut dmem_size", false,-1, 2,0);
        tracep->declBit(c+3,"tb_processor dut halt", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+13+i*2,"tb_processor dut reg_file", true,(i+0), 63,0);}}
        tracep->declArray(c+77,"tb_processor dut if_id", false,-1, 95,0);
        tracep->declArray(c+80,"tb_processor dut id_ex", false,-1, 290,0);
        tracep->declArray(c+90,"tb_processor dut ex_mem", false,-1, 138,0);
        tracep->declArray(c+95,"tb_processor dut mem_wb", false,-1, 69,0);
        tracep->declBus(c+98,"tb_processor dut dec_opcode", false,-1, 6,0);
        tracep->declBus(c+99,"tb_processor dut dec_funct3", false,-1, 2,0);
        tracep->declBus(c+100,"tb_processor dut dec_funct7", false,-1, 6,0);
        tracep->declBus(c+101,"tb_processor dut dec_rs1", false,-1, 4,0);
        tracep->declBus(c+102,"tb_processor dut dec_rs2", false,-1, 4,0);
        tracep->declBus(c+103,"tb_processor dut dec_rd", false,-1, 4,0);
        tracep->declBit(c+104,"tb_processor dut is_jal", false,-1);
        tracep->declQuad(c+105,"tb_processor dut jal_imm", false,-1, 63,0);
        tracep->declQuad(c+107,"tb_processor dut jump_target", false,-1, 63,0);
        tracep->declQuad(c+4,"tb_processor dut pc_reg", false,-1, 63,0);
        tracep->declQuad(c+109,"tb_processor dut imm_gen", false,-1, 63,0);
        tracep->declQuad(c+111,"tb_processor dut alu_in1", false,-1, 63,0);
        tracep->declQuad(c+113,"tb_processor dut alu_in2", false,-1, 63,0);
        tracep->declQuad(c+115,"tb_processor dut alu_out", false,-1, 63,0);
        tracep->declQuad(c+117,"tb_processor dut unnamedblk1 op2_val", false,-1, 63,0);
        tracep->declBus(c+125,"tb_processor dut unnamedblk2 i", false,-1, 31,0);
        tracep->declQuad(c+4,"tb_processor imem addr", false,-1, 63,0);
        tracep->declBus(c+10,"tb_processor imem instr", false,-1, 31,0);
        tracep->declBus(c+1,"tb_processor imem unnamedblk1 i", false,-1, 31,0);
        tracep->declBit(c+119,"tb_processor dmem clk", false,-1);
        tracep->declQuad(c+6,"tb_processor dmem addr", false,-1, 63,0);
        tracep->declQuad(c+8,"tb_processor dmem wdata", false,-1, 63,0);
        tracep->declQuad(c+121,"tb_processor dmem rdata", false,-1, 63,0);
        tracep->declBit(c+12,"tb_processor dmem we", false,-1);
        tracep->declBus(c+2,"tb_processor dmem unnamedblk1 i", false,-1, 31,0);
    }
}

void Vtb_processor::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtb_processor::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtb_processor::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtb_processor__Syms* __restrict vlSymsp = static_cast<Vtb_processor__Syms*>(userp);
    Vtb_processor* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->tb_processor__DOT__imem__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->tb_processor__DOT__dmem__DOT__unnamedblk1__DOT__i),32);
        tracep->fullBit(oldp+3,((0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])));
        tracep->fullQData(oldp+4,(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg),64);
        tracep->fullQData(oldp+6,((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                                    >> 0xbU)))),64);
        tracep->fullQData(oldp+8,((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) 
                                                    >> 0xbU)))),64);
        tracep->fullIData(oldp+10,(((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                     [(0x3fffU & ((IData)(3U) 
                                                  + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                     << 0x18U) | ((
                                                   vlTOPp->tb_processor__DOT__imem__DOT__mem
                                                   [
                                                   (0x3fffU 
                                                    & ((IData)(2U) 
                                                       + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                                   << 0x10U) 
                                                  | ((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                                      [
                                                      (0x3fffU 
                                                       & ((IData)(1U) 
                                                          + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                                      << 8U) 
                                                     | vlTOPp->tb_processor__DOT__imem__DOT__mem
                                                     [
                                                     (0x3fffU 
                                                      & (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg))])))),32);
        tracep->fullCData(oldp+11,((7U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])),3);
        tracep->fullBit(oldp+12,((1U & (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                        >> 3U))));
        tracep->fullQData(oldp+13,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[0]),64);
        tracep->fullQData(oldp+15,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[1]),64);
        tracep->fullQData(oldp+17,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[2]),64);
        tracep->fullQData(oldp+19,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[3]),64);
        tracep->fullQData(oldp+21,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[4]),64);
        tracep->fullQData(oldp+23,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[5]),64);
        tracep->fullQData(oldp+25,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[6]),64);
        tracep->fullQData(oldp+27,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[7]),64);
        tracep->fullQData(oldp+29,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[8]),64);
        tracep->fullQData(oldp+31,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[9]),64);
        tracep->fullQData(oldp+33,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[10]),64);
        tracep->fullQData(oldp+35,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[11]),64);
        tracep->fullQData(oldp+37,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[12]),64);
        tracep->fullQData(oldp+39,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[13]),64);
        tracep->fullQData(oldp+41,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[14]),64);
        tracep->fullQData(oldp+43,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[15]),64);
        tracep->fullQData(oldp+45,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[16]),64);
        tracep->fullQData(oldp+47,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[17]),64);
        tracep->fullQData(oldp+49,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[18]),64);
        tracep->fullQData(oldp+51,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[19]),64);
        tracep->fullQData(oldp+53,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[20]),64);
        tracep->fullQData(oldp+55,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[21]),64);
        tracep->fullQData(oldp+57,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[22]),64);
        tracep->fullQData(oldp+59,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[23]),64);
        tracep->fullQData(oldp+61,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[24]),64);
        tracep->fullQData(oldp+63,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[25]),64);
        tracep->fullQData(oldp+65,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[26]),64);
        tracep->fullQData(oldp+67,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[27]),64);
        tracep->fullQData(oldp+69,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[28]),64);
        tracep->fullQData(oldp+71,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[29]),64);
        tracep->fullQData(oldp+73,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[30]),64);
        tracep->fullQData(oldp+75,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[31]),64);
        tracep->fullWData(oldp+77,(vlTOPp->tb_processor__DOT__dut__DOT__if_id),96);
        tracep->fullWData(oldp+80,(vlTOPp->tb_processor__DOT__dut__DOT__id_ex),291);
        tracep->fullWData(oldp+90,(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem),139);
        tracep->fullWData(oldp+95,(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb),70);
        tracep->fullCData(oldp+98,((0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])),7);
        tracep->fullCData(oldp+99,((7U & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                           << 0x14U) 
                                          | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                             >> 0xcU)))),3);
        tracep->fullCData(oldp+100,((0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 7U) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 0x19U)))),7);
        tracep->fullCData(oldp+101,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 0x11U) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 0xfU)))),5);
        tracep->fullCData(oldp+102,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 0xcU) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 0x14U)))),5);
        tracep->fullCData(oldp+103,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                               << 0x19U) 
                                              | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                 >> 7U)))),5);
        tracep->fullBit(oldp+104,((0x6fU == (0x7fU 
                                             & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U]))));
        tracep->fullQData(oldp+105,(vlTOPp->tb_processor__DOT__dut__DOT__jal_imm),64);
        tracep->fullQData(oldp+107,(((((QData)((IData)(
                                                       vlTOPp->tb_processor__DOT__dut__DOT__if_id[2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U]))) 
                                     + vlTOPp->tb_processor__DOT__dut__DOT__jal_imm)),64);
        tracep->fullQData(oldp+109,(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen),64);
        tracep->fullQData(oldp+111,(vlTOPp->tb_processor__DOT__dut__DOT__alu_in1),64);
        tracep->fullQData(oldp+113,(vlTOPp->tb_processor__DOT__dut__DOT__alu_in2),64);
        tracep->fullQData(oldp+115,(vlTOPp->tb_processor__DOT__dut__DOT__alu_out),64);
        tracep->fullQData(oldp+117,(vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk1__DOT__op2_val),64);
        tracep->fullBit(oldp+119,(vlTOPp->clk));
        tracep->fullBit(oldp+120,(vlTOPp->rst_n));
        tracep->fullQData(oldp+121,(vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                    [(0x3ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                 << 0x12U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                   >> 0xeU)))]),64);
        tracep->fullIData(oldp+123,(vlTOPp->tb_processor__DOT__halt_counter),32);
        tracep->fullIData(oldp+124,(vlTOPp->tb_processor__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+125,(vlTOPp->tb_processor__DOT__dut__DOT__unnamedblk2__DOT__i),32);
    }
}
