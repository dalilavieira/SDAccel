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
struct v4l2_rect {int width; int height; int left; int top; } ;
struct v4l2_mbus_framefmt {int code; int width; int height; int /*<<< orphan*/  field; } ;
struct v4l2_mbus_config {int type; int flags; } ;
struct ipu_soc {unsigned int idmac_reg; int /*<<< orphan*/  dev; struct ipu_csi** csi_priv; } ;
struct ipu_csi_bus_config {int data_fmt; int mipi_dt; int data_width; int ext_vsync; int vsync_pol; int hsync_pol; int pixclk_pol; int clk_mode; int data_pol; int pack_tight; int force_eof; int data_en_pol; } ;
struct ipu_csi {unsigned int base; int id; int module; int inuse; struct ipu_soc* ipu; struct clk* clk_ipu; int /*<<< orphan*/  lock; } ;
struct device {int dummy; } ;
struct clk {int dummy; } ;
typedef  enum v4l2_mbus_type { ____Placeholder_v4l2_mbus_type } v4l2_mbus_type ;
typedef  enum ipu_csi_dest { ____Placeholder_ipu_csi_dest } ipu_csi_dest ;

/* Variables and functions */
 unsigned int CSI_ACT_FRM_SIZE ; 
 unsigned int CSI_CCIR_CODE_1 ; 
 unsigned int CSI_CCIR_CODE_2 ; 
 unsigned int CSI_CCIR_CODE_3 ; 
 int CSI_CCIR_ERR_DET_EN ; 
 int CSI_DATA_DEST_IC ; 
 int CSI_DATA_DEST_IDMAC ; 
 int CSI_HORI_DOWNSIZE_EN ; 
 int CSI_HSC_MASK ; 
 int CSI_HSC_SHIFT ; 
 int CSI_ID_2_SKIP_MASK ; 
 int CSI_ID_2_SKIP_SHIFT ; 
 int CSI_MAX_RATIO_SKIP_SMFC_MASK ; 
 int CSI_MAX_RATIO_SKIP_SMFC_SHIFT ; 
 unsigned int CSI_MIPI_DI ; 
 unsigned int CSI_OUT_FRM_CTRL ; 
 unsigned int CSI_SENS_CONF ; 
 int CSI_SENS_CONF_DATA_DEST_MASK ; 
 int CSI_SENS_CONF_DATA_DEST_SHIFT ; 
 int CSI_SENS_CONF_DATA_EN_POL_SHIFT ; 
 void* CSI_SENS_CONF_DATA_FMT_BAYER ; 
 int CSI_SENS_CONF_DATA_FMT_JPEG ; 
 int CSI_SENS_CONF_DATA_FMT_RGB444 ; 
 int CSI_SENS_CONF_DATA_FMT_RGB555 ; 
 int CSI_SENS_CONF_DATA_FMT_RGB565 ; 
 int CSI_SENS_CONF_DATA_FMT_RGB_YUV444 ; 
 int CSI_SENS_CONF_DATA_FMT_SHIFT ; 
 int CSI_SENS_CONF_DATA_FMT_YUV422_UYVY ; 
 int CSI_SENS_CONF_DATA_FMT_YUV422_YUYV ; 
 int CSI_SENS_CONF_DATA_POL_SHIFT ; 
 int CSI_SENS_CONF_DATA_WIDTH_SHIFT ; 
 int CSI_SENS_CONF_DIVRATIO_MASK ; 
 int CSI_SENS_CONF_DIVRATIO_SHIFT ; 
 int CSI_SENS_CONF_EXT_VSYNC_SHIFT ; 
 int CSI_SENS_CONF_FORCE_EOF_SHIFT ; 
 int CSI_SENS_CONF_HSYNC_POL_SHIFT ; 
 int CSI_SENS_CONF_PACK_TIGHT_SHIFT ; 
 int CSI_SENS_CONF_PIX_CLK_POL_SHIFT ; 
 int CSI_SENS_CONF_SENS_PRTCL_MASK ; 
 int CSI_SENS_CONF_SENS_PRTCL_SHIFT ; 
 int CSI_SENS_CONF_VSYNC_POL_SHIFT ; 
 unsigned int CSI_SENS_FRM_SIZE ; 
 unsigned int CSI_SKIP ; 
 int CSI_SKIP_SMFC_MASK ; 
 int CSI_SKIP_SMFC_SHIFT ; 
 int CSI_TEST_GEN_B_MASK ; 
 int CSI_TEST_GEN_B_SHIFT ; 
 int CSI_TEST_GEN_G_MASK ; 
 int CSI_TEST_GEN_G_SHIFT ; 
 int CSI_TEST_GEN_MODE_EN ; 
 int CSI_TEST_GEN_R_MASK ; 
 int CSI_TEST_GEN_R_SHIFT ; 
 unsigned int CSI_TST_CTRL ; 
 int CSI_VERT_DOWNSIZE_EN ; 
 int CSI_VSC_MASK ; 
 int CSI_VSC_SHIFT ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ipu_csi* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_DDR 176 
