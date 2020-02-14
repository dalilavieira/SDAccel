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
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int dummy; } ;
struct notifier_block {int dummy; } ;
struct nlattr {int dummy; } ;
struct TYPE_13__ {int /*<<< orphan*/  code; } ;
struct nft_regs {TYPE_10__ verdict; } ;
struct nft_pktinfo {struct sk_buff* skb; } ;
struct nf_flowtable {int dummy; } ;
struct nft_flowtable {int /*<<< orphan*/  name; int /*<<< orphan*/  use; struct nf_flowtable data; } ;
struct nft_flow_offload {struct nft_flowtable* flowtable; } ;
struct nft_expr {int dummy; } ;
struct nft_data {int dummy; } ;
struct nft_ctx {int /*<<< orphan*/  family; int /*<<< orphan*/  net; int /*<<< orphan*/  table; int /*<<< orphan*/  chain; } ;
struct nf_flow_route {TYPE_9__* tuple; } ;
struct nf_conn_help {int dummy; } ;
struct nf_conn {int /*<<< orphan*/  status; TYPE_8__* tuplehash; } ;
struct net_device {int dummy; } ;
struct ip_options {int /*<<< orphan*/  optlen; } ;
struct TYPE_19__ {int /*<<< orphan*/  flowi6_oif; int /*<<< orphan*/  daddr; } ;
struct TYPE_16__ {int /*<<< orphan*/  flowi4_oif; int /*<<< orphan*/  daddr; } ;
struct TYPE_20__ {TYPE_4__ ip6; TYPE_1__ ip4; } ;
struct flowi {TYPE_5__ u; } ;
struct flow_offload {int dummy; } ;
struct dst_entry {int dummy; } ;
typedef  int /*<<< orphan*/  fl ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
typedef  enum ip_conntrack_dir { ____Placeholder_ip_conntrack_dir } ip_conntrack_dir ;
struct TYPE_24__ {struct dst_entry* dst; } ;
struct TYPE_21__ {int protonum; } ;
struct TYPE_17__ {int /*<<< orphan*/  in6; int /*<<< orphan*/  ip; } ;
struct TYPE_18__ {TYPE_2__ u3; } ;
struct TYPE_22__ {TYPE_6__ dst; TYPE_3__ src; } ;
struct TYPE_23__ {TYPE_7__ tuple; } ;
struct TYPE_15__ {struct ip_options opt; } ;
struct TYPE_14__ {int /*<<< orphan*/  ifindex; } ;

/* Variables and functions */
 int CTINFO2DIR (int) ; 
 int EINVAL ; 
 int ENOENT ; 
 TYPE_12__* IPCB (struct sk_buff*) ; 
#define  IPPROTO_TCP 131 
#define  IPPROTO_UDP 130 
 int /*<<< orphan*/  IPS_OFFLOAD_BIT ; 
 size_t IP_CT_DIR_ORIGINAL ; 
 int IP_CT_NEW ; 
 int IP_CT_RELATED ; 
 scalar_t__ IS_ERR (struct nft_flowtable*) ; 
 unsigned long NETDEV_DOWN ; 
