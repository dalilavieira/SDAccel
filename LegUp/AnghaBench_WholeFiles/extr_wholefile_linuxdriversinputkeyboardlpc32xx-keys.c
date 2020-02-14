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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
struct resource {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct lpc32xx_kscan_drv {int* lastkeystates; int row_shift; unsigned int* keymap; int matrix_sz; int deb_clks; int scan_delay; struct input_dev* input; int /*<<< orphan*/  clk; int /*<<< orphan*/  kscan_base; } ;
struct TYPE_4__ {struct device* parent; } ;
struct TYPE_3__ {int vendor; int product; int version; } ;
struct input_dev {char* phys; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LPC32XX_KSCAN_FTST_USE32K_CLK ; 
 int /*<<< orphan*/  LPC32XX_KS_DATA (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  LPC32XX_KS_DEB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC32XX_KS_FAST_TST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC32XX_KS_IRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC32XX_KS_MATRIX_DIM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC32XX_KS_SCAN_CTL (int /*<<< orphan*/ ) ; 
 unsigned int MATRIX_SCAN_CODE (unsigned int,int,int) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 void* devm_kzalloc (struct device*,size_t,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lpc32xx_kscan_drv*) ; 
 int get_count_order (scalar_t__) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 struct lpc32xx_kscan_drv* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,unsigned int,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct lpc32xx_kscan_drv*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,unsigned int*,struct input_dev*) ; 
 int matrix_keypad_parse_properties (struct device*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lpc32xx_kscan_drv*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lpc32xx_mod_states(struct lpc32xx_kscan_drv *kscandat, int col)
{
	struct input_dev *input = kscandat->input;
	unsigned row, changed, scancode, keycode;
	u8 key;

	key = readl(LPC32XX_KS_DATA(kscandat->kscan_base, col));
	changed = key ^ kscandat->lastkeystates[col];
	kscandat->lastkeystates[col] = key;

	for (row = 0; changed; row++, changed >>= 1) {
		if (changed & 1) {
			/* Key state changed, signal an event */
			scancode = MATRIX_SCAN_CODE(row, col,
						    kscandat->row_shift);
			keycode = kscandat->keymap[scancode];
			input_event(input, EV_MSC, MSC_SCAN, scancode);
			input_report_key(input, keycode, key & (1 << row));
		}
	}
}

__attribute__((used)) static irqreturn_t lpc32xx_kscan_irq(int irq, void *dev_id)
{
	struct lpc32xx_kscan_drv *kscandat = dev_id;
	int i;

	for (i = 0; i < kscandat->matrix_sz; i++)
		lpc32xx_mod_states(kscandat, i);

	writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));

	input_sync(kscandat->input);

	return IRQ_HANDLED;
}

__attribute__((used)) static int lpc32xx_kscan_open(struct input_dev *dev)
{
	struct lpc32xx_kscan_drv *kscandat = input_get_drvdata(dev);
	int error;

	error = clk_prepare_enable(kscandat->clk);
	if (error)
		return error;

	writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));

	return 0;
}

__attribute__((used)) static void lpc32xx_kscan_close(struct input_dev *dev)
{
	struct lpc32xx_kscan_drv *kscandat = input_get_drvdata(dev);

	writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
	clk_disable_unprepare(kscandat->clk);
}

__attribute__((used)) static int lpc32xx_parse_dt(struct device *dev,
				      struct lpc32xx_kscan_drv *kscandat)
{
	struct device_node *np = dev->of_node;
	u32 rows = 0, columns = 0;
	int err;

	err = matrix_keypad_parse_properties(dev, &rows, &columns);
	if (err)
		return err;
	if (rows != columns) {
		dev_err(dev, "rows and columns must be equal!\n");
		return -EINVAL;
	}

	kscandat->matrix_sz = rows;
	kscandat->row_shift = get_count_order(columns);

	of_property_read_u32(np, "nxp,debounce-delay-ms", &kscandat->deb_clks);
	of_property_read_u32(np, "nxp,scan-delay-ms", &kscandat->scan_delay);
	if (!kscandat->deb_clks || !kscandat->scan_delay) {
		dev_err(dev, "debounce or scan delay not specified\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int lpc32xx_kscan_probe(struct platform_device *pdev)
{
	struct lpc32xx_kscan_drv *kscandat;
	struct input_dev *input;
	struct resource *res;
	size_t keymap_size;
	int error;
	int irq;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "failed to get platform I/O memory\n");
		return -EINVAL;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "failed to get platform irq\n");
		return -EINVAL;
	}

	kscandat = devm_kzalloc(&pdev->dev, sizeof(*kscandat),
				GFP_KERNEL);
	if (!kscandat)
		return -ENOMEM;

	error = lpc32xx_parse_dt(&pdev->dev, kscandat);
	if (error) {
		dev_err(&pdev->dev, "failed to parse device tree\n");
		return error;
	}

	keymap_size = sizeof(kscandat->keymap[0]) *
				(kscandat->matrix_sz << kscandat->row_shift);
	kscandat->keymap = devm_kzalloc(&pdev->dev, keymap_size, GFP_KERNEL);
	if (!kscandat->keymap)
		return -ENOMEM;

	kscandat->input = input = devm_input_allocate_device(&pdev->dev);
	if (!input) {
		dev_err(&pdev->dev, "failed to allocate input device\n");
		return -ENOMEM;
	}

	/* Setup key input */
	input->name		= pdev->name;
	input->phys		= "lpc32xx/input0";
	input->id.vendor	= 0x0001;
	input->id.product	= 0x0001;
	input->id.version	= 0x0100;
	input->open		= lpc32xx_kscan_open;
	input->close		= lpc32xx_kscan_close;
	input->dev.parent	= &pdev->dev;

	input_set_capability(input, EV_MSC, MSC_SCAN);

	error = matrix_keypad_build_keymap(NULL, NULL,
					   kscandat->matrix_sz,
					   kscandat->matrix_sz,
					   kscandat->keymap, kscandat->input);
	if (error) {
		dev_err(&pdev->dev, "failed to build keymap\n");
		return error;
	}

	input_set_drvdata(kscandat->input, kscandat);

	kscandat->kscan_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(kscandat->kscan_base))
		return PTR_ERR(kscandat->kscan_base);

	/* Get the key scanner clock */
	kscandat->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(kscandat->clk)) {
		dev_err(&pdev->dev, "failed to get clock\n");
		return PTR_ERR(kscandat->clk);
	}

	/* Configure the key scanner */
	error = clk_prepare_enable(kscandat->clk);
	if (error)
		return error;

	writel(kscandat->deb_clks, LPC32XX_KS_DEB(kscandat->kscan_base));
	writel(kscandat->scan_delay, LPC32XX_KS_SCAN_CTL(kscandat->kscan_base));
	writel(LPC32XX_KSCAN_FTST_USE32K_CLK,
	       LPC32XX_KS_FAST_TST(kscandat->kscan_base));
	writel(kscandat->matrix_sz,
	       LPC32XX_KS_MATRIX_DIM(kscandat->kscan_base));
	writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
	clk_disable_unprepare(kscandat->clk);

	error = devm_request_irq(&pdev->dev, irq, lpc32xx_kscan_irq, 0,
				 pdev->name, kscandat);
	if (error) {
		dev_err(&pdev->dev, "failed to request irq\n");
		return error;
	}

	error = input_register_device(kscandat->input);
	if (error) {
		dev_err(&pdev->dev, "failed to register input device\n");
		return error;
	}

	platform_set_drvdata(pdev, kscandat);

	return 0;
}

