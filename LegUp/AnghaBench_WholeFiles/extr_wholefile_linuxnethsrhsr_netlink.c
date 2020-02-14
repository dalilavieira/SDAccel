#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
typedef  struct net_device {int ifindex; } const net_device ;
struct net {int dummy; } ;
struct hsr_tag {void* path_and_LSDU_size; } ;
struct hsr_sup_tag {int dummy; } ;
struct hsr_priv {unsigned char* sup_multicast_addr; int sequence_nr; } ;
struct hsr_port {TYPE_2__* dev; } ;
struct TYPE_4__ {void* sequence_nr; } ;
struct hsr_ethhdr {TYPE_1__ hsr_tag; } ;
struct genl_info {int /*<<< orphan*/  snd_portid; int /*<<< orphan*/  snd_seq; struct nlattr** attrs; } ;
struct TYPE_6__ {int /*<<< orphan*/  portid; } ;
struct TYPE_5__ {int ifindex; } ;

/* Variables and functions */
 int EINVAL ; 
 int EMSGSIZE ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETH_ALEN ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 size_t HSR_A_ADDR_B_IFINDEX ; 
 size_t HSR_A_IF1_AGE ; 
 size_t HSR_A_IF1_IFINDEX ; 
 int /*<<< orphan*/  HSR_A_IF1_SEQ ; 
 size_t HSR_A_IF2_AGE ; 
 size_t HSR_A_IF2_IFINDEX ; 
 int /*<<< orphan*/  HSR_A_IF2_SEQ ; 
 size_t HSR_A_IFINDEX ; 
 size_t HSR_A_NODE_ADDR ; 
 size_t HSR_A_NODE_ADDR_B ; 
 int /*<<< orphan*/  HSR_C_NODE_DOWN ; 
 int /*<<< orphan*/  HSR_C_RING_ERROR ; 
 int /*<<< orphan*/  HSR_C_SET_NODE_LIST ; 
 int /*<<< orphan*/  HSR_C_SET_NODE_STATUS ; 
 int /*<<< orphan*/  HSR_PT_MASTER ; 
 int /*<<< orphan*/  HSR_PT_SLAVE_A ; 
 int /*<<< orphan*/  HSR_PT_SLAVE_B ; 
 size_t IFLA_HSR_MULTICAST_SPEC ; 
 int /*<<< orphan*/  IFLA_HSR_SEQ_NR ; 
 size_t IFLA_HSR_SLAVE1 ; 
 size_t IFLA_HSR_SLAVE2 ; 
 size_t IFLA_HSR_SUPERVISION_ADDR ; 
 size_t IFLA_HSR_VERSION ; 
 TYPE_3__ NETLINK_CB (struct sk_buff*) ; 
 int /*<<< orphan*/  NLMSG_GOODSIZE ; 
 struct net_device const* __dev_get_by_index (struct net*,int /*<<< orphan*/ ) ; 
 struct net* genl_info_net (struct genl_info*) ; 
 int /*<<< orphan*/  genlmsg_end (struct sk_buff*,void*) ; 
 int /*<<< orphan*/  genlmsg_multicast (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sk_buff* genlmsg_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* genlmsg_put (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  genlmsg_unicast (struct net*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 int hsr_dev_finalize (struct net_device const*,struct net_device const**,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  hsr_genl_family ; 
 void* hsr_get_next_node (struct hsr_priv*,void*,unsigned char*) ; 
 int hsr_get_node_data (struct hsr_priv*,unsigned char*,unsigned char*,int*,int*,int*,int*,int*) ; 
 struct hsr_port* hsr_port_get_hsr (struct hsr_priv*,int /*<<< orphan*/ ) ; 
 void* htons (int) ; 
 int /*<<< orphan*/  is_hsr_master (struct net_device const*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  netdev_info (struct net_device const*,char*) ; 
 struct hsr_priv* netdev_priv (struct net_device const*) ; 
 int /*<<< orphan*/  netdev_warn (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  netlink_ack (struct sk_buff*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 unsigned char* nla_data (struct nlattr*) ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 unsigned char nla_get_u8 (struct nlattr*) ; 
 int nla_put (struct sk_buff*,size_t,int,unsigned char*) ; 
 int nla_put_u16 (struct sk_buff*,int /*<<< orphan*/ ,int) ; 
 int nla_put_u32 (struct sk_buff*,size_t,int) ; 
 int /*<<< orphan*/  nlmsg_hdr (struct sk_buff*) ; 
 int ntohs (void*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 scalar_t__ skb_mac_header (struct sk_buff*) ; 

__attribute__((used)) static inline u16 get_hsr_tag_path(struct hsr_tag *ht)
{
	return ntohs(ht->path_and_LSDU_size) >> 12;
}

__attribute__((used)) static inline u16 get_hsr_tag_LSDU_size(struct hsr_tag *ht)
{
	return ntohs(ht->path_and_LSDU_size) & 0x0FFF;
}

__attribute__((used)) static inline void set_hsr_tag_path(struct hsr_tag *ht, u16 path)
{
	ht->path_and_LSDU_size = htons(
			(ntohs(ht->path_and_LSDU_size) & 0x0FFF) | (path << 12));
}

__attribute__((used)) static inline void set_hsr_tag_LSDU_size(struct hsr_tag *ht, u16 LSDU_size)
{
	ht->path_and_LSDU_size = htons(
			(ntohs(ht->path_and_LSDU_size) & 0xF000) |
			(LSDU_size & 0x0FFF));
}

__attribute__((used)) static inline u16 get_hsr_stag_path(struct hsr_sup_tag *hst)
{
	return get_hsr_tag_path((struct hsr_tag *) hst);
}

__attribute__((used)) static inline u16 get_hsr_stag_HSR_ver(struct hsr_sup_tag *hst)
{
	return get_hsr_tag_LSDU_size((struct hsr_tag *) hst);
}

__attribute__((used)) static inline void set_hsr_stag_path(struct hsr_sup_tag *hst, u16 path)
{
	set_hsr_tag_path((struct hsr_tag *) hst, path);
}

__attribute__((used)) static inline void set_hsr_stag_HSR_Ver(struct hsr_sup_tag *hst, u16 HSR_Ver)
{
	set_hsr_tag_LSDU_size((struct hsr_tag *) hst, HSR_Ver);
}

__attribute__((used)) static inline u16 hsr_get_skb_sequence_nr(struct sk_buff *skb)
{
	struct hsr_ethhdr *hsr_ethhdr;

	hsr_ethhdr = (struct hsr_ethhdr *) skb_mac_header(skb);
	return ntohs(hsr_ethhdr->hsr_tag.sequence_nr);
}

__attribute__((used)) static int hsr_newlink(struct net *src_net, struct net_device *dev,
		       struct nlattr *tb[], struct nlattr *data[],
		       struct netlink_ext_ack *extack)
{
	struct net_device *link[2];
	unsigned char multicast_spec, hsr_version;

	if (!data) {
		netdev_info(dev, "HSR: No slave devices specified\n");
		return -EINVAL;
	}
	if (!data[IFLA_HSR_SLAVE1]) {
		netdev_info(dev, "HSR: Slave1 device not specified\n");
		return -EINVAL;
	}
	link[0] = __dev_get_by_index(src_net, nla_get_u32(data[IFLA_HSR_SLAVE1]));
	if (!data[IFLA_HSR_SLAVE2]) {
		netdev_info(dev, "HSR: Slave2 device not specified\n");
		return -EINVAL;
	}
	link[1] = __dev_get_by_index(src_net, nla_get_u32(data[IFLA_HSR_SLAVE2]));

	if (!link[0] || !link[1])
		return -ENODEV;
	if (link[0] == link[1])
		return -EINVAL;

	if (!data[IFLA_HSR_MULTICAST_SPEC])
		multicast_spec = 0;
	else
		multicast_spec = nla_get_u8(data[IFLA_HSR_MULTICAST_SPEC]);

	if (!data[IFLA_HSR_VERSION])
		hsr_version = 0;
	else
		hsr_version = nla_get_u8(data[IFLA_HSR_VERSION]);

	return hsr_dev_finalize(dev, link, multicast_spec, hsr_version);
}

__attribute__((used)) static int hsr_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
	struct hsr_priv *hsr;
	struct hsr_port *port;
	int res;

	hsr = netdev_priv(dev);

	res = 0;

	rcu_read_lock();
	port = hsr_port_get_hsr(hsr, HSR_PT_SLAVE_A);
	if (port)
		res = nla_put_u32(skb, IFLA_HSR_SLAVE1, port->dev->ifindex);
	rcu_read_unlock();
	if (res)
		goto nla_put_failure;

	rcu_read_lock();
	port = hsr_port_get_hsr(hsr, HSR_PT_SLAVE_B);
	if (port)
		res = nla_put_u32(skb, IFLA_HSR_SLAVE2, port->dev->ifindex);
	rcu_read_unlock();
	if (res)
		goto nla_put_failure;

	if (nla_put(skb, IFLA_HSR_SUPERVISION_ADDR, ETH_ALEN,
		    hsr->sup_multicast_addr) ||
	    nla_put_u16(skb, IFLA_HSR_SEQ_NR, hsr->sequence_nr))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -EMSGSIZE;
}

void hsr_nl_ringerror(struct hsr_priv *hsr, unsigned char addr[ETH_ALEN],
		      struct hsr_port *port)
{
	struct sk_buff *skb;
	void *msg_head;
	struct hsr_port *master;
	int res;

	skb = genlmsg_new(NLMSG_GOODSIZE, GFP_ATOMIC);
	if (!skb)
		goto fail;

	msg_head = genlmsg_put(skb, 0, 0, &hsr_genl_family, 0, HSR_C_RING_ERROR);
	if (!msg_head)
		goto nla_put_failure;

	res = nla_put(skb, HSR_A_NODE_ADDR, ETH_ALEN, addr);
	if (res < 0)
		goto nla_put_failure;

	res = nla_put_u32(skb, HSR_A_IFINDEX, port->dev->ifindex);
	if (res < 0)
		goto nla_put_failure;

	genlmsg_end(skb, msg_head);
	genlmsg_multicast(&hsr_genl_family, skb, 0, 0, GFP_ATOMIC);

	return;

nla_put_failure:
	kfree_skb(skb);

fail:
	rcu_read_lock();
	master = hsr_port_get_hsr(hsr, HSR_PT_MASTER);
	netdev_warn(master->dev, "Could not send HSR ring error message\n");
	rcu_read_unlock();
}

void hsr_nl_nodedown(struct hsr_priv *hsr, unsigned char addr[ETH_ALEN])
{
	struct sk_buff *skb;
	void *msg_head;
	struct hsr_port *master;
	int res;

	skb = genlmsg_new(NLMSG_GOODSIZE, GFP_ATOMIC);
	if (!skb)
		goto fail;

	msg_head = genlmsg_put(skb, 0, 0, &hsr_genl_family, 0, HSR_C_NODE_DOWN);
	if (!msg_head)
		goto nla_put_failure;


	res = nla_put(skb, HSR_A_NODE_ADDR, ETH_ALEN, addr);
	if (res < 0)
		goto nla_put_failure;

	genlmsg_end(skb, msg_head);
	genlmsg_multicast(&hsr_genl_family, skb, 0, 0, GFP_ATOMIC);

	return;

nla_put_failure:
	kfree_skb(skb);

fail:
	rcu_read_lock();
	master = hsr_port_get_hsr(hsr, HSR_PT_MASTER);
	netdev_warn(master->dev, "Could not send HSR node down\n");
	rcu_read_unlock();
}

__attribute__((used)) static int hsr_get_node_status(struct sk_buff *skb_in, struct genl_info *info)
{
	/* For receiving */
	struct nlattr *na;
	struct net_device *hsr_dev;

	/* For sending */
	struct sk_buff *skb_out;
	void *msg_head;
	struct hsr_priv *hsr;
	struct hsr_port *port;
	unsigned char hsr_node_addr_b[ETH_ALEN];
	int hsr_node_if1_age;
	u16 hsr_node_if1_seq;
	int hsr_node_if2_age;
	u16 hsr_node_if2_seq;
	int addr_b_ifindex;
	int res;

	if (!info)
		goto invalid;

	na = info->attrs[HSR_A_IFINDEX];
	if (!na)
		goto invalid;
	na = info->attrs[HSR_A_NODE_ADDR];
	if (!na)
		goto invalid;

	hsr_dev = __dev_get_by_index(genl_info_net(info),
					nla_get_u32(info->attrs[HSR_A_IFINDEX]));
	if (!hsr_dev)
		goto invalid;
	if (!is_hsr_master(hsr_dev))
		goto invalid;


	/* Send reply */

	skb_out = genlmsg_new(NLMSG_GOODSIZE, GFP_KERNEL);
	if (!skb_out) {
		res = -ENOMEM;
		goto fail;
	}

	msg_head = genlmsg_put(skb_out, NETLINK_CB(skb_in).portid,
				info->snd_seq, &hsr_genl_family, 0,
				HSR_C_SET_NODE_STATUS);
	if (!msg_head) {
		res = -ENOMEM;
		goto nla_put_failure;
	}

	res = nla_put_u32(skb_out, HSR_A_IFINDEX, hsr_dev->ifindex);
	if (res < 0)
		goto nla_put_failure;

	hsr = netdev_priv(hsr_dev);
	res = hsr_get_node_data(hsr,
			(unsigned char *) nla_data(info->attrs[HSR_A_NODE_ADDR]),
			hsr_node_addr_b,
			&addr_b_ifindex,
			&hsr_node_if1_age,
			&hsr_node_if1_seq,
			&hsr_node_if2_age,
			&hsr_node_if2_seq);
	if (res < 0)
		goto nla_put_failure;

	res = nla_put(skb_out, HSR_A_NODE_ADDR, ETH_ALEN,
					nla_data(info->attrs[HSR_A_NODE_ADDR]));
	if (res < 0)
		goto nla_put_failure;

	if (addr_b_ifindex > -1) {
		res = nla_put(skb_out, HSR_A_NODE_ADDR_B, ETH_ALEN,
								hsr_node_addr_b);
		if (res < 0)
			goto nla_put_failure;

		res = nla_put_u32(skb_out, HSR_A_ADDR_B_IFINDEX, addr_b_ifindex);
		if (res < 0)
			goto nla_put_failure;
	}

	res = nla_put_u32(skb_out, HSR_A_IF1_AGE, hsr_node_if1_age);
	if (res < 0)
		goto nla_put_failure;
	res = nla_put_u16(skb_out, HSR_A_IF1_SEQ, hsr_node_if1_seq);
	if (res < 0)
		goto nla_put_failure;
	rcu_read_lock();
	port = hsr_port_get_hsr(hsr, HSR_PT_SLAVE_A);
	if (port)
		res = nla_put_u32(skb_out, HSR_A_IF1_IFINDEX,
				  port->dev->ifindex);
	rcu_read_unlock();
	if (res < 0)
		goto nla_put_failure;

	res = nla_put_u32(skb_out, HSR_A_IF2_AGE, hsr_node_if2_age);
	if (res < 0)
		goto nla_put_failure;
	res = nla_put_u16(skb_out, HSR_A_IF2_SEQ, hsr_node_if2_seq);
	if (res < 0)
		goto nla_put_failure;
	rcu_read_lock();
	port = hsr_port_get_hsr(hsr, HSR_PT_SLAVE_B);
	if (port)
		res = nla_put_u32(skb_out, HSR_A_IF2_IFINDEX,
				  port->dev->ifindex);
	rcu_read_unlock();
	if (res < 0)
		goto nla_put_failure;

	genlmsg_end(skb_out, msg_head);
	genlmsg_unicast(genl_info_net(info), skb_out, info->snd_portid);

	return 0;

invalid:
	netlink_ack(skb_in, nlmsg_hdr(skb_in), -EINVAL, NULL);
	return 0;

nla_put_failure:
	kfree_skb(skb_out);
	/* Fall through */

fail:
	return res;
}

__attribute__((used)) static int hsr_get_node_list(struct sk_buff *skb_in, struct genl_info *info)
{
	/* For receiving */
	struct nlattr *na;
	struct net_device *hsr_dev;

	/* For sending */
	struct sk_buff *skb_out;
	void *msg_head;
	struct hsr_priv *hsr;
	void *pos;
	unsigned char addr[ETH_ALEN];
	int res;

	if (!info)
		goto invalid;

	na = info->attrs[HSR_A_IFINDEX];
	if (!na)
		goto invalid;

	hsr_dev = __dev_get_by_index(genl_info_net(info),
				     nla_get_u32(info->attrs[HSR_A_IFINDEX]));
	if (!hsr_dev)
		goto invalid;
	if (!is_hsr_master(hsr_dev))
		goto invalid;


	/* Send reply */

	skb_out = genlmsg_new(NLMSG_GOODSIZE, GFP_KERNEL);
	if (!skb_out) {
		res = -ENOMEM;
		goto fail;
	}

	msg_head = genlmsg_put(skb_out, NETLINK_CB(skb_in).portid,
				info->snd_seq, &hsr_genl_family, 0,
				HSR_C_SET_NODE_LIST);
	if (!msg_head) {
		res = -ENOMEM;
		goto nla_put_failure;
	}

	res = nla_put_u32(skb_out, HSR_A_IFINDEX, hsr_dev->ifindex);
	if (res < 0)
		goto nla_put_failure;

	hsr = netdev_priv(hsr_dev);

	rcu_read_lock();
	pos = hsr_get_next_node(hsr, NULL, addr);
	while (pos) {
		res = nla_put(skb_out, HSR_A_NODE_ADDR, ETH_ALEN, addr);
		if (res < 0) {
			rcu_read_unlock();
			goto nla_put_failure;
		}
		pos = hsr_get_next_node(hsr, pos, addr);
	}
	rcu_read_unlock();

	genlmsg_end(skb_out, msg_head);
	genlmsg_unicast(genl_info_net(info), skb_out, info->snd_portid);

	return 0;

invalid:
	netlink_ack(skb_in, nlmsg_hdr(skb_in), -EINVAL, NULL);
	return 0;

nla_put_failure:
	kfree_skb(skb_out);
	/* Fall through */

fail:
	return res;
}

