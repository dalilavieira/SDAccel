#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
typedef  int uint16_t ;
struct TYPE_7__ {int /*<<< orphan*/  pin; int /*<<< orphan*/  GPIOx; } ;
typedef  TYPE_1__ CONFIG_Pin_TypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  ENABLE ; 
 int GPIO_ReadInputDataBit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_ResetBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_SetBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_ToggleBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PIN_POWER_AHB1 ; 
 int /*<<< orphan*/  RCC_AHB1PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void PIN_Config(void) {
    RCC_AHB1PeriphClockCmd(PIN_POWER_AHB1, ENABLE);
    #ifdef USE_DEBUG_PINS
        // enable clock to the relevant IO PORT(s)
        RCC_AHB1PeriphClockCmd(DEBUGPIN_POWER_AHB1, ENABLE);

        CONFIG_pins(pins_debug, DEBUGPIN_NUM);
    #endif
}

inline void PIN_Toggle(const CONFIG_Pin_TypeDef *pins, uint8_t index) {
    GPIO_ToggleBits(pins[index].GPIOx, pins[index].pin);
}

inline void PIN_High(const CONFIG_Pin_TypeDef *pins, uint8_t index) {
    GPIO_SetBits(pins[index].GPIOx, pins[index].pin);
}

inline void PIN_Low(const CONFIG_Pin_TypeDef *pins, uint8_t index) {
    GPIO_ResetBits(pins[index].GPIOx, pins[index].pin);
}

bool PIN_State(const CONFIG_Pin_TypeDef *pins, uint8_t index) {
    return GPIO_ReadInputDataBit(pins[index].GPIOx, pins[index].pin);
}

void PIN_Num(const CONFIG_Pin_TypeDef *pins, uint16_t state, uint8_t num_pins) {
    int i;
    for(i = 0; i < num_pins; i++) {
        if(state & 1)
            GPIO_SetBits(pins[i].GPIOx, pins[i].pin);
        else
            GPIO_ResetBits(pins[i].GPIOx, pins[i].pin);
        state >>= 1;
    }
}

