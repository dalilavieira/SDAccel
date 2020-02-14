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
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_reject {int type; int icmp_code; } ;
struct TYPE_2__ {int /*<<< orphan*/  code; } ;
struct nft_regs {TYPE_1__ verdict; } ;
struct nft_pktinfo {int /*<<< orphan*/  skb; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  NFPROTO_IPV4 132 
#define  NFPROTO_IPV6 131 
 size_t NFTA_REJECT_ICMP_CODE ; 
 size_t NFTA_REJECT_TYPE ; 
 int NFT_REJECT_ICMPX_MAX ; 
#define  NFT_REJECT_ICMPX_UNREACH 130 
#define  NFT_REJECT_ICMP_UNREACH 129 
#define  NFT_REJECT_TCP_RST 128 
 int /*<<< orphan*/  NF_DROP ; 
 int /*<<< orphan*/  htonl (int const) ; 
 int /*<<< orphan*/  nf_send_reset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_send_reset6 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_send_unreach (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_send_unreach6 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_hook (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 int nft_pf (struct nft_pktinfo const*) ; 
 int nft_reject_icmp_code (int) ; 
 int nft_reject_icmpv6_code (int) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 int nla_get_u8 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nla_put_u8 (struct sk_buff*,size_t,int) ; 
 int ntohl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nft_reject_inet_eval(const struct nft_expr *expr,
				 struct nft_regs *regs,
				 const struct nft_pktinfo *pkt)
{
	struct nft_reject *priv = nft_expr_priv(expr);

	switch (nft_pf(pkt)) {
	case NFPROTO_IPV4:
		switch (priv->type) {
		case NFT_REJECT_ICMP_UNREACH:
			nf_send_unreach(pkt->skb, priv->icmp_code,
					nft_hook(pkt));
			break;
		case NFT_REJECT_TCP_RST:
			nf_send_reset(nft_net(pkt), pkt->skb, nft_hook(pkt));
			break;
		case NFT_REJECT_ICMPX_UNREACH:
			nf_send_unreach(pkt->skb,
					nft_reject_icmp_code(priv->icmp_code),
					nft_hook(pkt));
			break;
		}
		break;
	case NFPROTO_IPV6:
		switch (priv->type) {
		case NFT_REJECT_ICMP_UNREACH:
			nf_send_unreach6(nft_net(pkt), pkt->skb,
					 priv->icmp_code, nft_hook(pkt));
			break;
		case NFT_REJECT_TCP_RST:
			nf_send_reset6(nft_net(pkt), pkt->skb, nft_hook(pkt));
			break;
		case NFT_REJECT_ICMPX_UNREACH:
			nf_send_unreach6(nft_net(pkt), pkt->skb,
					 nft_reject_icmpv6_code(priv->icmp_code),
					 nft_hook(pkt));
			break;
		}
		break;
	}

	regs->verdict.code = NF_DROP;
}

__attribute__((used)) static int nft_reject_inet_init(const struct nft_ctx *ctx,
				const struct nft_expr *expr,
				const struct nlattr * const tb[])
{
	struct nft_reject *priv = nft_expr_priv(expr);
	int icmp_code;

	if (tb[NFTA_REJECT_TYPE] == NULL)
		return -EINVAL;

	priv->type = ntohl(nla_get_be32(tb[NFTA_REJECT_TYPE]));
	switch (priv->type) {
	case NFT_REJECT_ICMP_UNREACH:
	case NFT_REJECT_ICMPX_UNREACH:
		if (tb[NFTA_REJECT_ICMP_CODE] == NULL)
			return -EINVAL;

		icmp_code = nla_get_u8(tb[NFTA_REJECT_ICMP_CODE]);
		if (priv->type == NFT_REJECT_ICMPX_UNREACH &&
		    icmp_code > NFT_REJECT_ICMPX_MAX)
			return -EINVAL;

		priv->icmp_code = icmp_code;
		break;
	case NFT_REJECT_TCP_RST:
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int nft_reject_inet_dump(struct sk_buff *skb,
				const struct nft_expr *expr)
{
	const struct nft_reject *priv = nft_expr_priv(expr);

	if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
		goto nla_put_failure;

	switch (priv->type) {
	case NFT_REJECT_ICMP_UNREACH:
	case NFT_REJECT_ICMPX_UNREACH:
		if (nla_put_u8(skb, NFTA_REJECT_ICMP_CODE, priv->icmp_code))
			goto nla_put_failure;
		break;
	default:
		break;
	}

	return 0;

nla_put_failure:
	return -1;
}

