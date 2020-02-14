#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_4__ ;
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int u64 ;
typedef  int u32 ;
struct xattr_handler {int dummy; } ;
struct timespec64 {int tv_sec; int tv_nsec; } ;
struct super_block {int dummy; } ;
struct shash_desc {scalar_t__ flags; int /*<<< orphan*/  tfm; } ;
struct qstr {int dummy; } ;
struct inode {int /*<<< orphan*/  i_mode; int /*<<< orphan*/  i_sb; } ;
struct extent_status {unsigned int es_pblk; } ;
struct ext4_sb_info {int /*<<< orphan*/  s_md_lock; int /*<<< orphan*/  s_chksum_driver; int /*<<< orphan*/  s_ext4_flags; TYPE_1__* s_es; } ;
struct ext4_journal_cb_entry {void (* jce_func ) (struct super_block*,struct ext4_journal_cb_entry*,int) ;int /*<<< orphan*/  jce_list; } ;
struct ext4_inode_info {int /*<<< orphan*/  xattr_sem; int /*<<< orphan*/  i_datasync_tid; int /*<<< orphan*/  i_sync_tid; int /*<<< orphan*/  jinode; } ;
struct dentry {int dummy; } ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  journal_t ;
struct TYPE_32__ {int h_sync; int h_buffer_credits; TYPE_3__* h_transaction; } ;
typedef  TYPE_4__ handle_t ;
typedef  unsigned int ext4_fsblk_t ;
typedef  int __u32 ;
typedef  int __le32 ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_31__ {int /*<<< orphan*/  t_tid; TYPE_2__* t_journal; int /*<<< orphan*/  t_private_list; } ;
struct TYPE_30__ {struct super_block* j_private; } ;
struct TYPE_29__ {scalar_t__ s_feature_compat; scalar_t__ s_feature_ro_compat; scalar_t__ s_feature_incompat; } ;

