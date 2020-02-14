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
typedef  int /*<<< orphan*/  jmp_buf ;

/* Variables and functions */
 scalar_t__ alloca (int) ; 
 int bottom ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (void*,int,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ setjmp (int /*<<< orphan*/ ) ; 
 int top ; 

int run(int y) {
  // confuse stack
  char *s = (char *)alloca(100);
  memset(s, 1, 100);
  s[y] = y;
  s[y / 2] = y * 2;
  volatile int x = s[y];
  top = (int)alloca(4);
  if (x <= 2) return x;
  jmp_buf buf;
  printf("setjmp of %d\n", x);
  if (setjmp(buf) == 0) {
    printf("going\n");
    x += run(x / 2);
    longjmp(buf, 1);
  }
  printf("back\n");
  return x / 2;
}

int main(int argc, char **argv) {
  int sum = 0;
  for (int i = 0; i < argc * 2; i++) {
    bottom = (int)alloca(4);
    sum += run(10);
    // scorch the earth
    if (bottom < top) {
      memset((void *)bottom, 1, top - bottom);
    } else {
      memset((void *)top, 1, bottom - top);
    }
  }
  printf("%d\n", sum);
  return sum;
}

