#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct usb_interface {TYPE_5__* cur_altsetting; } ;
struct usb_device_id {int dummy; } ;
struct usb_device {int speed; int /*<<< orphan*/  dev; } ;
struct urb {int transfer_buffer_length; int number_of_packets; int* transfer_buffer; void (* complete ) (struct urb*) ;int interval; TYPE_6__* iso_frame_desc; int /*<<< orphan*/  transfer_flags; int /*<<< orphan*/  pipe; struct flexcop_usb* context; struct usb_device* dev; int /*<<< orphan*/  actual_length; } ;
struct flexcop_usb {int* data; int tmp_buffer_length; int* tmp_buffer; int* iso_buffer; int buffer_size; struct flexcop_device* fc_dev; struct usb_interface* uintf; struct usb_device* udev; int /*<<< orphan*/  data_mutex; struct urb** iso_urb; int /*<<< orphan*/  dma_addr; } ;
struct flexcop_i2c_adapter {int port; TYPE_2__* fc; } ;
struct TYPE_10__ {int* proposed_mac; } ;
struct flexcop_device {int (* write_ibi_reg ) (struct flexcop_device*,int,TYPE_7__) ;int (* i2c_request ) (struct flexcop_i2c_adapter*,scalar_t__,int,int,int*,int) ;int (* get_mac_addr ) (struct flexcop_device*,int) ;int (* stream_control ) (struct flexcop_device*,int) ;int pid_filtering; int /*<<< orphan*/  owner; int /*<<< orphan*/ * dev; int /*<<< orphan*/  bus_type; TYPE_7__ (* read_ibi_reg ) (struct flexcop_device*,int) ;struct flexcop_usb* bus_specific; TYPE_1__ dvb_adapter; } ;
typedef  int flexcop_usb_request_t ;
typedef  int flexcop_usb_mem_page_t ;
typedef  int flexcop_usb_i2c_function_t ;
struct TYPE_16__ {int raw; } ;
typedef  TYPE_7__ flexcop_ibi_value ;
typedef  int flexcop_ibi_register ;
typedef  scalar_t__ flexcop_access_op_t ;
struct TYPE_15__ {scalar_t__ status; int actual_length; int offset; int length; } ;
struct TYPE_14__ {TYPE_4__* endpoint; } ;
struct TYPE_12__ {int /*<<< orphan*/  wMaxPacketSize; } ;
struct TYPE_13__ {TYPE_3__ desc; } ;
struct TYPE_11__ {struct flexcop_usb* bus_specific; } ;

/* Variables and functions */
 int B2C2_FLEX_PCIOFFSET_TO_INTERNALADDR (int) ; 
 int B2C2_USB_CTRL_PIPE_IN ; 
 int B2C2_USB_CTRL_PIPE_OUT ; 
 int /*<<< orphan*/  B2C2_USB_DATA_PIPE ; 
#define  B2C2_USB_FLASH_BLOCK 140 
 int B2C2_USB_FRAMES_PER_ISO ; 
 int B2C2_USB_I2C_REQUEST ; 
 int B2C2_USB_NUM_ISO_URB ; 
 int B2C2_USB_READ_REG ; 
#define  B2C2_USB_READ_V8_MEM 139 
 int B2C2_USB_WRITE_REG ; 
#define  B2C2_USB_WRITE_V8_MEM 138 
 int B2C2_WAIT_FOR_OPERATION_RDW ; 
 int B2C2_WAIT_FOR_OPERATION_V8FLASH ; 
 int B2C2_WAIT_FOR_OPERATION_V8READ ; 
 int B2C2_WAIT_FOR_OPERATION_V8WRITE ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ FC_READ ; 
 int FC_SRAM_DEST_CAI ; 
 int FC_SRAM_DEST_CAO ; 
 int FC_SRAM_DEST_MEDIA ; 
 int FC_SRAM_DEST_NET ; 
 int /*<<< orphan*/  FC_SRAM_DEST_TARGET_WAN_USB ; 
 int /*<<< orphan*/  FC_USB ; 
 int /*<<< orphan*/  FC_WAN_SPEED_8MBITS ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  URB_ISO_ASAP ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_ENDPOINT_DIR_MASK ; 
 int USB_FLASH_MAX ; 
