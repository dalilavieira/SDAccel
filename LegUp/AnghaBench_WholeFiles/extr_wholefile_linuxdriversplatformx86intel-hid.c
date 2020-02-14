#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int* pointer; } ;
struct TYPE_13__ {unsigned long long value; } ;
struct TYPE_12__ {int count; union acpi_object* elements; } ;
union acpi_object {TYPE_4__ buffer; TYPE_3__ integer; TYPE_2__ package; int /*<<< orphan*/  type; } ;
typedef  int u32 ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct intel_hid_priv {int wakeup_mode; TYPE_5__* array; TYPE_5__* input_dev; } ;
typedef  enum intel_hid_dsm_fn_codes { ____Placeholder_intel_hid_dsm_fn_codes } intel_hid_dsm_fn_codes ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_11__ {void* bustype; } ;
struct TYPE_15__ {char* name; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DEVICE_NOTIFY ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FREE (union acpi_object*) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_TYPE_BUFFER ; 
 int /*<<< orphan*/  ACPI_TYPE_INTEGER ; 
 int /*<<< orphan*/  ACPI_TYPE_PACKAGE ; 
 void* BUS_HOST ; 
 int EBUSY ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_EVENT_FILTER_UUID ; 
 int INTEL_HID_DSM_BTNE_FN ; 
 int INTEL_HID_DSM_BTNL_FN ; 
 int INTEL_HID_DSM_FN_INVALID ; 
 int INTEL_HID_DSM_FN_MAX ; 
 int INTEL_HID_DSM_HDEM_FN ; 
 int INTEL_HID_DSM_HDMM_FN ; 
 int INTEL_HID_DSM_HDSM_FN ; 
 int INTEL_HID_DSM_HEBC_V1_FN ; 
 int INTEL_HID_DSM_HEBC_V2_FN ; 
 int /*<<< orphan*/  KEY_POWER ; 
 union acpi_object* acpi_evaluate_dsm (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,union acpi_object*) ; 
 union acpi_object* acpi_evaluate_dsm_typed (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  acpi_execute_simple_method (int /*<<< orphan*/ ,char*,unsigned long long) ; 
 int /*<<< orphan*/  acpi_handle_debug (int /*<<< orphan*/ ,char*,int,...) ; 
 int /*<<< orphan*/  acpi_install_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*),struct platform_device*) ; 
 int /*<<< orphan*/  acpi_remove_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*)) ; 
 int /*<<< orphan*/  button_array_table ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned long long) ; 
 struct intel_hid_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct intel_hid_priv*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 void* devm_input_allocate_device (struct device*) ; 
 struct intel_hid_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ dmi_check_system (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  guid_parse (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int input_register_device (TYPE_5__*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_sync (TYPE_5__*) ; 
 int /*<<< orphan*/  intel_array_keymap ; 
 int /*<<< orphan*/  intel_dsm_guid ; 
 int intel_hid_dsm_fn_mask ; 
 scalar_t__* intel_hid_dsm_fn_to_method ; 
 int /*<<< orphan*/  intel_hid_keymap ; 
 scalar_t__ pm_resume_via_firmware () ; 
 scalar_t__ pm_suspend_via_firmware () ; 
 int /*<<< orphan*/  pm_wakeup_hard_event (struct device*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  sparse_keymap_entry_from_scancode (TYPE_5__*,int) ; 
 int /*<<< orphan*/  sparse_keymap_report_event (TYPE_5__*,unsigned long long,int,int) ; 
 int sparse_keymap_setup (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool intel_hid_execute_method(acpi_handle handle,
				     enum intel_hid_dsm_fn_codes fn_index,
				     unsigned long long arg)
{
	union acpi_object *obj, argv4, req;
	acpi_status status;
	char *method_name;

	if (fn_index <= INTEL_HID_DSM_FN_INVALID ||
	    fn_index >= INTEL_HID_DSM_FN_MAX)
		return false;

	method_name = (char *)intel_hid_dsm_fn_to_method[fn_index];

	if (!(intel_hid_dsm_fn_mask & fn_index))
		goto skip_dsm_exec;

	/* All methods expects a package with one integer element */
	req.type = ACPI_TYPE_INTEGER;
	req.integer.value = arg;

	argv4.type = ACPI_TYPE_PACKAGE;
	argv4.package.count = 1;
	argv4.package.elements = &req;

	obj = acpi_evaluate_dsm(handle, &intel_dsm_guid, 1, fn_index, &argv4);
	if (obj) {
		acpi_handle_debug(handle, "Exec DSM Fn code: %d[%s] success\n",
				  fn_index, method_name);
		ACPI_FREE(obj);
		return true;
	}

skip_dsm_exec:
	status = acpi_execute_simple_method(handle, method_name, arg);
	if (ACPI_SUCCESS(status))
		return true;

	return false;
}

__attribute__((used)) static bool intel_hid_evaluate_method(acpi_handle handle,
				      enum intel_hid_dsm_fn_codes fn_index,
				      unsigned long long *result)
{
	union acpi_object *obj;
	acpi_status status;
	char *method_name;

	if (fn_index <= INTEL_HID_DSM_FN_INVALID ||
	    fn_index >= INTEL_HID_DSM_FN_MAX)
		return false;

	method_name = (char *)intel_hid_dsm_fn_to_method[fn_index];

	if (!(intel_hid_dsm_fn_mask & fn_index))
		goto skip_dsm_eval;

	obj = acpi_evaluate_dsm_typed(handle, &intel_dsm_guid,
				      1, fn_index,
				      NULL,  ACPI_TYPE_INTEGER);
	if (obj) {
		*result = obj->integer.value;
		acpi_handle_debug(handle,
				  "Eval DSM Fn code: %d[%s] results: 0x%llx\n",
				  fn_index, method_name, *result);
		ACPI_FREE(obj);
		return true;
	}

skip_dsm_eval:
	status = acpi_evaluate_integer(handle, method_name, NULL, result);
	if (ACPI_SUCCESS(status))
		return true;

	return false;
}

__attribute__((used)) static void intel_hid_init_dsm(acpi_handle handle)
{
	union acpi_object *obj;

	guid_parse(HID_EVENT_FILTER_UUID, &intel_dsm_guid);

	obj = acpi_evaluate_dsm_typed(handle, &intel_dsm_guid, 1, 0, NULL,
				      ACPI_TYPE_BUFFER);
	if (obj) {
		intel_hid_dsm_fn_mask = *obj->buffer.pointer;
		ACPI_FREE(obj);
	}

	acpi_handle_debug(handle, "intel_hid_dsm_fn_mask = %llx\n",
			  intel_hid_dsm_fn_mask);
}

__attribute__((used)) static int intel_hid_set_enable(struct device *device, bool enable)
{
	acpi_handle handle = ACPI_HANDLE(device);

	/* Enable|disable features - power button is always enabled */
	if (!intel_hid_execute_method(handle, INTEL_HID_DSM_HDSM_FN,
				      enable)) {
		dev_warn(device, "failed to %sable hotkeys\n",
			 enable ? "en" : "dis");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static void intel_button_array_enable(struct device *device, bool enable)
{
	struct intel_hid_priv *priv = dev_get_drvdata(device);
	acpi_handle handle = ACPI_HANDLE(device);
	unsigned long long button_cap;
	acpi_status status;

	if (!priv->array)
		return;

	/* Query supported platform features */
	status = acpi_evaluate_integer(handle, "BTNC", NULL, &button_cap);
	if (ACPI_FAILURE(status)) {
		dev_warn(device, "failed to get button capability\n");
		return;
	}

	/* Enable|disable features - power button is always enabled */
	if (!intel_hid_execute_method(handle, INTEL_HID_DSM_BTNE_FN,
				      enable ? button_cap : 1))
		dev_warn(device, "failed to set button capability\n");
}

__attribute__((used)) static int intel_hid_pm_prepare(struct device *device)
{
	struct intel_hid_priv *priv = dev_get_drvdata(device);

	priv->wakeup_mode = true;
	return 0;
}

__attribute__((used)) static int intel_hid_pl_suspend_handler(struct device *device)
{
	if (pm_suspend_via_firmware()) {
		intel_hid_set_enable(device, false);
		intel_button_array_enable(device, false);
	}
	return 0;
}

__attribute__((used)) static int intel_hid_pl_resume_handler(struct device *device)
{
	struct intel_hid_priv *priv = dev_get_drvdata(device);

	priv->wakeup_mode = false;
	if (pm_resume_via_firmware()) {
		intel_hid_set_enable(device, true);
		intel_button_array_enable(device, true);
	}
	return 0;
}

__attribute__((used)) static int intel_hid_input_setup(struct platform_device *device)
{
	struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
	int ret;

	priv->input_dev = devm_input_allocate_device(&device->dev);
	if (!priv->input_dev)
		return -ENOMEM;

	ret = sparse_keymap_setup(priv->input_dev, intel_hid_keymap, NULL);
	if (ret)
		return ret;

	priv->input_dev->name = "Intel HID events";
	priv->input_dev->id.bustype = BUS_HOST;

	return input_register_device(priv->input_dev);
}

__attribute__((used)) static int intel_button_array_input_setup(struct platform_device *device)
{
	struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
	int ret;

	/* Setup input device for 5 button array */
	priv->array = devm_input_allocate_device(&device->dev);
	if (!priv->array)
		return -ENOMEM;

	ret = sparse_keymap_setup(priv->array, intel_array_keymap, NULL);
	if (ret)
		return ret;

	priv->array->name = "Intel HID 5 button array";
	priv->array->id.bustype = BUS_HOST;

	return input_register_device(priv->array);
}

__attribute__((used)) static void notify_handler(acpi_handle handle, u32 event, void *context)
{
	struct platform_device *device = context;
	struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
	unsigned long long ev_index;

	if (priv->wakeup_mode) {
		/*
		 * Needed for wakeup from suspend-to-idle to work on some
		 * platforms that don't expose the 5-button array, but still
		 * send notifies with the power button event code to this
		 * device object on power button actions while suspended.
		 */
		if (event == 0xce)
			goto wakeup;

		/* Wake up on 5-button array events only. */
		if (event == 0xc0 || !priv->array)
			return;

		if (!sparse_keymap_entry_from_scancode(priv->array, event)) {
			dev_info(&device->dev, "unknown event 0x%x\n", event);
			return;
		}

wakeup:
		pm_wakeup_hard_event(&device->dev);
		return;
	}

	/*
	 * Needed for suspend to work on some platforms that don't expose
	 * the 5-button array, but still send notifies with power button
	 * event code to this device object on power button actions.
	 *
	 * Report the power button press and release.
	 */
	if (!priv->array) {
		if (event == 0xce) {
			input_report_key(priv->input_dev, KEY_POWER, 1);
			input_sync(priv->input_dev);
			return;
		}

		if (event == 0xcf) {
			input_report_key(priv->input_dev, KEY_POWER, 0);
			input_sync(priv->input_dev);
			return;
		}
	}

	/* 0xC0 is for HID events, other values are for 5 button array */
	if (event != 0xc0) {
		if (!priv->array ||
		    !sparse_keymap_report_event(priv->array, event, 1, true))
			dev_dbg(&device->dev, "unknown event 0x%x\n", event);
		return;
	}

	if (!intel_hid_evaluate_method(handle, INTEL_HID_DSM_HDEM_FN,
				       &ev_index)) {
		dev_warn(&device->dev, "failed to get event index\n");
		return;
	}

	if (!sparse_keymap_report_event(priv->input_dev, ev_index, 1, true))
		dev_dbg(&device->dev, "unknown event index 0x%llx\n",
			 ev_index);
}

__attribute__((used)) static bool button_array_present(struct platform_device *device)
{
	acpi_handle handle = ACPI_HANDLE(&device->dev);
	unsigned long long event_cap;

	if (intel_hid_evaluate_method(handle, INTEL_HID_DSM_HEBC_V2_FN,
				      &event_cap)) {
		/* Check presence of 5 button array or v2 power button */
		if (event_cap & 0x60000)
			return true;
	}

	if (intel_hid_evaluate_method(handle, INTEL_HID_DSM_HEBC_V1_FN,
				      &event_cap)) {
		if (event_cap & 0x20000)
			return true;
	}

	if (dmi_check_system(button_array_table))
		return true;

	return false;
}

__attribute__((used)) static int intel_hid_probe(struct platform_device *device)
{
	acpi_handle handle = ACPI_HANDLE(&device->dev);
	unsigned long long mode;
	struct intel_hid_priv *priv;
	acpi_status status;
	int err;

	intel_hid_init_dsm(handle);

	if (!intel_hid_evaluate_method(handle, INTEL_HID_DSM_HDMM_FN, &mode)) {
		dev_warn(&device->dev, "failed to read mode\n");
		return -ENODEV;
	}

	if (mode != 0) {
		/*
		 * This driver only implements "simple" mode.  There appear
		 * to be no other modes, but we should be paranoid and check
		 * for compatibility.
		 */
		dev_info(&device->dev, "platform is not in simple mode\n");
		return -ENODEV;
	}

	priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	dev_set_drvdata(&device->dev, priv);

	err = intel_hid_input_setup(device);
	if (err) {
		pr_err("Failed to setup Intel HID hotkeys\n");
		return err;
	}

	/* Setup 5 button array */
	if (button_array_present(device)) {
		dev_info(&device->dev, "platform supports 5 button array\n");
		err = intel_button_array_input_setup(device);
		if (err)
			pr_err("Failed to setup Intel 5 button array hotkeys\n");
	}

	status = acpi_install_notify_handler(handle,
					     ACPI_DEVICE_NOTIFY,
					     notify_handler,
					     device);
	if (ACPI_FAILURE(status))
		return -EBUSY;

	err = intel_hid_set_enable(&device->dev, true);
	if (err)
		goto err_remove_notify;

	if (priv->array) {
		unsigned long long dummy;

		intel_button_array_enable(&device->dev, true);

		/* Call button load method to enable HID power button */
		if (!intel_hid_evaluate_method(handle, INTEL_HID_DSM_BTNL_FN,
					       &dummy)) {
			dev_warn(&device->dev,
				 "failed to enable HID power button\n");
		}
	}

	device_init_wakeup(&device->dev, true);
	return 0;

err_remove_notify:
	acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);

	return err;
}

__attribute__((used)) static int intel_hid_remove(struct platform_device *device)
{
	acpi_handle handle = ACPI_HANDLE(&device->dev);

	device_init_wakeup(&device->dev, false);
	acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
	intel_hid_set_enable(&device->dev, false);
	intel_button_array_enable(&device->dev, false);

	/*
	 * Even if we failed to shut off the event stream, we can still
	 * safely detach from the device.
	 */
	return 0;
}

