// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPE_tb.h for the primary calling header

#ifndef VERILATED_VPE_TB___024ROOT_H_
#define VERILATED_VPE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VPE_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPE_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ PE_tb__DOT__clk;
    CData/*0:0*/ PE_tb__DOT__rst_n;
    CData/*0:0*/ PE_tb__DOT__pe_valid;
    CData/*0:0*/ PE_tb__DOT__accum_clr;
    CData/*7:0*/ PE_tb__DOT__A;
    CData/*7:0*/ PE_tb__DOT__B;
    CData/*0:0*/ PE_tb__DOT___Vpast_0_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_1_0;
    CData/*7:0*/ PE_tb__DOT___Vpast_2_0;
    CData/*7:0*/ PE_tb__DOT___Vpast_3_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_4_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_5_0;
    CData/*7:0*/ PE_tb__DOT___Vpast_6_0;
    CData/*7:0*/ PE_tb__DOT___Vpast_7_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_8_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_9_0;
    CData/*0:0*/ PE_tb__DOT___Vpast_12_0;
    CData/*0:0*/ PE_tb__DOT__dut__DOT__mult_valid_reg;
    CData/*7:0*/ PE_tb__DOT__dut__DOT__A_forw_reg;
    CData/*7:0*/ PE_tb__DOT__dut__DOT__B_forw_reg;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_0_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT__rst_n;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_1_0;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_2_0;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_3_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_4_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_5_0;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_6_0;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_7_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_8_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_9_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_12_0;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT__pe_valid;
    CData/*0:0*/ __Vsampled_TOP__PE_tb__DOT__accum_clr;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT__A;
    CData/*7:0*/ __Vsampled_TOP__PE_tb__DOT__B;
    CData/*0:0*/ __Vtrigprevexpr___TOP__PE_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ PE_tb__DOT___Vpast_11_0;
    SData/*15:0*/ PE_tb__DOT__dut__DOT__mult_reg;
    SData/*15:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_11_0;
    IData/*31:0*/ PE_tb__DOT___Vpast_10_0;
    IData/*31:0*/ PE_tb__DOT__dut__DOT__accum_reg;
    IData/*31:0*/ __Vsampled_TOP__PE_tb__DOT___Vpast_10_0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hdd58016d__0;
    VlTriggerScheduler __VtrigSched_hdd58012c__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPE_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPE_tb___024root(VPE_tb__Syms* symsp, const char* v__name);
    ~VPE_tb___024root();
    VL_UNCOPYABLE(VPE_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
