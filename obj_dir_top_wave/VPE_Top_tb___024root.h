// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPE_Top_tb.h for the primary calling header

#ifndef VERILATED_VPE_TOP_TB___024ROOT_H_
#define VERILATED_VPE_TOP_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VPE_Top_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPE_Top_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ PE_Top_tb__DOT__clk;
    CData/*0:0*/ PE_Top_tb__DOT__rst_n;
    CData/*0:0*/ PE_Top_tb__DOT__accum_clr;
    CData/*0:0*/ PE_Top_tb__DOT__start;
    CData/*7:0*/ PE_Top_tb__DOT__K;
    CData/*7:0*/ PE_Top_tb__DOT__A_row0;
    CData/*7:0*/ PE_Top_tb__DOT__A_row1;
    CData/*7:0*/ PE_Top_tb__DOT__B_col0;
    CData/*7:0*/ PE_Top_tb__DOT__B_col1;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__issuing;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__accepted_count;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__active_K;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__valid_delay_1;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__valid_delay_2;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__v00;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_valid_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE00__DOT__A_forw_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE00__DOT__B_forw_reg;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_valid_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE01__DOT__A_forw_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE01__DOT__B_forw_reg;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_valid_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE10__DOT__A_forw_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE10__DOT__B_forw_reg;
    CData/*0:0*/ PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_valid_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE11__DOT__A_forw_reg;
    CData/*7:0*/ PE_Top_tb__DOT__dut__DOT__PE11__DOT__B_forw_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__PE_Top_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ PE_Top_tb__DOT__dut__DOT__PE00__DOT__mult_reg;
    SData/*15:0*/ PE_Top_tb__DOT__dut__DOT__PE01__DOT__mult_reg;
    SData/*15:0*/ PE_Top_tb__DOT__dut__DOT__PE10__DOT__mult_reg;
    SData/*15:0*/ PE_Top_tb__DOT__dut__DOT__PE11__DOT__mult_reg;
    IData/*31:0*/ PE_Top_tb__DOT__dut__DOT__PE00__DOT__accum_reg;
    IData/*31:0*/ PE_Top_tb__DOT__dut__DOT__PE01__DOT__accum_reg;
    IData/*31:0*/ PE_Top_tb__DOT__dut__DOT__PE10__DOT__accum_reg;
    IData/*31:0*/ PE_Top_tb__DOT__dut__DOT__PE11__DOT__accum_reg;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h3e55cb0f__0;
    VlTriggerScheduler __VtrigSched_h3e55cbce__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPE_Top_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPE_Top_tb___024root(VPE_Top_tb__Syms* symsp, const char* v__name);
    ~VPE_Top_tb___024root();
    VL_UNCOPYABLE(VPE_Top_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
