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
typedef  int /*<<< orphan*/  u32 ;
struct tcphdr {int /*<<< orphan*/  syn; } ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct TYPE_2__ {void* code; } ;
struct nft_regs {TYPE_1__ verdict; int /*<<< orphan*/ * data; } ;
struct nft_pktinfo {struct sk_buff* skb; } ;
struct nft_osf {size_t dreg; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 size_t NFTA_OSF_DREG ; 
 void* NFT_BREAK ; 
 int /*<<< orphan*/  NFT_DATA_VALUE ; 
 int /*<<< orphan*/  NFT_OSF_MAXGENRELEN ; 
 int /*<<< orphan*/  ip_hdrlen (struct sk_buff*) ; 
 char* nf_osf_find (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_osf_fingers ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 size_t nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_store (struct nft_ctx const*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct tcphdr* skb_header_pointer (struct sk_buff*,int /*<<< orphan*/ ,int,struct tcphdr*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nft_osf_eval(const struct nft_expr *expr, struct nft_regs *regs,
			 const struct nft_pktinfo *pkt)
{
	struct nft_osf *priv = nft_expr_priv(expr);
	u32 *dest = &regs->data[priv->dreg];
	struct sk_buff *skb = pkt->skb;
	const struct tcphdr *tcp;
	struct tcphdr _tcph;
	const char *os_name;

	tcp = skb_header_pointer(skb, ip_hdrlen(skb),
				 sizeof(struct tcphdr), &_tcph);
	if (!tcp) {
		regs->verdict.code = NFT_BREAK;
		return;
	}
	if (!tcp->syn) {
		regs->verdict.code = NFT_BREAK;
		return;
	}

	os_name = nf_osf_find(skb, nf_osf_fingers);
	if (!os_name)
		strncpy((char *)dest, "unknown", NFT_OSF_MAXGENRELEN);
	else
		strncpy((char *)dest, os_name, NFT_OSF_MAXGENRELEN);
}

__attribute__((used)) static int nft_osf_init(const struct nft_ctx *ctx,
			const struct nft_expr *expr,
			const struct nlattr * const tb[])
{
	struct nft_osf *priv = nft_expr_priv(expr);
	int err;

	priv->dreg = nft_parse_register(tb[NFTA_OSF_DREG]);
	err = nft_validate_register_store(ctx, priv->dreg, NULL,
					  NFT_DATA_VALUE, NFT_OSF_MAXGENRELEN);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int nft_osf_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_osf *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_OSF_DREG, priv->dreg))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