#define  IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_SDR 175 
#define  IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_DDR 174 
#define  IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_SDR 173 
#define  IPU_CSI_CLK_MODE_CCIR656_INTERLACED 172 
#define  IPU_CSI_CLK_MODE_CCIR656_PROGRESSIVE 171 
#define  IPU_CSI_CLK_MODE_GATED_CLK 170 
#define  IPU_CSI_CLK_MODE_NONGATED_CLK 169 
 int IPU_CSI_DATA_WIDTH_10 ; 
 int IPU_CSI_DATA_WIDTH_12 ; 
 int IPU_CSI_DATA_WIDTH_16 ; 
 void* IPU_CSI_DATA_WIDTH_8 ; 
 int IPU_CSI_DEST_IDMAC ; 
#define  MEDIA_BUS_FMT_BGR565_2X8_BE 168 
#define  MEDIA_BUS_FMT_BGR565_2X8_LE 167 
#define  MEDIA_BUS_FMT_BGR888_1X24 166 
#define  MEDIA_BUS_FMT_JPEG_1X8 165 
#define  MEDIA_BUS_FMT_RGB444_2X8_PADHI_BE 164 
#define  MEDIA_BUS_FMT_RGB444_2X8_PADHI_LE 163 
#define  MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE 162 
#define  MEDIA_BUS_FMT_RGB555_2X8_PADHI_LE 161 
#define  MEDIA_BUS_FMT_RGB565_2X8_BE 160 
#define  MEDIA_BUS_FMT_RGB565_2X8_LE 159 
#define  MEDIA_BUS_FMT_RGB888_1X24 158 
#define  MEDIA_BUS_FMT_SBGGR10_1X10 157 
#define  MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE 156 
#define  MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE 155 
#define  MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE 154 
#define  MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE 153 
#define  MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8 152 
#define  MEDIA_BUS_FMT_SBGGR12_1X12 151 
#define  MEDIA_BUS_FMT_SBGGR8_1X8 150 
#define  MEDIA_BUS_FMT_SGBRG10_1X10 149 
#define  MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8 148 
#define  MEDIA_BUS_FMT_SGBRG12_1X12 147 
#define  MEDIA_BUS_FMT_SGBRG8_1X8 146 
#define  MEDIA_BUS_FMT_SGRBG10_1X10 145 
#define  MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8 144 
#define  MEDIA_BUS_FMT_SGRBG12_1X12 143 
#define  MEDIA_BUS_FMT_SGRBG8_1X8 142 
#define  MEDIA_BUS_FMT_SRGGB10_1X10 141 
#define  MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8 140 
#define  MEDIA_BUS_FMT_SRGGB12_1X12 139 
#define  MEDIA_BUS_FMT_SRGGB8_1X8 138 
#define  MEDIA_BUS_FMT_UYVY8_1X16 137 
#define  MEDIA_BUS_FMT_UYVY8_2X8 136 
#define  MEDIA_BUS_FMT_Y10_1X10 135 
#define  MEDIA_BUS_FMT_Y12_1X12 134 
#define  MEDIA_BUS_FMT_Y8_1X8 133 
#define  MEDIA_BUS_FMT_YUYV8_1X16 132 
#define  MEDIA_BUS_FMT_YUYV8_2X8 131 
 void* MIPI_DT_RAW10 ; 
 int MIPI_DT_RAW12 ; 
 void* MIPI_DT_RAW8 ; 
 int MIPI_DT_RGB444 ; 
 int MIPI_DT_RGB555 ; 
 int MIPI_DT_RGB565 ; 
 int MIPI_DT_RGB888 ; 
 void* MIPI_DT_YUV422 ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  V4L2_FIELD_ALTERNATE ; 
 int /*<<< orphan*/  V4L2_FIELD_HAS_BOTH (int /*<<< orphan*/ ) ; 
