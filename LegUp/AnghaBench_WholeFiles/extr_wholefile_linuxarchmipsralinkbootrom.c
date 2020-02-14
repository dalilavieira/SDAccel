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
struct seq_file {int dummy; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BOOTROM_SIZE ; 
 int EINVAL ; 
 int /*<<< orphan*/  bootrom_file_ops ; 
 int /*<<< orphan*/  debugfs_create_file (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  membase ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  seq_write (struct seq_file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static int bootrom_show(struct seq_file *s, void *unused)
{
	seq_write(s, membase, BOOTROM_SIZE);

	return 0;
}

__attribute__((used)) static int bootrom_open(struct inode *inode, struct file *file)
{
	return single_open(file, bootrom_show, NULL);
}

__attribute__((used)) static int bootrom_setup(void)
{
	if (!debugfs_create_file("bootrom", 0444,
			NULL, NULL, &bootrom_file_ops)) {
		pr_err("Failed to create bootrom debugfs file\n");

		return -EINVAL;
	}

	return 0;
}

