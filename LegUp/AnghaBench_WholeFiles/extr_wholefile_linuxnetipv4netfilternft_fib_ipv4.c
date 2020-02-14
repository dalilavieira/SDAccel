#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nlattr {int dummy; } ;
struct TYPE_5__ {void* code; } ;
struct nft_regs {int* data; TYPE_1__ verdict; } ;
struct nft_pktinfo {TYPE_2__* skb; } ;
struct nft_fib {size_t dreg; int flags; int result; } ;
struct nft_expr_ops {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;
typedef  struct net_device {int ifindex; int /*<<< orphan*/  name; } const net_device ;
struct iphdr {void* daddr; void* saddr; int tos; } ;
struct flowi4 {int flowi4_tos; void* daddr; void* saddr; int /*<<< orphan*/  flowi4_mark; int /*<<< orphan*/  flowi4_iif; int /*<<< orphan*/  flowi4_scope; } ;
struct fib_result {int type; } ;
typedef  enum nft_fib_result { ____Placeholder_nft_fib_result } nft_fib_result ;
typedef  int /*<<< orphan*/  _iph ;
typedef  void* __be32 ;
struct TYPE_6__ {int /*<<< orphan*/  mark; struct net_device const* dev; } ;

/* Variables and functions */
 int DSCP_BITS ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EOPNOTSUPP ; 
 struct nft_expr_ops const* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FIB_LOOKUP_IGNORE_LINKSTATE ; 
 struct net_device const* FIB_RES_DEV (struct fib_result) ; 
 int /*<<< orphan*/  IFNAMSIZ ; 
 int /*<<< orphan*/  LOOPBACK_IFINDEX ; 
 int NFTA_FIB_F_DADDR ; 
 int NFTA_FIB_F_IIF ; 
 int NFTA_FIB_F_MARK ; 
 int NFTA_FIB_F_OIF ; 
 size_t NFTA_FIB_RESULT ; 
 void* NFT_BREAK ; 
#define  NFT_FIB_RESULT_ADDRTYPE 132 
#define  NFT_FIB_RESULT_OIF 131 
#define  NFT_FIB_RESULT_OIFNAME 130 
 scalar_t__ NF_INET_PRE_ROUTING ; 
#define  RTN_LOCAL 129 
#define  RTN_UNICAST 128 
 int /*<<< orphan*/  RT_SCOPE_UNIVERSE ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 scalar_t__ fib_lookup (int /*<<< orphan*/ ,struct flowi4*,struct fib_result*,int /*<<< orphan*/ ) ; 
 int inet_dev_addr_type (int /*<<< orphan*/ ,struct net_device const*,void*) ; 
 scalar_t__ ipv4_is_lbcast (void*) ; 
 scalar_t__ ipv4_is_local_multicast (void*) ; 
 scalar_t__ ipv4_is_multicast (void*) ; 
 scalar_t__ ipv4_is_zeronet (void*) ; 
 struct nft_fib* nft_expr_priv (struct nft_expr const*) ; 
 struct nft_expr_ops const nft_fib4_ops ; 
 struct nft_expr_ops const nft_fib4_type_ops ; 
 scalar_t__ nft_fib_is_loopback (TYPE_2__*,struct net_device const*) ; 
 int /*<<< orphan*/  nft_fib_store_result (int*,struct nft_fib const*,struct nft_pktinfo const*,int) ; 
 scalar_t__ nft_hook (struct nft_pktinfo const*) ; 
 struct net_device const* nft_in (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 struct net_device const* nft_out (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 struct iphdr* skb_header_pointer (TYPE_2__*,int,int,struct iphdr*) ; 
 int skb_network_offset (TYPE_2__*) ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __be32 get_saddr(__be32 addr)
{
	if (ipv4_is_multicast(addr) || ipv4_is_lbcast(addr) ||
	    ipv4_is_zeronet(addr))
		return 0;
	return addr;
}

void nft_fib4_eval_type(const struct nft_expr *expr, struct nft_regs *regs,
			const struct nft_pktinfo *pkt)
{
	const struct nft_fib *priv = nft_expr_priv(expr);
	int noff = skb_network_offset(pkt->skb);
	u32 *dst = &regs->data[priv->dreg];
	const struct net_device *dev = NULL;
	struct iphdr *iph, _iph;
	__be32 addr;

	if (priv->flags & NFTA_FIB_F_IIF)
		dev = nft_in(pkt);
	else if (priv->flags & NFTA_FIB_F_OIF)
		dev = nft_out(pkt);

	iph = skb_header_pointer(pkt->skb, noff, sizeof(_iph), &_iph);
	if (!iph) {
		regs->verdict.code = NFT_BREAK;
		return;
	}

	if (priv->flags & NFTA_FIB_F_DADDR)
		addr = iph->daddr;
	else
		addr = iph->saddr;

	*dst = inet_dev_addr_type(nft_net(pkt), dev, addr);
}

__attribute__((used)) static int get_ifindex(const struct net_device *dev)
{
	return dev ? dev->ifindex : 0;
}

void nft_fib4_eval(const struct nft_expr *expr, struct nft_regs *regs,
		   const struct nft_pktinfo *pkt)
{
	const struct nft_fib *priv = nft_expr_priv(expr);
	int noff = skb_network_offset(pkt->skb);
	u32 *dest = &regs->data[priv->dreg];
	struct iphdr *iph, _iph;
	struct fib_result res;
	struct flowi4 fl4 = {
		.flowi4_scope = RT_SCOPE_UNIVERSE,
		.flowi4_iif = LOOPBACK_IFINDEX,
	};
	const struct net_device *oif;
	struct net_device *found;
#ifdef CONFIG_IP_ROUTE_MULTIPATH
	int i;
#endif

	/*
	 * Do not set flowi4_oif, it restricts results (for example, asking
	 * for oif 3 will get RTN_UNICAST result even if the daddr exits
	 * on another interface.
	 *
	 * Search results for the desired outinterface instead.
	 */
	if (priv->flags & NFTA_FIB_F_OIF)
		oif = nft_out(pkt);
	else if (priv->flags & NFTA_FIB_F_IIF)
		oif = nft_in(pkt);
	else
		oif = NULL;

	if (nft_hook(pkt) == NF_INET_PRE_ROUTING &&
	    nft_fib_is_loopback(pkt->skb, nft_in(pkt))) {
		nft_fib_store_result(dest, priv, pkt,
				     nft_in(pkt)->ifindex);
		return;
	}

	iph = skb_header_pointer(pkt->skb, noff, sizeof(_iph), &_iph);
	if (!iph) {
		regs->verdict.code = NFT_BREAK;
		return;
	}

	if (ipv4_is_zeronet(iph->saddr)) {
		if (ipv4_is_lbcast(iph->daddr) ||
		    ipv4_is_local_multicast(iph->daddr)) {
			nft_fib_store_result(dest, priv, pkt,
					     get_ifindex(pkt->skb->dev));
			return;
		}
	}

	if (priv->flags & NFTA_FIB_F_MARK)
		fl4.flowi4_mark = pkt->skb->mark;

	fl4.flowi4_tos = iph->tos & DSCP_BITS;

	if (priv->flags & NFTA_FIB_F_DADDR) {
		fl4.daddr = iph->daddr;
		fl4.saddr = get_saddr(iph->saddr);
	} else {
		fl4.daddr = iph->saddr;
		fl4.saddr = get_saddr(iph->daddr);
	}

	*dest = 0;

	if (fib_lookup(nft_net(pkt), &fl4, &res, FIB_LOOKUP_IGNORE_LINKSTATE))
		return;

	switch (res.type) {
	case RTN_UNICAST:
		break;
	case RTN_LOCAL: /* Should not see RTN_LOCAL here */
		return;
	default:
		break;
	}

       if (!oif) {
               found = FIB_RES_DEV(res);
               goto ok;
       }

#ifdef CONFIG_IP_ROUTE_MULTIPATH
	for (i = 0; i < res.fi->fib_nhs; i++) {
		struct fib_nh *nh = &res.fi->fib_nh[i];

		if (nh->nh_dev == oif) {
			found = nh->nh_dev;
			goto ok;
		}
	}
	return;
#else
	found = FIB_RES_DEV(res);
	if (found != oif)
		return;
#endif
ok:
	switch (priv->result) {
	case NFT_FIB_RESULT_OIF:
		*dest = found->ifindex;
		break;
	case NFT_FIB_RESULT_OIFNAME:
		strncpy((char *)dest, found->name, IFNAMSIZ);
		break;
	default:
		WARN_ON_ONCE(1);
		break;
	}
}

__attribute__((used)) static const struct nft_expr_ops *
nft_fib4_select_ops(const struct nft_ctx *ctx,
		    const struct nlattr * const tb[])
{
	enum nft_fib_result result;

	if (!tb[NFTA_FIB_RESULT])
		return ERR_PTR(-EINVAL);

	result = ntohl(nla_get_be32(tb[NFTA_FIB_RESULT]));

	switch (result) {
	case NFT_FIB_RESULT_OIF:
		return &nft_fib4_ops;
	case NFT_FIB_RESULT_OIFNAME:
		return &nft_fib4_ops;
	case NFT_FIB_RESULT_ADDRTYPE:
		return &nft_fib4_type_ops;
	default:
		return ERR_PTR(-EOPNOTSUPP);
	}
}

