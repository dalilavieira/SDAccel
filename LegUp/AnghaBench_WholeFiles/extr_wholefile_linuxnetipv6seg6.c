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
struct sr6_tlv {int len; } ;
struct sk_buff {int dummy; } ;
struct seg6_pernet_data {struct in6_addr* tun_src; int /*<<< orphan*/  lock; } ;
struct netlink_callback {int dummy; } ;
struct net {int dummy; } ;
struct ipv6_sr_hdr {scalar_t__ type; int hdrlen; int segments_left; int first_segment; } ;
struct in6_addr {int dummy; } ;
struct genl_info {int /*<<< orphan*/  snd_seq; int /*<<< orphan*/  snd_portid; int /*<<< orphan*/ * attrs; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IPV6_SRCRT_TYPE_4 ; 
 int /*<<< orphan*/  NLMSG_DEFAULT_SIZE ; 
 size_t SEG6_ATTR_DST ; 
 int /*<<< orphan*/  SEG6_CMD_GET_TUNSRC ; 
 struct net* genl_info_net (struct genl_info*) ; 
 int /*<<< orphan*/  genlmsg_end (struct sk_buff*,void*) ; 
 struct sk_buff* genlmsg_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* genlmsg_put (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int genlmsg_reply (struct sk_buff*,struct genl_info*) ; 
 int /*<<< orphan*/  kfree (struct in6_addr*) ; 
 struct in6_addr* kmemdup (struct in6_addr*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct in6_addr* nla_data (int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put (struct sk_buff*,size_t,int,struct in6_addr*) ; 
 int /*<<< orphan*/  nlmsg_free (struct sk_buff*) ; 
 int /*<<< orphan*/  rcu_assign_pointer (struct in6_addr*,struct in6_addr*) ; 
 struct in6_addr* rcu_dereference (struct in6_addr*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  seg6_genl_family ; 
 struct seg6_pernet_data* seg6_pernet (struct net*) ; 
 int /*<<< orphan*/  synchronize_net () ; 

bool seg6_validate_srh(struct ipv6_sr_hdr *srh, int len)
{
	int trailing;
	unsigned int tlv_offset;

	if (srh->type != IPV6_SRCRT_TYPE_4)
		return false;

	if (((srh->hdrlen + 1) << 3) != len)
		return false;

	if (srh->segments_left > srh->first_segment)
		return false;

	tlv_offset = sizeof(*srh) + ((srh->first_segment + 1) << 4);

	trailing = len - tlv_offset;
	if (trailing < 0)
		return false;

	while (trailing) {
		struct sr6_tlv *tlv;
		unsigned int tlv_len;

		if (trailing < sizeof(*tlv))
			return false;

		tlv = (struct sr6_tlv *)((unsigned char *)srh + tlv_offset);
		tlv_len = sizeof(*tlv) + tlv->len;

		trailing -= tlv_len;
		if (trailing < 0)
			return false;

		tlv_offset += tlv_len;
	}

	return true;
}

__attribute__((used)) static int seg6_genl_sethmac(struct sk_buff *skb, struct genl_info *info)
{
	return -ENOTSUPP;
}

__attribute__((used)) static int seg6_genl_set_tunsrc(struct sk_buff *skb, struct genl_info *info)
{
	struct net *net = genl_info_net(info);
	struct in6_addr *val, *t_old, *t_new;
	struct seg6_pernet_data *sdata;

	sdata = seg6_pernet(net);

	if (!info->attrs[SEG6_ATTR_DST])
		return -EINVAL;

	val = nla_data(info->attrs[SEG6_ATTR_DST]);
	t_new = kmemdup(val, sizeof(*val), GFP_KERNEL);
	if (!t_new)
		return -ENOMEM;

	mutex_lock(&sdata->lock);

	t_old = sdata->tun_src;
	rcu_assign_pointer(sdata->tun_src, t_new);

	mutex_unlock(&sdata->lock);

	synchronize_net();
	kfree(t_old);

	return 0;
}

__attribute__((used)) static int seg6_genl_get_tunsrc(struct sk_buff *skb, struct genl_info *info)
{
	struct net *net = genl_info_net(info);
	struct in6_addr *tun_src;
	struct sk_buff *msg;
	void *hdr;

	msg = genlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
	if (!msg)
		return -ENOMEM;

	hdr = genlmsg_put(msg, info->snd_portid, info->snd_seq,
			  &seg6_genl_family, 0, SEG6_CMD_GET_TUNSRC);
	if (!hdr)
		goto free_msg;

	rcu_read_lock();
	tun_src = rcu_dereference(seg6_pernet(net)->tun_src);

	if (nla_put(msg, SEG6_ATTR_DST, sizeof(struct in6_addr), tun_src))
		goto nla_put_failure;

	rcu_read_unlock();

	genlmsg_end(msg, hdr);
	return genlmsg_reply(msg, info);

nla_put_failure:
	rcu_read_unlock();
free_msg:
	nlmsg_free(msg);
	return -ENOMEM;
}

__attribute__((used)) static int seg6_genl_dumphmac_start(struct netlink_callback *cb)
{
	return 0;
}

__attribute__((used)) static int seg6_genl_dumphmac_done(struct netlink_callback *cb)
{
	return 0;
}

__attribute__((used)) static int seg6_genl_dumphmac(struct sk_buff *skb, struct netlink_callback *cb)
{
	return -ENOTSUPP;
}

