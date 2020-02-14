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
typedef  int u32 ;
struct cpufreq_policy {scalar_t__ cpu; TYPE_1__* freq_table; } ;
struct TYPE_4__ {int event; } ;
struct TYPE_3__ {int frequency; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int GET_SPEEDSTEP_FREQS ; 
 int GET_SPEEDSTEP_OWNER ; 
 unsigned int SET_SPEEDSTEP_STATE ; 
 unsigned int SMI_TRIES ; 
 size_t SPEEDSTEP_HIGH ; 
 size_t SPEEDSTEP_LOW ; 
 TYPE_2__ ist_info ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mdelay (unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int smi_cmd ; 
 int /*<<< orphan*/  smi_port ; 
 int smi_sig ; 
 TYPE_1__* speedstep_freqs ; 
 int speedstep_get_freqs (int /*<<< orphan*/ ,unsigned int*,unsigned int*,int /*<<< orphan*/ *,void (*) (unsigned int)) ; 
 unsigned int speedstep_get_frequency (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  speedstep_processor ; 
 int virt_to_phys (unsigned char*) ; 

__attribute__((used)) static int speedstep_smi_ownership(void)
{
	u32 command, result, magic, dummy;
	u32 function = GET_SPEEDSTEP_OWNER;
	unsigned char magic_data[] = "Copyright (c) 1999 Intel Corporation";

	command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);
	magic = virt_to_phys(magic_data);

	pr_debug("trying to obtain ownership with command %x at port %x\n",
			command, smi_port);

	__asm__ __volatile__(
		"push %%ebp\n"
		"out %%al, (%%dx)\n"
		"pop %%ebp\n"
		: "=D" (result),
		  "=a" (dummy), "=b" (dummy), "=c" (dummy), "=d" (dummy),
		  "=S" (dummy)
		: "a" (command), "b" (function), "c" (0), "d" (smi_port),
		  "D" (0), "S" (magic)
		: "memory"
	);

	pr_debug("result is %x\n", result);

	return result;
}

__attribute__((used)) static int speedstep_smi_get_freqs(unsigned int *low, unsigned int *high)
{
	u32 command, result = 0, edi, high_mhz, low_mhz, dummy;
	u32 state = 0;
	u32 function = GET_SPEEDSTEP_FREQS;

	if (!(ist_info.event & 0xFFFF)) {
		pr_debug("bug #1422 -- can't read freqs from BIOS\n");
		return -ENODEV;
	}

	command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);

	pr_debug("trying to determine frequencies with command %x at port %x\n",
			command, smi_port);

	__asm__ __volatile__(
		"push %%ebp\n"
		"out %%al, (%%dx)\n"
		"pop %%ebp"
		: "=a" (result),
		  "=b" (high_mhz),
		  "=c" (low_mhz),
		  "=d" (state), "=D" (edi), "=S" (dummy)
		: "a" (command),
		  "b" (function),
		  "c" (state),
		  "d" (smi_port), "S" (0), "D" (0)
	);

	pr_debug("result %x, low_freq %u, high_freq %u\n",
			result, low_mhz, high_mhz);

	/* abort if results are obviously incorrect... */
	if ((high_mhz + low_mhz) < 600)
		return -EINVAL;

	*high = high_mhz * 1000;
	*low  = low_mhz  * 1000;

	return result;
}

__attribute__((used)) static void speedstep_set_state(unsigned int state)
{
	unsigned int result = 0, command, new_state, dummy;
	unsigned long flags;
	unsigned int function = SET_SPEEDSTEP_STATE;
	unsigned int retry = 0;

	if (state > 0x1)
		return;

	/* Disable IRQs */
	preempt_disable();
	local_irq_save(flags);

	command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);

	pr_debug("trying to set frequency to state %u "
		"with command %x at port %x\n",
		state, command, smi_port);

	do {
		if (retry) {
			/*
			 * We need to enable interrupts, otherwise the blockage
			 * won't resolve.
			 *
			 * We disable preemption so that other processes don't
			 * run. If other processes were running, they could
			 * submit more DMA requests, making the blockage worse.
			 */
			pr_debug("retry %u, previous result %u, waiting...\n",
					retry, result);
			local_irq_enable();
			mdelay(retry * 50);
			local_irq_disable();
		}
		retry++;
		__asm__ __volatile__(
			"push %%ebp\n"
			"out %%al, (%%dx)\n"
			"pop %%ebp"
			: "=b" (new_state), "=D" (result),
			  "=c" (dummy), "=a" (dummy),
			  "=d" (dummy), "=S" (dummy)
			: "a" (command), "b" (function), "c" (state),
			  "d" (smi_port), "S" (0), "D" (0)
			);
	} while ((new_state != state) && (retry <= SMI_TRIES));

	/* enable IRQs */
	local_irq_restore(flags);
	preempt_enable();

	if (new_state == state)
		pr_debug("change to %u MHz succeeded after %u tries "
			"with result %u\n",
			(speedstep_freqs[new_state].frequency / 1000),
			retry, result);
	else
		pr_err("change to state %u failed with new_state %u and result %u\n",
		       state, new_state, result);

	return;
}

__attribute__((used)) static int speedstep_target(struct cpufreq_policy *policy, unsigned int index)
{
	speedstep_set_state(index);

	return 0;
}

__attribute__((used)) static int speedstep_cpu_init(struct cpufreq_policy *policy)
{
	int result;
	unsigned int *low, *high;

	/* capability check */
	if (policy->cpu != 0)
		return -ENODEV;

	result = speedstep_smi_ownership();
	if (result) {
		pr_debug("fails in acquiring ownership of a SMI interface.\n");
		return -EINVAL;
	}

	/* detect low and high frequency */
	low = &speedstep_freqs[SPEEDSTEP_LOW].frequency;
	high = &speedstep_freqs[SPEEDSTEP_HIGH].frequency;

	result = speedstep_smi_get_freqs(low, high);
	if (result) {
		/* fall back to speedstep_lib.c dection mechanism:
		 * try both states out */
		pr_debug("could not detect low and high frequencies "
				"by SMI call.\n");
		result = speedstep_get_freqs(speedstep_processor,
				low, high,
				NULL,
				&speedstep_set_state);

		if (result) {
			pr_debug("could not detect two different speeds"
					" -- aborting.\n");
			return result;
		} else
			pr_debug("workaround worked.\n");
	}

	policy->freq_table = speedstep_freqs;

	return 0;
}

__attribute__((used)) static unsigned int speedstep_get(unsigned int cpu)
{
	if (cpu)
		return -ENODEV;
	return speedstep_get_frequency(speedstep_processor);
}

__attribute__((used)) static int speedstep_resume(struct cpufreq_policy *policy)
{
	int result = speedstep_smi_ownership();

	if (result)
		pr_debug("fails in re-acquiring ownership of a SMI interface.\n");

	return result;
}

