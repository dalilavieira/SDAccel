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
 scalar_t__ READ_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,int) ; 
 scalar_t__ __unbuffered_tpr_x ; 
 scalar_t__ __unbuffered_tpr_y ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  might_sleep () ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int srcu_read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  srcu_read_unlock (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ss ; 
 int /*<<< orphan*/  synchronize_srcu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  x ; 
 int /*<<< orphan*/  y ; 

void rcu_reader(void)
{
	int idx;

#ifndef FORCE_FAILURE_3
	idx = srcu_read_lock(&ss);
#endif
	might_sleep();

	__unbuffered_tpr_y = READ_ONCE(y);
#ifdef FORCE_FAILURE
	srcu_read_unlock(&ss, idx);
	idx = srcu_read_lock(&ss);
#endif
	WRITE_ONCE(x, 1);

#ifndef FORCE_FAILURE_3
	srcu_read_unlock(&ss, idx);
#endif
	might_sleep();
}

void *thread_update(void *arg)
{
	WRITE_ONCE(y, 1);
#ifndef FORCE_FAILURE_2
	synchronize_srcu(&ss);
#endif
	might_sleep();
	__unbuffered_tpr_x = READ_ONCE(x);

	return NULL;
}

void *thread_process_reader(void *arg)
{
	rcu_reader();

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tu;
	pthread_t tpr;

	if (pthread_create(&tu, NULL, thread_update, NULL))
		abort();
	if (pthread_create(&tpr, NULL, thread_process_reader, NULL))
		abort();
	if (pthread_join(tu, NULL))
		abort();
	if (pthread_join(tpr, NULL))
		abort();
	assert(__unbuffered_tpr_y != 0 || __unbuffered_tpr_x != 0);

#ifdef ASSERT_END
	assert(0);
#endif

	return 0;
}

