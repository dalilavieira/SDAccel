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
struct xenbus_watch {int dummy; } ;
struct notifier_block {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  groups; int /*<<< orphan*/ * bus; scalar_t__ id; } ;
typedef  size_t ssize_t ;
struct TYPE_2__ {unsigned long long target_pages; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 size_t EPERM ; 
 int NOTIFY_DONE ; 
 unsigned long long PAGES2KB (unsigned long long) ; 
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  XBT_NIL ; 
 struct device balloon_dev ; 
 int /*<<< orphan*/  balloon_groups ; 
 int /*<<< orphan*/  balloon_set_new_target (unsigned long long) ; 
 TYPE_1__ balloon_stats ; 
 int /*<<< orphan*/  balloon_subsys ; 
 int /*<<< orphan*/  bus_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int device_register (struct device*) ; 
 unsigned long long memparse (char const*,char**) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
static  int register_balloon (struct device*) ; 
 int /*<<< orphan*/  register_xen_selfballooning (struct device*) ; 
 int register_xenbus_watch (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  register_xenstore_notifier (int /*<<< orphan*/ *) ; 
 int simple_strtoull (char const*,char**,int /*<<< orphan*/ ) ; 
 size_t sprintf (char*,char*,unsigned long long) ; 
 int subsys_system_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  target_watch ; 
 scalar_t__ xen_initial_domain () ; 
 scalar_t__ xen_pv_domain () ; 
 int xenbus_scanf (int /*<<< orphan*/ ,char*,char*,char*,unsigned long long*) ; 
 int /*<<< orphan*/  xenstore_notifier ; 

__attribute__((used)) static void watch_target(struct xenbus_watch *watch,
			 const char *path, const char *token)
{
	unsigned long long new_target, static_max;
	int err;
	static bool watch_fired;
	static long target_diff;

	err = xenbus_scanf(XBT_NIL, "memory", "target", "%llu", &new_target);
	if (err != 1) {
		/* This is ok (for domain0 at least) - so just return */
		return;
	}

	/* The given memory/target value is in KiB, so it needs converting to
	 * pages. PAGE_SHIFT converts bytes to pages, hence PAGE_SHIFT - 10.
	 */
	new_target >>= PAGE_SHIFT - 10;

	if (!watch_fired) {
		watch_fired = true;

		if ((xenbus_scanf(XBT_NIL, "memory", "static-max",
				  "%llu", &static_max) == 1) ||
		    (xenbus_scanf(XBT_NIL, "memory", "memory_static_max",
				  "%llu", &static_max) == 1))
			static_max >>= PAGE_SHIFT - 10;
		else
			static_max = new_target;

		target_diff = (xen_pv_domain() || xen_initial_domain()) ? 0
				: static_max - balloon_stats.target_pages;
	}

	balloon_set_new_target(new_target - target_diff);
}

__attribute__((used)) static int balloon_init_watcher(struct notifier_block *notifier,
				unsigned long event,
				void *data)
{
	int err;

	err = register_xenbus_watch(&target_watch);
	if (err)
		pr_err("Failed to set balloon watcher\n");

	return NOTIFY_DONE;
}

void xen_balloon_init(void)
{
	register_balloon(&balloon_dev);

	register_xen_selfballooning(&balloon_dev);

	register_xenstore_notifier(&xenstore_notifier);
}

__attribute__((used)) static ssize_t show_target_kb(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return sprintf(buf, "%lu\n", PAGES2KB(balloon_stats.target_pages));
}

__attribute__((used)) static ssize_t store_target_kb(struct device *dev,
			       struct device_attribute *attr,
			       const char *buf,
			       size_t count)
{
	char *endchar;
	unsigned long long target_bytes;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	target_bytes = simple_strtoull(buf, &endchar, 0) * 1024;

	balloon_set_new_target(target_bytes >> PAGE_SHIFT);

	return count;
}

__attribute__((used)) static ssize_t show_target(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return sprintf(buf, "%llu\n",
		       (unsigned long long)balloon_stats.target_pages
		       << PAGE_SHIFT);
}

__attribute__((used)) static ssize_t store_target(struct device *dev,
			    struct device_attribute *attr,
			    const char *buf,
			    size_t count)
{
	char *endchar;
	unsigned long long target_bytes;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	target_bytes = memparse(buf, &endchar);

	balloon_set_new_target(target_bytes >> PAGE_SHIFT);

	return count;
}

__attribute__((used)) static int register_balloon(struct device *dev)
{
	int error;

	error = subsys_system_register(&balloon_subsys, NULL);
	if (error)
		return error;

	dev->id = 0;
	dev->bus = &balloon_subsys;
	dev->groups = balloon_groups;

	error = device_register(dev);
	if (error) {
		bus_unregister(&balloon_subsys);
		return error;
	}

	return 0;
}

