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
 scalar_t__ _ismbbkalnum (unsigned int) ; 
 scalar_t__ isalpha (unsigned int) ; 

int _ismbbalpha(unsigned int c)
{
  return (isalpha(c) || _ismbbkalnum(c));
}

