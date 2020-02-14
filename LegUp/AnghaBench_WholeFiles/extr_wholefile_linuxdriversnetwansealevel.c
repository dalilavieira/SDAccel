#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_6__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct z8530_channel {int /*<<< orphan*/  netdevice; } ;
struct slvl_device {int channel; TYPE_1__* chan; } ;
struct sk_buff {int /*<<< orphan*/  dev; int /*<<< orphan*/  protocol; scalar_t__ len; } ;
struct net_device {int base_addr; int irq; int /*<<< orphan*/ * netdev_ops; } ;
struct ifreq {int dummy; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
struct TYPE_8__ {int (* attach ) (struct net_device*,unsigned short,unsigned short) ;int /*<<< orphan*/  (* xmit ) (struct sk_buff*,struct net_device*) ;scalar_t__ priv; } ;
struct TYPE_7__ {void (* rx_function ) (struct z8530_channel*,struct sk_buff*) ;struct net_device* netdevice; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned short ENCODING_NRZ ; 
 unsigned short PARITY_CRC16_PR1_CCITT ; 
 struct net_device* alloc_hdlcdev (struct slvl_device*) ; 
 TYPE_6__* dev_to_hdlc (struct net_device*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 int /*<<< orphan*/  hdlc_close (struct net_device*) ; 
 int hdlc_ioctl (struct net_device*,struct ifreq*,int) ; 
 int hdlc_open (struct net_device*) ; 
 int /*<<< orphan*/  hdlc_type_trans (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__ register_hdlc_device (struct net_device*) ; 
 int /*<<< orphan*/  sealevel_ops ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_trim (struct sk_buff*,scalar_t__) ; 
 void z8530_null_rx (struct z8530_channel*,struct sk_buff*) ; 
 int /*<<< orphan*/  z8530_queue_xmit (TYPE_1__*,struct sk_buff*) ; 
 int /*<<< orphan*/  z8530_sync_close (struct net_device*,TYPE_1__*) ; 
 int /*<<< orphan*/  z8530_sync_dma_close (struct net_device*,TYPE_1__*) ; 
 int z8530_sync_dma_open (struct net_device*,TYPE_1__*) ; 
 int z8530_sync_open (struct net_device*,TYPE_1__*) ; 

__attribute__((used)) static inline struct slvl_device* dev_to_chan(struct net_device *dev)
{
	return (struct slvl_device *)dev_to_hdlc(dev)->priv;
}

__attribute__((used)) static void sealevel_input(struct z8530_channel *c, struct sk_buff *skb)
{
	/* Drop the CRC - it's not a good idea to try and negotiate it ;) */
	skb_trim(skb, skb->len - 2);
	skb->protocol = hdlc_type_trans(skb, c->netdevice);
	skb_reset_mac_header(skb);
	skb->dev = c->netdevice;
	netif_rx(skb);
}

__attribute__((used)) static int sealevel_open(struct net_device *d)
{
	struct slvl_device *slvl = dev_to_chan(d);
	int err = -1;
	int unit = slvl->channel;

	/*
	 *	Link layer up.
	 */

	switch (unit) {
		case 0:
			err = z8530_sync_dma_open(d, slvl->chan);
			break;
		case 1:
			err = z8530_sync_open(d, slvl->chan);
			break;
	}

	if (err)
		return err;

	err = hdlc_open(d);
	if (err) {
		switch (unit) {
			case 0:
				z8530_sync_dma_close(d, slvl->chan);
				break;
			case 1:
				z8530_sync_close(d, slvl->chan);
				break;
		}
		return err;
	}

	slvl->chan->rx_function = sealevel_input;

	/*
	 *	Go go go
	 */
	netif_start_queue(d);
	return 0;
}

__attribute__((used)) static int sealevel_close(struct net_device *d)
{
	struct slvl_device *slvl = dev_to_chan(d);
	int unit = slvl->channel;

	/*
	 *	Discard new frames
	 */

	slvl->chan->rx_function = z8530_null_rx;

	hdlc_close(d);
	netif_stop_queue(d);

	switch (unit) {
		case 0:
			z8530_sync_dma_close(d, slvl->chan);
			break;
		case 1:
			z8530_sync_close(d, slvl->chan);
			break;
	}
	return 0;
}

__attribute__((used)) static int sealevel_ioctl(struct net_device *d, struct ifreq *ifr, int cmd)
{
	/* struct slvl_device *slvl=dev_to_chan(d);
	   z8530_ioctl(d,&slvl->sync.chanA,ifr,cmd) */
	return hdlc_ioctl(d, ifr, cmd);
}

__attribute__((used)) static netdev_tx_t sealevel_queue_xmit(struct sk_buff *skb,
					     struct net_device *d)
{
	return z8530_queue_xmit(dev_to_chan(d)->chan, skb);
}

__attribute__((used)) static int sealevel_attach(struct net_device *dev, unsigned short encoding,
			   unsigned short parity)
{
	if (encoding == ENCODING_NRZ && parity == PARITY_CRC16_PR1_CCITT)
		return 0;
	return -EINVAL;
}

__attribute__((used)) static int slvl_setup(struct slvl_device *sv, int iobase, int irq)
{
	struct net_device *dev = alloc_hdlcdev(sv);
	if (!dev)
		return -1;

	dev_to_hdlc(dev)->attach = sealevel_attach;
	dev_to_hdlc(dev)->xmit = sealevel_queue_xmit;
	dev->netdev_ops = &sealevel_ops;
	dev->base_addr = iobase;
	dev->irq = irq;

	if (register_hdlc_device(dev)) {
		pr_err("unable to register HDLC device\n");
		free_netdev(dev);
		return -1;
	}

	sv->chan->netdevice = dev;
	return 0;
}

