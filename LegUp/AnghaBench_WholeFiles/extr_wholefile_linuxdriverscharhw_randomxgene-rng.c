#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_8__ {void* expires; } ;
struct xgene_rng_dev {int irq; int failure_cnt; int datum_size; scalar_t__ clk; scalar_t__ csr_base; int /*<<< orphan*/ * dev; void* revision; TYPE_2__ failure_timer; void* failure_ts; } ;
struct timer_list {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct hwrng {scalar_t__ priv; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {unsigned long priv; } ;

/* Variables and functions */
 int ALARM_THRESHOLD_SET (int /*<<< orphan*/ ,int) ; 
 int ENABLE_RNG_SET (int /*<<< orphan*/ ,int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HW_PATCH_LEVEL_RD (void*) ; 
 int HZ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int LONG_RUN_FAIL_MASK ; 
 int LONG_RUN_FAIL_MASK_SET (int,int) ; 
 int /*<<< orphan*/  MAJOR_HW_REV_RD (void*) ; 
 int MAX_REFILL_CYCLES_SET (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MINOR_HW_REV_RD (void*) ; 
 int MIN_REFILL_CYCLES_SET (int,int) ; 
 int MONOBIT_FAIL_MASK ; 
 int MONOBIT_FAIL_MASK_SET (int,int) ; 
 int NOISE_FAIL_MASK ; 
 int NOISE_FAIL_MASK_SET (int,int) ; 
 int POKER_FAIL_MASK ; 
 int POKER_FAIL_MASK_SET (int,int) ; 
 int PTR_ERR (scalar_t__) ; 
 int READY_MASK ; 
 scalar_t__ RNG_ALARMCNT ; 
 scalar_t__ RNG_ALARMMASK ; 
 scalar_t__ RNG_ALARMSTOP ; 
 scalar_t__ RNG_CONFIG ; 
 scalar_t__ RNG_CONTROL ; 
 scalar_t__ RNG_EIP_REV ; 
 scalar_t__ RNG_FRODETUNE ; 
 scalar_t__ RNG_FROENABLE ; 
 scalar_t__ RNG_INOUT_0 ; 
 scalar_t__ RNG_INTR_STS_ACK ; 
 int RNG_MAX_DATUM ; 
 scalar_t__ RNG_OPTIONS ; 
 int RUN_FAIL_MASK ; 
 int RUN_FAIL_MASK_SET (int,int) ; 
 int SHUTDOWN_OFLO_MASK ; 
 int SHUTDOWN_OFLO_MASK_SET (int,int) ; 
 int STUCK_OUT_MASK ; 
 int STUCK_OUT_MASK_SET (int,int) ; 
 int XGENE_RNG_RETRY_COUNT ; 
 int /*<<< orphan*/  XGENE_RNG_RETRY_INTERVAL ; 
 int /*<<< orphan*/  add_timer (TYPE_2__*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 struct xgene_rng_dev* ctx ; 
 int /*<<< orphan*/  del_timer (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,void*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct xgene_rng_dev* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct xgene_rng_dev*) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 int /*<<< orphan*/  failure_timer ; 
 struct xgene_rng_dev* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int hwrng_register (TYPE_1__*) ; 
 int /*<<< orphan*/  hwrng_unregister (TYPE_1__*) ; 
 void* jiffies ; 
 struct xgene_rng_dev* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xgene_rng_dev*) ; 
 void* readl (scalar_t__) ; 
 scalar_t__ time_after (void*,void*) ; 
 int /*<<< orphan*/  timer_setup (TYPE_2__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 TYPE_1__ xgene_rng_func ; 

__attribute__((used)) static void xgene_rng_expired_timer(struct timer_list *t)
{
	struct xgene_rng_dev *ctx = from_timer(ctx, t, failure_timer);

	/* Clear failure counter as timer expired */
	disable_irq(ctx->irq);
	ctx->failure_cnt = 0;
	del_timer(&ctx->failure_timer);
	enable_irq(ctx->irq);
}

__attribute__((used)) static void xgene_rng_start_timer(struct xgene_rng_dev *ctx)
{
	ctx->failure_timer.expires = jiffies + 120 * HZ;
	add_timer(&ctx->failure_timer);
}

__attribute__((used)) static void xgene_rng_init_fro(struct xgene_rng_dev *ctx, u32 fro_val)
{
	writel(fro_val, ctx->csr_base + RNG_FRODETUNE);
	writel(0x00000000, ctx->csr_base + RNG_ALARMMASK);
	writel(0x00000000, ctx->csr_base + RNG_ALARMSTOP);
	writel(0xFFFFFFFF, ctx->csr_base + RNG_FROENABLE);
}

__attribute__((used)) static void xgene_rng_chk_overflow(struct xgene_rng_dev *ctx)
{
	u32 val;

	val = readl(ctx->csr_base + RNG_INTR_STS_ACK);
	if (val & MONOBIT_FAIL_MASK)
		/*
		 * LFSR detected an out-of-bounds number of 1s after
		 * checking 20,000 bits (test T1 as specified in the
		 * AIS-31 standard)
		 */
		dev_err(ctx->dev, "test monobit failure error 0x%08X\n", val);
	if (val & POKER_FAIL_MASK)
		/*
		 * LFSR detected an out-of-bounds value in at least one
		 * of the 16 poker_count_X counters or an out of bounds sum
		 * of squares value after checking 20,000 bits (test T2 as
		 * specified in the AIS-31 standard)
		 */
		dev_err(ctx->dev, "test poker failure error 0x%08X\n", val);
	if (val & LONG_RUN_FAIL_MASK)
		/*
		 * LFSR detected a sequence of 34 identical bits
		 * (test T4 as specified in the AIS-31 standard)
		 */
		dev_err(ctx->dev, "test long run failure error 0x%08X\n", val);
	if (val & RUN_FAIL_MASK)
		/*
		 * LFSR detected an outof-bounds value for at least one
		 * of the running counters after checking 20,000 bits
		 * (test T3 as specified in the AIS-31 standard)
		 */
		dev_err(ctx->dev, "test run failure error 0x%08X\n", val);
	if (val & NOISE_FAIL_MASK)
		/* LFSR detected a sequence of 48 identical bits */
		dev_err(ctx->dev, "noise failure error 0x%08X\n", val);
	if (val & STUCK_OUT_MASK)
		/*
		 * Detected output data registers generated same value twice
		 * in a row
		 */
		dev_err(ctx->dev, "stuck out failure error 0x%08X\n", val);

	if (val & SHUTDOWN_OFLO_MASK) {
		u32 frostopped;

		/* FROs shut down after a second error event. Try recover. */
		if (++ctx->failure_cnt == 1) {
			/* 1st time, just recover */
			ctx->failure_ts = jiffies;
			frostopped = readl(ctx->csr_base + RNG_ALARMSTOP);
			xgene_rng_init_fro(ctx, frostopped);

			/*
			 * We must start a timer to clear out this error
			 * in case the system timer wrap around
			 */
			xgene_rng_start_timer(ctx);
		} else {
			/* 2nd time failure in lesser than 1 minute? */
			if (time_after(ctx->failure_ts + 60 * HZ, jiffies)) {
				dev_err(ctx->dev,
					"FRO shutdown failure error 0x%08X\n",
					val);
			} else {
				/* 2nd time failure after 1 minutes, recover */
				ctx->failure_ts = jiffies;
				ctx->failure_cnt = 1;
				/*
				 * We must start a timer to clear out this
				 * error in case the system timer wrap
				 * around
				 */
				xgene_rng_start_timer(ctx);
			}
			frostopped = readl(ctx->csr_base + RNG_ALARMSTOP);
			xgene_rng_init_fro(ctx, frostopped);
		}
	}
	/* Clear them all */
	writel(val, ctx->csr_base + RNG_INTR_STS_ACK);
}

__attribute__((used)) static irqreturn_t xgene_rng_irq_handler(int irq, void *id)
{
	struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) id;

	/* RNG Alarm Counter overflow */
	xgene_rng_chk_overflow(ctx);

	return IRQ_HANDLED;
}

__attribute__((used)) static int xgene_rng_data_present(struct hwrng *rng, int wait)
{
	struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;
	u32 i, val = 0;

	for (i = 0; i < XGENE_RNG_RETRY_COUNT; i++) {
		val = readl(ctx->csr_base + RNG_INTR_STS_ACK);
		if ((val & READY_MASK) || !wait)
			break;
		udelay(XGENE_RNG_RETRY_INTERVAL);
	}

	return (val & READY_MASK);
}

__attribute__((used)) static int xgene_rng_data_read(struct hwrng *rng, u32 *data)
{
	struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;
	int i;

	for (i = 0; i < ctx->datum_size; i++)
		data[i] = readl(ctx->csr_base + RNG_INOUT_0 + i * 4);

	/* Clear ready bit to start next transaction */
	writel(READY_MASK, ctx->csr_base + RNG_INTR_STS_ACK);

	return ctx->datum_size << 2;
}

__attribute__((used)) static void xgene_rng_init_internal(struct xgene_rng_dev *ctx)
{
	u32 val;

	writel(0x00000000, ctx->csr_base + RNG_CONTROL);

	val = MAX_REFILL_CYCLES_SET(0, 10);
	val = MIN_REFILL_CYCLES_SET(val, 10);
	writel(val, ctx->csr_base + RNG_CONFIG);

	val = ALARM_THRESHOLD_SET(0, 0xFF);
	writel(val, ctx->csr_base + RNG_ALARMCNT);

	xgene_rng_init_fro(ctx, 0);

	writel(MONOBIT_FAIL_MASK |
		POKER_FAIL_MASK	|
		LONG_RUN_FAIL_MASK |
		RUN_FAIL_MASK |
		NOISE_FAIL_MASK |
		STUCK_OUT_MASK |
		SHUTDOWN_OFLO_MASK |
		READY_MASK, ctx->csr_base + RNG_INTR_STS_ACK);

	val = ENABLE_RNG_SET(0, 1);
	val = MONOBIT_FAIL_MASK_SET(val, 1);
	val = POKER_FAIL_MASK_SET(val, 1);
	val = LONG_RUN_FAIL_MASK_SET(val, 1);
	val = RUN_FAIL_MASK_SET(val, 1);
	val = NOISE_FAIL_MASK_SET(val, 1);
	val = STUCK_OUT_MASK_SET(val, 1);
	val = SHUTDOWN_OFLO_MASK_SET(val, 1);
	writel(val, ctx->csr_base + RNG_CONTROL);
}

__attribute__((used)) static int xgene_rng_init(struct hwrng *rng)
{
	struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;

	ctx->failure_cnt = 0;
	timer_setup(&ctx->failure_timer, xgene_rng_expired_timer, 0);

	ctx->revision = readl(ctx->csr_base + RNG_EIP_REV);

	dev_dbg(ctx->dev, "Rev %d.%d.%d\n",
		MAJOR_HW_REV_RD(ctx->revision),
		MINOR_HW_REV_RD(ctx->revision),
		HW_PATCH_LEVEL_RD(ctx->revision));

	dev_dbg(ctx->dev, "Options 0x%08X",
		readl(ctx->csr_base + RNG_OPTIONS));

	xgene_rng_init_internal(ctx);

	ctx->datum_size = RNG_MAX_DATUM;

	return 0;
}

__attribute__((used)) static int xgene_rng_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct xgene_rng_dev *ctx;
	int rc = 0;

	ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->dev = &pdev->dev;
	platform_set_drvdata(pdev, ctx);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ctx->csr_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ctx->csr_base))
		return PTR_ERR(ctx->csr_base);

