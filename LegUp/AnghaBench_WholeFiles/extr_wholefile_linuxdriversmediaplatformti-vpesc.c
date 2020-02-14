#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  unsigned int u32 ;
typedef  int u16 ;
struct sc_data {int load_coeff_h; int load_coeff_v; scalar_t__ base; TYPE_1__* res; struct platform_device* pdev; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 unsigned int CFG_AUTO_HS ; 
 unsigned int CFG_COL_ACC_OFFSET_SHIFT ; 
 unsigned int CFG_DCM_2X ; 
 unsigned int CFG_DCM_4X ; 
 unsigned int CFG_ENABLE_EV ; 
 unsigned int CFG_ENABLE_SIN2_VER_INTP ; 
 unsigned int CFG_HP_BYPASS ; 
 unsigned int CFG_INTERLACE_I ; 
 unsigned int CFG_INTERLACE_O ; 
 unsigned int CFG_INVT_FID ; 
 unsigned int CFG_LINEAR ; 
 unsigned int CFG_LIN_ACC_INC_U_MASK ; 
 unsigned int CFG_LIN_ACC_INC_U_SHIFT ; 
 unsigned int CFG_ORG_H_SHIFT ; 
 unsigned int CFG_ORG_W_SHIFT ; 
 int CFG_ROW_ACC_INIT_RAV_B_SHIFT ; 
 int CFG_ROW_ACC_INIT_RAV_SHIFT ; 
 scalar_t__ CFG_SC0 ; 
 scalar_t__ CFG_SC1 ; 
 scalar_t__ CFG_SC10 ; 
 scalar_t__ CFG_SC11 ; 
 scalar_t__ CFG_SC12 ; 
 scalar_t__ CFG_SC13 ; 
 scalar_t__ CFG_SC17 ; 
 scalar_t__ CFG_SC18 ; 
 scalar_t__ CFG_SC19 ; 
 scalar_t__ CFG_SC2 ; 
 scalar_t__ CFG_SC20 ; 
 scalar_t__ CFG_SC21 ; 
 scalar_t__ CFG_SC22 ; 
 scalar_t__ CFG_SC23 ; 
 scalar_t__ CFG_SC24 ; 
 scalar_t__ CFG_SC25 ; 
 scalar_t__ CFG_SC3 ; 
 scalar_t__ CFG_SC4 ; 
 scalar_t__ CFG_SC5 ; 
 scalar_t__ CFG_SC6 ; 
 scalar_t__ CFG_SC8 ; 
 scalar_t__ CFG_SC9 ; 
 unsigned int CFG_SC_BYPASS ; 
 unsigned int CFG_SELFGEN_FID ; 
 unsigned int CFG_SRC_H_SHIFT ; 
 unsigned int CFG_SRC_W_SHIFT ; 
 unsigned int CFG_TAR_H_SHIFT ; 
 unsigned int CFG_TAR_W_SHIFT ; 
 unsigned int CFG_TRIM ; 
 unsigned int CFG_USE_RAV ; 
 unsigned int CFG_Y_PK_EN ; 
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct sc_data* ERR_CAST (scalar_t__) ; 
 struct sc_data* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HS_LE_16_16_SCALE ; 
 int HS_LT_9_16_SCALE ; 
 int HS_UP_SCALE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int SC_H_NUM_TAPS ; 
 int SC_NUM_PHASES ; 
 int SC_NUM_TAPS_MEM_ALIGN ; 
 int SC_V_NUM_TAPS ; 
 int VS_1_TO_1_SCALE ; 
 int VS_LT_9_16_SCALE ; 
 int VS_UP_SCALE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 scalar_t__ devm_ioremap_resource (struct device*,TYPE_1__*) ; 
 struct sc_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 unsigned int div64_u64 (int,unsigned long) ; 
 int /*<<< orphan*/  ioread32 (scalar_t__) ; 
 TYPE_1__* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char const*) ; 
 int** scaler_hs_coeffs ; 
 int** scaler_vs_coeffs ; 

