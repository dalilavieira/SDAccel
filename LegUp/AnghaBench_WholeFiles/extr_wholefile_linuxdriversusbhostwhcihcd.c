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
typedef  size_t u8 ;
typedef  int u64 ;
struct TYPE_2__ {int sg_tablesize; int /*<<< orphan*/  controller; } ;
struct usb_hcd {scalar_t__ wireless; int uses_new_polling; TYPE_1__ self; int /*<<< orphan*/  state; int /*<<< orphan*/  flags; } ;
struct wusbhc {size_t cluster_id; scalar_t__ ports_max; int /*<<< orphan*/  uwb_rc; int /*<<< orphan*/  set_gtk; int /*<<< orphan*/  set_ptk; int /*<<< orphan*/  set_num_dnts; int /*<<< orphan*/  bwa_set; int /*<<< orphan*/  dev_info_set; int /*<<< orphan*/  mmcie_rm; int /*<<< orphan*/  mmcie_add; int /*<<< orphan*/  stop; int /*<<< orphan*/  start; int /*<<< orphan*/  mmcies_max; struct device* dev; int /*<<< orphan*/  mutex; struct wusb_port* port; struct usb_hcd usb_hcd; } ;
struct wusb_port {int dummy; } ;
struct wusb_dev {int /*<<< orphan*/  refcnt; } ;
struct whc_std {int ntds_remaining; } ;
struct whc_qset {int remove; int reset; } ;
struct whc {scalar_t__ n_devices; struct umc_dev* umc; int /*<<< orphan*/  n_mmc_ies; int /*<<< orphan*/  lock; int /*<<< orphan*/  periodic_work; int /*<<< orphan*/  workqueue; int /*<<< orphan*/  async_work; scalar_t__ base; } ;
struct usb_host_endpoint {int /*<<< orphan*/  desc; struct whc_qset* hcpriv; } ;
struct usb_device {int devnum; int /*<<< orphan*/  wusb; int /*<<< orphan*/  dev; int /*<<< orphan*/  bus; } ;
struct urb {unsigned int pipe; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct umc_dev {struct device dev; int /*<<< orphan*/  irq; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  HCD_FLAG_POLL_RH ; 
 int /*<<< orphan*/  HC_STATE_RUNNING ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
#define  PIPE_BULK 135 
#define  PIPE_CONTROL 134 
#define  PIPE_INTERRUPT 133 
#define  PIPE_ISOCHRONOUS 132 
#define  QH_INFO1_TR_TYPE_BULK 131 
#define  QH_INFO1_TR_TYPE_CTRL 130 
#define  QH_INFO1_TR_TYPE_INT 129 
#define  QH_INFO1_TR_TYPE_ISOC 128 
 int QH_LINK_PTR (int) ; 
 int QH_LINK_PTR_MASK ; 
 int QH_LINK_T ; 
 scalar_t__ USB_MAXCHILDREN ; 
 int /*<<< orphan*/  WUSBCMD_RUN ; 
 scalar_t__ WUSBINTR ; 
 int WUSBINTR_ASYNC_SCHED_SYNCED ; 
 int WUSBINTR_DNTS_INT ; 
 int WUSBINTR_ERR_INT ; 
 int WUSBINTR_GEN_CMD_DONE ; 
 int WUSBINTR_HOST_ERR ; 
 int WUSBINTR_INT ; 
 scalar_t__ WUSBSTS ; 
 int /*<<< orphan*/  WUSBSTS_HCHALTED ; 
 struct wusb_dev* __wusb_dev_get_by_usb_dev (struct wusbhc*,struct usb_device*) ; 
 int /*<<< orphan*/  asl_qset_delete (struct whc*,struct whc_qset*) ; 
 int asl_urb_dequeue (struct whc*,struct urb*,int) ; 
 int asl_urb_enqueue (struct whc*,struct urb*,int /*<<< orphan*/ ) ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct usb_hcd* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,scalar_t__) ; 
 int /*<<< orphan*/  device_wakeup_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le_writel (int,scalar_t__) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pzl_qset_delete (struct whc*,struct whc_qset*) ; 
 int pzl_urb_dequeue (struct whc*,struct urb*,int) ; 
 int pzl_urb_enqueue (struct whc*,struct urb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int usb_add_hcd (struct usb_hcd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct usb_hcd* usb_create_hcd (int /*<<< orphan*/ *,struct device*,char*) ; 
 scalar_t__ usb_endpoint_xfer_bulk (int /*<<< orphan*/ *) ; 
 scalar_t__ usb_endpoint_xfer_control (int /*<<< orphan*/ *) ; 
 struct usb_hcd* usb_get_hcd (struct usb_hcd*) ; 
 struct wusbhc* usb_hcd_to_wusbhc (struct usb_hcd*) ; 
 int usb_pipetype (unsigned int) ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_remove_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  uwb_rc_get_by_grandpa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uwb_rc_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  whc_bwa_set ; 
 int /*<<< orphan*/  whc_clean_up (struct whc*) ; 
 int /*<<< orphan*/  whc_dbg_clean_up (struct whc*) ; 
 int /*<<< orphan*/  whc_dbg_init (struct whc*) ; 
 int /*<<< orphan*/  whc_dev_info_set ; 
 int /*<<< orphan*/  whc_hc_driver ; 
 int whc_init (struct whc*) ; 
 int /*<<< orphan*/  whc_mmcie_add ; 
 int /*<<< orphan*/  whc_mmcie_rm ; 
 int whc_set_cluster_id (struct whc*,size_t) ; 
 int /*<<< orphan*/  whc_set_gtk ; 
 int /*<<< orphan*/  whc_set_num_dnts ; 
 int /*<<< orphan*/  whc_set_ptk ; 
 int /*<<< orphan*/  whc_write_wusbcmd (struct whc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  whc_wusbhc_start ; 
 int /*<<< orphan*/  whc_wusbhc_stop ; 
 int /*<<< orphan*/  whci_wait_for (struct device*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*) ; 
 size_t wusb_cluster_id_get () ; 
 int /*<<< orphan*/  wusb_cluster_id_put (size_t) ; 
 int /*<<< orphan*/  wusb_dev_destroy ; 
 int wusbhc_b_create (struct wusbhc*) ; 
 int /*<<< orphan*/  wusbhc_b_destroy (struct wusbhc*) ; 
 int wusbhc_create (struct wusbhc*) ; 
 int /*<<< orphan*/  wusbhc_destroy (struct wusbhc*) ; 
 struct whc* wusbhc_to_whc (struct wusbhc*) ; 

__attribute__((used)) static inline void wusb_dev_init(struct wusb_dev *wusb_dev)
{
	kref_init(&wusb_dev->refcnt);
	/* no need to init the cack_node */
}

__attribute__((used)) static inline struct wusb_dev *wusb_dev_get(struct wusb_dev *wusb_dev)
{
	kref_get(&wusb_dev->refcnt);
	return wusb_dev;
}

__attribute__((used)) static inline void wusb_dev_put(struct wusb_dev *wusb_dev)
{
	kref_put(&wusb_dev->refcnt, wusb_dev_destroy);
}

__attribute__((used)) static inline
struct usb_hcd *usb_hcd_get_by_usb_dev(struct usb_device *usb_dev)
{
	struct usb_hcd *usb_hcd;
	usb_hcd = bus_to_hcd(usb_dev->bus);
	return usb_get_hcd(usb_hcd);
}

__attribute__((used)) static inline struct wusbhc *wusbhc_get(struct wusbhc *wusbhc)
{
	return usb_get_hcd(&wusbhc->usb_hcd) ? wusbhc : NULL;
}

__attribute__((used)) static inline struct wusbhc *wusbhc_get_by_usb_dev(struct usb_device *usb_dev)
{
	struct wusbhc *wusbhc = NULL;
	struct usb_hcd *usb_hcd;
	if (usb_dev->devnum > 1 && !usb_dev->wusb) {
		/* but root hubs */
		dev_err(&usb_dev->dev, "devnum %d wusb %d\n", usb_dev->devnum,
			usb_dev->wusb);
		BUG_ON(usb_dev->devnum > 1 && !usb_dev->wusb);
	}
	usb_hcd = usb_hcd_get_by_usb_dev(usb_dev);
	if (usb_hcd == NULL)
		return NULL;
	BUG_ON(usb_hcd->wireless == 0);
	return wusbhc = usb_hcd_to_wusbhc(usb_hcd);
}

__attribute__((used)) static inline void wusbhc_put(struct wusbhc *wusbhc)
{
	usb_put_hcd(&wusbhc->usb_hcd);
}

__attribute__((used)) static inline struct wusb_port *wusb_port_by_idx(struct wusbhc *wusbhc,
						 u8 port_idx)
{
	return &wusbhc->port[port_idx];
}

__attribute__((used)) static inline u8 wusb_port_no_to_idx(u8 port_no)
{
	return port_no - 1;
}

__attribute__((used)) static inline
struct wusb_dev *wusb_dev_get_by_usb_dev(struct usb_device *usb_dev)
{
	struct wusbhc *wusbhc;
	struct wusb_dev *wusb_dev;
	wusbhc = wusbhc_get_by_usb_dev(usb_dev);
	if (wusbhc == NULL)
		return NULL;
	mutex_lock(&wusbhc->mutex);
	wusb_dev = __wusb_dev_get_by_usb_dev(wusbhc, usb_dev);
	mutex_unlock(&wusbhc->mutex);
	wusbhc_put(wusbhc);
	return wusb_dev;
}

__attribute__((used)) static inline unsigned usb_pipe_to_qh_type(unsigned pipe)
{
	static const unsigned type[] = {
		[PIPE_ISOCHRONOUS] = QH_INFO1_TR_TYPE_ISOC,
		[PIPE_INTERRUPT]   = QH_INFO1_TR_TYPE_INT,
		[PIPE_CONTROL]     = QH_INFO1_TR_TYPE_CTRL,
		[PIPE_BULK]        = QH_INFO1_TR_TYPE_BULK,
	};
	return type[usb_pipetype(pipe)];
}

__attribute__((used)) static inline void whc_qset_set_link_ptr(u64 *ptr, u64 target)
{
	if (target)
		*ptr = (*ptr & ~(QH_LINK_PTR_MASK | QH_LINK_T)) | QH_LINK_PTR(target);
	else
		*ptr = QH_LINK_T;
}

__attribute__((used)) static inline bool whc_std_last(struct whc_std *std)
{
	return std->ntds_remaining <= 1;
}

__attribute__((used)) static int whc_reset(struct usb_hcd *usb_hcd)
{
	return 0;
}

__attribute__((used)) static int whc_start(struct usb_hcd *usb_hcd)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);
	u8 bcid;
	int ret;

	mutex_lock(&wusbhc->mutex);

	le_writel(WUSBINTR_GEN_CMD_DONE
		  | WUSBINTR_HOST_ERR
		  | WUSBINTR_ASYNC_SCHED_SYNCED
		  | WUSBINTR_DNTS_INT
		  | WUSBINTR_ERR_INT
		  | WUSBINTR_INT,
		  whc->base + WUSBINTR);

	/* set cluster ID */
	bcid = wusb_cluster_id_get();
	ret = whc_set_cluster_id(whc, bcid);
	if (ret < 0)
		goto out;
	wusbhc->cluster_id = bcid;

	/* start HC */
	whc_write_wusbcmd(whc, WUSBCMD_RUN, WUSBCMD_RUN);

	usb_hcd->uses_new_polling = 1;
	set_bit(HCD_FLAG_POLL_RH, &usb_hcd->flags);
	usb_hcd->state = HC_STATE_RUNNING;

out:
	mutex_unlock(&wusbhc->mutex);
	return ret;
}

__attribute__((used)) static void whc_stop(struct usb_hcd *usb_hcd)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);

