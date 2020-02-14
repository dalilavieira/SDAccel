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
typedef  int /*<<< orphan*/  EmscriptenMouseEvent ;
typedef  int /*<<< orphan*/  EM_BOOL ;
typedef  scalar_t__ EMSCRIPTEN_RESULT ;

/* Variables and functions */
 int /*<<< orphan*/  EM_ASM (int) ; 
 int* Module ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_hide_mouse () ; 
 scalar_t__ emscripten_set_click_callback (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (int,int /*<<< orphan*/  const*,void*)) ; 
 int /*<<< orphan*/  printf (char*) ; 

EM_BOOL mouse_callback(int eventType, const EmscriptenMouseEvent *e, void *userData)
{
	printf("Mouse click on canvas.\n");
#ifdef REPORT_RESULT
	REPORT_RESULT(0);
#endif
	return 0;
}

int main()
{
	printf("The mouse cursor should be hidden when hovering over the canvas rectangle. Click on the canvas to finish test.\n");
	emscripten_hide_mouse();
	EMSCRIPTEN_RESULT ret = emscripten_set_click_callback("#canvas", 0, 1, mouse_callback);
	assert(ret == 0);
	EM_ASM(Module['noExitRuntime'] = true);
}

