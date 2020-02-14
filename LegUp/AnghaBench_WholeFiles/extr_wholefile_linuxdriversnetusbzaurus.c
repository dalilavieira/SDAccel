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
typedef  int u8 ;
typedef  int u32 ;
struct usbnet {int rx_urb_size; TYPE_3__* udev; TYPE_2__* net; } ;
struct usb_interface {int /*<<< orphan*/  dev; TYPE_1__* cur_altsetting; } ;
struct usb_cdc_mdlm_detail_desc {int bLength; int* bDetailData; int /*<<< orphan*/  bGuidDescriptorType; } ;
struct usb_cdc_mdlm_desc {int bLength; int /*<<< orphan*/  bGUID; } ;
struct sk_buff {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {int hard_header_len; int mtu; } ;
struct TYPE_4__ {int* extra; int extralen; } ;

/* Variables and functions */
 int ENODEV ; 
#define  USB_CDC_MDLM_DETAIL_TYPE 129 
#define  USB_CDC_MDLM_TYPE 128 
 int USB_DT_CS_INTERFACE ; 
 int /*<<< orphan*/  blan_guid ; 
 int crc32_le (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  safe_guid ; 
 int /*<<< orphan*/  skb_cloned (struct sk_buff*) ; 
 struct sk_buff* skb_copy_expand (struct sk_buff*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_put_u8 (struct sk_buff*,int) ; 
 int skb_tailroom (struct sk_buff*) ; 
 int usbnet_generic_cdc_bind (struct usbnet*,struct usb_interface*) ; 
 int usbnet_get_endpoints (struct usbnet*,struct usb_interface*) ; 

__attribute__((used)) static struct sk_buff *
zaurus_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
	int			padlen;
	struct sk_buff		*skb2;

	padlen = 2;
	if (!skb_cloned(skb)) {
		int	tailroom = skb_tailroom(skb);
		if ((padlen + 4) <= tailroom)
			goto done;
	}
	skb2 = skb_copy_expand(skb, 0, 4 + padlen, flags);
	dev_kfree_skb_any(skb);
	skb = skb2;
	if (skb) {
		u32		fcs;
done:
		fcs = crc32_le(~0, skb->data, skb->len);
		fcs = ~fcs;

		skb_put_u8(skb, fcs & 0xff);
		skb_put_u8(skb, (fcs >> 8) & 0xff);
		skb_put_u8(skb, (fcs >> 16) & 0xff);
		skb_put_u8(skb, (fcs >> 24) & 0xff);
	}
	return skb;
}

__attribute__((used)) static int zaurus_bind(struct usbnet *dev, struct usb_interface *intf)
{
	/* Belcarra's funky framing has other options; mostly
	 * TRAILERS (!) with 4 bytes CRC, and maybe 2 pad bytes.
	 */
	dev->net->hard_header_len += 6;
	dev->rx_urb_size = dev->net->hard_header_len + dev->net->mtu;
	return usbnet_generic_cdc_bind(dev, intf);
}

__attribute__((used)) static int always_connected (struct usbnet *dev)
{
	return 0;
}

__attribute__((used)) static int blan_mdlm_bind(struct usbnet *dev, struct usb_interface *intf)
{
	u8				*buf = intf->cur_altsetting->extra;
	int				len = intf->cur_altsetting->extralen;
	struct usb_cdc_mdlm_desc	*desc = NULL;
	struct usb_cdc_mdlm_detail_desc	*detail = NULL;

	while (len > 3) {
		if (buf [1] != USB_DT_CS_INTERFACE)
			goto next_desc;

		/* use bDescriptorSubType, and just verify that we get a
		 * "BLAN" (or "SAFE") descriptor.
		 */
		switch (buf [2]) {
		case USB_CDC_MDLM_TYPE:
			if (desc) {
				dev_dbg(&intf->dev, "extra MDLM\n");
				goto bad_desc;
			}
			desc = (void *) buf;
			if (desc->bLength != sizeof *desc) {
				dev_dbg(&intf->dev, "MDLM len %u\n",
					desc->bLength);
				goto bad_desc;
			}
			/* expect bcdVersion 1.0, ignore */
			if (memcmp(&desc->bGUID, blan_guid, 16) &&
			    memcmp(&desc->bGUID, safe_guid, 16)) {
				/* hey, this one might _really_ be MDLM! */
				dev_dbg(&intf->dev, "MDLM guid\n");
				goto bad_desc;
			}
			break;
		case USB_CDC_MDLM_DETAIL_TYPE:
			if (detail) {
				dev_dbg(&intf->dev, "extra MDLM detail\n");
				goto bad_desc;
			}
			detail = (void *) buf;
			switch (detail->bGuidDescriptorType) {
			case 0:			/* "SAFE" */
				if (detail->bLength != (sizeof *detail + 2))
					goto bad_detail;
				break;
			case 1:			/* "BLAN" */
				if (detail->bLength != (sizeof *detail + 3))
					goto bad_detail;
				break;
			default:
				goto bad_detail;
			}

			/* assuming we either noticed BLAN already, or will
			 * find it soon, there are some data bytes here:
			 *  - bmNetworkCapabilities (unused)
			 *  - bmDataCapabilities (bits, see below)
			 *  - bPad (ignored, for PADAFTER -- BLAN-only)
			 * bits are:
			 *  - 0x01 -- Zaurus framing (add CRC)
			 *  - 0x02 -- PADBEFORE (CRC includes some padding)
			 *  - 0x04 -- PADAFTER (some padding after CRC)
			 *  - 0x08 -- "fermat" packet mangling (for hw bugs)
			 * the PADBEFORE appears not to matter; we interop
			 * with devices that use it and those that don't.
			 */
			if ((detail->bDetailData[1] & ~0x02) != 0x01) {
				/* bmDataCapabilities == 0 would be fine too,
				 * but framing is minidriver-coupled for now.
				 */
bad_detail:
				dev_dbg(&intf->dev,
						"bad MDLM detail, %d %d %d\n",
						detail->bLength,
						detail->bDetailData[0],
						detail->bDetailData[2]);
				goto bad_desc;
			}

			/* same extra framing as for non-BLAN mode */
			dev->net->hard_header_len += 6;
			dev->rx_urb_size = dev->net->hard_header_len
					+ dev->net->mtu;
			break;
		}
next_desc:
		len -= buf [0];	/* bLength */
		buf += buf [0];
	}

	if (!desc || !detail) {
		dev_dbg(&intf->dev, "missing cdc mdlm %s%sdescriptor\n",
			desc ? "" : "func ",
			detail ? "" : "detail ");
		goto bad_desc;
	}

	/* There's probably a CDC Ethernet descriptor there, but we can't
	 * rely on the Ethernet address it provides since not all vendors
	 * bother to make it unique.  Likewise there's no point in tracking
	 * of the CDC event notifications.
	 */
	return usbnet_get_endpoints(dev, intf);

bad_desc:
	dev_info(&dev->udev->dev, "unsupported MDLM descriptors\n");
	return -ENODEV;
}

