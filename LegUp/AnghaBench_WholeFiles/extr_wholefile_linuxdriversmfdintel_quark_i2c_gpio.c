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
struct resource {void* end; void* start; } ;
struct pci_device_id {int dummy; } ;
struct device {int dummy; } ;
struct pci_dev {struct device dev; void* irq; } ;
struct mfd_cell {int pdata_size; struct dwapb_platform_data* platform_data; scalar_t__ resources; } ;
struct intel_quark_mfd {struct device* dev; struct clk* i2c_clk; int /*<<< orphan*/  i2c_clk_lookup; } ;
struct dwapb_platform_data {int i2c_scl_freq; TYPE_1__* properties; int /*<<< orphan*/  nports; } ;
struct dw_i2c_platform_data {int i2c_scl_freq; TYPE_1__* properties; int /*<<< orphan*/  nports; } ;
struct dmi_system_id {scalar_t__ driver_data; } ;
struct clk {int dummy; } ;
struct TYPE_2__ {int has_irq; int irq_shared; void** irq; int /*<<< orphan*/  gpio_base; int /*<<< orphan*/  ngpio; scalar_t__ idx; int /*<<< orphan*/ * fwnode; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (struct mfd_cell*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INTEL_QUARK_GPIO_NPORTS ; 
 int /*<<< orphan*/  INTEL_QUARK_I2C_CLK_HZ ; 
 int /*<<< orphan*/  INTEL_QUARK_I2C_CONTROLLER_CLK ; 
 size_t INTEL_QUARK_IORES_IRQ ; 
 size_t INTEL_QUARK_IORES_MEM ; 
 int /*<<< orphan*/  INTEL_QUARK_MFD_GPIO_BASE ; 
 int /*<<< orphan*/  INTEL_QUARK_MFD_NGPIO ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int /*<<< orphan*/  MFD_GPIO_BAR ; 
 int /*<<< orphan*/  MFD_I2C_BAR ; 
 int PTR_ERR (struct clk*) ; 
 struct clk* clk_register_fixed_rate (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_unregister (struct clk*) ; 
 int /*<<< orphan*/  clkdev_create (struct clk*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clkdev_drop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct intel_quark_mfd* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct intel_quark_mfd*) ; 
 TYPE_1__* devm_kcalloc (struct device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct dmi_system_id* dmi_first_match (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dmi_platform_info ; 
 struct mfd_cell* intel_quark_mfd_cells ; 
 int mfd_add_devices (struct device*,int /*<<< orphan*/ ,struct mfd_cell*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 void* pci_resource_end (struct pci_dev*,int /*<<< orphan*/ ) ; 
 void* pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pcim_enable_device (struct pci_dev*) ; 

__attribute__((used)) static int intel_quark_register_i2c_clk(struct device *dev)
{
	struct intel_quark_mfd *quark_mfd = dev_get_drvdata(dev);
	struct clk *i2c_clk;

	i2c_clk = clk_register_fixed_rate(dev,
					  INTEL_QUARK_I2C_CONTROLLER_CLK, NULL,
					  0, INTEL_QUARK_I2C_CLK_HZ);
	if (IS_ERR(i2c_clk))
		return PTR_ERR(i2c_clk);

	quark_mfd->i2c_clk = i2c_clk;
	quark_mfd->i2c_clk_lookup = clkdev_create(i2c_clk, NULL,
						INTEL_QUARK_I2C_CONTROLLER_CLK);

	if (!quark_mfd->i2c_clk_lookup) {
		clk_unregister(quark_mfd->i2c_clk);
		dev_err(dev, "Fixed clk register failed\n");
		return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static void intel_quark_unregister_i2c_clk(struct device *dev)
{
	struct intel_quark_mfd *quark_mfd = dev_get_drvdata(dev);

	if (!quark_mfd->i2c_clk_lookup)
		return;

	clkdev_drop(quark_mfd->i2c_clk_lookup);
	clk_unregister(quark_mfd->i2c_clk);
}

__attribute__((used)) static int intel_quark_i2c_setup(struct pci_dev *pdev, struct mfd_cell *cell)
{
	const struct dmi_system_id *dmi_id;
	struct dw_i2c_platform_data *pdata;
	struct resource *res = (struct resource *)cell->resources;
	struct device *dev = &pdev->dev;

	res[INTEL_QUARK_IORES_MEM].start =
		pci_resource_start(pdev, MFD_I2C_BAR);
	res[INTEL_QUARK_IORES_MEM].end =
		pci_resource_end(pdev, MFD_I2C_BAR);

	res[INTEL_QUARK_IORES_IRQ].start = pdev->irq;
	res[INTEL_QUARK_IORES_IRQ].end = pdev->irq;

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	/* Normal mode by default */
	pdata->i2c_scl_freq = 100000;

	dmi_id = dmi_first_match(dmi_platform_info);
	if (dmi_id)
		pdata->i2c_scl_freq = (uintptr_t)dmi_id->driver_data;

	cell->platform_data = pdata;
	cell->pdata_size = sizeof(*pdata);

	return 0;
}

__attribute__((used)) static int intel_quark_gpio_setup(struct pci_dev *pdev, struct mfd_cell *cell)
{
	struct dwapb_platform_data *pdata;
	struct resource *res = (struct resource *)cell->resources;
	struct device *dev = &pdev->dev;

	res[INTEL_QUARK_IORES_MEM].start =
		pci_resource_start(pdev, MFD_GPIO_BAR);
	res[INTEL_QUARK_IORES_MEM].end =
		pci_resource_end(pdev, MFD_GPIO_BAR);

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	/* For intel quark x1000, it has only one port: portA */
	pdata->nports = INTEL_QUARK_GPIO_NPORTS;
	pdata->properties = devm_kcalloc(dev, pdata->nports,
					 sizeof(*pdata->properties),
					 GFP_KERNEL);
	if (!pdata->properties)
		return -ENOMEM;

	/* Set the properties for portA */
	pdata->properties->fwnode	= NULL;
	pdata->properties->idx		= 0;
	pdata->properties->ngpio	= INTEL_QUARK_MFD_NGPIO;
	pdata->properties->gpio_base	= INTEL_QUARK_MFD_GPIO_BASE;
	pdata->properties->irq[0]	= pdev->irq;
	pdata->properties->has_irq	= true;
	pdata->properties->irq_shared	= true;

	cell->platform_data = pdata;
	cell->pdata_size = sizeof(*pdata);

	return 0;
}

__attribute__((used)) static int intel_quark_mfd_probe(struct pci_dev *pdev,
				 const struct pci_device_id *id)
{
	struct intel_quark_mfd *quark_mfd;
	int ret;

	ret = pcim_enable_device(pdev);
	if (ret)
		return ret;

	quark_mfd = devm_kzalloc(&pdev->dev, sizeof(*quark_mfd), GFP_KERNEL);
	if (!quark_mfd)
		return -ENOMEM;

	quark_mfd->dev = &pdev->dev;
	dev_set_drvdata(&pdev->dev, quark_mfd);

	ret = intel_quark_register_i2c_clk(&pdev->dev);
	if (ret)
		return ret;

	ret = intel_quark_i2c_setup(pdev, &intel_quark_mfd_cells[1]);
	if (ret)
		goto err_unregister_i2c_clk;

	ret = intel_quark_gpio_setup(pdev, &intel_quark_mfd_cells[0]);
	if (ret)
		goto err_unregister_i2c_clk;

	ret = mfd_add_devices(&pdev->dev, 0, intel_quark_mfd_cells,
			      ARRAY_SIZE(intel_quark_mfd_cells), NULL, 0,
			      NULL);
	if (ret)
		goto err_unregister_i2c_clk;

	return 0;

err_unregister_i2c_clk:
	intel_quark_unregister_i2c_clk(&pdev->dev);
	return ret;
}

__attribute__((used)) static void intel_quark_mfd_remove(struct pci_dev *pdev)
{
	intel_quark_unregister_i2c_clk(&pdev->dev);
	mfd_remove_devices(&pdev->dev);
}

