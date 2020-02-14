#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct sram_parameters {unsigned long long sram_offset; unsigned int sram_size; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_4__ dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  ctl; int /*<<< orphan*/  srbar0; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EINVAL ; 
 int L2CR_L2E ; 
 int L2CR_L2FI ; 
 int L2CR_SRAM_EIGHTH ; 
 int L2CR_SRAM_FULL ; 
 int L2CR_SRAM_HALF ; 
 int L2CR_SRAM_QUART ; 
 int L2SRAM_BAR_MSK_LO18 ; 
#define  LOCK_WAYS_EIGHTH 131 
#define  LOCK_WAYS_FULL 130 
#define  LOCK_WAYS_HALF 129 
#define  LOCK_WAYS_TWO_EIGHTH 128 
 int /*<<< orphan*/  clrsetbits_be32 (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  eieio () ; 
 long instantiate_cache_sram (struct platform_device*,struct sram_parameters) ; 
 int /*<<< orphan*/  iounmap (TYPE_1__*) ; 
 scalar_t__ kstrtouint (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 scalar_t__ kstrtoull (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long long*) ; 
 TYPE_1__* l2ctlr ; 
 int lower_32_bits (unsigned long long) ; 
 unsigned int* of_get_property (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 TYPE_1__* of_iomap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_be32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  remove_cache_sram (struct platform_device*) ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sram_offset ; 
 int /*<<< orphan*/  sram_size ; 

__attribute__((used)) static int get_cache_sram_params(struct sram_parameters *sram_params)
{
	unsigned long long addr;
	unsigned int size;

	if (!sram_size || (kstrtouint(sram_size, 0, &size) < 0))
		return -EINVAL;

	if (!sram_offset || (kstrtoull(sram_offset, 0, &addr) < 0))
		return -EINVAL;

	sram_params->sram_offset = addr;
	sram_params->sram_size = size;

	return 0;
}

__attribute__((used)) static int mpc85xx_l2ctlr_of_probe(struct platform_device *dev)
{
	long rval;
	unsigned int rem;
	unsigned char ways;
	const unsigned int *prop;
	unsigned int l2cache_size;
	struct sram_parameters sram_params;

	if (!dev->dev.of_node) {
		dev_err(&dev->dev, "Device's OF-node is NULL\n");
		return -EINVAL;
	}

	prop = of_get_property(dev->dev.of_node, "cache-size", NULL);
	if (!prop) {
		dev_err(&dev->dev, "Missing L2 cache-size\n");
		return -EINVAL;
	}
	l2cache_size = *prop;

	if (get_cache_sram_params(&sram_params))
		return 0; /* fall back to L2 cache only */

	rem = l2cache_size % sram_params.sram_size;
	ways = LOCK_WAYS_FULL * sram_params.sram_size / l2cache_size;
	if (rem || (ways & (ways - 1))) {
		dev_err(&dev->dev, "Illegal cache-sram-size in command line\n");
		return -EINVAL;
	}

	l2ctlr = of_iomap(dev->dev.of_node, 0);
	if (!l2ctlr) {
		dev_err(&dev->dev, "Can't map L2 controller\n");
		return -EINVAL;
	}

	/*
	 * Write bits[0-17] to srbar0
	 */
	out_be32(&l2ctlr->srbar0,
		lower_32_bits(sram_params.sram_offset) & L2SRAM_BAR_MSK_LO18);

	/*
	 * Write bits[18-21] to srbare0
	 */
#ifdef CONFIG_PHYS_64BIT
	out_be32(&l2ctlr->srbarea0,
		upper_32_bits(sram_params.sram_offset) & L2SRAM_BARE_MSK_HI4);
#endif

	clrsetbits_be32(&l2ctlr->ctl, L2CR_L2E, L2CR_L2FI);

	switch (ways) {
	case LOCK_WAYS_EIGHTH:
		setbits32(&l2ctlr->ctl,
			L2CR_L2E | L2CR_L2FI | L2CR_SRAM_EIGHTH);
		break;

	case LOCK_WAYS_TWO_EIGHTH:
		setbits32(&l2ctlr->ctl,
			L2CR_L2E | L2CR_L2FI | L2CR_SRAM_QUART);
		break;

	case LOCK_WAYS_HALF:
		setbits32(&l2ctlr->ctl,
			L2CR_L2E | L2CR_L2FI | L2CR_SRAM_HALF);
		break;

	case LOCK_WAYS_FULL:
	default:
		setbits32(&l2ctlr->ctl,
			L2CR_L2E | L2CR_L2FI | L2CR_SRAM_FULL);
		break;
	}
	eieio();

	rval = instantiate_cache_sram(dev, sram_params);
	if (rval < 0) {
		dev_err(&dev->dev, "Can't instantiate Cache-SRAM\n");
		iounmap(l2ctlr);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int mpc85xx_l2ctlr_of_remove(struct platform_device *dev)
{
	BUG_ON(!l2ctlr);

	iounmap(l2ctlr);
	remove_cache_sram(dev);
	dev_info(&dev->dev, "MPC85xx L2 controller unloaded\n");

	return 0;
}

