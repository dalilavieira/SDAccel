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
typedef  scalar_t__ u8 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct dmi_system_id {int /*<<< orphan*/  driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  A1655_WIFI_COMMAND ; 
 scalar_t__ A1655_WIFI_OFF ; 
 scalar_t__ A1655_WIFI_ON ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/  M7440_PORT1 ; 
 int /*<<< orphan*/  M7440_PORT2 ; 
 scalar_t__ M7440_RADIO_OFF1 ; 
 scalar_t__ M7440_RADIO_OFF2 ; 
 scalar_t__ M7440_RADIO_ON1 ; 
 scalar_t__ M7440_RADIO_ON2 ; 
 int /*<<< orphan*/  RFKILL_TYPE_WLAN ; 
 int /*<<< orphan*/  amilo_rfkill_dev ; 
 int /*<<< orphan*/  amilo_rfkill_id_table ; 
 struct dmi_system_id* dmi_first_match (int /*<<< orphan*/ ) ; 
 int i8042_command (scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i8042_lock_chip () ; 
 int /*<<< orphan*/  i8042_unlock_chip () ; 
 scalar_t__ inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rfkill_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rfkill_destroy (int /*<<< orphan*/ ) ; 
 int rfkill_register (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rfkill_unregister (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int amilo_a1655_rfkill_set_block(void *data, bool blocked)
{
	u8 param = blocked ? A1655_WIFI_OFF : A1655_WIFI_ON;
	int rc;

	i8042_lock_chip();
	rc = i8042_command(&param, A1655_WIFI_COMMAND);
	i8042_unlock_chip();
	return rc;
}

__attribute__((used)) static int amilo_m7440_rfkill_set_block(void *data, bool blocked)
{
	u8 val1 = blocked ? M7440_RADIO_OFF1 : M7440_RADIO_ON1;
	u8 val2 = blocked ? M7440_RADIO_OFF2 : M7440_RADIO_ON2;

	outb(val1, M7440_PORT1);
	outb(val2, M7440_PORT2);

	/* Check whether the state has changed correctly */
	if (inb(M7440_PORT1) != val1 || inb(M7440_PORT2) != val2)
		return -EIO;

	return 0;
}

__attribute__((used)) static int amilo_rfkill_probe(struct platform_device *device)
{
	int rc;
	const struct dmi_system_id *system_id =
		dmi_first_match(amilo_rfkill_id_table);

	if (!system_id)
		return -ENXIO;

	amilo_rfkill_dev = rfkill_alloc(KBUILD_MODNAME, &device->dev,
					RFKILL_TYPE_WLAN,
					system_id->driver_data, NULL);
	if (!amilo_rfkill_dev)
		return -ENOMEM;

	rc = rfkill_register(amilo_rfkill_dev);
	if (rc)
		goto fail;

	return 0;

fail:
	rfkill_destroy(amilo_rfkill_dev);
	return rc;
}

__attribute__((used)) static int amilo_rfkill_remove(struct platform_device *device)
{
	rfkill_unregister(amilo_rfkill_dev);
	rfkill_destroy(amilo_rfkill_dev);
	return 0;
}

