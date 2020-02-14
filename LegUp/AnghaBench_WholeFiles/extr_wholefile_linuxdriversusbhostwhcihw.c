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
typedef  int u32 ;
struct usb_hcd {scalar_t__ wireless; } ;
struct wusbhc {int /*<<< orphan*/  mutex; struct wusb_port* port; struct usb_hcd usb_hcd; } ;
struct wusb_port {int dummy; } ;
struct wusb_dev {int /*<<< orphan*/  refcnt; } ;
struct whc_std {int ntds_remaining; } ;
struct whc {TYPE_1__* umc; struct wusbhc wusbhc; int /*<<< orphan*/  mutex; int /*<<< orphan*/  lock; scalar_t__ base; scalar_t__ gen_cmd_buf_dma; int /*<<< orphan*/  gen_cmd_buf; int /*<<< orphan*/  cmd_wq; } ;
struct usb_device {int devnum; int /*<<< orphan*/  wusb; int /*<<< orphan*/  dev; int /*<<< orphan*/  bus; } ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ETIMEDOUT ; 
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
 int /*<<< orphan*/  WHC_GENCMD_TIMEOUT_MS ; 
 scalar_t__ WUSBCMD ; 
 scalar_t__ WUSBGENADDR ; 
 scalar_t__ WUSBGENCMDPARAMS ; 
 scalar_t__ WUSBGENCMDSTS ; 
 int WUSBGENCMDSTS_ACTIVE ; 
 int WUSBGENCMDSTS_IOC ; 
 struct wusb_dev* __wusb_dev_get_by_usb_dev (struct wusbhc*,struct usb_device*) ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int le_readl (scalar_t__) ; 
 int /*<<< orphan*/  le_writel (int,scalar_t__) ; 
 int /*<<< orphan*/  le_writeq (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void*,size_t) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct usb_hcd* usb_get_hcd (struct usb_hcd*) ; 
 struct wusbhc* usb_hcd_to_wusbhc (struct usb_hcd*) ; 
 size_t usb_pipetype (unsigned int) ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wusb_dev_destroy ; 
 int /*<<< orphan*/  wusbhc_reset_all (struct wusbhc*) ; 

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

void whc_write_wusbcmd(struct whc *whc, u32 mask, u32 val)
{
	unsigned long flags;
	u32 cmd;

	spin_lock_irqsave(&whc->lock, flags);

	cmd = le_readl(whc->base + WUSBCMD);
	cmd = (cmd & ~mask) | val;
	le_writel(cmd, whc->base + WUSBCMD);

	spin_unlock_irqrestore(&whc->lock, flags);
}

int whc_do_gencmd(struct whc *whc, u32 cmd, u32 params, void *addr, size_t len)
{
	unsigned long flags;
	dma_addr_t dma_addr;
	int t;
	int ret = 0;

	mutex_lock(&whc->mutex);

	/* Wait for previous command to complete. */
	t = wait_event_timeout(whc->cmd_wq,
			       (le_readl(whc->base + WUSBGENCMDSTS) & WUSBGENCMDSTS_ACTIVE) == 0,
			       WHC_GENCMD_TIMEOUT_MS);
	if (t == 0) {
		dev_err(&whc->umc->dev, "generic command timeout (%04x/%04x)\n",
			le_readl(whc->base + WUSBGENCMDSTS),
			le_readl(whc->base + WUSBGENCMDPARAMS));
		ret = -ETIMEDOUT;
		goto out;
	}

	if (addr) {
		memcpy(whc->gen_cmd_buf, addr, len);
		dma_addr = whc->gen_cmd_buf_dma;
	} else
		dma_addr = 0;

	/* Poke registers to start cmd. */
	spin_lock_irqsave(&whc->lock, flags);

	le_writel(params, whc->base + WUSBGENCMDPARAMS);
	le_writeq(dma_addr, whc->base + WUSBGENADDR);

	le_writel(WUSBGENCMDSTS_ACTIVE | WUSBGENCMDSTS_IOC | cmd,
		  whc->base + WUSBGENCMDSTS);

	spin_unlock_irqrestore(&whc->lock, flags);
out:
	mutex_unlock(&whc->mutex);

	return ret;
}

void whc_hw_error(struct whc *whc, const char *reason)
{
	struct wusbhc *wusbhc = &whc->wusbhc;

	dev_err(&whc->umc->dev, "hardware error: %s\n", reason);
	wusbhc_reset_all(wusbhc);
}

