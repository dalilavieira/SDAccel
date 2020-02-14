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
struct TYPE_4__ {scalar_t__ opcode; int rs; int rt; int simmediate; } ;
struct TYPE_3__ {scalar_t__ func; int rs; } ;
union mips_instruction {TYPE_2__ i_format; TYPE_1__ r_format; } ;
struct stackframe {scalar_t__ pc; size_t sp; int ra; } ;
typedef  int off_t ;

/* Variables and functions */
 unsigned long THREAD_SIZE ; 
 int /*<<< orphan*/  VERIFY_READ ; 
 scalar_t__ __copy_from_user_inatomic (unsigned long*,unsigned long*,int) ; 
 int /*<<< orphan*/  access_ok (int /*<<< orphan*/ ,unsigned long*,int) ; 
 scalar_t__ addiu_op ; 
 scalar_t__ daddiu_op ; 
 scalar_t__ jr_op ; 
 scalar_t__ lui_op ; 
 int /*<<< orphan*/  oprofile_add_trace (unsigned long) ; 
 scalar_t__ sd_op ; 
 scalar_t__ sw_op ; 

__attribute__((used)) static inline int get_mem(unsigned long addr, unsigned long *result)
{
	unsigned long *address = (unsigned long *) addr;
	if (!access_ok(VERIFY_READ, address, sizeof(unsigned long)))
		return -1;
	if (__copy_from_user_inatomic(result, address, sizeof(unsigned long)))
		return -3;
	return 0;
}

__attribute__((used)) static inline int is_ra_save_ins(union mips_instruction *ip)
{
	/* sw / sd $ra, offset($sp) */
	return (ip->i_format.opcode == sw_op || ip->i_format.opcode == sd_op)
		&& ip->i_format.rs == 29 && ip->i_format.rt == 31;
}

__attribute__((used)) static inline int is_sp_move_ins(union mips_instruction *ip)
{
	/* addiu/daddiu sp,sp,-imm */
	if (ip->i_format.rs != 29 || ip->i_format.rt != 29)
		return 0;
	if (ip->i_format.opcode == addiu_op || ip->i_format.opcode == daddiu_op)
		return 1;
	return 0;
}

__attribute__((used)) static inline int is_end_of_function_marker(union mips_instruction *ip)
{
	/* jr ra */
	if (ip->r_format.func == jr_op && ip->r_format.rs == 31)
		return 1;
	/* lui gp */
	if (ip->i_format.opcode == lui_op && ip->i_format.rt == 28)
		return 1;
	return 0;
}

__attribute__((used)) static inline int unwind_user_frame(struct stackframe *old_frame,
				    const unsigned int max_instr_check)
{
	struct stackframe new_frame = *old_frame;
	off_t ra_offset = 0;
	size_t stack_size = 0;
	unsigned long addr;

	if (old_frame->pc == 0 || old_frame->sp == 0 || old_frame->ra == 0)
		return -9;

	for (addr = new_frame.pc; (addr + max_instr_check > new_frame.pc)
		&& (!ra_offset || !stack_size); --addr) {
		union mips_instruction ip;

		if (get_mem(addr, (unsigned long *) &ip))
			return -11;

		if (is_sp_move_ins(&ip)) {
			int stack_adjustment = ip.i_format.simmediate;
			if (stack_adjustment > 0)
				/* This marks the end of the previous function,
				   which means we overran. */
				break;
			stack_size = (unsigned long) stack_adjustment;
		} else if (is_ra_save_ins(&ip)) {
			int ra_slot = ip.i_format.simmediate;
			if (ra_slot < 0)
				/* This shouldn't happen. */
				break;
			ra_offset = ra_slot;
		} else if (is_end_of_function_marker(&ip))
			break;
	}

	if (!ra_offset || !stack_size)
		goto done;

	if (ra_offset) {
		new_frame.ra = old_frame->sp + ra_offset;
		if (get_mem(new_frame.ra, &(new_frame.ra)))
			return -13;
	}

	if (stack_size) {
		new_frame.sp = old_frame->sp + stack_size;
		if (get_mem(new_frame.sp, &(new_frame.sp)))
			return -14;
	}

	if (new_frame.sp > old_frame->sp)
		return -2;

done:
	new_frame.pc = old_frame->ra;
	*old_frame = new_frame;

	return 0;
}

__attribute__((used)) static inline void do_user_backtrace(unsigned long low_addr,
				     struct stackframe *frame,
				     unsigned int depth)
{
	const unsigned int max_instr_check = 512;
	const unsigned long high_addr = low_addr + THREAD_SIZE;

	while (depth-- && !unwind_user_frame(frame, max_instr_check)) {
		oprofile_add_trace(frame->ra);
		if (frame->sp < low_addr || frame->sp > high_addr)
			break;
	}
}

__attribute__((used)) static inline void do_kernel_backtrace(unsigned long low_addr,
				       struct stackframe *frame,
				       unsigned int depth) { }

