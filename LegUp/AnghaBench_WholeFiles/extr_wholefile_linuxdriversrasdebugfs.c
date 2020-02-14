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
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 
 int single_release (struct inode*,struct file*) ; 
 int /*<<< orphan*/  trace_count ; 

int ras_userspace_consumers(void)
{
	return atomic_read(&trace_count);
}

__attribute__((used)) static int trace_show(struct seq_file *m, void *v)
{
	return atomic_read(&trace_count);
}

__attribute__((used)) static int trace_open(struct inode *inode, struct file *file)
{
	atomic_inc(&trace_count);
	return single_open(file, trace_show, NULL);
}

__attribute__((used)) static int trace_release(struct inode *inode, struct file *file)
{
	atomic_dec(&trace_count);
	return single_release(inode, file);
}

