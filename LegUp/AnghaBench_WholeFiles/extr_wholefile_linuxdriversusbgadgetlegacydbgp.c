#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_9__ ;
typedef  struct TYPE_13__   TYPE_8__ ;
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct usb_request {int length; int zero; void (* complete ) (struct usb_ep*,struct usb_request*) ;int /*<<< orphan*/  buf; int /*<<< orphan*/  actual; int /*<<< orphan*/  status; } ;
struct usb_gadget_driver {int dummy; } ;
struct usb_gadget {int /*<<< orphan*/  dev; TYPE_1__* ep0; } ;
struct usb_ep {int dummy; } ;
struct usb_ctrlrequest {int bRequest; int /*<<< orphan*/  wLength; int /*<<< orphan*/  wValue; } ;
struct TYPE_14__ {int /*<<< orphan*/  bDebugOutEndpoint; int /*<<< orphan*/  bDebugInEndpoint; } ;
struct TYPE_13__ {struct usb_gadget* gadget; int /*<<< orphan*/  serial; struct usb_request* req; void* o_ep; void* i_ep; } ;
struct TYPE_12__ {int /*<<< orphan*/  bMaxPacketSize0; } ;
struct TYPE_11__ {int /*<<< orphan*/  bEndpointAddress; void* wMaxPacketSize; } ;
struct TYPE_10__ {int /*<<< orphan*/  maxpacket; } ;

/* Variables and functions */
 int DBGP_REQ_EP0_LEN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  USB_DEBUG_MAX_PACKET_SIZE ; 
 int USB_DEVICE_DEBUG_MODE ; 
