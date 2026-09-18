// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPE_tb__Syms.h"


void VPE_tb___024root__trace_chg_0_sub_0(VPE_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPE_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root__trace_chg_0\n"); );
    // Init
    VPE_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPE_tb___024root*>(voidSelf);
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPE_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VPE_tb___024root__trace_chg_0_sub_0(VPE_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.PE_tb__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelfRef.PE_tb__DOT__pe_valid));
        bufp->chgBit(oldp+2,(vlSelfRef.PE_tb__DOT__accum_clr));
        bufp->chgCData(oldp+3,(vlSelfRef.PE_tb__DOT__A),8);
        bufp->chgCData(oldp+4,(vlSelfRef.PE_tb__DOT__B),8);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+5,(vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg),32);
        bufp->chgCData(oldp+6,(vlSelfRef.PE_tb__DOT__dut__DOT__A_forw_reg),8);
        bufp->chgCData(oldp+7,(vlSelfRef.PE_tb__DOT__dut__DOT__B_forw_reg),8);
        bufp->chgSData(oldp+8,(vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg),16);
        bufp->chgBit(oldp+9,(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg));
    }
    bufp->chgBit(oldp+10,(vlSelfRef.PE_tb__DOT__clk));
}

void VPE_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root__trace_cleanup\n"); );
    // Init
    VPE_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPE_tb___024root*>(voidSelf);
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
