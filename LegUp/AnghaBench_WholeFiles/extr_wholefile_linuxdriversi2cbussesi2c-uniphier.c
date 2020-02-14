#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned long u32 ;
typedef  int u16 ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; struct device* parent; } ;
struct TYPE_6__ {int /*<<< orphan*/ * bus_recovery_info; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; } ;
struct uniphier_i2c_priv {unsigned int clk_cycle; scalar_t__ clk; TYPE_2__ adap; int /*<<< orphan*/  comp; scalar_t__ membase; scalar_t__ busy_cnt; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {int /*<<< orphan*/  name; struct device dev; } ;
struct i2c_msg {int flags; int addr; int len; int /*<<< orphan*/ * buf; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; int /*<<< orphan*/  timeout; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EAGAIN ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long I2C_FUNC_I2C ; 
 unsigned long I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int I2C_M_STOP ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 scalar_t__ UNIPHIER_I2C_BRST ; 
 unsigned long UNIPHIER_I2C_BRST_FOEN ; 
 unsigned int UNIPHIER_I2C_BRST_RSCL ; 
 scalar_t__ UNIPHIER_I2C_BSTS ; 
 unsigned long UNIPHIER_I2C_BSTS_SCL ; 
 unsigned long UNIPHIER_I2C_BSTS_SDA ; 
 scalar_t__ UNIPHIER_I2C_CLK ; 
 unsigned long UNIPHIER_I2C_DEFAULT_SPEED ; 
 scalar_t__ UNIPHIER_I2C_DREC ; 
 unsigned long UNIPHIER_I2C_DREC_BBN ; 
 unsigned long UNIPHIER_I2C_DREC_LAB ; 
 unsigned long UNIPHIER_I2C_DREC_LRB ; 
 scalar_t__ UNIPHIER_I2C_DTRM ; 
 unsigned long UNIPHIER_I2C_DTRM_IRQEN ; 
 int UNIPHIER_I2C_DTRM_NACK ; 
 int UNIPHIER_I2C_DTRM_RD ; 
 int UNIPHIER_I2C_DTRM_STA ; 
 int UNIPHIER_I2C_DTRM_STO ; 
 unsigned long UNIPHIER_I2C_MAX_SPEED ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct uniphier_i2c_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct uniphier_i2c_priv*) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 struct uniphier_i2c_priv* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_recover_bus (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_2__*,struct uniphier_i2c_priv*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned long*) ; 
 struct uniphier_i2c_priv* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct uniphier_i2c_priv*) ; 
 unsigned long readl (scalar_t__) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  uniphier_i2c_algo ; 
 int /*<<< orphan*/  uniphier_i2c_bus_recovery_info ; 
 scalar_t__ unlikely (unsigned long) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static irqreturn_t uniphier_i2c_interrupt(int irq, void *dev_id)
{
	struct uniphier_i2c_priv *priv = dev_id;

	/*
	 * This hardware uses edge triggered interrupt.  Do not touch the
	 * hardware registers in this handler to make sure to catch the next
	 * interrupt edge.  Just send a complete signal and return.
	 */
	complete(&priv->comp);

	return IRQ_HANDLED;
}

__attribute__((used)) static int uniphier_i2c_xfer_byte(struct i2c_adapter *adap, u32 txdata,
				  u32 *rxdatap)
{
	struct uniphier_i2c_priv *priv = i2c_get_adapdata(adap);
	unsigned long time_left;
	u32 rxdata;

	reinit_completion(&priv->comp);

	txdata |= UNIPHIER_I2C_DTRM_IRQEN;
	dev_dbg(&adap->dev, "write data: 0x%04x\n", txdata);
	writel(txdata, priv->membase + UNIPHIER_I2C_DTRM);

	time_left = wait_for_completion_timeout(&priv->comp, adap->timeout);
	if (unlikely(!time_left)) {
		dev_err(&adap->dev, "transaction timeout\n");
		return -ETIMEDOUT;
	}

	rxdata = readl(priv->membase + UNIPHIER_I2C_DREC);
	dev_dbg(&adap->dev, "read data: 0x%04x\n", rxdata);

	if (rxdatap)
		*rxdatap = rxdata;

	return 0;
}

__attribute__((used)) static int uniphier_i2c_send_byte(struct i2c_adapter *adap, u32 txdata)
{
	u32 rxdata;
	int ret;

	ret = uniphier_i2c_xfer_byte(adap, txdata, &rxdata);
	if (ret)
		return ret;

	if (unlikely(rxdata & UNIPHIER_I2C_DREC_LAB)) {
		dev_dbg(&adap->dev, "arbitration lost\n");
		return -EAGAIN;
	}
	if (unlikely(rxdata & UNIPHIER_I2C_DREC_LRB)) {
		dev_dbg(&adap->dev, "could not get ACK\n");
		return -ENXIO;
	}

	return 0;
}

