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
typedef  int /*<<< orphan*/  user_long_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  u_int ;
struct vnode {int dummy; } ;
struct ucred {int dummy; } ;
struct proc {int dummy; } ;
struct label {int dummy; } ;
struct flock {int dummy; } ;
struct fileglob {scalar_t__ fg_data; struct label* fg_label; } ;
typedef  int /*<<< orphan*/  off_t ;

/* Variables and functions */
 scalar_t__ DTYPE_VNODE ; 
 int EFTYPE ; 
 scalar_t__ FILEGLOB_DTYPE (struct fileglob*) ; 
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,struct ucred*,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct ucred*,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 int /*<<< orphan*/  file_check_change_offset ; 
 int /*<<< orphan*/  file_check_create ; 
 int /*<<< orphan*/  file_check_dup ; 
 int /*<<< orphan*/  file_check_fcntl ; 
 int /*<<< orphan*/  file_check_get ; 
 int /*<<< orphan*/  file_check_get_offset ; 
 int /*<<< orphan*/  file_check_inherit ; 
 int /*<<< orphan*/  file_check_ioctl ; 
 int /*<<< orphan*/  file_check_library_validation ; 
 int /*<<< orphan*/  file_check_lock ; 
 int /*<<< orphan*/  file_check_mmap ; 
 int /*<<< orphan*/  file_check_mmap_downgrade ; 
 int /*<<< orphan*/  file_check_receive ; 
 int /*<<< orphan*/  file_check_set ; 
 int /*<<< orphan*/  file_label_associate ; 
 int /*<<< orphan*/  file_label_destroy ; 
 int /*<<< orphan*/  file_label_init ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int mac_vnop_getxattr (struct vnode*,char const*,char*,size_t,size_t*) ; 
 int mac_vnop_removexattr (struct vnode*,char const*) ; 
 int mac_vnop_setxattr (struct vnode*,char const*,char*,size_t) ; 
 int /*<<< orphan*/  panic (char*) ; 

__attribute__((used)) static struct label *
mac_file_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(file_label_init, label);
	return (label);
}

void
mac_file_label_init(struct fileglob *fg)
{

	fg->fg_label = mac_file_label_alloc();
}

__attribute__((used)) static void
mac_file_label_free(struct label *label)
{

	MAC_PERFORM(file_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_file_label_associate(struct ucred *cred, struct fileglob *fg)
{

	MAC_PERFORM(file_label_associate, cred, fg, fg->fg_label);
}

void
mac_file_label_destroy(struct fileglob *fg)
{

	mac_file_label_free(fg->fg_label);
	fg->fg_label = NULL;
}

int
mac_file_check_create(struct ucred *cred)
{
	int error;

	MAC_CHECK(file_check_create, cred);
	return (error);
}

int
mac_file_check_dup(struct ucred *cred, struct fileglob *fg, int newfd)
{
	int error;

	MAC_CHECK(file_check_dup, cred, fg, fg->fg_label, newfd);
	return (error);
}

int
mac_file_check_fcntl(struct ucred *cred, struct fileglob *fg, int cmd,
    user_long_t arg)
{
	int error;

	MAC_CHECK(file_check_fcntl, cred, fg, fg->fg_label, cmd, arg);
	return (error);
}

int
mac_file_check_ioctl(struct ucred *cred, struct fileglob *fg, u_int cmd)
{
	int error;

	MAC_CHECK(file_check_ioctl, cred, fg, fg->fg_label, cmd);
	return (error);
}

int
mac_file_check_inherit(struct ucred *cred, struct fileglob *fg)
{
	int error;

	MAC_CHECK(file_check_inherit, cred, fg, fg->fg_label);
	return (error);
}

int
mac_file_check_receive(struct ucred *cred, struct fileglob *fg)
{
	int error;

	MAC_CHECK(file_check_receive, cred, fg, fg->fg_label);
	return (error);
}

int
mac_file_check_get_offset(struct ucred *cred, struct fileglob *fg)
{
	int error;

	MAC_CHECK(file_check_get_offset, cred, fg, fg->fg_label);
	return (error);
}

int
mac_file_check_change_offset(struct ucred *cred, struct fileglob *fg)
{
	int error;

	MAC_CHECK(file_check_change_offset, cred, fg, fg->fg_label);
	return (error);
}

int
mac_file_check_get(struct ucred *cred, struct fileglob *fg, char *elements,
    int len)
{
	int error;
	
	MAC_CHECK(file_check_get, cred, fg, elements, len);
	return (error);
}

int
mac_file_check_set(struct ucred *cred, struct fileglob *fg, char *buf,
    int buflen)
{
	int error;
	
	MAC_CHECK(file_check_set, cred, fg, buf, buflen);
	return (error);
}

int
mac_file_check_lock(struct ucred *cred, struct fileglob *fg, int op,
    struct flock *fl)
{
	int error;
	
	MAC_CHECK(file_check_lock, cred, fg, fg->fg_label, op, fl);
	return (error);
}

int
mac_file_check_library_validation(struct proc *proc,
	struct fileglob *fg, off_t slice_offset,
	user_long_t error_message, size_t error_message_size)
{
	int error;

	MAC_CHECK(file_check_library_validation, proc, fg, slice_offset, error_message, error_message_size);
	return (error);
}

int
mac_file_check_mmap(struct ucred *cred, struct fileglob *fg, int prot,
    int flags, uint64_t offset, int *maxprot)
{
	int error;
	int maxp;

	maxp = *maxprot;
	MAC_CHECK(file_check_mmap, cred, fg, fg->fg_label, prot, flags, offset, &maxp);
	if ((maxp | *maxprot) != *maxprot)
		panic("file_check_mmap increased max protections");
	*maxprot = maxp;
	return (error);
}

void
mac_file_check_mmap_downgrade(struct ucred *cred, struct fileglob *fg,
    int *prot)
{
	int result = *prot;

	MAC_PERFORM(file_check_mmap_downgrade, cred, fg, fg->fg_label,
	    &result);

	*prot = result;
}

int
mac_file_setxattr(struct fileglob *fg, const char *name, char *buf, size_t len) {
	struct vnode *vp = NULL;

	if (!fg || FILEGLOB_DTYPE(fg) != DTYPE_VNODE) {
		return EFTYPE;
	}

	vp = (struct vnode *)fg->fg_data;
	return mac_vnop_setxattr(vp, name, buf, len);
}

int
mac_file_getxattr(struct fileglob *fg, const char *name, char *buf, size_t len,
		size_t *attrlen) {
	struct vnode *vp = NULL;

	if (!fg || FILEGLOB_DTYPE(fg) != DTYPE_VNODE) {
		return EFTYPE;
	}

	vp = (struct vnode *)fg->fg_data;
	return mac_vnop_getxattr(vp, name, buf, len, attrlen);
}

int
mac_file_removexattr(struct fileglob *fg, const char *name) {
	struct vnode *vp = NULL;

	if (!fg || FILEGLOB_DTYPE(fg) != DTYPE_VNODE) {
		return EFTYPE;
	}

	vp = (struct vnode *)fg->fg_data;
	return mac_vnop_removexattr(vp, name);
}

