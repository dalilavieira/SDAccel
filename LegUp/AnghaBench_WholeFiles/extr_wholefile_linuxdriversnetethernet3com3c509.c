#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int ushort ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {int len; int /*<<< orphan*/  protocol; int /*<<< orphan*/  data; } ;
struct net_device_stats {int tx_bytes; short rx_bytes; int /*<<< orphan*/  rx_dropped; int /*<<< orphan*/  rx_packets; int /*<<< orphan*/  rx_crc_errors; int /*<<< orphan*/  rx_frame_errors; int /*<<< orphan*/  rx_length_errors; int /*<<< orphan*/  rx_over_errors; int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  tx_packets; int /*<<< orphan*/  rx_fifo_errors; int /*<<< orphan*/  tx_window_errors; int /*<<< orphan*/  collisions; int /*<<< orphan*/  tx_heartbeat_errors; int /*<<< orphan*/  tx_carrier_errors; int /*<<< orphan*/  tx_aborted_errors; int /*<<< orphan*/  tx_errors; } ;
struct net_device {int* dev_addr; int base_addr; int irq; int if_port; int mem_start; short name; int flags; struct net_device_stats stats; int /*<<< orphan*/ * ethtool_ops; int /*<<< orphan*/  watchdog_timeo; int /*<<< orphan*/ * netdev_ops; } ;
struct TYPE_4__ {int port; scalar_t__ duplex; scalar_t__ speed; } ;
struct TYPE_3__ {int /*<<< orphan*/  supported; } ;
struct ethtool_link_ksettings {TYPE_2__ base; TYPE_1__ link_modes; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct el3_private {int type; int /*<<< orphan*/  lock; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum el3_cardtype { ____Placeholder_el3_cardtype } el3_cardtype ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int AckIntr ; 
 int AdapterFailure ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int /*<<< orphan*/  DRV_VERSION ; 
 scalar_t__ DUPLEX_FULL ; 
 scalar_t__ DUPLEX_HALF ; 
 int EEPROM_READ ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  EL3WINDOW (int) ; 
 int EL3_CMD ; 
 scalar_t__ EL3_EISA ; 
 int /*<<< orphan*/  EL3_IO_EXTENT ; 
 int EL3_ISA ; 
 int EL3_STATUS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int FD_ENABLE ; 
 int IFF_ALLMULTI ; 
 int IFF_PROMISC ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int IntLatch ; 
 int IntReq ; 
 int MEDIA_TP ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
#define  PORT_AUI 130 
#define  PORT_BNC 129 
#define  PORT_TP 128 
 scalar_t__ RX_FIFO ; 
 int RX_STATUS ; 
 int RxBroadcast ; 
 int RxComplete ; 
 int RxDisable ; 
 int RxDiscard ; 
 int RxEarly ; 
 int RxEnable ; 
 int RxMulticast ; 
 int RxProm ; 
 int RxReset ; 
 int RxStation ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,struct device*) ; 
 scalar_t__ SPEED_10 ; 
 int SUPPORTED_10baseT_Full ; 
 int SUPPORTED_10baseT_Half ; 
 int SUPPORTED_AUI ; 
 int SUPPORTED_BNC ; 
 int SUPPORTED_TP ; 
 int SetIntrEnb ; 
 int SetRxFilter ; 
 int SetStatusEnb ; 
 int SetTxThreshold ; 
 int StartCoax ; 
 int StatsDisable ; 
 int StatsEnable ; 
 int StatsFull ; 
 int StopCoax ; 
 int TX_FIFO ; 
 int TX_FREE ; 
 int TX_STATUS ; 
 int /*<<< orphan*/  TX_TIMEOUT ; 
 int TxAvailable ; 
 int TxComplete ; 
 int TxDisable ; 
 int TxEnable ; 
 int TxReset ; 
 int WN0_ADDR_CONF ; 
 int WN0_CONF_CTRL ; 
 int WN0_IRQ ; 
 int WN4_MEDIA ; 
 int WN4_NETDIAG ; 
 struct net_device* alloc_etherdev (int) ; 
 int current_tag ; 
 int /*<<< orphan*/  dev_consume_skb_any (struct sk_buff*) ; 
 struct net_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct net_device*) ; 
 size_t el3_cards ; 
static  int el3_common_init (struct net_device*) ; 
 int el3_debug ; 
static  int el3_device_remove (struct device*) ; 
 struct net_device** el3_devs ; 
