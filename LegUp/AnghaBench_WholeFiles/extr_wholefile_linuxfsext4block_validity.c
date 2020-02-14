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
typedef  int /*<<< orphan*/  umode_t ;
typedef  int u64 ;
typedef  int u32 ;
struct timespec64 {int tv_sec; int tv_nsec; } ;
struct super_block {int dummy; } ;
struct shash_desc {scalar_t__ flags; int /*<<< orphan*/  tfm; } ;
struct extent_status {unsigned int es_pblk; } ;
struct ext4_sb_info {int /*<<< orphan*/  s_chksum_driver; int /*<<< orphan*/  s_ext4_flags; } ;
typedef  int s32 ;
typedef  unsigned int ext4_fsblk_t ;
typedef  int __u32 ;
typedef  int __le32 ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_4__ {TYPE_1__* s_es; } ;
struct TYPE_3__ {scalar_t__ s_feature_compat; scalar_t__ s_feature_ro_compat; scalar_t__ s_feature_incompat; } ;

/* Variables and functions */
 int /*<<< orphan*/  APPEND ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CHECK_FLAG_VALUE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPR ; 
 int /*<<< orphan*/  COMPRBLK ; 
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
 int EXT4_NSEC_MASK ; 
 int EXT4_OTHER_FLMASK ; 
 int EXT4_REG_FLMASK ; 
 TYPE_2__* EXT4_SB (struct super_block*) ; 
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
 int /*<<< orphan*/  cpu_to_le16 (unsigned int) ; 
 int cpu_to_le32 (int) ; 
 int crypto_shash_descsize (int /*<<< orphan*/ ) ; 
 int crypto_shash_update (struct shash_desc*,void const*,unsigned int) ; 
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

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

