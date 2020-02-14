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
typedef  int ulong ;
typedef  int uint32_t ;
typedef  int u32 ;
struct resource {unsigned int start; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct gpio_chip {int dummy; } ;
struct cs5535_gpio_chip {int base; int /*<<< orphan*/  chip; int /*<<< orphan*/  lock; struct platform_device* pdev; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 unsigned int GPIO_INPUT_AUX1 ; 
 unsigned int GPIO_INPUT_ENABLE ; 
 unsigned int GPIO_MAP_W ; 
 unsigned int GPIO_MAP_X ; 
 unsigned int GPIO_MAP_Y ; 
 unsigned int GPIO_MAP_Z ; 
 unsigned int GPIO_NEGATIVE_EDGE_STS ; 
 unsigned int GPIO_OUTPUT_AUX1 ; 
 unsigned int GPIO_OUTPUT_AUX2 ; 
 unsigned int GPIO_OUTPUT_ENABLE ; 
 unsigned int GPIO_OUTPUT_VAL ; 
 unsigned int GPIO_POSITIVE_EDGE_STS ; 
 unsigned int GPIO_READ_BACK ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int /*<<< orphan*/  MSR_PIC_ZSEL_HIGH ; 
 struct cs5535_gpio_chip cs5535_gpio_chip ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int devm_gpiochip_add_data (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct cs5535_gpio_chip*) ; 
 int /*<<< orphan*/  devm_request_region (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cs5535_gpio_chip* gpiochip_get_data (struct gpio_chip*) ; 
 int inl (unsigned int) ; 
 int mask ; 
 int /*<<< orphan*/  outl (int,unsigned int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdmsr (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wrmsr (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void errata_outl(struct cs5535_gpio_chip *chip, u32 val,
		unsigned int reg)
{
	unsigned long addr = chip->base + 0x80 + reg;

	/*
	 * According to the CS5536 errata (#36), after suspend
	 * a write to the high bank GPIO register will clear all
	 * non-selected bits; the recommended workaround is a
	 * read-modify-write operation.
	 *
	 * Don't apply this errata to the edge status GPIOs, as writing
	 * to their lower bits will clear them.
	 */
	if (reg != GPIO_POSITIVE_EDGE_STS && reg != GPIO_NEGATIVE_EDGE_STS) {
		if (val & 0xffff)
			val |= (inl(addr) & 0xffff); /* ignore the high bits */
		else
			val |= (inl(addr) ^ (val >> 16));
	}
	outl(val, addr);
}

__attribute__((used)) static void __cs5535_gpio_set(struct cs5535_gpio_chip *chip, unsigned offset,
		unsigned int reg)
{
	if (offset < 16)
		/* low bank register */
		outl(1 << offset, chip->base + reg);
	else
		/* high bank register */
		errata_outl(chip, 1 << (offset - 16), reg);
}

void cs5535_gpio_set(unsigned offset, unsigned int reg)
{
	struct cs5535_gpio_chip *chip = &cs5535_gpio_chip;
	unsigned long flags;

	spin_lock_irqsave(&chip->lock, flags);
	__cs5535_gpio_set(chip, offset, reg);
	spin_unlock_irqrestore(&chip->lock, flags);
}

__attribute__((used)) static void __cs5535_gpio_clear(struct cs5535_gpio_chip *chip, unsigned offset,
		unsigned int reg)
{
	if (offset < 16)
		/* low bank register */
		outl(1 << (offset + 16), chip->base + reg);
	else
		/* high bank register */
		errata_outl(chip, 1 << offset, reg);
}

void cs5535_gpio_clear(unsigned offset, unsigned int reg)
{
	struct cs5535_gpio_chip *chip = &cs5535_gpio_chip;
	unsigned long flags;

	spin_lock_irqsave(&chip->lock, flags);
	__cs5535_gpio_clear(chip, offset, reg);
	spin_unlock_irqrestore(&chip->lock, flags);
}

int cs5535_gpio_isset(unsigned offset, unsigned int reg)
{
	struct cs5535_gpio_chip *chip = &cs5535_gpio_chip;
	unsigned long flags;
	long val;

	spin_lock_irqsave(&chip->lock, flags);
	if (offset < 16)
		/* low bank register */
		val = inl(chip->base + reg);
	else {
		/* high bank register */
		val = inl(chip->base + 0x80 + reg);
		offset -= 16;
	}
	spin_unlock_irqrestore(&chip->lock, flags);

	return (val & (1 << offset)) ? 1 : 0;
}

int cs5535_gpio_set_irq(unsigned group, unsigned irq)
{
	uint32_t lo, hi;

	if (group > 7 || irq > 15)
		return -EINVAL;

	rdmsr(MSR_PIC_ZSEL_HIGH, lo, hi);

	lo &= ~(0xF << (group * 4));
	lo |= (irq & 0xF) << (group * 4);

	wrmsr(MSR_PIC_ZSEL_HIGH, lo, hi);
	return 0;
}

void cs5535_gpio_setup_event(unsigned offset, int pair, int pme)
{
	struct cs5535_gpio_chip *chip = &cs5535_gpio_chip;
	uint32_t shift = (offset % 8) * 4;
	unsigned long flags;
	uint32_t val;

	if (offset >= 24)
		offset = GPIO_MAP_W;
	else if (offset >= 16)
		offset = GPIO_MAP_Z;
	else if (offset >= 8)
		offset = GPIO_MAP_Y;
	else
		offset = GPIO_MAP_X;

	spin_lock_irqsave(&chip->lock, flags);
	val = inl(chip->base + offset);

	/* Clear whatever was there before */
	val &= ~(0xF << shift);

	/* Set the new value */
	val |= ((pair & 7) << shift);

	/* Set the PME bit if this is a PME event */
	if (pme)
		val |= (1 << (shift + 3));

	outl(val, chip->base + offset);
	spin_unlock_irqrestore(&chip->lock, flags);
}

__attribute__((used)) static int chip_gpio_request(struct gpio_chip *c, unsigned offset)
{
	struct cs5535_gpio_chip *chip = gpiochip_get_data(c);
	unsigned long flags;

	spin_lock_irqsave(&chip->lock, flags);

	/* check if this pin is available */
	if ((mask & (1 << offset)) == 0) {
		dev_info(&chip->pdev->dev,
			"pin %u is not available (check mask)\n", offset);
		spin_unlock_irqrestore(&chip->lock, flags);
		return -EINVAL;
	}

	/* disable output aux 1 & 2 on this pin */
	__cs5535_gpio_clear(chip, offset, GPIO_OUTPUT_AUX1);
	__cs5535_gpio_clear(chip, offset, GPIO_OUTPUT_AUX2);

	/* disable input aux 1 on this pin */
	__cs5535_gpio_clear(chip, offset, GPIO_INPUT_AUX1);

	spin_unlock_irqrestore(&chip->lock, flags);

	return 0;
}

__attribute__((used)) static int chip_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	return cs5535_gpio_isset(offset, GPIO_READ_BACK);
}

__attribute__((used)) static void chip_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
	if (val)
		cs5535_gpio_set(offset, GPIO_OUTPUT_VAL);
	else
		cs5535_gpio_clear(offset, GPIO_OUTPUT_VAL);
}

__attribute__((used)) static int chip_direction_input(struct gpio_chip *c, unsigned offset)
{
	struct cs5535_gpio_chip *chip = gpiochip_get_data(c);
	unsigned long flags;

	spin_lock_irqsave(&chip->lock, flags);
	__cs5535_gpio_set(chip, offset, GPIO_INPUT_ENABLE);
	__cs5535_gpio_clear(chip, offset, GPIO_OUTPUT_ENABLE);
	spin_unlock_irqrestore(&chip->lock, flags);

	return 0;
}

__attribute__((used)) static int chip_direction_output(struct gpio_chip *c, unsigned offset, int val)
{
	struct cs5535_gpio_chip *chip = gpiochip_get_data(c);
	unsigned long flags;

	spin_lock_irqsave(&chip->lock, flags);

	__cs5535_gpio_set(chip, offset, GPIO_INPUT_ENABLE);
	__cs5535_gpio_set(chip, offset, GPIO_OUTPUT_ENABLE);
	if (val)
		__cs5535_gpio_set(chip, offset, GPIO_OUTPUT_VAL);
	else
		__cs5535_gpio_clear(chip, offset, GPIO_OUTPUT_VAL);

	spin_unlock_irqrestore(&chip->lock, flags);

	return 0;
}

__attribute__((used)) static int cs5535_gpio_probe(struct platform_device *pdev)
{
	struct resource *res;
	int err = -EIO;
	ulong mask_orig = mask;

	/* There are two ways to get the GPIO base address; one is by
	 * fetching it from MSR_LBAR_GPIO, the other is by reading the
	 * PCI BAR info.  The latter method is easier (especially across
	 * different architectures), so we'll stick with that for now.  If
	 * it turns out to be unreliable in the face of crappy BIOSes, we
	 * can always go back to using MSRs.. */

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!res) {
		dev_err(&pdev->dev, "can't fetch device resource info\n");
		return err;
	}

	if (!devm_request_region(&pdev->dev, res->start, resource_size(res),
				 pdev->name)) {
		dev_err(&pdev->dev, "can't request region\n");
		return err;
	}

	/* set up the driver-specific struct */
	cs5535_gpio_chip.base = res->start;
	cs5535_gpio_chip.pdev = pdev;
	spin_lock_init(&cs5535_gpio_chip.lock);

	dev_info(&pdev->dev, "reserved resource region %pR\n", res);

	/* mask out reserved pins */
	mask &= 0x1F7FFFFF;

	/* do not allow pin 28, Power Button, as there's special handling
	 * in the PMC needed. (note 12, p. 48) */
	mask &= ~(1 << 28);

	if (mask_orig != mask)
		dev_info(&pdev->dev, "mask changed from 0x%08lX to 0x%08lX\n",
				mask_orig, mask);

	/* finally, register with the generic GPIO API */
	err = devm_gpiochip_add_data(&pdev->dev, &cs5535_gpio_chip.chip,
				     &cs5535_gpio_chip);
	if (err)
		return err;

	return 0;
}

