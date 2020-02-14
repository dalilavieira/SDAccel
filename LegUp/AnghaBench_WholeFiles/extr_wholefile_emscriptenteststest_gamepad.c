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
struct TYPE_8__ {double timestamp; int connected; int index; int numAxes; int numButtons; double* axis; int* digitalButton; double* analogButton; int /*<<< orphan*/  mapping; int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ EmscriptenGamepadEvent ;
typedef  int /*<<< orphan*/  EM_BOOL ;
typedef  scalar_t__ EMSCRIPTEN_RESULT ;

/* Variables and functions */
 scalar_t__ EMSCRIPTEN_RESULT_DEFERRED ; 
 scalar_t__ EMSCRIPTEN_RESULT_FAILED ; 
 scalar_t__ EMSCRIPTEN_RESULT_FAILED_NOT_DEFERRED ; 
 scalar_t__ EMSCRIPTEN_RESULT_INVALID_PARAM ; 
 scalar_t__ EMSCRIPTEN_RESULT_INVALID_TARGET ; 
 scalar_t__ EMSCRIPTEN_RESULT_NOT_SUPPORTED ; 
 scalar_t__ EMSCRIPTEN_RESULT_NO_DATA ; 
 scalar_t__ EMSCRIPTEN_RESULT_SUCCESS ; 
 scalar_t__ EMSCRIPTEN_RESULT_UNKNOWN_TARGET ; 
 int /*<<< orphan*/  EM_ASM (int) ; 
 int* Module ; 
 int /*<<< orphan*/  TEST_RESULT (scalar_t__ (*) (int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (int,TYPE_1__ const*,void*))) ; 
 int /*<<< orphan*/  emscripten_cancel_main_loop () ; 
 int emscripten_get_gamepad_status (int,TYPE_1__*) ; 
 int emscripten_get_num_gamepads () ; 
 scalar_t__ emscripten_sample_gamepad_data () ; 
 scalar_t__ emscripten_set_gamepadconnected_callback (int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (int,TYPE_1__ const*,void*)) ; 
 scalar_t__ emscripten_set_gamepaddisconnected_callback (int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (int,TYPE_1__ const*,void*)) ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int,int /*<<< orphan*/ ) ; 
 int prevNumGamepads ; 
 TYPE_1__* prevState ; 
 int /*<<< orphan*/  printf (char*,...) ; 

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

const char *emscripten_result_to_string(EMSCRIPTEN_RESULT result) {
  if (result == EMSCRIPTEN_RESULT_SUCCESS) return "EMSCRIPTEN_RESULT_SUCCESS";
  if (result == EMSCRIPTEN_RESULT_DEFERRED) return "EMSCRIPTEN_RESULT_DEFERRED";
  if (result == EMSCRIPTEN_RESULT_NOT_SUPPORTED) return "EMSCRIPTEN_RESULT_NOT_SUPPORTED";
  if (result == EMSCRIPTEN_RESULT_FAILED_NOT_DEFERRED) return "EMSCRIPTEN_RESULT_FAILED_NOT_DEFERRED";
  if (result == EMSCRIPTEN_RESULT_INVALID_TARGET) return "EMSCRIPTEN_RESULT_INVALID_TARGET";
  if (result == EMSCRIPTEN_RESULT_UNKNOWN_TARGET) return "EMSCRIPTEN_RESULT_UNKNOWN_TARGET";
  if (result == EMSCRIPTEN_RESULT_INVALID_PARAM) return "EMSCRIPTEN_RESULT_INVALID_PARAM";
  if (result == EMSCRIPTEN_RESULT_FAILED) return "EMSCRIPTEN_RESULT_FAILED";
  if (result == EMSCRIPTEN_RESULT_NO_DATA) return "EMSCRIPTEN_RESULT_NO_DATA";
  return "Unknown EMSCRIPTEN_RESULT!";
}

EM_BOOL gamepad_callback(int eventType, const EmscriptenGamepadEvent *e, void *userData)
{
  printf("%s: timeStamp: %g, connected: %d, index: %ld, numAxes: %d, numButtons: %d, id: \"%s\", mapping: \"%s\"\n",
    eventType != 0 ? emscripten_event_type_to_string(eventType) : "Gamepad state", e->timestamp, e->connected, e->index, 
    e->numAxes, e->numButtons, e->id, e->mapping);

  if (e->connected)
  {
    for(int i = 0; i < e->numAxes; ++i)
      printf("Axis %d: %g\n", i, e->axis[i]);

    for(int i = 0; i < e->numButtons; ++i)
      printf("Button %d: Digital: %d, Analog: %g\n", i, e->digitalButton[i], e->analogButton[i]);
  }

  return 0;
}

void mainloop()
{
  EMSCRIPTEN_RESULT res = emscripten_sample_gamepad_data();
  if (res != EMSCRIPTEN_RESULT_SUCCESS)
  {
    printf("emscripten_sample_gamepad_data returned EMSCRIPTEN_RESULT_NOT_SUPPORTED.\n");
    emscripten_cancel_main_loop();
    return;
  }

  int numGamepads = emscripten_get_num_gamepads();
  if (numGamepads != prevNumGamepads)
  {
    printf("Number of connected gamepads: %d\n", numGamepads);
    prevNumGamepads = numGamepads;
  }

  for(int i = 0; i < numGamepads && i < 32; ++i)
  {
    EmscriptenGamepadEvent ge;
    int ret = emscripten_get_gamepad_status(i, &ge);
    if (ret == EMSCRIPTEN_RESULT_SUCCESS)
    {
      int g = ge.index;
      for(int j = 0; j < ge.numAxes; ++j)
      {
        if (ge.axis[j] != prevState[g].axis[j])
          printf("Gamepad %d, axis %d: %g\n", g, j, ge.axis[j]);
      }

      for(int j = 0; j < ge.numButtons; ++j)
      {
        if (ge.analogButton[j] != prevState[g].analogButton[j] || ge.digitalButton[j] != prevState[g].digitalButton[j])
          printf("Gamepad %d, button %d: Digital: %d, Analog: %g\n", g, j, ge.digitalButton[j], ge.analogButton[j]);
      }
      prevState[g] = ge;
    }
  }
}

int main()
{
  EMSCRIPTEN_RESULT ret = emscripten_set_gamepadconnected_callback(0, 1, gamepad_callback);
  TEST_RESULT(emscripten_set_gamepadconnected_callback);
  ret = emscripten_set_gamepaddisconnected_callback(0, 1, gamepad_callback);
  TEST_RESULT(emscripten_set_gamepaddisconnected_callback);

  emscripten_set_main_loop(mainloop, 10, 0);

  /* For the events to function, one must either call emscripten_set_main_loop or enable Module.noExitRuntime by some other means. 
     Otherwise the application will exit after leaving main(), and the atexit handlers will clean up all event hooks (by design). */
  EM_ASM(Module['noExitRuntime'] = true);

#ifdef REPORT_RESULT
  // Keep the page running for a moment.
  emscripten_async_call(report_result, 0, 5000);
#endif
  return 0;
}

