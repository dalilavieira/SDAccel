#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct timer_list {int dummy; } ;
struct resource {scalar_t__ start; } ;
struct TYPE_7__ {TYPE_1__* platform_data; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_9__ {TYPE_2__* parent; } ;
struct pcmcia_socket {int features; unsigned long io_offset; unsigned int map_size; scalar_t__ pci_irq; TYPE_4__ dev; int /*<<< orphan*/  owner; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * resource_ops; struct bcm63xx_pcmcia_socket* driver_data; } ;
struct pccard_mem_map {int flags; scalar_t__ card_start; scalar_t__ static_start; } ;
struct pccard_io_map {int dummy; } ;
struct TYPE_8__ {int flags; unsigned int csc_mask; } ;
struct bcm63xx_pcmcia_socket {int base; int card_detected; int card_type; unsigned int old_status; int io_base; struct resource* reg_res; int /*<<< orphan*/  timer; struct resource* common_res; TYPE_1__* pd; struct resource* attr_res; struct pcmcia_socket socket; int /*<<< orphan*/  lock; TYPE_3__ requested_state; } ;
typedef  TYPE_3__ socket_state_t ;
struct TYPE_6__ {int /*<<< orphan*/  ready_gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  BCM63XX_PCMCIA_POLL_RATE ; 
 int CARD_3V ; 
 int CARD_CARDBUS ; 
 int CARD_PCCARD ; 
 int CARD_XV ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int IN_CD1_VS1H ; 
 unsigned int IN_CD1_VS2H ; 
 unsigned int IN_CD2_VS1H ; 
 unsigned int IN_CD2_VS2H ; 
 unsigned int IN_VS1 ; 
 unsigned int IN_VS2 ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int MAP_ATTRIB ; 
 int PCMCIA_C1_CBIDSEL_MASK ; 
 int PCMCIA_C1_CD1_MASK ; 
 int PCMCIA_C1_CD2_MASK ; 
 int PCMCIA_C1_EN_CARDBUS_MASK ; 
 int PCMCIA_C1_EN_PCMCIA_GPIO_MASK ; 
 int PCMCIA_C1_EN_PCMCIA_MASK ; 
 int PCMCIA_C1_REG ; 
 int PCMCIA_C1_RESET_MASK ; 
 int PCMCIA_C1_VS1OE_MASK ; 
 int PCMCIA_C1_VS1_MASK ; 
 int PCMCIA_C1_VS2OE_MASK ; 
 int PCMCIA_C1_VS2_MASK ; 
 int PCMCIA_C2_DATA16_MASK ; 
 int PCMCIA_C2_HOLD_SHIFT ; 
 int PCMCIA_C2_INACTIVE_SHIFT ; 
 int PCMCIA_C2_REG ; 
 int PCMCIA_C2_RWCOUNT_SHIFT ; 
 int PCMCIA_C2_SETUP_SHIFT ; 
 unsigned int SS_3VCARD ; 
 int SS_CAP_PCCARD ; 
 int SS_CAP_STATIC_MAP ; 
 unsigned int SS_CARDBUS ; 
 unsigned int SS_DETECT ; 
 unsigned int SS_POWERON ; 
 unsigned int SS_READY ; 
 int SS_RESET ; 
 unsigned int SS_XVCARD ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  bcm63xx_pcmcia_operations ; 
 int bcm_readl (int) ; 
 int /*<<< orphan*/  bcm_writel (int,int) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 struct bcm63xx_pcmcia_socket* from_timer (struct bcm63xx_pcmcia_socket*,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_get_value (int /*<<< orphan*/ ) ; 
 void* ioremap (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  iounmap (int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  kfree (struct bcm63xx_pcmcia_socket*) ; 
 struct bcm63xx_pcmcia_socket* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pccard_static_ops ; 
 int /*<<< orphan*/  pcmcia_parse_events (struct pcmcia_socket*,unsigned int) ; 
 int pcmcia_register_socket (struct pcmcia_socket*) ; 
 struct bcm63xx_pcmcia_socket* platform_get_drvdata (struct platform_device*) ; 
 void* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bcm63xx_pcmcia_socket*) ; 
 int /*<<< orphan*/  release_mem_region (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  request_mem_region (scalar_t__,unsigned int,char*) ; 
 unsigned int resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int* vscd_to_cardtype ; 

__attribute__((used)) static inline u32 pcmcia_readl(struct bcm63xx_pcmcia_socket *skt, u32 off)
{
	return bcm_readl(skt->base + off);
}

__attribute__((used)) static inline void pcmcia_writel(struct bcm63xx_pcmcia_socket *skt,
				 u32 val, u32 off)
{
	bcm_writel(val, skt->base + off);
}

__attribute__((used)) static int bcm63xx_pcmcia_sock_init(struct pcmcia_socket *sock)
{
	return 0;
}

__attribute__((used)) static int bcm63xx_pcmcia_suspend(struct pcmcia_socket *sock)
{
	return 0;
}

__attribute__((used)) static int bcm63xx_pcmcia_set_socket(struct pcmcia_socket *sock,
				     socket_state_t *state)
{
	struct bcm63xx_pcmcia_socket *skt;
	unsigned long flags;
	u32 val;

	skt = sock->driver_data;

	spin_lock_irqsave(&skt->lock, flags);

	/* note: hardware cannot control socket power, so we will
	 * always report SS_POWERON */

	/* apply socket reset */
	val = pcmcia_readl(skt, PCMCIA_C1_REG);
	if (state->flags & SS_RESET)
		val |= PCMCIA_C1_RESET_MASK;
	else
		val &= ~PCMCIA_C1_RESET_MASK;

	/* reverse reset logic for cardbus card */
	if (skt->card_detected && (skt->card_type & CARD_CARDBUS))
		val ^= PCMCIA_C1_RESET_MASK;

	pcmcia_writel(skt, val, PCMCIA_C1_REG);

	/* keep requested state for event reporting */
	skt->requested_state = *state;

	spin_unlock_irqrestore(&skt->lock, flags);

	return 0;
}

__attribute__((used)) static unsigned int __get_socket_status(struct bcm63xx_pcmcia_socket *skt)
{
	unsigned int stat;
	u32 val;

	stat = 0;

	/* check CD for card presence */
	val = pcmcia_readl(skt, PCMCIA_C1_REG);

	if (!(val & PCMCIA_C1_CD1_MASK) && !(val & PCMCIA_C1_CD2_MASK))
		stat |= SS_DETECT;

	/* if new insertion, detect cardtype */
	if ((stat & SS_DETECT) && !skt->card_detected) {
		unsigned int stat = 0;

		/* float VS1, float VS2 */
		val |= PCMCIA_C1_VS1OE_MASK;
		val |= PCMCIA_C1_VS2OE_MASK;
		pcmcia_writel(skt, val, PCMCIA_C1_REG);

		/* wait for output to stabilize and read VS[12] */
		udelay(10);
		val = pcmcia_readl(skt, PCMCIA_C1_REG);
		stat |= (val & PCMCIA_C1_VS1_MASK) ? IN_VS1 : 0;
		stat |= (val & PCMCIA_C1_VS2_MASK) ? IN_VS2 : 0;

		/* drive VS1 low, float VS2 */
		val &= ~PCMCIA_C1_VS1OE_MASK;
		val |= PCMCIA_C1_VS2OE_MASK;
		pcmcia_writel(skt, val, PCMCIA_C1_REG);

		/* wait for output to stabilize and read CD[12] */
		udelay(10);
		val = pcmcia_readl(skt, PCMCIA_C1_REG);
		stat |= (val & PCMCIA_C1_CD1_MASK) ? IN_CD1_VS2H : 0;
		stat |= (val & PCMCIA_C1_CD2_MASK) ? IN_CD2_VS2H : 0;

		/* float VS1, drive VS2 low */
		val |= PCMCIA_C1_VS1OE_MASK;
		val &= ~PCMCIA_C1_VS2OE_MASK;
		pcmcia_writel(skt, val, PCMCIA_C1_REG);

		/* wait for output to stabilize and read CD[12] */
		udelay(10);
		val = pcmcia_readl(skt, PCMCIA_C1_REG);
		stat |= (val & PCMCIA_C1_CD1_MASK) ? IN_CD1_VS1H : 0;
		stat |= (val & PCMCIA_C1_CD2_MASK) ? IN_CD2_VS1H : 0;

		/* guess cardtype from all this */
		skt->card_type = vscd_to_cardtype[stat];
		if (!skt->card_type)
			dev_err(&skt->socket.dev, "unsupported card type\n");

		/* drive both VS pin to 0 again */
		val &= ~(PCMCIA_C1_VS1OE_MASK | PCMCIA_C1_VS2OE_MASK);

		/* enable correct logic */
		val &= ~(PCMCIA_C1_EN_PCMCIA_MASK | PCMCIA_C1_EN_CARDBUS_MASK);
		if (skt->card_type & CARD_PCCARD)
			val |= PCMCIA_C1_EN_PCMCIA_MASK;
		else
			val |= PCMCIA_C1_EN_CARDBUS_MASK;

		pcmcia_writel(skt, val, PCMCIA_C1_REG);
	}
	skt->card_detected = (stat & SS_DETECT) ? 1 : 0;

	/* report card type/voltage */
	if (skt->card_type & CARD_CARDBUS)
		stat |= SS_CARDBUS;
	if (skt->card_type & CARD_3V)
		stat |= SS_3VCARD;
	if (skt->card_type & CARD_XV)
		stat |= SS_XVCARD;
	stat |= SS_POWERON;

	if (gpio_get_value(skt->pd->ready_gpio))
		stat |= SS_READY;

	return stat;
}

__attribute__((used)) static int bcm63xx_pcmcia_get_status(struct pcmcia_socket *sock,
				     unsigned int *status)
{
	struct bcm63xx_pcmcia_socket *skt;

	skt = sock->driver_data;

	spin_lock_bh(&skt->lock);
	*status = __get_socket_status(skt);
	spin_unlock_bh(&skt->lock);

	return 0;
}

__attribute__((used)) static void bcm63xx_pcmcia_poll(struct timer_list *t)
{
	struct bcm63xx_pcmcia_socket *skt;
	unsigned int stat, events;

	skt = from_timer(skt, t, timer);

	spin_lock_bh(&skt->lock);

	stat = __get_socket_status(skt);

	/* keep only changed bits, and mask with required one from the
	 * core */
	events = (stat ^ skt->old_status) & skt->requested_state.csc_mask;
	skt->old_status = stat;
	spin_unlock_bh(&skt->lock);

	if (events)
		pcmcia_parse_events(&skt->socket, events);

	mod_timer(&skt->timer,
		  jiffies + msecs_to_jiffies(BCM63XX_PCMCIA_POLL_RATE));
}

__attribute__((used)) static int bcm63xx_pcmcia_set_io_map(struct pcmcia_socket *sock,
				     struct pccard_io_map *map)
{
	/* this doesn't seem to be called by pcmcia layer if static
	 * mapping is used */
	return 0;
}

__attribute__((used)) static int bcm63xx_pcmcia_set_mem_map(struct pcmcia_socket *sock,
				      struct pccard_mem_map *map)
{
	struct bcm63xx_pcmcia_socket *skt;
	struct resource *res;

	skt = sock->driver_data;
	if (map->flags & MAP_ATTRIB)
		res = skt->attr_res;
	else
		res = skt->common_res;

	map->static_start = res->start + map->card_start;
	return 0;
}

__attribute__((used)) static int bcm63xx_drv_pcmcia_probe(struct platform_device *pdev)
{
	struct bcm63xx_pcmcia_socket *skt;
	struct pcmcia_socket *sock;
	struct resource *res, *irq_res;
	unsigned int regmem_size = 0, iomem_size = 0;
	u32 val;
	int ret;

	skt = kzalloc(sizeof(*skt), GFP_KERNEL);
	if (!skt)
		return -ENOMEM;
	spin_lock_init(&skt->lock);
	sock = &skt->socket;
	sock->driver_data = skt;

	/* make sure we have all resources we need */
	skt->common_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	skt->attr_res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	skt->pd = pdev->dev.platform_data;
	if (!skt->common_res || !skt->attr_res || !irq_res || !skt->pd) {
		ret = -EINVAL;
		goto err;
	}

	/* remap pcmcia registers */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	regmem_size = resource_size(res);
	if (!request_mem_region(res->start, regmem_size, "bcm63xx_pcmcia")) {
		ret = -EINVAL;
		goto err;
	}
	skt->reg_res = res;

	skt->base = ioremap(res->start, regmem_size);
	if (!skt->base) {
		ret = -ENOMEM;
		goto err;
	}

	/* remap io registers */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
	iomem_size = resource_size(res);
	skt->io_base = ioremap(res->start, iomem_size);
	if (!skt->io_base) {
		ret = -ENOMEM;
		goto err;
	}

	/* resources are static */
	sock->resource_ops = &pccard_static_ops;
	sock->ops = &bcm63xx_pcmcia_operations;
	sock->owner = THIS_MODULE;
	sock->dev.parent = &pdev->dev;
	sock->features = SS_CAP_STATIC_MAP | SS_CAP_PCCARD;
	sock->io_offset = (unsigned long)skt->io_base;
	sock->pci_irq = irq_res->start;

#ifdef CONFIG_CARDBUS
	sock->cb_dev = bcm63xx_cb_dev;
	if (bcm63xx_cb_dev)
		sock->features |= SS_CAP_CARDBUS;
#endif

	/* assume common & attribute memory have the same size */
	sock->map_size = resource_size(skt->common_res);

	/* initialize polling timer */
	timer_setup(&skt->timer, bcm63xx_pcmcia_poll, 0);

	/* initialize  pcmcia  control register,  drive  VS[12] to  0,
	 * leave CB IDSEL to the old  value since it is set by the PCI
	 * layer */
	val = pcmcia_readl(skt, PCMCIA_C1_REG);
	val &= PCMCIA_C1_CBIDSEL_MASK;
	val |= PCMCIA_C1_EN_PCMCIA_GPIO_MASK;
	pcmcia_writel(skt, val, PCMCIA_C1_REG);

	/*
	 * Hardware has only one set of timings registers, not one for
	 * each memory access type, so we configure them for the
	 * slowest one: attribute memory.
	 */
	val = PCMCIA_C2_DATA16_MASK;
	val |= 10 << PCMCIA_C2_RWCOUNT_SHIFT;
	val |= 6 << PCMCIA_C2_INACTIVE_SHIFT;
	val |= 3 << PCMCIA_C2_SETUP_SHIFT;
	val |= 3 << PCMCIA_C2_HOLD_SHIFT;
	pcmcia_writel(skt, val, PCMCIA_C2_REG);

	ret = pcmcia_register_socket(sock);
	if (ret)
		goto err;

	/* start polling socket */
	mod_timer(&skt->timer,
		  jiffies + msecs_to_jiffies(BCM63XX_PCMCIA_POLL_RATE));

	platform_set_drvdata(pdev, skt);
	return 0;

err:
	if (skt->io_base)
		iounmap(skt->io_base);
	if (skt->base)
		iounmap(skt->base);
	if (skt->reg_res)
		release_mem_region(skt->reg_res->start, regmem_size);
	kfree(skt);
	return ret;
}

__attribute__((used)) static int bcm63xx_drv_pcmcia_remove(struct platform_device *pdev)
{
	struct bcm63xx_pcmcia_socket *skt;
	struct resource *res;

	skt = platform_get_drvdata(pdev);
	del_timer_sync(&skt->timer);
	iounmap(skt->base);
	iounmap(skt->io_base);
	res = skt->reg_res;
	release_mem_region(res->start, resource_size(res));
	kfree(skt);
	return 0;
}

