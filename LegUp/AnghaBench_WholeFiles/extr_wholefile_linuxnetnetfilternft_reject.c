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
typedef  size_t u8 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_reject {int type; int /*<<< orphan*/  icmp_code; } ;
struct nft_expr {int dummy; } ;
struct nft_data {int dummy; } ;
struct nft_ctx {int /*<<< orphan*/  chain; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EINVAL ; 
 size_t NFTA_REJECT_ICMP_CODE ; 
 size_t NFTA_REJECT_TYPE ; 
 size_t NFT_REJECT_ICMPX_MAX ; 
#define  NFT_REJECT_ICMP_UNREACH 129 
#define  NFT_REJECT_TCP_RST 128 
 int NF_INET_FORWARD ; 
 int NF_INET_LOCAL_IN ; 
 int NF_INET_LOCAL_OUT ; 
 int /*<<< orphan*/  htonl (int) ; 
 int* icmp_code_v4 ; 
 int* icmp_code_v6 ; 
 int nft_chain_validate_hooks (int /*<<< orphan*/ ,int) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 int /*<<< orphan*/  nla_get_u8 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nla_put_u8 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int ntohl (int /*<<< orphan*/ ) ; 

int nft_reject_validate(const struct nft_ctx *ctx,
			const struct nft_expr *expr,
			const struct nft_data **data)
{
	return nft_chain_validate_hooks(ctx->chain,
					(1 << NF_INET_LOCAL_IN) |
					(1 << NF_INET_FORWARD) |
					(1 << NF_INET_LOCAL_OUT));
}

int nft_reject_init(const struct nft_ctx *ctx,
		    const struct nft_expr *expr,
		    const struct nlattr * const tb[])
{
	struct nft_reject *priv = nft_expr_priv(expr);

	if (tb[NFTA_REJECT_TYPE] == NULL)
		return -EINVAL;

	priv->type = ntohl(nla_get_be32(tb[NFTA_REJECT_TYPE]));
	switch (priv->type) {
	case NFT_REJECT_ICMP_UNREACH:
		if (tb[NFTA_REJECT_ICMP_CODE] == NULL)
			return -EINVAL;
		priv->icmp_code = nla_get_u8(tb[NFTA_REJECT_ICMP_CODE]);
	case NFT_REJECT_TCP_RST:
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

int nft_reject_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_reject *priv = nft_expr_priv(expr);

	if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
		goto nla_put_failure;

	switch (priv->type) {
	case NFT_REJECT_ICMP_UNREACH:
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

int nft_reject_icmp_code(u8 code)
{
	BUG_ON(code > NFT_REJECT_ICMPX_MAX);

	return icmp_code_v4[code];
}

int nft_reject_icmpv6_code(u8 code)
{
	BUG_ON(code > NFT_REJECT_ICMPX_MAX);

	return icmp_code_v6[code];
}

