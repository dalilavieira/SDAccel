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
 scalar_t__ LED_BASE ; 
 int /*<<< orphan*/  clear ; 
 int emma2rh_in32 (int) ; 
 int /*<<< orphan*/  emma2rh_out32 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emma2rh_out8 (scalar_t__,char const) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int strlen (char const*) ; 

void markeins_led_clear(void)
{
	emma2rh_out32(LED_BASE, clear);
	emma2rh_out32(LED_BASE + 4, clear);
}

void markeins_led(const char *str)
{
	int i;
	int len = strlen(str);

	markeins_led_clear();
	if (len > 8)
		len = 8;

	if (emma2rh_in32(0xb0000800) & (0x1 << 18))
		for (i = 0; i < len; i++)
			emma2rh_out8(LED_BASE + i, str[i]);
	else
		for (i = 0; i < len; i++)
			emma2rh_out8(LED_BASE + (i & 4) + (3 - (i & 3)),
				     str[i]);
}

void markeins_led_hex(u32 val)
{
	char str[10];

	sprintf(str, "%08x", val);
	markeins_led(str);
}

