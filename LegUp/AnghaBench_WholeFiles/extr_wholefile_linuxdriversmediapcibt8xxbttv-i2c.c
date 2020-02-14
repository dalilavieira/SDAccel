#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_9__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct v4l2_device {int dummy; } ;
struct i2c_msg {int len; int addr; int* buf; int flags; } ;
struct i2c_client {unsigned char addr; TYPE_4__* adapter; int /*<<< orphan*/  name; } ;
struct i2c_adapter {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_13__ {int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  owner; TYPE_9__* algo_data; int /*<<< orphan*/ * algo; } ;
struct TYPE_14__ {char* name; } ;
struct TYPE_12__ {int nr; TYPE_4__ i2c_adap; TYPE_5__ v4l2_dev; TYPE_2__* pci; } ;
struct TYPE_15__ {int udelay; struct bttv* data; } ;
struct bttv {int i2c_state; int i2c_done; scalar_t__ i2c_rc; int use_i2c_hw; int id; TYPE_3__ c; struct i2c_client i2c_client; TYPE_9__ i2c_algo; int /*<<< orphan*/  i2c_queue; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (char**) ; 
 int /*<<< orphan*/  BT848_I2C ; 
 int BT848_I2C_W3B ; 
 int BT848_INT_I2CDONE ; 
 int BT848_INT_RACK ; 
 int /*<<< orphan*/  BT848_INT_STAT ; 
 int BT878_I2C_NOSTART ; 
 int BT878_I2C_NOSTOP ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  ERESTARTSYS ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_HW ; 
 int I2C_M_RD ; 
 int I2C_NAME_SIZE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int btread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bttv_algo ; 
 TYPE_9__ bttv_i2c_algo_bit_template ; 
 scalar_t__ bttv_verbose ; 
 int /*<<< orphan*/  btwrite (int,int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_add_adapter (TYPE_4__*) ; 
 scalar_t__ i2c_bit_add_bus (TYPE_4__*) ; 
 scalar_t__ i2c_debug ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_4__*) ; 
 char** i2c_devs ; 
 struct v4l2_device* i2c_get_adapdata (struct i2c_adapter*) ; 
 scalar_t__ i2c_hw ; 
 int i2c_master_recv (struct i2c_client*,unsigned char*,int) ; 
 int i2c_master_send (struct i2c_client*,unsigned char*,int) ; 
 scalar_t__ i2c_scan ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_4__*,TYPE_5__*) ; 
 int i2c_udelay ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*,int,unsigned char) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int,int,char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 struct bttv* to_bttv (struct v4l2_device*) ; 
 int /*<<< orphan*/  tveeprom_read (struct i2c_client*,unsigned char*,int) ; 
 int /*<<< orphan*/  wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bttv_bit_setscl(void *data, int state)
{
	struct bttv *btv = (struct bttv*)data;

	if (state)
		btv->i2c_state |= 0x02;
	else
		btv->i2c_state &= ~0x02;
	btwrite(btv->i2c_state, BT848_I2C);
	btread(BT848_I2C);
}

__attribute__((used)) static void bttv_bit_setsda(void *data, int state)
{
	struct bttv *btv = (struct bttv*)data;

	if (state)
		btv->i2c_state |= 0x01;
	else
		btv->i2c_state &= ~0x01;
	btwrite(btv->i2c_state, BT848_I2C);
	btread(BT848_I2C);
}

__attribute__((used)) static int bttv_bit_getscl(void *data)
{
	struct bttv *btv = (struct bttv*)data;
	int state;

	state = btread(BT848_I2C) & 0x02 ? 1 : 0;
	return state;
}

__attribute__((used)) static int bttv_bit_getsda(void *data)
{
	struct bttv *btv = (struct bttv*)data;
	int state;

	state = btread(BT848_I2C) & 0x01;
	return state;
}

__attribute__((used)) static u32 functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int
bttv_i2c_wait_done(struct bttv *btv)
{
	int rc = 0;

	/* timeout */
	if (wait_event_interruptible_timeout(btv->i2c_queue,
	    btv->i2c_done, msecs_to_jiffies(85)) == -ERESTARTSYS)
		rc = -EIO;

	if (btv->i2c_done & BT848_INT_RACK)
		rc = 1;
	btv->i2c_done = 0;
	return rc;
}

