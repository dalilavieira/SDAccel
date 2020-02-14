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
typedef  int u32 ;
struct seattle_plat_data {struct ahci_host_priv* sgpio_ctrl; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct ata_port_info {int dummy; } ;
struct ata_port {int /*<<< orphan*/  lock; int /*<<< orphan*/  port_no; struct ahci_port_priv* private_data; TYPE_1__* host; } ;
struct ahci_port_priv {struct ahci_em_priv* em_priv; } ;
struct ahci_host_priv {int em_buf_sz; struct seattle_plat_data* plat_data; int /*<<< orphan*/  em_msg_type; scalar_t__ em_loc; } ;
struct ahci_em_priv {int led_state; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {struct ahci_host_priv* private_data; } ;

/* Variables and functions */
 int ACTIVITY_BIT_POS (int /*<<< orphan*/ ) ; 
 int ACTIVITY_MASK ; 
 int /*<<< orphan*/  EINVAL ; 
 int EM_MAX_SLOTS ; 
 int EM_MSG_LED_PMP_SLOT ; 
 int /*<<< orphan*/  EM_MSG_TYPE_LED ; 
 int FAULT_BIT_POS (int /*<<< orphan*/ ) ; 
 int FAULT_MASK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct ahci_host_priv*) ; 
 int LOCATE_BIT_POS (int /*<<< orphan*/ ) ; 
 int LOCATE_MASK ; 
 int PTR_ERR (struct ahci_host_priv*) ; 
 int /*<<< orphan*/  ahci_platform_disable_resources (struct ahci_host_priv*) ; 
 int ahci_platform_enable_resources (struct ahci_host_priv*) ; 
 struct ahci_host_priv* ahci_platform_get_resources (struct platform_device*,int /*<<< orphan*/ ) ; 
 int ahci_platform_init_host (struct platform_device*,struct ahci_host_priv*,struct ata_port_info const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ahci_platform_sht ; 
 struct ata_port_info const ahci_port_info ; 
 struct ata_port_info const ahci_port_seattle_info ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 struct ahci_host_priv* devm_ioremap_resource (struct device*,int /*<<< orphan*/ ) ; 
 struct seattle_plat_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int ioread32 (struct ahci_host_priv*) ; 
 int /*<<< orphan*/  iowrite32 (int,struct ahci_host_priv*) ; 
 int /*<<< orphan*/  platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static ssize_t seattle_transmit_led_message(struct ata_port *ap, u32 state,
					    ssize_t size)
{
	struct ahci_host_priv *hpriv = ap->host->private_data;
	struct ahci_port_priv *pp = ap->private_data;
	struct seattle_plat_data *plat_data = hpriv->plat_data;
	unsigned long flags;
	int pmp;
	struct ahci_em_priv *emp;
	u32 val;

	/* get the slot number from the message */
	pmp = (state & EM_MSG_LED_PMP_SLOT) >> 8;
	if (pmp >= EM_MAX_SLOTS)
		return -EINVAL;
	emp = &pp->em_priv[pmp];

	val = ioread32(plat_data->sgpio_ctrl);
	if (state & ACTIVITY_MASK)
		val |= 1 << ACTIVITY_BIT_POS((ap->port_no));
	else
		val &= ~(1 << ACTIVITY_BIT_POS((ap->port_no)));

	if (state & LOCATE_MASK)
		val |= 1 << LOCATE_BIT_POS((ap->port_no));
	else
		val &= ~(1 << LOCATE_BIT_POS((ap->port_no)));

	if (state & FAULT_MASK)
		val |= 1 << FAULT_BIT_POS((ap->port_no));
	else
		val &= ~(1 << FAULT_BIT_POS((ap->port_no)));

	iowrite32(val, plat_data->sgpio_ctrl);

	spin_lock_irqsave(ap->lock, flags);

	/* save off new led state for port/slot */
	emp->led_state = state;

	spin_unlock_irqrestore(ap->lock, flags);

	return size;
}

__attribute__((used)) static const struct ata_port_info *ahci_seattle_get_port_info(
		struct platform_device *pdev, struct ahci_host_priv *hpriv)
{
	struct device *dev = &pdev->dev;
	struct seattle_plat_data *plat_data;
	u32 val;

	plat_data = devm_kzalloc(dev, sizeof(*plat_data), GFP_KERNEL);
	if (!plat_data)
		return &ahci_port_info;

	plat_data->sgpio_ctrl = devm_ioremap_resource(dev,
			      platform_get_resource(pdev, IORESOURCE_MEM, 1));
	if (IS_ERR(plat_data->sgpio_ctrl))
		return &ahci_port_info;

	val = ioread32(plat_data->sgpio_ctrl);

	if (!(val & 0xf))
		return &ahci_port_info;

	hpriv->em_loc = 0;
	hpriv->em_buf_sz = 4;
	hpriv->em_msg_type = EM_MSG_TYPE_LED;
	hpriv->plat_data = plat_data;

	dev_info(dev, "SGPIO LED control is enabled.\n");
	return &ahci_port_seattle_info;
}

__attribute__((used)) static int ahci_seattle_probe(struct platform_device *pdev)
{
	int rc;
	struct ahci_host_priv *hpriv;

	hpriv = ahci_platform_get_resources(pdev, 0);
	if (IS_ERR(hpriv))
		return PTR_ERR(hpriv);

	rc = ahci_platform_enable_resources(hpriv);
	if (rc)
		return rc;

	rc = ahci_platform_init_host(pdev, hpriv,
				     ahci_seattle_get_port_info(pdev, hpriv),
				     &ahci_platform_sht);
	if (rc)
		goto disable_resources;

	return 0;
disable_resources:
	ahci_platform_disable_resources(hpriv);
	return rc;
}

