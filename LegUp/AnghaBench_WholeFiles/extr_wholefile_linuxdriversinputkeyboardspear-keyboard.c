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
typedef  size_t u32 ;
struct spear_kbd {void* last_key; unsigned int* keycodes; size_t mode; int irq; scalar_t__ clk; struct input_dev* input; scalar_t__ rep; scalar_t__ io_base; int /*<<< orphan*/  suspended_rate; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct matrix_keymap_data {int dummy; } ;
struct kbd_platform_data {size_t mode; int /*<<< orphan*/  suspended_rate; scalar_t__ rep; struct matrix_keymap_data* keymap; } ;
struct TYPE_2__ {int vendor; int product; int version; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; char* phys; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; TYPE_1__ id; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 size_t DATA_COLUMN_MASK ; 
 scalar_t__ DATA_REG ; 
 size_t DATA_ROW_MASK ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 void* KEY_RESERVED ; 
 size_t MODE_CTL_KEYBOARD ; 
 size_t MODE_CTL_KEYNUM_SHIFT ; 
 size_t MODE_CTL_PCLK_FREQ_MSK ; 
 size_t MODE_CTL_PCLK_FREQ_SHIFT ; 
 scalar_t__ MODE_CTL_REG ; 
 size_t MODE_CTL_SCAN_RATE_80 ; 
 size_t MODE_CTL_START_SCAN ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int /*<<< orphan*/  NUM_COLS ; 
 int /*<<< orphan*/  NUM_ROWS ; 
 int PTR_ERR (scalar_t__) ; 
 size_t STATUS_DATA_AVAIL ; 
 scalar_t__ STATUS_REG ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 int clk_get_rate (scalar_t__) ; 
 int clk_prepare (scalar_t__) ; 
 int /*<<< orphan*/  clk_unprepare (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct kbd_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct spear_kbd* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct spear_kbd*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 struct spear_kbd* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,unsigned int,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct spear_kbd*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int matrix_keypad_build_keymap (struct matrix_keymap_data const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*,struct input_dev*) ; 
 struct spear_kbd* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct spear_kbd*) ; 
 size_t readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (size_t,scalar_t__) ; 

__attribute__((used)) static irqreturn_t spear_kbd_interrupt(int irq, void *dev_id)
{
	struct spear_kbd *kbd = dev_id;
	struct input_dev *input = kbd->input;
	unsigned int key;
	u32 sts, val;

	sts = readl_relaxed(kbd->io_base + STATUS_REG);
	if (!(sts & STATUS_DATA_AVAIL))
		return IRQ_NONE;

	if (kbd->last_key != KEY_RESERVED) {
		input_report_key(input, kbd->last_key, 0);
		kbd->last_key = KEY_RESERVED;
	}

	/* following reads active (row, col) pair */
	val = readl_relaxed(kbd->io_base + DATA_REG) &
		(DATA_ROW_MASK | DATA_COLUMN_MASK);
	key = kbd->keycodes[val];

	input_event(input, EV_MSC, MSC_SCAN, val);
	input_report_key(input, key, 1);
	input_sync(input);

	kbd->last_key = key;

	/* clear interrupt */
	writel_relaxed(0, kbd->io_base + STATUS_REG);

	return IRQ_HANDLED;
}

__attribute__((used)) static int spear_kbd_open(struct input_dev *dev)
{
	struct spear_kbd *kbd = input_get_drvdata(dev);
	int error;
	u32 val;

	kbd->last_key = KEY_RESERVED;

	error = clk_enable(kbd->clk);
	if (error)
		return error;

	/* keyboard rate to be programmed is input clock (in MHz) - 1 */
	val = clk_get_rate(kbd->clk) / 1000000 - 1;
	val = (val & MODE_CTL_PCLK_FREQ_MSK) << MODE_CTL_PCLK_FREQ_SHIFT;

	/* program keyboard */
	val = MODE_CTL_SCAN_RATE_80 | MODE_CTL_KEYBOARD | val |
		(kbd->mode << MODE_CTL_KEYNUM_SHIFT);
	writel_relaxed(val, kbd->io_base + MODE_CTL_REG);
	writel_relaxed(1, kbd->io_base + STATUS_REG);

	/* start key scan */
	val = readl_relaxed(kbd->io_base + MODE_CTL_REG);
	val |= MODE_CTL_START_SCAN;
	writel_relaxed(val, kbd->io_base + MODE_CTL_REG);

	return 0;
}

__attribute__((used)) static void spear_kbd_close(struct input_dev *dev)
{
	struct spear_kbd *kbd = input_get_drvdata(dev);
	u32 val;

	/* stop key scan */
	val = readl_relaxed(kbd->io_base + MODE_CTL_REG);
	val &= ~MODE_CTL_START_SCAN;
	writel_relaxed(val, kbd->io_base + MODE_CTL_REG);

	clk_disable(kbd->clk);

	kbd->last_key = KEY_RESERVED;
}

__attribute__((used)) static inline int spear_kbd_parse_dt(struct platform_device *pdev,
				     struct spear_kbd *kbd)
{
	return -ENOSYS;
}

__attribute__((used)) static int spear_kbd_probe(struct platform_device *pdev)
{
	struct kbd_platform_data *pdata = dev_get_platdata(&pdev->dev);
	const struct matrix_keymap_data *keymap = pdata ? pdata->keymap : NULL;
	struct spear_kbd *kbd;
	struct input_dev *input_dev;
	struct resource *res;
	int irq;
	int error;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "not able to get irq for the device\n");
		return irq;
	}

