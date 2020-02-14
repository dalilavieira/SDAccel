#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct sh7760_i2c_platdata {int speed_khz; } ;
struct resource {scalar_t__ start; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  id; int /*<<< orphan*/  name; } ;
struct i2c_msg {char* buf; unsigned long len; int addr; int flags; } ;
struct i2c_adapter {int nr; int retries; int /*<<< orphan*/  dev; struct cami2c* algo_data; } ;
struct clk {unsigned long rate; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_5__ {int class; int retries; int /*<<< orphan*/  name; TYPE_1__ dev; struct cami2c* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  nr; } ;
struct cami2c {int status; int flags; int irq; struct cami2c* ioarea; scalar_t__ iobase; TYPE_2__ adap; struct i2c_msg* msg; int /*<<< orphan*/  xfer_done; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EREMOTEIO ; 
 unsigned long FCR_RFRST ; 
 unsigned long FCR_TFRST ; 
 unsigned long FIER_RXIE ; 
 unsigned long FIER_TEIE ; 
 unsigned long FIER_TXIE ; 
 int FIFO_SIZE ; 
 unsigned long FSR_RDF ; 
 unsigned long FSR_TDFE ; 
 unsigned long FSR_TEND ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2CCCR ; 
 int I2CFCR ; 
 int I2CFIER ; 
 int I2CFSR ; 
 int I2CMAR ; 
 int I2CMCR ; 
 int I2CMIER ; 
 int I2CMSR ; 
 int I2CRFDR ; 
 int I2CRXTX ; 
 int I2CSAR ; 
 int I2CSCR ; 
 int I2CSIER ; 
 int I2CSSR ; 
 int I2CTFDR ; 
 int I2C_CLASS_HWMON ; 
 int I2C_CLASS_SPD ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_M_RD ; 
 int IDF_RECV ; 
 int IDF_SEND ; 
 int IDF_STOP ; 
 int IDS_ARBLOST ; 
 int IDS_DONE ; 
 int IDS_NACK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 unsigned long MCR_ESG ; 
 unsigned long MCR_FSB ; 
 int MCR_FSDA ; 
 unsigned long MCR_MIE ; 
 unsigned long MIE_MALE ; 
 unsigned long MIE_MATE ; 
 unsigned long MIE_MNRE ; 
 unsigned long MIE_MSTE ; 
 unsigned long MSR_MAL ; 
 unsigned long MSR_MAT ; 
 unsigned long MSR_MNR ; 
 unsigned long MSR_MST ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  REGSIZE ; 
 int /*<<< orphan*/  SH7760_I2C_DEVNAME ; 
 unsigned long __raw_readl (unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned long) ; 
 unsigned long abs (unsigned long) ; 
 struct clk* clk_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct sh7760_i2c_platdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,scalar_t__,int) ; 
 int /*<<< orphan*/  free_irq (int,struct cami2c*) ; 
 int i2c_add_numbered_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 scalar_t__ ioremap (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct cami2c*) ; 
 struct cami2c* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct cami2c* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cami2c*) ; 
 int /*<<< orphan*/  release_resource (struct cami2c*) ; 
 scalar_t__ request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct cami2c*) ; 
 struct cami2c* request_mem_region (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh7760_i2c_algo ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void OUT32(struct cami2c *cam, int reg, unsigned long val)
{
	__raw_writel(val, (unsigned long)cam->iobase + reg);
}

__attribute__((used)) static inline unsigned long IN32(struct cami2c *cam, int reg)
{
	return __raw_readl((unsigned long)cam->iobase + reg);
}

__attribute__((used)) static irqreturn_t sh7760_i2c_irq(int irq, void *ptr)
{
	struct cami2c *id = ptr;
	struct i2c_msg *msg = id->msg;
	char *data = msg->buf;
	unsigned long msr, fsr, fier, len;

	msr = IN32(id, I2CMSR);
	fsr = IN32(id, I2CFSR);

	/* arbitration lost */
	if (msr & MSR_MAL) {
		OUT32(id, I2CMCR, 0);
		OUT32(id, I2CSCR, 0);
		OUT32(id, I2CSAR, 0);
		id->status |= IDS_DONE | IDS_ARBLOST;
		goto out;
	}

	if (msr & MSR_MNR) {
		/* NACK handling is very screwed up.  After receiving a
		 * NAK IRQ one has to wait a bit  before writing to any
		 * registers, or the ctl will lock up. After that delay
		 * do a normal i2c stop. Then wait at least 1 ms before
		 * attempting another transfer or ctl will stop working
		 */
		udelay(100);	/* wait or risk ctl hang */
		OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
		OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
		OUT32(id, I2CFIER, 0);
		OUT32(id, I2CMIER, MIE_MSTE);
		OUT32(id, I2CSCR, 0);
		OUT32(id, I2CSAR, 0);
		id->status |= IDS_NACK;
		msr &= ~MSR_MAT;
		fsr = 0;
		/* In some cases the MST bit is also set. */
	}

	/* i2c-stop was sent */
	if (msr & MSR_MST) {
		id->status |= IDS_DONE;
		goto out;
	}

	/* i2c slave addr was sent; set to "normal" operation */
	if (msr & MSR_MAT)
		OUT32(id, I2CMCR, MCR_MIE);

	fier = IN32(id, I2CFIER);

	if (fsr & FSR_RDF) {
		len = IN32(id, I2CRFDR);
		if (msg->len <= len) {
			if (id->flags & IDF_STOP) {
				OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
				OUT32(id, I2CFIER, 0);
				/* manual says: wait >= 0.5 SCL times */
				udelay(5);
				/* next int should be MST */
			} else {
				id->status |= IDS_DONE;
				/* keep the RDF bit: ctrl holds SCL low
				 * until the setup for the next i2c_msg
				 * clears this bit.
				 */
				fsr &= ~FSR_RDF;
			}
		}
		while (msg->len && len) {
			*data++ = IN32(id, I2CRXTX);
			msg->len--;
			len--;
		}

		if (msg->len) {
			len = (msg->len >= FIFO_SIZE) ? FIFO_SIZE - 1
						      : msg->len - 1;

			OUT32(id, I2CFCR, FCR_TFRST | ((len & 0xf) << 4));
		}

	} else if (id->flags & IDF_SEND) {
		if ((fsr & FSR_TEND) && (msg->len < 1)) {
			if (id->flags & IDF_STOP) {
				OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
			} else {
				id->status |= IDS_DONE;
				/* keep the TEND bit: ctl holds SCL low
				 * until the setup for the next i2c_msg
				 * clears this bit.
				 */
				fsr &= ~FSR_TEND;
			}
		}
		if (fsr & FSR_TDFE) {
			while (msg->len && (IN32(id, I2CTFDR) < FIFO_SIZE)) {
				OUT32(id, I2CRXTX, *data++);
				msg->len--;
			}

			if (msg->len < 1) {
				fier &= ~FIER_TXIE;
				OUT32(id, I2CFIER, fier);
			} else {
				len = (msg->len >= FIFO_SIZE) ? 2 : 0;
				OUT32(id, I2CFCR,
					  FCR_RFRST | ((len & 3) << 2));
			}
		}
	}
out:
	if (id->status & IDS_DONE) {
		OUT32(id, I2CMIER, 0);
		OUT32(id, I2CFIER, 0);
		id->msg = NULL;
		complete(&id->xfer_done);
	}
	/* clear status flags and ctrl resumes work */
	OUT32(id, I2CMSR, ~msr);
	OUT32(id, I2CFSR, ~fsr);
	OUT32(id, I2CSSR, 0);

	return IRQ_HANDLED;
}

__attribute__((used)) static void sh7760_i2c_mrecv(struct cami2c *id)
{
	int len;

	id->flags |= IDF_RECV;

	/* set the slave addr reg; otherwise rcv wont work! */
	OUT32(id, I2CSAR, 0xfe);
	OUT32(id, I2CMAR, (id->msg->addr << 1) | 1);

	/* adjust rx fifo trigger */
	if (id->msg->len >= FIFO_SIZE)
		len = FIFO_SIZE - 1;	/* trigger at fifo full */
	else
		len = id->msg->len - 1;	/* trigger before all received */

	OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
	OUT32(id, I2CFCR, FCR_TFRST | ((len & 0xF) << 4));

	OUT32(id, I2CMSR, 0);
	OUT32(id, I2CMCR, MCR_MIE | MCR_ESG);
	OUT32(id, I2CMIER, MIE_MNRE | MIE_MALE | MIE_MSTE | MIE_MATE);
	OUT32(id, I2CFIER, FIER_RXIE);
}

__attribute__((used)) static void sh7760_i2c_msend(struct cami2c *id)
{
	int len;

	id->flags |= IDF_SEND;

	/* set the slave addr reg; otherwise xmit wont work! */
	OUT32(id, I2CSAR, 0xfe);
	OUT32(id, I2CMAR, (id->msg->addr << 1) | 0);

	/* adjust tx fifo trigger */
	if (id->msg->len >= FIFO_SIZE)
		len = 2;	/* trig: 2 bytes left in TX fifo */
	else
		len = 0;	/* trig: 8 bytes left in TX fifo */

	OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
	OUT32(id, I2CFCR, FCR_RFRST | ((len & 3) << 2));

	while (id->msg->len && IN32(id, I2CTFDR) < FIFO_SIZE) {
		OUT32(id, I2CRXTX, *(id->msg->buf));
		(id->msg->len)--;
		(id->msg->buf)++;
	}

	OUT32(id, I2CMSR, 0);
	OUT32(id, I2CMCR, MCR_MIE | MCR_ESG);
	OUT32(id, I2CFSR, 0);
	OUT32(id, I2CMIER, MIE_MNRE | MIE_MALE | MIE_MSTE | MIE_MATE);
	OUT32(id, I2CFIER, FIER_TEIE | (id->msg->len ? FIER_TXIE : 0));
}

__attribute__((used)) static inline int sh7760_i2c_busy_check(struct cami2c *id)
{
	return (IN32(id, I2CMCR) & MCR_FSDA);
}

__attribute__((used)) static int sh7760_i2c_master_xfer(struct i2c_adapter *adap,
				  struct i2c_msg *msgs,
				  int num)
{
	struct cami2c *id = adap->algo_data;
	int i, retr;

	if (sh7760_i2c_busy_check(id)) {
		dev_err(&adap->dev, "sh7760-i2c%d: bus busy!\n", adap->nr);
		return -EBUSY;
	}

	i = 0;
	while (i < num) {
		retr = adap->retries;
retry:
		id->flags = ((i == (num-1)) ? IDF_STOP : 0);
		id->status = 0;
		id->msg = msgs;
		init_completion(&id->xfer_done);

		if (msgs->flags & I2C_M_RD)
			sh7760_i2c_mrecv(id);
		else
			sh7760_i2c_msend(id);

		wait_for_completion(&id->xfer_done);

		if (id->status == 0) {
			num = -EIO;
			break;
		}

		if (id->status & IDS_NACK) {
			/* wait a bit or i2c module stops working */
			mdelay(1);
			num = -EREMOTEIO;
			break;
		}

		if (id->status & IDS_ARBLOST) {
			if (retr--) {
				mdelay(2);
				goto retry;
			}
			num = -EREMOTEIO;
			break;
		}

		msgs++;
		i++;
	}

	id->msg = NULL;
	id->flags = 0;
	id->status = 0;

	OUT32(id, I2CMCR, 0);
	OUT32(id, I2CMSR, 0);
	OUT32(id, I2CMIER, 0);
	OUT32(id, I2CFIER, 0);

	/* reset slave module registers too: master mode enables slave
	 * module for receive ops (ack, data). Without this reset,
	 * eternal bus activity might be reported after NACK / ARBLOST.
	 */
	OUT32(id, I2CSCR, 0);
	OUT32(id, I2CSAR, 0);
	OUT32(id, I2CSSR, 0);

	return num;
}

__attribute__((used)) static u32 sh7760_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}

