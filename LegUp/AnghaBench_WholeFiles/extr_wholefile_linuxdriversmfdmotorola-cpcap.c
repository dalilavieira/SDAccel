#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u16 ;
struct spi_device {int bits_per_word; int mode; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct regmap_irq_chip_data {int dummy; } ;
struct regmap_irq_chip {int num_irqs; struct cpcap_ddata* irq_drv_data; struct regmap_irq* irqs; } ;
struct regmap_irq {unsigned int reg_offset; unsigned int mask; } ;
struct regmap {int dummy; } ;
struct of_device_id {int dummy; } ;
struct cpcap_ddata {struct spi_device* spi; int /*<<< orphan*/  regmap; TYPE_1__* regmap_conf; struct regmap_irq* irqs; int /*<<< orphan*/ * irqdata; } ;
struct TYPE_3__ {unsigned int val_bits; unsigned int reg_stride; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  CPCAP_NR_IRQ_REG_BANKS ; 
 int CPCAP_REGISTER_BITS ; 
 int CPCAP_REGISTER_SIZE ; 
 int CPCAP_REG_INTS1 ; 
 int CPCAP_REG_INTS4 ; 
 scalar_t__ CPCAP_REVISION_2_1 ; 
 int /*<<< orphan*/  CPCAP_REVISION_MAJOR (scalar_t__) ; 
 int /*<<< orphan*/  CPCAP_REVISION_MINOR (scalar_t__) ; 
 scalar_t__ CPCAP_VENDOR_ST ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_SHARED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SPI_CS_HIGH ; 
 int SPI_MODE_0 ; 
 int array3_size (int,int /*<<< orphan*/ ,int) ; 
 int cpcap_get_revision (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*) ; 
 int cpcap_get_vendor (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*) ; 
 struct regmap_irq_chip* cpcap_irq_chip ; 
 int /*<<< orphan*/  cpcap_of_match ; 
 TYPE_1__ cpcap_regmap_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_of_platform_populate (int /*<<< orphan*/ *) ; 
 int devm_regmap_add_irq_chip (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,struct regmap_irq_chip*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_spi (struct spi_device*,TYPE_1__*) ; 
 int /*<<< orphan*/  enable_irq_wake (int /*<<< orphan*/ ) ; 
 struct regmap_irq_chip_data* irq_get_chip_data (int) ; 
 int irq_get_trigger_type (int /*<<< orphan*/ ) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 int regmap_irq_chip_get_base (struct regmap_irq_chip_data*) ; 
 int regmap_read (struct regmap*,int,int*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct cpcap_ddata*) ; 
 int spi_setup (struct spi_device*) ; 

__attribute__((used)) static int cpcap_sense_irq(struct regmap *regmap, int irq)
{
	int regnum = irq / CPCAP_REGISTER_BITS;
	int mask = BIT(irq % CPCAP_REGISTER_BITS);
	int reg = CPCAP_REG_INTS1 + (regnum * CPCAP_REGISTER_SIZE);
	int err, val;

	if (reg < CPCAP_REG_INTS1 || reg > CPCAP_REG_INTS4)
		return -EINVAL;

	err = regmap_read(regmap, reg, &val);
	if (err)
		return err;

	return !!(val & mask);
}

int cpcap_sense_virq(struct regmap *regmap, int virq)
{
	struct regmap_irq_chip_data *d = irq_get_chip_data(virq);
	int irq_base = regmap_irq_chip_get_base(d);

	return cpcap_sense_irq(regmap, virq - irq_base);
}

__attribute__((used)) static int cpcap_check_revision(struct cpcap_ddata *cpcap)
{
	u16 vendor, rev;
	int ret;

	ret = cpcap_get_vendor(&cpcap->spi->dev, cpcap->regmap, &vendor);
	if (ret)
		return ret;

	ret = cpcap_get_revision(&cpcap->spi->dev, cpcap->regmap, &rev);
	if (ret)
		return ret;

	dev_info(&cpcap->spi->dev, "CPCAP vendor: %s rev: %i.%i (%x)\n",
		 vendor == CPCAP_VENDOR_ST ? "ST" : "TI",
		 CPCAP_REVISION_MAJOR(rev), CPCAP_REVISION_MINOR(rev),
		 rev);

	if (rev < CPCAP_REVISION_2_1) {
		dev_info(&cpcap->spi->dev,
			 "Please add old CPCAP revision support as needed\n");
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static void cpcap_init_one_regmap_irq(struct cpcap_ddata *cpcap,
				      struct regmap_irq *rirq,
				      int irq_base, int irq)
{
	unsigned int reg_offset;
	unsigned int bit, mask;

	reg_offset = irq - irq_base;
	reg_offset /= cpcap->regmap_conf->val_bits;
	reg_offset *= cpcap->regmap_conf->reg_stride;

	bit = irq % cpcap->regmap_conf->val_bits;
	mask = (1 << bit);

	rirq->reg_offset = reg_offset;
	rirq->mask = mask;
}

__attribute__((used)) static int cpcap_init_irq_chip(struct cpcap_ddata *cpcap, int irq_chip,
			       int irq_start, int nr_irqs)
{
	struct regmap_irq_chip *chip = &cpcap_irq_chip[irq_chip];
	int i, ret;

	for (i = irq_start; i < irq_start + nr_irqs; i++) {
		struct regmap_irq *rirq = &cpcap->irqs[i];

		cpcap_init_one_regmap_irq(cpcap, rirq, irq_start, i);
	}
	chip->irqs = &cpcap->irqs[irq_start];
	chip->num_irqs = nr_irqs;
	chip->irq_drv_data = cpcap;

	ret = devm_regmap_add_irq_chip(&cpcap->spi->dev, cpcap->regmap,
				       cpcap->spi->irq,
				       irq_get_trigger_type(cpcap->spi->irq) |
				       IRQF_SHARED, -1,
				       chip, &cpcap->irqdata[irq_chip]);
	if (ret) {
		dev_err(&cpcap->spi->dev, "could not add irq chip %i: %i\n",
			irq_chip, ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int cpcap_init_irq(struct cpcap_ddata *cpcap)
{
	int ret;

	cpcap->irqs = devm_kzalloc(&cpcap->spi->dev,
				   array3_size(sizeof(*cpcap->irqs),
					       CPCAP_NR_IRQ_REG_BANKS,
					       cpcap->regmap_conf->val_bits),
				   GFP_KERNEL);
	if (!cpcap->irqs)
		return -ENOMEM;

	ret = cpcap_init_irq_chip(cpcap, 0, 0, 16);
	if (ret)
		return ret;

	ret = cpcap_init_irq_chip(cpcap, 1, 16, 16);
	if (ret)
		return ret;

	ret = cpcap_init_irq_chip(cpcap, 2, 32, 64);
	if (ret)
		return ret;

	enable_irq_wake(cpcap->spi->irq);

	return 0;
}

__attribute__((used)) static int cpcap_probe(struct spi_device *spi)
{
	const struct of_device_id *match;
	struct cpcap_ddata *cpcap;
	int ret;

	match = of_match_device(of_match_ptr(cpcap_of_match), &spi->dev);
	if (!match)
		return -ENODEV;

	cpcap = devm_kzalloc(&spi->dev, sizeof(*cpcap), GFP_KERNEL);
	if (!cpcap)
		return -ENOMEM;

	cpcap->spi = spi;
	spi_set_drvdata(spi, cpcap);

	spi->bits_per_word = 16;
	spi->mode = SPI_MODE_0 | SPI_CS_HIGH;

	ret = spi_setup(spi);
	if (ret)
		return ret;

	cpcap->regmap_conf = &cpcap_regmap_config;
	cpcap->regmap = devm_regmap_init_spi(spi, &cpcap_regmap_config);
	if (IS_ERR(cpcap->regmap)) {
		ret = PTR_ERR(cpcap->regmap);
		dev_err(&cpcap->spi->dev, "Failed to initialize regmap: %d\n",
			ret);

		return ret;
	}

	ret = cpcap_check_revision(cpcap);
	if (ret) {
		dev_err(&cpcap->spi->dev, "Failed to detect CPCAP: %i\n", ret);
		return ret;
	}

	ret = cpcap_init_irq(cpcap);
	if (ret)
		return ret;

	return devm_of_platform_populate(&cpcap->spi->dev);
}

