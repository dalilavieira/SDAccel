#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct timer_list {int dummy; } ;
struct tegra_kbc_pin_cfg {int type; int num; } ;
struct tegra_kbc {int mmio; unsigned short* keycode; int use_ghost_filter; int max_keys; unsigned short* current_keys; unsigned int num_pressed_keys; int repoll_dly; int keypress_caused_wake; int wakeup; int clk; int rst; int repeat_cnt; int debounce_cnt; scalar_t__ irq; int num_rows_and_columns; struct input_dev* idev; TYPE_3__* hw_support; scalar_t__ keymap_data; scalar_t__ use_fn_map; int /*<<< orphan*/  timer; int /*<<< orphan*/  lock; TYPE_4__* dev; struct tegra_kbc_pin_cfg* pin_cfg; scalar_t__ cp_dly_jiffies; } ;
struct resource {int dummy; } ;
struct TYPE_16__ {struct device_node* of_node; } ;
struct platform_device {TYPE_4__ dev; int /*<<< orphan*/  name; } ;
struct of_device_id {TYPE_3__* data; } ;
struct TYPE_14__ {TYPE_4__* parent; } ;
struct TYPE_13__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_15__ {int max_rows; int max_columns; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int DIV_ROUND_UP (int,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int) ; 
 int KBC_COL_CFG0_0 ; 
 int KBC_CONTROL_0 ; 
 int KBC_CONTROL_FIFO_CNT_INT_EN ; 
 int KBC_CONTROL_KBC_EN ; 
 int /*<<< orphan*/  KBC_CYCLE_MS ; 
 int KBC_DEBOUNCE_CNT_SHIFT (unsigned int) ; 
 int KBC_FIFO_TH_CNT_SHIFT (int) ; 
 int KBC_INIT_DLY_0 ; 
 int KBC_INT_0 ; 
 int KBC_INT_FIFO_CNT_INT_STATUS ; 
 int KBC_INT_KEYPRESS_INT_STATUS ; 
 int KBC_KP_ENT0_0 ; 
 int KBC_KP_ENT1_0 ; 
 int /*<<< orphan*/  KBC_MAX_DEBOUNCE_CNT ; 
 int KBC_MAX_GPIO ; 
 int KBC_MAX_KPENT ; 
 int KBC_ROW0_MASK_0 ; 
 int KBC_ROW_CFG0_0 ; 
 int KBC_ROW_SCAN_DLY ; 
 unsigned int KBC_ROW_SCAN_TIME ; 
 unsigned char KBC_ROW_SHIFT ; 
 int KBC_RPT_DLY_0 ; 
 unsigned short KEY_FN ; 
 unsigned char MATRIX_SCAN_CODE (unsigned int,unsigned int,unsigned char) ; 
 int /*<<< orphan*/  MSC_SCAN ; 
#define  PIN_CFG_COL 130 
#define  PIN_CFG_IGNORE 129 
#define  PIN_CFG_ROW 128 
 int PTR_ERR (int) ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_4__*,int) ; 
 int devm_clk_get (TYPE_4__*,int /*<<< orphan*/ *) ; 
 struct input_dev* devm_input_allocate_device (TYPE_4__*) ; 
 int devm_ioremap_resource (TYPE_4__*,struct resource*) ; 
 struct tegra_kbc* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_4__*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct tegra_kbc*) ; 
 int devm_reset_control_get (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  disable_irq (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 struct tegra_kbc* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 struct tegra_kbc* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,unsigned short,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct tegra_kbc*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 scalar_t__ jiffies ; 
 struct tegra_kbc* kbc ; 
 int matrix_keypad_build_keymap (scalar_t__,int /*<<< orphan*/ *,unsigned int,int,unsigned short*,struct input_dev*) ; 
 int /*<<< orphan*/  memcpy (unsigned short*,unsigned short*,int) ; 
 unsigned int min (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (unsigned long) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_get_property (struct device_node*,char*,int*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_4__*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int of_property_read_u32_array (struct device_node*,char*,int*,int) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tegra_kbc*) ; 
 int readl (int) ; 
 int /*<<< orphan*/  reset_control_assert (int) ; 
 int /*<<< orphan*/  reset_control_deassert (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tegra_kbc_of_match ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ usecs_to_jiffies (int) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static void tegra_kbc_report_released_keys(struct input_dev *input,
					   unsigned short old_keycodes[],
					   unsigned int old_num_keys,
					   unsigned short new_keycodes[],
					   unsigned int new_num_keys)
{
	unsigned int i, j;

	for (i = 0; i < old_num_keys; i++) {
		for (j = 0; j < new_num_keys; j++)
			if (old_keycodes[i] == new_keycodes[j])
				break;

		if (j == new_num_keys)
			input_report_key(input, old_keycodes[i], 0);
	}
}

__attribute__((used)) static void tegra_kbc_report_pressed_keys(struct input_dev *input,
					  unsigned char scancodes[],
					  unsigned short keycodes[],
					  unsigned int num_pressed_keys)
{
	unsigned int i;

	for (i = 0; i < num_pressed_keys; i++) {
		input_event(input, EV_MSC, MSC_SCAN, scancodes[i]);
		input_report_key(input, keycodes[i], 1);
	}
}

__attribute__((used)) static void tegra_kbc_report_keys(struct tegra_kbc *kbc)
{
	unsigned char scancodes[KBC_MAX_KPENT];
	unsigned short keycodes[KBC_MAX_KPENT];
	u32 val = 0;
	unsigned int i;
	unsigned int num_down = 0;
	bool fn_keypress = false;
	bool key_in_same_row = false;
	bool key_in_same_col = false;

	for (i = 0; i < KBC_MAX_KPENT; i++) {
		if ((i % 4) == 0)
			val = readl(kbc->mmio + KBC_KP_ENT0_0 + i);

		if (val & 0x80) {
			unsigned int col = val & 0x07;
			unsigned int row = (val >> 3) & 0x0f;
			unsigned char scancode =
				MATRIX_SCAN_CODE(row, col, KBC_ROW_SHIFT);

			scancodes[num_down] = scancode;
			keycodes[num_down] = kbc->keycode[scancode];
			/* If driver uses Fn map, do not report the Fn key. */
			if ((keycodes[num_down] == KEY_FN) && kbc->use_fn_map)
				fn_keypress = true;
			else
				num_down++;
		}

		val >>= 8;
	}

	/*
	 * Matrix keyboard designs are prone to keyboard ghosting.
	 * Ghosting occurs if there are 3 keys such that -
	 * any 2 of the 3 keys share a row, and any 2 of them share a column.
	 * If so ignore the key presses for this iteration.
	 */
	if (kbc->use_ghost_filter && num_down >= 3) {
		for (i = 0; i < num_down; i++) {
			unsigned int j;
			u8 curr_col = scancodes[i] & 0x07;
			u8 curr_row = scancodes[i] >> KBC_ROW_SHIFT;

			/*
			 * Find 2 keys such that one key is in the same row
			 * and the other is in the same column as the i-th key.
			 */
			for (j = i + 1; j < num_down; j++) {
				u8 col = scancodes[j] & 0x07;
				u8 row = scancodes[j] >> KBC_ROW_SHIFT;

				if (col == curr_col)
					key_in_same_col = true;
				if (row == curr_row)
					key_in_same_row = true;
			}
		}
	}

	/*
	 * If the platform uses Fn keymaps, translate keys on a Fn keypress.
	 * Function keycodes are max_keys apart from the plain keycodes.
	 */
	if (fn_keypress) {
		for (i = 0; i < num_down; i++) {
			scancodes[i] += kbc->max_keys;
			keycodes[i] = kbc->keycode[scancodes[i]];
		}
	}

	/* Ignore the key presses for this iteration? */
	if (key_in_same_col && key_in_same_row)
		return;

	tegra_kbc_report_released_keys(kbc->idev,
				       kbc->current_keys, kbc->num_pressed_keys,
				       keycodes, num_down);
	tegra_kbc_report_pressed_keys(kbc->idev, scancodes, keycodes, num_down);
	input_sync(kbc->idev);

	memcpy(kbc->current_keys, keycodes, sizeof(kbc->current_keys));
	kbc->num_pressed_keys = num_down;
}

__attribute__((used)) static void tegra_kbc_set_fifo_interrupt(struct tegra_kbc *kbc, bool enable)
{
	u32 val;

	val = readl(kbc->mmio + KBC_CONTROL_0);
	if (enable)
		val |= KBC_CONTROL_FIFO_CNT_INT_EN;
	else
		val &= ~KBC_CONTROL_FIFO_CNT_INT_EN;
	writel(val, kbc->mmio + KBC_CONTROL_0);
}

__attribute__((used)) static void tegra_kbc_keypress_timer(struct timer_list *t)
{
	struct tegra_kbc *kbc = from_timer(kbc, t, timer);
	unsigned long flags;
	u32 val;
	unsigned int i;

	spin_lock_irqsave(&kbc->lock, flags);

	val = (readl(kbc->mmio + KBC_INT_0) >> 4) & 0xf;
	if (val) {
		unsigned long dly;

		tegra_kbc_report_keys(kbc);

		/*
		 * If more than one keys are pressed we need not wait
		 * for the repoll delay.
		 */
		dly = (val == 1) ? kbc->repoll_dly : 1;
		mod_timer(&kbc->timer, jiffies + msecs_to_jiffies(dly));
	} else {
		/* Release any pressed keys and exit the polling loop */
		for (i = 0; i < kbc->num_pressed_keys; i++)
			input_report_key(kbc->idev, kbc->current_keys[i], 0);
		input_sync(kbc->idev);

		kbc->num_pressed_keys = 0;

		/* All keys are released so enable the keypress interrupt */
		tegra_kbc_set_fifo_interrupt(kbc, true);
	}

	spin_unlock_irqrestore(&kbc->lock, flags);
}

__attribute__((used)) static irqreturn_t tegra_kbc_isr(int irq, void *args)
{
	struct tegra_kbc *kbc = args;
	unsigned long flags;
	u32 val;

	spin_lock_irqsave(&kbc->lock, flags);

	/*
	 * Quickly bail out & reenable interrupts if the fifo threshold
	 * count interrupt wasn't the interrupt source
	 */
	val = readl(kbc->mmio + KBC_INT_0);
	writel(val, kbc->mmio + KBC_INT_0);

	if (val & KBC_INT_FIFO_CNT_INT_STATUS) {
		/*
		 * Until all keys are released, defer further processing to
		 * the polling loop in tegra_kbc_keypress_timer.
		 */
		tegra_kbc_set_fifo_interrupt(kbc, false);
		mod_timer(&kbc->timer, jiffies + kbc->cp_dly_jiffies);
	} else if (val & KBC_INT_KEYPRESS_INT_STATUS) {
		/* We can be here only through system resume path */
		kbc->keypress_caused_wake = true;
	}

	spin_unlock_irqrestore(&kbc->lock, flags);

	return IRQ_HANDLED;
}

__attribute__((used)) static void tegra_kbc_setup_wakekeys(struct tegra_kbc *kbc, bool filter)
{
	int i;
	unsigned int rst_val;

	/* Either mask all keys or none. */
	rst_val = (filter && !kbc->wakeup) ? ~0 : 0;

	for (i = 0; i < kbc->hw_support->max_rows; i++)
		writel(rst_val, kbc->mmio + KBC_ROW0_MASK_0 + i * 4);
}

__attribute__((used)) static void tegra_kbc_config_pins(struct tegra_kbc *kbc)
{
	int i;

	for (i = 0; i < KBC_MAX_GPIO; i++) {
		u32 r_shft = 5 * (i % 6);
		u32 c_shft = 4 * (i % 8);
		u32 r_mask = 0x1f << r_shft;
		u32 c_mask = 0x0f << c_shft;
		u32 r_offs = (i / 6) * 4 + KBC_ROW_CFG0_0;
		u32 c_offs = (i / 8) * 4 + KBC_COL_CFG0_0;
		u32 row_cfg = readl(kbc->mmio + r_offs);
		u32 col_cfg = readl(kbc->mmio + c_offs);

		row_cfg &= ~r_mask;
		col_cfg &= ~c_mask;

		switch (kbc->pin_cfg[i].type) {
		case PIN_CFG_ROW:
			row_cfg |= ((kbc->pin_cfg[i].num << 1) | 1) << r_shft;
			break;

		case PIN_CFG_COL:
			col_cfg |= ((kbc->pin_cfg[i].num << 1) | 1) << c_shft;
			break;

		case PIN_CFG_IGNORE:
			break;
		}

		writel(row_cfg, kbc->mmio + r_offs);
		writel(col_cfg, kbc->mmio + c_offs);
	}
}

__attribute__((used)) static int tegra_kbc_start(struct tegra_kbc *kbc)
{
	unsigned int debounce_cnt;
	u32 val = 0;
	int ret;

	ret = clk_prepare_enable(kbc->clk);
	if (ret)
		return ret;

	/* Reset the KBC controller to clear all previous status.*/
	reset_control_assert(kbc->rst);
	udelay(100);
	reset_control_deassert(kbc->rst);
	udelay(100);

	tegra_kbc_config_pins(kbc);
	tegra_kbc_setup_wakekeys(kbc, false);

	writel(kbc->repeat_cnt, kbc->mmio + KBC_RPT_DLY_0);

	/* Keyboard debounce count is maximum of 12 bits. */
	debounce_cnt = min(kbc->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
	val = KBC_DEBOUNCE_CNT_SHIFT(debounce_cnt);
	val |= KBC_FIFO_TH_CNT_SHIFT(1); /* set fifo interrupt threshold to 1 */
	val |= KBC_CONTROL_FIFO_CNT_INT_EN;  /* interrupt on FIFO threshold */
	val |= KBC_CONTROL_KBC_EN;     /* enable */
	writel(val, kbc->mmio + KBC_CONTROL_0);

	/*
	 * Compute the delay(ns) from interrupt mode to continuous polling
	 * mode so the timer routine is scheduled appropriately.
	 */
	val = readl(kbc->mmio + KBC_INIT_DLY_0);
	kbc->cp_dly_jiffies = usecs_to_jiffies((val & 0xfffff) * 32);

	kbc->num_pressed_keys = 0;

	/*
	 * Atomically clear out any remaining entries in the key FIFO
	 * and enable keyboard interrupts.
	 */
	while (1) {
		val = readl(kbc->mmio + KBC_INT_0);
		val >>= 4;
		if (!val)
			break;

		val = readl(kbc->mmio + KBC_KP_ENT0_0);
		val = readl(kbc->mmio + KBC_KP_ENT1_0);
	}
	writel(0x7, kbc->mmio + KBC_INT_0);

	enable_irq(kbc->irq);

	return 0;
}

__attribute__((used)) static void tegra_kbc_stop(struct tegra_kbc *kbc)
{
	unsigned long flags;
	u32 val;

	spin_lock_irqsave(&kbc->lock, flags);
	val = readl(kbc->mmio + KBC_CONTROL_0);
	val &= ~1;
	writel(val, kbc->mmio + KBC_CONTROL_0);
	spin_unlock_irqrestore(&kbc->lock, flags);

	disable_irq(kbc->irq);
	del_timer_sync(&kbc->timer);

	clk_disable_unprepare(kbc->clk);
}

__attribute__((used)) static int tegra_kbc_open(struct input_dev *dev)
{
	struct tegra_kbc *kbc = input_get_drvdata(dev);

	return tegra_kbc_start(kbc);
}

__attribute__((used)) static void tegra_kbc_close(struct input_dev *dev)
{
	struct tegra_kbc *kbc = input_get_drvdata(dev);

	return tegra_kbc_stop(kbc);
}

__attribute__((used)) static bool tegra_kbc_check_pin_cfg(const struct tegra_kbc *kbc,
					unsigned int *num_rows)
{
	int i;

	*num_rows = 0;

	for (i = 0; i < KBC_MAX_GPIO; i++) {
		const struct tegra_kbc_pin_cfg *pin_cfg = &kbc->pin_cfg[i];

		switch (pin_cfg->type) {
		case PIN_CFG_ROW:
			if (pin_cfg->num >= kbc->hw_support->max_rows) {
				dev_err(kbc->dev,
					"pin_cfg[%d]: invalid row number %d\n",
					i, pin_cfg->num);
				return false;
			}
			(*num_rows)++;
			break;

		case PIN_CFG_COL:
			if (pin_cfg->num >= kbc->hw_support->max_columns) {
				dev_err(kbc->dev,
					"pin_cfg[%d]: invalid column number %d\n",
					i, pin_cfg->num);
				return false;
			}
			break;

		case PIN_CFG_IGNORE:
			break;

		default:
			dev_err(kbc->dev,
				"pin_cfg[%d]: invalid entry type %d\n",
				pin_cfg->type, pin_cfg->num);
			return false;
		}
	}

	return true;
}

__attribute__((used)) static int tegra_kbc_parse_dt(struct tegra_kbc *kbc)
{
	struct device_node *np = kbc->dev->of_node;
	u32 prop;
	int i;
	u32 num_rows = 0;
	u32 num_cols = 0;
	u32 cols_cfg[KBC_MAX_GPIO];
	u32 rows_cfg[KBC_MAX_GPIO];
	int proplen;
	int ret;

	if (!of_property_read_u32(np, "nvidia,debounce-delay-ms", &prop))
		kbc->debounce_cnt = prop;

	if (!of_property_read_u32(np, "nvidia,repeat-delay-ms", &prop))
		kbc->repeat_cnt = prop;

	if (of_find_property(np, "nvidia,needs-ghost-filter", NULL))
		kbc->use_ghost_filter = true;

	if (of_property_read_bool(np, "wakeup-source") ||
	    of_property_read_bool(np, "nvidia,wakeup-source")) /* legacy */
		kbc->wakeup = true;

	if (!of_get_property(np, "nvidia,kbc-row-pins", &proplen)) {
		dev_err(kbc->dev, "property nvidia,kbc-row-pins not found\n");
		return -ENOENT;
	}
	num_rows = proplen / sizeof(u32);

	if (!of_get_property(np, "nvidia,kbc-col-pins", &proplen)) {
		dev_err(kbc->dev, "property nvidia,kbc-col-pins not found\n");
		return -ENOENT;
	}
	num_cols = proplen / sizeof(u32);

	if (num_rows > kbc->hw_support->max_rows) {
		dev_err(kbc->dev,
			"Number of rows is more than supported by hardware\n");
		return -EINVAL;
	}

	if (num_cols > kbc->hw_support->max_columns) {
		dev_err(kbc->dev,
			"Number of cols is more than supported by hardware\n");
		return -EINVAL;
	}

	if (!of_get_property(np, "linux,keymap", &proplen)) {
		dev_err(kbc->dev, "property linux,keymap not found\n");
		return -ENOENT;
	}

	if (!num_rows || !num_cols || ((num_rows + num_cols) > KBC_MAX_GPIO)) {
		dev_err(kbc->dev,
			"keypad rows/columns not properly specified\n");
		return -EINVAL;
	}

	/* Set all pins as non-configured */
	for (i = 0; i < kbc->num_rows_and_columns; i++)
		kbc->pin_cfg[i].type = PIN_CFG_IGNORE;

	ret = of_property_read_u32_array(np, "nvidia,kbc-row-pins",
				rows_cfg, num_rows);
	if (ret < 0) {
		dev_err(kbc->dev, "Rows configurations are not proper\n");
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "nvidia,kbc-col-pins",
				cols_cfg, num_cols);
	if (ret < 0) {
		dev_err(kbc->dev, "Cols configurations are not proper\n");
		return -EINVAL;
	}

	for (i = 0; i < num_rows; i++) {
		kbc->pin_cfg[rows_cfg[i]].type = PIN_CFG_ROW;
		kbc->pin_cfg[rows_cfg[i]].num = i;
	}

	for (i = 0; i < num_cols; i++) {
		kbc->pin_cfg[cols_cfg[i]].type = PIN_CFG_COL;
		kbc->pin_cfg[cols_cfg[i]].num = i;
	}

	return 0;
}

__attribute__((used)) static int tegra_kbc_probe(struct platform_device *pdev)
{
	struct tegra_kbc *kbc;
	struct resource *res;
	int err;
	int num_rows = 0;
	unsigned int debounce_cnt;
	unsigned int scan_time_rows;
	unsigned int keymap_rows;
	const struct of_device_id *match;

	match = of_match_device(tegra_kbc_of_match, &pdev->dev);

	kbc = devm_kzalloc(&pdev->dev, sizeof(*kbc), GFP_KERNEL);
	if (!kbc) {
		dev_err(&pdev->dev, "failed to alloc memory for kbc\n");
		return -ENOMEM;
	}

	kbc->dev = &pdev->dev;
	kbc->hw_support = match->data;
	kbc->max_keys = kbc->hw_support->max_rows *
				kbc->hw_support->max_columns;
	kbc->num_rows_and_columns = kbc->hw_support->max_rows +
					kbc->hw_support->max_columns;
	keymap_rows = kbc->max_keys;
	spin_lock_init(&kbc->lock);

	err = tegra_kbc_parse_dt(kbc);
	if (err)
		return err;

	if (!tegra_kbc_check_pin_cfg(kbc, &num_rows))
		return -EINVAL;

	kbc->irq = platform_get_irq(pdev, 0);
	if (kbc->irq < 0) {
		dev_err(&pdev->dev, "failed to get keyboard IRQ\n");
		return -ENXIO;
	}

	kbc->idev = devm_input_allocate_device(&pdev->dev);
	if (!kbc->idev) {
		dev_err(&pdev->dev, "failed to allocate input device\n");
		return -ENOMEM;
	}

	timer_setup(&kbc->timer, tegra_kbc_keypress_timer, 0);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	kbc->mmio = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(kbc->mmio))
		return PTR_ERR(kbc->mmio);

	kbc->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(kbc->clk)) {
		dev_err(&pdev->dev, "failed to get keyboard clock\n");
		return PTR_ERR(kbc->clk);
	}

	kbc->rst = devm_reset_control_get(&pdev->dev, "kbc");
	if (IS_ERR(kbc->rst)) {
		dev_err(&pdev->dev, "failed to get keyboard reset\n");
		return PTR_ERR(kbc->rst);
	}

	/*
	 * The time delay between two consecutive reads of the FIFO is
	 * the sum of the repeat time and the time taken for scanning
	 * the rows. There is an additional delay before the row scanning
	 * starts. The repoll delay is computed in milliseconds.
	 */
	debounce_cnt = min(kbc->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
	scan_time_rows = (KBC_ROW_SCAN_TIME + debounce_cnt) * num_rows;
	kbc->repoll_dly = KBC_ROW_SCAN_DLY + scan_time_rows + kbc->repeat_cnt;
	kbc->repoll_dly = DIV_ROUND_UP(kbc->repoll_dly, KBC_CYCLE_MS);

	kbc->idev->name = pdev->name;
	kbc->idev->id.bustype = BUS_HOST;
	kbc->idev->dev.parent = &pdev->dev;
	kbc->idev->open = tegra_kbc_open;
	kbc->idev->close = tegra_kbc_close;

	if (kbc->keymap_data && kbc->use_fn_map)
		keymap_rows *= 2;

	err = matrix_keypad_build_keymap(kbc->keymap_data, NULL,
					 keymap_rows,
					 kbc->hw_support->max_columns,
					 kbc->keycode, kbc->idev);
	if (err) {
		dev_err(&pdev->dev, "failed to setup keymap\n");
		return err;
	}

	__set_bit(EV_REP, kbc->idev->evbit);
	input_set_capability(kbc->idev, EV_MSC, MSC_SCAN);

	input_set_drvdata(kbc->idev, kbc);

	err = devm_request_irq(&pdev->dev, kbc->irq, tegra_kbc_isr,
			       IRQF_TRIGGER_HIGH, pdev->name, kbc);
	if (err) {
		dev_err(&pdev->dev, "failed to request keyboard IRQ\n");
		return err;
	}

	disable_irq(kbc->irq);

	err = input_register_device(kbc->idev);
	if (err) {
		dev_err(&pdev->dev, "failed to register input device\n");
		return err;
	}

	platform_set_drvdata(pdev, kbc);
	device_init_wakeup(&pdev->dev, kbc->wakeup);

	return 0;
}