	rc = platform_get_irq(pdev, 0);
	if (rc < 0) {
		dev_err(&pdev->dev, "No IRQ resource\n");
		return rc;
	}
	ctx->irq = rc;

	dev_dbg(&pdev->dev, "APM X-Gene RNG BASE %p ALARM IRQ %d",
		ctx->csr_base, ctx->irq);

	rc = devm_request_irq(&pdev->dev, ctx->irq, xgene_rng_irq_handler, 0,
				dev_name(&pdev->dev), ctx);
	if (rc) {
		dev_err(&pdev->dev, "Could not request RNG alarm IRQ\n");
		return rc;
	}

	/* Enable IP clock */
	ctx->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(ctx->clk)) {
		dev_warn(&pdev->dev, "Couldn't get the clock for RNG\n");
	} else {
		rc = clk_prepare_enable(ctx->clk);
		if (rc) {
			dev_warn(&pdev->dev,
				 "clock prepare enable failed for RNG");
			return rc;
		}
	}

	xgene_rng_func.priv = (unsigned long) ctx;

	rc = hwrng_register(&xgene_rng_func);
	if (rc) {
		dev_err(&pdev->dev, "RNG registering failed error %d\n", rc);
		if (!IS_ERR(ctx->clk))
			clk_disable_unprepare(ctx->clk);
		return rc;
	}

	rc = device_init_wakeup(&pdev->dev, 1);
	if (rc) {
		dev_err(&pdev->dev, "RNG device_init_wakeup failed error %d\n",
			rc);
		if (!IS_ERR(ctx->clk))
			clk_disable_unprepare(ctx->clk);
		hwrng_unregister(&xgene_rng_func);
		return rc;
	}

	return 0;
}

__attribute__((used)) static int xgene_rng_remove(struct platform_device *pdev)
{
	struct xgene_rng_dev *ctx = platform_get_drvdata(pdev);
	int rc;

	rc = device_init_wakeup(&pdev->dev, 0);
	if (rc)
		dev_err(&pdev->dev, "RNG init wakeup failed error %d\n", rc);
	if (!IS_ERR(ctx->clk))
		clk_disable_unprepare(ctx->clk);
	hwrng_unregister(&xgene_rng_func);

	return rc;
}

