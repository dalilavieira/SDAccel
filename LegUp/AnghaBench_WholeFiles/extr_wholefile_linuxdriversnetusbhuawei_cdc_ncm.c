#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct usbnet {int /*<<< orphan*/  data; TYPE_1__* status; TYPE_2__* intf; } ;
struct usb_interface {int dummy; } ;
struct usb_driver {int (* suspend ) (struct usb_interface*,int /*<<< orphan*/ ) ;int (* resume ) (struct usb_interface*) ;int /*<<< orphan*/  (* disconnect ) (struct usb_interface*) ;} ;
struct huawei_cdc_ncm_state {struct usb_driver* subdriver; struct cdc_ncm_ctx* ctx; int /*<<< orphan*/  pmcount; } ;
struct cdc_ncm_ctx {struct usb_interface* control; } ;
typedef  int /*<<< orphan*/  pm_message_t ;
struct TYPE_5__ {int needs_remote_wakeup; } ;
struct TYPE_4__ {int /*<<< orphan*/  desc; } ;

/* Variables and functions */
 int CDC_NCM_FLAG_NDP_TO_END ; 
 int CDC_NCM_FLAG_RESET_NTB16 ; 
 int ENODEV ; 
 struct usb_driver* ERR_PTR (int) ; 
 scalar_t__ IS_ERR (struct usb_driver*) ; 
 int /*<<< orphan*/  PMSG_SUSPEND ; 
 int PTR_ERR (struct usb_driver*) ; 
 int atomic_add_return (int,int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int cdc_ncm_bind_common (struct usbnet*,struct usb_interface*,int,int) ; 
 int /*<<< orphan*/  cdc_ncm_unbind (struct usbnet*,struct usb_interface*) ; 
 int /*<<< orphan*/  stub1 (struct usb_interface*) ; 
 int stub2 (struct usb_interface*,int /*<<< orphan*/ ) ; 
 int stub3 (struct usb_interface*) ; 
 int stub4 (struct usb_interface*,int /*<<< orphan*/ ) ; 
 int usb_autopm_get_interface (TYPE_2__*) ; 
 int /*<<< orphan*/  usb_autopm_put_interface (TYPE_2__*) ; 
 struct usb_driver* usb_cdc_wdm_register (struct usb_interface*,int /*<<< orphan*/ *,int,int (*) (struct usb_interface*,int)) ; 
 struct usbnet* usb_get_intfdata (struct usb_interface*) ; 
 int usbnet_resume (struct usb_interface*) ; 
 int usbnet_suspend (struct usb_interface*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int huawei_cdc_ncm_manage_power(struct usbnet *usbnet_dev, int on)
{
	struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
	int rv;

	if ((on && atomic_add_return(1, &drvstate->pmcount) == 1) ||
			(!on && atomic_dec_and_test(&drvstate->pmcount))) {
		rv = usb_autopm_get_interface(usbnet_dev->intf);
		usbnet_dev->intf->needs_remote_wakeup = on;
		if (!rv)
			usb_autopm_put_interface(usbnet_dev->intf);
	}
	return 0;
}

__attribute__((used)) static int huawei_cdc_ncm_wdm_manage_power(struct usb_interface *intf,
					   int status)
{
	struct usbnet *usbnet_dev = usb_get_intfdata(intf);

	/* can be called while disconnecting */
	if (!usbnet_dev)
		return 0;

	return huawei_cdc_ncm_manage_power(usbnet_dev, status);
}

__attribute__((used)) static int huawei_cdc_ncm_bind(struct usbnet *usbnet_dev,
			       struct usb_interface *intf)
{
	struct cdc_ncm_ctx *ctx;
	struct usb_driver *subdriver = ERR_PTR(-ENODEV);
	int ret = -ENODEV;
	struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
	int drvflags = 0;

	/* altsetting should always be 1 for NCM devices - so we hard-coded
	 * it here. Some huawei devices will need the NDP part of the NCM package to
	 * be at the end of the frame.
	 */
	drvflags |= CDC_NCM_FLAG_NDP_TO_END;

	/* Additionally, it has been reported that some Huawei E3372H devices, with
	 * firmware version 21.318.01.00.541, come out of reset in NTB32 format mode, hence
	 * needing to be set to the NTB16 one again.
	 */
	drvflags |= CDC_NCM_FLAG_RESET_NTB16;
	ret = cdc_ncm_bind_common(usbnet_dev, intf, 1, drvflags);
	if (ret)
		goto err;

	ctx = drvstate->ctx;

	if (usbnet_dev->status)
		/* The wMaxCommand buffer must be big enough to hold
		 * any message from the modem. Experience has shown
		 * that some replies are more than 256 bytes long
		 */
		subdriver = usb_cdc_wdm_register(ctx->control,
						 &usbnet_dev->status->desc,
						 1024, /* wMaxCommand */
						 huawei_cdc_ncm_wdm_manage_power);
	if (IS_ERR(subdriver)) {
		ret = PTR_ERR(subdriver);
		cdc_ncm_unbind(usbnet_dev, intf);
		goto err;
	}

	/* Prevent usbnet from using the status descriptor */
	usbnet_dev->status = NULL;

	drvstate->subdriver = subdriver;

err:
	return ret;
}

__attribute__((used)) static void huawei_cdc_ncm_unbind(struct usbnet *usbnet_dev,
				  struct usb_interface *intf)
{
	struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
	struct cdc_ncm_ctx *ctx = drvstate->ctx;

	if (drvstate->subdriver && drvstate->subdriver->disconnect)
		drvstate->subdriver->disconnect(ctx->control);
	drvstate->subdriver = NULL;

	cdc_ncm_unbind(usbnet_dev, intf);
}

__attribute__((used)) static int huawei_cdc_ncm_suspend(struct usb_interface *intf,
				  pm_message_t message)
{
	int ret = 0;
	struct usbnet *usbnet_dev = usb_get_intfdata(intf);
	struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
	struct cdc_ncm_ctx *ctx = drvstate->ctx;

	if (ctx == NULL) {
		ret = -ENODEV;
		goto error;
	}

	ret = usbnet_suspend(intf, message);
	if (ret < 0)
		goto error;

	if (intf == ctx->control &&
		drvstate->subdriver &&
		drvstate->subdriver->suspend)
		ret = drvstate->subdriver->suspend(intf, message);
	if (ret < 0)
		usbnet_resume(intf);

error:
	return ret;
}

__attribute__((used)) static int huawei_cdc_ncm_resume(struct usb_interface *intf)
{
	int ret = 0;
	struct usbnet *usbnet_dev = usb_get_intfdata(intf);
	struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
	bool callsub;
	struct cdc_ncm_ctx *ctx = drvstate->ctx;

	/* should we call subdriver's resume function? */
	callsub =
		(intf == ctx->control &&
		drvstate->subdriver &&
		drvstate->subdriver->resume);

	if (callsub)
		ret = drvstate->subdriver->resume(intf);
	if (ret < 0)
		goto err;
	ret = usbnet_resume(intf);
	if (ret < 0 && callsub)
		drvstate->subdriver->suspend(intf, PMSG_SUSPEND);
err:
	return ret;
}

