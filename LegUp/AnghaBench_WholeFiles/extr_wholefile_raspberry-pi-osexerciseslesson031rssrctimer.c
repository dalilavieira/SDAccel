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
 int /*<<< orphan*/  ARM_TIMER_CLR ; 
 int /*<<< orphan*/  ARM_TIMER_CTRL ; 
 int /*<<< orphan*/  ARM_TIMER_LOAD ; 
 int CTRL_23BIT ; 
 int CTRL_ENABLE ; 
 int CTRL_INT_ENABLE ; 
 int /*<<< orphan*/  TIMER_C1 ; 
 int /*<<< orphan*/  TIMER_CLO ; 
 int /*<<< orphan*/  TIMER_CS ; 
 int TIMER_CS_M1 ; 
 int curVal ; 
 int get32 (int /*<<< orphan*/ ) ; 
 int interval ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,int) ; 

void timer_init(void) {
  curVal = get32(TIMER_CLO);
  curVal += interval;
  put32(TIMER_C1, curVal);
}

void handle_timer_irq(void) {
  curVal += interval;
  put32(TIMER_C1, curVal);
  put32(TIMER_CS, TIMER_CS_M1);
  printf("Timer interrupt received\n\r");
}

void arm_timer_init(void) {
  // According to the timer pre-divider register documentation, the default
  // pre-devider is configured to run at apb_clock/126 which is 1Mhz like the
  // system timer.
  put32(ARM_TIMER_LOAD, interval);
  put32(ARM_TIMER_CTRL, CTRL_ENABLE | CTRL_INT_ENABLE | CTRL_23BIT);
}

void handle_arm_timer_irq(void) {
  put32(ARM_TIMER_CLR, 1);
  printf("Timer interrupt received\n\r");
}

