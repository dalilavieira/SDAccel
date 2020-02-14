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
struct pt_regs {int dummy; } ;
struct op_system_config {int /*<<< orphan*/  enable_user; int /*<<< orphan*/  enable_kernel; int /*<<< orphan*/  enable_pal; } ;
struct op_register_config {int mux_select; int proc_mode; int freq; int reset_values; int need_reset; unsigned long enable; } ;
struct op_counter_config {unsigned long event; unsigned long count; int /*<<< orphan*/  enabled; } ;

/* Variables and functions */
 int /*<<< orphan*/  oprofile_add_sample (struct pt_regs*,unsigned long) ; 
 unsigned long wrperfmon (int,unsigned long) ; 

__attribute__((used)) static void
common_reg_setup(struct op_register_config *reg,
		 struct op_counter_config *ctr,
		 struct op_system_config *sys,
		 int cbox1_ofs, int cbox2_ofs)
{
	int i, ctl, reset, need_reset;

	/* Select desired events.  The event numbers are selected such
	   that they map directly into the event selection fields:

		PCSEL0:	0, 1
		PCSEL1:	24-39
		 CBOX1: 40-47
		PCSEL2: 48-63
		 CBOX2: 64-71

	   There are two special cases, in that CYCLES can be measured
	   on PCSEL[02], and SCACHE_WRITE can be measured on CBOX[12].
	   These event numbers are canonicalizes to their first appearance.  */

	ctl = 0;
	for (i = 0; i < 3; ++i) {
		unsigned long event = ctr[i].event;
		if (!ctr[i].enabled)
			continue;

		/* Remap the duplicate events, as described above.  */
		if (i == 2) {
			if (event == 0)
				event = 12+48;
			else if (event == 2+41)
				event = 4+65;
		}

		/* Convert the event numbers onto mux_select bit mask.  */
		if (event < 2)
			ctl |= event << 31;
		else if (event < 24)
			/* error */;
		else if (event < 40)
			ctl |= (event - 24) << 4;
		else if (event < 48)
			ctl |= (event - 40) << cbox1_ofs | 15 << 4;
		else if (event < 64)
			ctl |= event - 48;
		else if (event < 72)
			ctl |= (event - 64) << cbox2_ofs | 15;
	}
	reg->mux_select = ctl;

	/* Select processor mode.  */
	/* ??? Need to come up with some mechanism to trace only selected
	   processes.  For now select from pal, kernel and user mode.  */
	ctl = 0;
	ctl |= !sys->enable_pal << 9;
	ctl |= !sys->enable_kernel << 8;
	ctl |= !sys->enable_user << 30;
	reg->proc_mode = ctl;

	/* Select interrupt frequencies.  Take the interrupt count selected
	   by the user, and map it onto one of the possible counter widths.
	   If the user value is in between, compute a value to which the
	   counter is reset at each interrupt.  */

	ctl = reset = need_reset = 0;
	for (i = 0; i < 3; ++i) {
		unsigned long max, hilo, count = ctr[i].count;
		if (!ctr[i].enabled)
			continue;

		if (count <= 256)
			count = 256, hilo = 3, max = 256;
		else {
			max = (i == 2 ? 16384 : 65536);
			hilo = 2;
			if (count > max)
				count = max;
		}
		ctr[i].count = count;

		ctl |= hilo << (8 - i*2);
		reset |= (max - count) << (48 - 16*i);
		if (count != max)
			need_reset |= 1 << i;
	}
	reg->freq = ctl;
	reg->reset_values = reset;
	reg->need_reset = need_reset;
}

__attribute__((used)) static void
ev5_reg_setup(struct op_register_config *reg,
	      struct op_counter_config *ctr,
	      struct op_system_config *sys)
{
	common_reg_setup(reg, ctr, sys, 19, 22);
}

__attribute__((used)) static void
pca56_reg_setup(struct op_register_config *reg,
	        struct op_counter_config *ctr,
	        struct op_system_config *sys)
{
	common_reg_setup(reg, ctr, sys, 8, 11);
}

__attribute__((used)) static void
ev5_cpu_setup (void *x)
{
	struct op_register_config *reg = x;

	wrperfmon(2, reg->mux_select);
	wrperfmon(3, reg->proc_mode);
	wrperfmon(4, reg->freq);
	wrperfmon(6, reg->reset_values);
}

__attribute__((used)) static void
ev5_reset_ctr(struct op_register_config *reg, unsigned long ctr)
{
	unsigned long values, mask, not_pk, reset_values;

	mask = (ctr == 0 ? 0xfffful << 48
	        : ctr == 1 ? 0xfffful << 32
		: 0x3fff << 16);

	not_pk = 1 << 9 | 1 << 8;

	reset_values = reg->reset_values;

	if ((reg->proc_mode & not_pk) == not_pk) {
		values = wrperfmon(5, 0);
		values = (reset_values & mask) | (values & ~mask & -2);
		wrperfmon(6, values);
	} else {
		wrperfmon(0, -1);
		values = wrperfmon(5, 0);
		values = (reset_values & mask) | (values & ~mask & -2);
		wrperfmon(6, values);
		wrperfmon(1, reg->enable);
	}
}

__attribute__((used)) static void
ev5_handle_interrupt(unsigned long which, struct pt_regs *regs,
		     struct op_counter_config *ctr)
{
	/* Record the sample.  */
	oprofile_add_sample(regs, which);
}