	mutex_lock(&wusbhc->mutex);

	/* stop HC */
	le_writel(0, whc->base + WUSBINTR);
	whc_write_wusbcmd(whc, WUSBCMD_RUN, 0);
	whci_wait_for(&whc->umc->dev, whc->base + WUSBSTS,
		      WUSBSTS_HCHALTED, WUSBSTS_HCHALTED,
		      100, "HC to halt");

	wusb_cluster_id_put(wusbhc->cluster_id);

	mutex_unlock(&wusbhc->mutex);
}

__attribute__((used)) static int whc_get_frame_number(struct usb_hcd *usb_hcd)
{
	/* Frame numbers are not applicable to WUSB. */
	return -ENOSYS;
}

__attribute__((used)) static int whc_urb_enqueue(struct usb_hcd *usb_hcd, struct urb *urb,
			   gfp_t mem_flags)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);
	int ret;

	switch (usb_pipetype(urb->pipe)) {
	case PIPE_INTERRUPT:
		ret = pzl_urb_enqueue(whc, urb, mem_flags);
		break;
	case PIPE_ISOCHRONOUS:
		dev_err(&whc->umc->dev, "isochronous transfers unsupported\n");
		ret = -ENOTSUPP;
		break;
	case PIPE_CONTROL:
	case PIPE_BULK:
	default:
		ret = asl_urb_enqueue(whc, urb, mem_flags);
		break;
	}

	return ret;
}

