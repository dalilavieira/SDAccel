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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct platform_device {struct device dev; } ;
struct mfd_cell {int dummy; } ;
struct kempld_platform_data {int (* get_info ) (struct kempld_device_data*) ;int (* register_cells ) (struct kempld_device_data*) ;int /*<<< orphan*/  (* release_hardware_mutex ) (struct kempld_device_data*) ;int /*<<< orphan*/  pld_clock; int /*<<< orphan*/  (* get_hardware_mutex ) (struct kempld_device_data*) ;int /*<<< orphan*/  ioresource; } ;
struct TYPE_2__ {int buildnr; int minor; int major; int type; int spec_major; char const* version; scalar_t__ spec_minor; int /*<<< orphan*/  number; } ;
struct kempld_device_data {int feature_mask; struct device* dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  pld_clock; scalar_t__ io_base; scalar_t__ io_data; scalar_t__ io_index; TYPE_1__ info; } ;
struct dmi_system_id {struct kempld_platform_data* driver_data; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int KEMPLD_BUILDNR ; 
 int KEMPLD_FEATURE ; 
 int KEMPLD_FEATURE_BIT_GPIO ; 
 int KEMPLD_FEATURE_BIT_I2C ; 
 int KEMPLD_FEATURE_BIT_WATCHDOG ; 
 int KEMPLD_FEATURE_MASK_UART ; 
 size_t KEMPLD_GPIO ; 
 size_t KEMPLD_I2C ; 
 int KEMPLD_MAX_DEVS ; 
 int KEMPLD_MUTEX_KEY ; 
 int KEMPLD_SPEC ; 
 int KEMPLD_SPEC_GET_MAJOR (int) ; 
 scalar_t__ KEMPLD_SPEC_GET_MINOR (int) ; 
 size_t KEMPLD_UART ; 
 int KEMPLD_VERSION ; 
 int KEMPLD_VERSION_GET_MAJOR (int) ; 
 int KEMPLD_VERSION_GET_MINOR (int) ; 
 int /*<<< orphan*/  KEMPLD_VERSION_GET_NUMBER (int) ; 
 int KEMPLD_VERSION_GET_TYPE (int) ; 
 size_t KEMPLD_WDT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct kempld_device_data* dev_get_drvdata (struct device*) ; 
 struct kempld_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,char const*,char const*,int,scalar_t__) ; 
 scalar_t__ devm_ioport_map (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct kempld_device_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (int,scalar_t__) ; 
 struct mfd_cell* kempld_devs ; 
 void kempld_get_mutex (struct kempld_device_data*) ; 
 int /*<<< orphan*/  kempld_pdev ; 
 int kempld_read16 (struct kempld_device_data*,int) ; 
 int kempld_read8 (struct kempld_device_data*,int) ; 
 void kempld_release_mutex (struct kempld_device_data*) ; 
 int mfd_add_devices (struct device*,int,struct mfd_cell*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int platform_device_add (int /*<<< orphan*/ ) ; 
 int platform_device_add_data (int /*<<< orphan*/ ,struct kempld_platform_data const*,int) ; 
 int platform_device_add_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_put (int /*<<< orphan*/ ) ; 
 struct kempld_device_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct kempld_device_data*) ; 
 int /*<<< orphan*/  pld_attr_group ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int scnprintf (char const*,int,char*,...) ; 
 int /*<<< orphan*/  stub1 (struct kempld_device_data*) ; 
 int /*<<< orphan*/  stub2 (struct kempld_device_data*) ; 
 int stub3 (struct kempld_device_data*) ; 
 int stub4 (struct kempld_device_data*) ; 
 int /*<<< orphan*/  stub5 (struct kempld_device_data*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void kempld_get_hardware_mutex(struct kempld_device_data *pld)
{
	/* The mutex bit will read 1 until access has been granted */
	while (ioread8(pld->io_index) & KEMPLD_MUTEX_KEY)
		usleep_range(1000, 3000);
}

__attribute__((used)) static void kempld_release_hardware_mutex(struct kempld_device_data *pld)
{
	/* The harware mutex is released when 1 is written to the mutex bit. */
	iowrite8(KEMPLD_MUTEX_KEY, pld->io_index);
}

__attribute__((used)) static int kempld_get_info_generic(struct kempld_device_data *pld)
{
	u16 version;
	u8 spec;

	kempld_get_mutex(pld);

	version = kempld_read16(pld, KEMPLD_VERSION);
	spec = kempld_read8(pld, KEMPLD_SPEC);
	pld->info.buildnr = kempld_read16(pld, KEMPLD_BUILDNR);

	pld->info.minor = KEMPLD_VERSION_GET_MINOR(version);
	pld->info.major = KEMPLD_VERSION_GET_MAJOR(version);
	pld->info.number = KEMPLD_VERSION_GET_NUMBER(version);
	pld->info.type = KEMPLD_VERSION_GET_TYPE(version);

	if (spec == 0xff) {
		pld->info.spec_minor = 0;
		pld->info.spec_major = 1;
	} else {
		pld->info.spec_minor = KEMPLD_SPEC_GET_MINOR(spec);
		pld->info.spec_major = KEMPLD_SPEC_GET_MAJOR(spec);
	}

	if (pld->info.spec_major > 0)
		pld->feature_mask = kempld_read16(pld, KEMPLD_FEATURE);
	else
		pld->feature_mask = 0;

	kempld_release_mutex(pld);

	return 0;
}

__attribute__((used)) static int kempld_register_cells_generic(struct kempld_device_data *pld)
{
	struct mfd_cell devs[KEMPLD_MAX_DEVS];
	int i = 0;

	if (pld->feature_mask & KEMPLD_FEATURE_BIT_I2C)
		devs[i++] = kempld_devs[KEMPLD_I2C];

	if (pld->feature_mask & KEMPLD_FEATURE_BIT_WATCHDOG)
		devs[i++] = kempld_devs[KEMPLD_WDT];

	if (pld->feature_mask & KEMPLD_FEATURE_BIT_GPIO)
		devs[i++] = kempld_devs[KEMPLD_GPIO];

	if (pld->feature_mask & KEMPLD_FEATURE_MASK_UART)
		devs[i++] = kempld_devs[KEMPLD_UART];

	return mfd_add_devices(pld->dev, -1, devs, i, NULL, 0, NULL);
}

__attribute__((used)) static int kempld_create_platform_device(const struct dmi_system_id *id)
{
	const struct kempld_platform_data *pdata = id->driver_data;
	int ret;

	kempld_pdev = platform_device_alloc("kempld", -1);
	if (!kempld_pdev)
		return -ENOMEM;

	ret = platform_device_add_data(kempld_pdev, pdata, sizeof(*pdata));
	if (ret)
		goto err;

	ret = platform_device_add_resources(kempld_pdev, pdata->ioresource, 1);
	if (ret)
		goto err;

	ret = platform_device_add(kempld_pdev);
	if (ret)
		goto err;

	return 0;
err:
	platform_device_put(kempld_pdev);
	return ret;
}

u8 kempld_read8(struct kempld_device_data *pld, u8 index)
{
	iowrite8(index, pld->io_index);
	return ioread8(pld->io_data);
}

void kempld_write8(struct kempld_device_data *pld, u8 index, u8 data)
{
	iowrite8(index, pld->io_index);
	iowrite8(data, pld->io_data);
}

u16 kempld_read16(struct kempld_device_data *pld, u8 index)
{
	return kempld_read8(pld, index) | kempld_read8(pld, index + 1) << 8;
}

void kempld_write16(struct kempld_device_data *pld, u8 index, u16 data)
{
	kempld_write8(pld, index, (u8)data);
	kempld_write8(pld, index + 1, (u8)(data >> 8));
}

u32 kempld_read32(struct kempld_device_data *pld, u8 index)
{
	return kempld_read16(pld, index) | kempld_read16(pld, index + 2) << 16;
}

void kempld_write32(struct kempld_device_data *pld, u8 index, u32 data)
{
	kempld_write16(pld, index, (u16)data);
	kempld_write16(pld, index + 2, (u16)(data >> 16));
}

void kempld_get_mutex(struct kempld_device_data *pld)
{
	const struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);

	mutex_lock(&pld->lock);
	pdata->get_hardware_mutex(pld);
}

void kempld_release_mutex(struct kempld_device_data *pld)
{
	const struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);

	pdata->release_hardware_mutex(pld);
	mutex_unlock(&pld->lock);
}