#define  USB_DT_DEBUG 129 
#define  USB_DT_DEVICE 128 
 int USB_REQ_GET_DESCRIPTOR ; 
 int USB_REQ_SET_FEATURE ; 
 void* cpu_to_le16 (int /*<<< orphan*/ ) ; 
 TYPE_9__ dbg_desc ; 
 TYPE_8__ dbgp ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 TYPE_7__ device_desc ; 
 int gserial_connect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gserial_disconnect (int /*<<< orphan*/ ) ; 
 TYPE_3__ i_desc ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmalloc (int,int /*<<< orphan*/ ) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void*,int) ; 
 int min (int,int) ; 
 TYPE_3__ o_desc ; 
 int /*<<< orphan*/  tty_line ; 
 struct usb_request* usb_ep_alloc_request (TYPE_1__*,int /*<<< orphan*/ ) ; 
 void* usb_ep_autoconfig (struct usb_gadget*,TYPE_3__*) ; 
 int /*<<< orphan*/  usb_ep_autoconfig_reset (struct usb_gadget*) ; 
 int /*<<< orphan*/  usb_ep_free_request (TYPE_1__*,struct usb_request*) ; 
 int usb_ep_queue (TYPE_1__*,struct usb_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dbgp_disconnect(struct usb_gadget *gadget)
{
#ifdef CONFIG_USB_G_DBGP_PRINTK
	dbgp_disable_ep();
#else
	gserial_disconnect(dbgp.serial);
#endif
}

__attribute__((used)) static void dbgp_unbind(struct usb_gadget *gadget)
{
#ifdef CONFIG_USB_G_DBGP_SERIAL
	kfree(dbgp.serial);
	dbgp.serial = NULL;
#endif
	if (dbgp.req) {
		kfree(dbgp.req->buf);
		usb_ep_free_request(gadget->ep0, dbgp.req);
		dbgp.req = NULL;
	}
}

__attribute__((used)) static int dbgp_configure_endpoints(struct usb_gadget *gadget)
{
	int stp;

	usb_ep_autoconfig_reset(gadget);

	dbgp.i_ep = usb_ep_autoconfig(gadget, &i_desc);
	if (!dbgp.i_ep) {
		stp = 1;
		goto fail_1;
	}

	i_desc.wMaxPacketSize =
		cpu_to_le16(USB_DEBUG_MAX_PACKET_SIZE);

	dbgp.o_ep = usb_ep_autoconfig(gadget, &o_desc);
	if (!dbgp.o_ep) {
		stp = 2;
		goto fail_1;
	}

	o_desc.wMaxPacketSize =
		cpu_to_le16(USB_DEBUG_MAX_PACKET_SIZE);

	dbg_desc.bDebugInEndpoint = i_desc.bEndpointAddress;
	dbg_desc.bDebugOutEndpoint = o_desc.bEndpointAddress;

#ifdef CONFIG_USB_G_DBGP_SERIAL
	dbgp.serial->in = dbgp.i_ep;
	dbgp.serial->out = dbgp.o_ep;

	dbgp.serial->in->desc = &i_desc;
	dbgp.serial->out->desc = &o_desc;
#endif

	return 0;

fail_1:
	dev_dbg(&dbgp.gadget->dev, "ep config: failure (%d)\n", stp);
	return -ENODEV;
}

__attribute__((used)) static int dbgp_bind(struct usb_gadget *gadget,
		struct usb_gadget_driver *driver)
{
	int err, stp;

	dbgp.gadget = gadget;

	dbgp.req = usb_ep_alloc_request(gadget->ep0, GFP_KERNEL);
	if (!dbgp.req) {
		err = -ENOMEM;
		stp = 1;
		goto fail;
	}

	dbgp.req->buf = kmalloc(DBGP_REQ_EP0_LEN, GFP_KERNEL);
	if (!dbgp.req->buf) {
		err = -ENOMEM;
		stp = 2;
		goto fail;
	}

	dbgp.req->length = DBGP_REQ_EP0_LEN;

#ifdef CONFIG_USB_G_DBGP_SERIAL
	dbgp.serial = kzalloc(sizeof(struct gserial), GFP_KERNEL);
	if (!dbgp.serial) {
		stp = 3;
		err = -ENOMEM;
		goto fail;
	}

	if (gserial_alloc_line(&tty_line)) {
		stp = 4;
		err = -ENODEV;
		goto fail;
	}
#endif

	err = dbgp_configure_endpoints(gadget);
	if (err < 0) {
		stp = 5;
		goto fail;
	}

	dev_dbg(&dbgp.gadget->dev, "bind: success\n");
	return 0;

fail:
	dev_dbg(&gadget->dev, "bind: failure (%d:%d)\n", stp, err);
	dbgp_unbind(gadget);
	return err;
}

__attribute__((used)) static void dbgp_setup_complete(struct usb_ep *ep,
				struct usb_request *req)
{
	dev_dbg(&dbgp.gadget->dev, "setup complete: %d, %d/%d\n",
		req->status, req->actual, req->length);
}

__attribute__((used)) static int dbgp_setup(struct usb_gadget *gadget,
		      const struct usb_ctrlrequest *ctrl)
{
	struct usb_request *req = dbgp.req;
	u8 request = ctrl->bRequest;
	u16 value = le16_to_cpu(ctrl->wValue);
	u16 length = le16_to_cpu(ctrl->wLength);
	int err = -EOPNOTSUPP;
	void *data = NULL;
	u16 len = 0;

	if (request == USB_REQ_GET_DESCRIPTOR) {
		switch (value>>8) {
		case USB_DT_DEVICE:
			dev_dbg(&dbgp.gadget->dev, "setup: desc device\n");
			len = sizeof device_desc;
			data = &device_desc;
			device_desc.bMaxPacketSize0 = gadget->ep0->maxpacket;
			break;
		case USB_DT_DEBUG:
			dev_dbg(&dbgp.gadget->dev, "setup: desc debug\n");
			len = sizeof dbg_desc;
			data = &dbg_desc;
			break;
		default:
			goto fail;
		}
		err = 0;
	} else if (request == USB_REQ_SET_FEATURE &&
		   value == USB_DEVICE_DEBUG_MODE) {
		dev_dbg(&dbgp.gadget->dev, "setup: feat debug\n");
#ifdef CONFIG_USB_G_DBGP_PRINTK
		err = dbgp_enable_ep();
#else
		err = dbgp_configure_endpoints(gadget);
		if (err < 0) {
			goto fail;
		}
		err = gserial_connect(dbgp.serial, tty_line);
#endif
		if (err < 0)
			goto fail;
	} else
		goto fail;

	req->length = min(length, len);
	req->zero = len < req->length;
	if (data && req->length)
		memcpy(req->buf, data, req->length);

	req->complete = dbgp_setup_complete;
	return usb_ep_queue(gadget->ep0, req, GFP_ATOMIC);

fail:
	dev_dbg(&dbgp.gadget->dev,
		"setup: failure req %x v %x\n", request, value);
	return err;
}

