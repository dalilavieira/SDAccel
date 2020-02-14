#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct pci_dev {int /*<<< orphan*/  devfn; TYPE_1__* bus; } ;
struct notifier_block {int dummy; } ;
struct i2c_board_info {unsigned short const addr; int /*<<< orphan*/  member_0; } ;
struct i2c_peripheral {size_t type; scalar_t__ pci_devid; unsigned short alt_addr; struct i2c_client* client; struct i2c_board_info board_info; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  addr; } ;
struct TYPE_5__ {struct device* parent; } ;
struct i2c_adapter {TYPE_2__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  nr; } ;
struct device {int /*<<< orphan*/ * type; } ;
struct acpi_peripheral {int /*<<< orphan*/  properties; int /*<<< orphan*/  hid; } ;
struct acpi_device_id {int /*<<< orphan*/  id; } ;
struct TYPE_6__ {int num_i2c_peripherals; int num_acpi_peripherals; struct i2c_peripheral* i2c_peripherals; struct acpi_peripheral* acpi_peripherals; } ;
struct TYPE_4__ {int /*<<< orphan*/  number; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ID_LEN ; 
#define  BUS_NOTIFY_ADD_DEVICE 129 
#define  BUS_NOTIFY_REMOVED_DEVICE 128 
 int /*<<< orphan*/  I2C_BOARD_INFO (char*,unsigned short const) ; 
 unsigned short const I2C_CLIENT_END ; 
 scalar_t__ PCI_DEVID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ acpi_match_device (struct acpi_device_id*,int /*<<< orphan*/ *) ; 
 TYPE_3__* cros_laptop ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_is_pci (struct device*) ; 
 int device_add_properties (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  has_acpi_companion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * i2c_adapter_names ; 
 int /*<<< orphan*/  i2c_adapter_type ; 
 int /*<<< orphan*/  i2c_client_type ; 
 struct i2c_client* i2c_new_device (struct i2c_adapter*,struct i2c_board_info*) ; 
 struct i2c_client* i2c_new_probed_device (struct i2c_adapter*,struct i2c_board_info*,unsigned short const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,unsigned short const,...) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct i2c_adapter* to_i2c_adapter (struct device*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 

__attribute__((used)) static struct i2c_client *
chromes_laptop_instantiate_i2c_device(struct i2c_adapter *adapter,
				      struct i2c_board_info *info,
				      unsigned short alt_addr)
{
	const unsigned short addr_list[] = { info->addr, I2C_CLIENT_END };
	struct i2c_client *client;

	/*
	 * Add the i2c device. If we can't detect it at the primary
	 * address we scan secondary addresses. In any case the client
	 * structure gets assigned primary address.
	 */
	client = i2c_new_probed_device(adapter, info, addr_list, NULL);
	if (!client && alt_addr) {
		struct i2c_board_info dummy_info = {
			I2C_BOARD_INFO("dummy", info->addr),
		};
		const unsigned short alt_addr_list[] = {
			alt_addr, I2C_CLIENT_END
		};
		struct i2c_client *dummy;

		dummy = i2c_new_probed_device(adapter, &dummy_info,
					      alt_addr_list, NULL);
		if (dummy) {
			pr_debug("%d-%02x is probed at %02x\n",
				 adapter->nr, info->addr, dummy->addr);
			i2c_unregister_device(dummy);
			client = i2c_new_device(adapter, info);
		}
	}

	if (!client)
		pr_debug("failed to register device %d-%02x\n",
			 adapter->nr, info->addr);
	else
		pr_debug("added i2c device %d-%02x\n",
			 adapter->nr, info->addr);

	return client;
}

__attribute__((used)) static bool chromeos_laptop_match_adapter_devid(struct device *dev, u32 devid)
{
	struct pci_dev *pdev;

	if (!dev_is_pci(dev))
		return false;

	pdev = to_pci_dev(dev);
	return devid == PCI_DEVID(pdev->bus->number, pdev->devfn);
}

__attribute__((used)) static void chromeos_laptop_check_adapter(struct i2c_adapter *adapter)
{
	struct i2c_peripheral *i2c_dev;
	int i;

	for (i = 0; i < cros_laptop->num_i2c_peripherals; i++) {
		i2c_dev = &cros_laptop->i2c_peripherals[i];

		/* Skip devices already created */
		if (i2c_dev->client)
			continue;

		if (strncmp(adapter->name, i2c_adapter_names[i2c_dev->type],
			    strlen(i2c_adapter_names[i2c_dev->type])))
			continue;

		if (i2c_dev->pci_devid &&
		    !chromeos_laptop_match_adapter_devid(adapter->dev.parent,
							 i2c_dev->pci_devid)) {
			continue;
		}

		i2c_dev->client =
			chromes_laptop_instantiate_i2c_device(adapter,
							&i2c_dev->board_info,
							i2c_dev->alt_addr);
	}
}

__attribute__((used)) static bool chromeos_laptop_adjust_client(struct i2c_client *client)
{
	const struct acpi_peripheral *acpi_dev;
	struct acpi_device_id acpi_ids[2] = { };
	int i;
	int error;

	if (!has_acpi_companion(&client->dev))
		return false;

	for (i = 0; i < cros_laptop->num_acpi_peripherals; i++) {
		acpi_dev = &cros_laptop->acpi_peripherals[i];

		memcpy(acpi_ids[0].id, acpi_dev->hid, ACPI_ID_LEN);

		if (acpi_match_device(acpi_ids, &client->dev)) {
			error = device_add_properties(&client->dev,
						      acpi_dev->properties);
			if (error) {
				dev_err(&client->dev,
					"failed to add properties: %d\n",
					error);
				break;
			}

			return true;
		}
	}

	return false;
}

__attribute__((used)) static void chromeos_laptop_detach_i2c_client(struct i2c_client *client)
{
	struct i2c_peripheral *i2c_dev;
	int i;

	for (i = 0; i < cros_laptop->num_i2c_peripherals; i++) {
		i2c_dev = &cros_laptop->i2c_peripherals[i];

		if (i2c_dev->client == client)
			i2c_dev->client = NULL;
	}
}

__attribute__((used)) static int chromeos_laptop_i2c_notifier_call(struct notifier_block *nb,
					     unsigned long action, void *data)
{
	struct device *dev = data;

	switch (action) {
	case BUS_NOTIFY_ADD_DEVICE:
		if (dev->type == &i2c_adapter_type)
			chromeos_laptop_check_adapter(to_i2c_adapter(dev));
		else if (dev->type == &i2c_client_type)
			chromeos_laptop_adjust_client(to_i2c_client(dev));
		break;

	case BUS_NOTIFY_REMOVED_DEVICE:
		if (dev->type == &i2c_client_type)
			chromeos_laptop_detach_i2c_client(to_i2c_client(dev));
		break;
	}

	return 0;
}

