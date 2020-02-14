#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int dummy; } ;
struct TYPE_8__ {int xres; int yres; } ;
struct clcd_panel {int bpp; TYPE_1__ mode; } ;
struct TYPE_10__ {size_t smem_len; int /*<<< orphan*/  smem_start; } ;
struct TYPE_11__ {TYPE_3__ fix; int /*<<< orphan*/  screen_base; } ;
struct clcd_fb {TYPE_4__ fb; TYPE_2__* dev; struct clcd_panel* panel; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_9__ {TYPE_5__ dev; } ;

/* Variables and functions */
 size_t ALIGN (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  dma_alloc_wc (TYPE_5__*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_wc (TYPE_5__*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_mmap_wc (TYPE_5__*,struct vm_area_struct*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 struct clcd_panel nspire_classic_lcd_panel ; 
 struct clcd_panel nspire_cx_lcd_panel ; 
 int of_property_read_string (int /*<<< orphan*/ ,char*,char const**) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

int nspire_clcd_setup(struct clcd_fb *fb)
{
	struct clcd_panel *panel;
	size_t panel_size;
	const char *type;
	dma_addr_t dma;
	int err;

	BUG_ON(!fb->dev->dev.of_node);

	err = of_property_read_string(fb->dev->dev.of_node, "lcd-type", &type);
	if (err) {
		pr_err("CLCD: Could not find lcd-type property\n");
		return err;
	}

	if (!strcmp(type, "cx")) {
		panel = &nspire_cx_lcd_panel;
	} else if (!strcmp(type, "classic")) {
		panel = &nspire_classic_lcd_panel;
	} else {
		pr_err("CLCD: Unknown lcd-type %s\n", type);
		return -EINVAL;
	}

	panel_size = ((panel->mode.xres * panel->mode.yres) * panel->bpp) / 8;
	panel_size = ALIGN(panel_size, PAGE_SIZE);

	fb->fb.screen_base = dma_alloc_wc(&fb->dev->dev, panel_size, &dma,
					  GFP_KERNEL);

	if (!fb->fb.screen_base) {
		pr_err("CLCD: unable to map framebuffer\n");
		return -ENOMEM;
	}

	fb->fb.fix.smem_start = dma;
	fb->fb.fix.smem_len = panel_size;
	fb->panel = panel;

	return 0;
}

int nspire_clcd_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
	return dma_mmap_wc(&fb->dev->dev, vma, fb->fb.screen_base,
			   fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}

void nspire_clcd_remove(struct clcd_fb *fb)
{
	dma_free_wc(&fb->dev->dev, fb->fb.fix.smem_len, fb->fb.screen_base,
		    fb->fb.fix.smem_start);
}

