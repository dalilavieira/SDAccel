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
struct input_ctx {int dummy; } ;

/* Variables and functions */

void terminal_init(void)
{
}

void terminal_setup_getch(struct input_ctx *ictx)
{
}

void terminal_uninit(void)
{
}

void terminal_get_size(int *w, int *h)
{
}

void mp_write_console_ansi(void *wstream, char *buf)
{
}

