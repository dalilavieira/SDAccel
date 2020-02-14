#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct stmpe_keypad_variant {int num_data; int num_normal_data; unsigned int col_gpios; unsigned int row_gpios; int max_cols; int max_rows; scalar_t__ set_pullup; scalar_t__ auto_increment; } ;
struct stmpe_keypad {scalar_t__* keymap; int cols; int rows; int debounce_ms; int scan_count; struct stmpe* stmpe; struct input_dev* input; int /*<<< orphan*/  no_autorepeat; struct stmpe_keypad_variant* variant; } ;
struct stmpe {int* regs; size_t partnum; } ;
struct TYPE_10__ {struct device_node* of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct TYPE_9__ {TYPE_3__* parent; } ;
struct TYPE_8__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int /*<<< orphan*/  evbit; TYPE_2__ dev; TYPE_1__ id; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ KEY_RESERVED ; 
 int MATRIX_SCAN_CODE (int,int,int /*<<< orphan*/ ) ; 
 int MAX_NUM_DATA ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int /*<<< orphan*/  STMPE_BLOCK_KEYPAD ; 
 size_t STMPE_IDX_GPPUR_LSB ; 
 int STMPE_KEYPAD_MAX_DEBOUNCE ; 
 int STMPE_KEYPAD_MAX_SCAN_COUNT ; 
 int /*<<< orphan*/  STMPE_KEYPAD_ROW_SHIFT ; 
 int STMPE_KPC_COL ; 
 int /*<<< orphan*/  STMPE_KPC_CTRL_LSB ; 
 int STMPE_KPC_CTRL_LSB_DEBOUNCE ; 
 int STMPE_KPC_CTRL_LSB_SCAN ; 
 int /*<<< orphan*/  STMPE_KPC_CTRL_MSB ; 
 int STMPE_KPC_CTRL_MSB_SCAN_COUNT ; 
 int STMPE_KPC_DATA_BYTE0 ; 
 int STMPE_KPC_DATA_COL ; 
 int STMPE_KPC_DATA_NOKEY_MASK ; 
 int STMPE_KPC_DATA_ROW ; 
 int STMPE_KPC_DATA_UP ; 
 int STMPE_KPC_ROW_LSB ; 
 int /*<<< orphan*/  STMPE_KPC_ROW_MSB ; 
 int STMPE_KPC_ROW_MSB_ROWS ; 
 int __ffs (unsigned int) ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct stmpe* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct input_dev* devm_input_allocate_device (TYPE_3__*) ; 
 struct stmpe_keypad* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_3__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct stmpe_keypad*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,scalar_t__,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,scalar_t__*,struct input_dev*) ; 
 int matrix_keypad_parse_properties (TYPE_3__*,int*,int*) ; 
 int /*<<< orphan*/  of_property_read_bool (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct stmpe_keypad* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stmpe_keypad*) ; 
 int stmpe_block_read (struct stmpe*,int,int,int*) ; 
 int /*<<< orphan*/  stmpe_disable (struct stmpe*,int /*<<< orphan*/ ) ; 
 int stmpe_enable (struct stmpe*,int /*<<< orphan*/ ) ; 
 struct stmpe_keypad_variant* stmpe_keypad_variants ; 
 int stmpe_reg_read (struct stmpe*,int) ; 
 int stmpe_reg_write (struct stmpe*,int,int) ; 
 int stmpe_set_altfunc (struct stmpe*,unsigned int,int /*<<< orphan*/ ) ; 
 int stmpe_set_bits (struct stmpe*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int stmpe_keypad_read_data(struct stmpe_keypad *keypad, u8 *data)
{
	const struct stmpe_keypad_variant *variant = keypad->variant;
	struct stmpe *stmpe = keypad->stmpe;
	int ret;
	int i;

	if (variant->auto_increment)
		return stmpe_block_read(stmpe, STMPE_KPC_DATA_BYTE0,
					variant->num_data, data);

	for (i = 0; i < variant->num_data; i++) {
		ret = stmpe_reg_read(stmpe, STMPE_KPC_DATA_BYTE0 + i);
		if (ret < 0)
			return ret;

		data[i] = ret;
	}

	return 0;
}

__attribute__((used)) static irqreturn_t stmpe_keypad_irq(int irq, void *dev)
{
	struct stmpe_keypad *keypad = dev;
	struct input_dev *input = keypad->input;
	const struct stmpe_keypad_variant *variant = keypad->variant;
	u8 fifo[MAX_NUM_DATA];
	int ret;
	int i;

	ret = stmpe_keypad_read_data(keypad, fifo);
	if (ret < 0)
		return IRQ_NONE;

	for (i = 0; i < variant->num_normal_data; i++) {
		u8 data = fifo[i];
		int row = (data & STMPE_KPC_DATA_ROW) >> 3;
		int col = data & STMPE_KPC_DATA_COL;
		int code = MATRIX_SCAN_CODE(row, col, STMPE_KEYPAD_ROW_SHIFT);
		bool up = data & STMPE_KPC_DATA_UP;

		if ((data & STMPE_KPC_DATA_NOKEY_MASK)
			== STMPE_KPC_DATA_NOKEY_MASK)
			continue;

		input_event(input, EV_MSC, MSC_SCAN, code);
		input_report_key(input, keypad->keymap[code], !up);
		input_sync(input);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int stmpe_keypad_altfunc_init(struct stmpe_keypad *keypad)
{
	const struct stmpe_keypad_variant *variant = keypad->variant;
	unsigned int col_gpios = variant->col_gpios;
	unsigned int row_gpios = variant->row_gpios;
	struct stmpe *stmpe = keypad->stmpe;
	u8 pureg = stmpe->regs[STMPE_IDX_GPPUR_LSB];
	unsigned int pins = 0;
	unsigned int pu_pins = 0;
	int ret;
	int i;

	/*
	 * Figure out which pins need to be set to the keypad alternate
	 * function.
	 *
	 * {cols,rows}_gpios are bitmasks of which pins on the chip can be used
	 * for the keypad.
	 *
	 * keypad->{cols,rows} are a bitmask of which pins (of the ones useable
	 * for the keypad) are used on the board.
	 */

	for (i = 0; i < variant->max_cols; i++) {
		int num = __ffs(col_gpios);

		if (keypad->cols & (1 << i)) {
			pins |= 1 << num;
			pu_pins |= 1 << num;
		}

		col_gpios &= ~(1 << num);
	}

	for (i = 0; i < variant->max_rows; i++) {
		int num = __ffs(row_gpios);

		if (keypad->rows & (1 << i))
			pins |= 1 << num;

		row_gpios &= ~(1 << num);
	}

	ret = stmpe_set_altfunc(stmpe, pins, STMPE_BLOCK_KEYPAD);
	if (ret)
		return ret;

	/*
	 * On STMPE24xx, set pin bias to pull-up on all keypad input
	 * pins (columns), this incidentally happen to be maximum 8 pins
	 * and placed at GPIO0-7 so only the LSB of the pull up register
	 * ever needs to be written.
	 */
	if (variant->set_pullup) {
		u8 val;

		ret = stmpe_reg_read(stmpe, pureg);
		if (ret)
			return ret;

		/* Do not touch unused pins, may be used for GPIO */
		val = ret & ~pu_pins;
		val |= pu_pins;

		ret = stmpe_reg_write(stmpe, pureg, val);
	}

	return 0;
}

__attribute__((used)) static int stmpe_keypad_chip_init(struct stmpe_keypad *keypad)
{
	const struct stmpe_keypad_variant *variant = keypad->variant;
	struct stmpe *stmpe = keypad->stmpe;
	int ret;

	if (keypad->debounce_ms > STMPE_KEYPAD_MAX_DEBOUNCE)
		return -EINVAL;

	if (keypad->scan_count > STMPE_KEYPAD_MAX_SCAN_COUNT)
		return -EINVAL;

	ret = stmpe_enable(stmpe, STMPE_BLOCK_KEYPAD);
	if (ret < 0)
		return ret;

	ret = stmpe_keypad_altfunc_init(keypad);
	if (ret < 0)
		return ret;

	ret = stmpe_reg_write(stmpe, STMPE_KPC_COL, keypad->cols);
	if (ret < 0)
		return ret;

	ret = stmpe_reg_write(stmpe, STMPE_KPC_ROW_LSB, keypad->rows);
	if (ret < 0)
		return ret;

	if (variant->max_rows > 8) {
		ret = stmpe_set_bits(stmpe, STMPE_KPC_ROW_MSB,
				     STMPE_KPC_ROW_MSB_ROWS,
				     keypad->rows >> 8);
		if (ret < 0)
			return ret;
	}

	ret = stmpe_set_bits(stmpe, STMPE_KPC_CTRL_MSB,
			     STMPE_KPC_CTRL_MSB_SCAN_COUNT,
			     keypad->scan_count << 4);
	if (ret < 0)
		return ret;

	return stmpe_set_bits(stmpe, STMPE_KPC_CTRL_LSB,
			      STMPE_KPC_CTRL_LSB_SCAN |
			      STMPE_KPC_CTRL_LSB_DEBOUNCE,
			      STMPE_KPC_CTRL_LSB_SCAN |
			      (keypad->debounce_ms << 1));
}

__attribute__((used)) static void stmpe_keypad_fill_used_pins(struct stmpe_keypad *keypad,
					u32 used_rows, u32 used_cols)
{
	int row, col;

	for (row = 0; row < used_rows; row++) {
		for (col = 0; col < used_cols; col++) {
			int code = MATRIX_SCAN_CODE(row, col,
						    STMPE_KEYPAD_ROW_SHIFT);
			if (keypad->keymap[code] != KEY_RESERVED) {
				keypad->rows |= 1 << row;
				keypad->cols |= 1 << col;
			}
		}
	}
}

__attribute__((used)) static int stmpe_keypad_probe(struct platform_device *pdev)
{
	struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
	struct device_node *np = pdev->dev.of_node;
	struct stmpe_keypad *keypad;
	struct input_dev *input;
	u32 rows;
	u32 cols;
	int error;
	int irq;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	keypad = devm_kzalloc(&pdev->dev, sizeof(struct stmpe_keypad),
			      GFP_KERNEL);
	if (!keypad)
		return -ENOMEM;

	keypad->stmpe = stmpe;
	keypad->variant = &stmpe_keypad_variants[stmpe->partnum];

	of_property_read_u32(np, "debounce-interval", &keypad->debounce_ms);
	of_property_read_u32(np, "st,scan-count", &keypad->scan_count);
	keypad->no_autorepeat = of_property_read_bool(np, "st,no-autorepeat");

	input = devm_input_allocate_device(&pdev->dev);
	if (!input)
		return -ENOMEM;

	input->name = "STMPE keypad";
	input->id.bustype = BUS_I2C;
	input->dev.parent = &pdev->dev;

	error = matrix_keypad_parse_properties(&pdev->dev, &rows, &cols);
	if (error)
		return error;

	error = matrix_keypad_build_keymap(NULL, NULL, rows, cols,
					   keypad->keymap, input);
	if (error)
		return error;

	input_set_capability(input, EV_MSC, MSC_SCAN);
	if (!keypad->no_autorepeat)
		__set_bit(EV_REP, input->evbit);

	stmpe_keypad_fill_used_pins(keypad, rows, cols);

	keypad->input = input;

	error = stmpe_keypad_chip_init(keypad);
	if (error < 0)
		return error;

	error = devm_request_threaded_irq(&pdev->dev, irq,
					  NULL, stmpe_keypad_irq,
					  IRQF_ONESHOT, "stmpe-keypad", keypad);
	if (error) {
		dev_err(&pdev->dev, "unable to get irq: %d\n", error);
		return error;
	}

	error = input_register_device(input);
	if (error) {
		dev_err(&pdev->dev,
			"unable to register input device: %d\n", error);
		return error;
	}

	platform_set_drvdata(pdev, keypad);

	return 0;
}

__attribute__((used)) static int stmpe_keypad_remove(struct platform_device *pdev)
{
	struct stmpe_keypad *keypad = platform_get_drvdata(pdev);

	stmpe_disable(keypad->stmpe, STMPE_BLOCK_KEYPAD);

	return 0;
}

