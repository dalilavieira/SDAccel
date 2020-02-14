#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {void* driver_data; int /*<<< orphan*/  init_data; TYPE_2__* dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {size_t id; TYPE_2__ dev; } ;
struct pcap_regulator {int index; int en; int /*<<< orphan*/  reg; } ;
struct TYPE_4__ {int n_voltages; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int NA ; 
 int PTR_ERR (struct regulator_dev*) ; 
 void* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (TYPE_2__*) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int /*<<< orphan*/  ezx_pcap_read (void*,int /*<<< orphan*/ ,int*) ; 
 int ezx_pcap_set_bits (void*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/ * pcap_regulators ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 void* rdev_get_drvdata (struct regulator_dev*) ; 
 size_t rdev_get_id (struct regulator_dev*) ; 
 struct pcap_regulator* vreg_table ; 

__attribute__((used)) static int pcap_regulator_set_voltage_sel(struct regulator_dev *rdev,
					  unsigned selector)
{
	struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
	void *pcap = rdev_get_drvdata(rdev);

	/* the regulator doesn't support voltage switching */
	if (rdev->desc->n_voltages == 1)
		return -EINVAL;

	return ezx_pcap_set_bits(pcap, vreg->reg,
				 (rdev->desc->n_voltages - 1) << vreg->index,
				 selector << vreg->index);
}

__attribute__((used)) static int pcap_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
	struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
	void *pcap = rdev_get_drvdata(rdev);
	u32 tmp;

	if (rdev->desc->n_voltages == 1)
		return 0;

	ezx_pcap_read(pcap, vreg->reg, &tmp);
	tmp = ((tmp >> vreg->index) & (rdev->desc->n_voltages - 1));
	return tmp;
}

__attribute__((used)) static int pcap_regulator_enable(struct regulator_dev *rdev)
{
	struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
	void *pcap = rdev_get_drvdata(rdev);

	if (vreg->en == NA)
		return -EINVAL;

	return ezx_pcap_set_bits(pcap, vreg->reg, 1 << vreg->en, 1 << vreg->en);
}

__attribute__((used)) static int pcap_regulator_disable(struct regulator_dev *rdev)
{
	struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
	void *pcap = rdev_get_drvdata(rdev);

	if (vreg->en == NA)
		return -EINVAL;

	return ezx_pcap_set_bits(pcap, vreg->reg, 1 << vreg->en, 0);
}

__attribute__((used)) static int pcap_regulator_is_enabled(struct regulator_dev *rdev)
{
	struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
	void *pcap = rdev_get_drvdata(rdev);
	u32 tmp;

	if (vreg->en == NA)
		return -EINVAL;

	ezx_pcap_read(pcap, vreg->reg, &tmp);
	return (tmp >> vreg->en) & 1;
}

__attribute__((used)) static int pcap_regulator_probe(struct platform_device *pdev)
{
	struct regulator_dev *rdev;
	void *pcap = dev_get_drvdata(pdev->dev.parent);
	struct regulator_config config = { };

	config.dev = &pdev->dev;
	config.init_data = dev_get_platdata(&pdev->dev);
	config.driver_data = pcap;

	rdev = devm_regulator_register(&pdev->dev, &pcap_regulators[pdev->id],
				       &config);
	if (IS_ERR(rdev))
		return PTR_ERR(rdev);

	platform_set_drvdata(pdev, rdev);

	return 0;
}

