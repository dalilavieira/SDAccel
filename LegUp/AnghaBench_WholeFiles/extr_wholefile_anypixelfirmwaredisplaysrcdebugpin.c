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
typedef  int uint16_t ;
struct TYPE_3__ {int /*<<< orphan*/  pin; int /*<<< orphan*/  GPIOx; } ;

/* Variables and functions */
 scalar_t__ Bit_SET ; 
 int /*<<< orphan*/  CONFIG_pins (TYPE_1__*,size_t) ; 
 size_t DEBUGPIN_NUM ; 
 int /*<<< orphan*/  DEBUGPIN_POWER_AHB ; 
 int /*<<< orphan*/  ENABLE ; 
 scalar_t__ GPIO_ReadInputDataBit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_ResetBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_SetBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_AHBPeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__* pins_debug ; 

void DEBUGPIN_Config(void) {
	// enable clock to the relevant IO PORT(s)
	RCC_AHBPeriphClockCmd(DEBUGPIN_POWER_AHB, ENABLE);

    CONFIG_pins(pins_debug, DEBUGPIN_NUM);
}

inline void DEBUGPIN_Toggle(uint8_t index) {
    assert(index < DEBUGPIN_NUM);
    //GPIO_ToggleBits(pins_debug[index].GPIOx, pins_debug[index].pin);
    //FIXME this implementation is untested and was just implemented since the F0 std lib doesn't seem to include the toggle function (processor doesn't have toggle register)
    if(GPIO_ReadInputDataBit(pins_debug[index].GPIOx,pins_debug[index].pin) == Bit_SET)
        GPIO_ResetBits(pins_debug[index].GPIOx, pins_debug[index].pin);
    else
        GPIO_SetBits(pins_debug[index].GPIOx, pins_debug[index].pin);
}

inline void DEBUGPIN_High(uint8_t index) {
    assert(index < DEBUGPIN_NUM);
    GPIO_SetBits(pins_debug[index].GPIOx, pins_debug[index].pin);
}

inline void DEBUGPIN_Low(uint8_t index) {
    assert(index < DEBUGPIN_NUM);
    GPIO_ResetBits(pins_debug[index].GPIOx, pins_debug[index].pin);
}

void DEBUGPIN_Num(uint16_t state) {
    int i;
    for(i=0; i < DEBUGPIN_NUM; i++) {
        if(state & 1)
            GPIO_SetBits(pins_debug[i].GPIOx, pins_debug[i].pin);
        else
            GPIO_ResetBits(pins_debug[i].GPIOx, pins_debug[i].pin);
        state >>= 1;
    }
}