__attribute__((used)) static int
bttv_i2c_sendbytes(struct bttv *btv, const struct i2c_msg *msg, int last)
{
	u32 xmit;
	int retval,cnt;

	/* sanity checks */
	if (0 == msg->len)
		return -EINVAL;

	/* start, address + first byte */
	xmit = (msg->addr << 25) | (msg->buf[0] << 16) | I2C_HW;
	if (msg->len > 1 || !last)
		xmit |= BT878_I2C_NOSTOP;
	btwrite(xmit, BT848_I2C);
	retval = bttv_i2c_wait_done(btv);
	if (retval < 0)
		goto err;
	if (retval == 0)
		goto eio;
	if (i2c_debug) {
		pr_cont(" <W %02x %02x", msg->addr << 1, msg->buf[0]);
	}

	for (cnt = 1; cnt < msg->len; cnt++ ) {
		/* following bytes */
		xmit = (msg->buf[cnt] << 24) | I2C_HW | BT878_I2C_NOSTART;
		if (cnt < msg->len-1 || !last)
			xmit |= BT878_I2C_NOSTOP;
		btwrite(xmit, BT848_I2C);
		retval = bttv_i2c_wait_done(btv);
		if (retval < 0)
			goto err;
		if (retval == 0)
			goto eio;
		if (i2c_debug)
			pr_cont(" %02x", msg->buf[cnt]);
	}
	if (i2c_debug && !(xmit & BT878_I2C_NOSTOP))
		pr_cont(">\n");
	return msg->len;

 eio:
	retval = -EIO;
 err:
	if (i2c_debug)
		pr_cont(" ERR: %d\n",retval);
	return retval;
}

__attribute__((used)) static int
bttv_i2c_readbytes(struct bttv *btv, const struct i2c_msg *msg, int last)
{
	u32 xmit;
	u32 cnt;
	int retval;

	for (cnt = 0; cnt < msg->len; cnt++) {
		xmit = (msg->addr << 25) | (1 << 24) | I2C_HW;
		if (cnt < msg->len-1)
			xmit |= BT848_I2C_W3B;
		if (cnt < msg->len-1 || !last)
			xmit |= BT878_I2C_NOSTOP;
		if (cnt)
			xmit |= BT878_I2C_NOSTART;

		if (i2c_debug) {
			if (!(xmit & BT878_I2C_NOSTART))
				pr_cont(" <R %02x", (msg->addr << 1) +1);
		}

		btwrite(xmit, BT848_I2C);
		retval = bttv_i2c_wait_done(btv);
		if (retval < 0)
			goto err;
		if (retval == 0)
			goto eio;
		msg->buf[cnt] = ((u32)btread(BT848_I2C) >> 8) & 0xff;
		if (i2c_debug) {
			pr_cont(" =%02x", msg->buf[cnt]);
		}
		if (i2c_debug && !(xmit & BT878_I2C_NOSTOP))
			pr_cont(" >\n");
	}


	return msg->len;

 eio:
	retval = -EIO;
 err:
	if (i2c_debug)
		pr_cont(" ERR: %d\n",retval);
	return retval;
}

__attribute__((used)) static int bttv_i2c_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
	struct v4l2_device *v4l2_dev = i2c_get_adapdata(i2c_adap);
	struct bttv *btv = to_bttv(v4l2_dev);
	int retval = 0;
	int i;

	if (i2c_debug)
		pr_debug("bt-i2c:");

	btwrite(BT848_INT_I2CDONE|BT848_INT_RACK, BT848_INT_STAT);
	for (i = 0 ; i < num; i++) {
		if (msgs[i].flags & I2C_M_RD) {
			/* read */
			retval = bttv_i2c_readbytes(btv, &msgs[i], i+1 == num);
			if (retval < 0)
				goto err;
		} else {
			/* write */
			retval = bttv_i2c_sendbytes(btv, &msgs[i], i+1 == num);
			if (retval < 0)
				goto err;
		}
	}
	return num;

 err:
	return retval;
}

