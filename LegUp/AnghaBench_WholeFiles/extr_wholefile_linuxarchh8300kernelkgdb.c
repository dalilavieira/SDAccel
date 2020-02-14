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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_3__ {unsigned long ksp; } ;
struct task_struct {TYPE_1__ thread; } ;
struct pt_regs {unsigned long pc; } ;
struct TYPE_4__ {char* name; int /*<<< orphan*/  size; int /*<<< orphan*/  offset; } ;

/* Variables and functions */
 int DBG_MAX_REG_NUM ; 
 int EINVAL ; 
#define  GDB_CCR 128 
 size_t GDB_PC ; 
 size_t GDB_SP ; 
 unsigned long KSTK_EIP (struct task_struct*) ; 
 int /*<<< orphan*/  NUMREGBYTES ; 
 TYPE_2__* dbg_reg_def ; 
 int /*<<< orphan*/  kgdb_hex2long (char**,unsigned long*) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
	if (regno >= DBG_MAX_REG_NUM || regno < 0)
		return NULL;

	switch (regno) {
	case GDB_CCR:
#if defined(CONFIG_CPU_H8S)
	case GDB_EXR:
#endif
		*(u32 *)mem = *(u16 *)((void *)regs +
				       dbg_reg_def[regno].offset);
		break;
	default:
		if (dbg_reg_def[regno].offset >= 0)
			memcpy(mem, (void *)regs + dbg_reg_def[regno].offset,
			       dbg_reg_def[regno].size);
		else
			memset(mem, 0, dbg_reg_def[regno].size);
		break;
	}
	return dbg_reg_def[regno].name;
}

int dbg_set_reg(int regno, void *mem, struct pt_regs *regs)
{
	if (regno >= DBG_MAX_REG_NUM || regno < 0)
		return -EINVAL;

	switch (regno) {
	case GDB_CCR:
#if defined(CONFIG_CPU_H8S)
	case GDB_EXR:
#endif
		*(u16 *)((void *)regs +
			 dbg_reg_def[regno].offset) = *(u32 *)mem;
		break;
	default:
		memcpy((void *)regs + dbg_reg_def[regno].offset, mem,
		       dbg_reg_def[regno].size);
	}
	return 0;
}

void sleeping_thread_to_gdb_regs(unsigned long *gdb_regs, struct task_struct *p)
{
	memset((char *)gdb_regs, 0, NUMREGBYTES);
	gdb_regs[GDB_SP] = p->thread.ksp;
	gdb_regs[GDB_PC] = KSTK_EIP(p);
}

void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long pc)
{
	regs->pc = pc;
}

int kgdb_arch_handle_exception(int vector, int signo, int err_code,
				char *remcom_in_buffer, char *remcom_out_buffer,
				struct pt_regs *regs)
{
	char *ptr;
	unsigned long addr;

	switch (remcom_in_buffer[0]) {
	case 's':
	case 'c':
		/* handle the optional parameters */
		ptr = &remcom_in_buffer[1];
		if (kgdb_hex2long(&ptr, &addr))
			regs->pc = addr;

		return 0;
	}

	return -1; /* this means that we do not want to exit from the handler */
}

int kgdb_arch_init(void)
{
	return 0;
}

void kgdb_arch_exit(void)
{
	/* Nothing to do */
}

