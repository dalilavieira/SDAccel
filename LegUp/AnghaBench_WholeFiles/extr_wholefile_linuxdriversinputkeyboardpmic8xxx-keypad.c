#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct pmic8xxx_kp {int num_cols; int num_rows; int* keystate; int* stuckstate; int ctrl_reg; scalar_t__ key_sense_irq; scalar_t__ key_stuck_irq; TYPE_3__* input; int /*<<< orphan*/  regmap; int /*<<< orphan*/ * keycodes; TYPE_2__* dev; } ;
struct TYPE_18__ {int /*<<< orphan*/  parent; struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct input_dev {int dummy; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  new_state ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_17__ {int version; int product; int vendor; int /*<<< orphan*/  bustype; } ;
struct TYPE_19__ {char* name; char* phys; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 int DIV_ROUND_UP (int /*<<< orphan*/ ,unsigned int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int KEYP_CLOCK_FREQ ; 
 int KEYP_CTRL ; 
 unsigned int KEYP_CTRL_EVNTS_MASK ; 
 int KEYP_CTRL_KEYP_EN ; 
 int KEYP_CTRL_SCAN_COLS_BITS ; 
 scalar_t__ KEYP_CTRL_SCAN_COLS_MIN ; 
 int KEYP_CTRL_SCAN_COLS_SHIFT ; 
 scalar_t__ KEYP_CTRL_SCAN_ROWS_MIN ; 
 int KEYP_CTRL_SCAN_ROWS_SHIFT ; 
 int KEYP_OLD_DATA ; 
 int KEYP_RECENT_DATA ; 
 int KEYP_SCAN ; 
 int KEYP_SCAN_DBOUNCE_SHIFT ; 
 int KEYP_SCAN_PAUSE_SHIFT ; 
 int KEYP_SCAN_ROW_HOLD_SHIFT ; 
 int MATRIX_SCAN_CODE (int,int,int /*<<< orphan*/ ) ; 
 unsigned int MAX_DEBOUNCE_TIME ; 
 unsigned int MAX_ROW_HOLD_DELAY ; 
 unsigned int MAX_SCAN_DELAY ; 
 unsigned int MIN_DEBOUNCE_TIME ; 
 unsigned int MIN_ROW_HOLD_DELAY ; 
 unsigned int MIN_SCAN_DELAY ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 unsigned int NSEC_PER_SEC ; 
 unsigned int PM8XXX_MAX_COLS ; 
 int PM8XXX_MAX_ROWS ; 
 unsigned int PM8XXX_MIN_COLS ; 
 int PM8XXX_MIN_ROWS ; 
 int /*<<< orphan*/  PM8XXX_ROW_SHIFT ; 
 int /*<<< orphan*/  USEC_PER_SEC ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_2__*,int) ; 
 TYPE_3__* devm_input_allocate_device (TYPE_2__*) ; 
 struct pmic8xxx_kp* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_any_context_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct pmic8xxx_kp*) ; 
 int fls (unsigned int) ; 
 int hweight16 (int) ; 
 int /*<<< orphan*/  input_event (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct pmic8xxx_kp* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (TYPE_3__*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (TYPE_3__*,struct pmic8xxx_kp*) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  is_power_of_2 (unsigned int) ; 
 int matrix_keypad_build_keymap (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,unsigned int,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int matrix_keypad_parse_properties (TYPE_2__*,unsigned int*,unsigned int*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 scalar_t__ of_property_read_u32 (struct device_node const*,char*,unsigned int*) ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pmic8xxx_kp*) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static u8 pmic8xxx_col_state(struct pmic8xxx_kp *kp, u8 col)
{
	/* all keys pressed on that particular row? */
	if (col == 0x00)
		return 1 << kp->num_cols;
	else
		return col & ((1 << kp->num_cols) - 1);
}

__attribute__((used)) static int pmic8xxx_chk_sync_read(struct pmic8xxx_kp *kp)
{
	int rc;
	unsigned int scan_val;

	rc = regmap_read(kp->regmap, KEYP_SCAN, &scan_val);
	if (rc < 0) {
		dev_err(kp->dev, "Error reading KEYP_SCAN reg, rc=%d\n", rc);
		return rc;
	}

	scan_val |= 0x1;

	rc = regmap_write(kp->regmap, KEYP_SCAN, scan_val);
	if (rc < 0) {
		dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);
		return rc;
	}

	/* 2 * 32KHz clocks */
	udelay((2 * DIV_ROUND_UP(USEC_PER_SEC, KEYP_CLOCK_FREQ)) + 1);

	return rc;
}

__attribute__((used)) static int pmic8xxx_kp_read_data(struct pmic8xxx_kp *kp, u16 *state,
					u16 data_reg, int read_rows)
{
	int rc, row;
	unsigned int val;

	for (row = 0; row < read_rows; row++) {
		rc = regmap_read(kp->regmap, data_reg, &val);
		if (rc)
			return rc;
		dev_dbg(kp->dev, "%d = %d\n", row, val);
		state[row] = pmic8xxx_col_state(kp, val);
	}

	return 0;
}

__attribute__((used)) static int pmic8xxx_kp_read_matrix(struct pmic8xxx_kp *kp, u16 *new_state,
					 u16 *old_state)
{
	int rc, read_rows;
	unsigned int scan_val;

	if (kp->num_rows < PM8XXX_MIN_ROWS)
		read_rows = PM8XXX_MIN_ROWS;
	else
		read_rows = kp->num_rows;

	pmic8xxx_chk_sync_read(kp);

	if (old_state) {
		rc = pmic8xxx_kp_read_data(kp, old_state, KEYP_OLD_DATA,
						read_rows);
		if (rc < 0) {
			dev_err(kp->dev,
				"Error reading KEYP_OLD_DATA, rc=%d\n", rc);
			return rc;
		}
	}

	rc = pmic8xxx_kp_read_data(kp, new_state, KEYP_RECENT_DATA,
					 read_rows);
	if (rc < 0) {
		dev_err(kp->dev,
			"Error reading KEYP_RECENT_DATA, rc=%d\n", rc);
		return rc;
	}

	/* 4 * 32KHz clocks */
	udelay((4 * DIV_ROUND_UP(USEC_PER_SEC, KEYP_CLOCK_FREQ)) + 1);

	rc = regmap_read(kp->regmap, KEYP_SCAN, &scan_val);
	if (rc < 0) {
		dev_err(kp->dev, "Error reading KEYP_SCAN reg, rc=%d\n", rc);
		return rc;
	}

	scan_val &= 0xFE;
	rc = regmap_write(kp->regmap, KEYP_SCAN, scan_val);
	if (rc < 0)
		dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static void __pmic8xxx_kp_scan_matrix(struct pmic8xxx_kp *kp, u16 *new_state,
					 u16 *old_state)
{
	int row, col, code;

	for (row = 0; row < kp->num_rows; row++) {
		int bits_changed = new_state[row] ^ old_state[row];

		if (!bits_changed)
			continue;

		for (col = 0; col < kp->num_cols; col++) {
			if (!(bits_changed & (1 << col)))
				continue;

			dev_dbg(kp->dev, "key [%d:%d] %s\n", row, col,
					!(new_state[row] & (1 << col)) ?
					"pressed" : "released");

			code = MATRIX_SCAN_CODE(row, col, PM8XXX_ROW_SHIFT);

			input_event(kp->input, EV_MSC, MSC_SCAN, code);
			input_report_key(kp->input,
					kp->keycodes[code],
					!(new_state[row] & (1 << col)));

			input_sync(kp->input);
		}
	}
}

__attribute__((used)) static bool pmic8xxx_detect_ghost_keys(struct pmic8xxx_kp *kp, u16 *new_state)
{
	int row, found_first = -1;
	u16 check, row_state;

	check = 0;
	for (row = 0; row < kp->num_rows; row++) {
		row_state = (~new_state[row]) &
				 ((1 << kp->num_cols) - 1);

		if (hweight16(row_state) > 1) {
			if (found_first == -1)
				found_first = row;
			if (check & row_state) {
				dev_dbg(kp->dev, "detected ghost key on row[%d]"
					 " and row[%d]\n", found_first, row);
				return true;
			}
		}
		check |= row_state;
	}
	return false;
}

__attribute__((used)) static int pmic8xxx_kp_scan_matrix(struct pmic8xxx_kp *kp, unsigned int events)
{
	u16 new_state[PM8XXX_MAX_ROWS];
	u16 old_state[PM8XXX_MAX_ROWS];
	int rc;

	switch (events) {
	case 0x1:
		rc = pmic8xxx_kp_read_matrix(kp, new_state, NULL);
		if (rc < 0)
			return rc;

		/* detecting ghost key is not an error */
		if (pmic8xxx_detect_ghost_keys(kp, new_state))
			return 0;
		__pmic8xxx_kp_scan_matrix(kp, new_state, kp->keystate);
		memcpy(kp->keystate, new_state, sizeof(new_state));
	break;
	case 0x3: /* two events - eventcounter is gray-coded */
		rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
		if (rc < 0)
			return rc;

		__pmic8xxx_kp_scan_matrix(kp, old_state, kp->keystate);
		__pmic8xxx_kp_scan_matrix(kp, new_state, old_state);
		memcpy(kp->keystate, new_state, sizeof(new_state));
	break;
	case 0x2:
		dev_dbg(kp->dev, "Some key events were lost\n");
		rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
		if (rc < 0)
			return rc;
		__pmic8xxx_kp_scan_matrix(kp, old_state, kp->keystate);
		__pmic8xxx_kp_scan_matrix(kp, new_state, old_state);
		memcpy(kp->keystate, new_state, sizeof(new_state));
	break;
	default:
		rc = -EINVAL;
	}
	return rc;
}

__attribute__((used)) static irqreturn_t pmic8xxx_kp_stuck_irq(int irq, void *data)
{
	u16 new_state[PM8XXX_MAX_ROWS];
	u16 old_state[PM8XXX_MAX_ROWS];
	int rc;
	struct pmic8xxx_kp *kp = data;

	rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
	if (rc < 0) {
		dev_err(kp->dev, "failed to read keypad matrix\n");
		return IRQ_HANDLED;
	}

	__pmic8xxx_kp_scan_matrix(kp, new_state, kp->stuckstate);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t pmic8xxx_kp_irq(int irq, void *data)
{
	struct pmic8xxx_kp *kp = data;
	unsigned int ctrl_val, events;
	int rc;

	rc = regmap_read(kp->regmap, KEYP_CTRL, &ctrl_val);
	if (rc < 0) {
		dev_err(kp->dev, "failed to read keyp_ctrl register\n");
		return IRQ_HANDLED;
	}

	events = ctrl_val & KEYP_CTRL_EVNTS_MASK;

	rc = pmic8xxx_kp_scan_matrix(kp, events);
	if (rc < 0)
		dev_err(kp->dev, "failed to scan matrix\n");

	return IRQ_HANDLED;
}

__attribute__((used)) static int pmic8xxx_kpd_init(struct pmic8xxx_kp *kp,
			     struct platform_device *pdev)
{
	const struct device_node *of_node = pdev->dev.of_node;
	unsigned int scan_delay_ms;
	unsigned int row_hold_ns;
	unsigned int debounce_ms;
	int bits, rc, cycles;
	u8 scan_val = 0, ctrl_val = 0;
	static const u8 row_bits[] = {
		0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7,
	};

	/* Find column bits */
	if (kp->num_cols < KEYP_CTRL_SCAN_COLS_MIN)
		bits = 0;
	else
		bits = kp->num_cols - KEYP_CTRL_SCAN_COLS_MIN;
	ctrl_val = (bits & KEYP_CTRL_SCAN_COLS_BITS) <<
		KEYP_CTRL_SCAN_COLS_SHIFT;

	/* Find row bits */
	if (kp->num_rows < KEYP_CTRL_SCAN_ROWS_MIN)
		bits = 0;
	else
		bits = row_bits[kp->num_rows - KEYP_CTRL_SCAN_ROWS_MIN];

	ctrl_val |= (bits << KEYP_CTRL_SCAN_ROWS_SHIFT);

	rc = regmap_write(kp->regmap, KEYP_CTRL, ctrl_val);
	if (rc < 0) {
		dev_err(kp->dev, "Error writing KEYP_CTRL reg, rc=%d\n", rc);
		return rc;
	}

	if (of_property_read_u32(of_node, "scan-delay", &scan_delay_ms))
		scan_delay_ms = MIN_SCAN_DELAY;

	if (scan_delay_ms > MAX_SCAN_DELAY || scan_delay_ms < MIN_SCAN_DELAY ||
	    !is_power_of_2(scan_delay_ms)) {
		dev_err(&pdev->dev, "invalid keypad scan time supplied\n");
		return -EINVAL;
	}

	if (of_property_read_u32(of_node, "row-hold", &row_hold_ns))
		row_hold_ns = MIN_ROW_HOLD_DELAY;

	if (row_hold_ns > MAX_ROW_HOLD_DELAY ||
	    row_hold_ns < MIN_ROW_HOLD_DELAY ||
	    ((row_hold_ns % MIN_ROW_HOLD_DELAY) != 0)) {
		dev_err(&pdev->dev, "invalid keypad row hold time supplied\n");
		return -EINVAL;
	}

	if (of_property_read_u32(of_node, "debounce", &debounce_ms))
		debounce_ms = MIN_DEBOUNCE_TIME;

	if (((debounce_ms % 5) != 0) ||
	    debounce_ms > MAX_DEBOUNCE_TIME ||
	    debounce_ms < MIN_DEBOUNCE_TIME) {
		dev_err(&pdev->dev, "invalid debounce time supplied\n");
		return -EINVAL;
	}

	bits = (debounce_ms / 5) - 1;

	scan_val |= (bits << KEYP_SCAN_DBOUNCE_SHIFT);

	bits = fls(scan_delay_ms) - 1;
	scan_val |= (bits << KEYP_SCAN_PAUSE_SHIFT);

	/* Row hold time is a multiple of 32KHz cycles. */
	cycles = (row_hold_ns * KEYP_CLOCK_FREQ) / NSEC_PER_SEC;

	scan_val |= (cycles << KEYP_SCAN_ROW_HOLD_SHIFT);

	rc = regmap_write(kp->regmap, KEYP_SCAN, scan_val);
	if (rc)
		dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);

	return rc;

}

__attribute__((used)) static int pmic8xxx_kp_enable(struct pmic8xxx_kp *kp)
{
	int rc;

	kp->ctrl_reg |= KEYP_CTRL_KEYP_EN;

	rc = regmap_write(kp->regmap, KEYP_CTRL, kp->ctrl_reg);
	if (rc < 0)
		dev_err(kp->dev, "Error writing KEYP_CTRL reg, rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int pmic8xxx_kp_disable(struct pmic8xxx_kp *kp)
{
	int rc;

	kp->ctrl_reg &= ~KEYP_CTRL_KEYP_EN;

	rc = regmap_write(kp->regmap, KEYP_CTRL, kp->ctrl_reg);
	if (rc < 0)
		return rc;

	return rc;
}

__attribute__((used)) static int pmic8xxx_kp_open(struct input_dev *dev)
{
	struct pmic8xxx_kp *kp = input_get_drvdata(dev);

	return pmic8xxx_kp_enable(kp);
}

__attribute__((used)) static void pmic8xxx_kp_close(struct input_dev *dev)
{
	struct pmic8xxx_kp *kp = input_get_drvdata(dev);

	pmic8xxx_kp_disable(kp);
}

__attribute__((used)) static int pmic8xxx_kp_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	unsigned int rows, cols;
	bool repeat;
	bool wakeup;
	struct pmic8xxx_kp *kp;
	int rc;
	unsigned int ctrl_val;

	rc = matrix_keypad_parse_properties(&pdev->dev, &rows, &cols);
	if (rc)
		return rc;

	if (cols > PM8XXX_MAX_COLS || rows > PM8XXX_MAX_ROWS ||
	    cols < PM8XXX_MIN_COLS) {
		dev_err(&pdev->dev, "invalid platform data\n");
		return -EINVAL;
	}

	repeat = !of_property_read_bool(np, "linux,input-no-autorepeat");

	wakeup = of_property_read_bool(np, "wakeup-source") ||
		 /* legacy name */
		 of_property_read_bool(np, "linux,keypad-wakeup");

	kp = devm_kzalloc(&pdev->dev, sizeof(*kp), GFP_KERNEL);
	if (!kp)
		return -ENOMEM;

	kp->regmap = dev_get_regmap(pdev->dev.parent, NULL);
	if (!kp->regmap)
		return -ENODEV;

	platform_set_drvdata(pdev, kp);

	kp->num_rows	= rows;
	kp->num_cols	= cols;
	kp->dev		= &pdev->dev;

	kp->input = devm_input_allocate_device(&pdev->dev);
	if (!kp->input) {
		dev_err(&pdev->dev, "unable to allocate input device\n");
		return -ENOMEM;
	}

	kp->key_sense_irq = platform_get_irq(pdev, 0);
	if (kp->key_sense_irq < 0) {
		dev_err(&pdev->dev, "unable to get keypad sense irq\n");
		return kp->key_sense_irq;
	}

	kp->key_stuck_irq = platform_get_irq(pdev, 1);
	if (kp->key_stuck_irq < 0) {
		dev_err(&pdev->dev, "unable to get keypad stuck irq\n");
		return kp->key_stuck_irq;
	}

	kp->input->name = "PMIC8XXX keypad";
	kp->input->phys = "pmic8xxx_keypad/input0";

	kp->input->id.bustype	= BUS_I2C;
	kp->input->id.version	= 0x0001;
	kp->input->id.product	= 0x0001;
	kp->input->id.vendor	= 0x0001;

	kp->input->open		= pmic8xxx_kp_open;
	kp->input->close	= pmic8xxx_kp_close;

	rc = matrix_keypad_build_keymap(NULL, NULL,
					PM8XXX_MAX_ROWS, PM8XXX_MAX_COLS,
					kp->keycodes, kp->input);
	if (rc) {
		dev_err(&pdev->dev, "failed to build keymap\n");
		return rc;
	}

	if (repeat)
		__set_bit(EV_REP, kp->input->evbit);
	input_set_capability(kp->input, EV_MSC, MSC_SCAN);

	input_set_drvdata(kp->input, kp);

	/* initialize keypad state */
	memset(kp->keystate, 0xff, sizeof(kp->keystate));
	memset(kp->stuckstate, 0xff, sizeof(kp->stuckstate));

	rc = pmic8xxx_kpd_init(kp, pdev);
	if (rc < 0) {
		dev_err(&pdev->dev, "unable to initialize keypad controller\n");
		return rc;
	}

	rc = devm_request_any_context_irq(&pdev->dev, kp->key_sense_irq,
			pmic8xxx_kp_irq, IRQF_TRIGGER_RISING, "pmic-keypad",
			kp);
	if (rc < 0) {
		dev_err(&pdev->dev, "failed to request keypad sense irq\n");
		return rc;
	}

	rc = devm_request_any_context_irq(&pdev->dev, kp->key_stuck_irq,
			pmic8xxx_kp_stuck_irq, IRQF_TRIGGER_RISING,
			"pmic-keypad-stuck", kp);
	if (rc < 0) {
		dev_err(&pdev->dev, "failed to request keypad stuck irq\n");
		return rc;
	}

	rc = regmap_read(kp->regmap, KEYP_CTRL, &ctrl_val);
	if (rc < 0) {
		dev_err(&pdev->dev, "failed to read KEYP_CTRL register\n");
		return rc;
	}

	kp->ctrl_reg = ctrl_val;

	rc = input_register_device(kp->input);
	if (rc < 0) {
		dev_err(&pdev->dev, "unable to register keypad input device\n");
		return rc;
	}

	device_init_wakeup(&pdev->dev, wakeup);

	return 0;
}