__attribute__((used)) static int whc_urb_dequeue(struct usb_hcd *usb_hcd, struct urb *urb, int status)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);
	int ret;

	switch (usb_pipetype(urb->pipe)) {
	case PIPE_INTERRUPT:
		ret = pzl_urb_dequeue(whc, urb, status);
		break;
	case PIPE_ISOCHRONOUS:
		ret = -ENOTSUPP;
		break;
	case PIPE_CONTROL:
	case PIPE_BULK:
	default:
		ret = asl_urb_dequeue(whc, urb, status);
		break;
	}

	return ret;
}

__attribute__((used)) static void whc_endpoint_disable(struct usb_hcd *usb_hcd,
				 struct usb_host_endpoint *ep)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);
	struct whc_qset *qset;

	qset = ep->hcpriv;
	if (qset) {
		ep->hcpriv = NULL;
		if (usb_endpoint_xfer_bulk(&ep->desc)
		    || usb_endpoint_xfer_control(&ep->desc))
			asl_qset_delete(whc, qset);
		else
			pzl_qset_delete(whc, qset);
	}
}

__attribute__((used)) static void whc_endpoint_reset(struct usb_hcd *usb_hcd,
			       struct usb_host_endpoint *ep)
{
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);
	struct whc_qset *qset;
	unsigned long flags;

	spin_lock_irqsave(&whc->lock, flags);

	qset = ep->hcpriv;
	if (qset) {
		qset->remove = 1;
		qset->reset = 1;

		if (usb_endpoint_xfer_bulk(&ep->desc)
		    || usb_endpoint_xfer_control(&ep->desc))
			queue_work(whc->workqueue, &whc->async_work);
		else
			queue_work(whc->workqueue, &whc->periodic_work);
	}

	spin_unlock_irqrestore(&whc->lock, flags);
}

