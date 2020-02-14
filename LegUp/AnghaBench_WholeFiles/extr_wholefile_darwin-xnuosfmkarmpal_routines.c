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

/* Variables and functions */
 int serial_getc () ; 
 int serial_init () ; 
 int /*<<< orphan*/  serial_putc (char) ; 

int
pal_serial_init(void)
{
	return serial_init();
}

void
pal_serial_putc_nocr(char c)
{
	serial_putc(c);
}

void
pal_serial_putc(char c)
{
	serial_putc(c);
}

int
pal_serial_getc(void)
{
	return serial_getc();
}

