#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {int /*<<< orphan*/  id; int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct i2c_msg {scalar_t__ addr; int flags; char* buf; int len; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct i2c_algo_iop3xx_data {int SR_enabled; int SR_received; int class; int timeout; scalar_t__ ioaddr; struct i2c_algo_iop3xx_data* algo_data; int /*<<< orphan*/  lock; int /*<<< orphan*/  waitq; int /*<<< orphan*/ * algo; int /*<<< orphan*/  nr; TYPE_1__ dev; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; scalar_t__ id; } ;
struct i2c_adapter {int SR_enabled; int SR_received; int class; int timeout; scalar_t__ ioaddr; struct i2c_adapter* algo_data; int /*<<< orphan*/  lock; int /*<<< orphan*/  waitq; int /*<<< orphan*/ * algo; int /*<<< orphan*/  nr; TYPE_1__ dev; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; scalar_t__ id; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int (* compare_func ) (unsigned int,unsigned int) ;

/* Variables and functions */
 scalar_t__ CR_OFFSET ; 
 scalar_t__ DBR_OFFSET ; 
 int EBUSY ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int I2C_CLASS_HWMON ; 
 int I2C_CLASS_SPD ; 
 int I2C_ERR_ALD ; 
 int I2C_ERR_BERR ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  IOP3XX_I2C_IO_SIZE ; 
 int IOP3XX_ICR_ALD_IE ; 
 int IOP3XX_ICR_BERR_IE ; 
 unsigned long IOP3XX_ICR_GCD ; 
 unsigned long IOP3XX_ICR_MSTART ; 
 unsigned long IOP3XX_ICR_MSTOP ; 
 unsigned long IOP3XX_ICR_NACK ; 
 int IOP3XX_ICR_RXFULL_IE ; 
 unsigned long IOP3XX_ICR_SCLEN ; 
 unsigned long IOP3XX_ICR_TBYTE ; 
 int IOP3XX_ICR_TXEMPTY_IE ; 
 unsigned long IOP3XX_ICR_UE ; 
 unsigned long IOP3XX_ICR_UNIT_RESET ; 
 int IOP3XX_ISR_ALD ; 
 int IOP3XX_ISR_BERRD ; 
 unsigned long IOP3XX_ISR_CLEARBITS ; 
 int IOP3XX_ISR_RXFULL ; 
 int IOP3XX_ISR_TXEMPTY ; 
 unsigned int IOP3XX_ISR_UNITBUSY ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ MYSAR ; 
 scalar_t__ SR_OFFSET ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 unsigned char i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int /*<<< orphan*/  i2c_add_numbered_adapter (struct i2c_algo_iop3xx_data*) ; 
 int /*<<< orphan*/  i2c_id ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iop3xx_i2c_algo ; 
 scalar_t__ ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct i2c_algo_iop3xx_data*) ; 
 struct i2c_algo_iop3xx_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct i2c_algo_iop3xx_data* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct i2c_algo_iop3xx_data*) ; 
 int /*<<< orphan*/  release_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct i2c_algo_iop3xx_data*) ; 
 int /*<<< orphan*/  request_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned char
iic_cook_addr(struct i2c_msg *msg)
{
	unsigned char addr;

	addr = i2c_8bit_addr_from_msg(msg);

	return addr;
}

__attribute__((used)) static void
iop3xx_i2c_reset(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
	/* Follows devman 9.3 */
	__raw_writel(IOP3XX_ICR_UNIT_RESET, iop3xx_adap->ioaddr + CR_OFFSET);
	__raw_writel(IOP3XX_ISR_CLEARBITS, iop3xx_adap->ioaddr + SR_OFFSET);
	__raw_writel(0, iop3xx_adap->ioaddr + CR_OFFSET);
}

