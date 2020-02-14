#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct samsung_keypad_platdata {unsigned int rows; int cols; struct matrix_keymap_data* keymap_data; int /*<<< orphan*/  wakeup; int /*<<< orphan*/  no_autorepeat; int /*<<< orphan*/  (* cfg_gpio ) (unsigned int,int) ;} ;
struct samsung_keypad {unsigned int cols; scalar_t__ type; int rows; unsigned int* row_state; unsigned int row_shift; int stopped; int irq; struct samsung_keypad_platdata const* clk; struct input_dev* input_dev; int /*<<< orphan*/ * keycodes; int /*<<< orphan*/  wait; struct platform_device* pdev; scalar_t__ base; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {scalar_t__ of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct matrix_keymap_data {scalar_t__ keymap; } ;
struct TYPE_6__ {struct device* parent; } ;
struct TYPE_4__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; TYPE_3__ dev; TYPE_1__ id; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {scalar_t__ driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct samsung_keypad_platdata* ERR_PTR (int) ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct samsung_keypad_platdata const*) ; 
 scalar_t__ KEYPAD_TYPE_S5PV210 ; 
 unsigned int MATRIX_SCAN_CODE (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int PTR_ERR (struct samsung_keypad_platdata const*) ; 
 unsigned int S5PV210_KEYIFCOLEN_MASK ; 
 scalar_t__ SAMSUNG_KEYIFCOL ; 
 unsigned int SAMSUNG_KEYIFCOL_MASK ; 
 scalar_t__ SAMSUNG_KEYIFCON ; 
 unsigned int SAMSUNG_KEYIFCON_INT_F_EN ; 
 unsigned int SAMSUNG_KEYIFCON_INT_R_EN ; 
 scalar_t__ SAMSUNG_KEYIFROW ; 
 scalar_t__ SAMSUNG_KEYIFSTSCLR ; 
 int SAMSUNG_MAX_COLS ; 
 unsigned int SAMSUNG_MAX_ROWS ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable (struct samsung_keypad_platdata const*) ; 
 int /*<<< orphan*/  clk_enable (struct samsung_keypad_platdata const*) ; 
 int clk_prepare (struct samsung_keypad_platdata const*) ; 
 int /*<<< orphan*/  clk_unprepare (struct samsung_keypad_platdata const*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct samsung_keypad_platdata* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int /*<<< orphan*/ ) ; 
 struct samsung_keypad_platdata const* devm_clk_get (struct device*,char*) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_kfree (struct device*,void*) ; 
 struct samsung_keypad* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct samsung_keypad*) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 unsigned int get_count_order (int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 struct samsung_keypad* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct samsung_keypad*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int matrix_keypad_build_keymap (struct matrix_keymap_data const*,int /*<<< orphan*/ *,unsigned int,int,int /*<<< orphan*/ *,struct input_dev*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int*,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 scalar_t__ of_device_is_compatible (scalar_t__,char*) ; 
 TYPE_2__* platform_get_device_id (struct platform_device*) ; 
 struct samsung_keypad* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct samsung_keypad*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  stub1 (unsigned int,int) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static void samsung_keypad_scan(struct samsung_keypad *keypad,
				unsigned int *row_state)
{
	unsigned int col;
	unsigned int val;

	for (col = 0; col < keypad->cols; col++) {
		if (keypad->type == KEYPAD_TYPE_S5PV210) {
			val = S5PV210_KEYIFCOLEN_MASK;
			val &= ~(1 << col) << 8;
		} else {
			val = SAMSUNG_KEYIFCOL_MASK;
			val &= ~(1 << col);
		}

		writel(val, keypad->base + SAMSUNG_KEYIFCOL);
		mdelay(1);

		val = readl(keypad->base + SAMSUNG_KEYIFROW);
		row_state[col] = ~val & ((1 << keypad->rows) - 1);
	}

	/* KEYIFCOL reg clear */
	writel(0, keypad->base + SAMSUNG_KEYIFCOL);
}

__attribute__((used)) static bool samsung_keypad_report(struct samsung_keypad *keypad,
				  unsigned int *row_state)
{
	struct input_dev *input_dev = keypad->input_dev;
	unsigned int changed;
	unsigned int pressed;
	unsigned int key_down = 0;
	unsigned int val;
	unsigned int col, row;

	for (col = 0; col < keypad->cols; col++) {
		changed = row_state[col] ^ keypad->row_state[col];
		key_down |= row_state[col];
		if (!changed)
			continue;

		for (row = 0; row < keypad->rows; row++) {
			if (!(changed & (1 << row)))
				continue;

			pressed = row_state[col] & (1 << row);

			dev_dbg(&keypad->input_dev->dev,
				"key %s, row: %d, col: %d\n",
				pressed ? "pressed" : "released", row, col);

			val = MATRIX_SCAN_CODE(row, col, keypad->row_shift);

			input_event(input_dev, EV_MSC, MSC_SCAN, val);
			input_report_key(input_dev,
					keypad->keycodes[val], pressed);
		}
		input_sync(keypad->input_dev);
	}

	memcpy(keypad->row_state, row_state, sizeof(keypad->row_state));

	return key_down;
}

__attribute__((used)) static irqreturn_t samsung_keypad_irq(int irq, void *dev_id)
{
	struct samsung_keypad *keypad = dev_id;
	unsigned int row_state[SAMSUNG_MAX_COLS];
	unsigned int val;
	bool key_down;

	pm_runtime_get_sync(&keypad->pdev->dev);

	do {
		val = readl(keypad->base + SAMSUNG_KEYIFSTSCLR);
		/* Clear interrupt. */
		writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);

		samsung_keypad_scan(keypad, row_state);

		key_down = samsung_keypad_report(keypad, row_state);
		if (key_down)
			wait_event_timeout(keypad->wait, keypad->stopped,
					   msecs_to_jiffies(50));

	} while (key_down && !keypad->stopped);

	pm_runtime_put(&keypad->pdev->dev);

	return IRQ_HANDLED;
}

__attribute__((used)) static void samsung_keypad_start(struct samsung_keypad *keypad)
{
	unsigned int val;

	pm_runtime_get_sync(&keypad->pdev->dev);

	/* Tell IRQ thread that it may poll the device. */
	keypad->stopped = false;

	clk_enable(keypad->clk);

	/* Enable interrupt bits. */
	val = readl(keypad->base + SAMSUNG_KEYIFCON);
	val |= SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN;
	writel(val, keypad->base + SAMSUNG_KEYIFCON);

	/* KEYIFCOL reg clear. */
	writel(0, keypad->base + SAMSUNG_KEYIFCOL);

	pm_runtime_put(&keypad->pdev->dev);
}

__attribute__((used)) static void samsung_keypad_stop(struct samsung_keypad *keypad)
{
	unsigned int val;

	pm_runtime_get_sync(&keypad->pdev->dev);

	/* Signal IRQ thread to stop polling and disable the handler. */
	keypad->stopped = true;
	wake_up(&keypad->wait);
	disable_irq(keypad->irq);

	/* Clear interrupt. */
	writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);

	/* Disable interrupt bits. */
	val = readl(keypad->base + SAMSUNG_KEYIFCON);
	val &= ~(SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN);
	writel(val, keypad->base + SAMSUNG_KEYIFCON);

	clk_disable(keypad->clk);

	/*
	 * Now that chip should not generate interrupts we can safely
	 * re-enable the handler.
	 */
	enable_irq(keypad->irq);

	pm_runtime_put(&keypad->pdev->dev);
}

__attribute__((used)) static int samsung_keypad_open(struct input_dev *input_dev)
{
	struct samsung_keypad *keypad = input_get_drvdata(input_dev);

	samsung_keypad_start(keypad);

	return 0;
}

__attribute__((used)) static void samsung_keypad_close(struct input_dev *input_dev)
{
	struct samsung_keypad *keypad = input_get_drvdata(input_dev);

	samsung_keypad_stop(keypad);
}

__attribute__((used)) static struct samsung_keypad_platdata *
samsung_keypad_parse_dt(struct device *dev)
{
	dev_err(dev, "no platform data defined\n");

	return ERR_PTR(-EINVAL);
}

__attribute__((used)) static int samsung_keypad_probe(struct platform_device *pdev)
{
	const struct samsung_keypad_platdata *pdata;
	const struct matrix_keymap_data *keymap_data;
	struct samsung_keypad *keypad;
	struct resource *res;
	struct input_dev *input_dev;
	unsigned int row_shift;
	unsigned int keymap_size;
	int error;

	pdata = dev_get_platdata(&pdev->dev);
	if (!pdata) {
		pdata = samsung_keypad_parse_dt(&pdev->dev);
		if (IS_ERR(pdata))
			return PTR_ERR(pdata);
	}

	keymap_data = pdata->keymap_data;
	if (!keymap_data) {
		dev_err(&pdev->dev, "no keymap data defined\n");
		return -EINVAL;
	}

	if (!pdata->rows || pdata->rows > SAMSUNG_MAX_ROWS)
		return -EINVAL;

	if (!pdata->cols || pdata->cols > SAMSUNG_MAX_COLS)
		return -EINVAL;

	/* initialize the gpio */
	if (pdata->cfg_gpio)
		pdata->cfg_gpio(pdata->rows, pdata->cols);

	row_shift = get_count_order(pdata->cols);
	keymap_size = (pdata->rows << row_shift) * sizeof(keypad->keycodes[0]);

	keypad = devm_kzalloc(&pdev->dev, sizeof(*keypad) + keymap_size,
			      GFP_KERNEL);
	input_dev = devm_input_allocate_device(&pdev->dev);
	if (!keypad || !input_dev)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENODEV;

	keypad->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
	if (!keypad->base)
		return -EBUSY;

	keypad->clk = devm_clk_get(&pdev->dev, "keypad");
	if (IS_ERR(keypad->clk)) {
		dev_err(&pdev->dev, "failed to get keypad clk\n");
		return PTR_ERR(keypad->clk);
	}

	error = clk_prepare(keypad->clk);
	if (error) {
		dev_err(&pdev->dev, "keypad clock prepare failed\n");
		return error;
	}

	keypad->input_dev = input_dev;
	keypad->pdev = pdev;
	keypad->row_shift = row_shift;
	keypad->rows = pdata->rows;
	keypad->cols = pdata->cols;
	keypad->stopped = true;
	init_waitqueue_head(&keypad->wait);

	if (pdev->dev.of_node)
		keypad->type = of_device_is_compatible(pdev->dev.of_node,
					"samsung,s5pv210-keypad");
	else
		keypad->type = platform_get_device_id(pdev)->driver_data;

	input_dev->name = pdev->name;
	input_dev->id.bustype = BUS_HOST;
	input_dev->dev.parent = &pdev->dev;

	input_dev->open = samsung_keypad_open;
	input_dev->close = samsung_keypad_close;

	error = matrix_keypad_build_keymap(keymap_data, NULL,
					   pdata->rows, pdata->cols,
					   keypad->keycodes, input_dev);
	if (error) {
		dev_err(&pdev->dev, "failed to build keymap\n");
		goto err_unprepare_clk;
	}

	input_set_capability(input_dev, EV_MSC, MSC_SCAN);
	if (!pdata->no_autorepeat)
		__set_bit(EV_REP, input_dev->evbit);

	input_set_drvdata(input_dev, keypad);

	keypad->irq = platform_get_irq(pdev, 0);
	if (keypad->irq < 0) {
		error = keypad->irq;
		goto err_unprepare_clk;
	}

	error = devm_request_threaded_irq(&pdev->dev, keypad->irq, NULL,
					  samsung_keypad_irq, IRQF_ONESHOT,
					  dev_name(&pdev->dev), keypad);
	if (error) {
		dev_err(&pdev->dev, "failed to register keypad interrupt\n");
		goto err_unprepare_clk;
	}

	device_init_wakeup(&pdev->dev, pdata->wakeup);
	platform_set_drvdata(pdev, keypad);
	pm_runtime_enable(&pdev->dev);

	error = input_register_device(keypad->input_dev);
	if (error)
		goto err_disable_runtime_pm;

	if (pdev->dev.of_node) {
		devm_kfree(&pdev->dev, (void *)pdata->keymap_data->keymap);
		devm_kfree(&pdev->dev, (void *)pdata->keymap_data);
		devm_kfree(&pdev->dev, (void *)pdata);
	}
	return 0;

err_disable_runtime_pm:
	pm_runtime_disable(&pdev->dev);
err_unprepare_clk:
	clk_unprepare(keypad->clk);
	return error;
}

__attribute__((used)) static int samsung_keypad_remove(struct platform_device *pdev)
{
	struct samsung_keypad *keypad = platform_get_drvdata(pdev);

	pm_runtime_disable(&pdev->dev);

	input_unregister_device(keypad->input_dev);

	clk_unprepare(keypad->clk);

	return 0;
}

