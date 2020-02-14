#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_13__ ;
typedef  struct TYPE_14__   TYPE_10__ ;

/* Type definitions */
struct TYPE_24__ {scalar_t__ a4; } ;
typedef  TYPE_9__ xfrm_address_t ;
struct TYPE_22__ {scalar_t__ a4; } ;
struct TYPE_20__ {scalar_t__ a4; } ;
struct TYPE_21__ {TYPE_5__ daddr; } ;
struct xfrm_tmpl {int /*<<< orphan*/  reqid; int /*<<< orphan*/  mode; TYPE_7__ saddr; TYPE_6__ id; } ;
struct TYPE_23__ {void* family; int /*<<< orphan*/  reqid; int /*<<< orphan*/  mode; TYPE_7__ saddr; int /*<<< orphan*/  flags; } ;
struct xfrm_state {TYPE_8__ props; TYPE_6__ id; } ;
struct TYPE_19__ {int /*<<< orphan*/  a4; } ;
struct TYPE_18__ {int /*<<< orphan*/  a4; } ;
struct xfrm_selector {int prefixlen_d; int prefixlen_s; int /*<<< orphan*/  ifindex; int /*<<< orphan*/  proto; void* family; void* sport_mask; int /*<<< orphan*/  sport; void* dport_mask; int /*<<< orphan*/  dport; TYPE_4__ saddr; TYPE_3__ daddr; } ;
struct sk_buff {int dummy; } ;
struct iphdr {int ihl; int /*<<< orphan*/  ttl; int /*<<< orphan*/  tos; int /*<<< orphan*/  frag_off; int /*<<< orphan*/  id; } ;
struct flowi4 {int /*<<< orphan*/  flowi4_oif; int /*<<< orphan*/  flowi4_proto; int /*<<< orphan*/  uli; int /*<<< orphan*/  saddr; int /*<<< orphan*/  daddr; } ;
struct TYPE_17__ {struct flowi4 ip4; } ;
struct flowi {TYPE_2__ u; } ;
struct TYPE_16__ {scalar_t__ sysctl_ip_no_pmtu_disc; } ;
struct TYPE_15__ {int ihl; int optlen; int /*<<< orphan*/  flow_lbl; int /*<<< orphan*/  ttl; int /*<<< orphan*/  tos; int /*<<< orphan*/  frag_off; int /*<<< orphan*/  id; } ;
struct TYPE_14__ {TYPE_1__ ipv4; } ;

/* Variables and functions */
 void* AF_INET ; 
 TYPE_13__* XFRM_MODE_SKB_CB (struct sk_buff*) ; 
 int /*<<< orphan*/  XFRM_STATE_NOPMTUDISC ; 
 void* htons (int) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  xfrm_flowi_dport (struct flowi const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfrm_flowi_sport (struct flowi const*,int /*<<< orphan*/ *) ; 
 TYPE_10__* xs_net (struct xfrm_state*) ; 

__attribute__((used)) static int xfrm4_init_flags(struct xfrm_state *x)
{
	if (xs_net(x)->ipv4.sysctl_ip_no_pmtu_disc)
		x->props.flags |= XFRM_STATE_NOPMTUDISC;
	return 0;
}

__attribute__((used)) static void
__xfrm4_init_tempsel(struct xfrm_selector *sel, const struct flowi *fl)
{
	const struct flowi4 *fl4 = &fl->u.ip4;

	sel->daddr.a4 = fl4->daddr;
	sel->saddr.a4 = fl4->saddr;
	sel->dport = xfrm_flowi_dport(fl, &fl4->uli);
	sel->dport_mask = htons(0xffff);
	sel->sport = xfrm_flowi_sport(fl, &fl4->uli);
	sel->sport_mask = htons(0xffff);
	sel->family = AF_INET;
	sel->prefixlen_d = 32;
	sel->prefixlen_s = 32;
	sel->proto = fl4->flowi4_proto;
	sel->ifindex = fl4->flowi4_oif;
}

__attribute__((used)) static void
xfrm4_init_temprop(struct xfrm_state *x, const struct xfrm_tmpl *tmpl,
		   const xfrm_address_t *daddr, const xfrm_address_t *saddr)
{
	x->id = tmpl->id;
	if (x->id.daddr.a4 == 0)
		x->id.daddr.a4 = daddr->a4;
	x->props.saddr = tmpl->saddr;
	if (x->props.saddr.a4 == 0)
		x->props.saddr.a4 = saddr->a4;
	x->props.mode = tmpl->mode;
	x->props.reqid = tmpl->reqid;
	x->props.family = AF_INET;
}

int xfrm4_extract_header(struct sk_buff *skb)
{
	const struct iphdr *iph = ip_hdr(skb);

	XFRM_MODE_SKB_CB(skb)->ihl = sizeof(*iph);
	XFRM_MODE_SKB_CB(skb)->id = iph->id;
	XFRM_MODE_SKB_CB(skb)->frag_off = iph->frag_off;
	XFRM_MODE_SKB_CB(skb)->tos = iph->tos;
	XFRM_MODE_SKB_CB(skb)->ttl = iph->ttl;
	XFRM_MODE_SKB_CB(skb)->optlen = iph->ihl * 4 - sizeof(*iph);
	memset(XFRM_MODE_SKB_CB(skb)->flow_lbl, 0,
	       sizeof(XFRM_MODE_SKB_CB(skb)->flow_lbl));

	return 0;
}