__attribute__((used)) static void
iop3xx_i2c_enable(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
	u32 cr = IOP3XX_ICR_GCD | IOP3XX_ICR_SCLEN | IOP3XX_ICR_UE;

	/*
	 * Every time unit enable is asserted, GPOD needs to be cleared
	 * on IOP3XX to avoid data corruption on the bus.
	 */
#if defined(CONFIG_ARCH_IOP32X) || defined(CONFIG_ARCH_IOP33X)
	if (iop3xx_adap->id == 0) {
		gpio_set_value(7, 0);
		gpio_set_value(6, 0);
	} else {
		gpio_set_value(5, 0);
		gpio_set_value(4, 0);
	}
#endif
	/* NB SR bits not same position as CR IE bits :-( */
	iop3xx_adap->SR_enabled =
		IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD |
		IOP3XX_ISR_RXFULL | IOP3XX_ISR_TXEMPTY;

	cr |= IOP3XX_ICR_ALD_IE | IOP3XX_ICR_BERR_IE |
		IOP3XX_ICR_RXFULL_IE | IOP3XX_ICR_TXEMPTY_IE;

	__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
}

__attribute__((used)) static void
iop3xx_i2c_transaction_cleanup(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
	unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);

	cr &= ~(IOP3XX_ICR_MSTART | IOP3XX_ICR_TBYTE |
		IOP3XX_ICR_MSTOP | IOP3XX_ICR_SCLEN);

	__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
}

