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
 int /*<<< orphan*/  GPIO_ENABLE1_W1TS_REG ; 
 int /*<<< orphan*/  GPIO_ENABLE_W1TS_REG ; 
 int /*<<< orphan*/  GPIO_OUT1_W1TC_REG ; 
 int /*<<< orphan*/  GPIO_OUT1_W1TS_REG ; 
 int GPIO_OUT_REG ; 
 int /*<<< orphan*/  GPIO_OUT_W1TC_REG ; 
 int /*<<< orphan*/  GPIO_OUT_W1TS_REG ; 
 scalar_t__ READ_PERI_REG (int) ; 
 int /*<<< orphan*/  WRITE_PERI_REG (int /*<<< orphan*/ ,int) ; 

void led_setup(int io) {
  if (io < 32) {
    WRITE_PERI_REG(GPIO_ENABLE_W1TS_REG, 1 << io);
  } else {
    WRITE_PERI_REG(GPIO_ENABLE1_W1TS_REG, 1 << (io - 32));
  }
}

void led_on(int io) {
  if (io < 32) {
    WRITE_PERI_REG(GPIO_OUT_W1TS_REG, 1 << io);
  } else {
    WRITE_PERI_REG(GPIO_OUT1_W1TS_REG, 1 << (io - 32));
  }
}

void led_off(int io) {
  if (io < 32) {
    WRITE_PERI_REG(GPIO_OUT_W1TC_REG, 1 << io);
  } else {
    WRITE_PERI_REG(GPIO_OUT1_W1TC_REG, 1 << (io - 32));
  }
}

void led_toggle(int io) {
  if (READ_PERI_REG(GPIO_OUT_REG & (1 << io))) {
    WRITE_PERI_REG(GPIO_OUT_W1TC_REG, 1 << io);
  } else {
    WRITE_PERI_REG(GPIO_OUT_W1TS_REG, 1 << io);
  }
}

