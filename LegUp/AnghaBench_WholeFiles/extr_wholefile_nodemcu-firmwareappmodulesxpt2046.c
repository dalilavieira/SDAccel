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
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int int32_t ;
typedef  scalar_t__ int16_t ;

/* Variables and functions */
 int ADC_MAX ; 
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int CAL_MARGIN ; 
 scalar_t__ CTRL_HI_X ; 
 scalar_t__ CTRL_HI_Y ; 
 scalar_t__ CTRL_LO_DFR ; 
 scalar_t__ CTRL_LO_SER ; 
 int /*<<< orphan*/  ETS_GPIO_INTR_DISABLE () ; 
 int /*<<< orphan*/  ETS_GPIO_INTR_ENABLE () ; 
 int /*<<< orphan*/  GPIO_REG_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_STATUS_W1TC_ADDRESS ; 
 int /*<<< orphan*/  PLATFORM_GPIO_FLOAT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_HIGH ; 
 int /*<<< orphan*/  PLATFORM_GPIO_LOW ; 
 int /*<<< orphan*/  PLATFORM_GPIO_OUTPUT ; 
 int _cal_dvi ; 
 int _cal_dvj ; 
 int _cal_dx ; 
 int _cal_dy ; 
 int _cal_vi1 ; 
 int _cal_vj1 ; 
 void* _cs_pin ; 
 int _height ; 
 size_t _irq_pin ; 
 int _width ; 
 void* luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/ * pin_num ; 
 int /*<<< orphan*/  platform_gpio_mode (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ platform_gpio_read (size_t) ; 
 int /*<<< orphan*/  platform_gpio_write (void*,int /*<<< orphan*/ ) ; 
 int platform_spi_send_recv (int,int,scalar_t__) ; 

__attribute__((used)) static int16_t besttwoavg( int16_t x , int16_t y , int16_t z ) {
  int16_t da, db, dc;
  int16_t reta = 0;

  if ( x > y ) da = x - y; else da = y - x;
  if ( x > z ) db = x - z; else db = z - x;
  if ( z > y ) dc = z - y; else dc = y - z;

  if ( da <= db && da <= dc ) reta = (x + y) >> 1;
  else if ( db <= da && db <= dc ) reta = (x + z) >> 1;
  else reta = (y + z) >> 1;

  return reta;
}

__attribute__((used)) static int isTouching() {
  return (platform_gpio_read(_irq_pin) == 0);
}

__attribute__((used)) static uint16_t transfer16(uint16_t _data) {
  union { uint16_t val; struct { uint8_t lsb; uint8_t msb; }; } t;
  t.val = _data;
  t.msb = platform_spi_send_recv(1, 8, t.msb);
  t.lsb = platform_spi_send_recv(1, 8, t.lsb);
  return t.val;
}

__attribute__((used)) static uint16_t _readLoop(uint8_t ctrl, uint8_t max_samples) {
  uint16_t prev = 0xffff, cur = 0xffff;
  uint8_t i = 0;
  do {
    prev = cur;
    cur = platform_spi_send_recv(1, 8 , 0);
    cur = (cur << 4) | (platform_spi_send_recv(1, 8 , ctrl) >> 4);  // 16 clocks -> 12-bits (zero-padded at end)
  } while ((prev != cur) && (++i < max_samples));
  return cur;
}

__attribute__((used)) static void getRaw(uint16_t *vi, uint16_t *vj) {
  // Implementation based on TI Technical Note http://www.ti.com/lit/an/sbaa036/sbaa036.pdf

  // Disable interrupt: reading position generates false interrupt
  ETS_GPIO_INTR_DISABLE();

  platform_gpio_write(_cs_pin, PLATFORM_GPIO_LOW);
  platform_spi_send_recv(1, 8 , CTRL_HI_X | CTRL_LO_DFR);  // Send first control int
  *vi = _readLoop(CTRL_HI_X | CTRL_LO_DFR, 255);
  *vj = _readLoop(CTRL_HI_Y | CTRL_LO_DFR, 255);

  // Turn off ADC by issuing one more read (throwaway)
  // This needs to be done, because PD=0b11 (needed for MODE_DFR) will disable PENIRQ
  platform_spi_send_recv(1, 8 , 0);  // Maintain 16-clocks/conversion; _readLoop always ends after issuing a control int
  platform_spi_send_recv(1, 8 , CTRL_HI_Y | CTRL_LO_SER);
  transfer16(0);  // Flush last read, just to be sure

  platform_gpio_write(_cs_pin, PLATFORM_GPIO_HIGH);

  // Clear interrupt status
  GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, BIT(pin_num[_irq_pin]));
  // Enable interrupt again
  ETS_GPIO_INTR_ENABLE();
}

