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
struct vm_area_struct {int dummy; } ;
struct device_node {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;
struct clcd_panel {TYPE_1__ mode; } ;
struct TYPE_7__ {unsigned long smem_len; int /*<<< orphan*/  smem_start; } ;
struct TYPE_8__ {TYPE_3__ fix; int /*<<< orphan*/  screen_base; } ;
struct clcd_fb {TYPE_4__ fb; TYPE_2__* dev; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct clcd_panel**) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dma_alloc_wc (int /*<<< orphan*/ *,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_wc (int /*<<< orphan*/ *,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_mmap_wc (int /*<<< orphan*/ *,struct vm_area_struct*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 struct clcd_panel** panels ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static inline int versatile_clcd_init_panel(struct clcd_fb *fb,
					    struct device_node *panel)
{
	return 0;
}

struct clcd_panel *versatile_clcd_get_panel(const char *name)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(panels); i++)
		if (strcmp(panels[i]->mode.name, name) == 0)
			break;

	if (i < ARRAY_SIZE(panels))
		return panels[i];

	pr_err("CLCD: couldn't get parameters for panel %s\n", name);

	return NULL;
}

int versatile_clcd_setup_dma(struct clcd_fb *fb, unsigned long framesize)
{
	dma_addr_t dma;

	fb->fb.screen_base = dma_alloc_wc(&fb->dev->dev, framesize, &dma,
					  GFP_KERNEL);
	if (!fb->fb.screen_base) {
		pr_err("CLCD: unable to map framebuffer\n");
		return -ENOMEM;
	}

	fb->fb.fix.smem_start	= dma;
	fb->fb.fix.smem_len	= framesize;

	return 0;
}

int versatile_clcd_mmap_dma(struct clcd_fb *fb, struct vm_area_struct *vma)
{
	return dma_mmap_wc(&fb->dev->dev, vma, fb->fb.screen_base,
			   fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}

void versatile_clcd_remove_dma(struct clcd_fb *fb)
{
	dma_free_wc(&fb->dev->dev, fb->fb.fix.smem_len, fb->fb.screen_base,
		    fb->fb.fix.smem_start);
}

