#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int x; int y; } ;
typedef  TYPE_1__ stat ;

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,int,int) ; 

int main() {
  stat s;
  s.x = 10;
  s.y = 22;
  printf("*%d,%d*\n", s.x, s.y);
}

