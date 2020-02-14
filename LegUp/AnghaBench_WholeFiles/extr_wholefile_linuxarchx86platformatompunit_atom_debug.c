#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u32 ;
struct seq_file {struct punit_device* private; } ;
struct punit_device {int sss_pos; scalar_t__ name; int /*<<< orphan*/  reg; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_MBI_UNIT_PMC ; 
 int ENXIO ; 
 int /*<<< orphan*/  MBI_REG_READ ; 
 int /*<<< orphan*/  debugfs_create_dir (char*,int /*<<< orphan*/ *) ; 
 struct dentry* debugfs_create_file (char*,int,int /*<<< orphan*/ ,struct punit_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugfs_remove (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * dstates ; 
 int iosf_mbi_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  punit_dbg_file ; 
 int /*<<< orphan*/  punit_dev_state_fops ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 

__attribute__((used)) static int punit_dev_state_show(struct seq_file *seq_file, void *unused)
{
	u32 punit_pwr_status;
	struct punit_device *punit_devp = seq_file->private;
	int index;
	int status;

	seq_puts(seq_file, "\n\nPUNIT NORTH COMPLEX DEVICES :\n");
	while (punit_devp->name) {
		status = iosf_mbi_read(BT_MBI_UNIT_PMC, MBI_REG_READ,
				       punit_devp->reg, &punit_pwr_status);
		if (status) {
			seq_printf(seq_file, "%9s : Read Failed\n",
				   punit_devp->name);
		} else  {
			index = (punit_pwr_status >> punit_devp->sss_pos) & 3;
			seq_printf(seq_file, "%9s : %s\n", punit_devp->name,
				   dstates[index]);
		}
		punit_devp++;
	}

	return 0;
}

__attribute__((used)) static int punit_dbgfs_register(struct punit_device *punit_device)
{
	static struct dentry *dev_state;

	punit_dbg_file = debugfs_create_dir("punit_atom", NULL);
	if (!punit_dbg_file)
		return -ENXIO;

	dev_state = debugfs_create_file("dev_power_state", 0444,
					punit_dbg_file, punit_device,
					&punit_dev_state_fops);
	if (!dev_state) {
		pr_err("punit_dev_state register failed\n");
		debugfs_remove(punit_dbg_file);
		return -ENXIO;
	}

	return 0;
}

__attribute__((used)) static void punit_dbgfs_unregister(void)
{
	debugfs_remove_recursive(punit_dbg_file);
}

