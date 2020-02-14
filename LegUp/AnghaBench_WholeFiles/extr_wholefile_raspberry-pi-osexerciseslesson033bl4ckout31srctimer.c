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
 int /*<<< orphan*/  TIMER_C1 ; 
 int /*<<< orphan*/  TIMER_CLO ; 
 int /*<<< orphan*/  TIMER_CS ; 
 int /*<<< orphan*/  TIMER_CS_M1 ; 
 int /*<<< orphan*/  curVal ; 
 int /*<<< orphan*/  gen_timer_init () ; 
 int /*<<< orphan*/  gen_timer_reset () ; 
 int /*<<< orphan*/  get32 (int /*<<< orphan*/ ) ; 
 scalar_t__ interval ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void timer_init ( void )
{
	curVal = get32(TIMER_CLO);
	curVal += interval;
	put32(TIMER_C1, curVal);
}

void handle_timer_irq( void ) 
{
	curVal += interval;
	put32(TIMER_C1, curVal);
	put32(TIMER_CS, TIMER_CS_M1);
	printf("Timer interrupt received\n\r");
}

void generic_timer_init ( void )
{
	gen_timer_init();
	gen_timer_reset();
}

void handle_generic_timer_irq( void ) 
{
	printf("Timer interrupt received\n\r");
	gen_timer_reset();
}

