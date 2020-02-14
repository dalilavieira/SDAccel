#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int tid; } ;
struct TYPE_5__ {int lock; scalar_t__ waiters; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 TYPE_3__* __pthread_self () ; 
 int /*<<< orphan*/  __wait (int*,scalar_t__*,int,int) ; 
 int /*<<< orphan*/  __wake (int*,int,int) ; 
 int a_cas (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  a_store (int*,int /*<<< orphan*/ ) ; 

int __lockfile(FILE *f)
{
#ifndef __EMSCRIPTEN__ // XXX EMSCRIPTEN: for now no pthreads; ignore locking
	int owner, tid = __pthread_self()->tid;
	if (f->lock == tid)
		return 0;
	while ((owner = a_cas(&f->lock, 0, tid)))
		__wait(&f->lock, &f->waiters, owner, 1);
#endif
	return 1;
}

void __unlockfile(FILE *f)
{
#ifndef __EMSCRIPTEN__
	a_store(&f->lock, 0);

	/* The following read is technically invalid under situations
	 * of self-synchronized destruction. Another thread may have
	 * called fclose as soon as the above store has completed.
	 * Nonetheless, since FILE objects always live in memory
	 * obtained by malloc from the heap, it's safe to assume
	 * the dereferences below will not fault. In the worst case,
	 * a spurious syscall will be made. If the implementation of
	 * malloc changes, this assumption needs revisiting. */

	if (f->waiters) __wake(&f->lock, 1, 1);
#endif
}

