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
typedef  int u8 ;
typedef  int u16 ;
struct usb_data_stream {struct dvb_usb_adapter* user_priv; } ;
struct rc_map_table {int scancode; } ;
struct TYPE_8__ {scalar_t__ generic_bulk_ctrl_endpoint; scalar_t__ generic_bulk_ctrl_endpoint_response; } ;
struct dvb_usb_device {int /*<<< orphan*/  usb_mutex; TYPE_1__ props; int /*<<< orphan*/  udev; } ;
struct TYPE_11__ {int num_frontends; TYPE_3__* fe; } ;
struct dvb_usb_adapter {scalar_t__ feedcount; int state; TYPE_5__* fe_adap; TYPE_4__ props; TYPE_2__* dev; int /*<<< orphan*/  demux; } ;
struct TYPE_13__ {void (* complete ) (struct usb_data_stream*,int*,size_t) ;struct dvb_usb_adapter* user_priv; int /*<<< orphan*/  udev; } ;
struct TYPE_12__ {TYPE_6__ stream; } ;
struct TYPE_10__ {int caps; int /*<<< orphan*/  stream; } ;
struct TYPE_9__ {int /*<<< orphan*/  udev; } ;

/* Variables and functions */
 int DVB_USB_ADAP_RECEIVES_204_BYTE_TS ; 
 int DVB_USB_ADAP_RECEIVES_RAW_PAYLOAD ; 
 int DVB_USB_ADAP_STATE_DVB ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  deb_xfer (char*) ; 
 int /*<<< orphan*/  debug_dump (int*,int,int /*<<< orphan*/  (*) (char*)) ; 
 int /*<<< orphan*/  dvb_dmx_swfilter (int /*<<< orphan*/ *,int*,size_t) ; 
 int /*<<< orphan*/  dvb_dmx_swfilter_204 (int /*<<< orphan*/ *,int*,size_t) ; 
 int /*<<< orphan*/  dvb_dmx_swfilter_raw (int /*<<< orphan*/ *,int*,size_t) ; 
 int /*<<< orphan*/  err (char*,...) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int usb_bulk_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int,int*,int) ; 
 int /*<<< orphan*/  usb_rcvbulkpipe (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  usb_sndbulkpipe (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  usb_urb_exit (TYPE_6__*) ; 
 int usb_urb_init (TYPE_6__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u8 rc5_custom(struct rc_map_table *key)
{
	return (key->scancode >> 8) & 0xff;
}

__attribute__((used)) static inline u8 rc5_data(struct rc_map_table *key)
{
	return key->scancode & 0xff;
}

__attribute__((used)) static inline u16 rc5_scan(struct rc_map_table *key)
{
	return key->scancode & 0xffff;
}

int dvb_usb_generic_rw(struct dvb_usb_device *d, u8 *wbuf, u16 wlen, u8 *rbuf,
	u16 rlen, int delay_ms)
{
	int actlen,ret = -ENOMEM;

	if (!d || wbuf == NULL || wlen == 0)
		return -EINVAL;

	if (d->props.generic_bulk_ctrl_endpoint == 0) {
		err("endpoint for generic control not specified.");
		return -EINVAL;
	}

	if ((ret = mutex_lock_interruptible(&d->usb_mutex)))
		return ret;

	deb_xfer(">>> ");
	debug_dump(wbuf,wlen,deb_xfer);

	ret = usb_bulk_msg(d->udev,usb_sndbulkpipe(d->udev,
			d->props.generic_bulk_ctrl_endpoint), wbuf,wlen,&actlen,
			2000);

	if (ret)
		err("bulk message failed: %d (%d/%d)",ret,wlen,actlen);
	else
		ret = actlen != wlen ? -1 : 0;

	/* an answer is expected, and no error before */
	if (!ret && rbuf && rlen) {
		if (delay_ms)
			msleep(delay_ms);

		ret = usb_bulk_msg(d->udev,usb_rcvbulkpipe(d->udev,
				d->props.generic_bulk_ctrl_endpoint_response ?
				d->props.generic_bulk_ctrl_endpoint_response :
				d->props.generic_bulk_ctrl_endpoint),rbuf,rlen,&actlen,
				2000);

		if (ret)
			err("recv bulk message failed: %d",ret);
		else {
			deb_xfer("<<< ");
			debug_dump(rbuf,actlen,deb_xfer);
		}
	}

	mutex_unlock(&d->usb_mutex);
	return ret;
}

int dvb_usb_generic_write(struct dvb_usb_device *d, u8 *buf, u16 len)
{
	return dvb_usb_generic_rw(d,buf,len,NULL,0,0);
}

__attribute__((used)) static void dvb_usb_data_complete(struct usb_data_stream *stream, u8 *buffer, size_t length)
{
	struct dvb_usb_adapter *adap = stream->user_priv;
	if (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)
		dvb_dmx_swfilter(&adap->demux, buffer, length);
}

__attribute__((used)) static void dvb_usb_data_complete_204(struct usb_data_stream *stream, u8 *buffer, size_t length)
{
	struct dvb_usb_adapter *adap = stream->user_priv;
	if (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)
		dvb_dmx_swfilter_204(&adap->demux, buffer, length);
}

__attribute__((used)) static void dvb_usb_data_complete_raw(struct usb_data_stream *stream,
				      u8 *buffer, size_t length)
{
	struct dvb_usb_adapter *adap = stream->user_priv;
	if (adap->feedcount > 0 && adap->state & DVB_USB_ADAP_STATE_DVB)
		dvb_dmx_swfilter_raw(&adap->demux, buffer, length);
}

int dvb_usb_adapter_stream_init(struct dvb_usb_adapter *adap)
{
	int i, ret = 0;
	for (i = 0; i < adap->props.num_frontends; i++) {

		adap->fe_adap[i].stream.udev      = adap->dev->udev;
		if (adap->props.fe[i].caps & DVB_USB_ADAP_RECEIVES_204_BYTE_TS)
			adap->fe_adap[i].stream.complete =
				dvb_usb_data_complete_204;
		else
		if (adap->props.fe[i].caps & DVB_USB_ADAP_RECEIVES_RAW_PAYLOAD)
			adap->fe_adap[i].stream.complete =
				dvb_usb_data_complete_raw;
		else
		adap->fe_adap[i].stream.complete  = dvb_usb_data_complete;
		adap->fe_adap[i].stream.user_priv = adap;
		ret = usb_urb_init(&adap->fe_adap[i].stream,
				   &adap->props.fe[i].stream);
		if (ret < 0)
			break;
	}
	return ret;
}

int dvb_usb_adapter_stream_exit(struct dvb_usb_adapter *adap)
{
	int i;
	for (i = 0; i < adap->props.num_frontends; i++)
		usb_urb_exit(&adap->fe_adap[i].stream);
	return 0;
}

