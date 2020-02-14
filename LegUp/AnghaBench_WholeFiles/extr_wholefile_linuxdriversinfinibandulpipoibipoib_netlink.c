#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  void* u64 ;
typedef  scalar_t__ u16 ;
struct sk_buff {int dummy; } ;
struct rdma_netdev {struct ipoib_dev_priv* clnt_priv; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct net_device {scalar_t__ type; } ;
struct net {int dummy; } ;
struct ipoib_tx_buf {void** mapping; struct sk_buff* skb; } ;
struct ipoib_path {int dummy; } ;
struct ipoib_neigh {int /*<<< orphan*/  refcnt; } ;
struct TYPE_6__ {int num_sge; } ;
struct TYPE_7__ {TYPE_2__ wr; } ;
struct ipoib_dev_priv {scalar_t__ pkey; int /*<<< orphan*/  flags; TYPE_3__ tx_wr; TYPE_1__* tx_sge; } ;
struct ipoib_cm_tx {int dummy; } ;
struct ipoib_ah {int /*<<< orphan*/  ref; } ;
struct ib_wc {int dummy; } ;
typedef  int /*<<< orphan*/  skb_frag_t ;
struct TYPE_8__ {int nr_frags; int /*<<< orphan*/ * frags; } ;
struct TYPE_5__ {scalar_t__ length; void* addr; } ;

/* Variables and functions */
 scalar_t__ ARPHRD_INFINIBAND ; 
 int EINVAL ; 
 int EMSGSIZE ; 
 int ENODEV ; 
 int EOPNOTSUPP ; 
 size_t IFLA_IPOIB_MODE ; 
 size_t IFLA_IPOIB_PKEY ; 
 size_t IFLA_IPOIB_UMCAST ; 
 size_t IFLA_LINK ; 
 int /*<<< orphan*/  IPOIB_FLAG_ADMIN_CM ; 
 int /*<<< orphan*/  IPOIB_FLAG_SUBINTERFACE ; 
 int /*<<< orphan*/  IPOIB_FLAG_UMCAST ; 
 int /*<<< orphan*/  IPOIB_HARD_LEN ; 
 scalar_t__ IPOIB_MODE_CONNECTED ; 
 scalar_t__ IPOIB_MODE_DATAGRAM ; 
 int /*<<< orphan*/  IPOIB_PSEUDO_LEN ; 
 int /*<<< orphan*/  IPOIB_RTNL_CHILD ; 
 struct net_device* __dev_get_by_index (struct net*,int /*<<< orphan*/ ) ; 
 int __ipoib_vlan_add (struct ipoib_dev_priv*,struct ipoib_dev_priv*,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  ipoib_dbg (struct ipoib_dev_priv*,char*) ; 
 int /*<<< orphan*/  ipoib_free_ah ; 
 int /*<<< orphan*/  ipoib_neigh_dtor (struct ipoib_neigh*) ; 
 int ipoib_set_mode (struct net_device*,char*) ; 
 int /*<<< orphan*/  ipoib_set_umcast (struct net_device*,scalar_t__) ; 
 int /*<<< orphan*/  ipoib_warn (struct ipoib_dev_priv*,char*) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rdma_netdev* netdev_priv (struct net_device const*) ; 
 scalar_t__ nla_get_u16 (struct nlattr*) ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 scalar_t__ nla_put_u16 (struct sk_buff*,size_t,scalar_t__) ; 
 size_t nla_total_size (int) ; 
 scalar_t__ skb_frag_size (int /*<<< orphan*/ *) ; 
 scalar_t__ skb_headlen (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int /*<<< orphan*/ ) ; 
 char* skb_push (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 TYPE_4__* skb_shinfo (struct sk_buff*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void skb_add_pseudo_hdr(struct sk_buff *skb)
{
	char *data = skb_push(skb, IPOIB_PSEUDO_LEN);

	/*
	 * only the ipoib header is present now, make room for a dummy
	 * pseudo header and set skb field accordingly
	 */
	memset(data, 0, IPOIB_PSEUDO_LEN);
	skb_reset_mac_header(skb);
	skb_pull(skb, IPOIB_HARD_LEN);
}

__attribute__((used)) static inline struct ipoib_dev_priv *ipoib_priv(const struct net_device *dev)
{
	struct rdma_netdev *rn = netdev_priv(dev);

	return rn->clnt_priv;
}

__attribute__((used)) static inline void ipoib_neigh_put(struct ipoib_neigh *neigh)
{
	if (atomic_dec_and_test(&neigh->refcnt))
		ipoib_neigh_dtor(neigh);
}

__attribute__((used)) static inline void ipoib_put_ah(struct ipoib_ah *ah)
{
	kref_put(&ah->ref, ipoib_free_ah);
}

__attribute__((used)) static inline void ipoib_build_sge(struct ipoib_dev_priv *priv,
				   struct ipoib_tx_buf *tx_req)
{
	int i, off;
	struct sk_buff *skb = tx_req->skb;
	skb_frag_t *frags = skb_shinfo(skb)->frags;
	int nr_frags = skb_shinfo(skb)->nr_frags;
	u64 *mapping = tx_req->mapping;

	if (skb_headlen(skb)) {
		priv->tx_sge[0].addr         = mapping[0];
		priv->tx_sge[0].length       = skb_headlen(skb);
		off = 1;
	} else
		off = 0;

	for (i = 0; i < nr_frags; ++i) {
		priv->tx_sge[i + off].addr = mapping[i + off];
		priv->tx_sge[i + off].length = skb_frag_size(&frags[i]);
	}
	priv->tx_wr.wr.num_sge	     = nr_frags + off;
}

__attribute__((used)) static inline int ipoib_cm_admin_enabled(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline int ipoib_cm_enabled(struct net_device *dev, u8 *hwaddr)

{
	return 0;
}

__attribute__((used)) static inline int ipoib_cm_up(struct ipoib_neigh *neigh)

{
	return 0;
}

__attribute__((used)) static inline struct ipoib_cm_tx *ipoib_cm_get(struct ipoib_neigh *neigh)
{
	return NULL;
}

__attribute__((used)) static inline void ipoib_cm_set(struct ipoib_neigh *neigh, struct ipoib_cm_tx *tx)
{
}

__attribute__((used)) static inline int ipoib_cm_has_srq(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline unsigned int ipoib_cm_max_mtu(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline
void ipoib_cm_send(struct net_device *dev, struct sk_buff *skb, struct ipoib_cm_tx *tx)
{
	return;
}

__attribute__((used)) static inline
int ipoib_cm_dev_open(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline
void ipoib_cm_dev_stop(struct net_device *dev)
{
	return;
}

__attribute__((used)) static inline
int ipoib_cm_dev_init(struct net_device *dev)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline
void ipoib_cm_dev_cleanup(struct net_device *dev)
{
	return;
}

__attribute__((used)) static inline
struct ipoib_cm_tx *ipoib_cm_create_tx(struct net_device *dev, struct ipoib_path *path,
				    struct ipoib_neigh *neigh)
{
	return NULL;
}

__attribute__((used)) static inline
void ipoib_cm_destroy_tx(struct ipoib_cm_tx *tx)
{
	return;
}

__attribute__((used)) static inline
int ipoib_cm_add_mode_attr(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void ipoib_cm_skb_too_long(struct net_device *dev, struct sk_buff *skb,
					 unsigned int mtu)
{
	dev_kfree_skb_any(skb);
}

__attribute__((used)) static inline void ipoib_cm_handle_rx_wc(struct net_device *dev, struct ib_wc *wc)
{
}

__attribute__((used)) static inline void ipoib_cm_handle_tx_wc(struct net_device *dev, struct ib_wc *wc)
{
}

__attribute__((used)) static inline void ipoib_create_debug_files(struct net_device *dev) { }

__attribute__((used)) static inline void ipoib_delete_debug_files(struct net_device *dev) { }

__attribute__((used)) static inline int ipoib_register_debugfs(void) { return 0; }

__attribute__((used)) static inline void ipoib_unregister_debugfs(void) { }

__attribute__((used)) static int ipoib_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
	struct ipoib_dev_priv *priv = ipoib_priv(dev);
	u16 val;

	if (nla_put_u16(skb, IFLA_IPOIB_PKEY, priv->pkey))
		goto nla_put_failure;

	val = test_bit(IPOIB_FLAG_ADMIN_CM, &priv->flags);
	if (nla_put_u16(skb, IFLA_IPOIB_MODE, val))
		goto nla_put_failure;

	val = test_bit(IPOIB_FLAG_UMCAST, &priv->flags);
	if (nla_put_u16(skb, IFLA_IPOIB_UMCAST, val))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -EMSGSIZE;
}

__attribute__((used)) static int ipoib_changelink(struct net_device *dev, struct nlattr *tb[],
			    struct nlattr *data[],
			    struct netlink_ext_ack *extack)
{
	u16 mode, umcast;
	int ret = 0;

	if (data[IFLA_IPOIB_MODE]) {
		mode  = nla_get_u16(data[IFLA_IPOIB_MODE]);
		if (mode == IPOIB_MODE_DATAGRAM)
			ret = ipoib_set_mode(dev, "datagram\n");
		else if (mode == IPOIB_MODE_CONNECTED)
			ret = ipoib_set_mode(dev, "connected\n");
		else
			ret = -EINVAL;

		if (ret < 0)
			goto out_err;
	}

	if (data[IFLA_IPOIB_UMCAST]) {
		umcast = nla_get_u16(data[IFLA_IPOIB_UMCAST]);
		ipoib_set_umcast(dev, umcast);
	}

out_err:
	return ret;
}

__attribute__((used)) static int ipoib_new_child_link(struct net *src_net, struct net_device *dev,
				struct nlattr *tb[], struct nlattr *data[],
				struct netlink_ext_ack *extack)
{
	struct net_device *pdev;
	struct ipoib_dev_priv *ppriv;
	u16 child_pkey;
	int err;

	if (!tb[IFLA_LINK])
		return -EINVAL;

	pdev = __dev_get_by_index(src_net, nla_get_u32(tb[IFLA_LINK]));
	if (!pdev || pdev->type != ARPHRD_INFINIBAND)
		return -ENODEV;

	ppriv = ipoib_priv(pdev);

	if (test_bit(IPOIB_FLAG_SUBINTERFACE, &ppriv->flags)) {
		ipoib_warn(ppriv, "child creation disallowed for child devices\n");
		return -EINVAL;
	}

	if (!data || !data[IFLA_IPOIB_PKEY]) {
		ipoib_dbg(ppriv, "no pkey specified, using parent pkey\n");
		child_pkey  = ppriv->pkey;
	} else
		child_pkey  = nla_get_u16(data[IFLA_IPOIB_PKEY]);

	err = __ipoib_vlan_add(ppriv, ipoib_priv(dev),
			       child_pkey, IPOIB_RTNL_CHILD);

	if (!err && data)
		err = ipoib_changelink(dev, tb, data, extack);
	return err;
}

__attribute__((used)) static size_t ipoib_get_size(const struct net_device *dev)
{
	return nla_total_size(2) +	/* IFLA_IPOIB_PKEY   */
		nla_total_size(2) +	/* IFLA_IPOIB_MODE   */
		nla_total_size(2);	/* IFLA_IPOIB_UMCAST */
}

