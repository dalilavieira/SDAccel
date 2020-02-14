#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  addr; } ;
struct TYPE_11__ {int /*<<< orphan*/  offset; TYPE_1__* anal; } ;
struct TYPE_10__ {int addr; } ;
struct TYPE_9__ {int /*<<< orphan*/  esil; } ;
typedef  TYPE_2__ RAnalFunction ;

/* Variables and functions */
 TYPE_3__* core ; 
 TYPE_6__* fcn ; 
 int /*<<< orphan*/  help_msg_aft ; 
 int* input ; 
 int /*<<< orphan*/  r_anal_esil_set_pc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_core_anal_type_match (TYPE_3__*,TYPE_6__*) ; 
 int /*<<< orphan*/  r_core_cmd_help (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_core_seek (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  seek ; 

__attribute__((used)) static int cmpaddr(const void *_a, const void *_b) {
	const RAnalFunction *a = _a, *b = _b;
	return a->addr - b->addr;
}

int main (int argc, char **argv) {
	r_anal_esil_set_pc (core->anal->esil, fcn ? fcn->addr : core->offset);
	switch (*input) {
	case '\0': // "aft"
	{
		seek = core->offset;
		r_anal_esil_set_pc (core->anal->esil, fcn ? fcn->addr : core->offset);
		r_core_anal_type_match (core, fcn);
		r_core_seek (core, seek, true);
		break;
	}
	case '?':
	default:
		r_core_cmd_help (core, help_msg_aft);
		break;
	}
	return 0;
}

