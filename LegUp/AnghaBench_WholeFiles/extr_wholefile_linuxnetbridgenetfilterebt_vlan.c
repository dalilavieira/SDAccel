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
struct xt_mtchk_param {struct ebt_entry* entryinfo; struct ebt_vlan_info* matchinfo; } ;
struct xt_action_param {struct ebt_vlan_info* matchinfo; } ;
struct vlan_hdr {scalar_t__ h_vlan_TCI; unsigned char h_vlan_encapsulated_proto; } ;
struct sk_buff {unsigned char protocol; } ;
struct ebt_vlan_info {int bitmask; int invflags; unsigned short id; unsigned short prio; scalar_t__ encap; } ;
struct ebt_entry {scalar_t__ ethproto; } ;
typedef  int /*<<< orphan*/  _frame ;
typedef  unsigned char __be16 ;

/* Variables and functions */
 int EBT_VLAN_ENCAP ; 
 int EBT_VLAN_ID ; 
 int EBT_VLAN_MASK ; 
 int EBT_VLAN_PRIO ; 
 int EINVAL ; 
 int /*<<< orphan*/  ETH_P_8021Q ; 
 unsigned short ETH_ZLEN ; 
 int /*<<< orphan*/  EXIT_ON_MISMATCH (unsigned char,int) ; 
 scalar_t__ GET_BITMASK (int) ; 
 unsigned short VLAN_N_VID ; 
 unsigned short VLAN_VID_MASK ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 unsigned short ntohs (scalar_t__) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned short,...) ; 
 struct vlan_hdr* skb_header_pointer (struct sk_buff const*,int /*<<< orphan*/ ,int,struct vlan_hdr*) ; 
 unsigned short skb_vlan_tag_get (struct sk_buff const*) ; 
 scalar_t__ skb_vlan_tag_present (struct sk_buff const*) ; 

__attribute__((used)) static bool
ebt_vlan_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct ebt_vlan_info *info = par->matchinfo;

	unsigned short TCI;	/* Whole TCI, given from parsed frame */
	unsigned short id;	/* VLAN ID, given from frame TCI */
	unsigned char prio;	/* user_priority, given from frame TCI */
	/* VLAN encapsulated Type/Length field, given from orig frame */
	__be16 encap;

	if (skb_vlan_tag_present(skb)) {
		TCI = skb_vlan_tag_get(skb);
		encap = skb->protocol;
	} else {
		const struct vlan_hdr *fp;
		struct vlan_hdr _frame;

		fp = skb_header_pointer(skb, 0, sizeof(_frame), &_frame);
		if (fp == NULL)
			return false;

		TCI = ntohs(fp->h_vlan_TCI);
		encap = fp->h_vlan_encapsulated_proto;
	}

	/* Tag Control Information (TCI) consists of the following elements:
	 * - User_priority. The user_priority field is three bits in length,
	 * interpreted as a binary number.
	 * - Canonical Format Indicator (CFI). The Canonical Format Indicator
	 * (CFI) is a single bit flag value. Currently ignored.
	 * - VLAN Identifier (VID). The VID is encoded as
	 * an unsigned binary number.
	 */
	id = TCI & VLAN_VID_MASK;
	prio = (TCI >> 13) & 0x7;

	/* Checking VLAN Identifier (VID) */
	if (GET_BITMASK(EBT_VLAN_ID))
		EXIT_ON_MISMATCH(id, EBT_VLAN_ID);

	/* Checking user_priority */
	if (GET_BITMASK(EBT_VLAN_PRIO))
		EXIT_ON_MISMATCH(prio, EBT_VLAN_PRIO);

	/* Checking Encapsulated Proto (Length/Type) field */
	if (GET_BITMASK(EBT_VLAN_ENCAP))
		EXIT_ON_MISMATCH(encap, EBT_VLAN_ENCAP);

	return true;
}

__attribute__((used)) static int ebt_vlan_mt_check(const struct xt_mtchk_param *par)
{
	struct ebt_vlan_info *info = par->matchinfo;
	const struct ebt_entry *e = par->entryinfo;

	/* Is it 802.1Q frame checked? */
	if (e->ethproto != htons(ETH_P_8021Q)) {
		pr_debug("passed entry proto %2.4X is not 802.1Q (8100)\n",
			 ntohs(e->ethproto));
		return -EINVAL;
	}

	/* Check for bitmask range
	 * True if even one bit is out of mask
	 */
	if (info->bitmask & ~EBT_VLAN_MASK) {
		pr_debug("bitmask %2X is out of mask (%2X)\n",
			 info->bitmask, EBT_VLAN_MASK);
		return -EINVAL;
	}

	/* Check for inversion flags range */
	if (info->invflags & ~EBT_VLAN_MASK) {
		pr_debug("inversion flags %2X is out of mask (%2X)\n",
			 info->invflags, EBT_VLAN_MASK);
		return -EINVAL;
	}

	/* Reserved VLAN ID (VID) values
	 * -----------------------------
	 * 0 - The null VLAN ID.
	 * 1 - The default Port VID (PVID)
	 * 0x0FFF - Reserved for implementation use.
	 * if_vlan.h: VLAN_N_VID 4096.
	 */
	if (GET_BITMASK(EBT_VLAN_ID)) {
		if (!!info->id) { /* if id!=0 => check vid range */
			if (info->id > VLAN_N_VID) {
				pr_debug("id %d is out of range (1-4096)\n",
					 info->id);
				return -EINVAL;
			}
			/* Note: This is valid VLAN-tagged frame point.
			 * Any value of user_priority are acceptable,
			 * but should be ignored according to 802.1Q Std.
			 * So we just drop the prio flag.
			 */
			info->bitmask &= ~EBT_VLAN_PRIO;
		}
		/* Else, id=0 (null VLAN ID)  => user_priority range (any?) */
	}

	if (GET_BITMASK(EBT_VLAN_PRIO)) {
		if ((unsigned char) info->prio > 7) {
			pr_debug("prio %d is out of range (0-7)\n",
				 info->prio);
			return -EINVAL;
		}
	}
	/* Check for encapsulated proto range - it is possible to be
	 * any value for u_short range.
	 * if_ether.h:  ETH_ZLEN        60   -  Min. octets in frame sans FCS
	 */
	if (GET_BITMASK(EBT_VLAN_ENCAP)) {
		if ((unsigned short) ntohs(info->encap) < ETH_ZLEN) {
			pr_debug("encap frame length %d is less than "
				 "minimal\n", ntohs(info->encap));
			return -EINVAL;
		}
	}

	return 0;
}