__attribute__((used)) static irqreturn_t
iop3xx_i2c_irq_handler(int this_irq, void *dev_id)
{
	struct i2c_algo_iop3xx_data *iop3xx_adap = dev_id;
	u32 sr = __raw_readl(iop3xx_adap->ioaddr + SR_OFFSET);

	if ((sr &= iop3xx_adap->SR_enabled)) {
		__raw_writel(sr, iop3xx_adap->ioaddr + SR_OFFSET);
		iop3xx_adap->SR_received |= sr;
		wake_up_interruptible(&iop3xx_adap->waitq);
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int
iop3xx_i2c_error(u32 sr)
{
	int rc = 0;

	if ((sr & IOP3XX_ISR_BERRD)) {
		if ( !rc ) rc = -I2C_ERR_BERR;
	}
	if ((sr & IOP3XX_ISR_ALD)) {
		if ( !rc ) rc = -I2C_ERR_ALD;
	}
	return rc;
}

__attribute__((used)) static inline u32
iop3xx_i2c_get_srstat(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
	unsigned long flags;
	u32 sr;

	spin_lock_irqsave(&iop3xx_adap->lock, flags);
	sr = iop3xx_adap->SR_received;
	iop3xx_adap->SR_received = 0;
	spin_unlock_irqrestore(&iop3xx_adap->lock, flags);

	return sr;
}

__attribute__((used)) static int
iop3xx_i2c_wait_event(struct i2c_algo_iop3xx_data *iop3xx_adap,
			  unsigned flags, unsigned* status,
			  compare_func compare)
{
	unsigned sr = 0;
	int interrupted;
	int done;
	int rc = 0;

	do {
		interrupted = wait_event_interruptible_timeout (
			iop3xx_adap->waitq,
			(done = compare( sr = iop3xx_i2c_get_srstat(iop3xx_adap) ,flags )),
			1 * HZ
			);
		if ((rc = iop3xx_i2c_error(sr)) < 0) {
			*status = sr;
			return rc;
		} else if (!interrupted) {
			*status = sr;
			return -ETIMEDOUT;
		}
	} while(!done);

	*status = sr;

	return 0;
}

__attribute__((used)) static int
all_bits_clear(unsigned test, unsigned mask)
{
	return (test & mask) == 0;
}

__attribute__((used)) static int
any_bits_set(unsigned test, unsigned mask)
{
	return (test & mask) != 0;
}

__attribute__((used)) static int
iop3xx_i2c_wait_tx_done(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
	return iop3xx_i2c_wait_event(
		iop3xx_adap,
	        IOP3XX_ISR_TXEMPTY | IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD,
		status, any_bits_set);
}

__attribute__((used)) static int
iop3xx_i2c_wait_rx_done(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
	return iop3xx_i2c_wait_event(
		iop3xx_adap,
		IOP3XX_ISR_RXFULL | IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD,
		status,	any_bits_set);
}

__attribute__((used)) static int
iop3xx_i2c_wait_idle(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
	return iop3xx_i2c_wait_event(
		iop3xx_adap, IOP3XX_ISR_UNITBUSY, status, all_bits_clear);
}

__attribute__((used)) static int
iop3xx_i2c_send_target_addr(struct i2c_algo_iop3xx_data *iop3xx_adap,
				struct i2c_msg* msg)
{
	unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
	int status;
	int rc;

	/* avoid writing to my slave address (hangs on 80331),
	 * forbidden in Intel developer manual
	 */
	if (msg->addr == MYSAR) {
		return -EBUSY;
	}

	__raw_writel(iic_cook_addr(msg), iop3xx_adap->ioaddr + DBR_OFFSET);

	cr &= ~(IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK);
	cr |= IOP3XX_ICR_MSTART | IOP3XX_ICR_TBYTE;

	__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
	rc = iop3xx_i2c_wait_tx_done(iop3xx_adap, &status);

	return rc;
}

__attribute__((used)) static int
iop3xx_i2c_write_byte(struct i2c_algo_iop3xx_data *iop3xx_adap, char byte,
				int stop)
{
	unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
	int status;
	int rc = 0;

	__raw_writel(byte, iop3xx_adap->ioaddr + DBR_OFFSET);
	cr &= ~IOP3XX_ICR_MSTART;
	if (stop) {
		cr |= IOP3XX_ICR_MSTOP;
	} else {
		cr &= ~IOP3XX_ICR_MSTOP;
	}
	cr |= IOP3XX_ICR_TBYTE;
	__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
	rc = iop3xx_i2c_wait_tx_done(iop3xx_adap, &status);

	return rc;
}

__attribute__((used)) static int
iop3xx_i2c_read_byte(struct i2c_algo_iop3xx_data *iop3xx_adap, char* byte,
				int stop)
{
	unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
	int status;
	int rc = 0;

	cr &= ~IOP3XX_ICR_MSTART;

	if (stop) {
		cr |= IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK;
	} else {
		cr &= ~(IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK);
	}
	cr |= IOP3XX_ICR_TBYTE;
	__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);

	rc = iop3xx_i2c_wait_rx_done(iop3xx_adap, &status);

	*byte = __raw_readl(iop3xx_adap->ioaddr + DBR_OFFSET);

	return rc;
}

__attribute__((used)) static int
iop3xx_i2c_writebytes(struct i2c_adapter *i2c_adap, const char *buf, int count)
{
	struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
	int ii;
	int rc = 0;

	for (ii = 0; rc == 0 && ii != count; ++ii)
		rc = iop3xx_i2c_write_byte(iop3xx_adap, buf[ii], ii==count-1);
	return rc;
}

__attribute__((used)) static int
iop3xx_i2c_readbytes(struct i2c_adapter *i2c_adap, char *buf, int count)
{
	struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
	int ii;
	int rc = 0;

	for (ii = 0; rc == 0 && ii != count; ++ii)
		rc = iop3xx_i2c_read_byte(iop3xx_adap, &buf[ii], ii==count-1);

	return rc;
}

__attribute__((used)) static int
iop3xx_i2c_handle_msg(struct i2c_adapter *i2c_adap, struct i2c_msg* pmsg)
{
	struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
	int rc;

	rc = iop3xx_i2c_send_target_addr(iop3xx_adap, pmsg);
	if (rc < 0) {
		return rc;
	}

	if ((pmsg->flags&I2C_M_RD)) {
		return iop3xx_i2c_readbytes(i2c_adap, pmsg->buf, pmsg->len);
	} else {
		return iop3xx_i2c_writebytes(i2c_adap, pmsg->buf, pmsg->len);
	}
}

__attribute__((used)) static int
iop3xx_i2c_master_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs,
				int num)
{
	struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
	int im = 0;
	int ret = 0;
	int status;

	iop3xx_i2c_wait_idle(iop3xx_adap, &status);
	iop3xx_i2c_reset(iop3xx_adap);
	iop3xx_i2c_enable(iop3xx_adap);

	for (im = 0; ret == 0 && im != num; im++) {
		ret = iop3xx_i2c_handle_msg(i2c_adap, &msgs[im]);
	}

	iop3xx_i2c_transaction_cleanup(iop3xx_adap);

	if(ret)
		return ret;

	return im;
}

