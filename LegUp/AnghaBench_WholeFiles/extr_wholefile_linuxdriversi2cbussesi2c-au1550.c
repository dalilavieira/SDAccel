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
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  id; } ;
struct i2c_msg {unsigned int addr; int flags; unsigned int len; unsigned char* buf; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; TYPE_1__ dev; struct i2c_au1550_data* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  nr; } ;
struct i2c_au1550_data {int xfer_timeout; TYPE_2__ adap; scalar_t__ psc_base; } ;
struct i2c_adapter {struct i2c_au1550_data* algo_data; } ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PSC_CTRL ; 
 unsigned long PSC_CTRL_DISABLE ; 
 unsigned long PSC_CTRL_ENABLE ; 
 unsigned long PSC_CTRL_SUSPEND ; 
 int PSC_SEL ; 
 unsigned long PSC_SEL_PS_SMBUSMODE ; 
 int PSC_SMBCFG ; 
 unsigned long PSC_SMBCFG_DD_DISABLE ; 
 unsigned long PSC_SMBCFG_DE_ENABLE ; 
 int /*<<< orphan*/  PSC_SMBCFG_DIV8 ; 
 unsigned long PSC_SMBCFG_RT_FIFO8 ; 
 unsigned long PSC_SMBCFG_SET_DIV (int /*<<< orphan*/ ) ; 
 unsigned long PSC_SMBCFG_TT_FIFO8 ; 
 int PSC_SMBEVNT ; 
 unsigned long PSC_SMBEVNT_AL ; 
 unsigned long PSC_SMBEVNT_ALLCLR ; 
 unsigned long PSC_SMBEVNT_AN ; 
 unsigned long PSC_SMBEVNT_DN ; 
 int PSC_SMBEVNT_MD ; 
 int PSC_SMBMSK ; 
 unsigned long PSC_SMBMSK_ALLMASK ; 
 int PSC_SMBPCR ; 
 unsigned long PSC_SMBPCR_DC ; 
 unsigned long PSC_SMBPCR_MS ; 
 int PSC_SMBSTAT ; 
 unsigned long PSC_SMBSTAT_RE ; 
 int PSC_SMBSTAT_SR ; 
 int PSC_SMBSTAT_TE ; 
 int PSC_SMBTMR ; 
 unsigned long PSC_SMBTMR_SET_CH (int) ; 
 unsigned long PSC_SMBTMR_SET_CL (int) ; 
 unsigned long PSC_SMBTMR_SET_PS (int) ; 
 unsigned long PSC_SMBTMR_SET_PU (int) ; 
 unsigned long PSC_SMBTMR_SET_SH (int) ; 
 unsigned long PSC_SMBTMR_SET_SU (int) ; 
 unsigned long PSC_SMBTMR_SET_TH (int /*<<< orphan*/ ) ; 
 int PSC_SMBTXRX ; 
 unsigned int PSC_SMBTXRX_STP ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  au1550_algo ; 
 int /*<<< orphan*/  cpu_relax () ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct i2c_au1550_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int i2c_add_numbered_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 struct i2c_au1550_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct i2c_au1550_data*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline void WR(struct i2c_au1550_data *a, int r, unsigned long v)
{
	__raw_writel(v, a->psc_base + r);
	wmb();
}

__attribute__((used)) static inline unsigned long RD(struct i2c_au1550_data *a, int r)
{
	return __raw_readl(a->psc_base + r);
}

