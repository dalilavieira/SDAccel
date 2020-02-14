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
typedef  int u32 ;

/* Variables and functions */
 scalar_t__ CKSEG1ADDR (int) ; 
 int _prom_get_hwconf () ; 
 char* _prom_getenv (char*) ; 
 int /*<<< orphan*/  _prom_putchar (char) ; 
 char const* system_type ; 

void prom_putchar(char c)
{
	_prom_putchar(c);
}

char *prom_getenv(char *s)
{
	return _prom_getenv(s);
}

void *prom_get_hwconf(void)
{
	u32 hwconf = _prom_get_hwconf();

	if (hwconf == 0xffffffff)
		return NULL;

	return (void *)CKSEG1ADDR(hwconf);
}

const char *get_system_type(void)
{
	return system_type;
}

