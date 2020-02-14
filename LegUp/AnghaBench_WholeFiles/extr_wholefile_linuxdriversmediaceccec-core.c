#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct device {TYPE_1__* driver; } ;
struct cec_devnode {int /*<<< orphan*/  minor; int /*<<< orphan*/  dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  registered; } ;
struct TYPE_7__ {struct device* parent; } ;
struct TYPE_8__ {TYPE_3__ dev; } ;
struct cec_adapter {TYPE_2__* ops; scalar_t__ kthread_config; scalar_t__ kthread; int /*<<< orphan*/  cec_dir; TYPE_4__ devnode; int /*<<< orphan*/  owner; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* adap_free ) (struct cec_adapter*) ;} ;
struct TYPE_5__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENXIO ; 
 scalar_t__ IS_ERR_OR_NULL (struct cec_adapter*) ; 
 scalar_t__ WARN_ON (int) ; 
 void cec_delete_adapter (struct cec_adapter*) ; 
 int /*<<< orphan*/  cec_devnode_lock ; 
 int /*<<< orphan*/  cec_devnode_nums ; 
 int cec_devnode_register (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cec_devnode_unregister (struct cec_adapter*) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_3__*,struct cec_adapter*) ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct cec_adapter*) ; 
 int /*<<< orphan*/  kthread_stop (scalar_t__) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct cec_adapter*) ; 
 struct cec_adapter* to_cec_adapter (struct cec_devnode*) ; 
 struct cec_devnode* to_cec_devnode (struct device*) ; 

int cec_get_device(struct cec_devnode *devnode)
{
	/*
	 * Check if the cec device is available. This needs to be done with
	 * the devnode->lock held to prevent an open/unregister race:
	 * without the lock, the device could be unregistered and freed between
	 * the devnode->registered check and get_device() calls, leading to
	 * a crash.
	 */
	mutex_lock(&devnode->lock);
	/*
	 * return ENXIO if the cec device has been removed
	 * already or if it is not registered anymore.
	 */
	if (!devnode->registered) {
		mutex_unlock(&devnode->lock);
		return -ENXIO;
	}
	/* and increase the device refcount */
	get_device(&devnode->dev);
	mutex_unlock(&devnode->lock);
	return 0;
}

void cec_put_device(struct cec_devnode *devnode)
{
	put_device(&devnode->dev);
}

__attribute__((used)) static void cec_devnode_release(struct device *cd)
{
	struct cec_devnode *devnode = to_cec_devnode(cd);

	mutex_lock(&cec_devnode_lock);
	/* Mark device node number as free */
	clear_bit(devnode->minor, cec_devnode_nums);
	mutex_unlock(&cec_devnode_lock);

	cec_delete_adapter(to_cec_adapter(devnode));
}

int cec_register_adapter(struct cec_adapter *adap,
			 struct device *parent)
{
	int res;

	if (IS_ERR_OR_NULL(adap))
		return 0;

	if (WARN_ON(!parent))
		return -EINVAL;

	adap->owner = parent->driver->owner;
	adap->devnode.dev.parent = parent;

#ifdef CONFIG_MEDIA_CEC_RC
	if (adap->capabilities & CEC_CAP_RC) {
		adap->rc->dev.parent = parent;
		res = rc_register_device(adap->rc);

		if (res) {
			pr_err("cec-%s: failed to prepare input device\n",
			       adap->name);
			rc_free_device(adap->rc);
			adap->rc = NULL;
			return res;
		}
	}
#endif

	res = cec_devnode_register(&adap->devnode, adap->owner);
	if (res) {
#ifdef CONFIG_MEDIA_CEC_RC
		/* Note: rc_unregister also calls rc_free */
		rc_unregister_device(adap->rc);
		adap->rc = NULL;
#endif
		return res;
	}

	dev_set_drvdata(&adap->devnode.dev, adap);
#ifdef CONFIG_DEBUG_FS
	if (!top_cec_dir)
		return 0;

	adap->cec_dir = debugfs_create_dir(dev_name(&adap->devnode.dev), top_cec_dir);
	if (IS_ERR_OR_NULL(adap->cec_dir)) {
		pr_warn("cec-%s: Failed to create debugfs dir\n", adap->name);
		return 0;
	}
	adap->status_file = debugfs_create_devm_seqfile(&adap->devnode.dev,
		"status", adap->cec_dir, cec_adap_status);
	if (IS_ERR_OR_NULL(adap->status_file)) {
		pr_warn("cec-%s: Failed to create status file\n", adap->name);
		debugfs_remove_recursive(adap->cec_dir);
		adap->cec_dir = NULL;
		return 0;
	}
	if (!adap->ops->error_inj_show || !adap->ops->error_inj_parse_line)
		return 0;
	adap->error_inj_file = debugfs_create_file("error-inj", 0644,
						   adap->cec_dir, adap,
						   &cec_error_inj_fops);
	if (IS_ERR_OR_NULL(adap->error_inj_file))
		pr_warn("cec-%s: Failed to create error-inj file\n",
			adap->name);
#endif
	return 0;
}

void cec_unregister_adapter(struct cec_adapter *adap)
{
	if (IS_ERR_OR_NULL(adap))
		return;

#ifdef CONFIG_MEDIA_CEC_RC
	/* Note: rc_unregister also calls rc_free */
	rc_unregister_device(adap->rc);
	adap->rc = NULL;
#endif
	debugfs_remove_recursive(adap->cec_dir);
#ifdef CONFIG_CEC_NOTIFIER
	if (adap->notifier)
		cec_notifier_unregister(adap->notifier);
#endif
	cec_devnode_unregister(adap);
}

void cec_delete_adapter(struct cec_adapter *adap)
{
	if (IS_ERR_OR_NULL(adap))
		return;
	kthread_stop(adap->kthread);
	if (adap->kthread_config)
		kthread_stop(adap->kthread_config);
	if (adap->ops->adap_free)
		adap->ops->adap_free(adap);
#ifdef CONFIG_MEDIA_CEC_RC
	rc_free_device(adap->rc);
#endif
	kfree(adap);
}

