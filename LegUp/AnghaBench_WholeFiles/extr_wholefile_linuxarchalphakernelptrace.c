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
typedef  int /*<<< orphan*/  tmp ;
struct task_struct {int dummy; } ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  pgprot_t ;
struct TYPE_3__ {unsigned long usp; unsigned long unique; } ;
struct TYPE_4__ {unsigned long ieee_state; unsigned long* bpt_addr; unsigned int* bpt_insn; int bpt_nsaved; TYPE_1__ pcb; } ;

/* Variables and functions */
 int BREAKINST ; 
 int /*<<< orphan*/  DBG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  DBG_BPT ; 
 int /*<<< orphan*/  DBG_MEM ; 
 int EIO ; 
 int FOLL_FORCE ; 
 int FOLL_WRITE ; 
 unsigned long FPCR_DYN_MASK ; 
 unsigned long IEEE_SW_MASK ; 
#define  PTRACE_PEEKDATA 133 
#define  PTRACE_PEEKTEXT 132 
#define  PTRACE_PEEKUSR 131 
#define  PTRACE_POKEDATA 130 
#define  PTRACE_POKETEXT 129 
#define  PTRACE_POKEUSR 128 
 unsigned long REG_PC ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int access_process_vm (struct task_struct*,unsigned long,int*,int,int) ; 
 int /*<<< orphan*/  force_successful_syscall_return () ; 
 long generic_ptrace_pokedata (struct task_struct*,unsigned long,unsigned long) ; 
 unsigned long ieee_swcr_to_fpcr (unsigned long) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,int) ; 
 size_t ptrace_access_vm (struct task_struct*,unsigned long,unsigned long*,int,int) ; 
 long ptrace_request (struct task_struct*,long,unsigned long,unsigned long) ; 
 int* regoff ; 
 unsigned long swcr_update_status (unsigned long,unsigned long) ; 
 unsigned long* task_stack_page (struct task_struct*) ; 
 TYPE_2__* task_thread_info (struct task_struct*) ; 
 unsigned long zero ; 

__attribute__((used)) static inline void find_console_vga_hose(void) { }

__attribute__((used)) static inline void locate_and_init_vga(void *(*sel_func)(void *, void *)) { }

__attribute__((used)) static inline int
__alpha_remap_area_pages(unsigned long address, unsigned long phys_addr,
			 unsigned long size, unsigned long flags)
{
	pgprot_t prot;

	prot = __pgprot(_PAGE_VALID | _PAGE_ASM | _PAGE_KRE
			| _PAGE_KWE | flags);
	return ioremap_page_range(address, address + size, phys_addr, prot);
}

__attribute__((used)) static unsigned long *
get_reg_addr(struct task_struct * task, unsigned long regno)
{
	unsigned long *addr;

	if (regno == 30) {
		addr = &task_thread_info(task)->pcb.usp;
	} else if (regno == 65) {
		addr = &task_thread_info(task)->pcb.unique;
	} else if (regno == 31 || regno > 65) {
		zero = 0;
		addr = &zero;
	} else {
		addr = task_stack_page(task) + regoff[regno];
	}
	return addr;
}

__attribute__((used)) static unsigned long
get_reg(struct task_struct * task, unsigned long regno)
{
	/* Special hack for fpcr -- combine hardware and software bits.  */
	if (regno == 63) {
		unsigned long fpcr = *get_reg_addr(task, regno);
		unsigned long swcr
		  = task_thread_info(task)->ieee_state & IEEE_SW_MASK;
		swcr = swcr_update_status(swcr, fpcr);
		return fpcr | swcr;
	}
	return *get_reg_addr(task, regno);
}

__attribute__((used)) static int
put_reg(struct task_struct *task, unsigned long regno, unsigned long data)
{
	if (regno == 63) {
		task_thread_info(task)->ieee_state
		  = ((task_thread_info(task)->ieee_state & ~IEEE_SW_MASK)
		     | (data & IEEE_SW_MASK));
		data = (data & FPCR_DYN_MASK) | ieee_swcr_to_fpcr(data);
	}
	*get_reg_addr(task, regno) = data;
	return 0;
}

__attribute__((used)) static inline int
read_int(struct task_struct *task, unsigned long addr, int * data)
{
	int copied = access_process_vm(task, addr, data, sizeof(int),
			FOLL_FORCE);
	return (copied == sizeof(int)) ? 0 : -EIO;
}

__attribute__((used)) static inline int
write_int(struct task_struct *task, unsigned long addr, int data)
{
	int copied = access_process_vm(task, addr, &data, sizeof(int),
			FOLL_FORCE | FOLL_WRITE);
	return (copied == sizeof(int)) ? 0 : -EIO;
}