__attribute__((used)) static int whc_probe(struct umc_dev *umc)
{
	int ret;
	struct usb_hcd *usb_hcd;
	struct wusbhc *wusbhc;
	struct whc *whc;
	struct device *dev = &umc->dev;

	usb_hcd = usb_create_hcd(&whc_hc_driver, dev, "whci");
	if (usb_hcd == NULL) {
		dev_err(dev, "unable to create hcd\n");
		return -ENOMEM;
	}

	usb_hcd->wireless = 1;
	usb_hcd->self.sg_tablesize = 2048; /* somewhat arbitrary */

	wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	whc = wusbhc_to_whc(wusbhc);
	whc->umc = umc;

	ret = whc_init(whc);
	if (ret)
		goto error_whc_init;

	wusbhc->dev = dev;
	wusbhc->uwb_rc = uwb_rc_get_by_grandpa(umc->dev.parent);
	if (!wusbhc->uwb_rc) {
		ret = -ENODEV;
		dev_err(dev, "cannot get radio controller\n");
		goto error_uwb_rc;
	}

	if (whc->n_devices > USB_MAXCHILDREN) {
		dev_warn(dev, "USB_MAXCHILDREN too low for WUSB adapter (%u ports)\n",
			 whc->n_devices);
		wusbhc->ports_max = USB_MAXCHILDREN;
	} else
		wusbhc->ports_max = whc->n_devices;
	wusbhc->mmcies_max      = whc->n_mmc_ies;
	wusbhc->start           = whc_wusbhc_start;
	wusbhc->stop            = whc_wusbhc_stop;
	wusbhc->mmcie_add       = whc_mmcie_add;
	wusbhc->mmcie_rm        = whc_mmcie_rm;
	wusbhc->dev_info_set    = whc_dev_info_set;
	wusbhc->bwa_set         = whc_bwa_set;
	wusbhc->set_num_dnts    = whc_set_num_dnts;
	wusbhc->set_ptk         = whc_set_ptk;
	wusbhc->set_gtk         = whc_set_gtk;

	ret = wusbhc_create(wusbhc);
	if (ret)
		goto error_wusbhc_create;

	ret = usb_add_hcd(usb_hcd, whc->umc->irq, IRQF_SHARED);
	if (ret) {
		dev_err(dev, "cannot add HCD: %d\n", ret);
		goto error_usb_add_hcd;
	}
	device_wakeup_enable(usb_hcd->self.controller);

	ret = wusbhc_b_create(wusbhc);
	if (ret) {
		dev_err(dev, "WUSBHC phase B setup failed: %d\n", ret);
		goto error_wusbhc_b_create;
	}

	whc_dbg_init(whc);

	return 0;

error_wusbhc_b_create:
	usb_remove_hcd(usb_hcd);
error_usb_add_hcd:
	wusbhc_destroy(wusbhc);
error_wusbhc_create:
	uwb_rc_put(wusbhc->uwb_rc);
error_uwb_rc:
	whc_clean_up(whc);
error_whc_init:
	usb_put_hcd(usb_hcd);
	return ret;
}

__attribute__((used)) static void whc_remove(struct umc_dev *umc)
{
	struct usb_hcd *usb_hcd = dev_get_drvdata(&umc->dev);
	struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
	struct whc *whc = wusbhc_to_whc(wusbhc);

	if (usb_hcd) {
		whc_dbg_clean_up(whc);
		wusbhc_b_destroy(wusbhc);
		usb_remove_hcd(usb_hcd);
		wusbhc_destroy(wusbhc);
		uwb_rc_put(wusbhc->uwb_rc);
		whc_clean_up(whc);
		usb_put_hcd(usb_hcd);
	}
}

