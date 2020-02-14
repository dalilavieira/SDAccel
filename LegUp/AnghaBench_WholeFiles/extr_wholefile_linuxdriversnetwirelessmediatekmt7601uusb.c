#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  usb_complete_t ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct usb_interface {int /*<<< orphan*/  dev; struct usb_host_interface* cur_altsetting; } ;
struct TYPE_8__ {unsigned int bNumEndpoints; } ;
struct usb_host_interface {TYPE_2__* endpoint; TYPE_1__ desc; } ;
struct usb_endpoint_descriptor {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct usb_device {int dummy; } ;
struct urb {struct completion* context; int /*<<< orphan*/  status; } ;
struct mt7601u_dma_buf {size_t len; TYPE_3__* urb; int /*<<< orphan*/  dma; int /*<<< orphan*/  buf; } ;
struct mt7601u_dev {int* in_eps; int const* vend_buf; int /*<<< orphan*/  state; int /*<<< orphan*/  hw; int /*<<< orphan*/  stat_wq; int /*<<< orphan*/  dev; void* out_max_packet; void** out_eps; void* in_max_packet; int /*<<< orphan*/  vendor_req_mutex; } ;
struct completion {int dummy; } ;
typedef  int /*<<< orphan*/  pm_message_t ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_10__ {int /*<<< orphan*/  transfer_flags; int /*<<< orphan*/  transfer_dma; } ;
struct TYPE_9__ {struct usb_endpoint_descriptor desc; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  ECONNRESET ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ESHUTDOWN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MT7601U_STATE_INITIALIZED ; 
 int /*<<< orphan*/  MT7601U_STATE_REMOVED ; 
 int MT_ASIC_VERSION ; 
 int MT_EFUSE_CTRL ; 
 int MT_EFUSE_CTRL_SEL ; 
 int MT_MAC_CSR0 ; 
 int MT_TX_BAND_CFG ; 
 int MT_VEND_BUF ; 
 int MT_VEND_DEV_MODE ; 
 int MT_VEND_DEV_MODE_RESET ; 
 int MT_VEND_MULTI_READ ; 
 int MT_VEND_REQ_MAX_RETRY ; 
 int /*<<< orphan*/  MT_VEND_REQ_TOUT_MS ; 
 int MT_VEND_WRITE ; 
 int /*<<< orphan*/  URB_NO_TRANSFER_DMA_MAP ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int const USB_RECIP_DEVICE ; 
 int const USB_TYPE_VENDOR ; 
 int USHRT_MAX ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*,int) ; 
 int __MT_EP_IN_MAX ; 
 int __MT_EP_OUT_MAX ; 
 int /*<<< orphan*/  complete (struct completion*) ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int const,int const,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int const* devm_kmalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int get_unaligned_le32 (int const*) ; 
 int /*<<< orphan*/  ieee80211_free_hw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_unregister_hw (int /*<<< orphan*/ ) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct mt7601u_dev* mt7601u_alloc_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mt7601u_burst_write_regs (struct mt7601u_dev*,int,void const*,int) ; 
 int /*<<< orphan*/  mt7601u_cleanup (struct mt7601u_dev*) ; 
 int mt7601u_init_hardware (struct mt7601u_dev*) ; 
 int mt7601u_register_device (struct mt7601u_dev*) ; 
 int mt7601u_rmc (struct mt7601u_dev*,int,int,int) ; 
 int mt7601u_rmw (struct mt7601u_dev*,int,int,int) ; 
 int mt7601u_rr (struct mt7601u_dev*,int) ; 
 int mt7601u_wait_asic_ready (struct mt7601u_dev*) ; 
 void mt7601u_wr (struct mt7601u_dev*,int const,int const) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct usb_interface* to_usb_interface (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_mt_submit_urb (struct mt7601u_dev*,TYPE_3__*) ; 
 int /*<<< orphan*/  trace_mt_vend_req (struct mt7601u_dev*,unsigned int const,int const,int const,int const,int const,void*,size_t const,int) ; 
 int /*<<< orphan*/  trace_reg_read (struct mt7601u_dev*,int,int) ; 
 int /*<<< orphan*/  trace_reg_write (struct mt7601u_dev*,int const,int const) ; 
 int /*<<< orphan*/  usb_alloc_coherent (struct usb_device*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_3__* usb_alloc_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int usb_control_msg (struct usb_device*,unsigned int const,int const,int const,int const,int const,void*,size_t const,int /*<<< orphan*/ ) ; 
 scalar_t__ usb_endpoint_is_bulk_in (struct usb_endpoint_descriptor*) ; 
 scalar_t__ usb_endpoint_is_bulk_out (struct usb_endpoint_descriptor*) ; 
 void* usb_endpoint_maxp (struct usb_endpoint_descriptor*) ; 
 void* usb_endpoint_num (struct usb_endpoint_descriptor*) ; 
 int /*<<< orphan*/  usb_fill_bulk_urb (TYPE_3__*,struct usb_device*,unsigned int,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  usb_free_coherent (struct usb_device*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_free_urb (TYPE_3__*) ; 
 struct usb_device* usb_get_dev (struct usb_device*) ; 
 struct mt7601u_dev* usb_get_intfdata (struct usb_interface*) ; 
 int /*<<< orphan*/  usb_put_dev (struct usb_device*) ; 
 unsigned int usb_rcvbulkpipe (struct usb_device*,int) ; 
 unsigned int usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_reset_device (struct usb_device*) ; 
 int /*<<< orphan*/  usb_set_intfdata (struct usb_interface*,struct mt7601u_dev*) ; 
 unsigned int usb_sndbulkpipe (struct usb_device*,void*) ; 
 unsigned int usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int usb_submit_urb (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 mt76_rr(struct mt7601u_dev *dev, u32 offset)
{
	return mt7601u_rr(dev, offset);
}

__attribute__((used)) static inline void mt76_wr(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt7601u_wr(dev, offset, val);
}

__attribute__((used)) static inline u32
mt76_rmw(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val)
{
	return mt7601u_rmw(dev, offset, mask, val);
}

__attribute__((used)) static inline u32 mt76_set(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt76_rmw(dev, offset, 0, val);
}

__attribute__((used)) static inline u32 mt76_clear(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt76_rmw(dev, offset, val, 0);
}

__attribute__((used)) static inline u32 mt7601u_mac_set_ctrlch(struct mt7601u_dev *dev, bool below)
{
	return mt7601u_rmc(dev, MT_TX_BAND_CFG, 1, below);
}

__attribute__((used)) static inline struct usb_device *mt7601u_to_usb_dev(struct mt7601u_dev *mt7601u)
{
	return interface_to_usbdev(to_usb_interface(mt7601u->dev));
}

__attribute__((used)) static inline bool mt7601u_urb_has_error(struct urb *urb)
{
	return urb->status &&
		urb->status != -ENOENT &&
		urb->status != -ECONNRESET &&
		urb->status != -ESHUTDOWN;
}

bool mt7601u_usb_alloc_buf(struct mt7601u_dev *dev, size_t len,
			   struct mt7601u_dma_buf *buf)
{
	struct usb_device *usb_dev = mt7601u_to_usb_dev(dev);

	buf->len = len;
	buf->urb = usb_alloc_urb(0, GFP_KERNEL);
	buf->buf = usb_alloc_coherent(usb_dev, buf->len, GFP_KERNEL, &buf->dma);

	return !buf->urb || !buf->buf;
}

void mt7601u_usb_free_buf(struct mt7601u_dev *dev, struct mt7601u_dma_buf *buf)
{
	struct usb_device *usb_dev = mt7601u_to_usb_dev(dev);

	usb_free_coherent(usb_dev, buf->len, buf->buf, buf->dma);
	usb_free_urb(buf->urb);
}

int mt7601u_usb_submit_buf(struct mt7601u_dev *dev, int dir, int ep_idx,
			   struct mt7601u_dma_buf *buf, gfp_t gfp,
			   usb_complete_t complete_fn, void *context)
{
	struct usb_device *usb_dev = mt7601u_to_usb_dev(dev);
	unsigned pipe;
	int ret;

	if (dir == USB_DIR_IN)
		pipe = usb_rcvbulkpipe(usb_dev, dev->in_eps[ep_idx]);
	else
		pipe = usb_sndbulkpipe(usb_dev, dev->out_eps[ep_idx]);

	usb_fill_bulk_urb(buf->urb, usb_dev, pipe, buf->buf, buf->len,
			  complete_fn, context);
	buf->urb->transfer_dma = buf->dma;
	buf->urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;

	trace_mt_submit_urb(dev, buf->urb);
	ret = usb_submit_urb(buf->urb, gfp);
	if (ret)
		dev_err(dev->dev, "Error: submit URB dir:%d ep:%d failed:%d\n",
			dir, ep_idx, ret);
	return ret;
}

void mt7601u_complete_urb(struct urb *urb)
{
	struct completion *cmpl = urb->context;

	complete(cmpl);
}

int mt7601u_vendor_request(struct mt7601u_dev *dev, const u8 req,
			   const u8 direction, const u16 val, const u16 offset,
			   void *buf, const size_t buflen)
{
	int i, ret;
	struct usb_device *usb_dev = mt7601u_to_usb_dev(dev);
	const u8 req_type = direction | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
	const unsigned int pipe = (direction == USB_DIR_IN) ?
		usb_rcvctrlpipe(usb_dev, 0) : usb_sndctrlpipe(usb_dev, 0);

	for (i = 0; i < MT_VEND_REQ_MAX_RETRY; i++) {
		ret = usb_control_msg(usb_dev, pipe, req, req_type,
				      val, offset, buf, buflen,
				      MT_VEND_REQ_TOUT_MS);
		trace_mt_vend_req(dev, pipe, req, req_type, val, offset,
				  buf, buflen, ret);

		if (ret == -ENODEV)
			set_bit(MT7601U_STATE_REMOVED, &dev->state);
		if (ret >= 0 || ret == -ENODEV)
			return ret;

		msleep(5);
	}

	dev_err(dev->dev, "Vendor request req:%02x off:%04x failed:%d\n",
		req, offset, ret);

	return ret;
}

void mt7601u_vendor_reset(struct mt7601u_dev *dev)
{
	mt7601u_vendor_request(dev, MT_VEND_DEV_MODE, USB_DIR_OUT,
			       MT_VEND_DEV_MODE_RESET, 0, NULL, 0);
}

__attribute__((used)) static u32 __mt7601u_rr(struct mt7601u_dev *dev, u32 offset)
{
	int ret;
	u32 val = ~0;

	WARN_ONCE(offset > USHRT_MAX, "read high off:%08x", offset);

	ret = mt7601u_vendor_request(dev, MT_VEND_MULTI_READ, USB_DIR_IN,
				     0, offset, dev->vend_buf, MT_VEND_BUF);
	if (ret == MT_VEND_BUF)
		val = get_unaligned_le32(dev->vend_buf);
	else if (ret > 0)
		dev_err(dev->dev, "Error: wrong size read:%d off:%08x\n",
			ret, offset);

	trace_reg_read(dev, offset, val);
	return val;
}

u32 mt7601u_rr(struct mt7601u_dev *dev, u32 offset)
{
	u32 ret;

	mutex_lock(&dev->vendor_req_mutex);
	ret = __mt7601u_rr(dev, offset);
	mutex_unlock(&dev->vendor_req_mutex);

	return ret;
}

__attribute__((used)) static int __mt7601u_vendor_single_wr(struct mt7601u_dev *dev, const u8 req,
				      const u16 offset, const u32 val)
{
	int ret = mt7601u_vendor_request(dev, req, USB_DIR_OUT,
					 val & 0xffff, offset, NULL, 0);
	if (!ret)
		ret = mt7601u_vendor_request(dev, req, USB_DIR_OUT,
					     val >> 16, offset + 2, NULL, 0);
	trace_reg_write(dev, offset, val);
	return ret;
}

int mt7601u_vendor_single_wr(struct mt7601u_dev *dev, const u8 req,
			     const u16 offset, const u32 val)
{
	int ret;

	mutex_lock(&dev->vendor_req_mutex);
	ret = __mt7601u_vendor_single_wr(dev, req, offset, val);
	mutex_unlock(&dev->vendor_req_mutex);

	return ret;
}

void mt7601u_wr(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	WARN_ONCE(offset > USHRT_MAX, "write high off:%08x", offset);

	mt7601u_vendor_single_wr(dev, MT_VEND_WRITE, offset, val);
}

u32 mt7601u_rmw(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val)
{
	mutex_lock(&dev->vendor_req_mutex);
	val |= __mt7601u_rr(dev, offset) & ~mask;
	__mt7601u_vendor_single_wr(dev, MT_VEND_WRITE, offset, val);
	mutex_unlock(&dev->vendor_req_mutex);

	return val;
}

u32 mt7601u_rmc(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val)
{
	u32 reg;

	mutex_lock(&dev->vendor_req_mutex);
	reg = __mt7601u_rr(dev, offset);
	val |= reg & ~mask;
	if (reg != val)
		__mt7601u_vendor_single_wr(dev, MT_VEND_WRITE,
					   offset, val);
	mutex_unlock(&dev->vendor_req_mutex);

	return val;
}

void mt7601u_wr_copy(struct mt7601u_dev *dev, u32 offset,
		     const void *data, int len)
{
	WARN_ONCE(offset & 3, "unaligned write copy off:%08x", offset);
	WARN_ONCE(len & 3, "short write copy off:%08x", offset);

	mt7601u_burst_write_regs(dev, offset, data, len / 4);
}

void mt7601u_addr_wr(struct mt7601u_dev *dev, const u32 offset, const u8 *addr)
{
	mt7601u_wr(dev, offset, get_unaligned_le32(addr));
	mt7601u_wr(dev, offset + 4, addr[4] | addr[5] << 8);
}

__attribute__((used)) static int mt7601u_assign_pipes(struct usb_interface *usb_intf,
				struct mt7601u_dev *dev)
{
	struct usb_endpoint_descriptor *ep_desc;
	struct usb_host_interface *intf_desc = usb_intf->cur_altsetting;
	unsigned i, ep_i = 0, ep_o = 0;

	BUILD_BUG_ON(sizeof(dev->in_eps) < __MT_EP_IN_MAX);
	BUILD_BUG_ON(sizeof(dev->out_eps) < __MT_EP_OUT_MAX);

	for (i = 0; i < intf_desc->desc.bNumEndpoints; i++) {
		ep_desc = &intf_desc->endpoint[i].desc;

		if (usb_endpoint_is_bulk_in(ep_desc) &&
		    ep_i++ < __MT_EP_IN_MAX) {
			dev->in_eps[ep_i - 1] = usb_endpoint_num(ep_desc);
			dev->in_max_packet = usb_endpoint_maxp(ep_desc);
			/* Note: this is ignored by usb sub-system but vendor
			 *	 code does it. We can drop this at some point.
			 */
			dev->in_eps[ep_i - 1] |= USB_DIR_IN;
		} else if (usb_endpoint_is_bulk_out(ep_desc) &&
			   ep_o++ < __MT_EP_OUT_MAX) {
			dev->out_eps[ep_o - 1] = usb_endpoint_num(ep_desc);
			dev->out_max_packet = usb_endpoint_maxp(ep_desc);
		}
	}

	if (ep_i != __MT_EP_IN_MAX || ep_o != __MT_EP_OUT_MAX) {
		dev_err(dev->dev, "Error: wrong pipe number in:%d out:%d\n",
			ep_i, ep_o);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int mt7601u_probe(struct usb_interface *usb_intf,
			 const struct usb_device_id *id)
{
	struct usb_device *usb_dev = interface_to_usbdev(usb_intf);
	struct mt7601u_dev *dev;
	u32 asic_rev, mac_rev;
	int ret;

	dev = mt7601u_alloc_device(&usb_intf->dev);
	if (!dev)
		return -ENOMEM;

	usb_dev = usb_get_dev(usb_dev);
	usb_reset_device(usb_dev);

	usb_set_intfdata(usb_intf, dev);

	dev->vend_buf = devm_kmalloc(dev->dev, MT_VEND_BUF, GFP_KERNEL);
	if (!dev->vend_buf) {
		ret = -ENOMEM;
		goto err;
	}

	ret = mt7601u_assign_pipes(usb_intf, dev);
	if (ret)
		goto err;
	ret = mt7601u_wait_asic_ready(dev);
	if (ret)
		goto err;

	asic_rev = mt7601u_rr(dev, MT_ASIC_VERSION);
	mac_rev = mt7601u_rr(dev, MT_MAC_CSR0);
	dev_info(dev->dev, "ASIC revision: %08x MAC revision: %08x\n",
		 asic_rev, mac_rev);

	/* Note: vendor driver skips this check for MT7601U */
	if (!(mt7601u_rr(dev, MT_EFUSE_CTRL) & MT_EFUSE_CTRL_SEL))
		dev_warn(dev->dev, "Warning: eFUSE not present\n");

	ret = mt7601u_init_hardware(dev);
	if (ret)
		goto err;
	ret = mt7601u_register_device(dev);
	if (ret)
		goto err_hw;

	set_bit(MT7601U_STATE_INITIALIZED, &dev->state);

	return 0;
err_hw:
	mt7601u_cleanup(dev);
err:
	usb_set_intfdata(usb_intf, NULL);
	usb_put_dev(interface_to_usbdev(usb_intf));

	destroy_workqueue(dev->stat_wq);
	ieee80211_free_hw(dev->hw);
	return ret;
}

__attribute__((used)) static void mt7601u_disconnect(struct usb_interface *usb_intf)
{
	struct mt7601u_dev *dev = usb_get_intfdata(usb_intf);

	ieee80211_unregister_hw(dev->hw);
	mt7601u_cleanup(dev);

	usb_set_intfdata(usb_intf, NULL);
	usb_put_dev(interface_to_usbdev(usb_intf));

	destroy_workqueue(dev->stat_wq);
	ieee80211_free_hw(dev->hw);
}

__attribute__((used)) static int mt7601u_suspend(struct usb_interface *usb_intf, pm_message_t state)
{
	struct mt7601u_dev *dev = usb_get_intfdata(usb_intf);

	mt7601u_cleanup(dev);

	return 0;
}

__attribute__((used)) static int mt7601u_resume(struct usb_interface *usb_intf)
{
	struct mt7601u_dev *dev = usb_get_intfdata(usb_intf);
	int ret;

	ret = mt7601u_init_hardware(dev);
	if (ret)
		return ret;

	set_bit(MT7601U_STATE_INITIALIZED, &dev->state);

	return 0;
}

