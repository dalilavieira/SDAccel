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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */

u32 atomic_dec (u32 *p)
{
  return p[0]--;
}

u32 atomic_inc (u32 *p)
{
  return p[0]++;
}

size_t get_global_id (u32 dimindx __attribute__((unused)))
{
  return 0;
}

size_t get_local_id (u32 dimindx __attribute__((unused)))
{
  return 0;
}

size_t get_local_size (u32 dimindx __attribute__((unused)))
{
  return 0;
}

