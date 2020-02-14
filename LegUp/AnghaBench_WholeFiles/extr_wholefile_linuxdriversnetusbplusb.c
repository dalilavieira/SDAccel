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
typedef  int u8 ;
struct usbnet {int /*<<< orphan*/  net; } ;

/* Variables and functions */
 int PL_PEER_E ; 
 int PL_RESET_IN ; 
 int PL_RESET_OUT ; 
 int PL_S_EN ; 
 int USB_DIR_IN ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  link ; 
 int /*<<< orphan*/  netif_dbg (struct usbnet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ netif_msg_probe (struct usbnet*) ; 
 int usbnet_read_cmd (struct usbnet*,int,int,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int
pl_vendor_req(struct usbnet *dev, u8 req, u8 val, u8 index)
{
	return usbnet_read_cmd(dev, req,
				USB_DIR_IN | USB_TYPE_VENDOR |
				USB_RECIP_DEVICE,
				val, index, NULL, 0);
}

__attribute__((used)) static inline int
pl_clear_QuickLink_features(struct usbnet *dev, int val)
{
	return pl_vendor_req(dev, 1, (u8) val, 0);
}

__attribute__((used)) static inline int
pl_set_QuickLink_features(struct usbnet *dev, int val)
{
	return pl_vendor_req(dev, 3, (u8) val, 0);
}

__attribute__((used)) static int pl_reset(struct usbnet *dev)
{
	int status;

	/* some units seem to need this reset, others reject it utterly.
	 * FIXME be more like "naplink" or windows drivers.
	 */
	status = pl_set_QuickLink_features(dev,
		PL_S_EN|PL_RESET_OUT|PL_RESET_IN|PL_PEER_E);
	if (status != 0 && netif_msg_probe(dev))
		netif_dbg(dev, link, dev->net, "pl_reset --> %d\n", status);
	return 0;
}