static  void el3_down (struct net_device*) ; 
static  int /*<<< orphan*/  el3_interrupt (int,void*) ; 
static  int el3_rx (struct net_device*) ; 
static  void el3_up (struct net_device*) ; 
 int /*<<< orphan*/  eth_type_trans (struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  ethtool_convert_legacy_u32_to_link_mode (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ethtool_ops ; 
 int /*<<< orphan*/  free_irq (int,struct net_device*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 int /*<<< orphan*/  htons (int) ; 
 int id_port ; 
static  int id_read_eeprom (int) ; 
 int inb (int) ; 
 int /*<<< orphan*/  insl (scalar_t__,int /*<<< orphan*/ ,short) ; 
 int inw (int) ; 
 int* irq ; 
 int max_interrupt_work ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct sk_buff* netdev_alloc_skb (struct net_device*,short) ; 
 int /*<<< orphan*/  netdev_boot_setup_check (struct net_device*) ; 
 int netdev_mc_count (struct net_device*) ; 
 int /*<<< orphan*/  netdev_ops ; 
 struct el3_private* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_trans_update (struct net_device*) ; 
 int /*<<< orphan*/  netif_wake_queue (struct net_device*) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  outsl (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outw (int,int) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,int,int) ; 
 int /*<<< orphan*/  pr_info (char*,short,...) ; 
 int /*<<< orphan*/  pr_warn (char*,short,int,int,int) ; 
 int register_netdev (struct net_device*) ; 
 int /*<<< orphan*/  release_region (int,int /*<<< orphan*/ ) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,short,struct net_device*) ; 
 int /*<<< orphan*/  request_region (int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,short) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 
static  void update_stats (struct net_device*) ; 
 short version ; 

__attribute__((used)) static int el3_isa_id_sequence(__be16 *phys_addr)
{
	short lrs_state = 0xff;
	int i;

	/* ISA boards are detected by sending the ID sequence to the
	   ID_PORT.  We find cards past the first by setting the 'current_tag'
	   on cards as they are found.  Cards with their tag set will not
	   respond to subsequent ID sequences. */

	outb(0x00, id_port);
	outb(0x00, id_port);
	for (i = 0; i < 255; i++) {
		outb(lrs_state, id_port);
		lrs_state <<= 1;
		lrs_state = lrs_state & 0x100 ? lrs_state ^ 0xcf : lrs_state;
	}
	/* For the first probe, clear all board's tag registers. */
	if (current_tag == 0)
		outb(0xd0, id_port);
	else			/* Otherwise kill off already-found boards. */
		outb(0xd8, id_port);
	if (id_read_eeprom(7) != 0x6d50)
		return 1;
	/* Read in EEPROM data, which does contention-select.
	   Only the lowest address board will stay "on-line".
	   3Com got the byte order backwards. */
	for (i = 0; i < 3; i++)
		phys_addr[i] = htons(id_read_eeprom(i));
#ifdef CONFIG_PNP
	if (!nopnp) {
		/* The ISA PnP 3c509 cards respond to the ID sequence too.
		   This check is needed in order not to register them twice. */
		for (i = 0; i < el3_cards; i++) {
			struct el3_private *lp = netdev_priv(el3_devs[i]);
			if (lp->type == EL3_PNP &&
			    ether_addr_equal((u8 *)phys_addr, el3_devs[i]->dev_addr)) {
				if (el3_debug > 3)
					pr_debug("3c509 with address %02x %02x %02x %02x %02x %02x was found by ISAPnP\n",
						phys_addr[0] & 0xff, phys_addr[0] >> 8,
						phys_addr[1] & 0xff, phys_addr[1] >> 8,
						phys_addr[2] & 0xff, phys_addr[2] >> 8);
				/* Set the adaptor tag so that the next card can be found. */
				outb(0xd0 + ++current_tag, id_port);
				return 2;
			}
		}
	}
#endif /* CONFIG_PNP */
	return 0;

}

__attribute__((used)) static void el3_dev_fill(struct net_device *dev, __be16 *phys_addr, int ioaddr,
			 int irq, int if_port, enum el3_cardtype type)
{
	struct el3_private *lp = netdev_priv(dev);

	memcpy(dev->dev_addr, phys_addr, ETH_ALEN);
	dev->base_addr = ioaddr;
	dev->irq = irq;
	dev->if_port = if_port;
	lp->type = type;
}

__attribute__((used)) static int el3_isa_match(struct device *pdev, unsigned int ndev)
{
	struct net_device *dev;
	int ioaddr, isa_irq, if_port, err;
	unsigned int iobase;
	__be16 phys_addr[3];

	while ((err = el3_isa_id_sequence(phys_addr)) == 2)
		;	/* Skip to next card when PnP card found */
	if (err == 1)
		return 0;

	iobase = id_read_eeprom(8);
	if_port = iobase >> 14;
	ioaddr = 0x200 + ((iobase & 0x1f) << 4);
	if (irq[el3_cards] > 1 && irq[el3_cards] < 16)
		isa_irq = irq[el3_cards];
	else
		isa_irq = id_read_eeprom(9) >> 12;

	dev = alloc_etherdev(sizeof(struct el3_private));
	if (!dev)
		return -ENOMEM;

	SET_NETDEV_DEV(dev, pdev);
	netdev_boot_setup_check(dev);

	if (!request_region(ioaddr, EL3_IO_EXTENT, "3c509-isa")) {
		free_netdev(dev);
		return 0;
	}

	/* Set the adaptor tag so that the next card can be found. */
	outb(0xd0 + ++current_tag, id_port);

	/* Activate the adaptor at the EEPROM location. */
	outb((ioaddr >> 4) | 0xe0, id_port);

	EL3WINDOW(0);
	if (inw(ioaddr) != 0x6d50) {
		free_netdev(dev);
		return 0;
	}

	/* Free the interrupt so that some other card can use it. */
	outw(0x0f00, ioaddr + WN0_IRQ);

	el3_dev_fill(dev, phys_addr, ioaddr, isa_irq, if_port, EL3_ISA);
	dev_set_drvdata(pdev, dev);
	if (el3_common_init(dev)) {
		free_netdev(dev);
		return 0;
	}

	el3_devs[el3_cards++] = dev;
	return 1;
}

__attribute__((used)) static int el3_isa_remove(struct device *pdev,
				    unsigned int ndev)
{
	el3_device_remove(pdev);
	dev_set_drvdata(pdev, NULL);
	return 0;
}

__attribute__((used)) static int el3_common_init(struct net_device *dev)
{
	struct el3_private *lp = netdev_priv(dev);
	int err;
	const char *if_names[] = {"10baseT", "AUI", "undefined", "BNC"};

	spin_lock_init(&lp->lock);

	if (dev->mem_start & 0x05) { /* xcvr codes 1/3/4/12 */
		dev->if_port = (dev->mem_start & 0x0f);
	} else { /* xcvr codes 0/8 */
		/* use eeprom value, but save user's full-duplex selection */
		dev->if_port |= (dev->mem_start & 0x08);
	}

	/* The EL3-specific entries in the device structure. */
	dev->netdev_ops = &netdev_ops;
	dev->watchdog_timeo = TX_TIMEOUT;
	dev->ethtool_ops = &ethtool_ops;

	err = register_netdev(dev);
	if (err) {
		pr_err("Failed to register 3c5x9 at %#3.3lx, IRQ %d.\n",
			dev->base_addr, dev->irq);
		release_region(dev->base_addr, EL3_IO_EXTENT);
		return err;
	}

	pr_info("%s: 3c5x9 found at %#3.3lx, %s port, address %pM, IRQ %d.\n",
	       dev->name, dev->base_addr, if_names[(dev->if_port & 0x03)],
	       dev->dev_addr, dev->irq);

	if (el3_debug > 0)
		pr_info("%s", version);
	return 0;

}

__attribute__((used)) static void el3_common_remove (struct net_device *dev)
{
	unregister_netdev (dev);
	release_region(dev->base_addr, EL3_IO_EXTENT);
	free_netdev (dev);
}

__attribute__((used)) static int el3_device_remove(struct device *device)
{
	struct net_device *dev;

	dev = dev_get_drvdata(device);

	el3_common_remove (dev);
	return 0;
}

__attribute__((used)) static ushort read_eeprom(int ioaddr, int index)
{
	outw(EEPROM_READ + index, ioaddr + 10);
	/* Pause for at least 162 us. for the read to take place.
	   Some chips seem to require much longer */
	mdelay(2);
	return inw(ioaddr + 12);
}

__attribute__((used)) static ushort id_read_eeprom(int index)
{
	int bit, word = 0;

	/* Issue read command, and pause for at least 162 us. for it to complete.
	   Assume extra-fast 16Mhz bus. */
	outb(EEPROM_READ + index, id_port);

	/* Pause for at least 162 us. for the read to take place. */
	/* Some chips seem to require much longer */
	mdelay(4);

	for (bit = 15; bit >= 0; bit--)
		word = (word << 1) + (inb(id_port) & 0x01);

	if (el3_debug > 3)
		pr_debug("  3c509 EEPROM word %d %#4.4x.\n", index, word);

	return word;
}

__attribute__((used)) static int
el3_open(struct net_device *dev)
{
	int ioaddr = dev->base_addr;
	int i;

	outw(TxReset, ioaddr + EL3_CMD);
	outw(RxReset, ioaddr + EL3_CMD);
	outw(SetStatusEnb | 0x00, ioaddr + EL3_CMD);

	i = request_irq(dev->irq, el3_interrupt, 0, dev->name, dev);
	if (i)
		return i;

	EL3WINDOW(0);
	if (el3_debug > 3)
		pr_debug("%s: Opening, IRQ %d	 status@%x %4.4x.\n", dev->name,
			   dev->irq, ioaddr + EL3_STATUS, inw(ioaddr + EL3_STATUS));

	el3_up(dev);

	if (el3_debug > 3)
		pr_debug("%s: Opened 3c509  IRQ %d  status %4.4x.\n",
			   dev->name, dev->irq, inw(ioaddr + EL3_STATUS));

	return 0;
}

__attribute__((used)) static void
el3_tx_timeout (struct net_device *dev)
{
	int ioaddr = dev->base_addr;

	/* Transmitter timeout, serious problems. */
	pr_warn("%s: transmit timed out, Tx_status %2.2x status %4.4x Tx FIFO room %d\n",
		dev->name, inb(ioaddr + TX_STATUS), inw(ioaddr + EL3_STATUS),
		inw(ioaddr + TX_FREE));
	dev->stats.tx_errors++;
	netif_trans_update(dev); /* prevent tx timeout */
	/* Issue TX_RESET and TX_START commands. */
	outw(TxReset, ioaddr + EL3_CMD);
	outw(TxEnable, ioaddr + EL3_CMD);
	netif_wake_queue(dev);
}

__attribute__((used)) static netdev_tx_t
el3_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct el3_private *lp = netdev_priv(dev);
	int ioaddr = dev->base_addr;
	unsigned long flags;

	netif_stop_queue (dev);

	dev->stats.tx_bytes += skb->len;

	if (el3_debug > 4) {
		pr_debug("%s: el3_start_xmit(length = %u) called, status %4.4x.\n",
			   dev->name, skb->len, inw(ioaddr + EL3_STATUS));
	}
	/*
	 *	We lock the driver against other processors. Note
	 *	we don't need to lock versus the IRQ as we suspended
	 *	that. This means that we lose the ability to take
	 *	an RX during a TX upload. That sucks a bit with SMP
	 *	on an original 3c509 (2K buffer)
	 *
	 *	Using disable_irq stops us crapping on other
	 *	time sensitive devices.
	 */

	spin_lock_irqsave(&lp->lock, flags);

	/* Put out the doubleword header... */
	outw(skb->len, ioaddr + TX_FIFO);
	outw(0x00, ioaddr + TX_FIFO);
	/* ... and the packet rounded to a doubleword. */
	outsl(ioaddr + TX_FIFO, skb->data, (skb->len + 3) >> 2);

	if (inw(ioaddr + TX_FREE) > 1536)
		netif_start_queue(dev);
	else
		/* Interrupt us when the FIFO has room for max-sized packet. */
		outw(SetTxThreshold + 1536, ioaddr + EL3_CMD);

	spin_unlock_irqrestore(&lp->lock, flags);

	dev_consume_skb_any (skb);

	/* Clear the Tx status stack. */
	{
		short tx_status;
		int i = 4;

		while (--i > 0	&&	(tx_status = inb(ioaddr + TX_STATUS)) > 0) {
			if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
			if (tx_status & 0x30) outw(TxReset, ioaddr + EL3_CMD);
			if (tx_status & 0x3C) outw(TxEnable, ioaddr + EL3_CMD);
			outb(0x00, ioaddr + TX_STATUS); /* Pop the status stack. */
		}
	}
	return NETDEV_TX_OK;
}

__attribute__((used)) static irqreturn_t
el3_interrupt(int irq, void *dev_id)
{
	struct net_device *dev = dev_id;
	struct el3_private *lp;
	int ioaddr, status;
	int i = max_interrupt_work;

	lp = netdev_priv(dev);
	spin_lock(&lp->lock);

	ioaddr = dev->base_addr;

	if (el3_debug > 4) {
		status = inw(ioaddr + EL3_STATUS);
		pr_debug("%s: interrupt, status %4.4x.\n", dev->name, status);
	}

	while ((status = inw(ioaddr + EL3_STATUS)) &
		   (IntLatch | RxComplete | StatsFull)) {

		if (status & RxComplete)
			el3_rx(dev);

		if (status & TxAvailable) {
			if (el3_debug > 5)
				pr_debug("	TX room bit was handled.\n");
			/* There's room in the FIFO for a full-sized packet. */
			outw(AckIntr | TxAvailable, ioaddr + EL3_CMD);
			netif_wake_queue (dev);
		}
		if (status & (AdapterFailure | RxEarly | StatsFull | TxComplete)) {
			/* Handle all uncommon interrupts. */
			if (status & StatsFull)				/* Empty statistics. */
				update_stats(dev);
			if (status & RxEarly) {				/* Rx early is unused. */
				el3_rx(dev);
				outw(AckIntr | RxEarly, ioaddr + EL3_CMD);
			}
			if (status & TxComplete) {			/* Really Tx error. */
				short tx_status;
				int i = 4;

				while (--i>0 && (tx_status = inb(ioaddr + TX_STATUS)) > 0) {
					if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
					if (tx_status & 0x30) outw(TxReset, ioaddr + EL3_CMD);
					if (tx_status & 0x3C) outw(TxEnable, ioaddr + EL3_CMD);
					outb(0x00, ioaddr + TX_STATUS); /* Pop the status stack. */
				}
			}
			if (status & AdapterFailure) {
				/* Adapter failure requires Rx reset and reinit. */
				outw(RxReset, ioaddr + EL3_CMD);
				/* Set the Rx filter to the current state. */
				outw(SetRxFilter | RxStation | RxBroadcast
					 | (dev->flags & IFF_ALLMULTI ? RxMulticast : 0)
					 | (dev->flags & IFF_PROMISC ? RxProm : 0),
					 ioaddr + EL3_CMD);
				outw(RxEnable, ioaddr + EL3_CMD); /* Re-enable the receiver. */
				outw(AckIntr | AdapterFailure, ioaddr + EL3_CMD);
			}
		}

		if (--i < 0) {
			pr_err("%s: Infinite loop in interrupt, status %4.4x.\n",
				   dev->name, status);
			/* Clear all interrupts. */
			outw(AckIntr | 0xFF, ioaddr + EL3_CMD);
			break;
		}
		/* Acknowledge the IRQ. */
		outw(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD); /* Ack IRQ */
	}

	if (el3_debug > 4) {
		pr_debug("%s: exiting interrupt, status %4.4x.\n", dev->name,
			   inw(ioaddr + EL3_STATUS));
	}
	spin_unlock(&lp->lock);
	return IRQ_HANDLED;
}

__attribute__((used)) static struct net_device_stats *
el3_get_stats(struct net_device *dev)
{
	struct el3_private *lp = netdev_priv(dev);
	unsigned long flags;

	/*
	 *	This is fast enough not to bother with disable IRQ
	 *	stuff.
	 */

	spin_lock_irqsave(&lp->lock, flags);
	update_stats(dev);
	spin_unlock_irqrestore(&lp->lock, flags);
	return &dev->stats;
}

__attribute__((used)) static void update_stats(struct net_device *dev)
{
	int ioaddr = dev->base_addr;

	if (el3_debug > 5)
		pr_debug("   Updating the statistics.\n");
	/* Turn off statistics updates while reading. */
	outw(StatsDisable, ioaddr + EL3_CMD);
	/* Switch to the stats window, and read everything. */
	EL3WINDOW(6);
	dev->stats.tx_carrier_errors 	+= inb(ioaddr + 0);
	dev->stats.tx_heartbeat_errors	+= inb(ioaddr + 1);
	/* Multiple collisions. */	   inb(ioaddr + 2);
	dev->stats.collisions		+= inb(ioaddr + 3);
	dev->stats.tx_window_errors	+= inb(ioaddr + 4);
	dev->stats.rx_fifo_errors	+= inb(ioaddr + 5);
	dev->stats.tx_packets		+= inb(ioaddr + 6);
	/* Rx packets	*/		   inb(ioaddr + 7);
	/* Tx deferrals */		   inb(ioaddr + 8);
	inw(ioaddr + 10);	/* Total Rx and Tx octets. */
	inw(ioaddr + 12);

	/* Back to window 1, and turn statistics back on. */
	EL3WINDOW(1);
	outw(StatsEnable, ioaddr + EL3_CMD);
}

__attribute__((used)) static int
el3_rx(struct net_device *dev)
{
	int ioaddr = dev->base_addr;
	short rx_status;

	if (el3_debug > 5)
		pr_debug("   In rx_packet(), status %4.4x, rx_status %4.4x.\n",
			   inw(ioaddr+EL3_STATUS), inw(ioaddr+RX_STATUS));
	while ((rx_status = inw(ioaddr + RX_STATUS)) > 0) {
		if (rx_status & 0x4000) { /* Error, update stats. */
			short error = rx_status & 0x3800;

			outw(RxDiscard, ioaddr + EL3_CMD);
			dev->stats.rx_errors++;
			switch (error) {
			case 0x0000:		dev->stats.rx_over_errors++; break;
			case 0x0800:		dev->stats.rx_length_errors++; break;
			case 0x1000:		dev->stats.rx_frame_errors++; break;
			case 0x1800:		dev->stats.rx_length_errors++; break;
			case 0x2000:		dev->stats.rx_frame_errors++; break;
			case 0x2800:		dev->stats.rx_crc_errors++; break;
			}
		} else {
			short pkt_len = rx_status & 0x7ff;
			struct sk_buff *skb;

			skb = netdev_alloc_skb(dev, pkt_len + 5);
			if (el3_debug > 4)
				pr_debug("Receiving packet size %d status %4.4x.\n",
					   pkt_len, rx_status);
			if (skb != NULL) {
				skb_reserve(skb, 2);     /* Align IP on 16 byte */

				/* 'skb->data' points to the start of sk_buff data area. */
				insl(ioaddr + RX_FIFO, skb_put(skb,pkt_len),
					 (pkt_len + 3) >> 2);

				outw(RxDiscard, ioaddr + EL3_CMD); /* Pop top Rx packet. */
				skb->protocol = eth_type_trans(skb,dev);
				netif_rx(skb);
				dev->stats.rx_bytes += pkt_len;
				dev->stats.rx_packets++;
				continue;
			}
			outw(RxDiscard, ioaddr + EL3_CMD);
			dev->stats.rx_dropped++;
			if (el3_debug)
				pr_debug("%s: Couldn't allocate a sk_buff of size %d.\n",
					   dev->name, pkt_len);
		}
		inw(ioaddr + EL3_STATUS); 				/* Delay. */
		while (inw(ioaddr + EL3_STATUS) & 0x1000)
			pr_debug("	Waiting for 3c509 to discard packet, status %x.\n",
				   inw(ioaddr + EL3_STATUS) );
	}

	return 0;
}

__attribute__((used)) static void
set_multicast_list(struct net_device *dev)
{
	unsigned long flags;
	struct el3_private *lp = netdev_priv(dev);
	int ioaddr = dev->base_addr;
	int mc_count = netdev_mc_count(dev);

	if (el3_debug > 1) {
		static int old;
		if (old != mc_count) {
			old = mc_count;
			pr_debug("%s: Setting Rx mode to %d addresses.\n",
				 dev->name, mc_count);
		}
	}
	spin_lock_irqsave(&lp->lock, flags);
	if (dev->flags&IFF_PROMISC) {
		outw(SetRxFilter | RxStation | RxMulticast | RxBroadcast | RxProm,
			 ioaddr + EL3_CMD);
	}
	else if (mc_count || (dev->flags&IFF_ALLMULTI)) {
		outw(SetRxFilter | RxStation | RxMulticast | RxBroadcast, ioaddr + EL3_CMD);
	}
	else
		outw(SetRxFilter | RxStation | RxBroadcast, ioaddr + EL3_CMD);
	spin_unlock_irqrestore(&lp->lock, flags);
}

__attribute__((used)) static int
el3_close(struct net_device *dev)
{
	int ioaddr = dev->base_addr;
	struct el3_private *lp = netdev_priv(dev);

	if (el3_debug > 2)
		pr_debug("%s: Shutting down ethercard.\n", dev->name);

	el3_down(dev);

	free_irq(dev->irq, dev);
	/* Switching back to window 0 disables the IRQ. */
	EL3WINDOW(0);
	if (lp->type != EL3_EISA) {
		/* But we explicitly zero the IRQ line select anyway. Don't do
		 * it on EISA cards, it prevents the module from getting an
		 * IRQ after unload+reload... */
		outw(0x0f00, ioaddr + WN0_IRQ);
	}

	return 0;
}

__attribute__((used)) static int
el3_link_ok(struct net_device *dev)
{
	int ioaddr = dev->base_addr;
	u16 tmp;

	EL3WINDOW(4);
	tmp = inw(ioaddr + WN4_MEDIA);
	EL3WINDOW(1);
	return tmp & (1<<11);
}

__attribute__((used)) static void
el3_netdev_get_ecmd(struct net_device *dev, struct ethtool_link_ksettings *cmd)
{
	u16 tmp;
	int ioaddr = dev->base_addr;
	u32 supported;

	EL3WINDOW(0);
	/* obtain current transceiver via WN4_MEDIA? */
	tmp = inw(ioaddr + WN0_ADDR_CONF);
	switch (tmp >> 14) {
	case 0:
		cmd->base.port = PORT_TP;
		break;
	case 1:
		cmd->base.port = PORT_AUI;
		break;
	case 3:
		cmd->base.port = PORT_BNC;
	default:
		break;
	}

	cmd->base.duplex = DUPLEX_HALF;
	supported = 0;
	tmp = inw(ioaddr + WN0_CONF_CTRL);
	if (tmp & (1<<13))
		supported |= SUPPORTED_AUI;
	if (tmp & (1<<12))
		supported |= SUPPORTED_BNC;
	if (tmp & (1<<9)) {
		supported |= SUPPORTED_TP | SUPPORTED_10baseT_Half |
				SUPPORTED_10baseT_Full;	/* hmm... */
		EL3WINDOW(4);
		tmp = inw(ioaddr + WN4_NETDIAG);
		if (tmp & FD_ENABLE)
			cmd->base.duplex = DUPLEX_FULL;
	}

	ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.supported,
						supported);
	cmd->base.speed = SPEED_10;
	EL3WINDOW(1);
}