/* Variables and functions */
 int /*<<< orphan*/  APPEND ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int /*<<< orphan*/  CHECK_FLAG_VALUE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPR ; 
 int /*<<< orphan*/  COMPRBLK ; 
 int /*<<< orphan*/  DATA_FLAGS ; 
 int /*<<< orphan*/  DELALLOC ; 
 int /*<<< orphan*/  DIOREAD_NOLOCK ; 
 int /*<<< orphan*/  DIRSYNC ; 
 int /*<<< orphan*/  DIRTY ; 
 int /*<<< orphan*/  EA_INODE ; 
 int /*<<< orphan*/  ENCRYPT ; 
 int /*<<< orphan*/  EOFBLOCKS ; 
 unsigned int ES_MASK ; 
 unsigned int ES_SHIFT ; 
 unsigned int ES_TYPE_MASK ; 
 int EXT4_EPOCH_BITS ; 
 int EXT4_EPOCH_MASK ; 
 int /*<<< orphan*/  EXT4_FLAGS_SHUTDOWN ; 
 struct ext4_inode_info* EXT4_I (struct inode*) ; 
 int /*<<< orphan*/  EXT4_INODE_EXTENTS ; 
 int /*<<< orphan*/  EXT4_INODE_JOURNAL_DATA ; 
 int EXT4_INODE_JOURNAL_DATA_MODE ; 
 int EXT4_INODE_ORDERED_DATA_MODE ; 
 int EXT4_INODE_WRITEBACK_DATA_MODE ; 
 int /*<<< orphan*/ * EXT4_JOURNAL (struct inode*) ; 
 scalar_t__ EXT4_MOUNT_JOURNAL_DATA ; 
 scalar_t__ EXT4_MOUNT_ORDERED_DATA ; 
 scalar_t__ EXT4_MOUNT_WRITEBACK_DATA ; 
 unsigned long EXT4_NOJOURNAL_MAX_REF_COUNT ; 
 int EXT4_NSEC_MASK ; 
 int EXT4_OTHER_FLMASK ; 
 int EXT4_REG_FLMASK ; 
 struct ext4_sb_info* EXT4_SB (struct super_block*) ; 
 int /*<<< orphan*/  EXT4_STATE_NO_EXPAND ; 
 int /*<<< orphan*/  EXT4_XATTR_INDEX_TRUSTED ; 
 int /*<<< orphan*/  EXTENTS ; 
 int EXTENT_STATUS_DELAYED ; 
 int EXTENT_STATUS_HOLE ; 
 int EXTENT_STATUS_REFERENCED ; 
 int EXTENT_STATUS_UNWRITTEN ; 
 int EXTENT_STATUS_WRITTEN ; 
 int /*<<< orphan*/  HUGE_FILE ; 
 int /*<<< orphan*/  IMAGIC ; 
 int /*<<< orphan*/  IMMUTABLE ; 
 int /*<<< orphan*/  INDEX ; 
 int /*<<< orphan*/  INLINE_DATA ; 
 int /*<<< orphan*/  JOURNAL_DATA ; 
 int /*<<< orphan*/  NOATIME ; 
 int /*<<< orphan*/  NOCOMPR ; 
 int /*<<< orphan*/  NODUMP ; 
 int /*<<< orphan*/  NOTAIL ; 
 int /*<<< orphan*/  PROJINHERIT ; 
 int /*<<< orphan*/  RESERVED ; 
 int /*<<< orphan*/  SECRM ; 
 int /*<<< orphan*/  SYNC ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 scalar_t__ S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TOPDIR ; 
 int /*<<< orphan*/  UNRM ; 
 TYPE_4__* __ext4_journal_start_sb (int /*<<< orphan*/ ,unsigned int,int,int,int) ; 
 int capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le16 (unsigned int) ; 
 int cpu_to_le32 (int) ; 
 int crypto_shash_descsize (int /*<<< orphan*/ ) ; 
 int crypto_shash_update (struct shash_desc*,void const*,unsigned int) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 scalar_t__ down_write_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ext4_clear_inode_state (struct inode*,int /*<<< orphan*/ ) ; 
 scalar_t__ ext4_encrypted_inode (struct inode*) ; 
 int /*<<< orphan*/  ext4_set_inode_state (struct inode*,int /*<<< orphan*/ ) ; 
 scalar_t__ ext4_test_inode_flag (struct inode*,int /*<<< orphan*/ ) ; 
 int ext4_test_inode_state (struct inode*,int /*<<< orphan*/ ) ; 
 int ext4_xattr_get (struct inode*,int /*<<< orphan*/ ,char const*,void*,size_t) ; 
 int ext4_xattr_set (struct inode*,int /*<<< orphan*/ ,char const*,void const*,size_t,int) ; 
 int is_handle_aborted (TYPE_4__*) ; 
 int jbd2_journal_blocks_per_page (struct inode*) ; 
 int jbd2_journal_extend (TYPE_4__*,int) ; 
 int jbd2_journal_force_commit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jbd2_journal_free_reserved (TYPE_4__*) ; 
 int jbd2_journal_inode_add_wait (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int jbd2_journal_inode_add_write (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int jbd2_journal_restart (TYPE_4__*,int) ; 
 TYPE_4__* journal_current_handle () ; 
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_opt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline __u32 ext4_mask_flags(umode_t mode, __u32 flags)
{
	if (S_ISDIR(mode))
		return flags;
	else if (S_ISREG(mode))
		return flags & EXT4_REG_FLMASK;
	else
		return flags & EXT4_OTHER_FLMASK;
}

__attribute__((used)) static inline void ext4_check_flag_values(void)
{
	CHECK_FLAG_VALUE(SECRM);
	CHECK_FLAG_VALUE(UNRM);
	CHECK_FLAG_VALUE(COMPR);
	CHECK_FLAG_VALUE(SYNC);
	CHECK_FLAG_VALUE(IMMUTABLE);
	CHECK_FLAG_VALUE(APPEND);
	CHECK_FLAG_VALUE(NODUMP);
	CHECK_FLAG_VALUE(NOATIME);
	CHECK_FLAG_VALUE(DIRTY);
	CHECK_FLAG_VALUE(COMPRBLK);
	CHECK_FLAG_VALUE(NOCOMPR);
	CHECK_FLAG_VALUE(ENCRYPT);
	CHECK_FLAG_VALUE(INDEX);
	CHECK_FLAG_VALUE(IMAGIC);
	CHECK_FLAG_VALUE(JOURNAL_DATA);
	CHECK_FLAG_VALUE(NOTAIL);
	CHECK_FLAG_VALUE(DIRSYNC);
	CHECK_FLAG_VALUE(TOPDIR);
	CHECK_FLAG_VALUE(HUGE_FILE);
	CHECK_FLAG_VALUE(EXTENTS);
	CHECK_FLAG_VALUE(EA_INODE);
	CHECK_FLAG_VALUE(EOFBLOCKS);
	CHECK_FLAG_VALUE(INLINE_DATA);
	CHECK_FLAG_VALUE(PROJINHERIT);
	CHECK_FLAG_VALUE(RESERVED);
}

__attribute__((used)) static inline __le32 ext4_encode_extra_time(struct timespec64 *time)
{
	u32 extra =((time->tv_sec - (s32)time->tv_sec) >> 32) & EXT4_EPOCH_MASK;
	return cpu_to_le32(extra | (time->tv_nsec << EXT4_EPOCH_BITS));
}

__attribute__((used)) static inline void ext4_decode_extra_time(struct timespec64 *time,
					  __le32 extra)
{
	if (unlikely(extra & cpu_to_le32(EXT4_EPOCH_MASK))) {

#if 1
		/* Handle legacy encoding of pre-1970 dates with epoch
		 * bits 1,1. (This backwards compatibility may be removed
		 * at the discretion of the ext4 developers.)
		 */
		u64 extra_bits = le32_to_cpu(extra) & EXT4_EPOCH_MASK;
		if (extra_bits == 3 && ((time->tv_sec) & 0x80000000) != 0)
			extra_bits = 0;
		time->tv_sec += extra_bits << 32;
#else
		time->tv_sec += (u64)(le32_to_cpu(extra) & EXT4_EPOCH_MASK) << 32;
#endif
	}
	time->tv_nsec = (le32_to_cpu(extra) & EXT4_NSEC_MASK) >> EXT4_EPOCH_BITS;
}

__attribute__((used)) static inline unsigned int ext4_es_status(struct extent_status *es)
{
	return es->es_pblk >> ES_SHIFT;
}

__attribute__((used)) static inline unsigned int ext4_es_type(struct extent_status *es)
{
	return (es->es_pblk & ES_TYPE_MASK) >> ES_SHIFT;
}

__attribute__((used)) static inline int ext4_es_is_written(struct extent_status *es)
{
	return (ext4_es_type(es) & EXTENT_STATUS_WRITTEN) != 0;
}

__attribute__((used)) static inline int ext4_es_is_unwritten(struct extent_status *es)
{
	return (ext4_es_type(es) & EXTENT_STATUS_UNWRITTEN) != 0;
}

__attribute__((used)) static inline int ext4_es_is_delayed(struct extent_status *es)
{
	return (ext4_es_type(es) & EXTENT_STATUS_DELAYED) != 0;
}

__attribute__((used)) static inline int ext4_es_is_hole(struct extent_status *es)
{
	return (ext4_es_type(es) & EXTENT_STATUS_HOLE) != 0;
}

__attribute__((used)) static inline void ext4_es_set_referenced(struct extent_status *es)
{
	es->es_pblk |= ((ext4_fsblk_t)EXTENT_STATUS_REFERENCED) << ES_SHIFT;
}

__attribute__((used)) static inline void ext4_es_clear_referenced(struct extent_status *es)
{
	es->es_pblk &= ~(((ext4_fsblk_t)EXTENT_STATUS_REFERENCED) << ES_SHIFT);
}

__attribute__((used)) static inline int ext4_es_is_referenced(struct extent_status *es)
{
	return (ext4_es_status(es) & EXTENT_STATUS_REFERENCED) != 0;
}

__attribute__((used)) static inline ext4_fsblk_t ext4_es_pblock(struct extent_status *es)
{
	return es->es_pblk & ~ES_MASK;
}

__attribute__((used)) static inline void ext4_es_store_pblock(struct extent_status *es,
					ext4_fsblk_t pb)
{
	ext4_fsblk_t block;

	block = (pb & ~ES_MASK) | (es->es_pblk & ES_MASK);
	es->es_pblk = block;
}

__attribute__((used)) static inline void ext4_es_store_status(struct extent_status *es,
					unsigned int status)
{
	es->es_pblk = (((ext4_fsblk_t)status << ES_SHIFT) & ES_MASK) |
		      (es->es_pblk & ~ES_MASK);
}

__attribute__((used)) static inline void ext4_es_store_pblock_status(struct extent_status *es,
					       ext4_fsblk_t pb,
					       unsigned int status)
{
	es->es_pblk = (((ext4_fsblk_t)status << ES_SHIFT) & ES_MASK) |
		      (pb & ~ES_MASK);
}

__attribute__((used)) static inline bool ext4_has_compat_features(struct super_block *sb)
{
	return (EXT4_SB(sb)->s_es->s_feature_compat != 0);
}

__attribute__((used)) static inline bool ext4_has_ro_compat_features(struct super_block *sb)
{
	return (EXT4_SB(sb)->s_es->s_feature_ro_compat != 0);
}

__attribute__((used)) static inline bool ext4_has_incompat_features(struct super_block *sb)
{
	return (EXT4_SB(sb)->s_es->s_feature_incompat != 0);
}

__attribute__((used)) static inline int ext4_forced_shutdown(struct ext4_sb_info *sbi)
{
	return test_bit(EXT4_FLAGS_SHUTDOWN, &sbi->s_ext4_flags);
}

__attribute__((used)) static inline unsigned int
ext4_rec_len_from_disk(__le16 dlen, unsigned blocksize)
{
	unsigned len = le16_to_cpu(dlen);

#if (PAGE_SIZE >= 65536)
	if (len == EXT4_MAX_REC_LEN || len == 0)
		return blocksize;
	return (len & 65532) | ((len & 3) << 16);
#else
	return len;
#endif
}

__attribute__((used)) static inline __le16 ext4_rec_len_to_disk(unsigned len, unsigned blocksize)
{
	if ((len > blocksize) || (blocksize > (1 << 18)) || (len & 3))
		BUG();
#if (PAGE_SIZE >= 65536)
	if (len < 65536)
		return cpu_to_le16(len);
	if (len == blocksize) {
		if (blocksize == 65536)
			return cpu_to_le16(EXT4_MAX_REC_LEN);
		else
			return cpu_to_le16(0);
	}
	return cpu_to_le16((len & 65532) | ((len >> 16) & 3));
#else
	return cpu_to_le16(len);
#endif
}

__attribute__((used)) static inline u32 ext4_chksum(struct ext4_sb_info *sbi, u32 crc,
			      const void *address, unsigned int length)
{
	struct {
		struct shash_desc shash;
		char ctx[4];
	} desc;

	BUG_ON(crypto_shash_descsize(sbi->s_chksum_driver)!=sizeof(desc.ctx));

	desc.shash.tfm = sbi->s_chksum_driver;
	desc.shash.flags = 0;
	*(u32 *)desc.ctx = crc;

	BUG_ON(crypto_shash_update(&desc.shash, address, length));

	return *(u32 *)desc.ctx;
}

__attribute__((used)) static inline void _ext4_journal_callback_add(handle_t *handle,
			struct ext4_journal_cb_entry *jce)
{
	/* Add the jce to transaction's private list */
	list_add_tail(&jce->jce_list, &handle->h_transaction->t_private_list);
}

__attribute__((used)) static inline void ext4_journal_callback_add(handle_t *handle,
			void (*func)(struct super_block *sb,
				     struct ext4_journal_cb_entry *jce,
				     int rc),
			struct ext4_journal_cb_entry *jce)
{
	struct ext4_sb_info *sbi =
			EXT4_SB(handle->h_transaction->t_journal->j_private);

	/* Add the jce to transaction's private list */
	jce->jce_func = func;
	spin_lock(&sbi->s_md_lock);
	_ext4_journal_callback_add(handle, jce);
	spin_unlock(&sbi->s_md_lock);
}

__attribute__((used)) static inline bool ext4_journal_callback_try_del(handle_t *handle,
					     struct ext4_journal_cb_entry *jce)
{
	bool deleted;
	struct ext4_sb_info *sbi =
			EXT4_SB(handle->h_transaction->t_journal->j_private);

	spin_lock(&sbi->s_md_lock);
	deleted = !list_empty(&jce->jce_list);
	list_del_init(&jce->jce_list);
	spin_unlock(&sbi->s_md_lock);
	return deleted;
}

__attribute__((used)) static inline int ext4_handle_valid(handle_t *handle)
{
	if ((unsigned long)handle < EXT4_NOJOURNAL_MAX_REF_COUNT)
		return 0;
	return 1;
}

__attribute__((used)) static inline void ext4_handle_sync(handle_t *handle)
{
	if (ext4_handle_valid(handle))
		handle->h_sync = 1;
}

__attribute__((used)) static inline int ext4_handle_is_aborted(handle_t *handle)
{
	if (ext4_handle_valid(handle))
		return is_handle_aborted(handle);
	return 0;
}

__attribute__((used)) static inline int ext4_handle_has_enough_credits(handle_t *handle, int needed)
{
	if (ext4_handle_valid(handle) && handle->h_buffer_credits < needed)
		return 0;
	return 1;
}

__attribute__((used)) static inline handle_t *__ext4_journal_start(struct inode *inode,
					     unsigned int line, int type,
					     int blocks, int rsv_blocks)
{
	return __ext4_journal_start_sb(inode->i_sb, line, type, blocks,
				       rsv_blocks);
}

__attribute__((used)) static inline void ext4_journal_free_reserved(handle_t *handle)
{
	if (ext4_handle_valid(handle))
		jbd2_journal_free_reserved(handle);
}

__attribute__((used)) static inline handle_t *ext4_journal_current_handle(void)
{
	return journal_current_handle();
}

__attribute__((used)) static inline int ext4_journal_extend(handle_t *handle, int nblocks)
{
	if (ext4_handle_valid(handle))
		return jbd2_journal_extend(handle, nblocks);
	return 0;
}

__attribute__((used)) static inline int ext4_journal_restart(handle_t *handle, int nblocks)
{
	if (ext4_handle_valid(handle))
		return jbd2_journal_restart(handle, nblocks);
	return 0;
}

__attribute__((used)) static inline int ext4_journal_blocks_per_page(struct inode *inode)
{
	if (EXT4_JOURNAL(inode) != NULL)
		return jbd2_journal_blocks_per_page(inode);
	return 0;
}

__attribute__((used)) static inline int ext4_journal_force_commit(journal_t *journal)
{
	if (journal)
		return jbd2_journal_force_commit(journal);
	return 0;
}

__attribute__((used)) static inline int ext4_jbd2_inode_add_write(handle_t *handle,
					    struct inode *inode)
{
	if (ext4_handle_valid(handle))
		return jbd2_journal_inode_add_write(handle,
						    EXT4_I(inode)->jinode);
	return 0;
}

__attribute__((used)) static inline int ext4_jbd2_inode_add_wait(handle_t *handle,
					   struct inode *inode)
{
	if (ext4_handle_valid(handle))
		return jbd2_journal_inode_add_wait(handle,
						   EXT4_I(inode)->jinode);
	return 0;
}

__attribute__((used)) static inline void ext4_update_inode_fsync_trans(handle_t *handle,
						 struct inode *inode,
						 int datasync)
{
	struct ext4_inode_info *ei = EXT4_I(inode);

	if (ext4_handle_valid(handle) && !is_handle_aborted(handle)) {
		ei->i_sync_tid = handle->h_transaction->t_tid;
		if (datasync)
			ei->i_datasync_tid = handle->h_transaction->t_tid;
	}
}

__attribute__((used)) static inline int ext4_inode_journal_mode(struct inode *inode)
{
	if (EXT4_JOURNAL(inode) == NULL)
		return EXT4_INODE_WRITEBACK_DATA_MODE;	/* writeback */
	/* We do not support data journalling with delayed allocation */
	if (!S_ISREG(inode->i_mode) ||
	    test_opt(inode->i_sb, DATA_FLAGS) == EXT4_MOUNT_JOURNAL_DATA ||
	    (ext4_test_inode_flag(inode, EXT4_INODE_JOURNAL_DATA) &&
	    !test_opt(inode->i_sb, DELALLOC))) {
		/* We do not support data journalling for encrypted data */
		if (S_ISREG(inode->i_mode) && ext4_encrypted_inode(inode))
			return EXT4_INODE_ORDERED_DATA_MODE;  /* ordered */
		return EXT4_INODE_JOURNAL_DATA_MODE;	/* journal data */
	}
	if (test_opt(inode->i_sb, DATA_FLAGS) == EXT4_MOUNT_ORDERED_DATA)
		return EXT4_INODE_ORDERED_DATA_MODE;	/* ordered */
	if (test_opt(inode->i_sb, DATA_FLAGS) == EXT4_MOUNT_WRITEBACK_DATA)
		return EXT4_INODE_WRITEBACK_DATA_MODE;	/* writeback */
	BUG();
}

__attribute__((used)) static inline int ext4_should_journal_data(struct inode *inode)
{
	return ext4_inode_journal_mode(inode) & EXT4_INODE_JOURNAL_DATA_MODE;
}

__attribute__((used)) static inline int ext4_should_order_data(struct inode *inode)
{
	return ext4_inode_journal_mode(inode) & EXT4_INODE_ORDERED_DATA_MODE;
}

__attribute__((used)) static inline int ext4_should_writeback_data(struct inode *inode)
{
	return ext4_inode_journal_mode(inode) & EXT4_INODE_WRITEBACK_DATA_MODE;
}

__attribute__((used)) static inline int ext4_should_dioread_nolock(struct inode *inode)
{
	if (!test_opt(inode->i_sb, DIOREAD_NOLOCK))
		return 0;
	if (!S_ISREG(inode->i_mode))
		return 0;
	if (!(ext4_test_inode_flag(inode, EXT4_INODE_EXTENTS)))
		return 0;
	if (ext4_should_journal_data(inode))
		return 0;
	return 1;
}

__attribute__((used)) static inline void ext4_write_lock_xattr(struct inode *inode, int *save)
{
	down_write(&EXT4_I(inode)->xattr_sem);
	*save = ext4_test_inode_state(inode, EXT4_STATE_NO_EXPAND);
	ext4_set_inode_state(inode, EXT4_STATE_NO_EXPAND);
}

__attribute__((used)) static inline int ext4_write_trylock_xattr(struct inode *inode, int *save)
{
	if (down_write_trylock(&EXT4_I(inode)->xattr_sem) == 0)
		return 0;
	*save = ext4_test_inode_state(inode, EXT4_STATE_NO_EXPAND);
	ext4_set_inode_state(inode, EXT4_STATE_NO_EXPAND);
	return 1;
}

__attribute__((used)) static inline void ext4_write_unlock_xattr(struct inode *inode, int *save)
{
	if (*save == 0)
		ext4_clear_inode_state(inode, EXT4_STATE_NO_EXPAND);
	up_write(&EXT4_I(inode)->xattr_sem);
}

__attribute__((used)) static inline int ext4_init_security(handle_t *handle, struct inode *inode,
				     struct inode *dir, const struct qstr *qstr)
{
	return 0;
}

__attribute__((used)) static inline void ext4_xattr_inode_set_class(struct inode *ea_inode) { }

__attribute__((used)) static bool
ext4_xattr_trusted_list(struct dentry *dentry)
{
	return capable(CAP_SYS_ADMIN);
}

__attribute__((used)) static int
ext4_xattr_trusted_get(const struct xattr_handler *handler,
		       struct dentry *unused, struct inode *inode,
		       const char *name, void *buffer, size_t size)
{
	return ext4_xattr_get(inode, EXT4_XATTR_INDEX_TRUSTED,
			      name, buffer, size);
}

__attribute__((used)) static int
ext4_xattr_trusted_set(const struct xattr_handler *handler,
		       struct dentry *unused, struct inode *inode,
		       const char *name, const void *value,
		       size_t size, int flags)
{
	return ext4_xattr_set(inode, EXT4_XATTR_INDEX_TRUSTED,
			      name, value, size, flags);
}

