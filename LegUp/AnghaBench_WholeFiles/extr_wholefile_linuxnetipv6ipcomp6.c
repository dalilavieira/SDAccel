#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_8__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  const xfrm_address_t ;
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct TYPE_10__ {TYPE_6__* a6; } ;
struct TYPE_13__ {int mode; scalar_t__ header_len; TYPE_2__ saddr; int /*<<< orphan*/  family; } ;
struct TYPE_11__ {TYPE_6__* a6; } ;
struct TYPE_12__ {TYPE_3__ daddr; int /*<<< orphan*/  spi; int /*<<< orphan*/  proto; } ;
struct TYPE_14__ {int m; int v; } ;
struct TYPE_9__ {int /*<<< orphan*/  state; } ;
struct xfrm_state {TYPE_5__ props; int /*<<< orphan*/  tunnel_users; struct xfrm_state* tunnel; TYPE_4__ id; TYPE_6__ mark; TYPE_1__ km; TYPE_6__ sel; } ;
struct sk_buff {int mark; TYPE_8__* dev; scalar_t__ data; } ;
struct net {int dummy; } ;
struct ipv6hdr {int /*<<< orphan*/  daddr; } ;
struct ip_comp_hdr {int /*<<< orphan*/  cpi; } ;
struct inet6_skb_parm {int dummy; } ;
struct in6_addr {int dummy; } ;
typedef  scalar_t__ __be32 ;
struct TYPE_15__ {int /*<<< orphan*/  ifindex; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET6 ; 
 int EINVAL ; 
 scalar_t__ ICMPV6_PKT_TOOBIG ; 
 int /*<<< orphan*/  IPPROTO_COMP ; 
 int /*<<< orphan*/  IPPROTO_IPV6 ; 
 scalar_t__ NDISC_REDIRECT ; 
#define  XFRM_MODE_TRANSPORT 129 
#define  XFRM_MODE_TUNNEL 128 
 int /*<<< orphan*/  XFRM_STATE_DEAD ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 struct net* dev_net (TYPE_8__*) ; 
 scalar_t__ htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip6_redirect (struct sk_buff*,struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip6_update_pmtu (struct sk_buff*,struct net*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ipcomp_init_state (struct xfrm_state*) ; 
 int /*<<< orphan*/  memcpy (TYPE_6__*,TYPE_6__*,int) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_net_uid (struct net*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfrm6_tunnel_alloc_spi (struct net*,int /*<<< orphan*/  const*) ; 
 scalar_t__ xfrm6_tunnel_spi_lookup (struct net*,int /*<<< orphan*/  const*) ; 
 scalar_t__ xfrm_init_state (struct xfrm_state*) ; 
 struct xfrm_state* xfrm_state_alloc (struct net*) ; 
 int /*<<< orphan*/  xfrm_state_hold (struct xfrm_state*) ; 
 int /*<<< orphan*/  xfrm_state_insert (struct xfrm_state*) ; 
 struct xfrm_state* xfrm_state_lookup (struct net*,int,int /*<<< orphan*/  const*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfrm_state_put (struct xfrm_state*) ; 
 struct net* xs_net (struct xfrm_state*) ; 

__attribute__((used)) static int ipcomp6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
				u8 type, u8 code, int offset, __be32 info)
{
	struct net *net = dev_net(skb->dev);
	__be32 spi;
	const struct ipv6hdr *iph = (const struct ipv6hdr *)skb->data;
	struct ip_comp_hdr *ipcomph =
		(struct ip_comp_hdr *)(skb->data + offset);
	struct xfrm_state *x;

	if (type != ICMPV6_PKT_TOOBIG &&
	    type != NDISC_REDIRECT)
		return 0;

	spi = htonl(ntohs(ipcomph->cpi));
	x = xfrm_state_lookup(net, skb->mark, (const xfrm_address_t *)&iph->daddr,
			      spi, IPPROTO_COMP, AF_INET6);
	if (!x)
		return 0;

	if (type == NDISC_REDIRECT)
		ip6_redirect(skb, net, skb->dev->ifindex, 0,
			     sock_net_uid(net, NULL));
	else
		ip6_update_pmtu(skb, net, info, 0, 0, sock_net_uid(net, NULL));
	xfrm_state_put(x);

	return 0;
}

__attribute__((used)) static struct xfrm_state *ipcomp6_tunnel_create(struct xfrm_state *x)
{
	struct net *net = xs_net(x);
	struct xfrm_state *t = NULL;

	t = xfrm_state_alloc(net);
	if (!t)
		goto out;

	t->id.proto = IPPROTO_IPV6;
	t->id.spi = xfrm6_tunnel_alloc_spi(net, (xfrm_address_t *)&x->props.saddr);
	if (!t->id.spi)
		goto error;

	memcpy(t->id.daddr.a6, x->id.daddr.a6, sizeof(struct in6_addr));
	memcpy(&t->sel, &x->sel, sizeof(t->sel));
	t->props.family = AF_INET6;
	t->props.mode = x->props.mode;
	memcpy(t->props.saddr.a6, x->props.saddr.a6, sizeof(struct in6_addr));
	memcpy(&t->mark, &x->mark, sizeof(t->mark));

	if (xfrm_init_state(t))
		goto error;

	atomic_set(&t->tunnel_users, 1);

out:
	return t;

error:
	t->km.state = XFRM_STATE_DEAD;
	xfrm_state_put(t);
	t = NULL;
	goto out;
}

__attribute__((used)) static int ipcomp6_tunnel_attach(struct xfrm_state *x)
{
	struct net *net = xs_net(x);
	int err = 0;
	struct xfrm_state *t = NULL;
	__be32 spi;
	u32 mark = x->mark.m & x->mark.v;

	spi = xfrm6_tunnel_spi_lookup(net, (xfrm_address_t *)&x->props.saddr);
	if (spi)
		t = xfrm_state_lookup(net, mark, (xfrm_address_t *)&x->id.daddr,
					      spi, IPPROTO_IPV6, AF_INET6);
	if (!t) {
		t = ipcomp6_tunnel_create(x);
		if (!t) {
			err = -EINVAL;
			goto out;
		}
		xfrm_state_insert(t);
		xfrm_state_hold(t);
	}
	x->tunnel = t;
	atomic_inc(&t->tunnel_users);

out:
	return err;
}

__attribute__((used)) static int ipcomp6_init_state(struct xfrm_state *x)
{
	int err = -EINVAL;

	x->props.header_len = 0;
	switch (x->props.mode) {
	case XFRM_MODE_TRANSPORT:
		break;
	case XFRM_MODE_TUNNEL:
		x->props.header_len += sizeof(struct ipv6hdr);
		break;
	default:
		goto out;
	}

	err = ipcomp_init_state(x);
	if (err)
		goto out;

	if (x->props.mode == XFRM_MODE_TUNNEL) {
		err = ipcomp6_tunnel_attach(x);
		if (err)
			goto out;
	}

	err = 0;
out:
	return err;
}

__attribute__((used)) static int ipcomp6_rcv_cb(struct sk_buff *skb, int err)
{
	return 0;
}