#define  NFPROTO_IPV4 129 
#define  NFPROTO_IPV6 128 
 size_t NFTA_FLOW_TABLE_NAME ; 
 int /*<<< orphan*/  NFT_BREAK ; 
 int NF_INET_FORWARD ; 
 int NOTIFY_DONE ; 
 int PTR_ERR (struct nft_flowtable*) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_net (struct net_device*) ; 
 int /*<<< orphan*/  dst_release (struct dst_entry*) ; 
 int flow_offload_add (struct nf_flowtable*,struct flow_offload*) ; 
 struct flow_offload* flow_offload_alloc (struct nf_conn*,struct nf_flow_route*) ; 
 int /*<<< orphan*/  flow_offload_free (struct flow_offload*) ; 
 int /*<<< orphan*/  memset (struct flowi*,int /*<<< orphan*/ ,int) ; 
 struct net_device* netdev_notifier_info_to_dev (void*) ; 
 struct nf_conn* nf_ct_get (struct sk_buff*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_flow_table_cleanup (int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  nf_route (int /*<<< orphan*/ ,struct dst_entry**,struct flowi*,int,int) ; 
 struct nf_conn_help* nfct_help (struct nf_conn*) ; 
 int nft_chain_validate_hooks (int /*<<< orphan*/ ,unsigned int) ; 
 struct nft_flow_offload* nft_expr_priv (struct nft_expr const*) ; 
 struct nft_flowtable* nft_flowtable_lookup (int /*<<< orphan*/ ,struct nlattr const* const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_genmask_next (int /*<<< orphan*/ ) ; 
 TYPE_11__* nft_in (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 int nft_pf (struct nft_pktinfo const*) ; 
 scalar_t__ nla_put_string (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 struct dst_entry* skb_dst (struct sk_buff*) ; 
 scalar_t__ skb_sec_path (struct sk_buff*) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nft_flow_route(const struct nft_pktinfo *pkt,
			  const struct nf_conn *ct,
			  struct nf_flow_route *route,
			  enum ip_conntrack_dir dir)
{
	struct dst_entry *this_dst = skb_dst(pkt->skb);
	struct dst_entry *other_dst = NULL;
	struct flowi fl;

	memset(&fl, 0, sizeof(fl));
	switch (nft_pf(pkt)) {
	case NFPROTO_IPV4:
		fl.u.ip4.daddr = ct->tuplehash[dir].tuple.src.u3.ip;
		fl.u.ip4.flowi4_oif = nft_in(pkt)->ifindex;
		break;
	case NFPROTO_IPV6:
		fl.u.ip6.daddr = ct->tuplehash[dir].tuple.src.u3.in6;
		fl.u.ip6.flowi6_oif = nft_in(pkt)->ifindex;
		break;
	}

	nf_route(nft_net(pkt), &other_dst, &fl, false, nft_pf(pkt));
	if (!other_dst)
		return -ENOENT;

	route->tuple[dir].dst		= this_dst;
	route->tuple[!dir].dst		= other_dst;

	return 0;
}

__attribute__((used)) static bool nft_flow_offload_skip(struct sk_buff *skb)
{
	struct ip_options *opt  = &(IPCB(skb)->opt);

	if (unlikely(opt->optlen))
		return true;
	if (skb_sec_path(skb))
		return true;

	return false;
}

__attribute__((used)) static void nft_flow_offload_eval(const struct nft_expr *expr,
				  struct nft_regs *regs,
				  const struct nft_pktinfo *pkt)
{
	struct nft_flow_offload *priv = nft_expr_priv(expr);
	struct nf_flowtable *flowtable = &priv->flowtable->data;
	const struct nf_conn_help *help;
	enum ip_conntrack_info ctinfo;
	struct nf_flow_route route;
	struct flow_offload *flow;
	enum ip_conntrack_dir dir;
	struct nf_conn *ct;
	int ret;

	if (nft_flow_offload_skip(pkt->skb))
		goto out;

	ct = nf_ct_get(pkt->skb, &ctinfo);
	if (!ct)
		goto out;

	switch (ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.dst.protonum) {
	case IPPROTO_TCP:
	case IPPROTO_UDP:
		break;
	default:
		goto out;
	}

	help = nfct_help(ct);
	if (help)
		goto out;

	if (ctinfo == IP_CT_NEW ||
	    ctinfo == IP_CT_RELATED)
		goto out;

	if (test_and_set_bit(IPS_OFFLOAD_BIT, &ct->status))
		goto out;

	dir = CTINFO2DIR(ctinfo);
	if (nft_flow_route(pkt, ct, &route, dir) < 0)
		goto err_flow_route;

	flow = flow_offload_alloc(ct, &route);
	if (!flow)
		goto err_flow_alloc;

	ret = flow_offload_add(flowtable, flow);
	if (ret < 0)
		goto err_flow_add;

	return;

err_flow_add:
	flow_offload_free(flow);
err_flow_alloc:
	dst_release(route.tuple[!dir].dst);
err_flow_route:
	clear_bit(IPS_OFFLOAD_BIT, &ct->status);
out:
	regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static int nft_flow_offload_validate(const struct nft_ctx *ctx,
				     const struct nft_expr *expr,
				     const struct nft_data **data)
{
	unsigned int hook_mask = (1 << NF_INET_FORWARD);

	return nft_chain_validate_hooks(ctx->chain, hook_mask);
}

__attribute__((used)) static int nft_flow_offload_init(const struct nft_ctx *ctx,
				 const struct nft_expr *expr,
				 const struct nlattr * const tb[])
{
	struct nft_flow_offload *priv = nft_expr_priv(expr);
	u8 genmask = nft_genmask_next(ctx->net);
	struct nft_flowtable *flowtable;

	if (!tb[NFTA_FLOW_TABLE_NAME])
		return -EINVAL;

	flowtable = nft_flowtable_lookup(ctx->table, tb[NFTA_FLOW_TABLE_NAME],
					 genmask);
	if (IS_ERR(flowtable))
		return PTR_ERR(flowtable);

	priv->flowtable = flowtable;
	flowtable->use++;

	return nf_ct_netns_get(ctx->net, ctx->family);
}

__attribute__((used)) static void nft_flow_offload_destroy(const struct nft_ctx *ctx,
				     const struct nft_expr *expr)
{
	struct nft_flow_offload *priv = nft_expr_priv(expr);

	priv->flowtable->use--;
	nf_ct_netns_put(ctx->net, ctx->family);
}

__attribute__((used)) static int nft_flow_offload_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_flow_offload *priv = nft_expr_priv(expr);

	if (nla_put_string(skb, NFTA_FLOW_TABLE_NAME, priv->flowtable->name))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int flow_offload_netdev_event(struct notifier_block *this,
				     unsigned long event, void *ptr)
{
	struct net_device *dev = netdev_notifier_info_to_dev(ptr);

	if (event != NETDEV_DOWN)
		return NOTIFY_DONE;

	nf_flow_table_cleanup(dev_net(dev), dev);

	return NOTIFY_DONE;
}

