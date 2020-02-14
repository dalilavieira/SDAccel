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
struct work_struct {int dummy; } ;

/* Variables and functions */
 unsigned int AVR_QUOT (int /*<<< orphan*/ ) ; 
 scalar_t__ UART_DLL ; 
 scalar_t__ UART_DLM ; 
 scalar_t__ UART_FCR ; 
 char const UART_FCR_ENABLE_FIFO ; 
 scalar_t__ UART_IER ; 
 scalar_t__ UART_LCR ; 
 unsigned char UART_LCR_DLAB ; 
 unsigned char UART_LCR_EPAR ; 
 unsigned char UART_LCR_PARITY ; 
 unsigned char UART_LCR_STOP ; 
 unsigned char UART_LCR_WLEN8 ; 
 scalar_t__ UART_LSR ; 
 int UART_LSR_DR ; 
 char UART_LSR_TEMT ; 
 char UART_LSR_THRE ; 
 scalar_t__ UART_MCR ; 
 scalar_t__ UART_RX ; 
 scalar_t__ UART_TX ; 
 scalar_t__ avr_addr ; 
 int /*<<< orphan*/  avr_clock ; 
 int in_8 (scalar_t__) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  out_8 (scalar_t__,char const) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int strlen (char const*) ; 

__attribute__((used)) static void wd_stop(struct work_struct *unused)
{
	const char string[] = "AAAAFFFFJJJJ>>>>VVVV>>>>ZZZZVVVVKKKK";
	int i = 0, rescue = 8;
	int len = strlen(string);

	while (rescue--) {
		int j;
		char lsr = in_8(avr_addr + UART_LSR);

		if (lsr & (UART_LSR_THRE | UART_LSR_TEMT)) {
			for (j = 0; j < 16 && i < len; j++, i++)
				out_8(avr_addr + UART_TX, string[i]);
			if (i == len) {
				/* Read "OK" back: 4ms for the last "KKKK"
				   plus a couple bytes back */
				msleep(7);
				printk("linkstation: disarming the AVR watchdog: ");
				while (in_8(avr_addr + UART_LSR) & UART_LSR_DR)
					printk("%c", in_8(avr_addr + UART_RX));
				break;
			}
		}
		msleep(17);
	}
	printk("\n");
}

void avr_uart_configure(void)
{
	unsigned char cval = UART_LCR_WLEN8;
	unsigned int quot = AVR_QUOT(avr_clock);

	if (!avr_addr || !avr_clock)
		return;

	out_8(avr_addr + UART_LCR, cval);			/* initialise UART */
	out_8(avr_addr + UART_MCR, 0);
	out_8(avr_addr + UART_IER, 0);

	cval |= UART_LCR_STOP | UART_LCR_PARITY | UART_LCR_EPAR;

	out_8(avr_addr + UART_LCR, cval);			/* Set character format */

	out_8(avr_addr + UART_LCR, cval | UART_LCR_DLAB);	/* set DLAB */
	out_8(avr_addr + UART_DLL, quot & 0xff);		/* LS of divisor */
	out_8(avr_addr + UART_DLM, quot >> 8);			/* MS of divisor */
	out_8(avr_addr + UART_LCR, cval);			/* reset DLAB */
	out_8(avr_addr + UART_FCR, UART_FCR_ENABLE_FIFO);	/* enable FIFO */
}

void avr_uart_send(const char c)
{
	if (!avr_addr || !avr_clock)
		return;

	out_8(avr_addr + UART_TX, c);
	out_8(avr_addr + UART_TX, c);
	out_8(avr_addr + UART_TX, c);
	out_8(avr_addr + UART_TX, c);
}

