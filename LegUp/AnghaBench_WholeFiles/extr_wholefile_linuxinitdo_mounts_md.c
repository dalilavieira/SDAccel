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
typedef  int /*<<< orphan*/  u32 ;
struct kstat {int /*<<< orphan*/  rdev; int /*<<< orphan*/  mode; } ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int S_IFBLK ; 
 int /*<<< orphan*/  S_ISBLK (int /*<<< orphan*/ ) ; 
 int ksys_mknod (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ksys_unlink (char*) ; 
 int /*<<< orphan*/  new_encode_dev (int /*<<< orphan*/ ) ; 
 scalar_t__ vfs_stat (char*,struct kstat*) ; 

__attribute__((used)) static inline int create_dev(char *name, dev_t dev)
{
	ksys_unlink(name);
	return ksys_mknod(name, S_IFBLK|0600, new_encode_dev(dev));
}

__attribute__((used)) static inline u32 bstat(char *name)
{
	struct kstat stat;
	if (vfs_stat(name, &stat) != 0)
		return 0;
	if (!S_ISBLK(stat.mode))
		return 0;
	return stat.rdev;
}

__attribute__((used)) static inline int rd_load_disk(int n) { return 0; }

__attribute__((used)) static inline int rd_load_image(char *from) { return 0; }

__attribute__((used)) static inline bool initrd_load(void) { return false; }

__attribute__((used)) static inline void md_run_setup(void) {}

