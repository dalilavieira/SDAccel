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
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct twl4030_keypad_data {int rows; int cols; int rep; struct matrix_keymap_data* keymap_data; } ;
struct twl4030_keypad {int n_cols; int n_rows; int* kp_state; int autorepeat; int /*<<< orphan*/  irq; int /*<<< orphan*/ * dbg_dev; int /*<<< orphan*/ * keymap; struct input_dev* input; } ;
struct platform_device {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; } ;
struct matrix_keymap_data {int dummy; } ;
struct TYPE_2__ {int vendor; int product; int version; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; char* phys; int /*<<< orphan*/  evbit; TYPE_1__ id; } ;
typedef  int /*<<< orphan*/  new_state ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEYP_CTRL ; 
 int KEYP_CTRL_KBD_ON ; 
 int KEYP_CTRL_SOFTMODEN ; 
 int KEYP_CTRL_SOFT_NRST ; 
 int KEYP_CTRL_TOE_EN ; 
 int /*<<< orphan*/  KEYP_DEB ; 
 int /*<<< orphan*/  KEYP_EDR ; 
 int KEYP_EDR_KP_BOTH ; 
 int KEYP_EDR_TO_RISING ; 
 int /*<<< orphan*/  KEYP_FULL_CODE_7_0 ; 
 int /*<<< orphan*/  KEYP_IMR1 ; 
 int KEYP_IMR1_KP ; 
 int KEYP_IMR1_TO ; 
 int /*<<< orphan*/  KEYP_ISR1 ; 
 int /*<<< orphan*/  KEYP_LK_PTV ; 
 int KEYP_LK_PTV_PTV_SHIFT ; 
 int KEYP_PERIOD_US (int,int) ; 
 int /*<<< orphan*/  KEYP_SIH_CTRL ; 
 int /*<<< orphan*/  KEYP_TIMEOUT_H ; 
 int /*<<< orphan*/  KEYP_TIMEOUT_L ; 
 int MATRIX_SCAN_CODE (int,int,int) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int PTV_PRESCALER ; 
 scalar_t__ TWL4030_MAX_COLS ; 
 int TWL4030_MAX_ROWS ; 
 int /*<<< orphan*/  TWL4030_MODULE_KEYPAD ; 
 int TWL4030_ROW_SHIFT ; 
 int TWL4030_SIH_CTRL_COR_MASK ; 
 int TWL4030_SIH_CTRL_PENDDIS_MASK ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct twl4030_keypad_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int,int) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 struct twl4030_keypad* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct twl4030_keypad*) ; 
 int hweight16 (int) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int matrix_keypad_build_keymap (struct matrix_keymap_data const*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,struct input_dev*) ; 
 int matrix_keypad_parse_properties (int /*<<< orphan*/ *,int*,int*) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int twl_i2c_read (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int) ; 
 int twl_i2c_write_u8 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int twl4030_kpread(struct twl4030_keypad *kp,
		u8 *data, u32 reg, u8 num_bytes)
{
	int ret = twl_i2c_read(TWL4030_MODULE_KEYPAD, data, reg, num_bytes);

	if (ret < 0)
		dev_warn(kp->dbg_dev,
			"Couldn't read TWL4030: %X - ret %d[%x]\n",
			 reg, ret, ret);

	return ret;
}

__attribute__((used)) static int twl4030_kpwrite_u8(struct twl4030_keypad *kp, u8 data, u32 reg)
{
	int ret = twl_i2c_write_u8(TWL4030_MODULE_KEYPAD, data, reg);

	if (ret < 0)
		dev_warn(kp->dbg_dev,
			"Could not write TWL4030: %X - ret %d[%x]\n",
			 reg, ret, ret);

	return ret;
}

__attribute__((used)) static inline u16 twl4030_col_xlate(struct twl4030_keypad *kp, u8 col)
{
	/*
	 * If all bits in a row are active for all columns then
	 * we have that row line connected to gnd. Mark this
	 * key on as if it was on matrix position n_cols (i.e.
	 * one higher than the size of the matrix).
	 */
	if (col == 0xFF)
		return 1 << kp->n_cols;
	else
		return col & ((1 << kp->n_cols) - 1);
}

