#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tty_driver {int dummy; } ;
struct console {int index; } ;
struct TYPE_3__ {int flags; } ;

/* Variables and functions */
 int CON_ENABLED ; 
 int /*<<< orphan*/  SSC_PUTCHAR ; 
 struct tty_driver* hp_simserial_driver ; 
 TYPE_1__ hpsim_cons ; 
 int /*<<< orphan*/  ia64_platform_is (char*) ; 
 int /*<<< orphan*/  ia64_ssc (char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  register_console (TYPE_1__*) ; 

__attribute__((used)) static int
simcons_init (struct console *cons, char *options)
{
	return 0;
}

__attribute__((used)) static void
simcons_write (struct console *cons, const char *buf, unsigned count)
{
	unsigned long ch;

	while (count-- > 0) {
		ch = *buf++;
		ia64_ssc(ch, 0, 0, 0, SSC_PUTCHAR);
		if (ch == '\n')
		  ia64_ssc('\r', 0, 0, 0, SSC_PUTCHAR);
	}
}

__attribute__((used)) static struct tty_driver *simcons_console_device (struct console *c, int *index)
{
	*index = c->index;
	return hp_simserial_driver;
}

int simcons_register(void)
{
	if (!ia64_platform_is("hpsim"))
		return 1;

	if (hpsim_cons.flags & CON_ENABLED)
		return 1;

	register_console(&hpsim_cons);
	return 0;
}

