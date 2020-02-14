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
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct work_struct {int dummy; } ;
struct TYPE_11__ {int device_type; scalar_t__ target_port_protocols; int /*<<< orphan*/  initiator_port_protocols; void* sas_address; } ;
struct sas_rphy {TYPE_5__ identify; } ;
struct TYPE_12__ {int device_type; int phy_identifier; void* sas_address; scalar_t__ target_port_protocols; int /*<<< orphan*/  initiator_port_protocols; } ;
struct sas_phy {void* negotiated_linkrate; void* maximum_linkrate; void* minimum_linkrate; void* maximum_linkrate_hw; void* minimum_linkrate_hw; TYPE_6__ identify; int /*<<< orphan*/  dev; } ;
struct sas_internal {TYPE_2__* dft; } ;
struct TYPE_10__ {TYPE_3__* shost; } ;
struct sas_ha_struct {int num_phys; int /*<<< orphan*/  sas_addr; TYPE_4__ core; struct asd_sas_phy** sas_phy; } ;
struct expander_device {scalar_t__ parent_port; struct ex_phy* ex_phy; } ;
struct ex_phy {int /*<<< orphan*/  phy; } ;
struct domain_device {int dev_type; int /*<<< orphan*/  kref; int /*<<< orphan*/  done_lock; int /*<<< orphan*/  disco_list_node; int /*<<< orphan*/  dev_list_node; int /*<<< orphan*/  siblings; TYPE_1__* rphy; struct expander_device ex_dev; scalar_t__ tproto; int /*<<< orphan*/  iproto; int /*<<< orphan*/  sas_addr; int /*<<< orphan*/  port; scalar_t__ parent; } ;
struct bsg_job {int dummy; } ;
struct asd_sas_port {int dummy; } ;
struct asd_sas_phy {int error; struct sas_phy* phy; scalar_t__ tproto; int /*<<< orphan*/  iproto; scalar_t__ frame_rcvd_size; int /*<<< orphan*/  sas_prim_lock; int /*<<< orphan*/  frame_rcvd_lock; struct sas_ha_struct* ha; struct asd_sas_port* port; int /*<<< orphan*/  port_phy_el; int /*<<< orphan*/  event_nr; int /*<<< orphan*/  id; scalar_t__ enabled; scalar_t__ suspended; scalar_t__ in_shutdown; } ;
struct asd_sas_event {struct asd_sas_phy* phy; } ;
struct Scsi_Host {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  shost_gendev; int /*<<< orphan*/  transportt; } ;
struct TYPE_8__ {int (* lldd_control_phy ) (struct asd_sas_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  PHY_FUNC_DISABLE ; 
 int /*<<< orphan*/  PHY_FUNC_HARD_RESET ; 
 int /*<<< orphan*/  PHY_FUNC_RELEASE_SPINUP_HOLD ; 
 void* SAS_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SAS_DPRINTK (char*,char const*,char*,void*,int) ; 
#define  SAS_EDGE_EXPANDER_DEVICE 132 
#define  SAS_END_DEVICE 131 
#define  SAS_FANOUT_EXPANDER_DEVICE 130 
 void* SAS_LINK_RATE_UNKNOWN ; 
 void* SAS_PHY_UNUSED ; 
#define  SAS_SATA_DEV 129 
#define  SAS_SATA_PENDING 128 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bsg_job_done (struct bsg_job*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ dev_is_sata (struct domain_device*) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct domain_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sas_deform_port (struct asd_sas_phy*,int) ; 
 int /*<<< orphan*/  sas_free_device ; 
 int /*<<< orphan*/  sas_phy_add (struct sas_phy*) ; 
 struct sas_phy* sas_phy_alloc (int /*<<< orphan*/ *,int) ; 
 int sas_port_add (scalar_t__) ; 
 int /*<<< orphan*/  sas_port_add_phy (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ sas_port_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sas_port_mark_backlink (scalar_t__) ; 
 int /*<<< orphan*/  sas_printk (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  sas_unregister_dev (int /*<<< orphan*/ ,struct domain_device*) ; 
 int /*<<< orphan*/  shost_printk (int /*<<< orphan*/ ,struct Scsi_Host*,char*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int stub1 (struct asd_sas_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub2 (struct asd_sas_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub3 (struct asd_sas_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub4 (struct asd_sas_phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct asd_sas_event* to_asd_sas_event (struct work_struct*) ; 
 struct sas_internal* to_sas_internal (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static void sas_phye_loss_of_signal(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;

	phy->in_shutdown = 0;
	phy->error = 0;
	sas_deform_port(phy, 1);
}

__attribute__((used)) static void sas_phye_oob_done(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;

	phy->in_shutdown = 0;
	phy->error = 0;
}

__attribute__((used)) static void sas_phye_oob_error(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;
	struct sas_ha_struct *sas_ha = phy->ha;
	struct asd_sas_port *port = phy->port;
	struct sas_internal *i =
		to_sas_internal(sas_ha->core.shost->transportt);

	sas_deform_port(phy, 1);

	if (!port && phy->enabled && i->dft->lldd_control_phy) {
		phy->error++;
		switch (phy->error) {
		case 1:
		case 2:
			i->dft->lldd_control_phy(phy, PHY_FUNC_HARD_RESET,
						 NULL);
			break;
		case 3:
		default:
			phy->error = 0;
			phy->enabled = 0;
			i->dft->lldd_control_phy(phy, PHY_FUNC_DISABLE, NULL);
			break;
		}
	}
}

__attribute__((used)) static void sas_phye_spinup_hold(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;
	struct sas_ha_struct *sas_ha = phy->ha;
	struct sas_internal *i =
		to_sas_internal(sas_ha->core.shost->transportt);

	phy->error = 0;
	i->dft->lldd_control_phy(phy, PHY_FUNC_RELEASE_SPINUP_HOLD, NULL);
}

__attribute__((used)) static void sas_phye_resume_timeout(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;

	/* phew, lldd got the phy back in the nick of time */
	if (!phy->suspended) {
		dev_info(&phy->phy->dev, "resume timeout cancelled\n");
		return;
	}

	phy->error = 0;
	phy->suspended = 0;
	sas_deform_port(phy, 1);
}

__attribute__((used)) static void sas_phye_shutdown(struct work_struct *work)
{
	struct asd_sas_event *ev = to_asd_sas_event(work);
	struct asd_sas_phy *phy = ev->phy;
	struct sas_ha_struct *sas_ha = phy->ha;
	struct sas_internal *i =
		to_sas_internal(sas_ha->core.shost->transportt);

	if (phy->enabled) {
		int ret;

		phy->error = 0;
		phy->enabled = 0;
		ret = i->dft->lldd_control_phy(phy, PHY_FUNC_DISABLE, NULL);
		if (ret)
			sas_printk("lldd disable phy%02d returned %d\n",
				phy->id, ret);
	} else
		sas_printk("phy%02d is not enabled, cannot shutdown\n",
			phy->id);
}

int sas_register_phys(struct sas_ha_struct *sas_ha)
{
	int i;

	/* Now register the phys. */
	for (i = 0; i < sas_ha->num_phys; i++) {
		struct asd_sas_phy *phy = sas_ha->sas_phy[i];

		phy->error = 0;
		atomic_set(&phy->event_nr, 0);
		INIT_LIST_HEAD(&phy->port_phy_el);

		phy->port = NULL;
		phy->ha = sas_ha;
		spin_lock_init(&phy->frame_rcvd_lock);
		spin_lock_init(&phy->sas_prim_lock);
		phy->frame_rcvd_size = 0;

		phy->phy = sas_phy_alloc(&sas_ha->core.shost->shost_gendev, i);
		if (!phy->phy)
			return -ENOMEM;

		phy->phy->identify.initiator_port_protocols =
			phy->iproto;
		phy->phy->identify.target_port_protocols = phy->tproto;
		phy->phy->identify.sas_address = SAS_ADDR(sas_ha->sas_addr);
		phy->phy->identify.phy_identifier = i;
		phy->phy->minimum_linkrate_hw = SAS_LINK_RATE_UNKNOWN;
		phy->phy->maximum_linkrate_hw = SAS_LINK_RATE_UNKNOWN;
		phy->phy->minimum_linkrate = SAS_LINK_RATE_UNKNOWN;
		phy->phy->maximum_linkrate = SAS_LINK_RATE_UNKNOWN;
		phy->phy->negotiated_linkrate = SAS_LINK_RATE_UNKNOWN;

		sas_phy_add(phy->phy);
	}

	return 0;
}

