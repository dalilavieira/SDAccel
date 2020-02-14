#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; struct TYPE_11__* parent; } ;
struct i2c_adapter {TYPE_2__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; int /*<<< orphan*/  timeout; } ;
struct riic_dev {int base; int clk; int err; scalar_t__ bytes_left; int* buf; int is_last; struct i2c_adapter adapter; int /*<<< orphan*/  msg_done; struct i2c_msg* msg; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {TYPE_2__ dev; } ;
struct i2c_timings {int bus_freq_hz; int scl_fall_ns; int scl_rise_ns; } ;
struct i2c_msg {int* buf; int flags; scalar_t__ len; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {unsigned long name; int /*<<< orphan*/  isr; int /*<<< orphan*/  res_num; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int DIV_ROUND_UP (unsigned long,unsigned long) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int ICBR_RESERVED ; 
 int ICCR1_ICE ; 
 int ICCR1_IICRST ; 
 int ICCR1_SOWP ; 
 int ICCR2_BBSY ; 
 int ICCR2_RS ; 
 int ICCR2_SP ; 
 int ICCR2_ST ; 
 int ICIER_NAKIE ; 
 int ICIER_RIE ; 
 int ICIER_SPIE ; 
 int ICIER_TEIE ; 
 int ICIER_TIE ; 
 int ICMR1_CKS (int) ; 
 int ICMR3_ACKBT ; 
 int ICMR3_ACKWP ; 
 int ICMR3_RDRFS ; 
 int ICSR2_NACKF ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int) ; 
 int PTR_ERR (int) ; 
 int RIIC_ICBRH ; 
 int RIIC_ICBRL ; 
 int RIIC_ICCR1 ; 
 int RIIC_ICCR2 ; 
 int RIIC_ICDRR ; 
 int RIIC_ICDRT ; 
 int RIIC_ICIER ; 
 int RIIC_ICMR1 ; 
 int RIIC_ICMR3 ; 
 int RIIC_ICSER ; 
 int RIIC_ICSR2 ; 
 scalar_t__ RIIC_INIT_MSG ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 unsigned long clk_get_rate (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,unsigned long) ; 
 int devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 struct riic_dev* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,struct riic_dev*) ; 
 int i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 struct riic_dev* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_parse_fw_timings (TYPE_2__*,struct i2c_timings*,int) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,struct riic_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 struct riic_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct riic_dev*) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned long,int,int,int,int,int,int) ; 
 int readb (int) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  riic_algo ; 
 TYPE_1__* riic_irqs ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (int,int) ; 

__attribute__((used)) static inline void riic_clear_set_bit(struct riic_dev *riic, u8 clear, u8 set, u8 reg)
{
	writeb((readb(riic->base + reg) & ~clear) | set, riic->base + reg);
}

__attribute__((used)) static int riic_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
	struct riic_dev *riic = i2c_get_adapdata(adap);
	unsigned long time_left;
	int i, ret;
	u8 start_bit;

	ret = clk_prepare_enable(riic->clk);
	if (ret)
		return ret;

	if (readb(riic->base + RIIC_ICCR2) & ICCR2_BBSY) {
		riic->err = -EBUSY;
		goto out;
	}

	reinit_completion(&riic->msg_done);
	riic->err = 0;

	writeb(0, riic->base + RIIC_ICSR2);

	for (i = 0, start_bit = ICCR2_ST; i < num; i++) {
		riic->bytes_left = RIIC_INIT_MSG;
		riic->buf = msgs[i].buf;
		riic->msg = &msgs[i];
		riic->is_last = (i == num - 1);

		writeb(ICIER_NAKIE | ICIER_TIE, riic->base + RIIC_ICIER);

		writeb(start_bit, riic->base + RIIC_ICCR2);

		time_left = wait_for_completion_timeout(&riic->msg_done, riic->adapter.timeout);
		if (time_left == 0)
			riic->err = -ETIMEDOUT;

		if (riic->err)
			break;

		start_bit = ICCR2_RS;
	}

 out:
	clk_disable_unprepare(riic->clk);

	return riic->err ?: num;
}

