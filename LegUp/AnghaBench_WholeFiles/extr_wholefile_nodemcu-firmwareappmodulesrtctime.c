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

__attribute__((used)) static int __isleap (int year) {
  /* every fourth year is a leap year except for century years that are
   * not divisible by 400. */
  /*  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); */
  return (!(year % 4) && ((year % 100) || !(year % 400)));
}

