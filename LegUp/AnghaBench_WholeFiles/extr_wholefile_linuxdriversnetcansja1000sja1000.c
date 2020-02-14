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
typedef  int uint8_t ;
typedef  int u8 ;
struct sk_buff {scalar_t__ data; } ;
struct TYPE_3__ {int /*<<< orphan*/  arbitration_lost; int /*<<< orphan*/  bus_error; } ;
struct can_bittiming {int brp; int sjw; int prop_seg; int phase_seg1; int phase_seg2; } ;
struct TYPE_4__ {scalar_t__ state; int ctrlmode; int (* do_set_bittiming ) (struct net_device const*) ;int (* do_set_mode ) (struct net_device const*,int) ;int (* do_get_berr_counter ) (struct net_device const*,struct can_berr_counter*) ;int ctrlmode_supported; int /*<<< orphan*/ * bittiming_const; TYPE_1__ can_stats; struct can_bittiming bittiming; } ;
struct sja1000_priv {int (* read_reg ) (struct sja1000_priv*,int /*<<< orphan*/ ) ;int cdr; int ocr; int flags; void* priv; int /*<<< orphan*/  cmdreg_lock; TYPE_2__ can; struct net_device const* dev; int /*<<< orphan*/  irq_flags; int /*<<< orphan*/  (* post_irq ) (struct sja1000_priv*) ;int /*<<< orphan*/  (* pre_irq ) (struct sja1000_priv*) ;int /*<<< orphan*/  (* write_reg ) (struct sja1000_priv*,int /*<<< orphan*/ ,unsigned int) ;scalar_t__ reg_base; } ;
struct net_device_stats {int rx_bytes; int tx_bytes; int /*<<< orphan*/  tx_packets; int /*<<< orphan*/  tx_errors; int /*<<< orphan*/  rx_packets; int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  rx_over_errors; } ;
typedef  struct net_device {int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  flags; int /*<<< orphan*/  irq; int /*<<< orphan*/  name; struct net_device_stats stats; } const net_device ;
struct can_frame {int can_dlc; int can_id; unsigned int* data; } ;
struct can_berr_counter {int txerr; int rxerr; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum can_state { ____Placeholder_can_state } can_state ;
typedef  enum can_mode { ____Placeholder_can_mode } can_mode ;
typedef  int canid_t ;

/* Variables and functions */
 int CAN_CTRLMODE_3_SAMPLES ; 
 int CAN_CTRLMODE_BERR_REPORTING ; 
 int CAN_CTRLMODE_LISTENONLY ; 
 int CAN_CTRLMODE_LOOPBACK ; 
 int CAN_CTRLMODE_ONE_SHOT ; 
 int CAN_CTRLMODE_PRESUME_ACK ; 
 int CAN_EFF_FLAG ; 
 int CAN_ERR_BUSERROR ; 
 int CAN_ERR_CRTL ; 
 unsigned int CAN_ERR_CRTL_RX_OVERFLOW ; 
 int CAN_ERR_LOSTARB ; 
 int CAN_ERR_PROT ; 
 unsigned int CAN_ERR_PROT_BIT ; 
 unsigned int CAN_ERR_PROT_FORM ; 
 unsigned int CAN_ERR_PROT_STUFF ; 
 int CAN_ERR_PROT_TX ; 
 int /*<<< orphan*/  CAN_LED_EVENT_OPEN ; 
 int /*<<< orphan*/  CAN_LED_EVENT_RX ; 
 int /*<<< orphan*/  CAN_LED_EVENT_STOP ; 
 int /*<<< orphan*/  CAN_LED_EVENT_TX ; 
#define  CAN_MODE_START 131 
 int CAN_RTR_FLAG ; 
 int CAN_STATE_BUS_OFF ; 
 void* CAN_STATE_ERROR_ACTIVE ; 
 int CAN_STATE_ERROR_PASSIVE ; 
 int CAN_STATE_ERROR_WARNING ; 
 scalar_t__ CAN_STATE_STOPPED ; 
 int CDR_PELICAN ; 
 int CMD_AT ; 
 int CMD_CDO ; 
 int CMD_RRB ; 
 int CMD_SRR ; 
 int CMD_TR ; 
 int EAGAIN ; 
#define  ECC_BIT 130 
 int ECC_DIR ; 
#define  ECC_FORM 129 
 int ECC_MASK ; 
 int ECC_SEG ; 
#define  ECC_STUFF 128 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  IFF_ECHO ; 
 int IRQ_ALI ; 
 int IRQ_ALL ; 
 int IRQ_BEI ; 
 int IRQ_DOI ; 
 int IRQ_EI ; 
 int IRQ_EPI ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int IRQ_OFF ; 
 int IRQ_RI ; 
 int IRQ_TI ; 
 int IRQ_WUI ; 
 int MOD_LOM ; 
 unsigned char MOD_RM ; 
 int MOD_STM ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
 int OCR_MODE_NORMAL ; 
 int /*<<< orphan*/  SJA1000_ACCC0 ; 
 int /*<<< orphan*/  SJA1000_ACCC1 ; 
 int /*<<< orphan*/  SJA1000_ACCC2 ; 
 int /*<<< orphan*/  SJA1000_ACCC3 ; 
 int /*<<< orphan*/  SJA1000_ACCM0 ; 
 int /*<<< orphan*/  SJA1000_ACCM1 ; 
 int /*<<< orphan*/  SJA1000_ACCM2 ; 
 int /*<<< orphan*/  SJA1000_ACCM3 ; 
 int /*<<< orphan*/  SJA1000_ALC ; 
 int /*<<< orphan*/  SJA1000_BTR0 ; 
 int /*<<< orphan*/  SJA1000_BTR1 ; 
 int /*<<< orphan*/  SJA1000_CDR ; 
 int /*<<< orphan*/  SJA1000_CMR ; 
 int SJA1000_CUSTOM_IRQ_HANDLER ; 
 int /*<<< orphan*/  SJA1000_ECC ; 
 int /*<<< orphan*/  SJA1000_ECHO_SKB_MAX ; 
 int SJA1000_EFF_BUF ; 
 int /*<<< orphan*/  SJA1000_FI ; 
 int SJA1000_FI_FF ; 
 int SJA1000_FI_RTR ; 
 int /*<<< orphan*/  SJA1000_ID1 ; 
 int /*<<< orphan*/  SJA1000_ID2 ; 
 int /*<<< orphan*/  SJA1000_ID3 ; 
 int /*<<< orphan*/  SJA1000_ID4 ; 
 int /*<<< orphan*/  SJA1000_IER ; 
 int /*<<< orphan*/  SJA1000_IR ; 
 int SJA1000_MAX_IRQ ; 
 int /*<<< orphan*/  SJA1000_MOD ; 
 int /*<<< orphan*/  SJA1000_OCR ; 
 int /*<<< orphan*/  SJA1000_RXERR ; 
 int SJA1000_SFF_BUF ; 
 int /*<<< orphan*/  SJA1000_SR ; 
 int /*<<< orphan*/  SJA1000_TXERR ; 
 int SR_BS ; 
 int SR_ES ; 
 int SR_RBS ; 
 int SR_TCS ; 
 struct sk_buff* alloc_can_err_skb (struct net_device const*,struct can_frame**) ; 
 struct sk_buff* alloc_can_skb (struct net_device const*,struct can_frame**) ; 
 struct net_device const* alloc_candev (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  can_bus_off (struct net_device const*) ; 
 int /*<<< orphan*/  can_change_state (struct net_device const*,struct can_frame*,int,int) ; 
 scalar_t__ can_dropped_invalid_skb (struct net_device const*,struct sk_buff*) ; 
 int /*<<< orphan*/  can_free_echo_skb (struct net_device const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  can_get_echo_skb (struct net_device const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  can_led_event (struct net_device const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  can_put_echo_skb (struct sk_buff*,struct net_device const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close_candev (struct net_device const*) ; 
 int /*<<< orphan*/  devm_can_led_init (struct net_device const*) ; 
 int /*<<< orphan*/  free_candev (struct net_device const*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,void*) ; 
 int get_can_dlc (int) ; 
 int /*<<< orphan*/  netdev_dbg (struct net_device const*,char*,...) ; 
 int /*<<< orphan*/  netdev_err (struct net_device const*,char*) ; 
 int /*<<< orphan*/  netdev_info (struct net_device const*,char*,int,int) ; 
 struct sja1000_priv* netdev_priv (struct net_device const*) ; 
 int /*<<< orphan*/  netdev_warn (struct net_device const*,char*) ; 
 int /*<<< orphan*/  netif_queue_stopped (struct net_device const*) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device const*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device const*) ; 
 int /*<<< orphan*/  netif_wake_queue (struct net_device const*) ; 
 int open_candev (struct net_device const*) ; 
 int register_candev (struct net_device const*) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  sja1000_bittiming_const ; 
 int /*<<< orphan*/  sja1000_netdev_ops ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub10 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub11 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 unsigned char stub12 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub14 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub15 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub16 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub17 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub18 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub19 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int stub2 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub20 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub21 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub22 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int stub23 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub24 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub25 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int stub26 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub27 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub28 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub29 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int stub3 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub30 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub31 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub32 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub33 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub34 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub35 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub36 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub37 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub38 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub39 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 unsigned char stub4 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub40 (struct sja1000_priv*,int /*<<< orphan*/ ,unsigned int) ; 
 int stub41 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub42 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub43 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub44 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub45 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub46 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub47 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 unsigned int stub48 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 unsigned int stub49 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 unsigned int stub50 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub51 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub52 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub53 (struct sja1000_priv*) ; 
 int stub54 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub55 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub56 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub57 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int stub58 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub59 (struct sja1000_priv*) ; 
 int /*<<< orphan*/  stub6 (struct sja1000_priv*,int /*<<< orphan*/ ,unsigned char) ; 
 unsigned char stub7 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 unsigned char stub8 (struct sja1000_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (struct sja1000_priv*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  unregister_candev (struct net_device const*) ; 

__attribute__((used)) static void sja1000_write_cmdreg(struct sja1000_priv *priv, u8 val)
{
	unsigned long flags;

	/*
	 * The command register needs some locking and time to settle
	 * the write_reg() operation - especially on SMP systems.
	 */
	spin_lock_irqsave(&priv->cmdreg_lock, flags);
	priv->write_reg(priv, SJA1000_CMR, val);
	priv->read_reg(priv, SJA1000_SR);
	spin_unlock_irqrestore(&priv->cmdreg_lock, flags);
}

__attribute__((used)) static int sja1000_is_absent(struct sja1000_priv *priv)
{
	return (priv->read_reg(priv, SJA1000_MOD) == 0xFF);
}

__attribute__((used)) static int sja1000_probe_chip(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);

	if (priv->reg_base && sja1000_is_absent(priv)) {
		netdev_err(dev, "probing failed\n");
		return 0;
	}
	return -1;
}

__attribute__((used)) static void set_reset_mode(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	unsigned char status = priv->read_reg(priv, SJA1000_MOD);
	int i;

	/* disable interrupts */
	priv->write_reg(priv, SJA1000_IER, IRQ_OFF);

	for (i = 0; i < 100; i++) {
		/* check reset bit */
		if (status & MOD_RM) {
			priv->can.state = CAN_STATE_STOPPED;
			return;
		}

		/* reset chip */
		priv->write_reg(priv, SJA1000_MOD, MOD_RM);
		udelay(10);
		status = priv->read_reg(priv, SJA1000_MOD);
	}

	netdev_err(dev, "setting SJA1000 into reset mode failed!\n");
}

__attribute__((used)) static void set_normal_mode(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	unsigned char status = priv->read_reg(priv, SJA1000_MOD);
	u8 mod_reg_val = 0x00;
	int i;

	for (i = 0; i < 100; i++) {
		/* check reset bit */
		if ((status & MOD_RM) == 0) {
			priv->can.state = CAN_STATE_ERROR_ACTIVE;
			/* enable interrupts */
			if (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
				priv->write_reg(priv, SJA1000_IER, IRQ_ALL);
			else
				priv->write_reg(priv, SJA1000_IER,
						IRQ_ALL & ~IRQ_BEI);
			return;
		}

		/* set chip to normal mode */
		if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
			mod_reg_val |= MOD_LOM;
		if (priv->can.ctrlmode & CAN_CTRLMODE_PRESUME_ACK)
			mod_reg_val |= MOD_STM;
		priv->write_reg(priv, SJA1000_MOD, mod_reg_val);

		udelay(10);

		status = priv->read_reg(priv, SJA1000_MOD);
	}

	netdev_err(dev, "setting SJA1000 into normal mode failed!\n");
}

__attribute__((used)) static void chipset_init(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);

	/* set clock divider and output control register */
	priv->write_reg(priv, SJA1000_CDR, priv->cdr | CDR_PELICAN);

	/* set acceptance filter (accept all) */
	priv->write_reg(priv, SJA1000_ACCC0, 0x00);
	priv->write_reg(priv, SJA1000_ACCC1, 0x00);
	priv->write_reg(priv, SJA1000_ACCC2, 0x00);
	priv->write_reg(priv, SJA1000_ACCC3, 0x00);

	priv->write_reg(priv, SJA1000_ACCM0, 0xFF);
	priv->write_reg(priv, SJA1000_ACCM1, 0xFF);
	priv->write_reg(priv, SJA1000_ACCM2, 0xFF);
	priv->write_reg(priv, SJA1000_ACCM3, 0xFF);

	priv->write_reg(priv, SJA1000_OCR, priv->ocr | OCR_MODE_NORMAL);
}

__attribute__((used)) static void sja1000_start(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);

	/* leave reset mode */
	if (priv->can.state != CAN_STATE_STOPPED)
		set_reset_mode(dev);

	/* Initialize chip if uninitialized at this stage */
	if (!(priv->read_reg(priv, SJA1000_CDR) & CDR_PELICAN))
		chipset_init(dev);

	/* Clear error counters and error code capture */
	priv->write_reg(priv, SJA1000_TXERR, 0x0);
	priv->write_reg(priv, SJA1000_RXERR, 0x0);
	priv->read_reg(priv, SJA1000_ECC);

	/* clear interrupt flags */
	priv->read_reg(priv, SJA1000_IR);

	/* leave reset mode */
	set_normal_mode(dev);
}

__attribute__((used)) static int sja1000_set_mode(struct net_device *dev, enum can_mode mode)
{
	switch (mode) {
	case CAN_MODE_START:
		sja1000_start(dev);
		if (netif_queue_stopped(dev))
			netif_wake_queue(dev);
		break;

	default:
		return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static int sja1000_set_bittiming(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	struct can_bittiming *bt = &priv->can.bittiming;
	u8 btr0, btr1;

	btr0 = ((bt->brp - 1) & 0x3f) | (((bt->sjw - 1) & 0x3) << 6);
	btr1 = ((bt->prop_seg + bt->phase_seg1 - 1) & 0xf) |
		(((bt->phase_seg2 - 1) & 0x7) << 4);
	if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
		btr1 |= 0x80;

	netdev_info(dev, "setting BTR0=0x%02x BTR1=0x%02x\n", btr0, btr1);

	priv->write_reg(priv, SJA1000_BTR0, btr0);
	priv->write_reg(priv, SJA1000_BTR1, btr1);

	return 0;
}

__attribute__((used)) static int sja1000_get_berr_counter(const struct net_device *dev,
				    struct can_berr_counter *bec)
{
	struct sja1000_priv *priv = netdev_priv(dev);

	bec->txerr = priv->read_reg(priv, SJA1000_TXERR);
	bec->rxerr = priv->read_reg(priv, SJA1000_RXERR);

	return 0;
}

__attribute__((used)) static netdev_tx_t sja1000_start_xmit(struct sk_buff *skb,
					    struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	struct can_frame *cf = (struct can_frame *)skb->data;
	uint8_t fi;
	uint8_t dlc;
	canid_t id;
	uint8_t dreg;
	u8 cmd_reg_val = 0x00;
	int i;

	if (can_dropped_invalid_skb(dev, skb))
		return NETDEV_TX_OK;

	netif_stop_queue(dev);

	fi = dlc = cf->can_dlc;
	id = cf->can_id;

	if (id & CAN_RTR_FLAG)
		fi |= SJA1000_FI_RTR;

	if (id & CAN_EFF_FLAG) {
		fi |= SJA1000_FI_FF;
		dreg = SJA1000_EFF_BUF;
		priv->write_reg(priv, SJA1000_FI, fi);
		priv->write_reg(priv, SJA1000_ID1, (id & 0x1fe00000) >> 21);
		priv->write_reg(priv, SJA1000_ID2, (id & 0x001fe000) >> 13);
		priv->write_reg(priv, SJA1000_ID3, (id & 0x00001fe0) >> 5);
		priv->write_reg(priv, SJA1000_ID4, (id & 0x0000001f) << 3);
	} else {
		dreg = SJA1000_SFF_BUF;
		priv->write_reg(priv, SJA1000_FI, fi);
		priv->write_reg(priv, SJA1000_ID1, (id & 0x000007f8) >> 3);
		priv->write_reg(priv, SJA1000_ID2, (id & 0x00000007) << 5);
	}

	for (i = 0; i < dlc; i++)
		priv->write_reg(priv, dreg++, cf->data[i]);

	can_put_echo_skb(skb, dev, 0);

	if (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT)
		cmd_reg_val |= CMD_AT;

	if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
		cmd_reg_val |= CMD_SRR;
	else
		cmd_reg_val |= CMD_TR;

	sja1000_write_cmdreg(priv, cmd_reg_val);

	return NETDEV_TX_OK;
}

__attribute__((used)) static void sja1000_rx(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	struct net_device_stats *stats = &dev->stats;
	struct can_frame *cf;
	struct sk_buff *skb;
	uint8_t fi;
	uint8_t dreg;
	canid_t id;
	int i;

	/* create zero'ed CAN frame buffer */
	skb = alloc_can_skb(dev, &cf);
	if (skb == NULL)
		return;

	fi = priv->read_reg(priv, SJA1000_FI);

	if (fi & SJA1000_FI_FF) {
		/* extended frame format (EFF) */
		dreg = SJA1000_EFF_BUF;
		id = (priv->read_reg(priv, SJA1000_ID1) << 21)
		    | (priv->read_reg(priv, SJA1000_ID2) << 13)
		    | (priv->read_reg(priv, SJA1000_ID3) << 5)
		    | (priv->read_reg(priv, SJA1000_ID4) >> 3);
		id |= CAN_EFF_FLAG;
	} else {
		/* standard frame format (SFF) */
		dreg = SJA1000_SFF_BUF;
		id = (priv->read_reg(priv, SJA1000_ID1) << 3)
		    | (priv->read_reg(priv, SJA1000_ID2) >> 5);
	}

	cf->can_dlc = get_can_dlc(fi & 0x0F);
	if (fi & SJA1000_FI_RTR) {
		id |= CAN_RTR_FLAG;
	} else {
		for (i = 0; i < cf->can_dlc; i++)
			cf->data[i] = priv->read_reg(priv, dreg++);
	}

	cf->can_id = id;

	/* release receive buffer */
	sja1000_write_cmdreg(priv, CMD_RRB);

	stats->rx_packets++;
	stats->rx_bytes += cf->can_dlc;
	netif_rx(skb);

	can_led_event(dev, CAN_LED_EVENT_RX);
}

__attribute__((used)) static int sja1000_err(struct net_device *dev, uint8_t isrc, uint8_t status)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	struct net_device_stats *stats = &dev->stats;
	struct can_frame *cf;
	struct sk_buff *skb;
	enum can_state state = priv->can.state;
	enum can_state rx_state, tx_state;
	unsigned int rxerr, txerr;
	uint8_t ecc, alc;

	skb = alloc_can_err_skb(dev, &cf);
	if (skb == NULL)
		return -ENOMEM;

	txerr = priv->read_reg(priv, SJA1000_TXERR);
	rxerr = priv->read_reg(priv, SJA1000_RXERR);

	cf->data[6] = txerr;
	cf->data[7] = rxerr;

	if (isrc & IRQ_DOI) {
		/* data overrun interrupt */
		netdev_dbg(dev, "data overrun interrupt\n");
		cf->can_id |= CAN_ERR_CRTL;
		cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
		stats->rx_over_errors++;
		stats->rx_errors++;
		sja1000_write_cmdreg(priv, CMD_CDO);	/* clear bit */
	}

	if (isrc & IRQ_EI) {
		/* error warning interrupt */
		netdev_dbg(dev, "error warning interrupt\n");

		if (status & SR_BS)
			state = CAN_STATE_BUS_OFF;
		else if (status & SR_ES)
			state = CAN_STATE_ERROR_WARNING;
		else
			state = CAN_STATE_ERROR_ACTIVE;
	}
	if (isrc & IRQ_BEI) {
		/* bus error interrupt */
		priv->can.can_stats.bus_error++;
		stats->rx_errors++;

		ecc = priv->read_reg(priv, SJA1000_ECC);

		cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;

		/* set error type */
		switch (ecc & ECC_MASK) {
		case ECC_BIT:
			cf->data[2] |= CAN_ERR_PROT_BIT;
			break;
		case ECC_FORM:
			cf->data[2] |= CAN_ERR_PROT_FORM;
			break;
		case ECC_STUFF:
			cf->data[2] |= CAN_ERR_PROT_STUFF;
			break;
		default:
			break;
		}

		/* set error location */
		cf->data[3] = ecc & ECC_SEG;

		/* Error occurred during transmission? */
		if ((ecc & ECC_DIR) == 0)
			cf->data[2] |= CAN_ERR_PROT_TX;
	}
	if (isrc & IRQ_EPI) {
		/* error passive interrupt */
		netdev_dbg(dev, "error passive interrupt\n");

		if (state == CAN_STATE_ERROR_PASSIVE)
			state = CAN_STATE_ERROR_WARNING;
		else
			state = CAN_STATE_ERROR_PASSIVE;
	}
	if (isrc & IRQ_ALI) {
		/* arbitration lost interrupt */
		netdev_dbg(dev, "arbitration lost interrupt\n");
		alc = priv->read_reg(priv, SJA1000_ALC);
		priv->can.can_stats.arbitration_lost++;
		stats->tx_errors++;
		cf->can_id |= CAN_ERR_LOSTARB;
		cf->data[0] = alc & 0x1f;
	}

	if (state != priv->can.state) {
		tx_state = txerr >= rxerr ? state : 0;
		rx_state = txerr <= rxerr ? state : 0;

		can_change_state(dev, cf, tx_state, rx_state);

		if(state == CAN_STATE_BUS_OFF)
			can_bus_off(dev);
	}

	stats->rx_packets++;
	stats->rx_bytes += cf->can_dlc;
	netif_rx(skb);

	return 0;
}

irqreturn_t sja1000_interrupt(int irq, void *dev_id)
{
	struct net_device *dev = (struct net_device *)dev_id;
	struct sja1000_priv *priv = netdev_priv(dev);
	struct net_device_stats *stats = &dev->stats;
	uint8_t isrc, status;
	int n = 0;

	if (priv->pre_irq)
		priv->pre_irq(priv);

	/* Shared interrupts and IRQ off? */
	if (priv->read_reg(priv, SJA1000_IER) == IRQ_OFF)
		goto out;

	while ((isrc = priv->read_reg(priv, SJA1000_IR)) &&
	       (n < SJA1000_MAX_IRQ)) {

		status = priv->read_reg(priv, SJA1000_SR);
		/* check for absent controller due to hw unplug */
		if (status == 0xFF && sja1000_is_absent(priv))
			goto out;

		if (isrc & IRQ_WUI)
			netdev_warn(dev, "wakeup interrupt\n");

		if (isrc & IRQ_TI) {
			/* transmission buffer released */
			if (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT &&
			    !(status & SR_TCS)) {
				stats->tx_errors++;
				can_free_echo_skb(dev, 0);
			} else {
				/* transmission complete */
				stats->tx_bytes +=
					priv->read_reg(priv, SJA1000_FI) & 0xf;
				stats->tx_packets++;
				can_get_echo_skb(dev, 0);
			}
			netif_wake_queue(dev);
			can_led_event(dev, CAN_LED_EVENT_TX);
		}
		if (isrc & IRQ_RI) {
			/* receive interrupt */
			while (status & SR_RBS) {
				sja1000_rx(dev);
				status = priv->read_reg(priv, SJA1000_SR);
				/* check for absent controller */
				if (status == 0xFF && sja1000_is_absent(priv))
					goto out;
			}
		}
		if (isrc & (IRQ_DOI | IRQ_EI | IRQ_BEI | IRQ_EPI | IRQ_ALI)) {
			/* error interrupt */
			if (sja1000_err(dev, isrc, status))
				break;
		}
		n++;
	}
out:
	if (priv->post_irq)
		priv->post_irq(priv);

	if (n >= SJA1000_MAX_IRQ)
		netdev_dbg(dev, "%d messages handled in ISR", n);

	return (n) ? IRQ_HANDLED : IRQ_NONE;
}

__attribute__((used)) static int sja1000_open(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);
	int err;

	/* set chip into reset mode */
	set_reset_mode(dev);

	/* common open */
	err = open_candev(dev);
	if (err)
		return err;

	/* register interrupt handler, if not done by the device driver */
	if (!(priv->flags & SJA1000_CUSTOM_IRQ_HANDLER)) {
		err = request_irq(dev->irq, sja1000_interrupt, priv->irq_flags,
				  dev->name, (void *)dev);
		if (err) {
			close_candev(dev);
			return -EAGAIN;
		}
	}

	/* init and start chi */
	sja1000_start(dev);

	can_led_event(dev, CAN_LED_EVENT_OPEN);

	netif_start_queue(dev);

	return 0;
}

__attribute__((used)) static int sja1000_close(struct net_device *dev)
{
	struct sja1000_priv *priv = netdev_priv(dev);

	netif_stop_queue(dev);
	set_reset_mode(dev);

	if (!(priv->flags & SJA1000_CUSTOM_IRQ_HANDLER))
		free_irq(dev->irq, (void *)dev);

	close_candev(dev);

	can_led_event(dev, CAN_LED_EVENT_STOP);

	return 0;
}

struct net_device *alloc_sja1000dev(int sizeof_priv)
{
	struct net_device *dev;
	struct sja1000_priv *priv;

	dev = alloc_candev(sizeof(struct sja1000_priv) + sizeof_priv,
		SJA1000_ECHO_SKB_MAX);
	if (!dev)
		return NULL;

	priv = netdev_priv(dev);

	priv->dev = dev;
	priv->can.bittiming_const = &sja1000_bittiming_const;
	priv->can.do_set_bittiming = sja1000_set_bittiming;
	priv->can.do_set_mode = sja1000_set_mode;
	priv->can.do_get_berr_counter = sja1000_get_berr_counter;
	priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
				       CAN_CTRLMODE_LISTENONLY |
				       CAN_CTRLMODE_3_SAMPLES |
				       CAN_CTRLMODE_ONE_SHOT |
				       CAN_CTRLMODE_BERR_REPORTING |
				       CAN_CTRLMODE_PRESUME_ACK;

	spin_lock_init(&priv->cmdreg_lock);

	if (sizeof_priv)
		priv->priv = (void *)priv + sizeof(struct sja1000_priv);

	return dev;
}

void free_sja1000dev(struct net_device *dev)
{
	free_candev(dev);
}

int register_sja1000dev(struct net_device *dev)
{
	int ret;

	if (!sja1000_probe_chip(dev))
		return -ENODEV;

	dev->flags |= IFF_ECHO;	/* we support local echo */
	dev->netdev_ops = &sja1000_netdev_ops;

	set_reset_mode(dev);
	chipset_init(dev);

	ret =  register_candev(dev);

	if (!ret)
		devm_can_led_init(dev);

	return ret;
}

void unregister_sja1000dev(struct net_device *dev)
{
	set_reset_mode(dev);
	unregister_candev(dev);
}

