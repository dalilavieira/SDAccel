#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct nvkm_volt_func {int dummy; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct nvkm_volt {TYPE_1__ subdev; } ;
struct nvkm_fuse {int dummy; } ;
struct nvkm_device {int /*<<< orphan*/  gpio; int /*<<< orphan*/  bios; struct nvkm_fuse* fuse; } ;
struct nvbios_volt {int base; int pwm_range; int pwm_freq; scalar_t__ type; } ;
struct gk104_volt {struct nvkm_volt base; struct nvbios_volt bios; } ;
struct dcb_gpio_func {int dummy; } ;
struct TYPE_5__ {struct nvbios_volt bios; } ;

/* Variables and functions */
 int /*<<< orphan*/  DCB_GPIO_VID_PWM ; 
 int DIV_ROUND_UP (int,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ NVBIOS_VOLT_PWM ; 
 TYPE_3__* gk104_volt (struct nvkm_volt*) ; 
 struct nvkm_volt_func const gk104_volt_gpio ; 
 struct nvkm_volt_func const gk104_volt_pwm ; 
 struct gk104_volt* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvbios_volt_parse (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nvbios_volt*) ; 
 int /*<<< orphan*/  nvkm_debug (TYPE_1__*,char*,char const*) ; 
 int /*<<< orphan*/  nvkm_error (TYPE_1__*,char*) ; 
 int nvkm_fuse_read (struct nvkm_fuse*,int) ; 
 int /*<<< orphan*/  nvkm_gpio_find (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct dcb_gpio_func*) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_volt_ctor (struct nvkm_volt_func const*,struct nvkm_device*,int,struct nvkm_volt*) ; 
 int /*<<< orphan*/  nvkm_voltgpio_init (struct nvkm_volt*) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
gk104_volt_get(struct nvkm_volt *base)
{
	struct nvbios_volt *bios = &gk104_volt(base)->bios;
	struct nvkm_device *device = base->subdev.device;
	u32 div, duty;

	div  = nvkm_rd32(device, 0x20340);
	duty = nvkm_rd32(device, 0x20344);

	return bios->base + bios->pwm_range * duty / div;
}

__attribute__((used)) static int
gk104_volt_set(struct nvkm_volt *base, u32 uv)
{
	struct nvbios_volt *bios = &gk104_volt(base)->bios;
	struct nvkm_device *device = base->subdev.device;
	u32 div, duty;

	/* the blob uses this crystal frequency, let's use it too. */
	div = 27648000 / bios->pwm_freq;
	duty = DIV_ROUND_UP((uv - bios->base) * div, bios->pwm_range);

	nvkm_wr32(device, 0x20340, div);
	nvkm_wr32(device, 0x20344, 0x80000000 | duty);

	return 0;
}

__attribute__((used)) static int
gk104_volt_speedo_read(struct nvkm_volt *volt)
{
	struct nvkm_device *device = volt->subdev.device;
	struct nvkm_fuse *fuse = device->fuse;
	int ret;

	if (!fuse)
		return -EINVAL;

	nvkm_wr32(device, 0x122634, 0x0);
	ret = nvkm_fuse_read(fuse, 0x3a8);
	nvkm_wr32(device, 0x122634, 0x41);
	return ret;
}

int
gk104_volt_new(struct nvkm_device *device, int index, struct nvkm_volt **pvolt)
{
	const struct nvkm_volt_func *volt_func = &gk104_volt_gpio;
	struct dcb_gpio_func gpio;
	struct nvbios_volt bios;
	struct gk104_volt *volt;
	u8 ver, hdr, cnt, len;
	const char *mode;

	if (!nvbios_volt_parse(device->bios, &ver, &hdr, &cnt, &len, &bios))
		return 0;

	if (!nvkm_gpio_find(device->gpio, 0, DCB_GPIO_VID_PWM, 0xff, &gpio) &&
	    bios.type == NVBIOS_VOLT_PWM) {
		volt_func = &gk104_volt_pwm;
	}

	if (!(volt = kzalloc(sizeof(*volt), GFP_KERNEL)))
		return -ENOMEM;
	nvkm_volt_ctor(volt_func, device, index, &volt->base);
	*pvolt = &volt->base;
	volt->bios = bios;

	/* now that we have a subdev, we can show an error if we found through
	 * the voltage table that we were supposed to use the PWN mode but we
	 * did not find the right GPIO for it.
	 */
	if (bios.type == NVBIOS_VOLT_PWM && volt_func != &gk104_volt_pwm) {
		nvkm_error(&volt->base.subdev,
			   "Type mismatch between the voltage table type and "
			   "the GPIO table. Fallback to GPIO mode.\n");
	}

	if (volt_func == &gk104_volt_gpio) {
		nvkm_voltgpio_init(&volt->base);
		mode = "GPIO";
	} else
		mode = "PWM";

	nvkm_debug(&volt->base.subdev, "Using %s mode\n", mode);

	return 0;
}

