#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  TYPE_1__* thread_t ;
struct TYPE_12__ {scalar_t__** cpu_kpc_buf; } ;
typedef  TYPE_2__ cpu_data_t ;
typedef  int boolean_t ;
struct TYPE_11__ {int kperf_flags; scalar_t__* kpc_buf; } ;

/* Variables and functions */
 int EINVAL ; 
 int FALSE ; 
 scalar_t__ KPC_MAX_COUNTERS ; 
 int /*<<< orphan*/  LCK_ATTR_NULL ; 
 int TRUE ; 
 int T_KPC_ALLOC ; 
 int /*<<< orphan*/  act_set_kperf (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* current_cpu_datap () ; 
 TYPE_1__* current_thread () ; 
 void* kpc_counterbuf_alloc () ; 
 int /*<<< orphan*/  kpc_counterbuf_free (scalar_t__*) ; 
 scalar_t__ kpc_get_counter_count (scalar_t__) ; 
 int /*<<< orphan*/  kpc_get_cpu_counters (int,scalar_t__,int /*<<< orphan*/ *,scalar_t__*) ; 
 int kpc_off_cpu_active ; 
 void kpc_off_cpu_update () ; 
 scalar_t__ kpc_thread_classes ; 
 scalar_t__ kpc_thread_classes_count ; 
 int /*<<< orphan*/  kpc_thread_lckgrp ; 
 int /*<<< orphan*/  kpc_thread_lckgrp_attr ; 
 int /*<<< orphan*/  kpc_thread_lock ; 
 int kpc_threads_counting ; 
 int /*<<< orphan*/  lck_grp_alloc_init (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_grp_attr_alloc_init () ; 
 int /*<<< orphan*/  lck_mtx_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,scalar_t__) ; 
 int ml_set_interrupts_enabled (int) ; 

void
kpc_thread_init(void)
{
	kpc_thread_lckgrp_attr = lck_grp_attr_alloc_init();
	kpc_thread_lckgrp = lck_grp_alloc_init("kpc", kpc_thread_lckgrp_attr);
	lck_mtx_init(&kpc_thread_lock, kpc_thread_lckgrp, LCK_ATTR_NULL);
}

uint32_t
kpc_get_thread_counting(void)
{
	uint32_t kpc_thread_classes_tmp;
	int kpc_threads_counting_tmp;

	/* Make sure we get a consistent snapshot of these values */
	lck_mtx_lock(&kpc_thread_lock);

	kpc_thread_classes_tmp = kpc_thread_classes;
	kpc_threads_counting_tmp = kpc_threads_counting;

	lck_mtx_unlock(&kpc_thread_lock);

	if( kpc_threads_counting_tmp )
		return kpc_thread_classes_tmp;
	else
		return 0;
}

int
kpc_set_thread_counting(uint32_t classes)
{
	uint32_t count;

	lck_mtx_lock(&kpc_thread_lock);

	count = kpc_get_counter_count(classes);

	if( (classes == 0)
	    || (count == 0) )
	{
		/* shut down */
		kpc_threads_counting = FALSE;
	}
	else
	{
		/* stash the config */
		kpc_thread_classes = classes;

		/* work out the size */
		kpc_thread_classes_count = count;
		assert(kpc_thread_classes_count <= KPC_MAX_COUNTERS);

		/* enable switch */
		kpc_threads_counting = TRUE;

		/* and schedule an AST for this thread... */
		if( !current_thread()->kpc_buf )
		{
			current_thread()->kperf_flags |= T_KPC_ALLOC;
			act_set_kperf(current_thread());
		}
	}

    kpc_off_cpu_update();
	lck_mtx_unlock(&kpc_thread_lock);

	return 0;
}

__attribute__((used)) static void
kpc_update_thread_counters( thread_t thread )
{
	uint32_t i;
	uint64_t *tmp = NULL;
	cpu_data_t *cpu = NULL;

	cpu = current_cpu_datap();

	/* 1. stash current PMCs into latest CPU block */
	kpc_get_cpu_counters( FALSE, kpc_thread_classes, 
	                      NULL, cpu->cpu_kpc_buf[1] );

	/* 2. apply delta to old thread */
	if( thread->kpc_buf )
		for( i = 0; i < kpc_thread_classes_count; i++ )
			thread->kpc_buf[i] += cpu->cpu_kpc_buf[1][i] - cpu->cpu_kpc_buf[0][i];

	/* schedule any necessary allocations */
	if( !current_thread()->kpc_buf )
	{
		current_thread()->kperf_flags |= T_KPC_ALLOC;
		act_set_kperf(current_thread());
	}

	/* 3. switch the PMC block pointers */
	tmp = cpu->cpu_kpc_buf[1];
	cpu->cpu_kpc_buf[1] = cpu->cpu_kpc_buf[0];
	cpu->cpu_kpc_buf[0] = tmp;
}

int
kpc_get_curthread_counters(uint32_t *inoutcount, uint64_t *buf)
{
	thread_t thread = current_thread();
	boolean_t enabled;

	/* buffer too small :( */
	if( *inoutcount < kpc_thread_classes_count )
		return EINVAL;

	/* copy data and actual size */
	if( !thread->kpc_buf )
		return EINVAL;

	enabled = ml_set_interrupts_enabled(FALSE);

	/* snap latest version of counters for this thread */
	kpc_update_thread_counters( current_thread() );
	
	/* copy out */
	memcpy( buf, thread->kpc_buf, 
	        kpc_thread_classes_count * sizeof(*buf) );
	*inoutcount = kpc_thread_classes_count;

	ml_set_interrupts_enabled(enabled);

	return 0;
}

void
kpc_off_cpu_update(void)
{
	kpc_off_cpu_active = kpc_threads_counting;
}

void
kpc_off_cpu_internal(thread_t thread)
{
	if (kpc_threads_counting) {
		kpc_update_thread_counters(thread);
	}
}

void
kpc_thread_create(thread_t thread)
{
	/* nothing to do if we're not counting */
	if(!kpc_threads_counting)
		return;

	/* give the new thread a counterbuf */
	thread->kpc_buf = kpc_counterbuf_alloc();
}

void
kpc_thread_destroy(thread_t thread)
{
	uint64_t *buf = NULL;

	/* usual case: no kpc buf, just return */
	if( !thread->kpc_buf )
		return;

	/* otherwise, don't leak */
	buf = thread->kpc_buf;
	thread->kpc_buf = NULL;
	kpc_counterbuf_free(buf);
}

void
kpc_thread_ast_handler( thread_t thread )
{
	/* see if we want an alloc */
	if( thread->kperf_flags & T_KPC_ALLOC )
		thread->kpc_buf = kpc_counterbuf_alloc();
}

