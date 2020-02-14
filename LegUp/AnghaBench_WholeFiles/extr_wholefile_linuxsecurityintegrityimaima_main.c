#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct linux_binprm {struct cred* cred; struct file* file; } ;
struct key {int dummy; } ;
struct integrity_iint_cache {int flags; int measured_pcrs; int /*<<< orphan*/  atomic_flags; int /*<<< orphan*/  mutex; int /*<<< orphan*/  version; } ;
struct inode {TYPE_1__* i_sb; int /*<<< orphan*/  i_mode; int /*<<< orphan*/  i_writecount; int /*<<< orphan*/  i_readcount; } ;
struct ima_template_desc {int /*<<< orphan*/  name; } ;
struct file {int f_mode; int f_flags; int /*<<< orphan*/  f_path; } ;
struct evm_ima_xattr_data {scalar_t__ type; } ;
struct dentry {struct inode* d_inode; } ;
struct cred {int dummy; } ;
struct audit_context {int dummy; } ;
struct audit_buffer {int dummy; } ;
typedef  scalar_t__ loff_t ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int fmode_t ;
typedef  enum kernel_read_file_id { ____Placeholder_kernel_read_file_id } kernel_read_file_id ;
typedef  enum kernel_load_data_id { ____Placeholder_kernel_load_data_id } kernel_load_data_id ;
typedef  enum integrity_status { ____Placeholder_integrity_status } integrity_status ;
typedef  enum ima_hooks { ____Placeholder_ima_hooks } ima_hooks ;
typedef  enum hash_algo { ____Placeholder_hash_algo } hash_algo ;
struct TYPE_2__ {int s_iflags; } ;

/* Variables and functions */
 int BPRM_CHECK ; 
 int CONFIG_IMA_MEASURE_PCR_IDX ; 
 int CREDS_CHECK ; 
 int EACCES ; 
 int EBADF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 scalar_t__ EVM_IMA_XATTR_DIGSIG ; 
 int FILE_CHECK ; 
 int FMODE_WRITE ; 
 int IMA_ACTION_FLAGS ; 
 int IMA_APPRAISE ; 
 int IMA_APPRAISED ; 
 int IMA_APPRAISED_SUBMASK ; 
 int IMA_APPRAISE_ENFORCE ; 
 int IMA_APPRAISE_FIRMWARE ; 
 int IMA_APPRAISE_KEXEC ; 
 int IMA_APPRAISE_MODULES ; 
 int IMA_APPRAISE_SUBMASK ; 
 int IMA_AUDIT ; 
 int /*<<< orphan*/  IMA_CHANGE_ATTR ; 
 int /*<<< orphan*/  IMA_CHANGE_XATTR ; 
 int /*<<< orphan*/  IMA_DIGSIG ; 
 int IMA_DONE_MASK ; 
 int IMA_DO_MASK ; 
 int IMA_FAIL_UNVERIFIABLE_SIGS ; 
 int IMA_FILE_APPRAISE ; 
 int IMA_HASH ; 
 int IMA_HASHED ; 
 int /*<<< orphan*/  IMA_HASH_BITS ; 
 int IMA_MEASURE ; 
 int IMA_MEASURED ; 
 int /*<<< orphan*/  IMA_MUST_MEASURE ; 
 int IMA_NEW_FILE ; 
 int IMA_PERMIT_DIRECTIO ; 
 int /*<<< orphan*/  IMA_TEMPLATE_IMA_NAME ; 
 int /*<<< orphan*/  IMA_UPDATE_XATTR ; 
 int INTEGRITY_UNKNOWN ; 
 scalar_t__ IS_IMA (struct inode*) ; 
 int /*<<< orphan*/  IS_I_VERSION (struct inode*) ; 
