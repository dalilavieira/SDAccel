#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int device_type; scalar_t__ target_port_protocols; int /*<<< orphan*/  initiator_port_protocols; int /*<<< orphan*/  sas_address; } ;
struct sas_rphy {TYPE_1__ identify; } ;
struct TYPE_5__ {int device_type; scalar_t__ target_port_protocols; } ;
struct sas_phy {TYPE_2__ identify; } ;
struct expander_device {scalar_t__ parent_port; struct ex_phy* ex_phy; } ;
struct ex_phy {int /*<<< orphan*/  phy; } ;
struct domain_device {int dev_type; int /*<<< orphan*/  kref; int /*<<< orphan*/  done_lock; int /*<<< orphan*/  disco_list_node; int /*<<< orphan*/  dev_list_node; int /*<<< orphan*/  siblings; TYPE_3__* rphy; struct expander_device ex_dev; scalar_t__ tproto; int /*<<< orphan*/  iproto; int /*<<< orphan*/  sas_addr; int /*<<< orphan*/  port; scalar_t__ parent; } ;
struct bsg_job {int dummy; } ;
struct asd_sas_port {int id; int /*<<< orphan*/  num_phys; int /*<<< orphan*/  oob_mode; int /*<<< orphan*/  tproto; int /*<<< orphan*/  iproto; int /*<<< orphan*/  attached_sas_addr; int /*<<< orphan*/  sas_addr; int /*<<< orphan*/  class; } ;
struct asd_sas_phy {struct sas_phy* phy; } ;
struct Scsi_Host {int dummy; } ;
typedef  enum port_event { ____Placeholder_port_event } port_event ;
typedef  enum phy_event { ____Placeholder_phy_event } phy_event ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  SAS_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SAS_DPRINTK (char*,...) ; 
#define  SAS_EDGE_EXPANDER_DEVICE 132 
#define  SAS_END_DEVICE 131 
#define  SAS_FANOUT_EXPANDER_DEVICE 130 
 void* SAS_PHY_UNUSED ; 
#define  SAS_SATA_DEV 129 
#define  SAS_SATA_PENDING 128 
 int /*<<< orphan*/  bsg_job_done (struct bsg_job*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ dev_is_sata (struct domain_device*) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct domain_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sas_free_device ; 
 int /*<<< orphan*/ * sas_phye_str ; 
 int sas_port_add (scalar_t__) ; 
 int /*<<< orphan*/  sas_port_add_phy (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ sas_port_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sas_port_mark_backlink (scalar_t__) ; 
 int /*<<< orphan*/ * sas_porte_str ; 
 int /*<<< orphan*/  sas_unregister_dev (int /*<<< orphan*/ ,struct domain_device*) ; 
 int /*<<< orphan*/  shost_printk (int /*<<< orphan*/ ,struct Scsi_Host*,char*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void sas_smp_host_handler(struct bsg_job *job,
		struct Scsi_Host *shost)
{
	shost_printk(KERN_ERR, shost,
		"Cannot send SMP to a sas host (not enabled in CONFIG)\n");
	bsg_job_done(job, -EINVAL, 0);
}

__attribute__((used)) static inline void sas_fail_probe(struct domain_device *dev, const char *func, int err)
{
	SAS_DPRINTK("%s: for %s device %16llx returned %d\n",
		    func, dev->parent ? "exp-attached" :
					    "direct-attached",
		    SAS_ADDR(dev->sas_addr), err);
	sas_unregister_dev(dev->port, dev);
}

__attribute__((used)) static inline void sas_fill_in_rphy(struct domain_device *dev,
				    struct sas_rphy *rphy)
{
	rphy->identify.sas_address = SAS_ADDR(dev->sas_addr);
	rphy->identify.initiator_port_protocols = dev->iproto;
	rphy->identify.target_port_protocols = dev->tproto;
	switch (dev->dev_type) {
	case SAS_SATA_DEV:
		/* FIXME: need sata device type */
	case SAS_END_DEVICE:
	case SAS_SATA_PENDING:
		rphy->identify.device_type = SAS_END_DEVICE;
		break;
	case SAS_EDGE_EXPANDER_DEVICE:
		rphy->identify.device_type = SAS_EDGE_EXPANDER_DEVICE;
		break;
	case SAS_FANOUT_EXPANDER_DEVICE:
		rphy->identify.device_type = SAS_FANOUT_EXPANDER_DEVICE;
		break;
	default:
		rphy->identify.device_type = SAS_PHY_UNUSED;
		break;
	}
}

__attribute__((used)) static inline void sas_phy_set_target(struct asd_sas_phy *p, struct domain_device *dev)
{
	struct sas_phy *phy = p->phy;

	if (dev) {
		if (dev_is_sata(dev))
			phy->identify.device_type = SAS_END_DEVICE;
		else
			phy->identify.device_type = dev->dev_type;
		phy->identify.target_port_protocols = dev->tproto;
	} else {
		phy->identify.device_type = SAS_PHY_UNUSED;
		phy->identify.target_port_protocols = 0;
	}
}

__attribute__((used)) static inline void sas_add_parent_port(struct domain_device *dev, int phy_id)
{
	struct expander_device *ex = &dev->ex_dev;
	struct ex_phy *ex_phy = &ex->ex_phy[phy_id];

	if (!ex->parent_port) {
		ex->parent_port = sas_port_alloc(&dev->rphy->dev, phy_id);
		/* FIXME: error handling */
		BUG_ON(!ex->parent_port);
		BUG_ON(sas_port_add(ex->parent_port));
		sas_port_mark_backlink(ex->parent_port);
	}
	sas_port_add_phy(ex->parent_port, ex_phy->phy);
}

__attribute__((used)) static inline struct domain_device *sas_alloc_device(void)
{
	struct domain_device *dev = kzalloc(sizeof(*dev), GFP_KERNEL);

	if (dev) {
		INIT_LIST_HEAD(&dev->siblings);
		INIT_LIST_HEAD(&dev->dev_list_node);
		INIT_LIST_HEAD(&dev->disco_list_node);
		kref_init(&dev->kref);
		spin_lock_init(&dev->done_lock);
	}
	return dev;
}

__attribute__((used)) static inline void sas_put_device(struct domain_device *dev)
{
	kref_put(&dev->kref, sas_free_device);
}

void sas_dprint_porte(int phyid, enum port_event pe)
{
	SAS_DPRINTK("phy%d: port event: %s\n", phyid, sas_porte_str[pe]);
}

void sas_dprint_phye(int phyid, enum phy_event pe)
{
	SAS_DPRINTK("phy%d: phy event: %s\n", phyid, sas_phye_str[pe]);
}

void sas_dump_port(struct asd_sas_port *port)
{
	SAS_DPRINTK("port%d: class:0x%x\n", port->id, port->class);
	SAS_DPRINTK("port%d: sas_addr:%llx\n", port->id,
		    SAS_ADDR(port->sas_addr));
	SAS_DPRINTK("port%d: attached_sas_addr:%llx\n", port->id,
		    SAS_ADDR(port->attached_sas_addr));
	SAS_DPRINTK("port%d: iproto:0x%x\n", port->id, port->iproto);
	SAS_DPRINTK("port%d: tproto:0x%x\n", port->id, port->tproto);
	SAS_DPRINTK("port%d: oob_mode:0x%x\n", port->id, port->oob_mode);
	SAS_DPRINTK("port%d: num_phys:%d\n", port->id, port->num_phys);
}

