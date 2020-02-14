#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device_id {int driver_data; } ;
struct TYPE_8__ {int /*<<< orphan*/  kobj; struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct irq_domain {struct ab8500* host_data; } ;
struct irq_data {int hwirq; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {struct device* parent; } ;
struct ab8500 {int chip_id; int (* write ) (struct ab8500*,int,int) ;int (* read ) (struct ab8500*,int) ;int (* write_masked ) (struct ab8500*,int,int,int) ;int mask_size; int* oldmask; int* mask; int* irq_reg_offset; int it_latchhier_num; int version; TYPE_1__* dev; int /*<<< orphan*/  domain; int /*<<< orphan*/  irq; int /*<<< orphan*/  transfer_ongoing; int /*<<< orphan*/  irq_lock; int /*<<< orphan*/  lock; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
typedef  enum ab8500_version { ____Placeholder_ab8500_version } ab8500_version ;

/* Variables and functions */
 int AB8500_CHARGER ; 
 int AB8500_CH_USBCH_STAT1_REG ; 
 int AB8500_CUT2P0 ; 
 int AB8500_IC_NAME_REG ; 
 int AB8500_INTERRUPT ; 
 int AB8500_INT_GPIO41F ; 
 int AB8500_INT_GPIO41R ; 
 int AB8500_INT_GPIO6F ; 
 int AB8500_INT_GPIO6R ; 
 int AB8500_IT_LATCH1_REG ; 
 int AB8500_IT_LATCHHIER1_REG ; 
 void* AB8500_IT_LATCHHIER_NUM ; 
 int AB8500_IT_MASK1_REG ; 
 int AB8500_MISC ; 
 int AB8500_NR_IRQS ; 
 int AB8500_NUM_IRQ_REGS ; 
 int AB8500_POW_KEY_1_ON ; 
 int AB8500_REGU_CTRL2 ; 
 int AB8500_REV_REG ; 
 int AB8500_RTC ; 
 int AB8500_SWITCH_OFF_STATUS ; 
 int AB8500_SYS_CTRL1_BLOCK ; 
 int AB8500_TURN_ON_STATUS ; 
 int AB8500_VBUS_DET ; 
 int AB8500_VERSION_UNDEFINED ; 
 int AB8505_NR_IRQS ; 
 int AB8505_TURN_ON_STATUS_2 ; 
 int AB8540_INT_GPIO43F ; 
 int AB8540_INT_GPIO43R ; 
 int AB8540_INT_GPIO44F ; 
 int AB8540_INT_GPIO44R ; 
 int AB8540_IT_LATCHHIER_NUM ; 
 int AB8540_NR_IRQS ; 
 int AB8540_NUM_IRQ_REGS ; 
 int AB9540_INT_GPIO50F ; 
 int AB9540_INT_GPIO50R ; 
 int AB9540_INT_GPIO54F ; 
 int AB9540_INT_GPIO54R ; 
 int AB9540_MODEM_CTRL2_REG ; 
 int AB9540_MODEM_CTRL2_SWDBBRSTN_BIT ; 
 int AB9540_NR_IRQS ; 
 int AB9540_NUM_IRQ_REGS ; 
 int ARRAY_SIZE (char const* const*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int IRQF_NO_SUSPEND ; 
 int IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int IRQ_TYPE_EDGE_FALLING ; 
 unsigned int IRQ_TYPE_EDGE_RISING ; 
 int VBUS_DET_DBNC1 ; 
 int VBUS_DET_DBNC100 ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  ab8500_attr_group ; 
 char const* const* ab8500_bm_devs ; 
 char const* const* ab8500_devs ; 
 int /*<<< orphan*/  ab8500_irq_chip ; 
 int /*<<< orphan*/  ab8500_irq_ops ; 
 int* ab8500_irq_regoffset ; 
 int /*<<< orphan*/  ab8500_ops ; 
 int /*<<< orphan*/ * ab8500_version_str ; 
 int /*<<< orphan*/  ab8505_attr_group ; 
 char const* const* ab8505_devs ; 
 char const* const* ab8540_cut1_devs ; 
 char const* const* ab8540_cut2_devs ; 
 char const* const* ab8540_devs ; 
 int* ab8540_irq_regoffset ; 
 int /*<<< orphan*/  ab9540_attr_group ; 
 char const* const* ab9540_devs ; 
 int* ab9540_irq_regoffset ; 
 int abx500_register_ops (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct ab8500* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,char const,...) ; 
 int /*<<< orphan*/  dev_vdbg (TYPE_1__*,char*,...) ; 
 void* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct ab8500*) ; 
 int /*<<< orphan*/  handle_nested_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 int /*<<< orphan*/  irq_create_mapping (int /*<<< orphan*/ ,int) ; 
 struct ab8500* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  irq_domain_add_simple (struct device_node*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct ab8500*) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct ab8500*) ; 
 int /*<<< orphan*/  irq_set_nested_thread (unsigned int,int) ; 
 int /*<<< orphan*/  irq_set_noprobe (unsigned int) ; 
 unsigned int irqd_get_trigger_type (struct irq_data*) ; 
 scalar_t__ is_ab8500_1p1_or_earlier (struct ab8500*) ; 
 scalar_t__ is_ab8505 (struct ab8500*) ; 
 scalar_t__ is_ab8540 (struct ab8500*) ; 
 scalar_t__ is_ab8540_1p2_or_earlier (struct ab8500*) ; 
 scalar_t__ is_ab9540 (struct ab8500*) ; 
 int mfd_add_devices (TYPE_1__*,int /*<<< orphan*/ ,char const* const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  no_bm ; 
 int /*<<< orphan*/  on_stat_lock ; 
 struct platform_device_id* platform_get_device_id (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ab8500*) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int prcmu_abb_read (int,int,int*,int) ; 
 int prcmu_abb_write (int,int,int*,int) ; 
 int prcmu_abb_write_masked (int,int,int*,int*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int stub1 (struct ab8500*,int,int) ; 
 int stub2 (struct ab8500*,int) ; 
 int stub3 (struct ab8500*,int) ; 
 int stub4 (struct ab8500*,int,int) ; 
 int stub5 (struct ab8500*,int,int,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int turn_on_stat_mask ; 
 int turn_on_stat_set ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int ab8500_prcmu_write(struct ab8500 *ab8500, u16 addr, u8 data)
{
	int ret;

	ret = prcmu_abb_write((u8)(addr >> 8), (u8)(addr & 0xFF), &data, 1);
	if (ret < 0)
		dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
	return ret;
}

__attribute__((used)) static int ab8500_prcmu_write_masked(struct ab8500 *ab8500, u16 addr, u8 mask,
	u8 data)
{
	int ret;

	ret = prcmu_abb_write_masked((u8)(addr >> 8), (u8)(addr & 0xFF), &data,
		&mask, 1);
	if (ret < 0)
		dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
	return ret;
}

__attribute__((used)) static int ab8500_prcmu_read(struct ab8500 *ab8500, u16 addr)
{
	int ret;
	u8 data;

	ret = prcmu_abb_read((u8)(addr >> 8), (u8)(addr & 0xFF), &data, 1);
	if (ret < 0) {
		dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
		return ret;
	}
	return (int)data;
}

__attribute__((used)) static int ab8500_get_chip_id(struct device *dev)
{
	struct ab8500 *ab8500;

	if (!dev)
		return -EINVAL;
	ab8500 = dev_get_drvdata(dev->parent);
	return ab8500 ? (int)ab8500->chip_id : -EINVAL;
}

__attribute__((used)) static int set_register_interruptible(struct ab8500 *ab8500, u8 bank,
	u8 reg, u8 data)
{
	int ret;
	/*
	 * Put the u8 bank and u8 register together into a an u16.
	 * The bank on higher 8 bits and register in lower 8 bits.
	 */
	u16 addr = ((u16)bank) << 8 | reg;

	dev_vdbg(ab8500->dev, "wr: addr %#x <= %#x\n", addr, data);

	mutex_lock(&ab8500->lock);

	ret = ab8500->write(ab8500, addr, data);
	if (ret < 0)
		dev_err(ab8500->dev, "failed to write reg %#x: %d\n",
			addr, ret);
	mutex_unlock(&ab8500->lock);

	return ret;
}

__attribute__((used)) static int ab8500_set_register(struct device *dev, u8 bank,
	u8 reg, u8 value)
{
	int ret;
	struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);

	atomic_inc(&ab8500->transfer_ongoing);
	ret = set_register_interruptible(ab8500, bank, reg, value);
	atomic_dec(&ab8500->transfer_ongoing);
	return ret;
}

__attribute__((used)) static int get_register_interruptible(struct ab8500 *ab8500, u8 bank,
	u8 reg, u8 *value)
{
	int ret;
	u16 addr = ((u16)bank) << 8 | reg;

	mutex_lock(&ab8500->lock);

	ret = ab8500->read(ab8500, addr);
	if (ret < 0)
		dev_err(ab8500->dev, "failed to read reg %#x: %d\n",
			addr, ret);
	else
		*value = ret;

	mutex_unlock(&ab8500->lock);
	dev_vdbg(ab8500->dev, "rd: addr %#x => data %#x\n", addr, ret);

	return (ret < 0) ? ret : 0;
}

__attribute__((used)) static int ab8500_get_register(struct device *dev, u8 bank,
	u8 reg, u8 *value)
{
	int ret;
	struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);

	atomic_inc(&ab8500->transfer_ongoing);
	ret = get_register_interruptible(ab8500, bank, reg, value);
	atomic_dec(&ab8500->transfer_ongoing);
	return ret;
}

__attribute__((used)) static int mask_and_set_register_interruptible(struct ab8500 *ab8500, u8 bank,
	u8 reg, u8 bitmask, u8 bitvalues)
{
	int ret;
	u16 addr = ((u16)bank) << 8 | reg;

	mutex_lock(&ab8500->lock);

	if (ab8500->write_masked == NULL) {
		u8 data;

		ret = ab8500->read(ab8500, addr);
		if (ret < 0) {
			dev_err(ab8500->dev, "failed to read reg %#x: %d\n",
				addr, ret);
			goto out;
		}

		data = (u8)ret;
		data = (~bitmask & data) | (bitmask & bitvalues);

		ret = ab8500->write(ab8500, addr, data);
		if (ret < 0)
			dev_err(ab8500->dev, "failed to write reg %#x: %d\n",
				addr, ret);

		dev_vdbg(ab8500->dev, "mask: addr %#x => data %#x\n", addr,
			data);
		goto out;
	}
	ret = ab8500->write_masked(ab8500, addr, bitmask, bitvalues);
	if (ret < 0)
		dev_err(ab8500->dev, "failed to modify reg %#x: %d\n", addr,
			ret);
out:
	mutex_unlock(&ab8500->lock);
	return ret;
}

__attribute__((used)) static int ab8500_mask_and_set_register(struct device *dev,
	u8 bank, u8 reg, u8 bitmask, u8 bitvalues)
{
	int ret;
	struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);

	atomic_inc(&ab8500->transfer_ongoing);
	ret = mask_and_set_register_interruptible(ab8500, bank, reg,
						 bitmask, bitvalues);
	atomic_dec(&ab8500->transfer_ongoing);
	return ret;
}

__attribute__((used)) static void ab8500_irq_lock(struct irq_data *data)
{
	struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);

