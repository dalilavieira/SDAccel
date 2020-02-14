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
 scalar_t__ PCIMT_CSWCSM ; 
 int inb_p (int) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void kb_wait(void)
{
	int i;

	for (i = 0; i < 0x10000; i++)
		if ((inb_p(0x64) & 0x02) == 0)
			break;
}

void sni_machine_restart(char *command)
{
	int i;

	/* This does a normal via the keyboard controller like a PC.
	   We can do that easier ...  */
	local_irq_disable();
	for (;;) {
		for (i = 0; i < 100; i++) {
			kb_wait();
			udelay(50);
			outb_p(0xfe, 0x64);	 /* pulse reset low */
			udelay(50);
		}
	}
}

void sni_machine_power_off(void)
{
	*(volatile unsigned char *)PCIMT_CSWCSM = 0xfd;
}

