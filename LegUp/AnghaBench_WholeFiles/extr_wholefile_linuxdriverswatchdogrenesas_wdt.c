#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct watchdog_device {struct device* parent; int /*<<< orphan*/  timeout; } ;
struct TYPE_7__ {int min_timeout; unsigned int max_timeout; int /*<<< orphan*/  timeout; struct device* parent; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; int /*<<< orphan*/  bootstatus; } ;
struct rwdt_priv {int cks; unsigned long clk_rate; TYPE_1__ wdev; struct clk* base; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned long*) ; 
 unsigned int DIV_BY_CLKS_PER_SEC (struct rwdt_priv*,int) ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int MUL_BY_CLKS_PER_SEC (struct rwdt_priv*,int /*<<< orphan*/ ) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  RWDT_DEFAULT_TIMEOUT ; 
 unsigned int RWTCNT ; 
 unsigned int RWTCSRA ; 
 int RWTCSRA_TME ; 
 int RWTCSRA_WOVF ; 
 int RWTCSRA_WRFLG ; 
 unsigned int RWTCSRB ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 unsigned long* clk_divs ; 
 unsigned long clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct clk* devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 struct clk* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct rwdt_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct rwdt_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rwdt_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int readb_relaxed (struct clk*) ; 
 int readw_relaxed (struct clk*) ; 
 int /*<<< orphan*/  rwdt_ident ; 
 int /*<<< orphan*/  rwdt_ops ; 
 struct rwdt_priv* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_init_timeout (TYPE_1__*,int /*<<< orphan*/ ,struct device*) ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_1__*,struct rwdt_priv*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 
 int /*<<< orphan*/  writel_relaxed (int,struct clk*) ; 

__attribute__((used)) static void rwdt_write(struct rwdt_priv *priv, u32 val, unsigned int reg)
{
	if (reg == RWTCNT)
		val |= 0x5a5a0000;
	else
		val |= 0xa5a5a500;

	writel_relaxed(val, priv->base + reg);
}

__attribute__((used)) static int rwdt_init_timeout(struct watchdog_device *wdev)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);

	rwdt_write(priv, 65536 - MUL_BY_CLKS_PER_SEC(priv, wdev->timeout), RWTCNT);

	return 0;
}

__attribute__((used)) static int rwdt_start(struct watchdog_device *wdev)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
	u8 val;

	pm_runtime_get_sync(wdev->parent);

	/* Stop the timer before we modify any register */
	val = readb_relaxed(priv->base + RWTCSRA) & ~RWTCSRA_TME;
	rwdt_write(priv, val, RWTCSRA);

	rwdt_init_timeout(wdev);
	rwdt_write(priv, priv->cks, RWTCSRA);
	rwdt_write(priv, 0, RWTCSRB);

	while (readb_relaxed(priv->base + RWTCSRA) & RWTCSRA_WRFLG)
		cpu_relax();

	rwdt_write(priv, priv->cks | RWTCSRA_TME, RWTCSRA);

	return 0;
}

__attribute__((used)) static int rwdt_stop(struct watchdog_device *wdev)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);

	rwdt_write(priv, priv->cks, RWTCSRA);
	pm_runtime_put(wdev->parent);

	return 0;
}

__attribute__((used)) static unsigned int rwdt_get_timeleft(struct watchdog_device *wdev)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
	u16 val = readw_relaxed(priv->base + RWTCNT);

	return DIV_BY_CLKS_PER_SEC(priv, 65536 - val);
}

__attribute__((used)) static int rwdt_restart(struct watchdog_device *wdev, unsigned long action,
			void *data)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);

	rwdt_start(wdev);
	rwdt_write(priv, 0xffff, RWTCNT);
	return 0;
}

__attribute__((used)) static inline bool rwdt_blacklisted(struct device *dev) { return false; }

__attribute__((used)) static int rwdt_probe(struct platform_device *pdev)
{
	struct rwdt_priv *priv;
	struct resource *res;
	struct clk *clk;
	unsigned long clks_per_sec;
	int ret, i;

	if (rwdt_blacklisted(&pdev->dev))
		return -ENODEV;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->base))
		return PTR_ERR(priv->base);

	clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_get_sync(&pdev->dev);
	priv->clk_rate = clk_get_rate(clk);
	priv->wdev.bootstatus = (readb_relaxed(priv->base + RWTCSRA) &
				RWTCSRA_WOVF) ? WDIOF_CARDRESET : 0;
	pm_runtime_put(&pdev->dev);

	if (!priv->clk_rate) {
		ret = -ENOENT;
		goto out_pm_disable;
	}

	for (i = ARRAY_SIZE(clk_divs) - 1; i >= 0; i--) {
		clks_per_sec = priv->clk_rate / clk_divs[i];
		if (clks_per_sec && clks_per_sec < 65536) {
			priv->cks = i;
			break;
		}
	}

	if (i < 0) {
		dev_err(&pdev->dev, "Can't find suitable clock divider\n");
		ret = -ERANGE;
		goto out_pm_disable;
	}

	priv->wdev.info = &rwdt_ident,
	priv->wdev.ops = &rwdt_ops,
	priv->wdev.parent = &pdev->dev;
	priv->wdev.min_timeout = 1;
	priv->wdev.max_timeout = DIV_BY_CLKS_PER_SEC(priv, 65536);
	priv->wdev.timeout = min(priv->wdev.max_timeout, RWDT_DEFAULT_TIMEOUT);

	platform_set_drvdata(pdev, priv);
	watchdog_set_drvdata(&priv->wdev, priv);
	watchdog_set_nowayout(&priv->wdev, nowayout);
	watchdog_set_restart_priority(&priv->wdev, 0);

	/* This overrides the default timeout only if DT configuration was found */
	ret = watchdog_init_timeout(&priv->wdev, 0, &pdev->dev);
	if (ret)
		dev_warn(&pdev->dev, "Specified timeout value invalid, using default\n");

	ret = watchdog_register_device(&priv->wdev);
	if (ret < 0)
		goto out_pm_disable;

	return 0;

 out_pm_disable:
	pm_runtime_disable(&pdev->dev);
	return ret;
}

__attribute__((used)) static int rwdt_remove(struct platform_device *pdev)
{
	struct rwdt_priv *priv = platform_get_drvdata(pdev);

	watchdog_unregister_device(&priv->wdev);
	pm_runtime_disable(&pdev->dev);

	return 0;
}

