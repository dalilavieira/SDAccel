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
struct pm_subsys_data {int refcount; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int early_init; int /*<<< orphan*/  lock; struct pm_subsys_data* subsys_data; int /*<<< orphan*/ * qos; } ;
struct device {struct dev_pm_domain* pm_domain; TYPE_1__ power; } ;
struct dev_pm_domain {int /*<<< orphan*/  (* detach ) (struct device*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  EEXIST ; 
 int ENOMEM ; 
 struct device* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int acpi_dev_pm_attach (struct device*,int) ; 
 struct pm_subsys_data* dev_to_psd (struct device*) ; 
 scalar_t__ device_is_bound (struct device*) ; 
 int device_is_registered (struct device*) ; 
 int genpd_dev_pm_attach (struct device*) ; 
 struct device* genpd_dev_pm_attach_by_id (struct device*,unsigned int) ; 
 struct device* genpd_dev_pm_attach_by_name (struct device*,char*) ; 
 int /*<<< orphan*/  kfree (struct pm_subsys_data*) ; 
 struct pm_subsys_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_clk_init (struct device*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct device*,int) ; 

__attribute__((used)) static inline void device_pm_init_common(struct device *dev)
{
	if (!dev->power.early_init) {
		spin_lock_init(&dev->power.lock);
		dev->power.qos = NULL;
		dev->power.early_init = true;
	}
}

__attribute__((used)) static inline void pm_runtime_early_init(struct device *dev)
{
	device_pm_init_common(dev);
}

__attribute__((used)) static inline void pm_runtime_init(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_reinit(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_remove(struct device *dev) {}

__attribute__((used)) static inline int dpm_sysfs_add(struct device *dev) { return 0; }

__attribute__((used)) static inline void dpm_sysfs_remove(struct device *dev) {}

__attribute__((used)) static inline void device_pm_sleep_init(struct device *dev) {}

__attribute__((used)) static inline void device_pm_add(struct device *dev) {}

__attribute__((used)) static inline void device_pm_remove(struct device *dev)
{
	pm_runtime_remove(dev);
}

__attribute__((used)) static inline void device_pm_move_before(struct device *deva,
					 struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_after(struct device *deva,
					struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_last(struct device *dev) {}

__attribute__((used)) static inline void device_pm_check_callbacks(struct device *dev) {}

__attribute__((used)) static inline bool device_pm_initialized(struct device *dev)
{
	return device_is_registered(dev);
}

__attribute__((used)) static inline void device_pm_init(struct device *dev)
{
	device_pm_init_common(dev);
	device_pm_sleep_init(dev);
	pm_runtime_init(dev);
}

int dev_pm_get_subsys_data(struct device *dev)
{
	struct pm_subsys_data *psd;

	psd = kzalloc(sizeof(*psd), GFP_KERNEL);
	if (!psd)
		return -ENOMEM;

	spin_lock_irq(&dev->power.lock);

	if (dev->power.subsys_data) {
		dev->power.subsys_data->refcount++;
	} else {
		spin_lock_init(&psd->lock);
		psd->refcount = 1;
		dev->power.subsys_data = psd;
		pm_clk_init(dev);
		psd = NULL;
	}

	spin_unlock_irq(&dev->power.lock);

	/* kfree() verifies that its argument is nonzero. */
	kfree(psd);

	return 0;
}

void dev_pm_put_subsys_data(struct device *dev)
{
	struct pm_subsys_data *psd;

	spin_lock_irq(&dev->power.lock);

	psd = dev_to_psd(dev);
	if (!psd)
		goto out;

	if (--psd->refcount == 0)
		dev->power.subsys_data = NULL;
	else
		psd = NULL;

 out:
	spin_unlock_irq(&dev->power.lock);
	kfree(psd);
}

int dev_pm_domain_attach(struct device *dev, bool power_on)
{
	int ret;

	if (dev->pm_domain)
		return 0;

	ret = acpi_dev_pm_attach(dev, power_on);
	if (!ret)
		ret = genpd_dev_pm_attach(dev);

	return ret < 0 ? ret : 0;
}

struct device *dev_pm_domain_attach_by_id(struct device *dev,
					  unsigned int index)
{
	if (dev->pm_domain)
		return ERR_PTR(-EEXIST);

	return genpd_dev_pm_attach_by_id(dev, index);
}

struct device *dev_pm_domain_attach_by_name(struct device *dev,
					    char *name)
{
	if (dev->pm_domain)
		return ERR_PTR(-EEXIST);

	return genpd_dev_pm_attach_by_name(dev, name);
}

void dev_pm_domain_detach(struct device *dev, bool power_off)
{
	if (dev->pm_domain && dev->pm_domain->detach)
		dev->pm_domain->detach(dev, power_off);
}

void dev_pm_domain_set(struct device *dev, struct dev_pm_domain *pd)
{
	if (dev->pm_domain == pd)
		return;

	WARN(pd && device_is_bound(dev),
	     "PM domains can only be changed for unbound devices\n");
	dev->pm_domain = pd;
	device_pm_check_callbacks(dev);
}

