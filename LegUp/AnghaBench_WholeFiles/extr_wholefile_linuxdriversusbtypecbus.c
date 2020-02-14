#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct typec_device_id {scalar_t__ svid; scalar_t__ mode; } ;
struct TYPE_9__ {int /*<<< orphan*/ * bus; struct module* owner; } ;
struct typec_altmode_driver {int (* probe ) (struct typec_altmode const*) ;int /*<<< orphan*/  (* remove ) (struct typec_altmode const*) ;struct typec_device_id* id_table; TYPE_4__ driver; } ;
struct device {struct device_driver* driver; int /*<<< orphan*/  kobj; int /*<<< orphan*/  parent; } ;
typedef  struct typec_altmode {scalar_t__ svid; scalar_t__ mode; char* desc; TYPE_2__* ops; scalar_t__ active; struct device dev; } const typec_altmode ;
struct module {int dummy; } ;
struct kobj_uevent_env {int dummy; } ;
struct device_driver {int dummy; } ;
struct device_attribute {int dummy; } ;
struct altmode {struct altmode* partner; struct typec_altmode const adev; TYPE_1__** plug; int /*<<< orphan*/  nh; TYPE_3__* mux; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  enum typec_plug_index { ____Placeholder_typec_plug_index } typec_plug_index ;
struct TYPE_8__ {int (* set ) (TYPE_3__*,scalar_t__) ;} ;
struct TYPE_7__ {int (* notify ) (struct typec_altmode const*,unsigned long,void*) ;int (* enter ) (struct typec_altmode const*) ;int (* exit ) (struct typec_altmode const*) ;int (* vdm ) (struct typec_altmode const*,int /*<<< orphan*/  const,int /*<<< orphan*/  const*,int) ;int /*<<< orphan*/  (* attention ) (struct typec_altmode const*,int /*<<< orphan*/ ) ;} ;
struct TYPE_6__ {struct typec_altmode const adev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 scalar_t__ TYPEC_ANY_MODE ; 
 int TYPEC_STATE_SAFE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int add_uevent_var (struct kobj_uevent_env*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int driver_register (TYPE_4__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_4__*) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int is_typec_port (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 int stub1 (TYPE_3__*,scalar_t__) ; 
 int stub2 (struct typec_altmode const*,unsigned long,void*) ; 
 int stub3 (struct typec_altmode const*) ; 
 int stub4 (struct typec_altmode const*) ; 
 int /*<<< orphan*/  stub5 (struct typec_altmode const*,int /*<<< orphan*/ ) ; 
 int stub6 (struct typec_altmode const*,int /*<<< orphan*/  const,int /*<<< orphan*/  const*,int) ; 
 int stub7 (struct typec_altmode const*) ; 
 int /*<<< orphan*/  stub8 (struct typec_altmode const*) ; 
 int sysfs_create_link (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sysfs_remove_link (int /*<<< orphan*/ *,char*) ; 
 struct altmode* to_altmode (struct typec_altmode const*) ; 
 struct typec_altmode_driver* to_altmode_driver (struct device_driver*) ; 
 struct typec_altmode const* to_typec_altmode (struct device*) ; 
 int /*<<< orphan*/  typec_altmode_update_active (struct typec_altmode const*,int) ; 
 int /*<<< orphan*/  typec_bus ; 

__attribute__((used)) static inline int typec_altmode_set_mux(struct altmode *alt, u8 state)
{
	return alt->mux ? alt->mux->set(alt->mux, state) : 0;
}

__attribute__((used)) static int typec_altmode_set_state(struct typec_altmode *adev, int state)
{
	bool is_port = is_typec_port(adev->dev.parent);
	struct altmode *port_altmode;
	int ret;

	port_altmode = is_port ? to_altmode(adev) : to_altmode(adev)->partner;

	ret = typec_altmode_set_mux(port_altmode, state);
	if (ret)
		return ret;

	blocking_notifier_call_chain(&port_altmode->nh, state, NULL);

	return 0;
}

int typec_altmode_notify(struct typec_altmode *adev,
			 unsigned long conf, void *data)
{
	bool is_port;
	struct altmode *altmode;
	struct altmode *partner;
	int ret;

	if (!adev)
		return 0;

	altmode = to_altmode(adev);

	if (!altmode->partner)
		return -ENODEV;

	is_port = is_typec_port(adev->dev.parent);
	partner = altmode->partner;

	ret = typec_altmode_set_mux(is_port ? altmode : partner, (u8)conf);
	if (ret)
		return ret;

	blocking_notifier_call_chain(is_port ? &altmode->nh : &partner->nh,
				     conf, data);

	if (partner->adev.ops && partner->adev.ops->notify)
		return partner->adev.ops->notify(&partner->adev, conf, data);

	return 0;
}

int typec_altmode_enter(struct typec_altmode *adev)
{
	struct altmode *partner = to_altmode(adev)->partner;
	struct typec_altmode *pdev = &partner->adev;
	int ret;

	if (!adev || adev->active)
		return 0;

	if (!pdev->ops || !pdev->ops->enter)
		return -EOPNOTSUPP;

	/* Moving to USB Safe State */
	ret = typec_altmode_set_state(adev, TYPEC_STATE_SAFE);
	if (ret)
		return ret;

	/* Enter Mode */
	return pdev->ops->enter(pdev);
}

int typec_altmode_exit(struct typec_altmode *adev)
{
	struct altmode *partner = to_altmode(adev)->partner;
	struct typec_altmode *pdev = &partner->adev;
	int ret;

	if (!adev || !adev->active)
		return 0;

	if (!pdev->ops || !pdev->ops->enter)
		return -EOPNOTSUPP;

	/* Moving to USB Safe State */
	ret = typec_altmode_set_state(adev, TYPEC_STATE_SAFE);
	if (ret)
		return ret;

	/* Exit Mode command */
	return pdev->ops->exit(pdev);
}

void typec_altmode_attention(struct typec_altmode *adev, u32 vdo)
{
	struct typec_altmode *pdev = &to_altmode(adev)->partner->adev;

	if (pdev->ops && pdev->ops->attention)
		pdev->ops->attention(pdev, vdo);
}

int typec_altmode_vdm(struct typec_altmode *adev,
		      const u32 header, const u32 *vdo, int count)
{
	struct typec_altmode *pdev;
	struct altmode *altmode;

	if (!adev)
		return 0;

	altmode = to_altmode(adev);

	if (!altmode->partner)
		return -ENODEV;

	pdev = &altmode->partner->adev;

	if (!pdev->ops || !pdev->ops->vdm)
		return -EOPNOTSUPP;

	return pdev->ops->vdm(pdev, header, vdo, count);
}

const struct typec_altmode *
typec_altmode_get_partner(struct typec_altmode *adev)
{
	return &to_altmode(adev)->partner->adev;
}

struct typec_altmode *typec_altmode_get_plug(struct typec_altmode *adev,
					     enum typec_plug_index index)
{
	struct altmode *port = to_altmode(adev)->partner;

	if (port->plug[index]) {
		get_device(&port->plug[index]->adev.dev);
		return &port->plug[index]->adev;
	}

	return NULL;
}

void typec_altmode_put_plug(struct typec_altmode *plug)
{
	if (plug)
		put_device(&plug->dev);
}

int __typec_altmode_register_driver(struct typec_altmode_driver *drv,
				    struct module *module)
{
	if (!drv->probe)
		return -EINVAL;

	drv->driver.owner = module;
	drv->driver.bus = &typec_bus;

	return driver_register(&drv->driver);
}

void typec_altmode_unregister_driver(struct typec_altmode_driver *drv)
{
	driver_unregister(&drv->driver);
}

struct typec_altmode *typec_match_altmode(struct typec_altmode **altmodes,
					  size_t n, u16 svid, u8 mode)
{
	int i;

	for (i = 0; i < n; i++) {
		if (!altmodes[i])
			break;
		if (altmodes[i]->svid == svid && altmodes[i]->mode == mode)
			return altmodes[i];
	}

	return NULL;
}

__attribute__((used)) static ssize_t
description_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct typec_altmode *alt = to_typec_altmode(dev);

	return sprintf(buf, "%s\n", alt->desc ? alt->desc : "");
}

__attribute__((used)) static int typec_match(struct device *dev, struct device_driver *driver)
{
	struct typec_altmode_driver *drv = to_altmode_driver(driver);
	struct typec_altmode *altmode = to_typec_altmode(dev);
	const struct typec_device_id *id;

	for (id = drv->id_table; id->svid; id++)
		if (id->svid == altmode->svid &&
		    (id->mode == TYPEC_ANY_MODE || id->mode == altmode->mode))
			return 1;
	return 0;
}

__attribute__((used)) static int typec_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	struct typec_altmode *altmode = to_typec_altmode(dev);

	if (add_uevent_var(env, "SVID=%04X", altmode->svid))
		return -ENOMEM;

	if (add_uevent_var(env, "MODE=%u", altmode->mode))
		return -ENOMEM;

	return add_uevent_var(env, "MODALIAS=typec:id%04Xm%02X",
			      altmode->svid, altmode->mode);
}

__attribute__((used)) static int typec_altmode_create_links(struct altmode *alt)
{
	struct device *port_dev = &alt->partner->adev.dev;
	struct device *dev = &alt->adev.dev;
	int err;

	err = sysfs_create_link(&dev->kobj, &port_dev->kobj, "port");
	if (err)
		return err;

	err = sysfs_create_link(&port_dev->kobj, &dev->kobj, "partner");
	if (err)
		sysfs_remove_link(&dev->kobj, "port");

	return err;
}

__attribute__((used)) static void typec_altmode_remove_links(struct altmode *alt)
{
	sysfs_remove_link(&alt->partner->adev.dev.kobj, "partner");
	sysfs_remove_link(&alt->adev.dev.kobj, "port");
}

__attribute__((used)) static int typec_probe(struct device *dev)
{
	struct typec_altmode_driver *drv = to_altmode_driver(dev->driver);
	struct typec_altmode *adev = to_typec_altmode(dev);
	struct altmode *altmode = to_altmode(adev);
	int ret;

	/* Fail if the port does not support the alternate mode */
	if (!altmode->partner)
		return -ENODEV;

	ret = typec_altmode_create_links(altmode);
	if (ret) {
		dev_warn(dev, "failed to create symlinks\n");
		return ret;
	}

	ret = drv->probe(adev);
	if (ret)
		typec_altmode_remove_links(altmode);

	return ret;
}

__attribute__((used)) static int typec_remove(struct device *dev)
{
	struct typec_altmode_driver *drv = to_altmode_driver(dev->driver);
	struct typec_altmode *adev = to_typec_altmode(dev);
	struct altmode *altmode = to_altmode(adev);

	typec_altmode_remove_links(altmode);

	if (drv->remove)
		drv->remove(to_typec_altmode(dev));

	if (adev->active) {
		WARN_ON(typec_altmode_set_state(adev, TYPEC_STATE_SAFE));
		typec_altmode_update_active(adev, false);
	}

	adev->desc = NULL;
	adev->ops = NULL;

	return 0;
}

