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
 int /*<<< orphan*/  __get_cpuid (int,unsigned int*,unsigned int*,unsigned int*,unsigned int*) ; 
 unsigned int bit_SSE42 ; 

int supports_x86_sse42(void)
{
#if defined(__clang__)
  unsigned int eax = 0, ebx = 0, ecx = 0, edx = 0;
  __get_cpuid(1, &eax, &ebx, &ecx, &edx);
  return ecx & bit_SSE42;
#else
  __builtin_cpu_init();
  return __builtin_cpu_supports("sse4.2");
#endif
}

