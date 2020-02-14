#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int flags; size_t wend; scalar_t__ lbf; size_t buf_size; size_t wpos; size_t wbase; scalar_t__ rend; scalar_t__ rpos; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 int F_NORD ; 
 int F_NOWR ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 

void _flushlbf(void)
{
	fflush(0);
}

int __fsetlocking(FILE *f, int type)
{
	return 0;
}

int __fwriting(FILE *f)
{
	return (f->flags & F_NORD) || f->wend;
}

int __freading(FILE *f)
{
	return (f->flags & F_NOWR) || f->rend;
}

int __freadable(FILE *f)
{
	return !(f->flags & F_NORD);
}

int __fwritable(FILE *f)
{
	return !(f->flags & F_NOWR);
}

int __flbf(FILE *f)
{
	return f->lbf >= 0;
}

size_t __fbufsize(FILE *f)
{
	return f->buf_size;
}

size_t __fpending(FILE *f)
{
	return f->wend ? f->wpos - f->wbase : 0;
}

int __fpurge(FILE *f)
{
	f->wpos = f->wbase = f->wend = 0;
	f->rpos = f->rend = 0;
	return 0;
}