#define  V4L2_MBUS_BT656 130 
#define  V4L2_MBUS_CSI2 129 
 int V4L2_MBUS_HSYNC_ACTIVE_LOW ; 
#define  V4L2_MBUS_PARALLEL 128 
 int V4L2_MBUS_PCLK_SAMPLE_FALLING ; 
 int V4L2_MBUS_VSYNC_ACTIVE_LOW ; 
 int clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 unsigned int devm_ioremap (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 struct ipu_csi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipu_module_disable (struct ipu_soc*,int) ; 
 int /*<<< orphan*/  ipu_module_enable (struct ipu_soc*,int) ; 
 int /*<<< orphan*/  memset (struct ipu_csi_bus_config*,int /*<<< orphan*/ ,int) ; 
 int readl (unsigned int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int,unsigned int) ; 

__attribute__((used)) static inline u32 ipu_idmac_read(struct ipu_soc *ipu, unsigned offset)
{
	return readl(ipu->idmac_reg + offset);
}

__attribute__((used)) static inline void ipu_idmac_write(struct ipu_soc *ipu, u32 value,
				   unsigned offset)
{
	writel(value, ipu->idmac_reg + offset);
}

__attribute__((used)) static inline u32 ipu_csi_read(struct ipu_csi *csi, unsigned offset)
{
	return readl(csi->base + offset);
}

__attribute__((used)) static inline void ipu_csi_write(struct ipu_csi *csi, u32 value,
				 unsigned offset)
{
	writel(value, csi->base + offset);
}

__attribute__((used)) static int ipu_csi_set_testgen_mclk(struct ipu_csi *csi, u32 pixel_clk,
					u32 ipu_clk)
{
	u32 temp;
	int div_ratio;

	div_ratio = (ipu_clk / pixel_clk) - 1;

	if (div_ratio > 0xFF || div_ratio < 0) {
		dev_err(csi->ipu->dev,
			"value of pixel_clk extends normal range\n");
		return -EINVAL;
	}

	temp = ipu_csi_read(csi, CSI_SENS_CONF);
	temp &= ~CSI_SENS_CONF_DIVRATIO_MASK;
	ipu_csi_write(csi, temp | (div_ratio << CSI_SENS_CONF_DIVRATIO_SHIFT),
			  CSI_SENS_CONF);

	return 0;
}

__attribute__((used)) static int mbus_code_to_bus_cfg(struct ipu_csi_bus_config *cfg, u32 mbus_code,
				enum v4l2_mbus_type mbus_type)
{
	switch (mbus_code) {
	case MEDIA_BUS_FMT_BGR565_2X8_BE:
	case MEDIA_BUS_FMT_BGR565_2X8_LE:
	case MEDIA_BUS_FMT_RGB565_2X8_BE:
	case MEDIA_BUS_FMT_RGB565_2X8_LE:
		if (mbus_type == V4L2_MBUS_CSI2)
			cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_RGB565;
		else
			cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_RGB565;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_RGB444_2X8_PADHI_BE:
	case MEDIA_BUS_FMT_RGB444_2X8_PADHI_LE:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_RGB444;
		cfg->mipi_dt = MIPI_DT_RGB444;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE:
	case MEDIA_BUS_FMT_RGB555_2X8_PADHI_LE:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_RGB555;
		cfg->mipi_dt = MIPI_DT_RGB555;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_RGB888_1X24:
	case MEDIA_BUS_FMT_BGR888_1X24:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_RGB_YUV444;
		cfg->mipi_dt = MIPI_DT_RGB888;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_UYVY8_2X8:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_YUV422_UYVY;
		cfg->mipi_dt = MIPI_DT_YUV422;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_YUYV8_2X8:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_YUV422_YUYV;
		cfg->mipi_dt = MIPI_DT_YUV422;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_UYVY8_1X16:
	case MEDIA_BUS_FMT_YUYV8_1X16:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_YUV422;
		cfg->data_width = IPU_CSI_DATA_WIDTH_16;
		break;
	case MEDIA_BUS_FMT_SBGGR8_1X8:
	case MEDIA_BUS_FMT_SGBRG8_1X8:
	case MEDIA_BUS_FMT_SGRBG8_1X8:
	case MEDIA_BUS_FMT_SRGGB8_1X8:
	case MEDIA_BUS_FMT_Y8_1X8:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_RAW8;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8:
	case MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8:
	case MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8:
	case MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8:
	case MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE:
	case MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE:
	case MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE:
	case MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_RAW10;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	case MEDIA_BUS_FMT_SBGGR10_1X10:
	case MEDIA_BUS_FMT_SGBRG10_1X10:
	case MEDIA_BUS_FMT_SGRBG10_1X10:
	case MEDIA_BUS_FMT_SRGGB10_1X10:
	case MEDIA_BUS_FMT_Y10_1X10:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_RAW10;
		cfg->data_width = IPU_CSI_DATA_WIDTH_10;
		break;
	case MEDIA_BUS_FMT_SBGGR12_1X12:
	case MEDIA_BUS_FMT_SGBRG12_1X12:
	case MEDIA_BUS_FMT_SGRBG12_1X12:
	case MEDIA_BUS_FMT_SRGGB12_1X12:
	case MEDIA_BUS_FMT_Y12_1X12:
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_BAYER;
		cfg->mipi_dt = MIPI_DT_RAW12;
		cfg->data_width = IPU_CSI_DATA_WIDTH_12;
		break;
	case MEDIA_BUS_FMT_JPEG_1X8:
		/* TODO */
		cfg->data_fmt = CSI_SENS_CONF_DATA_FMT_JPEG;
		cfg->mipi_dt = MIPI_DT_RAW8;
		cfg->data_width = IPU_CSI_DATA_WIDTH_8;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int fill_csi_bus_cfg(struct ipu_csi_bus_config *csicfg,
				 struct v4l2_mbus_config *mbus_cfg,
				 struct v4l2_mbus_framefmt *mbus_fmt)
{
	int ret;

	memset(csicfg, 0, sizeof(*csicfg));

	ret = mbus_code_to_bus_cfg(csicfg, mbus_fmt->code, mbus_cfg->type);
	if (ret < 0)
		return ret;

	switch (mbus_cfg->type) {
	case V4L2_MBUS_PARALLEL:
		csicfg->ext_vsync = 1;
		csicfg->vsync_pol = (mbus_cfg->flags &
				     V4L2_MBUS_VSYNC_ACTIVE_LOW) ? 1 : 0;
		csicfg->hsync_pol = (mbus_cfg->flags &
				     V4L2_MBUS_HSYNC_ACTIVE_LOW) ? 1 : 0;
		csicfg->pixclk_pol = (mbus_cfg->flags &
				      V4L2_MBUS_PCLK_SAMPLE_FALLING) ? 1 : 0;
		csicfg->clk_mode = IPU_CSI_CLK_MODE_GATED_CLK;
		break;
	case V4L2_MBUS_BT656:
		csicfg->ext_vsync = 0;
		if (V4L2_FIELD_HAS_BOTH(mbus_fmt->field) ||
		    mbus_fmt->field == V4L2_FIELD_ALTERNATE)
			csicfg->clk_mode = IPU_CSI_CLK_MODE_CCIR656_INTERLACED;
		else
			csicfg->clk_mode = IPU_CSI_CLK_MODE_CCIR656_PROGRESSIVE;
		break;
	case V4L2_MBUS_CSI2:
		/*
		 * MIPI CSI-2 requires non gated clock mode, all other
		 * parameters are not applicable for MIPI CSI-2 bus.
		 */
		csicfg->clk_mode = IPU_CSI_CLK_MODE_NONGATED_CLK;
		break;
	default:
		/* will never get here, keep compiler quiet */
		break;
	}

	return 0;
}

int ipu_csi_init_interface(struct ipu_csi *csi,
			   struct v4l2_mbus_config *mbus_cfg,
			   struct v4l2_mbus_framefmt *mbus_fmt)
{
	struct ipu_csi_bus_config cfg;
	unsigned long flags;
	u32 width, height, data = 0;
	int ret;

	ret = fill_csi_bus_cfg(&cfg, mbus_cfg, mbus_fmt);
	if (ret < 0)
		return ret;

	/* set default sensor frame width and height */
	width = mbus_fmt->width;
	height = mbus_fmt->height;

	/* Set the CSI_SENS_CONF register remaining fields */
	data |= cfg.data_width << CSI_SENS_CONF_DATA_WIDTH_SHIFT |
		cfg.data_fmt << CSI_SENS_CONF_DATA_FMT_SHIFT |
		cfg.data_pol << CSI_SENS_CONF_DATA_POL_SHIFT |
		cfg.vsync_pol << CSI_SENS_CONF_VSYNC_POL_SHIFT |
		cfg.hsync_pol << CSI_SENS_CONF_HSYNC_POL_SHIFT |
		cfg.pixclk_pol << CSI_SENS_CONF_PIX_CLK_POL_SHIFT |
		cfg.ext_vsync << CSI_SENS_CONF_EXT_VSYNC_SHIFT |
		cfg.clk_mode << CSI_SENS_CONF_SENS_PRTCL_SHIFT |
		cfg.pack_tight << CSI_SENS_CONF_PACK_TIGHT_SHIFT |
		cfg.force_eof << CSI_SENS_CONF_FORCE_EOF_SHIFT |
		cfg.data_en_pol << CSI_SENS_CONF_DATA_EN_POL_SHIFT;

	spin_lock_irqsave(&csi->lock, flags);

	ipu_csi_write(csi, data, CSI_SENS_CONF);

	/* Set CCIR registers */

	switch (cfg.clk_mode) {
	case IPU_CSI_CLK_MODE_CCIR656_PROGRESSIVE:
		ipu_csi_write(csi, 0x40030, CSI_CCIR_CODE_1);
		ipu_csi_write(csi, 0xFF0000, CSI_CCIR_CODE_3);
		break;
	case IPU_CSI_CLK_MODE_CCIR656_INTERLACED:
		if (mbus_fmt->width == 720 && mbus_fmt->height == 576) {
			/*
			 * PAL case
			 *
			 * Field0BlankEnd = 0x6, Field0BlankStart = 0x2,
			 * Field0ActiveEnd = 0x4, Field0ActiveStart = 0
			 * Field1BlankEnd = 0x7, Field1BlankStart = 0x3,
			 * Field1ActiveEnd = 0x5, Field1ActiveStart = 0x1
			 */
			height = 625; /* framelines for PAL */

			ipu_csi_write(csi, 0x40596 | CSI_CCIR_ERR_DET_EN,
					  CSI_CCIR_CODE_1);
			ipu_csi_write(csi, 0xD07DF, CSI_CCIR_CODE_2);
			ipu_csi_write(csi, 0xFF0000, CSI_CCIR_CODE_3);
		} else if (mbus_fmt->width == 720 && mbus_fmt->height == 480) {
			/*
			 * NTSC case
			 *
			 * Field0BlankEnd = 0x7, Field0BlankStart = 0x3,
			 * Field0ActiveEnd = 0x5, Field0ActiveStart = 0x1
			 * Field1BlankEnd = 0x6, Field1BlankStart = 0x2,
			 * Field1ActiveEnd = 0x4, Field1ActiveStart = 0
			 */
			height = 525; /* framelines for NTSC */

			ipu_csi_write(csi, 0xD07DF | CSI_CCIR_ERR_DET_EN,
					  CSI_CCIR_CODE_1);
			ipu_csi_write(csi, 0x40596, CSI_CCIR_CODE_2);
			ipu_csi_write(csi, 0xFF0000, CSI_CCIR_CODE_3);
		} else {
			dev_err(csi->ipu->dev,
				"Unsupported CCIR656 interlaced video mode\n");
			spin_unlock_irqrestore(&csi->lock, flags);
			return -EINVAL;
		}
		break;
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_SDR:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_SDR:
		ipu_csi_write(csi, 0x40030 | CSI_CCIR_ERR_DET_EN,
				   CSI_CCIR_CODE_1);
		ipu_csi_write(csi, 0xFF0000, CSI_CCIR_CODE_3);
		break;
	case IPU_CSI_CLK_MODE_GATED_CLK:
	case IPU_CSI_CLK_MODE_NONGATED_CLK:
		ipu_csi_write(csi, 0, CSI_CCIR_CODE_1);
		break;
	}

	/* Setup sensor frame size */
	ipu_csi_write(csi, (width - 1) | ((height - 1) << 16),
		      CSI_SENS_FRM_SIZE);

	dev_dbg(csi->ipu->dev, "CSI_SENS_CONF = 0x%08X\n",
		ipu_csi_read(csi, CSI_SENS_CONF));
	dev_dbg(csi->ipu->dev, "CSI_ACT_FRM_SIZE = 0x%08X\n",
		ipu_csi_read(csi, CSI_ACT_FRM_SIZE));

	spin_unlock_irqrestore(&csi->lock, flags);

	return 0;
}

bool ipu_csi_is_interlaced(struct ipu_csi *csi)
{
	unsigned long flags;
	u32 sensor_protocol;

	spin_lock_irqsave(&csi->lock, flags);
	sensor_protocol =
		(ipu_csi_read(csi, CSI_SENS_CONF) &
		 CSI_SENS_CONF_SENS_PRTCL_MASK) >>
		CSI_SENS_CONF_SENS_PRTCL_SHIFT;
	spin_unlock_irqrestore(&csi->lock, flags);

	switch (sensor_protocol) {
	case IPU_CSI_CLK_MODE_GATED_CLK:
	case IPU_CSI_CLK_MODE_NONGATED_CLK:
	case IPU_CSI_CLK_MODE_CCIR656_PROGRESSIVE:
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_SDR:
		return false;
	case IPU_CSI_CLK_MODE_CCIR656_INTERLACED:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_SDR:
		return true;
	default:
		dev_err(csi->ipu->dev,
			"CSI %d sensor protocol unsupported\n", csi->id);
		return false;
	}
}

void ipu_csi_get_window(struct ipu_csi *csi, struct v4l2_rect *w)
{
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&csi->lock, flags);

	reg = ipu_csi_read(csi, CSI_ACT_FRM_SIZE);
	w->width = (reg & 0xFFFF) + 1;
	w->height = (reg >> 16 & 0xFFFF) + 1;

	reg = ipu_csi_read(csi, CSI_OUT_FRM_CTRL);
	w->left = (reg & CSI_HSC_MASK) >> CSI_HSC_SHIFT;
	w->top = (reg & CSI_VSC_MASK) >> CSI_VSC_SHIFT;

	spin_unlock_irqrestore(&csi->lock, flags);
}

void ipu_csi_set_window(struct ipu_csi *csi, struct v4l2_rect *w)
{
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&csi->lock, flags);

	ipu_csi_write(csi, (w->width - 1) | ((w->height - 1) << 16),
			  CSI_ACT_FRM_SIZE);

	reg = ipu_csi_read(csi, CSI_OUT_FRM_CTRL);
	reg &= ~(CSI_HSC_MASK | CSI_VSC_MASK);
	reg |= ((w->top << CSI_VSC_SHIFT) | (w->left << CSI_HSC_SHIFT));
	ipu_csi_write(csi, reg, CSI_OUT_FRM_CTRL);

	spin_unlock_irqrestore(&csi->lock, flags);
}

void ipu_csi_set_downsize(struct ipu_csi *csi, bool horiz, bool vert)
{
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&csi->lock, flags);

	reg = ipu_csi_read(csi, CSI_OUT_FRM_CTRL);
	reg &= ~(CSI_HORI_DOWNSIZE_EN | CSI_VERT_DOWNSIZE_EN);
	reg |= (horiz ? CSI_HORI_DOWNSIZE_EN : 0) |
	       (vert ? CSI_VERT_DOWNSIZE_EN : 0);
	ipu_csi_write(csi, reg, CSI_OUT_FRM_CTRL);

	spin_unlock_irqrestore(&csi->lock, flags);
}

