#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* pthread_t ;
struct TYPE_7__ {int lock; int lockcount; struct TYPE_7__* prev_locked; struct TYPE_7__* next_locked; } ;
struct TYPE_6__ {int tid; TYPE_2__* stdio_locks; } ;
typedef  TYPE_2__ FILE ;

/* Variables and functions */
 int LONG_MAX ; 
 TYPE_1__* __pthread_self () ; 
 scalar_t__ a_cas (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  a_store (int*,int) ; 

void __do_orphaned_stdio_locks()
{
	FILE *f;
	for (f=__pthread_self()->stdio_locks; f; f=f->next_locked)
		a_store(&f->lock, 0x40000000);
}

void __unlist_locked_file(FILE *f)
{
	if (f->lockcount) {
		if (f->next_locked) f->next_locked->prev_locked = f->prev_locked;
		if (f->prev_locked) f->prev_locked->next_locked = f->next_locked;
		else __pthread_self()->stdio_locks = f->next_locked;
	}
}

int ftrylockfile(FILE *f)
{
	pthread_t self = __pthread_self();
	int tid = self->tid;
	if (f->lock == tid) {
		if (f->lockcount == LONG_MAX)
			return -1;
		f->lockcount++;
		return 0;
	}
	if (f->lock < 0) f->lock = 0;
	if (f->lock || a_cas(&f->lock, 0, tid))
		return -1;
	f->lockcount = 1;
	f->prev_locked = 0;
	f->next_locked = self->stdio_locks;
	if (f->next_locked) f->next_locked->prev_locked = f;
	self->stdio_locks = f;
	return 0;
}

