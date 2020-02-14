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
typedef  unsigned char const u_int8_t ;
typedef  int u_int16_t ;
struct xt_mtchk_param {struct xt_dccp_info* matchinfo; } ;
struct xt_dccp_info {scalar_t__* spts; int flags; int invflags; scalar_t__* dpts; int typemask; unsigned char option; } ;
struct xt_action_param {scalar_t__ fragoff; unsigned int thoff; int hotdrop; struct xt_dccp_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct dccp_hdr {int dccph_doff; int dccph_type; int /*<<< orphan*/  dccph_dport; int /*<<< orphan*/  dccph_sport; } ;
typedef  int /*<<< orphan*/  _dh ;

/* Variables and functions */
 scalar_t__ DCCHECK (int,int /*<<< orphan*/ ,int,int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  XT_DCCP_DEST_PORTS ; 
 int /*<<< orphan*/  XT_DCCP_OPTION ; 
 int /*<<< orphan*/  XT_DCCP_SRC_PORTS ; 
 int /*<<< orphan*/  XT_DCCP_TYPE ; 
 int XT_DCCP_VALID_FLAGS ; 
 int __dccp_hdr_len (struct dccp_hdr const*) ; 
 int /*<<< orphan*/  dccp_buflock ; 
 struct dccp_hdr* dccp_optbuf ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 void* skb_header_pointer (struct sk_buff const*,unsigned int,int,struct dccp_hdr*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool
dccp_find_option(u_int8_t option,
		 const struct sk_buff *skb,
		 unsigned int protoff,
		 const struct dccp_hdr *dh,
		 bool *hotdrop)
{
	/* tcp.doff is only 4 bits, ie. max 15 * 4 bytes */
	const unsigned char *op;
	unsigned int optoff = __dccp_hdr_len(dh);
	unsigned int optlen = dh->dccph_doff*4 - __dccp_hdr_len(dh);
	unsigned int i;

	if (dh->dccph_doff * 4 < __dccp_hdr_len(dh))
		goto invalid;

	if (!optlen)
		return false;

	spin_lock_bh(&dccp_buflock);
	op = skb_header_pointer(skb, protoff + optoff, optlen, dccp_optbuf);
	if (op == NULL) {
		/* If we don't have the whole header, drop packet. */
		goto partial;
	}

	for (i = 0; i < optlen; ) {
		if (op[i] == option) {
			spin_unlock_bh(&dccp_buflock);
			return true;
		}

		if (op[i] < 2)
			i++;
		else
			i += op[i+1]?:1;
	}

	spin_unlock_bh(&dccp_buflock);
	return false;

partial:
	spin_unlock_bh(&dccp_buflock);
invalid:
	*hotdrop = true;
	return false;
}

__attribute__((used)) static inline bool
match_types(const struct dccp_hdr *dh, u_int16_t typemask)
{
	return typemask & (1 << dh->dccph_type);
}

__attribute__((used)) static inline bool
match_option(u_int8_t option, const struct sk_buff *skb, unsigned int protoff,
	     const struct dccp_hdr *dh, bool *hotdrop)
{
	return dccp_find_option(option, skb, protoff, dh, hotdrop);
}

__attribute__((used)) static bool
dccp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_dccp_info *info = par->matchinfo;
	const struct dccp_hdr *dh;
	struct dccp_hdr _dh;

	if (par->fragoff != 0)
		return false;

	dh = skb_header_pointer(skb, par->thoff, sizeof(_dh), &_dh);
	if (dh == NULL) {
		par->hotdrop = true;
		return false;
	}

	return  DCCHECK(ntohs(dh->dccph_sport) >= info->spts[0]
			&& ntohs(dh->dccph_sport) <= info->spts[1],
			XT_DCCP_SRC_PORTS, info->flags, info->invflags)
		&& DCCHECK(ntohs(dh->dccph_dport) >= info->dpts[0]
			&& ntohs(dh->dccph_dport) <= info->dpts[1],
			XT_DCCP_DEST_PORTS, info->flags, info->invflags)
		&& DCCHECK(match_types(dh, info->typemask),
			   XT_DCCP_TYPE, info->flags, info->invflags)
		&& DCCHECK(match_option(info->option, skb, par->thoff, dh,
					&par->hotdrop),
			   XT_DCCP_OPTION, info->flags, info->invflags);
}

__attribute__((used)) static int dccp_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_dccp_info *info = par->matchinfo;

	if (info->flags & ~XT_DCCP_VALID_FLAGS)
		return -EINVAL;
	if (info->invflags & ~XT_DCCP_VALID_FLAGS)
		return -EINVAL;
	if (info->invflags & ~info->flags)
		return -EINVAL;
	return 0;
}