#define  USB_FUNC_I2C_CHECKWRITE 137 
#define  USB_FUNC_I2C_MULTIWRITE 136 
#define  USB_FUNC_I2C_READ 135 
#define  USB_FUNC_I2C_REPEATREAD 134 
#define  USB_FUNC_I2C_REPEATWRITE 133 
#define  USB_FUNC_I2C_WRITE 132 
 int USB_MEM_READ_MAX ; 
 int USB_MEM_WRITE_MAX ; 
#define  USB_SPEED_FULL 131 
#define  USB_SPEED_HIGH 130 
#define  USB_SPEED_LOW 129 
#define  USB_SPEED_UNKNOWN 128 
 int USB_TYPE_VENDOR ; 
 int V8_MEMORY_EXTENDED ; 
 int V8_MEMORY_PAGE_FLASH ; 
 int V8_MEMORY_PAGE_MASK ; 
 int V8_MEMORY_PAGE_SIZE ; 
 int bytes_left_to_read_on_page (int,int) ; 
 int /*<<< orphan*/  deb_i2c (char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  deb_info (char*,int) ; 
 int /*<<< orphan*/  deb_ts (char*,...) ; 
 int /*<<< orphan*/  deb_v8 (char*,int,int,int,int,int) ; 
 int /*<<< orphan*/  debug_dump (int*,int,int /*<<< orphan*/  (*) (char*,int,int,int,int,int)) ; 
 int /*<<< orphan*/  err (char*,...) ; 
 int /*<<< orphan*/  flexcop_device_exit (struct flexcop_device*) ; 
 int flexcop_device_initialize (struct flexcop_device*) ; 
 int /*<<< orphan*/  flexcop_device_kfree (struct flexcop_device*) ; 
 struct flexcop_device* flexcop_device_kmalloc (int) ; 
 int /*<<< orphan*/  flexcop_pass_dmx_packets (struct flexcop_device*,int*,int) ; 
 int /*<<< orphan*/  flexcop_sram_ctrl (struct flexcop_device*,int,int,int) ; 
 int /*<<< orphan*/  flexcop_sram_set_dest (struct flexcop_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  flexcop_wan_set_speed (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  info (char*,...) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* usb_alloc_coherent (struct usb_device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct urb* usb_alloc_urb (int,int /*<<< orphan*/ ) ; 
 int usb_control_msg (struct usb_device*,int,int,int,int,int,int*,int,int) ; 
 int /*<<< orphan*/  usb_free_coherent (struct usb_device*,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_free_urb (struct urb*) ; 
 struct flexcop_usb* usb_get_intfdata (struct usb_interface*) ; 
 int /*<<< orphan*/  usb_kill_urb (struct urb*) ; 
 int /*<<< orphan*/  usb_set_interface (struct usb_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_set_intfdata (struct usb_interface*,struct flexcop_usb*) ; 
 int usb_submit_urb (struct urb*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int flexcop_usb_readwrite_dw(struct flexcop_device *fc, u16 wRegOffsPCI, u32 *val, u8 read)
{
	struct flexcop_usb *fc_usb = fc->bus_specific;
	u8 request = read ? B2C2_USB_READ_REG : B2C2_USB_WRITE_REG;
	u8 request_type = (read ? USB_DIR_IN : USB_DIR_OUT) | USB_TYPE_VENDOR;
	u8 wAddress = B2C2_FLEX_PCIOFFSET_TO_INTERNALADDR(wRegOffsPCI) |
		(read ? 0x80 : 0);
	int ret;

	mutex_lock(&fc_usb->data_mutex);
	if (!read)
		memcpy(fc_usb->data, val, sizeof(*val));

	ret = usb_control_msg(fc_usb->udev,
			read ? B2C2_USB_CTRL_PIPE_IN : B2C2_USB_CTRL_PIPE_OUT,
			request,
			request_type, /* 0xc0 read or 0x40 write */
			wAddress,
			0,
			fc_usb->data,
			sizeof(u32),
			B2C2_WAIT_FOR_OPERATION_RDW * HZ);

	if (ret != sizeof(u32)) {
		err("error while %s dword from %d (%d).", read ? "reading" :
				"writing", wAddress, wRegOffsPCI);
		if (ret >= 0)
			ret = -EIO;
	}

	if (read && ret >= 0)
		memcpy(val, fc_usb->data, sizeof(*val));
	mutex_unlock(&fc_usb->data_mutex);

	return ret;
}

__attribute__((used)) static int flexcop_usb_v8_memory_req(struct flexcop_usb *fc_usb,
		flexcop_usb_request_t req, u8 page, u16 wAddress,
		u8 *pbBuffer, u32 buflen)
{
	u8 request_type = USB_TYPE_VENDOR;
	u16 wIndex;
	int nWaitTime, pipe, ret;
	wIndex = page << 8;

	if (buflen > sizeof(fc_usb->data)) {
		err("Buffer size bigger than max URB control message\n");
		return -EIO;
	}

	switch (req) {
	case B2C2_USB_READ_V8_MEM:
		nWaitTime = B2C2_WAIT_FOR_OPERATION_V8READ;
		request_type |= USB_DIR_IN;
		pipe = B2C2_USB_CTRL_PIPE_IN;
		break;
	case B2C2_USB_WRITE_V8_MEM:
		wIndex |= pbBuffer[0];
		request_type |= USB_DIR_OUT;
		nWaitTime = B2C2_WAIT_FOR_OPERATION_V8WRITE;
		pipe = B2C2_USB_CTRL_PIPE_OUT;
		break;
	case B2C2_USB_FLASH_BLOCK:
		request_type |= USB_DIR_OUT;
		nWaitTime = B2C2_WAIT_FOR_OPERATION_V8FLASH;
		pipe = B2C2_USB_CTRL_PIPE_OUT;
		break;
	default:
		deb_info("unsupported request for v8_mem_req %x.\n", req);
		return -EINVAL;
	}
	deb_v8("v8mem: %02x %02x %04x %04x, len: %d\n", request_type, req,
			wAddress, wIndex, buflen);

	mutex_lock(&fc_usb->data_mutex);

	if ((request_type & USB_ENDPOINT_DIR_MASK) == USB_DIR_OUT)
		memcpy(fc_usb->data, pbBuffer, buflen);

	ret = usb_control_msg(fc_usb->udev, pipe,
			req,
			request_type,
			wAddress,
			wIndex,
			fc_usb->data,
			buflen,
			nWaitTime * HZ);
	if (ret != buflen)
		ret = -EIO;

	if (ret >= 0) {
		ret = 0;
		if ((request_type & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
			memcpy(pbBuffer, fc_usb->data, buflen);
	}

	mutex_unlock(&fc_usb->data_mutex);

	debug_dump(pbBuffer, ret, deb_v8);
	return ret;
}

__attribute__((used)) static int flexcop_usb_memory_req(struct flexcop_usb *fc_usb,
		flexcop_usb_request_t req, flexcop_usb_mem_page_t page_start,
		u32 addr, int extended, u8 *buf, u32 len)
{
	int i,ret = 0;
	u16 wMax;
	u32 pagechunk = 0;

	switch(req) {
	case B2C2_USB_READ_V8_MEM:
		wMax = USB_MEM_READ_MAX;
		break;
	case B2C2_USB_WRITE_V8_MEM:
		wMax = USB_MEM_WRITE_MAX;
		break;
	case B2C2_USB_FLASH_BLOCK:
		wMax = USB_FLASH_MAX;
		break;
	default:
		return -EINVAL;
		break;
	}
	for (i = 0; i < len;) {
		pagechunk =
			wMax < bytes_left_to_read_on_page(addr, len) ?
				wMax :
				bytes_left_to_read_on_page(addr, len);
		deb_info("%x\n",
			(addr & V8_MEMORY_PAGE_MASK) |
				(V8_MEMORY_EXTENDED*extended));

		ret = flexcop_usb_v8_memory_req(fc_usb, req,
			page_start + (addr / V8_MEMORY_PAGE_SIZE),
			(addr & V8_MEMORY_PAGE_MASK) |
				(V8_MEMORY_EXTENDED*extended),
			&buf[i], pagechunk);

		if (ret < 0)
			return ret;
		addr += pagechunk;
		len -= pagechunk;
	}
	return 0;
}

__attribute__((used)) static int flexcop_usb_get_mac_addr(struct flexcop_device *fc, int extended)
{
	return flexcop_usb_memory_req(fc->bus_specific, B2C2_USB_READ_V8_MEM,
		V8_MEMORY_PAGE_FLASH, 0x1f010, 1,
		fc->dvb_adapter.proposed_mac, 6);
}

__attribute__((used)) static int flexcop_usb_i2c_req(struct flexcop_i2c_adapter *i2c,
		flexcop_usb_request_t req, flexcop_usb_i2c_function_t func,
		u8 chipaddr, u8 addr, u8 *buf, u8 buflen)
{
	struct flexcop_usb *fc_usb = i2c->fc->bus_specific;
	u16 wValue, wIndex;
	int nWaitTime, pipe, ret;
	u8 request_type = USB_TYPE_VENDOR;

	if (buflen > sizeof(fc_usb->data)) {
		err("Buffer size bigger than max URB control message\n");
		return -EIO;
	}

	switch (func) {
	case USB_FUNC_I2C_WRITE:
	case USB_FUNC_I2C_MULTIWRITE:
	case USB_FUNC_I2C_REPEATWRITE:
		/* DKT 020208 - add this to support special case of DiSEqC */
	case USB_FUNC_I2C_CHECKWRITE:
		pipe = B2C2_USB_CTRL_PIPE_OUT;
		nWaitTime = 2;
		request_type |= USB_DIR_OUT;
		break;
	case USB_FUNC_I2C_READ:
	case USB_FUNC_I2C_REPEATREAD:
		pipe = B2C2_USB_CTRL_PIPE_IN;
		nWaitTime = 2;
		request_type |= USB_DIR_IN;
		break;
	default:
		deb_info("unsupported function for i2c_req %x\n", func);
		return -EINVAL;
	}
	wValue = (func << 8) | (i2c->port << 4);
	wIndex = (chipaddr << 8 ) | addr;

	deb_i2c("i2c %2d: %02x %02x %02x %02x %02x %02x\n",
			func, request_type, req,
			wValue & 0xff, wValue >> 8,
			wIndex & 0xff, wIndex >> 8);

	mutex_lock(&fc_usb->data_mutex);

	if ((request_type & USB_ENDPOINT_DIR_MASK) == USB_DIR_OUT)
		memcpy(fc_usb->data, buf, buflen);

	ret = usb_control_msg(fc_usb->udev, pipe,
			req,
			request_type,
			wValue,
			wIndex,
			fc_usb->data,
			buflen,
			nWaitTime * HZ);

	if (ret != buflen)
		ret = -EIO;

	if (ret >= 0) {
		ret = 0;
		if ((request_type & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
			memcpy(buf, fc_usb->data, buflen);
	}

	mutex_unlock(&fc_usb->data_mutex);

	return 0;
}

__attribute__((used)) static flexcop_ibi_value flexcop_usb_read_ibi_reg(struct flexcop_device *fc,
	flexcop_ibi_register reg)
{
	flexcop_ibi_value val;
	val.raw = 0;
	flexcop_usb_readwrite_dw(fc, reg, &val.raw, 1);
	return val;
}

__attribute__((used)) static int flexcop_usb_write_ibi_reg(struct flexcop_device *fc,
		flexcop_ibi_register reg, flexcop_ibi_value val)
{
	return flexcop_usb_readwrite_dw(fc, reg, &val.raw, 0);
}

__attribute__((used)) static int flexcop_usb_i2c_request(struct flexcop_i2c_adapter *i2c,
		flexcop_access_op_t op, u8 chipaddr, u8 addr, u8 *buf, u16 len)
{
	if (op == FC_READ)
		return flexcop_usb_i2c_req(i2c, B2C2_USB_I2C_REQUEST,
				USB_FUNC_I2C_READ, chipaddr, addr, buf, len);
	else
		return flexcop_usb_i2c_req(i2c, B2C2_USB_I2C_REQUEST,
				USB_FUNC_I2C_WRITE, chipaddr, addr, buf, len);
}

__attribute__((used)) static void flexcop_usb_process_frame(struct flexcop_usb *fc_usb,
	u8 *buffer, int buffer_length)
{
	u8 *b;
	int l;

	deb_ts("tmp_buffer_length=%d, buffer_length=%d\n",
		fc_usb->tmp_buffer_length, buffer_length);

	if (fc_usb->tmp_buffer_length > 0) {
		memcpy(fc_usb->tmp_buffer+fc_usb->tmp_buffer_length, buffer,
				buffer_length);
		fc_usb->tmp_buffer_length += buffer_length;
		b = fc_usb->tmp_buffer;
		l = fc_usb->tmp_buffer_length;
	} else {
		b=buffer;
		l=buffer_length;
	}

	while (l >= 190) {
		if (*b == 0xff) {
			switch (*(b+1) & 0x03) {
			case 0x01: /* media packet */
				if (*(b+2) == 0x47)
					flexcop_pass_dmx_packets(
							fc_usb->fc_dev, b+2, 1);
				else
					deb_ts("not ts packet %*ph\n", 4, b+2);
				b += 190;
				l -= 190;
				break;
			default:
				deb_ts("wrong packet type\n");
				l = 0;
				break;
			}
		} else {
			deb_ts("wrong header\n");
			l = 0;
		}
	}

	if (l>0)
		memcpy(fc_usb->tmp_buffer, b, l);
	fc_usb->tmp_buffer_length = l;
}

__attribute__((used)) static void flexcop_usb_urb_complete(struct urb *urb)
{
	struct flexcop_usb *fc_usb = urb->context;
	int i;

	if (urb->actual_length > 0)
		deb_ts("urb completed, bufsize: %d actlen; %d\n",
			urb->transfer_buffer_length, urb->actual_length);

	for (i = 0; i < urb->number_of_packets; i++) {
		if (urb->iso_frame_desc[i].status < 0) {
			err("iso frame descriptor %d has an error: %d\n", i,
				urb->iso_frame_desc[i].status);
		} else
			if (urb->iso_frame_desc[i].actual_length > 0) {
				deb_ts("passed %d bytes to the demux\n",
					urb->iso_frame_desc[i].actual_length);

				flexcop_usb_process_frame(fc_usb,
					urb->transfer_buffer +
						urb->iso_frame_desc[i].offset,
					urb->iso_frame_desc[i].actual_length);
			}
		urb->iso_frame_desc[i].status = 0;
		urb->iso_frame_desc[i].actual_length = 0;
	}
	usb_submit_urb(urb,GFP_ATOMIC);
}

__attribute__((used)) static int flexcop_usb_stream_control(struct flexcop_device *fc, int onoff)
{
	/* submit/kill iso packets */
	return 0;
}

__attribute__((used)) static void flexcop_usb_transfer_exit(struct flexcop_usb *fc_usb)
{
	int i;
	for (i = 0; i < B2C2_USB_NUM_ISO_URB; i++)
		if (fc_usb->iso_urb[i] != NULL) {
			deb_ts("unlinking/killing urb no. %d\n",i);
			usb_kill_urb(fc_usb->iso_urb[i]);
			usb_free_urb(fc_usb->iso_urb[i]);
		}

	if (fc_usb->iso_buffer != NULL)
		usb_free_coherent(fc_usb->udev,
			fc_usb->buffer_size, fc_usb->iso_buffer,
			fc_usb->dma_addr);
}

__attribute__((used)) static int flexcop_usb_transfer_init(struct flexcop_usb *fc_usb)
{
	u16 frame_size = le16_to_cpu(
		fc_usb->uintf->cur_altsetting->endpoint[0].desc.wMaxPacketSize);
	int bufsize = B2C2_USB_NUM_ISO_URB * B2C2_USB_FRAMES_PER_ISO *
		frame_size, i, j, ret;
	int buffer_offset = 0;

	deb_ts("creating %d iso-urbs with %d frames each of %d bytes size = %d.\n",
	       B2C2_USB_NUM_ISO_URB,
			B2C2_USB_FRAMES_PER_ISO, frame_size, bufsize);

	fc_usb->iso_buffer = usb_alloc_coherent(fc_usb->udev,
			bufsize, GFP_KERNEL, &fc_usb->dma_addr);
	if (fc_usb->iso_buffer == NULL)
		return -ENOMEM;

	memset(fc_usb->iso_buffer, 0, bufsize);
	fc_usb->buffer_size = bufsize;

	/* creating iso urbs */
	for (i = 0; i < B2C2_USB_NUM_ISO_URB; i++) {
		fc_usb->iso_urb[i] = usb_alloc_urb(B2C2_USB_FRAMES_PER_ISO,
			GFP_ATOMIC);
		if (fc_usb->iso_urb[i] == NULL) {
			ret = -ENOMEM;
			goto urb_error;
		}
	}

	/* initialising and submitting iso urbs */
	for (i = 0; i < B2C2_USB_NUM_ISO_URB; i++) {
		int frame_offset = 0;
		struct urb *urb = fc_usb->iso_urb[i];
		deb_ts("initializing and submitting urb no. %d (buf_offset: %d).\n",
		       i, buffer_offset);

		urb->dev = fc_usb->udev;
		urb->context = fc_usb;
		urb->complete = flexcop_usb_urb_complete;
		urb->pipe = B2C2_USB_DATA_PIPE;
		urb->transfer_flags = URB_ISO_ASAP;
		urb->interval = 1;
		urb->number_of_packets = B2C2_USB_FRAMES_PER_ISO;
		urb->transfer_buffer_length = frame_size * B2C2_USB_FRAMES_PER_ISO;
		urb->transfer_buffer = fc_usb->iso_buffer + buffer_offset;

		buffer_offset += frame_size * B2C2_USB_FRAMES_PER_ISO;
		for (j = 0; j < B2C2_USB_FRAMES_PER_ISO; j++) {
			deb_ts("urb no: %d, frame: %d, frame_offset: %d\n",
					i, j, frame_offset);
			urb->iso_frame_desc[j].offset = frame_offset;
			urb->iso_frame_desc[j].length = frame_size;
			frame_offset += frame_size;
		}

		if ((ret = usb_submit_urb(fc_usb->iso_urb[i],GFP_ATOMIC))) {
			err("submitting urb %d failed with %d.", i, ret);
			goto urb_error;
		}
		deb_ts("submitted urb no. %d.\n",i);
	}

	/* SRAM */
	flexcop_sram_set_dest(fc_usb->fc_dev, FC_SRAM_DEST_MEDIA |
			FC_SRAM_DEST_NET | FC_SRAM_DEST_CAO | FC_SRAM_DEST_CAI,
			FC_SRAM_DEST_TARGET_WAN_USB);
	flexcop_wan_set_speed(fc_usb->fc_dev, FC_WAN_SPEED_8MBITS);
	flexcop_sram_ctrl(fc_usb->fc_dev, 1, 1, 1);
	return 0;

urb_error:
	flexcop_usb_transfer_exit(fc_usb);
	return ret;
}

__attribute__((used)) static int flexcop_usb_init(struct flexcop_usb *fc_usb)
{
	/* use the alternate setting with the larges buffer */
	usb_set_interface(fc_usb->udev,0,1);
	switch (fc_usb->udev->speed) {
	case USB_SPEED_LOW:
		err("cannot handle USB speed because it is too slow.");
		return -ENODEV;
		break;
	case USB_SPEED_FULL:
		info("running at FULL speed.");
		break;
	case USB_SPEED_HIGH:
		info("running at HIGH speed.");
		break;
	case USB_SPEED_UNKNOWN: /* fall through */
	default:
		err("cannot handle USB speed because it is unknown.");
		return -ENODEV;
	}
	usb_set_intfdata(fc_usb->uintf, fc_usb);
	return 0;
}

__attribute__((used)) static void flexcop_usb_exit(struct flexcop_usb *fc_usb)
{
	usb_set_intfdata(fc_usb->uintf, NULL);
}

__attribute__((used)) static int flexcop_usb_probe(struct usb_interface *intf,
		const struct usb_device_id *id)
{
	struct usb_device *udev = interface_to_usbdev(intf);
	struct flexcop_usb *fc_usb = NULL;
	struct flexcop_device *fc = NULL;
	int ret;

	if ((fc = flexcop_device_kmalloc(sizeof(struct flexcop_usb))) == NULL) {
		err("out of memory\n");
		return -ENOMEM;
	}

	/* general flexcop init */
	fc_usb = fc->bus_specific;
	fc_usb->fc_dev = fc;
	mutex_init(&fc_usb->data_mutex);

	fc->read_ibi_reg  = flexcop_usb_read_ibi_reg;
	fc->write_ibi_reg = flexcop_usb_write_ibi_reg;
	fc->i2c_request = flexcop_usb_i2c_request;
	fc->get_mac_addr = flexcop_usb_get_mac_addr;

	fc->stream_control = flexcop_usb_stream_control;

	fc->pid_filtering = 1;
	fc->bus_type = FC_USB;

	fc->dev = &udev->dev;
	fc->owner = THIS_MODULE;

	/* bus specific part */
	fc_usb->udev = udev;
	fc_usb->uintf = intf;
	if ((ret = flexcop_usb_init(fc_usb)) != 0)
		goto err_kfree;

	/* init flexcop */
	if ((ret = flexcop_device_initialize(fc)) != 0)
		goto err_usb_exit;

	/* xfer init */
	if ((ret = flexcop_usb_transfer_init(fc_usb)) != 0)
		goto err_fc_exit;

	info("%s successfully initialized and connected.", DRIVER_NAME);
	return 0;

err_fc_exit:
	flexcop_device_exit(fc);
err_usb_exit:
	flexcop_usb_exit(fc_usb);
err_kfree:
	flexcop_device_kfree(fc);
	return ret;
}

__attribute__((used)) static void flexcop_usb_disconnect(struct usb_interface *intf)
{
	struct flexcop_usb *fc_usb = usb_get_intfdata(intf);
	flexcop_usb_transfer_exit(fc_usb);
	flexcop_device_exit(fc_usb->fc_dev);
	flexcop_usb_exit(fc_usb);
	flexcop_device_kfree(fc_usb->fc_dev);
	info("%s successfully deinitialized and disconnected.", DRIVER_NAME);
}

