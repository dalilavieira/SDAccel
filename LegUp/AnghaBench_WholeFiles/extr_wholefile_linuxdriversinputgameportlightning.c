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
struct l4 {int port; } ;
struct gameport {struct l4* port_data; } ;

/* Variables and functions */
 int GAMEPORT_MODE_COOKED ; 
 int L4_BUSY ; 
 int L4_CMD_GETCAL ; 
 int L4_CMD_SETCAL ; 
 int /*<<< orphan*/  L4_PORT ; 
 int L4_SELECT_ANALOG ; 
 int L4_SELECT_DIGITAL ; 
 unsigned int L4_TIMEOUT ; 
 int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int l4_wait_ready(void)
{
	unsigned int t = L4_TIMEOUT;

	while ((inb(L4_PORT) & L4_BUSY) && t > 0) t--;
	return -(t <= 0);
}

__attribute__((used)) static int l4_cooked_read(struct gameport *gameport, int *axes, int *buttons)
{
	struct l4 *l4 = gameport->port_data;
	unsigned char status;
	int i, result = -1;

	outb(L4_SELECT_ANALOG, L4_PORT);
	outb(L4_SELECT_DIGITAL + (l4->port >> 2), L4_PORT);

	if (inb(L4_PORT) & L4_BUSY) goto fail;
	outb(l4->port & 3, L4_PORT);

	if (l4_wait_ready()) goto fail;
	status = inb(L4_PORT);

	for (i = 0; i < 4; i++)
		if (status & (1 << i)) {
			if (l4_wait_ready()) goto fail;
			axes[i] = inb(L4_PORT);
			if (axes[i] > 252) axes[i] = -1;
		}

	if (status & 0x10) {
		if (l4_wait_ready()) goto fail;
		*buttons = inb(L4_PORT) & 0x0f;
	}

	result = 0;

fail:	outb(L4_SELECT_ANALOG, L4_PORT);
	return result;
}

__attribute__((used)) static int l4_open(struct gameport *gameport, int mode)
{
	struct l4 *l4 = gameport->port_data;

        if (l4->port != 0 && mode != GAMEPORT_MODE_COOKED)
		return -1;
	outb(L4_SELECT_ANALOG, L4_PORT);
	return 0;
}

__attribute__((used)) static int l4_getcal(int port, int *cal)
{
	int i, result = -1;

	outb(L4_SELECT_ANALOG, L4_PORT);
	outb(L4_SELECT_DIGITAL + (port >> 2), L4_PORT);
	if (inb(L4_PORT) & L4_BUSY)
		goto out;

	outb(L4_CMD_GETCAL, L4_PORT);
	if (l4_wait_ready())
		goto out;

	if (inb(L4_PORT) != L4_SELECT_DIGITAL + (port >> 2))
		goto out;

	if (l4_wait_ready())
		goto out;
        outb(port & 3, L4_PORT);

	for (i = 0; i < 4; i++) {
		if (l4_wait_ready())
			goto out;
		cal[i] = inb(L4_PORT);
	}

	result = 0;

out:	outb(L4_SELECT_ANALOG, L4_PORT);
	return result;
}

__attribute__((used)) static int l4_setcal(int port, int *cal)
{
	int i, result = -1;

	outb(L4_SELECT_ANALOG, L4_PORT);
	outb(L4_SELECT_DIGITAL + (port >> 2), L4_PORT);
	if (inb(L4_PORT) & L4_BUSY)
		goto out;

	outb(L4_CMD_SETCAL, L4_PORT);
	if (l4_wait_ready())
		goto out;

	if (inb(L4_PORT) != L4_SELECT_DIGITAL + (port >> 2))
		goto out;

	if (l4_wait_ready())
		goto out;
        outb(port & 3, L4_PORT);

	for (i = 0; i < 4; i++) {
		if (l4_wait_ready())
			goto out;
		outb(cal[i], L4_PORT);
	}

	result = 0;

out:	outb(L4_SELECT_ANALOG, L4_PORT);
	return result;
}

__attribute__((used)) static int l4_calibrate(struct gameport *gameport, int *axes, int *max)
{
	int i, t;
	int cal[4];
	struct l4 *l4 = gameport->port_data;

	if (l4_getcal(l4->port, cal))
		return -1;

	for (i = 0; i < 4; i++) {
		t = (max[i] * cal[i]) / 200;
		t = (t < 1) ? 1 : ((t > 255) ? 255 : t);
		axes[i] = (axes[i] < 0) ? -1 : (axes[i] * cal[i]) / t;
		axes[i] = (axes[i] > 252) ? 252 : axes[i];
		cal[i] = t;
	}

	if (l4_setcal(l4->port, cal))
		return -1;

	return 0;
}

