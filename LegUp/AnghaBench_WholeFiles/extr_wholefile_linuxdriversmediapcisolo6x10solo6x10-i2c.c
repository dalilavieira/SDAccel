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
typedef  void* u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct solo_dev {int irq_mask; scalar_t__ i2c_id; scalar_t__ i2c_state; scalar_t__ i2c_msg_ptr; scalar_t__ i2c_msg_num; struct i2c_adapter* i2c_adap; TYPE_2__* pdev; int /*<<< orphan*/  i2c_mutex; int /*<<< orphan*/  i2c_wait; struct i2c_msg* i2c_msg; scalar_t__ reg_base; } ;
struct i2c_msg {int flags; int addr; int len; void** buf; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct i2c_adapter {int retries; struct solo_dev* algo_data; TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ CHK_FLAGS (int,int) ; 
 int /*<<< orphan*/  DEFINE_WAIT (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENXIO ; 
 int HZ ; 
 int I2C_FUNC_I2C ; 
 int I2C_M_NOSTART ; 
 int I2C_M_NO_RD_ACK ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 void* IIC_STATE_IDLE ; 
#define  IIC_STATE_READ 130 
#define  IIC_STATE_START 129 
 scalar_t__ IIC_STATE_STOP ; 
#define  IIC_STATE_WRITE 128 
 int /*<<< orphan*/  PCI_STATUS ; 
 char* SOLO6X10_NAME ; 
 int SOLO_I2C_ADAPTERS ; 
 int SOLO_IIC_ACK_EN ; 
 int SOLO_IIC_CFG ; 
 int SOLO_IIC_CH_SET (scalar_t__) ; 
 int SOLO_IIC_CTRL ; 
 int SOLO_IIC_ENABLE ; 
 int SOLO_IIC_PRESCALE (int) ; 
 int SOLO_IIC_READ ; 
 int SOLO_IIC_RXD ; 
 int SOLO_IIC_START ; 
 int SOLO_IIC_STATE_SIG_ERR ; 
 int SOLO_IIC_STATE_TRNS ; 
 int SOLO_IIC_STOP ; 
 int SOLO_IIC_TXD ; 
 int SOLO_IIC_WRITE ; 
 int SOLO_IRQ_IIC ; 
 int SOLO_IRQ_MASK ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  finish_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_read_config_word (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  prepare_to_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 unsigned long schedule_timeout (unsigned long) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*,int) ; 
 int /*<<< orphan*/  solo_i2c_algo ; 
 int /*<<< orphan*/  wait ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline u32 solo_reg_read(struct solo_dev *solo_dev, int reg)
{
	return readl(solo_dev->reg_base + reg);
}

__attribute__((used)) static inline void solo_reg_write(struct solo_dev *solo_dev, int reg,
				  u32 data)
{
	u16 val;

	writel(data, solo_dev->reg_base + reg);
	pci_read_config_word(solo_dev->pdev, PCI_STATUS, &val);
}

__attribute__((used)) static inline void solo_irq_on(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask |= mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

__attribute__((used)) static inline void solo_irq_off(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask &= ~mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

u8 solo_i2c_readbyte(struct solo_dev *solo_dev, int id, u8 addr, u8 off)
{
	struct i2c_msg msgs[2];
	u8 data;

	msgs[0].flags = 0;
	msgs[0].addr = addr;
	msgs[0].len = 1;
	msgs[0].buf = &off;

	msgs[1].flags = I2C_M_RD;
	msgs[1].addr = addr;
	msgs[1].len = 1;
	msgs[1].buf = &data;

	i2c_transfer(&solo_dev->i2c_adap[id], msgs, 2);

	return data;
}

void solo_i2c_writebyte(struct solo_dev *solo_dev, int id, u8 addr,
			u8 off, u8 data)
{
	struct i2c_msg msgs;
	u8 buf[2];

	buf[0] = off;
	buf[1] = data;
	msgs.flags = 0;
	msgs.addr = addr;
	msgs.len = 2;
	msgs.buf = buf;

	i2c_transfer(&solo_dev->i2c_adap[id], &msgs, 1);
}

__attribute__((used)) static void solo_i2c_flush(struct solo_dev *solo_dev, int wr)
{
	u32 ctrl;

	ctrl = SOLO_IIC_CH_SET(solo_dev->i2c_id);

	if (solo_dev->i2c_state == IIC_STATE_START)
		ctrl |= SOLO_IIC_START;

	if (wr) {
		ctrl |= SOLO_IIC_WRITE;
	} else {
		ctrl |= SOLO_IIC_READ;
		if (!(solo_dev->i2c_msg->flags & I2C_M_NO_RD_ACK))
			ctrl |= SOLO_IIC_ACK_EN;
	}

	if (solo_dev->i2c_msg_ptr == solo_dev->i2c_msg->len)
		ctrl |= SOLO_IIC_STOP;

	solo_reg_write(solo_dev, SOLO_IIC_CTRL, ctrl);
}

__attribute__((used)) static void solo_i2c_start(struct solo_dev *solo_dev)
{
	u32 addr = solo_dev->i2c_msg->addr << 1;

	if (solo_dev->i2c_msg->flags & I2C_M_RD)
		addr |= 1;

	solo_dev->i2c_state = IIC_STATE_START;
	solo_reg_write(solo_dev, SOLO_IIC_TXD, addr);
	solo_i2c_flush(solo_dev, 1);
}

__attribute__((used)) static void solo_i2c_stop(struct solo_dev *solo_dev)
{
	solo_irq_off(solo_dev, SOLO_IRQ_IIC);
	solo_reg_write(solo_dev, SOLO_IIC_CTRL, 0);
	solo_dev->i2c_state = IIC_STATE_STOP;
	wake_up(&solo_dev->i2c_wait);
}

__attribute__((used)) static int solo_i2c_handle_read(struct solo_dev *solo_dev)
{
prepare_read:
	if (solo_dev->i2c_msg_ptr != solo_dev->i2c_msg->len) {
		solo_i2c_flush(solo_dev, 0);
		return 0;
	}

	solo_dev->i2c_msg_ptr = 0;
	solo_dev->i2c_msg++;
	solo_dev->i2c_msg_num--;

	if (solo_dev->i2c_msg_num == 0) {
		solo_i2c_stop(solo_dev);
		return 0;
	}

	if (!(solo_dev->i2c_msg->flags & I2C_M_NOSTART)) {
		solo_i2c_start(solo_dev);
	} else {
		if (solo_dev->i2c_msg->flags & I2C_M_RD)
			goto prepare_read;
		else
			solo_i2c_stop(solo_dev);
	}

	return 0;
}

__attribute__((used)) static int solo_i2c_handle_write(struct solo_dev *solo_dev)
{
retry_write:
	if (solo_dev->i2c_msg_ptr != solo_dev->i2c_msg->len) {
		solo_reg_write(solo_dev, SOLO_IIC_TXD,
			       solo_dev->i2c_msg->buf[solo_dev->i2c_msg_ptr]);
		solo_dev->i2c_msg_ptr++;
		solo_i2c_flush(solo_dev, 1);
		return 0;
	}

	solo_dev->i2c_msg_ptr = 0;
	solo_dev->i2c_msg++;
	solo_dev->i2c_msg_num--;

	if (solo_dev->i2c_msg_num == 0) {
		solo_i2c_stop(solo_dev);
		return 0;
	}

	if (!(solo_dev->i2c_msg->flags & I2C_M_NOSTART)) {
		solo_i2c_start(solo_dev);
	} else {
		if (solo_dev->i2c_msg->flags & I2C_M_RD)
			solo_i2c_stop(solo_dev);
		else
			goto retry_write;
	}

	return 0;
}

int solo_i2c_isr(struct solo_dev *solo_dev)
{
	u32 status = solo_reg_read(solo_dev, SOLO_IIC_CTRL);
	int ret = -EINVAL;


	if (CHK_FLAGS(status, SOLO_IIC_STATE_TRNS | SOLO_IIC_STATE_SIG_ERR)
	    || solo_dev->i2c_id < 0) {
		solo_i2c_stop(solo_dev);
		return -ENXIO;
	}

	switch (solo_dev->i2c_state) {
	case IIC_STATE_START:
		if (solo_dev->i2c_msg->flags & I2C_M_RD) {
			solo_dev->i2c_state = IIC_STATE_READ;
			ret = solo_i2c_handle_read(solo_dev);
			break;
		}

		solo_dev->i2c_state = IIC_STATE_WRITE;
		/* fall through */
	case IIC_STATE_WRITE:
		ret = solo_i2c_handle_write(solo_dev);
		break;

	case IIC_STATE_READ:
		solo_dev->i2c_msg->buf[solo_dev->i2c_msg_ptr] =
			solo_reg_read(solo_dev, SOLO_IIC_RXD);
		solo_dev->i2c_msg_ptr++;

		ret = solo_i2c_handle_read(solo_dev);
		break;

	default:
		solo_i2c_stop(solo_dev);
	}

	return ret;
}

__attribute__((used)) static int solo_i2c_master_xfer(struct i2c_adapter *adap,
				struct i2c_msg msgs[], int num)
{
	struct solo_dev *solo_dev = adap->algo_data;
	unsigned long timeout;
	int ret;
	int i;
	DEFINE_WAIT(wait);

	for (i = 0; i < SOLO_I2C_ADAPTERS; i++) {
		if (&solo_dev->i2c_adap[i] == adap)
			break;
	}

	if (i == SOLO_I2C_ADAPTERS)
		return num; /* XXX Right return value for failure? */

	mutex_lock(&solo_dev->i2c_mutex);
	solo_dev->i2c_id = i;
	solo_dev->i2c_msg = msgs;
	solo_dev->i2c_msg_num = num;
	solo_dev->i2c_msg_ptr = 0;

	solo_reg_write(solo_dev, SOLO_IIC_CTRL, 0);
	solo_irq_on(solo_dev, SOLO_IRQ_IIC);
	solo_i2c_start(solo_dev);

	timeout = HZ / 2;

	for (;;) {
		prepare_to_wait(&solo_dev->i2c_wait, &wait,
				TASK_INTERRUPTIBLE);

		if (solo_dev->i2c_state == IIC_STATE_STOP)
			break;

		timeout = schedule_timeout(timeout);
		if (!timeout)
			break;

		if (signal_pending(current))
			break;
	}

	finish_wait(&solo_dev->i2c_wait, &wait);
	ret = num - solo_dev->i2c_msg_num;
	solo_dev->i2c_state = IIC_STATE_IDLE;
	solo_dev->i2c_id = -1;

	mutex_unlock(&solo_dev->i2c_mutex);

	return ret;
}

__attribute__((used)) static u32 solo_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C;
}

int solo_i2c_init(struct solo_dev *solo_dev)
{
	int i;
	int ret;

	solo_reg_write(solo_dev, SOLO_IIC_CFG,
		       SOLO_IIC_PRESCALE(8) | SOLO_IIC_ENABLE);

	solo_dev->i2c_id = -1;
	solo_dev->i2c_state = IIC_STATE_IDLE;
	init_waitqueue_head(&solo_dev->i2c_wait);
	mutex_init(&solo_dev->i2c_mutex);

	for (i = 0; i < SOLO_I2C_ADAPTERS; i++) {
		struct i2c_adapter *adap = &solo_dev->i2c_adap[i];

		snprintf(adap->name, I2C_NAME_SIZE, "%s I2C %d",
			 SOLO6X10_NAME, i);
		adap->algo = &solo_i2c_algo;
		adap->algo_data = solo_dev;
		adap->retries = 1;
		adap->dev.parent = &solo_dev->pdev->dev;

		ret = i2c_add_adapter(adap);
		if (ret) {
			adap->algo_data = NULL;
			break;
		}
	}

	if (ret) {
		for (i = 0; i < SOLO_I2C_ADAPTERS; i++) {
			if (!solo_dev->i2c_adap[i].algo_data)
				break;
			i2c_del_adapter(&solo_dev->i2c_adap[i]);
			solo_dev->i2c_adap[i].algo_data = NULL;
		}
		return ret;
	}

	return 0;
}

void solo_i2c_exit(struct solo_dev *solo_dev)
{
	int i;

	for (i = 0; i < SOLO_I2C_ADAPTERS; i++) {
		if (!solo_dev->i2c_adap[i].algo_data)
			continue;
		i2c_del_adapter(&solo_dev->i2c_adap[i]);
		solo_dev->i2c_adap[i].algo_data = NULL;
	}
}

