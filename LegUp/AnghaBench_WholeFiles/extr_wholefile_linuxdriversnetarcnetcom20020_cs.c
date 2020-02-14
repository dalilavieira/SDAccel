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
struct pcmcia_device {int io_lines; scalar_t__ open; struct com20020_dev* priv; int /*<<< orphan*/  dev; scalar_t__ irq; TYPE_2__** resource; int /*<<< orphan*/  config_flags; } ;
struct net_device {int base_addr; scalar_t__ irq; int /*<<< orphan*/ * dev_addr; } ;
struct com20020_dev {struct net_device* dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  owner; } ;
struct arcnet_local {int config; int clockm; char* card_name; int /*<<< orphan*/  card_flags; TYPE_1__ hw; int /*<<< orphan*/  clockp; int /*<<< orphan*/  backplane; int /*<<< orphan*/  timeout; } ;
struct TYPE_4__ {int end; int start; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARC_CAN_10MBIT ; 
 int /*<<< orphan*/  COM20020_REG_W_CONFIG ; 
 int /*<<< orphan*/  COM20020_REG_W_SUBADR ; 
 int /*<<< orphan*/  CONF_ENABLE_IRQ ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IO_DATA_PATH_WIDTH_8 ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct net_device* alloc_arcdev (char*) ; 
 int /*<<< orphan*/  arcnet_outb (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  backplane ; 
 int clockm ; 
 int /*<<< orphan*/  clockp ; 
 scalar_t__ com20020_check (struct net_device*) ; 
static  int com20020_config (struct pcmcia_device*) ; 
 int com20020_found (struct net_device*,int /*<<< orphan*/ ) ; 
static  void com20020_release (struct pcmcia_device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct net_device*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 int /*<<< orphan*/  kfree (struct com20020_dev*) ; 
 struct com20020_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_dbg (struct net_device*,char*,int,scalar_t__) ; 
 struct arcnet_local* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_device_detach (struct net_device*) ; 
 int /*<<< orphan*/  node ; 
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 
 int pcmcia_enable_device (struct pcmcia_device*) ; 
 int pcmcia_request_io (struct pcmcia_device*) ; 
 int /*<<< orphan*/  timeout ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 

__attribute__((used)) static inline void com20020_set_subaddress(struct arcnet_local *lp,
					   int ioaddr, int val)
{
	if (val < 4) {
		lp->config = (lp->config & ~0x03) | val;
		arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
	} else {
		arcnet_outb(val, ioaddr, COM20020_REG_W_SUBADR);
	}
}

__attribute__((used)) static void regdump(struct net_device *dev)
{
#ifdef DEBUG
	int ioaddr = dev->base_addr;
	int count;

	netdev_dbg(dev, "register dump:\n");
	for (count = 0; count < 16; count++) {
		if (!(count % 16))
			pr_cont("%04X:", ioaddr + count);
		pr_cont(" %02X", arcnet_inb(ioaddr, count));
	}
	pr_cont("\n");

	netdev_dbg(dev, "buffer0 dump:\n");
	/* set up the address register */
	count = 0;
	arcnet_outb((count >> 8) | RDDATAflag | AUTOINCflag,
		    ioaddr, com20020_REG_W_ADDR_HI);
	arcnet_outb(count & 0xff, ioaddr, COM20020_REG_W_ADDR_LO);

	for (count = 0; count < 256 + 32; count++) {
		if (!(count % 16))
			pr_cont("%04X:", count);

		/* copy the data */
		pr_cont(" %02X", arcnet_inb(ioaddr, COM20020_REG_RW_MEMDATA));
	}
	pr_cont("\n");
#endif
}

__attribute__((used)) static int com20020_probe(struct pcmcia_device *p_dev)
{
	struct com20020_dev *info;
	struct net_device *dev;
	struct arcnet_local *lp;

	dev_dbg(&p_dev->dev, "com20020_attach()\n");

	/* Create new network device */
	info = kzalloc(sizeof(*info), GFP_KERNEL);
	if (!info)
		goto fail_alloc_info;

	dev = alloc_arcdev("");
	if (!dev)
		goto fail_alloc_dev;

	lp = netdev_priv(dev);
	lp->timeout = timeout;
	lp->backplane = backplane;
	lp->clockp = clockp;
	lp->clockm = clockm & 3;
	lp->hw.owner = THIS_MODULE;

	/* fill in our module parameters as defaults */
	dev->dev_addr[0] = node;

	p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
	p_dev->resource[0]->end = 16;
	p_dev->config_flags |= CONF_ENABLE_IRQ;

	info->dev = dev;
	p_dev->priv = info;

	return com20020_config(p_dev);

fail_alloc_dev:
	kfree(info);
fail_alloc_info:
	return -ENOMEM;
}

__attribute__((used)) static void com20020_detach(struct pcmcia_device *link)
{
	struct com20020_dev *info = link->priv;
	struct net_device *dev = info->dev;

	dev_dbg(&link->dev, "detach...\n");

	dev_dbg(&link->dev, "com20020_detach\n");

	dev_dbg(&link->dev, "unregister...\n");

	unregister_netdev(dev);

	/* this is necessary because we register our IRQ separately
	 * from card services.
	 */
	if (dev->irq)
		free_irq(dev->irq, dev);

	com20020_release(link);

	/* Unlink device structure, free bits */
	dev_dbg(&link->dev, "unlinking...\n");
	if (link->priv) {
		dev = info->dev;
		if (dev) {
			dev_dbg(&link->dev, "kfree...\n");
			free_netdev(dev);
		}
		dev_dbg(&link->dev, "kfree2...\n");
		kfree(info);
	}

}

__attribute__((used)) static int com20020_config(struct pcmcia_device *link)
{
	struct arcnet_local *lp;
	struct com20020_dev *info;
	struct net_device *dev;
	int i, ret;
	int ioaddr;

	info = link->priv;
	dev = info->dev;

	dev_dbg(&link->dev, "config...\n");

	dev_dbg(&link->dev, "com20020_config\n");

	dev_dbg(&link->dev, "baseport1 is %Xh\n",
		(unsigned int)link->resource[0]->start);

	i = -ENODEV;
	link->io_lines = 16;

	if (!link->resource[0]->start) {
		for (ioaddr = 0x100; ioaddr < 0x400; ioaddr += 0x10) {
			link->resource[0]->start = ioaddr;
			i = pcmcia_request_io(link);
			if (i == 0)
				break;
		}
	} else {
		i = pcmcia_request_io(link);
	}

	if (i != 0) {
		dev_dbg(&link->dev, "requestIO failed totally!\n");
		goto failed;
	}

	ioaddr = dev->base_addr = link->resource[0]->start;
	dev_dbg(&link->dev, "got ioaddr %Xh\n", ioaddr);

	dev_dbg(&link->dev, "request IRQ %d\n",
		link->irq);
	if (!link->irq) {
		dev_dbg(&link->dev, "requestIRQ failed totally!\n");
		goto failed;
	}

	dev->irq = link->irq;

	ret = pcmcia_enable_device(link);
	if (ret)
		goto failed;

	if (com20020_check(dev)) {
		regdump(dev);
		goto failed;
	}

	lp = netdev_priv(dev);
	lp->card_name = "PCMCIA COM20020";
	lp->card_flags = ARC_CAN_10MBIT; /* pretend all of them can 10Mbit */

	SET_NETDEV_DEV(dev, &link->dev);

	i = com20020_found(dev, 0);	/* calls register_netdev */

	if (i != 0) {
		dev_notice(&link->dev,
			   "com20020_found() failed\n");
		goto failed;
	}

	netdev_dbg(dev, "port %#3lx, irq %d\n",
		   dev->base_addr, dev->irq);
	return 0;

failed:
	dev_dbg(&link->dev, "com20020_config failed...\n");
	com20020_release(link);
	return -ENODEV;
}

__attribute__((used)) static void com20020_release(struct pcmcia_device *link)
{
	dev_dbg(&link->dev, "com20020_release\n");
	pcmcia_disable_device(link);
}

__attribute__((used)) static int com20020_suspend(struct pcmcia_device *link)
{
	struct com20020_dev *info = link->priv;
	struct net_device *dev = info->dev;

	if (link->open)
		netif_device_detach(dev);

	return 0;
}

__attribute__((used)) static int com20020_resume(struct pcmcia_device *link)
{
	struct com20020_dev *info = link->priv;
	struct net_device *dev = info->dev;

	if (link->open) {
		int ioaddr = dev->base_addr;
		struct arcnet_local *lp = netdev_priv(dev);

		arcnet_outb(lp->config | 0x80, ioaddr, COM20020_REG_W_CONFIG);
		udelay(5);
		arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
	}

	return 0;
}

