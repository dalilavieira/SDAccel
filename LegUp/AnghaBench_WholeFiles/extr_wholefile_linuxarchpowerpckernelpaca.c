#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */

__attribute__((used)) static inline void setup_power_save(void) { }

__attribute__((used)) static inline void check_smt_enabled(void) { }

__attribute__((used)) static inline void setup_tlb_core_data(void) { }

__attribute__((used)) static inline void exc_lvl_early_init(void) { }

__attribute__((used)) static inline void emergency_stack_init(void) { }

__attribute__((used)) static inline void kvm_cma_reserve(void) { }

