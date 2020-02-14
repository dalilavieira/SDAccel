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
typedef  int u8 ;
typedef  int u32 ;
struct tc_keypad {int keypad_stopped; int /*<<< orphan*/ * keymap; struct tc3589x* tc3589x; struct input_dev* input; struct tc3589x_keypad_platform_data const* board; } ;
typedef  struct tc3589x_keypad_platform_data {int kcol; int krow; int settle_time; int debounce_period; int enable_wakeup; int irqtype; scalar_t__ no_autorepeat; int /*<<< orphan*/  keymap_data; } const tc3589x_keypad_platform_data ;
struct tc3589x {int dummy; } ;
struct device {struct device* parent; struct device_node* of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct TYPE_2__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; int /*<<< orphan*/ * keycode; struct device dev; int /*<<< orphan*/  name; TYPE_1__ id; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 int DEDICATED_KEY_VAL ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 struct tc3589x_keypad_platform_data const* ERR_PTR (int) ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IOCFG_IG ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct tc3589x_keypad_platform_data const*) ; 
 int KPD_CLK_EN ; 
 int KP_EVCODE_COL_MASK ; 
 int KP_EVCODE_ROW_MASK ; 
 int KP_RELEASE_EVT_MASK ; 
 int KP_ROW_SHIFT ; 
 int MATRIX_SCAN_CODE (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int PTR_ERR (struct tc3589x_keypad_platform_data const*) ; 
 int TC35893_DATA_REGS ; 
 int TC35893_KEYCODE_FIFO_CLEAR ; 
 int TC35893_KEYCODE_FIFO_EMPTY ; 
 int /*<<< orphan*/  TC35893_KEYPAD_ROW_SHIFT ; 
 int /*<<< orphan*/  TC3589x_CLKEN ; 
 int /*<<< orphan*/  TC3589x_EVTCODE_FIFO ; 
 int TC3589x_EVT_INT ; 
 int TC3589x_EVT_INT_CLR ; 
 int TC3589x_EVT_LOSS_INT ; 
 int /*<<< orphan*/  TC3589x_IOCFG ; 
 int /*<<< orphan*/  TC3589x_IOPULLCFG0_LSB ; 
 int /*<<< orphan*/  TC3589x_IOPULLCFG0_MSB ; 
 int /*<<< orphan*/  TC3589x_IOPULLCFG1_LSB ; 
 int /*<<< orphan*/  TC3589x_IOPULLCFG1_MSB ; 
 int /*<<< orphan*/  TC3589x_IOPULLCFG2_LSB ; 
 int /*<<< orphan*/  TC3589x_KBCFG_LSB ; 
 int /*<<< orphan*/  TC3589x_KBCFG_MSB ; 
 int /*<<< orphan*/  TC3589x_KBDBOUNCE ; 
 int /*<<< orphan*/  TC3589x_KBDIC ; 
 int /*<<< orphan*/  TC3589x_KBDMFS ; 
 int TC3589x_KBDMFS_EN ; 
 int /*<<< orphan*/  TC3589x_KBDMSK ; 
 int TC3589x_KBDRST ; 
 int /*<<< orphan*/  TC3589x_KBDSETTLE_REG ; 
 int /*<<< orphan*/  TC3589x_KBDSIZE ; 
 int TC3589x_KBD_INT_CLR ; 
 int TC3589x_MAX_KPCOL ; 
 int TC3589x_MAX_KPROW ; 
 int TC3589x_PULLUP_ALL_MASK ; 
 int /*<<< orphan*/  TC3589x_RSTCTRL ; 
 int /*<<< orphan*/  TC3589x_RSTINTCLR ; 
 scalar_t__ TC_KPD_COLUMNS ; 
 int TC_KPD_DEBOUNCE_PERIOD ; 
 scalar_t__ TC_KPD_ROWS ; 
 int TC_KPD_SETTLE_TIME ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct tc3589x* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (struct device*,int) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct tc_keypad*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct tc_keypad* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct tc_keypad*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,struct input_dev*) ; 
 int /*<<< orphan*/  of_get_property (struct device_node*,char*,int*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tc_keypad*) ; 
 int tc3589x_reg_read (struct tc3589x*,int /*<<< orphan*/ ) ; 
 int tc3589x_reg_write (struct tc3589x*,int /*<<< orphan*/ ,int) ; 
 int tc3589x_set_bits (struct tc3589x*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int tc3589x_keypad_init_key_hardware(struct tc_keypad *keypad)
{
	int ret;
	struct tc3589x *tc3589x = keypad->tc3589x;
	const struct tc3589x_keypad_platform_data *board = keypad->board;

	/* validate platform configuration */
	if (board->kcol > TC3589x_MAX_KPCOL || board->krow > TC3589x_MAX_KPROW)
		return -EINVAL;

	/* configure KBDSIZE 4 LSbits for cols and 4 MSbits for rows */
	ret = tc3589x_reg_write(tc3589x, TC3589x_KBDSIZE,
			(board->krow << KP_ROW_SHIFT) | board->kcol);
	if (ret < 0)
		return ret;

	/* configure dedicated key config, no dedicated key selected */
	ret = tc3589x_reg_write(tc3589x, TC3589x_KBCFG_LSB, DEDICATED_KEY_VAL);
	if (ret < 0)
		return ret;

	ret = tc3589x_reg_write(tc3589x, TC3589x_KBCFG_MSB, DEDICATED_KEY_VAL);
	if (ret < 0)
		return ret;

	/* Configure settle time */
	ret = tc3589x_reg_write(tc3589x, TC3589x_KBDSETTLE_REG,
				board->settle_time);
	if (ret < 0)
		return ret;

	/* Configure debounce time */
	ret = tc3589x_reg_write(tc3589x, TC3589x_KBDBOUNCE,
				board->debounce_period);
	if (ret < 0)
		return ret;

	/* Start of initialise keypad GPIOs */
	ret = tc3589x_set_bits(tc3589x, TC3589x_IOCFG, 0x0, IOCFG_IG);
	if (ret < 0)
		return ret;

	/* Configure pull-up resistors for all row GPIOs */
	ret = tc3589x_reg_write(tc3589x, TC3589x_IOPULLCFG0_LSB,
					TC3589x_PULLUP_ALL_MASK);
	if (ret < 0)
		return ret;

	ret = tc3589x_reg_write(tc3589x, TC3589x_IOPULLCFG0_MSB,
					TC3589x_PULLUP_ALL_MASK);
	if (ret < 0)
		return ret;

	/* Configure pull-up resistors for all column GPIOs */
	ret = tc3589x_reg_write(tc3589x, TC3589x_IOPULLCFG1_LSB,
			TC3589x_PULLUP_ALL_MASK);
	if (ret < 0)
		return ret;

	ret = tc3589x_reg_write(tc3589x, TC3589x_IOPULLCFG1_MSB,
			TC3589x_PULLUP_ALL_MASK);
	if (ret < 0)
		return ret;

	ret = tc3589x_reg_write(tc3589x, TC3589x_IOPULLCFG2_LSB,
			TC3589x_PULLUP_ALL_MASK);

	return ret;
}

__attribute__((used)) static irqreturn_t tc3589x_keypad_irq(int irq, void *dev)
{
	struct tc_keypad *keypad = dev;
	struct tc3589x *tc3589x = keypad->tc3589x;
	u8 i, row_index, col_index, kbd_code, up;
	u8 code;

	for (i = 0; i < TC35893_DATA_REGS * 2; i++) {
		kbd_code = tc3589x_reg_read(tc3589x, TC3589x_EVTCODE_FIFO);

		/* loop till fifo is empty and no more keys are pressed */
		if (kbd_code == TC35893_KEYCODE_FIFO_EMPTY ||
				kbd_code == TC35893_KEYCODE_FIFO_CLEAR)
			continue;

		/* valid key is found */
		col_index = kbd_code & KP_EVCODE_COL_MASK;
		row_index = (kbd_code & KP_EVCODE_ROW_MASK) >> KP_ROW_SHIFT;
		code = MATRIX_SCAN_CODE(row_index, col_index,
						TC35893_KEYPAD_ROW_SHIFT);
		up = kbd_code & KP_RELEASE_EVT_MASK;

		input_event(keypad->input, EV_MSC, MSC_SCAN, code);
		input_report_key(keypad->input, keypad->keymap[code], !up);
		input_sync(keypad->input);
	}

	/* clear IRQ */
	tc3589x_set_bits(tc3589x, TC3589x_KBDIC,
			0x0, TC3589x_EVT_INT_CLR | TC3589x_KBD_INT_CLR);
	/* enable IRQ */
	tc3589x_set_bits(tc3589x, TC3589x_KBDMSK,
			0x0, TC3589x_EVT_LOSS_INT | TC3589x_EVT_INT);

	return IRQ_HANDLED;
}

__attribute__((used)) static int tc3589x_keypad_enable(struct tc_keypad *keypad)
{
	struct tc3589x *tc3589x = keypad->tc3589x;
	int ret;

	/* pull the keypad module out of reset */
	ret = tc3589x_set_bits(tc3589x, TC3589x_RSTCTRL, TC3589x_KBDRST, 0x0);
	if (ret < 0)
		return ret;

	/* configure KBDMFS */
	ret = tc3589x_set_bits(tc3589x, TC3589x_KBDMFS, 0x0, TC3589x_KBDMFS_EN);
	if (ret < 0)
		return ret;

	/* enable the keypad clock */
	ret = tc3589x_set_bits(tc3589x, TC3589x_CLKEN, 0x0, KPD_CLK_EN);
	if (ret < 0)
		return ret;

	/* clear pending IRQs */
	ret =  tc3589x_set_bits(tc3589x, TC3589x_RSTINTCLR, 0x0, 0x1);
	if (ret < 0)
		return ret;

	/* enable the IRQs */
	ret = tc3589x_set_bits(tc3589x, TC3589x_KBDMSK, 0x0,
					TC3589x_EVT_LOSS_INT | TC3589x_EVT_INT);
	if (ret < 0)
		return ret;

	keypad->keypad_stopped = false;

	return ret;
}

__attribute__((used)) static int tc3589x_keypad_disable(struct tc_keypad *keypad)
{
	struct tc3589x *tc3589x = keypad->tc3589x;
	int ret;

	/* clear IRQ */
	ret = tc3589x_set_bits(tc3589x, TC3589x_KBDIC,
			0x0, TC3589x_EVT_INT_CLR | TC3589x_KBD_INT_CLR);
	if (ret < 0)
		return ret;

	/* disable all interrupts */
	ret = tc3589x_set_bits(tc3589x, TC3589x_KBDMSK,
			~(TC3589x_EVT_LOSS_INT | TC3589x_EVT_INT), 0x0);
	if (ret < 0)
		return ret;

	/* disable the keypad module */
	ret = tc3589x_set_bits(tc3589x, TC3589x_CLKEN, 0x1, 0x0);
	if (ret < 0)
		return ret;

	/* put the keypad module into reset */
	ret = tc3589x_set_bits(tc3589x, TC3589x_RSTCTRL, TC3589x_KBDRST, 0x1);

	keypad->keypad_stopped = true;

	return ret;
}

__attribute__((used)) static int tc3589x_keypad_open(struct input_dev *input)
{
	int error;
	struct tc_keypad *keypad = input_get_drvdata(input);

	/* enable the keypad module */
	error = tc3589x_keypad_enable(keypad);
	if (error < 0) {
		dev_err(&input->dev, "failed to enable keypad module\n");
		return error;
	}

	error = tc3589x_keypad_init_key_hardware(keypad);
	if (error < 0) {
		dev_err(&input->dev, "failed to configure keypad module\n");
		return error;
	}

	return 0;
}

__attribute__((used)) static void tc3589x_keypad_close(struct input_dev *input)
{
	struct tc_keypad *keypad = input_get_drvdata(input);

	/* disable the keypad module */
	tc3589x_keypad_disable(keypad);
}

__attribute__((used)) static const struct tc3589x_keypad_platform_data *
tc3589x_keypad_of_probe(struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct tc3589x_keypad_platform_data *plat;
	u32 cols, rows;
	u32 debounce_ms;
	int proplen;

	if (!np)
		return ERR_PTR(-ENODEV);

	plat = devm_kzalloc(dev, sizeof(*plat), GFP_KERNEL);
	if (!plat)
		return ERR_PTR(-ENOMEM);

	of_property_read_u32(np, "keypad,num-columns", &cols);
	of_property_read_u32(np, "keypad,num-rows", &rows);
	plat->kcol = (u8) cols;
	plat->krow = (u8) rows;
	if (!plat->krow || !plat->kcol ||
	     plat->krow > TC_KPD_ROWS || plat->kcol > TC_KPD_COLUMNS) {
		dev_err(dev,
			"keypad columns/rows not properly specified (%ux%u)\n",
			plat->kcol, plat->krow);
		return ERR_PTR(-EINVAL);
	}

	if (!of_get_property(np, "linux,keymap", &proplen)) {
		dev_err(dev, "property linux,keymap not found\n");
		return ERR_PTR(-ENOENT);
	}

	plat->no_autorepeat = of_property_read_bool(np, "linux,no-autorepeat");

	plat->enable_wakeup = of_property_read_bool(np, "wakeup-source") ||
			      /* legacy name */
			      of_property_read_bool(np, "linux,wakeup");

	/* The custom delay format is ms/16 */
	of_property_read_u32(np, "debounce-delay-ms", &debounce_ms);
	if (debounce_ms)
		plat->debounce_period = debounce_ms * 16;
	else
		plat->debounce_period = TC_KPD_DEBOUNCE_PERIOD;

	plat->settle_time = TC_KPD_SETTLE_TIME;
	/* FIXME: should be property of the IRQ resource? */
	plat->irqtype = IRQF_TRIGGER_FALLING;

	return plat;
}

__attribute__((used)) static int tc3589x_keypad_probe(struct platform_device *pdev)
{
	struct tc3589x *tc3589x = dev_get_drvdata(pdev->dev.parent);
	struct tc_keypad *keypad;
	struct input_dev *input;
	const struct tc3589x_keypad_platform_data *plat;
	int error, irq;

	plat = tc3589x_keypad_of_probe(&pdev->dev);
	if (IS_ERR(plat)) {
		dev_err(&pdev->dev, "invalid keypad platform data\n");
		return PTR_ERR(plat);
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	keypad = devm_kzalloc(&pdev->dev, sizeof(struct tc_keypad),
			      GFP_KERNEL);
	if (!keypad)
		return -ENOMEM;

	input = devm_input_allocate_device(&pdev->dev);
	if (!input) {
		dev_err(&pdev->dev, "failed to allocate input device\n");
		return -ENOMEM;
	}

	keypad->board = plat;
	keypad->input = input;
	keypad->tc3589x = tc3589x;

	input->id.bustype = BUS_I2C;
	input->name = pdev->name;
	input->dev.parent = &pdev->dev;

	input->open = tc3589x_keypad_open;
	input->close = tc3589x_keypad_close;

	error = matrix_keypad_build_keymap(plat->keymap_data, NULL,
					   TC3589x_MAX_KPROW, TC3589x_MAX_KPCOL,
					   NULL, input);
	if (error) {
		dev_err(&pdev->dev, "Failed to build keymap\n");
		return error;
	}

	keypad->keymap = input->keycode;

	input_set_capability(input, EV_MSC, MSC_SCAN);
	if (!plat->no_autorepeat)
		__set_bit(EV_REP, input->evbit);

	input_set_drvdata(input, keypad);

	tc3589x_keypad_disable(keypad);

	error = devm_request_threaded_irq(&pdev->dev, irq,
					  NULL, tc3589x_keypad_irq,
					  plat->irqtype | IRQF_ONESHOT,
					  "tc3589x-keypad", keypad);
	if (error) {
		dev_err(&pdev->dev,
				"Could not allocate irq %d,error %d\n",
				irq, error);
		return error;
	}

	error = input_register_device(input);
	if (error) {
		dev_err(&pdev->dev, "Could not register input device\n");
		return error;
	}

	/* let platform decide if keypad is a wakeup source or not */
	device_init_wakeup(&pdev->dev, plat->enable_wakeup);
	device_set_wakeup_capable(&pdev->dev, plat->enable_wakeup);

	platform_set_drvdata(pdev, keypad);

	return 0;
}

