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
 int GLFW_JOYSTICK_16 ; 
 int /*<<< orphan*/  GLFW_RESIZABLE ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  g_window ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,float) ; 
 int /*<<< orphan*/  glfwCreateWindow (int,int,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 float* glfwGetJoystickAxes (int,int*) ; 
 unsigned char* glfwGetJoystickButtons (int,int*) ; 
 char* glfwGetJoystickName (int) ; 
 int /*<<< orphan*/  glfwInit () ; 
 int /*<<< orphan*/  glfwJoystickPresent (int) ; 
 int /*<<< orphan*/  glfwMakeContextCurrent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glfwPollEvents () ; 
 int /*<<< orphan*/  glfwSetJoystickCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  glfwWindowHint (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glfwWindowShouldClose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  window ; 

void render() {
  glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  for (int j = GLFW_JOYSTICK_1; j < GLFW_JOYSTICK_16; ++j) {
    int joy = GLFW_JOYSTICK_1 + j;
    if (!glfwJoystickPresent(joy)) continue;

    static struct {
      int axes_count;
      float axes[16];
      int button_count;
      unsigned char buttons[16];
    } last_gamepad_state[16] = {0};

    const char *name = glfwGetJoystickName(joy);

    int axes_count = 0;
    const float *axes = glfwGetJoystickAxes(joy, &axes_count);

    int button_count = 0;
    const unsigned char *buttons = glfwGetJoystickButtons(joy, &button_count);

    last_gamepad_state[joy].axes_count = axes_count;
    for (int i = 0; i < axes_count; ++i) {
      if (last_gamepad_state[joy].axes[i] != axes[i]) {
        printf("(%d %s) axis %d = %f\n", joy, name, i, axes[i]);
      }

      last_gamepad_state[joy].axes[i] = axes[i];
    }

    last_gamepad_state[joy].button_count =  button_count;
    for (int i = 0; i < button_count; ++i) {
      if (last_gamepad_state[joy].buttons[i] != buttons[i]) {
        printf("(%d %s) button %d = %d\n", joy, name, i, buttons[i]);
      }

      last_gamepad_state[joy].buttons[i] = buttons[i];
    }
  }
}

void joystick_callback(int joy, int event)
{
  if (event == GLFW_CONNECTED) {
    printf("Joystick %d was connected: %s\n", joy, glfwGetJoystickName(joy));
  } else if (event == GLFW_DISCONNECTED) {
    printf("Joystick %d was disconnected\n", joy);
  }
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

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(render, 0, 1);
#else
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
#endif

  glfwTerminate();

  return 0;
}

