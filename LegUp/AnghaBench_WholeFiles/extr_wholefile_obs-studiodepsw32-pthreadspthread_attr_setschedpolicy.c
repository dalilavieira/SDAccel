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
typedef  int /*<<< orphan*/  pthread_attr_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOTSUP ; 
 int SCHED_OTHER ; 
 scalar_t__ ptw32_is_attr (int /*<<< orphan*/ *) ; 

int
pthread_attr_setschedpolicy (pthread_attr_t * attr, int policy)
{
  if (ptw32_is_attr (attr) != 0)
    {
      return EINVAL;
    }

  if (policy != SCHED_OTHER)
    {
      return ENOTSUP;
    }

  return 0;
}

