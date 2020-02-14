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
struct kobject {struct kernfs_node* sd; } ;
struct TYPE_4__ {TYPE_1__* target_kn; } ;
struct kernfs_node {void* ns; TYPE_2__ symlink; } ;
struct TYPE_3__ {struct kobject* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EEXIST ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  IS_ERR (struct kernfs_node*) ; 
 scalar_t__ KERNFS_LINK ; 
 int PTR_ERR (struct kernfs_node*) ; 
 struct kernfs_node* kernfs_create_link (struct kernfs_node*,char const*,struct kernfs_node*) ; 
 struct kernfs_node* kernfs_find_and_get_ns (struct kernfs_node*,char const*,void const*) ; 
 int /*<<< orphan*/  kernfs_get (struct kernfs_node*) ; 
 scalar_t__ kernfs_ns_enabled (struct kernfs_node*) ; 
 int /*<<< orphan*/  kernfs_put (struct kernfs_node*) ; 
 int /*<<< orphan*/  kernfs_remove_by_name (struct kernfs_node*,char const*) ; 
 int /*<<< orphan*/  kernfs_remove_by_name_ns (struct kernfs_node*,char const*,void const*) ; 
 int kernfs_rename_ns (struct kernfs_node*,struct kernfs_node*,char const*,void const*) ; 
 scalar_t__ kernfs_type (struct kernfs_node*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 struct kernfs_node* sysfs_root_kn ; 
 int /*<<< orphan*/  sysfs_symlink_target_lock ; 
 int /*<<< orphan*/  sysfs_warn_dup (struct kernfs_node*,char const*) ; 

__attribute__((used)) static int sysfs_do_create_link_sd(struct kernfs_node *parent,
				   struct kobject *target_kobj,
				   const char *name, int warn)
{
	struct kernfs_node *kn, *target = NULL;

	BUG_ON(!name || !parent);

	/*
	 * We don't own @target_kobj and it may be removed at any time.
	 * Synchronize using sysfs_symlink_target_lock.  See
	 * sysfs_remove_dir() for details.
	 */
	spin_lock(&sysfs_symlink_target_lock);
	if (target_kobj->sd) {
		target = target_kobj->sd;
		kernfs_get(target);
	}
	spin_unlock(&sysfs_symlink_target_lock);

	if (!target)
		return -ENOENT;

	kn = kernfs_create_link(parent, name, target);
	kernfs_put(target);

	if (!IS_ERR(kn))
		return 0;

	if (warn && PTR_ERR(kn) == -EEXIST)
		sysfs_warn_dup(parent, name);
	return PTR_ERR(kn);
}

int sysfs_create_link_sd(struct kernfs_node *kn, struct kobject *target,
			 const char *name)
{
	return sysfs_do_create_link_sd(kn, target, name, 1);
}

__attribute__((used)) static int sysfs_do_create_link(struct kobject *kobj, struct kobject *target,
				const char *name, int warn)
{
	struct kernfs_node *parent = NULL;

	if (!kobj)
		parent = sysfs_root_kn;
	else
		parent = kobj->sd;

	if (!parent)
		return -EFAULT;

	return sysfs_do_create_link_sd(parent, target, name, warn);
}

int sysfs_create_link(struct kobject *kobj, struct kobject *target,
		      const char *name)
{
	return sysfs_do_create_link(kobj, target, name, 1);
}

int sysfs_create_link_nowarn(struct kobject *kobj, struct kobject *target,
			     const char *name)
{
	return sysfs_do_create_link(kobj, target, name, 0);
}

void sysfs_delete_link(struct kobject *kobj, struct kobject *targ,
			const char *name)
{
	const void *ns = NULL;

	/*
	 * We don't own @target and it may be removed at any time.
	 * Synchronize using sysfs_symlink_target_lock.  See
	 * sysfs_remove_dir() for details.
	 */
	spin_lock(&sysfs_symlink_target_lock);
	if (targ->sd && kernfs_ns_enabled(kobj->sd))
		ns = targ->sd->ns;
	spin_unlock(&sysfs_symlink_target_lock);
	kernfs_remove_by_name_ns(kobj->sd, name, ns);
}

void sysfs_remove_link(struct kobject *kobj, const char *name)
{
	struct kernfs_node *parent = NULL;

	if (!kobj)
		parent = sysfs_root_kn;
	else
		parent = kobj->sd;

	kernfs_remove_by_name(parent, name);
}

int sysfs_rename_link_ns(struct kobject *kobj, struct kobject *targ,
			 const char *old, const char *new, const void *new_ns)
{
	struct kernfs_node *parent, *kn = NULL;
	const void *old_ns = NULL;
	int result;

	if (!kobj)
		parent = sysfs_root_kn;
	else
		parent = kobj->sd;

	if (targ->sd)
		old_ns = targ->sd->ns;

	result = -ENOENT;
	kn = kernfs_find_and_get_ns(parent, old, old_ns);
	if (!kn)
		goto out;

	result = -EINVAL;
	if (kernfs_type(kn) != KERNFS_LINK)
		goto out;
	if (kn->symlink.target_kn->priv != targ)
		goto out;

	result = kernfs_rename_ns(kn, parent, new, new_ns);

out:
	kernfs_put(kn);
	return result;
}

