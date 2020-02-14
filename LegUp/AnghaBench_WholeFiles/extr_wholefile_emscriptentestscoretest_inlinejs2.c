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
 int /*<<< orphan*/  printf (char*,int) ; 

int mix(int x, int y) {
  int ret;
  asm("Math.pow(2, %0+%1+1)" : "=r"(ret) : "r"(x), "r"(y));  // read and write
  return ret;
}

void mult() {
  asm("var $_$1 = Math.abs(-100); $_$1 *= 2; out($_$1)");  // multiline
  asm __volatile__("out('done')");
}

int main(int argc, char **argv) {
  printf("%d\n", mix(argc, argc / 2));
  mult();
  return 0;
}

