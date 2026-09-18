// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_tb.h for the primary calling header

#include "VPE_tb__pch.h"
#include "VPE_tb__Syms.h"
#include "VPE_tb___024root.h"

VL_ATTR_COLD void VPE_tb___024root___eval_initial__TOP(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelfRef.PE_tb__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x455f7462U;
    __Vtemp_1[2U] = 0x50U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void VPE_tb___024root___configure_coverage(VPE_tb___024root* vlSelf, bool first) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___configure_coverage\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "tb/PE_sva.sv", 159, 22, ".PE_tb.c_valid_then_bubble", "v_user/PE_tb", "c_valid_then_bubble", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "tb/PE_sva.sv", 168, 22, ".PE_tb.c_consecutive_valid", "v_user/PE_tb", "c_consecutive_valid", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "tb/PE_sva.sv", 177, 26, ".PE_tb.c_clear_pending_product", "v_user/PE_tb", "c_clear_pending_product", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "tb/PE_sva.sv", 185, 20, ".PE_tb.c_clear_and_valid", "v_user/PE_tb", "c_clear_and_valid", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "tb/PE_sva.sv", 194, 26, ".PE_tb.c_reset_during_activity", "v_user/PE_tb", "c_reset_during_activity", "");
}
