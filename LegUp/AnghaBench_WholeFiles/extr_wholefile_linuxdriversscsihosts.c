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
typedef  int ulong ;
struct work_struct {int dummy; } ;
struct scsi_target {int dummy; } ;
struct scsi_host_template {scalar_t__ supported_mode; int dma_boundary; int /*<<< orphan*/  name; scalar_t__ force_blk_mq; scalar_t__ max_sectors; scalar_t__ max_host_blocked; int /*<<< orphan*/  eh_host_reset_handler; int /*<<< orphan*/  no_write_same; int /*<<< orphan*/  use_clustering; scalar_t__ unchecked_isa_dma; int /*<<< orphan*/  cmd_per_lun; int /*<<< orphan*/  sg_prot_tablesize; int /*<<< orphan*/  sg_tablesize; int /*<<< orphan*/  can_queue; int /*<<< orphan*/  this_id; int /*<<< orphan*/  tag_alloc_policy; int /*<<< orphan*/  (* info ) (struct Scsi_Host*) ;} ;
struct scsi_device {int dummy; } ;
struct scsi_cmnd {int dummy; } ;
struct device {int /*<<< orphan*/ * type; int /*<<< orphan*/  groups; int /*<<< orphan*/ * class; struct device* parent; int /*<<< orphan*/ * bus; } ;
struct TYPE_3__ {scalar_t__ tags; } ;
struct Scsi_Host {int shost_state; int host_no; int dma_channel; int max_id; int max_lun; int max_cmd_len; int eh_deadline; scalar_t__ active_mode; int dma_boundary; int use_blk_mq; scalar_t__ work_q; struct scsi_host_template* hostt; struct device shost_gendev; int /*<<< orphan*/  host_busy; scalar_t__ ehandler; scalar_t__ tmf_work_q; struct device shost_dev; scalar_t__ max_sectors; scalar_t__ max_host_blocked; int /*<<< orphan*/  no_write_same; int /*<<< orphan*/  use_clustering; scalar_t__ unchecked_isa_dma; int /*<<< orphan*/  cmd_per_lun; int /*<<< orphan*/  sg_prot_tablesize; int /*<<< orphan*/  sg_tablesize; int /*<<< orphan*/  can_queue; int /*<<< orphan*/  this_id; TYPE_2__* transportt; scalar_t__ max_channel; int /*<<< orphan*/  scan_mutex; int /*<<< orphan*/  host_wait; int /*<<< orphan*/  starved_list; int /*<<< orphan*/  eh_cmd_q; int /*<<< orphan*/  __targets; int /*<<< orphan*/  __devices; int /*<<< orphan*/ * host_lock; int /*<<< orphan*/  default_lock; struct Scsi_Host* shost_data; scalar_t__ bqt; TYPE_1__ tag_set; int /*<<< orphan*/  work_q_name; struct device* dma_dev; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum scsi_host_state { ____Placeholder_scsi_host_state } scsi_host_state ;
struct TYPE_4__ {int host_size; scalar_t__ create_work_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int INT_MAX ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  KERN_INFO ; 
 int /*<<< orphan*/  KERN_WARNING ; 
 scalar_t__ MODE_INITIATOR ; 
 scalar_t__ MODE_UNKNOWN ; 
 int /*<<< orphan*/  PTR_ERR (scalar_t__) ; 
 scalar_t__ SCSI_DEFAULT_HOST_BLOCKED ; 
 scalar_t__ SCSI_DEFAULT_MAX_SECTORS ; 
 int /*<<< orphan*/  SCSI_LOG_ERROR_RECOVERY (int,int /*<<< orphan*/ ) ; 
#define  SHOST_CANCEL 134 
#define  SHOST_CANCEL_RECOVERY 133 
#define  SHOST_CREATED 132 
#define  SHOST_DEL 131 
#define  SHOST_DEL_RECOVERY 130 
#define  SHOST_RECOVERY 129 
#define  SHOST_RUNNING 128 
 int WQ_MEM_RECLAIM ; 
 int WQ_UNBOUND ; 
 int /*<<< orphan*/  __GFP_DMA ; 
 scalar_t__ alloc_workqueue (char*,int,int,int) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 TYPE_2__ blank_transport_template ; 
 int /*<<< orphan*/  blk_free_tags (scalar_t__) ; 
 scalar_t__ blk_init_tags (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct device* class_find_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned short*,int (*) (struct device*,void const*)) ; 
 int class_register (int /*<<< orphan*/ *) ; 
 struct Scsi_Host* class_to_shost (struct device*) ; 
 int /*<<< orphan*/  class_unregister (int /*<<< orphan*/ *) ; 
 scalar_t__ create_singlethread_workqueue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  destroy_workqueue (scalar_t__) ; 
 struct Scsi_Host* dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_name (struct device*,char*,int) ; 
 struct Scsi_Host* dev_to_shost (struct device*) ; 
 int device_add (struct device*) ; 
 int /*<<< orphan*/  device_del (struct device*) ; 
 int /*<<< orphan*/  device_disable_async_suspend (struct device*) ; 
 int /*<<< orphan*/  device_enable_async_suspend (struct device*) ; 
 int /*<<< orphan*/  device_initialize (struct device*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  flush_workqueue (scalar_t__) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int /*<<< orphan*/  host_index_ida ; 
 int /*<<< orphan*/  ida_destroy (int /*<<< orphan*/ *) ; 
 int ida_simple_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct Scsi_Host*) ; 
 scalar_t__ kthread_run (int /*<<< orphan*/ ,struct Scsi_Host*,char*,int) ; 
 int /*<<< orphan*/  kthread_stop (scalar_t__) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct device platform_bus ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (struct device*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int queue_work (scalar_t__,struct work_struct*) ; 
 int /*<<< orphan*/  rcu_barrier () ; 
 int /*<<< orphan*/  scsi_bus_type ; 
 int /*<<< orphan*/  scsi_error_handler ; 
 int /*<<< orphan*/  scsi_forget_host (struct Scsi_Host*) ; 
 struct Scsi_Host* scsi_host_get (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_host_state_name (int) ; 
 int /*<<< orphan*/  scsi_host_type ; 
 int scsi_init_sense_cache (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_mq_destroy_tags (struct Scsi_Host*) ; 
 int scsi_mq_setup_tags (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_proc_host_add (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_proc_host_rm (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_proc_hostdir_add (struct scsi_host_template*) ; 
 int /*<<< orphan*/  scsi_proc_hostdir_rm (struct scsi_host_template*) ; 
 int scsi_sysfs_add_host (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_sysfs_shost_attr_groups ; 
 scalar_t__ scsi_use_blk_mq ; 
 int /*<<< orphan*/  shost_class ; 
 int shost_eh_deadline ; 
 int /*<<< orphan*/  shost_printk (int /*<<< orphan*/ ,struct Scsi_Host*,char*,...) ; 
 scalar_t__ shost_use_blk_mq (struct Scsi_Host*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct Scsi_Host*) ; 
 int /*<<< orphan*/  transport_unregister_device (struct device*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline void scsi_log_send(struct scsi_cmnd *cmd) 
	{ }

__attribute__((used)) static inline void scsi_log_completion(struct scsi_cmnd *cmd, int disposition)
	{ }

__attribute__((used)) static inline void scsi_netlink_init(void) {}

__attribute__((used)) static inline void scsi_netlink_exit(void) {}

__attribute__((used)) static inline void scsi_autopm_get_target(struct scsi_target *t) {}

__attribute__((used)) static inline void scsi_autopm_put_target(struct scsi_target *t) {}

__attribute__((used)) static inline int scsi_autopm_get_host(struct Scsi_Host *h) { return 0; }

__attribute__((used)) static inline void scsi_autopm_put_host(struct Scsi_Host *h) {}

__attribute__((used)) static inline void scsi_dh_add_device(struct scsi_device *sdev) { }

__attribute__((used)) static inline void scsi_dh_release_device(struct scsi_device *sdev) { }

__attribute__((used)) static void scsi_host_cls_release(struct device *dev)
{
	put_device(&class_to_shost(dev)->shost_gendev);
}

int scsi_host_set_state(struct Scsi_Host *shost, enum scsi_host_state state)
{
	enum scsi_host_state oldstate = shost->shost_state;

	if (state == oldstate)
		return 0;

	switch (state) {
	case SHOST_CREATED:
		/* There are no legal states that come back to
		 * created.  This is the manually initialised start
		 * state */
		goto illegal;

	case SHOST_RUNNING:
		switch (oldstate) {
		case SHOST_CREATED:
		case SHOST_RECOVERY:
			break;
		default:
			goto illegal;
		}
		break;

	case SHOST_RECOVERY:
		switch (oldstate) {
		case SHOST_RUNNING:
			break;
		default:
			goto illegal;
		}
		break;

	case SHOST_CANCEL:
		switch (oldstate) {
		case SHOST_CREATED:
		case SHOST_RUNNING:
		case SHOST_CANCEL_RECOVERY:
			break;
		default:
			goto illegal;
		}
		break;

	case SHOST_DEL:
		switch (oldstate) {
		case SHOST_CANCEL:
		case SHOST_DEL_RECOVERY:
			break;
		default:
			goto illegal;
		}
		break;

	case SHOST_CANCEL_RECOVERY:
		switch (oldstate) {
		case SHOST_CANCEL:
		case SHOST_RECOVERY:
			break;
		default:
			goto illegal;
		}
		break;

	case SHOST_DEL_RECOVERY:
		switch (oldstate) {
		case SHOST_CANCEL_RECOVERY:
			break;
		default:
			goto illegal;
		}
		break;
	}
	shost->shost_state = state;
	return 0;

 illegal:
	SCSI_LOG_ERROR_RECOVERY(1,
				shost_printk(KERN_ERR, shost,
					     "Illegal host state transition"
					     "%s->%s\n",
					     scsi_host_state_name(oldstate),
					     scsi_host_state_name(state)));
	return -EINVAL;
}

void scsi_remove_host(struct Scsi_Host *shost)
{
	unsigned long flags;

	mutex_lock(&shost->scan_mutex);
	spin_lock_irqsave(shost->host_lock, flags);
	if (scsi_host_set_state(shost, SHOST_CANCEL))
		if (scsi_host_set_state(shost, SHOST_CANCEL_RECOVERY)) {
			spin_unlock_irqrestore(shost->host_lock, flags);
			mutex_unlock(&shost->scan_mutex);
			return;
		}
	spin_unlock_irqrestore(shost->host_lock, flags);

	scsi_autopm_get_host(shost);
	flush_workqueue(shost->tmf_work_q);
	scsi_forget_host(shost);
	mutex_unlock(&shost->scan_mutex);
	scsi_proc_host_rm(shost);

	spin_lock_irqsave(shost->host_lock, flags);
	if (scsi_host_set_state(shost, SHOST_DEL))
		BUG_ON(scsi_host_set_state(shost, SHOST_DEL_RECOVERY));
	spin_unlock_irqrestore(shost->host_lock, flags);

	transport_unregister_device(&shost->shost_gendev);
	device_unregister(&shost->shost_dev);
	device_del(&shost->shost_gendev);
}

int scsi_add_host_with_dma(struct Scsi_Host *shost, struct device *dev,
			   struct device *dma_dev)
{
	struct scsi_host_template *sht = shost->hostt;
	int error = -EINVAL;

	shost_printk(KERN_INFO, shost, "%s\n",
			sht->info ? sht->info(shost) : sht->name);

	if (!shost->can_queue) {
		shost_printk(KERN_ERR, shost,
			     "can_queue = 0 no longer supported\n");
		goto fail;
	}

	error = scsi_init_sense_cache(shost);
	if (error)
		goto fail;

	if (shost_use_blk_mq(shost)) {
		error = scsi_mq_setup_tags(shost);
		if (error)
			goto fail;
	} else {
		shost->bqt = blk_init_tags(shost->can_queue,
				shost->hostt->tag_alloc_policy);
		if (!shost->bqt) {
			error = -ENOMEM;
			goto fail;
		}
	}

	if (!shost->shost_gendev.parent)
		shost->shost_gendev.parent = dev ? dev : &platform_bus;
	if (!dma_dev)
		dma_dev = shost->shost_gendev.parent;

	shost->dma_dev = dma_dev;

	/*
	 * Increase usage count temporarily here so that calling
	 * scsi_autopm_put_host() will trigger runtime idle if there is
	 * nothing else preventing suspending the device.
	 */
	pm_runtime_get_noresume(&shost->shost_gendev);
	pm_runtime_set_active(&shost->shost_gendev);
	pm_runtime_enable(&shost->shost_gendev);
	device_enable_async_suspend(&shost->shost_gendev);

	error = device_add(&shost->shost_gendev);
	if (error)
		goto out_disable_runtime_pm;

	scsi_host_set_state(shost, SHOST_RUNNING);
	get_device(shost->shost_gendev.parent);

	device_enable_async_suspend(&shost->shost_dev);

	error = device_add(&shost->shost_dev);
	if (error)
		goto out_del_gendev;

	get_device(&shost->shost_gendev);

	if (shost->transportt->host_size) {
		shost->shost_data = kzalloc(shost->transportt->host_size,
					 GFP_KERNEL);
		if (shost->shost_data == NULL) {
			error = -ENOMEM;
			goto out_del_dev;
		}
	}

	if (shost->transportt->create_work_queue) {
		snprintf(shost->work_q_name, sizeof(shost->work_q_name),
			 "scsi_wq_%d", shost->host_no);
		shost->work_q = create_singlethread_workqueue(
					shost->work_q_name);
		if (!shost->work_q) {
			error = -EINVAL;
			goto out_free_shost_data;
		}
	}

	error = scsi_sysfs_add_host(shost);
	if (error)
		goto out_destroy_host;

	scsi_proc_host_add(shost);
	scsi_autopm_put_host(shost);
	return error;

 out_destroy_host:
	if (shost->work_q)
		destroy_workqueue(shost->work_q);
 out_free_shost_data:
	kfree(shost->shost_data);
 out_del_dev:
	device_del(&shost->shost_dev);
 out_del_gendev:
	device_del(&shost->shost_gendev);
 out_disable_runtime_pm:
	device_disable_async_suspend(&shost->shost_gendev);
	pm_runtime_disable(&shost->shost_gendev);
	pm_runtime_set_suspended(&shost->shost_gendev);
	pm_runtime_put_noidle(&shost->shost_gendev);
	if (shost_use_blk_mq(shost))
		scsi_mq_destroy_tags(shost);
 fail:
	return error;
}

__attribute__((used)) static void scsi_host_dev_release(struct device *dev)
{
	struct Scsi_Host *shost = dev_to_shost(dev);
	struct device *parent = dev->parent;

	scsi_proc_hostdir_rm(shost->hostt);

	/* Wait for functions invoked through call_rcu(&shost->rcu, ...) */
	rcu_barrier();

	if (shost->tmf_work_q)
		destroy_workqueue(shost->tmf_work_q);
	if (shost->ehandler)
		kthread_stop(shost->ehandler);
	if (shost->work_q)
		destroy_workqueue(shost->work_q);

	if (shost->shost_state == SHOST_CREATED) {
		/*
		 * Free the shost_dev device name here if scsi_host_alloc()
		 * and scsi_host_put() have been called but neither
		 * scsi_host_add() nor scsi_host_remove() has been called.
		 * This avoids that the memory allocated for the shost_dev
		 * name is leaked.
		 */
		kfree(dev_name(&shost->shost_dev));
	}

	if (shost_use_blk_mq(shost)) {
		if (shost->tag_set.tags)
			scsi_mq_destroy_tags(shost);
	} else {
		if (shost->bqt)
			blk_free_tags(shost->bqt);
	}

	kfree(shost->shost_data);

	ida_simple_remove(&host_index_ida, shost->host_no);

	if (parent)
		put_device(parent);
	kfree(shost);
}

struct Scsi_Host *scsi_host_alloc(struct scsi_host_template *sht, int privsize)
{
	struct Scsi_Host *shost;
	gfp_t gfp_mask = GFP_KERNEL;
	int index;

	if (sht->unchecked_isa_dma && privsize)
		gfp_mask |= __GFP_DMA;

	shost = kzalloc(sizeof(struct Scsi_Host) + privsize, gfp_mask);
	if (!shost)
		return NULL;

	shost->host_lock = &shost->default_lock;
	spin_lock_init(shost->host_lock);
	shost->shost_state = SHOST_CREATED;
	INIT_LIST_HEAD(&shost->__devices);
	INIT_LIST_HEAD(&shost->__targets);
	INIT_LIST_HEAD(&shost->eh_cmd_q);
	INIT_LIST_HEAD(&shost->starved_list);
	init_waitqueue_head(&shost->host_wait);
	mutex_init(&shost->scan_mutex);

	index = ida_simple_get(&host_index_ida, 0, 0, GFP_KERNEL);
	if (index < 0)
		goto fail_kfree;
	shost->host_no = index;

	shost->dma_channel = 0xff;

	/* These three are default values which can be overridden */
	shost->max_channel = 0;
	shost->max_id = 8;
	shost->max_lun = 8;

	/* Give each shost a default transportt */
	shost->transportt = &blank_transport_template;

	/*
	 * All drivers right now should be able to handle 12 byte
	 * commands.  Every so often there are requests for 16 byte
	 * commands, but individual low-level drivers need to certify that
	 * they actually do something sensible with such commands.
	 */
	shost->max_cmd_len = 12;
	shost->hostt = sht;
	shost->this_id = sht->this_id;
	shost->can_queue = sht->can_queue;
	shost->sg_tablesize = sht->sg_tablesize;
	shost->sg_prot_tablesize = sht->sg_prot_tablesize;
	shost->cmd_per_lun = sht->cmd_per_lun;
	shost->unchecked_isa_dma = sht->unchecked_isa_dma;
	shost->use_clustering = sht->use_clustering;
	shost->no_write_same = sht->no_write_same;

	if (shost_eh_deadline == -1 || !sht->eh_host_reset_handler)
		shost->eh_deadline = -1;
	else if ((ulong) shost_eh_deadline * HZ > INT_MAX) {
		shost_printk(KERN_WARNING, shost,
			     "eh_deadline %u too large, setting to %u\n",
			     shost_eh_deadline, INT_MAX / HZ);
		shost->eh_deadline = INT_MAX;
	} else
		shost->eh_deadline = shost_eh_deadline * HZ;

	if (sht->supported_mode == MODE_UNKNOWN)
		/* means we didn't set it ... default to INITIATOR */
		shost->active_mode = MODE_INITIATOR;
	else
		shost->active_mode = sht->supported_mode;

	if (sht->max_host_blocked)
		shost->max_host_blocked = sht->max_host_blocked;
	else
		shost->max_host_blocked = SCSI_DEFAULT_HOST_BLOCKED;

	/*
	 * If the driver imposes no hard sector transfer limit, start at
	 * machine infinity initially.
	 */
	if (sht->max_sectors)
		shost->max_sectors = sht->max_sectors;
	else
		shost->max_sectors = SCSI_DEFAULT_MAX_SECTORS;

	/*
	 * assume a 4GB boundary, if not set
	 */
	if (sht->dma_boundary)
		shost->dma_boundary = sht->dma_boundary;
	else
		shost->dma_boundary = 0xffffffff;

	shost->use_blk_mq = scsi_use_blk_mq || shost->hostt->force_blk_mq;

	device_initialize(&shost->shost_gendev);
	dev_set_name(&shost->shost_gendev, "host%d", shost->host_no);
	shost->shost_gendev.bus = &scsi_bus_type;
	shost->shost_gendev.type = &scsi_host_type;

	device_initialize(&shost->shost_dev);
	shost->shost_dev.parent = &shost->shost_gendev;
	shost->shost_dev.class = &shost_class;
	dev_set_name(&shost->shost_dev, "host%d", shost->host_no);
	shost->shost_dev.groups = scsi_sysfs_shost_attr_groups;

	shost->ehandler = kthread_run(scsi_error_handler, shost,
			"scsi_eh_%d", shost->host_no);
	if (IS_ERR(shost->ehandler)) {
		shost_printk(KERN_WARNING, shost,
			"error handler thread failed to spawn, error = %ld\n",
			PTR_ERR(shost->ehandler));
		goto fail_index_remove;
	}

	shost->tmf_work_q = alloc_workqueue("scsi_tmf_%d",
					    WQ_UNBOUND | WQ_MEM_RECLAIM,
					   1, shost->host_no);
	if (!shost->tmf_work_q) {
		shost_printk(KERN_WARNING, shost,
			     "failed to create tmf workq\n");
		goto fail_kthread;
	}
	scsi_proc_hostdir_add(shost->hostt);
	return shost;

 fail_kthread:
	kthread_stop(shost->ehandler);
 fail_index_remove:
	ida_simple_remove(&host_index_ida, shost->host_no);
 fail_kfree:
	kfree(shost);
	return NULL;
}

__attribute__((used)) static int __scsi_host_match(struct device *dev, const void *data)
{
	struct Scsi_Host *p;
	const unsigned short *hostnum = data;

	p = class_to_shost(dev);
	return p->host_no == *hostnum;
}

struct Scsi_Host *scsi_host_lookup(unsigned short hostnum)
{
	struct device *cdev;
	struct Scsi_Host *shost = NULL;

	cdev = class_find_device(&shost_class, NULL, &hostnum,
				 __scsi_host_match);
	if (cdev) {
		shost = scsi_host_get(class_to_shost(cdev));
		put_device(cdev);
	}
	return shost;
}

struct Scsi_Host *scsi_host_get(struct Scsi_Host *shost)
{
	if ((shost->shost_state == SHOST_DEL) ||
		!get_device(&shost->shost_gendev))
		return NULL;
	return shost;
}

int scsi_host_busy(struct Scsi_Host *shost)
{
	return atomic_read(&shost->host_busy);
}

void scsi_host_put(struct Scsi_Host *shost)
{
	put_device(&shost->shost_gendev);
}

int scsi_init_hosts(void)
{
	return class_register(&shost_class);
}

void scsi_exit_hosts(void)
{
	class_unregister(&shost_class);
	ida_destroy(&host_index_ida);
}

int scsi_is_host_device(const struct device *dev)
{
	return dev->type == &scsi_host_type;
}

int scsi_queue_work(struct Scsi_Host *shost, struct work_struct *work)
{
	if (unlikely(!shost->work_q)) {
		shost_printk(KERN_ERR, shost,
			"ERROR: Scsi host '%s' attempted to queue scsi-work, "
			"when no workqueue created.\n", shost->hostt->name);
		dump_stack();

		return -EINVAL;
	}

	return queue_work(shost->work_q, work);
}

void scsi_flush_work(struct Scsi_Host *shost)
{
	if (!shost->work_q) {
		shost_printk(KERN_ERR, shost,
			"ERROR: Scsi host '%s' attempted to flush scsi-work, "
			"when no workqueue created.\n", shost->hostt->name);
		dump_stack();
		return;
	}

	flush_workqueue(shost->work_q);
}

