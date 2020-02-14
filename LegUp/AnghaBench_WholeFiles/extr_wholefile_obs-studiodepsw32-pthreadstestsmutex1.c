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
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/ * mutex ; 
 scalar_t__ pthread_mutex_destroy (int /*<<< orphan*/ **) ; 
 scalar_t__ pthread_mutex_init (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_lock (int /*<<< orphan*/ **) ; 
 scalar_t__ pthread_mutex_unlock (int /*<<< orphan*/ **) ; 

int
main()
{
  assert(mutex == NULL);

  assert(pthread_mutex_init(&mutex, NULL) == 0);

  assert(mutex != NULL);

  assert(pthread_mutex_lock(&mutex) == 0);

  assert(pthread_mutex_unlock(&mutex) == 0);

  assert(pthread_mutex_destroy(&mutex) == 0);

  assert(mutex == NULL);

  return 0;
}

