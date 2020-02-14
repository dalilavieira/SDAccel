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
typedef  int u8 ;
typedef  int u32 ;
struct nvbios_therm_sensor {int slope_div; int slope_mult; int offset_num; int offset_den; int offset_constant; } ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_therm {struct nvbios_therm_sensor bios_sensor; struct nvkm_subdev subdev; } ;
struct nvkm_device {int chipset; int crystal; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  nv50_therm ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int nvkm_therm_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_therm**) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
pwm_info(struct nvkm_therm *therm, int *line, int *ctrl, int *indx)
{
	struct nvkm_subdev *subdev = &therm->subdev;

	if (*line == 0x04) {
		*ctrl = 0x00e100;
		*line = 4;
		*indx = 0;
	} else
	if (*line == 0x09) {
		*ctrl = 0x00e100;
		*line = 9;
		*indx = 1;
	} else
	if (*line == 0x10) {
		*ctrl = 0x00e28c;
		*line = 0;
		*indx = 0;
	} else {
		nvkm_error(subdev, "unknown pwm ctrl for gpio %d\n", *line);
		return -ENODEV;
	}

	return 0;
}

int
nv50_fan_pwm_ctrl(struct nvkm_therm *therm, int line, bool enable)
{
	struct nvkm_device *device = therm->subdev.device;
	u32 data = enable ? 0x00000001 : 0x00000000;
	int ctrl, id, ret = pwm_info(therm, &line, &ctrl, &id);
	if (ret == 0)
		nvkm_mask(device, ctrl, 0x00010001 << line, data << line);
	return ret;
}

int
nv50_fan_pwm_get(struct nvkm_therm *therm, int line, u32 *divs, u32 *duty)
{
	struct nvkm_device *device = therm->subdev.device;
	int ctrl, id, ret = pwm_info(therm, &line, &ctrl, &id);
	if (ret)
		return ret;

	if (nvkm_rd32(device, ctrl) & (1 << line)) {
		*divs = nvkm_rd32(device, 0x00e114 + (id * 8));
		*duty = nvkm_rd32(device, 0x00e118 + (id * 8));
		return 0;
	}

	return -EINVAL;
}

int
nv50_fan_pwm_set(struct nvkm_therm *therm, int line, u32 divs, u32 duty)
{
	struct nvkm_device *device = therm->subdev.device;
	int ctrl, id, ret = pwm_info(therm, &line, &ctrl, &id);
	if (ret)
		return ret;

	nvkm_wr32(device, 0x00e114 + (id * 8), divs);
	nvkm_wr32(device, 0x00e118 + (id * 8), duty | 0x80000000);
	return 0;
}

int
nv50_fan_pwm_clock(struct nvkm_therm *therm, int line)
{
	struct nvkm_device *device = therm->subdev.device;
	int pwm_clock;

	/* determine the PWM source clock */
	if (device->chipset > 0x50 && device->chipset < 0x94) {
		u8 pwm_div = nvkm_rd32(device, 0x410c);
		if (nvkm_rd32(device, 0xc040) & 0x800000) {
			/* Use the HOST clock (100 MHz)
			* Where does this constant(2.4) comes from? */
			pwm_clock = (100000000 >> pwm_div) * 10 / 24;
		} else {
			/* Where does this constant(20) comes from? */
			pwm_clock = (device->crystal * 1000) >> pwm_div;
			pwm_clock /= 20;
		}
	} else {
		pwm_clock = (device->crystal * 1000) / 20;
	}

	return pwm_clock;
}

__attribute__((used)) static void
nv50_sensor_setup(struct nvkm_therm *therm)
{
	struct nvkm_device *device = therm->subdev.device;
	nvkm_mask(device, 0x20010, 0x40000000, 0x0);
	mdelay(20); /* wait for the temperature to stabilize */
}

__attribute__((used)) static int
nv50_temp_get(struct nvkm_therm *therm)
{
	struct nvkm_device *device = therm->subdev.device;
	struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
	int core_temp;

	core_temp = nvkm_rd32(device, 0x20014) & 0x3fff;

	/* if the slope or the offset is unset, do no use the sensor */
	if (!sensor->slope_div || !sensor->slope_mult ||
	    !sensor->offset_num || !sensor->offset_den)
	    return -ENODEV;

	core_temp = core_temp * sensor->slope_mult / sensor->slope_div;
	core_temp = core_temp + sensor->offset_num / sensor->offset_den;
	core_temp = core_temp + sensor->offset_constant - 8;

	/* reserve negative temperatures for errors */
	if (core_temp < 0)
		core_temp = 0;

	return core_temp;
}

__attribute__((used)) static void
nv50_therm_init(struct nvkm_therm *therm)
{
	nv50_sensor_setup(therm);
}

int
nv50_therm_new(struct nvkm_device *device, int index,
	       struct nvkm_therm **ptherm)
{
	return nvkm_therm_new_(&nv50_therm, device, index, ptherm);
}

