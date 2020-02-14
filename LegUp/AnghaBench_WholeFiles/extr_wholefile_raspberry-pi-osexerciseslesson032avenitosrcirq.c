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
 int /*<<< orphan*/  AUX_IRQ ; 
 int /*<<< orphan*/  ENABLE_IRQS_1 ; 
 int /*<<< orphan*/  IRQ_PENDING_1 ; 
 unsigned int SYSTEM_TIMER_IRQ_1 ; 
 unsigned int en_AUX_INT ; 
 char** entry_error_messages ; 
 unsigned int get32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_timer_irq () ; 
 int /*<<< orphan*/  handle_uart_irq () ; 
 unsigned int miniUART_IRQ ; 
 int /*<<< orphan*/  printf (char*,char*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,unsigned int) ; 

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1 | en_AUX_INT);
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

void handle_irq(void)
{
	unsigned int irq1 = get32(IRQ_PENDING_1);
	unsigned int irq2 = get32(AUX_IRQ);

	if (irq1 & SYSTEM_TIMER_IRQ_1) handle_timer_irq();
	if (irq2 & miniUART_IRQ) handle_uart_irq();
	
}