__attribute__((used)) static int
el3_netdev_set_ecmd(struct net_device *dev,
		    const struct ethtool_link_ksettings *cmd)
{
	u16 tmp;
	int ioaddr = dev->base_addr;

	if (cmd->base.speed != SPEED_10)
		return -EINVAL;
	if ((cmd->base.duplex != DUPLEX_HALF) &&
	    (cmd->base.duplex != DUPLEX_FULL))
		return -EINVAL;

	/* change XCVR type */
	EL3WINDOW(0);
	tmp = inw(ioaddr + WN0_ADDR_CONF);
	switch (cmd->base.port) {
	case PORT_TP:
		tmp &= ~(3<<14);
		dev->if_port = 0;
		break;
	case PORT_AUI:
		tmp |= (1<<14);
		dev->if_port = 1;
		break;
	case PORT_BNC:
		tmp |= (3<<14);
		dev->if_port = 3;
		break;
	default:
		return -EINVAL;
	}

	outw(tmp, ioaddr + WN0_ADDR_CONF);
	if (dev->if_port == 3) {
		/* fire up the DC-DC convertor if BNC gets enabled */
		tmp = inw(ioaddr + WN0_ADDR_CONF);
		if (tmp & (3 << 14)) {
			outw(StartCoax, ioaddr + EL3_CMD);
			udelay(800);
		} else
			return -EIO;
	}

	EL3WINDOW(4);
	tmp = inw(ioaddr + WN4_NETDIAG);
	if (cmd->base.duplex == DUPLEX_FULL)
		tmp |= FD_ENABLE;
	else
		tmp &= ~FD_ENABLE;
	outw(tmp, ioaddr + WN4_NETDIAG);
	EL3WINDOW(1);

	return 0;
}

