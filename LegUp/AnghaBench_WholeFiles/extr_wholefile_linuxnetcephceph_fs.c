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
struct ceph_file_layout_legacy {void* fl_pg_pool; void* fl_object_size; void* fl_stripe_count; void* fl_stripe_unit; } ;
struct ceph_file_layout {int stripe_unit; int stripe_count; int object_size; int pool_id; } ;
typedef  int __u32 ;

/* Variables and functions */
 int CEPH_CAP_AUTH_EXCL ; 
 int CEPH_CAP_AUTH_SHARED ; 
 int CEPH_CAP_FILE_BUFFER ; 
 int CEPH_CAP_FILE_CACHE ; 
 int CEPH_CAP_FILE_EXCL ; 
 int CEPH_CAP_FILE_LAZYIO ; 
 int CEPH_CAP_FILE_RD ; 
 int CEPH_CAP_FILE_SHARED ; 
 int CEPH_CAP_FILE_WR ; 
 int CEPH_CAP_PIN ; 
 int CEPH_CAP_XATTR_EXCL ; 
 int CEPH_CAP_XATTR_SHARED ; 
 int CEPH_FILE_MODE_LAZY ; 
 int CEPH_FILE_MODE_RD ; 
 int CEPH_FILE_MODE_RDWR ; 
 int CEPH_FILE_MODE_WR ; 
 int CEPH_MIN_STRIPE_UNIT ; 
#define  O_ACCMODE 131 
#define  O_RDONLY 130 
#define  O_RDWR 129 
#define  O_WRONLY 128 
 void* cpu_to_le32 (scalar_t__) ; 
 void* le32_to_cpu (void*) ; 

int ceph_file_layout_is_valid(const struct ceph_file_layout *layout)
{
	__u32 su = layout->stripe_unit;
	__u32 sc = layout->stripe_count;
	__u32 os = layout->object_size;

	/* stripe unit, object size must be non-zero, 64k increment */
	if (!su || (su & (CEPH_MIN_STRIPE_UNIT-1)))
		return 0;
	if (!os || (os & (CEPH_MIN_STRIPE_UNIT-1)))
		return 0;
	/* object size must be a multiple of stripe unit */
	if (os < su || os % su)
		return 0;
	/* stripe count must be non-zero */
	if (!sc)
		return 0;
	return 1;
}

void ceph_file_layout_from_legacy(struct ceph_file_layout *fl,
				  struct ceph_file_layout_legacy *legacy)
{
	fl->stripe_unit = le32_to_cpu(legacy->fl_stripe_unit);
	fl->stripe_count = le32_to_cpu(legacy->fl_stripe_count);
	fl->object_size = le32_to_cpu(legacy->fl_object_size);
	fl->pool_id = le32_to_cpu(legacy->fl_pg_pool);
	if (fl->pool_id == 0 && fl->stripe_unit == 0 &&
	    fl->stripe_count == 0 && fl->object_size == 0)
		fl->pool_id = -1;
}

void ceph_file_layout_to_legacy(struct ceph_file_layout *fl,
				struct ceph_file_layout_legacy *legacy)
{
	legacy->fl_stripe_unit = cpu_to_le32(fl->stripe_unit);
	legacy->fl_stripe_count = cpu_to_le32(fl->stripe_count);
	legacy->fl_object_size = cpu_to_le32(fl->object_size);
	if (fl->pool_id >= 0)
		legacy->fl_pg_pool = cpu_to_le32(fl->pool_id);
	else
		legacy->fl_pg_pool = 0;
}

int ceph_flags_to_mode(int flags)
{
	int mode;

#ifdef O_DIRECTORY  /* fixme */
	if ((flags & O_DIRECTORY) == O_DIRECTORY)
		return CEPH_FILE_MODE_PIN;
#endif

	switch (flags & O_ACCMODE) {
	case O_WRONLY:
		mode = CEPH_FILE_MODE_WR;
		break;
	case O_RDONLY:
		mode = CEPH_FILE_MODE_RD;
		break;
	case O_RDWR:
	case O_ACCMODE: /* this is what the VFS does */
		mode = CEPH_FILE_MODE_RDWR;
		break;
	}
#ifdef O_LAZY
	if (flags & O_LAZY)
		mode |= CEPH_FILE_MODE_LAZY;
#endif

	return mode;
}

int ceph_caps_for_mode(int mode)
{
	int caps = CEPH_CAP_PIN;

	if (mode & CEPH_FILE_MODE_RD)
		caps |= CEPH_CAP_FILE_SHARED |
			CEPH_CAP_FILE_RD | CEPH_CAP_FILE_CACHE;
	if (mode & CEPH_FILE_MODE_WR)
		caps |= CEPH_CAP_FILE_EXCL |
			CEPH_CAP_FILE_WR | CEPH_CAP_FILE_BUFFER |
			CEPH_CAP_AUTH_SHARED | CEPH_CAP_AUTH_EXCL |
			CEPH_CAP_XATTR_SHARED | CEPH_CAP_XATTR_EXCL;
	if (mode & CEPH_FILE_MODE_LAZY)
		caps |= CEPH_CAP_FILE_LAZYIO;

	return caps;
}

