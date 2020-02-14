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
 int /*<<< orphan*/  GLFW_CURSOR ; 
 scalar_t__ GLFW_CURSOR_DISABLED ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,float) ; 
 int /*<<< orphan*/  glfwCreateWindow (int,int,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ glfwGetInputMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glfwInit () ; 
 int /*<<< orphan*/  glfwPollEvents () ; 
 int /*<<< orphan*/  glfwSetInputMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  glfwWindowShouldClose (int /*<<< orphan*/ ) ; 
 int last_cursor_disabled ; 
 int pointerlock_isActive ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int result ; 
 int /*<<< orphan*/  window ; 

void render() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    int cursor_disabled = glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;

    if (cursor_disabled != last_cursor_disabled) {
        last_cursor_disabled = cursor_disabled;

        printf("GLFW_CURSOR_DISABLED? %d\n", cursor_disabled);

        static int step = 2;
        if (cursor_disabled == pointerlock_isActive) {
            printf("Pass %d: glfwGetInputMode GLFW_CURSOR matches pointerlockchange event\n\n", step++);

            if (step == 5) {
                printf("All tests passed.\n");
                REPORT_RESULT(1);
                exit(0);
            }

            if (cursor_disabled) printf("Press escape to exit Pointer Lock\n");
            else printf("Click again to enable Pointer Lock\n");
        } else {
            printf("FAIL: cursor_disabled(%d) != pointerlock_isActive(%d)\n", cursor_disabled, pointerlock_isActive);
            REPORT_RESULT(result);
            exit(1);
        }
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "test_glfw_cursor_disabled", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED) {
        // Browsers do not allow disabling the cursor (Pointer Lock) without a gesture.
        printf("FAIL: glfwGetInputMode returned GLFW_CURSOR_DISABLED prematurely\n");
        REPORT_RESULT(result);
        exit(1);
    }
    printf("Pass 1: glfwGetInputMode not prematurely returning cursor disabled\n");
    printf("Click within the canvas to activate Pointer Lock\n");

#ifdef __EMSCRIPTEN__
    emscripten_set_pointerlockchange_callback(NULL, NULL, 0, on_pointerlockchange);
    emscripten_set_main_loop(render, 0, 1);
#else
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
#endif

    glfwTerminate();
    return 0;
}