void ipu_csi_set_test_generator(struct ipu_csi *csi, bool active,
				u32 r_value, u32 g_value, u32 b_value,
				u32 pix_clk)
{
	unsigned long flags;
	u32 ipu_clk = clk_get_rate(csi->clk_ipu);
	u32 temp;

	spin_lock_irqsave(&csi->lock, flags);

	temp = ipu_csi_read(csi, CSI_TST_CTRL);

	if (!active) {
		temp &= ~CSI_TEST_GEN_MODE_EN;
		ipu_csi_write(csi, temp, CSI_TST_CTRL);
	} else {
		/* Set sensb_mclk div_ratio */
		ipu_csi_set_testgen_mclk(csi, pix_clk, ipu_clk);

		temp &= ~(CSI_TEST_GEN_R_MASK | CSI_TEST_GEN_G_MASK |
			  CSI_TEST_GEN_B_MASK);
		temp |= CSI_TEST_GEN_MODE_EN;
		temp |= (r_value << CSI_TEST_GEN_R_SHIFT) |
			(g_value << CSI_TEST_GEN_G_SHIFT) |
			(b_value << CSI_TEST_GEN_B_SHIFT);
		ipu_csi_write(csi, temp, CSI_TST_CTRL);
	}

	spin_unlock_irqrestore(&csi->lock, flags);
}

