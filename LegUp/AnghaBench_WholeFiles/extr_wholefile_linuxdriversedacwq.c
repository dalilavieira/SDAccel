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
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct mem_ctl_info {int dummy; } ;
struct file_operations {int dummy; } ;
struct dentry {int dummy; } ;
struct delayed_work {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  WQ_MEM_RECLAIM ; 
 int /*<<< orphan*/ * alloc_ordered_workqueue (char*,int /*<<< orphan*/ ) ; 
 int cancel_delayed_work_sync (struct delayed_work*) ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush_workqueue (int /*<<< orphan*/ *) ; 
 int mod_delayed_work (int /*<<< orphan*/ *,struct delayed_work*,unsigned long) ; 
 int queue_delayed_work (int /*<<< orphan*/ *,struct delayed_work*,unsigned long) ; 
 int /*<<< orphan*/ * wq ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

bool edac_queue_work(struct delayed_work *work, unsigned long delay)
{
	return queue_delayed_work(wq, work, delay);
}

bool edac_mod_work(struct delayed_work *work, unsigned long delay)
{
	return mod_delayed_work(wq, work, delay);
}

bool edac_stop_work(struct delayed_work *work)
{
	bool ret;

	ret = cancel_delayed_work_sync(work);
	flush_workqueue(wq);

	return ret;
}

int edac_workqueue_setup(void)
{
	wq = alloc_ordered_workqueue("edac-poller", WQ_MEM_RECLAIM);
	if (!wq)
		return -ENODEV;
	else
		return 0;
}

void edac_workqueue_teardown(void)
{
	flush_workqueue(wq);
	destroy_workqueue(wq);
	wq = NULL;
}