__attribute__((used)) static int twl4030_read_kp_matrix_state(struct twl4030_keypad *kp, u16 *state)
{
	u8 new_state[TWL4030_MAX_ROWS];
	int row;
	int ret = twl4030_kpread(kp, new_state,
				 KEYP_FULL_CODE_7_0, kp->n_rows);
	if (ret >= 0)
		for (row = 0; row < kp->n_rows; row++)
			state[row] = twl4030_col_xlate(kp, new_state[row]);

	return ret;
}

__attribute__((used)) static bool twl4030_is_in_ghost_state(struct twl4030_keypad *kp, u16 *key_state)
{
	int i;
	u16 check = 0;

	for (i = 0; i < kp->n_rows; i++) {
		u16 col = key_state[i];

		if ((col & check) && hweight16(col) > 1)
			return true;

		check |= col;
	}

	return false;
}

__attribute__((used)) static void twl4030_kp_scan(struct twl4030_keypad *kp, bool release_all)
{
	struct input_dev *input = kp->input;
	u16 new_state[TWL4030_MAX_ROWS];
	int col, row;

	if (release_all) {
		memset(new_state, 0, sizeof(new_state));
	} else {
		/* check for any changes */
		int ret = twl4030_read_kp_matrix_state(kp, new_state);

		if (ret < 0)	/* panic ... */
			return;

		if (twl4030_is_in_ghost_state(kp, new_state))
			return;
	}

	/* check for changes and print those */
	for (row = 0; row < kp->n_rows; row++) {
		int changed = new_state[row] ^ kp->kp_state[row];

		if (!changed)
			continue;

		/* Extra column handles "all gnd" rows */
		for (col = 0; col < kp->n_cols + 1; col++) {
			int code;

			if (!(changed & (1 << col)))
				continue;

			dev_dbg(kp->dbg_dev, "key [%d:%d] %s\n", row, col,
				(new_state[row] & (1 << col)) ?
				"press" : "release");

			code = MATRIX_SCAN_CODE(row, col, TWL4030_ROW_SHIFT);
			input_event(input, EV_MSC, MSC_SCAN, code);
			input_report_key(input, kp->keymap[code],
					 new_state[row] & (1 << col));
		}
		kp->kp_state[row] = new_state[row];
	}
	input_sync(input);
}

__attribute__((used)) static irqreturn_t do_kp_irq(int irq, void *_kp)
{
	struct twl4030_keypad *kp = _kp;
	u8 reg;
	int ret;

	/* Read & Clear TWL4030 pending interrupt */
	ret = twl4030_kpread(kp, &reg, KEYP_ISR1, 1);

	/*
	 * Release all keys if I2C has gone bad or
	 * the KEYP has gone to idle state.
	 */
	if (ret >= 0 && (reg & KEYP_IMR1_KP))
		twl4030_kp_scan(kp, false);
	else
		twl4030_kp_scan(kp, true);

	return IRQ_HANDLED;
}

__attribute__((used)) static int twl4030_kp_program(struct twl4030_keypad *kp)
{
	u8 reg;
	int i;

	/* Enable controller, with hardware decoding but not autorepeat */
	reg = KEYP_CTRL_SOFT_NRST | KEYP_CTRL_SOFTMODEN
		| KEYP_CTRL_TOE_EN | KEYP_CTRL_KBD_ON;
	if (twl4030_kpwrite_u8(kp, reg, KEYP_CTRL) < 0)
		return -EIO;

	/*
	 * NOTE: we could use sih_setup() here to package keypad
	 * event sources as four different IRQs ... but we don't.
	 */

	/* Enable TO rising and KP rising and falling edge detection */
	reg = KEYP_EDR_KP_BOTH | KEYP_EDR_TO_RISING;
	if (twl4030_kpwrite_u8(kp, reg, KEYP_EDR) < 0)
		return -EIO;

	/* Set PTV prescaler Field */
	reg = (PTV_PRESCALER << KEYP_LK_PTV_PTV_SHIFT);
	if (twl4030_kpwrite_u8(kp, reg, KEYP_LK_PTV) < 0)
		return -EIO;

	/* Set key debounce time to 20 ms */
	i = KEYP_PERIOD_US(20000, PTV_PRESCALER);
	if (twl4030_kpwrite_u8(kp, i, KEYP_DEB) < 0)
		return -EIO;

	/* Set timeout period to 200 ms */
	i = KEYP_PERIOD_US(200000, PTV_PRESCALER);
	if (twl4030_kpwrite_u8(kp, (i & 0xFF), KEYP_TIMEOUT_L) < 0)
		return -EIO;

	if (twl4030_kpwrite_u8(kp, (i >> 8), KEYP_TIMEOUT_H) < 0)
		return -EIO;

	/*
	 * Enable Clear-on-Read; disable remembering events that fire
	 * after the IRQ but before our handler acks (reads) them.
	 */
	reg = TWL4030_SIH_CTRL_COR_MASK | TWL4030_SIH_CTRL_PENDDIS_MASK;
	if (twl4030_kpwrite_u8(kp, reg, KEYP_SIH_CTRL) < 0)
		return -EIO;

	/* initialize key state; irqs update it from here on */
	if (twl4030_read_kp_matrix_state(kp, kp->kp_state) < 0)
		return -EIO;

	return 0;
}