int ipu_csi_set_mipi_datatype(struct ipu_csi *csi, u32 vc,
			      struct v4l2_mbus_framefmt *mbus_fmt)
{
	struct ipu_csi_bus_config cfg;
	unsigned long flags;
	u32 temp;
	int ret;

	if (vc > 3)
		return -EINVAL;

	ret = mbus_code_to_bus_cfg(&cfg, mbus_fmt->code, V4L2_MBUS_CSI2);
	if (ret < 0)
		return ret;

	spin_lock_irqsave(&csi->lock, flags);

	temp = ipu_csi_read(csi, CSI_MIPI_DI);
	temp &= ~(0xff << (vc * 8));
	temp |= (cfg.mipi_dt << (vc * 8));
	ipu_csi_write(csi, temp, CSI_MIPI_DI);

	spin_unlock_irqrestore(&csi->lock, flags);

	return 0;
}

int ipu_csi_set_skip_smfc(struct ipu_csi *csi, u32 skip,
			  u32 max_ratio, u32 id)
{
	unsigned long flags;
	u32 temp;

	if (max_ratio > 5 || id > 3)
		return -EINVAL;

	spin_lock_irqsave(&csi->lock, flags);

	temp = ipu_csi_read(csi, CSI_SKIP);
	temp &= ~(CSI_MAX_RATIO_SKIP_SMFC_MASK | CSI_ID_2_SKIP_MASK |
		  CSI_SKIP_SMFC_MASK);
	temp |= (max_ratio << CSI_MAX_RATIO_SKIP_SMFC_SHIFT) |
		(id << CSI_ID_2_SKIP_SHIFT) |
		(skip << CSI_SKIP_SMFC_SHIFT);
	ipu_csi_write(csi, temp, CSI_SKIP);

	spin_unlock_irqrestore(&csi->lock, flags);

	return 0;
}

