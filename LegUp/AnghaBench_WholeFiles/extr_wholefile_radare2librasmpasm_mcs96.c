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
typedef  size_t ut8 ;
struct TYPE_5__ {int type; int /*<<< orphan*/  ins; } ;
struct TYPE_4__ {int size; int /*<<< orphan*/  buf_asm; } ;
typedef  TYPE_1__ RAsmOp ;
typedef  int /*<<< orphan*/  RAsm ;

/* Variables and functions */
 int MCS96_2B ; 
 int MCS96_3B ; 
 int MCS96_4B ; 
 int MCS96_5B ; 
 int MCS96_6B ; 
 TYPE_2__* mcs96_op ; 
 int /*<<< orphan*/  memcmp (size_t const*,char*,int) ; 
 int /*<<< orphan*/  r_strbuf_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mcs96_len (const ut8 buf) {
	if (mcs96_op[buf].type & MCS96_6B) {
		return 6;
	}
	if (mcs96_op[buf].type & MCS96_5B) {
		return 5;
	}
	if (mcs96_op[buf].type & MCS96_4B) {
		return 4;
	}
	if (mcs96_op[buf].type & MCS96_3B) {
		return 3;
	}
	if (mcs96_op[buf].type & MCS96_2B) {
		return 2;
	}
	return 1;
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	if (len > 1 && !memcmp (buf, "\xff\xff", 2)) {
		return -1;
	}
	r_strbuf_set (&op->buf_asm, mcs96_op[buf[0]].ins);
	op->size = mcs96_len (buf[0]);
	return op->size;
}