__attribute__((used)) static int wait_xfer_done(struct i2c_au1550_data *adap)
{
	int i;

	/* Wait for Tx Buffer Empty */
	for (i = 0; i < adap->xfer_timeout; i++) {
		if (RD(adap, PSC_SMBSTAT) & PSC_SMBSTAT_TE)
			return 0;

		udelay(1);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int wait_ack(struct i2c_au1550_data *adap)
{
	unsigned long stat;

	if (wait_xfer_done(adap))
		return -ETIMEDOUT;

	stat = RD(adap, PSC_SMBEVNT);
	if ((stat & (PSC_SMBEVNT_DN | PSC_SMBEVNT_AN | PSC_SMBEVNT_AL)) != 0)
		return -ETIMEDOUT;

	return 0;
}

__attribute__((used)) static int wait_master_done(struct i2c_au1550_data *adap)
{
	int i;

	/* Wait for Master Done. */
	for (i = 0; i < 2 * adap->xfer_timeout; i++) {
		if ((RD(adap, PSC_SMBEVNT) & PSC_SMBEVNT_MD) != 0)
			return 0;
		udelay(1);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int
do_address(struct i2c_au1550_data *adap, unsigned int addr, int rd, int q)
{
	unsigned long stat;

	/* Reset the FIFOs, clear events. */
	stat = RD(adap, PSC_SMBSTAT);
	WR(adap, PSC_SMBEVNT, PSC_SMBEVNT_ALLCLR);

	if (!(stat & PSC_SMBSTAT_TE) || !(stat & PSC_SMBSTAT_RE)) {
		WR(adap, PSC_SMBPCR, PSC_SMBPCR_DC);
		while ((RD(adap, PSC_SMBPCR) & PSC_SMBPCR_DC) != 0)
			cpu_relax();
		udelay(50);
	}

	/* Write out the i2c chip address and specify operation */
	addr <<= 1;
	if (rd)
		addr |= 1;

	/* zero-byte xfers stop immediately */
	if (q)
		addr |= PSC_SMBTXRX_STP;

	/* Put byte into fifo, start up master. */
	WR(adap, PSC_SMBTXRX, addr);
	WR(adap, PSC_SMBPCR, PSC_SMBPCR_MS);
	if (wait_ack(adap))
		return -EIO;
	return (q) ? wait_master_done(adap) : 0;
}

__attribute__((used)) static int wait_for_rx_byte(struct i2c_au1550_data *adap, unsigned char *out)
{
	int j;

	if (wait_xfer_done(adap))
		return -EIO;

	j =  adap->xfer_timeout * 100;
	do {
		j--;
		if (j <= 0)
			return -EIO;

		if ((RD(adap, PSC_SMBSTAT) & PSC_SMBSTAT_RE) == 0)
			j = 0;
		else
			udelay(1);
	} while (j > 0);

	*out = RD(adap, PSC_SMBTXRX);

	return 0;
}

__attribute__((used)) static int i2c_read(struct i2c_au1550_data *adap, unsigned char *buf,
		    unsigned int len)
{
	int i;

	if (len == 0)
		return 0;

	/* A read is performed by stuffing the transmit fifo with
	 * zero bytes for timing, waiting for bytes to appear in the
	 * receive fifo, then reading the bytes.
	 */
	i = 0;
	while (i < (len - 1)) {
		WR(adap, PSC_SMBTXRX, 0);
		if (wait_for_rx_byte(adap, &buf[i]))
			return -EIO;

		i++;
	}

	/* The last byte has to indicate transfer done. */
	WR(adap, PSC_SMBTXRX, PSC_SMBTXRX_STP);
	if (wait_master_done(adap))
		return -EIO;

	buf[i] = (unsigned char)(RD(adap, PSC_SMBTXRX) & 0xff);
	return 0;
}

__attribute__((used)) static int i2c_write(struct i2c_au1550_data *adap, unsigned char *buf,
		     unsigned int len)
{
	int i;
	unsigned long data;

	if (len == 0)
		return 0;

	i = 0;
	while (i < (len-1)) {
		data = buf[i];
		WR(adap, PSC_SMBTXRX, data);
		if (wait_ack(adap))
			return -EIO;
		i++;
	}

	/* The last byte has to indicate transfer done. */
	data = buf[i];
	data |= PSC_SMBTXRX_STP;
	WR(adap, PSC_SMBTXRX, data);
	if (wait_master_done(adap))
		return -EIO;
	return 0;
}

__attribute__((used)) static int
au1550_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
	struct i2c_au1550_data *adap = i2c_adap->algo_data;
	struct i2c_msg *p;
	int i, err = 0;

	WR(adap, PSC_CTRL, PSC_CTRL_ENABLE);

	for (i = 0; !err && i < num; i++) {
		p = &msgs[i];
		err = do_address(adap, p->addr, p->flags & I2C_M_RD,
				 (p->len == 0));
		if (err || !p->len)
			continue;
		if (p->flags & I2C_M_RD)
			err = i2c_read(adap, p->buf, p->len);
		else
			err = i2c_write(adap, p->buf, p->len);
	}

	/* Return the number of messages processed, or the error code.
	*/
	if (err == 0)
		err = num;

	WR(adap, PSC_CTRL, PSC_CTRL_SUSPEND);

	return err;
}

__attribute__((used)) static u32 au1550_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static void i2c_au1550_setup(struct i2c_au1550_data *priv)
{
	unsigned long cfg;

	WR(priv, PSC_CTRL, PSC_CTRL_DISABLE);
	WR(priv, PSC_SEL, PSC_SEL_PS_SMBUSMODE);
	WR(priv, PSC_SMBCFG, 0);
	WR(priv, PSC_CTRL, PSC_CTRL_ENABLE);
	while ((RD(priv, PSC_SMBSTAT) & PSC_SMBSTAT_SR) == 0)
		cpu_relax();

	cfg = PSC_SMBCFG_RT_FIFO8 | PSC_SMBCFG_TT_FIFO8 | PSC_SMBCFG_DD_DISABLE;
	WR(priv, PSC_SMBCFG, cfg);

	/* Divide by 8 to get a 6.25 MHz clock.  The later protocol
	 * timings are based on this clock.
	 */
	cfg |= PSC_SMBCFG_SET_DIV(PSC_SMBCFG_DIV8);
	WR(priv, PSC_SMBCFG, cfg);
	WR(priv, PSC_SMBMSK, PSC_SMBMSK_ALLMASK);

	/* Set the protocol timer values.  See Table 71 in the
	 * Au1550 Data Book for standard timing values.
	 */
	WR(priv, PSC_SMBTMR, PSC_SMBTMR_SET_TH(0) | PSC_SMBTMR_SET_PS(20) | \
		PSC_SMBTMR_SET_PU(20) | PSC_SMBTMR_SET_SH(20) | \
		PSC_SMBTMR_SET_SU(20) | PSC_SMBTMR_SET_CL(20) | \
		PSC_SMBTMR_SET_CH(20));

	cfg |= PSC_SMBCFG_DE_ENABLE;
	WR(priv, PSC_SMBCFG, cfg);
	while ((RD(priv, PSC_SMBSTAT) & PSC_SMBSTAT_SR) == 0)
		cpu_relax();

	WR(priv, PSC_CTRL, PSC_CTRL_SUSPEND);
}

__attribute__((used)) static void i2c_au1550_disable(struct i2c_au1550_data *priv)
{
	WR(priv, PSC_SMBCFG, 0);
	WR(priv, PSC_CTRL, PSC_CTRL_DISABLE);
}

__attribute__((used)) static int
i2c_au1550_probe(struct platform_device *pdev)
{
	struct i2c_au1550_data *priv;
	struct resource *r;
	int ret;

	priv = devm_kzalloc(&pdev->dev, sizeof(struct i2c_au1550_data),
			    GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->psc_base = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(priv->psc_base))
		return PTR_ERR(priv->psc_base);

	priv->xfer_timeout = 200;

	priv->adap.nr = pdev->id;
	priv->adap.algo = &au1550_algo;
	priv->adap.algo_data = priv;
	priv->adap.dev.parent = &pdev->dev;
	strlcpy(priv->adap.name, "Au1xxx PSC I2C", sizeof(priv->adap.name));

	/* Now, set up the PSC for SMBus PIO mode. */
	i2c_au1550_setup(priv);

	ret = i2c_add_numbered_adapter(&priv->adap);
	if (ret) {
		i2c_au1550_disable(priv);
		return ret;
	}

	platform_set_drvdata(pdev, priv);
	return 0;
}

__attribute__((used)) static int i2c_au1550_remove(struct platform_device *pdev)
{
	struct i2c_au1550_data *priv = platform_get_drvdata(pdev);

	i2c_del_adapter(&priv->adap);
	i2c_au1550_disable(priv);
	return 0;
}

