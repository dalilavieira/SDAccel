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
 int /*<<< orphan*/  printf (char*,int,short,...) ; 

int main() {
  char c = '1';
  short s = 2;
  int i = 3;
  long long l = 4;
  float f = 5.5;
  double d = 6.6;

  printf("%c,%hd,%d,%lld,%.1f,%.1f\n", c, s, i, l, f, d);
  printf("%#x,%#x\n", 1, 0);

  return 0;
}

