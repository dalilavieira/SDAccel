#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  id; } ;
union nf_conntrack_man_proto {TYPE_1__ icmp; } ;
typedef  unsigned int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct TYPE_12__ {int /*<<< orphan*/  id; } ;
struct TYPE_13__ {TYPE_4__ icmp; } ;
struct TYPE_10__ {int /*<<< orphan*/  id; } ;
struct TYPE_11__ {TYPE_2__ icmp; } ;
struct nf_nat_range2 {int flags; TYPE_5__ min_proto; TYPE_3__ max_proto; } ;
struct nf_nat_l3proto {int /*<<< orphan*/  (* csum_update ) (struct sk_buff*,unsigned int,int /*<<< orphan*/ *,struct nf_conntrack_tuple const*,int) ;} ;
struct TYPE_14__ {int /*<<< orphan*/  id; } ;
struct TYPE_15__ {TYPE_6__ icmp; } ;
struct TYPE_16__ {TYPE_7__ u; } ;
struct nf_conntrack_tuple {TYPE_8__ src; } ;
struct nf_conn {int dummy; } ;
struct icmp6hdr {scalar_t__ icmp6_type; int /*<<< orphan*/  icmp6_identifier; int /*<<< orphan*/  icmp6_cksum; } ;
typedef  enum nf_nat_manip_type { ____Placeholder_nf_nat_manip_type } nf_nat_manip_type ;

/* Variables and functions */
 scalar_t__ ICMPV6_ECHO_REPLY ; 
 scalar_t__ ICMPV6_ECHO_REQUEST ; 
 int NF_NAT_RANGE_PROTO_SPECIFIED ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  inet_proto_csum_replace2 (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nf_nat_used_tuple (struct nf_conntrack_tuple*,struct nf_conn const*) ; 
 int ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  stub1 (struct sk_buff*,unsigned int,int /*<<< orphan*/ *,struct nf_conntrack_tuple const*,int) ; 

__attribute__((used)) static bool
icmpv6_in_range(const struct nf_conntrack_tuple *tuple,
		enum nf_nat_manip_type maniptype,
		const union nf_conntrack_man_proto *min,
		const union nf_conntrack_man_proto *max)
{
	return ntohs(tuple->src.u.icmp.id) >= ntohs(min->icmp.id) &&
	       ntohs(tuple->src.u.icmp.id) <= ntohs(max->icmp.id);
}

__attribute__((used)) static void
icmpv6_unique_tuple(const struct nf_nat_l3proto *l3proto,
		    struct nf_conntrack_tuple *tuple,
		    const struct nf_nat_range2 *range,
		    enum nf_nat_manip_type maniptype,
		    const struct nf_conn *ct)
{
	static u16 id;
	unsigned int range_size;
	unsigned int i;

	range_size = ntohs(range->max_proto.icmp.id) -
		     ntohs(range->min_proto.icmp.id) + 1;

	if (!(range->flags & NF_NAT_RANGE_PROTO_SPECIFIED))
		range_size = 0xffff;

	for (i = 0; ; ++id) {
		tuple->src.u.icmp.id = htons(ntohs(range->min_proto.icmp.id) +
					     (id % range_size));
		if (++i == range_size || !nf_nat_used_tuple(tuple, ct))
			return;
	}
}

__attribute__((used)) static bool
icmpv6_manip_pkt(struct sk_buff *skb,
		 const struct nf_nat_l3proto *l3proto,
		 unsigned int iphdroff, unsigned int hdroff,
		 const struct nf_conntrack_tuple *tuple,
		 enum nf_nat_manip_type maniptype)
{
	struct icmp6hdr *hdr;

	if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
		return false;

	hdr = (struct icmp6hdr *)(skb->data + hdroff);
	l3proto->csum_update(skb, iphdroff, &hdr->icmp6_cksum,
			     tuple, maniptype);
	if (hdr->icmp6_type == ICMPV6_ECHO_REQUEST ||
	    hdr->icmp6_type == ICMPV6_ECHO_REPLY) {
		inet_proto_csum_replace2(&hdr->icmp6_cksum, skb,
					 hdr->icmp6_identifier,
					 tuple->src.u.icmp.id, false);
		hdr->icmp6_identifier = tuple->src.u.icmp.id;
	}
	return true;
}

