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
 unsigned int AUX_IRQ ; 
 int /*<<< orphan*/  ENABLE_IRQS_1 ; 
 int /*<<< orphan*/  IRQ_PENDING_1 ; 
 unsigned int SYSTEM_TIMER_IRQ_1 ; 
 char** entry_error_messages ; 
 unsigned int get32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_timer_irq () ; 
 int /*<<< orphan*/  handle_uart_irq () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,unsigned int) ; 

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1 | AUX_IRQ);
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

void handle_irq(void)
{
	unsigned int irq = get32(IRQ_PENDING_1);

	// loop in case multiple interrupts have been raised
	while (irq) {
		// each bitflag is only 1 bit so we do not 
		// need to test equality against themself
		if (irq & SYSTEM_TIMER_IRQ_1) {
			handle_timer_irq();
			irq &= ~SYSTEM_TIMER_IRQ_1;
		} else if (irq & AUX_IRQ) {
			handle_uart_irq();
			irq &= ~AUX_IRQ;
		} else {
			printf("Unknown pending irq: %x\r\n", irq);
			irq = 0;
		}
	}
}