int ipu_csi_set_dest(struct ipu_csi *csi, enum ipu_csi_dest csi_dest)
{
	unsigned long flags;
	u32 csi_sens_conf, dest;

	if (csi_dest == IPU_CSI_DEST_IDMAC)
		dest = CSI_DATA_DEST_IDMAC;
	else
		dest = CSI_DATA_DEST_IC; /* IC or VDIC */

	spin_lock_irqsave(&csi->lock, flags);

	csi_sens_conf = ipu_csi_read(csi, CSI_SENS_CONF);
	csi_sens_conf &= ~CSI_SENS_CONF_DATA_DEST_MASK;
	csi_sens_conf |= (dest << CSI_SENS_CONF_DATA_DEST_SHIFT);
	ipu_csi_write(csi, csi_sens_conf, CSI_SENS_CONF);

	spin_unlock_irqrestore(&csi->lock, flags);

	return 0;
}

int ipu_csi_enable(struct ipu_csi *csi)
{
	ipu_module_enable(csi->ipu, csi->module);

	return 0;
}

int ipu_csi_disable(struct ipu_csi *csi)
{
	ipu_module_disable(csi->ipu, csi->module);

	return 0;
}

struct ipu_csi *ipu_csi_get(struct ipu_soc *ipu, int id)
{
	unsigned long flags;
	struct ipu_csi *csi, *ret;

