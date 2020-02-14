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
typedef  int u32 ;
struct thermal_zone_device {struct soc_sensor_entry* devdata; } ;
struct soc_sensor_entry {int mode; int locked; int store_dts_enable; int store_ptps; struct thermal_zone_device* tzone; } ;
typedef  enum thermal_trip_type { ____Placeholder_thermal_trip_type } thermal_trip_type ;
typedef  enum thermal_device_mode { ____Placeholder_thermal_device_mode } thermal_device_mode ;

/* Variables and functions */
 int ENOMEM ; 
 int EPERM ; 
 struct soc_sensor_entry* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct thermal_zone_device*) ; 
 int /*<<< orphan*/  MBI_REG_READ ; 
 int /*<<< orphan*/  MBI_REG_WRITE ; 
 int PTR_ERR (struct thermal_zone_device*) ; 
 int QRK_DTS_ENABLE_BIT ; 
 int QRK_DTS_ID_TP_CRITICAL ; 
 int QRK_DTS_LOCK_BIT ; 
 int QRK_DTS_MASK_TEMP ; 
 int QRK_DTS_MASK_TP_THRES ; 
 int QRK_DTS_OFFSET_TEMP ; 
 int /*<<< orphan*/  QRK_DTS_REG_OFFSET_ENABLE ; 
 int /*<<< orphan*/  QRK_DTS_REG_OFFSET_LOCK ; 
 int /*<<< orphan*/  QRK_DTS_REG_OFFSET_PTPS ; 
 int /*<<< orphan*/  QRK_DTS_REG_OFFSET_TEMP ; 
 int QRK_DTS_SAFE_TP_THRES ; 
 int QRK_DTS_SHIFT_TP ; 
 int QRK_DTS_TEMP_BASE ; 
 int QRK_DTS_WR_MASK_CLR ; 
 int QRK_DTS_WR_MASK_SET ; 
 int /*<<< orphan*/  QRK_MAX_DTS_TRIPS ; 
 int /*<<< orphan*/  QRK_MBI_UNIT_RMU ; 
 void* THERMAL_DEVICE_DISABLED ; 
 int THERMAL_DEVICE_ENABLED ; 
 int THERMAL_TRIP_CRITICAL ; 
 int THERMAL_TRIP_HOT ; 
 int /*<<< orphan*/  dts_update_mutex ; 
 int iosf_mbi_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int iosf_mbi_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kfree (struct soc_sensor_entry*) ; 
 struct soc_sensor_entry* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  polling_delay ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 struct thermal_zone_device* thermal_zone_device_register (char*,int /*<<< orphan*/ ,int,struct soc_sensor_entry*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thermal_zone_device_unregister (struct thermal_zone_device*) ; 
 int /*<<< orphan*/  tzone_ops ; 

__attribute__((used)) static int soc_dts_enable(struct thermal_zone_device *tzd)
{
	u32 out;
	struct soc_sensor_entry *aux_entry = tzd->devdata;
	int ret;

	ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			    QRK_DTS_REG_OFFSET_ENABLE, &out);
	if (ret)
		return ret;

	if (out & QRK_DTS_ENABLE_BIT) {
		aux_entry->mode = THERMAL_DEVICE_ENABLED;
		return 0;
	}

	if (!aux_entry->locked) {
		out |= QRK_DTS_ENABLE_BIT;
		ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, MBI_REG_WRITE,
				     QRK_DTS_REG_OFFSET_ENABLE, out);
		if (ret)
			return ret;

		aux_entry->mode = THERMAL_DEVICE_ENABLED;
	} else {
		aux_entry->mode = THERMAL_DEVICE_DISABLED;
		pr_info("DTS is locked. Cannot enable DTS\n");
		ret = -EPERM;
	}

	return ret;
}

