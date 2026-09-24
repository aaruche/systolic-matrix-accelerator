// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_Top_tb.h for the primary calling header

#include "VPE_Top_tb__pch.h"
#include "VPE_Top_tb___024root.h"

VL_ATTR_COLD void VPE_Top_tb___024root___eval_static(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPE_Top_tb___024root___eval_initial__TOP(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PE_Top_tb__DOT__clk = 0U;
}

VL_ATTR_COLD void VPE_Top_tb___024root___eval_final(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__stl(VPE_Top_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VPE_Top_tb___024root___eval_phase__stl(VPE_Top_tb___024root* vlSelf);

VL_ATTR_COLD void VPE_Top_tb___024root___eval_settle(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VPE_Top_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/PE_Top_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VPE_Top_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__stl(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPE_Top_tb___024root___stl_sequent__TOP__0(VPE_Top_tb___024root* vlSelf);
VL_ATTR_COLD void VPE_Top_tb___024root____Vm_traceActivitySetAll(VPE_Top_tb___024root* vlSelf);

VL_ATTR_COLD void VPE_Top_tb___024root___eval_stl(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VPE_Top_tb___024root___stl_sequent__TOP__0(vlSelf);
        VPE_Top_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void VPE_Top_tb___024root___stl_sequent__TOP__0(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00 = ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing) 
                                               & ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count) 
                                                  < (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K)));
}

VL_ATTR_COLD void VPE_Top_tb___024root___eval_triggers__stl(VPE_Top_tb___024root* vlSelf);

VL_ATTR_COLD bool VPE_Top_tb___024root___eval_phase__stl(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VPE_Top_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VPE_Top_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__act(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge PE_Top_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge PE_Top_tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__nba(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge PE_Top_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge PE_Top_tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPE_Top_tb___024root____Vm_traceActivitySetAll(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void VPE_Top_tb___024root___ctor_var_reset(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->PE_Top_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__accum_clr = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__K = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__A_row0 = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__A_row1 = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__B_col0 = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__B_col1 = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__issuing = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__accepted_count = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__active_K = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__valid_delay_1 = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__valid_delay_2 = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__v00 = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg = VL_RAND_RESET_I(16);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg = VL_RAND_RESET_I(16);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE01__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg = VL_RAND_RESET_I(16);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE10__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg = VL_RAND_RESET_I(16);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg = VL_RAND_RESET_I(32);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE11__DOT__A_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->PE_Top_tb__DOT__dut__DOT__PE11__DOT__B_forw_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
