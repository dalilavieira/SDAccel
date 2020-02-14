#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct resource {int dummy; } ;
struct pci_device_id {scalar_t__ driver_data; } ;
struct pci_dev {int /*<<< orphan*/  irq; int /*<<< orphan*/  resource; int /*<<< orphan*/  dev; } ;
struct intel_th_drvdata {int dummy; } ;
struct TYPE_4__ {struct device* parent; } ;
struct TYPE_3__ {scalar_t__ port; scalar_t__ type; } ;
struct intel_th_device {int num_resources; scalar_t__ type; TYPE_2__ dev; TYPE_1__ output; struct resource* resource; } ;
struct intel_th {int (* activate ) (struct intel_th*) ;void (* deactivate ) (struct intel_th*) ;int /*<<< orphan*/  dev; struct intel_th_device* hub; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BAR_MASK ; 
 int /*<<< orphan*/  DEVICE_COUNT_RESOURCE ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 scalar_t__ GTH_NONE ; 
 int /*<<< orphan*/  INTEL_TH_CAP (struct intel_th*,int /*<<< orphan*/ ) ; 
 scalar_t__ INTEL_TH_OUTPUT ; 
 scalar_t__ INTEL_TH_SWITCH ; 
 scalar_t__ IS_ERR (struct intel_th*) ; 
 int /*<<< orphan*/  NPKDSC_TSACT ; 
 int /*<<< orphan*/  PCI_REG_NPKDSC ; 
 int PTR_ERR (struct intel_th*) ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct intel_th* dev_get_drvdata (struct device*) ; 
 struct intel_th* intel_th_alloc (int /*<<< orphan*/ *,struct intel_th_drvdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  intel_th_free (struct intel_th*) ; 
 struct intel_th* pci_get_drvdata (struct pci_dev*) ; 
 int pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int pci_write_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcim_enable_device (struct pci_dev*) ; 
 int pcim_iomap_regions_request_all (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int resource_type (struct resource*) ; 
 struct intel_th_device* to_intel_th_device (struct device*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tscu_enable ; 

__attribute__((used)) static inline struct resource *
intel_th_device_get_resource(struct intel_th_device *thdev, unsigned int type,
			     unsigned int num)
{
	int i;

	for (i = 0; i < thdev->num_resources; i++)
		if (resource_type(&thdev->resource[i]) == type && !num--)
			return &thdev->resource[i];

	return NULL;
}

__attribute__((used)) static inline bool
intel_th_output_assigned(struct intel_th_device *thdev)
{
	return thdev->type == INTEL_TH_OUTPUT &&
		(thdev->output.port >= 0 ||
		 thdev->output.type == GTH_NONE);
}

__attribute__((used)) static inline struct intel_th_device *
to_intel_th_parent(struct intel_th_device *thdev)
{
	struct device *parent = thdev->dev.parent;

	if (!parent)
		return NULL;

	return to_intel_th_device(parent);
}

__attribute__((used)) static inline struct intel_th *to_intel_th(struct intel_th_device *thdev)
{
	if (thdev->type == INTEL_TH_OUTPUT)
		thdev = to_intel_th_parent(thdev);

	if (WARN_ON_ONCE(!thdev || thdev->type == INTEL_TH_OUTPUT))
		return NULL;

	return dev_get_drvdata(thdev->dev.parent);
}

__attribute__((used)) static inline struct intel_th_device *
to_intel_th_hub(struct intel_th_device *thdev)
{
	if (thdev->type == INTEL_TH_SWITCH)
		return thdev;
	else if (thdev->type == INTEL_TH_OUTPUT)
		return to_intel_th_parent(thdev);

	return to_intel_th(thdev)->hub;
}

__attribute__((used)) static int intel_th_pci_activate(struct intel_th *th)
{
	struct pci_dev *pdev = to_pci_dev(th->dev);
	u32 npkdsc;
	int err;

	if (!INTEL_TH_CAP(th, tscu_enable))
		return 0;

	err = pci_read_config_dword(pdev, PCI_REG_NPKDSC, &npkdsc);
	if (!err) {
		npkdsc |= NPKDSC_TSACT;
		err = pci_write_config_dword(pdev, PCI_REG_NPKDSC, npkdsc);
	}

	if (err)
		dev_err(&pdev->dev, "failed to read NPKDSC register\n");

	return err;
}

__attribute__((used)) static void intel_th_pci_deactivate(struct intel_th *th)
{
	struct pci_dev *pdev = to_pci_dev(th->dev);
	u32 npkdsc;
	int err;

	if (!INTEL_TH_CAP(th, tscu_enable))
		return;

	err = pci_read_config_dword(pdev, PCI_REG_NPKDSC, &npkdsc);
	if (!err) {
		npkdsc |= NPKDSC_TSACT;
		err = pci_write_config_dword(pdev, PCI_REG_NPKDSC, npkdsc);
	}

	if (err)
		dev_err(&pdev->dev, "failed to read NPKDSC register\n");
}

__attribute__((used)) static int intel_th_pci_probe(struct pci_dev *pdev,
			      const struct pci_device_id *id)
{
	struct intel_th_drvdata *drvdata = (void *)id->driver_data;
	struct intel_th *th;
	int err;

	err = pcim_enable_device(pdev);
	if (err)
		return err;

	err = pcim_iomap_regions_request_all(pdev, BAR_MASK, DRIVER_NAME);
	if (err)
		return err;

	th = intel_th_alloc(&pdev->dev, drvdata, pdev->resource,
			    DEVICE_COUNT_RESOURCE, pdev->irq);
	if (IS_ERR(th))
		return PTR_ERR(th);

	th->activate   = intel_th_pci_activate;
	th->deactivate = intel_th_pci_deactivate;

	pci_set_master(pdev);

	return 0;
}

__attribute__((used)) static void intel_th_pci_remove(struct pci_dev *pdev)
{
	struct intel_th *th = pci_get_drvdata(pdev);

	intel_th_free(th);
}

