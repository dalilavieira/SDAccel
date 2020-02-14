#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  unsigned int u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct img_ir_priv_raw {int dummy; } ;
struct img_ir_priv_hw {int dummy; } ;
struct img_ir_priv {int irq; void* sys_clk; void* clk; void* reg_base; int /*<<< orphan*/  lock; int /*<<< orphan*/ * dev; struct img_ir_priv_raw raw; struct img_ir_priv_hw hw; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int IMG_IR_CORE_REV ; 
 unsigned int IMG_IR_DESIGNER ; 
 unsigned int IMG_IR_DESIGNER_SHIFT ; 
 unsigned int IMG_IR_IRQ_CLEAR ; 
 unsigned int IMG_IR_IRQ_DATA2_VALID ; 
 unsigned int IMG_IR_IRQ_DATA_MATCH ; 
 unsigned int IMG_IR_IRQ_DATA_VALID ; 
 unsigned int IMG_IR_IRQ_EDGE ; 
 unsigned int IMG_IR_IRQ_ENABLE ; 
 unsigned int IMG_IR_IRQ_STATUS ; 
 unsigned int IMG_IR_MAINT_REV ; 
 unsigned int IMG_IR_MAINT_REV_SHIFT ; 
 unsigned int IMG_IR_MAJOR_REV ; 
 unsigned int IMG_IR_MAJOR_REV_SHIFT ; 
 unsigned int IMG_IR_MINOR_REV ; 
 unsigned int IMG_IR_MINOR_REV_SHIFT ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 void* devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 void* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct img_ir_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct img_ir_priv*) ; 
 unsigned int ioread32 (void*) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,void*) ; 
 struct img_ir_priv* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct img_ir_priv*) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct img_ir_priv*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool img_ir_raw_enabled(struct img_ir_priv_raw *raw)
{
	return false;
}

__attribute__((used)) static inline void img_ir_isr_raw(struct img_ir_priv *priv, u32 irq_status)
{
}

__attribute__((used)) static inline void img_ir_setup_raw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static inline int img_ir_probe_raw(struct img_ir_priv *priv)
{
	return -ENODEV;
}

__attribute__((used)) static inline void img_ir_remove_raw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static inline bool img_ir_hw_enabled(struct img_ir_priv_hw *hw)
{
	return false;
}

__attribute__((used)) static inline void img_ir_isr_hw(struct img_ir_priv *priv, u32 irq_status)
{
}

__attribute__((used)) static inline void img_ir_setup_hw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static inline int img_ir_probe_hw(struct img_ir_priv *priv)
{
	return -ENODEV;
}

__attribute__((used)) static inline void img_ir_remove_hw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static inline void img_ir_write(struct img_ir_priv *priv,
				unsigned int reg_offs, unsigned int data)
{
	iowrite32(data, priv->reg_base + reg_offs);
}

__attribute__((used)) static inline unsigned int img_ir_read(struct img_ir_priv *priv,
				       unsigned int reg_offs)
{
	return ioread32(priv->reg_base + reg_offs);
}

__attribute__((used)) static irqreturn_t img_ir_isr(int irq, void *dev_id)
{
	struct img_ir_priv *priv = dev_id;
	u32 irq_status;

	spin_lock(&priv->lock);
	/* we have to clear irqs before reading */
	irq_status = img_ir_read(priv, IMG_IR_IRQ_STATUS);
	img_ir_write(priv, IMG_IR_IRQ_CLEAR, irq_status);

	/* don't handle valid data irqs if we're only interested in matches */
	irq_status &= img_ir_read(priv, IMG_IR_IRQ_ENABLE);

	/* hand off edge interrupts to raw decode handler */
	if (irq_status & IMG_IR_IRQ_EDGE && img_ir_raw_enabled(&priv->raw))
		img_ir_isr_raw(priv, irq_status);

	/* hand off hardware match interrupts to hardware decode handler */
	if (irq_status & (IMG_IR_IRQ_DATA_MATCH |
			  IMG_IR_IRQ_DATA_VALID |
			  IMG_IR_IRQ_DATA2_VALID) &&
	    img_ir_hw_enabled(&priv->hw))
		img_ir_isr_hw(priv, irq_status);

	spin_unlock(&priv->lock);
	return IRQ_HANDLED;
}