__attribute__((used)) static int twl4030_kp_probe(struct platform_device *pdev)
{
	struct twl4030_keypad_data *pdata = dev_get_platdata(&pdev->dev);
	const struct matrix_keymap_data *keymap_data = NULL;
	struct twl4030_keypad *kp;
	struct input_dev *input;
	u8 reg;
	int error;

	kp = devm_kzalloc(&pdev->dev, sizeof(*kp), GFP_KERNEL);
	if (!kp)
		return -ENOMEM;

	input = devm_input_allocate_device(&pdev->dev);
	if (!input)
		return -ENOMEM;

	/* get the debug device */
	kp->dbg_dev		= &pdev->dev;
	kp->input		= input;

	/* setup input device */
	input->name		= "TWL4030 Keypad";
	input->phys		= "twl4030_keypad/input0";

	input->id.bustype	= BUS_HOST;
	input->id.vendor	= 0x0001;
	input->id.product	= 0x0001;
	input->id.version	= 0x0003;

	if (pdata) {
		if (!pdata->rows || !pdata->cols || !pdata->keymap_data) {
			dev_err(&pdev->dev, "Missing platform_data\n");
			return -EINVAL;
		}

		kp->n_rows = pdata->rows;
		kp->n_cols = pdata->cols;
		kp->autorepeat = pdata->rep;
		keymap_data = pdata->keymap_data;
	} else {
		error = matrix_keypad_parse_properties(&pdev->dev, &kp->n_rows,
						       &kp->n_cols);
		if (error)
			return error;

		kp->autorepeat = true;
	}

	if (kp->n_rows > TWL4030_MAX_ROWS || kp->n_cols > TWL4030_MAX_COLS) {
		dev_err(&pdev->dev,
			"Invalid rows/cols amount specified in platform/devicetree data\n");
		return -EINVAL;
	}

	kp->irq = platform_get_irq(pdev, 0);
	if (!kp->irq) {
		dev_err(&pdev->dev, "no keyboard irq assigned\n");
		return -EINVAL;
	}

	error = matrix_keypad_build_keymap(keymap_data, NULL,
					   TWL4030_MAX_ROWS,
					   1 << TWL4030_ROW_SHIFT,
					   kp->keymap, input);
	if (error) {
		dev_err(kp->dbg_dev, "Failed to build keymap\n");
		return error;
	}

	input_set_capability(input, EV_MSC, MSC_SCAN);
	/* Enable auto repeat feature of Linux input subsystem */
	if (kp->autorepeat)
		__set_bit(EV_REP, input->evbit);

	error = input_register_device(input);
	if (error) {
		dev_err(kp->dbg_dev,
			"Unable to register twl4030 keypad device\n");
		return error;
	}

	error = twl4030_kp_program(kp);
	if (error)
		return error;

	/*
	 * This ISR will always execute in kernel thread context because of
	 * the need to access the TWL4030 over the I2C bus.
	 *
	 * NOTE:  we assume this host is wired to TWL4040 INT1, not INT2 ...
	 */
	error = devm_request_threaded_irq(&pdev->dev, kp->irq, NULL, do_kp_irq,
					  0, pdev->name, kp);
	if (error) {
		dev_info(kp->dbg_dev, "request_irq failed for irq no=%d: %d\n",
			kp->irq, error);
		return error;
	}

	/* Enable KP and TO interrupts now. */
	reg = (u8) ~(KEYP_IMR1_KP | KEYP_IMR1_TO);
	if (twl4030_kpwrite_u8(kp, reg, KEYP_IMR1)) {
		/* mask all events - we don't care about the result */
		(void) twl4030_kpwrite_u8(kp, 0xff, KEYP_IMR1);
		return -EIO;
	}

	return 0;
}

