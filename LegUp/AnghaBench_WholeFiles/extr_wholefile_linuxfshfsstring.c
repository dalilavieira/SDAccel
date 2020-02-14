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
struct super_block {char const* s_id; } ;
struct qstr {unsigned char* name; unsigned int len; int /*<<< orphan*/  hash; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  HFS_FLG_BITMAP_DIRTY ; 
 unsigned int HFS_NAMELEN ; 
 TYPE_1__* HFS_SB (struct super_block*) ; 
 scalar_t__* caseorder ; 
 int /*<<< orphan*/  end_name_hash (unsigned int) ; 
 int /*<<< orphan*/  hfs_mark_mdb_dirty (struct super_block*) ; 
 unsigned int init_name_hash (struct dentry const*) ; 
 unsigned int partial_name_hash (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline const char *hfs_mdb_name(struct super_block *sb)
{
	return sb->s_id;
}

__attribute__((used)) static inline void hfs_bitmap_dirty(struct super_block *sb)
{
	set_bit(HFS_FLG_BITMAP_DIRTY, &HFS_SB(sb)->flags);
	hfs_mark_mdb_dirty(sb);
}

int hfs_hash_dentry(const struct dentry *dentry, struct qstr *this)
{
	const unsigned char *name = this->name;
	unsigned int hash, len = this->len;

	if (len > HFS_NAMELEN)
		len = HFS_NAMELEN;

	hash = init_name_hash(dentry);
	for (; len; len--)
		hash = partial_name_hash(caseorder[*name++], hash);
	this->hash = end_name_hash(hash);
	return 0;
}

int hfs_strcmp(const unsigned char *s1, unsigned int len1,
	       const unsigned char *s2, unsigned int len2)
{
	int len, tmp;

	len = (len1 > len2) ? len2 : len1;

	while (len--) {
		tmp = (int)caseorder[*(s1++)] - (int)caseorder[*(s2++)];
		if (tmp)
			return tmp;
	}
	return len1 - len2;
}

int hfs_compare_dentry(const struct dentry *dentry,
		unsigned int len, const char *str, const struct qstr *name)
{
	const unsigned char *n1, *n2;

	if (len >= HFS_NAMELEN) {
		if (name->len < HFS_NAMELEN)
			return 1;
		len = HFS_NAMELEN;
	} else if (len != name->len)
		return 1;

	n1 = str;
	n2 = name->name;
	while (len--) {
		if (caseorder[*n1++] != caseorder[*n2++])
			return 1;
	}
	return 0;
}

