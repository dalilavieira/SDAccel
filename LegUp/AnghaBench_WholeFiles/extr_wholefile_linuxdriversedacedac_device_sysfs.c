#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct mem_ctl_info {int dummy; } ;
struct kobject {int /*<<< orphan*/  parent; } ;
struct instance_attribute {size_t (* show ) (struct edac_device_instance*,char*) ;size_t (* store ) (struct edac_device_instance*,char const*,size_t) ;} ;
struct file_operations {int dummy; } ;
struct TYPE_9__ {int ue_count; int ce_count; } ;
struct edac_device_instance {int nr_blocks; struct kobject kobj; struct edac_device_block* blocks; int /*<<< orphan*/  name; struct edac_device_ctl_info* ctl; TYPE_2__ counters; } ;
struct edac_device_ctl_info {int log_ue; int log_ce; int panic_on_ue; int poll_msec; int nr_instances; struct kobject kobj; int /*<<< orphan*/  dev_idx; TYPE_7__* dev; struct edac_dev_sysfs_attribute* sysfs_attributes; struct edac_device_instance* instances; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; struct bus_type* edac_subsys; } ;
struct TYPE_10__ {int ue_count; int ce_count; } ;
struct edac_device_block {int nr_attribs; struct kobject kobj; struct edac_dev_sysfs_block_attribute* block_attributes; int /*<<< orphan*/  name; TYPE_5__* instance; TYPE_3__ counters; } ;
struct attribute {int /*<<< orphan*/  name; } ;
struct edac_dev_sysfs_block_attribute {size_t (* show ) (struct kobject*,struct attribute*,char*) ;size_t (* store ) (struct kobject*,struct attribute*,char const*,size_t) ;struct attribute attr; } ;
struct TYPE_13__ {int /*<<< orphan*/ * name; } ;
struct edac_dev_sysfs_attribute {TYPE_6__ attr; } ;
struct dentry {int dummy; } ;
struct ctl_info_attribute {size_t (* show ) (struct edac_device_ctl_info*,char*) ;size_t (* store ) (struct edac_device_ctl_info*,char const*,size_t) ;} ;
struct bus_type {TYPE_1__* dev_root; } ;
typedef  size_t ssize_t ;
struct TYPE_14__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_12__ {TYPE_4__* ctl; } ;
struct TYPE_11__ {struct kobject kobj; } ;
struct TYPE_8__ {struct kobject kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  EDAC_DEVICE_SYMLINK ; 
 size_t EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  KOBJ_ADD ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  edac_dbg (int,char*,...) ; 
 int /*<<< orphan*/  edac_device_reset_delay_period (struct edac_device_ctl_info*,unsigned long) ; 
 struct bus_type* edac_get_sysfs_subsys () ; 
 int /*<<< orphan*/  kfree (struct edac_device_ctl_info*) ; 
 struct kobject* kobject_get (struct kobject*) ; 
 int kobject_init_and_add (struct kobject*,int /*<<< orphan*/ *,struct kobject*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kobject_name (struct kobject*) ; 
 int /*<<< orphan*/  kobject_put (struct kobject*) ; 
 int /*<<< orphan*/  kobject_uevent (struct kobject*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktype_block_ctrl ; 
 int /*<<< orphan*/  ktype_device_ctrl ; 
 int /*<<< orphan*/  ktype_instance_ctrl ; 
 int /*<<< orphan*/  memset (struct kobject*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ simple_strtoul (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 size_t sprintf (char*,char*,int) ; 
 size_t stub1 (struct edac_device_ctl_info*,char*) ; 
 size_t stub2 (struct edac_device_ctl_info*,char const*,size_t) ; 
 size_t stub3 (struct edac_device_instance*,char*) ; 
 size_t stub4 (struct edac_device_instance*,char const*,size_t) ; 
 size_t stub5 (struct kobject*,struct attribute*,char*) ; 
 size_t stub6 (struct kobject*,struct attribute*,char const*,size_t) ; 
 int sysfs_create_file (struct kobject*,struct attribute*) ; 
 int sysfs_create_link (struct kobject*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysfs_remove_file (struct kobject*,struct attribute*) ; 
 int /*<<< orphan*/  sysfs_remove_link (struct kobject*,int /*<<< orphan*/ ) ; 
 struct edac_device_block* to_block (struct kobject*) ; 
 struct edac_dev_sysfs_block_attribute* to_block_attr (struct attribute*) ; 
 struct edac_device_ctl_info* to_ctl_info (struct kobject*) ; 
 struct ctl_info_attribute* to_ctl_info_attr (struct attribute*) ; 
 struct edac_device_ctl_info* to_edacdev (struct kobject*) ; 
 struct edac_device_instance* to_instance (struct kobject*) ; 
 struct instance_attribute* to_instance_attr (struct attribute*) ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

__attribute__((used)) static ssize_t edac_device_ctl_log_ue_show(struct edac_device_ctl_info
					*ctl_info, char *data)
{
	return sprintf(data, "%u\n", ctl_info->log_ue);
}

__attribute__((used)) static ssize_t edac_device_ctl_log_ue_store(struct edac_device_ctl_info
					*ctl_info, const char *data,
					size_t count)
{
	/* if parameter is zero, turn off flag, if non-zero turn on flag */
	ctl_info->log_ue = (simple_strtoul(data, NULL, 0) != 0);

	return count;
}

__attribute__((used)) static ssize_t edac_device_ctl_log_ce_show(struct edac_device_ctl_info
					*ctl_info, char *data)
{
	return sprintf(data, "%u\n", ctl_info->log_ce);
}

__attribute__((used)) static ssize_t edac_device_ctl_log_ce_store(struct edac_device_ctl_info
					*ctl_info, const char *data,
					size_t count)
{
	/* if parameter is zero, turn off flag, if non-zero turn on flag */
	ctl_info->log_ce = (simple_strtoul(data, NULL, 0) != 0);

	return count;
}

__attribute__((used)) static ssize_t edac_device_ctl_panic_on_ue_show(struct edac_device_ctl_info
						*ctl_info, char *data)
{
	return sprintf(data, "%u\n", ctl_info->panic_on_ue);
}

__attribute__((used)) static ssize_t edac_device_ctl_panic_on_ue_store(struct edac_device_ctl_info
						 *ctl_info, const char *data,
						 size_t count)
{
	/* if parameter is zero, turn off flag, if non-zero turn on flag */
	ctl_info->panic_on_ue = (simple_strtoul(data, NULL, 0) != 0);

	return count;
}

__attribute__((used)) static ssize_t edac_device_ctl_poll_msec_show(struct edac_device_ctl_info
					*ctl_info, char *data)
{
	return sprintf(data, "%u\n", ctl_info->poll_msec);
}

__attribute__((used)) static ssize_t edac_device_ctl_poll_msec_store(struct edac_device_ctl_info
					*ctl_info, const char *data,
					size_t count)
{
	unsigned long value;

	/* get the value and enforce that it is non-zero, must be at least
	 * one millisecond for the delay period, between scans
	 * Then cancel last outstanding delay for the work request
	 * and set a new one.
	 */
	value = simple_strtoul(data, NULL, 0);
	edac_device_reset_delay_period(ctl_info, value);

	return count;
}

__attribute__((used)) static ssize_t edac_dev_ctl_info_show(struct kobject *kobj,
				struct attribute *attr, char *buffer)
{
	struct edac_device_ctl_info *edac_dev = to_ctl_info(kobj);
	struct ctl_info_attribute *ctl_info_attr = to_ctl_info_attr(attr);

	if (ctl_info_attr->show)
		return ctl_info_attr->show(edac_dev, buffer);
	return -EIO;
}

__attribute__((used)) static ssize_t edac_dev_ctl_info_store(struct kobject *kobj,
				struct attribute *attr,
				const char *buffer, size_t count)
{
	struct edac_device_ctl_info *edac_dev = to_ctl_info(kobj);
	struct ctl_info_attribute *ctl_info_attr = to_ctl_info_attr(attr);

	if (ctl_info_attr->store)
		return ctl_info_attr->store(edac_dev, buffer, count);
	return -EIO;
}

__attribute__((used)) static void edac_device_ctrl_master_release(struct kobject *kobj)
{
	struct edac_device_ctl_info *edac_dev = to_edacdev(kobj);

	edac_dbg(4, "control index=%d\n", edac_dev->dev_idx);

	/* decrement the EDAC CORE module ref count */
	module_put(edac_dev->owner);

	/* free the control struct containing the 'main' kobj
	 * passed in to this routine
	 */
	kfree(edac_dev);
}

int edac_device_register_sysfs_main_kobj(struct edac_device_ctl_info *edac_dev)
{
	struct bus_type *edac_subsys;
	int err;

	edac_dbg(1, "\n");

	/* get the /sys/devices/system/edac reference */
	edac_subsys = edac_get_sysfs_subsys();

	/* Point to the 'edac_subsys' this instance 'reports' to */
	edac_dev->edac_subsys = edac_subsys;

	/* Init the devices's kobject */
	memset(&edac_dev->kobj, 0, sizeof(struct kobject));

	/* Record which module 'owns' this control structure
	 * and bump the ref count of the module
	 */
	edac_dev->owner = THIS_MODULE;

	if (!try_module_get(edac_dev->owner)) {
		err = -ENODEV;
		goto err_out;
	}

	/* register */
	err = kobject_init_and_add(&edac_dev->kobj, &ktype_device_ctrl,
				   &edac_subsys->dev_root->kobj,
				   "%s", edac_dev->name);
	if (err) {
		edac_dbg(1, "Failed to register '.../edac/%s'\n",
			 edac_dev->name);
		goto err_kobj_reg;
	}
	kobject_uevent(&edac_dev->kobj, KOBJ_ADD);

	/* At this point, to 'free' the control struct,
	 * edac_device_unregister_sysfs_main_kobj() must be used
	 */

	edac_dbg(4, "Registered '.../edac/%s' kobject\n", edac_dev->name);

	return 0;

	/* Error exit stack */
err_kobj_reg:
	module_put(edac_dev->owner);

err_out:
	return err;
}

void edac_device_unregister_sysfs_main_kobj(struct edac_device_ctl_info *dev)
{
	edac_dbg(0, "\n");
	edac_dbg(4, "name of kobject is: %s\n", kobject_name(&dev->kobj));

	/*
	 * Unregister the edac device's kobject and
	 * allow for reference count to reach 0 at which point
	 * the callback will be called to:
	 *   a) module_put() this module
	 *   b) 'kfree' the memory
	 */
	kobject_put(&dev->kobj);
}

__attribute__((used)) static ssize_t instance_ue_count_show(struct edac_device_instance *instance,
				char *data)
{
	return sprintf(data, "%u\n", instance->counters.ue_count);
}

__attribute__((used)) static ssize_t instance_ce_count_show(struct edac_device_instance *instance,
				char *data)
{
	return sprintf(data, "%u\n", instance->counters.ce_count);
}

__attribute__((used)) static void edac_device_ctrl_instance_release(struct kobject *kobj)
{
	struct edac_device_instance *instance;

	edac_dbg(1, "\n");

	/* map from this kobj to the main control struct
	 * and then dec the main kobj count
	 */
	instance = to_instance(kobj);
	kobject_put(&instance->ctl->kobj);
}

__attribute__((used)) static ssize_t edac_dev_instance_show(struct kobject *kobj,
				struct attribute *attr, char *buffer)
{
	struct edac_device_instance *instance = to_instance(kobj);
	struct instance_attribute *instance_attr = to_instance_attr(attr);

	if (instance_attr->show)
		return instance_attr->show(instance, buffer);
	return -EIO;
}

__attribute__((used)) static ssize_t edac_dev_instance_store(struct kobject *kobj,
				struct attribute *attr,
				const char *buffer, size_t count)
{
	struct edac_device_instance *instance = to_instance(kobj);
	struct instance_attribute *instance_attr = to_instance_attr(attr);

	if (instance_attr->store)
		return instance_attr->store(instance, buffer, count);
	return -EIO;
}

__attribute__((used)) static ssize_t block_ue_count_show(struct kobject *kobj,
					struct attribute *attr, char *data)
{
	struct edac_device_block *block = to_block(kobj);

	return sprintf(data, "%u\n", block->counters.ue_count);
}

__attribute__((used)) static ssize_t block_ce_count_show(struct kobject *kobj,
					struct attribute *attr, char *data)
{
	struct edac_device_block *block = to_block(kobj);

	return sprintf(data, "%u\n", block->counters.ce_count);
}

__attribute__((used)) static void edac_device_ctrl_block_release(struct kobject *kobj)
{
	struct edac_device_block *block;

	edac_dbg(1, "\n");

	/* get the container of the kobj */
	block = to_block(kobj);

	/* map from 'block kobj' to 'block->instance->controller->main_kobj'
	 * now 'release' the block kobject
	 */
	kobject_put(&block->instance->ctl->kobj);
}

__attribute__((used)) static ssize_t edac_dev_block_show(struct kobject *kobj,
				struct attribute *attr, char *buffer)
{
	struct edac_dev_sysfs_block_attribute *block_attr =
						to_block_attr(attr);

	if (block_attr->show)
		return block_attr->show(kobj, attr, buffer);
	return -EIO;
}

__attribute__((used)) static ssize_t edac_dev_block_store(struct kobject *kobj,
				struct attribute *attr,
				const char *buffer, size_t count)
{
	struct edac_dev_sysfs_block_attribute *block_attr;

	block_attr = to_block_attr(attr);

	if (block_attr->store)
		return block_attr->store(kobj, attr, buffer, count);
	return -EIO;
}

__attribute__((used)) static int edac_device_create_block(struct edac_device_ctl_info *edac_dev,
				struct edac_device_instance *instance,
				struct edac_device_block *block)
{
	int i;
	int err;
	struct edac_dev_sysfs_block_attribute *sysfs_attrib;
	struct kobject *main_kobj;

	edac_dbg(4, "Instance '%s' inst_p=%p  block '%s'  block_p=%p\n",
		 instance->name, instance, block->name, block);
	edac_dbg(4, "block kobj=%p  block kobj->parent=%p\n",
		 &block->kobj, &block->kobj.parent);

	/* init this block's kobject */
	memset(&block->kobj, 0, sizeof(struct kobject));

	/* bump the main kobject's reference count for this controller
	 * and this instance is dependent on the main
	 */
	main_kobj = kobject_get(&edac_dev->kobj);
	if (!main_kobj) {
		err = -ENODEV;
		goto err_out;
	}

	/* Add this block's kobject */
	err = kobject_init_and_add(&block->kobj, &ktype_block_ctrl,
				   &instance->kobj,
				   "%s", block->name);
	if (err) {
		edac_dbg(1, "Failed to register instance '%s'\n", block->name);
		kobject_put(main_kobj);
		err = -ENODEV;
		goto err_out;
	}

	/* If there are driver level block attributes, then added them
	 * to the block kobject
	 */
	sysfs_attrib = block->block_attributes;
	if (sysfs_attrib && block->nr_attribs) {
		for (i = 0; i < block->nr_attribs; i++, sysfs_attrib++) {

			edac_dbg(4, "creating block attrib='%s' attrib->%p to kobj=%p\n",
				 sysfs_attrib->attr.name,
				 sysfs_attrib, &block->kobj);

			/* Create each block_attribute file */
			err = sysfs_create_file(&block->kobj,
				&sysfs_attrib->attr);
			if (err)
				goto err_on_attrib;
		}
	}
	kobject_uevent(&block->kobj, KOBJ_ADD);

	return 0;

	/* Error unwind stack */
err_on_attrib:
	kobject_put(&block->kobj);

err_out:
	return err;
}

__attribute__((used)) static void edac_device_delete_block(struct edac_device_ctl_info *edac_dev,
				struct edac_device_block *block)
{
	struct edac_dev_sysfs_block_attribute *sysfs_attrib;
	int i;

	/* if this block has 'attributes' then we need to iterate over the list
	 * and 'remove' the attributes on this block
	 */
	sysfs_attrib = block->block_attributes;
	if (sysfs_attrib && block->nr_attribs) {
		for (i = 0; i < block->nr_attribs; i++, sysfs_attrib++) {

			/* remove each block_attrib file */
			sysfs_remove_file(&block->kobj,
				(struct attribute *) sysfs_attrib);
		}
	}

	/* unregister this block's kobject, SEE:
	 *	edac_device_ctrl_block_release() callback operation
	 */
	kobject_put(&block->kobj);
}

__attribute__((used)) static int edac_device_create_instance(struct edac_device_ctl_info *edac_dev,
				int idx)
{
	int i, j;
	int err;
	struct edac_device_instance *instance;
	struct kobject *main_kobj;

	instance = &edac_dev->instances[idx];

	/* Init the instance's kobject */
	memset(&instance->kobj, 0, sizeof(struct kobject));

	instance->ctl = edac_dev;

	/* bump the main kobject's reference count for this controller
	 * and this instance is dependent on the main
	 */
	main_kobj = kobject_get(&edac_dev->kobj);
	if (!main_kobj) {
		err = -ENODEV;
		goto err_out;
	}

	/* Formally register this instance's kobject under the edac_device */
	err = kobject_init_and_add(&instance->kobj, &ktype_instance_ctrl,
				   &edac_dev->kobj, "%s", instance->name);
	if (err != 0) {
		edac_dbg(2, "Failed to register instance '%s'\n",
			 instance->name);
		kobject_put(main_kobj);
		goto err_out;
	}

	edac_dbg(4, "now register '%d' blocks for instance %d\n",
		 instance->nr_blocks, idx);

	/* register all blocks of this instance */
	for (i = 0; i < instance->nr_blocks; i++) {
		err = edac_device_create_block(edac_dev, instance,
						&instance->blocks[i]);
		if (err) {
			/* If any fail, remove all previous ones */
			for (j = 0; j < i; j++)
				edac_device_delete_block(edac_dev,
							&instance->blocks[j]);
			goto err_release_instance_kobj;
		}
	}
	kobject_uevent(&instance->kobj, KOBJ_ADD);

	edac_dbg(4, "Registered instance %d '%s' kobject\n",
		 idx, instance->name);

	return 0;

	/* error unwind stack */
err_release_instance_kobj:
	kobject_put(&instance->kobj);

err_out:
	return err;
}

__attribute__((used)) static void edac_device_delete_instance(struct edac_device_ctl_info *edac_dev,
					int idx)
{
	struct edac_device_instance *instance;
	int i;

	instance = &edac_dev->instances[idx];

	/* unregister all blocks in this instance */
	for (i = 0; i < instance->nr_blocks; i++)
		edac_device_delete_block(edac_dev, &instance->blocks[i]);

	/* unregister this instance's kobject, SEE:
	 *	edac_device_ctrl_instance_release() for callback operation
	 */
	kobject_put(&instance->kobj);
}

__attribute__((used)) static int edac_device_create_instances(struct edac_device_ctl_info *edac_dev)
{
	int i, j;
	int err;

	edac_dbg(0, "\n");

	/* iterate over creation of the instances */
	for (i = 0; i < edac_dev->nr_instances; i++) {
		err = edac_device_create_instance(edac_dev, i);
		if (err) {
			/* unwind previous instances on error */
			for (j = 0; j < i; j++)
				edac_device_delete_instance(edac_dev, j);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static void edac_device_delete_instances(struct edac_device_ctl_info *edac_dev)
{
	int i;

	/* iterate over creation of the instances */
	for (i = 0; i < edac_dev->nr_instances; i++)
		edac_device_delete_instance(edac_dev, i);
}

__attribute__((used)) static int edac_device_add_main_sysfs_attributes(
			struct edac_device_ctl_info *edac_dev)
{
	struct edac_dev_sysfs_attribute *sysfs_attrib;
	int err = 0;

	sysfs_attrib = edac_dev->sysfs_attributes;
	if (sysfs_attrib) {
		/* iterate over the array and create an attribute for each
		 * entry in the list
		 */
		while (sysfs_attrib->attr.name != NULL) {
			err = sysfs_create_file(&edac_dev->kobj,
				(struct attribute*) sysfs_attrib);
			if (err)
				goto err_out;

			sysfs_attrib++;
		}
	}

err_out:
	return err;
}

__attribute__((used)) static void edac_device_remove_main_sysfs_attributes(
			struct edac_device_ctl_info *edac_dev)
{
	struct edac_dev_sysfs_attribute *sysfs_attrib;

	/* if there are main attributes, defined, remove them. First,
	 * point to the start of the array and iterate over it
	 * removing each attribute listed from this device's instance's kobject
	 */
	sysfs_attrib = edac_dev->sysfs_attributes;
	if (sysfs_attrib) {
		while (sysfs_attrib->attr.name != NULL) {
			sysfs_remove_file(&edac_dev->kobj,
					(struct attribute *) sysfs_attrib);
			sysfs_attrib++;
		}
	}
}

int edac_device_create_sysfs(struct edac_device_ctl_info *edac_dev)
{
	int err;
	struct kobject *edac_kobj = &edac_dev->kobj;

	edac_dbg(0, "idx=%d\n", edac_dev->dev_idx);

	/*  go create any main attributes callers wants */
	err = edac_device_add_main_sysfs_attributes(edac_dev);
	if (err) {
		edac_dbg(0, "failed to add sysfs attribs\n");
		goto err_out;
	}

	/* create a symlink from the edac device
	 * to the platform 'device' being used for this
	 */
	err = sysfs_create_link(edac_kobj,
				&edac_dev->dev->kobj, EDAC_DEVICE_SYMLINK);
	if (err) {
		edac_dbg(0, "sysfs_create_link() returned err= %d\n", err);
		goto err_remove_main_attribs;
	}

	/* Create the first level instance directories
	 * In turn, the nested blocks beneath the instances will
	 * be registered as well
	 */
	err = edac_device_create_instances(edac_dev);
	if (err) {
		edac_dbg(0, "edac_device_create_instances() returned err= %d\n",
			 err);
		goto err_remove_link;
	}


	edac_dbg(4, "create-instances done, idx=%d\n", edac_dev->dev_idx);

	return 0;

	/* Error unwind stack */
err_remove_link:
	/* remove the sym link */
	sysfs_remove_link(&edac_dev->kobj, EDAC_DEVICE_SYMLINK);

err_remove_main_attribs:
	edac_device_remove_main_sysfs_attributes(edac_dev);

err_out:
	return err;
}

void edac_device_remove_sysfs(struct edac_device_ctl_info *edac_dev)
{
	edac_dbg(0, "\n");

	/* remove any main attributes for this device */
	edac_device_remove_main_sysfs_attributes(edac_dev);

	/* remove the device sym link */
	sysfs_remove_link(&edac_dev->kobj, EDAC_DEVICE_SYMLINK);

	/* walk the instance/block kobject tree, deconstructing it */
	edac_device_delete_instances(edac_dev);
}

