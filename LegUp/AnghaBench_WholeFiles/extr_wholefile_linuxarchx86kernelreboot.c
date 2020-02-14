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
typedef  int u8 ;
struct pt_regs {int dummy; } ;
typedef  void (* nmi_shootdown_cb ) (int,struct pt_regs*) ;
struct TYPE_2__ {int /*<<< orphan*/  (* halt ) () ;int /*<<< orphan*/  (* restart ) (char*) ;int /*<<< orphan*/  (* shutdown ) () ;int /*<<< orphan*/  (* power_off ) () ;int /*<<< orphan*/  (* emergency_restart ) () ;} ;

/* Variables and functions */
#define  BOOT_ACPI 134 
#define  BOOT_BIOS 133 
#define  BOOT_CF9_FORCE 132 
#define  BOOT_CF9_SAFE 131 
#define  BOOT_EFI 130 
#define  BOOT_KBD 129 
#define  BOOT_TRIPLE 128 
 int /*<<< orphan*/  MRR_BIOS ; 
 scalar_t__ REBOOT_WARM ; 
 int /*<<< orphan*/  TB_SHUTDOWN_HALT ; 
 int /*<<< orphan*/  TB_SHUTDOWN_REBOOT ; 
 scalar_t__ __va (int) ; 
 int /*<<< orphan*/  acpi_reboot () ; 
 int /*<<< orphan*/  cpu_emergency_vmxoff () ; 
 scalar_t__ cpu_has_vmx () ; 
 scalar_t__ cpu_vmx_enabled () ; 
 int /*<<< orphan*/  cpu_vmxoff () ; 
 scalar_t__ efi_capsule_pending (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efi_reboot (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idt_invalidate (int /*<<< orphan*/ *) ; 
 int inb (int) ; 
 int /*<<< orphan*/  lapic_shutdown () ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 TYPE_1__ machine_ops ; 
 int /*<<< orphan*/  machine_real_restart (int /*<<< orphan*/ ) ; 
 void machine_shutdown () ; 
 void nmi_shootdown_cpus (void (*) (int,struct pt_regs*)) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  pm_power_off () ; 
 int port_cf9_safe ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_notice (char*) ; 
 int reboot_emergency ; 
 int /*<<< orphan*/  reboot_force ; 
 scalar_t__ reboot_mode ; 
 int reboot_type ; 
 int /*<<< orphan*/  restore_boot_irq_mode () ; 
 int /*<<< orphan*/  stop_this_cpu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 () ; 
 int /*<<< orphan*/  stub3 () ; 
 int /*<<< orphan*/  stub4 (char*) ; 
 int /*<<< orphan*/  stub5 () ; 
 int /*<<< orphan*/  tboot_shutdown (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void kb_wait(void)
{
	int i;

	for (i = 0; i < 0x10000; i++) {
		if ((inb(0x64) & 0x02) == 0)
			break;
		udelay(2);
	}
}

__attribute__((used)) static void vmxoff_nmi(int cpu, struct pt_regs *regs)
{
	cpu_emergency_vmxoff();
}

__attribute__((used)) static void emergency_vmx_disable_all(void)
{
	/* Just make sure we won't change CPUs while doing this */
	local_irq_disable();

	/*
	 * We need to disable VMX on all CPUs before rebooting, otherwise
	 * we risk hanging up the machine, because the CPU ignore INIT
	 * signals when VMX is enabled.
	 *
	 * We can't take any locks and we may be on an inconsistent
	 * state, so we use NMIs as IPIs to tell the other CPUs to disable
	 * VMX and halt.
	 *
	 * For safety, we will avoid running the nmi_shootdown_cpus()
	 * stuff unnecessarily, but we don't have a way to check
	 * if other CPUs have VMX enabled. So we will call it only if the
	 * CPU we are running on has VMX enabled.
	 *
	 * We will miss cases where VMX is not enabled on all CPUs. This
	 * shouldn't do much harm because KVM always enable VMX on all
	 * CPUs anyway. But we can miss it on the small window where KVM
	 * is still enabling VMX.
	 */
	if (cpu_has_vmx() && cpu_vmx_enabled()) {
		/* Disable VMX on this CPU. */
		cpu_vmxoff();

		/* Halt and disable VMX on the other CPUs */
		nmi_shootdown_cpus(vmxoff_nmi);

	}
}

void __attribute__((weak)) mach_reboot_fixups(void)
{
}

__attribute__((used)) static void native_machine_emergency_restart(void)
{
	int i;
	int attempt = 0;
	int orig_reboot_type = reboot_type;
	unsigned short mode;

	if (reboot_emergency)
		emergency_vmx_disable_all();

	tboot_shutdown(TB_SHUTDOWN_REBOOT);

	/* Tell the BIOS if we want cold or warm reboot */
	mode = reboot_mode == REBOOT_WARM ? 0x1234 : 0;
	*((unsigned short *)__va(0x472)) = mode;

	/*
	 * If an EFI capsule has been registered with the firmware then
	 * override the reboot= parameter.
	 */
	if (efi_capsule_pending(NULL)) {
		pr_info("EFI capsule is pending, forcing EFI reboot.\n");
		reboot_type = BOOT_EFI;
	}

	for (;;) {
		/* Could also try the reset bit in the Hammer NB */
		switch (reboot_type) {
		case BOOT_ACPI:
			acpi_reboot();
			reboot_type = BOOT_KBD;
			break;

		case BOOT_KBD:
			mach_reboot_fixups(); /* For board specific fixups */

			for (i = 0; i < 10; i++) {
				kb_wait();
				udelay(50);
				outb(0xfe, 0x64); /* Pulse reset low */
				udelay(50);
			}
			if (attempt == 0 && orig_reboot_type == BOOT_ACPI) {
				attempt = 1;
				reboot_type = BOOT_ACPI;
			} else {
				reboot_type = BOOT_EFI;
			}
			break;

		case BOOT_EFI:
			efi_reboot(reboot_mode, NULL);
			reboot_type = BOOT_BIOS;
			break;

		case BOOT_BIOS:
			machine_real_restart(MRR_BIOS);

			/* We're probably dead after this, but... */
			reboot_type = BOOT_CF9_SAFE;
			break;

		case BOOT_CF9_FORCE:
			port_cf9_safe = true;
			/* Fall through */

		case BOOT_CF9_SAFE:
			if (port_cf9_safe) {
				u8 reboot_code = reboot_mode == REBOOT_WARM ?  0x06 : 0x0E;
				u8 cf9 = inb(0xcf9) & ~reboot_code;
				outb(cf9|2, 0xcf9); /* Request hard reset */
				udelay(50);
				/* Actually do the reset */
				outb(cf9|reboot_code, 0xcf9);
				udelay(50);
			}
			reboot_type = BOOT_TRIPLE;
			break;

		case BOOT_TRIPLE:
			idt_invalidate(NULL);
			__asm__ __volatile__("int3");

			/* We're probably dead after this, but... */
			reboot_type = BOOT_KBD;
			break;
		}
	}
}

void native_machine_shutdown(void)
{
	/* Stop the cpus and apics */
#ifdef CONFIG_X86_IO_APIC
	/*
	 * Disabling IO APIC before local APIC is a workaround for
	 * erratum AVR31 in "Intel Atom Processor C2000 Product Family
	 * Specification Update". In this situation, interrupts that target
	 * a Logical Processor whose Local APIC is either in the process of
	 * being hardware disabled or software disabled are neither delivered
	 * nor discarded. When this erratum occurs, the processor may hang.
	 *
	 * Even without the erratum, it still makes sense to quiet IO APIC
	 * before disabling Local APIC.
	 */
	clear_IO_APIC();
#endif

#ifdef CONFIG_SMP
	/*
	 * Stop all of the others. Also disable the local irq to
	 * not receive the per-cpu timer interrupt which may trigger
	 * scheduler's load balance.
	 */
	local_irq_disable();
	stop_other_cpus();
#endif

	lapic_shutdown();
	restore_boot_irq_mode();

#ifdef CONFIG_HPET_TIMER
	hpet_disable();
#endif

#ifdef CONFIG_X86_64
	x86_platform.iommu_shutdown();
#endif
}

__attribute__((used)) static void __machine_emergency_restart(int emergency)
{
	reboot_emergency = emergency;
	machine_ops.emergency_restart();
}

__attribute__((used)) static void native_machine_restart(char *__unused)
{
	pr_notice("machine restart\n");

	if (!reboot_force)
		machine_shutdown();
	__machine_emergency_restart(0);
}

__attribute__((used)) static void native_machine_halt(void)
{
	/* Stop other cpus and apics */
	machine_shutdown();

	tboot_shutdown(TB_SHUTDOWN_HALT);

	stop_this_cpu(NULL);
}

__attribute__((used)) static void native_machine_power_off(void)
{
	if (pm_power_off) {
		if (!reboot_force)
			machine_shutdown();
		pm_power_off();
	}
	/* A fallback in case there is no PM info available */
	tboot_shutdown(TB_SHUTDOWN_HALT);
}

void machine_power_off(void)
{
	machine_ops.power_off();
}

void machine_shutdown(void)
{
	machine_ops.shutdown();
}

void machine_emergency_restart(void)
{
	__machine_emergency_restart(1);
}

void machine_restart(char *cmd)
{
	machine_ops.restart(cmd);
}

void machine_halt(void)
{
	machine_ops.halt();
}

void nmi_shootdown_cpus(nmi_shootdown_cb callback)
{
	/* No other CPUs to shoot down */
}

void run_crash_ipi_callback(struct pt_regs *regs)
{
}

