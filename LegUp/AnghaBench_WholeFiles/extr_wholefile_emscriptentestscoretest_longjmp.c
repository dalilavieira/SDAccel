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
 int /*<<< orphan*/  buf ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int setjmp (int /*<<< orphan*/ ) ; 

void second(void) {
  printf("second\n");
  longjmp(buf, -1);
}

void first(void) {
  printf("first\n");  // prints
  longjmp(buf, 1);  // jumps back to where setjmp was called - making setjmp now
                    // return 1
}

int main() {
  volatile int x = 0;
  int jmpval = setjmp(buf);
  if (!jmpval) {
    x++;                  // should be properly restored once longjmp jumps back
    first();              // when executed, setjmp returns 1
    printf("skipped\n");  // does not print
  } else if (jmpval == 1) {  // when first() jumps back, setjmp returns 1
    printf("result: %d %d\n", x, jmpval);  // prints
    x++;
    second();                 // when executed, setjmp returns -1
  } else if (jmpval == -1) {  // when second() jumps back, setjmp returns -1
    printf("result: %d %d\n", x, jmpval);  // prints
  }

  return 0;
}

