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
struct page {int dummy; } ;
struct device_node {int /*<<< orphan*/  name; } ;
struct clk {int dummy; } ;
typedef  enum fsl_diu_monitor_port { ____Placeholder_fsl_diu_monitor_port } fsl_diu_monitor_port ;
struct TYPE_4__ {int /*<<< orphan*/ * release_bootmem; } ;
struct TYPE_3__ {unsigned long fb_phys; unsigned long fb_len; int in_use; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int FSL_DIU_PORT_DVI ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 unsigned long PAGE_MASK ; 
 unsigned long PFN_DOWN (unsigned long) ; 
 unsigned long PFN_UP (unsigned long) ; 
 int PageTail (struct page*) ; 
 unsigned long abs (unsigned int) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 struct clk* clk_get_sys (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ clk_prepare_enable (struct clk*) ; 
 int /*<<< orphan*/  clk_set_rate (struct clk*,unsigned int) ; 
 TYPE_2__ diu_ops ; 
 TYPE_1__ diu_shared_fb ; 
 int /*<<< orphan*/  free_reserved_page (struct page*) ; 
 struct clk* of_clk_get (struct device_node*,int /*<<< orphan*/ ) ; 
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int page_ref_count (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned int,...) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 

__attribute__((used)) static void mpc512x_set_pixel_clock(unsigned int pixclock)
{
	struct device_node *np;
	struct clk *clk_diu;
	unsigned long epsilon, minpixclock, maxpixclock;
	unsigned long offset, want, got, delta;

	/* lookup and enable the DIU clock */
	np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-diu");
	if (!np) {
		pr_err("Could not find DIU device tree node.\n");
		return;
	}
	clk_diu = of_clk_get(np, 0);
	if (IS_ERR(clk_diu)) {
		/* backwards compat with device trees that lack clock specs */
		clk_diu = clk_get_sys(np->name, "ipg");
	}
	of_node_put(np);
	if (IS_ERR(clk_diu)) {
		pr_err("Could not lookup DIU clock.\n");
		return;
	}
	if (clk_prepare_enable(clk_diu)) {
		pr_err("Could not enable DIU clock.\n");
		return;
	}

	/*
	 * convert the picoseconds spec into the desired clock rate,
	 * determine the acceptable clock range for the monitor (+/- 5%),
	 * do the calculation in steps to avoid integer overflow
	 */
	pr_debug("DIU pixclock in ps - %u\n", pixclock);
	pixclock = (1000000000 / pixclock) * 1000;
	pr_debug("DIU pixclock freq  - %u\n", pixclock);
	epsilon = pixclock / 20; /* pixclock * 0.05 */
	pr_debug("DIU deviation      - %lu\n", epsilon);
	minpixclock = pixclock - epsilon;
	maxpixclock = pixclock + epsilon;
	pr_debug("DIU minpixclock    - %lu\n", minpixclock);
	pr_debug("DIU maxpixclock    - %lu\n", maxpixclock);

	/*
	 * check whether the DIU supports the desired pixel clock
	 *
	 * - simply request the desired clock and see what the
	 *   platform's clock driver will make of it, assuming that it
	 *   will setup the best approximation of the requested value
	 * - try other candidate frequencies in the order of decreasing
	 *   preference (i.e. with increasing distance from the desired
	 *   pixel clock, and checking the lower frequency before the
	 *   higher frequency to not overload the hardware) until the
	 *   first match is found -- any potential subsequent match
	 *   would only be as good as the former match or typically
	 *   would be less preferrable
	 *
	 * the offset increment of pixelclock divided by 64 is an
	 * arbitrary choice -- it's simple to calculate, in the typical
	 * case we expect the first check to succeed already, in the
	 * worst case seven frequencies get tested (the exact center and
	 * three more values each to the left and to the right) before
	 * the 5% tolerance window is exceeded, resulting in fast enough
	 * execution yet high enough probability of finding a suitable
	 * value, while the error rate will be in the order of single
	 * percents
	 */
	for (offset = 0; offset <= epsilon; offset += pixclock / 64) {
		want = pixclock - offset;
		pr_debug("DIU checking clock - %lu\n", want);
		clk_set_rate(clk_diu, want);
		got = clk_get_rate(clk_diu);
		delta = abs(pixclock - got);
		if (delta < epsilon)
			break;
		if (!offset)
			continue;
		want = pixclock + offset;
		pr_debug("DIU checking clock - %lu\n", want);
		clk_set_rate(clk_diu, want);
		got = clk_get_rate(clk_diu);
		delta = abs(pixclock - got);
		if (delta < epsilon)
			break;
	}
	if (offset <= epsilon) {
		pr_debug("DIU clock accepted - %lu\n", want);
		pr_debug("DIU pixclock want %u, got %lu, delta %lu, eps %lu\n",
			 pixclock, got, delta, epsilon);
		return;
	}
	pr_warn("DIU pixclock auto search unsuccessful\n");

	/*
	 * what is the most appropriate action to take when the search
	 * for an available pixel clock which is acceptable to the
	 * monitor has failed?  disable the DIU (clock) or just provide
	 * a "best effort"?  we go with the latter
	 */
	pr_warn("DIU pixclock best effort fallback (backend's choice)\n");
	clk_set_rate(clk_diu, pixclock);
	got = clk_get_rate(clk_diu);
	delta = abs(pixclock - got);
	pr_debug("DIU pixclock want %u, got %lu, delta %lu, eps %lu\n",
		 pixclock, got, delta, epsilon);
}

__attribute__((used)) static enum fsl_diu_monitor_port
mpc512x_valid_monitor_port(enum fsl_diu_monitor_port port)
{
	return FSL_DIU_PORT_DVI;
}

__attribute__((used)) static inline void mpc512x_free_bootmem(struct page *page)
{
	BUG_ON(PageTail(page));
	BUG_ON(page_ref_count(page) > 1);
	free_reserved_page(page);
}

__attribute__((used)) static void mpc512x_release_bootmem(void)
{
	unsigned long addr = diu_shared_fb.fb_phys & PAGE_MASK;
	unsigned long size = diu_shared_fb.fb_len;
	unsigned long start, end;

	if (diu_shared_fb.in_use) {
		start = PFN_UP(addr);
		end = PFN_DOWN(addr + size);

		for (; start < end; start++)
			mpc512x_free_bootmem(pfn_to_page(start));

		diu_shared_fb.in_use = false;
	}
	diu_ops.release_bootmem	= NULL;
}

