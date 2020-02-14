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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct key {int dummy; } ;
struct integrity_iint_cache {int dummy; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct evm_ima_xattr_data {int dummy; } ;
struct dentry {int dummy; } ;
struct audit_context {int dummy; } ;
struct audit_buffer {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum integrity_status { ____Placeholder_integrity_status } integrity_status ;
typedef  enum ima_hooks { ____Placeholder_ima_hooks } ima_hooks ;
typedef  enum hash_algo { ____Placeholder_hash_algo } hash_algo ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  IMA_HASH_BITS ; 
 int INTEGRITY_UNKNOWN ; 
 unsigned long hash_long (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ima_hash_algo ; 

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

