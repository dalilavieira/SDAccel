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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int inb (int /*<<< orphan*/ ) ; 
 int lpt_hardware_initialized ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void byteblaster_write(int port, int data)
{
	outb((u8)data, (u16)(port + 0x378));
}

__attribute__((used)) static int byteblaster_read(int port)
{
	int data = 0;
	data = inb((u16)(port + 0x378));
	return data & 0xff;
}

int netup_jtag_io_lpt(void *device, int tms, int tdi, int read_tdo)
{
	int data = 0;
	int tdo = 0;
	int initial_lpt_ctrl = 0;

	if (!lpt_hardware_initialized) {
		initial_lpt_ctrl = byteblaster_read(2);
		byteblaster_write(2, (initial_lpt_ctrl | 0x02) & 0xdf);
		lpt_hardware_initialized = 1;
	}

	data = ((tdi ? 0x40 : 0) | (tms ? 0x02 : 0));

	byteblaster_write(0, data);

	if (read_tdo) {
		tdo = byteblaster_read(1);
		tdo = ((tdo & 0x80) ? 0 : 1);
	}

	byteblaster_write(0, data | 0x01);

	byteblaster_write(0, data);

	return tdo;
}

