#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {unsigned long r4; unsigned long r5; unsigned long r6; unsigned long r7; unsigned long r8; unsigned long r9; unsigned long sl; unsigned long fp; unsigned long sp; unsigned long pc; } ;
struct thread_info {TYPE_1__ cpu_context; } ;
struct task_struct {int dummy; } ;
struct pt_regs {unsigned long ARM_pc; } ;
struct notifier_block {int dummy; } ;
struct kgdb_bkpt {scalar_t__ saved_instr; scalar_t__ bpt_addr; } ;
struct die_args {int /*<<< orphan*/  signr; struct pt_regs* regs; } ;
struct TYPE_6__ {scalar_t__ gdb_bpt_instr; } ;
struct TYPE_5__ {int offset; char* name; int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int BREAK_INSTR_SIZE ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int DBG_MAX_REG_NUM ; 
 int EINVAL ; 
 int GDB_MAX_REGS ; 
 int NOTIFY_DONE ; 
 int NOTIFY_STOP ; 
 int /*<<< orphan*/  SIGTRAP ; 
 size_t _FP ; 
 size_t _PC ; 
 size_t _R10 ; 
 size_t _R4 ; 
 size_t _R5 ; 
 size_t _R6 ; 
 size_t _R7 ; 
 size_t _R8 ; 
 size_t _R9 ; 
 size_t _SPT ; 
 int /*<<< orphan*/  __patch_text (void*,unsigned int) ; 
 TYPE_3__ arch_kgdb_ops ; 
 int compiled_break ; 
 TYPE_2__* dbg_reg_def ; 
 int /*<<< orphan*/  get_irq_regs () ; 
 int /*<<< orphan*/  kgdb_brkpt_hook ; 
 int /*<<< orphan*/  kgdb_compiled_brkpt_hook ; 
 scalar_t__ kgdb_handle_exception (int,int /*<<< orphan*/ ,unsigned long,struct pt_regs*) ; 
 int /*<<< orphan*/  kgdb_hex2long (char**,unsigned long*) ; 
 int /*<<< orphan*/  kgdb_nmicallback (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kgdb_notifier ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int probe_kernel_read (scalar_t__,char*,int) ; 
 int /*<<< orphan*/  raw_smp_processor_id () ; 
 int register_die_notifier (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  register_undef_hook (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_call_function (void (*) (void*),int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct thread_info* task_thread_info (struct task_struct*) ; 
 int /*<<< orphan*/  unregister_die_notifier (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unregister_undef_hook (int /*<<< orphan*/ *) ; 

char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
	if (regno >= DBG_MAX_REG_NUM || regno < 0)
		return NULL;

	if (dbg_reg_def[regno].offset != -1)
		memcpy(mem, (void *)regs + dbg_reg_def[regno].offset,
		       dbg_reg_def[regno].size);
	else
		memset(mem, 0, dbg_reg_def[regno].size);
	return dbg_reg_def[regno].name;
}

int dbg_set_reg(int regno, void *mem, struct pt_regs *regs)
{
	if (regno >= DBG_MAX_REG_NUM || regno < 0)
		return -EINVAL;

	if (dbg_reg_def[regno].offset != -1)
		memcpy((void *)regs + dbg_reg_def[regno].offset, mem,
		       dbg_reg_def[regno].size);
	return 0;
}

void
sleeping_thread_to_gdb_regs(unsigned long *gdb_regs, struct task_struct *task)
{
	struct thread_info *ti;
	int regno;

	/* Just making sure... */
	if (task == NULL)
		return;

	/* Initialize to zero */
	for (regno = 0; regno < GDB_MAX_REGS; regno++)
		gdb_regs[regno] = 0;

	/* Otherwise, we have only some registers from switch_to() */
	ti			= task_thread_info(task);
	gdb_regs[_R4]		= ti->cpu_context.r4;
	gdb_regs[_R5]		= ti->cpu_context.r5;
	gdb_regs[_R6]		= ti->cpu_context.r6;
	gdb_regs[_R7]		= ti->cpu_context.r7;
	gdb_regs[_R8]		= ti->cpu_context.r8;
	gdb_regs[_R9]		= ti->cpu_context.r9;
	gdb_regs[_R10]		= ti->cpu_context.sl;
	gdb_regs[_FP]		= ti->cpu_context.fp;
	gdb_regs[_SPT]		= ti->cpu_context.sp;
	gdb_regs[_PC]		= ti->cpu_context.pc;
}

void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long pc)
{
	regs->ARM_pc = pc;
}

int kgdb_arch_handle_exception(int exception_vector, int signo,
			       int err_code, char *remcom_in_buffer,
			       char *remcom_out_buffer,
			       struct pt_regs *linux_regs)
{
	unsigned long addr;
	char *ptr;

	switch (remcom_in_buffer[0]) {
	case 'D':
	case 'k':
	case 'c':
		/*
		 * Try to read optional parameter, pc unchanged if no parm.
		 * If this was a compiled breakpoint, we need to move
		 * to the next instruction or we will just breakpoint
		 * over and over again.
		 */
		ptr = &remcom_in_buffer[1];
		if (kgdb_hex2long(&ptr, &addr))
			linux_regs->ARM_pc = addr;
		else if (compiled_break == 1)
			linux_regs->ARM_pc += 4;

		compiled_break = 0;

		return 0;
	}

	return -1;
}

__attribute__((used)) static int kgdb_brk_fn(struct pt_regs *regs, unsigned int instr)
{
	kgdb_handle_exception(1, SIGTRAP, 0, regs);

	return 0;
}

__attribute__((used)) static int kgdb_compiled_brk_fn(struct pt_regs *regs, unsigned int instr)
{
	compiled_break = 1;
	kgdb_handle_exception(1, SIGTRAP, 0, regs);

	return 0;
}

__attribute__((used)) static void kgdb_call_nmi_hook(void *ignored)
{
       kgdb_nmicallback(raw_smp_processor_id(), get_irq_regs());
}

void kgdb_roundup_cpus(unsigned long flags)
{
       local_irq_enable();
       smp_call_function(kgdb_call_nmi_hook, NULL, 0);
       local_irq_disable();
}

__attribute__((used)) static int __kgdb_notify(struct die_args *args, unsigned long cmd)
{
	struct pt_regs *regs = args->regs;

	if (kgdb_handle_exception(1, args->signr, cmd, regs))
		return NOTIFY_DONE;
	return NOTIFY_STOP;
}

__attribute__((used)) static int
kgdb_notify(struct notifier_block *self, unsigned long cmd, void *ptr)
{
	unsigned long flags;
	int ret;

	local_irq_save(flags);
	ret = __kgdb_notify(ptr, cmd);
	local_irq_restore(flags);

	return ret;
}

int kgdb_arch_init(void)
{
	int ret = register_die_notifier(&kgdb_notifier);

	if (ret != 0)
		return ret;

	register_undef_hook(&kgdb_brkpt_hook);
	register_undef_hook(&kgdb_compiled_brkpt_hook);

	return 0;
}

void kgdb_arch_exit(void)
{
	unregister_undef_hook(&kgdb_brkpt_hook);
	unregister_undef_hook(&kgdb_compiled_brkpt_hook);
	unregister_die_notifier(&kgdb_notifier);
}

int kgdb_arch_set_breakpoint(struct kgdb_bkpt *bpt)
{
	int err;

	/* patch_text() only supports int-sized breakpoints */
	BUILD_BUG_ON(sizeof(int) != BREAK_INSTR_SIZE);

	err = probe_kernel_read(bpt->saved_instr, (char *)bpt->bpt_addr,
				BREAK_INSTR_SIZE);
	if (err)
		return err;

	/* Machine is already stopped, so we can use __patch_text() directly */
	__patch_text((void *)bpt->bpt_addr,
		     *(unsigned int *)arch_kgdb_ops.gdb_bpt_instr);

	return err;
}

int kgdb_arch_remove_breakpoint(struct kgdb_bkpt *bpt)
{
	/* Machine is already stopped, so we can use __patch_text() directly */
	__patch_text((void *)bpt->bpt_addr, *(unsigned int *)bpt->saved_instr);

	return 0;
}

