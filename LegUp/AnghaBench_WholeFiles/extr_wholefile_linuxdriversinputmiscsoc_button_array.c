#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int count; union acpi_object* elements; } ;
struct TYPE_6__ {int length; int /*<<< orphan*/  pointer; } ;
struct TYPE_5__ {int value; } ;
union acpi_object {scalar_t__ type; TYPE_3__ package; TYPE_2__ buffer; TYPE_1__ integer; } ;
struct device {TYPE_4__* driver; } ;
struct soc_button_info {char* name; int autorepeat; int acpi_index; int wakeup; int nbuttons; int rep; struct device dev; int /*<<< orphan*/  event_code; int /*<<< orphan*/  event_type; struct gpio_keys_button* buttons; } ;
struct soc_button_data {struct soc_button_info** children; } ;
struct platform_device {char* name; int autorepeat; int acpi_index; int wakeup; int nbuttons; int rep; struct device dev; int /*<<< orphan*/  event_code; int /*<<< orphan*/  event_type; struct gpio_keys_button* buttons; } ;
struct gpio_keys_platform_data {char* name; int autorepeat; int acpi_index; int wakeup; int nbuttons; int rep; struct device dev; int /*<<< orphan*/  event_code; int /*<<< orphan*/  event_type; struct gpio_keys_button* buttons; } ;
struct gpio_keys_button {int gpio; int active_low; char* desc; int wakeup; int debounce_interval; int /*<<< orphan*/  code; int /*<<< orphan*/  type; } ;
struct gpio_desc {char* name; int autorepeat; int acpi_index; int wakeup; int nbuttons; int rep; struct device dev; int /*<<< orphan*/  event_code; int /*<<< orphan*/  event_type; struct gpio_keys_button* buttons; } ;
struct acpi_device_id {scalar_t__ driver_data; } ;
struct acpi_buffer {union acpi_object* pointer; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  acpi_status ;
struct TYPE_8__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ALLOCATE_BUFFER ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 scalar_t__ ACPI_TYPE_BUFFER ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 scalar_t__ ACPI_TYPE_PACKAGE ; 
 int BUTTON_TYPES ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct soc_button_info* ERR_PTR (int) ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_ASIS ; 
 scalar_t__ IS_ERR (struct soc_button_info*) ; 
 int /*<<< orphan*/  KEY_LEFTMETA ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int /*<<< orphan*/  KEY_RESERVED ; 
 int /*<<< orphan*/  KEY_VOLUMEDOWN ; 
 int /*<<< orphan*/  KEY_VOLUMEUP ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (struct soc_button_info*) ; 
 int /*<<< orphan*/  acpi_evaluate_object_typed (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,struct acpi_buffer*,scalar_t__) ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  btns_desc_uuid ; 
 int desc_to_gpio (struct soc_button_info*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int,int,int) ; 
 struct soc_button_info* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_kfree (struct device*,struct soc_button_info*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_is_valid (int) ; 
 int gpiod_count (struct device*,int /*<<< orphan*/ *) ; 
 struct soc_button_info* gpiod_get_index (struct device*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_put (struct soc_button_info*) ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int platform_device_add (struct soc_button_info*) ; 
 int platform_device_add_data (struct soc_button_info*,struct soc_button_info*,int) ; 
 struct soc_button_info* platform_device_alloc (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_put (struct soc_button_info*) ; 
 int /*<<< orphan*/  platform_device_unregister (struct soc_button_info*) ; 
 struct soc_button_data* platform_get_drvdata (struct soc_button_info*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct soc_button_info*,struct soc_button_data*) ; 

__attribute__((used)) static int soc_button_lookup_gpio(struct device *dev, int acpi_index)
{
	struct gpio_desc *desc;
	int gpio;

	desc = gpiod_get_index(dev, NULL, acpi_index, GPIOD_ASIS);
	if (IS_ERR(desc))
		return PTR_ERR(desc);

	gpio = desc_to_gpio(desc);

	gpiod_put(desc);

	return gpio;
}

__attribute__((used)) static struct platform_device *
soc_button_device_create(struct platform_device *pdev,
			 const struct soc_button_info *button_info,
			 bool autorepeat)
{
	const struct soc_button_info *info;
	struct platform_device *pd;
	struct gpio_keys_button *gpio_keys;
	struct gpio_keys_platform_data *gpio_keys_pdata;
	int n_buttons = 0;
	int gpio;
	int error;

	for (info = button_info; info->name; info++)
		if (info->autorepeat == autorepeat)
			n_buttons++;

	gpio_keys_pdata = devm_kzalloc(&pdev->dev,
				       sizeof(*gpio_keys_pdata) +
					sizeof(*gpio_keys) * n_buttons,
				       GFP_KERNEL);
	if (!gpio_keys_pdata)
		return ERR_PTR(-ENOMEM);

	gpio_keys = (void *)(gpio_keys_pdata + 1);
	n_buttons = 0;

	for (info = button_info; info->name; info++) {
		if (info->autorepeat != autorepeat)
			continue;

		gpio = soc_button_lookup_gpio(&pdev->dev, info->acpi_index);
		if (!gpio_is_valid(gpio))
			continue;

		gpio_keys[n_buttons].type = info->event_type;
		gpio_keys[n_buttons].code = info->event_code;
		gpio_keys[n_buttons].gpio = gpio;
		gpio_keys[n_buttons].active_low = 1;
		gpio_keys[n_buttons].desc = info->name;
		gpio_keys[n_buttons].wakeup = info->wakeup;
		/* These devices often use cheap buttons, use 50 ms debounce */
		gpio_keys[n_buttons].debounce_interval = 50;
		n_buttons++;
	}

	if (n_buttons == 0) {
		error = -ENODEV;
		goto err_free_mem;
	}

	gpio_keys_pdata->buttons = gpio_keys;
	gpio_keys_pdata->nbuttons = n_buttons;
	gpio_keys_pdata->rep = autorepeat;

	pd = platform_device_alloc("gpio-keys", PLATFORM_DEVID_AUTO);
	if (!pd) {
		error = -ENOMEM;
		goto err_free_mem;
	}

	error = platform_device_add_data(pd, gpio_keys_pdata,
					 sizeof(*gpio_keys_pdata));
	if (error)
		goto err_free_pdev;

	error = platform_device_add(pd);
	if (error)
		goto err_free_pdev;

	return pd;

err_free_pdev:
	platform_device_put(pd);
err_free_mem:
	devm_kfree(&pdev->dev, gpio_keys_pdata);
	return ERR_PTR(error);
}

__attribute__((used)) static int soc_button_get_acpi_object_int(const union acpi_object *obj)
{
	if (obj->type != ACPI_TYPE_INTEGER)
		return -1;

	return obj->integer.value;
}

__attribute__((used)) static int soc_button_parse_btn_desc(struct device *dev,
				     const union acpi_object *desc,
				     int collection_uid,
				     struct soc_button_info *info)
{
	int upage, usage;

	if (desc->type != ACPI_TYPE_PACKAGE ||
	    desc->package.count != 5 ||
	    /* First byte should be 1 (control) */
	    soc_button_get_acpi_object_int(&desc->package.elements[0]) != 1 ||
	    /* Third byte should be collection uid */
	    soc_button_get_acpi_object_int(&desc->package.elements[2]) !=
							    collection_uid) {
		dev_err(dev, "Invalid ACPI Button Descriptor\n");
		return -ENODEV;
	}

	info->event_type = EV_KEY;
	info->acpi_index =
		soc_button_get_acpi_object_int(&desc->package.elements[1]);
	upage = soc_button_get_acpi_object_int(&desc->package.elements[3]);
	usage = soc_button_get_acpi_object_int(&desc->package.elements[4]);

	/*
	 * The UUID: fa6bd625-9ce8-470d-a2c7-b3ca36c4282e descriptors use HID
	 * usage page and usage codes, but otherwise the device is not HID
	 * compliant: it uses one irq per button instead of generating HID
	 * input reports and some buttons should generate wakeups where as
	 * others should not, so we cannot use the HID subsystem.
	 *
	 * Luckily all devices only use a few usage page + usage combinations,
	 * so we can simply check for the known combinations here.
	 */
	if (upage == 0x01 && usage == 0x81) {
		info->name = "power";
		info->event_code = KEY_POWER;
		info->wakeup = true;
	} else if (upage == 0x07 && usage == 0xe3) {
		info->name = "home";
		info->event_code = KEY_LEFTMETA;
		info->wakeup = true;
	} else if (upage == 0x0c && usage == 0xe9) {
		info->name = "volume_up";
		info->event_code = KEY_VOLUMEUP;
		info->autorepeat = true;
	} else if (upage == 0x0c && usage == 0xea) {
		info->name = "volume_down";
		info->event_code = KEY_VOLUMEDOWN;
		info->autorepeat = true;
	} else {
		dev_warn(dev, "Unknown button index %d upage %02x usage %02x, ignoring\n",
			 info->acpi_index, upage, usage);
		info->name = "unknown";
		info->event_code = KEY_RESERVED;
	}

	return 0;
}

__attribute__((used)) static struct soc_button_info *soc_button_get_button_info(struct device *dev)
{
	struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER };
	const union acpi_object *desc, *el0, *uuid, *btns_desc = NULL;
	struct soc_button_info *button_info;
	acpi_status status;
	int i, btn, collection_uid = -1;

	status = acpi_evaluate_object_typed(ACPI_HANDLE(dev), "_DSD", NULL,
					    &buf, ACPI_TYPE_PACKAGE);
	if (ACPI_FAILURE(status)) {
		dev_err(dev, "ACPI _DSD object not found\n");
		return ERR_PTR(-ENODEV);
	}

	/* Look for the Button Descriptors UUID */
	desc = buf.pointer;
	for (i = 0; (i + 1) < desc->package.count; i += 2) {
		uuid = &desc->package.elements[i];

		if (uuid->type != ACPI_TYPE_BUFFER ||
		    uuid->buffer.length != 16 ||
		    desc->package.elements[i + 1].type != ACPI_TYPE_PACKAGE) {
			break;
		}

		if (memcmp(uuid->buffer.pointer, btns_desc_uuid, 16) == 0) {
			btns_desc = &desc->package.elements[i + 1];
			break;
		}
	}

	if (!btns_desc) {
		dev_err(dev, "ACPI Button Descriptors not found\n");
		button_info = ERR_PTR(-ENODEV);
		goto out;
	}

	/* The first package describes the collection */
	el0 = &btns_desc->package.elements[0];
	if (el0->type == ACPI_TYPE_PACKAGE &&
	    el0->package.count == 5 &&
	    /* First byte should be 0 (collection) */
	    soc_button_get_acpi_object_int(&el0->package.elements[0]) == 0 &&
	    /* Third byte should be 0 (top level collection) */
	    soc_button_get_acpi_object_int(&el0->package.elements[2]) == 0) {
		collection_uid = soc_button_get_acpi_object_int(
						&el0->package.elements[1]);
	}
	if (collection_uid == -1) {
		dev_err(dev, "Invalid Button Collection Descriptor\n");
		button_info = ERR_PTR(-ENODEV);
		goto out;
	}

	/* There are package.count - 1 buttons + 1 terminating empty entry */
	button_info = devm_kcalloc(dev, btns_desc->package.count,
				   sizeof(*button_info), GFP_KERNEL);
	if (!button_info) {
		button_info = ERR_PTR(-ENOMEM);
		goto out;
	}

	/* Parse the button descriptors */
	for (i = 1, btn = 0; i < btns_desc->package.count; i++, btn++) {
		if (soc_button_parse_btn_desc(dev,
					      &btns_desc->package.elements[i],
					      collection_uid,
					      &button_info[btn])) {
			button_info = ERR_PTR(-ENODEV);
			goto out;
		}
	}

out:
	kfree(buf.pointer);
	return button_info;
}

__attribute__((used)) static int soc_button_remove(struct platform_device *pdev)
{
	struct soc_button_data *priv = platform_get_drvdata(pdev);

	int i;

	for (i = 0; i < BUTTON_TYPES; i++)
		if (priv->children[i])
			platform_device_unregister(priv->children[i]);

	return 0;
}

__attribute__((used)) static int soc_button_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct acpi_device_id *id;
	struct soc_button_info *button_info;
	struct soc_button_data *priv;
	struct platform_device *pd;
	int i;
	int error;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return -ENODEV;

	if (!id->driver_data) {
		button_info = soc_button_get_button_info(dev);
		if (IS_ERR(button_info))
			return PTR_ERR(button_info);
	} else {
		button_info = (struct soc_button_info *)id->driver_data;
	}

	error = gpiod_count(dev, NULL);
	if (error < 0) {
		dev_dbg(dev, "no GPIO attached, ignoring...\n");
		return -ENODEV;
	}

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv);

	for (i = 0; i < BUTTON_TYPES; i++) {
		pd = soc_button_device_create(pdev, button_info, i == 0);
		if (IS_ERR(pd)) {
			error = PTR_ERR(pd);
			if (error != -ENODEV) {
				soc_button_remove(pdev);
				return error;
			}
			continue;
		}

		priv->children[i] = pd;
	}

	if (!priv->children[0] && !priv->children[1])
		return -ENODEV;

	if (!id->driver_data)
		devm_kfree(dev, button_info);

	return 0;
}

