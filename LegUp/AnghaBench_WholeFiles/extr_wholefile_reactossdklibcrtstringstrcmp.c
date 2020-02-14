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
typedef  scalar_t__ _TCHAR ;

/* Variables and functions */

int _tcscmp(const _TCHAR* s1, const _TCHAR* s2)
{
 while(*s1 == *s2)
 {
  if(*s1 == 0) return 0;

  s1 ++;
  s2 ++;
 }

 return *s1 - *s2;
}

