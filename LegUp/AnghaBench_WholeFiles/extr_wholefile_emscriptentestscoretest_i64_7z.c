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
 int a ; 
 int b ; 
 int /*<<< orphan*/  printf (char*,int,int) ; 

int main(int argc, char *argv[]) {
  a = argc;
  b = argv[1][0];
  printf("%d,%d\n", (int)a, (int)b);
  if (a > a + b || a > a + b + 1) {
    printf("one %lld, %lld", a, b);
    return 0;
  }
  printf("zero %lld, %lld", a, b);
  return 0;
}

