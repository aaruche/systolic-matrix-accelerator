// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_tb.h for the primary calling header

#include "VPE_tb__pch.h"
#include "VPE_tb__Syms.h"
#include "VPE_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VPE_tb___024root___dump_triggers__act(VPE_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VPE_tb___024root___eval_triggers__act(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.PE_tb__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__PE_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.PE_tb__DOT__clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__PE_tb__DOT__clk__0)));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__PE_tb__DOT__clk__0 
        = vlSelfRef.PE_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPE_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VPE_tb___024root___nba_sequent__TOP__0(VPE_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPE_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPE_tb___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__PE_tb__DOT__dut__DOT__accum_reg;
    __Vdly__PE_tb__DOT__dut__DOT__accum_reg = 0;
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_12_0)) 
                                     | (0U == vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:101: Assertion failed in %NPE_tb: Accumulator was not cleared\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 101, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_9_0)) 
                                     | (vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg 
                                        == (vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_10_0 
                                            + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_11_0)))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:90: Assertion failed in %NPE_tb: Accumulator did not add the previous valid product\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 90, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_8_0)) 
                                     | (~ (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg)))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:75: Assertion failed in %NPE_tb.a_product_bubble: Product-valid was not cleared after a bubble\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 75, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_1_0)) 
                                     | (((IData)(vlSelfRef.PE_tb__DOT__dut__DOT__A_forw_reg) 
                                         == (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_2_0)) 
                                        & ((IData)(vlSelfRef.PE_tb__DOT__dut__DOT__B_forw_reg) 
                                           == (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_3_0))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:29: Assertion failed in %NPE_tb.a_forwarding: Operand forwarding property failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 29, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_4_0)) 
                                     | ((0U == (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg)) 
                                        & (~ (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:45: Assertion failed in %NPE_tb.a_product_clear: Product pipeline was not cleared\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 45, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)) 
                                  | ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_5_0)) 
                                     | (((IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg) 
                                         == (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_6_0))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_7_0)))))) 
                                        & (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg)))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:61: Assertion failed in %NPE_tb.a_product_capture: Product capture failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 61, "");
        }
    }
    __Vdly__PE_tb__DOT__dut__DOT__accum_reg = vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg;
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT___Vpast_0_0)) 
                                  | (((((0U == (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__A_forw_reg)) 
                                        & (0U == (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__B_forw_reg))) 
                                       & (0U == (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg))) 
                                      & (~ (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg))) 
                                     & (0U == vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg))))))) {
            VL_WRITEF_NX("[%0t] %%Error: PE_sva.sv:14: Assertion failed in %NPE_tb: Reset operation failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/PE_sva.sv", 14, "");
        }
    }
    vlSelfRef.PE_tb__DOT___Vpast_2_0 = vlSelfRef.__Vsampled_TOP__PE_tb__DOT__A;
    vlSelfRef.PE_tb__DOT___Vpast_3_0 = vlSelfRef.__Vsampled_TOP__PE_tb__DOT__B;
    vlSelfRef.PE_tb__DOT___Vpast_6_0 = vlSelfRef.__Vsampled_TOP__PE_tb__DOT__A;
    vlSelfRef.PE_tb__DOT___Vpast_7_0 = vlSelfRef.__Vsampled_TOP__PE_tb__DOT__B;
    vlSelfRef.PE_tb__DOT___Vpast_10_0 = vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg;
    vlSelfRef.PE_tb__DOT___Vpast_0_0 = (1U & (~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n)));
    vlSelfRef.PE_tb__DOT___Vpast_4_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                        & (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr));
    vlSelfRef.PE_tb__DOT___Vpast_12_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                         & (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr));
    vlSelfRef.PE_tb__DOT___Vpast_1_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                        & ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__pe_valid) 
                                           & (~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr))));
    vlSelfRef.PE_tb__DOT___Vpast_5_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                        & ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__pe_valid) 
                                           & (~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr))));
    vlSelfRef.PE_tb__DOT___Vpast_8_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                        & ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__pe_valid)) 
                                           & (~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr))));
    vlSelfRef.PE_tb__DOT___Vpast_11_0 = vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg;
    if (vlSelfRef.PE_tb__DOT__rst_n) {
        if (vlSelfRef.PE_tb__DOT__accum_clr) {
            __Vdly__PE_tb__DOT__dut__DOT__accum_reg = 0U;
            vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg = 0U;
        } else {
            if (vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg) {
                __Vdly__PE_tb__DOT__dut__DOT__accum_reg 
                    = (vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg)));
            }
            if (vlSelfRef.PE_tb__DOT__pe_valid) {
                vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg 
                    = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                  & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_tb__DOT__A))), 
                                             (0xffffU 
                                              & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.PE_tb__DOT__B)))));
            }
        }
        if (((IData)(vlSelfRef.PE_tb__DOT__pe_valid) 
             & (~ (IData)(vlSelfRef.PE_tb__DOT__accum_clr)))) {
            vlSelfRef.PE_tb__DOT__dut__DOT__A_forw_reg 
                = vlSelfRef.PE_tb__DOT__A;
            vlSelfRef.PE_tb__DOT__dut__DOT__B_forw_reg 
                = vlSelfRef.PE_tb__DOT__B;
        }
    } else {
        __Vdly__PE_tb__DOT__dut__DOT__accum_reg = 0U;
        vlSelfRef.PE_tb__DOT__dut__DOT__A_forw_reg = 0U;
        vlSelfRef.PE_tb__DOT__dut__DOT__B_forw_reg = 0U;
        vlSelfRef.PE_tb__DOT__dut__DOT__mult_reg = 0U;
    }
    vlSelfRef.PE_tb__DOT___Vpast_9_0 = ((IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__rst_n) 
                                        & ((~ (IData)(vlSelfRef.__Vsampled_TOP__PE_tb__DOT__accum_clr)) 
                                           & (IData)(vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg)));
    vlSelfRef.PE_tb__DOT__dut__DOT__accum_reg = __Vdly__PE_tb__DOT__dut__DOT__accum_reg;
    vlSelfRef.PE_tb__DOT__dut__DOT__mult_valid_reg 
        = ((IData)(vlSelfRef.PE_tb__DOT__rst_n) && 
           ((1U & (~ (IData)(vlSelfRef.PE_tb__DOT__accum_clr))) 
            && (IData)(vlSelfRef.PE_tb__DOT__pe_valid)));
}
