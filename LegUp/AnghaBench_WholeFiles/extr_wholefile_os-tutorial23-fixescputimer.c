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
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  registers_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ0 ; 
 int /*<<< orphan*/  UNUSED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  port_byte_out (int,int) ; 
 int /*<<< orphan*/  register_interrupt_handler (int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  tick ; 

__attribute__((used)) static void timer_callback(registers_t *regs) {
    tick++;
    UNUSED(regs);
}

void init_timer(uint32_t freq) {
    /* Install the function we just wrote */
    register_interrupt_handler(IRQ0, timer_callback);

    /* Get the PIT value: hardware clock at 1193180 Hz */
    uint32_t divisor = 1193180 / freq;
    uint8_t low  = (uint8_t)(divisor & 0xFF);
    uint8_t high = (uint8_t)( (divisor >> 8) & 0xFF);
    /* Send the command */
    port_byte_out(0x43, 0x36); /* Command port */
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}

