#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int lock; int /*<<< orphan*/  waiters; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 int /*<<< orphan*/  __wait (int*,int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ ftrylockfile (TYPE_1__*) ; 

void flockfile(FILE *f)
{
	while (ftrylockfile(f)) {
		int owner = f->lock;
		if (owner) __wait(&f->lock, &f->waiters, owner, 1);
	}
}

