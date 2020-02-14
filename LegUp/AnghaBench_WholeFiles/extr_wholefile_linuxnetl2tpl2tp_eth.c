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
typedef  scalar_t__ u32 ;
struct udphdr {int dummy; } ;
struct sk_buff {unsigned char* data; unsigned int len; int /*<<< orphan*/  ip_summed; } ;
struct seq_file {int dummy; } ;
struct rtnl_link_stats64 {unsigned long tx_bytes; unsigned long tx_packets; unsigned long tx_dropped; unsigned long rx_bytes; unsigned long rx_packets; unsigned long rx_errors; } ;
struct net_device {int needs_free_netdev; int needed_headroom; scalar_t__ min_mtu; scalar_t__ max_mtu; int /*<<< orphan*/  name; scalar_t__ mtu; int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  features; int /*<<< orphan*/  priv_flags; int /*<<< orphan*/  broadcast; } ;
struct net {int dummy; } ;
struct l2tp_tunnel {scalar_t__ encap; int /*<<< orphan*/  sock; int /*<<< orphan*/  ref_count; } ;
struct l2tp_session_cfg {int /*<<< orphan*/  ifname; } ;
struct l2tp_session {void* priv; int l2specific_type; int peer_cookie_len; scalar_t__ hdr_len; int debug; void (* recv_skb ) (struct l2tp_session*,struct sk_buff*,int) ;void (* session_close ) (struct l2tp_session*) ;void (* show ) (struct seq_file*,void*) ;char* ifname; int /*<<< orphan*/  name; int /*<<< orphan*/  ref_count; } ;
struct l2tp_eth_sess {int /*<<< orphan*/  dev; } ;
struct l2tp_eth {struct l2tp_session* session; int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  rx_bytes; int /*<<< orphan*/  rx_packets; int /*<<< orphan*/  tx_dropped; int /*<<< orphan*/  tx_packets; int /*<<< orphan*/  tx_bytes; } ;
struct dst_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHECKSUM_NONE ; 
 int /*<<< orphan*/  CONFIG_L2TP_DEBUGFS ; 
 int /*<<< orphan*/  DUMP_PREFIX_OFFSET ; 
 int ENOMEM ; 
 scalar_t__ ETH_DATA_LEN ; 
 unsigned int ETH_HLEN ; 
 scalar_t__ ETH_MAX_MTU ; 
 int /*<<< orphan*/  IFF_TX_SKB_SHARING ; 
 int IFNAMSIZ ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct l2tp_session*) ; 
 scalar_t__ L2TP_ENCAPTYPE_UDP ; 
 int /*<<< orphan*/  L2TP_ETH_DEV_NAME ; 
