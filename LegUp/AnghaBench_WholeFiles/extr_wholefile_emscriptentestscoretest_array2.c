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
 double** grid ; 
 int /*<<< orphan*/  printf (char*,...) ; 

int main() {
  for (int i = 0; i < 4; i++)
    printf("%d:%.2f,%.2f ", i, grid[i][0], grid[i][1]);
  printf("\n");
  return 0;
}

