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
struct xattr {char const* name; int value_len; struct evm_ima_xattr_data* value; } ;
struct key {int dummy; } ;
struct integrity_iint_cache {int flags; int /*<<< orphan*/  evm_status; } ;
struct inode {int /*<<< orphan*/  i_mode; } ;
struct iattr {unsigned int ia_valid; } ;
struct evm_ima_xattr_data {scalar_t__ type; int /*<<< orphan*/  digest; } ;
struct TYPE_4__ {unsigned char* name; } ;
struct dentry {TYPE_2__ d_name; struct inode* d_inode; TYPE_1__* d_sb; } ;
struct audit_context {int dummy; } ;
struct audit_buffer {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum integrity_status { ____Placeholder_integrity_status } integrity_status ;
struct TYPE_3__ {scalar_t__ s_magic; } ;

/* Variables and functions */
 unsigned int ATTR_GID ; 
 unsigned int ATTR_MODE ; 
 unsigned int ATTR_UID ; 
 int AUDIT_INTEGRITY_METADATA ; 
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 int EVM_ALLOW_METADATA_WRITES ; 
 scalar_t__ EVM_IMA_XATTR_DIGSIG ; 
 scalar_t__ EVM_XATTR_HMAC ; 
 scalar_t__ EVM_XATTR_PORTABLE_DIGSIG ; 
 int /*<<< orphan*/  GFP_NOFS ; 
 int IMA_NEW_FILE ; 
 int INTEGRITY_NOXATTRS ; 
 int INTEGRITY_PASS ; 
 int /*<<< orphan*/  INTEGRITY_UNKNOWN ; 
 scalar_t__ SYSFS_MAGIC ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 scalar_t__ TMPFS_MAGIC ; 
 char const* XATTR_EVM_SUFFIX ; 
 int /*<<< orphan*/  XATTR_NAME_EVM ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 struct inode* d_backing_inode (struct dentry*) ; 
 scalar_t__ evm_fixmode ; 
 int evm_init_hmac (struct inode*,struct xattr const*,int /*<<< orphan*/ ) ; 
 int evm_initialized ; 
 int /*<<< orphan*/  evm_key_loaded () ; 
 int /*<<< orphan*/  evm_protected_xattr (char const*) ; 
 int /*<<< orphan*/  evm_update_evmxattr (struct dentry*,char const*,void const*,size_t) ; 
 int evm_verify_hmac (struct dentry*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct integrity_iint_cache* integrity_iint_find (struct inode*) ; 
 char** integrity_status_msg ; 
 int /*<<< orphan*/  kfree (struct evm_ima_xattr_data*) ; 
 struct evm_ima_xattr_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  posix_xattr_acl (char const*) ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int integrity_digsig_verify(const unsigned int id,
					  const char *sig, int siglen,
					  const char *digest, int digestlen)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int integrity_init_keyring(const unsigned int id)
{
	return 0;
}

__attribute__((used)) static inline int asymmetric_verify(struct key *keyring, const char *sig,
				    int siglen, const char *data, int datalen)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline void ima_load_x509(void)
{
}

__attribute__((used)) static inline void evm_load_x509(void)
{
}

__attribute__((used)) static inline void integrity_audit_msg(int audit_msgno, struct inode *inode,
				       const unsigned char *fname,
				       const char *op, const char *cause,
				       int result, int info)
{
}

__attribute__((used)) static inline struct audit_buffer *
integrity_audit_log_start(struct audit_context *ctx, gfp_t gfp_mask, int type)
{
	return NULL;
}

__attribute__((used)) static enum integrity_status evm_verify_current_integrity(struct dentry *dentry)
{
	struct inode *inode = d_backing_inode(dentry);

	if (!evm_key_loaded() || !S_ISREG(inode->i_mode) || evm_fixmode)
		return 0;
	return evm_verify_hmac(dentry, NULL, NULL, 0, NULL);
}

__attribute__((used)) static int evm_protect_xattr(struct dentry *dentry, const char *xattr_name,
			     const void *xattr_value, size_t xattr_value_len)
{
	enum integrity_status evm_status;

	if (strcmp(xattr_name, XATTR_NAME_EVM) == 0) {
		if (!capable(CAP_SYS_ADMIN))
			return -EPERM;
	} else if (!evm_protected_xattr(xattr_name)) {
		if (!posix_xattr_acl(xattr_name))
			return 0;
		evm_status = evm_verify_current_integrity(dentry);
		if ((evm_status == INTEGRITY_PASS) ||
		    (evm_status == INTEGRITY_NOXATTRS))
			return 0;
		goto out;
	}

	evm_status = evm_verify_current_integrity(dentry);
	if (evm_status == INTEGRITY_NOXATTRS) {
		struct integrity_iint_cache *iint;

		iint = integrity_iint_find(d_backing_inode(dentry));
		if (iint && (iint->flags & IMA_NEW_FILE))
			return 0;

		/* exception for pseudo filesystems */
		if (dentry->d_sb->s_magic == TMPFS_MAGIC
		    || dentry->d_sb->s_magic == SYSFS_MAGIC)
			return 0;

		integrity_audit_msg(AUDIT_INTEGRITY_METADATA,
				    dentry->d_inode, dentry->d_name.name,
				    "update_metadata",
				    integrity_status_msg[evm_status],
				    -EPERM, 0);
	}
out:
	if (evm_status != INTEGRITY_PASS)
		integrity_audit_msg(AUDIT_INTEGRITY_METADATA, d_backing_inode(dentry),
				    dentry->d_name.name, "appraise_metadata",
				    integrity_status_msg[evm_status],
				    -EPERM, 0);
	return evm_status == INTEGRITY_PASS ? 0 : -EPERM;
}

int evm_inode_setxattr(struct dentry *dentry, const char *xattr_name,
		       const void *xattr_value, size_t xattr_value_len)
{
	const struct evm_ima_xattr_data *xattr_data = xattr_value;

	/* Policy permits modification of the protected xattrs even though
	 * there's no HMAC key loaded
	 */
	if (evm_initialized & EVM_ALLOW_METADATA_WRITES)
		return 0;

	if (strcmp(xattr_name, XATTR_NAME_EVM) == 0) {
		if (!xattr_value_len)
			return -EINVAL;
		if (xattr_data->type != EVM_IMA_XATTR_DIGSIG &&
		    xattr_data->type != EVM_XATTR_PORTABLE_DIGSIG)
			return -EPERM;
	}
	return evm_protect_xattr(dentry, xattr_name, xattr_value,
				 xattr_value_len);
}

int evm_inode_removexattr(struct dentry *dentry, const char *xattr_name)
{
	/* Policy permits modification of the protected xattrs even though
	 * there's no HMAC key loaded
	 */
	if (evm_initialized & EVM_ALLOW_METADATA_WRITES)
		return 0;

	return evm_protect_xattr(dentry, xattr_name, NULL, 0);
}

__attribute__((used)) static void evm_reset_status(struct inode *inode)
{
	struct integrity_iint_cache *iint;

	iint = integrity_iint_find(inode);
	if (iint)
		iint->evm_status = INTEGRITY_UNKNOWN;
}

void evm_inode_post_setxattr(struct dentry *dentry, const char *xattr_name,
			     const void *xattr_value, size_t xattr_value_len)
{
	if (!evm_key_loaded() || (!evm_protected_xattr(xattr_name)
				  && !posix_xattr_acl(xattr_name)))
		return;

	evm_reset_status(dentry->d_inode);

	evm_update_evmxattr(dentry, xattr_name, xattr_value, xattr_value_len);
}

void evm_inode_post_removexattr(struct dentry *dentry, const char *xattr_name)
{
	if (!evm_key_loaded() || !evm_protected_xattr(xattr_name))
		return;

	evm_reset_status(dentry->d_inode);

	evm_update_evmxattr(dentry, xattr_name, NULL, 0);
}

int evm_inode_setattr(struct dentry *dentry, struct iattr *attr)
{
	unsigned int ia_valid = attr->ia_valid;
	enum integrity_status evm_status;

	/* Policy permits modification of the protected attrs even though
	 * there's no HMAC key loaded
	 */
	if (evm_initialized & EVM_ALLOW_METADATA_WRITES)
		return 0;

	if (!(ia_valid & (ATTR_MODE | ATTR_UID | ATTR_GID)))
		return 0;
	evm_status = evm_verify_current_integrity(dentry);
	if ((evm_status == INTEGRITY_PASS) ||
	    (evm_status == INTEGRITY_NOXATTRS))
		return 0;
	integrity_audit_msg(AUDIT_INTEGRITY_METADATA, d_backing_inode(dentry),
			    dentry->d_name.name, "appraise_metadata",
			    integrity_status_msg[evm_status], -EPERM, 0);
	return -EPERM;
}

void evm_inode_post_setattr(struct dentry *dentry, int ia_valid)
{
	if (!evm_key_loaded())
		return;

	if (ia_valid & (ATTR_MODE | ATTR_UID | ATTR_GID))
		evm_update_evmxattr(dentry, NULL, NULL, 0);
}

int evm_inode_init_security(struct inode *inode,
				 const struct xattr *lsm_xattr,
				 struct xattr *evm_xattr)
{
	struct evm_ima_xattr_data *xattr_data;
	int rc;

	if (!evm_key_loaded() || !evm_protected_xattr(lsm_xattr->name))
		return 0;

	xattr_data = kzalloc(sizeof(*xattr_data), GFP_NOFS);
	if (!xattr_data)
		return -ENOMEM;

	xattr_data->type = EVM_XATTR_HMAC;
	rc = evm_init_hmac(inode, lsm_xattr, xattr_data->digest);
	if (rc < 0)
		goto out;

	evm_xattr->value = xattr_data;
	evm_xattr->value_len = sizeof(*xattr_data);
	evm_xattr->name = XATTR_EVM_SUFFIX;
	return 0;
out:
	kfree(xattr_data);
	return rc;
}

