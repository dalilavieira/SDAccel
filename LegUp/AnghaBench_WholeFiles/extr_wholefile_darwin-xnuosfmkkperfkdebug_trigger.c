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
typedef  int /*<<< orphan*/  user_addr_t ;
typedef  size_t uint8_t ;
typedef  scalar_t__ uint32_t ;
struct kperf_kdebug_filter {size_t n_debugids; scalar_t__* debugids; int /*<<< orphan*/  types; } ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 scalar_t__ DBG_PERF ; 
 size_t DECODE_TYPE (int /*<<< orphan*/ ,size_t) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ KDBG_EXTRACT_CLASS (scalar_t__) ; 
 scalar_t__ KPERF_KDEBUG_DEBUGIDS_MAX ; 
 int /*<<< orphan*/  KPERF_KDEBUG_FILTER_SIZE (scalar_t__) ; 
 scalar_t__ KPERF_KDEBUG_N_DEBUGIDS (scalar_t__) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_DIAG ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bzero (struct kperf_kdebug_filter*,int) ; 
 int copyin (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__* debugid_masks ; 
 struct kperf_kdebug_filter* kalloc_tag (int,int /*<<< orphan*/ ) ; 
 unsigned int kperf_action_get_count () ; 
 int kperf_init () ; 
 int kperf_kdebug_action ; 
 int /*<<< orphan*/  kperf_kdebug_active ; 
 struct kperf_kdebug_filter* kperf_kdebug_filter ; 
 int kperf_kdebug_set_n_debugids (scalar_t__) ; 
static  void kperf_kdebug_update () ; 

int
kperf_kdebug_init(void)
{
	kperf_kdebug_filter = kalloc_tag(sizeof(*kperf_kdebug_filter),
	                                 VM_KERN_MEMORY_DIAG);
	if (kperf_kdebug_filter == NULL) {
		return ENOMEM;
	}
	bzero(kperf_kdebug_filter, sizeof(*kperf_kdebug_filter));

	return 0;
}

void
kperf_kdebug_reset(void)
{
	int err;

	if ((err = kperf_init())) {
		return;
	}

	kperf_kdebug_action = 0;
	bzero(kperf_kdebug_filter, sizeof(*kperf_kdebug_filter));
	kperf_kdebug_update();
}

boolean_t
kperf_kdebug_should_trigger(uint32_t debugid)
{
	/* ignore kperf events */
	if (KDBG_EXTRACT_CLASS(debugid) == DBG_PERF) {
		return FALSE;
	}

	/*
	 * Search linearly through list of debugids and masks.  If the filter
	 * gets larger than 128 bytes, change this to either a binary search or
	 * a sparse bitmap on the uint32_t range, depending on the new size.
	 */
	for (uint8_t i = 0; i < kperf_kdebug_filter->n_debugids; i++) {
		uint32_t check_debugid =
			kperf_kdebug_filter->debugids[i];
		uint32_t mask = debugid_masks[DECODE_TYPE(kperf_kdebug_filter->types, i)];

		if ((debugid & mask) == check_debugid) {
			return TRUE;
		}
	}

	return FALSE;
}

int
kperf_kdebug_set_filter(user_addr_t user_filter, uint32_t user_size)
{
	uint32_t n_debugids_provided = 0;
	int err = 0;

	if ((err = kperf_init())) {
		return err;
	}

	n_debugids_provided = (uint32_t)KPERF_KDEBUG_N_DEBUGIDS(user_size);

	/* detect disabling the filter completely */
	if (n_debugids_provided == 0) {
		bzero(kperf_kdebug_filter, sizeof(*kperf_kdebug_filter));
		goto out;
	}

	if ((err = kperf_kdebug_set_n_debugids(n_debugids_provided))) {
		goto out;
	}

	if ((err = copyin(user_filter, (char *)kperf_kdebug_filter,
	                  KPERF_KDEBUG_FILTER_SIZE(n_debugids_provided))))
	{
		bzero(kperf_kdebug_filter, sizeof(*kperf_kdebug_filter));
		goto out;
	}

out:
	kperf_kdebug_update();

	return err;
}

uint32_t
kperf_kdebug_get_filter(struct kperf_kdebug_filter **filter)
{
	int err;

	if ((err = kperf_init())) {
		return 0;
	}

	assert(filter != NULL);

	*filter = kperf_kdebug_filter;
	return kperf_kdebug_filter->n_debugids;
}

int
kperf_kdebug_set_n_debugids(uint32_t n_debugids_in)
{
	int err;

	if ((err = kperf_init())) {
		return EINVAL;
	}

	if (n_debugids_in > KPERF_KDEBUG_DEBUGIDS_MAX) {
		return EINVAL;
	}

	kperf_kdebug_filter->n_debugids = n_debugids_in;

	return 0;
}

int
kperf_kdebug_set_action(int action_id)
{
	if (action_id < 0 || (unsigned int)action_id > kperf_action_get_count()) {
		return EINVAL;
	}

	kperf_kdebug_action = action_id;
	kperf_kdebug_update();

	return 0;
}

int
kperf_kdebug_get_action(void)
{
	return kperf_kdebug_action;
}

__attribute__((used)) static void
kperf_kdebug_update(void)
{
	int err;

	if ((err = kperf_init())) {
		return;
	}

	if (kperf_kdebug_action != 0 &&
	    kperf_kdebug_filter->n_debugids != 0)
	{
		kperf_kdebug_active = TRUE;
	} else {
		kperf_kdebug_active = FALSE;
	}
}