	if (id > 1)
		return ERR_PTR(-EINVAL);

	csi = ipu->csi_priv[id];
	ret = csi;

	spin_lock_irqsave(&csi->lock, flags);

	if (csi->inuse) {
		ret = ERR_PTR(-EBUSY);
		goto unlock;
	}

	csi->inuse = true;
unlock:
	spin_unlock_irqrestore(&csi->lock, flags);
	return ret;
}

void ipu_csi_put(struct ipu_csi *csi)
{
	unsigned long flags;

	spin_lock_irqsave(&csi->lock, flags);
	csi->inuse = false;
	spin_unlock_irqrestore(&csi->lock, flags);
}

int ipu_csi_init(struct ipu_soc *ipu, struct device *dev, int id,
		 unsigned long base, u32 module, struct clk *clk_ipu)
{
	struct ipu_csi *csi;

	if (id > 1)
		return -ENODEV;

	csi = devm_kzalloc(dev, sizeof(*csi), GFP_KERNEL);
	if (!csi)
		return -ENOMEM;

	ipu->csi_priv[id] = csi;

	spin_lock_init(&csi->lock);
	csi->module = module;
	csi->id = id;
	csi->clk_ipu = clk_ipu;
	csi->base = devm_ioremap(dev, base, PAGE_SIZE);
	if (!csi->base)
		return -ENOMEM;

	dev_dbg(dev, "CSI%d base: 0x%08lx remapped to %p\n",
		id, base, csi->base);
	csi->ipu = ipu;

	return 0;
}