__attribute__((used)) static void setCalibration (uint16_t vi1, uint16_t vj1, uint16_t vi2, uint16_t vj2) {
  _cal_dx = _width - 2*CAL_MARGIN;
  _cal_dy = _height - 2*CAL_MARGIN;

  _cal_vi1 = (int32_t)vi1;
  _cal_vj1 = (int32_t)vj1;
  _cal_dvi = (int32_t)vi2 - vi1;
  _cal_dvj = (int32_t)vj2 - vj1;
}

__attribute__((used)) static void getPosition (uint16_t *x, uint16_t *y) {
  if (isTouching() == 0) {
    *x = *y = 0xffff;
    return;
  }
  uint16_t vi, vj;

  getRaw(&vi, &vj);

  // Map to (un-rotated) display coordinates
  *x = (uint16_t)(_cal_dx * (vj - _cal_vj1) / _cal_dvj + CAL_MARGIN);
  if (*x > 0x7fff) *x = 0;
  *y = (uint16_t)(_cal_dy * (vi - _cal_vi1) / _cal_dvi + CAL_MARGIN);
  if (*y > 0x7fff) *y = 0;
}

__attribute__((used)) static int xpt2046_init( lua_State* L ) {
  _cs_pin  = luaL_checkinteger( L, 1 );
  _irq_pin = luaL_checkinteger( L, 2 );
  _height  = luaL_checkinteger( L, 3 );
  _width   = luaL_checkinteger( L, 4 );
  // set pins correct
  platform_gpio_mode(_cs_pin, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_FLOAT );

  setCalibration(
    /*vi1=*/((int32_t)CAL_MARGIN) * ADC_MAX / _width,
    /*vj1=*/((int32_t)CAL_MARGIN) * ADC_MAX / _height,
    /*vi2=*/((int32_t)_width - CAL_MARGIN) * ADC_MAX / _width,
    /*vj2=*/((int32_t)_height - CAL_MARGIN) * ADC_MAX / _height
  );

  // assume spi was inited before with a clockDiv of >=16
  // as higher spi clock speed produced inaccurate results

  // do first powerdown
  platform_gpio_write(_cs_pin, PLATFORM_GPIO_LOW);

  // Issue a throw-away read, with power-down enabled (PD{1,0} == 0b00)
  // Otherwise, ADC is disabled
  platform_spi_send_recv(1, 8, CTRL_HI_Y | CTRL_LO_SER);
  transfer16(0); // Flush, just to be sure

  platform_gpio_write(_cs_pin, PLATFORM_GPIO_HIGH);
  return 0;
}

__attribute__((used)) static int xpt2046_isTouched( lua_State* L ) {
  lua_pushboolean( L, isTouching());
  return 1;
}

__attribute__((used)) static int xpt2046_setCalibration( lua_State* L ) {
  int32_t a = luaL_checkinteger( L, 1 );
  int32_t b = luaL_checkinteger( L, 2 );
  int32_t c = luaL_checkinteger( L, 3 );
  int32_t d = luaL_checkinteger( L, 4 );
  setCalibration(a,b,c,d);
  return 0;
}

__attribute__((used)) static int xpt2046_getRaw( lua_State* L ) {
  uint16_t x, y;
  getRaw(&x, &y);
  lua_pushinteger( L, x);
  lua_pushinteger( L, y);
  return 2;
}

__attribute__((used)) static int xpt2046_getPosition( lua_State* L ) {
  uint16_t x, y;
  getPosition(&x, &y);
  lua_pushinteger( L, x);
  lua_pushinteger( L, y);
  return 2;
}

__attribute__((used)) static int xpt2046_getPositionAvg( lua_State* L ) {
  // Run three times
  uint16_t x1, y1, x2, y2, x3, y3;
  getPosition(&x1, &y1);
  getPosition(&x2, &y2);
  getPosition(&x3, &y3);

  // Average the two best results
  int16_t x = besttwoavg(x1,x2,x3);
  int16_t y = besttwoavg(y1,y2,y3);

  lua_pushinteger( L, x);
  lua_pushinteger( L, y);
  return 2;
}

