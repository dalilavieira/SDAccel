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
struct TYPE_2__ {int command; unsigned char data; } ;

/* Variables and functions */
 int HZ ; 
 int KBD_STAT_IBF ; 
 TYPE_1__* jazz_kh ; 
 unsigned long jiffies ; 
 scalar_t__ time_before_eq (unsigned long,unsigned long) ; 

__attribute__((used)) static void jazz_write_output(unsigned char val)
{
	int status;

	do {
		status = jazz_kh->command;
	} while (status & KBD_STAT_IBF);
	jazz_kh->data = val;
}

__attribute__((used)) static void jazz_write_command(unsigned char val)
{
	int status;

	do {
		status = jazz_kh->command;
	} while (status & KBD_STAT_IBF);
	jazz_kh->command = val;
}

__attribute__((used)) static unsigned char jazz_read_status(void)
{
	return jazz_kh->command;
}

__attribute__((used)) static inline void kb_wait(void)
{
	unsigned long start = jiffies;
	unsigned long timeout = start + HZ/2;

	do {
		if (! (jazz_read_status() & 0x02))
			return;
	} while (time_before_eq(jiffies, timeout));
}

void jazz_machine_restart(char *command)
{
	while(1) {
		kb_wait();
		jazz_write_command(0xd1);
		kb_wait();
		jazz_write_output(0x00);
	}
}