__attribute__((used)) static u32
iop3xx_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int
iop3xx_i2c_remove(struct platform_device *pdev)
{
	struct i2c_adapter *padapter = platform_get_drvdata(pdev);
	struct i2c_algo_iop3xx_data *adapter_data =
		(struct i2c_algo_iop3xx_data *)padapter->algo_data;
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	unsigned long cr = __raw_readl(adapter_data->ioaddr + CR_OFFSET);

	/*
	 * Disable the actual HW unit
	 */
	cr &= ~(IOP3XX_ICR_ALD_IE | IOP3XX_ICR_BERR_IE |
		IOP3XX_ICR_RXFULL_IE | IOP3XX_ICR_TXEMPTY_IE);
	__raw_writel(cr, adapter_data->ioaddr + CR_OFFSET);

	iounmap(adapter_data->ioaddr);
	release_mem_region(res->start, IOP3XX_I2C_IO_SIZE);
	kfree(adapter_data);
	kfree(padapter);

	return 0;
}

__attribute__((used)) static int
iop3xx_i2c_probe(struct platform_device *pdev)
{
	struct resource *res;
	int ret, irq;
	struct i2c_adapter *new_adapter;
	struct i2c_algo_iop3xx_data *adapter_data;

	new_adapter = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
	if (!new_adapter) {
		ret = -ENOMEM;
		goto out;
	}

	adapter_data = kzalloc(sizeof(struct i2c_algo_iop3xx_data), GFP_KERNEL);
	if (!adapter_data) {
		ret = -ENOMEM;
		goto free_adapter;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		ret = -ENODEV;
		goto free_both;
	}

	if (!request_mem_region(res->start, IOP3XX_I2C_IO_SIZE, pdev->name)) {
		ret = -EBUSY;
		goto free_both;
	}

	/* set the adapter enumeration # */
	adapter_data->id = i2c_id++;

	adapter_data->ioaddr = ioremap(res->start, IOP3XX_I2C_IO_SIZE);
	if (!adapter_data->ioaddr) {
		ret = -ENOMEM;
		goto release_region;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		ret = -ENXIO;
		goto unmap;
	}
	ret = request_irq(irq, iop3xx_i2c_irq_handler, 0,
				pdev->name, adapter_data);

	if (ret) {
		ret = -EIO;
		goto unmap;
	}

	memcpy(new_adapter->name, pdev->name, strlen(pdev->name));
	new_adapter->owner = THIS_MODULE;
	new_adapter->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
	new_adapter->dev.parent = &pdev->dev;
	new_adapter->nr = pdev->id;

	/*
	 * Default values...should these come in from board code?
	 */
	new_adapter->timeout = HZ;
	new_adapter->algo = &iop3xx_i2c_algo;

	init_waitqueue_head(&adapter_data->waitq);
	spin_lock_init(&adapter_data->lock);

	iop3xx_i2c_reset(adapter_data);
	iop3xx_i2c_enable(adapter_data);

	platform_set_drvdata(pdev, new_adapter);
	new_adapter->algo_data = adapter_data;

	i2c_add_numbered_adapter(new_adapter);

	return 0;

unmap:
	iounmap(adapter_data->ioaddr);

release_region:
	release_mem_region(res->start, IOP3XX_I2C_IO_SIZE);

free_both:
	kfree(adapter_data);

free_adapter:
	kfree(new_adapter);

out:
	return ret;
}

