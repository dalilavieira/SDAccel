#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_18__ {TYPE_1__* cur; } ;
struct TYPE_17__ {int /*<<< orphan*/  (* revisit_bb_anal ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* post_anal ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* post_anal_bb_cb ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* post_anal_op_cb ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* pre_anal_bb_cb ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* pre_anal_op_cb ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* pre_anal ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;} ;
typedef  int /*<<< orphan*/  RAnalState ;
typedef  TYPE_2__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void r_anal_ex_perform_pre_anal(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->pre_anal) {
		anal->cur->pre_anal (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_pre_anal_op_cb(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->pre_anal_op_cb) {
		anal->cur->pre_anal_op_cb (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_pre_anal_bb_cb(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->pre_anal_bb_cb) {
		anal->cur->pre_anal_bb_cb (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_post_anal_op_cb(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->post_anal_op_cb) {
		anal->cur->post_anal_op_cb (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_post_anal_bb_cb(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->post_anal_bb_cb) {
		anal->cur->post_anal_bb_cb (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_post_anal(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->post_anal) {
		anal->cur->post_anal (anal, state, addr);
	}
}

__attribute__((used)) static void r_anal_ex_perform_revisit_bb_cb(RAnal *anal, RAnalState *state, ut64 addr) {
	if (anal && anal->cur && anal->cur->revisit_bb_anal) {
		anal->cur->revisit_bb_anal (anal, state, addr);
	}
}

