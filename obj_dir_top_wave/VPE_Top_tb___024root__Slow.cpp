// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPE_Top_tb.h for the primary calling header

#include "VPE_Top_tb__pch.h"
#include "VPE_Top_tb__Syms.h"
#include "VPE_Top_tb___024root.h"

void VPE_Top_tb___024root___ctor_var_reset(VPE_Top_tb___024root* vlSelf);

VPE_Top_tb___024root::VPE_Top_tb___024root(VPE_Top_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPE_Top_tb___024root___ctor_var_reset(this);
}

void VPE_Top_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VPE_Top_tb___024root::~VPE_Top_tb___024root() {
}
