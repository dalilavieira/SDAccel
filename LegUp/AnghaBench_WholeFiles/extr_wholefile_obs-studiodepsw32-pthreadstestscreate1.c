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
 int /*<<< orphan*/  Sleep (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 int washere ; 

void * func(void * arg)
{
  washere = 1;
  return 0; 
}

int
main()
{
  pthread_t t;

  assert(pthread_create(&t, NULL, func, NULL) == 0);

  /* A dirty hack, but we cannot rely on pthread_join in this
     primitive test. */
  Sleep(2000);

  assert(washere == 1);

  return 0;
}