__attribute__((used)) static int kempld_get_info(struct kempld_device_data *pld)
{
	int ret;
	const struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
	char major, minor;

	ret = pdata->get_info(pld);
	if (ret)
		return ret;

	/* The Kontron PLD firmware version string has the following format:
	 * Pwxy.zzzz
	 *   P:    Fixed
	 *   w:    PLD number    - 1 hex digit
	 *   x:    Major version - 1 alphanumerical digit (0-9A-V)
	 *   y:    Minor version - 1 alphanumerical digit (0-9A-V)
	 *   zzzz: Build number  - 4 zero padded hex digits */

	if (pld->info.major < 10)
		major = pld->info.major + '0';
	else
		major = (pld->info.major - 10) + 'A';
	if (pld->info.minor < 10)
		minor = pld->info.minor + '0';
	else
		minor = (pld->info.minor - 10) + 'A';

	ret = scnprintf(pld->info.version, sizeof(pld->info.version),
			"P%X%c%c.%04X", pld->info.number, major, minor,
			pld->info.buildnr);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int kempld_register_cells(struct kempld_device_data *pld)
{
	const struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);

	return pdata->register_cells(pld);
}

__attribute__((used)) static const char *kempld_get_type_string(struct kempld_device_data *pld)
{
	const char *version_type;

	switch (pld->info.type) {
	case 0:
		version_type = "release";
		break;
	case 1:
		version_type = "debug";
		break;
	case 2:
		version_type = "custom";
		break;
	default:
		version_type = "unspecified";
		break;
	}

	return version_type;
}

