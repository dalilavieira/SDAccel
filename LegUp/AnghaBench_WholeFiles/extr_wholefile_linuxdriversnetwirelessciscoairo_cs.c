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
struct pcmcia_device {scalar_t__ config_index; int config_flags; scalar_t__ open; struct local_info* priv; int /*<<< orphan*/  dev; TYPE_1__** resource; int /*<<< orphan*/  irq; } ;
struct local_info {int /*<<< orphan*/ * eth_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 int CONF_AUTO_AUDIO ; 
 int CONF_AUTO_SET_IO ; 
 int CONF_AUTO_SET_VPP ; 
 int CONF_ENABLE_IRQ ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
static  int airo_config (struct pcmcia_device*) ; 
static  void airo_release (struct pcmcia_device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * init_airo_card (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct local_info*) ; 
 struct local_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_device_attach (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netif_device_detach (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 
 int pcmcia_enable_device (struct pcmcia_device*) ; 
 int pcmcia_loop_config (struct pcmcia_device*,int (*) (struct pcmcia_device*,void*),int /*<<< orphan*/ *) ; 
 int pcmcia_request_io (struct pcmcia_device*) ; 
 int /*<<< orphan*/  reset_airo_card (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stop_airo_card (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int airo_probe(struct pcmcia_device *p_dev)
{
	struct local_info *local;

	dev_dbg(&p_dev->dev, "airo_attach()\n");

	/* Allocate space for private device-specific data */
	local = kzalloc(sizeof(*local), GFP_KERNEL);
	if (!local)
		return -ENOMEM;

	p_dev->priv = local;

	return airo_config(p_dev);
}

__attribute__((used)) static void airo_detach(struct pcmcia_device *link)
{
	dev_dbg(&link->dev, "airo_detach\n");

	airo_release(link);

	if (((struct local_info *)link->priv)->eth_dev) {
		stop_airo_card(((struct local_info *)link->priv)->eth_dev,
			       0);
	}
	((struct local_info *)link->priv)->eth_dev = NULL;

	kfree(link->priv);
}

__attribute__((used)) static int airo_cs_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
	if (p_dev->config_index == 0)
		return -EINVAL;

	return pcmcia_request_io(p_dev);
}

__attribute__((used)) static int airo_config(struct pcmcia_device *link)
{
	int ret;

	dev_dbg(&link->dev, "airo_config\n");

	link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
		CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;

	ret = pcmcia_loop_config(link, airo_cs_config_check, NULL);
	if (ret)
		goto failed;

	if (!link->irq)
		goto failed;

	ret = pcmcia_enable_device(link);
	if (ret)
		goto failed;
	((struct local_info *)link->priv)->eth_dev =
		init_airo_card(link->irq,
			       link->resource[0]->start, 1, &link->dev);
	if (!((struct local_info *)link->priv)->eth_dev)
		goto failed;

	return 0;

 failed:
	airo_release(link);
	return -ENODEV;
}

__attribute__((used)) static void airo_release(struct pcmcia_device *link)
{
	dev_dbg(&link->dev, "airo_release\n");
	pcmcia_disable_device(link);
}

__attribute__((used)) static int airo_suspend(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	netif_device_detach(local->eth_dev);

	return 0;
}

__attribute__((used)) static int airo_resume(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	if (link->open) {
		reset_airo_card(local->eth_dev);
		netif_device_attach(local->eth_dev);
	}

	return 0;
}

