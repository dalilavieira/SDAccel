#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  scalar_t__ u32 ;
typedef  void* u16 ;
struct usb_hcd {scalar_t__ wireless; } ;
struct wusbhc {int /*<<< orphan*/  mutex; struct wusb_port* port; struct usb_hcd usb_hcd; } ;
struct wusb_port {int dummy; } ;
struct wusb_dev {int /*<<< orphan*/  refcnt; } ;
struct wahc {scalar_t__ status; int /*<<< orphan*/  wusb; int /*<<< orphan*/ * dti_buf; struct urb* dti_urb; int /*<<< orphan*/  dti_buf_size; int /*<<< orphan*/ * dti_epd; int /*<<< orphan*/ * dto_epd; int /*<<< orphan*/  quirks; TYPE_6__* usb_iface; int /*<<< orphan*/  usb_dev; scalar_t__ active_buf_in_urbs; int /*<<< orphan*/ * buf_in_urbs; int /*<<< orphan*/  xfer_id_count; scalar_t__ dto_in_use; int /*<<< orphan*/  xfer_error_work; int /*<<< orphan*/  xfer_enqueue_work; int /*<<< orphan*/  xfer_list_lock; int /*<<< orphan*/  xfer_errored_list; int /*<<< orphan*/  xfer_delayed_list; int /*<<< orphan*/  xfer_list; int /*<<< orphan*/  dti_edc; int /*<<< orphan*/  dti_state; int /*<<< orphan*/  notifs_queued; int /*<<< orphan*/  nep_edc; int /*<<< orphan*/  rpipe_mutex; int /*<<< orphan*/  rpipe_lock; int /*<<< orphan*/  rpipe_delayed_list; struct urb* nep_urb; int /*<<< orphan*/  nep_buffer_size; int /*<<< orphan*/  nep_buffer; } ;
struct wa_rpipe {int /*<<< orphan*/  seg_list; int /*<<< orphan*/  segs_available; int /*<<< orphan*/  refcnt; } ;
struct device {int dummy; } ;
struct usb_interface {TYPE_5__* cur_altsetting; struct device dev; } ;
struct usb_device {int devnum; int /*<<< orphan*/  wusb; int /*<<< orphan*/  dev; int /*<<< orphan*/  bus; } ;
struct urb {int /*<<< orphan*/  transfer_buffer_length; int /*<<< orphan*/  transfer_buffer; } ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  kernel_ulong_t ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_13__ {struct device dev; TYPE_2__* cur_altsetting; } ;
struct TYPE_10__ {int bNumEndpoints; } ;
struct TYPE_12__ {TYPE_4__* endpoint; TYPE_3__ desc; } ;
struct TYPE_11__ {int /*<<< orphan*/  desc; } ;
struct TYPE_8__ {int /*<<< orphan*/  bInterfaceNumber; } ;
struct TYPE_9__ {TYPE_1__ desc; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USB_CTRL_GET_TIMEOUT ; 
 int /*<<< orphan*/  USB_CTRL_SET_TIMEOUT ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_INTERFACE ; 
 int /*<<< orphan*/  USB_REQ_CLEAR_FEATURE ; 
 int /*<<< orphan*/  USB_REQ_GET_STATUS ; 
 int /*<<< orphan*/  USB_REQ_SET_FEATURE ; 
 int USB_TYPE_CLASS ; 
 int /*<<< orphan*/  WA_DTI_TRANSFER_RESULT_PENDING ; 
 void* WA_ENABLE ; 
 int WA_MAX_BUF_IN_URBS ; 
 struct wusb_dev* __wusb_dev_get_by_usb_dev (struct wusbhc*,struct usb_device*) ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 int /*<<< orphan*/  edc_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kmalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rpipe_destroy ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ ,scalar_t__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_endpoint_maxp (int /*<<< orphan*/ *) ; 
 struct usb_hcd* usb_get_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_get_intf (TYPE_6__*) ; 
 struct wusbhc* usb_hcd_to_wusbhc (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_init_urb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_kill_urb (struct urb*) ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_put_intf (TYPE_6__*) ; 
 int /*<<< orphan*/  usb_put_urb (struct urb*) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int usb_submit_urb (struct urb*,int /*<<< orphan*/ ) ; 
 int wa_nep_create (struct wahc*,struct usb_interface*) ; 
 int /*<<< orphan*/  wa_nep_destroy (struct wahc*) ; 
 int /*<<< orphan*/  wa_process_errored_transfers_run ; 
 int wa_rpipes_create (struct wahc*) ; 
 int /*<<< orphan*/  wa_rpipes_destroy (struct wahc*) ; 
 int /*<<< orphan*/  wa_urb_enqueue_run ; 
 int /*<<< orphan*/  wusb_dev_destroy ; 
 int /*<<< orphan*/  wusbhc_reset_all (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static inline int wa_nep_arm(struct wahc *wa, gfp_t gfp_mask)
{
	struct urb *urb = wa->nep_urb;
	urb->transfer_buffer = wa->nep_buffer;
	urb->transfer_buffer_length = wa->nep_buffer_size;
	return usb_submit_urb(urb, gfp_mask);
}

__attribute__((used)) static inline void wa_nep_disarm(struct wahc *wa)
{
	usb_kill_urb(wa->nep_urb);
}

__attribute__((used)) static inline void wa_rpipe_init(struct wahc *wa)
{
	INIT_LIST_HEAD(&wa->rpipe_delayed_list);
	spin_lock_init(&wa->rpipe_lock);
	mutex_init(&wa->rpipe_mutex);
}

__attribute__((used)) static inline void wa_init(struct wahc *wa)
{
	int index;

	edc_init(&wa->nep_edc);
	atomic_set(&wa->notifs_queued, 0);
	wa->dti_state = WA_DTI_TRANSFER_RESULT_PENDING;
	wa_rpipe_init(wa);
	edc_init(&wa->dti_edc);
	INIT_LIST_HEAD(&wa->xfer_list);
	INIT_LIST_HEAD(&wa->xfer_delayed_list);
	INIT_LIST_HEAD(&wa->xfer_errored_list);
	spin_lock_init(&wa->xfer_list_lock);
	INIT_WORK(&wa->xfer_enqueue_work, wa_urb_enqueue_run);
	INIT_WORK(&wa->xfer_error_work, wa_process_errored_transfers_run);
	wa->dto_in_use = 0;
	atomic_set(&wa->xfer_id_count, 1);
	/* init the buf in URBs */
	for (index = 0; index < WA_MAX_BUF_IN_URBS; ++index)
		usb_init_urb(&(wa->buf_in_urbs[index]));
	wa->active_buf_in_urbs = 0;
}

__attribute__((used)) static inline
void __rpipe_get(struct wa_rpipe *rpipe)
{
	kref_get(&rpipe->refcnt);
}

__attribute__((used)) static inline void rpipe_put(struct wa_rpipe *rpipe)
{
	kref_put(&rpipe->refcnt, rpipe_destroy);

}

__attribute__((used)) static inline void rpipe_avail_dec(struct wa_rpipe *rpipe)
{
	atomic_dec(&rpipe->segs_available);
}

__attribute__((used)) static inline int rpipe_avail_inc(struct wa_rpipe *rpipe)
{
	return atomic_inc_return(&rpipe->segs_available) > 0
		&& !list_empty(&rpipe->seg_list);
}

__attribute__((used)) static inline struct wahc *wa_get(struct wahc *wa)
{
	usb_get_intf(wa->usb_iface);
	return wa;
}

__attribute__((used)) static inline void wa_put(struct wahc *wa)
{
	usb_put_intf(wa->usb_iface);
}

__attribute__((used)) static inline int __wa_feature(struct wahc *wa, unsigned op, u16 feature)
{
	return usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
			op ? USB_REQ_SET_FEATURE : USB_REQ_CLEAR_FEATURE,
			USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
			feature,
			wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
			NULL, 0, USB_CTRL_SET_TIMEOUT);
}

__attribute__((used)) static inline int __wa_set_feature(struct wahc *wa, u16 feature)
{
	return  __wa_feature(wa, 1, feature);
}

__attribute__((used)) static inline int __wa_clear_feature(struct wahc *wa, u16 feature)
{
	return __wa_feature(wa, 0, feature);
}

__attribute__((used)) static inline
s32 __wa_get_status(struct wahc *wa)
{
	s32 result;
	result = usb_control_msg(
		wa->usb_dev, usb_rcvctrlpipe(wa->usb_dev, 0),
		USB_REQ_GET_STATUS,
		USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
		0, wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
		&wa->status, sizeof(wa->status), USB_CTRL_GET_TIMEOUT);
	if (result >= 0)
		result = wa->status;
	return result;
}

__attribute__((used)) static inline s32 __wa_wait_status(struct wahc *wa, u32 mask, u32 value)
{
	s32 result;
	unsigned loops = 10;
	do {
		msleep(50);
		result = __wa_get_status(wa);
		if ((result & mask) == value)
			break;
		if (loops-- == 0) {
			result = -ETIMEDOUT;
			break;
		}
	} while (result >= 0);
	return result;
}

__attribute__((used)) static inline int __wa_stop(struct wahc *wa)
{
	int result;
	struct device *dev = &wa->usb_iface->dev;

	result = __wa_clear_feature(wa, WA_ENABLE);
	if (result < 0 && result != -ENODEV) {
		dev_err(dev, "error commanding HC to stop: %d\n", result);
		goto out;
	}
	result = __wa_wait_status(wa, WA_ENABLE, 0);
	if (result < 0 && result != -ENODEV)
		dev_err(dev, "error waiting for HC to stop: %d\n", result);
out:
	return 0;
}

int wa_create(struct wahc *wa, struct usb_interface *iface,
	kernel_ulong_t quirks)
{
	int result;
	struct device *dev = &iface->dev;

	if (iface->cur_altsetting->desc.bNumEndpoints < 3)
		return -ENODEV;

	result = wa_rpipes_create(wa);
	if (result < 0)
		goto error_rpipes_create;
	wa->quirks = quirks;
	/* Fill up Data Transfer EP pointers */
	wa->dti_epd = &iface->cur_altsetting->endpoint[1].desc;
	wa->dto_epd = &iface->cur_altsetting->endpoint[2].desc;
	wa->dti_buf_size = usb_endpoint_maxp(wa->dti_epd);
	wa->dti_buf = kmalloc(wa->dti_buf_size, GFP_KERNEL);
	if (wa->dti_buf == NULL) {
		result = -ENOMEM;
		goto error_dti_buf_alloc;
	}
	result = wa_nep_create(wa, iface);
	if (result < 0) {
		dev_err(dev, "WA-CDS: can't initialize notif endpoint: %d\n",
			result);
		goto error_nep_create;
	}
	return 0;

error_nep_create:
	kfree(wa->dti_buf);
error_dti_buf_alloc:
	wa_rpipes_destroy(wa);
error_rpipes_create:
	return result;
}

void __wa_destroy(struct wahc *wa)
{
	if (wa->dti_urb) {
		usb_kill_urb(wa->dti_urb);
		usb_put_urb(wa->dti_urb);
	}
	kfree(wa->dti_buf);
	wa_nep_destroy(wa);
	wa_rpipes_destroy(wa);
}

void wa_reset_all(struct wahc *wa)
{
	/* FIXME: assuming HWA. */
	wusbhc_reset_all(wa->wusb);
}

