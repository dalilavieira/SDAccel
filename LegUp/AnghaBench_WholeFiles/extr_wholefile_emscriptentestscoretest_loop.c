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
 int /*<<< orphan*/  printf (char*,...) ; 

int main() {
  int x = 5;
  for (int i = 0; i < 6; i++) {
    x += x * i;
    if (x > 1000) {
      if (x % 7 == 0) printf("cheez\n");
      x /= 2;
      break;
    }
  }
  printf("*%d*\n", x);
  return 0;
}