__attribute__((used)) static void img_ir_setup(struct img_ir_priv *priv)
{
	/* start off with interrupts disabled */
	img_ir_write(priv, IMG_IR_IRQ_ENABLE, 0);

	img_ir_setup_raw(priv);
	img_ir_setup_hw(priv);

	if (!IS_ERR(priv->clk))
		clk_prepare_enable(priv->clk);
}

__attribute__((used)) static void img_ir_ident(struct img_ir_priv *priv)
{
	u32 core_rev = img_ir_read(priv, IMG_IR_CORE_REV);

	dev_info(priv->dev,
		 "IMG IR Decoder (%d.%d.%d.%d) probed successfully\n",
		 (core_rev & IMG_IR_DESIGNER) >> IMG_IR_DESIGNER_SHIFT,
		 (core_rev & IMG_IR_MAJOR_REV) >> IMG_IR_MAJOR_REV_SHIFT,
		 (core_rev & IMG_IR_MINOR_REV) >> IMG_IR_MINOR_REV_SHIFT,
		 (core_rev & IMG_IR_MAINT_REV) >> IMG_IR_MAINT_REV_SHIFT);
	dev_info(priv->dev, "Modes:%s%s\n",
		 img_ir_hw_enabled(&priv->hw) ? " hardware" : "",
		 img_ir_raw_enabled(&priv->raw) ? " raw" : "");
}

__attribute__((used)) static int img_ir_probe(struct platform_device *pdev)
{
	struct img_ir_priv *priv;
	struct resource *res_regs;
	int irq, error, error2;

	/* Get resources from platform device */
	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "cannot find IRQ resource\n");
		return irq;
	}

	/* Private driver data */
	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv);
	priv->dev = &pdev->dev;
	spin_lock_init(&priv->lock);

	/* Ioremap the registers */
	res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->reg_base = devm_ioremap_resource(&pdev->dev, res_regs);
	if (IS_ERR(priv->reg_base))
		return PTR_ERR(priv->reg_base);

	/* Get core clock */
	priv->clk = devm_clk_get(&pdev->dev, "core");
	if (IS_ERR(priv->clk))
		dev_warn(&pdev->dev, "cannot get core clock resource\n");

	/* Get sys clock */
	priv->sys_clk = devm_clk_get(&pdev->dev, "sys");
	if (IS_ERR(priv->sys_clk))
		dev_warn(&pdev->dev, "cannot get sys clock resource\n");
	/*
	 * Enabling the system clock before the register interface is
	 * accessed. ISR shouldn't get called with Sys Clock disabled,
	 * hence exiting probe with an error.
	 */
	if (!IS_ERR(priv->sys_clk)) {
		error = clk_prepare_enable(priv->sys_clk);
		if (error) {
			dev_err(&pdev->dev, "cannot enable sys clock\n");
			return error;
		}
	}

	/* Set up raw & hw decoder */
	error = img_ir_probe_raw(priv);
	error2 = img_ir_probe_hw(priv);
	if (error && error2) {
		if (error == -ENODEV)
			error = error2;
		goto err_probe;
	}

	/* Get the IRQ */
	priv->irq = irq;
	error = request_irq(priv->irq, img_ir_isr, 0, "img-ir", priv);
	if (error) {
		dev_err(&pdev->dev, "cannot register IRQ %u\n",
			priv->irq);
		error = -EIO;
		goto err_irq;
	}

	img_ir_ident(priv);
	img_ir_setup(priv);

	return 0;

err_irq:
	img_ir_remove_hw(priv);
	img_ir_remove_raw(priv);
err_probe:
	if (!IS_ERR(priv->sys_clk))
		clk_disable_unprepare(priv->sys_clk);
	return error;
}

__attribute__((used)) static int img_ir_remove(struct platform_device *pdev)
{
	struct img_ir_priv *priv = platform_get_drvdata(pdev);

	free_irq(priv->irq, priv);
	img_ir_remove_hw(priv);
	img_ir_remove_raw(priv);

	if (!IS_ERR(priv->clk))
		clk_disable_unprepare(priv->clk);
	if (!IS_ERR(priv->sys_clk))
		clk_disable_unprepare(priv->sys_clk);
	return 0;
}

