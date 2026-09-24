// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_Top_tb.h for the primary calling header

#include "VPE_Top_tb__pch.h"
#include "VPE_Top_tb___024root.h"

VL_ATTR_COLD void VPE_Top_tb___024root___eval_initial__TOP(VPE_Top_tb___024root* vlSelf);
VlCoroutine VPE_Top_tb___024root___eval_initial__TOP__Vtiming__0(VPE_Top_tb___024root* vlSelf);
VlCoroutine VPE_Top_tb___024root___eval_initial__TOP__Vtiming__1(VPE_Top_tb___024root* vlSelf);

void VPE_Top_tb___024root___eval_initial(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VPE_Top_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    VPE_Top_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    VPE_Top_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0 
        = vlSelfRef.PE_Top_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine VPE_Top_tb___024root___eval_initial__TOP__Vtiming__1(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/PE_Top_tb.sv", 
                                             49);
        vlSelfRef.PE_Top_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__clk)));
    }
}

void VPE_Top_tb___024root___eval_act(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VPE_Top_tb___024root___nba_sequent__TOP__0(VPE_Top_tb___024root* vlSelf);

void VPE_Top_tb___024root___eval_nba(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPE_Top_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void VPE_Top_tb___024root___nba_sequent__TOP__0(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count;
    __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count = 0;
    IData/*31:0*/ __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg = 0;
    IData/*31:0*/ __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg = 0;
    IData/*31:0*/ __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg = 0;
    IData/*31:0*/ __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg = 0;
    // Body
    __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count 
        = vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg 
        = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg 
        = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg 
        = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg;
    __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg 
        = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg;
    if (vlSelfRef.PE_Top_tb__DOT__rst_n) {
        if (vlSelfRef.PE_Top_tb__DOT__accum_clr) {
            __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg = 0U;
            __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg = 0U;
            __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg = 0U;
            __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing = 0U;
            __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg = 0U;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K = 0U;
        } else {
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_valid_reg) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg 
                    = (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg)));
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_valid_reg) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg 
                    = (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg)));
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_valid_reg) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg 
                    = (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg)));
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_valid_reg) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg 
                    = (vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg)));
            }
            if (vlSelfRef.PE_Top_tb__DOT__start) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count = 0U;
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing 
                    = (0U != (IData)(vlSelfRef.PE_Top_tb__DOT__K));
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K 
                    = vlSelfRef.PE_Top_tb__DOT__K;
            } else if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00) {
                __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count)));
                if (((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count) 
                     == (0xffU & ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K) 
                                  - (IData)(1U))))) {
                    vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing = 0U;
                }
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00) {
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg 
                    = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                  & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__A_row0))), 
                                             (0xffffU 
                                              & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__B_col0)))));
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1) {
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg 
                    = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                  & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg))), 
                                             (0xffffU 
                                              & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__B_col1)))));
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg 
                    = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                  & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__A_row1))), 
                                             (0xffffU 
                                              & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg)))));
            }
            if (vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2) {
                vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg 
                    = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                  & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg))), 
                                             (0xffffU 
                                              & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg)))));
            }
        }
        if (((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2) 
             & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr)))) {
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__A_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__B_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg;
        }
        if (((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1) 
             & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr)))) {
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__A_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__B_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__A_row1;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__B_col1;
        }
        if (((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00) 
             & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr)))) {
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__A_row0;
            vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg 
                = vlSelfRef.PE_Top_tb__DOT__B_col0;
        }
    } else {
        __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg = 0U;
        __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg = 0U;
        __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg = 0U;
        __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing = 0U;
        __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__A_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__B_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__A_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__B_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg = 0U;
        vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg = 0U;
    }
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg 
        = __Vdly__PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg;
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg 
        = __Vdly__PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg;
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg 
        = __Vdly__PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg;
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg 
        = __Vdly__PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg;
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count 
        = __Vdly__PE_Top_tb__DOT__dut__DOT__accepted_count;
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_valid_reg 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_valid_reg 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_valid_reg 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_valid_reg 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_2 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__valid_delay_1 
        = ((IData)(vlSelfRef.PE_Top_tb__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.PE_Top_tb__DOT__accum_clr))) 
               && (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00)));
    vlSelfRef.PE_Top_tb__DOT__dut__DOT__v00 = ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__issuing) 
                                               & ((IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__accepted_count) 
                                                  < (IData)(vlSelfRef.PE_Top_tb__DOT__dut__DOT__active_K)));
}

void VPE_Top_tb___024root___timing_resume(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h3e55cb0f__0.resume(
                                                   "@(posedge PE_Top_tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h3e55cbce__0.resume(
                                                   "@(negedge PE_Top_tb.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void VPE_Top_tb___024root___timing_commit(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h3e55cb0f__0.commit(
                                                   "@(posedge PE_Top_tb.clk)");
    }
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h3e55cbce__0.commit(
                                                   "@(negedge PE_Top_tb.clk)");
    }
}

void VPE_Top_tb___024root___eval_triggers__act(VPE_Top_tb___024root* vlSelf);

bool VPE_Top_tb___024root___eval_phase__act(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VPE_Top_tb___024root___eval_triggers__act(vlSelf);
    VPE_Top_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VPE_Top_tb___024root___timing_resume(vlSelf);
        VPE_Top_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VPE_Top_tb___024root___eval_phase__nba(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VPE_Top_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__nba(VPE_Top_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__act(VPE_Top_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VPE_Top_tb___024root___eval(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VPE_Top_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/PE_Top_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VPE_Top_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/PE_Top_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VPE_Top_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VPE_Top_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VPE_Top_tb___024root___eval_debug_assertions(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
