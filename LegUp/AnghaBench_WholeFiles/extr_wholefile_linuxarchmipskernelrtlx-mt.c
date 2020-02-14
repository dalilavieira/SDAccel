#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  rt_queue; int /*<<< orphan*/  lx_queue; } ;

/* Variables and functions */
 int C_SW0 ; 
 unsigned int EVPE_ENABLE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ MIPS_CPU_IRQ_BASE ; 
 int MIPS_CPU_RTLX_IRQ ; 
 int RTLX_CHANNELS ; 
 TYPE_1__* channel_wqs ; 
 int /*<<< orphan*/  do_IRQ (scalar_t__) ; 
 unsigned int dvpe () ; 
 int /*<<< orphan*/  evpe (unsigned int) ; 
 int /*<<< orphan*/  irq_enable_hazard () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int read_c0_cause () ; 
 int read_c0_status () ; 
 int read_vpe_c0_cause () ; 
 int /*<<< orphan*/  set_c0_status (int) ; 
 int /*<<< orphan*/  settc (int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_vpe_c0_cause (int) ; 

__attribute__((used)) static void rtlx_dispatch(void)
{
	if (read_c0_cause() & read_c0_status() & C_SW0)
		do_IRQ(MIPS_CPU_IRQ_BASE + MIPS_CPU_RTLX_IRQ);
}

__attribute__((used)) static irqreturn_t rtlx_interrupt(int irq, void *dev_id)
{
	unsigned int vpeflags;
	unsigned long flags;
	int i;

	local_irq_save(flags);
	vpeflags = dvpe();
	set_c0_status(0x100 << MIPS_CPU_RTLX_IRQ);
	irq_enable_hazard();
	evpe(vpeflags);
	local_irq_restore(flags);

	for (i = 0; i < RTLX_CHANNELS; i++) {
		wake_up(&channel_wqs[i].lx_queue);
		wake_up(&channel_wqs[i].rt_queue);
	}

	return IRQ_HANDLED;
}

void _interrupt_sp(void)
{
	unsigned long flags;

	local_irq_save(flags);
	dvpe();
	settc(1);
	write_vpe_c0_cause(read_vpe_c0_cause() | C_SW0);
	evpe(EVPE_ENABLE);
	local_irq_restore(flags);
}

