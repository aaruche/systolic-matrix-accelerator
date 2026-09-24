// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_Top_tb.h for the primary calling header

#include "VPE_Top_tb__pch.h"
#include "VPE_Top_tb__Syms.h"
#include "VPE_Top_tb___024root.h"

VL_INLINE_OPT VlCoroutine VPE_Top_tb___024root___eval_initial__TOP__Vtiming__0(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col1 = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_start;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_start = 0;
    CData/*0:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_clear;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_clear = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_K;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_K = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row1 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col0;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col0 = 0;
    CData/*7:0*/ __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x705f7462U;
    __Vtemp_1[2U] = 0x455f546fU;
    __Vtemp_1[3U] = 0x50U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.PE_Top_tb__DOT__rst_n = 0U;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = 0U;
    vlSelfRef.PE_Top_tb__DOT__start = 0U;
    vlSelfRef.PE_Top_tb__DOT__K = 0U;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = 0U;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = 0U;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = 0U;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cb0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         89);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h3e55cb0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         89);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         91);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__rst_n = 1U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col1 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col0 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row1 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row0 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_K = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_clear = 1U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__0__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col1 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col0 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row1 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row0 = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_start = 1U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__1__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col1 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col0 = 5U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row1 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row0 = 1U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__2__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col1 = 6U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col0 = 7U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row1 = 3U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row0 = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__3__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col1 = 8U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col0 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row1 = 4U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row0 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__4__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col1 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col0 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row1 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row0 = 0x63U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__5__next_B_col1;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col1 = 0xa8U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col0 = 0xa8U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row1 = 0xa8U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row0 = 0xa8U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_K = 2U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_clear = 0U;
    __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_start = 0U;
    co_await vlSelfRef.__VtrigSched_h3e55cbce__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.PE_Top_tb__DOT__start = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_start;
    vlSelfRef.PE_Top_tb__DOT__accum_clr = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_clear;
    vlSelfRef.PE_Top_tb__DOT__K = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_K;
    vlSelfRef.PE_Top_tb__DOT__A_row0 = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row0;
    vlSelfRef.PE_Top_tb__DOT__A_row1 = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_A_row1;
    vlSelfRef.PE_Top_tb__DOT__B_col0 = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col0;
    vlSelfRef.PE_Top_tb__DOT__B_col1 = __Vtask_PE_Top_tb__DOT__drive_cycle__6__next_B_col1;
    co_await vlSelfRef.__VtrigSched_h3e55cb0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb/PE_Top_tb.sv", 
                                         157);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("FINAL C = {%0d, %0d, %0d, %0d}\n",0,
                 32,vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg,
                 32,vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg,
                 32,vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg,
                 32,vlSelfRef.PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg);
    co_await vlSelfRef.__VtrigSched_h3e55cb0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         167);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h3e55cb0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge PE_Top_tb.clk)", 
                                                         "tb/PE_Top_tb.sv", 
                                                         167);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("tb/PE_Top_tb.sv", 168, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_Top_tb___024root___dump_triggers__act(VPE_Top_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VPE_Top_tb___024root___eval_triggers__act(VPE_Top_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_Top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_Top_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.PE_Top_tb__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.PE_Top_tb__DOT__clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0)));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0 
        = vlSelfRef.PE_Top_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPE_Top_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
