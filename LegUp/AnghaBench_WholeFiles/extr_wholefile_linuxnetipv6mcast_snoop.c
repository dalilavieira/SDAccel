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
typedef  scalar_t__ u8 ;
struct sk_buff {unsigned int len; } ;
struct mld_msg {int mld_type; int /*<<< orphan*/  mld_mca; } ;
struct mld2_report {int dummy; } ;
struct mld2_query {int dummy; } ;
struct ipv6hdr {int version; scalar_t__ nexthdr; int /*<<< orphan*/  payload_len; int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
typedef  int /*<<< orphan*/  __sum16 ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMSG ; 
#define  ICMPV6_MGM_QUERY 131 
#define  ICMPV6_MGM_REDUCTION 130 
#define  ICMPV6_MGM_REPORT 129 
#define  ICMPV6_MLD2_REPORT 128 
 scalar_t__ IPPROTO_HOPOPTS ; 
 scalar_t__ IPPROTO_ICMPV6 ; 
 int IPV6_ADDR_LINKLOCAL ; 
 int /*<<< orphan*/  ip6_compute_pseudo ; 
 scalar_t__ ipv6_addr_any (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ipv6_addr_is_ll_all_nodes (int /*<<< orphan*/ *) ; 
 int ipv6_addr_type (int /*<<< orphan*/ *) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff*) ; 
 int ipv6_skip_exthdr (struct sk_buff*,int,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 unsigned int ntohs (int /*<<< orphan*/ ) ; 
 scalar_t__ pskb_may_pull (struct sk_buff*,unsigned int) ; 
 struct sk_buff* skb_checksum_trimmed (struct sk_buff*,unsigned int,int /*<<< orphan*/  (*) (struct sk_buff*)) ; 
 int /*<<< orphan*/  skb_checksum_validate (struct sk_buff*,scalar_t__,int /*<<< orphan*/ ) ; 
 int skb_network_offset (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_transport_header (struct sk_buff*,int) ; 
 scalar_t__ skb_transport_header (struct sk_buff*) ; 
 int skb_transport_offset (struct sk_buff*) ; 

__attribute__((used)) static int ipv6_mc_check_ip6hdr(struct sk_buff *skb)
{
	const struct ipv6hdr *ip6h;
	unsigned int len;
	unsigned int offset = skb_network_offset(skb) + sizeof(*ip6h);

	if (!pskb_may_pull(skb, offset))
		return -EINVAL;

	ip6h = ipv6_hdr(skb);

	if (ip6h->version != 6)
		return -EINVAL;

	len = offset + ntohs(ip6h->payload_len);
	if (skb->len < len || len <= offset)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int ipv6_mc_check_exthdrs(struct sk_buff *skb)
{
	const struct ipv6hdr *ip6h;
	int offset;
	u8 nexthdr;
	__be16 frag_off;

	ip6h = ipv6_hdr(skb);

	if (ip6h->nexthdr != IPPROTO_HOPOPTS)
		return -ENOMSG;

	nexthdr = ip6h->nexthdr;
	offset = skb_network_offset(skb) + sizeof(*ip6h);
	offset = ipv6_skip_exthdr(skb, offset, &nexthdr, &frag_off);

	if (offset < 0)
		return -EINVAL;

	if (nexthdr != IPPROTO_ICMPV6)
		return -ENOMSG;

	skb_set_transport_header(skb, offset);

	return 0;
}

__attribute__((used)) static int ipv6_mc_check_mld_reportv2(struct sk_buff *skb)
{
	unsigned int len = skb_transport_offset(skb);

	len += sizeof(struct mld2_report);

	return pskb_may_pull(skb, len) ? 0 : -EINVAL;
}

__attribute__((used)) static int ipv6_mc_check_mld_query(struct sk_buff *skb)
{
	struct mld_msg *mld;
	unsigned int len = skb_transport_offset(skb);

	/* RFC2710+RFC3810 (MLDv1+MLDv2) require link-local source addresses */
	if (!(ipv6_addr_type(&ipv6_hdr(skb)->saddr) & IPV6_ADDR_LINKLOCAL))
		return -EINVAL;

	len += sizeof(struct mld_msg);
	if (skb->len < len)
		return -EINVAL;

	/* MLDv1? */
	if (skb->len != len) {
		/* or MLDv2? */
		len += sizeof(struct mld2_query) - sizeof(struct mld_msg);
		if (skb->len < len || !pskb_may_pull(skb, len))
			return -EINVAL;
	}

	mld = (struct mld_msg *)skb_transport_header(skb);

	/* RFC2710+RFC3810 (MLDv1+MLDv2) require the multicast link layer
	 * all-nodes destination address (ff02::1) for general queries
	 */
	if (ipv6_addr_any(&mld->mld_mca) &&
	    !ipv6_addr_is_ll_all_nodes(&ipv6_hdr(skb)->daddr))
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int ipv6_mc_check_mld_msg(struct sk_buff *skb)
{
	struct mld_msg *mld = (struct mld_msg *)skb_transport_header(skb);

	switch (mld->mld_type) {
	case ICMPV6_MGM_REDUCTION:
	case ICMPV6_MGM_REPORT:
		/* fall through */
		return 0;
	case ICMPV6_MLD2_REPORT:
		return ipv6_mc_check_mld_reportv2(skb);
	case ICMPV6_MGM_QUERY:
		return ipv6_mc_check_mld_query(skb);
	default:
		return -ENOMSG;
	}
}

__attribute__((used)) static inline __sum16 ipv6_mc_validate_checksum(struct sk_buff *skb)
{
	return skb_checksum_validate(skb, IPPROTO_ICMPV6, ip6_compute_pseudo);
}

__attribute__((used)) static int __ipv6_mc_check_mld(struct sk_buff *skb,
			       struct sk_buff **skb_trimmed)

{
	struct sk_buff *skb_chk = NULL;
	unsigned int transport_len;
	unsigned int len = skb_transport_offset(skb) + sizeof(struct mld_msg);
	int ret = -EINVAL;

	transport_len = ntohs(ipv6_hdr(skb)->payload_len);
	transport_len -= skb_transport_offset(skb) - sizeof(struct ipv6hdr);

	skb_chk = skb_checksum_trimmed(skb, transport_len,
				       ipv6_mc_validate_checksum);
	if (!skb_chk)
		goto err;

	if (!pskb_may_pull(skb_chk, len))
		goto err;

	ret = ipv6_mc_check_mld_msg(skb_chk);
	if (ret)
		goto err;

	if (skb_trimmed)
		*skb_trimmed = skb_chk;
	/* free now unneeded clone */
	else if (skb_chk != skb)
		kfree_skb(skb_chk);

	ret = 0;

err:
	if (ret && skb_chk && skb_chk != skb)
		kfree_skb(skb_chk);

	return ret;
}

int ipv6_mc_check_mld(struct sk_buff *skb, struct sk_buff **skb_trimmed)
{
	int ret;

	ret = ipv6_mc_check_ip6hdr(skb);
	if (ret < 0)
		return ret;

	ret = ipv6_mc_check_exthdrs(skb);
	if (ret < 0)
		return ret;

	return __ipv6_mc_check_mld(skb, skb_trimmed);
}

