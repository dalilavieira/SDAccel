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

/* Variables and functions */
 int GLFW_CONNECTED ; 
 int GLFW_DISCONNECTED ; 
 int GLFW_JOYSTICK_1 ; 
 int GLFW_JOYSTICK_2 ; 
 int /*<<< orphan*/  GLFW_RESIZABLE ; 
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_async_call (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  emscripten_run_script (char*) ; 
 int /*<<< orphan*/  g_window ; 
 int /*<<< orphan*/  glfwCreateWindow (int,int,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 float* glfwGetJoystickAxes (int,int*) ; 
 unsigned char* glfwGetJoystickButtons (int,int*) ; 
 char* glfwGetJoystickName (int) ; 
 int /*<<< orphan*/  glfwInit () ; 
 int glfwJoystickPresent (int) ; 
 int /*<<< orphan*/  glfwMakeContextCurrent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glfwPollEvents () ; 
 int /*<<< orphan*/  glfwSetJoystickCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  glfwWindowHint (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glfwWindowShouldClose (int /*<<< orphan*/ ) ; 
 int joy_connected ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  window ; 

void joystick_callback(int joy, int event)
{
  if (event == GLFW_CONNECTED) {
    printf("Joystick %d was connected: %s\n", joy, glfwGetJoystickName(joy));
    joy_connected = joy; // use the most recently connected joystick
  } else if (event == GLFW_DISCONNECTED) {
    printf("Joystick %d was disconnected\n", joy);
    if (joy == joy_connected) joy_connected = -1;
  }
}

void main_2(void *arg) {
  printf("Testing adding new gamepads\n");
  emscripten_run_script("window.addNewGamepad('Pad Thai', 4, 16)");
  emscripten_run_script("window.addNewGamepad('Pad Kee Mao', 0, 4)");
  // Check that the joysticks exist properly.
  assert(glfwJoystickPresent(GLFW_JOYSTICK_1));
  assert(glfwJoystickPresent(GLFW_JOYSTICK_2));

  assert(strcmp(glfwGetJoystickName(GLFW_JOYSTICK_1), "Pad Thai") == 0);
  assert(strcmp(glfwGetJoystickName(GLFW_JOYSTICK_2), "Pad Kee Mao") == 0);

  int axes_count = 0;
  int buttons_count = 0;

  glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
  glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
  assert(axes_count == 4);
  assert(buttons_count == 16);

  glfwGetJoystickAxes(GLFW_JOYSTICK_2, &axes_count);
  glfwGetJoystickButtons(GLFW_JOYSTICK_2, &buttons_count);
  assert(axes_count == 0);
  assert(buttons_count == 4);

  // Buttons
  printf("Testing buttons\n");
  const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
  assert(buttons_count == 16);
  assert(buttons[0] == 0);
  emscripten_run_script("window.simulateGamepadButtonDown(0, 1)");
  buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
  assert(buttons_count == 16);
  assert(buttons[1] == 1);

  emscripten_run_script("window.simulateGamepadButtonUp(0, 1)");
  buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
  assert(buttons_count == 16);
  assert(buttons[1] == 0);


  emscripten_run_script("window.simulateGamepadButtonDown(1, 0)");
  buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_2, &buttons_count);
  assert(buttons_count == 4);
  assert(buttons[0] == 1);

  emscripten_run_script("window.simulateGamepadButtonUp(1, 0)");
  buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_2, &buttons_count);
  assert(buttons_count == 4);
  assert(buttons[1] == 0);

  // Joystick wiggling
  printf("Testing joystick axes\n");
  emscripten_run_script("window.simulateAxisMotion(0, 0, 1)");
  const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
  assert(axes_count == 4);
  assert(axes[0] == 1);

  emscripten_run_script("window.simulateAxisMotion(0, 0, 0)");
  axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
  assert(axes_count == 4);
  assert(axes[0] == 0);

  emscripten_run_script("window.simulateAxisMotion(0, 1, -1)");
  axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
  assert(axes_count == 4);
  assert(axes[1] == -1);

  // End test.
  printf("Test passed!\n");
  REPORT_RESULT(2);
}

int main() {
  if (!glfwInit())
  {
    printf("Could not create window. Test failed.\n");
#ifdef REPORT_RESULT
    REPORT_RESULT(0);
#endif
    return -1;
  }
  glfwWindowHint(GLFW_RESIZABLE , 1);
  g_window = glfwCreateWindow(600, 450, "GLFW joystick test", NULL, NULL);
  if (!g_window)
  {
    printf("Could not create window. Test failed.\n");
#ifdef REPORT_RESULT
    REPORT_RESULT(0);
#endif
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(g_window);
  glfwSetJoystickCallback(joystick_callback);

  emscripten_async_call(main_2, NULL, 3000); // avoid startup delays and intermittent errors

#ifndef __EMSCRIPTEN__
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
#endif

  glfwTerminate();

  return 0;
}

