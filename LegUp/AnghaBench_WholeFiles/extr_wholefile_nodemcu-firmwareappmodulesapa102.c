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
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_OUTPUT_SET (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  NOP ; 
 int /*<<< orphan*/  PLATFORM_GPIO_FLOAT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_HIGH ; 
 int /*<<< orphan*/  PLATFORM_GPIO_LOW ; 
 int /*<<< orphan*/  PLATFORM_GPIO_OUTPUT ; 
 int /*<<< orphan*/  gpio ; 
 int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int* pin_num ; 
 int /*<<< orphan*/  platform_gpio_mode (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void apa102_send_byte(uint32_t data_pin, uint32_t clock_pin, uint8_t byte) {
  int i;
  for (i = 0; i < 8; i++) {
    if (byte & 0x80) {
      GPIO_OUTPUT_SET(data_pin, PLATFORM_GPIO_HIGH); // Set pin high
    } else {
      GPIO_OUTPUT_SET(data_pin, PLATFORM_GPIO_LOW); // Set pin low
    }
    GPIO_OUTPUT_SET(clock_pin, PLATFORM_GPIO_HIGH); // Set pin high
    byte <<= 1;
    NOP;
    NOP;
    GPIO_OUTPUT_SET(clock_pin, PLATFORM_GPIO_LOW); // Set pin low
    NOP;
    NOP;
  }
}

__attribute__((used)) static void apa102_send_buffer(uint32_t data_pin, uint32_t clock_pin, uint32_t *buf, uint32_t nbr_frames) {
  int i;

  // Send 32-bit Start Frame that's all 0x00
  apa102_send_byte(data_pin, clock_pin, 0x00);
  apa102_send_byte(data_pin, clock_pin, 0x00);
  apa102_send_byte(data_pin, clock_pin, 0x00);
  apa102_send_byte(data_pin, clock_pin, 0x00);

  // Send 32-bit LED Frames
  for (i = 0; i < nbr_frames; i++) {
    uint8_t *byte = (uint8_t *) buf++;

    // Set the first 3 bits of that byte to 1.
    // This makes the lua interface easier to use since you
    // don't have to worry about creating invalid LED Frames.
    byte[0] |= 0xE0;
    apa102_send_byte(data_pin, clock_pin, byte[0]);
    apa102_send_byte(data_pin, clock_pin, byte[1]);
    apa102_send_byte(data_pin, clock_pin, byte[2]);
    apa102_send_byte(data_pin, clock_pin, byte[3]);
  }

  // Send 32-bit End Frames
  uint32_t required_postamble_frames = (nbr_frames + 1) / 2;
  for (i = 0; i < required_postamble_frames; i++) {
    apa102_send_byte(data_pin, clock_pin, 0xFF);
    apa102_send_byte(data_pin, clock_pin, 0xFF);
    apa102_send_byte(data_pin, clock_pin, 0xFF);
    apa102_send_byte(data_pin, clock_pin, 0xFF);
  }
}

__attribute__((used)) static int apa102_write(lua_State* L) {
  uint8_t data_pin = luaL_checkinteger(L, 1);
  MOD_CHECK_ID(gpio, data_pin);
  uint32_t alt_data_pin = pin_num[data_pin];

  uint8_t clock_pin = luaL_checkinteger(L, 2);
  MOD_CHECK_ID(gpio, clock_pin);
  uint32_t alt_clock_pin = pin_num[clock_pin];

  size_t buf_len;
  const char *buf = luaL_checklstring(L, 3, &buf_len);
  uint32_t nbr_frames = buf_len / 4;

  if (nbr_frames > 100000) {
    return luaL_error(L, "The supplied buffer is too long, and might cause the callback watchdog to bark.");
  }

  // Initialize the output pins
  platform_gpio_mode(data_pin, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_FLOAT);
  GPIO_OUTPUT_SET(alt_data_pin, PLATFORM_GPIO_HIGH); // Set pin high
  platform_gpio_mode(clock_pin, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_FLOAT);
  GPIO_OUTPUT_SET(alt_clock_pin, PLATFORM_GPIO_LOW); // Set pin low

  // Send the buffers
  apa102_send_buffer(alt_data_pin, alt_clock_pin, (uint32_t *) buf, (uint32_t) nbr_frames);
  return 0;
}

