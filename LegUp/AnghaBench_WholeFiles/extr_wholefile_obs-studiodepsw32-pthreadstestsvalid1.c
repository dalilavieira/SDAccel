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
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,void**) ; 
 scalar_t__ pthread_kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sched_yield () ; 
 int washere ; 

void * func(void * arg)
{
  washere = 1;
  return (void *) 0; 
}

int
main()
{
  pthread_t t;
  void * result = NULL;

  washere = 0;
  assert(pthread_create(&t, NULL, func, NULL) == 0);
  assert(pthread_join(t, &result) == 0);
  assert((int)(size_t)result == 0);
  assert(washere == 1);
  sched_yield();
  assert(pthread_kill(t, 0) == ESRCH);

  return 0;
}

