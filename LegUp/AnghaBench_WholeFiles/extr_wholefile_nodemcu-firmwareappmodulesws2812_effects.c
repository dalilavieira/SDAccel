#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int speed; int mode_delay; int brightness; int* color; int counter_mode_call; int mode_color_index; int counter_mode_step; int effect_type; int effect_int_param1; int running; int /*<<< orphan*/  os_t; TYPE_2__* buffer; int /*<<< orphan*/  buffer_ref; } ;
typedef  TYPE_1__ ws2812_effects ;
struct TYPE_7__ {char* values; size_t colorsPerLed; size_t size; } ;
typedef  TYPE_2__ ws2812_buffer ;
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  luaL_Buffer ;

/* Variables and functions */
 int BRIGHTNESS_DEFAULT ; 
 int DELAY_DEFAULT ; 
 int EFFECT_PARAM_INVALID ; 
 int /*<<< orphan*/  FALSE ; 
 char* LIBRARY_NOT_INITIALIZED_ERROR_MSG ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 int LUA_TNIL ; 
 int LUA_TNONE ; 
 int LUA_TNUMBER ; 
 int LUA_TSTRING ; 
 int /*<<< orphan*/  SHIFT_CIRCULAR ; 
 int SPEED_DEFAULT ; 
 int SPEED_MAX ; 
 int UINT32_MAX ; 