#define  L2TP_L2SPECTYPE_DEFAULT 129 
#define  L2TP_L2SPECTYPE_NONE 128 
 int L2TP_MSG_DATA ; 
 int NETDEV_TX_OK ; 
 int /*<<< orphan*/  NETIF_F_LLTX ; 
 unsigned char NET_NAME_ENUM ; 
 unsigned char NET_NAME_USER ; 
 scalar_t__ NET_RX_SUCCESS ; 
 int NET_XMIT_SUCCESS ; 
 int PTR_ERR (struct l2tp_session*) ; 
 int /*<<< orphan*/  RCU_INIT_POINTER (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SET_NETDEV_DEVTYPE (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 struct net_device* alloc_netdev (int,char*,unsigned char,void (*) (struct net_device*)) ; 
 int /*<<< orphan*/  atomic_long_add (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_long_inc (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_long_read (int /*<<< orphan*/ *) ; 
 scalar_t__ dev_forward_skb (struct net_device*,struct sk_buff*) ; 
 int /*<<< orphan*/  dev_hold (struct net_device*) ; 
 int /*<<< orphan*/  dev_net_set (struct net_device*,struct net*) ; 
 int /*<<< orphan*/  dev_put (struct net_device*) ; 
 scalar_t__ dst_mtu (struct dst_entry*) ; 
 int /*<<< orphan*/  dst_release (struct dst_entry*) ; 
 int /*<<< orphan*/  eth_broadcast_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eth_hw_addr_random (struct net_device*) ; 
 int /*<<< orphan*/  ether_setup (struct net_device*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 scalar_t__ kernel_sock_ip_overhead (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct l2tp_session*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  l2tp_eth_netdev_ops ; 
 struct l2tp_session* l2tp_session_create (int,struct l2tp_tunnel*,scalar_t__,scalar_t__,struct l2tp_session_cfg*) ; 
 int /*<<< orphan*/  l2tp_session_delete (struct l2tp_session*) ; 
 int /*<<< orphan*/  l2tp_session_free (struct l2tp_session*) ; 
 int l2tp_session_register (struct l2tp_session*,struct l2tp_tunnel*) ; 
 int /*<<< orphan*/  l2tp_tunnel_free (struct l2tp_tunnel*) ; 
 int l2tp_xmit_skb (struct l2tp_session*,struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  l2tpeth_type ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  lock_sock (int /*<<< orphan*/ ) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_lockdep_set_classes (struct net_device*) ; 
 struct l2tp_eth* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  nf_reset (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print_hex_dump_bytes (char*,int /*<<< orphan*/ ,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct net_device*) ; 
 struct net_device* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int register_netdevice (struct net_device*) ; 
 int /*<<< orphan*/  release_sock (int /*<<< orphan*/ ) ; 
 struct net_device* rtnl_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int /*<<< orphan*/  secpath_reset (struct sk_buff*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 
 struct dst_entry* sk_dst_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_dst_drop (struct sk_buff*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  unregister_netdevice (struct net_device*) ; 

__attribute__((used)) static inline void *l2tp_session_priv(struct l2tp_session *session)
{
	return &session->priv[0];
}

__attribute__((used)) static inline void l2tp_tunnel_inc_refcount(struct l2tp_tunnel *tunnel)
{
	refcount_inc(&tunnel->ref_count);
}

__attribute__((used)) static inline void l2tp_tunnel_dec_refcount(struct l2tp_tunnel *tunnel)
{
	if (refcount_dec_and_test(&tunnel->ref_count))
		l2tp_tunnel_free(tunnel);
}

__attribute__((used)) static inline void l2tp_session_inc_refcount(struct l2tp_session *session)
{
	refcount_inc(&session->ref_count);
}

__attribute__((used)) static inline void l2tp_session_dec_refcount(struct l2tp_session *session)
{
	if (refcount_dec_and_test(&session->ref_count))
		l2tp_session_free(session);
}

__attribute__((used)) static inline int l2tp_get_l2specific_len(struct l2tp_session *session)
{
	switch (session->l2specific_type) {
	case L2TP_L2SPECTYPE_DEFAULT:
		return 4;
	case L2TP_L2SPECTYPE_NONE:
	default:
		return 0;
	}
}

__attribute__((used)) static inline u32 l2tp_tunnel_dst_mtu(const struct l2tp_tunnel *tunnel)
{
	struct dst_entry *dst;
	u32 mtu;

	dst = sk_dst_get(tunnel->sock);
	if (!dst)
		return 0;

	mtu = dst_mtu(dst);
	dst_release(dst);

	return mtu;
}

__attribute__((used)) static inline bool l2tp_tunnel_uses_xfrm(const struct l2tp_tunnel *tunnel)
{
	return false;
}

__attribute__((used)) static inline int l2tp_v3_ensure_opt_in_linear(struct l2tp_session *session, struct sk_buff *skb,
					       unsigned char **ptr, unsigned char **optr)
{
	int opt_len = session->peer_cookie_len + l2tp_get_l2specific_len(session);

	if (opt_len > 0) {
		int off = *ptr - *optr;

		if (!pskb_may_pull(skb, off + opt_len))
			return -1;

		if (skb->data != *optr) {
			*optr = skb->data;
			*ptr = skb->data + off;
		}
	}

	return 0;
}

__attribute__((used)) static int l2tp_eth_dev_init(struct net_device *dev)
{
	eth_hw_addr_random(dev);
	eth_broadcast_addr(dev->broadcast);
	netdev_lockdep_set_classes(dev);

	return 0;
}

__attribute__((used)) static void l2tp_eth_dev_uninit(struct net_device *dev)
{
	struct l2tp_eth *priv = netdev_priv(dev);
	struct l2tp_eth_sess *spriv;

	spriv = l2tp_session_priv(priv->session);
	RCU_INIT_POINTER(spriv->dev, NULL);
	/* No need for synchronize_net() here. We're called by
	 * unregister_netdev*(), which does the synchronisation for us.
	 */
}

__attribute__((used)) static int l2tp_eth_dev_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct l2tp_eth *priv = netdev_priv(dev);
	struct l2tp_session *session = priv->session;
	unsigned int len = skb->len;
	int ret = l2tp_xmit_skb(session, skb, session->hdr_len);

	if (likely(ret == NET_XMIT_SUCCESS)) {
		atomic_long_add(len, &priv->tx_bytes);
		atomic_long_inc(&priv->tx_packets);
	} else {
		atomic_long_inc(&priv->tx_dropped);
	}
	return NETDEV_TX_OK;
}

__attribute__((used)) static void l2tp_eth_get_stats64(struct net_device *dev,
				 struct rtnl_link_stats64 *stats)
{
	struct l2tp_eth *priv = netdev_priv(dev);

	stats->tx_bytes   = (unsigned long) atomic_long_read(&priv->tx_bytes);
	stats->tx_packets = (unsigned long) atomic_long_read(&priv->tx_packets);
	stats->tx_dropped = (unsigned long) atomic_long_read(&priv->tx_dropped);
	stats->rx_bytes   = (unsigned long) atomic_long_read(&priv->rx_bytes);
	stats->rx_packets = (unsigned long) atomic_long_read(&priv->rx_packets);
	stats->rx_errors  = (unsigned long) atomic_long_read(&priv->rx_errors);

}

__attribute__((used)) static void l2tp_eth_dev_setup(struct net_device *dev)
{
	SET_NETDEV_DEVTYPE(dev, &l2tpeth_type);
	ether_setup(dev);
	dev->priv_flags		&= ~IFF_TX_SKB_SHARING;
	dev->features		|= NETIF_F_LLTX;
	dev->netdev_ops		= &l2tp_eth_netdev_ops;
	dev->needs_free_netdev	= true;
}

__attribute__((used)) static void l2tp_eth_dev_recv(struct l2tp_session *session, struct sk_buff *skb, int data_len)
{
	struct l2tp_eth_sess *spriv = l2tp_session_priv(session);
	struct net_device *dev;
	struct l2tp_eth *priv;

	if (session->debug & L2TP_MSG_DATA) {
		unsigned int length;

		length = min(32u, skb->len);
		if (!pskb_may_pull(skb, length))
			goto error;

		pr_debug("%s: eth recv\n", session->name);
		print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, skb->data, length);
	}

	if (!pskb_may_pull(skb, ETH_HLEN))
		goto error;

	secpath_reset(skb);

	/* checksums verified by L2TP */
	skb->ip_summed = CHECKSUM_NONE;

	skb_dst_drop(skb);
	nf_reset(skb);

	rcu_read_lock();
	dev = rcu_dereference(spriv->dev);
	if (!dev)
		goto error_rcu;

	priv = netdev_priv(dev);
	if (dev_forward_skb(dev, skb) == NET_RX_SUCCESS) {
		atomic_long_inc(&priv->rx_packets);
		atomic_long_add(data_len, &priv->rx_bytes);
	} else {
		atomic_long_inc(&priv->rx_errors);
	}
	rcu_read_unlock();

	return;

error_rcu:
	rcu_read_unlock();
error:
	kfree_skb(skb);
}

__attribute__((used)) static void l2tp_eth_delete(struct l2tp_session *session)
{
	struct l2tp_eth_sess *spriv;
	struct net_device *dev;

	if (session) {
		spriv = l2tp_session_priv(session);

		rtnl_lock();
		dev = rtnl_dereference(spriv->dev);
		if (dev) {
			unregister_netdevice(dev);
			rtnl_unlock();
			module_put(THIS_MODULE);
		} else {
			rtnl_unlock();
		}
	}
}

__attribute__((used)) static void l2tp_eth_show(struct seq_file *m, void *arg)
{
	struct l2tp_session *session = arg;
	struct l2tp_eth_sess *spriv = l2tp_session_priv(session);
	struct net_device *dev;

	rcu_read_lock();
	dev = rcu_dereference(spriv->dev);
	if (!dev) {
		rcu_read_unlock();
		return;
	}
	dev_hold(dev);
	rcu_read_unlock();

	seq_printf(m, "   interface %s\n", dev->name);

	dev_put(dev);
}

__attribute__((used)) static void l2tp_eth_adjust_mtu(struct l2tp_tunnel *tunnel,
				struct l2tp_session *session,
				struct net_device *dev)
{
	unsigned int overhead = 0;
	u32 l3_overhead = 0;
	u32 mtu;

	/* if the encap is UDP, account for UDP header size */
	if (tunnel->encap == L2TP_ENCAPTYPE_UDP) {
		overhead += sizeof(struct udphdr);
		dev->needed_headroom += sizeof(struct udphdr);
	}

	lock_sock(tunnel->sock);
	l3_overhead = kernel_sock_ip_overhead(tunnel->sock);
	release_sock(tunnel->sock);

	if (l3_overhead == 0) {
		/* L3 Overhead couldn't be identified, this could be
		 * because tunnel->sock was NULL or the socket's
		 * address family was not IPv4 or IPv6,
		 * dev mtu stays at 1500.
		 */
		return;
	}
	/* Adjust MTU, factor overhead - underlay L3, overlay L2 hdr
	 * UDP overhead, if any, was already factored in above.
	 */
	overhead += session->hdr_len + ETH_HLEN + l3_overhead;

	mtu = l2tp_tunnel_dst_mtu(tunnel) - overhead;
	if (mtu < dev->min_mtu || mtu > dev->max_mtu)
		dev->mtu = ETH_DATA_LEN - overhead;
	else
		dev->mtu = mtu;

	dev->needed_headroom += session->hdr_len;
}

__attribute__((used)) static int l2tp_eth_create(struct net *net, struct l2tp_tunnel *tunnel,
			   u32 session_id, u32 peer_session_id,
			   struct l2tp_session_cfg *cfg)
{
	unsigned char name_assign_type;
	struct net_device *dev;
	char name[IFNAMSIZ];
	struct l2tp_session *session;
	struct l2tp_eth *priv;
	struct l2tp_eth_sess *spriv;
	int rc;

	if (cfg->ifname) {
		strlcpy(name, cfg->ifname, IFNAMSIZ);
		name_assign_type = NET_NAME_USER;
	} else {
		strcpy(name, L2TP_ETH_DEV_NAME);
		name_assign_type = NET_NAME_ENUM;
	}

	session = l2tp_session_create(sizeof(*spriv), tunnel, session_id,
				      peer_session_id, cfg);
	if (IS_ERR(session)) {
		rc = PTR_ERR(session);
		goto err;
	}

	dev = alloc_netdev(sizeof(*priv), name, name_assign_type,
			   l2tp_eth_dev_setup);
	if (!dev) {
		rc = -ENOMEM;
		goto err_sess;
	}

	dev_net_set(dev, net);
	dev->min_mtu = 0;
	dev->max_mtu = ETH_MAX_MTU;
	l2tp_eth_adjust_mtu(tunnel, session, dev);

	priv = netdev_priv(dev);
	priv->session = session;

	session->recv_skb = l2tp_eth_dev_recv;
	session->session_close = l2tp_eth_delete;
	if (IS_ENABLED(CONFIG_L2TP_DEBUGFS))
		session->show = l2tp_eth_show;

	spriv = l2tp_session_priv(session);

	l2tp_session_inc_refcount(session);

	rtnl_lock();

	/* Register both device and session while holding the rtnl lock. This
	 * ensures that l2tp_eth_delete() will see that there's a device to
	 * unregister, even if it happened to run before we assign spriv->dev.
	 */
	rc = l2tp_session_register(session, tunnel);
	if (rc < 0) {
		rtnl_unlock();
		goto err_sess_dev;
	}

	rc = register_netdevice(dev);
	if (rc < 0) {
		rtnl_unlock();
		l2tp_session_delete(session);
		l2tp_session_dec_refcount(session);
		free_netdev(dev);

		return rc;
	}

	strlcpy(session->ifname, dev->name, IFNAMSIZ);
	rcu_assign_pointer(spriv->dev, dev);

	rtnl_unlock();

	l2tp_session_dec_refcount(session);

	__module_get(THIS_MODULE);

	return 0;

err_sess_dev:
	l2tp_session_dec_refcount(session);
	free_netdev(dev);
err_sess:
	kfree(session);
err:
	return rc;
}

