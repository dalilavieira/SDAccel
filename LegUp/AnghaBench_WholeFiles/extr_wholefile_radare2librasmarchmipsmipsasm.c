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
typedef  int ut8 ;

/* Variables and functions */
 int /*<<< orphan*/  eprintf (char*,...) ; 
 scalar_t__ r_num_get (int /*<<< orphan*/ *,char const*) ; 
 scalar_t__* regs ; 
 int /*<<< orphan*/  strcmp (char const*,scalar_t__) ; 

__attribute__((used)) static int mips_r(ut8 *b, int op, int rs, int rt, int rd, int sa, int fun) {
//^this will keep the below mips_r fuctions working
// diff instructions use a diff arg order (add is rd, rs, rt - sll is rd, rt, sa - sllv is rd, rt, rs
//static int mips_r (ut8 *b, int op, int rd, int rs, int rt, int sa, int fun) {
	if (rs == -1 || rt == -1) {
		return -1;
	}
	b[3] = ((op<<2)&0xfc) | ((rs>>3)&3); // 2
	b[2] = (rs<<5) | (rt&0x1f); // 1
	b[1] = ((rd<<3)&0xff) | (sa>>2); // 0
	b[0] = (fun&0x3f) | ((sa&3)<<6);
	return 4;
}

__attribute__((used)) static int mips_i(ut8 *b, int op, int rs, int rt, int imm, int is_branch) {
	if (rs == -1 || rt == -1) {
		return -1;
	}
	if (is_branch) {
		if (imm > 4) {
			imm /= 4;
			imm--;
		} else {
			imm = 0;
		}
	}
	b[3] = ((op<<2)&0xfc) | ((rs>>3)&3);
	b[2] = (rs<<5) | (rt);
	b[1] = (imm>>8) &0xff;
	b[0] = imm & 0xff;
	return 4;
}

__attribute__((used)) static int mips_j(ut8 *b, int op, int addr) {
	addr /= 4;
	b[3] = ((op<<2)&0xfc) | ((addr>>24)&3);
	b[2] = (addr>>16)&0xff;
	b[1] = (addr>>8) &0xff;
	b[0] = addr & 0xff;
	return 4;
}

__attribute__((used)) static int getreg(const char *p) {
	int n;
	if (!p || !*p) {
		eprintf ("Missing argument\n");
		return -1;
	}
	/* check if it's a register */
	for (n = 0; regs[n]; n++) {
		if (!strcmp (p, regs[n])) {
			return n;
		}
	}
	/* try to convert it into a number */
	if (p[0] == '-') {
		n = (int) r_num_get (NULL, &p[1]);
		n = -n;
	} else {
		n = (int) r_num_get (NULL, p);
	}
	if (n != 0 || p[0] == '0') {
		return n;
	}
	eprintf ("Invalid reg name (%s) at pos %d\n", p, n);
	return -1;
}

