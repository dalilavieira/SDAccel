#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_therm {TYPE_2__* fan; struct nvkm_subdev subdev; } ;
struct nvkm_device {int crystal; } ;
struct TYPE_3__ {scalar_t__ func; int line; } ;
struct TYPE_4__ {TYPE_1__ tach; } ;

/* Variables and functions */
 scalar_t__ DCB_GPIO_UNUSED ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  g84_sensor_setup (struct nvkm_therm*) ; 
 int /*<<< orphan*/  gf119_therm ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,int,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int nvkm_therm_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_therm**) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
pwm_info(struct nvkm_therm *therm, int line)
{
	struct nvkm_subdev *subdev = &therm->subdev;
	struct nvkm_device *device = subdev->device;
	u32 gpio = nvkm_rd32(device, 0x00d610 + (line * 0x04));

	switch (gpio & 0x000000c0) {
	case 0x00000000: /* normal mode, possibly pwm forced off by us */
	case 0x00000040: /* nvio special */
		switch (gpio & 0x0000001f) {
		case 0x00: return 2;
		case 0x19: return 1;
		case 0x1c: return 0;
		case 0x1e: return 2;
		default:
			break;
		}
	default:
		break;
	}

	nvkm_error(subdev, "GPIO %d unknown PWM: %08x\n", line, gpio);
	return -ENODEV;
}

int
gf119_fan_pwm_ctrl(struct nvkm_therm *therm, int line, bool enable)
{
	struct nvkm_device *device = therm->subdev.device;
	u32 data = enable ? 0x00000040 : 0x00000000;
	int indx = pwm_info(therm, line);
	if (indx < 0)
		return indx;
	else if (indx < 2)
		nvkm_mask(device, 0x00d610 + (line * 0x04), 0x000000c0, data);
	/* nothing to do for indx == 2, it seems hardwired to PTHERM */
	return 0;
}

int
gf119_fan_pwm_get(struct nvkm_therm *therm, int line, u32 *divs, u32 *duty)
{
	struct nvkm_device *device = therm->subdev.device;
	int indx = pwm_info(therm, line);
	if (indx < 0)
		return indx;
	else if (indx < 2) {
		if (nvkm_rd32(device, 0x00d610 + (line * 0x04)) & 0x00000040) {
			*divs = nvkm_rd32(device, 0x00e114 + (indx * 8));
			*duty = nvkm_rd32(device, 0x00e118 + (indx * 8));
			return 0;
		}
	} else if (indx == 2) {
		*divs = nvkm_rd32(device, 0x0200d8) & 0x1fff;
		*duty = nvkm_rd32(device, 0x0200dc) & 0x1fff;
		return 0;
	}

	return -EINVAL;
}

int
gf119_fan_pwm_set(struct nvkm_therm *therm, int line, u32 divs, u32 duty)
{
	struct nvkm_device *device = therm->subdev.device;
	int indx = pwm_info(therm, line);
	if (indx < 0)
		return indx;
	else if (indx < 2) {
		nvkm_wr32(device, 0x00e114 + (indx * 8), divs);
		nvkm_wr32(device, 0x00e118 + (indx * 8), duty | 0x80000000);
	} else if (indx == 2) {
		nvkm_mask(device, 0x0200d8, 0x1fff, divs); /* keep the high bits */
		nvkm_wr32(device, 0x0200dc, duty | 0x40000000);
	}
	return 0;
}

int
gf119_fan_pwm_clock(struct nvkm_therm *therm, int line)
{
	struct nvkm_device *device = therm->subdev.device;
	int indx = pwm_info(therm, line);
	if (indx < 0)
		return 0;
	else if (indx < 2)
		return (device->crystal * 1000) / 20;
	else
		return device->crystal * 1000 / 10;
}

void
gf119_therm_init(struct nvkm_therm *therm)
{
	struct nvkm_device *device = therm->subdev.device;

	g84_sensor_setup(therm);

	/* enable fan tach, count revolutions per-second */
	nvkm_mask(device, 0x00e720, 0x00000003, 0x00000002);
	if (therm->fan->tach.func != DCB_GPIO_UNUSED) {
		nvkm_mask(device, 0x00d79c, 0x000000ff, therm->fan->tach.line);
		nvkm_wr32(device, 0x00e724, device->crystal * 1000);
		nvkm_mask(device, 0x00e720, 0x00000001, 0x00000001);
	}
	nvkm_mask(device, 0x00e720, 0x00000002, 0x00000000);
}

int
gf119_therm_new(struct nvkm_device *device, int index,
	       struct nvkm_therm **ptherm)
{
	return nvkm_therm_new_(&gf119_therm, device, index, ptherm);
}

