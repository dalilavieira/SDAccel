#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct seq_file {scalar_t__ private; } ;
struct pl111_drm_dev_private {scalar_t__ regs; } ;
struct drm_minor {int /*<<< orphan*/  debugfs_root; } ;
struct drm_info_node {TYPE_1__* minor; } ;
struct drm_device {struct pl111_drm_dev_private* dev_private; } ;
struct TYPE_7__ {scalar_t__ reg; int /*<<< orphan*/  name; } ;
struct TYPE_6__ {struct drm_device* dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int drm_debugfs_create_files (TYPE_2__*,int,int /*<<< orphan*/ ,struct drm_minor*) ; 
 TYPE_2__* pl111_debugfs_list ; 
 TYPE_2__* pl111_reg_defs ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 

int pl111_debugfs_regs(struct seq_file *m, void *unused)
{
	struct drm_info_node *node = (struct drm_info_node *)m->private;
	struct drm_device *dev = node->minor->dev;
	struct pl111_drm_dev_private *priv = dev->dev_private;
	int i;

	for (i = 0; i < ARRAY_SIZE(pl111_reg_defs); i++) {
		seq_printf(m, "%s (0x%04x): 0x%08x\n",
			   pl111_reg_defs[i].name, pl111_reg_defs[i].reg,
			   readl(priv->regs + pl111_reg_defs[i].reg));
	}

	return 0;
}

int
pl111_debugfs_init(struct drm_minor *minor)
{
	return drm_debugfs_create_files(pl111_debugfs_list,
					ARRAY_SIZE(pl111_debugfs_list),
					minor->debugfs_root, minor);
}