__attribute__((used)) static irqreturn_t riic_tdre_isr(int irq, void *data)
{
	struct riic_dev *riic = data;
	u8 val;

	if (!riic->bytes_left)
		return IRQ_NONE;

	if (riic->bytes_left == RIIC_INIT_MSG) {
		if (riic->msg->flags & I2C_M_RD)
			/* On read, switch over to receive interrupt */
			riic_clear_set_bit(riic, ICIER_TIE, ICIER_RIE, RIIC_ICIER);
		else
			/* On write, initialize length */
			riic->bytes_left = riic->msg->len;

		val = i2c_8bit_addr_from_msg(riic->msg);
	} else {
		val = *riic->buf;
		riic->buf++;
		riic->bytes_left--;
	}

	/*
	 * Switch to transmission ended interrupt when done. Do check here
	 * after bytes_left was initialized to support SMBUS_QUICK (new msg has
	 * 0 length then)
	 */
	if (riic->bytes_left == 0)
		riic_clear_set_bit(riic, ICIER_TIE, ICIER_TEIE, RIIC_ICIER);

	/*
	 * This acks the TIE interrupt. We get another TIE immediately if our
	 * value could be moved to the shadow shift register right away. So
	 * this must be after updates to ICIER (where we want to disable TIE)!
	 */
	writeb(val, riic->base + RIIC_ICDRT);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t riic_tend_isr(int irq, void *data)
{
	struct riic_dev *riic = data;

	if (readb(riic->base + RIIC_ICSR2) & ICSR2_NACKF) {
		/* We got a NACKIE */
		readb(riic->base + RIIC_ICDRR);	/* dummy read */
		riic->err = -ENXIO;
	} else if (riic->bytes_left) {
		return IRQ_NONE;
	}

	if (riic->is_last || riic->err) {
		riic_clear_set_bit(riic, ICIER_TEIE, ICIER_SPIE, RIIC_ICIER);
		writeb(ICCR2_SP, riic->base + RIIC_ICCR2);
	} else {
		/* Transfer is complete, but do not send STOP */
		riic_clear_set_bit(riic, ICIER_TEIE, 0, RIIC_ICIER);
		complete(&riic->msg_done);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t riic_rdrf_isr(int irq, void *data)
{
	struct riic_dev *riic = data;

	if (!riic->bytes_left)
		return IRQ_NONE;

	if (riic->bytes_left == RIIC_INIT_MSG) {
		riic->bytes_left = riic->msg->len;
		readb(riic->base + RIIC_ICDRR);	/* dummy read */
		return IRQ_HANDLED;
	}

	if (riic->bytes_left == 1) {
		/* STOP must come before we set ACKBT! */
		if (riic->is_last) {
			riic_clear_set_bit(riic, 0, ICIER_SPIE, RIIC_ICIER);
			writeb(ICCR2_SP, riic->base + RIIC_ICCR2);
		}

		riic_clear_set_bit(riic, 0, ICMR3_ACKBT, RIIC_ICMR3);

	} else {
		riic_clear_set_bit(riic, ICMR3_ACKBT, 0, RIIC_ICMR3);
	}

	/* Reading acks the RIE interrupt */
	*riic->buf = readb(riic->base + RIIC_ICDRR);
	riic->buf++;
	riic->bytes_left--;

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t riic_stop_isr(int irq, void *data)
{
	struct riic_dev *riic = data;

	/* read back registers to confirm writes have fully propagated */
	writeb(0, riic->base + RIIC_ICSR2);
	readb(riic->base + RIIC_ICSR2);
	writeb(0, riic->base + RIIC_ICIER);
	readb(riic->base + RIIC_ICIER);

	complete(&riic->msg_done);

	return IRQ_HANDLED;
}

__attribute__((used)) static u32 riic_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int riic_init_hw(struct riic_dev *riic, struct i2c_timings *t)
{
	int ret;
	unsigned long rate;
	int total_ticks, cks, brl, brh;

	ret = clk_prepare_enable(riic->clk);
	if (ret)
		return ret;

	if (t->bus_freq_hz > 400000) {
		dev_err(&riic->adapter.dev,
			"unsupported bus speed (%dHz). 400000 max\n",
			t->bus_freq_hz);
		clk_disable_unprepare(riic->clk);
		return -EINVAL;
	}

	rate = clk_get_rate(riic->clk);

	/*
	 * Assume the default register settings:
	 *  FER.SCLE = 1 (SCL sync circuit enabled, adds 2 or 3 cycles)
	 *  FER.NFE = 1 (noise circuit enabled)
	 *  MR3.NF = 0 (1 cycle of noise filtered out)
	 *
	 * Freq (CKS=000) = (I2CCLK + tr + tf)/ (BRH + 3 + 1) + (BRL + 3 + 1)
	 * Freq (CKS!=000) = (I2CCLK + tr + tf)/ (BRH + 2 + 1) + (BRL + 2 + 1)
	 */

	/*
	 * Determine reference clock rate. We must be able to get the desired
	 * frequency with only 62 clock ticks max (31 high, 31 low).
	 * Aim for a duty of 60% LOW, 40% HIGH.
	 */
	total_ticks = DIV_ROUND_UP(rate, t->bus_freq_hz);

	for (cks = 0; cks < 7; cks++) {
		/*
		 * 60% low time must be less than BRL + 2 + 1
		 * BRL max register value is 0x1F.
		 */
		brl = ((total_ticks * 6) / 10);
		if (brl <= (0x1F + 3))
			break;

		total_ticks /= 2;
		rate /= 2;
	}

	if (brl > (0x1F + 3)) {
		dev_err(&riic->adapter.dev, "invalid speed (%lu). Too slow.\n",
			(unsigned long)t->bus_freq_hz);
		clk_disable_unprepare(riic->clk);
		return -EINVAL;
	}

	brh = total_ticks - brl;

	/* Remove automatic clock ticks for sync circuit and NF */
	if (cks == 0) {
		brl -= 4;
		brh -= 4;
	} else {
		brl -= 3;
		brh -= 3;
	}

	/*
	 * Remove clock ticks for rise and fall times. Convert ns to clock
	 * ticks.
	 */
	brl -= t->scl_fall_ns / (1000000000 / rate);
	brh -= t->scl_rise_ns / (1000000000 / rate);

	/* Adjust for min register values for when SCLE=1 and NFE=1 */
	if (brl < 1)
		brl = 1;
	if (brh < 1)
		brh = 1;

	pr_debug("i2c-riic: freq=%lu, duty=%d, fall=%lu, rise=%lu, cks=%d, brl=%d, brh=%d\n",
		 rate / total_ticks, ((brl + 3) * 100) / (brl + brh + 6),
		 t->scl_fall_ns / (1000000000 / rate),
		 t->scl_rise_ns / (1000000000 / rate), cks, brl, brh);

	/* Changing the order of accessing IICRST and ICE may break things! */
	writeb(ICCR1_IICRST | ICCR1_SOWP, riic->base + RIIC_ICCR1);
	riic_clear_set_bit(riic, 0, ICCR1_ICE, RIIC_ICCR1);

	writeb(ICMR1_CKS(cks), riic->base + RIIC_ICMR1);
	writeb(brh | ICBR_RESERVED, riic->base + RIIC_ICBRH);
	writeb(brl | ICBR_RESERVED, riic->base + RIIC_ICBRL);

	writeb(0, riic->base + RIIC_ICSER);
	writeb(ICMR3_ACKWP | ICMR3_RDRFS, riic->base + RIIC_ICMR3);

	riic_clear_set_bit(riic, ICCR1_IICRST, 0, RIIC_ICCR1);

	clk_disable_unprepare(riic->clk);

	return 0;
}

__attribute__((used)) static int riic_i2c_probe(struct platform_device *pdev)
{
	struct riic_dev *riic;
	struct i2c_adapter *adap;
	struct resource *res;
	struct i2c_timings i2c_t;
	int i, ret;

	riic = devm_kzalloc(&pdev->dev, sizeof(*riic), GFP_KERNEL);
	if (!riic)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	riic->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(riic->base))
		return PTR_ERR(riic->base);

	riic->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(riic->clk)) {
		dev_err(&pdev->dev, "missing controller clock");
		return PTR_ERR(riic->clk);
	}

	for (i = 0; i < ARRAY_SIZE(riic_irqs); i++) {
		res = platform_get_resource(pdev, IORESOURCE_IRQ, riic_irqs[i].res_num);
		if (!res)
			return -ENODEV;

		ret = devm_request_irq(&pdev->dev, res->start, riic_irqs[i].isr,
					0, riic_irqs[i].name, riic);
		if (ret) {
			dev_err(&pdev->dev, "failed to request irq %s\n", riic_irqs[i].name);
			return ret;
		}
	}

	adap = &riic->adapter;
	i2c_set_adapdata(adap, riic);
	strlcpy(adap->name, "Renesas RIIC adapter", sizeof(adap->name));
	adap->owner = THIS_MODULE;
	adap->algo = &riic_algo;
	adap->dev.parent = &pdev->dev;
	adap->dev.of_node = pdev->dev.of_node;

	init_completion(&riic->msg_done);

	i2c_parse_fw_timings(&pdev->dev, &i2c_t, true);

	ret = riic_init_hw(riic, &i2c_t);
	if (ret)
		return ret;


	ret = i2c_add_adapter(adap);
	if (ret)
		return ret;

	platform_set_drvdata(pdev, riic);

	dev_info(&pdev->dev, "registered with %dHz bus speed\n",
		 i2c_t.bus_freq_hz);
	return 0;
}

__attribute__((used)) static int riic_i2c_remove(struct platform_device *pdev)
{
	struct riic_dev *riic = platform_get_drvdata(pdev);

	writeb(0, riic->base + RIIC_ICIER);
	i2c_del_adapter(&riic->adapter);

	return 0;
}

