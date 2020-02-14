#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct entry {void* cl; int /*<<< orphan*/  (* func ) (void*,void*,void*) ;} ;
struct TYPE_6__ {struct TYPE_6__* link; struct entry* x; } ;
typedef  TYPE_1__* List ;
typedef  int /*<<< orphan*/  (* Apply ) (void*,void*,void*) ;

/* Variables and functions */
 int /*<<< orphan*/  NEW (struct entry*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PERM ; 
 TYPE_1__* append (struct entry*,TYPE_1__*) ; 
 int /*<<< orphan*/  stub1 (void*,void*,void*) ; 

void attach(Apply func, void *cl, List *list) {
	struct entry *p;

	NEW(p, PERM);
	p->func = func;
	p->cl = cl;
	*list = append(p, *list);
}

void apply(List event, void *arg1, void *arg2) {
	if (event) {
		List lp = event;
		do {
			struct entry *p = lp->x;
			(*p->func)(p->cl, arg1, arg2);
			lp = lp->link;
		} while (lp != event);
	}
}

