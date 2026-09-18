// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VPE_tb__pch.h"
#include "VPE_tb.h"
#include "VPE_tb___024root.h"

// FUNCTIONS
VPE_tb__Syms::~VPE_tb__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void VPE_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void VPE_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void VPE_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

VPE_tb__Syms::VPE_tb__Syms(VerilatedContext* contextp, const char* namep, VPE_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(31);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_PE_tb.configure(this, name(), "PE_tb", "PE_tb", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_accumulator_output.configure(this, name(), "PE_tb.a_accumulator_output", "a_accumulator_output", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_forwarding.configure(this, name(), "PE_tb.a_forwarding", "a_forwarding", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_forwarding_hold.configure(this, name(), "PE_tb.a_forwarding_hold", "a_forwarding_hold", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_forwarding_outputs.configure(this, name(), "PE_tb.a_forwarding_outputs", "a_forwarding_outputs", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_invalid_product_holds_accumulator.configure(this, name(), "PE_tb.a_invalid_product_holds_accumulator", "a_invalid_product_holds_accumulator", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_product_bubble.configure(this, name(), "PE_tb.a_product_bubble", "a_product_bubble", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_product_capture.configure(this, name(), "PE_tb.a_product_capture", "a_product_capture", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_PE_tb__a_product_clear.configure(this, name(), "PE_tb.a_product_clear", "a_product_clear", "<null>", -9, VerilatedScope::SCOPE_OTHER);
}
