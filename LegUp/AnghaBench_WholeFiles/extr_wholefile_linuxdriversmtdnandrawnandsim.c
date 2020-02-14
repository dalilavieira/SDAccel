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
struct seq_file {int dummy; } ;
struct nandsim {int dummy; } ;
struct inode {int /*<<< orphan*/  i_private; } ;
struct file {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_3__ {struct dentry* dfs_dir; } ;
struct TYPE_4__ {TYPE_1__ dbg; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_DEBUG_FS ; 
 int /*<<< orphan*/  CONFIG_MTD_PARTITIONED_MASTER ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR_OR_NULL (struct dentry*) ; 
 int /*<<< orphan*/  NS_ERR (char*) ; 
 int /*<<< orphan*/  NS_WARN (char*) ; 
 int /*<<< orphan*/  S_IRUSR ; 
 struct dentry* debugfs_create_file (char*,int /*<<< orphan*/ ,struct dentry*,struct nandsim*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dfs_fops ; 
 unsigned long* erase_block_wear ; 
 TYPE_2__* nsmtd ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned long,...) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ ) ; 
 unsigned int wear_eb_count ; 

__attribute__((used)) static int nandsim_debugfs_show(struct seq_file *m, void *private)
{
	unsigned long wmin = -1, wmax = 0, avg;
	unsigned long deciles[10], decile_max[10], tot = 0;
	unsigned int i;

	/* Calc wear stats */
	for (i = 0; i < wear_eb_count; ++i) {
		unsigned long wear = erase_block_wear[i];
		if (wear < wmin)
			wmin = wear;
		if (wear > wmax)
			wmax = wear;
		tot += wear;
	}

	for (i = 0; i < 9; ++i) {
		deciles[i] = 0;
		decile_max[i] = (wmax * (i + 1) + 5) / 10;
	}
	deciles[9] = 0;
	decile_max[9] = wmax;
	for (i = 0; i < wear_eb_count; ++i) {
		int d;
		unsigned long wear = erase_block_wear[i];
		for (d = 0; d < 10; ++d)
			if (wear <= decile_max[d]) {
				deciles[d] += 1;
				break;
			}
	}
	avg = tot / wear_eb_count;

	/* Output wear report */
	seq_printf(m, "Total numbers of erases:  %lu\n", tot);
	seq_printf(m, "Number of erase blocks:   %u\n", wear_eb_count);
	seq_printf(m, "Average number of erases: %lu\n", avg);
	seq_printf(m, "Maximum number of erases: %lu\n", wmax);
	seq_printf(m, "Minimum number of erases: %lu\n", wmin);
	for (i = 0; i < 10; ++i) {
		unsigned long from = (i ? decile_max[i - 1] + 1 : 0);
		if (from > decile_max[i])
			continue;
		seq_printf(m, "Number of ebs with erase counts from %lu to %lu : %lu\n",
			from,
			decile_max[i],
			deciles[i]);
	}

	return 0;
}

__attribute__((used)) static int nandsim_debugfs_open(struct inode *inode, struct file *file)
{
	return single_open(file, nandsim_debugfs_show, inode->i_private);
}

__attribute__((used)) static int nandsim_debugfs_create(struct nandsim *dev)
{
	struct dentry *root = nsmtd->dbg.dfs_dir;
	struct dentry *dent;

	/*
	 * Just skip debugfs initialization when the debugfs directory is
	 * missing.
	 */
	if (IS_ERR_OR_NULL(root)) {
		if (IS_ENABLED(CONFIG_DEBUG_FS) &&
		    !IS_ENABLED(CONFIG_MTD_PARTITIONED_MASTER))
			NS_WARN("CONFIG_MTD_PARTITIONED_MASTER must be enabled to expose debugfs stuff\n");
		return 0;
	}

	dent = debugfs_create_file("nandsim_wear_report", S_IRUSR,
				   root, dev, &dfs_fops);
	if (IS_ERR_OR_NULL(dent)) {
		NS_ERR("cannot create \"nandsim_wear_report\" debugfs entry\n");
		return -1;
	}

	return 0;
}