	mutex_lock(&ab8500->irq_lock);
	atomic_inc(&ab8500->transfer_ongoing);
}

__attribute__((used)) static void ab8500_irq_sync_unlock(struct irq_data *data)
{
	struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
	int i;

	for (i = 0; i < ab8500->mask_size; i++) {
		u8 old = ab8500->oldmask[i];
		u8 new = ab8500->mask[i];
		int reg;

		if (new == old)
			continue;

		/*
		 * Interrupt register 12 doesn't exist prior to AB8500 version
		 * 2.0
		 */
		if (ab8500->irq_reg_offset[i] == 11 &&
			is_ab8500_1p1_or_earlier(ab8500))
			continue;

		if (ab8500->irq_reg_offset[i] < 0)
			continue;

		ab8500->oldmask[i] = new;

		reg = AB8500_IT_MASK1_REG + ab8500->irq_reg_offset[i];
		set_register_interruptible(ab8500, AB8500_INTERRUPT, reg, new);
	}
	atomic_dec(&ab8500->transfer_ongoing);
	mutex_unlock(&ab8500->irq_lock);
}

__attribute__((used)) static void ab8500_irq_mask(struct irq_data *data)
{
	struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
	int offset = data->hwirq;
	int index = offset / 8;
	int mask = 1 << (offset % 8);

	ab8500->mask[index] |= mask;

	/* The AB8500 GPIOs have two interrupts each (rising & falling). */
	if (offset >= AB8500_INT_GPIO6R && offset <= AB8500_INT_GPIO41R)
		ab8500->mask[index + 2] |= mask;
	if (offset >= AB9540_INT_GPIO50R && offset <= AB9540_INT_GPIO54R)
		ab8500->mask[index + 1] |= mask;
	if (offset == AB8540_INT_GPIO43R || offset == AB8540_INT_GPIO44R)
		/* Here the falling IRQ is one bit lower */
		ab8500->mask[index] |= (mask << 1);
}

__attribute__((used)) static void ab8500_irq_unmask(struct irq_data *data)
{
	struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
	unsigned int type = irqd_get_trigger_type(data);
	int offset = data->hwirq;
	int index = offset / 8;
	int mask = 1 << (offset % 8);

	if (type & IRQ_TYPE_EDGE_RISING)
		ab8500->mask[index] &= ~mask;

	/* The AB8500 GPIOs have two interrupts each (rising & falling). */
	if (type & IRQ_TYPE_EDGE_FALLING) {
		if (offset >= AB8500_INT_GPIO6R && offset <= AB8500_INT_GPIO41R)
			ab8500->mask[index + 2] &= ~mask;
		else if (offset >= AB9540_INT_GPIO50R &&
			 offset <= AB9540_INT_GPIO54R)
			ab8500->mask[index + 1] &= ~mask;
		else if (offset == AB8540_INT_GPIO43R ||
			 offset == AB8540_INT_GPIO44R)
			/* Here the falling IRQ is one bit lower */
			ab8500->mask[index] &= ~(mask << 1);
		else
			ab8500->mask[index] &= ~mask;
	} else {
		/* Satisfies the case where type is not set. */
		ab8500->mask[index] &= ~mask;
	}
}

__attribute__((used)) static int ab8500_irq_set_type(struct irq_data *data, unsigned int type)
{
	return 0;
}

__attribute__((used)) static void update_latch_offset(u8 *offset, int i)
{
	/* Fix inconsistent ITFromLatch25 bit mapping... */
	if (unlikely(*offset == 17))
		*offset = 24;
	/* Fix inconsistent ab8540 bit mapping... */
	if (unlikely(*offset == 16))
		*offset = 25;
	if ((i == 3) && (*offset >= 24))
		*offset += 2;
}

__attribute__((used)) static int ab8500_handle_hierarchical_line(struct ab8500 *ab8500,
					int latch_offset, u8 latch_val)
{
	int int_bit, line, i;

	for (i = 0; i < ab8500->mask_size; i++)
		if (ab8500->irq_reg_offset[i] == latch_offset)
			break;

	if (i >= ab8500->mask_size) {
		dev_err(ab8500->dev, "Register offset 0x%2x not declared\n",
				latch_offset);
		return -ENXIO;
	}

	/* ignore masked out interrupts */
	latch_val &= ~ab8500->mask[i];

	while (latch_val) {
		int_bit = __ffs(latch_val);
		line = (i << 3) + int_bit;
		latch_val &= ~(1 << int_bit);

		/*
		 * This handles the falling edge hwirqs from the GPIO
		 * lines. Route them back to the line registered for the
		 * rising IRQ, as this is merely a flag for the same IRQ
		 * in linux terms.
		 */
		if (line >= AB8500_INT_GPIO6F && line <= AB8500_INT_GPIO41F)
			line -= 16;
		if (line >= AB9540_INT_GPIO50F && line <= AB9540_INT_GPIO54F)
			line -= 8;
		if (line == AB8540_INT_GPIO43F || line == AB8540_INT_GPIO44F)
			line += 1;

		handle_nested_irq(irq_create_mapping(ab8500->domain, line));
	}

	return 0;
}

__attribute__((used)) static int ab8500_handle_hierarchical_latch(struct ab8500 *ab8500,
					int hier_offset, u8 hier_val)
{
	int latch_bit, status;
	u8 latch_offset, latch_val;

	do {
		latch_bit = __ffs(hier_val);
		latch_offset = (hier_offset << 3) + latch_bit;

		update_latch_offset(&latch_offset, hier_offset);

		status = get_register_interruptible(ab8500,
				AB8500_INTERRUPT,
				AB8500_IT_LATCH1_REG + latch_offset,
				&latch_val);
		if (status < 0 || latch_val == 0)
			goto discard;

		status = ab8500_handle_hierarchical_line(ab8500,
				latch_offset, latch_val);
		if (status < 0)
			return status;
discard:
		hier_val &= ~(1 << latch_bit);
	} while (hier_val);

	return 0;
}

__attribute__((used)) static irqreturn_t ab8500_hierarchical_irq(int irq, void *dev)
{
	struct ab8500 *ab8500 = dev;
	u8 i;

	dev_vdbg(ab8500->dev, "interrupt\n");

	/*  Hierarchical interrupt version */
	for (i = 0; i < (ab8500->it_latchhier_num); i++) {
		int status;
		u8 hier_val;

		status = get_register_interruptible(ab8500, AB8500_INTERRUPT,
			AB8500_IT_LATCHHIER1_REG + i, &hier_val);
		if (status < 0 || hier_val == 0)
			continue;

		status = ab8500_handle_hierarchical_latch(ab8500, i, hier_val);
		if (status < 0)
			break;
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int ab8500_irq_map(struct irq_domain *d, unsigned int virq,
				irq_hw_number_t hwirq)
{
	struct ab8500 *ab8500 = d->host_data;

	if (!ab8500)
		return -EINVAL;

	irq_set_chip_data(virq, ab8500);
	irq_set_chip_and_handler(virq, &ab8500_irq_chip,
				handle_simple_irq);
	irq_set_nested_thread(virq, 1);
	irq_set_noprobe(virq);

	return 0;
}

__attribute__((used)) static int ab8500_irq_init(struct ab8500 *ab8500, struct device_node *np)
{
	int num_irqs;

	if (is_ab8540(ab8500))
		num_irqs = AB8540_NR_IRQS;
	else if (is_ab9540(ab8500))
		num_irqs = AB9540_NR_IRQS;
	else if (is_ab8505(ab8500))
		num_irqs = AB8505_NR_IRQS;
	else
		num_irqs = AB8500_NR_IRQS;

	/* If ->irq_base is zero this will give a linear mapping */
	ab8500->domain = irq_domain_add_simple(ab8500->dev->of_node,
					       num_irqs, 0,
					       &ab8500_irq_ops, ab8500);

	if (!ab8500->domain) {
		dev_err(ab8500->dev, "Failed to create irqdomain\n");
		return -ENODEV;
	}

	return 0;
}

int ab8500_suspend(struct ab8500 *ab8500)
{
	if (atomic_read(&ab8500->transfer_ongoing))
		return -EINVAL;

	return 0;
}

__attribute__((used)) static ssize_t show_chip_id(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct ab8500 *ab8500;

	ab8500 = dev_get_drvdata(dev);

	return sprintf(buf, "%#x\n", ab8500 ? ab8500->chip_id : -EINVAL);
}

__attribute__((used)) static ssize_t show_switch_off_status(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int ret;
	u8 value;
	struct ab8500 *ab8500;

	ab8500 = dev_get_drvdata(dev);
	ret = get_register_interruptible(ab8500, AB8500_RTC,
		AB8500_SWITCH_OFF_STATUS, &value);
	if (ret < 0)
		return ret;
	return sprintf(buf, "%#x\n", value);
}

void ab8500_override_turn_on_stat(u8 mask, u8 set)
{
	spin_lock(&on_stat_lock);
	turn_on_stat_mask = mask;
	turn_on_stat_set = set;
	spin_unlock(&on_stat_lock);
}

__attribute__((used)) static ssize_t show_turn_on_status(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int ret;
	u8 value;
	struct ab8500 *ab8500;

	ab8500 = dev_get_drvdata(dev);
	ret = get_register_interruptible(ab8500, AB8500_SYS_CTRL1_BLOCK,
		AB8500_TURN_ON_STATUS, &value);
	if (ret < 0)
		return ret;

	/*
	 * In L9540, turn_on_status register is not updated correctly if
	 * the device is rebooted with AC/USB charger connected. Due to
	 * this, the device boots android instead of entering into charge
	 * only mode. Read the AC/USB status register to detect the charger
	 * presence and update the turn on status manually.
	 */
	if (is_ab9540(ab8500)) {
		spin_lock(&on_stat_lock);
		value = (value & turn_on_stat_mask) | turn_on_stat_set;
		spin_unlock(&on_stat_lock);
	}

	return sprintf(buf, "%#x\n", value);
}

__attribute__((used)) static ssize_t show_turn_on_status_2(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int ret;
	u8 value;
	struct ab8500 *ab8500;

	ab8500 = dev_get_drvdata(dev);
	ret = get_register_interruptible(ab8500, AB8500_SYS_CTRL1_BLOCK,
		AB8505_TURN_ON_STATUS_2, &value);
	if (ret < 0)
		return ret;
	return sprintf(buf, "%#x\n", (value & 0x1));
}

__attribute__((used)) static ssize_t show_ab9540_dbbrstn(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct ab8500 *ab8500;
	int ret;
	u8 value;

	ab8500 = dev_get_drvdata(dev);

	ret = get_register_interruptible(ab8500, AB8500_REGU_CTRL2,
		AB9540_MODEM_CTRL2_REG, &value);
	if (ret < 0)
		return ret;

	return sprintf(buf, "%d\n",
			(value & AB9540_MODEM_CTRL2_SWDBBRSTN_BIT) ? 1 : 0);
}

__attribute__((used)) static ssize_t store_ab9540_dbbrstn(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct ab8500 *ab8500;
	int ret = count;
	int err;
	u8 bitvalues;

	ab8500 = dev_get_drvdata(dev);

	if (count > 0) {
		switch (buf[0]) {
		case '0':
			bitvalues = 0;
			break;
		case '1':
			bitvalues = AB9540_MODEM_CTRL2_SWDBBRSTN_BIT;
			break;
		default:
			goto exit;
		}

		err = mask_and_set_register_interruptible(ab8500,
			AB8500_REGU_CTRL2, AB9540_MODEM_CTRL2_REG,
			AB9540_MODEM_CTRL2_SWDBBRSTN_BIT, bitvalues);
		if (err)
			dev_info(ab8500->dev,
				"Failed to set DBBRSTN %c, err %#x\n",
				buf[0], err);
	}

exit:
	return ret;
}

__attribute__((used)) static int ab8500_probe(struct platform_device *pdev)
{
	static const char * const switch_off_status[] = {
		"Swoff bit programming",
		"Thermal protection activation",
		"Vbat lower then BattOk falling threshold",
		"Watchdog expired",
		"Non presence of 32kHz clock",
		"Battery level lower than power on reset threshold",
		"Power on key 1 pressed longer than 10 seconds",
		"DB8500 thermal shutdown"};
	static const char * const turn_on_status[] = {
		"Battery rising (Vbat)",
		"Power On Key 1 dbF",
		"Power On Key 2 dbF",
		"RTC Alarm",
		"Main Charger Detect",
		"Vbus Detect (USB)",
		"USB ID Detect",
		"UART Factory Mode Detect"};
	const struct platform_device_id *platid = platform_get_device_id(pdev);
	enum ab8500_version version = AB8500_VERSION_UNDEFINED;
	struct device_node *np = pdev->dev.of_node;
	struct ab8500 *ab8500;
	struct resource *resource;
	int ret;
	int i;
	u8 value;

	ab8500 = devm_kzalloc(&pdev->dev, sizeof(*ab8500), GFP_KERNEL);
	if (!ab8500)
		return -ENOMEM;

	ab8500->dev = &pdev->dev;

	resource = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!resource) {
		dev_err(&pdev->dev, "no IRQ resource\n");
		return -ENODEV;
	}

	ab8500->irq = resource->start;

	ab8500->read = ab8500_prcmu_read;
	ab8500->write = ab8500_prcmu_write;
	ab8500->write_masked = ab8500_prcmu_write_masked;

	mutex_init(&ab8500->lock);
	mutex_init(&ab8500->irq_lock);
	atomic_set(&ab8500->transfer_ongoing, 0);

	platform_set_drvdata(pdev, ab8500);

	if (platid)
		version = platid->driver_data;

	if (version != AB8500_VERSION_UNDEFINED)
		ab8500->version = version;
	else {
		ret = get_register_interruptible(ab8500, AB8500_MISC,
			AB8500_IC_NAME_REG, &value);
		if (ret < 0) {
			dev_err(&pdev->dev, "could not probe HW\n");
			return ret;
		}

		ab8500->version = value;
	}

	ret = get_register_interruptible(ab8500, AB8500_MISC,
		AB8500_REV_REG, &value);
	if (ret < 0)
		return ret;

	ab8500->chip_id = value;

	dev_info(ab8500->dev, "detected chip, %s rev. %1x.%1x\n",
			ab8500_version_str[ab8500->version],
			ab8500->chip_id >> 4,
			ab8500->chip_id & 0x0F);

	/* Configure AB8540 */
	if (is_ab8540(ab8500)) {
		ab8500->mask_size = AB8540_NUM_IRQ_REGS;
		ab8500->irq_reg_offset = ab8540_irq_regoffset;
		ab8500->it_latchhier_num = AB8540_IT_LATCHHIER_NUM;
	} /* Configure AB8500 or AB9540 IRQ */
	else if (is_ab9540(ab8500) || is_ab8505(ab8500)) {
		ab8500->mask_size = AB9540_NUM_IRQ_REGS;
		ab8500->irq_reg_offset = ab9540_irq_regoffset;
		ab8500->it_latchhier_num = AB8500_IT_LATCHHIER_NUM;
	} else {
		ab8500->mask_size = AB8500_NUM_IRQ_REGS;
		ab8500->irq_reg_offset = ab8500_irq_regoffset;
		ab8500->it_latchhier_num = AB8500_IT_LATCHHIER_NUM;
	}
	ab8500->mask = devm_kzalloc(&pdev->dev, ab8500->mask_size,
				    GFP_KERNEL);
	if (!ab8500->mask)
		return -ENOMEM;
	ab8500->oldmask = devm_kzalloc(&pdev->dev, ab8500->mask_size,
				       GFP_KERNEL);
	if (!ab8500->oldmask)
		return -ENOMEM;

	/*
	 * ab8500 has switched off due to (SWITCH_OFF_STATUS):
	 * 0x01 Swoff bit programming
	 * 0x02 Thermal protection activation
	 * 0x04 Vbat lower then BattOk falling threshold
	 * 0x08 Watchdog expired
	 * 0x10 Non presence of 32kHz clock
	 * 0x20 Battery level lower than power on reset threshold
	 * 0x40 Power on key 1 pressed longer than 10 seconds
	 * 0x80 DB8500 thermal shutdown
	 */

	ret = get_register_interruptible(ab8500, AB8500_RTC,
		AB8500_SWITCH_OFF_STATUS, &value);
	if (ret < 0)
		return ret;
	dev_info(ab8500->dev, "switch off cause(s) (%#x): ", value);

	if (value) {
		for (i = 0; i < ARRAY_SIZE(switch_off_status); i++) {
			if (value & 1)
				pr_cont(" \"%s\"", switch_off_status[i]);
			value = value >> 1;

		}
		pr_cont("\n");
	} else {
		pr_cont(" None\n");
	}
	ret = get_register_interruptible(ab8500, AB8500_SYS_CTRL1_BLOCK,
		AB8500_TURN_ON_STATUS, &value);
	if (ret < 0)
		return ret;
	dev_info(ab8500->dev, "turn on reason(s) (%#x): ", value);

	if (value) {
		for (i = 0; i < ARRAY_SIZE(turn_on_status); i++) {
			if (value & 1)
				pr_cont("\"%s\" ", turn_on_status[i]);
			value = value >> 1;
		}
		pr_cont("\n");
	} else {
		pr_cont("None\n");
	}

	if (is_ab9540(ab8500)) {
		ret = get_register_interruptible(ab8500, AB8500_CHARGER,
			AB8500_CH_USBCH_STAT1_REG, &value);
		if (ret < 0)
			return ret;
		if ((value & VBUS_DET_DBNC1) && (value & VBUS_DET_DBNC100))
			ab8500_override_turn_on_stat(~AB8500_POW_KEY_1_ON,
						     AB8500_VBUS_DET);
	}

	/* Clear and mask all interrupts */
	for (i = 0; i < ab8500->mask_size; i++) {
		/*
		 * Interrupt register 12 doesn't exist prior to AB8500 version
		 * 2.0
		 */
		if (ab8500->irq_reg_offset[i] == 11 &&
				is_ab8500_1p1_or_earlier(ab8500))
			continue;

		if (ab8500->irq_reg_offset[i] < 0)
			continue;

		get_register_interruptible(ab8500, AB8500_INTERRUPT,
			AB8500_IT_LATCH1_REG + ab8500->irq_reg_offset[i],
			&value);
		set_register_interruptible(ab8500, AB8500_INTERRUPT,
			AB8500_IT_MASK1_REG + ab8500->irq_reg_offset[i], 0xff);
	}

	ret = abx500_register_ops(ab8500->dev, &ab8500_ops);
	if (ret)
		return ret;

	for (i = 0; i < ab8500->mask_size; i++)
		ab8500->mask[i] = ab8500->oldmask[i] = 0xff;

	ret = ab8500_irq_init(ab8500, np);
	if (ret)
		return ret;

	ret = devm_request_threaded_irq(&pdev->dev, ab8500->irq, NULL,
			ab8500_hierarchical_irq,
			IRQF_ONESHOT | IRQF_NO_SUSPEND,
			"ab8500", ab8500);
	if (ret)
		return ret;

	if (is_ab9540(ab8500))
		ret = mfd_add_devices(ab8500->dev, 0, ab9540_devs,
				ARRAY_SIZE(ab9540_devs), NULL,
				0, ab8500->domain);
	else if (is_ab8540(ab8500)) {
		ret = mfd_add_devices(ab8500->dev, 0, ab8540_devs,
			      ARRAY_SIZE(ab8540_devs), NULL,
			      0, ab8500->domain);
		if (ret)
			return ret;

		if (is_ab8540_1p2_or_earlier(ab8500))
			ret = mfd_add_devices(ab8500->dev, 0, ab8540_cut1_devs,
			      ARRAY_SIZE(ab8540_cut1_devs), NULL,
			      0, ab8500->domain);
		else /* ab8540 >= cut2 */
			ret = mfd_add_devices(ab8500->dev, 0, ab8540_cut2_devs,
			      ARRAY_SIZE(ab8540_cut2_devs), NULL,
			      0, ab8500->domain);
	} else if (is_ab8505(ab8500))
		ret = mfd_add_devices(ab8500->dev, 0, ab8505_devs,
			      ARRAY_SIZE(ab8505_devs), NULL,
			      0, ab8500->domain);
	else
		ret = mfd_add_devices(ab8500->dev, 0, ab8500_devs,
				ARRAY_SIZE(ab8500_devs), NULL,
				0, ab8500->domain);
	if (ret)
		return ret;

	if (!no_bm) {
		/* Add battery management devices */
		ret = mfd_add_devices(ab8500->dev, 0, ab8500_bm_devs,
				      ARRAY_SIZE(ab8500_bm_devs), NULL,
				      0, ab8500->domain);
		if (ret)
			dev_err(ab8500->dev, "error adding bm devices\n");
	}

	if (((is_ab8505(ab8500) || is_ab9540(ab8500)) &&
			ab8500->chip_id >= AB8500_CUT2P0) || is_ab8540(ab8500))
		ret = sysfs_create_group(&ab8500->dev->kobj,
					&ab9540_attr_group);
	else
		ret = sysfs_create_group(&ab8500->dev->kobj,
					&ab8500_attr_group);

	if ((is_ab8505(ab8500) || is_ab9540(ab8500)) &&
			ab8500->chip_id >= AB8500_CUT2P0)
		ret = sysfs_create_group(&ab8500->dev->kobj,
					 &ab8505_attr_group);

	if (ret)
		dev_err(ab8500->dev, "error creating sysfs entries\n");

	return ret;
}