__attribute__((used)) static int soc_dts_disable(struct thermal_zone_device *tzd)
{
	u32 out;
	struct soc_sensor_entry *aux_entry = tzd->devdata;
	int ret;

	ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			    QRK_DTS_REG_OFFSET_ENABLE, &out);
	if (ret)
		return ret;

	if (!(out & QRK_DTS_ENABLE_BIT)) {
		aux_entry->mode = THERMAL_DEVICE_DISABLED;
		return 0;
	}

	if (!aux_entry->locked) {
		out &= ~QRK_DTS_ENABLE_BIT;
		ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, MBI_REG_WRITE,
				     QRK_DTS_REG_OFFSET_ENABLE, out);

		if (ret)
			return ret;

		aux_entry->mode = THERMAL_DEVICE_DISABLED;
	} else {
		aux_entry->mode = THERMAL_DEVICE_ENABLED;
		pr_info("DTS is locked. Cannot disable DTS\n");
		ret = -EPERM;
	}

	return ret;
}

__attribute__((used)) static int _get_trip_temp(int trip, int *temp)
{
	int status;
	u32 out;

	mutex_lock(&dts_update_mutex);
	status = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			       QRK_DTS_REG_OFFSET_PTPS, &out);
	mutex_unlock(&dts_update_mutex);

	if (status)
		return status;

	/*
	 * Thermal Sensor Programmable Trip Point Register has 8-bit
	 * fields for critical (catastrophic) and hot set trip point
	 * thresholds. The threshold value is always offset by its
	 * temperature base (50 degree Celsius).
	 */
	*temp = (out >> (trip * QRK_DTS_SHIFT_TP)) & QRK_DTS_MASK_TP_THRES;
	*temp -= QRK_DTS_TEMP_BASE;

	return 0;
}

__attribute__((used)) static inline int sys_get_trip_temp(struct thermal_zone_device *tzd,
				int trip, int *temp)
{
	return _get_trip_temp(trip, temp);
}

__attribute__((used)) static inline int sys_get_crit_temp(struct thermal_zone_device *tzd, int *temp)
{
	return _get_trip_temp(QRK_DTS_ID_TP_CRITICAL, temp);
}

__attribute__((used)) static int update_trip_temp(struct soc_sensor_entry *aux_entry,
				int trip, int temp)
{
	u32 out;
	u32 temp_out;
	u32 store_ptps;
	int ret;

	mutex_lock(&dts_update_mutex);
	if (aux_entry->locked) {
		ret = -EPERM;
		goto failed;
	}

	ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			    QRK_DTS_REG_OFFSET_PTPS, &store_ptps);
	if (ret)
		goto failed;

	/*
	 * Protection against unsafe trip point thresdhold value.
	 * As Quark X1000 data-sheet does not provide any recommendation
	 * regarding the safe trip point threshold value to use, we choose
	 * the safe value according to the threshold value set by UEFI BIOS.
	 */
	if (temp > QRK_DTS_SAFE_TP_THRES)
		temp = QRK_DTS_SAFE_TP_THRES;

	/*
	 * Thermal Sensor Programmable Trip Point Register has 8-bit
	 * fields for critical (catastrophic) and hot set trip point
	 * thresholds. The threshold value is always offset by its
	 * temperature base (50 degree Celsius).
	 */
	temp_out = temp + QRK_DTS_TEMP_BASE;
	out = (store_ptps & ~(QRK_DTS_MASK_TP_THRES <<
		(trip * QRK_DTS_SHIFT_TP)));
	out |= (temp_out & QRK_DTS_MASK_TP_THRES) <<
		(trip * QRK_DTS_SHIFT_TP);

	ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, MBI_REG_WRITE,
			     QRK_DTS_REG_OFFSET_PTPS, out);

failed:
	mutex_unlock(&dts_update_mutex);
	return ret;
}

__attribute__((used)) static inline int sys_set_trip_temp(struct thermal_zone_device *tzd, int trip,
				int temp)
{
	return update_trip_temp(tzd->devdata, trip, temp);
}

__attribute__((used)) static int sys_get_trip_type(struct thermal_zone_device *thermal,
		int trip, enum thermal_trip_type *type)
{
	if (trip)
		*type = THERMAL_TRIP_HOT;
	else
		*type = THERMAL_TRIP_CRITICAL;

	return 0;
}

