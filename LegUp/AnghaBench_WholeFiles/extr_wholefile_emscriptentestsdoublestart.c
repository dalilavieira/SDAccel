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
 int /*<<< orphan*/  REPORT_RESULT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emscripten_async_call (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  emscripten_cancel_main_loop () ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  times ; 

void later(void* nada) {
  REPORT_RESULT(times);
}

void main_loop(void) {
  static int cnt = 0;
  if (++cnt >= 10) emscripten_cancel_main_loop();
}

int main(void) {
  emscripten_async_call(later, NULL, 2000);
  times++;
  printf("This should only appear once.\n");
  emscripten_set_main_loop(main_loop, 10, 0);
  return 0;
}

