#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct tty_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  tty_insert_flip_char (struct tty_port*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tty_schedule_flip (struct tty_port*) ; 

__attribute__((used)) static inline void
kbd_put_queue(struct tty_port *port, int ch)
{
	tty_insert_flip_char(port, ch, 0);
	tty_schedule_flip(port);
}

__attribute__((used)) static inline void
kbd_puts_queue(struct tty_port *port, char *cp)
{
	while (*cp)
		tty_insert_flip_char(port, *cp++, 0);
	tty_schedule_flip(port);
}

