// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPE_TB__SYMS_H_
#define VERILATED_VPE_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "VPE_tb.h"

// INCLUDE MODULE CLASSES
#include "VPE_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VPE_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPE_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPE_tb___024root               TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_PE_tb;
    VerilatedScope __Vscope_PE_tb__a_forwarding;
    VerilatedScope __Vscope_PE_tb__a_product_bubble;
    VerilatedScope __Vscope_PE_tb__a_product_capture;
    VerilatedScope __Vscope_PE_tb__a_product_clear;

    // CONSTRUCTORS
    VPE_tb__Syms(VerilatedContext* contextp, const char* namep, VPE_tb* modelp);
    ~VPE_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
