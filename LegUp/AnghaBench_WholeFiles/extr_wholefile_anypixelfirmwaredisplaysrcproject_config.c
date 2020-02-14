#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_8__ {int /*<<< orphan*/  pin; int /*<<< orphan*/  GPIOx; int /*<<< orphan*/  speed; int /*<<< orphan*/  PuPd; int /*<<< orphan*/  otype; int /*<<< orphan*/  mode; int /*<<< orphan*/  af; int /*<<< orphan*/  pinsource; } ;
struct TYPE_7__ {int /*<<< orphan*/  GPIO_Speed; int /*<<< orphan*/  GPIO_PuPd; int /*<<< orphan*/  GPIO_OType; int /*<<< orphan*/  GPIO_Mode; int /*<<< orphan*/  GPIO_Pin; } ;
typedef  TYPE_1__ GPIO_InitTypeDef ;
typedef  TYPE_2__ CONFIG_Pin_TypeDef ;

/* Variables and functions */
 int ADDRPIN_NUM ; 
 int /*<<< orphan*/  ADDRPIN_POWER_AHB ; 
 scalar_t__ Bit_SET ; 
 int /*<<< orphan*/  ENABLE ; 
 int /*<<< orphan*/  GPIO_Init (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  GPIO_PinAFConfig (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GPIO_ReadInputDataBit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_AHBPeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__* pins_addrPD ; 
 TYPE_2__* pins_addrPU ; 
 int /*<<< orphan*/  usleep (int) ; 

void CONFIG_Setup(void) {

}

void CONFIG_pins(const CONFIG_Pin_TypeDef *pins, int num_pins ) {
    GPIO_InitTypeDef  GPIO_InitStructure;
    int i;

    for(i = 0; i < num_pins; i++) {
        //if(pins[i].mode == GPIO_Mode_AF)
        GPIO_PinAFConfig(pins[i].GPIOx, pins[i].pinsource, pins[i].af);

        GPIO_InitStructure.GPIO_Pin = pins[i].pin;
        GPIO_InitStructure.GPIO_Mode = pins[i].mode;
        GPIO_InitStructure.GPIO_OType = pins[i].otype;
        GPIO_InitStructure.GPIO_PuPd = pins[i].PuPd;
        GPIO_InitStructure.GPIO_Speed = pins[i].speed;
        GPIO_Init(pins[i].GPIOx, &GPIO_InitStructure);

    }
}

uint32_t CONFIG_get_addr(void) {
    uint32_t low = 0, high = 0;
    int i;
    RCC_AHBPeriphClockCmd(ADDRPIN_POWER_AHB, ENABLE);
    // capture the values in both pull up and pull down
    CONFIG_pins(pins_addrPD, ADDRPIN_NUM);
    usleep(5000);
    for(i = ADDRPIN_NUM-1; i >= 0; i--) {
        if( GPIO_ReadInputDataBit(pins_addrPD[i].GPIOx, pins_addrPD[i].pin) == Bit_SET)
            low = (low << 1) | 1;
        else
            low = (low << 1);
    }
    CONFIG_pins(pins_addrPU, ADDRPIN_NUM);
    usleep(5000);
    for(i = ADDRPIN_NUM-1; i >= 0; i--) {
        if( GPIO_ReadInputDataBit(pins_addrPU[i].GPIOx, pins_addrPU[i].pin) == Bit_SET)
            high = (high << 1) | 1;
        else
            high = (high << 1);
    }
    if(low == high)
        return high;
    else
        return 4;
}

