#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * parent; int /*<<< orphan*/ * bus; } ;
struct ntb_dev {int topo; int /*<<< orphan*/  released; int /*<<< orphan*/  ctx_lock; int /*<<< orphan*/ * ctx; struct ntb_ctx_ops const* ctx_ops; TYPE_6__ dev; TYPE_1__* pdev; int /*<<< orphan*/  ops; } ;
struct ntb_ctx_ops {int /*<<< orphan*/  (* msg_event ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* db_event ) (int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* link_event ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_10__ {int (* probe ) (struct ntb_client*,struct ntb_dev*) ;int /*<<< orphan*/  (* remove ) (struct ntb_client*,struct ntb_dev*) ;} ;
struct TYPE_11__ {char const* name; struct module* owner; int /*<<< orphan*/ * bus; } ;
struct ntb_client {TYPE_2__ ops; TYPE_3__ drv; } ;
struct module {int dummy; } ;
struct device {scalar_t__ driver; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int NTB_DEF_PEER_CNT ; 
 int NTB_DEF_PEER_IDX ; 
 int NTB_PORT_PRI_USD ; 
 int NTB_PORT_SEC_DSD ; 
#define  NTB_TOPO_B2B_DSD 131 
#define  NTB_TOPO_B2B_USD 130 
#define  NTB_TOPO_PRI 129 
#define  NTB_TOPO_SEC 128 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 struct ntb_dev* dev_ntb (struct device*) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_6__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_6__*) ; 
 int /*<<< orphan*/  device_unregister (TYPE_6__*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 struct ntb_client* drv_ntb_client (scalar_t__) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ntb_bus ; 
 int /*<<< orphan*/  ntb_client_ops_is_valid (TYPE_2__*) ; 
 int /*<<< orphan*/  ntb_ctx_ops_is_valid (struct ntb_ctx_ops const*) ; 
 int /*<<< orphan*/  ntb_dev_ops_is_valid (int /*<<< orphan*/ ) ; 
static  void ntb_dev_release (struct device*) ; 
 int /*<<< orphan*/  pci_name (TYPE_1__*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ *) ; 
 int stub4 (struct ntb_client*,struct ntb_dev*) ; 
 int /*<<< orphan*/  stub5 (struct ntb_client*,struct ntb_dev*) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

int __ntb_register_client(struct ntb_client *client, struct module *mod,
			  const char *mod_name)
{
	if (!client)
		return -EINVAL;
	if (!ntb_client_ops_is_valid(&client->ops))
		return -EINVAL;

	memset(&client->drv, 0, sizeof(client->drv));
	client->drv.bus = &ntb_bus;
	client->drv.name = mod_name;
	client->drv.owner = mod;

	return driver_register(&client->drv);
}

void ntb_unregister_client(struct ntb_client *client)
{
	driver_unregister(&client->drv);
}

int ntb_register_device(struct ntb_dev *ntb)
{
	if (!ntb)
		return -EINVAL;
	if (!ntb->pdev)
		return -EINVAL;
	if (!ntb->ops)
		return -EINVAL;
	if (!ntb_dev_ops_is_valid(ntb->ops))
		return -EINVAL;

	init_completion(&ntb->released);

	ntb->dev.bus = &ntb_bus;
	ntb->dev.parent = &ntb->pdev->dev;
	ntb->dev.release = ntb_dev_release;
	dev_set_name(&ntb->dev, "%s", pci_name(ntb->pdev));

	ntb->ctx = NULL;
	ntb->ctx_ops = NULL;
	spin_lock_init(&ntb->ctx_lock);

	return device_register(&ntb->dev);
}

void ntb_unregister_device(struct ntb_dev *ntb)
{
	device_unregister(&ntb->dev);
	wait_for_completion(&ntb->released);
}

int ntb_set_ctx(struct ntb_dev *ntb, void *ctx,
		const struct ntb_ctx_ops *ctx_ops)
{
	unsigned long irqflags;

	if (!ntb_ctx_ops_is_valid(ctx_ops))
		return -EINVAL;
	if (ntb->ctx_ops)
		return -EINVAL;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		ntb->ctx = ctx;
		ntb->ctx_ops = ctx_ops;
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);

	return 0;
}

void ntb_clear_ctx(struct ntb_dev *ntb)
{
	unsigned long irqflags;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		ntb->ctx_ops = NULL;
		ntb->ctx = NULL;
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}

void ntb_link_event(struct ntb_dev *ntb)
{
	unsigned long irqflags;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		if (ntb->ctx_ops && ntb->ctx_ops->link_event)
			ntb->ctx_ops->link_event(ntb->ctx);
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}

void ntb_db_event(struct ntb_dev *ntb, int vector)
{
	unsigned long irqflags;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		if (ntb->ctx_ops && ntb->ctx_ops->db_event)
			ntb->ctx_ops->db_event(ntb->ctx, vector);
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}

void ntb_msg_event(struct ntb_dev *ntb)
{
	unsigned long irqflags;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		if (ntb->ctx_ops && ntb->ctx_ops->msg_event)
			ntb->ctx_ops->msg_event(ntb->ctx);
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}

int ntb_default_port_number(struct ntb_dev *ntb)
{
	switch (ntb->topo) {
	case NTB_TOPO_PRI:
	case NTB_TOPO_B2B_USD:
		return NTB_PORT_PRI_USD;
	case NTB_TOPO_SEC:
	case NTB_TOPO_B2B_DSD:
		return NTB_PORT_SEC_DSD;
	default:
		break;
	}

	return -EINVAL;
}

int ntb_default_peer_port_count(struct ntb_dev *ntb)
{
	return NTB_DEF_PEER_CNT;
}

int ntb_default_peer_port_number(struct ntb_dev *ntb, int pidx)
{
	if (pidx != NTB_DEF_PEER_IDX)
		return -EINVAL;

	switch (ntb->topo) {
	case NTB_TOPO_PRI:
	case NTB_TOPO_B2B_USD:
		return NTB_PORT_SEC_DSD;
	case NTB_TOPO_SEC:
	case NTB_TOPO_B2B_DSD:
		return NTB_PORT_PRI_USD;
	default:
		break;
	}

	return -EINVAL;
}

int ntb_default_peer_port_idx(struct ntb_dev *ntb, int port)
{
	int peer_port = ntb_default_peer_port_number(ntb, NTB_DEF_PEER_IDX);

	if (peer_port == -EINVAL || port != peer_port)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int ntb_probe(struct device *dev)
{
	struct ntb_dev *ntb;
	struct ntb_client *client;
	int rc;

	get_device(dev);
	ntb = dev_ntb(dev);
	client = drv_ntb_client(dev->driver);

	rc = client->ops.probe(client, ntb);
	if (rc)
		put_device(dev);

	return rc;
}

__attribute__((used)) static int ntb_remove(struct device *dev)
{
	struct ntb_dev *ntb;
	struct ntb_client *client;

	if (dev->driver) {
		ntb = dev_ntb(dev);
		client = drv_ntb_client(dev->driver);

		client->ops.remove(client, ntb);
		put_device(dev);
	}

	return 0;
}

__attribute__((used)) static void ntb_dev_release(struct device *dev)
{
	struct ntb_dev *ntb = dev_ntb(dev);

	complete(&ntb->released);
}

