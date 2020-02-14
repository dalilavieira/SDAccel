#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ regs; } ;
struct task_struct {TYPE_1__ thread; } ;
struct pvr_s {int dummy; } ;
struct pt_regs {unsigned long pc; } ;
struct TYPE_5__ {unsigned long* pvr; } ;

/* Variables and functions */
 size_t GDB_BTR ; 
 unsigned int GDB_PVR ; 
 size_t GDB_REDR ; 
 size_t GDB_RPID ; 
 size_t GDB_RTLBHI ; 
 size_t GDB_RTLBLO ; 
 size_t GDB_RTLBX ; 
 size_t GDB_RZPR ; 
 int /*<<< orphan*/  get_pvr (TYPE_2__*) ; 
 int /*<<< orphan*/  kgdb_hex2long (char**,unsigned long*) ; 
 TYPE_2__ pvr ; 

void pt_regs_to_gdb_regs(unsigned long *gdb_regs, struct pt_regs *regs)
{
	unsigned int i;
	unsigned long *pt_regb = (unsigned long *)regs;
	int temp;

	/* registers r0 - r31, pc, msr, ear, esr, fsr + do not save pt_mode */
	for (i = 0; i < (sizeof(struct pt_regs) / 4) - 1; i++)
		gdb_regs[i] = pt_regb[i];

	/* Branch target register can't be changed */
	__asm__ __volatile__ ("mfs %0, rbtr;" : "=r"(temp) : );
	gdb_regs[GDB_BTR] = temp;

	/* pvr part  - we have 11 pvr regs */
	for (i = 0; i < sizeof(struct pvr_s)/4; i++)
		gdb_regs[GDB_PVR + i] = pvr.pvr[i];

	/* read special registers - can't be changed */
	__asm__ __volatile__ ("mfs %0, redr;" : "=r"(temp) : );
	gdb_regs[GDB_REDR] = temp;
	__asm__ __volatile__ ("mfs %0, rpid;" : "=r"(temp) : );
	gdb_regs[GDB_RPID] = temp;
	__asm__ __volatile__ ("mfs %0, rzpr;" : "=r"(temp) : );
	gdb_regs[GDB_RZPR] = temp;
	__asm__ __volatile__ ("mfs %0, rtlbx;" : "=r"(temp) : );
	gdb_regs[GDB_RTLBX] = temp;
	__asm__ __volatile__ ("mfs %0, rtlblo;" : "=r"(temp) : );
	gdb_regs[GDB_RTLBLO] = temp;
	__asm__ __volatile__ ("mfs %0, rtlbhi;" : "=r"(temp) : );
	gdb_regs[GDB_RTLBHI] = temp;
}

void gdb_regs_to_pt_regs(unsigned long *gdb_regs, struct pt_regs *regs)
{
	unsigned int i;
	unsigned long *pt_regb = (unsigned long *)regs;

	/* pt_regs and gdb_regs have the same 37 values.
	 * The rest of gdb_regs are unused and can't be changed.
	 * r0 register value can't be changed too. */
	for (i = 1; i < (sizeof(struct pt_regs) / 4) - 1; i++)
		pt_regb[i] = gdb_regs[i];
}

void sleeping_thread_to_gdb_regs(unsigned long *gdb_regs, struct task_struct *p)
{
	unsigned int i;
	unsigned long *pt_regb = (unsigned long *)(p->thread.regs);

	/* registers r0 - r31, pc, msr, ear, esr, fsr + do not save pt_mode */
	for (i = 0; i < (sizeof(struct pt_regs) / 4) - 1; i++)
		gdb_regs[i] = pt_regb[i];

	/* pvr part  - we have 11 pvr regs */
	for (i = 0; i < sizeof(struct pvr_s)/4; i++)
		gdb_regs[GDB_PVR + i] = pvr.pvr[i];
}

void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long ip)
{
	regs->pc = ip;
}

int kgdb_arch_handle_exception(int vector, int signo, int err_code,
			       char *remcom_in_buffer, char *remcom_out_buffer,
			       struct pt_regs *regs)
{
	char *ptr;
	unsigned long address;

	switch (remcom_in_buffer[0]) {
	case 'c':
		/* handle the optional parameter */
		ptr = &remcom_in_buffer[1];
		if (kgdb_hex2long(&ptr, &address))
			regs->pc = address;

		return 0;
	}
	return -1; /* this means that we do not want to exit from the handler */
}

int kgdb_arch_init(void)
{
	get_pvr(&pvr); /* Fill PVR structure */
	return 0;
}

void kgdb_arch_exit(void)
{
	/* Nothing to do */
}

