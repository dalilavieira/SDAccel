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
typedef  int /*<<< orphan*/  u32 ;
struct tnl_ptk_info {scalar_t__ proto; int hdr_len; void* key; void* seq; int /*<<< orphan*/  flags; } ;
struct sk_buff {int* data; } ;
struct iphdr {int ihl; } ;
struct gre_protocol {int (* handler ) (struct sk_buff*) ;int /*<<< orphan*/  (* err_handler ) (struct sk_buff*,int /*<<< orphan*/ ) ;} ;
struct gre_base_hdr {int flags; scalar_t__ protocol; } ;
struct erspan_base_hdr {int dummy; } ;
typedef  void* __be32 ;
typedef  scalar_t__ __be16 ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  ETH_P_ERSPAN ; 
 int /*<<< orphan*/  ETH_P_ERSPAN2 ; 
 int /*<<< orphan*/  ETH_P_WCCP ; 
 size_t GREPROTO_MAX ; 
 int GRE_CSUM ; 
 int GRE_KEY ; 
 int GRE_ROUTING ; 
 int GRE_SEQ ; 
 int GRE_VERSION ; 
 int /*<<< orphan*/  IPPROTO_GRE ; 
 int NET_RX_DROP ; 
 struct gre_protocol const* cmpxchg (struct gre_protocol const**,struct gre_protocol const*,struct gre_protocol const*) ; 
 void* cpu_to_be32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_session_id (struct erspan_base_hdr*) ; 
 int gre_calc_hlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gre_flags_to_tnl_flags (int) ; 
 int /*<<< orphan*/ * gre_proto ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  null_compute_pseudo ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 struct gre_protocol* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 scalar_t__ skb_checksum_simple_validate (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_checksum_try_convert (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (struct sk_buff*) ; 
 int /*<<< orphan*/  stub2 (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  synchronize_rcu () ; 
 scalar_t__ unlikely (int) ; 

int gre_add_protocol(const struct gre_protocol *proto, u8 version)
{
	if (version >= GREPROTO_MAX)
		return -EINVAL;

	return (cmpxchg((const struct gre_protocol **)&gre_proto[version], NULL, proto) == NULL) ?
		0 : -EBUSY;
}

int gre_del_protocol(const struct gre_protocol *proto, u8 version)
{
	int ret;

	if (version >= GREPROTO_MAX)
		return -EINVAL;

	ret = (cmpxchg((const struct gre_protocol **)&gre_proto[version], proto, NULL) == proto) ?
		0 : -EBUSY;

	if (ret)
		return ret;

	synchronize_rcu();
	return 0;
}

int gre_parse_header(struct sk_buff *skb, struct tnl_ptk_info *tpi,
		     bool *csum_err, __be16 proto, int nhs)
{
	const struct gre_base_hdr *greh;
	__be32 *options;
	int hdr_len;

	if (unlikely(!pskb_may_pull(skb, nhs + sizeof(struct gre_base_hdr))))
		return -EINVAL;

	greh = (struct gre_base_hdr *)(skb->data + nhs);
	if (unlikely(greh->flags & (GRE_VERSION | GRE_ROUTING)))
		return -EINVAL;

	tpi->flags = gre_flags_to_tnl_flags(greh->flags);
	hdr_len = gre_calc_hlen(tpi->flags);

	if (!pskb_may_pull(skb, nhs + hdr_len))
		return -EINVAL;

	greh = (struct gre_base_hdr *)(skb->data + nhs);
	tpi->proto = greh->protocol;

	options = (__be32 *)(greh + 1);
	if (greh->flags & GRE_CSUM) {
		if (skb_checksum_simple_validate(skb)) {
			*csum_err = true;
			return -EINVAL;
		}

		skb_checksum_try_convert(skb, IPPROTO_GRE, 0,
					 null_compute_pseudo);
		options++;
	}

	if (greh->flags & GRE_KEY) {
		tpi->key = *options;
		options++;
	} else {
		tpi->key = 0;
	}
	if (unlikely(greh->flags & GRE_SEQ)) {
		tpi->seq = *options;
		options++;
	} else {
		tpi->seq = 0;
	}
	/* WCCP version 1 and 2 protocol decoding.
	 * - Change protocol to IPv4/IPv6
	 * - When dealing with WCCPv2, Skip extra 4 bytes in GRE header
	 */
	if (greh->flags == 0 && tpi->proto == htons(ETH_P_WCCP)) {
		tpi->proto = proto;
		if ((*(u8 *)options & 0xF0) != 0x40)
			hdr_len += 4;
	}
	tpi->hdr_len = hdr_len;

	/* ERSPAN ver 1 and 2 protocol sets GRE key field
	 * to 0 and sets the configured key in the
	 * inner erspan header field
	 */
	if (greh->protocol == htons(ETH_P_ERSPAN) ||
	    greh->protocol == htons(ETH_P_ERSPAN2)) {
		struct erspan_base_hdr *ershdr;

		if (!pskb_may_pull(skb, nhs + hdr_len + sizeof(*ershdr)))
			return -EINVAL;

		ershdr = (struct erspan_base_hdr *)options;
		tpi->key = cpu_to_be32(get_session_id(ershdr));
	}

	return hdr_len;
}

__attribute__((used)) static int gre_rcv(struct sk_buff *skb)
{
	const struct gre_protocol *proto;
	u8 ver;
	int ret;

	if (!pskb_may_pull(skb, 12))
		goto drop;

	ver = skb->data[1]&0x7f;
	if (ver >= GREPROTO_MAX)
		goto drop;

	rcu_read_lock();
	proto = rcu_dereference(gre_proto[ver]);
	if (!proto || !proto->handler)
		goto drop_unlock;
	ret = proto->handler(skb);
	rcu_read_unlock();
	return ret;

drop_unlock:
	rcu_read_unlock();
drop:
	kfree_skb(skb);
	return NET_RX_DROP;
}

__attribute__((used)) static void gre_err(struct sk_buff *skb, u32 info)
{
	const struct gre_protocol *proto;
	const struct iphdr *iph = (const struct iphdr *)skb->data;
	u8 ver = skb->data[(iph->ihl<<2) + 1]&0x7f;

	if (ver >= GREPROTO_MAX)
		return;

	rcu_read_lock();
	proto = rcu_dereference(gre_proto[ver]);
	if (proto && proto->err_handler)
		proto->err_handler(skb, info);
	rcu_read_unlock();
}

