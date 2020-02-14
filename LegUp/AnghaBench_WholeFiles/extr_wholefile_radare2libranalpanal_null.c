#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_8__ {int /*<<< orphan*/  reg; } ;
struct TYPE_7__ {int size; } ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_1__ RAnalOp ;
typedef  TYPE_2__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  memset (TYPE_1__*,char,int) ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int null_anal(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len, RAnalOpMask mask) {
	memset (op, '\0', sizeof(RAnalOp));
	/* This should better follow the disassembler */
	return op->size = 1;
}

__attribute__((used)) static int null_set_reg_profile(RAnal* anal){
	return r_reg_set_profile_string(anal->reg, "");
}