__attribute__((used)) static void el3_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
	strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
	strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}

__attribute__((used)) static int el3_get_link_ksettings(struct net_device *dev,
				  struct ethtool_link_ksettings *cmd)
{
	struct el3_private *lp = netdev_priv(dev);

	spin_lock_irq(&lp->lock);
	el3_netdev_get_ecmd(dev, cmd);
	spin_unlock_irq(&lp->lock);
	return 0;
}

__attribute__((used)) static int el3_set_link_ksettings(struct net_device *dev,
				  const struct ethtool_link_ksettings *cmd)
{
	struct el3_private *lp = netdev_priv(dev);
	int ret;

	spin_lock_irq(&lp->lock);
	ret = el3_netdev_set_ecmd(dev, cmd);
	spin_unlock_irq(&lp->lock);
	return ret;
}

__attribute__((used)) static u32 el3_get_link(struct net_device *dev)
{
	struct el3_private *lp = netdev_priv(dev);
	u32 ret;

	spin_lock_irq(&lp->lock);
	ret = el3_link_ok(dev);
	spin_unlock_irq(&lp->lock);
	return ret;
}

__attribute__((used)) static u32 el3_get_msglevel(struct net_device *dev)
{
	return el3_debug;
}

__attribute__((used)) static void el3_set_msglevel(struct net_device *dev, u32 v)
{
	el3_debug = v;
}

