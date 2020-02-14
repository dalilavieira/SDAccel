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
struct work_struct {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_2__ {scalar_t__ current_pages; } ;

/* Variables and functions */
 int ENODEV ; 
 int HZ ; 
 unsigned long MB2PAGES (int) ; 
 int PAGES2MB (unsigned long) ; 
 int /*<<< orphan*/  balloon_set_new_target (scalar_t__) ; 
 TYPE_1__ balloon_stats ; 
 unsigned long max_pfn ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int) ; 
 unsigned long selfballoon_downhysteresis ; 
 int selfballoon_interval ; 
 scalar_t__ selfballoon_min_usable_mb ; 
 int selfballoon_reserved_mb ; 
 unsigned long selfballoon_uphysteresis ; 
 int /*<<< orphan*/  selfballoon_worker ; 
 scalar_t__ tmem_enabled ; 
 int totalram_pages ; 
 unsigned long totalreserve_pages ; 
 unsigned long vm_memory_committed () ; 
 int /*<<< orphan*/  xen_domain () ; 
 scalar_t__ xen_initial_domain () ; 
 int xen_selfballooning_enabled ; 

__attribute__((used)) static void selfballoon_process(struct work_struct *work)
{
	unsigned long cur_pages, goal_pages, tgt_pages, floor_pages;
	unsigned long useful_pages;
	bool reset_timer = false;

	if (xen_selfballooning_enabled) {
		cur_pages = totalram_pages;
		tgt_pages = cur_pages; /* default is no change */
		goal_pages = vm_memory_committed() +
				totalreserve_pages +
				MB2PAGES(selfballoon_reserved_mb);
#ifdef CONFIG_FRONTSWAP
		/* allow space for frontswap pages to be repatriated */
		if (frontswap_selfshrinking)
			goal_pages += frontswap_curr_pages();
#endif
		if (cur_pages > goal_pages)
			tgt_pages = cur_pages -
				((cur_pages - goal_pages) /
				  selfballoon_downhysteresis);
		else if (cur_pages < goal_pages)
			tgt_pages = cur_pages +
				((goal_pages - cur_pages) /
				  selfballoon_uphysteresis);
		/* else if cur_pages == goal_pages, no change */
		useful_pages = max_pfn - totalreserve_pages;
		if (selfballoon_min_usable_mb != 0)
			floor_pages = totalreserve_pages +
					MB2PAGES(selfballoon_min_usable_mb);
		/* piecewise linear function ending in ~3% slope */
		else if (useful_pages < MB2PAGES(16))
			floor_pages = max_pfn; /* not worth ballooning */
		else if (useful_pages < MB2PAGES(64))
			floor_pages = totalreserve_pages + MB2PAGES(16) +
					((useful_pages - MB2PAGES(16)) >> 1);
		else if (useful_pages < MB2PAGES(512))
			floor_pages = totalreserve_pages + MB2PAGES(40) +
					((useful_pages - MB2PAGES(40)) >> 3);
		else /* useful_pages >= MB2PAGES(512) */
			floor_pages = totalreserve_pages + MB2PAGES(99) +
					((useful_pages - MB2PAGES(99)) >> 5);
		if (tgt_pages < floor_pages)
			tgt_pages = floor_pages;
		balloon_set_new_target(tgt_pages +
			balloon_stats.current_pages - totalram_pages);
		reset_timer = true;
	}
#ifdef CONFIG_FRONTSWAP
	if (frontswap_selfshrinking) {
		frontswap_selfshrink();
		reset_timer = true;
	}
#endif
	if (reset_timer)
		schedule_delayed_work(&selfballoon_worker,
			selfballoon_interval * HZ);
}

int register_xen_selfballooning(struct device *dev)
{
	int error = -1;

#ifdef CONFIG_SYSFS
	error = sysfs_create_group(&dev->kobj, &selfballoon_group);
#endif
	return error;
}

int xen_selfballoon_init(bool use_selfballooning, bool use_frontswap_selfshrink)
{
	bool enable = false;
	unsigned long reserve_pages;

	if (!xen_domain())
		return -ENODEV;

	if (xen_initial_domain()) {
		pr_info("Xen selfballooning driver disabled for domain0\n");
		return -ENODEV;
	}

	xen_selfballooning_enabled = tmem_enabled && use_selfballooning;
	if (xen_selfballooning_enabled) {
		pr_info("Initializing Xen selfballooning driver\n");
		enable = true;
	}
#ifdef CONFIG_FRONTSWAP
	frontswap_selfshrinking = tmem_enabled && use_frontswap_selfshrink;
	if (frontswap_selfshrinking) {
		pr_info("Initializing frontswap selfshrinking driver\n");
		enable = true;
	}
#endif
	if (!enable)
		return -ENODEV;

	/*
	 * Give selfballoon_reserved_mb a default value(10% of total ram pages)
	 * to make selfballoon not so aggressive.
	 *
	 * There are mainly two reasons:
	 * 1) The original goal_page didn't consider some pages used by kernel
	 *    space, like slab pages and memory used by device drivers.
	 *
	 * 2) The balloon driver may not give back memory to guest OS fast
	 *    enough when the workload suddenly aquries a lot of physical memory.
	 *
	 * In both cases, the guest OS will suffer from memory pressure and
	 * OOM killer may be triggered.
	 * By reserving extra 10% of total ram pages, we can keep the system
	 * much more reliably and response faster in some cases.
	 */
	if (!selfballoon_reserved_mb) {
		reserve_pages = totalram_pages / 10;
		selfballoon_reserved_mb = PAGES2MB(reserve_pages);
	}
	schedule_delayed_work(&selfballoon_worker, selfballoon_interval * HZ);

	return 0;
}