__attribute__((used)) static ssize_t kempld_version_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct kempld_device_data *pld = dev_get_drvdata(dev);

	return scnprintf(buf, PAGE_SIZE, "%s\n", pld->info.version);
}

__attribute__((used)) static ssize_t kempld_specification_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct kempld_device_data *pld = dev_get_drvdata(dev);

	return scnprintf(buf, PAGE_SIZE, "%d.%d\n", pld->info.spec_major,
		       pld->info.spec_minor);
}

__attribute__((used)) static ssize_t kempld_type_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct kempld_device_data *pld = dev_get_drvdata(dev);

	return scnprintf(buf, PAGE_SIZE, "%s\n", kempld_get_type_string(pld));
}

__attribute__((used)) static int kempld_detect_device(struct kempld_device_data *pld)
{
	u8 index_reg;
	int ret;

	mutex_lock(&pld->lock);

	/* Check for empty IO space */
	index_reg = ioread8(pld->io_index);
	if (index_reg == 0xff && ioread8(pld->io_data) == 0xff) {
		mutex_unlock(&pld->lock);
		return -ENODEV;
	}

	/* Release hardware mutex if acquired */
	if (!(index_reg & KEMPLD_MUTEX_KEY)) {
		iowrite8(KEMPLD_MUTEX_KEY, pld->io_index);
		/* PXT and COMe-cPC2 boards may require a second release */
		iowrite8(KEMPLD_MUTEX_KEY, pld->io_index);
	}

	mutex_unlock(&pld->lock);

	ret = kempld_get_info(pld);
	if (ret)
		return ret;

	dev_info(pld->dev, "Found Kontron PLD - %s (%s), spec %d.%d\n",
		 pld->info.version, kempld_get_type_string(pld),
		 pld->info.spec_major, pld->info.spec_minor);

	ret = sysfs_create_group(&pld->dev->kobj, &pld_attr_group);
	if (ret)
		return ret;

	ret = kempld_register_cells(pld);
	if (ret)
		sysfs_remove_group(&pld->dev->kobj, &pld_attr_group);

	return ret;
}

__attribute__((used)) static int kempld_probe(struct platform_device *pdev)
{
	const struct kempld_platform_data *pdata =
		dev_get_platdata(&pdev->dev);
	struct device *dev = &pdev->dev;
	struct kempld_device_data *pld;
	struct resource *ioport;

	pld = devm_kzalloc(dev, sizeof(*pld), GFP_KERNEL);
	if (!pld)
		return -ENOMEM;

	ioport = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!ioport)
		return -EINVAL;

	pld->io_base = devm_ioport_map(dev, ioport->start,
					resource_size(ioport));
	if (!pld->io_base)
		return -ENOMEM;

	pld->io_index = pld->io_base;
	pld->io_data = pld->io_base + 1;
	pld->pld_clock = pdata->pld_clock;
	pld->dev = dev;

	mutex_init(&pld->lock);
	platform_set_drvdata(pdev, pld);

	return kempld_detect_device(pld);
}

__attribute__((used)) static int kempld_remove(struct platform_device *pdev)
{
	struct kempld_device_data *pld = platform_get_drvdata(pdev);
	const struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);

	sysfs_remove_group(&pld->dev->kobj, &pld_attr_group);

	mfd_remove_devices(&pdev->dev);
	pdata->release_hardware_mutex(pld);

	return 0;
}

