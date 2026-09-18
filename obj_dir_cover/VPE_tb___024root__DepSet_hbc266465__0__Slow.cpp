// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_tb.h for the primary calling header

#include "VPE_tb__pch.h"
#include "VPE_tb___024root.h"

VL_ATTR_COLD void VPE_tb___024root___eval_static(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPE_tb___024root___eval_final(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPE_tb___024root___eval_settle(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_tb___024root___dump_triggers__act(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge PE_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge PE_tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_tb___024root___dump_triggers__nba(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge PE_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge PE_tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPE_tb___024root___ctor_var_reset(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->PE_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__pe_valid = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__accum_clr = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__A = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT__B = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_0_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_1_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_2_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_3_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_4_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_5_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_6_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_7_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_8_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_9_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_10_0 = VL_RAND_RESET_I(32);
    vlSelf->PE_tb__DOT___Vpast_11_0 = VL_RAND_RESET_I(16);
    vlSelf->PE_tb__DOT___Vpast_12_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_13_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_14_0 = VL_RAND_RESET_I(32);
    vlSelf->PE_tb__DOT___Vpast_15_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_16_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_17_0 = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT___Vpast_18_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_19_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT___Vpast_20_0 = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__dut__DOT__mult_reg = VL_RAND_RESET_I(16);
    vlSelf->PE_tb__DOT__dut__DOT__mult_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->PE_tb__DOT__dut__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->PE_tb__DOT__dut__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_tb__DOT__dut__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_0_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_1_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_2_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_3_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_4_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_5_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_6_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_7_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_8_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_9_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_10_0 = VL_RAND_RESET_I(32);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_11_0 = VL_RAND_RESET_I(16);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_12_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_13_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_14_0 = VL_RAND_RESET_I(32);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_15_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_16_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT___Vpast_17_0 = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__dut__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__dut__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__dut__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__pe_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__accum_clr = VL_RAND_RESET_I(1);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__A = VL_RAND_RESET_I(8);
    vlSelf->__Vsampled_TOP__PE_tb__DOT__B = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__PE_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
