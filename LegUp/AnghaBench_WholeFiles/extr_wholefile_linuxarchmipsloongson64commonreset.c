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
 int /*<<< orphan*/  LOONGSON_BOOT_BASE ; 
 int /*<<< orphan*/  cpu_wait () ; 
 scalar_t__ ioremap_nocache (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mach_prepare_reboot () ; 
 int /*<<< orphan*/  mach_prepare_shutdown () ; 
 int /*<<< orphan*/  pr_notice (char*) ; 
 void stub1 () ; 

__attribute__((used)) static inline void loongson_reboot(void)
{
#ifndef CONFIG_CPU_JUMP_WORKAROUNDS
	((void (*)(void))ioremap_nocache(LOONGSON_BOOT_BASE, 4)) ();
#else
	void (*func)(void);

	func = (void *)ioremap_nocache(LOONGSON_BOOT_BASE, 4);

	__asm__ __volatile__(
	"	.set	noat						\n"
	"	jr	%[func]						\n"
	"	.set	at						\n"
	: /* No outputs */
	: [func] "r" (func));
#endif
}

__attribute__((used)) static void loongson_restart(char *command)
{
#ifndef CONFIG_LEFI_FIRMWARE_INTERFACE
	/* do preparation for reboot */
	mach_prepare_reboot();

	/* reboot via jumping to boot base address */
	loongson_reboot();
#else
	void (*fw_restart)(void) = (void *)loongson_sysconf.restart_addr;

	fw_restart();
	while (1) {
		if (cpu_wait)
			cpu_wait();
	}
#endif
}

__attribute__((used)) static void loongson_poweroff(void)
{
#ifndef CONFIG_LEFI_FIRMWARE_INTERFACE
	mach_prepare_shutdown();

	/*
	 * It needs a wait loop here, but mips/kernel/reset.c already calls
	 * a generic delay loop, machine_hang(), so simply return.
	 */
	return;
#else
	void (*fw_poweroff)(void) = (void *)loongson_sysconf.poweroff_addr;

	fw_poweroff();
	while (1) {
		if (cpu_wait)
			cpu_wait();
	}
#endif
}

__attribute__((used)) static void loongson_halt(void)
{
	pr_notice("\n\n** You can safely turn off the power now **\n\n");
	while (1) {
		if (cpu_wait)
			cpu_wait();
	}
}

