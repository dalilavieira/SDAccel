#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  events ;
struct TYPE_8__ {int which; int charCode; char* key; int keyCode; char* code; scalar_t__ altKey; scalar_t__ ctrlKey; int /*<<< orphan*/  charValue; int /*<<< orphan*/  locale; int /*<<< orphan*/  repeat; scalar_t__ metaKey; scalar_t__ shiftKey; int /*<<< orphan*/  location; } ;
typedef  TYPE_1__ EmscriptenKeyboardEvent ;
typedef  int EM_BOOL ;

/* Variables and functions */
 scalar_t__ DOM_VK_BACK_SPACE ; 
 scalar_t__ DOM_VK_F1 ; 
 scalar_t__ DOM_VK_F24 ; 
 scalar_t__ DOM_VK_TAB ; 
 int EMSCRIPTEN_EVENT_KEYPRESS ; 
 int EMSCRIPTEN_EVENT_KEYUP ; 
 int /*<<< orphan*/  EMSCRIPTEN_EVENT_TARGET_WINDOW ; 
 int /*<<< orphan*/  EM_ASM (int) ; 
 int* Module ; 
 int emscripten_compute_dom_pk_code (char*) ; 
 char* emscripten_dom_pk_code_to_string (int) ; 
 int /*<<< orphan*/  emscripten_dom_vk_to_string (int) ; 
 int /*<<< orphan*/  emscripten_set_keydown_callback (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int (*) (int,TYPE_1__ const*,void*)) ; 
 int /*<<< orphan*/  emscripten_set_keypress_callback (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int (*) (int,TYPE_1__ const*,void*)) ; 
 int /*<<< orphan*/  emscripten_set_keyup_callback (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int (*) (int,TYPE_1__ const*,void*)) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int strlen (char*) ; 

__attribute__((used)) static inline const char *emscripten_event_type_to_string(int eventType) {
  const char *events[] = { "(invalid)", "(none)", "keypress", "keydown", "keyup", "click", "mousedown", "mouseup", "dblclick", "mousemove", "wheel", "resize", 
    "scroll", "blur", "focus", "focusin", "focusout", "deviceorientation", "devicemotion", "orientationchange", "fullscreenchange", "pointerlockchange", 
    "visibilitychange", "touchstart", "touchend", "touchmove", "touchcancel", "gamepadconnected", "gamepaddisconnected", "beforeunload", 
    "batterychargingchange", "batterylevelchange", "webglcontextlost", "webglcontextrestored", "mouseenter", "mouseleave", "mouseover", "mouseout", "(invalid)" };
  ++eventType;
  if (eventType < 0) eventType = 0;
  if (eventType >= sizeof(events)/sizeof(events[0])) eventType = sizeof(events)/sizeof(events[0])-1;
  return events[eventType];
}

int interpret_charcode_for_keyevent(int eventType, const EmscriptenKeyboardEvent *e)
{
  // Only KeyPress events carry a charCode. For KeyDown and KeyUp events, these don't seem to be present yet, until later when the KeyDown
  // is transformed to KeyPress. Sometimes it can be useful to already at KeyDown time to know what the charCode of the resulting
  // KeyPress will be. The following attempts to do this:
  if (eventType == EMSCRIPTEN_EVENT_KEYPRESS && e->which) return e->which;
  if (e->charCode) return e->charCode;
  if (strlen(e->key) == 1) return (int)e->key[0];
  if (e->which) return e->which;
  return e->keyCode;
}

int number_of_characters_in_utf8_string(const char *str)
{
  if (!str) return 0;
  int num_chars = 0;
  while(*str)
  {
    if ((*str++ & 0xC0) != 0x80) ++num_chars; // Skip all continuation bytes
  }
  return num_chars;
}

int emscripten_key_event_is_printable_character(const EmscriptenKeyboardEvent *keyEvent)
{
  // Not sure if this is correct, but heuristically looks good. Improvements on corner cases welcome.
  return number_of_characters_in_utf8_string(keyEvent->key) == 1;
}

EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData)
{
  int dom_pk_code = emscripten_compute_dom_pk_code(e->code);

  printf("%s, key: \"%s\" (printable: %s), code: \"%s\" = %s (%d), location: %lu,%s%s%s%s repeat: %d, locale: \"%s\", char: \"%s\", charCode: %lu (interpreted: %d), keyCode: %s(%lu), which: %lu\n",
    emscripten_event_type_to_string(eventType), e->key, emscripten_key_event_is_printable_character(e) ? "true" : "false", e->code,
    emscripten_dom_pk_code_to_string(dom_pk_code), dom_pk_code, e->location,
    e->ctrlKey ? " CTRL" : "", e->shiftKey ? " SHIFT" : "", e->altKey ? " ALT" : "", e->metaKey ? " META" : "", 
    e->repeat, e->locale, e->charValue, e->charCode, interpret_charcode_for_keyevent(eventType, e), emscripten_dom_vk_to_string(e->keyCode), e->keyCode, e->which);

  if (eventType == EMSCRIPTEN_EVENT_KEYUP) printf("\n"); // Visual cue

  // Return true for events we want to suppress default web browser handling for.
  // For testing purposes, want to return false here on most KeyDown messages so that they get transformed to KeyPress messages.
  return e->keyCode == DOM_VK_BACK_SPACE // Don't navigate away from this test page on backspace.
    || e->keyCode == DOM_VK_TAB // Don't change keyboard focus to different browser UI elements while testing.
    || (e->keyCode >= DOM_VK_F1 && e->keyCode <= DOM_VK_F24) // Don't F5 refresh the test page to reload.
    || e->ctrlKey // Don't trigger e.g. Ctrl-B to open bookmarks
    || e->altKey // Don't trigger any alt-X based shortcuts either (Alt-F4 is not overrideable though)
    || eventType == EMSCRIPTEN_EVENT_KEYPRESS || eventType == EMSCRIPTEN_EVENT_KEYUP; // Don't perform any default actions on these.
}

int main()
{
  printf("Press any keys on the keyboard to test the appropriate generated EmscriptenKeyboardEvent structure.\n");
  emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
  emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
  emscripten_set_keypress_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
  EM_ASM(Module['noExitRuntime'] = true);
}

