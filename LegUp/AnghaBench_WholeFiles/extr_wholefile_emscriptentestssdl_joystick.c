#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int which; int button; int state; } ;
struct TYPE_5__ {int which; int axis; int value; } ;
struct TYPE_7__ {int type; TYPE_2__ jbutton; TYPE_1__ jaxis; } ;
typedef  int /*<<< orphan*/  SDL_Surface ;
typedef  int /*<<< orphan*/  SDL_Joystick ;
typedef  TYPE_3__ SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 scalar_t__ SDL_DISABLE ; 
 scalar_t__ SDL_ENABLE ; 
 int /*<<< orphan*/  SDL_HWSURFACE ; 
 int SDL_INIT_JOYSTICK ; 
 int SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int) ; 
#define  SDL_JOYAXISMOTION 130 
#define  SDL_JOYBUTTONDOWN 129 
#define  SDL_JOYBUTTONUP 128 
 int /*<<< orphan*/  SDL_JoystickClose (int /*<<< orphan*/ *) ; 
 scalar_t__ SDL_JoystickEventState (scalar_t__) ; 
 int SDL_JoystickGetAxis (int /*<<< orphan*/ *,int) ; 
 int SDL_JoystickGetButton (int /*<<< orphan*/ *,int) ; 
 scalar_t__ SDL_JoystickIndex (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_JoystickName (int) ; 
 int SDL_JoystickNumAxes (int /*<<< orphan*/ *) ; 
 int SDL_JoystickNumButtons (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SDL_JoystickOpen (int /*<<< orphan*/ ) ; 
 int SDL_JoystickOpened (int) ; 
 int /*<<< orphan*/  SDL_JoystickUpdate () ; 
 int SDL_NumJoysticks () ; 
 int SDL_PRESSED ; 
 int SDL_PollEvent (TYPE_3__*) ; 
 scalar_t__ SDL_QUERY ; 
 int SDL_RELEASED ; 
 int /*<<< orphan*/ * SDL_SetVideoMode (int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_async_call (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  emscripten_run_script (char*) ; 
 void main_2 (void*) ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,char*,int) ; 

void assertJoystickEvent(int expectedGamepad, int expectedType, int expectedIndex, int expectedValue) {
  SDL_Event event;
  while(1) {
    // Loop ends either when assertion fails (we run out of events), or we find
    // the event we're looking for.
    assert(SDL_PollEvent(&event) == 1);
    if (event.type != expectedType) {
      continue;
    }
    switch(event.type) {
      case SDL_JOYAXISMOTION: {
        assert(event.jaxis.which == expectedGamepad);
        assert(event.jaxis.axis == expectedIndex);
        assert(event.jaxis.value == expectedValue);
        break;
      }
      case SDL_JOYBUTTONUP: case SDL_JOYBUTTONDOWN: {
        assert(event.jbutton.which == expectedGamepad);
        assert(event.jbutton.button == expectedIndex);
        assert(event.jbutton.state == expectedValue);
        break;
      }
    }
    // Break out of while loop.
    break;
  }
}

void assertNoJoystickEvent() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_JOYBUTTONDOWN: case SDL_JOYBUTTONUP: case SDL_JOYAXISMOTION: {
        // Fail.
        assert(0);
      }
    }
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
  SDL_Surface *screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);
  emscripten_async_call(main_2, NULL, 3000); // avoid startup delays and intermittent errors
  return 0;
}

void main_2(void* arg) {
  // TODO: At the moment, we only support joystick support through polling.
  emscripten_run_script("window.addNewGamepad('Pad Thai', 4, 16)");
  emscripten_run_script("window.addNewGamepad('Pad Kee Mao', 0, 4)");
  // Check that the joysticks exist properly.
  assert(SDL_NumJoysticks() == 2);
  assert(!SDL_JoystickOpened(0));
  assert(!SDL_JoystickOpened(1));
  SDL_Joystick* pad1 = SDL_JoystickOpen(0);
  assert(SDL_JoystickOpened(0));
  assert(SDL_JoystickIndex(pad1) == 0);
  assert(strncmp(SDL_JoystickName(0), "Pad Thai", 9) == 0);
  assert(strncmp(SDL_JoystickName(1), "Pad Kee Mao", 12) == 0);
  assert(SDL_JoystickNumAxes(pad1) == 4);
  assert(SDL_JoystickNumButtons(pad1) == 16);

  // By default, SDL will automatically process events. Test this behavior, and then disable it.
  assert(SDL_JoystickEventState(SDL_QUERY) == SDL_ENABLE);
  SDL_JoystickEventState(SDL_DISABLE);
  assert(SDL_JoystickEventState(SDL_QUERY) == SDL_DISABLE);
  // Button events.
  emscripten_run_script("window.simulateGamepadButtonDown(0, 1)");
  // We didn't tell SDL to automatically update this joystick's state.
  assertNoJoystickEvent();
  SDL_JoystickUpdate();
  assertJoystickEvent(0, SDL_JOYBUTTONDOWN, 1, SDL_PRESSED);
  assert(SDL_JoystickGetButton(pad1, 1) == 1);
  // Enable automatic updates.
  SDL_JoystickEventState(SDL_ENABLE);
  assert(SDL_JoystickEventState(SDL_QUERY) == SDL_ENABLE);
  emscripten_run_script("window.simulateGamepadButtonUp(0, 1)");
  assertJoystickEvent(0, SDL_JOYBUTTONUP, 1, SDL_RELEASED);
  assert(SDL_JoystickGetButton(pad1, 1) == 0);
  // No button change: Should not result in a new event.
  emscripten_run_script("window.simulateGamepadButtonUp(0, 1)");
  assertNoJoystickEvent();
  // Joystick 1 is not opened; should not result in a new event.
  emscripten_run_script("window.simulateGamepadButtonDown(1, 1)");
  assertNoJoystickEvent();

  // Joystick wiggling
  emscripten_run_script("window.simulateAxisMotion(0, 0, 1)");
  assertJoystickEvent(0, SDL_JOYAXISMOTION, 0, 32767);
  assert(SDL_JoystickGetAxis(pad1, 0) == 32767);
  emscripten_run_script("window.simulateAxisMotion(0, 0, 0)");
  assertJoystickEvent(0, SDL_JOYAXISMOTION, 0, 0);
  assert(SDL_JoystickGetAxis(pad1, 0) == 0);
  emscripten_run_script("window.simulateAxisMotion(0, 1, -1)");
  assertJoystickEvent(0, SDL_JOYAXISMOTION, 1, -32768);
  assert(SDL_JoystickGetAxis(pad1, 1) == -32768);
  emscripten_run_script("window.simulateAxisMotion(0, 1, -1)");
  // No joystick change: Should not result in a new event.
  assertNoJoystickEvent();
  // Joystick 1 is not opened; should not result in a new event.
  emscripten_run_script("window.simulateAxisMotion(1, 1, -1)");
  assertNoJoystickEvent();

  SDL_JoystickClose(pad1);
  assert(!SDL_JoystickOpened(0));

  // Joystick 0 is closed; we should not process any new gamepad events from it.
  emscripten_run_script("window.simulateGamepadButtonDown(0, 1)");
  assertNoJoystickEvent();

  // End test.
  printf("Test passed!\n");
  REPORT_RESULT(2);
}

