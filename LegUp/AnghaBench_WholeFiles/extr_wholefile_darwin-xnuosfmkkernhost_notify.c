#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_9__ ;
typedef  struct TYPE_34__   TYPE_8__ ;
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
struct host_notify_entry {int dummy; } ;
typedef  TYPE_3__* queue_t ;
struct TYPE_30__ {TYPE_2__* prev; TYPE_1__* next; } ;
typedef  TYPE_3__ queue_head_t ;
typedef  int /*<<< orphan*/  queue_entry_t ;
typedef  int /*<<< orphan*/  msg ;
typedef  int mach_msg_size_t ;
struct TYPE_31__ {TYPE_6__* msgh_remote_port; int /*<<< orphan*/  msgh_id; void* msgh_voucher_port; void* msgh_local_port; int /*<<< orphan*/  msgh_bits; } ;
typedef  TYPE_5__ mach_msg_header_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
typedef  TYPE_6__* ipc_port_t ;
typedef  scalar_t__ ipc_kobject_t ;
typedef  scalar_t__ host_t ;
typedef  TYPE_7__* host_notify_t ;
typedef  int host_flavor_t ;
struct TYPE_34__ {TYPE_5__ Head; } ;
typedef  TYPE_8__ __Request__host_calendar_set_t ;
struct TYPE_35__ {TYPE_5__ Head; } ;
typedef  TYPE_9__ __Request__host_calendar_changed_t ;
struct TYPE_33__ {TYPE_6__* port; } ;
struct TYPE_32__ {scalar_t__ ip_kobject; scalar_t__ ip_tempowner; } ;
struct TYPE_29__ {TYPE_3__* next; } ;
struct TYPE_28__ {TYPE_3__* prev; } ;

