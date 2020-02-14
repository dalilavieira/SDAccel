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
typedef  scalar_t__ u64 ;
struct s390_idle_data {int dummy; } ;
struct TYPE_2__ {scalar_t__ clock_comparator; } ;

/* Variables and functions */
 int /*<<< orphan*/  CIF_IGNORE_IRQ ; 
 unsigned long CR0_IRQ_SUBCLASS_MASK ; 
 unsigned long PSW_MASK_EXT ; 
 unsigned long PSW_MASK_WAIT ; 
 TYPE_1__ S390_lowcore ; 
 int /*<<< orphan*/  __ctl_load (unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __ctl_store (unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long __extract_psw () ; 
 int /*<<< orphan*/  _local_bh_enable () ; 
 int /*<<< orphan*/  barrier () ; 
 int /*<<< orphan*/  clear_cpu_flag (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  do_div (unsigned long long,int) ; 
 int /*<<< orphan*/  enabled_wait () ; 
 scalar_t__ get_tod_clock () ; 
 scalar_t__ get_tod_clock_fast () ; 
 scalar_t__ in_irq () ; 
 scalar_t__ in_softirq () ; 
 int /*<<< orphan*/  local_bh_disable () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 scalar_t__ local_tick_disable () ; 
 int /*<<< orphan*/  local_tick_enable (scalar_t__) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  psw_idle (struct s390_idle_data*,unsigned long) ; 
 scalar_t__ raw_irqs_disabled_flags (unsigned long) ; 
 int /*<<< orphan*/  set_clock_comparator (scalar_t__) ; 
 int /*<<< orphan*/  set_cpu_flag (int /*<<< orphan*/ ) ; 
 scalar_t__ tod_after (scalar_t__,scalar_t__) ; 

void __delay(unsigned long loops)
{
        /*
         * To end the bloody studid and useless discussion about the
         * BogoMips number I took the liberty to define the __delay
         * function in a way that that resulting BogoMips number will
         * yield the megahertz number of the cpu. The important function
         * is udelay and that is done using the tod clock. -- martin.
         */
	asm volatile("0: brct %0,0b" : : "d" ((loops/2) + 1));
}

__attribute__((used)) static void __udelay_disabled(unsigned long long usecs)
{
	unsigned long cr0, cr0_new, psw_mask;
	struct s390_idle_data idle;
	u64 end;

	end = get_tod_clock() + (usecs << 12);
	__ctl_store(cr0, 0, 0);
	cr0_new = cr0 & ~CR0_IRQ_SUBCLASS_MASK;
	cr0_new |= (1UL << (63 - 52)); /* enable clock comparator irq */
	__ctl_load(cr0_new, 0, 0);
	psw_mask = __extract_psw() | PSW_MASK_EXT | PSW_MASK_WAIT;
	set_clock_comparator(end);
	set_cpu_flag(CIF_IGNORE_IRQ);
	psw_idle(&idle, psw_mask);
	clear_cpu_flag(CIF_IGNORE_IRQ);
	set_clock_comparator(S390_lowcore.clock_comparator);
	__ctl_load(cr0, 0, 0);
}

__attribute__((used)) static void __udelay_enabled(unsigned long long usecs)
{
	u64 clock_saved, end;

	end = get_tod_clock_fast() + (usecs << 12);
	do {
		clock_saved = 0;
		if (tod_after(S390_lowcore.clock_comparator, end)) {
			clock_saved = local_tick_disable();
			set_clock_comparator(end);
		}
		enabled_wait();
		if (clock_saved)
			local_tick_enable(clock_saved);
	} while (get_tod_clock_fast() < end);
}

void __udelay(unsigned long long usecs)
{
	unsigned long flags;

	preempt_disable();
	local_irq_save(flags);
	if (in_irq()) {
		__udelay_disabled(usecs);
		goto out;
	}
	if (in_softirq()) {
		if (raw_irqs_disabled_flags(flags))
			__udelay_disabled(usecs);
		else
			__udelay_enabled(usecs);
		goto out;
	}
	if (raw_irqs_disabled_flags(flags)) {
		local_bh_disable();
		__udelay_disabled(usecs);
		_local_bh_enable();
		goto out;
	}
	__udelay_enabled(usecs);
out:
	local_irq_restore(flags);
	preempt_enable();
}

void udelay_simple(unsigned long long usecs)
{
	u64 end;

	end = get_tod_clock_fast() + (usecs << 12);
	while (get_tod_clock_fast() < end)
		cpu_relax();
}

void __ndelay(unsigned long long nsecs)
{
	u64 end;

	nsecs <<= 9;
	do_div(nsecs, 125);
	end = get_tod_clock_fast() + nsecs;
	if (nsecs & ~0xfffUL)
		__udelay(nsecs >> 12);
	while (get_tod_clock_fast() < end)
		barrier();
}

