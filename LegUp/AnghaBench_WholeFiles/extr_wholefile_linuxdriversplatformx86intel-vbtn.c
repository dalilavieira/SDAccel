#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int value; } ;
union acpi_object {scalar_t__ type; TYPE_3__ integer; } ;
typedef  int u32 ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct key_entry {scalar_t__ type; } ;
struct intel_vbtn_priv {int wakeup_mode; TYPE_4__* input_dev; } ;
struct acpi_buffer {union acpi_object* pointer; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_11__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_10__ {struct device* parent; } ;
struct TYPE_13__ {char* name; TYPE_2__ id; TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ALLOCATE_BUFFER ; 
 int /*<<< orphan*/  ACPI_DEVICE_NOTIFY ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int /*<<< orphan*/  DMI_CHASSIS_TYPE ; 
 int DOCK_MODE_FLAG ; 
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ KE_IGNORE ; 
 int /*<<< orphan*/  SW_DOCK ; 
 int /*<<< orphan*/  SW_TABLET_MODE ; 
 int TABLET_MODE_FLAG ; 
 int /*<<< orphan*/  acpi_evaluate_object (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,struct acpi_buffer*) ; 
 int /*<<< orphan*/  acpi_install_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*),struct platform_device*) ; 
 int /*<<< orphan*/  acpi_remove_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*)) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 struct intel_vbtn_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct intel_vbtn_priv*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 TYPE_4__* devm_input_allocate_device (struct device*) ; 
 struct intel_vbtn_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 char* dmi_get_system_info (int /*<<< orphan*/ ) ; 
 int input_register_device (TYPE_4__*) ; 
 int /*<<< orphan*/  input_report_switch (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  intel_vbtn_keymap ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 int /*<<< orphan*/  pm_wakeup_hard_event (struct device*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 struct key_entry* sparse_keymap_entry_from_scancode (TYPE_4__*,int) ; 
 scalar_t__ sparse_keymap_report_event (TYPE_4__*,int,unsigned int,int) ; 
 int sparse_keymap_setup (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int intel_vbtn_input_setup(struct platform_device *device)
{
	struct intel_vbtn_priv *priv = dev_get_drvdata(&device->dev);
	int ret;

	priv->input_dev = devm_input_allocate_device(&device->dev);
	if (!priv->input_dev)
		return -ENOMEM;

	ret = sparse_keymap_setup(priv->input_dev, intel_vbtn_keymap, NULL);
	if (ret)
		return ret;

	priv->input_dev->dev.parent = &device->dev;
	priv->input_dev->name = "Intel Virtual Button driver";
	priv->input_dev->id.bustype = BUS_HOST;

	return input_register_device(priv->input_dev);
}

__attribute__((used)) static void notify_handler(acpi_handle handle, u32 event, void *context)
{
	struct platform_device *device = context;
	struct intel_vbtn_priv *priv = dev_get_drvdata(&device->dev);
	unsigned int val = !(event & 1); /* Even=press, Odd=release */
	const struct key_entry *ke_rel;
	bool autorelease;

	if (priv->wakeup_mode) {
		if (sparse_keymap_entry_from_scancode(priv->input_dev, event)) {
			pm_wakeup_hard_event(&device->dev);
			return;
		}
		goto out_unknown;
	}

	/*
	 * Even press events are autorelease if there is no corresponding odd
	 * release event, or if the odd event is KE_IGNORE.
	 */
	ke_rel = sparse_keymap_entry_from_scancode(priv->input_dev, event | 1);
	autorelease = val && (!ke_rel || ke_rel->type == KE_IGNORE);

	if (sparse_keymap_report_event(priv->input_dev, event, val, autorelease))
		return;

out_unknown:
	dev_dbg(&device->dev, "unknown event index 0x%x\n", event);
}

__attribute__((used)) static void detect_tablet_mode(struct platform_device *device)
{
	const char *chassis_type = dmi_get_system_info(DMI_CHASSIS_TYPE);
	struct intel_vbtn_priv *priv = dev_get_drvdata(&device->dev);
	acpi_handle handle = ACPI_HANDLE(&device->dev);
	struct acpi_buffer vgbs_output = { ACPI_ALLOCATE_BUFFER, NULL };
	union acpi_object *obj;
	acpi_status status;
	int m;

	if (!(chassis_type && strcmp(chassis_type, "31") == 0))
		goto out;

	status = acpi_evaluate_object(handle, "VGBS", NULL, &vgbs_output);
	if (ACPI_FAILURE(status))
		goto out;

	obj = vgbs_output.pointer;
	if (!(obj && obj->type == ACPI_TYPE_INTEGER))
		goto out;

	m = !(obj->integer.value & TABLET_MODE_FLAG);
	input_report_switch(priv->input_dev, SW_TABLET_MODE, m);
	m = (obj->integer.value & DOCK_MODE_FLAG) ? 1 : 0;
	input_report_switch(priv->input_dev, SW_DOCK, m);
out:
	kfree(vgbs_output.pointer);
}

__attribute__((used)) static int intel_vbtn_probe(struct platform_device *device)
{
	acpi_handle handle = ACPI_HANDLE(&device->dev);
	struct intel_vbtn_priv *priv;
	acpi_status status;
	int err;

	status = acpi_evaluate_object(handle, "VBDL", NULL, NULL);
	if (ACPI_FAILURE(status)) {
		dev_warn(&device->dev, "failed to read Intel Virtual Button driver\n");
		return -ENODEV;
	}

	priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	dev_set_drvdata(&device->dev, priv);

	err = intel_vbtn_input_setup(device);
	if (err) {
		pr_err("Failed to setup Intel Virtual Button\n");
		return err;
	}

	detect_tablet_mode(device);

	status = acpi_install_notify_handler(handle,
					     ACPI_DEVICE_NOTIFY,
					     notify_handler,
					     device);
	if (ACPI_FAILURE(status))
		return -EBUSY;

	device_init_wakeup(&device->dev, true);
	return 0;
}

__attribute__((used)) static int intel_vbtn_remove(struct platform_device *device)
{
	acpi_handle handle = ACPI_HANDLE(&device->dev);

	device_init_wakeup(&device->dev, false);
	acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);

	/*
	 * Even if we failed to shut off the event stream, we can still
	 * safely detach from the device.
	 */
	return 0;
}

__attribute__((used)) static int intel_vbtn_pm_prepare(struct device *dev)
{
	struct intel_vbtn_priv *priv = dev_get_drvdata(dev);

	priv->wakeup_mode = true;
	return 0;
}

__attribute__((used)) static int intel_vbtn_pm_resume(struct device *dev)
{
	struct intel_vbtn_priv *priv = dev_get_drvdata(dev);

	priv->wakeup_mode = false;
	return 0;
}

