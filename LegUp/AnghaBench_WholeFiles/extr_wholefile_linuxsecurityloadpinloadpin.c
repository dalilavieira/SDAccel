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
struct super_block {int dummy; } ;
struct TYPE_4__ {TYPE_1__* mnt; } ;
struct file {TYPE_2__ f_path; } ;
typedef  enum kernel_read_file_id { ____Placeholder_kernel_read_file_id } kernel_read_file_id ;
typedef  enum kernel_load_data_id { ____Placeholder_kernel_load_data_id } kernel_load_data_id ;
struct TYPE_3__ {struct super_block* mnt_sb; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int EPERM ; 
 struct super_block* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR_OR_NULL (struct super_block*) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  enabled ; 
 char* kernel_read_file_id_str (int) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrdup_quotable_cmdline (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* kstrdup_quotable_file (struct file*,int /*<<< orphan*/ ) ; 
 struct super_block* pinned_root ; 
 int /*<<< orphan*/  pinned_root_spinlock ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_notice (char*,char const*,char*,char*,char*,char*,int /*<<< orphan*/ ,char*,char*,char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  task_pid_nr (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void report_load(const char *origin, struct file *file, char *operation)
{
	char *cmdline, *pathname;

	pathname = kstrdup_quotable_file(file, GFP_KERNEL);
	cmdline = kstrdup_quotable_cmdline(current, GFP_KERNEL);

	pr_notice("%s %s obj=%s%s%s pid=%d cmdline=%s%s%s\n",
		  origin, operation,
		  (pathname && pathname[0] != '<') ? "\"" : "",
		  pathname,
		  (pathname && pathname[0] != '<') ? "\"" : "",
		  task_pid_nr(current),
		  cmdline ? "\"" : "", cmdline, cmdline ? "\"" : "");

	kfree(cmdline);
	kfree(pathname);
}

__attribute__((used)) static void check_pinning_enforcement(struct super_block *mnt_sb)
{
	pr_info("load pinning engaged.\n");
}

__attribute__((used)) static void loadpin_sb_free_security(struct super_block *mnt_sb)
{
	/*
	 * When unmounting the filesystem we were using for load
	 * pinning, we acknowledge the superblock release, but make sure
	 * no other modules or firmware can be loaded.
	 */
	if (!IS_ERR_OR_NULL(pinned_root) && mnt_sb == pinned_root) {
		pinned_root = ERR_PTR(-EIO);
		pr_info("umount pinned fs: refusing further loads\n");
	}
}

__attribute__((used)) static int loadpin_read_file(struct file *file, enum kernel_read_file_id id)
{
	struct super_block *load_root;
	const char *origin = kernel_read_file_id_str(id);

	/* This handles the older init_module API that has a NULL file. */
	if (!file) {
		if (!enabled) {
			report_load(origin, NULL, "old-api-pinning-ignored");
			return 0;
		}

		report_load(origin, NULL, "old-api-denied");
		return -EPERM;
	}

	load_root = file->f_path.mnt->mnt_sb;

	/* First loaded module/firmware defines the root for all others. */
	spin_lock(&pinned_root_spinlock);
	/*
	 * pinned_root is only NULL at startup. Otherwise, it is either
	 * a valid reference, or an ERR_PTR.
	 */
	if (!pinned_root) {
		pinned_root = load_root;
		/*
		 * Unlock now since it's only pinned_root we care about.
		 * In the worst case, we will (correctly) report pinning
		 * failures before we have announced that pinning is
		 * enabled. This would be purely cosmetic.
		 */
		spin_unlock(&pinned_root_spinlock);
		check_pinning_enforcement(pinned_root);
		report_load(origin, file, "pinned");
	} else {
		spin_unlock(&pinned_root_spinlock);
	}

	if (IS_ERR_OR_NULL(pinned_root) || load_root != pinned_root) {
		if (unlikely(!enabled)) {
			report_load(origin, file, "pinning-ignored");
			return 0;
		}

		report_load(origin, file, "denied");
		return -EPERM;
	}

	return 0;
}

__attribute__((used)) static int loadpin_load_data(enum kernel_load_data_id id)
{
	return loadpin_read_file(NULL, (enum kernel_read_file_id) id);
}

