#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {scalar_t__ wpos; scalar_t__ wbase; scalar_t__ rpos; scalar_t__ rend; scalar_t__ wend; struct TYPE_10__* next; int /*<<< orphan*/  (* seek ) (TYPE_1__*,scalar_t__,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write ) (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 int EOF ; 
 int /*<<< orphan*/  FLOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  FUNLOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  SEEK_CUR ; 
 TYPE_1__** __ofl_lock () ; 
 int /*<<< orphan*/  __ofl_unlock () ; 
 TYPE_1__* __stdout_used ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __fflush_unlocked(FILE *f)
{
	/* If writing, flush output */
	if (f->wpos > f->wbase) {
		f->write(f, 0, 0);
		if (!f->wpos) return EOF;
	}

	/* If reading, sync position, per POSIX */
	if (f->rpos < f->rend) f->seek(f, f->rpos-f->rend, SEEK_CUR);

	/* Clear read and write modes */
	f->wpos = f->wbase = f->wend = 0;
	f->rpos = f->rend = 0;

	return 0;
}

int fflush(FILE *f)
{
	int r;

	if (f) {
		FLOCK(f);
		r = __fflush_unlocked(f);
		FUNLOCK(f);
		return r;
	}

	r = __stdout_used ? fflush(__stdout_used) : 0;

	for (f=*__ofl_lock(); f; f=f->next) {
		FLOCK(f);
		if (f->wpos > f->wbase) r |= __fflush_unlocked(f);
		FUNLOCK(f);
	}
	__ofl_unlock();
	
	return r;
}

