#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct sk_buff {int dummy; } ;
struct net_device {scalar_t__ mtu; } ;
struct TYPE_12__ {int link_state; scalar_t__ link_speed; } ;
struct mlx4_en_priv {int validate_loopback; int rx_ring_num; scalar_t__ port_up; struct mlx4_en_dev* mdev; TYPE_2__ port_state; int /*<<< orphan*/  port; TYPE_1__** rx_cq; TYPE_4__* dev; scalar_t__ loopback_ok; } ;
struct mlx4_en_dev {TYPE_5__* dev; } ;
typedef  void mlx4_cqe ;
struct ethhdr {int /*<<< orphan*/  h_proto; int /*<<< orphan*/  h_source; int /*<<< orphan*/  h_dest; } ;
struct TYPE_13__ {int flags; } ;
struct TYPE_15__ {int flags; TYPE_3__ caps; } ;
struct TYPE_14__ {int /*<<< orphan*/  features; int /*<<< orphan*/  dev_addr; } ;
struct TYPE_11__ {int /*<<< orphan*/  vector; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 scalar_t__ ETH_HLEN ; 
 int /*<<< orphan*/  ETH_P_ARP ; 
 int ETH_TEST_FL_FAILED ; 
 int ETH_TEST_FL_OFFLINE ; 
 int /*<<< orphan*/  MLX4_CMD_HW_HEALTH_CHECK ; 
 int /*<<< orphan*/  MLX4_CMD_TIME_CLASS_A ; 
 int /*<<< orphan*/  MLX4_CMD_WRAPPED ; 
 int MLX4_DEV_CAP_FLAG_UC_LOOPBACK ; 
 int MLX4_EN_LOOPBACK_RETRIES ; 
 int MLX4_EN_LOOPBACK_TIMEOUT ; 
 int MLX4_EN_NUM_SELF_TEST ; 
 int MLX4_FLAG_MSI_X ; 
 unsigned int MLX4_LOOPBACK_TEST_PAYLOAD ; 
 scalar_t__ MLX4_SELFTEST_LB_MIN_MTU ; 
 scalar_t__ NET_IP_ALIGN ; 
 scalar_t__ SPEED_100 ; 
 scalar_t__ SPEED_1000 ; 
 scalar_t__ SPEED_10000 ; 
 scalar_t__ SPEED_20000 ; 
 scalar_t__ SPEED_40000 ; 
 scalar_t__ SPEED_56000 ; 
 int /*<<< orphan*/  en_err (struct mlx4_en_priv*,char*) ; 
 int /*<<< orphan*/  eth_zero_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int mlx4_cmd (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mlx4_en_QUERY_PORT (struct mlx4_en_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx4_en_update_loopback_state (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int mlx4_en_xmit (struct sk_buff*,TYPE_4__*) ; 
 scalar_t__ mlx4_is_slave (TYPE_5__*) ; 
 int mlx4_test_async (TYPE_5__*) ; 
 int mlx4_test_interrupt (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct sk_buff* netdev_alloc_skb (TYPE_4__*,scalar_t__) ; 
 struct mlx4_en_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_off (struct net_device*) ; 
 int netif_carrier_ok (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_on (struct net_device*) ; 
 void* skb_put (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 

__attribute__((used)) static inline struct mlx4_cqe *mlx4_en_get_cqe(void *buf, int idx, int cqe_sz)
{
	return buf + idx * cqe_sz;
}

__attribute__((used)) static int mlx4_en_test_registers(struct mlx4_en_priv *priv)
{
	return mlx4_cmd(priv->mdev->dev, 0, 0, 0, MLX4_CMD_HW_HEALTH_CHECK,
			MLX4_CMD_TIME_CLASS_A, MLX4_CMD_WRAPPED);
}

__attribute__((used)) static int mlx4_en_test_loopback_xmit(struct mlx4_en_priv *priv)
{
	struct sk_buff *skb;
	struct ethhdr *ethh;
	unsigned char *packet;
	unsigned int packet_size = MLX4_LOOPBACK_TEST_PAYLOAD;
	unsigned int i;
	int err;


	/* build the pkt before xmit */
	skb = netdev_alloc_skb(priv->dev, MLX4_LOOPBACK_TEST_PAYLOAD + ETH_HLEN + NET_IP_ALIGN);
	if (!skb)
		return -ENOMEM;

	skb_reserve(skb, NET_IP_ALIGN);

	ethh = skb_put(skb, sizeof(struct ethhdr));
	packet = skb_put(skb, packet_size);
	memcpy(ethh->h_dest, priv->dev->dev_addr, ETH_ALEN);
	eth_zero_addr(ethh->h_source);
	ethh->h_proto = htons(ETH_P_ARP);
	skb_reset_mac_header(skb);
	for (i = 0; i < packet_size; ++i)	/* fill our packet */
		packet[i] = (unsigned char)(i & 0xff);

	/* xmit the pkt */
	err = mlx4_en_xmit(skb, priv->dev);
	return err;
}

__attribute__((used)) static int mlx4_en_test_loopback(struct mlx4_en_priv *priv)
{
	u32 loopback_ok = 0;
	int i;

        priv->loopback_ok = 0;
	priv->validate_loopback = 1;

	mlx4_en_update_loopback_state(priv->dev, priv->dev->features);

	/* xmit */
	if (mlx4_en_test_loopback_xmit(priv)) {
		en_err(priv, "Transmitting loopback packet failed\n");
		goto mlx4_en_test_loopback_exit;
	}

	/* polling for result */
	for (i = 0; i < MLX4_EN_LOOPBACK_RETRIES; ++i) {
		msleep(MLX4_EN_LOOPBACK_TIMEOUT);
		if (priv->loopback_ok) {
			loopback_ok = 1;
			break;
		}
	}
	if (!loopback_ok)
		en_err(priv, "Loopback packet didn't arrive\n");

mlx4_en_test_loopback_exit:

	priv->validate_loopback = 0;

	mlx4_en_update_loopback_state(priv->dev, priv->dev->features);
	return !loopback_ok;
}

__attribute__((used)) static int mlx4_en_test_interrupts(struct mlx4_en_priv *priv)
{
	struct mlx4_en_dev *mdev = priv->mdev;
	int err = 0;
	int i = 0;

	err = mlx4_test_async(mdev->dev);
	/* When not in MSI_X or slave, test only async */
	if (!(mdev->dev->flags & MLX4_FLAG_MSI_X) || mlx4_is_slave(mdev->dev))
		return err;

	/* A loop over all completion vectors of current port,
	 * for each vector check whether it works by mapping command
	 * completions to that vector and performing a NOP command
	 */
	for (i = 0; i < priv->rx_ring_num; i++) {
		err = mlx4_test_interrupt(mdev->dev, priv->rx_cq[i]->vector);
		if (err)
			break;
	}

	return err;
}

__attribute__((used)) static int mlx4_en_test_link(struct mlx4_en_priv *priv)
{
	if (mlx4_en_QUERY_PORT(priv->mdev, priv->port))
		return -ENOMEM;
	if (priv->port_state.link_state == 1)
		return 0;
	else
		return 1;
}

__attribute__((used)) static int mlx4_en_test_speed(struct mlx4_en_priv *priv)
{

	if (mlx4_en_QUERY_PORT(priv->mdev, priv->port))
		return -ENOMEM;

	/* The device supports 100M, 1G, 10G, 20G, 40G and 56G speed */
	if (priv->port_state.link_speed != SPEED_100 &&
	    priv->port_state.link_speed != SPEED_1000 &&
	    priv->port_state.link_speed != SPEED_10000 &&
	    priv->port_state.link_speed != SPEED_20000 &&
	    priv->port_state.link_speed != SPEED_40000 &&
	    priv->port_state.link_speed != SPEED_56000)
		return priv->port_state.link_speed;

	return 0;
}

void mlx4_en_ex_selftest(struct net_device *dev, u32 *flags, u64 *buf)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int i, carrier_ok;

	memset(buf, 0, sizeof(u64) * MLX4_EN_NUM_SELF_TEST);

	if (*flags & ETH_TEST_FL_OFFLINE) {
		/* disable the interface */
		carrier_ok = netif_carrier_ok(dev);

		netif_carrier_off(dev);
		/* Wait until all tx queues are empty.
		 * there should not be any additional incoming traffic
		 * since we turned the carrier off */
		msleep(200);

		if (priv->mdev->dev->caps.flags &
					MLX4_DEV_CAP_FLAG_UC_LOOPBACK) {
			buf[3] = mlx4_en_test_registers(priv);
			if (priv->port_up && dev->mtu >= MLX4_SELFTEST_LB_MIN_MTU)
				buf[4] = mlx4_en_test_loopback(priv);
		}

		if (carrier_ok)
			netif_carrier_on(dev);

	}
	buf[0] = mlx4_en_test_interrupts(priv);
	buf[1] = mlx4_en_test_link(priv);
	buf[2] = mlx4_en_test_speed(priv);

	for (i = 0; i < MLX4_EN_NUM_SELF_TEST; i++) {
		if (buf[i])
			*flags |= ETH_TEST_FL_FAILED;
	}
}

