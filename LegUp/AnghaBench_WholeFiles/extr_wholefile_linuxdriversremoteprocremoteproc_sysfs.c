#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct rproc {char* firmware; scalar_t__ state; int /*<<< orphan*/  dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  name; TYPE_1__* ops; } ;
struct resource_table {int dummy; } ;
struct firmware {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int (* sanity_check ) (struct rproc*,struct firmware const*) ;int (* load ) (struct rproc*,struct firmware const*) ;int (* parse_fw ) (struct rproc*,struct firmware const*) ;struct resource_table* (* find_loaded_rsc_table ) (struct rproc*,struct firmware const*) ;int /*<<< orphan*/  (* get_boot_addr ) (struct rproc*,struct firmware const*) ;} ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int RPROC_LAST ; 
 scalar_t__ RPROC_OFFLINE ; 
 scalar_t__ RPROC_RUNNING ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrndup (char const*,int,int /*<<< orphan*/ ) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int rproc_boot (struct rproc*) ; 
 int /*<<< orphan*/  rproc_shutdown (struct rproc*) ; 
 char** rproc_state_string ; 
 int sprintf (char*,char*,char*) ; 
 int strcspn (char const*,char*) ; 
 int stub1 (struct rproc*,struct firmware const*) ; 
 int /*<<< orphan*/  stub2 (struct rproc*,struct firmware const*) ; 
 int stub3 (struct rproc*,struct firmware const*) ; 
 int stub4 (struct rproc*,struct firmware const*) ; 
 struct resource_table* stub5 (struct rproc*,struct firmware const*) ; 
 scalar_t__ sysfs_streq (char const*,char*) ; 
 struct rproc* to_rproc (struct device*) ; 

__attribute__((used)) static inline
int rproc_fw_sanity_check(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->sanity_check)
		return rproc->ops->sanity_check(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
u32 rproc_get_boot_addr(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->get_boot_addr)
		return rproc->ops->get_boot_addr(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
int rproc_load_segments(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->load)
		return rproc->ops->load(rproc, fw);

	return -EINVAL;
}

__attribute__((used)) static inline int rproc_parse_fw(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->parse_fw)
		return rproc->ops->parse_fw(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
struct resource_table *rproc_find_loaded_rsc_table(struct rproc *rproc,
						   const struct firmware *fw)
{
	if (rproc->ops->find_loaded_rsc_table)
		return rproc->ops->find_loaded_rsc_table(rproc, fw);

	return NULL;
}

__attribute__((used)) static ssize_t firmware_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct rproc *rproc = to_rproc(dev);

	return sprintf(buf, "%s\n", rproc->firmware);
}

__attribute__((used)) static ssize_t firmware_store(struct device *dev,
			      struct device_attribute *attr,
			      const char *buf, size_t count)
{
	struct rproc *rproc = to_rproc(dev);
	char *p;
	int err, len = count;

	err = mutex_lock_interruptible(&rproc->lock);
	if (err) {
		dev_err(dev, "can't lock rproc %s: %d\n", rproc->name, err);
		return -EINVAL;
	}

	if (rproc->state != RPROC_OFFLINE) {
		dev_err(dev, "can't change firmware while running\n");
		err = -EBUSY;
		goto out;
	}

	len = strcspn(buf, "\n");

	p = kstrndup(buf, len, GFP_KERNEL);
	if (!p) {
		err = -ENOMEM;
		goto out;
	}

	kfree(rproc->firmware);
	rproc->firmware = p;
out:
	mutex_unlock(&rproc->lock);

	return err ? err : count;
}

__attribute__((used)) static ssize_t state_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct rproc *rproc = to_rproc(dev);
	unsigned int state;

	state = rproc->state > RPROC_LAST ? RPROC_LAST : rproc->state;
	return sprintf(buf, "%s\n", rproc_state_string[state]);
}

__attribute__((used)) static ssize_t state_store(struct device *dev,
			      struct device_attribute *attr,
			      const char *buf, size_t count)
{
	struct rproc *rproc = to_rproc(dev);
	int ret = 0;

	if (sysfs_streq(buf, "start")) {
		if (rproc->state == RPROC_RUNNING)
			return -EBUSY;

		ret = rproc_boot(rproc);
		if (ret)
			dev_err(&rproc->dev, "Boot failed: %d\n", ret);
	} else if (sysfs_streq(buf, "stop")) {
		if (rproc->state != RPROC_RUNNING)
			return -EINVAL;

		rproc_shutdown(rproc);
	} else {
		dev_err(&rproc->dev, "Unrecognised option: %s\n", buf);
		ret = -EINVAL;
	}
	return ret ? ret : count;
}

