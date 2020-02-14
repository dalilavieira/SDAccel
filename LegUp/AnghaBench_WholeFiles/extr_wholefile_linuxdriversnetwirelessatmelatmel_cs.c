#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct pcmcia_device_id {int /*<<< orphan*/  driver_info; } ;
struct pcmcia_device {scalar_t__ config_index; int config_flags; struct local_info* priv; int /*<<< orphan*/  dev; TYPE_1__** resource; int /*<<< orphan*/  irq; } ;
struct net_device {int dummy; } ;
struct local_info {struct net_device* eth_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATMEL_FW_TYPE_NONE ; 
 int CONF_AUTO_AUDIO ; 
 int CONF_AUTO_SET_IO ; 
 int CONF_AUTO_SET_VPP ; 
 int CONF_ENABLE_IRQ ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
static  int atmel_config (struct pcmcia_device*) ; 
 int /*<<< orphan*/  atmel_open (struct net_device*) ; 
static  void atmel_release (struct pcmcia_device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct pcmcia_device_id* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct net_device* init_atmel_card (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int (*) (void*),struct pcmcia_device*) ; 
 int /*<<< orphan*/  kfree (struct local_info*) ; 
 struct local_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_device_attach (struct net_device*) ; 
 int /*<<< orphan*/  netif_device_detach (struct net_device*) ; 
 scalar_t__ pcmcia_dev_present (struct pcmcia_device*) ; 
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 
 int pcmcia_enable_device (struct pcmcia_device*) ; 
 scalar_t__ pcmcia_loop_config (struct pcmcia_device*,int (*) (struct pcmcia_device*,void*),int /*<<< orphan*/ *) ; 
 int pcmcia_request_io (struct pcmcia_device*) ; 
 int /*<<< orphan*/  stop_atmel_card (struct net_device*) ; 

__attribute__((used)) static int atmel_probe(struct pcmcia_device *p_dev)
{
	struct local_info *local;

	dev_dbg(&p_dev->dev, "atmel_attach()\n");

	/* Allocate space for private device-specific data */
	local = kzalloc(sizeof(*local), GFP_KERNEL);
	if (!local)
		return -ENOMEM;

	p_dev->priv = local;

	return atmel_config(p_dev);
}

__attribute__((used)) static void atmel_detach(struct pcmcia_device *link)
{
	dev_dbg(&link->dev, "atmel_detach\n");

	atmel_release(link);

	kfree(link->priv);
}

__attribute__((used)) static int card_present(void *arg)
{
	struct pcmcia_device *link = (struct pcmcia_device *)arg;

	if (pcmcia_dev_present(link))
		return 1;

	return 0;
}

__attribute__((used)) static int atmel_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
	if (p_dev->config_index == 0)
		return -EINVAL;

	return pcmcia_request_io(p_dev);
}

__attribute__((used)) static int atmel_config(struct pcmcia_device *link)
{
	struct local_info *dev;
	int ret;
	const struct pcmcia_device_id *did;

	dev = link->priv;
	did = dev_get_drvdata(&link->dev);

	dev_dbg(&link->dev, "atmel_config\n");

	link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
		CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;

	if (pcmcia_loop_config(link, atmel_config_check, NULL))
		goto failed;

	if (!link->irq) {
		dev_err(&link->dev, "atmel: cannot assign IRQ: check that CONFIG_ISA is set in kernel config.");
		goto failed;
	}

	ret = pcmcia_enable_device(link);
	if (ret)
		goto failed;

	((struct local_info *)link->priv)->eth_dev =
		init_atmel_card(link->irq,
				link->resource[0]->start,
				did ? did->driver_info : ATMEL_FW_TYPE_NONE,
				&link->dev,
				card_present,
				link);
	if (!((struct local_info *)link->priv)->eth_dev)
			goto failed;


	return 0;

 failed:
	atmel_release(link);
	return -ENODEV;
}

__attribute__((used)) static void atmel_release(struct pcmcia_device *link)
{
	struct net_device *dev = ((struct local_info *)link->priv)->eth_dev;

	dev_dbg(&link->dev, "atmel_release\n");

	if (dev)
		stop_atmel_card(dev);
	((struct local_info *)link->priv)->eth_dev = NULL;

	pcmcia_disable_device(link);
}

__attribute__((used)) static int atmel_suspend(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	netif_device_detach(local->eth_dev);

	return 0;
}

__attribute__((used)) static int atmel_resume(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	atmel_open(local->eth_dev);
	netif_device_attach(local->eth_dev);

	return 0;
}

