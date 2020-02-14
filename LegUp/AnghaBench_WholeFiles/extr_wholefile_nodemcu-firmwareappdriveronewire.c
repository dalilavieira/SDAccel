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
typedef  scalar_t__ uint8_t ;
typedef  size_t uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  DIRECT_MODE_INPUT (scalar_t__) ; 
 scalar_t__ DIRECT_READ (scalar_t__) ; 
 int /*<<< orphan*/  DIRECT_WRITE_HIGH (scalar_t__) ; 
 int /*<<< orphan*/  DIRECT_WRITE_LOW (scalar_t__) ; 
 int /*<<< orphan*/  PLATFORM_GPIO_INPUT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_PULLUP ; 
 int /*<<< orphan*/  delayMicroseconds (int) ; 
 int /*<<< orphan*/  interrupts () ; 
 int /*<<< orphan*/  noInterrupts () ; 
 int owDefaultPower ; 
 int /*<<< orphan*/  platform_gpio_mode (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void onewire_init(uint8_t pin)
{
	// pinMode(pin, INPUT);
  platform_gpio_mode(pin, PLATFORM_GPIO_INPUT, PLATFORM_GPIO_PULLUP);
#if ONEWIRE_SEARCH
	onewire_reset_search(pin);
#endif
}

uint8_t onewire_reset(uint8_t pin)
{
	uint8_t r;
	uint8_t retries = 125;

	noInterrupts();
	DIRECT_MODE_INPUT(pin);
	interrupts();
	// wait until the wire is high... just in case
	do {
		if (--retries == 0) return 0;
		delayMicroseconds(2);
	} while ( !DIRECT_READ(pin));

	noInterrupts();
	DIRECT_WRITE_LOW(pin);
	interrupts();
	delayMicroseconds(480);
	noInterrupts();
	DIRECT_MODE_INPUT(pin);	// allow it to float
	delayMicroseconds(70);
	r = !DIRECT_READ(pin);
	interrupts();
	delayMicroseconds(410);
	return r;
}

__attribute__((used)) static void onewire_write_bit(uint8_t pin, uint8_t v, uint8_t power)
{
	if (v & 1) {
		noInterrupts();
		DIRECT_WRITE_LOW(pin);
		delayMicroseconds(5);
		if (power) {
			DIRECT_WRITE_HIGH(pin);
		} else {
			DIRECT_MODE_INPUT(pin);	// drive output high by the pull-up
		}
		delayMicroseconds(8);
		interrupts();
		delayMicroseconds(52);
	} else {
		noInterrupts();
		DIRECT_WRITE_LOW(pin);
		delayMicroseconds(65);
		if (power) {
			DIRECT_WRITE_HIGH(pin);
		} else {
			DIRECT_MODE_INPUT(pin);	// drive output high by the pull-up
		}
		interrupts();
		delayMicroseconds(5);
	}
}

__attribute__((used)) static uint8_t onewire_read_bit(uint8_t pin)
{
	uint8_t r;

	noInterrupts();
	DIRECT_WRITE_LOW(pin);

	delayMicroseconds(5);
	DIRECT_MODE_INPUT(pin);	// let pin float, pull up will raise
	delayMicroseconds(8);
	r = DIRECT_READ(pin);
	interrupts();
	delayMicroseconds(52);
	return r;
}

void onewire_write(uint8_t pin, uint8_t v, uint8_t power /* = 0 */) {
  uint8_t bitMask;

  for (bitMask = 0x01; bitMask; bitMask <<= 1) {
    // send last bit with requested power mode
    onewire_write_bit(pin, (bitMask & v)?1:0, bitMask & 0x80 ? power : 0);
  }
}

void onewire_write_bytes(uint8_t pin, const uint8_t *buf, uint16_t count, bool power /* = 0 */) {
  uint16_t i;
  for (i = 0 ; i < count ; i++)
    onewire_write(pin, buf[i], i < count-1 ? owDefaultPower : power);
}

uint8_t onewire_read(uint8_t pin) {
  uint8_t bitMask;
  uint8_t r = 0;

  for (bitMask = 0x01; bitMask; bitMask <<= 1) {
  	if (onewire_read_bit(pin)) r |= bitMask;
  }
  return r;
}

void onewire_read_bytes(uint8_t pin, uint8_t *buf, uint16_t count) {
  uint16_t i;
  for (i = 0 ; i < count ; i++)
    buf[i] = onewire_read(pin);
}

void onewire_select(uint8_t pin, const uint8_t rom[8])
{
    uint8_t i;

    onewire_write(pin, 0x55, owDefaultPower);           // Choose ROM

    for (i = 0; i < 8; i++) onewire_write(pin, rom[i], owDefaultPower);
}

void onewire_skip(uint8_t pin)
{
    onewire_write(pin, 0xCC, owDefaultPower);           // Skip ROM
}

void onewire_depower(uint8_t pin)
{
	noInterrupts();
	DIRECT_MODE_INPUT(pin);
	interrupts();
}

