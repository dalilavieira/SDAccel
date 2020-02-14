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
struct TYPE_4__ {unsigned short* addr; unsigned short inst; } ;
struct TYPE_5__ {TYPE_1__ breakinfo; } ;
struct task_struct {TYPE_2__ thread; } ;
struct optable {int type; size_t length; unsigned char bitmask; unsigned char bitpattern; } ;
struct TYPE_6__ {int size; struct optable* ptr; } ;

/* Variables and functions */
 unsigned short BREAKINST ; 
 int /*<<< orphan*/  PT_CCR ; 
 int /*<<< orphan*/  PT_ER0 ; 
 int /*<<< orphan*/  PT_ER1 ; 
 int /*<<< orphan*/  PT_PC ; 
 int /*<<< orphan*/  PT_USP ; 
 unsigned char* condmask ; 
 void* h8300_get_reg (struct task_struct*,int /*<<< orphan*/ ) ; 
#define  ind 134 
#define  jabs 133 
#define  none 132 
 TYPE_3__* optables ; 
#define  reg 131 
#define  relb 130 
#define  relw 129 
#define  ret 128 

void user_disable_single_step(struct task_struct *child)
{
	if ((long)child->thread.breakinfo.addr != -1L) {
		*(child->thread.breakinfo.addr) = child->thread.breakinfo.inst;
		child->thread.breakinfo.addr = (unsigned short *)-1L;
	}
}

__attribute__((used)) static int isbranch(struct task_struct *task, int reson)
{
	unsigned char cond = h8300_get_reg(task, PT_CCR);

	/* encode complex conditions */
	/* B4: N^V
	   B5: Z|(N^V)
	   B6: C|Z */
	__asm__("bld #3,%w0\n\t"
		"bxor #1,%w0\n\t"
		"bst #4,%w0\n\t"
		"bor #2,%w0\n\t"
		"bst #5,%w0\n\t"
		"bld #2,%w0\n\t"
		"bor #0,%w0\n\t"
		"bst #6,%w0\n\t"
		: "=&r"(cond) : "0"(cond) : "cc");
	cond &= condmask[reson >> 1];
	if (!(reson & 1))
		return cond == 0;
	else
		return cond != 0;
}

__attribute__((used)) static unsigned short *decode(struct task_struct *child,
			      const struct optable *op,
			      char *fetch_p, unsigned short *pc,
			      unsigned char inst)
{
	unsigned long addr;
	unsigned long *sp;
	int regno;

	switch (op->type) {
	case none:
		return (unsigned short *)pc + op->length;
	case jabs:
		addr = *(unsigned long *)pc;
		return (unsigned short *)(addr & 0x00ffffff);
	case ind:
		addr = *pc & 0xff;
		return (unsigned short *)(*(unsigned long *)addr);
	case ret:
		sp = (unsigned long *)h8300_get_reg(child, PT_USP);
		/* user stack frames
		   |   er0  | temporary saved
		   +--------+
		   |   exp  | exception stack frames
		   +--------+
		   | ret pc | userspace return address
		*/
		return (unsigned short *)(*(sp+2) & 0x00ffffff);
	case reg:
		regno = (*pc >> 4) & 0x07;
		if (regno == 0)
			addr = h8300_get_reg(child, PT_ER0);
		else
			addr = h8300_get_reg(child, regno-1 + PT_ER1);
		return (unsigned short *)addr;
	case relb:
		if (inst == 0x55 || isbranch(child, inst & 0x0f))
			pc = (unsigned short *)((unsigned long)pc +
						((signed char)(*fetch_p)));
		return pc+1; /* skip myself */
	case relw:
		if (inst == 0x5c || isbranch(child, (*fetch_p & 0xf0) >> 4))
			pc = (unsigned short *)((unsigned long)pc +
						((signed short)(*(pc+1))));
		return pc+2; /* skip myself */
	default:
		return NULL;
	}
}

__attribute__((used)) static unsigned short *nextpc(struct task_struct *child, unsigned short *pc)
{
	const struct optable *op;
	unsigned char *fetch_p;
	int op_len;
	unsigned char inst;

	op = optables[0].ptr;
	op_len = optables[0].size;
	fetch_p = (unsigned char *)pc;
	inst = *fetch_p++;
	do {
		if ((inst & op->bitmask) == op->bitpattern) {
			if (op->length < 0) {
				op = optables[-op->length].ptr;
				op_len = optables[-op->length].size + 1;
				inst = *fetch_p++;
			} else
				return decode(child, op, fetch_p, pc, inst);
		} else
			op++;
	} while (--op_len > 0);
	return NULL;
}

void user_enable_single_step(struct task_struct *child)
{
	unsigned short *next;

	next = nextpc(child, (unsigned short *)h8300_get_reg(child, PT_PC));
	child->thread.breakinfo.addr = next;
	child->thread.breakinfo.inst = *next;
	*next = BREAKINST;
}

