#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_7__ {TYPE_1__ dev; int /*<<< orphan*/  mutex; } ;
typedef  struct uwb_rc {scalar_t__ ready; int /*<<< orphan*/  pals; TYPE_3__ uwb_dev; } const uwb_rc ;
struct uwb_pal {char* name; TYPE_2__* device; int /*<<< orphan*/  debugfs_dir; int /*<<< orphan*/  node; struct uwb_rc const* rc; } ;
struct uwb_dev {int /*<<< orphan*/  dev; } ;
struct uwb_beca_e {int /*<<< orphan*/  refcnt; } ;
struct device {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 struct device* class_find_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct uwb_rc const*,int (*) (struct device*,void const*)) ; 
 int /*<<< orphan*/  debugfs_remove (int /*<<< orphan*/ ) ; 
 struct uwb_rc const* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  device_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int sysfs_create_link (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sysfs_remove_link (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uwb_bce_kfree ; 
 int /*<<< orphan*/  uwb_dbg_create_pal_dir (struct uwb_pal*) ; 
 int /*<<< orphan*/  uwb_dev_get (TYPE_3__*) ; 
 int /*<<< orphan*/  uwb_dev_put (TYPE_3__*) ; 
 int /*<<< orphan*/  uwb_radio_stop (struct uwb_pal*) ; 
 int /*<<< orphan*/  uwb_rc_class ; 

__attribute__((used)) static inline struct uwb_rc *__uwb_rc_get(struct uwb_rc *rc)
{
	uwb_dev_get(&rc->uwb_dev);
	return rc;
}

__attribute__((used)) static inline void __uwb_rc_put(struct uwb_rc *rc)
{
	if (rc)
		uwb_dev_put(&rc->uwb_dev);
}

__attribute__((used)) static inline void uwb_bce_get(struct uwb_beca_e *bce)
{
	kref_get(&bce->refcnt);
}

__attribute__((used)) static inline void uwb_bce_put(struct uwb_beca_e *bce)
{
	kref_put(&bce->refcnt, uwb_bce_kfree);
}

__attribute__((used)) static inline void uwb_dev_lock(struct uwb_dev *uwb_dev)
{
	device_lock(&uwb_dev->dev);
}

__attribute__((used)) static inline void uwb_dev_unlock(struct uwb_dev *uwb_dev)
{
	device_unlock(&uwb_dev->dev);
}

void uwb_pal_init(struct uwb_pal *pal)
{
	INIT_LIST_HEAD(&pal->node);
}

int uwb_pal_register(struct uwb_pal *pal)
{
	struct uwb_rc *rc = pal->rc;
	int ret;

	if (pal->device) {
		/* create a link to the uwb_rc in the PAL device's directory. */
		ret = sysfs_create_link(&pal->device->kobj,
					&rc->uwb_dev.dev.kobj, "uwb_rc");
		if (ret < 0)
			return ret;
		/* create a link to the PAL in the UWB device's directory. */
		ret = sysfs_create_link(&rc->uwb_dev.dev.kobj,
					&pal->device->kobj, pal->name);
		if (ret < 0) {
			sysfs_remove_link(&pal->device->kobj, "uwb_rc");
			return ret;
		}
	}

	pal->debugfs_dir = uwb_dbg_create_pal_dir(pal);

	mutex_lock(&rc->uwb_dev.mutex);
	list_add(&pal->node, &rc->pals);
	mutex_unlock(&rc->uwb_dev.mutex);

	return 0;
}

__attribute__((used)) static int find_rc(struct device *dev, const void *data)
{
	const struct uwb_rc *target_rc = data;
	struct uwb_rc *rc = dev_get_drvdata(dev);

	if (rc == NULL) {
		WARN_ON(1);
		return 0;
	}
	if (rc == target_rc) {
		if (rc->ready == 0)
			return 0;
		else
			return 1;
	}
	return 0;
}

__attribute__((used)) static bool uwb_rc_class_device_exists(struct uwb_rc *target_rc)
{
	struct device *dev;

	dev = class_find_device(&uwb_rc_class, NULL, target_rc,	find_rc);

	put_device(dev);

	return (dev != NULL);
}

void uwb_pal_unregister(struct uwb_pal *pal)
{
	struct uwb_rc *rc = pal->rc;

	uwb_radio_stop(pal);

	mutex_lock(&rc->uwb_dev.mutex);
	list_del(&pal->node);
	mutex_unlock(&rc->uwb_dev.mutex);

	debugfs_remove(pal->debugfs_dir);

	if (pal->device) {
		/* remove link to the PAL in the UWB device's directory. */
		if (uwb_rc_class_device_exists(rc))
			sysfs_remove_link(&rc->uwb_dev.dev.kobj, pal->name);

		/* remove link to uwb_rc in the PAL device's directory. */
		sysfs_remove_link(&pal->device->kobj, "uwb_rc");
	}
}

void uwb_rc_pal_init(struct uwb_rc *rc)
{
	INIT_LIST_HEAD(&rc->pals);
}

