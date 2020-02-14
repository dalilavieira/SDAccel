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
typedef  int u32 ;
typedef  int u16 ;
struct tsensor_shared_calib {int base_cp; int base_ft; int actual_temp_cp; int actual_temp_ft; } ;
struct tegra_tsensor_group {int pdiv; int pdiv_ate; } ;
struct tegra_tsensor {int fuse_corr_alpha; int fuse_corr_beta; TYPE_1__* config; scalar_t__ calib_fuse_offset; struct tegra_tsensor_group* group; } ;
struct tegra_soctherm_fuse {int fuse_base_cp_mask; int fuse_base_cp_shift; int fuse_base_ft_mask; int fuse_base_ft_shift; int fuse_shift_ft_mask; int fuse_shift_ft_shift; scalar_t__ fuse_spare_realignment; } ;
typedef  int s64 ;
typedef  int s32 ;
typedef  int s16 ;
struct TYPE_2__ {int tsample_ate; int tsample; } ;

/* Variables and functions */
 int CALIB_COEFFICIENT ; 
 int FUSE_TSENSOR_CALIB_FT_TS_BASE_MASK ; 
 int FUSE_TSENSOR_CALIB_FT_TS_BASE_SHIFT ; 
 scalar_t__ FUSE_TSENSOR_COMMON ; 
 int NOMINAL_CALIB_CP ; 
 int NOMINAL_CALIB_FT ; 
 int SENSOR_CONFIG2_THERMA_SHIFT ; 
 int SENSOR_CONFIG2_THERMB_SHIFT ; 
 int div64_s64 (int,int) ; 
 int sign_extend32 (int,int) ; 
 int tegra_fuse_readl (scalar_t__,int*) ; 

__attribute__((used)) static s64 div64_s64_precise(s64 a, s32 b)
{
	s64 r, al;

	/* Scale up for increased precision division */
	al = a << 16;

	r = div64_s64(al * 2 + 1, 2 * b);
	return r >> 16;
}

int tegra_calc_shared_calib(const struct tegra_soctherm_fuse *tfuse,
			    struct tsensor_shared_calib *shared)
{
	u32 val;
	s32 shifted_cp, shifted_ft;
	int err;

	err = tegra_fuse_readl(FUSE_TSENSOR_COMMON, &val);
	if (err)
		return err;

	shared->base_cp = (val & tfuse->fuse_base_cp_mask) >>
			  tfuse->fuse_base_cp_shift;
	shared->base_ft = (val & tfuse->fuse_base_ft_mask) >>
			  tfuse->fuse_base_ft_shift;

	shifted_ft = (val & tfuse->fuse_shift_ft_mask) >>
		     tfuse->fuse_shift_ft_shift;
	shifted_ft = sign_extend32(shifted_ft, 4);

	if (tfuse->fuse_spare_realignment) {
		err = tegra_fuse_readl(tfuse->fuse_spare_realignment, &val);
		if (err)
			return err;
	}

	shifted_cp = sign_extend32(val, 5);

	shared->actual_temp_cp = 2 * NOMINAL_CALIB_CP + shifted_cp;
	shared->actual_temp_ft = 2 * NOMINAL_CALIB_FT + shifted_ft;

	return 0;
}

int tegra_calc_tsensor_calib(const struct tegra_tsensor *sensor,
			     const struct tsensor_shared_calib *shared,
			     u32 *calibration)
{
	const struct tegra_tsensor_group *sensor_group;
	u32 val, calib;
	s32 actual_tsensor_ft, actual_tsensor_cp;
	s32 delta_sens, delta_temp;
	s32 mult, div;
	s16 therma, thermb;
	s64 temp;
	int err;

	sensor_group = sensor->group;

	err = tegra_fuse_readl(sensor->calib_fuse_offset, &val);
	if (err)
		return err;

	actual_tsensor_cp = (shared->base_cp * 64) + sign_extend32(val, 12);
	val = (val & FUSE_TSENSOR_CALIB_FT_TS_BASE_MASK) >>
	      FUSE_TSENSOR_CALIB_FT_TS_BASE_SHIFT;
	actual_tsensor_ft = (shared->base_ft * 32) + sign_extend32(val, 12);

	delta_sens = actual_tsensor_ft - actual_tsensor_cp;
	delta_temp = shared->actual_temp_ft - shared->actual_temp_cp;

	mult = sensor_group->pdiv * sensor->config->tsample_ate;
	div = sensor->config->tsample * sensor_group->pdiv_ate;

	temp = (s64)delta_temp * (1LL << 13) * mult;
	therma = div64_s64_precise(temp, (s64)delta_sens * div);

	temp = ((s64)actual_tsensor_ft * shared->actual_temp_cp) -
		((s64)actual_tsensor_cp * shared->actual_temp_ft);
	thermb = div64_s64_precise(temp, delta_sens);

	temp = (s64)therma * sensor->fuse_corr_alpha;
	therma = div64_s64_precise(temp, CALIB_COEFFICIENT);

	temp = (s64)thermb * sensor->fuse_corr_alpha + sensor->fuse_corr_beta;
	thermb = div64_s64_precise(temp, CALIB_COEFFICIENT);

	calib = ((u16)therma << SENSOR_CONFIG2_THERMA_SHIFT) |
		((u16)thermb << SENSOR_CONFIG2_THERMB_SHIFT);

	*calibration = calib;

	return 0;
}

