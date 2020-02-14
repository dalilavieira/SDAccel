#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct usb_hcd {scalar_t__ wireless; } ;
struct wusbhc {int /*<<< orphan*/  mutex; struct wusb_port* port; struct usb_hcd usb_hcd; } ;
struct wusb_port {int dummy; } ;
struct wusb_dev {int /*<<< orphan*/  refcnt; } ;
struct whc_std {int ntds_remaining; } ;
struct whc_qset {int dummy; } ;
struct whc {int n_devices; int /*<<< orphan*/ * workqueue; scalar_t__ base_phys; scalar_t__ base; TYPE_1__* umc; int /*<<< orphan*/ * qset_pool; int /*<<< orphan*/  gen_cmd_buf_dma; TYPE_3__* gen_cmd_buf; int /*<<< orphan*/  dn_buf_dma; TYPE_3__* dn_buf; int /*<<< orphan*/  di_buf_dma; TYPE_3__* di_buf; int /*<<< orphan*/  n_mmc_ies; int /*<<< orphan*/  n_keys; int /*<<< orphan*/  periodic_removed_list; int /*<<< orphan*/ * periodic_list; int /*<<< orphan*/  periodic_work; int /*<<< orphan*/  async_removed_list; int /*<<< orphan*/  async_list; int /*<<< orphan*/  async_work; int /*<<< orphan*/  dn_work; int /*<<< orphan*/  periodic_list_wq; int /*<<< orphan*/  async_list_wq; int /*<<< orphan*/  cmd_wq; int /*<<< orphan*/  mutex; int /*<<< orphan*/  lock; } ;
struct usb_device {int devnum; int /*<<< orphan*/  wusb; int /*<<< orphan*/  dev; int /*<<< orphan*/  bus; } ;
struct dn_buf_entry {int dummy; } ;
struct di_buf_entry {int dummy; } ;
typedef  scalar_t__ resource_size_t ;
struct TYPE_7__ {int /*<<< orphan*/  addr_sec_info; } ;
struct TYPE_6__ {scalar_t__ end; scalar_t__ start; } ;
struct TYPE_5__ {TYPE_2__ resource; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
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
 scalar_t__ WHCSPARAMS ; 
 int WHCSPARAMS_TO_N_DEVICES (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WHCSPARAMS_TO_N_KEYS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WHCSPARAMS_TO_N_MMC_IES (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WHC_DI_DISABLE ; 
 int WHC_GEN_CMD_DATA_LEN ; 
 int WHC_N_DN_ENTRIES ; 
 scalar_t__ WUSBCMD ; 
 int /*<<< orphan*/  WUSBCMD_WHCRESET ; 
 scalar_t__ WUSBDEVICEINFOADDR ; 
 scalar_t__ WUSBDNTSBUFADDR ; 
 struct wusb_dev* __wusb_dev_get_by_usb_dev (struct wusbhc*,struct usb_device*) ; 
 int /*<<< orphan*/ * alloc_ordered_workqueue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  asl_clean_up (struct whc*) ; 
 int asl_init (struct whc*) ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * dma_pool_create (char*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_pool_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 scalar_t__ ioremap (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le_readl (scalar_t__) ; 
 int /*<<< orphan*/  le_writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  le_writeq (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pzl_clean_up (struct whc*) ; 
 int pzl_init (struct whc*) ; 
 int /*<<< orphan*/  release_mem_region (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  request_mem_region (scalar_t__,scalar_t__,char*) ; 
 scalar_t__ resource_size (TYPE_2__*) ; 
 int /*<<< orphan*/  scan_async_work ; 
 int /*<<< orphan*/  scan_periodic_work ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 struct usb_hcd* usb_get_hcd (struct usb_hcd*) ; 
 struct wusbhc* usb_hcd_to_wusbhc (struct usb_hcd*) ; 
 size_t usb_pipetype (unsigned int) ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 void whc_clean_up (struct whc*) ; 
 int /*<<< orphan*/  whc_dn_work ; 
 int /*<<< orphan*/  whci_wait_for (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  wusb_dev_destroy ; 

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

__attribute__((used)) static void whc_hw_reset(struct whc *whc)
{
	le_writel(WUSBCMD_WHCRESET, whc->base + WUSBCMD);
	whci_wait_for(&whc->umc->dev, whc->base + WUSBCMD, WUSBCMD_WHCRESET, 0,
		      100, "reset");
}

__attribute__((used)) static void whc_hw_init_di_buf(struct whc *whc)
{
	int d;

	/* Disable all entries in the Device Information buffer. */
	for (d = 0; d < whc->n_devices; d++)
		whc->di_buf[d].addr_sec_info = WHC_DI_DISABLE;

	le_writeq(whc->di_buf_dma, whc->base + WUSBDEVICEINFOADDR);
}

__attribute__((used)) static void whc_hw_init_dn_buf(struct whc *whc)
{
	/* Clear the Device Notification buffer to ensure the V (valid)
	 * bits are clear.  */
	memset(whc->dn_buf, 0, 4096);

	le_writeq(whc->dn_buf_dma, whc->base + WUSBDNTSBUFADDR);
}

int whc_init(struct whc *whc)
{
	u32 whcsparams;
	int ret, i;
	resource_size_t start, len;

	spin_lock_init(&whc->lock);
	mutex_init(&whc->mutex);
	init_waitqueue_head(&whc->cmd_wq);
	init_waitqueue_head(&whc->async_list_wq);
	init_waitqueue_head(&whc->periodic_list_wq);
	whc->workqueue = alloc_ordered_workqueue(dev_name(&whc->umc->dev), 0);
	if (whc->workqueue == NULL) {
		ret = -ENOMEM;
		goto error;
	}
	INIT_WORK(&whc->dn_work, whc_dn_work);

	INIT_WORK(&whc->async_work, scan_async_work);
	INIT_LIST_HEAD(&whc->async_list);
	INIT_LIST_HEAD(&whc->async_removed_list);

	INIT_WORK(&whc->periodic_work, scan_periodic_work);
	for (i = 0; i < 5; i++)
		INIT_LIST_HEAD(&whc->periodic_list[i]);
	INIT_LIST_HEAD(&whc->periodic_removed_list);

	/* Map HC registers. */
	start = whc->umc->resource.start;
	len   = whc->umc->resource.end - start + 1;
	if (!request_mem_region(start, len, "whci-hc")) {
		dev_err(&whc->umc->dev, "can't request HC region\n");
		ret = -EBUSY;
		goto error;
	}
	whc->base_phys = start;
	whc->base = ioremap(start, len);
	if (!whc->base) {
		dev_err(&whc->umc->dev, "ioremap\n");
		ret = -ENOMEM;
		goto error;
	}

	whc_hw_reset(whc);

	/* Read maximum number of devices, keys and MMC IEs. */
	whcsparams = le_readl(whc->base + WHCSPARAMS);
	whc->n_devices = WHCSPARAMS_TO_N_DEVICES(whcsparams);
	whc->n_keys    = WHCSPARAMS_TO_N_KEYS(whcsparams);
	whc->n_mmc_ies = WHCSPARAMS_TO_N_MMC_IES(whcsparams);

	dev_dbg(&whc->umc->dev, "N_DEVICES = %d, N_KEYS = %d, N_MMC_IES = %d\n",
		whc->n_devices, whc->n_keys, whc->n_mmc_ies);

	whc->qset_pool = dma_pool_create("qset", &whc->umc->dev,
					 sizeof(struct whc_qset), 64, 0);
	if (whc->qset_pool == NULL) {
		ret = -ENOMEM;
		goto error;
	}

	ret = asl_init(whc);
	if (ret < 0)
		goto error;
	ret = pzl_init(whc);
	if (ret < 0)
		goto error;

	/* Allocate and initialize a buffer for generic commands, the
	   Device Information buffer, and the Device Notification
	   buffer. */

	whc->gen_cmd_buf = dma_alloc_coherent(&whc->umc->dev, WHC_GEN_CMD_DATA_LEN,
					      &whc->gen_cmd_buf_dma, GFP_KERNEL);
	if (whc->gen_cmd_buf == NULL) {
		ret = -ENOMEM;
		goto error;
	}

	whc->dn_buf = dma_alloc_coherent(&whc->umc->dev,
					 sizeof(struct dn_buf_entry) * WHC_N_DN_ENTRIES,
					 &whc->dn_buf_dma, GFP_KERNEL);
	if (!whc->dn_buf) {
		ret = -ENOMEM;
		goto error;
	}
	whc_hw_init_dn_buf(whc);

	whc->di_buf = dma_alloc_coherent(&whc->umc->dev,
					 sizeof(struct di_buf_entry) * whc->n_devices,
					 &whc->di_buf_dma, GFP_KERNEL);
	if (!whc->di_buf) {
		ret = -ENOMEM;
		goto error;
	}
	whc_hw_init_di_buf(whc);

	return 0;

error:
	whc_clean_up(whc);
	return ret;
}

void whc_clean_up(struct whc *whc)
{
	resource_size_t len;

	if (whc->di_buf)
		dma_free_coherent(&whc->umc->dev, sizeof(struct di_buf_entry) * whc->n_devices,
				  whc->di_buf, whc->di_buf_dma);
	if (whc->dn_buf)
		dma_free_coherent(&whc->umc->dev, sizeof(struct dn_buf_entry) * WHC_N_DN_ENTRIES,
				  whc->dn_buf, whc->dn_buf_dma);
	if (whc->gen_cmd_buf)
		dma_free_coherent(&whc->umc->dev, WHC_GEN_CMD_DATA_LEN,
				  whc->gen_cmd_buf, whc->gen_cmd_buf_dma);

	pzl_clean_up(whc);
	asl_clean_up(whc);

	dma_pool_destroy(whc->qset_pool);

	len   = resource_size(&whc->umc->resource);
	if (whc->base)
		iounmap(whc->base);
	if (whc->base_phys)
		release_mem_region(whc->base_phys, len);

	if (whc->workqueue)
		destroy_workqueue(whc->workqueue);
}

