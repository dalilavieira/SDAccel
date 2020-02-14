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
typedef  int u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_pktinfo {int dummy; } ;
struct nft_fib {int result; int flags; int /*<<< orphan*/  dreg; } ;
struct nft_expr {int dummy; } ;
struct nft_data {int dummy; } ;
struct nft_ctx {int /*<<< orphan*/  chain; } ;
struct net_device {char* name; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int IFNAMSIZ ; 
 size_t NFTA_FIB_DREG ; 
 size_t NFTA_FIB_FLAGS ; 
 int NFTA_FIB_F_ALL ; 
 int NFTA_FIB_F_DADDR ; 
 int NFTA_FIB_F_IIF ; 
 int NFTA_FIB_F_OIF ; 
 int NFTA_FIB_F_PRESENT ; 
 int NFTA_FIB_F_SADDR ; 
 size_t NFTA_FIB_RESULT ; 
 int /*<<< orphan*/  NFT_DATA_VALUE ; 
#define  NFT_FIB_RESULT_ADDRTYPE 130 
#define  NFT_FIB_RESULT_OIF 129 
#define  NFT_FIB_RESULT_OIFNAME 128 
 int NF_INET_FORWARD ; 
 int NF_INET_LOCAL_IN ; 
 int NF_INET_LOCAL_OUT ; 
 int NF_INET_POST_ROUTING ; 
 int NF_INET_PRE_ROUTING ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 struct net_device* dev_get_by_index_rcu (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int nft_chain_validate_hooks (int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_store (struct nft_ctx const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 void* ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (void*,char*,unsigned int) ; 

int nft_fib_validate(const struct nft_ctx *ctx, const struct nft_expr *expr,
		     const struct nft_data **data)
{
	const struct nft_fib *priv = nft_expr_priv(expr);
	unsigned int hooks;

	switch (priv->result) {
	case NFT_FIB_RESULT_OIF: /* fallthrough */
	case NFT_FIB_RESULT_OIFNAME:
		hooks = (1 << NF_INET_PRE_ROUTING);
		break;
	case NFT_FIB_RESULT_ADDRTYPE:
		if (priv->flags & NFTA_FIB_F_IIF)
			hooks = (1 << NF_INET_PRE_ROUTING) |
				(1 << NF_INET_LOCAL_IN) |
				(1 << NF_INET_FORWARD);
		else if (priv->flags & NFTA_FIB_F_OIF)
			hooks = (1 << NF_INET_LOCAL_OUT) |
				(1 << NF_INET_POST_ROUTING) |
				(1 << NF_INET_FORWARD);
		else
			hooks = (1 << NF_INET_LOCAL_IN) |
				(1 << NF_INET_LOCAL_OUT) |
				(1 << NF_INET_FORWARD) |
				(1 << NF_INET_PRE_ROUTING) |
				(1 << NF_INET_POST_ROUTING);

		break;
	default:
		return -EINVAL;
	}

	return nft_chain_validate_hooks(ctx->chain, hooks);
}

int nft_fib_init(const struct nft_ctx *ctx, const struct nft_expr *expr,
		 const struct nlattr * const tb[])
{
	struct nft_fib *priv = nft_expr_priv(expr);
	unsigned int len;
	int err;

	if (!tb[NFTA_FIB_DREG] || !tb[NFTA_FIB_RESULT] || !tb[NFTA_FIB_FLAGS])
		return -EINVAL;

	priv->flags = ntohl(nla_get_be32(tb[NFTA_FIB_FLAGS]));

	if (priv->flags == 0 || (priv->flags & ~NFTA_FIB_F_ALL))
		return -EINVAL;

	if ((priv->flags & (NFTA_FIB_F_SADDR | NFTA_FIB_F_DADDR)) ==
			   (NFTA_FIB_F_SADDR | NFTA_FIB_F_DADDR))
		return -EINVAL;
	if ((priv->flags & (NFTA_FIB_F_IIF | NFTA_FIB_F_OIF)) ==
			   (NFTA_FIB_F_IIF | NFTA_FIB_F_OIF))
		return -EINVAL;
	if ((priv->flags & (NFTA_FIB_F_SADDR | NFTA_FIB_F_DADDR)) == 0)
		return -EINVAL;

	priv->result = ntohl(nla_get_be32(tb[NFTA_FIB_RESULT]));
	priv->dreg = nft_parse_register(tb[NFTA_FIB_DREG]);

	switch (priv->result) {
	case NFT_FIB_RESULT_OIF:
		if (priv->flags & NFTA_FIB_F_OIF)
			return -EINVAL;
		len = sizeof(int);
		break;
	case NFT_FIB_RESULT_OIFNAME:
		if (priv->flags & NFTA_FIB_F_OIF)
			return -EINVAL;
		len = IFNAMSIZ;
		break;
	case NFT_FIB_RESULT_ADDRTYPE:
		len = sizeof(u32);
		break;
	default:
		return -EINVAL;
	}

	err = nft_validate_register_store(ctx, priv->dreg, NULL,
					  NFT_DATA_VALUE, len);
	if (err < 0)
		return err;

	return 0;
}

int nft_fib_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_fib *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_FIB_DREG, priv->dreg))
		return -1;

	if (nla_put_be32(skb, NFTA_FIB_RESULT, htonl(priv->result)))
		return -1;

	if (nla_put_be32(skb, NFTA_FIB_FLAGS, htonl(priv->flags)))
		return -1;

	return 0;
}

void nft_fib_store_result(void *reg, const struct nft_fib *priv,
			  const struct nft_pktinfo *pkt, int index)
{
	struct net_device *dev;
	u32 *dreg = reg;

	switch (priv->result) {
	case NFT_FIB_RESULT_OIF:
		*dreg = (priv->flags & NFTA_FIB_F_PRESENT) ? !!index : index;
		break;
	case NFT_FIB_RESULT_OIFNAME:
		dev = dev_get_by_index_rcu(nft_net(pkt), index);
		if (priv->flags & NFTA_FIB_F_PRESENT)
			*dreg = !!dev;
		else
			strncpy(reg, dev ? dev->name : "", IFNAMSIZ);
		break;
	default:
		WARN_ON_ONCE(1);
		*dreg = 0;
		break;
	}
}