__attribute__((used)) static void
el3_down(struct net_device *dev)
{
	int ioaddr = dev->base_addr;

	netif_stop_queue(dev);

	/* Turn off statistics ASAP.  We update lp->stats below. */
	outw(StatsDisable, ioaddr + EL3_CMD);

	/* Disable the receiver and transmitter. */
	outw(RxDisable, ioaddr + EL3_CMD);
	outw(TxDisable, ioaddr + EL3_CMD);

	if (dev->if_port == 3)
		/* Turn off thinnet power.  Green! */
		outw(StopCoax, ioaddr + EL3_CMD);
	else if (dev->if_port == 0) {
		/* Disable link beat and jabber, if_port may change here next open(). */
		EL3WINDOW(4);
		outw(inw(ioaddr + WN4_MEDIA) & ~MEDIA_TP, ioaddr + WN4_MEDIA);
	}

	outw(SetIntrEnb | 0x0000, ioaddr + EL3_CMD);

	update_stats(dev);
}

__attribute__((used)) static void
el3_up(struct net_device *dev)
{
	int i, sw_info, net_diag;
	int ioaddr = dev->base_addr;

	/* Activating the board required and does no harm otherwise */
	outw(0x0001, ioaddr + 4);

	/* Set the IRQ line. */
	outw((dev->irq << 12) | 0x0f00, ioaddr + WN0_IRQ);

	/* Set the station address in window 2 each time opened. */
	EL3WINDOW(2);

	for (i = 0; i < 6; i++)
		outb(dev->dev_addr[i], ioaddr + i);

	if ((dev->if_port & 0x03) == 3) /* BNC interface */
		/* Start the thinnet transceiver. We should really wait 50ms...*/
		outw(StartCoax, ioaddr + EL3_CMD);
	else if ((dev->if_port & 0x03) == 0) { /* 10baseT interface */
		/* Combine secondary sw_info word (the adapter level) and primary
			sw_info word (duplex setting plus other useless bits) */
		EL3WINDOW(0);
		sw_info = (read_eeprom(ioaddr, 0x14) & 0x400f) |
			(read_eeprom(ioaddr, 0x0d) & 0xBff0);

		EL3WINDOW(4);
		net_diag = inw(ioaddr + WN4_NETDIAG);
		net_diag = (net_diag | FD_ENABLE); /* temporarily assume full-duplex will be set */
		pr_info("%s: ", dev->name);
		switch (dev->if_port & 0x0c) {
			case 12:
				/* force full-duplex mode if 3c5x9b */
				if (sw_info & 0x000f) {
					pr_cont("Forcing 3c5x9b full-duplex mode");
					break;
				}
			case 8:
				/* set full-duplex mode based on eeprom config setting */
				if ((sw_info & 0x000f) && (sw_info & 0x8000)) {
					pr_cont("Setting 3c5x9b full-duplex mode (from EEPROM configuration bit)");
					break;
				}
			default:
				/* xcvr=(0 || 4) OR user has an old 3c5x9 non "B" model */
				pr_cont("Setting 3c5x9/3c5x9B half-duplex mode");
				net_diag = (net_diag & ~FD_ENABLE); /* disable full duplex */
		}

		outw(net_diag, ioaddr + WN4_NETDIAG);
		pr_cont(" if_port: %d, sw_info: %4.4x\n", dev->if_port, sw_info);
		if (el3_debug > 3)
			pr_debug("%s: 3c5x9 net diag word is now: %4.4x.\n", dev->name, net_diag);
		/* Enable link beat and jabber check. */
		outw(inw(ioaddr + WN4_MEDIA) | MEDIA_TP, ioaddr + WN4_MEDIA);
	}

	/* Switch to the stats window, and clear all stats by reading. */
	outw(StatsDisable, ioaddr + EL3_CMD);
	EL3WINDOW(6);
	for (i = 0; i < 9; i++)
		inb(ioaddr + i);
	inw(ioaddr + 10);
	inw(ioaddr + 12);

	/* Switch to register set 1 for normal use. */
	EL3WINDOW(1);

	/* Accept b-case and phys addr only. */
	outw(SetRxFilter | RxStation | RxBroadcast, ioaddr + EL3_CMD);
	outw(StatsEnable, ioaddr + EL3_CMD); /* Turn on statistics. */

	outw(RxEnable, ioaddr + EL3_CMD); /* Enable the receiver. */
	outw(TxEnable, ioaddr + EL3_CMD); /* Enable transmitter. */
	/* Allow status bits to be seen. */
	outw(SetStatusEnb | 0xff, ioaddr + EL3_CMD);
	/* Ack all pending events, and set active indicator mask. */
	outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
		 ioaddr + EL3_CMD);
	outw(SetIntrEnb | IntLatch|TxAvailable|TxComplete|RxComplete|StatsFull,
		 ioaddr + EL3_CMD);

	netif_start_queue(dev);
}

