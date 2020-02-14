#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int (* pv_nbgetchar ) () ;int (* pv_nbputchar ) (char) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 TYPE_1__* romvec ; 
 int stub1 () ; 
 int stub2 (char) ; 

int
prom_nbgetchar(void)
{
	int i = -1;
	unsigned long flags;

	local_irq_save(flags);
		i = (*(romvec->pv_nbgetchar))();
	local_irq_restore(flags);
	return i; /* Ugh, we could spin forever on unsupported proms ;( */
}

int
prom_nbputchar(char c)
{
	unsigned long flags;
	int i = -1;

	local_irq_save(flags);
		i = (*(romvec->pv_nbputchar))(c);
	local_irq_restore(flags);
	return i; /* Ugh, we could spin forever on unsupported proms ;( */
}

char
prom_getchar(void)
{
	int character;
	while((character = prom_nbgetchar()) == -1) ;
	return (char) character;
}

void
prom_putchar(char c)
{
	while(prom_nbputchar(c) == -1) ;
	return;
}

