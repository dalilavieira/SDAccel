#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct serdev_device {TYPE_2__ dev; } ;
struct gnss_serial {void* drvdata; int speed; struct gnss_device* gdev; struct serdev_device* serdev; TYPE_1__* ops; } ;
struct gnss_device {int /*<<< orphan*/ * ops; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  enum gnss_serial_pm_state { ____Placeholder_gnss_serial_pm_state } gnss_serial_pm_state ;
struct TYPE_8__ {int (* set_power ) (struct gnss_serial*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_PM ; 
 int ENOMEM ; 
 struct gnss_serial* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GNSS_SERIAL_ACTIVE ; 
 int GNSS_SERIAL_OFF ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX_SCHEDULE_TIMEOUT ; 
 struct gnss_device* gnss_allocate_device (TYPE_2__*) ; 
 int /*<<< orphan*/  gnss_deregister_device (struct gnss_device*) ; 
 struct gnss_serial* gnss_get_drvdata (struct gnss_device*) ; 
 int gnss_insert_raw (struct gnss_device*,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  gnss_put_device (struct gnss_device*) ; 
 int gnss_register_device (struct gnss_device*) ; 
 int /*<<< orphan*/  gnss_serial_gnss_ops ; 
 int /*<<< orphan*/  gnss_serial_serdev_ops ; 
 int /*<<< orphan*/  gnss_set_drvdata (struct gnss_device*,struct gnss_serial*) ; 
 int /*<<< orphan*/  kfree (struct gnss_serial*) ; 
 struct gnss_serial* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_2__*) ; 
 int pm_runtime_get_sync (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (TYPE_2__*) ; 
 scalar_t__ pm_runtime_suspended (struct device*) ; 
 int /*<<< orphan*/  serdev_device_close (struct serdev_device*) ; 
 struct gnss_serial* serdev_device_get_drvdata (struct serdev_device*) ; 
 int serdev_device_open (struct serdev_device*) ; 
 int /*<<< orphan*/  serdev_device_set_baudrate (struct serdev_device*,int) ; 
 int /*<<< orphan*/  serdev_device_set_client_ops (struct serdev_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  serdev_device_set_drvdata (struct serdev_device*,struct gnss_serial*) ; 
 int /*<<< orphan*/  serdev_device_set_flow_control (struct serdev_device*,int) ; 
 int /*<<< orphan*/  serdev_device_wait_until_sent (struct serdev_device*,int /*<<< orphan*/ ) ; 
 int serdev_device_write (struct serdev_device*,unsigned char const*,size_t,int /*<<< orphan*/ ) ; 
 int stub1 (struct gnss_serial*,int) ; 

__attribute__((used)) static inline void *gnss_serial_get_drvdata(struct gnss_serial *gserial)
{
	return gserial->drvdata;
}

__attribute__((used)) static int gnss_serial_open(struct gnss_device *gdev)
{
	struct gnss_serial *gserial = gnss_get_drvdata(gdev);
	struct serdev_device *serdev = gserial->serdev;
	int ret;

	ret = serdev_device_open(serdev);
	if (ret)
		return ret;

	serdev_device_set_baudrate(serdev, gserial->speed);
	serdev_device_set_flow_control(serdev, false);

	ret = pm_runtime_get_sync(&serdev->dev);
	if (ret < 0) {
		pm_runtime_put_noidle(&serdev->dev);
		goto err_close;
	}

	return 0;

err_close:
	serdev_device_close(serdev);

	return ret;
}

__attribute__((used)) static void gnss_serial_close(struct gnss_device *gdev)
{
	struct gnss_serial *gserial = gnss_get_drvdata(gdev);
	struct serdev_device *serdev = gserial->serdev;

	serdev_device_close(serdev);

	pm_runtime_put(&serdev->dev);
}

__attribute__((used)) static int gnss_serial_write_raw(struct gnss_device *gdev,
		const unsigned char *buf, size_t count)
{
	struct gnss_serial *gserial = gnss_get_drvdata(gdev);
	struct serdev_device *serdev = gserial->serdev;
	int ret;

	/* write is only buffered synchronously */
	ret = serdev_device_write(serdev, buf, count, MAX_SCHEDULE_TIMEOUT);
	if (ret < 0)
		return ret;

	/* FIXME: determine if interrupted? */
	serdev_device_wait_until_sent(serdev, 0);

	return count;
}

__attribute__((used)) static int gnss_serial_receive_buf(struct serdev_device *serdev,
					const unsigned char *buf, size_t count)
{
	struct gnss_serial *gserial = serdev_device_get_drvdata(serdev);
	struct gnss_device *gdev = gserial->gdev;

	return gnss_insert_raw(gdev, buf, count);
}

__attribute__((used)) static int gnss_serial_set_power(struct gnss_serial *gserial,
					enum gnss_serial_pm_state state)
{
	if (!gserial->ops || !gserial->ops->set_power)
		return 0;

	return gserial->ops->set_power(gserial, state);
}

__attribute__((used)) static int gnss_serial_parse_dt(struct serdev_device *serdev)
{
	struct gnss_serial *gserial = serdev_device_get_drvdata(serdev);
	struct device_node *node = serdev->dev.of_node;
	u32 speed = 4800;

	of_property_read_u32(node, "current-speed", &speed);

	gserial->speed = speed;

	return 0;
}

struct gnss_serial *gnss_serial_allocate(struct serdev_device *serdev,
						size_t data_size)
{
	struct gnss_serial *gserial;
	struct gnss_device *gdev;
	int ret;

	gserial = kzalloc(sizeof(*gserial) + data_size, GFP_KERNEL);
	if (!gserial)
		return ERR_PTR(-ENOMEM);

	gdev = gnss_allocate_device(&serdev->dev);
	if (!gdev) {
		ret = -ENOMEM;
		goto err_free_gserial;
	}

	gdev->ops = &gnss_serial_gnss_ops;
	gnss_set_drvdata(gdev, gserial);

	gserial->serdev = serdev;
	gserial->gdev = gdev;

	serdev_device_set_drvdata(serdev, gserial);
	serdev_device_set_client_ops(serdev, &gnss_serial_serdev_ops);

	ret = gnss_serial_parse_dt(serdev);
	if (ret)
		goto err_put_device;

	return gserial;

err_put_device:
	gnss_put_device(gserial->gdev);
err_free_gserial:
	kfree(gserial);

	return ERR_PTR(ret);
}

void gnss_serial_free(struct gnss_serial *gserial)
{
	gnss_put_device(gserial->gdev);
	kfree(gserial);
}

int gnss_serial_register(struct gnss_serial *gserial)
{
	struct serdev_device *serdev = gserial->serdev;
	int ret;

	if (IS_ENABLED(CONFIG_PM)) {
		pm_runtime_enable(&serdev->dev);
	} else {
		ret = gnss_serial_set_power(gserial, GNSS_SERIAL_ACTIVE);
		if (ret < 0)
			return ret;
	}

	ret = gnss_register_device(gserial->gdev);
	if (ret)
		goto err_disable_rpm;

	return 0;

err_disable_rpm:
	if (IS_ENABLED(CONFIG_PM))
		pm_runtime_disable(&serdev->dev);
	else
		gnss_serial_set_power(gserial, GNSS_SERIAL_OFF);

	return ret;
}

void gnss_serial_deregister(struct gnss_serial *gserial)
{
	struct serdev_device *serdev = gserial->serdev;

	gnss_deregister_device(gserial->gdev);

	if (IS_ENABLED(CONFIG_PM))
		pm_runtime_disable(&serdev->dev);
	else
		gnss_serial_set_power(gserial, GNSS_SERIAL_OFF);
}

__attribute__((used)) static int gnss_serial_prepare(struct device *dev)
{
	if (pm_runtime_suspended(dev))
		return 1;

	return 0;
}

