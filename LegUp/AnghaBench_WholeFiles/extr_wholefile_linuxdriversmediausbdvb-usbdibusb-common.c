#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct rc_map_table {int scancode; } ;
struct i2c_msg {int flags; int addr; int* buf; int len; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_usb_device {int /*<<< orphan*/  i2c_mutex; } ;
struct dvb_usb_adapter {struct dvb_usb_device* dev; TYPE_2__* fe_adap; struct dibusb_state* priv; } ;
struct TYPE_3__ {scalar_t__ (* pid_parse ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* pid_ctrl ) (int /*<<< orphan*/ ,int,int,int) ;scalar_t__ (* fifo_ctrl ) (int /*<<< orphan*/ ,int) ;} ;
struct dibusb_state {TYPE_1__ ops; } ;
struct TYPE_4__ {int /*<<< orphan*/  fe; } ;

/* Variables and functions */
 int DIBUSB_IOCTL_CMD_DISABLE_STREAM ; 
 int DIBUSB_IOCTL_CMD_ENABLE_STREAM ; 
 int DIBUSB_IOCTL_CMD_POWER_MODE ; 
 int DIBUSB_IOCTL_POWER_SLEEP ; 
 int DIBUSB_IOCTL_POWER_WAKEUP ; 
 int DIBUSB_REQ_I2C_READ ; 
 int DIBUSB_REQ_I2C_WRITE ; 
 int DIBUSB_REQ_POLL_REMOTE ; 
 int DIBUSB_REQ_SET_IOCTL ; 
 int DIBUSB_REQ_SET_STREAMING_MODE ; 
 int EAGAIN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int I2C_M_RD ; 
 int MAX_XFER_SIZE ; 
 int /*<<< orphan*/  deb_info (char*,int,int*) ; 
 int dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_write (struct dvb_usb_device*,int*,int) ; 
 int /*<<< orphan*/  dvb_usb_nec_rc_key_to_event (struct dvb_usb_device*,int*,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  err (char*) ; 
 struct dvb_usb_device* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int,int,int) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  warn (char*,int) ; 

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

int dibusb_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	if (adap->priv != NULL) {
		struct dibusb_state *st = adap->priv;
		if (st->ops.fifo_ctrl != NULL)
			if (st->ops.fifo_ctrl(adap->fe_adap[0].fe, onoff)) {
				err("error while controlling the fifo of the demod.");
				return -ENODEV;
			}
	}
	return 0;
}

int dibusb_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
	if (adap->priv != NULL) {
		struct dibusb_state *st = adap->priv;
		if (st->ops.pid_ctrl != NULL)
			st->ops.pid_ctrl(adap->fe_adap[0].fe,
					 index, pid, onoff);
	}
	return 0;
}

int dibusb_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	if (adap->priv != NULL) {
		struct dibusb_state *st = adap->priv;
		if (st->ops.pid_parse != NULL)
			if (st->ops.pid_parse(adap->fe_adap[0].fe, onoff) < 0)
				err("could not handle pid_parser");
	}
	return 0;
}

int dibusb_power_ctrl(struct dvb_usb_device *d, int onoff)
{
	u8 *b;
	int ret;

	b = kmalloc(3, GFP_KERNEL);
	if (!b)
		return -ENOMEM;

	b[0] = DIBUSB_REQ_SET_IOCTL;
	b[1] = DIBUSB_IOCTL_CMD_POWER_MODE;
	b[2] = onoff ? DIBUSB_IOCTL_POWER_WAKEUP : DIBUSB_IOCTL_POWER_SLEEP;

	ret = dvb_usb_generic_write(d, b, 3);

	kfree(b);

	msleep(10);

	return ret;
}

int dibusb2_0_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	int ret;
	u8 *b;

	b = kmalloc(3, GFP_KERNEL);
	if (!b)
		return -ENOMEM;

	if ((ret = dibusb_streaming_ctrl(adap,onoff)) < 0)
		goto ret;

	if (onoff) {
		b[0] = DIBUSB_REQ_SET_STREAMING_MODE;
		b[1] = 0x00;
		ret = dvb_usb_generic_write(adap->dev, b, 2);
		if (ret  < 0)
			goto ret;
	}

	b[0] = DIBUSB_REQ_SET_IOCTL;
	b[1] = onoff ? DIBUSB_IOCTL_CMD_ENABLE_STREAM : DIBUSB_IOCTL_CMD_DISABLE_STREAM;
	ret = dvb_usb_generic_write(adap->dev, b, 3);

