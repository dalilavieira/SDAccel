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
typedef  size_t u8 ;
struct nvkm_subdev {int dummy; } ;
struct nvkm_volt {int vid_nr; TYPE_2__* vid; struct nvkm_subdev subdev; } ;
struct nvkm_device_tegra {int gpu_speedo; int /*<<< orphan*/  vdd; } ;
struct nvkm_device {TYPE_1__* func; } ;
struct gk20a_volt {struct nvkm_volt base; int /*<<< orphan*/  vdd; } ;
struct cvb_coef {int c2; int c1; int c0; int c3; int c4; int c5; } ;
struct TYPE_4__ {int uv; size_t vid; } ;
struct TYPE_3__ {struct nvkm_device_tegra* (* tegra ) (struct nvkm_device*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (struct cvb_coef*) ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int DIV_ROUND_UP (int,int const) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct cvb_coef* gk20a_cvb_coef ; 
 struct gk20a_volt* gk20a_volt (struct nvkm_volt*) ; 
 struct gk20a_volt* kzalloc (int,int /*<<< orphan*/ ) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*,int,...) ; 
 int /*<<< orphan*/  nvkm_volt_ctor (struct gk20a_volt* (*) (struct nvkm_volt*),struct nvkm_device*,int,struct nvkm_volt*) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int regulator_set_voltage (int /*<<< orphan*/ ,int,int) ; 
 struct nvkm_device_tegra* stub1 (struct nvkm_device*) ; 

__attribute__((used)) static inline int
gk20a_volt_get_cvb_voltage(int speedo, int s_scale, const struct cvb_coef *coef)
{
	int mv;

	mv = DIV_ROUND_CLOSEST(coef->c2 * speedo, s_scale);
	mv = DIV_ROUND_CLOSEST((mv + coef->c1) * speedo, s_scale) + coef->c0;
	return mv;
}

__attribute__((used)) static inline int
gk20a_volt_get_cvb_t_voltage(int speedo, int temp, int s_scale, int t_scale,
			     const struct cvb_coef *coef)
{
	int cvb_mv, mv;

	cvb_mv = gk20a_volt_get_cvb_voltage(speedo, s_scale, coef);

	mv = DIV_ROUND_CLOSEST(coef->c3 * speedo, s_scale) + coef->c4 +
		DIV_ROUND_CLOSEST(coef->c5 * temp, t_scale);
	mv = DIV_ROUND_CLOSEST(mv * temp, t_scale) + cvb_mv;
	return mv;
}

__attribute__((used)) static int
gk20a_volt_calc_voltage(const struct cvb_coef *coef, int speedo)
{
	static const int v_scale = 1000;
	int mv;

	mv = gk20a_volt_get_cvb_t_voltage(speedo, -10, 100, 10, coef);
	mv = DIV_ROUND_UP(mv, v_scale);

	return mv * 1000;
}

__attribute__((used)) static int
gk20a_volt_vid_get(struct nvkm_volt *base)
{
	struct gk20a_volt *volt = gk20a_volt(base);
	int i, uv;

	uv = regulator_get_voltage(volt->vdd);

	for (i = 0; i < volt->base.vid_nr; i++)
		if (volt->base.vid[i].uv >= uv)
			return i;

	return -EINVAL;
}

__attribute__((used)) static int
gk20a_volt_vid_set(struct nvkm_volt *base, u8 vid)
{
	struct gk20a_volt *volt = gk20a_volt(base);
	struct nvkm_subdev *subdev = &volt->base.subdev;

	nvkm_debug(subdev, "set voltage as %duv\n", volt->base.vid[vid].uv);
	return regulator_set_voltage(volt->vdd, volt->base.vid[vid].uv, 1200000);
}

__attribute__((used)) static int
gk20a_volt_set_id(struct nvkm_volt *base, u8 id, int condition)
{
	struct gk20a_volt *volt = gk20a_volt(base);
	struct nvkm_subdev *subdev = &volt->base.subdev;
	int prev_uv = regulator_get_voltage(volt->vdd);
	int target_uv = volt->base.vid[id].uv;
	int ret;

	nvkm_debug(subdev, "prev=%d, target=%d, condition=%d\n",
		   prev_uv, target_uv, condition);
	if (!condition ||
		(condition < 0 && target_uv < prev_uv) ||
		(condition > 0 && target_uv > prev_uv)) {
		ret = gk20a_volt_vid_set(&volt->base, volt->base.vid[id].vid);
	} else {
		ret = 0;
	}

	return ret;
}

int
gk20a_volt_ctor(struct nvkm_device *device, int index,
		const struct cvb_coef *coefs, int nb_coefs,
		int vmin, struct gk20a_volt *volt)
{
	struct nvkm_device_tegra *tdev = device->func->tegra(device);
	int i, uv;

	nvkm_volt_ctor(&gk20a_volt, device, index, &volt->base);

	uv = regulator_get_voltage(tdev->vdd);
	nvkm_debug(&volt->base.subdev, "the default voltage is %duV\n", uv);

	volt->vdd = tdev->vdd;

	volt->base.vid_nr = nb_coefs;
	for (i = 0; i < volt->base.vid_nr; i++) {
		volt->base.vid[i].vid = i;
		volt->base.vid[i].uv = max(
			gk20a_volt_calc_voltage(&coefs[i], tdev->gpu_speedo),
			vmin);
		nvkm_debug(&volt->base.subdev, "%2d: vid=%d, uv=%d\n", i,
			   volt->base.vid[i].vid, volt->base.vid[i].uv);
	}

	return 0;
}

int
gk20a_volt_new(struct nvkm_device *device, int index, struct nvkm_volt **pvolt)
{
	struct gk20a_volt *volt;

	volt = kzalloc(sizeof(*volt), GFP_KERNEL);
	if (!volt)
		return -ENOMEM;
	*pvolt = &volt->base;

	return gk20a_volt_ctor(device, index, gk20a_cvb_coef,
			       ARRAY_SIZE(gk20a_cvb_coef), 0, volt);
}

