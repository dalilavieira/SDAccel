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
struct file_system_type {int dummy; } ;
struct dentry {int dummy; } ;
typedef  scalar_t__ dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_TMPFS ; 
 int /*<<< orphan*/  ENODEV ; 
 struct dentry* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned int MAJOR (scalar_t__) ; 
 unsigned int MINOR (scalar_t__) ; 
 scalar_t__ MKDEV (unsigned int,unsigned int) ; 
 scalar_t__ Root_NFS ; 
 scalar_t__ Root_RAM0 ; 
 int S_IFBLK ; 
 int /*<<< orphan*/  S_ISBLK (int /*<<< orphan*/ ) ; 
 scalar_t__ blk_lookup_devt (char*,int) ; 
 scalar_t__ is_tmpfs ; 
 scalar_t__ isdigit (char) ; 
 int ksys_mknod (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ksys_unlink (char*) ; 
 struct dentry* mount_nodev (struct file_system_type*,int,void*,void*) ; 
 scalar_t__ new_decode_dev (int) ; 
 int /*<<< orphan*/  new_encode_dev (scalar_t__) ; 
 void* ramfs_fill_super ; 
 void* shmem_fill_super ; 
 int simple_strtoul (char const*,char**,int) ; 
 int sscanf (char const*,char*,unsigned int*,unsigned int*,...) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,unsigned long*) ; 
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

dev_t name_to_dev_t(const char *name)
{
	char s[32];
	char *p;
	dev_t res = 0;
	int part;

#ifdef CONFIG_BLOCK
	if (strncmp(name, "PARTUUID=", 9) == 0) {
		name += 9;
		res = devt_from_partuuid(name);
		if (!res)
			goto fail;
		goto done;
	}
#endif

	if (strncmp(name, "/dev/", 5) != 0) {
		unsigned maj, min, offset;
		char dummy;

		if ((sscanf(name, "%u:%u%c", &maj, &min, &dummy) == 2) ||
		    (sscanf(name, "%u:%u:%u:%c", &maj, &min, &offset, &dummy) == 3)) {
			res = MKDEV(maj, min);
			if (maj != MAJOR(res) || min != MINOR(res))
				goto fail;
		} else {
			res = new_decode_dev(simple_strtoul(name, &p, 16));
			if (*p)
				goto fail;
		}
		goto done;
	}

	name += 5;
	res = Root_NFS;
	if (strcmp(name, "nfs") == 0)
		goto done;
	res = Root_RAM0;
	if (strcmp(name, "ram") == 0)
		goto done;

	if (strlen(name) > 31)
		goto fail;
	strcpy(s, name);
	for (p = s; *p; p++)
		if (*p == '/')
			*p = '!';
	res = blk_lookup_devt(s, 0);
	if (res)
		goto done;

	/*
	 * try non-existent, but valid partition, which may only exist
	 * after revalidating the disk, like partitioned md devices
	 */
	while (p > s && isdigit(p[-1]))
		p--;
	if (p == s || !*p || *p == '0')
		goto fail;

	/* try disk name without <part number> */
	part = simple_strtoul(p, NULL, 10);
	*p = '\0';
	res = blk_lookup_devt(s, part);
	if (res)
		goto done;

	/* try disk name without p<part number> */
	if (p < s + 2 || !isdigit(p[-2]) || p[-1] != 'p')
		goto fail;
	p[-1] = '\0';
	res = blk_lookup_devt(s, part);
	if (res)
		goto done;

fail:
	return 0;
done:
	return res;
}

__attribute__((used)) static struct dentry *rootfs_mount(struct file_system_type *fs_type,
	int flags, const char *dev_name, void *data)
{
	static unsigned long once;
	void *fill = ramfs_fill_super;

	if (test_and_set_bit(0, &once))
		return ERR_PTR(-ENODEV);

	if (IS_ENABLED(CONFIG_TMPFS) && is_tmpfs)
		fill = shmem_fill_super;

	return mount_nodev(fs_type, flags, data, fill);
}