#define  LOADING_FIRMWARE 130 
#define  LOADING_KEXEC_IMAGE 129 
#define  LOADING_MODULE 128 
 int MAY_ACCESS ; 
 int MAY_APPEND ; 
 int MAY_EXEC ; 
 int MAY_READ ; 
 int MAY_WRITE ; 
 int MMAP_CHECK ; 
 int NAME_MAX ; 
 int O_DIRECT ; 
 unsigned long PROT_EXEC ; 
 int READING_FIRMWARE ; 
 int READING_X509_CERTIFICATE ; 
 int SB_I_IMA_UNVERIFIABLE_SIGNATURE ; 
 int SB_I_UNTRUSTED_MOUNTER ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __putname (char*) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  current ; 
 struct cred* current_cred () ; 
 struct dentry* file_dentry (struct file*) ; 
 struct inode* file_inode (struct file*) ; 
 unsigned long hash_long (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ima_add_violation (struct file*,char const*,struct integrity_iint_cache*,char*,char*) ; 
 int ima_appraise ; 
 int /*<<< orphan*/  ima_audit_measurement (struct integrity_iint_cache*,char const*) ; 
 int ima_collect_measurement (struct integrity_iint_cache*,struct file*,char*,scalar_t__,int) ; 
 char* ima_d_path (int /*<<< orphan*/ *,char**,char*) ; 
 int ima_get_action (struct inode*,struct cred const*,int /*<<< orphan*/ ,int,int,int*) ; 
 int ima_hash_algo ; 
 int ima_policy_flag ; 
 int /*<<< orphan*/  ima_store_measurement (struct integrity_iint_cache*,struct file*,char const*,struct evm_ima_xattr_data*,int,int) ; 
 struct ima_template_desc* ima_template_desc_current () ; 
 int /*<<< orphan*/  inode_eq_iversion (struct inode*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inode_lock (struct inode*) ; 
 int /*<<< orphan*/  inode_unlock (struct inode*) ; 
 struct integrity_iint_cache* integrity_iint_find (struct inode*) ; 
 struct integrity_iint_cache* integrity_inode_get (struct inode*) ; 
 int is_module_sig_enforced () ; 
 int /*<<< orphan*/  kfree (struct evm_ima_xattr_data*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__* read_idmap ; 
 int /*<<< orphan*/  security_cred_getsecid (struct cred*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  security_task_getsecid (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static inline void ima_load_kexec_buffer(void) {}

__attribute__((used)) static inline unsigned long ima_hash_key(u8 *digest)
{
	return hash_long(*digest, IMA_HASH_BITS);
}

__attribute__((used)) static inline int ima_appraise_measurement(enum ima_hooks func,
					   struct integrity_iint_cache *iint,
					   struct file *file,
					   const unsigned char *filename,
					   struct evm_ima_xattr_data *xattr_value,
					   int xattr_len)
{
	return INTEGRITY_UNKNOWN;
}

__attribute__((used)) static inline int ima_must_appraise(struct inode *inode, int mask,
				    enum ima_hooks func)
{
	return 0;
}

__attribute__((used)) static inline void ima_update_xattr(struct integrity_iint_cache *iint,
				    struct file *file)
{
}

__attribute__((used)) static inline enum integrity_status ima_get_cache_status(struct integrity_iint_cache
							 *iint,
							 enum ima_hooks func)
{
	return INTEGRITY_UNKNOWN;
}

__attribute__((used)) static inline enum hash_algo
ima_get_hash_algo(struct evm_ima_xattr_data *xattr_value, int xattr_len)
{
	return ima_hash_algo;
}

__attribute__((used)) static inline int ima_read_xattr(struct dentry *dentry,
				 struct evm_ima_xattr_data **xattr_value)
{
	return 0;
}

__attribute__((used)) static inline int security_filter_rule_init(u32 field, u32 op, char *rulestr,
					    void **lsmrule)
{
	return -EINVAL;
}

__attribute__((used)) static inline int security_filter_rule_match(u32 secid, u32 field, u32 op,
					     void *lsmrule,
					     struct audit_context *actx)
{
	return -EINVAL;
}

__attribute__((used)) static void ima_rdwr_violation_check(struct file *file,
				     struct integrity_iint_cache *iint,
				     int must_measure,
				     char **pathbuf,
				     const char **pathname,
				     char *filename)
{
	struct inode *inode = file_inode(file);
	fmode_t mode = file->f_mode;
	bool send_tomtou = false, send_writers = false;

	if (mode & FMODE_WRITE) {
		if (atomic_read(&inode->i_readcount) && IS_IMA(inode)) {
			if (!iint)
				iint = integrity_iint_find(inode);
			/* IMA_MEASURE is set from reader side */
			if (iint && test_bit(IMA_MUST_MEASURE,
						&iint->atomic_flags))
				send_tomtou = true;
		}
	} else {
		if (must_measure)
			set_bit(IMA_MUST_MEASURE, &iint->atomic_flags);
		if ((atomic_read(&inode->i_writecount) > 0) && must_measure)
			send_writers = true;
	}

	if (!send_tomtou && !send_writers)
		return;

	*pathname = ima_d_path(&file->f_path, pathbuf, filename);

	if (send_tomtou)
		ima_add_violation(file, *pathname, iint,
				  "invalid_pcr", "ToMToU");
	if (send_writers)
		ima_add_violation(file, *pathname, iint,
				  "invalid_pcr", "open_writers");
}

__attribute__((used)) static void ima_check_last_writer(struct integrity_iint_cache *iint,
				  struct inode *inode, struct file *file)
{
	fmode_t mode = file->f_mode;
	bool update;

	if (!(mode & FMODE_WRITE))
		return;

	mutex_lock(&iint->mutex);
	if (atomic_read(&inode->i_writecount) == 1) {
		update = test_and_clear_bit(IMA_UPDATE_XATTR,
					    &iint->atomic_flags);
		if (!IS_I_VERSION(inode) ||
		    !inode_eq_iversion(inode, iint->version) ||
		    (iint->flags & IMA_NEW_FILE)) {
			iint->flags &= ~(IMA_DONE_MASK | IMA_NEW_FILE);
			iint->measured_pcrs = 0;
			if (update)
				ima_update_xattr(iint, file);
		}
	}
	mutex_unlock(&iint->mutex);
}

void ima_file_free(struct file *file)
{
	struct inode *inode = file_inode(file);
	struct integrity_iint_cache *iint;

	if (!ima_policy_flag || !S_ISREG(inode->i_mode))
		return;

	iint = integrity_iint_find(inode);
	if (!iint)
		return;

	ima_check_last_writer(iint, inode, file);
}

__attribute__((used)) static int process_measurement(struct file *file, const struct cred *cred,
			       u32 secid, char *buf, loff_t size, int mask,
			       enum ima_hooks func)
{
	struct inode *inode = file_inode(file);
	struct integrity_iint_cache *iint = NULL;
	struct ima_template_desc *template_desc;
	char *pathbuf = NULL;
	char filename[NAME_MAX];
	const char *pathname = NULL;
	int rc = 0, action, must_appraise = 0;
	int pcr = CONFIG_IMA_MEASURE_PCR_IDX;
	struct evm_ima_xattr_data *xattr_value = NULL;
	int xattr_len = 0;
	bool violation_check;
	enum hash_algo hash_algo;

	if (!ima_policy_flag || !S_ISREG(inode->i_mode))
		return 0;

	/* Return an IMA_MEASURE, IMA_APPRAISE, IMA_AUDIT action
	 * bitmask based on the appraise/audit/measurement policy.
	 * Included is the appraise submask.
	 */
	action = ima_get_action(inode, cred, secid, mask, func, &pcr);
	violation_check = ((func == FILE_CHECK || func == MMAP_CHECK) &&
			   (ima_policy_flag & IMA_MEASURE));
	if (!action && !violation_check)
		return 0;

	must_appraise = action & IMA_APPRAISE;

	/*  Is the appraise rule hook specific?  */
	if (action & IMA_FILE_APPRAISE)
		func = FILE_CHECK;

	inode_lock(inode);

	if (action) {
		iint = integrity_inode_get(inode);
		if (!iint)
			rc = -ENOMEM;
	}

	if (!rc && violation_check)
		ima_rdwr_violation_check(file, iint, action & IMA_MEASURE,
					 &pathbuf, &pathname, filename);

	inode_unlock(inode);

	if (rc)
		goto out;
	if (!action)
		goto out;

	mutex_lock(&iint->mutex);

	if (test_and_clear_bit(IMA_CHANGE_ATTR, &iint->atomic_flags))
		/* reset appraisal flags if ima_inode_post_setattr was called */
		iint->flags &= ~(IMA_APPRAISE | IMA_APPRAISED |
				 IMA_APPRAISE_SUBMASK | IMA_APPRAISED_SUBMASK |
				 IMA_ACTION_FLAGS);

	/*
	 * Re-evaulate the file if either the xattr has changed or the
	 * kernel has no way of detecting file change on the filesystem.
	 * (Limited to privileged mounted filesystems.)
	 */
	if (test_and_clear_bit(IMA_CHANGE_XATTR, &iint->atomic_flags) ||
	    ((inode->i_sb->s_iflags & SB_I_IMA_UNVERIFIABLE_SIGNATURE) &&
	     !(inode->i_sb->s_iflags & SB_I_UNTRUSTED_MOUNTER) &&
	     !(action & IMA_FAIL_UNVERIFIABLE_SIGS))) {
		iint->flags &= ~IMA_DONE_MASK;
		iint->measured_pcrs = 0;
	}

	/* Determine if already appraised/measured based on bitmask
	 * (IMA_MEASURE, IMA_MEASURED, IMA_XXXX_APPRAISE, IMA_XXXX_APPRAISED,
	 *  IMA_AUDIT, IMA_AUDITED)
	 */
	iint->flags |= action;
	action &= IMA_DO_MASK;
	action &= ~((iint->flags & (IMA_DONE_MASK ^ IMA_MEASURED)) >> 1);

	/* If target pcr is already measured, unset IMA_MEASURE action */
	if ((action & IMA_MEASURE) && (iint->measured_pcrs & (0x1 << pcr)))
		action ^= IMA_MEASURE;

	/* HASH sets the digital signature and update flags, nothing else */
	if ((action & IMA_HASH) &&
	    !(test_bit(IMA_DIGSIG, &iint->atomic_flags))) {
		xattr_len = ima_read_xattr(file_dentry(file), &xattr_value);
		if ((xattr_value && xattr_len > 2) &&
		    (xattr_value->type == EVM_IMA_XATTR_DIGSIG))
			set_bit(IMA_DIGSIG, &iint->atomic_flags);
		iint->flags |= IMA_HASHED;
		action ^= IMA_HASH;
		set_bit(IMA_UPDATE_XATTR, &iint->atomic_flags);
	}

	/* Nothing to do, just return existing appraised status */
	if (!action) {
		if (must_appraise)
			rc = ima_get_cache_status(iint, func);
		goto out_locked;
	}

	template_desc = ima_template_desc_current();
	if ((action & IMA_APPRAISE_SUBMASK) ||
		    strcmp(template_desc->name, IMA_TEMPLATE_IMA_NAME) != 0)
		/* read 'security.ima' */
		xattr_len = ima_read_xattr(file_dentry(file), &xattr_value);

	hash_algo = ima_get_hash_algo(xattr_value, xattr_len);

	rc = ima_collect_measurement(iint, file, buf, size, hash_algo);
	if (rc != 0 && rc != -EBADF && rc != -EINVAL)
		goto out_locked;

	if (!pathbuf)	/* ima_rdwr_violation possibly pre-fetched */
		pathname = ima_d_path(&file->f_path, &pathbuf, filename);

	if (action & IMA_MEASURE)
		ima_store_measurement(iint, file, pathname,
				      xattr_value, xattr_len, pcr);
	if (rc == 0 && (action & IMA_APPRAISE_SUBMASK)) {
		inode_lock(inode);
		rc = ima_appraise_measurement(func, iint, file, pathname,
					      xattr_value, xattr_len);
		inode_unlock(inode);
	}
	if (action & IMA_AUDIT)
		ima_audit_measurement(iint, pathname);

	if ((file->f_flags & O_DIRECT) && (iint->flags & IMA_PERMIT_DIRECTIO))
		rc = 0;
out_locked:
	if ((mask & MAY_WRITE) && test_bit(IMA_DIGSIG, &iint->atomic_flags) &&
	     !(iint->flags & IMA_NEW_FILE))
		rc = -EACCES;
	mutex_unlock(&iint->mutex);
	kfree(xattr_value);
out:
	if (pathbuf)
		__putname(pathbuf);
	if (must_appraise) {
		if (rc && (ima_appraise & IMA_APPRAISE_ENFORCE))
			return -EACCES;
		if (file->f_mode & FMODE_WRITE)
			set_bit(IMA_UPDATE_XATTR, &iint->atomic_flags);
	}
	return 0;
}

int ima_file_mmap(struct file *file, unsigned long prot)
{
	u32 secid;

	if (file && (prot & PROT_EXEC)) {
		security_task_getsecid(current, &secid);
		return process_measurement(file, current_cred(), secid, NULL,
					   0, MAY_EXEC, MMAP_CHECK);
	}

	return 0;
}

int ima_bprm_check(struct linux_binprm *bprm)
{
	int ret;
	u32 secid;

	security_task_getsecid(current, &secid);
	ret = process_measurement(bprm->file, current_cred(), secid, NULL, 0,
				  MAY_EXEC, BPRM_CHECK);
	if (ret)
		return ret;

	security_cred_getsecid(bprm->cred, &secid);
	return process_measurement(bprm->file, bprm->cred, secid, NULL, 0,
				   MAY_EXEC, CREDS_CHECK);
}

int ima_file_check(struct file *file, int mask)
{
	u32 secid;

	security_task_getsecid(current, &secid);
	return process_measurement(file, current_cred(), secid, NULL, 0,
				   mask & (MAY_READ | MAY_WRITE | MAY_EXEC |
					   MAY_APPEND), FILE_CHECK);
}

void ima_post_path_mknod(struct dentry *dentry)
{
	struct integrity_iint_cache *iint;
	struct inode *inode = dentry->d_inode;
	int must_appraise;

	must_appraise = ima_must_appraise(inode, MAY_ACCESS, FILE_CHECK);
	if (!must_appraise)
		return;

	iint = integrity_inode_get(inode);
	if (iint)
		iint->flags |= IMA_NEW_FILE;
}

int ima_read_file(struct file *file, enum kernel_read_file_id read_id)
{
	/*
	 * READING_FIRMWARE_PREALLOC_BUFFER
	 *
	 * Do devices using pre-allocated memory run the risk of the
	 * firmware being accessible to the device prior to the completion
	 * of IMA's signature verification any more than when using two
	 * buffers?
	 */
	return 0;
}

int ima_post_read_file(struct file *file, void *buf, loff_t size,
		       enum kernel_read_file_id read_id)
{
	enum ima_hooks func;
	u32 secid;

	if (!file && read_id == READING_FIRMWARE) {
		if ((ima_appraise & IMA_APPRAISE_FIRMWARE) &&
		    (ima_appraise & IMA_APPRAISE_ENFORCE)) {
			pr_err("Prevent firmware loading_store.\n");
			return -EACCES;	/* INTEGRITY_UNKNOWN */
		}
		return 0;
	}

	/* permit signed certs */
	if (!file && read_id == READING_X509_CERTIFICATE)
		return 0;

	if (!file || !buf || size == 0) { /* should never happen */
		if (ima_appraise & IMA_APPRAISE_ENFORCE)
			return -EACCES;
		return 0;
	}

	func = read_idmap[read_id] ?: FILE_CHECK;
	security_task_getsecid(current, &secid);
	return process_measurement(file, current_cred(), secid, buf, size,
				   MAY_READ, func);
}

int ima_load_data(enum kernel_load_data_id id)
{
	bool sig_enforce;

	if ((ima_appraise & IMA_APPRAISE_ENFORCE) != IMA_APPRAISE_ENFORCE)
		return 0;

	switch (id) {
	case LOADING_KEXEC_IMAGE:
		if (ima_appraise & IMA_APPRAISE_KEXEC) {
			pr_err("impossible to appraise a kernel image without a file descriptor; try using kexec_file_load syscall.\n");
			return -EACCES;	/* INTEGRITY_UNKNOWN */
		}
		break;
	case LOADING_FIRMWARE:
		if (ima_appraise & IMA_APPRAISE_FIRMWARE) {
			pr_err("Prevent firmware sysfs fallback loading.\n");
			return -EACCES;	/* INTEGRITY_UNKNOWN */
		}
		break;
	case LOADING_MODULE:
		sig_enforce = is_module_sig_enforced();

		if (!sig_enforce && (ima_appraise & IMA_APPRAISE_MODULES)) {
			pr_err("impossible to appraise a module without a file descriptor. sig_enforce kernel parameter might help\n");
			return -EACCES;	/* INTEGRITY_UNKNOWN */
		}
	default:
		break;
	}
	return 0;
}

