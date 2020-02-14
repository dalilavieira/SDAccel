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
typedef  int u_short ;

/* Variables and functions */
 int /*<<< orphan*/  KBD_DATA_REG ; 
 int /*<<< orphan*/  KBD_STATUS_REG ; 
 int KBD_STAT_MOUSE_OBF ; 
 int KBD_STAT_OBF ; 
 scalar_t__ KDB_FLAG (int /*<<< orphan*/ ) ; 
 int KTYP (int) ; 
#define  KT_LATIN 130 
#define  KT_LETTER 129 
#define  KT_SPEC 128 
 int K_ENTER ; 
 int /*<<< orphan*/  NO_I8042 ; 
 int /*<<< orphan*/  NO_VT_CONSOLE ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isprint (int) ; 
 int kbd_exists ; 
 int kbd_last_ret ; 
 int /*<<< orphan*/  kdb_printf (char*,int) ; 
 int** key_maps ; 
 int* plain_map ; 

int kdb_get_kbd_char(void)
{
	int scancode, scanstatus;
	static int shift_lock;	/* CAPS LOCK state (0-off, 1-on) */
	static int shift_key;	/* Shift next keypress */
	static int ctrl_key;
	u_short keychar;

	if (KDB_FLAG(NO_I8042) || KDB_FLAG(NO_VT_CONSOLE) ||
	    (inb(KBD_STATUS_REG) == 0xff && inb(KBD_DATA_REG) == 0xff)) {
		kbd_exists = 0;
		return -1;
	}
	kbd_exists = 1;

	if ((inb(KBD_STATUS_REG) & KBD_STAT_OBF) == 0)
		return -1;

	/*
	 * Fetch the scancode
	 */
	scancode = inb(KBD_DATA_REG);
	scanstatus = inb(KBD_STATUS_REG);

	/*
	 * Ignore mouse events.
	 */
	if (scanstatus & KBD_STAT_MOUSE_OBF)
		return -1;

	/*
	 * Ignore release, trigger on make
	 * (except for shift keys, where we want to
	 *  keep the shift state so long as the key is
	 *  held down).
	 */

	if (((scancode&0x7f) == 0x2a) || ((scancode&0x7f) == 0x36)) {
		/*
		 * Next key may use shift table
		 */
		if ((scancode & 0x80) == 0)
			shift_key = 1;
		else
			shift_key = 0;
		return -1;
	}

	if ((scancode&0x7f) == 0x1d) {
		/*
		 * Left ctrl key
		 */
		if ((scancode & 0x80) == 0)
			ctrl_key = 1;
		else
			ctrl_key = 0;
		return -1;
	}

	if ((scancode & 0x80) != 0) {
		if (scancode == 0x9c)
			kbd_last_ret = 0;
		return -1;
	}

	scancode &= 0x7f;

	/*
	 * Translate scancode
	 */

	if (scancode == 0x3a) {
		/*
		 * Toggle caps lock
		 */
		shift_lock ^= 1;

#ifdef	KDB_BLINK_LED
		kdb_toggleled(0x4);
#endif
		return -1;
	}

	if (scancode == 0x0e) {
		/*
		 * Backspace
		 */
		return 8;
	}

	/* Special Key */
	switch (scancode) {
	case 0xF: /* Tab */
		return 9;
	case 0x53: /* Del */
		return 4;
	case 0x47: /* Home */
		return 1;
	case 0x4F: /* End */
		return 5;
	case 0x4B: /* Left */
		return 2;
	case 0x48: /* Up */
		return 16;
	case 0x50: /* Down */
		return 14;
	case 0x4D: /* Right */
		return 6;
	}

	if (scancode == 0xe0)
		return -1;

	/*
	 * For Japanese 86/106 keyboards
	 * 	See comment in drivers/char/pc_keyb.c.
	 * 	- Masahiro Adegawa
	 */
	if (scancode == 0x73)
		scancode = 0x59;
	else if (scancode == 0x7d)
		scancode = 0x7c;

	if (!shift_lock && !shift_key && !ctrl_key) {
		keychar = plain_map[scancode];
	} else if ((shift_lock || shift_key) && key_maps[1]) {
		keychar = key_maps[1][scancode];
	} else if (ctrl_key && key_maps[4]) {
		keychar = key_maps[4][scancode];
	} else {
		keychar = 0x0020;
		kdb_printf("Unknown state/scancode (%d)\n", scancode);
	}
	keychar &= 0x0fff;
	if (keychar == '\t')
		keychar = ' ';
	switch (KTYP(keychar)) {
	case KT_LETTER:
	case KT_LATIN:
		if (isprint(keychar))
			break;		/* printable characters */
		/* drop through */
	case KT_SPEC:
		if (keychar == K_ENTER)
			break;
		/* drop through */
	default:
		return -1;	/* ignore unprintables */
	}

	if (scancode == 0x1c) {
		kbd_last_ret = 1;
		return 13;
	}

	return keychar & 0xff;
}

void kdb_kbd_cleanup_state(void)
{
	int scancode, scanstatus;

	/*
	 * Nothing to clean up, since either
	 * ENTER was never pressed, or has already
	 * gotten cleaned up.
	 */
	if (!kbd_last_ret)
		return;

	kbd_last_ret = 0;
	/*
	 * Enter key. Need to absorb the break code here, lest it gets
	 * leaked out if we exit KDB as the result of processing 'g'.
	 *
	 * This has several interesting implications:
	 * + Need to handle KP ENTER, which has break code 0xe0 0x9c.
	 * + Need to handle repeat ENTER and repeat KP ENTER. Repeats
	 *   only get a break code at the end of the repeated
	 *   sequence. This means we can't propagate the repeated key
	 *   press, and must swallow it away.
	 * + Need to handle possible PS/2 mouse input.
	 * + Need to handle mashed keys.
	 */

	while (1) {
		while ((inb(KBD_STATUS_REG) & KBD_STAT_OBF) == 0)
			cpu_relax();

		/*
		 * Fetch the scancode.
		 */
		scancode = inb(KBD_DATA_REG);
		scanstatus = inb(KBD_STATUS_REG);

		/*
		 * Skip mouse input.
		 */
		if (scanstatus & KBD_STAT_MOUSE_OBF)
			continue;

		/*
		 * If we see 0xe0, this is either a break code for KP
		 * ENTER, or a repeat make for KP ENTER. Either way,
		 * since the second byte is equivalent to an ENTER,
		 * skip the 0xe0 and try again.
		 *
		 * If we see 0x1c, this must be a repeat ENTER or KP
		 * ENTER (and we swallowed 0xe0 before). Try again.
		 *
		 * We can also see make and break codes for other keys
		 * mashed before or after pressing ENTER. Thus, if we
		 * see anything other than 0x9c, we have to try again.
		 *
		 * Note, if you held some key as ENTER was depressed,
		 * that break code would get leaked out.
		 */
		if (scancode != 0x9c)
			continue;

		return;
	}
}