__attribute__((used)) static int sys_get_curr_temp(struct thermal_zone_device *tzd,
				int *temp)
{
	u32 out;
	int ret;

	mutex_lock(&dts_update_mutex);
	ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			    QRK_DTS_REG_OFFSET_TEMP, &out);
	mutex_unlock(&dts_update_mutex);

	if (ret)
		return ret;

	/*
	 * Thermal Sensor Temperature Register has 8-bit field
	 * for temperature value (offset by temperature base
	 * 50 degree Celsius).
	 */
	out = (out >> QRK_DTS_OFFSET_TEMP) & QRK_DTS_MASK_TEMP;
	*temp = out - QRK_DTS_TEMP_BASE;

	return 0;
}

__attribute__((used)) static int sys_get_mode(struct thermal_zone_device *tzd,
				enum thermal_device_mode *mode)
{
	struct soc_sensor_entry *aux_entry = tzd->devdata;
	*mode = aux_entry->mode;
	return 0;
}

__attribute__((used)) static int sys_set_mode(struct thermal_zone_device *tzd,
				enum thermal_device_mode mode)
{
	int ret;

	mutex_lock(&dts_update_mutex);
	if (mode == THERMAL_DEVICE_ENABLED)
		ret = soc_dts_enable(tzd);
	else
		ret = soc_dts_disable(tzd);
	mutex_unlock(&dts_update_mutex);

	return ret;
}

__attribute__((used)) static void free_soc_dts(struct soc_sensor_entry *aux_entry)
{
	if (aux_entry) {
		if (!aux_entry->locked) {
			mutex_lock(&dts_update_mutex);
			iosf_mbi_write(QRK_MBI_UNIT_RMU, MBI_REG_WRITE,
				       QRK_DTS_REG_OFFSET_ENABLE,
				       aux_entry->store_dts_enable);

			iosf_mbi_write(QRK_MBI_UNIT_RMU, MBI_REG_WRITE,
				       QRK_DTS_REG_OFFSET_PTPS,
				       aux_entry->store_ptps);
			mutex_unlock(&dts_update_mutex);
		}
		thermal_zone_device_unregister(aux_entry->tzone);
		kfree(aux_entry);
	}
}

__attribute__((used)) static struct soc_sensor_entry *alloc_soc_dts(void)
{
	struct soc_sensor_entry *aux_entry;
	int err;
	u32 out;
	int wr_mask;

	aux_entry = kzalloc(sizeof(*aux_entry), GFP_KERNEL);
	if (!aux_entry) {
		err = -ENOMEM;
		return ERR_PTR(-ENOMEM);
	}

	/* Check if DTS register is locked */
	err = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
			    QRK_DTS_REG_OFFSET_LOCK, &out);
	if (err)
		goto err_ret;

	if (out & QRK_DTS_LOCK_BIT) {
		aux_entry->locked = true;
		wr_mask = QRK_DTS_WR_MASK_CLR;
	} else {
		aux_entry->locked = false;
		wr_mask = QRK_DTS_WR_MASK_SET;
	}

	/* Store DTS default state if DTS registers are not locked */
	if (!aux_entry->locked) {
		/* Store DTS default enable for restore on exit */
		err = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
				    QRK_DTS_REG_OFFSET_ENABLE,
				    &aux_entry->store_dts_enable);
		if (err)
			goto err_ret;

		/* Store DTS default PTPS register for restore on exit */
		err = iosf_mbi_read(QRK_MBI_UNIT_RMU, MBI_REG_READ,
				    QRK_DTS_REG_OFFSET_PTPS,
				    &aux_entry->store_ptps);
		if (err)
			goto err_ret;
	}

	aux_entry->tzone = thermal_zone_device_register("quark_dts",
			QRK_MAX_DTS_TRIPS,
			wr_mask,
			aux_entry, &tzone_ops, NULL, 0, polling_delay);
	if (IS_ERR(aux_entry->tzone)) {
		err = PTR_ERR(aux_entry->tzone);
		goto err_ret;
	}

	mutex_lock(&dts_update_mutex);
	err = soc_dts_enable(aux_entry->tzone);
	mutex_unlock(&dts_update_mutex);
	if (err)
		goto err_aux_status;

	return aux_entry;

err_aux_status:
	thermal_zone_device_unregister(aux_entry->tzone);
err_ret:
	kfree(aux_entry);
	return ERR_PTR(err);
}