void sc_dump_regs(struct sc_data *sc)
{
	struct device *dev = &sc->pdev->dev;

#define DUMPREG(r) dev_dbg(dev, "%-35s %08x\n", #r, \
	ioread32(sc->base + CFG_##r))

	dev_dbg(dev, "SC Registers @ %pa:\n", &sc->res->start);

	DUMPREG(SC0);
	DUMPREG(SC1);
	DUMPREG(SC2);
	DUMPREG(SC3);
	DUMPREG(SC4);
	DUMPREG(SC5);
	DUMPREG(SC6);
	DUMPREG(SC8);
	DUMPREG(SC9);
	DUMPREG(SC10);
	DUMPREG(SC11);
	DUMPREG(SC12);
	DUMPREG(SC13);
	DUMPREG(SC17);
	DUMPREG(SC18);
	DUMPREG(SC19);
	DUMPREG(SC20);
	DUMPREG(SC21);
	DUMPREG(SC22);
	DUMPREG(SC23);
	DUMPREG(SC24);
	DUMPREG(SC25);

#undef DUMPREG
}

void sc_set_hs_coeffs(struct sc_data *sc, void *addr, unsigned int src_w,
		unsigned int dst_w)
{
	int sixteenths;
	int idx;
	int i, j;
	u16 *coeff_h = addr;
	const u16 *cp;

	if (dst_w > src_w) {
		idx = HS_UP_SCALE;
	} else {
		if ((dst_w << 1) < src_w)
			dst_w <<= 1;	/* first level decimation */
		if ((dst_w << 1) < src_w)
			dst_w <<= 1;	/* second level decimation */

		if (dst_w == src_w) {
			idx = HS_LE_16_16_SCALE;
		} else {
			sixteenths = (dst_w << 4) / src_w;
			if (sixteenths < 8)
				sixteenths = 8;
			idx = HS_LT_9_16_SCALE + sixteenths - 8;
		}
	}

	cp = scaler_hs_coeffs[idx];

	for (i = 0; i < SC_NUM_PHASES * 2; i++) {
		for (j = 0; j < SC_H_NUM_TAPS; j++)
			*coeff_h++ = *cp++;
		/*
		 * for each phase, the scaler expects space for 8 coefficients
		 * in it's memory. For the horizontal scaler, we copy the first
		 * 7 coefficients and skip the last slot to move to the next
		 * row to hold coefficients for the next phase
		 */
		coeff_h += SC_NUM_TAPS_MEM_ALIGN - SC_H_NUM_TAPS;
	}

	sc->load_coeff_h = true;
}

void sc_set_vs_coeffs(struct sc_data *sc, void *addr, unsigned int src_h,
		unsigned int dst_h)
{
	int sixteenths;
	int idx;
	int i, j;
	u16 *coeff_v = addr;
	const u16 *cp;

	if (dst_h > src_h) {
		idx = VS_UP_SCALE;
	} else if (dst_h == src_h) {
		idx = VS_1_TO_1_SCALE;
	} else {
		sixteenths = (dst_h << 4) / src_h;
		if (sixteenths < 8)
			sixteenths = 8;
		idx = VS_LT_9_16_SCALE + sixteenths - 8;
	}

	cp = scaler_vs_coeffs[idx];

	for (i = 0; i < SC_NUM_PHASES * 2; i++) {
		for (j = 0; j < SC_V_NUM_TAPS; j++)
			*coeff_v++ = *cp++;
		/*
		 * for the vertical scaler, we copy the first 5 coefficients and
		 * skip the last 3 slots to move to the next row to hold
		 * coefficients for the next phase
		 */
		coeff_v += SC_NUM_TAPS_MEM_ALIGN - SC_V_NUM_TAPS;
	}

	sc->load_coeff_v = true;
}

void sc_config_scaler(struct sc_data *sc, u32 *sc_reg0, u32 *sc_reg8,
		u32 *sc_reg17, unsigned int src_w, unsigned int src_h,
		unsigned int dst_w, unsigned int dst_h)
{
	struct device *dev = &sc->pdev->dev;
	u32 val;
	int dcm_x, dcm_shift;
	bool use_rav;
	unsigned long lltmp;
	u32 lin_acc_inc, lin_acc_inc_u;
	u32 col_acc_offset;
	u16 factor = 0;
	int row_acc_init_rav = 0, row_acc_init_rav_b = 0;
	u32 row_acc_inc = 0, row_acc_offset = 0, row_acc_offset_b = 0;
	/*
	 * location of SC register in payload memory with respect to the first
	 * register in the mmr address data block
	 */
	u32 *sc_reg9 = sc_reg8 + 1;
	u32 *sc_reg12 = sc_reg8 + 4;
	u32 *sc_reg13 = sc_reg8 + 5;
	u32 *sc_reg24 = sc_reg17 + 7;

	val = sc_reg0[0];

	/* clear all the features(they may get enabled elsewhere later) */
	val &= ~(CFG_SELFGEN_FID | CFG_TRIM | CFG_ENABLE_SIN2_VER_INTP |
		CFG_INTERLACE_I | CFG_DCM_4X | CFG_DCM_2X | CFG_AUTO_HS |
		CFG_ENABLE_EV | CFG_USE_RAV | CFG_INVT_FID | CFG_SC_BYPASS |
		CFG_INTERLACE_O | CFG_Y_PK_EN | CFG_HP_BYPASS | CFG_LINEAR);

	if (src_w == dst_w && src_h == dst_h) {
		val |= CFG_SC_BYPASS;
		sc_reg0[0] = val;
		return;
	}

	/* we only support linear scaling for now */
	val |= CFG_LINEAR;

	/* configure horizontal scaler */

	/* enable 2X or 4X decimation */
	dcm_x = src_w / dst_w;
	if (dcm_x > 4) {
		val |= CFG_DCM_4X;
		dcm_shift = 2;
	} else if (dcm_x > 2) {
		val |= CFG_DCM_2X;
		dcm_shift = 1;
	} else {
		dcm_shift = 0;
	}

	lltmp = dst_w - 1;
	lin_acc_inc = div64_u64(((u64)(src_w >> dcm_shift) - 1) << 24, lltmp);
	lin_acc_inc_u = 0;
	col_acc_offset = 0;

	dev_dbg(dev, "hs config: src_w = %d, dst_w = %d, decimation = %s, lin_acc_inc = %08x\n",
		src_w, dst_w, dcm_shift == 2 ? "4x" :
		(dcm_shift == 1 ? "2x" : "none"), lin_acc_inc);

	/* configure vertical scaler */

	/* use RAV for vertical scaler if vertical downscaling is > 4x */
	if (dst_h < (src_h >> 2)) {
		use_rav = true;
		val |= CFG_USE_RAV;
	} else {
		use_rav = false;
	}

	if (use_rav) {
		/* use RAV */
		factor = (u16) ((dst_h << 10) / src_h);

		row_acc_init_rav = factor + ((1 + factor) >> 1);
		if (row_acc_init_rav >= 1024)
			row_acc_init_rav -= 1024;

		row_acc_init_rav_b = row_acc_init_rav +
				(1 + (row_acc_init_rav >> 1)) -
				(1024 >> 1);

		if (row_acc_init_rav_b < 0) {
			row_acc_init_rav_b += row_acc_init_rav;
			row_acc_init_rav *= 2;
		}

		dev_dbg(dev, "vs config(RAV): src_h = %d, dst_h = %d, factor = %d, acc_init = %08x, acc_init_b = %08x\n",
			src_h, dst_h, factor, row_acc_init_rav,
			row_acc_init_rav_b);
	} else {
		/* use polyphase */
		row_acc_inc = ((src_h - 1) << 16) / (dst_h - 1);
		row_acc_offset = 0;
		row_acc_offset_b = 0;

		dev_dbg(dev, "vs config(POLY): src_h = %d, dst_h = %d,row_acc_inc = %08x\n",
			src_h, dst_h, row_acc_inc);
	}


	sc_reg0[0] = val;
	sc_reg0[1] = row_acc_inc;
	sc_reg0[2] = row_acc_offset;
	sc_reg0[3] = row_acc_offset_b;

	sc_reg0[4] = ((lin_acc_inc_u & CFG_LIN_ACC_INC_U_MASK) <<
			CFG_LIN_ACC_INC_U_SHIFT) | (dst_w << CFG_TAR_W_SHIFT) |
			(dst_h << CFG_TAR_H_SHIFT);

	sc_reg0[5] = (src_w << CFG_SRC_W_SHIFT) | (src_h << CFG_SRC_H_SHIFT);

	sc_reg0[6] = (row_acc_init_rav_b << CFG_ROW_ACC_INIT_RAV_B_SHIFT) |
		(row_acc_init_rav << CFG_ROW_ACC_INIT_RAV_SHIFT);

	*sc_reg9 = lin_acc_inc;

	*sc_reg12 = col_acc_offset << CFG_COL_ACC_OFFSET_SHIFT;

	*sc_reg13 = factor;

	*sc_reg24 = (src_w << CFG_ORG_W_SHIFT) | (src_h << CFG_ORG_H_SHIFT);
}

struct sc_data *sc_create(struct platform_device *pdev, const char *res_name)
{
	struct sc_data *sc;

	dev_dbg(&pdev->dev, "sc_create\n");

	sc = devm_kzalloc(&pdev->dev, sizeof(*sc), GFP_KERNEL);
	if (!sc) {
		dev_err(&pdev->dev, "couldn't alloc sc_data\n");
		return ERR_PTR(-ENOMEM);
	}

	sc->pdev = pdev;

	sc->res = platform_get_resource_byname(pdev, IORESOURCE_MEM, res_name);
	if (!sc->res) {
		dev_err(&pdev->dev, "missing '%s' platform resources data\n",
			res_name);
		return ERR_PTR(-ENODEV);
	}

	sc->base = devm_ioremap_resource(&pdev->dev, sc->res);
	if (IS_ERR(sc->base)) {
		dev_err(&pdev->dev, "failed to ioremap\n");
		return ERR_CAST(sc->base);
	}

	return sc;
}

