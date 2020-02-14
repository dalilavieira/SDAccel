#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ishtp_msg_hdr {size_t length; int msg_complete; scalar_t__ reserved; scalar_t__ fw_addr; scalar_t__ host_addr; } ;
struct TYPE_4__ {int /*<<< orphan*/  list; } ;
struct ishtp_device {int dev_state; int /*<<< orphan*/  devc; TYPE_2__ read_list; int /*<<< orphan*/  host_clients_map; scalar_t__ open_handle_count; int /*<<< orphan*/  bh_hbm_work; int /*<<< orphan*/  fw_clients_lock; int /*<<< orphan*/  cl_list_lock; int /*<<< orphan*/  device_list_lock; int /*<<< orphan*/  device_lock; int /*<<< orphan*/  read_list_spinlock; int /*<<< orphan*/  wait_hbm_recvd_msg; int /*<<< orphan*/  rd_msg_spinlock; scalar_t__ rd_msg_fifo_tail; scalar_t__ rd_msg_fifo_head; int /*<<< orphan*/  device_list; int /*<<< orphan*/  cl_list; TYPE_1__* ops; } ;
struct ishtp_cl {scalar_t__ host_client_id; scalar_t__ fw_client_id; } ;
struct TYPE_3__ {int (* ipc_reset ) (struct ishtp_device*) ;int (* hw_reset ) (struct ishtp_device*) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ISHTP_CLIENTS_MAX ; 
#define  ISHTP_DEV_DISABLED 134 
#define  ISHTP_DEV_ENABLED 133 
#define  ISHTP_DEV_INITIALIZING 132 
#define  ISHTP_DEV_INIT_CLIENTS 131 
#define  ISHTP_DEV_POWER_DOWN 130 
#define  ISHTP_DEV_POWER_UP 129 
#define  ISHTP_DEV_RESETTING 128 
 unsigned long MSEC_PER_SEC ; 
 int /*<<< orphan*/  bh_hbm_work_fn ; 
 int /*<<< orphan*/  bitmap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bitmap_zero (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 scalar_t__ ishtp_hbm_start_wait (struct ishtp_device*) ; 
 int /*<<< orphan*/  ishtp_query_subscribers (struct ishtp_device*) ; 
 unsigned long msecs_to_jiffies (unsigned long) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int stub1 (struct ishtp_device*) ; 
 int stub2 (struct ishtp_device*) ; 

__attribute__((used)) static inline void ishtp_hbm_hdr(struct ishtp_msg_hdr *hdr, size_t length)
{
	hdr->host_addr = 0;
	hdr->fw_addr = 0;
	hdr->length = length;
	hdr->msg_complete = 1;
	hdr->reserved = 0;
}

__attribute__((used)) static inline unsigned long ishtp_secs_to_jiffies(unsigned long sec)
{
	return msecs_to_jiffies(sec * MSEC_PER_SEC);
}

__attribute__((used)) static inline int ish_ipc_reset(struct ishtp_device *dev)
{
	return dev->ops->ipc_reset(dev);
}

__attribute__((used)) static inline int ish_hw_reset(struct ishtp_device *dev)
{
	return dev->ops->hw_reset(dev);
}

__attribute__((used)) static inline bool ishtp_cl_cmp_id(const struct ishtp_cl *cl1,
				   const struct ishtp_cl *cl2)
{
	return cl1 && cl2 &&
		(cl1->host_client_id == cl2->host_client_id) &&
		(cl1->fw_client_id == cl2->fw_client_id);
}

const char *ishtp_dev_state_str(int state)
{
	switch (state) {
	case ISHTP_DEV_INITIALIZING:
		return	"INITIALIZING";
	case ISHTP_DEV_INIT_CLIENTS:
		return	"INIT_CLIENTS";
	case ISHTP_DEV_ENABLED:
		return	"ENABLED";
	case ISHTP_DEV_RESETTING:
		return	"RESETTING";
	case ISHTP_DEV_DISABLED:
		return	"DISABLED";
	case ISHTP_DEV_POWER_DOWN:
		return	"POWER_DOWN";
	case ISHTP_DEV_POWER_UP:
		return	"POWER_UP";
	default:
		return "unknown";
	}
}

void ishtp_device_init(struct ishtp_device *dev)
{
	dev->dev_state = ISHTP_DEV_INITIALIZING;
	INIT_LIST_HEAD(&dev->cl_list);
	INIT_LIST_HEAD(&dev->device_list);
	dev->rd_msg_fifo_head = 0;
	dev->rd_msg_fifo_tail = 0;
	spin_lock_init(&dev->rd_msg_spinlock);

	init_waitqueue_head(&dev->wait_hbm_recvd_msg);
	spin_lock_init(&dev->read_list_spinlock);
	spin_lock_init(&dev->device_lock);
	spin_lock_init(&dev->device_list_lock);
	spin_lock_init(&dev->cl_list_lock);
	spin_lock_init(&dev->fw_clients_lock);
	INIT_WORK(&dev->bh_hbm_work, bh_hbm_work_fn);

	bitmap_zero(dev->host_clients_map, ISHTP_CLIENTS_MAX);
	dev->open_handle_count = 0;

	/*
	 * Reserving client ID 0 for ISHTP Bus Message communications
	 */
	bitmap_set(dev->host_clients_map, 0, 1);

	INIT_LIST_HEAD(&dev->read_list.list);

}

int ishtp_start(struct ishtp_device *dev)
{
	if (ishtp_hbm_start_wait(dev)) {
		dev_err(dev->devc, "HBM haven't started");
		goto err;
	}

	/* suspend & resume notification - send QUERY_SUBSCRIBERS msg */
	ishtp_query_subscribers(dev);

	return 0;
err:
	dev_err(dev->devc, "link layer initialization failed.\n");
	dev->dev_state = ISHTP_DEV_DISABLED;
	return -ENODEV;
}

