#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_7__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct device {int /*<<< orphan*/  kobj; scalar_t__ of_node; } ;
struct TYPE_15__ {int control_base_addr; int data_base_addr; int query_base_addr; } ;
struct rmi_function {struct device dev; TYPE_5__ fd; struct rmi_device* rmi_dev; } ;
struct rmi_driver_data {int num_of_irq_regs; TYPE_2__* f01_container; } ;
struct TYPE_13__ {int nosleep; int doze_interval; int wakeup_threshold; int doze_holdoff; } ;
struct rmi_device_platform_data {TYPE_3__ power_management; } ;
struct rmi_device {TYPE_6__* driver; TYPE_7__* xport; struct device dev; } ;
struct TYPE_14__ {int ctrl0; int doze_interval; int wakeup_threshold; int doze_holdoff; } ;
struct f01_basic_properties {int manufacturer_id; int has_lts; int has_adjustable_doze; int has_adjustable_doze_holdoff; char* product_id; int productinfo; int package_id; int firmware_id; int /*<<< orphan*/  dom; } ;
struct f01_data {int num_of_irq_regs; int doze_interval_addr; int wakeup_threshold_addr; int doze_holdoff_addr; int old_nosleep; TYPE_4__ device_control; struct f01_basic_properties properties; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __le64 ;
struct TYPE_17__ {int /*<<< orphan*/  dev; TYPE_1__* ops; struct rmi_device_platform_data pdata; } ;
struct TYPE_16__ {int (* reset_handler ) (struct rmi_device*) ;} ;
struct TYPE_12__ {struct device dev; } ;
struct TYPE_11__ {int (* read_block ) (TYPE_7__*,int,int*,int) ;int (* write_block ) (TYPE_7__*,int,int*,int) ;} ;

/* Variables and functions */
 int BIT (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_RETVAL (int) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int RMI_F01_BASIC_QUERY_LEN ; 
 int RMI_F01_CTRL0_CONFIGURED_BIT ; 
 int RMI_F01_CTRL0_NOSLEEP_BIT ; 
 int RMI_F01_CTRL0_SLEEP_MODE_MASK ; 
 int RMI_F01_QRY1_HAS_ADJ_DOZE ; 
 int RMI_F01_QRY1_HAS_ADJ_DOZE_HOFF ; 
 int RMI_F01_QRY1_HAS_LTS ; 
 int RMI_F01_QRY1_HAS_QUERY42 ; 
 int RMI_F01_QRY1_HAS_SENSOR_ID ; 
 int RMI_F01_QRY2_PRODINFO_MASK ; 
 int RMI_F01_QRY5_YEAR_MASK ; 
 int RMI_F01_QRY6_MONTH_MASK ; 
 int RMI_F01_QRY7_DAY_MASK ; 
 scalar_t__ RMI_F01_STATUS_BOOTLOADER (int) ; 
 int RMI_F01_STATUS_CODE (int) ; 
 scalar_t__ RMI_F01_STATUS_UNCONFIGURED (int) ; 
 size_t RMI_PRODUCT_ID_LENGTH ; 
#define  RMI_REG_STATE_DEFAULT 130 
#define  RMI_REG_STATE_OFF 129 
#define  RMI_REG_STATE_ON 128 
 int RMI_SLEEP_MODE_NORMAL ; 
 int RMI_SLEEP_MODE_RESERVED1 ; 
 int RMI_SLEEP_MODE_SENSOR_SLEEP ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,char*,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct f01_data*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 scalar_t__ device_may_wakeup (int /*<<< orphan*/ ) ; 
 struct f01_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int get_unaligned_le64 (int*) ; 
 int /*<<< orphan*/  memcpy (char*,int*,size_t) ; 
 int /*<<< orphan*/  rmi_f01_attr_group ; 
 int /*<<< orphan*/  scnprintf (char*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int,int,int) ; 
 int stub1 (struct rmi_device*) ; 
 int stub2 (TYPE_7__*,int,int*,int) ; 
 int stub3 (TYPE_7__*,int,void*,size_t) ; 
 int stub4 (TYPE_7__*,int,int*,int) ; 
 int stub5 (TYPE_7__*,int,void const*,size_t) ; 
 int stub6 (struct rmi_device*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct rmi_device_platform_data *
rmi_get_platform_data(struct rmi_device *d)
{
	return &d->xport->pdata;
}

__attribute__((used)) static inline int rmi_reset(struct rmi_device *d)
{
	return d->driver->reset_handler(d);
}

__attribute__((used)) static inline int rmi_read(struct rmi_device *d, u16 addr, u8 *buf)
{
	return d->xport->ops->read_block(d->xport, addr, buf, 1);
}

__attribute__((used)) static inline int rmi_read_block(struct rmi_device *d, u16 addr,
				 void *buf, size_t len)
{
	return d->xport->ops->read_block(d->xport, addr, buf, len);
}

__attribute__((used)) static inline int rmi_write(struct rmi_device *d, u16 addr, u8 data)
{
	return d->xport->ops->write_block(d->xport, addr, &data, 1);
}

__attribute__((used)) static inline int rmi_write_block(struct rmi_device *d, u16 addr,
				  const void *buf, size_t len)
{
	return d->xport->ops->write_block(d->xport, addr, buf, len);
}

__attribute__((used)) static inline int rmi_f03_overwrite_button(struct rmi_function *fn,
					   unsigned int button, int value)
{
	return 0;
}

__attribute__((used)) static inline void rmi_f03_commit_buttons(struct rmi_function *fn) {}

__attribute__((used)) static inline int rmi_f34_create_sysfs(struct rmi_device *rmi_dev)
{
	return 0;
}

__attribute__((used)) static inline void rmi_f34_remove_sysfs(struct rmi_device *rmi_dev)
{
}

__attribute__((used)) static int rmi_f01_read_properties(struct rmi_device *rmi_dev,
				   u16 query_base_addr,
				   struct f01_basic_properties *props)
{
	u8 queries[RMI_F01_BASIC_QUERY_LEN];
	int ret;
	int query_offset = query_base_addr;
	bool has_ds4_queries = false;
	bool has_query42 = false;
	bool has_sensor_id = false;
	bool has_package_id_query = false;
	bool has_build_id_query = false;
	u16 prod_info_addr;
	u8 ds4_query_len;

	ret = rmi_read_block(rmi_dev, query_offset,
			       queries, RMI_F01_BASIC_QUERY_LEN);
	if (ret) {
		dev_err(&rmi_dev->dev,
			"Failed to read device query registers: %d\n", ret);
		return ret;
	}

	prod_info_addr = query_offset + 17;
	query_offset += RMI_F01_BASIC_QUERY_LEN;

	/* Now parse what we got */
	props->manufacturer_id = queries[0];

	props->has_lts = queries[1] & RMI_F01_QRY1_HAS_LTS;
	props->has_adjustable_doze =
			queries[1] & RMI_F01_QRY1_HAS_ADJ_DOZE;
	props->has_adjustable_doze_holdoff =
			queries[1] & RMI_F01_QRY1_HAS_ADJ_DOZE_HOFF;
	has_query42 = queries[1] & RMI_F01_QRY1_HAS_QUERY42;
	has_sensor_id = queries[1] & RMI_F01_QRY1_HAS_SENSOR_ID;

	snprintf(props->dom, sizeof(props->dom), "20%02d/%02d/%02d",
		 queries[5] & RMI_F01_QRY5_YEAR_MASK,
		 queries[6] & RMI_F01_QRY6_MONTH_MASK,
		 queries[7] & RMI_F01_QRY7_DAY_MASK);

	memcpy(props->product_id, &queries[11],
		RMI_PRODUCT_ID_LENGTH);
	props->product_id[RMI_PRODUCT_ID_LENGTH] = '\0';

	props->productinfo =
			((queries[2] & RMI_F01_QRY2_PRODINFO_MASK) << 7) |
			(queries[3] & RMI_F01_QRY2_PRODINFO_MASK);

	if (has_sensor_id)
		query_offset++;

	if (has_query42) {
		ret = rmi_read(rmi_dev, query_offset, queries);
		if (ret) {
			dev_err(&rmi_dev->dev,
				"Failed to read query 42 register: %d\n", ret);
			return ret;
		}

		has_ds4_queries = !!(queries[0] & BIT(0));
		query_offset++;
	}

	if (has_ds4_queries) {
		ret = rmi_read(rmi_dev, query_offset, &ds4_query_len);
		if (ret) {
			dev_err(&rmi_dev->dev,
				"Failed to read DS4 queries length: %d\n", ret);
			return ret;
		}
		query_offset++;

		if (ds4_query_len > 0) {
			ret = rmi_read(rmi_dev, query_offset, queries);
			if (ret) {
				dev_err(&rmi_dev->dev,
					"Failed to read DS4 queries: %d\n",
					ret);
				return ret;
			}

			has_package_id_query = !!(queries[0] & BIT(0));
			has_build_id_query = !!(queries[0] & BIT(1));
		}

		if (has_package_id_query) {
			ret = rmi_read_block(rmi_dev, prod_info_addr,
					     queries, sizeof(__le64));
			if (ret) {
				dev_err(&rmi_dev->dev,
					"Failed to read package info: %d\n",
					ret);
				return ret;
			}

			props->package_id = get_unaligned_le64(queries);
			prod_info_addr++;
		}

		if (has_build_id_query) {
			ret = rmi_read_block(rmi_dev, prod_info_addr, queries,
					    3);
			if (ret) {
				dev_err(&rmi_dev->dev,
					"Failed to read product info: %d\n",
					ret);
				return ret;
			}

			props->firmware_id = queries[1] << 8 | queries[0];
			props->firmware_id += queries[2] * 65536;
		}
	}

	return 0;
}

const char *rmi_f01_get_product_ID(struct rmi_function *fn)
{
	struct f01_data *f01 = dev_get_drvdata(&fn->dev);

	return f01->properties.product_id;
}

__attribute__((used)) static ssize_t rmi_driver_manufacturer_id_show(struct device *dev,
					       struct device_attribute *dattr,
					       char *buf)
{
	struct rmi_driver_data *data = dev_get_drvdata(dev);
	struct f01_data *f01 = dev_get_drvdata(&data->f01_container->dev);

	return scnprintf(buf, PAGE_SIZE, "%d\n",
			 f01->properties.manufacturer_id);
}

__attribute__((used)) static ssize_t rmi_driver_dom_show(struct device *dev,
				   struct device_attribute *dattr, char *buf)
{
	struct rmi_driver_data *data = dev_get_drvdata(dev);
	struct f01_data *f01 = dev_get_drvdata(&data->f01_container->dev);

	return scnprintf(buf, PAGE_SIZE, "%s\n", f01->properties.dom);
}

__attribute__((used)) static ssize_t rmi_driver_product_id_show(struct device *dev,
					  struct device_attribute *dattr,
					  char *buf)
{
	struct rmi_driver_data *data = dev_get_drvdata(dev);
	struct f01_data *f01 = dev_get_drvdata(&data->f01_container->dev);

	return scnprintf(buf, PAGE_SIZE, "%s\n", f01->properties.product_id);
}

__attribute__((used)) static ssize_t rmi_driver_firmware_id_show(struct device *dev,
					   struct device_attribute *dattr,
					   char *buf)
{
	struct rmi_driver_data *data = dev_get_drvdata(dev);
	struct f01_data *f01 = dev_get_drvdata(&data->f01_container->dev);

	return scnprintf(buf, PAGE_SIZE, "%d\n", f01->properties.firmware_id);
}

__attribute__((used)) static ssize_t rmi_driver_package_id_show(struct device *dev,
					  struct device_attribute *dattr,
					  char *buf)
{
	struct rmi_driver_data *data = dev_get_drvdata(dev);
	struct f01_data *f01 = dev_get_drvdata(&data->f01_container->dev);

	u32 package_id = f01->properties.package_id;

	return scnprintf(buf, PAGE_SIZE, "%04x.%04x\n",
			 package_id & 0xffff, (package_id >> 16) & 0xffff);
}

__attribute__((used)) static inline int rmi_f01_of_probe(struct device *dev,
					struct rmi_device_platform_data *pdata)
{
	return -ENODEV;
}

__attribute__((used)) static int rmi_f01_probe(struct rmi_function *fn)
{
	struct rmi_device *rmi_dev = fn->rmi_dev;
	struct rmi_driver_data *driver_data = dev_get_drvdata(&rmi_dev->dev);
	struct rmi_device_platform_data *pdata = rmi_get_platform_data(rmi_dev);
	struct f01_data *f01;
	int error;
	u16 ctrl_base_addr = fn->fd.control_base_addr;
	u8 device_status;
	u8 temp;

	if (fn->dev.of_node) {
		error = rmi_f01_of_probe(&fn->dev, pdata);
		if (error)
			return error;
	}

	f01 = devm_kzalloc(&fn->dev, sizeof(struct f01_data), GFP_KERNEL);
	if (!f01)
		return -ENOMEM;

	f01->num_of_irq_regs = driver_data->num_of_irq_regs;

	/*
	 * Set the configured bit and (optionally) other important stuff
	 * in the device control register.
	 */

	error = rmi_read(rmi_dev, fn->fd.control_base_addr,
			 &f01->device_control.ctrl0);
	if (error) {
		dev_err(&fn->dev, "Failed to read F01 control: %d\n", error);
		return error;
	}

	switch (pdata->power_management.nosleep) {
	case RMI_REG_STATE_DEFAULT:
		break;
	case RMI_REG_STATE_OFF:
		f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_NOSLEEP_BIT;
		break;
	case RMI_REG_STATE_ON:
		f01->device_control.ctrl0 |= RMI_F01_CTRL0_NOSLEEP_BIT;
		break;
	}

	/*
	 * Sleep mode might be set as a hangover from a system crash or
	 * reboot without power cycle.  If so, clear it so the sensor
	 * is certain to function.
	 */
	if ((f01->device_control.ctrl0 & RMI_F01_CTRL0_SLEEP_MODE_MASK) !=
			RMI_SLEEP_MODE_NORMAL) {
		dev_warn(&fn->dev,
			 "WARNING: Non-zero sleep mode found. Clearing...\n");
		f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
	}

	f01->device_control.ctrl0 |= RMI_F01_CTRL0_CONFIGURED_BIT;

	error = rmi_write(rmi_dev, fn->fd.control_base_addr,
			  f01->device_control.ctrl0);
	if (error) {
		dev_err(&fn->dev, "Failed to write F01 control: %d\n", error);
		return error;
	}

	/* Dummy read in order to clear irqs */
	error = rmi_read(rmi_dev, fn->fd.data_base_addr + 1, &temp);
	if (error < 0) {
		dev_err(&fn->dev, "Failed to read Interrupt Status.\n");
		return error;
	}

	error = rmi_f01_read_properties(rmi_dev, fn->fd.query_base_addr,
					&f01->properties);
	if (error < 0) {
		dev_err(&fn->dev, "Failed to read F01 properties.\n");
		return error;
	}

	dev_info(&fn->dev, "found RMI device, manufacturer: %s, product: %s, fw id: %d\n",
		 f01->properties.manufacturer_id == 1 ? "Synaptics" : "unknown",
		 f01->properties.product_id, f01->properties.firmware_id);

	/* Advance to interrupt control registers, then skip over them. */
	ctrl_base_addr++;
	ctrl_base_addr += f01->num_of_irq_regs;

	/* read control register */
	if (f01->properties.has_adjustable_doze) {
		f01->doze_interval_addr = ctrl_base_addr;
		ctrl_base_addr++;

		if (pdata->power_management.doze_interval) {
			f01->device_control.doze_interval =
				pdata->power_management.doze_interval;
			error = rmi_write(rmi_dev, f01->doze_interval_addr,
					  f01->device_control.doze_interval);
			if (error) {
				dev_err(&fn->dev,
					"Failed to configure F01 doze interval register: %d\n",
					error);
				return error;
			}
		} else {
			error = rmi_read(rmi_dev, f01->doze_interval_addr,
					 &f01->device_control.doze_interval);
			if (error) {
				dev_err(&fn->dev,
					"Failed to read F01 doze interval register: %d\n",
					error);
				return error;
			}
		}

		f01->wakeup_threshold_addr = ctrl_base_addr;
		ctrl_base_addr++;

		if (pdata->power_management.wakeup_threshold) {
			f01->device_control.wakeup_threshold =
				pdata->power_management.wakeup_threshold;
			error = rmi_write(rmi_dev, f01->wakeup_threshold_addr,
					  f01->device_control.wakeup_threshold);
			if (error) {
				dev_err(&fn->dev,
					"Failed to configure F01 wakeup threshold register: %d\n",
					error);
				return error;
			}
		} else {
			error = rmi_read(rmi_dev, f01->wakeup_threshold_addr,
					 &f01->device_control.wakeup_threshold);
			if (error < 0) {
				dev_err(&fn->dev,
					"Failed to read F01 wakeup threshold register: %d\n",
					error);
				return error;
			}
		}
	}

	if (f01->properties.has_lts)
		ctrl_base_addr++;

	if (f01->properties.has_adjustable_doze_holdoff) {
		f01->doze_holdoff_addr = ctrl_base_addr;
		ctrl_base_addr++;

		if (pdata->power_management.doze_holdoff) {
			f01->device_control.doze_holdoff =
				pdata->power_management.doze_holdoff;
			error = rmi_write(rmi_dev, f01->doze_holdoff_addr,
					  f01->device_control.doze_holdoff);
			if (error) {
				dev_err(&fn->dev,
					"Failed to configure F01 doze holdoff register: %d\n",
					error);
				return error;
			}
		} else {
			error = rmi_read(rmi_dev, f01->doze_holdoff_addr,
					 &f01->device_control.doze_holdoff);
			if (error) {
				dev_err(&fn->dev,
					"Failed to read F01 doze holdoff register: %d\n",
					error);
				return error;
			}
		}
	}

	error = rmi_read(rmi_dev, fn->fd.data_base_addr, &device_status);
	if (error < 0) {
		dev_err(&fn->dev,
			"Failed to read device status: %d\n", error);
		return error;
	}

	if (RMI_F01_STATUS_UNCONFIGURED(device_status)) {
		dev_err(&fn->dev,
			"Device was reset during configuration process, status: %#02x!\n",
			RMI_F01_STATUS_CODE(device_status));
		return -EINVAL;
	}

	dev_set_drvdata(&fn->dev, f01);

	error = sysfs_create_group(&fn->rmi_dev->dev.kobj, &rmi_f01_attr_group);
	if (error)
		dev_warn(&fn->dev, "Failed to create sysfs group: %d\n", error);

	return 0;
}

__attribute__((used)) static void rmi_f01_remove(struct rmi_function *fn)
{
	/* Note that the bus device is used, not the F01 device */
	sysfs_remove_group(&fn->rmi_dev->dev.kobj, &rmi_f01_attr_group);
}

__attribute__((used)) static int rmi_f01_config(struct rmi_function *fn)
{
	struct f01_data *f01 = dev_get_drvdata(&fn->dev);
	int error;

	error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
			  f01->device_control.ctrl0);
	if (error) {
		dev_err(&fn->dev,
			"Failed to write device_control register: %d\n", error);
		return error;
	}

	if (f01->properties.has_adjustable_doze) {
		error = rmi_write(fn->rmi_dev, f01->doze_interval_addr,
				  f01->device_control.doze_interval);
		if (error) {
			dev_err(&fn->dev,
				"Failed to write doze interval: %d\n", error);
			return error;
		}

		error = rmi_write_block(fn->rmi_dev,
					 f01->wakeup_threshold_addr,
					 &f01->device_control.wakeup_threshold,
					 sizeof(u8));
		if (error) {
			dev_err(&fn->dev,
				"Failed to write wakeup threshold: %d\n",
				error);
			return error;
		}
	}

	if (f01->properties.has_adjustable_doze_holdoff) {
		error = rmi_write(fn->rmi_dev, f01->doze_holdoff_addr,
				  f01->device_control.doze_holdoff);
		if (error) {
			dev_err(&fn->dev,
				"Failed to write doze holdoff: %d\n", error);
			return error;
		}
	}

	return 0;
}

__attribute__((used)) static int rmi_f01_suspend(struct rmi_function *fn)
{
	struct f01_data *f01 = dev_get_drvdata(&fn->dev);
	int error;

	f01->old_nosleep =
		f01->device_control.ctrl0 & RMI_F01_CTRL0_NOSLEEP_BIT;
	f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_NOSLEEP_BIT;

	f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
	if (device_may_wakeup(fn->rmi_dev->xport->dev))
		f01->device_control.ctrl0 |= RMI_SLEEP_MODE_RESERVED1;
	else
		f01->device_control.ctrl0 |= RMI_SLEEP_MODE_SENSOR_SLEEP;

	error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
			  f01->device_control.ctrl0);
	if (error) {
		dev_err(&fn->dev, "Failed to write sleep mode: %d.\n", error);
		if (f01->old_nosleep)
			f01->device_control.ctrl0 |= RMI_F01_CTRL0_NOSLEEP_BIT;
		f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
		f01->device_control.ctrl0 |= RMI_SLEEP_MODE_NORMAL;
		return error;
	}

	return 0;
}

__attribute__((used)) static int rmi_f01_resume(struct rmi_function *fn)
{
	struct f01_data *f01 = dev_get_drvdata(&fn->dev);
	int error;

	if (f01->old_nosleep)
		f01->device_control.ctrl0 |= RMI_F01_CTRL0_NOSLEEP_BIT;

	f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
	f01->device_control.ctrl0 |= RMI_SLEEP_MODE_NORMAL;

	error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
			  f01->device_control.ctrl0);
	if (error) {
		dev_err(&fn->dev,
			"Failed to restore normal operation: %d.\n", error);
		return error;
	}

	return 0;
}

__attribute__((used)) static irqreturn_t rmi_f01_attention(int irq, void *ctx)
{
	struct rmi_function *fn = ctx;
	struct rmi_device *rmi_dev = fn->rmi_dev;
	int error;
	u8 device_status;

	error = rmi_read(rmi_dev, fn->fd.data_base_addr, &device_status);
	if (error) {
		dev_err(&fn->dev,
			"Failed to read device status: %d.\n", error);
		return IRQ_RETVAL(error);
	}

	if (RMI_F01_STATUS_BOOTLOADER(device_status))
		dev_warn(&fn->dev,
			 "Device in bootloader mode, please update firmware\n");

	if (RMI_F01_STATUS_UNCONFIGURED(device_status)) {
		dev_warn(&fn->dev, "Device reset detected.\n");
		error = rmi_dev->driver->reset_handler(rmi_dev);
		if (error) {
			dev_err(&fn->dev, "Device reset failed: %d\n", error);
			return IRQ_RETVAL(error);
		}
	}

	return IRQ_HANDLED;
}

