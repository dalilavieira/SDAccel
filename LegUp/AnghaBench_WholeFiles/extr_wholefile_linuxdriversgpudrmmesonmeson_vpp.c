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
struct meson_drm {scalar_t__ io_base; TYPE_1__* dev; } ;
struct drm_rect {int x1; int x2; int y1; int y2; } ;
struct TYPE_2__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  VIU_MISC_CTRL1 ; 
 int /*<<< orphan*/  VPP_DOLBY_CTRL ; 
 int /*<<< orphan*/  VPP_DUMMY_DATA1 ; 
 int /*<<< orphan*/  VPP_HOLD_LINES ; 
 int /*<<< orphan*/  VPP_MISC ; 
 int /*<<< orphan*/  VPP_OFIFO_SIZE ; 
 int VPP_OSD1_POSTBLEND ; 
 int VPP_OSD2_POSTBLEND ; 
 int /*<<< orphan*/  VPP_OSD_HSC_CTRL0 ; 
 int /*<<< orphan*/  VPP_OSD_SCALE_COEF ; 
 int /*<<< orphan*/  VPP_OSD_SCALE_COEF_IDX ; 
 int /*<<< orphan*/  VPP_OSD_SCI_WH_M1 ; 
 int /*<<< orphan*/  VPP_OSD_SCO_H_START_END ; 
 int /*<<< orphan*/  VPP_OSD_SCO_V_START_END ; 
 int /*<<< orphan*/  VPP_OSD_SC_CTRL0 ; 
 int /*<<< orphan*/  VPP_OSD_VSC_CTRL0 ; 
 int /*<<< orphan*/  VPP_OSD_VSC_INI_PHASE ; 
 int /*<<< orphan*/  VPP_OSD_VSC_PHASE_STEP ; 
 int VPP_POSTBLEND_ENABLE ; 
 int VPP_PREBLEND_ENABLE ; 
 int VPP_VD1_POSTBLEND ; 
 int VPP_VD2_POSTBLEND ; 
 int /*<<< orphan*/  VPU_VIU_VENC_MUX_CTRL ; 
 scalar_t__ _REG (int /*<<< orphan*/ ) ; 
 int drm_rect_height (struct drm_rect*) ; 
 int drm_rect_width (struct drm_rect*) ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char const*) ; 
 int readl_relaxed (scalar_t__) ; 
 unsigned int* vpp_filter_coefs_4point_bspline ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  writel_bits_relaxed (int,int,scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned int const,scalar_t__) ; 

__attribute__((used)) static inline int meson_vpu_is_compatible(struct meson_drm *priv,
					  const char *compat)
{
	return of_device_is_compatible(priv->dev->of_node, compat);
}

void meson_vpp_setup_mux(struct meson_drm *priv, unsigned int mux)
{
	writel(mux, priv->io_base + _REG(VPU_VIU_VENC_MUX_CTRL));
}

void meson_vpp_setup_interlace_vscaler_osd1(struct meson_drm *priv,
					    struct drm_rect *input)
{
	writel_relaxed(BIT(3) /* Enable scaler */ |
		       BIT(2), /* Select OSD1 */
			priv->io_base + _REG(VPP_OSD_SC_CTRL0));

	writel_relaxed(((drm_rect_width(input) - 1) << 16) |
		       (drm_rect_height(input) - 1),
			priv->io_base + _REG(VPP_OSD_SCI_WH_M1));
	/* 2:1 scaling */
	writel_relaxed(((input->x1) << 16) | (input->x2),
			priv->io_base + _REG(VPP_OSD_SCO_H_START_END));
	writel_relaxed(((input->y1 >> 1) << 16) | (input->y2 >> 1),
			priv->io_base + _REG(VPP_OSD_SCO_V_START_END));

	/* 2:1 scaling values */
	writel_relaxed(BIT(16), priv->io_base + _REG(VPP_OSD_VSC_INI_PHASE));
	writel_relaxed(BIT(25), priv->io_base + _REG(VPP_OSD_VSC_PHASE_STEP));

	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));

	writel_relaxed((4 << 0) /* osd_vsc_bank_length */ |
		       (4 << 3) /* osd_vsc_top_ini_rcv_num0 */ |
		       (1 << 8) /* osd_vsc_top_rpt_p0_num0 */ |
		       (6 << 11) /* osd_vsc_bot_ini_rcv_num0 */ |
		       (2 << 16) /* osd_vsc_bot_rpt_p0_num0 */ |
		       BIT(23)	/* osd_prog_interlace */ |
		       BIT(24), /* Enable vertical scaler */
			priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
}

void meson_vpp_disable_interlace_vscaler_osd1(struct meson_drm *priv)
{
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_SC_CTRL0));
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));
}

__attribute__((used)) static void meson_vpp_write_scaling_filter_coefs(struct meson_drm *priv,
						 const unsigned int *coefs,
						 bool is_horizontal)
{
	int i;

	writel_relaxed(is_horizontal ? BIT(8) : 0,
			priv->io_base + _REG(VPP_OSD_SCALE_COEF_IDX));
	for (i = 0; i < 33; i++)
		writel_relaxed(coefs[i],
				priv->io_base + _REG(VPP_OSD_SCALE_COEF));
}

void meson_vpp_init(struct meson_drm *priv)
{
	/* set dummy data default YUV black */
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
		writel_relaxed(0x108080, priv->io_base + _REG(VPP_DUMMY_DATA1));
	else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu")) {
		writel_bits_relaxed(0xff << 16, 0xff << 16,
				    priv->io_base + _REG(VIU_MISC_CTRL1));
		writel_relaxed(0x20000, priv->io_base + _REG(VPP_DOLBY_CTRL));
		writel_relaxed(0x1020080,
				priv->io_base + _REG(VPP_DUMMY_DATA1));
	}

	/* Initialize vpu fifo control registers */
	writel_relaxed(readl_relaxed(priv->io_base + _REG(VPP_OFIFO_SIZE)) |
			0x77f, priv->io_base + _REG(VPP_OFIFO_SIZE));
	writel_relaxed(0x08080808, priv->io_base + _REG(VPP_HOLD_LINES));

	/* Turn off preblend */
	writel_bits_relaxed(VPP_PREBLEND_ENABLE, 0,
			    priv->io_base + _REG(VPP_MISC));

	/* Turn off POSTBLEND */
	writel_bits_relaxed(VPP_POSTBLEND_ENABLE, 0,
			    priv->io_base + _REG(VPP_MISC));

	/* Force all planes off */
	writel_bits_relaxed(VPP_OSD1_POSTBLEND | VPP_OSD2_POSTBLEND |
			    VPP_VD1_POSTBLEND | VPP_VD2_POSTBLEND, 0,
			    priv->io_base + _REG(VPP_MISC));

	/* Disable Scalers */
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_SC_CTRL0));
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
	writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));

	/* Write in the proper filter coefficients. */
	meson_vpp_write_scaling_filter_coefs(priv,
				vpp_filter_coefs_4point_bspline, false);
	meson_vpp_write_scaling_filter_coefs(priv,
				vpp_filter_coefs_4point_bspline, true);
}

