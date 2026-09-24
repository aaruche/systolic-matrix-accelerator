// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPE_Top_tb__Syms.h"


void VPE_Top_tb___024root__trace_chg_0_sub_0(VPE_Top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPE_Top_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root__trace_chg_0\n"); );
    // Init
    VPE_Top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPE_Top_tb___024root*>(voidSelf);
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPE_Top_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VPE_Top_tb___024root__trace_chg_0_sub_0(VPE_Top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.PE_Top_tb__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelfRef.PE_Top_tb__DOT__accum_clr));
        bufp->chgBit(oldp+2,(vlSelfRef.PE_Top_tb__DOT__start));
        bufp->chgCData(oldp+3,(vlSelfRef.PE_Top_tb__DOT__K),8);
        bufp->chgCData(oldp+4,(vlSelfRef.PE_Top_tb__DOT__A_row0),8);
        bufp->chgCData(oldp+5,(vlSelfRef.PE_Top_tb__DOT__A_row1),8);
        bufp->chgCData(oldp+6,(vlSelfRef.PE_Top_tb__DOT__B_col0),8);
        bufp->chgCData(oldp+7,(vlSelfRef.PE_Top_tb__DOT__B_col1),8);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+8,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg),32);
        bufp->chgIData(oldp+9,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg),32);
        bufp->chgIData(oldp+10,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg),32);
        bufp->chgIData(oldp+11,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg),32);
        bufp->chgCData(oldp+12,(((((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00) 
                                   << 3U) | ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1) 
                                             << 2U)) 
                                 | (((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1) 
                                     << 1U) | (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2)))),4);
        bufp->chgCData(oldp+13,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg),8);
        bufp->chgCData(oldp+14,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg),8);
        bufp->chgCData(oldp+15,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg),8);
        bufp->chgCData(oldp+16,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg),8);
        bufp->chgCData(oldp+17,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__A_forw_reg),8);
        bufp->chgCData(oldp+18,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__B_forw_reg),8);
        bufp->chgCData(oldp+19,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__A_forw_reg),8);
        bufp->chgCData(oldp+20,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__B_forw_reg),8);
        bufp->chgBit(oldp+21,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing));
        bufp->chgCData(oldp+22,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count),8);
        bufp->chgCData(oldp+23,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K),8);
        bufp->chgBit(oldp+24,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1));
        bufp->chgBit(oldp+25,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2));
        bufp->chgBit(oldp+26,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00));
        bufp->chgSData(oldp+27,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg),16);
        bufp->chgBit(oldp+28,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_valid_reg));
        bufp->chgSData(oldp+29,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg),16);
        bufp->chgBit(oldp+30,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_valid_reg));
        bufp->chgSData(oldp+31,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg),16);
        bufp->chgBit(oldp+32,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_valid_reg));
        bufp->chgSData(oldp+33,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg),16);
        bufp->chgBit(oldp+34,(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_valid_reg));
    }
    bufp->chgBit(oldp+35,(vlSelfRef.PE_Top_tb__DOT__clk));
}

void VPE_Top_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root__trace_cleanup\n"); );
    // Init
    VPE_Top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPE_Top_tb___024root*>(voidSelf);
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
