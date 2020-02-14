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
struct ubx_data {struct gnss_serial* v_bckp; struct gnss_serial* vcc; } ;
struct serdev_device {int /*<<< orphan*/  dev; } ;
struct gnss_serial {void* drvdata; TYPE_1__* gdev; int /*<<< orphan*/ * ops; } ;
typedef  enum gnss_serial_pm_state { ____Placeholder_gnss_serial_pm_state } gnss_serial_pm_state ;
struct TYPE_2__ {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
#define  GNSS_SERIAL_ACTIVE 130 
#define  GNSS_SERIAL_OFF 129 
#define  GNSS_SERIAL_STANDBY 128 
 int /*<<< orphan*/  GNSS_TYPE_UBX ; 
 scalar_t__ IS_ERR (struct gnss_serial*) ; 
 int PTR_ERR (struct gnss_serial*) ; 
 struct gnss_serial* devm_regulator_get (int /*<<< orphan*/ *,char*) ; 
 struct gnss_serial* devm_regulator_get_optional (int /*<<< orphan*/ *,char*) ; 
 struct gnss_serial* gnss_serial_allocate (struct serdev_device*,int) ; 
 int /*<<< orphan*/  gnss_serial_deregister (struct gnss_serial*) ; 
 int /*<<< orphan*/  gnss_serial_free (struct gnss_serial*) ; 
 int gnss_serial_register (struct gnss_serial*) ; 
 int regulator_disable (struct gnss_serial*) ; 
 int regulator_enable (struct gnss_serial*) ; 
 struct gnss_serial* serdev_device_get_drvdata (struct serdev_device*) ; 
 int /*<<< orphan*/  ubx_gserial_ops ; 

__attribute__((used)) static inline void *gnss_serial_get_drvdata(struct gnss_serial *gserial)
{
	return gserial->drvdata;
}

__attribute__((used)) static int ubx_set_active(struct gnss_serial *gserial)
{
	struct ubx_data *data = gnss_serial_get_drvdata(gserial);
	int ret;

	ret = regulator_enable(data->vcc);
	if (ret)
		return ret;

	return 0;
}

__attribute__((used)) static int ubx_set_standby(struct gnss_serial *gserial)
{
	struct ubx_data *data = gnss_serial_get_drvdata(gserial);
	int ret;

	ret = regulator_disable(data->vcc);
	if (ret)
		return ret;

	return 0;
}

__attribute__((used)) static int ubx_set_power(struct gnss_serial *gserial,
				enum gnss_serial_pm_state state)
{
	switch (state) {
	case GNSS_SERIAL_ACTIVE:
		return ubx_set_active(gserial);
	case GNSS_SERIAL_OFF:
	case GNSS_SERIAL_STANDBY:
		return ubx_set_standby(gserial);
	}

	return -EINVAL;
}

__attribute__((used)) static int ubx_probe(struct serdev_device *serdev)
{
	struct gnss_serial *gserial;
	struct ubx_data *data;
	int ret;

	gserial = gnss_serial_allocate(serdev, sizeof(*data));
	if (IS_ERR(gserial)) {
		ret = PTR_ERR(gserial);
		return ret;
	}

	gserial->ops = &ubx_gserial_ops;

	gserial->gdev->type = GNSS_TYPE_UBX;

	data = gnss_serial_get_drvdata(gserial);

	data->vcc = devm_regulator_get(&serdev->dev, "vcc");
	if (IS_ERR(data->vcc)) {
		ret = PTR_ERR(data->vcc);
		goto err_free_gserial;
	}

	data->v_bckp = devm_regulator_get_optional(&serdev->dev, "v-bckp");
	if (IS_ERR(data->v_bckp)) {
		ret = PTR_ERR(data->v_bckp);
		if (ret == -ENODEV)
			data->v_bckp = NULL;
		else
			goto err_free_gserial;
	}

	if (data->v_bckp) {
		ret = regulator_enable(data->v_bckp);
		if (ret)
			goto err_free_gserial;
	}

	ret = gnss_serial_register(gserial);
	if (ret)
		goto err_disable_v_bckp;

	return 0;

err_disable_v_bckp:
	if (data->v_bckp)
		regulator_disable(data->v_bckp);
err_free_gserial:
	gnss_serial_free(gserial);

	return ret;
}

__attribute__((used)) static void ubx_remove(struct serdev_device *serdev)
{
	struct gnss_serial *gserial = serdev_device_get_drvdata(serdev);
	struct ubx_data *data = gnss_serial_get_drvdata(gserial);

	gnss_serial_deregister(gserial);
	if (data->v_bckp)
		regulator_disable(data->v_bckp);
	gnss_serial_free(gserial);
}

