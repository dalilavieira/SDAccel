#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct timeval {int tv_usec; int /*<<< orphan*/  tv_sec; } ;
struct statfs64 {long f_bsize; long long f_blocks; long long f_bfree; long long f_bavail; long long f_files; long long f_ffree; long f_namelen; int /*<<< orphan*/  f_fsid; } ;
struct stat64 {int /*<<< orphan*/  st_rdev; int /*<<< orphan*/  st_blocks; int /*<<< orphan*/  st_blksize; int /*<<< orphan*/  st_mtime; int /*<<< orphan*/  st_ctime; int /*<<< orphan*/  st_atime; int /*<<< orphan*/  st_size; int /*<<< orphan*/  st_gid; int /*<<< orphan*/  st_uid; int /*<<< orphan*/  st_nlink; int /*<<< orphan*/  st_mode; int /*<<< orphan*/  st_ino; } ;
struct TYPE_4__ {int tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct TYPE_5__ {int tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct TYPE_6__ {scalar_t__ tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct hostfs_stat {TYPE_1__ mtime; TYPE_2__ atime; int /*<<< orphan*/  min; int /*<<< orphan*/  maj; int /*<<< orphan*/  blocks; int /*<<< orphan*/  blksize; TYPE_3__ ctime; int /*<<< orphan*/  size; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; int /*<<< orphan*/  nlink; int /*<<< orphan*/  mode; int /*<<< orphan*/  ino; } ;
struct hostfs_iattr {int ia_valid; int ia_uid; int ia_gid; TYPE_1__ ia_mtime; TYPE_2__ ia_atime; int /*<<< orphan*/  ia_size; int /*<<< orphan*/  ia_mode; } ;
struct dirent {char* d_name; unsigned long long d_ino; unsigned int d_type; unsigned long long d_off; } ;
typedef  void DIR ;

/* Variables and functions */
 int /*<<< orphan*/  AT_FDCWD ; 
 int EINVAL ; 
 int ENOSYS ; 
 int HOSTFS_ATTR_ATIME ; 
 int HOSTFS_ATTR_ATIME_SET ; 
 int HOSTFS_ATTR_GID ; 
 int HOSTFS_ATTR_MODE ; 
 int HOSTFS_ATTR_MTIME ; 
 int HOSTFS_ATTR_MTIME_SET ; 
 int HOSTFS_ATTR_SIZE ; 
 int HOSTFS_ATTR_UID ; 
 int O_APPEND ; 
 int O_CREAT ; 
 int O_RDONLY ; 
 int O_RDWR ; 
 int O_WRONLY ; 
 int R_OK ; 
 int W_OK ; 
 int X_OK ; 
 scalar_t__ access (char*,int) ; 
 scalar_t__ chmod (char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ chown (char const*,int,int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  closedir (void*) ; 
 int dup2 (int,int) ; 
 int errno ; 
 scalar_t__ fchmod (int,int /*<<< orphan*/ ) ; 
 scalar_t__ fchown (int,int,int) ; 
 int fdatasync (int) ; 
 scalar_t__ fstat64 (int,struct stat64*) ; 
 int fsync (int) ; 
 scalar_t__ ftruncate (int,int /*<<< orphan*/ ) ; 
 scalar_t__ futimes (int,struct timeval*) ; 
 int link (char const*,char const*) ; 
 int lseek64 (int,long long,int) ; 
 scalar_t__ lstat64 (char const*,struct stat64*) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ *,int) ; 
 int mkdir (char const*,int) ; 
 int mknod (char const*,int,int /*<<< orphan*/ ) ; 
 int open64 (char*,int,...) ; 
 void* opendir (char*) ; 
 int /*<<< orphan*/  os_major (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_makedev (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  os_minor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int pread64 (int,char*,int,unsigned long long) ; 
 int pwrite64 (int,char const*,int,unsigned long long) ; 
 struct dirent* readdir (void*) ; 
 int readlink (char*,char*,int) ; 
 int rename (char*,char*) ; 
 int rmdir (char const*) ; 
 int /*<<< orphan*/  seekdir (void*,unsigned long long) ; 
 int statfs64 (char*,struct statfs64*) ; 
 int strlen (char*) ; 
 int symlink (char const*,char const*) ; 
 int syscall (int,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*,unsigned int) ; 
 scalar_t__ truncate (char const*,int /*<<< orphan*/ ) ; 
 int unlink (char const*) ; 
 scalar_t__ utimes (char const*,struct timeval*) ; 

__attribute__((used)) static void stat64_to_hostfs(const struct stat64 *buf, struct hostfs_stat *p)
{
	p->ino = buf->st_ino;
	p->mode = buf->st_mode;
	p->nlink = buf->st_nlink;
	p->uid = buf->st_uid;
	p->gid = buf->st_gid;
	p->size = buf->st_size;
	p->atime.tv_sec = buf->st_atime;
	p->atime.tv_nsec = 0;
	p->ctime.tv_sec = buf->st_ctime;
	p->ctime.tv_nsec = 0;
	p->mtime.tv_sec = buf->st_mtime;
	p->mtime.tv_nsec = 0;
	p->blksize = buf->st_blksize;
	p->blocks = buf->st_blocks;
	p->maj = os_major(buf->st_rdev);
	p->min = os_minor(buf->st_rdev);
}

int stat_file(const char *path, struct hostfs_stat *p, int fd)
{
	struct stat64 buf;

	if (fd >= 0) {
		if (fstat64(fd, &buf) < 0)
			return -errno;
	} else if (lstat64(path, &buf) < 0) {
		return -errno;
	}
	stat64_to_hostfs(&buf, p);
	return 0;
}

int access_file(char *path, int r, int w, int x)
{
	int mode = 0;

	if (r)
		mode = R_OK;
	if (w)
		mode |= W_OK;
	if (x)
		mode |= X_OK;
	if (access(path, mode) != 0)
		return -errno;
	else return 0;
}

int open_file(char *path, int r, int w, int append)
{
	int mode = 0, fd;

	if (r && !w)
		mode = O_RDONLY;
	else if (!r && w)
		mode = O_WRONLY;
	else if (r && w)
		mode = O_RDWR;
	else panic("Impossible mode in open_file");

	if (append)
		mode |= O_APPEND;
	fd = open64(path, mode);
	if (fd < 0)
		return -errno;
	else return fd;
}

void *open_dir(char *path, int *err_out)
{
	DIR *dir;

	dir = opendir(path);
	*err_out = errno;

	return dir;
}

void seek_dir(void *stream, unsigned long long pos)
{
	DIR *dir = stream;

	seekdir(dir, pos);
}

char *read_dir(void *stream, unsigned long long *pos_out,
	       unsigned long long *ino_out, int *len_out,
	       unsigned int *type_out)
{
	DIR *dir = stream;
	struct dirent *ent;

	ent = readdir(dir);
	if (ent == NULL)
		return NULL;
	*len_out = strlen(ent->d_name);
	*ino_out = ent->d_ino;
	*type_out = ent->d_type;
	*pos_out = ent->d_off;
	return ent->d_name;
}

int read_file(int fd, unsigned long long *offset, char *buf, int len)
{
	int n;

	n = pread64(fd, buf, len, *offset);
	if (n < 0)
		return -errno;
	*offset += n;
	return n;
}

int write_file(int fd, unsigned long long *offset, const char *buf, int len)
{
	int n;

	n = pwrite64(fd, buf, len, *offset);
	if (n < 0)
		return -errno;
	*offset += n;
	return n;
}

int lseek_file(int fd, long long offset, int whence)
{
	int ret;

	ret = lseek64(fd, offset, whence);
	if (ret < 0)
		return -errno;
	return 0;
}

int fsync_file(int fd, int datasync)
{
	int ret;
	if (datasync)
		ret = fdatasync(fd);
	else
		ret = fsync(fd);

	if (ret < 0)
		return -errno;
	return 0;
}

int replace_file(int oldfd, int fd)
{
	return dup2(oldfd, fd);
}

void close_file(void *stream)
{
	close(*((int *) stream));
}

void close_dir(void *stream)
{
	closedir(stream);
}

int file_create(char *name, int mode)
{
	int fd;

	fd = open64(name, O_CREAT | O_RDWR, mode);
	if (fd < 0)
		return -errno;
	return fd;
}

int set_attr(const char *file, struct hostfs_iattr *attrs, int fd)
{
	struct hostfs_stat st;
	struct timeval times[2];
	int err, ma;

	if (attrs->ia_valid & HOSTFS_ATTR_MODE) {
		if (fd >= 0) {
			if (fchmod(fd, attrs->ia_mode) != 0)
				return -errno;
		} else if (chmod(file, attrs->ia_mode) != 0) {
			return -errno;
		}
	}
	if (attrs->ia_valid & HOSTFS_ATTR_UID) {
		if (fd >= 0) {
			if (fchown(fd, attrs->ia_uid, -1))
				return -errno;
		} else if (chown(file, attrs->ia_uid, -1)) {
			return -errno;
		}
	}
	if (attrs->ia_valid & HOSTFS_ATTR_GID) {
		if (fd >= 0) {
			if (fchown(fd, -1, attrs->ia_gid))
				return -errno;
		} else if (chown(file, -1, attrs->ia_gid)) {
			return -errno;
		}
	}
	if (attrs->ia_valid & HOSTFS_ATTR_SIZE) {
		if (fd >= 0) {
			if (ftruncate(fd, attrs->ia_size))
				return -errno;
		} else if (truncate(file, attrs->ia_size)) {
			return -errno;
		}
	}

	/*
	 * Update accessed and/or modified time, in two parts: first set
	 * times according to the changes to perform, and then call futimes()
	 * or utimes() to apply them.
	 */
	ma = (HOSTFS_ATTR_ATIME_SET | HOSTFS_ATTR_MTIME_SET);
	if (attrs->ia_valid & ma) {
		err = stat_file(file, &st, fd);
		if (err != 0)
			return err;

		times[0].tv_sec = st.atime.tv_sec;
		times[0].tv_usec = st.atime.tv_nsec / 1000;
		times[1].tv_sec = st.mtime.tv_sec;
		times[1].tv_usec = st.mtime.tv_nsec / 1000;

		if (attrs->ia_valid & HOSTFS_ATTR_ATIME_SET) {
			times[0].tv_sec = attrs->ia_atime.tv_sec;
			times[0].tv_usec = attrs->ia_atime.tv_nsec / 1000;
		}
		if (attrs->ia_valid & HOSTFS_ATTR_MTIME_SET) {
			times[1].tv_sec = attrs->ia_mtime.tv_sec;
			times[1].tv_usec = attrs->ia_mtime.tv_nsec / 1000;
		}

		if (fd >= 0) {
			if (futimes(fd, times) != 0)
				return -errno;
		} else if (utimes(file, times) != 0) {
			return -errno;
		}
	}

	/* Note: ctime is not handled */
	if (attrs->ia_valid & (HOSTFS_ATTR_ATIME | HOSTFS_ATTR_MTIME)) {
		err = stat_file(file, &st, fd);
		attrs->ia_atime = st.atime;
		attrs->ia_mtime = st.mtime;
		if (err != 0)
			return err;
	}
	return 0;
}

int make_symlink(const char *from, const char *to)
{
	int err;

	err = symlink(to, from);
	if (err)
		return -errno;
	return 0;
}

int unlink_file(const char *file)
{
	int err;

	err = unlink(file);
	if (err)
		return -errno;
	return 0;
}

int do_mkdir(const char *file, int mode)
{
	int err;

	err = mkdir(file, mode);
	if (err)
		return -errno;
	return 0;
}

int hostfs_do_rmdir(const char *file)
{
	int err;

	err = rmdir(file);
	if (err)
		return -errno;
	return 0;
}

int do_mknod(const char *file, int mode, unsigned int major, unsigned int minor)
{
	int err;

	err = mknod(file, mode, os_makedev(major, minor));
	if (err)
		return -errno;
	return 0;
}

int link_file(const char *to, const char *from)
{
	int err;

	err = link(to, from);
	if (err)
		return -errno;
	return 0;
}

int hostfs_do_readlink(char *file, char *buf, int size)
{
	int n;

	n = readlink(file, buf, size);
	if (n < 0)
		return -errno;
	if (n < size)
		buf[n] = '\0';
	return n;
}

int rename_file(char *from, char *to)
{
	int err;

	err = rename(from, to);
	if (err < 0)
		return -errno;
	return 0;
}

int rename2_file(char *from, char *to, unsigned int flags)
{
	int err;

#ifndef SYS_renameat2
#  ifdef __x86_64__
#    define SYS_renameat2 316
#  endif
#  ifdef __i386__
#    define SYS_renameat2 353
#  endif
#endif

#ifdef SYS_renameat2
	err = syscall(SYS_renameat2, AT_FDCWD, from, AT_FDCWD, to, flags);
	if (err < 0) {
		if (errno != ENOSYS)
			return -errno;
		else
			return -EINVAL;
	}
	return 0;
#else
	return -EINVAL;
#endif
}

int do_statfs(char *root, long *bsize_out, long long *blocks_out,
	      long long *bfree_out, long long *bavail_out,
	      long long *files_out, long long *ffree_out,
	      void *fsid_out, int fsid_size, long *namelen_out)
{
	struct statfs64 buf;
	int err;

	err = statfs64(root, &buf);
	if (err < 0)
		return -errno;

	*bsize_out = buf.f_bsize;
	*blocks_out = buf.f_blocks;
	*bfree_out = buf.f_bfree;
	*bavail_out = buf.f_bavail;
	*files_out = buf.f_files;
	*ffree_out = buf.f_ffree;
	memcpy(fsid_out, &buf.f_fsid,
	       sizeof(buf.f_fsid) > fsid_size ? fsid_size :
	       sizeof(buf.f_fsid));
	*namelen_out = buf.f_namelen;

	return 0;
}

