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
        tracep->declBit(c+106,"clk", false,-1);
        tracep->declBit(c+107,"rst_n", false,-1);
        tracep->declBit(c+106,"tb_processor clk", false,-1);
        tracep->declBit(c+107,"tb_processor rst_n", false,-1);
        tracep->declBit(c+2,"tb_processor halt", false,-1);
        tracep->declQuad(c+3,"tb_processor imem_addr", false,-1, 63,0);
        tracep->declQuad(c+5,"tb_processor dmem_addr", false,-1, 63,0);
        tracep->declQuad(c+7,"tb_processor dmem_wdata", false,-1, 63,0);
        tracep->declQuad(c+108,"tb_processor dmem_rdata", false,-1, 63,0);
        tracep->declBus(c+9,"tb_processor instr", false,-1, 31,0);
        tracep->declBus(c+10,"tb_processor dmem_size", false,-1, 2,0);
        tracep->declBit(c+11,"tb_processor dmem_we", false,-1);
        tracep->declBus(c+110,"tb_processor halt_counter", false,-1, 31,0);
        tracep->declBus(c+111,"tb_processor unnamedblk1 i", false,-1, 31,0);
        tracep->declBit(c+106,"tb_processor dut clk", false,-1);
        tracep->declBit(c+107,"tb_processor dut rst_n", false,-1);
        tracep->declQuad(c+3,"tb_processor dut imem_addr", false,-1, 63,0);
        tracep->declBus(c+9,"tb_processor dut imem_instr", false,-1, 31,0);
        tracep->declQuad(c+5,"tb_processor dut dmem_addr", false,-1, 63,0);
        tracep->declQuad(c+7,"tb_processor dut dmem_wdata", false,-1, 63,0);
        tracep->declQuad(c+108,"tb_processor dut dmem_rdata", false,-1, 63,0);
        tracep->declBit(c+11,"tb_processor dut dmem_we", false,-1);
        tracep->declBus(c+10,"tb_processor dut dmem_size", false,-1, 2,0);
        tracep->declBit(c+2,"tb_processor dut halt", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+42+i*2,"tb_processor dut reg_file", true,(i+0), 63,0);}}
        tracep->declArray(c+12,"tb_processor dut if_id", false,-1, 95,0);
        tracep->declArray(c+15,"tb_processor dut id_ex", false,-1, 280,0);
        tracep->declArray(c+24,"tb_processor dut ex_mem", false,-1, 138,0);
        tracep->declArray(c+29,"tb_processor dut mem_wb", false,-1, 69,0);
        tracep->declQuad(c+3,"tb_processor dut pc_reg", false,-1, 63,0);
        tracep->declBus(c+32,"tb_processor dut dec_opcode", false,-1, 6,0);
        tracep->declBus(c+33,"tb_processor dut dec_funct3", false,-1, 2,0);
        tracep->declBus(c+34,"tb_processor dut dec_funct7", false,-1, 6,0);
        tracep->declBus(c+35,"tb_processor dut dec_rs1", false,-1, 4,0);
        tracep->declBus(c+36,"tb_processor dut dec_rs2", false,-1, 4,0);
        tracep->declBus(c+37,"tb_processor dut dec_rd", false,-1, 4,0);
        tracep->declQuad(c+38,"tb_processor dut imm_gen", false,-1, 63,0);
        tracep->declQuad(c+40,"tb_processor dut alu_out", false,-1, 63,0);
        tracep->declQuad(c+3,"tb_processor imem addr", false,-1, 63,0);
        tracep->declBus(c+9,"tb_processor imem instr", false,-1, 31,0);
        tracep->declBus(c+1,"tb_processor imem unnamedblk1 i", false,-1, 31,0);
        tracep->declBit(c+106,"tb_processor dmem clk", false,-1);
        tracep->declQuad(c+5,"tb_processor dmem addr", false,-1, 63,0);
        tracep->declQuad(c+7,"tb_processor dmem wdata", false,-1, 63,0);
        tracep->declQuad(c+108,"tb_processor dmem rdata", false,-1, 63,0);
        tracep->declBit(c+11,"tb_processor dmem we", false,-1);
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
        tracep->fullBit(oldp+2,((0x6fU == vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])));
        tracep->fullQData(oldp+3,(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg),64);
        tracep->fullQData(oldp+5,((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[4U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                                    >> 0xbU)))),64);
        tracep->fullQData(oldp+7,((((QData)((IData)(
                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[1U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])) 
                                                    >> 0xbU)))),64);
        tracep->fullIData(oldp+9,(((vlTOPp->tb_processor__DOT__imem__DOT__mem
                                    [(0x3fffU & ((IData)(3U) 
                                                 + (IData)(vlTOPp->tb_processor__DOT__dut__DOT__pc_reg)))] 
                                    << 0x18U) | ((vlTOPp->tb_processor__DOT__imem__DOT__mem
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
        tracep->fullCData(oldp+10,((7U & vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U])),3);
        tracep->fullBit(oldp+11,((1U & (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[0U] 
                                        >> 3U))));
        tracep->fullWData(oldp+12,(vlTOPp->tb_processor__DOT__dut__DOT__if_id),96);
        tracep->fullWData(oldp+15,(vlTOPp->tb_processor__DOT__dut__DOT__id_ex),281);
        tracep->fullWData(oldp+24,(vlTOPp->tb_processor__DOT__dut__DOT__ex_mem),139);
        tracep->fullWData(oldp+29,(vlTOPp->tb_processor__DOT__dut__DOT__mem_wb),70);
        tracep->fullCData(oldp+32,((0x7fU & vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U])),7);
        tracep->fullCData(oldp+33,((7U & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                           << 0x14U) 
                                          | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                             >> 0xcU)))),3);
        tracep->fullCData(oldp+34,((0x7fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 7U) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 0x19U)))),7);
        tracep->fullCData(oldp+35,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 0x11U) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 0xfU)))),5);
        tracep->fullCData(oldp+36,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 0xcU) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 0x14U)))),5);
        tracep->fullCData(oldp+37,((0x1fU & ((vlTOPp->tb_processor__DOT__dut__DOT__if_id[1U] 
                                              << 0x19U) 
                                             | (vlTOPp->tb_processor__DOT__dut__DOT__if_id[0U] 
                                                >> 7U)))),5);
        tracep->fullQData(oldp+38,(vlTOPp->tb_processor__DOT__dut__DOT__imm_gen),64);
        tracep->fullQData(oldp+40,(vlTOPp->tb_processor__DOT__dut__DOT__alu_out),64);
        tracep->fullQData(oldp+42,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[0]),64);
        tracep->fullQData(oldp+44,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[1]),64);
        tracep->fullQData(oldp+46,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[2]),64);
        tracep->fullQData(oldp+48,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[3]),64);
        tracep->fullQData(oldp+50,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[4]),64);
        tracep->fullQData(oldp+52,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[5]),64);
        tracep->fullQData(oldp+54,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[6]),64);
        tracep->fullQData(oldp+56,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[7]),64);
        tracep->fullQData(oldp+58,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[8]),64);
        tracep->fullQData(oldp+60,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[9]),64);
        tracep->fullQData(oldp+62,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[10]),64);
        tracep->fullQData(oldp+64,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[11]),64);
        tracep->fullQData(oldp+66,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[12]),64);
        tracep->fullQData(oldp+68,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[13]),64);
        tracep->fullQData(oldp+70,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[14]),64);
        tracep->fullQData(oldp+72,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[15]),64);
        tracep->fullQData(oldp+74,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[16]),64);
        tracep->fullQData(oldp+76,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[17]),64);
        tracep->fullQData(oldp+78,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[18]),64);
        tracep->fullQData(oldp+80,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[19]),64);
        tracep->fullQData(oldp+82,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[20]),64);
        tracep->fullQData(oldp+84,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[21]),64);
        tracep->fullQData(oldp+86,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[22]),64);
        tracep->fullQData(oldp+88,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[23]),64);
        tracep->fullQData(oldp+90,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[24]),64);
        tracep->fullQData(oldp+92,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[25]),64);
        tracep->fullQData(oldp+94,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[26]),64);
        tracep->fullQData(oldp+96,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[27]),64);
        tracep->fullQData(oldp+98,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[28]),64);
        tracep->fullQData(oldp+100,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[29]),64);
        tracep->fullQData(oldp+102,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[30]),64);
        tracep->fullQData(oldp+104,(vlTOPp->tb_processor__DOT__dut__DOT__reg_file[31]),64);
        tracep->fullBit(oldp+106,(vlTOPp->clk));
        tracep->fullBit(oldp+107,(vlTOPp->rst_n));
        tracep->fullQData(oldp+108,(vlTOPp->tb_processor__DOT__dmem__DOT__mem
                                    [(0x1ffU & ((vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[3U] 
                                                 << 0x12U) 
                                                | (vlTOPp->tb_processor__DOT__dut__DOT__ex_mem[2U] 
                                                   >> 0xeU)))]),64);
        tracep->fullIData(oldp+110,(vlTOPp->tb_processor__DOT__halt_counter),32);
        tracep->fullIData(oldp+111,(vlTOPp->tb_processor__DOT__unnamedblk1__DOT__i),32);
    }
}
