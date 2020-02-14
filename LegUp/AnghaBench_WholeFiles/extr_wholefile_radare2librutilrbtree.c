#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {scalar_t__ len; TYPE_1__** path; } ;
struct TYPE_15__ {int red; struct TYPE_15__** child; } ;
typedef  int /*<<< orphan*/  (* RBNodeSum ) (TYPE_1__*) ;
typedef  TYPE_1__ RBNode ;
typedef  TYPE_3__ RBIter ;
typedef  int (* RBComparator ) (void*,TYPE_1__*) ;

/* Variables and functions */

__attribute__((used)) static inline bool red(RBNode *x) {
	return x && x->red;
}

__attribute__((used)) static inline RBNode *zag(RBNode *x, int dir, RBNodeSum sum) {
	RBNode *y = x->child[dir];
	x->child[dir] = y->child[!dir];
	y->child[!dir] = x;
	x->red = true;
	y->red = false;
	if (sum) {
		sum (x);
	}
	return y;
}

__attribute__((used)) static inline RBNode *zig_zag(RBNode *x, int dir, RBNodeSum sum) {
	RBNode *y = x->child[dir], *z = y->child[!dir];
	y->child[!dir] = z->child[dir];
	z->child[dir] = y;
	x->child[dir] = z->child[!dir];
	z->child[!dir] = x;
	x->red = y->red = true;
	z->red = false;
	if (sum) {
		sum (x);
		sum (y);
	}
	return z;
}

__attribute__((used)) static inline RBIter bound_iter(RBNode *x, void *data, RBComparator cmp, bool upper, bool backward) {
	RBIter it;
	it.len = 0;
	while (x) {
		int d = cmp (data, x);
		if (upper ? d < 0 : d <= 0) {
			if (!backward) {
				it.path[it.len++] = x;
			}
			x = x->child[0];
		} else {
			if (backward) {
				it.path[it.len++] = x;
			}
			x = x->child[1];
		}
	}
	return it;
}

