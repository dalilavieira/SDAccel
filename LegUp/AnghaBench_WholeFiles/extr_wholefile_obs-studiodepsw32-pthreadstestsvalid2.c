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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 scalar_t__ ESRCH ; 
 int /*<<< orphan*/  PTW32_THREAD_NULL_ID ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ pthread_kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
main()
{
  pthread_t NullThread = PTW32_THREAD_NULL_ID;

  assert(pthread_kill(NullThread, 0) == ESRCH);

  return 0;
}

