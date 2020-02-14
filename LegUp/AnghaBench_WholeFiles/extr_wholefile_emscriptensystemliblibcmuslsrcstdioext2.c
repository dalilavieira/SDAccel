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
struct TYPE_6__ {size_t rend; size_t rpos; int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 int /*<<< orphan*/  F_ERR ; 

size_t __freadahead(FILE *f)
{
	return f->rend - f->rpos;
}

const char *__freadptr(FILE *f, size_t *sizep)
{
	size_t size = f->rend - f->rpos;
	if (!size) return 0;
	*sizep = size;
	return (const char *)f->rpos;
}

void __freadptrinc(FILE *f, size_t inc)
{
	f->rpos += inc;
}

void __fseterr(FILE *f)
{
	f->flags |= F_ERR;
}

