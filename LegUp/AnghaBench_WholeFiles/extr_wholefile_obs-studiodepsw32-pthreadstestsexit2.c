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
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 int /*<<< orphan*/  pthread_exit (void*) ; 

void *
func(void * arg)
{
	pthread_exit(arg);

	/* Never reached. */
	assert(0);

	return NULL;
}

int
main(int argc, char * argv[])
{
  pthread_t t;

  assert(pthread_create(&t, NULL, func, (void *) NULL) == 0);

  Sleep(100);

  return 0;
}

