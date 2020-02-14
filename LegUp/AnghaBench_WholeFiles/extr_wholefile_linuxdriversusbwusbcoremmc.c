#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t u8 ;
struct wusb_ckhdid {int dummy; } ;
struct usb_hcd {scalar_t__ wireless; } ;
struct wusbhc {size_t mmcies_max; int (* mmcie_add ) (struct wusbhc*,size_t,size_t,unsigned int,struct wuie_hdr*) ;int (* mmcie_rm ) (struct wusbhc*,unsigned int) ;int (* start ) (struct wusbhc*) ;int active; int (* set_num_dnts ) (struct wusbhc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  mutex; int /*<<< orphan*/ * uwb_rc; int /*<<< orphan*/  pal; struct device* dev; struct wusb_ckhdid chid; int /*<<< orphan*/  dnts_num_slots; int /*<<< orphan*/  dnts_interval; int /*<<< orphan*/ * wuie_host_info; int /*<<< orphan*/  (* stop ) (struct wusbhc*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  mmcie_mutex; struct wuie_hdr** mmcie; struct wusb_port* port; struct usb_hcd usb_hcd; } ;
struct wusb_port {int dummy; } ;
struct wusb_dev {int /*<<< orphan*/  refcnt; } ;
struct wuie_hdr {int bIEIdentifier; } ;
struct usb_device {int devnum; int /*<<< orphan*/  wusb; int /*<<< orphan*/  dev; int /*<<< orphan*/  bus; } ;
struct device {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EBUSY ; 
 int ENOBUFS ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
#define  WUIE_ID_HOST_INFO 129 
#define  WUIE_ID_ISOCH_DISCARD 128 
 int /*<<< orphan*/  WUSB_CHANNEL_STOP_DELAY_MS ; 
 struct wusb_dev* __wusb_dev_get_by_usb_dev (struct wusbhc*,struct usb_device*) ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct wuie_hdr** kcalloc (size_t,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct wuie_hdr**) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (struct wusb_ckhdid const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct wusbhc*,size_t,size_t,unsigned int,struct wuie_hdr*) ; 
 int stub2 (struct wusbhc*,unsigned int) ; 
 int stub3 (struct wusbhc*) ; 
 int /*<<< orphan*/  stub4 (struct wusbhc*,int /*<<< orphan*/ ) ; 
 int stub5 (struct wusbhc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct usb_hcd* usb_get_hcd (struct usb_hcd*) ; 
 struct wusbhc* usb_hcd_to_wusbhc (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int uwb_radio_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uwb_radio_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uwb_rc_get_by_grandpa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uwb_rc_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wusb_ckhdid_zero ; 
 int /*<<< orphan*/  wusb_dev_destroy ; 
 int wusbhc_devconnect_start (struct wusbhc*) ; 
 int /*<<< orphan*/  wusbhc_devconnect_stop (struct wusbhc*) ; 
 int wusbhc_pal_register (struct wusbhc*) ; 
 int wusbhc_rsv_establish (struct wusbhc*) ; 
 int /*<<< orphan*/  wusbhc_rsv_terminate (struct wusbhc*) ; 
 int wusbhc_sec_start (struct wusbhc*) ; 
 int /*<<< orphan*/  wusbhc_sec_stop (struct wusbhc*) ; 

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

int wusbhc_mmcie_create(struct wusbhc *wusbhc)
{
	u8 mmcies = wusbhc->mmcies_max;
	wusbhc->mmcie = kcalloc(mmcies, sizeof(wusbhc->mmcie[0]), GFP_KERNEL);
	if (wusbhc->mmcie == NULL)
		return -ENOMEM;
	mutex_init(&wusbhc->mmcie_mutex);
	return 0;
}

void wusbhc_mmcie_destroy(struct wusbhc *wusbhc)
{
	kfree(wusbhc->mmcie);
}

int wusbhc_mmcie_set(struct wusbhc *wusbhc, u8 interval, u8 repeat_cnt,
		     struct wuie_hdr *wuie)
{
	int result = -ENOBUFS;
	unsigned handle, itr;

	/* Search a handle, taking into account the ordering */
	mutex_lock(&wusbhc->mmcie_mutex);
	switch (wuie->bIEIdentifier) {
	case WUIE_ID_HOST_INFO:
		/* Always last */
		handle = wusbhc->mmcies_max - 1;
		break;
	case WUIE_ID_ISOCH_DISCARD:
		dev_err(wusbhc->dev, "Special ordering case for WUIE ID 0x%x "
			"unimplemented\n", wuie->bIEIdentifier);
		result = -ENOSYS;
		goto error_unlock;
	default:
		/* search for it or find the last empty slot */
		handle = ~0;
		for (itr = 0; itr < wusbhc->mmcies_max - 1; itr++) {
			if (wusbhc->mmcie[itr] == wuie) {
				handle = itr;
				break;
			}
			if (wusbhc->mmcie[itr] == NULL)
				handle = itr;
		}
		if (handle == ~0)
			goto error_unlock;
	}
	result = (wusbhc->mmcie_add)(wusbhc, interval, repeat_cnt, handle,
				     wuie);
	if (result >= 0)
		wusbhc->mmcie[handle] = wuie;
error_unlock:
	mutex_unlock(&wusbhc->mmcie_mutex);
	return result;
}

void wusbhc_mmcie_rm(struct wusbhc *wusbhc, struct wuie_hdr *wuie)
{
	int result;
	unsigned handle, itr;

	mutex_lock(&wusbhc->mmcie_mutex);
	for (itr = 0; itr < wusbhc->mmcies_max; itr++) {
		if (wusbhc->mmcie[itr] == wuie) {
			handle = itr;
			goto found;
		}
	}
	mutex_unlock(&wusbhc->mmcie_mutex);
	return;

found:
	result = (wusbhc->mmcie_rm)(wusbhc, handle);
	if (result == 0)
		wusbhc->mmcie[itr] = NULL;
	mutex_unlock(&wusbhc->mmcie_mutex);
}

__attribute__((used)) static int wusbhc_mmc_start(struct wusbhc *wusbhc)
{
	int ret;

	mutex_lock(&wusbhc->mutex);
	ret = wusbhc->start(wusbhc);
	if (ret >= 0)
		wusbhc->active = 1;
	mutex_unlock(&wusbhc->mutex);

	return ret;
}

__attribute__((used)) static void wusbhc_mmc_stop(struct wusbhc *wusbhc)
{
	mutex_lock(&wusbhc->mutex);
	wusbhc->active = 0;
	wusbhc->stop(wusbhc, WUSB_CHANNEL_STOP_DELAY_MS);
	mutex_unlock(&wusbhc->mutex);
}

int wusbhc_start(struct wusbhc *wusbhc)
{
	int result;
	struct device *dev = wusbhc->dev;

	WARN_ON(wusbhc->wuie_host_info != NULL);
	BUG_ON(wusbhc->uwb_rc == NULL);

	result = wusbhc_rsv_establish(wusbhc);
	if (result < 0) {
		dev_err(dev, "cannot establish cluster reservation: %d\n",
			result);
		goto error_rsv_establish;
	}

	result = wusbhc_devconnect_start(wusbhc);
	if (result < 0) {
		dev_err(dev, "error enabling device connections: %d\n",
			result);
		goto error_devconnect_start;
	}

	result = wusbhc_sec_start(wusbhc);
	if (result < 0) {
		dev_err(dev, "error starting security in the HC: %d\n",
			result);
		goto error_sec_start;
	}

	result = wusbhc->set_num_dnts(wusbhc, wusbhc->dnts_interval,
		wusbhc->dnts_num_slots);
	if (result < 0) {
		dev_err(dev, "Cannot set DNTS parameters: %d\n", result);
		goto error_set_num_dnts;
	}
	result = wusbhc_mmc_start(wusbhc);
	if (result < 0) {
		dev_err(dev, "error starting wusbch: %d\n", result);
		goto error_wusbhc_start;
	}

	return 0;

error_wusbhc_start:
	wusbhc_sec_stop(wusbhc);
error_set_num_dnts:
error_sec_start:
	wusbhc_devconnect_stop(wusbhc);
error_devconnect_start:
	wusbhc_rsv_terminate(wusbhc);
error_rsv_establish:
	return result;
}

void wusbhc_stop(struct wusbhc *wusbhc)
{
	wusbhc_mmc_stop(wusbhc);
	wusbhc_sec_stop(wusbhc);
	wusbhc_devconnect_stop(wusbhc);
	wusbhc_rsv_terminate(wusbhc);
}

int wusbhc_chid_set(struct wusbhc *wusbhc, const struct wusb_ckhdid *chid)
{
	int result = 0;

	if (memcmp(chid, &wusb_ckhdid_zero, sizeof(*chid)) == 0)
		chid = NULL;

	mutex_lock(&wusbhc->mutex);
	if (chid) {
		if (wusbhc->active) {
			mutex_unlock(&wusbhc->mutex);
			return -EBUSY;
		}
		wusbhc->chid = *chid;
	}

	/* register with UWB if we haven't already since we are about to start
	    the radio. */
	if ((chid) && (wusbhc->uwb_rc == NULL)) {
		wusbhc->uwb_rc = uwb_rc_get_by_grandpa(wusbhc->dev->parent);
		if (wusbhc->uwb_rc == NULL) {
			result = -ENODEV;
			dev_err(wusbhc->dev,
				"Cannot get associated UWB Host Controller\n");
			goto error_rc_get;
		}

		result = wusbhc_pal_register(wusbhc);
		if (result < 0) {
			dev_err(wusbhc->dev, "Cannot register as a UWB PAL\n");
			goto error_pal_register;
		}
	}
	mutex_unlock(&wusbhc->mutex);

	if (chid)
		result = uwb_radio_start(&wusbhc->pal);
	else if (wusbhc->uwb_rc)
		uwb_radio_stop(&wusbhc->pal);

	return result;

error_pal_register:
	uwb_rc_put(wusbhc->uwb_rc);
	wusbhc->uwb_rc = NULL;
error_rc_get:
	mutex_unlock(&wusbhc->mutex);

	return result;
}

