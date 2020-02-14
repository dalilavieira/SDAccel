#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* work_interval_t ;
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
struct work_interval_notification {int wicp_create_flags; scalar_t__ wicp_port; int notify_flags; int create_flags; scalar_t__ next_start; scalar_t__ deadline; scalar_t__ finish; scalar_t__ start; scalar_t__ wicp_id; } ;
struct work_interval_create_params {int wicp_create_flags; scalar_t__ wicp_port; int notify_flags; int create_flags; scalar_t__ next_start; scalar_t__ deadline; scalar_t__ finish; scalar_t__ start; scalar_t__ wicp_id; } ;
typedef  int /*<<< orphan*/  notification ;
typedef  scalar_t__ mach_port_t ;
typedef  scalar_t__ kern_return_t ;
typedef  int /*<<< orphan*/  create_params ;
struct TYPE_10__ {int create_flags; scalar_t__ wi_port; scalar_t__ work_interval_id; int /*<<< orphan*/  thread_id; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ KERN_SUCCESS ; 
 scalar_t__ MACH_PORT_NULL ; 
 int /*<<< orphan*/  MACH_PORT_RIGHT_SEND ; 
 int /*<<< orphan*/  MACH_PORT_VALID (scalar_t__) ; 
 int WORK_INTERVAL_FLAG_JOINABLE ; 
 int /*<<< orphan*/  WORK_INTERVAL_OPERATION_CREATE2 ; 
 int /*<<< orphan*/  WORK_INTERVAL_OPERATION_DESTROY ; 
 int /*<<< orphan*/  WORK_INTERVAL_OPERATION_JOIN ; 
 int /*<<< orphan*/  WORK_INTERVAL_OPERATION_NOTIFY ; 
 int /*<<< orphan*/  __thread_selfid () ; 
 int __work_interval_ctl (int /*<<< orphan*/ ,scalar_t__,struct work_interval_notification*,int) ; 
 int errno ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 scalar_t__ mach_absolute_time () ; 
 scalar_t__ mach_port_deallocate (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ mach_port_mod_refs (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mach_task_self () ; 
 TYPE_1__* malloc (int) ; 
 int work_interval_join_port (scalar_t__) ; 

int
work_interval_create(work_interval_t *interval_handle, uint32_t create_flags)
{
	int ret;
	work_interval_t handle;

	if (interval_handle == NULL) {
		errno = EINVAL;
		return -1;
	}

	struct work_interval_create_params create_params = {
		.wicp_create_flags = create_flags,
	};

	ret = __work_interval_ctl(WORK_INTERVAL_OPERATION_CREATE2, 0,
	                          &create_params, sizeof(create_params));
	if (ret == -1) {
		return ret;
	}

	handle = malloc(sizeof(*handle));
	if (handle == NULL) {
		errno = ENOMEM;
		return -1;
	}

	handle->thread_id = __thread_selfid();
	handle->work_interval_id = create_params.wicp_id;
	handle->create_flags = create_params.wicp_create_flags;
	handle->wi_port = create_params.wicp_port;

	*interval_handle = handle;
	return 0;
}

int
work_interval_notify(work_interval_t interval_handle, uint64_t start,
                     uint64_t finish, uint64_t deadline, uint64_t next_start,
                     uint32_t notify_flags)
{
	int ret;
	uint64_t work_interval_id;
	struct work_interval_notification notification = {
		.start = start,
		.finish = finish,
		.deadline = deadline,
		.next_start = next_start,
		.notify_flags = notify_flags
	};

	if (interval_handle == NULL) {
		errno = EINVAL;
		return -1;
	}

	notification.create_flags = interval_handle->create_flags;
	work_interval_id = interval_handle->work_interval_id;

	ret = __work_interval_ctl(WORK_INTERVAL_OPERATION_NOTIFY, work_interval_id,
	                          &notification, sizeof(notification));
	return ret;
}

int
work_interval_notify_simple(work_interval_t interval_handle, uint64_t start,
                            uint64_t deadline, uint64_t next_start)
{
	return work_interval_notify(interval_handle, start, mach_absolute_time(),
	                            deadline, next_start, 0);
}

int
work_interval_destroy(work_interval_t interval_handle)
{
	if (interval_handle == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (interval_handle->create_flags & WORK_INTERVAL_FLAG_JOINABLE) {
		mach_port_t wi_port = interval_handle->wi_port;

		/*
		 * A joinable work interval's lifetime is tied to the port lifetime.
		 * When the last port reference is destroyed, the work interval
		 * is destroyed via no-senders notification.
		 *
		 * Note however that after destroy it can no longer be notified
		 * because the userspace token is gone.
		 *
		 * Additionally, this function does not cause the thread to un-join
		 * the interval.
		 */
		kern_return_t kr = mach_port_deallocate(mach_task_self(), wi_port);

		if (kr != KERN_SUCCESS) {
			/*
			 * If the deallocate fails, then someone got their port
			 * lifecycle wrong and over-released a port right.
			 *
			 * Return an error so the client can assert on this,
			 * and still find the port name in the interval handle.
			 */
			errno = EINVAL;
			return -1;
		}

		interval_handle->wi_port = MACH_PORT_NULL;
		interval_handle->work_interval_id = 0;

		free(interval_handle);
		return 0;
	} else {
		uint64_t work_interval_id = interval_handle->work_interval_id;

		int ret = __work_interval_ctl(WORK_INTERVAL_OPERATION_DESTROY,
		                              work_interval_id, NULL, 0);

		interval_handle->work_interval_id = 0;

		int saved_errno = errno;
		free(interval_handle);
		errno = saved_errno;
		return ret;
	}
}

int
work_interval_join(work_interval_t interval_handle)
{
	if (interval_handle == NULL) {
		errno = EINVAL;
		return -1;
	}

	if ((interval_handle->create_flags & WORK_INTERVAL_FLAG_JOINABLE) == 0) {
		errno = EINVAL;
		return -1;
	}

	mach_port_t wi_port = interval_handle->wi_port;

	if (!MACH_PORT_VALID(wi_port)) {
		errno = EINVAL;
		return -1;
	}

	return work_interval_join_port(wi_port);
}

int
work_interval_join_port(mach_port_t port)
{
	if (port == MACH_PORT_NULL) {
		errno = EINVAL;
		return -1;
	}

	return __work_interval_ctl(WORK_INTERVAL_OPERATION_JOIN,
	                           (uint64_t)port, NULL, 0);
}

int
work_interval_leave(void)
{
	return __work_interval_ctl(WORK_INTERVAL_OPERATION_JOIN,
	                           (uint64_t)MACH_PORT_NULL, NULL, 0);
}

int
work_interval_copy_port(work_interval_t interval_handle, mach_port_t *port)
{
	if (port == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (interval_handle == NULL) {
		*port = MACH_PORT_NULL;
		errno = EINVAL;
		return -1;
	}

	if ((interval_handle->create_flags & WORK_INTERVAL_FLAG_JOINABLE) == 0) {
		*port = MACH_PORT_NULL;
		errno = EINVAL;
		return -1;
	}

	mach_port_t wi_port = interval_handle->wi_port;

	kern_return_t kr = mach_port_mod_refs(mach_task_self(), wi_port,
	                                      MACH_PORT_RIGHT_SEND, 1);

	if (kr != KERN_SUCCESS) {
		*port = MACH_PORT_NULL;
		errno = EINVAL;
		return -1;
	}

	*port = wi_port;

	return 0;
}