__attribute__((used)) static int calc_CCR(unsigned long scl_hz)
{
	struct clk *mclk;
	unsigned long mck, m1, dff, odff, iclk;
	signed char cdf, cdfm;
	int scgd, scgdm, scgds;

	mclk = clk_get(NULL, "peripheral_clk");
	if (IS_ERR(mclk)) {
		return PTR_ERR(mclk);
	} else {
		mck = mclk->rate;
		clk_put(mclk);
	}

	odff = scl_hz;
	scgdm = cdfm = m1 = 0;
	for (cdf = 3; cdf >= 0; cdf--) {
		iclk = mck / (1 + cdf);
		if (iclk >= 20000000)
			continue;
		scgds = ((iclk / scl_hz) - 20) >> 3;
		for (scgd = scgds; (scgd < 63) && scgd <= scgds + 1; scgd++) {
			m1 = iclk / (20 + (scgd << 3));
			dff = abs(scl_hz - m1);
			if (dff < odff) {
				odff = dff;
				cdfm = cdf;
				scgdm = scgd;
			}
		}
	}
	/* fail if more than 25% off of requested SCL */
	if (odff > (scl_hz >> 2))
		return -EINVAL;

	/* create a CCR register value */
	return ((scgdm << 2) | cdfm);
}

__attribute__((used)) static int sh7760_i2c_probe(struct platform_device *pdev)
{
	struct sh7760_i2c_platdata *pd;
	struct resource *res;
	struct cami2c *id;
	int ret;

	pd = dev_get_platdata(&pdev->dev);
	if (!pd) {
		dev_err(&pdev->dev, "no platform_data!\n");
		ret = -ENODEV;
		goto out0;
	}

	id = kzalloc(sizeof(struct cami2c), GFP_KERNEL);
	if (!id) {
		dev_err(&pdev->dev, "no mem for private data\n");
		ret = -ENOMEM;
		goto out0;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "no mmio resources\n");
		ret = -ENODEV;
		goto out1;
	}

	id->ioarea = request_mem_region(res->start, REGSIZE, pdev->name);
	if (!id->ioarea) {
		dev_err(&pdev->dev, "mmio already reserved\n");
		ret = -EBUSY;
		goto out1;
	}

	id->iobase = ioremap(res->start, REGSIZE);
	if (!id->iobase) {
		dev_err(&pdev->dev, "cannot ioremap\n");
		ret = -ENODEV;
		goto out2;
	}

	id->irq = platform_get_irq(pdev, 0);

	id->adap.nr = pdev->id;
	id->adap.algo = &sh7760_i2c_algo;
	id->adap.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
	id->adap.retries = 3;
	id->adap.algo_data = id;
	id->adap.dev.parent = &pdev->dev;
	snprintf(id->adap.name, sizeof(id->adap.name),
		"SH7760 I2C at %08lx", (unsigned long)res->start);

	OUT32(id, I2CMCR, 0);
	OUT32(id, I2CMSR, 0);
	OUT32(id, I2CMIER, 0);
	OUT32(id, I2CMAR, 0);
	OUT32(id, I2CSIER, 0);
	OUT32(id, I2CSAR, 0);
	OUT32(id, I2CSCR, 0);
	OUT32(id, I2CSSR, 0);
	OUT32(id, I2CFIER, 0);
	OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
	OUT32(id, I2CFSR, 0);

	ret = calc_CCR(pd->speed_khz * 1000);
	if (ret < 0) {
		dev_err(&pdev->dev, "invalid SCL clock: %dkHz\n",
			pd->speed_khz);
		goto out3;
	}
	OUT32(id, I2CCCR, ret);

	if (request_irq(id->irq, sh7760_i2c_irq, 0,
			SH7760_I2C_DEVNAME, id)) {
		dev_err(&pdev->dev, "cannot get irq %d\n", id->irq);
		ret = -EBUSY;
		goto out3;
	}

	ret = i2c_add_numbered_adapter(&id->adap);
	if (ret < 0)
		goto out4;

	platform_set_drvdata(pdev, id);

	dev_info(&pdev->dev, "%d kHz mmio %08x irq %d\n",
		 pd->speed_khz, res->start, id->irq);

	return 0;

out4:
	free_irq(id->irq, id);
out3:
	iounmap(id->iobase);
out2:
	release_resource(id->ioarea);
	kfree(id->ioarea);
out1:
	kfree(id);
out0:
	return ret;
}

__attribute__((used)) static int sh7760_i2c_remove(struct platform_device *pdev)
{
	struct cami2c *id = platform_get_drvdata(pdev);

	i2c_del_adapter(&id->adap);
	free_irq(id->irq, id);
	iounmap(id->iobase);
	release_resource(id->ioarea);
	kfree(id->ioarea);
	kfree(id);

	return 0;
}

