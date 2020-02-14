#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut16 ;
struct TYPE_12__ {int a_type; int a; int b_type; int b; size_t opcode; } ;
struct TYPE_11__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_10__ {int a_type; int a; int opcode; } ;
struct TYPE_9__ {scalar_t__ opcode; } ;
struct TYPE_13__ {TYPE_4__ b; TYPE_3__ member_0; TYPE_2__ n; TYPE_1__ code; } ;
typedef  TYPE_5__ op ;

/* Variables and functions */
 int* opCycle ; 
 int* opCycleB ; 
 char** opName ; 
 char** opNameB ; 
 char** regs ; 
 int sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 

__attribute__((used)) static inline int needWord(ut8 type) {
	return ((type <= 0x17) && (type > 0x0f)) \
		|| (type == 0x1e) || (type == 0x1f);
}

__attribute__((used)) static int valPrint(char *out, ut8 type, ut16 value) {
	if (type <= 0x07) return sprintf(out, "%s", regs[type]);
	if (type <= 0x0f) return sprintf(out, "[%s]", regs[type - 0x08]);
	if (type <= 0x17) return sprintf(out, "[%s + %#hx]", regs[type - 0x10], value);
	if (type <= 0x1d) return sprintf(out, "%s", regs[type - 0x18 + 0x08]);
	if (type == 0x1e) return sprintf(out, "[%#hx]", value);
	if (type == 0x1f) return sprintf(out, "%#hx", value);
	return sprintf(out, "%#hx", (short)(type - 0x20));
}

__attribute__((used)) static int instrPrint(char *out, const op* o) {
	char arg[32], arg2[32];
	if (o->code.opcode == 0) {
		valPrint (arg, o->n.a_type, o->n.a);
		if (o->n.opcode > 1) {
			strcpy (out, "invalid");
			return strlen (out);
		}
		return sprintf(out, "%s %s",
			opNameB[o->n.opcode], arg);
	}
	valPrint (arg, o->b.a_type, o->b.a);
	valPrint (arg2, o->b.b_type, o->b.b);
	return sprintf(out, "%s %s, %s", opName[o->b.opcode], arg, arg2);
}

__attribute__((used)) static int instrGet(ut16 in, op* o, ut16 a, ut16 b) {
	int ret = 1;
	o->code.opcode = in & 0xF;
	if (!(o->code.opcode = in & 0xF)) {
		/* Non basic op code */
		o->n.opcode = (in >> 4) & 0x3F;
		o->n.a_type = (in >> 10) & 0x3F;

		if (needWord(o->n.a_type)) {
			o->n.a = a;
			ret++;
		}
	} else {
		o->b.a_type = (in >> 4) & 0x3F;
		o->b.b_type = (in >> 10) & 0x3F;
		if (needWord(o->b.a_type)) {
			o->b.a = a;
			ret++;
			if (needWord (o->b.b_type)) {
				o->b.b = b;
				ret++;
			}
		} else if (needWord(o->b.b_type)) {
			o->b.b = a;
			ret++;
		}
	}
	return ret;
}

__attribute__((used)) static int instrGetCycles(const op* o) {
	if (o->code.opcode == 0)
		return opCycleB[o->n.opcode] + needWord(o->n.a_type);
	return opCycle[o->b.opcode] + needWord(o->b.a_type)
		+ needWord(o->b.b_type);
}

int dcpu16_disasm(char *out, const ut16* inp, int len, int *cost) {
	op o = {{0}};
	int delta = instrGet (inp[0], &o, inp[1], inp[2]);
	if (cost) *cost = instrGetCycles(&o) + ((o.b.opcode >= 0xc)?1:0);
	instrPrint (out, &o);
	//ind = (o.b.opcode >= 0xC);
	return delta<<1;
}

