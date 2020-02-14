#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_6__ {int high; int low; } ;
struct TYPE_5__ {int invertedSignal; TYPE_2__ syncFactor; TYPE_2__ zero; TYPE_2__ one; } ;
typedef  TYPE_1__ Protocol ;
typedef  TYPE_2__ HighLow ;

/* Variables and functions */
 int /*<<< orphan*/  PLATFORM_GPIO_FLOAT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_OUTPUT ; 
 void* luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  os_delay_us (int) ; 
 int /*<<< orphan*/  platform_gpio_mode (unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_gpio_write (int,int) ; 
 TYPE_1__* proto ; 

void transmit(HighLow pulses, bool invertedSignal, int pulseLength, int pin) {
  platform_gpio_write(pin, !invertedSignal);
  os_delay_us(pulseLength * pulses.high);
  platform_gpio_write(pin, invertedSignal);
  os_delay_us(pulseLength * pulses.low);
}

void send(unsigned long protocol_id, unsigned long pulse_length, unsigned long repeat, unsigned long pin, unsigned long value, unsigned int length) {
  platform_gpio_mode(pin, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_FLOAT);
  Protocol p = proto[protocol_id-1];
  for (int nRepeat = 0; nRepeat < repeat; nRepeat++) {
    for (int i = length-1; i >= 0; i--) {
      if (value & (1L << i))
        transmit(p.one, p.invertedSignal, pulse_length, pin);
      else
        transmit(p.zero, p.invertedSignal, pulse_length, pin);
    }
    transmit(p.syncFactor, p.invertedSignal, pulse_length, pin);
  }
}

__attribute__((used)) static int rfswitch_send( lua_State *L )
{
  unsigned int protocol_id = luaL_checkinteger( L, 1 );
  unsigned int pulse_length = luaL_checkinteger( L, 2 );
  unsigned int repeat = luaL_checkinteger( L, 3 );
  unsigned int pin = luaL_checkinteger( L, 4 );
  unsigned long value = luaL_checkinteger( L, 5 );
  unsigned long length = luaL_checkinteger( L, 6 );
  send(protocol_id, pulse_length, repeat, pin, value, length);
  return 0;
}

