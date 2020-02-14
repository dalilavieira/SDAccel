#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
typedef  int uint32_t ;
typedef  scalar_t__ int8_t ;
struct TYPE_3__ {int /*<<< orphan*/  pin; int /*<<< orphan*/  GPIOx; } ;

/* Variables and functions */
 scalar_t__ BUTTONS_NUM ; 
 size_t BUTTONS_POLARITY ; 
 int /*<<< orphan*/  BUTTONS_POWER_AHB1 ; 
 size_t BUTTONS_Read (size_t) ; 
 int /*<<< orphan*/  CONFIG_pins (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  ENABLE ; 
 size_t GPIO_ReadInputDataBit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_AHB1PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int configured ; 
 TYPE_1__* pin_buttons ; 

void BUTTONS_Config(void) {
	// enable clock to the relevant IO PORT(s)
	RCC_AHB1PeriphClockCmd(BUTTONS_POWER_AHB1, ENABLE);

    // configure the gpio pins to read from the buttons/switches
    CONFIG_pins(pin_buttons, BUTTONS_NUM);

	configured = true;
}

uint32_t BUTTONS_Read_All(void) {
	int8_t i;
	uint32_t result = 0;
	for(i = BUTTONS_NUM-1; i >= 0; i--)
		result = (result << 1) | BUTTONS_Read(i);
	return result;
}

uint8_t BUTTONS_Read(uint8_t index) {
	assert(configured == true);

	if(GPIO_ReadInputDataBit(pin_buttons[index].GPIOx, pin_buttons[index].pin) == ((BUTTONS_POLARITY >> index) & 1) )
		return 1;
	else
		return 0;
}