#define  WS2812_EFFECT_BLINK 144 
#define  WS2812_EFFECT_CIRCUS_COMBUSTUS 143 
#define  WS2812_EFFECT_COLOR_WIPE 142 
#define  WS2812_EFFECT_CYCLE 141 
#define  WS2812_EFFECT_FIRE_FLICKER 140 
#define  WS2812_EFFECT_FIRE_FLICKER_INTENSE 139 
#define  WS2812_EFFECT_FIRE_FLICKER_SOFT 138 
#define  WS2812_EFFECT_FLICKER 137 
#define  WS2812_EFFECT_GRADIENT 136 
#define  WS2812_EFFECT_GRADIENT_RGB 135 
#define  WS2812_EFFECT_HALLOWEEN 134 
#define  WS2812_EFFECT_LARSON_SCANNER 133 
#define  WS2812_EFFECT_RAINBOW 132 
#define  WS2812_EFFECT_RAINBOW_CYCLE 131 
#define  WS2812_EFFECT_RANDOM_COLOR 130 
#define  WS2812_EFFECT_RANDOM_DOT 129 
#define  WS2812_EFFECT_STATIC 128 
 int abs (int) ; 
 int /*<<< orphan*/  c_memset (int*,int /*<<< orphan*/ ,int) ; 
 int color_wheel (int) ; 
 int grb2hsv (int,int,int) ; 
 int hsv2grb (int,int,int) ; 
 int /*<<< orphan*/  luaL_addchar (int /*<<< orphan*/ *,char) ; 
 int /*<<< orphan*/  luaL_addstring (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 int /*<<< orphan*/  luaL_argerror (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaL_buffinit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int luaL_checkint (int /*<<< orphan*/ *,int) ; 
 void* luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int luaL_checkoption (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,char const* const*) ; 
 scalar_t__ luaL_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int luaL_optinteger (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,int) ; 
 char* lua_tolstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int lua_type (int /*<<< orphan*/ *,int) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  os_free (void*) ; 
 int /*<<< orphan*/  os_timer_arm (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_timer_disarm (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_timer_setfn (int /*<<< orphan*/ *,void (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ os_zalloc (size_t) ; 
 int rand () ; 
 TYPE_1__* state ; 
 int /*<<< orphan*/  ws2812_buffer_shift (TYPE_2__*,int,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  ws2812_write_data (char const*,size_t,char const*,size_t) ; 

__attribute__((used)) static int ws2812_write(ws2812_buffer* buffer) {
  size_t length1, length2;
  const char *buffer1, *buffer2;

  buffer1 = 0;
  length1 = 0;

  buffer1 = buffer->values;
  length1 = buffer->colorsPerLed*buffer->size;

  buffer2 = 0;
  length2 = 0;

  // Send the buffers
  ws2812_write_data(buffer1, length1, buffer2, length2);

  return 0;
}

__attribute__((used)) static int ws2812_set_pixel(int pixel, uint32_t color) {
  ws2812_buffer * buffer = state->buffer;
  uint8_t g = ((color & 0x00FF0000) >> 16);
  uint8_t r = ((color & 0x0000FF00) >> 8);
  uint8_t b = (color & 0x000000FF);
  uint8_t w = buffer->colorsPerLed  == 4 ? ((color & 0xFF000000) >> 24) : 0;

  int offset = pixel * buffer->colorsPerLed;
  buffer->values[offset] = g;
  buffer->values[offset+1] = r;
  buffer->values[offset+2] = b;
  if (buffer->colorsPerLed == 4) {
    buffer->values[offset+3] = w;
  }

  return 0;
}

__attribute__((used)) static uint8_t get_random_wheel_index(uint8_t pos)
{
  uint8_t r = 0;
  uint8_t x = 0;
  uint8_t y = 0;
  uint8_t d = 0;

  while(d < 42) {
    r = rand() % 360;
    x = abs(pos - r);
    y = 360 - x;
    d = min(x, y);
  }

  return r;
}

__attribute__((used)) static int ws2812_effects_init(lua_State *L) {
  ws2812_buffer * buffer = (ws2812_buffer*)luaL_checkudata(L, 1, "ws2812.buffer");
  luaL_argcheck(L, buffer != NULL, 1, "no valid buffer provided");
  // get rid of old state
  if (state != NULL) {
    luaL_unref(L, LUA_REGISTRYINDEX, state->buffer_ref);
    os_free((void *) state);
  }
  // Allocate memory and set all to zero
  size_t size = sizeof(ws2812_effects) + buffer->colorsPerLed*sizeof(uint8_t);
  state = (ws2812_effects *) os_zalloc(size);
  // initialize
  state->speed = SPEED_DEFAULT;
  state->mode_delay = DELAY_DEFAULT;
  state->brightness = BRIGHTNESS_DEFAULT;
  state->buffer = buffer;

  state->buffer_ref = luaL_ref(L, LUA_REGISTRYINDEX);

  return 0;
}

__attribute__((used)) static int ws2812_effects_set_color(lua_State* L) {
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);

  uint8_t g = luaL_checkinteger(L, 1);
  uint8_t r = luaL_checkinteger(L, 2);
  uint8_t b = luaL_checkinteger(L, 3);
  uint8_t w = luaL_optinteger(L, 4, 0 );

  state->color[0] = g;
  state->color[1] = r;
  state->color[2] = b;
  state->color[3] = w;
  return 0;
}

__attribute__((used)) static int ws2812_effects_get_speed(lua_State* L) {
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  lua_pushnumber(L, state->speed);
  return 1;
}

__attribute__((used)) static int ws2812_effects_set_speed(lua_State* L) {
  uint8_t speed = luaL_checkinteger(L, 1);
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  luaL_argcheck(L, speed >= 0 && speed <= 255, 1, "should be a 0-255");
  state->speed = speed;
  state->mode_delay = 10;
  return 0;
}

__attribute__((used)) static int ws2812_effects_get_delay(lua_State* L) {
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  lua_pushnumber(L, state->mode_delay);
  return 1;
}

__attribute__((used)) static int ws2812_effects_set_delay(lua_State* L) {
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  const int delay = luaL_checkinteger(L, 1);
  luaL_argcheck(L, delay >= 10, 1, "must be equal / larger than 10");

  state->mode_delay = delay;
  state->speed = 0;
  return 1;
}

__attribute__((used)) static int ws2812_effects_set_brightness(lua_State* L) {
  uint8_t brightness = luaL_checkint(L, 1);
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  luaL_argcheck(L, brightness >= 0 && brightness < 256, 1, "should be a 0-255");
  state->brightness = brightness;
  return 0;
}

__attribute__((used)) static int ws2812_effects_fill_buffer(uint32_t color) {

  ws2812_buffer * buffer = state->buffer;

  uint8_t g = ((color & 0x00FF0000) >> 16);
  uint8_t r = ((color & 0x0000FF00) >> 8);
  uint8_t b = (color & 0x000000FF);
  uint8_t w = buffer->colorsPerLed  == 4 ? ((color & 0xFF000000) >> 24) : 0;

  // Fill buffer
  int i;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    *p++ = g * state->brightness / 255;
    *p++ = r * state->brightness / 255;
    *p++ = b * state->brightness / 255;
    if (buffer->colorsPerLed == 4) {
      *p++ = w * state->brightness / 255;
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_fill_color() {

  uint8_t g = state->color[0];
  uint8_t r = state->color[1];
  uint8_t b = state->color[2];
  uint8_t w = state->color[3];

  uint32_t color = (w << 24) | (g << 16) | (r << 8) | b;

  ws2812_effects_fill_buffer(color);

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_blink() {
  if(state->counter_mode_call % 2 == 1) {
    // on
    ws2812_effects_fill_color();
  }
  else {
    // off
    ws2812_buffer * buffer = state->buffer;
    c_memset(&buffer->values[0], 0, buffer->size * buffer->colorsPerLed);
  }
  return 0;
}

__attribute__((used)) static int ws2812_effects_gradient(const char *gradient_spec, size_t length1) {

  ws2812_buffer * buffer = state->buffer;

  int segments = (length1 / buffer->colorsPerLed) - 1;
  int segmentSize = buffer->size / segments;

  uint8_t g1, r1, b1, g2, r2, b2;
  int i,j,k;

  g2 = *gradient_spec++;
  r2 = *gradient_spec++;
  b2 = *gradient_spec++;
  // skip non-rgb components
  for (j = 3; j < buffer->colorsPerLed; j++)
  {
    *gradient_spec++;
  }

  // reference to buffer memory
  uint8_t * p = &buffer->values[0];

  uint16_t h1,h2;
  uint8_t s,v,s1,v1,s2,v2;

  for (k = 0; k < segments; k++) {
    g1 = g2;
    r1 = r2;
    b1 = b2;
    uint32_t hsv1 = grb2hsv(g1, r1, b1);
    h1 = (hsv1 & 0xFFFF0000) >> 16;
    s1 = (hsv1 & 0x0000FF00) >> 8;
    v1 = (hsv1 & 0x000000FF);

    g2 = *gradient_spec++;
    r2 = *gradient_spec++;
    b2 = *gradient_spec++;
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *gradient_spec++;
    }

    uint32_t hsv2 = grb2hsv(g2, r2, b2);
    h2 = (hsv2 & 0xFFFF0000) >> 16;
    s2 = (hsv1 & 0x0000FF00) >> 8;
    v2 = (hsv1 & 0x000000FF);

    // get distance and direction to use
    int maxCCW = h1 > h2 ? h1 - h2 : 360 + h1 - h2;
    int maxCW = h1 > h2 ? 360 + h2 - h1 : h2 - h1;

    // Fill buffer
    int numPixels = segmentSize;
    // make sure we fill the strip correctly in case of rounding errors
    if (k == segments - 1) {
      numPixels = buffer->size - (segmentSize * (segments - 1));
    }

    int steps = numPixels - 1;

    for(i = 0; i < numPixels; i++) {
      // calculate HSV values
      //h = h1 + ((h2-h1) * i / fillSize);
      int h = maxCCW > maxCW ? h1 + ((maxCW * i / steps) % 360) : h1 - (maxCCW * i / steps);
      if (h < 0) h = h + 360;
      if (h > 359) h = h - 360;
      s = s1 + ((s2-s1) * i / steps);
      v = v1 + ((v2-v1) * i / steps);
      // convert to RGB
      uint32_t grb = hsv2grb(h, s, v);

      *p++ = ((grb & 0x00FF0000) >> 16) * state->brightness / 255;
      *p++ = ((grb & 0x0000FF00) >> 8)  * state->brightness / 255;
      *p++ = (grb & 0x000000FF) * state->brightness / 255;

      for (j = 3; j < buffer->colorsPerLed; j++) {
        *p++ = 0;
      }
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_gradient_rgb(const char *buffer1, size_t length1) {

  ws2812_buffer * buffer = state->buffer;

  int segments = (length1 / buffer->colorsPerLed) - 1;
  int segmentSize = buffer->size / segments;

  uint8_t g1, r1, b1, g2, r2, b2;
  int i,j,k;

  g2 = *buffer1++;
  r2 = *buffer1++;
  b2 = *buffer1++;
  // skip non-rgb components
  for (j = 3; j < buffer->colorsPerLed; j++)
  {
    *buffer1++;
  }

  // reference to buffer memory
  uint8_t * p = &buffer->values[0];
  for (k = 0; k < segments; k++) {
    g1 = g2;
    r1 = r2;
    b1 = b2;

    g2 = *buffer1++;
    r2 = *buffer1++;
    b2 = *buffer1++;

    for (j = 3; j < buffer->colorsPerLed; j++) {
      *buffer1++;
    }

    // Fill buffer
    int numPixels = segmentSize;
    // make sure we fill the strip correctly in case of rounding errors
    if (k == segments - 1) {
      numPixels = buffer->size - (segmentSize * (segments - 1));
    }

    int steps = numPixels - 1;

    for(i = 0; i < numPixels; i++) {
      *p++ = (g1 + ((g2-g1) * i / steps)) * state->brightness / 255;
      *p++ = (r1 + ((r2-r1) * i / steps)) * state->brightness / 255;
      *p++ = (b1 + ((b2-b1) * i / steps)) * state->brightness / 255;
      for (j = 3; j < buffer->colorsPerLed; j++)
      {
        *p++ = 0;
      }
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_random_color() {
  state->mode_color_index = get_random_wheel_index(state->mode_color_index);
  ws2812_buffer * buffer = state->buffer;

  uint32_t color = color_wheel(state->mode_color_index);
  uint8_t r = ((color & 0x00FF0000) >> 16) * state->brightness / 255;
  uint8_t g = ((color & 0x0000FF00) >>  8) * state->brightness / 255;
  uint8_t b = ((color & 0x000000FF) >>  0) * state->brightness / 255;

  // Fill buffer
  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    *p++ = g;
    *p++ = r;
    *p++ = b;
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *p++ = 0;
    }
  }
}

__attribute__((used)) static int ws2812_effects_mode_rainbow() {

  ws2812_buffer * buffer = state->buffer;

  uint32_t color = color_wheel(state->counter_mode_step);
  uint8_t r = (color & 0x00FF0000) >> 16;
  uint8_t g = (color & 0x0000FF00) >>  8;
  uint8_t b = (color & 0x000000FF) >>  0;

  // Fill buffer
  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    *p++ = g * state->brightness / 255;
    *p++ = r * state->brightness / 255;
    *p++ = b * state->brightness / 255;
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *p++ = 0;
    }
  }

  state->counter_mode_step = (state->counter_mode_step + 1) % 360;
  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_rainbow_cycle(int repeat_count) {

  ws2812_buffer * buffer = state->buffer;

  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    uint16_t wheel_index = (i * 360 / buffer->size * repeat_count) % 360;
    uint32_t color = color_wheel(wheel_index);
    uint8_t r = ((color & 0x00FF0000) >> 16) * state->brightness / 255;
    uint8_t g = ((color & 0x0000FF00) >>  8) * state->brightness / 255;
    uint8_t b = ((color & 0x000000FF) >>  0) * state->brightness / 255;
    *p++ = g;
    *p++ = r;
    *p++ = b;
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *p++ = 0;
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_flicker_int(uint8_t max_flicker) {

  ws2812_buffer * buffer = state->buffer;

  uint8_t p_g = state->color[0];
  uint8_t p_r = state->color[1];
  uint8_t p_b = state->color[2];

  // Fill buffer
  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    int flicker = rand() % (max_flicker > 0 ? max_flicker : 1);
    int r1 = p_r-flicker;
    int g1 = p_g-flicker;
    int b1 = p_b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    *p++ = g1 * state->brightness / 255;
    *p++ = r1 * state->brightness / 255;
    *p++ = b1 * state->brightness / 255;
    for (j = 3; j < buffer->colorsPerLed; j++) {
      *p++ = 0;
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_halloween() {
  ws2812_buffer * buffer = state->buffer;

  int g1 = 50 * state->brightness / 255;
  int r1 = 255 * state->brightness / 255;
  int b1 = 0 * state->brightness / 255;

  int g2 = 0 * state->brightness / 255;
  int r2 = 255 * state->brightness / 255;
  int b2 = 130 * state->brightness / 255;


  // Fill buffer
  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    *p++ = (i % 4 < 2) ? g1 : g2;
    *p++ = (i % 4 < 2) ? r1 : r2;
    *p++ = (i % 4 < 2) ? b1 : b2;
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *p++ = 0;
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_circus_combustus() {
  ws2812_buffer * buffer = state->buffer;

  int g1 = 0 * state->brightness / 255;
  int r1 = 255 * state->brightness / 255;
  int b1 = 0 * state->brightness / 255;

  int g2 = 255 * state->brightness / 255;
  int r2 = 255 * state->brightness / 255;
  int b2 = 255 * state->brightness / 255;

  // Fill buffer
  int i,j;
  uint8_t * p = &buffer->values[0];
  for(i = 0; i < buffer->size; i++) {
    if (i % 6 < 2) {
      *p++ = g1;
      *p++ = r1;
      *p++ = b1;
    }
    else if (i % 6 < 4) {
      *p++ = g2;
      *p++ = r2;
      *p++ = b2;
    }
    else {
      *p++ = 0;
      *p++ = 0;
      *p++ = 0;
    }
    for (j = 3; j < buffer->colorsPerLed; j++)
    {
      *p++ = 0;
    }
  }

  return 0;
}

__attribute__((used)) static int ws2812_effects_mode_larson_scanner() {

  ws2812_buffer * buffer = state->buffer;
  int led_index = 0;

  for(int i=0; i < buffer->size * buffer->colorsPerLed; i++) {
    buffer->values[i] = buffer->values[i] >> 1;
  }

  uint16_t pos = 0;

  if(state->counter_mode_step < buffer->size) {
    pos = state->counter_mode_step;
  } else {
    pos = (buffer->size * 2) - state->counter_mode_step - 2;
  }
  pos = pos * buffer->colorsPerLed;
  buffer->values[pos + 1] = state->color[1];
  buffer->values[pos] = state->color[0];
  buffer->values[pos + 2] = state->color[2];

  state->counter_mode_step = (state->counter_mode_step + 1) % ((buffer->size * 2) - 2);
}

__attribute__((used)) static int ws2812_effects_mode_color_wipe() {

  ws2812_buffer * buffer = state->buffer;

  int led_index = (state->counter_mode_step % buffer->size) * buffer->colorsPerLed;

  if (state->counter_mode_step >= buffer->size)
  {
    buffer->values[led_index] = 0;
    buffer->values[led_index + 1] = 0;
    buffer->values[led_index + 2] = 0;
  }
  else
  {
    uint8_t px_r = state->color[1] * state->brightness / 255;
    uint8_t px_g = state->color[0] * state->brightness / 255;
    uint8_t px_b = state->color[2] * state->brightness / 255;
    buffer->values[led_index] = px_g;
    buffer->values[led_index + 1] = px_r;
    buffer->values[led_index + 2] = px_b;
  }
  state->counter_mode_step = (state->counter_mode_step + 1) % (buffer->size * 2);
}

__attribute__((used)) static int ws2812_effects_mode_random_dot(uint8_t dots) {

  ws2812_buffer * buffer = state->buffer;

  // fade out
  for(int i=0; i < buffer->size * buffer->colorsPerLed; i++) {
    buffer->values[i] = buffer->values[i] >> 1;
  }

  for(int i=0; i < dots; i++) {
    // pick random pixel
    int led_index  = rand() % buffer->size;

    uint32_t color = (state->color[0] << 16) | (state->color[1] << 8) | state->color[2];
    if (buffer->colorsPerLed == 4) {
      color = color | (state->color[3] << 24);
    }
    ws2812_set_pixel(led_index, color);
  }

  state->counter_mode_step = (state->counter_mode_step + 1) % ((buffer->size * 2) - 2);
}

__attribute__((used)) static uint32_t ws2812_effects_mode_delay()
{
  // check if delay has been set explicitly
  if (state->speed == 0 && state->mode_delay > 0)
  {
    return state->mode_delay;
  }

  uint32_t delay = 10;
  switch (state->effect_type) {
    case WS2812_EFFECT_BLINK:
    case WS2812_EFFECT_RAINBOW:
    case WS2812_EFFECT_RAINBOW_CYCLE:
      delay = 10 + ((1000 * (uint32_t)(SPEED_MAX - state->speed)) / SPEED_MAX);
    break;
    case WS2812_EFFECT_FLICKER:
    case WS2812_EFFECT_FIRE_FLICKER:
    case WS2812_EFFECT_FIRE_FLICKER_SOFT:
    case WS2812_EFFECT_FIRE_FLICKER_INTENSE:
      delay = 30 + (rand() % 100) + (200 * (SPEED_MAX - state->speed) / SPEED_MAX);
    break;

    case WS2812_EFFECT_RANDOM_COLOR:
    case WS2812_EFFECT_HALLOWEEN:
    case WS2812_EFFECT_CIRCUS_COMBUSTUS:
    case WS2812_EFFECT_LARSON_SCANNER:
    case WS2812_EFFECT_CYCLE:
    case WS2812_EFFECT_COLOR_WIPE:
    case WS2812_EFFECT_RANDOM_DOT:
      delay = 10 + ((1000 * (uint32_t)(SPEED_MAX - state->speed)) / SPEED_MAX);
    break;

  }
  return delay;
}

__attribute__((used)) static void ws2812_effects_loop(void *p)
{

  if (state->effect_type == WS2812_EFFECT_BLINK)
  {
    ws2812_effects_mode_blink();
  }
  else if (state->effect_type == WS2812_EFFECT_RAINBOW)
  {
    ws2812_effects_mode_rainbow();
  }
  else if (state->effect_type == WS2812_EFFECT_RAINBOW_CYCLE)
  {
    // the rainbow cycle effect can be achieved by shifting the buffer
    ws2812_buffer_shift(state->buffer, 1, SHIFT_CIRCULAR, 1, -1);
  }
  else if (state->effect_type == WS2812_EFFECT_FLICKER)
  {
    int flicker_value = state->effect_int_param1 != EFFECT_PARAM_INVALID ? state->effect_int_param1 : 100;
    if (flicker_value == 0) {
      flicker_value = 50;
    }
    ws2812_effects_mode_flicker_int(flicker_value);
    state->counter_mode_step = (state->counter_mode_step + 1) % 256;
  }
  else if (state->effect_type == WS2812_EFFECT_FIRE_FLICKER)
  {
    ws2812_effects_mode_flicker_int(110);
    state->counter_mode_step = (state->counter_mode_step + 1) % 256;
  }
  else if (state->effect_type == WS2812_EFFECT_FIRE_FLICKER_SOFT)
  {
    ws2812_effects_mode_flicker_int(70);
    state->counter_mode_step = (state->counter_mode_step + 1) % 256;
  }
  else if (state->effect_type == WS2812_EFFECT_FIRE_FLICKER_INTENSE)
  {
    ws2812_effects_mode_flicker_int(170);
    state->counter_mode_step = (state->counter_mode_step + 1) % 256;
  }
  else if (state->effect_type == WS2812_EFFECT_RANDOM_COLOR)
  {
    ws2812_effects_mode_random_color();
  }
  else if (state->effect_type == WS2812_EFFECT_HALLOWEEN)
  {
    ws2812_buffer_shift(state->buffer, 1, SHIFT_CIRCULAR, 1, -1);
  }
  else if (state->effect_type == WS2812_EFFECT_CIRCUS_COMBUSTUS)
  {
    ws2812_buffer_shift(state->buffer, 1, SHIFT_CIRCULAR, 1, -1);
  }
  else if (state->effect_type == WS2812_EFFECT_LARSON_SCANNER)
  {
    ws2812_effects_mode_larson_scanner();
  }
  else if (state->effect_type == WS2812_EFFECT_CYCLE)
  {
    ws2812_buffer_shift(state->buffer, state->effect_int_param1, SHIFT_CIRCULAR, 1, -1);
  }
  else if (state->effect_type == WS2812_EFFECT_COLOR_WIPE)
  {
    ws2812_effects_mode_color_wipe();
  }
  else if (state->effect_type == WS2812_EFFECT_RANDOM_DOT)
  {
    uint8_t dots = state->effect_int_param1 != EFFECT_PARAM_INVALID ? state->effect_int_param1 : 1;
    ws2812_effects_mode_random_dot(dots);
  }

  // set the new delay for this effect
  state->mode_delay = ws2812_effects_mode_delay();
  // call count
  state->counter_mode_call = (state->counter_mode_call + 1) % UINT32_MAX;
  // write the buffer
  ws2812_write(state->buffer);
  // set the timer
  if (state->running == 1 && state->mode_delay >= 10)
  {
    os_timer_disarm(&(state->os_t));
    os_timer_arm(&(state->os_t), state->mode_delay, FALSE);
  }
}

__attribute__((used)) static int ws2812_effects_set_mode(lua_State* L) {

  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);

  // opts must be same order as effect type enum
  static const char * const opts[] = {"static", "blink", "gradient", "gradient_rgb", "random_color", "rainbow",
    "rainbow_cycle", "flicker", "fire", "fire_soft", "fire_intense", "halloween", "circus_combustus",
    "larson_scanner", "cycle", "color_wipe", "random_dot", NULL};

  int type = luaL_checkoption(L, 1, NULL, opts);

  state->effect_type = type;
  int effect_param = EFFECT_PARAM_INVALID;
  // check additional int parameter
  // First mandatory parameter
  int arg_type = lua_type(L, 2);
  if (arg_type == LUA_TNONE || arg_type == LUA_TNIL)
  {
    // we don't have a second parameter
  }
  else if(arg_type == LUA_TNUMBER)
  {
    effect_param = luaL_optinteger( L, 2, EFFECT_PARAM_INVALID );
  }

  // initialize the effect
  state->counter_mode_step = 0;

  switch (state->effect_type) {
    case WS2812_EFFECT_STATIC:
    // fill with currently set color
    ws2812_effects_fill_color();
    state->mode_delay = 250;
    break;
    case WS2812_EFFECT_BLINK:
    ws2812_effects_mode_blink();
    break;
    case WS2812_EFFECT_GRADIENT:
    if(arg_type == LUA_TSTRING)
    {
      size_t length1;
      const char *buffer1 = lua_tolstring(L, 2, &length1);

      if ((length1 / state->buffer->colorsPerLed < 2) || (length1 % state->buffer->colorsPerLed != 0))
      {
        luaL_argerror(L, 2, "must be at least two colors and same size as buffer colors");
      }

      ws2812_effects_gradient(buffer1, length1);
      ws2812_write(state->buffer);
    }
    else
    {
      luaL_argerror(L, 2, "string expected");
    }

    break;
    case WS2812_EFFECT_GRADIENT_RGB:
    if(arg_type == LUA_TSTRING)
    {
      size_t length1;
      const char *buffer1 = lua_tolstring(L, 2, &length1);

      if ((length1 / state->buffer->colorsPerLed < 2) || (length1 % state->buffer->colorsPerLed != 0))
      {
        luaL_argerror(L, 2, "must be at least two colors and same size as buffer colors");
      }

      ws2812_effects_gradient_rgb(buffer1, length1);
      ws2812_write(state->buffer);
    }
    else
    {
      luaL_argerror(L, 2, "string expected");
    }

    break;
    case WS2812_EFFECT_RANDOM_COLOR:
    ws2812_effects_mode_random_color();
    break;
    case WS2812_EFFECT_RAINBOW:
    ws2812_effects_mode_rainbow();
    break;
    case WS2812_EFFECT_RAINBOW_CYCLE:
    ws2812_effects_mode_rainbow_cycle(effect_param != EFFECT_PARAM_INVALID ? effect_param : 1);
    break;
    // flicker
    case WS2812_EFFECT_FLICKER:
    state->effect_int_param1 = effect_param;
    break;
    case WS2812_EFFECT_FIRE_FLICKER:
    case WS2812_EFFECT_FIRE_FLICKER_SOFT:
    case WS2812_EFFECT_FIRE_FLICKER_INTENSE:
    {
      state->color[0] = 255-40;
      state->color[1] = 255;
      state->color[2] = 40;
      state->color[3] = 0;
    }
    break;
    case WS2812_EFFECT_HALLOWEEN:
    ws2812_effects_mode_halloween();
    break;
    case WS2812_EFFECT_CIRCUS_COMBUSTUS:
    ws2812_effects_mode_circus_combustus();
    break;
    case WS2812_EFFECT_LARSON_SCANNER:
    ws2812_effects_mode_larson_scanner();
    break;
    case WS2812_EFFECT_CYCLE:
    if (effect_param != EFFECT_PARAM_INVALID) {
      state->effect_int_param1 = effect_param;
    }
    break;
    case WS2812_EFFECT_COLOR_WIPE:
    {
      uint32_t black = 0;
      ws2812_effects_fill_buffer(black);
      ws2812_effects_mode_color_wipe();
      break;
    }
    case WS2812_EFFECT_RANDOM_DOT:
    {
      // check if more than 1 dot shall be set
      state->effect_int_param1 = effect_param;
      uint32_t black = 0;
      ws2812_effects_fill_buffer(black);
      break;
    }
  }

}

__attribute__((used)) static int ws2812_effects_start(lua_State* L) {

  //NODE_DBG("pin:%d, level:%d \n", pin, level);
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  if (state != NULL) {
    os_timer_disarm(&(state->os_t));
    state->running = 1;
    state->counter_mode_call = 0;
    state->counter_mode_step = 0;
    // set the timer
    os_timer_setfn(&(state->os_t), ws2812_effects_loop, NULL);
    os_timer_arm(&(state->os_t), state->mode_delay, FALSE);
  }
  return 0;
}

__attribute__((used)) static int ws2812_effects_stop(lua_State* L) {
  luaL_argcheck(L, state != NULL, 1, LIBRARY_NOT_INITIALIZED_ERROR_MSG);
  if (state != NULL) {
    os_timer_disarm(&(state->os_t));
    state->running = 0;
  }
  return 0;
}

__attribute__((used)) static int ws2812_effects_tostring(lua_State* L) {

  luaL_Buffer result;
  luaL_buffinit(L, &result);

  luaL_addchar(&result, '[');
  luaL_addstring(&result, "effects");
  luaL_addchar(&result, ']');
  luaL_pushresult(&result);

  return 1;
}

