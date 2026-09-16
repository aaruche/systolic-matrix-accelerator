// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_tb.h for the primary calling header

#include "VPE_tb__pch.h"
#include "VPE_tb___024root.h"

VL_ATTR_COLD void VPE_tb___024root___eval_initial__TOP(VPE_tb___024root* vlSelf);
VlCoroutine VPE_tb___024root___eval_initial__TOP__Vtiming__0(VPE_tb___024root* vlSelf);
VlCoroutine VPE_tb___024root___eval_initial__TOP__Vtiming__1(VPE_tb___024root* vlSelf);

void VPE_tb___024root___eval_initial(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VPE_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    VPE_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    VPE_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__PE_tb__DOT__clk__0 
        = vlSelfRef.PE_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine VPE_tb___024root___eval_initial__TOP__Vtiming__0(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PE_tb__DOT__rst_n = 0U;
    vlSelfRef.PE_tb__DOT__pe_valid = 0U;
    vlSelfRef.PE_tb__DOT__accum_clr = 0U;
    vlSelfRef.PE_tb__DOT__A = 0U;
    vlSelfRef.PE_tb__DOT__B = 0U;
    co_await vlSelfRef.__VtrigSched_hdd58016d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58016d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__rst_n = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         56);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__pe_valid = 0U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         60);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__accum_clr = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         63);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__accum_clr = 0U;
    vlSelfRef.PE_tb__DOT__pe_valid = 1U;
    vlSelfRef.PE_tb__DOT__A = 3U;
    vlSelfRef.PE_tb__DOT__B = 0xfeU;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__pe_valid = 1U;
    vlSelfRef.PE_tb__DOT__A = 0xfcU;
    vlSelfRef.PE_tb__DOT__B = 5U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__pe_valid = 0U;
    vlSelfRef.PE_tb__DOT__A = 0x63U;
    vlSelfRef.PE_tb__DOT__B = 0x63U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         84);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__pe_valid = 0U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         88);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__accum_clr = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58012c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         91);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_tb__DOT__accum_clr = 0U;
    co_await vlSelfRef.__VtrigSched_hdd58016d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         95);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hdd58016d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_tb.clk)", 
                                                         "tb/PE_tb.sv", 
                                                         95);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("tb/PE_tb.sv", 97, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine VPE_tb___024root___eval_initial__TOP__Vtiming__1(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/PE_tb.sv", 
                                             37);
        vlSelfRef.PE_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.PE_tb__DOT__clk)));
    }
}

void VPE_tb___024root___eval_act(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VPE_tb___024root___nba_sequent__TOP__0(VPE_tb___024root* vlSelf);

void VPE_tb___024root___eval_nba(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPE_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void VPE_tb___024root___timing_resume(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hdd58016d__0.resume(
                                                   "@(posedge PE_tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hdd58012c__0.resume(
                                                   "@(negedge PE_tb.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void VPE_tb___024root___timing_commit(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hdd58016d__0.commit(
                                                   "@(posedge PE_tb.clk)");
    }
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hdd58012c__0.commit(
                                                   "@(negedge PE_tb.clk)");
    }
}

void VPE_tb___024root___eval_triggers__act(VPE_tb___024root* vlSelf);

bool VPE_tb___024root___eval_phase__act(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VPE_tb___024root___eval_triggers__act(vlSelf);
    VPE_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VPE_tb___024root___timing_resume(vlSelf);
        VPE_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VPE_tb___024root___eval_phase__nba(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VPE_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_tb___024root___dump_triggers__nba(VPE_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_tb___024root___dump_triggers__act(VPE_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VPE_tb___024root___eval(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_0_0 
        = vlSelfRef.PE_tb__DOT___Vpast_0_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n = vlSelfRef.PE_tb__DOT__rst_n;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_1_0 
        = vlSelfRef.PE_tb__DOT___Vpast_1_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_2_0 
        = vlSelfRef.PE_tb__DOT___Vpast_2_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_3_0 
        = vlSelfRef.PE_tb__DOT___Vpast_3_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_4_0 
        = vlSelfRef.PE_tb__DOT___Vpast_4_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_5_0 
        = vlSelfRef.PE_tb__DOT___Vpast_5_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_6_0 
        = vlSelfRef.PE_tb__DOT___Vpast_6_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_7_0 
        = vlSelfRef.PE_tb__DOT___Vpast_7_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_8_0 
        = vlSelfRef.PE_tb__DOT___Vpast_8_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_9_0 
        = vlSelfRef.PE_tb__DOT___Vpast_9_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_10_0 
        = vlSelfRef.PE_tb__DOT___Vpast_10_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_11_0 
        = vlSelfRef.PE_tb__DOT___Vpast_11_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_12_0 
        = vlSelfRef.PE_tb__DOT___Vpast_12_0;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT__pe_valid 
        = vlSelfRef.PE_tb__DOT__pe_valid;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr 
        = vlSelfRef.PE_tb__DOT__accum_clr;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT__A = vlSelfRef.PE_tb__DOT__A;
    vlSelfRef.__Vsampled_TOP__PE_tb__DOT__B = vlSelfRef.PE_tb__DOT__B;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VPE_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/PE_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VPE_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/PE_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VPE_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VPE_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VPE_tb___024root___eval_debug_assertions(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
