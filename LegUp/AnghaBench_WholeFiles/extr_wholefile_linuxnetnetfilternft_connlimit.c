#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_set_ext {int dummy; } ;
struct TYPE_8__ {void* code; } ;
struct nft_regs {TYPE_2__ verdict; } ;
struct nft_pktinfo {int /*<<< orphan*/  skb; } ;
struct nft_object {int dummy; } ;
typedef  struct nft_expr const nft_expr ;
struct nft_ctx {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct TYPE_9__ {unsigned int count; } ;
struct nft_connlimit {unsigned int limit; int invert; TYPE_3__ list; } ;
struct nf_conntrack_zone {int dummy; } ;
struct nf_conntrack_tuple {int dummy; } ;
struct nf_conn {TYPE_1__* tuplehash; } ;
struct net {int dummy; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
struct TYPE_7__ {struct nf_conntrack_tuple tuple; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 size_t IP_CT_DIR_ORIGINAL ; 
 size_t NFTA_CONNLIMIT_COUNT ; 
 size_t NFTA_CONNLIMIT_FLAGS ; 
 void* NFT_BREAK ; 
 int NFT_CONNLIMIT_F_INV ; 
 void* NF_DROP ; 
 int /*<<< orphan*/  htonl (int) ; 
 scalar_t__ nf_conncount_add (int /*<<< orphan*/ ,TYPE_3__*,struct nf_conntrack_tuple const*,struct nf_conntrack_zone const*) ; 
 int /*<<< orphan*/  nf_conncount_cache_free (TYPE_3__*) ; 
 int nf_conncount_gc_list (struct net*,TYPE_3__*) ; 
 int /*<<< orphan*/  nf_conncount_list_init (TYPE_3__*) ; 
 struct nf_conn* nf_ct_get (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  nf_ct_get_tuplepr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nf_conntrack_tuple*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nf_conntrack_zone* nf_ct_zone (struct nf_conn const*) ; 
 struct nf_conntrack_zone nf_ct_zone_dflt ; 
 struct nft_connlimit* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 struct nft_connlimit* nft_obj_data (struct nft_object*) ; 
 int /*<<< orphan*/  nft_pf (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_network_offset (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void nft_connlimit_do_eval(struct nft_connlimit *priv,
					 struct nft_regs *regs,
					 const struct nft_pktinfo *pkt,
					 const struct nft_set_ext *ext)
{
	const struct nf_conntrack_zone *zone = &nf_ct_zone_dflt;
	const struct nf_conntrack_tuple *tuple_ptr;
	struct nf_conntrack_tuple tuple;
	enum ip_conntrack_info ctinfo;
	const struct nf_conn *ct;
	unsigned int count;

	tuple_ptr = &tuple;

	ct = nf_ct_get(pkt->skb, &ctinfo);
	if (ct != NULL) {
		tuple_ptr = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
		zone = nf_ct_zone(ct);
	} else if (!nf_ct_get_tuplepr(pkt->skb, skb_network_offset(pkt->skb),
				      nft_pf(pkt), nft_net(pkt), &tuple)) {
		regs->verdict.code = NF_DROP;
		return;
	}

	if (nf_conncount_add(nft_net(pkt), &priv->list, tuple_ptr, zone)) {
		regs->verdict.code = NF_DROP;
		return;
	}

	count = priv->list.count;

	if ((count > priv->limit) ^ priv->invert) {
		regs->verdict.code = NFT_BREAK;
		return;
	}
}

__attribute__((used)) static int nft_connlimit_do_init(const struct nft_ctx *ctx,
				 const struct nlattr * const tb[],
				 struct nft_connlimit *priv)
{
	bool invert = false;
	u32 flags, limit;

	if (!tb[NFTA_CONNLIMIT_COUNT])
		return -EINVAL;

	limit = ntohl(nla_get_be32(tb[NFTA_CONNLIMIT_COUNT]));

	if (tb[NFTA_CONNLIMIT_FLAGS]) {
		flags = ntohl(nla_get_be32(tb[NFTA_CONNLIMIT_FLAGS]));
		if (flags & ~NFT_CONNLIMIT_F_INV)
			return -EOPNOTSUPP;
		if (flags & NFT_CONNLIMIT_F_INV)
			invert = true;
	}

	nf_conncount_list_init(&priv->list);
	priv->limit	= limit;
	priv->invert	= invert;

	return nf_ct_netns_get(ctx->net, ctx->family);
}

__attribute__((used)) static void nft_connlimit_do_destroy(const struct nft_ctx *ctx,
				     struct nft_connlimit *priv)
{
	nf_ct_netns_put(ctx->net, ctx->family);
	nf_conncount_cache_free(&priv->list);
}

__attribute__((used)) static int nft_connlimit_do_dump(struct sk_buff *skb,
				 struct nft_connlimit *priv)
{
	if (nla_put_be32(skb, NFTA_CONNLIMIT_COUNT, htonl(priv->limit)))
		goto nla_put_failure;
	if (priv->invert &&
	    nla_put_be32(skb, NFTA_CONNLIMIT_FLAGS, htonl(NFT_CONNLIMIT_F_INV)))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static inline void nft_connlimit_obj_eval(struct nft_object *obj,
					struct nft_regs *regs,
					const struct nft_pktinfo *pkt)
{
	struct nft_connlimit *priv = nft_obj_data(obj);

	nft_connlimit_do_eval(priv, regs, pkt, NULL);
}

__attribute__((used)) static int nft_connlimit_obj_init(const struct nft_ctx *ctx,
				const struct nlattr * const tb[],
				struct nft_object *obj)
{
	struct nft_connlimit *priv = nft_obj_data(obj);

	return nft_connlimit_do_init(ctx, tb, priv);
}

__attribute__((used)) static void nft_connlimit_obj_destroy(const struct nft_ctx *ctx,
				      struct nft_object *obj)
{
	struct nft_connlimit *priv = nft_obj_data(obj);

	nft_connlimit_do_destroy(ctx, priv);
}

__attribute__((used)) static int nft_connlimit_obj_dump(struct sk_buff *skb,
				  struct nft_object *obj, bool reset)
{
	struct nft_connlimit *priv = nft_obj_data(obj);

	return nft_connlimit_do_dump(skb, priv);
}

__attribute__((used)) static void nft_connlimit_eval(const struct nft_expr *expr,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	nft_connlimit_do_eval(priv, regs, pkt, NULL);
}

__attribute__((used)) static int nft_connlimit_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	return nft_connlimit_do_dump(skb, priv);
}

__attribute__((used)) static int nft_connlimit_init(const struct nft_ctx *ctx,
			      const struct nft_expr *expr,
			      const struct nlattr * const tb[])
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	return nft_connlimit_do_init(ctx, tb, priv);
}

__attribute__((used)) static void nft_connlimit_destroy(const struct nft_ctx *ctx,
				const struct nft_expr *expr)
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	nft_connlimit_do_destroy(ctx, priv);
}

__attribute__((used)) static int nft_connlimit_clone(struct nft_expr *dst, const struct nft_expr *src)
{
	struct nft_connlimit *priv_dst = nft_expr_priv(dst);
	struct nft_connlimit *priv_src = nft_expr_priv(src);

	nf_conncount_list_init(&priv_dst->list);
	priv_dst->limit	 = priv_src->limit;
	priv_dst->invert = priv_src->invert;

	return 0;
}

__attribute__((used)) static void nft_connlimit_destroy_clone(const struct nft_ctx *ctx,
					const struct nft_expr *expr)
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	nf_conncount_cache_free(&priv->list);
}

__attribute__((used)) static bool nft_connlimit_gc(struct net *net, const struct nft_expr *expr)
{
	struct nft_connlimit *priv = nft_expr_priv(expr);

	return nf_conncount_gc_list(net, &priv->list);
}

