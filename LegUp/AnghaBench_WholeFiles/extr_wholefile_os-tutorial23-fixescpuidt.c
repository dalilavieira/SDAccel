#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  idt_gate_t ;
struct TYPE_4__ {int flags; int /*<<< orphan*/  high_offset; scalar_t__ always0; int /*<<< orphan*/  sel; int /*<<< orphan*/  low_offset; } ;
struct TYPE_3__ {int limit; scalar_t__ base; } ;

/* Variables and functions */
 int IDT_ENTRIES ; 
 int /*<<< orphan*/  KERNEL_CS ; 
 int /*<<< orphan*/  high_16 (scalar_t__) ; 
 TYPE_2__* idt ; 
 TYPE_1__ idt_reg ; 
 int /*<<< orphan*/  low_16 (scalar_t__) ; 

void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = high_16(handler);
}

void set_idt() {
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    /* Don't make the mistake of loading &idt -- always load &idt_reg */
    asm volatile("lidtl (%0)" : : "r" (&idt_reg));
}