__attribute__((used)) static int uniphier_i2c_tx(struct i2c_adapter *adap, u16 addr, u16 len,
			   const u8 *buf)
{
	int ret;

	dev_dbg(&adap->dev, "start condition\n");
	ret = uniphier_i2c_send_byte(adap, addr << 1 |
				     UNIPHIER_I2C_DTRM_STA |
				     UNIPHIER_I2C_DTRM_NACK);
	if (ret)
		return ret;

	while (len--) {
		ret = uniphier_i2c_send_byte(adap,
					     UNIPHIER_I2C_DTRM_NACK | *buf++);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int uniphier_i2c_rx(struct i2c_adapter *adap, u16 addr, u16 len,
			   u8 *buf)
{
	int ret;

	dev_dbg(&adap->dev, "start condition\n");
	ret = uniphier_i2c_send_byte(adap, addr << 1 |
				     UNIPHIER_I2C_DTRM_STA |
				     UNIPHIER_I2C_DTRM_NACK |
				     UNIPHIER_I2C_DTRM_RD);
	if (ret)
		return ret;

	while (len--) {
		u32 rxdata;

		ret = uniphier_i2c_xfer_byte(adap,
					     len ? 0 : UNIPHIER_I2C_DTRM_NACK,
					     &rxdata);
		if (ret)
			return ret;
		*buf++ = rxdata;
	}

	return 0;
}

__attribute__((used)) static int uniphier_i2c_stop(struct i2c_adapter *adap)
{
	dev_dbg(&adap->dev, "stop condition\n");
	return uniphier_i2c_send_byte(adap, UNIPHIER_I2C_DTRM_STO |
				      UNIPHIER_I2C_DTRM_NACK);
}

__attribute__((used)) static int uniphier_i2c_master_xfer_one(struct i2c_adapter *adap,
					struct i2c_msg *msg, bool stop)
{
	bool is_read = msg->flags & I2C_M_RD;
	bool recovery = false;
	int ret;

	dev_dbg(&adap->dev, "%s: addr=0x%02x, len=%d, stop=%d\n",
		is_read ? "receive" : "transmit", msg->addr, msg->len, stop);

	if (is_read)
		ret = uniphier_i2c_rx(adap, msg->addr, msg->len, msg->buf);
	else
		ret = uniphier_i2c_tx(adap, msg->addr, msg->len, msg->buf);

	if (ret == -EAGAIN) /* could not acquire bus. bail out without STOP */
		return ret;

	if (ret == -ETIMEDOUT) {
		/* This error is fatal.  Needs recovery. */
		stop = false;
		recovery = true;
	}

	if (stop) {
		int ret2 = uniphier_i2c_stop(adap);

		if (ret2) {
			/* Failed to issue STOP.  The bus needs recovery. */
			recovery = true;
			ret = ret ?: ret2;
		}
	}

	if (recovery)
		i2c_recover_bus(adap);

	return ret;
}

__attribute__((used)) static int uniphier_i2c_check_bus_busy(struct i2c_adapter *adap)
{
	struct uniphier_i2c_priv *priv = i2c_get_adapdata(adap);

	if (!(readl(priv->membase + UNIPHIER_I2C_DREC) &
						UNIPHIER_I2C_DREC_BBN)) {
		if (priv->busy_cnt++ > 3) {
			/*
			 * If bus busy continues too long, it is probably
			 * in a wrong state.  Try bus recovery.
			 */
			i2c_recover_bus(adap);
			priv->busy_cnt = 0;
		}

		return -EAGAIN;
	}

	priv->busy_cnt = 0;
	return 0;
}

__attribute__((used)) static int uniphier_i2c_master_xfer(struct i2c_adapter *adap,
				    struct i2c_msg *msgs, int num)
{
	struct i2c_msg *msg, *emsg = msgs + num;
	int ret;

	ret = uniphier_i2c_check_bus_busy(adap);
	if (ret)
		return ret;

	for (msg = msgs; msg < emsg; msg++) {
		/* Emit STOP if it is the last message or I2C_M_STOP is set. */
		bool stop = (msg + 1 == emsg) || (msg->flags & I2C_M_STOP);

		ret = uniphier_i2c_master_xfer_one(adap, msg, stop);
		if (ret)
			return ret;
	}

	return num;
}

__attribute__((used)) static u32 uniphier_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static void uniphier_i2c_reset(struct uniphier_i2c_priv *priv, bool reset_on)
{
	u32 val = UNIPHIER_I2C_BRST_RSCL;

	val |= reset_on ? 0 : UNIPHIER_I2C_BRST_FOEN;
	writel(val, priv->membase + UNIPHIER_I2C_BRST);
}

__attribute__((used)) static int uniphier_i2c_get_scl(struct i2c_adapter *adap)
{
	struct uniphier_i2c_priv *priv = i2c_get_adapdata(adap);

	return !!(readl(priv->membase + UNIPHIER_I2C_BSTS) &
							UNIPHIER_I2C_BSTS_SCL);
}

__attribute__((used)) static void uniphier_i2c_set_scl(struct i2c_adapter *adap, int val)
{
	struct uniphier_i2c_priv *priv = i2c_get_adapdata(adap);

	writel(val ? UNIPHIER_I2C_BRST_RSCL : 0,
	       priv->membase + UNIPHIER_I2C_BRST);
}

__attribute__((used)) static int uniphier_i2c_get_sda(struct i2c_adapter *adap)
{
	struct uniphier_i2c_priv *priv = i2c_get_adapdata(adap);

	return !!(readl(priv->membase + UNIPHIER_I2C_BSTS) &
							UNIPHIER_I2C_BSTS_SDA);
}

__attribute__((used)) static void uniphier_i2c_unprepare_recovery(struct i2c_adapter *adap)
{
	uniphier_i2c_reset(i2c_get_adapdata(adap), false);
}

__attribute__((used)) static void uniphier_i2c_hw_init(struct uniphier_i2c_priv *priv)
{
	unsigned int cyc = priv->clk_cycle;

	uniphier_i2c_reset(priv, true);

	/*
	 * Bit30-16: clock cycles of tLOW.
	 *  Standard-mode: tLOW = 4.7 us, tHIGH = 4.0 us
	 *  Fast-mode:     tLOW = 1.3 us, tHIGH = 0.6 us
	 * "tLow/tHIGH = 5/4" meets both.
	 */
	writel((cyc * 5 / 9 << 16) | cyc, priv->membase + UNIPHIER_I2C_CLK);

	uniphier_i2c_reset(priv, false);
}

__attribute__((used)) static int uniphier_i2c_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct uniphier_i2c_priv *priv;
	struct resource *regs;
	u32 bus_speed;
	unsigned long clk_rate;
	int irq, ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->membase = devm_ioremap_resource(dev, regs);
	if (IS_ERR(priv->membase))
		return PTR_ERR(priv->membase);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(dev, "failed to get IRQ number\n");
		return irq;
	}

	if (of_property_read_u32(dev->of_node, "clock-frequency", &bus_speed))
		bus_speed = UNIPHIER_I2C_DEFAULT_SPEED;

	if (!bus_speed || bus_speed > UNIPHIER_I2C_MAX_SPEED) {
		dev_err(dev, "invalid clock-frequency %d\n", bus_speed);
		return -EINVAL;
	}

	priv->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(priv->clk)) {
		dev_err(dev, "failed to get clock\n");
		return PTR_ERR(priv->clk);
	}

	ret = clk_prepare_enable(priv->clk);
	if (ret)
		return ret;

	clk_rate = clk_get_rate(priv->clk);
	if (!clk_rate) {
		dev_err(dev, "input clock rate should not be zero\n");
		ret = -EINVAL;
		goto disable_clk;
	}

	priv->clk_cycle = clk_rate / bus_speed;
	init_completion(&priv->comp);
	priv->adap.owner = THIS_MODULE;
	priv->adap.algo = &uniphier_i2c_algo;
	priv->adap.dev.parent = dev;
	priv->adap.dev.of_node = dev->of_node;
	strlcpy(priv->adap.name, "UniPhier I2C", sizeof(priv->adap.name));
	priv->adap.bus_recovery_info = &uniphier_i2c_bus_recovery_info;
	i2c_set_adapdata(&priv->adap, priv);
	platform_set_drvdata(pdev, priv);

	uniphier_i2c_hw_init(priv);

	ret = devm_request_irq(dev, irq, uniphier_i2c_interrupt, 0, pdev->name,
			       priv);
	if (ret) {
		dev_err(dev, "failed to request irq %d\n", irq);
		goto disable_clk;
	}

	ret = i2c_add_adapter(&priv->adap);
disable_clk:
	if (ret)
		clk_disable_unprepare(priv->clk);

	return ret;
}

__attribute__((used)) static int uniphier_i2c_remove(struct platform_device *pdev)
{
	struct uniphier_i2c_priv *priv = platform_get_drvdata(pdev);

	i2c_del_adapter(&priv->adap);
	clk_disable_unprepare(priv->clk);

	return 0;
}