/* Variables and functions */
 int HOST_NOTIFY_CALENDAR_CHANGE ; 
 int HOST_NOTIFY_CALENDAR_SET ; 
 int HOST_NOTIFY_TYPE_MAX ; 
 scalar_t__ HOST_NULL ; 
 scalar_t__ IKOT_HOST_NOTIFY ; 
 scalar_t__ IKOT_NONE ; 
 scalar_t__ IKO_NULL ; 
 TYPE_6__* IP_NULL ; 
 int /*<<< orphan*/  IP_VALID (TYPE_6__*) ; 
 int /*<<< orphan*/  KERN_FAILURE ; 
 int /*<<< orphan*/  KERN_INVALID_ARGUMENT ; 
 int /*<<< orphan*/  KERN_INVALID_CAPABILITY ; 
 int /*<<< orphan*/  KERN_RESOURCE_SHORTAGE ; 
 int /*<<< orphan*/  KERN_SUCCESS ; 
 int /*<<< orphan*/  MACH_MSGH_BITS_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MACH_MSG_TYPE_MOVE_SEND_ONCE ; 
 void* MACH_PORT_NULL ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ dequeue (TYPE_3__*) ; 
 int /*<<< orphan*/  enqueue_tail (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  host_notify_lock ; 
 int /*<<< orphan*/  host_notify_lock_attr ; 
 int /*<<< orphan*/  host_notify_lock_ext ; 
 int /*<<< orphan*/  host_notify_lock_grp ; 
 int /*<<< orphan*/  host_notify_lock_grp_attr ; 
 TYPE_3__* host_notify_queue ; 
 int /*<<< orphan*/ * host_notify_replyid ; 
 int /*<<< orphan*/  host_notify_zone ; 
 int /*<<< orphan*/  ip_active (TYPE_6__*) ; 
 scalar_t__ ip_kotype (TYPE_6__*) ; 
 int /*<<< orphan*/  ip_lock (TYPE_6__*) ; 
 int /*<<< orphan*/  ip_unlock (TYPE_6__*) ; 
 int /*<<< orphan*/  ipc_kobject_set_atomically (TYPE_6__*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ipc_port_release_sonce (TYPE_6__*) ; 
 int /*<<< orphan*/  lck_attr_setdefault (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_grp_attr_setdefault (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_grp_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_init_ext (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mach_msg_send_from_kernel_proper (TYPE_5__*,int) ; 
 int /*<<< orphan*/  queue_empty (TYPE_3__*) ; 
 int /*<<< orphan*/  queue_init (TYPE_3__*) ; 
 int /*<<< orphan*/  remqueue (int /*<<< orphan*/ ) ; 
 scalar_t__ zalloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ ,TYPE_7__*) ; 
 int /*<<< orphan*/  zinit (int,int,int,char*) ; 

void
host_notify_init(void)
{
	int		i;

	for (i = 0; i <= HOST_NOTIFY_TYPE_MAX; i++)
		queue_init(&host_notify_queue[i]);

	lck_grp_attr_setdefault(&host_notify_lock_grp_attr);
	lck_grp_init(&host_notify_lock_grp, "host_notify", &host_notify_lock_grp_attr);
	lck_attr_setdefault(&host_notify_lock_attr);

	lck_mtx_init_ext(&host_notify_lock, &host_notify_lock_ext, &host_notify_lock_grp, &host_notify_lock_attr);

	i = sizeof (struct host_notify_entry);
	host_notify_zone =
			zinit(i, (4096 * i), (16 * i), "host_notify");
}

kern_return_t
host_request_notification(
	host_t					host,
	host_flavor_t			notify_type,
	ipc_port_t				port)
{
	host_notify_t		entry;

	if (host == HOST_NULL)
		return (KERN_INVALID_ARGUMENT);

	if (!IP_VALID(port))
		return (KERN_INVALID_CAPABILITY);

	if (notify_type > HOST_NOTIFY_TYPE_MAX || notify_type < 0)
		return (KERN_INVALID_ARGUMENT);

	entry = (host_notify_t)zalloc(host_notify_zone);
	if (entry == NULL)
		return (KERN_RESOURCE_SHORTAGE);

	lck_mtx_lock(&host_notify_lock);

	ip_lock(port);
	if (!ip_active(port) || port->ip_tempowner || ip_kotype(port) != IKOT_NONE) {
		ip_unlock(port);

		lck_mtx_unlock(&host_notify_lock);
		zfree(host_notify_zone, entry);

		return (KERN_FAILURE);
	}

	entry->port = port;
	ipc_kobject_set_atomically(port, (ipc_kobject_t)entry, IKOT_HOST_NOTIFY);
	ip_unlock(port);

	enqueue_tail(&host_notify_queue[notify_type], (queue_entry_t)entry);
	lck_mtx_unlock(&host_notify_lock);

	return (KERN_SUCCESS);
}

void
host_notify_port_destroy(
	ipc_port_t			port)
{
	host_notify_t		entry;

	lck_mtx_lock(&host_notify_lock);

	ip_lock(port);
	if (ip_kotype(port) == IKOT_HOST_NOTIFY) {
		entry = (host_notify_t)port->ip_kobject;
		assert(entry != NULL);
		ipc_kobject_set_atomically(port, IKO_NULL, IKOT_NONE);
		ip_unlock(port);

		assert(entry->port == port);
		remqueue((queue_entry_t)entry);
		lck_mtx_unlock(&host_notify_lock);
		zfree(host_notify_zone, entry);

		ipc_port_release_sonce(port);
		return;
	}
	ip_unlock(port);

	lck_mtx_unlock(&host_notify_lock);
}

__attribute__((used)) static void
host_notify_all(
	host_flavor_t		notify_type,
	mach_msg_header_t	*msg,
	mach_msg_size_t		msg_size)
{
	queue_t		notify_queue = &host_notify_queue[notify_type];

	lck_mtx_lock(&host_notify_lock);

	if (!queue_empty(notify_queue)) {
		queue_head_t		send_queue;
		host_notify_t		entry;

		send_queue = *notify_queue;
		queue_init(notify_queue);

		send_queue.next->prev = &send_queue;
		send_queue.prev->next = &send_queue;

		msg->msgh_bits =
		    MACH_MSGH_BITS_SET(MACH_MSG_TYPE_MOVE_SEND_ONCE, 0, 0, 0);
		msg->msgh_local_port = MACH_PORT_NULL;
		msg->msgh_voucher_port = MACH_PORT_NULL;
		msg->msgh_id = host_notify_replyid[notify_type];

		while ((entry = (host_notify_t)dequeue(&send_queue)) != NULL) {
			ipc_port_t		port;

			port = entry->port;
			assert(port != IP_NULL);

			ip_lock(port);
			assert(ip_kotype(port) == IKOT_HOST_NOTIFY);
			assert(port->ip_kobject == (ipc_kobject_t)entry);
			ipc_kobject_set_atomically(port, IKO_NULL, IKOT_NONE);
			ip_unlock(port);

			lck_mtx_unlock(&host_notify_lock);
			zfree(host_notify_zone, entry);

			msg->msgh_remote_port = port;

			(void) mach_msg_send_from_kernel_proper(msg, msg_size);

			lck_mtx_lock(&host_notify_lock);
		}
	}

	lck_mtx_unlock(&host_notify_lock);
}

void
host_notify_calendar_change(void)
{
	__Request__host_calendar_changed_t	msg;

	host_notify_all(HOST_NOTIFY_CALENDAR_CHANGE, &msg.Head, sizeof (msg));
}

void
host_notify_calendar_set(void)
{
	__Request__host_calendar_set_t	msg;

	host_notify_all(HOST_NOTIFY_CALENDAR_SET, &msg.Head, sizeof (msg));
}

