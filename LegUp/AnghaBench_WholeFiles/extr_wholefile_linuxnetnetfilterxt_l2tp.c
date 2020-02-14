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
union l2tp_val {scalar_t__ val32; int /*<<< orphan*/ * val16; } ;
typedef  int u8 ;
typedef  void* u32 ;
typedef  int u16 ;
struct xt_mtchk_param {struct ipt_entry* entryinfo; struct xt_l2tp_info* matchinfo; } ;
struct xt_l2tp_info {int flags; scalar_t__ type; int version; scalar_t__ tid; scalar_t__ sid; } ;
struct xt_action_param {scalar_t__ fragoff; int thoff; struct xt_l2tp_info* matchinfo; } ;
struct udphdr {int dummy; } ;
struct sk_buff {int dummy; } ;
struct l2tp_data {scalar_t__ type; int version; scalar_t__ tid; scalar_t__ sid; int /*<<< orphan*/  member_0; } ;
struct ipt_ip {int const proto; } ;
struct ipt_entry {struct ipt_ip ip; } ;
struct iphdr {int protocol; } ;
typedef  int /*<<< orphan*/  lhbuf ;

/* Variables and functions */
 int EINVAL ; 
#define  IPPROTO_L2TP 129 
#define  IPPROTO_UDP 128 
 int L2TP_HDR_L_BIT ; 
 int L2TP_HDR_T_BIT ; 
 int L2TP_HDR_VER ; 
 int XT_L2TP_SID ; 
 int XT_L2TP_TID ; 
 int XT_L2TP_TYPE ; 
 scalar_t__ XT_L2TP_TYPE_CONTROL ; 
 scalar_t__ XT_L2TP_TYPE_DATA ; 
 int XT_L2TP_VERSION ; 
 struct iphdr* ip_hdr (struct sk_buff const*) ; 
 void* ntohl (scalar_t__) ; 
 int ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,...) ; 
 union l2tp_val* skb_header_pointer (struct sk_buff const*,int,int,union l2tp_val*) ; 

__attribute__((used)) static bool l2tp_match(const struct xt_l2tp_info *info, struct l2tp_data *data)
{
	if ((info->flags & XT_L2TP_TYPE) && (info->type != data->type))
		return false;

	if ((info->flags & XT_L2TP_VERSION) && (info->version != data->version))
		return false;

	/* Check tid only for L2TPv3 control or any L2TPv2 packets */
	if ((info->flags & XT_L2TP_TID) &&
	    ((data->type == XT_L2TP_TYPE_CONTROL) || (data->version == 2)) &&
	    (info->tid != data->tid))
		return false;

	/* Check sid only for L2TP data packets */
	if ((info->flags & XT_L2TP_SID) && (data->type == XT_L2TP_TYPE_DATA) &&
	    (info->sid != data->sid))
		return false;

	return true;
}

__attribute__((used)) static bool l2tp_udp_mt(const struct sk_buff *skb, struct xt_action_param *par, u16 thoff)
{
	const struct xt_l2tp_info *info = par->matchinfo;
	int uhlen = sizeof(struct udphdr);
	int offs = thoff + uhlen;
	union l2tp_val *lh;
	union l2tp_val lhbuf;
	u16 flags;
	struct l2tp_data data = { 0, };

	if (par->fragoff != 0)
		return false;

	/* Extract L2TP header fields. The flags in the first 16 bits
	 * tell us where the other fields are.
	 */
	lh = skb_header_pointer(skb, offs, 2, &lhbuf);
	if (lh == NULL)
		return false;

	flags = ntohs(lh->val16[0]);
	if (flags & L2TP_HDR_T_BIT)
		data.type = XT_L2TP_TYPE_CONTROL;
	else
		data.type = XT_L2TP_TYPE_DATA;
	data.version = (u8) flags & L2TP_HDR_VER;

	/* Now extract the L2TP tid/sid. These are in different places
	 * for L2TPv2 (rfc2661) and L2TPv3 (rfc3931). For L2TPv2, we
	 * must also check to see if the length field is present,
	 * since this affects the offsets into the packet of the
	 * tid/sid fields.
	 */
	if (data.version == 3) {
		lh = skb_header_pointer(skb, offs + 4, 4, &lhbuf);
		if (lh == NULL)
			return false;
		if (data.type == XT_L2TP_TYPE_CONTROL)
			data.tid = ntohl(lh->val32);
		else
			data.sid = ntohl(lh->val32);
	} else if (data.version == 2) {
		if (flags & L2TP_HDR_L_BIT)
			offs += 2;
		lh = skb_header_pointer(skb, offs + 2, 4, &lhbuf);
		if (lh == NULL)
			return false;
		data.tid = (u32) ntohs(lh->val16[0]);
		data.sid = (u32) ntohs(lh->val16[1]);
	} else
		return false;

	return l2tp_match(info, &data);
}