ret:
	kfree(b);
	return ret;
}

int dibusb2_0_power_ctrl(struct dvb_usb_device *d, int onoff)
{
	u8 *b;
	int ret;

	if (!onoff)
		return 0;

	b = kmalloc(3, GFP_KERNEL);
	if (!b)
		return -ENOMEM;

	b[0] = DIBUSB_REQ_SET_IOCTL;
	b[1] = DIBUSB_IOCTL_CMD_POWER_MODE;
	b[2] = DIBUSB_IOCTL_POWER_WAKEUP;

	ret = dvb_usb_generic_write(d, b, 3);

	kfree(b);

	return ret;
}

__attribute__((used)) static int dibusb_i2c_msg(struct dvb_usb_device *d, u8 addr,
			  u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
	u8 *sndbuf;
	int ret, wo, len;

	/* write only ? */
	wo = (rbuf == NULL || rlen == 0);

	len = 2 + wlen + (wo ? 0 : 2);

	sndbuf = kmalloc(MAX_XFER_SIZE, GFP_KERNEL);
	if (!sndbuf)
		return -ENOMEM;

	if (4 + wlen > MAX_XFER_SIZE) {
		warn("i2c wr: len=%d is too big!\n", wlen);
		ret = -EOPNOTSUPP;
		goto ret;
	}

	sndbuf[0] = wo ? DIBUSB_REQ_I2C_WRITE : DIBUSB_REQ_I2C_READ;
	sndbuf[1] = (addr << 1) | (wo ? 0 : 1);

	memcpy(&sndbuf[2], wbuf, wlen);

	if (!wo) {
		sndbuf[wlen + 2] = (rlen >> 8) & 0xff;
		sndbuf[wlen + 3] = rlen & 0xff;
	}

	ret = dvb_usb_generic_rw(d, sndbuf, len, rbuf, rlen, 0);

ret:
	kfree(sndbuf);
	return ret;
}

__attribute__((used)) static int dibusb_i2c_xfer(struct i2c_adapter *adap,struct i2c_msg msg[],int num)
{
	struct dvb_usb_device *d = i2c_get_adapdata(adap);
	int i;

	if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
		return -EAGAIN;

	for (i = 0; i < num; i++) {
		/* write/read request */
		if (i+1 < num && (msg[i].flags & I2C_M_RD) == 0
					  && (msg[i+1].flags & I2C_M_RD)) {
			if (dibusb_i2c_msg(d, msg[i].addr, msg[i].buf,msg[i].len,
						msg[i+1].buf,msg[i+1].len) < 0)
				break;
			i++;
		} else if ((msg[i].flags & I2C_M_RD) == 0) {
			if (dibusb_i2c_msg(d, msg[i].addr, msg[i].buf,msg[i].len,NULL,0) < 0)
				break;
		} else if (msg[i].addr != 0x50) {
			/* 0x50 is the address of the eeprom - we need to protect it
			 * from dibusb's bad i2c implementation: reads without
			 * writing the offset before are forbidden */
			if (dibusb_i2c_msg(d, msg[i].addr, NULL, 0, msg[i].buf, msg[i].len) < 0)
				break;
		}
	}

	mutex_unlock(&d->i2c_mutex);
	return i;
}

__attribute__((used)) static u32 dibusb_i2c_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C;
}

int dibusb_read_eeprom_byte(struct dvb_usb_device *d, u8 offs, u8 *val)
{
	u8 *buf;
	int rc;

	buf = kmalloc(2, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	buf[0] = offs;

	rc = dibusb_i2c_msg(d, 0x50, &buf[0], 1, &buf[1], 1);
	*val = buf[1];
	kfree(buf);

	return rc;
}

int dibusb_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
	u8 *buf;
	int ret;

	buf = kmalloc(5, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	buf[0] = DIBUSB_REQ_POLL_REMOTE;

	ret = dvb_usb_generic_rw(d, buf, 1, buf, 5, 0);
	if (ret < 0)
		goto ret;

	dvb_usb_nec_rc_key_to_event(d, buf, event, state);

	if (buf[0] != 0)
		deb_info("key: %*ph\n", 5, buf);

ret:
	kfree(buf);

	return ret;
}

