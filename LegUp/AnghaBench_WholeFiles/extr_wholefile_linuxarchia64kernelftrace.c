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
struct module {int dummy; } ;
struct ftrace_orig_insn {int /*<<< orphan*/  imm20; int /*<<< orphan*/  sign; } ;
struct ftrace_call_insn {unsigned long imm39_l; unsigned long imm39_h; unsigned long imm20; unsigned long i; } ;
struct fnptr {unsigned long ip; } ;
struct dyn_ftrace {unsigned long ip; int flags; } ;
typedef  scalar_t__ ftrace_func_t ;

/* Variables and functions */
 int EFAULT ; 
 int EINVAL ; 
 int EPERM ; 
 int FTRACE_FL_CONVERTED ; 
 int MCOUNT_INSN_SIZE ; 
 int /*<<< orphan*/  flush_icache_range (unsigned long,unsigned long) ; 
 scalar_t__ ftrace_call ; 
 unsigned char* ftrace_call_code ; 
 unsigned char* ftrace_nop_code ; 
 unsigned char* ftrace_orig_code ; 
 scalar_t__ ftrace_stub ; 
 int /*<<< orphan*/  ia64_patch_imm64 (unsigned long,unsigned long) ; 
 scalar_t__ memcmp (unsigned char*,unsigned char*,int) ; 
 scalar_t__ probe_kernel_read (unsigned char*,void*,int) ; 
 scalar_t__ probe_kernel_write (void*,unsigned char*,int) ; 

__attribute__((used)) static unsigned char *ftrace_nop_replace(void)
{
	return ftrace_nop_code;
}

__attribute__((used)) static unsigned char *ftrace_call_replace(unsigned long ip, unsigned long addr)
{
	struct ftrace_call_insn *code = (void *)ftrace_call_code;
	unsigned long offset = addr - (ip + 0x10);

	code->imm39_l = offset >> 24;
	code->imm39_h = offset >> 40;
	code->imm20 = offset >> 4;
	code->i = offset >> 63;
	return ftrace_call_code;
}

__attribute__((used)) static int
ftrace_modify_code(unsigned long ip, unsigned char *old_code,
		   unsigned char *new_code, int do_check)
{
	unsigned char replaced[MCOUNT_INSN_SIZE];

	/*
	 * Note:
	 * We are paranoid about modifying text, as if a bug was to happen, it
	 * could cause us to read or write to someplace that could cause harm.
	 * Carefully read and modify the code with probe_kernel_*(), and make
	 * sure what we read is what we expected it to be before modifying it.
	 */

	if (!do_check)
		goto skip_check;

	/* read the text we want to modify */
	if (probe_kernel_read(replaced, (void *)ip, MCOUNT_INSN_SIZE))
		return -EFAULT;

	/* Make sure it is what we expect it to be */
	if (memcmp(replaced, old_code, MCOUNT_INSN_SIZE) != 0)
		return -EINVAL;

skip_check:
	/* replace the text with the new text */
	if (probe_kernel_write(((void *)ip), new_code, MCOUNT_INSN_SIZE))
		return -EPERM;
	flush_icache_range(ip, ip + MCOUNT_INSN_SIZE);

	return 0;
}

__attribute__((used)) static int ftrace_make_nop_check(struct dyn_ftrace *rec, unsigned long addr)
{
	unsigned char __attribute__((aligned(8))) replaced[MCOUNT_INSN_SIZE];
	unsigned long ip = rec->ip;

	if (probe_kernel_read(replaced, (void *)ip, MCOUNT_INSN_SIZE))
		return -EFAULT;
	if (rec->flags & FTRACE_FL_CONVERTED) {
		struct ftrace_call_insn *call_insn, *tmp_call;

		call_insn = (void *)ftrace_call_code;
		tmp_call = (void *)replaced;
		call_insn->imm39_l = tmp_call->imm39_l;
		call_insn->imm39_h = tmp_call->imm39_h;
		call_insn->imm20 = tmp_call->imm20;
		call_insn->i = tmp_call->i;
		if (memcmp(replaced, ftrace_call_code, MCOUNT_INSN_SIZE) != 0)
			return -EINVAL;
		return 0;
	} else {
		struct ftrace_orig_insn *call_insn, *tmp_call;

		call_insn = (void *)ftrace_orig_code;
		tmp_call = (void *)replaced;
		call_insn->sign = tmp_call->sign;
		call_insn->imm20 = tmp_call->imm20;
		if (memcmp(replaced, ftrace_orig_code, MCOUNT_INSN_SIZE) != 0)
			return -EINVAL;
		return 0;
	}
}

int ftrace_make_nop(struct module *mod,
		    struct dyn_ftrace *rec, unsigned long addr)
{
	int ret;
	char *new;

	ret = ftrace_make_nop_check(rec, addr);
	if (ret)
		return ret;
	new = ftrace_nop_replace();
	return ftrace_modify_code(rec->ip, NULL, new, 0);
}

int ftrace_make_call(struct dyn_ftrace *rec, unsigned long addr)
{
	unsigned long ip = rec->ip;
	unsigned char *old, *new;

	old=  ftrace_nop_replace();
	new = ftrace_call_replace(ip, addr);
	return ftrace_modify_code(ip, old, new, 1);
}

int ftrace_update_ftrace_func(ftrace_func_t func)
{
	unsigned long ip;
	unsigned long addr = ((struct fnptr *)ftrace_call)->ip;

	if (func == ftrace_stub)
		return 0;
	ip = ((struct fnptr *)func)->ip;

	ia64_patch_imm64(addr + 2, ip);

	flush_icache_range(addr, addr + 16);
	return 0;
}

