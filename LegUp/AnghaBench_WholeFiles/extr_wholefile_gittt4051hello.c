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
 int /*<<< orphan*/  putchar (char) ; 

__attribute__((used)) static void hello(void)	// Begin of hello
{
	/*
	 * Classic.
	 */
	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');
	putchar(' ');
	/* delete me from hello */
	putchar('w');
	putchar('o');
	putchar('r');
	putchar('l');
	putchar('d');
	putchar('.');
	putchar('\n');
}