void ipu_csi_exit(struct ipu_soc *ipu, int id)
{
}

void ipu_csi_dump(struct ipu_csi *csi)
{
	dev_dbg(csi->ipu->dev, "CSI_SENS_CONF:     %08x\n",
		ipu_csi_read(csi, CSI_SENS_CONF));
	dev_dbg(csi->ipu->dev, "CSI_SENS_FRM_SIZE: %08x\n",
		ipu_csi_read(csi, CSI_SENS_FRM_SIZE));
	dev_dbg(csi->ipu->dev, "CSI_ACT_FRM_SIZE:  %08x\n",
		ipu_csi_read(csi, CSI_ACT_FRM_SIZE));
	dev_dbg(csi->ipu->dev, "CSI_OUT_FRM_CTRL:  %08x\n",
		ipu_csi_read(csi, CSI_OUT_FRM_CTRL));
	dev_dbg(csi->ipu->dev, "CSI_TST_CTRL:      %08x\n",
		ipu_csi_read(csi, CSI_TST_CTRL));
	dev_dbg(csi->ipu->dev, "CSI_CCIR_CODE_1:   %08x\n",
		ipu_csi_read(csi, CSI_CCIR_CODE_1));
	dev_dbg(csi->ipu->dev, "CSI_CCIR_CODE_2:   %08x\n",
		ipu_csi_read(csi, CSI_CCIR_CODE_2));
	dev_dbg(csi->ipu->dev, "CSI_CCIR_CODE_3:   %08x\n",
		ipu_csi_read(csi, CSI_CCIR_CODE_3));
	dev_dbg(csi->ipu->dev, "CSI_MIPI_DI:       %08x\n",
		ipu_csi_read(csi, CSI_MIPI_DI));
	dev_dbg(csi->ipu->dev, "CSI_SKIP:          %08x\n",
		ipu_csi_read(csi, CSI_SKIP));
}