int bttv_I2CRead(struct bttv *btv, unsigned char addr, char *probe_for)
{
	unsigned char buffer = 0;

	if (0 != btv->i2c_rc)
		return -1;
	if (bttv_verbose && NULL != probe_for)
		pr_info("%d: i2c: checking for %s @ 0x%02x... ",
			btv->c.nr, probe_for, addr);
	btv->i2c_client.addr = addr >> 1;
	if (1 != i2c_master_recv(&btv->i2c_client, &buffer, 1)) {
		if (NULL != probe_for) {
			if (bttv_verbose)
				pr_cont("not found\n");
		} else
			pr_warn("%d: i2c read 0x%x: error\n",
				btv->c.nr, addr);
		return -1;
	}
	if (bttv_verbose && NULL != probe_for)
		pr_cont("found\n");
	return buffer;
}

int bttv_I2CWrite(struct bttv *btv, unsigned char addr, unsigned char b1,
		    unsigned char b2, int both)
{
	unsigned char buffer[2];
	int bytes = both ? 2 : 1;

	if (0 != btv->i2c_rc)
		return -1;
	btv->i2c_client.addr = addr >> 1;
	buffer[0] = b1;
	buffer[1] = b2;
	if (bytes != i2c_master_send(&btv->i2c_client, buffer, bytes))
		return -1;
	return 0;
}

void bttv_readee(struct bttv *btv, unsigned char *eedata, int addr)
{
	memset(eedata, 0, 256);
	if (0 != btv->i2c_rc)
		return;
	btv->i2c_client.addr = addr >> 1;
	tveeprom_read(&btv->i2c_client, eedata, 256);
}

__attribute__((used)) static void do_i2c_scan(char *name, struct i2c_client *c)
{
	unsigned char buf;
	int i,rc;

	for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
		c->addr = i;
		rc = i2c_master_recv(c,&buf,0);
		if (rc < 0)
			continue;
		pr_info("%s: i2c scan: found device @ 0x%x  [%s]\n",
			name, i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
	}
}

int init_bttv_i2c(struct bttv *btv)
{
	strlcpy(btv->i2c_client.name, "bttv internal", I2C_NAME_SIZE);

	if (i2c_hw)
		btv->use_i2c_hw = 1;
	if (btv->use_i2c_hw) {
		/* bt878 */
		strlcpy(btv->c.i2c_adap.name, "bt878",
			sizeof(btv->c.i2c_adap.name));
		btv->c.i2c_adap.algo = &bttv_algo;
	} else {
		/* bt848 */
	/* Prevents usage of invalid delay values */
		if (i2c_udelay<5)
			i2c_udelay=5;

		strlcpy(btv->c.i2c_adap.name, "bttv",
			sizeof(btv->c.i2c_adap.name));
		btv->i2c_algo = bttv_i2c_algo_bit_template;
		btv->i2c_algo.udelay = i2c_udelay;
		btv->i2c_algo.data = btv;
		btv->c.i2c_adap.algo_data = &btv->i2c_algo;
	}
	btv->c.i2c_adap.owner = THIS_MODULE;

	btv->c.i2c_adap.dev.parent = &btv->c.pci->dev;
	snprintf(btv->c.i2c_adap.name, sizeof(btv->c.i2c_adap.name),
		 "bt%d #%d [%s]", btv->id, btv->c.nr,
		 btv->use_i2c_hw ? "hw" : "sw");

	i2c_set_adapdata(&btv->c.i2c_adap, &btv->c.v4l2_dev);
	btv->i2c_client.adapter = &btv->c.i2c_adap;


	if (btv->use_i2c_hw) {
		btv->i2c_rc = i2c_add_adapter(&btv->c.i2c_adap);
	} else {
		bttv_bit_setscl(btv,1);
		bttv_bit_setsda(btv,1);
		btv->i2c_rc = i2c_bit_add_bus(&btv->c.i2c_adap);
	}
	if (0 == btv->i2c_rc && i2c_scan)
		do_i2c_scan(btv->c.v4l2_dev.name, &btv->i2c_client);

	return btv->i2c_rc;
}

int fini_bttv_i2c(struct bttv *btv)
{
	if (btv->i2c_rc == 0)
		i2c_del_adapter(&btv->c.i2c_adap);

	return 0;
}