__attribute__((used)) static bool l2tp_ip_mt(const struct sk_buff *skb, struct xt_action_param *par, u16 thoff)
{
	const struct xt_l2tp_info *info = par->matchinfo;
	union l2tp_val *lh;
	union l2tp_val lhbuf;
	struct l2tp_data data = { 0, };

	/* For IP encap, the L2TP sid is the first 32-bits. */
	lh = skb_header_pointer(skb, thoff, sizeof(lhbuf), &lhbuf);
	if (lh == NULL)
		return false;
	if (lh->val32 == 0) {
		/* Must be a control packet. The L2TP tid is further
		 * into the packet.
		 */
		data.type = XT_L2TP_TYPE_CONTROL;
		lh = skb_header_pointer(skb, thoff + 8, sizeof(lhbuf),
					&lhbuf);
		if (lh == NULL)
			return false;
		data.tid = ntohl(lh->val32);
	} else {
		data.sid = ntohl(lh->val32);
		data.type = XT_L2TP_TYPE_DATA;
	}

	data.version = 3;

	return l2tp_match(info, &data);
}

__attribute__((used)) static bool l2tp_mt4(const struct sk_buff *skb, struct xt_action_param *par)
{
	struct iphdr *iph = ip_hdr(skb);
	u8 ipproto = iph->protocol;

	/* l2tp_mt_check4 already restricts the transport protocol */
	switch (ipproto) {
	case IPPROTO_UDP:
		return l2tp_udp_mt(skb, par, par->thoff);
	case IPPROTO_L2TP:
		return l2tp_ip_mt(skb, par, par->thoff);
	}

	return false;
}

__attribute__((used)) static int l2tp_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_l2tp_info *info = par->matchinfo;

	/* Check for invalid flags */
	if (info->flags & ~(XT_L2TP_TID | XT_L2TP_SID | XT_L2TP_VERSION |
			    XT_L2TP_TYPE)) {
		pr_info_ratelimited("unknown flags: %x\n", info->flags);
		return -EINVAL;
	}

	/* At least one of tid, sid or type=control must be specified */
	if ((!(info->flags & XT_L2TP_TID)) &&
	    (!(info->flags & XT_L2TP_SID)) &&
	    ((!(info->flags & XT_L2TP_TYPE)) ||
	     (info->type != XT_L2TP_TYPE_CONTROL))) {
		pr_info_ratelimited("invalid flags combination: %x\n",
				    info->flags);
		return -EINVAL;
	}

	/* If version 2 is specified, check that incompatible params
	 * are not supplied
	 */
	if (info->flags & XT_L2TP_VERSION) {
		if ((info->version < 2) || (info->version > 3)) {
			pr_info_ratelimited("wrong L2TP version: %u\n",
					    info->version);
			return -EINVAL;
		}

		if (info->version == 2) {
			if ((info->flags & XT_L2TP_TID) &&
			    (info->tid > 0xffff)) {
				pr_info_ratelimited("v2 tid > 0xffff: %u\n",
						    info->tid);
				return -EINVAL;
			}
			if ((info->flags & XT_L2TP_SID) &&
			    (info->sid > 0xffff)) {
				pr_info_ratelimited("v2 sid > 0xffff: %u\n",
						    info->sid);
				return -EINVAL;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int l2tp_mt_check4(const struct xt_mtchk_param *par)
{
	const struct xt_l2tp_info *info = par->matchinfo;
	const struct ipt_entry *e = par->entryinfo;
	const struct ipt_ip *ip = &e->ip;
	int ret;

	ret = l2tp_mt_check(par);
	if (ret != 0)
		return ret;

	if ((ip->proto != IPPROTO_UDP) &&
	    (ip->proto != IPPROTO_L2TP)) {
		pr_info_ratelimited("missing protocol rule (udp|l2tpip)\n");
		return -EINVAL;
	}

	if ((ip->proto == IPPROTO_L2TP) &&
	    (info->version == 2)) {
		pr_info_ratelimited("v2 doesn't support IP mode\n");
		return -EINVAL;
	}

	return 0;
}