	kbd = devm_kzalloc(&pdev->dev, sizeof(*kbd), GFP_KERNEL);
	if (!kbd) {
		dev_err(&pdev->dev, "not enough memory for driver data\n");
		return -ENOMEM;
	}

	input_dev = devm_input_allocate_device(&pdev->dev);
	if (!input_dev) {
		dev_err(&pdev->dev, "unable to allocate input device\n");
		return -ENOMEM;
	}

	kbd->input = input_dev;
	kbd->irq = irq;

	if (!pdata) {
		error = spear_kbd_parse_dt(pdev, kbd);
		if (error)
			return error;
	} else {
		kbd->mode = pdata->mode;
		kbd->rep = pdata->rep;
		kbd->suspended_rate = pdata->suspended_rate;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	kbd->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(kbd->io_base))
		return PTR_ERR(kbd->io_base);

	kbd->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(kbd->clk))
		return PTR_ERR(kbd->clk);

	input_dev->name = "Spear Keyboard";
	input_dev->phys = "keyboard/input0";
	input_dev->id.bustype = BUS_HOST;
	input_dev->id.vendor = 0x0001;
	input_dev->id.product = 0x0001;
	input_dev->id.version = 0x0100;
	input_dev->open = spear_kbd_open;
	input_dev->close = spear_kbd_close;

	error = matrix_keypad_build_keymap(keymap, NULL, NUM_ROWS, NUM_COLS,
					   kbd->keycodes, input_dev);
	if (error) {
		dev_err(&pdev->dev, "Failed to build keymap\n");
		return error;
	}

	if (kbd->rep)
		__set_bit(EV_REP, input_dev->evbit);
	input_set_capability(input_dev, EV_MSC, MSC_SCAN);

	input_set_drvdata(input_dev, kbd);

	error = devm_request_irq(&pdev->dev, irq, spear_kbd_interrupt, 0,
			"keyboard", kbd);
	if (error) {
		dev_err(&pdev->dev, "request_irq failed\n");
		return error;
	}

	error = clk_prepare(kbd->clk);
	if (error)
		return error;

	error = input_register_device(input_dev);
	if (error) {
		dev_err(&pdev->dev, "Unable to register keyboard device\n");
		clk_unprepare(kbd->clk);
		return error;
	}

	device_init_wakeup(&pdev->dev, 1);
	platform_set_drvdata(pdev, kbd);

	return 0;
}

__attribute__((used)) static int spear_kbd_remove(struct platform_device *pdev)
{
	struct spear_kbd *kbd = platform_get_drvdata(pdev);

	input_unregister_device(kbd->input);
	clk_unprepare(kbd->clk);

	return 0;
}

