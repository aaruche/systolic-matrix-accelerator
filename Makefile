# MiniMat build and run entry point. `make help` lists targets.
#
# Options (set on the command line, e.g. `make top COVERAGE=1`):
#   COVERAGE=1    build with --coverage-user so cover properties are counted
#   XRAND=1       random power-up state instead of zeros (use with SEED)
#   SEED=N        Verilator random seed (default 1)
#   ERRLIMIT=N    keep running past the first N-1 $error (default 1)
#   SEEDS="1 2"   seed list for the `seeds-*` targets

VERILATOR ?= verilator
BUILD     ?= build

COVERAGE ?= 0
XRAND    ?= 0
SEED     ?= 1
ERRLIMIT ?= 1
SEEDS    ?= 1 2 3 4 5

RTL_PE  := src/PE.v
RTL_TOP := src/PE_Top.v src/PE.v

VFLAGS := --binary --timing --assert --trace --timescale 1ns/1ps -Wno-fatal -Itb
RUNARGS := +verilator+error+limit+$(ERRLIMIT)
VARIANT :=

ifeq ($(COVERAGE),1)
  VFLAGS  += --coverage-user
  VARIANT := $(VARIANT)_cov
endif
ifeq ($(XRAND),1)
  VFLAGS  += --x-assign unique --x-initial unique
  RUNARGS += +verilator+rand+reset+2 +verilator+seed+$(SEED)
  VARIANT := $(VARIANT)_xrand
endif

PE_DIR  := $(BUILD)/pe$(VARIANT)
TOP_DIR := $(BUILD)/top$(VARIANT)

# Build dirs used by the seeds-* targets (always the XRAND=1 variant).
SEED_VARIANT := $(if $(filter 1,$(COVERAGE)),_cov)_xrand

.PHONY: help all pe top build-pe build-top seeds-pe seeds-top lint synth wave-pe wave-top clean

help:
	@echo "make pe         build + run PE unit test      (waves: $(BUILD)/pe*/PE_tb.vcd)"
	@echo "make top        build + run PE_Top array test (waves: $(BUILD)/top*/PE_Top_tb.vcd)"
	@echo "make all        pe + top"
	@echo "make seeds-pe   run PE test with random power-up for each of SEEDS"
	@echo "make seeds-top  run PE_Top test with random power-up for each of SEEDS"
	@echo "make lint       verilator -Wall lint of the RTL"
	@echo "make synth      yosys generic synth + stat (check for latches)"
	@echo "make wave-pe / wave-top   open the last waves in gtkwave"
	@echo "make clean      remove $(BUILD)/"
	@echo "Options: COVERAGE=1 XRAND=1 SEED=N ERRLIMIT=N SEEDS=\"...\""

all: pe top

# Builds always rerun: Verilator is fast and this avoids stale binaries.
build-pe:
	@mkdir -p $(BUILD)
	$(VERILATOR) $(VFLAGS) --top-module PE_tb --Mdir $(PE_DIR) tb/PE_tb.sv $(RTL_PE)

build-top:
	@mkdir -p $(BUILD)
	$(VERILATOR) $(VFLAGS) --top-module PE_Top_tb --Mdir $(TOP_DIR) tb/PE_Top_tb.sv $(RTL_TOP)

# Sims run inside their build dir so VCD and coverage.dat land there.
pe: build-pe
	cd $(PE_DIR) && ./VPE_tb $(RUNARGS)

top: build-top
	cd $(TOP_DIR) && ./VPE_Top_tb $(RUNARGS)

seeds-pe:
	$(MAKE) --no-print-directory build-pe XRAND=1
	@for s in $(SEEDS); do \
	  echo "== seed $$s =="; \
	  (cd $(BUILD)/pe$(SEED_VARIANT) && \
	   ./VPE_tb +verilator+error+limit+$(ERRLIMIT) +verilator+rand+reset+2 +verilator+seed+$$s) || exit 1; \
	done

seeds-top:
	$(MAKE) --no-print-directory build-top XRAND=1
	@for s in $(SEEDS); do \
	  echo "== seed $$s =="; \
	  (cd $(BUILD)/top$(SEED_VARIANT) && \
	   ./VPE_Top_tb +verilator+error+limit+$(ERRLIMIT) +verilator+rand+reset+2 +verilator+seed+$$s) || exit 1; \
	done

lint:
	$(VERILATOR) --lint-only -Wall --top-module PE_Top $(RTL_TOP)

synth:
	yosys -p "read_verilog $(RTL_TOP); synth -top PE_Top; stat"

wave-pe:
	gtkwave $(PE_DIR)/PE_tb.vcd

wave-top:
	gtkwave $(TOP_DIR)/PE_Top_tb.vcd PE_Top_tb.vcd.gtkw

clean:
	rm -rf $(BUILD)