int
ptrace_set_bpt(struct task_struct * child)
{
	int displ, i, res, reg_b, nsaved = 0;
	unsigned int insn, op_code;
	unsigned long pc;

	pc  = get_reg(child, REG_PC);
	res = read_int(child, pc, (int *) &insn);
	if (res < 0)
		return res;

	op_code = insn >> 26;
	if (op_code >= 0x30) {
		/*
		 * It's a branch: instead of trying to figure out
		 * whether the branch will be taken or not, we'll put
		 * a breakpoint at either location.  This is simpler,
		 * more reliable, and probably not a whole lot slower
		 * than the alternative approach of emulating the
		 * branch (emulation can be tricky for fp branches).
		 */
		displ = ((s32)(insn << 11)) >> 9;
		task_thread_info(child)->bpt_addr[nsaved++] = pc + 4;
		if (displ)		/* guard against unoptimized code */
			task_thread_info(child)->bpt_addr[nsaved++]
			  = pc + 4 + displ;
		DBG(DBG_BPT, ("execing branch\n"));
	} else if (op_code == 0x1a) {
		reg_b = (insn >> 16) & 0x1f;
		task_thread_info(child)->bpt_addr[nsaved++] = get_reg(child, reg_b);
		DBG(DBG_BPT, ("execing jump\n"));
	} else {
		task_thread_info(child)->bpt_addr[nsaved++] = pc + 4;
		DBG(DBG_BPT, ("execing normal insn\n"));
	}

	/* install breakpoints: */
	for (i = 0; i < nsaved; ++i) {
		res = read_int(child, task_thread_info(child)->bpt_addr[i],
			       (int *) &insn);
		if (res < 0)
			return res;
		task_thread_info(child)->bpt_insn[i] = insn;
		DBG(DBG_BPT, ("    -> next_pc=%lx\n",
			      task_thread_info(child)->bpt_addr[i]));
		res = write_int(child, task_thread_info(child)->bpt_addr[i],
				BREAKINST);
		if (res < 0)
			return res;
	}
	task_thread_info(child)->bpt_nsaved = nsaved;
	return 0;
}

int
ptrace_cancel_bpt(struct task_struct * child)
{
	int i, nsaved = task_thread_info(child)->bpt_nsaved;

	task_thread_info(child)->bpt_nsaved = 0;

	if (nsaved > 2) {
		printk("ptrace_cancel_bpt: bogus nsaved: %d!\n", nsaved);
		nsaved = 2;
	}

	for (i = 0; i < nsaved; ++i) {
		write_int(child, task_thread_info(child)->bpt_addr[i],
			  task_thread_info(child)->bpt_insn[i]);
	}
	return (nsaved != 0);
}

void user_enable_single_step(struct task_struct *child)
{
	/* Mark single stepping.  */
	task_thread_info(child)->bpt_nsaved = -1;
}

void user_disable_single_step(struct task_struct *child)
{
	ptrace_cancel_bpt(child);
}

void ptrace_disable(struct task_struct *child)
{ 
	user_disable_single_step(child);
}

long arch_ptrace(struct task_struct *child, long request,
		 unsigned long addr, unsigned long data)
{
	unsigned long tmp;
	size_t copied;
	long ret;

	switch (request) {
	/* When I and D space are separate, these will need to be fixed.  */
	case PTRACE_PEEKTEXT: /* read word at location addr. */
	case PTRACE_PEEKDATA:
		copied = ptrace_access_vm(child, addr, &tmp, sizeof(tmp),
				FOLL_FORCE);
		ret = -EIO;
		if (copied != sizeof(tmp))
			break;
		
		force_successful_syscall_return();
		ret = tmp;
		break;

	/* Read register number ADDR. */
	case PTRACE_PEEKUSR:
		force_successful_syscall_return();
		ret = get_reg(child, addr);
		DBG(DBG_MEM, ("peek $%lu->%#lx\n", addr, ret));
		break;

	/* When I and D space are separate, this will have to be fixed.  */
	case PTRACE_POKETEXT: /* write the word at location addr. */
	case PTRACE_POKEDATA:
		ret = generic_ptrace_pokedata(child, addr, data);
		break;

	case PTRACE_POKEUSR: /* write the specified register */
		DBG(DBG_MEM, ("poke $%lu<-%#lx\n", addr, data));
		ret = put_reg(child, addr, data);
		break;
	default:
		ret = ptrace_request(child, request, addr, data);
		break;
	}
	return ret;
}

