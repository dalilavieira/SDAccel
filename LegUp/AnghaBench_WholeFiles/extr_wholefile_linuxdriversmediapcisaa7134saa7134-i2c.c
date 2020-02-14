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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct video_device {int /*<<< orphan*/ * queue; } ;
struct TYPE_8__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_10__ {struct saa7134_dev* algo_data; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct i2c_client {int addr; TYPE_3__* adapter; } ;
struct saa7134_dev {scalar_t__ board; unsigned char* eedata; TYPE_3__ i2c_adap; struct i2c_client i2c_client; int /*<<< orphan*/  v4l2_dev; int /*<<< orphan*/  name; TYPE_2__* pci; int /*<<< orphan*/  empress_vbq; } ;
struct i2c_msg {int flags; int addr; int len; int* buf; } ;
struct i2c_adapter {struct saa7134_dev* algo_data; } ;
struct file {int dummy; } ;
typedef  enum i2c_status { ____Placeholder_i2c_status } i2c_status ;
typedef  enum i2c_attr { ____Placeholder_i2c_attr } i2c_attr ;
typedef  int __u32 ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
#define  ARB_LOST 138 
 int ARRAY_SIZE (char**) ; 
#define  BUSY 137 
#define  BUS_ERR 136 
 int CONTINUE ; 
#define  DONE_STOP 135 
 int EIO ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  I2C_WAIT_DELAY ; 
 int I2C_WAIT_RETRY ; 
#define  IDLE 134 
 int NOP ; 
#define  NO_ACKN 133 
#define  NO_DEVICE 132 
 scalar_t__ SAA7134_BOARD_MD7134 ; 
 int SAA7134_I2C_ATTR_STATUS ; 
 int SAA7134_I2C_DATA ; 
#define  SEQ_ERR 131 
 int START ; 
 int STOP ; 
#define  ST_ERR 130 
#define  TO_ARB 129 
#define  TO_SCL 128 
 int /*<<< orphan*/  i2c_add_adapter (TYPE_3__*) ; 
 int /*<<< orphan*/  i2c_cont (int,char*,...) ; 
 int /*<<< orphan*/  i2c_dbg (int,char*,...) ; 
 int i2c_debug ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_3__*) ; 
 char** i2c_devs ; 
 int i2c_master_recv (struct i2c_client*,unsigned char*,int) ; 
 int i2c_master_send (struct i2c_client*,unsigned char*,int) ; 
 scalar_t__ i2c_scan ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int i2c_transfer (TYPE_3__*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*,int,...) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ,int) ; 
 TYPE_3__ saa7134_adap_template ; 
 struct i2c_client saa7134_client_template ; 
 int /*<<< orphan*/  saa7134_probe_i2c_ir (struct saa7134_dev*) ; 
 int /*<<< orphan*/  saa_andorb (int,int,int) ; 
 int saa_readb (int) ; 
 int saa_readl (int) ; 
 int /*<<< orphan*/  saa_wait (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  saa_writel (int,int) ; 
 int /*<<< orphan*/ * str_i2c_attr ; 
 unsigned char* str_i2c_status ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 
 struct video_device* video_devdata (struct file*) ; 
 struct saa7134_dev* video_get_drvdata (struct video_device*) ; 

__attribute__((used)) static inline bool is_empress(struct file *file)
{
	struct video_device *vdev = video_devdata(file);
	struct saa7134_dev *dev = video_get_drvdata(vdev);

	return vdev->queue == &dev->empress_vbq;
}

__attribute__((used)) static inline enum i2c_status i2c_get_status(struct saa7134_dev *dev)
{
	enum i2c_status status;

	status = saa_readb(SAA7134_I2C_ATTR_STATUS) & 0x0f;
	i2c_dbg(2, "i2c stat <= %s\n", str_i2c_status[status]);
	return status;
}

__attribute__((used)) static inline void i2c_set_status(struct saa7134_dev *dev,
				  enum i2c_status status)
{
	i2c_dbg(2, "i2c stat => %s\n", str_i2c_status[status]);
	saa_andorb(SAA7134_I2C_ATTR_STATUS,0x0f,status);
}

__attribute__((used)) static inline void i2c_set_attr(struct saa7134_dev *dev, enum i2c_attr attr)
{
	i2c_dbg(2, "i2c attr => %s\n", str_i2c_attr[attr]);
	saa_andorb(SAA7134_I2C_ATTR_STATUS,0xc0,attr << 6);
}

__attribute__((used)) static inline int i2c_is_error(enum i2c_status status)
{
	switch (status) {
	case NO_DEVICE:
	case NO_ACKN:
	case BUS_ERR:
	case ARB_LOST:
	case SEQ_ERR:
	case ST_ERR:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static inline int i2c_is_idle(enum i2c_status status)
{
	switch (status) {
	case IDLE:
	case DONE_STOP:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static inline int i2c_is_busy(enum i2c_status status)
{
	switch (status) {
	case BUSY:
	case TO_SCL:
	case TO_ARB:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int i2c_is_busy_wait(struct saa7134_dev *dev)
{
	enum i2c_status status;
	int count;

	for (count = 0; count < I2C_WAIT_RETRY; count++) {
		status = i2c_get_status(dev);
		if (!i2c_is_busy(status))
			break;
		saa_wait(I2C_WAIT_DELAY);
	}
	if (I2C_WAIT_RETRY == count)
		return false;
	return true;
}

__attribute__((used)) static int i2c_reset(struct saa7134_dev *dev)
{
	enum i2c_status status;
	int count;

	i2c_dbg(2, "i2c reset\n");
	status = i2c_get_status(dev);
	if (!i2c_is_error(status))
		return true;
	i2c_set_status(dev,status);

	for (count = 0; count < I2C_WAIT_RETRY; count++) {
		status = i2c_get_status(dev);
		if (!i2c_is_error(status))
			break;
		udelay(I2C_WAIT_DELAY);
	}
	if (I2C_WAIT_RETRY == count)
		return false;

	if (!i2c_is_idle(status))
		return false;

	i2c_set_attr(dev,NOP);
	return true;
}

__attribute__((used)) static inline int i2c_send_byte(struct saa7134_dev *dev,
				enum i2c_attr attr,
				unsigned char data)
{
	enum i2c_status status;
	__u32 dword;

	/* have to write both attr + data in one 32bit word */
	dword  = saa_readl(SAA7134_I2C_ATTR_STATUS >> 2);
	dword &= 0x0f;
	dword |= (attr << 6);
	dword |= ((__u32)data << 8);
	dword |= 0x00 << 16;  /* 100 kHz */
//	dword |= 0x40 << 16;  /* 400 kHz */
	dword |= 0xf0 << 24;
	saa_writel(SAA7134_I2C_ATTR_STATUS >> 2, dword);
	i2c_dbg(2, "i2c data => 0x%x\n", data);

	if (!i2c_is_busy_wait(dev))
		return -EIO;
	status = i2c_get_status(dev);
	if (i2c_is_error(status))
		return -EIO;
	return 0;
}

__attribute__((used)) static inline int i2c_recv_byte(struct saa7134_dev *dev)
{
	enum i2c_status status;
	unsigned char data;

	i2c_set_attr(dev,CONTINUE);
	if (!i2c_is_busy_wait(dev))
		return -EIO;
	status = i2c_get_status(dev);
	if (i2c_is_error(status))
		return -EIO;
	data = saa_readb(SAA7134_I2C_DATA);
	i2c_dbg(2, "i2c data <= 0x%x\n", data);
	return data;
}

__attribute__((used)) static int saa7134_i2c_xfer(struct i2c_adapter *i2c_adap,
			    struct i2c_msg *msgs, int num)
{
	struct saa7134_dev *dev = i2c_adap->algo_data;
	enum i2c_status status;
	unsigned char data;
	int addr,rc,i,byte;

	status = i2c_get_status(dev);
	if (!i2c_is_idle(status))
		if (!i2c_reset(dev))
			return -EIO;

	i2c_dbg(2, "start xfer\n");
	i2c_dbg(1, "i2c xfer:");
	for (i = 0; i < num; i++) {
		if (!(msgs[i].flags & I2C_M_NOSTART) || 0 == i) {
			/* send address */
			i2c_dbg(2, "send address\n");
			addr  = msgs[i].addr << 1;
			if (msgs[i].flags & I2C_M_RD)
				addr |= 1;
			if (i > 0 && msgs[i].flags &
			    I2C_M_RD && msgs[i].addr != 0x40 &&
			    msgs[i].addr != 0x41 &&
			    msgs[i].addr != 0x19) {
				/* workaround for a saa7134 i2c bug
				 * needed to talk to the mt352 demux
				 * thanks to pinnacle for the hint */
				int quirk = 0xfe;
				i2c_cont(1, " [%02x quirk]", quirk);
				i2c_send_byte(dev,START,quirk);
				i2c_recv_byte(dev);
			}
			i2c_cont(1, " < %02x", addr);
			rc = i2c_send_byte(dev,START,addr);
			if (rc < 0)
				 goto err;
		}
		if (msgs[i].flags & I2C_M_RD) {
			/* read bytes */
			i2c_dbg(2, "read bytes\n");
			for (byte = 0; byte < msgs[i].len; byte++) {
				i2c_cont(1, " =");
				rc = i2c_recv_byte(dev);
				if (rc < 0)
					goto err;
				i2c_cont(1, "%02x", rc);
				msgs[i].buf[byte] = rc;
			}
			/* discard mysterious extra byte when reading
			   from Samsung S5H1411.  i2c bus gets error
			   if we do not. */
			if (0x19 == msgs[i].addr) {
				i2c_cont(1, " ?");
				rc = i2c_recv_byte(dev);
				if (rc < 0)
					goto err;
				i2c_cont(1, "%02x", rc);
			}
		} else {
			/* write bytes */
			i2c_dbg(2, "write bytes\n");
			for (byte = 0; byte < msgs[i].len; byte++) {
				data = msgs[i].buf[byte];
				i2c_cont(1, " %02x", data);
				rc = i2c_send_byte(dev,CONTINUE,data);
				if (rc < 0)
					goto err;
			}
		}
	}
	i2c_dbg(2, "xfer done\n");
	i2c_cont(1, " >");
	i2c_set_attr(dev,STOP);
	rc = -EIO;
	if (!i2c_is_busy_wait(dev))
		goto err;
	status = i2c_get_status(dev);
	if (i2c_is_error(status))
		goto err;
	/* ensure that the bus is idle for at least one bit slot */
	msleep(1);

	i2c_cont(1, "\n");
	return num;
 err:
	if (1 == i2c_debug) {
		status = i2c_get_status(dev);
		i2c_cont(1, " ERROR: %s\n", str_i2c_status[status]);
	}
	return rc;
}

__attribute__((used)) static u32 functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static void saa7134_i2c_eeprom_md7134_gate(struct saa7134_dev *dev)
{
	u8 subaddr = 0x7, dmdregval;
	u8 data[2];
	int ret;
	struct i2c_msg i2cgatemsg_r[] = { {.addr = 0x08, .flags = 0,
					   .buf = &subaddr, .len = 1},
					  {.addr = 0x08,
					   .flags = I2C_M_RD,
					   .buf = &dmdregval, .len = 1}
					};
	struct i2c_msg i2cgatemsg_w[] = { {.addr = 0x08, .flags = 0,
					   .buf = data, .len = 2} };

	ret = i2c_transfer(&dev->i2c_adap, i2cgatemsg_r, 2);
	if ((ret == 2) && (dmdregval & 0x2)) {
		pr_debug("%s: DVB-T demod i2c gate was left closed\n",
			 dev->name);

		data[0] = subaddr;
		data[1] = (dmdregval & ~0x2);
		if (i2c_transfer(&dev->i2c_adap, i2cgatemsg_w, 1) != 1)
			pr_err("%s: EEPROM i2c gate open failure\n",
			  dev->name);
	}
}

__attribute__((used)) static int
saa7134_i2c_eeprom(struct saa7134_dev *dev, unsigned char *eedata, int len)
{
	unsigned char buf;
	int i,err;

	if (dev->board == SAA7134_BOARD_MD7134)
		saa7134_i2c_eeprom_md7134_gate(dev);

	dev->i2c_client.addr = 0xa0 >> 1;
	buf = 0;
	if (1 != (err = i2c_master_send(&dev->i2c_client,&buf,1))) {
		pr_info("%s: Huh, no eeprom present (err=%d)?\n",
		       dev->name,err);
		return -1;
	}
	if (len != (err = i2c_master_recv(&dev->i2c_client,eedata,len))) {
		pr_warn("%s: i2c eeprom read error (err=%d)\n",
		       dev->name,err);
		return -1;
	}

	for (i = 0; i < len; i += 16) {
		int size = (len - i) > 16 ? 16 : len - i;

		pr_info("i2c eeprom %02x: %*ph\n", i, size, &eedata[i]);
	}

	return 0;
}

__attribute__((used)) static void do_i2c_scan(struct i2c_client *c)
{
	unsigned char buf;
	int i,rc;

	for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
		c->addr = i;
		rc = i2c_master_recv(c,&buf,0);
		if (rc < 0)
			continue;
		pr_info("i2c scan: found device @ 0x%x  [%s]\n",
			 i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
	}
}

int saa7134_i2c_register(struct saa7134_dev *dev)
{
	dev->i2c_adap = saa7134_adap_template;
	dev->i2c_adap.dev.parent = &dev->pci->dev;
	strcpy(dev->i2c_adap.name,dev->name);
	dev->i2c_adap.algo_data = dev;
	i2c_set_adapdata(&dev->i2c_adap, &dev->v4l2_dev);
	i2c_add_adapter(&dev->i2c_adap);

	dev->i2c_client = saa7134_client_template;
	dev->i2c_client.adapter = &dev->i2c_adap;

	saa7134_i2c_eeprom(dev,dev->eedata,sizeof(dev->eedata));
	if (i2c_scan)
		do_i2c_scan(&dev->i2c_client);

	/* Instantiate the IR receiver device, if present */
	saa7134_probe_i2c_ir(dev);
	return 0;
}

int saa7134_i2c_unregister(struct saa7134_dev *dev)
{
	i2c_del_adapter(&dev->i2c_adap);
	return 0;
}

