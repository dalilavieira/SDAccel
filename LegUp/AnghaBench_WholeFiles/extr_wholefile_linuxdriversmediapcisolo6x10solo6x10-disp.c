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
typedef  int const u16 ;
struct solo_dev {int irq_mask; int vin_hstart; int vin_vstart; int video_vsize; int vout_hstart; int vout_vstart; scalar_t__ type; scalar_t__ video_type; int video_hsize; int nr_chans; int fps; int /*<<< orphan*/  pdev; scalar_t__ reg_base; } ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PCI_STATUS ; 
 int SOLO_DEF_MOT_THRESH ; 
 scalar_t__ SOLO_DEV_6010 ; 
 int /*<<< orphan*/  SOLO_DISP_EXT_ADDR ; 
 int SOLO_IRQ_MASK ; 
 int SOLO_MOTION_EXT_ADDR (struct solo_dev*) ; 
 int SOLO_MOTION_SZ ; 
 int SOLO_MOT_FLAG_AREA ; 
 int SOLO_MOT_FLAG_SIZE ; 
 int SOLO_MOT_THRESH_SIZE ; 
 int SOLO_PROGRESSIVE_VSIZE ; 
 int SOLO_SYS_VCLK ; 
 int /*<<< orphan*/  SOLO_VCLK_DELAY ; 
 int SOLO_VCLK_SELECT (int) ; 
 int SOLO_VCLK_VIN0001_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN0203_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN0405_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN0607_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN0809_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN1011_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN1213_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VCLK_VIN1415_DELAY (int /*<<< orphan*/ ) ; 
 int SOLO_VI_ACT_I_P ; 
 int SOLO_VI_ACT_I_S ; 
 int SOLO_VI_ACT_P ; 
 int SOLO_VI_CH_ENA ; 
 int SOLO_VI_CH_FORMAT ; 
 int SOLO_VI_FD_SEL_MASK (int /*<<< orphan*/ ) ; 
 int SOLO_VI_FMT_CFG ; 
 int SOLO_VI_H_START (int) ; 
 int SOLO_VI_MOTION_BAR ; 
 int SOLO_VI_MOTION_BORDER ; 
 int SOLO_VI_MOTION_EN (int /*<<< orphan*/ ) ; 
 int SOLO_VI_MOTION_FRAME_COUNT (int) ; 
 int SOLO_VI_MOTION_SAMPLE_COUNT (int) ; 
 int SOLO_VI_MOTION_SAMPLE_LENGTH (int) ; 
 int SOLO_VI_MOT_ADR ; 
 int SOLO_VI_MOT_CTRL ; 
 int SOLO_VI_PAGE_SW ; 
 int SOLO_VI_PB_ACT_H ; 
 int SOLO_VI_PB_ACT_V ; 
 int SOLO_VI_PB_CONFIG ; 
 int SOLO_VI_PB_HSIZE (int) ; 
 int SOLO_VI_PB_HSTART (int) ; 
 int SOLO_VI_PB_HSTOP (int) ; 
 int SOLO_VI_PB_PAL ; 
 int SOLO_VI_PB_RANGE_HV ; 
 int SOLO_VI_PB_USER_MODE ; 
 int SOLO_VI_PB_VSIZE (int) ; 
 int SOLO_VI_PB_VSTART (int) ; 
 int SOLO_VI_PB_VSTOP (int) ; 
 int SOLO_VI_PROG_MASK (int /*<<< orphan*/ ) ; 
 int SOLO_VI_V_START (int) ; 
 int SOLO_VI_V_STOP (int) ; 
 int SOLO_VI_WIN_CTRL0 (int) ; 
 int SOLO_VI_WIN_CTRL1 (int) ; 
 int SOLO_VI_WIN_ON (int) ; 
 int SOLO_VI_WIN_SW ; 
 int SOLO_VO_ACT_H ; 
 int SOLO_VO_ACT_V ; 
 int SOLO_VO_BKG_COLOR ; 
 int SOLO_VO_BORDER_FILL_COLOR ; 
 int SOLO_VO_BORDER_FILL_MASK ; 
 int SOLO_VO_BORDER_LINE_COLOR ; 
 int SOLO_VO_BORDER_LINE_MASK ; 
 int SOLO_VO_BORDER_X (int) ; 
 int SOLO_VO_BORDER_Y (int) ; 
 int SOLO_VO_CURSOR_CLR ; 
 int SOLO_VO_CURSOR_CLR2 ; 
 int SOLO_VO_CURSOR_MASK (int) ; 
 int SOLO_VO_CURSOR_POS ; 
 int SOLO_VO_DISP_BASE (int /*<<< orphan*/ ) ; 
 int SOLO_VO_DISP_CTRL ; 
 int SOLO_VO_DISP_ERASE ; 
 int SOLO_VO_DISP_ERASE_COUNT (int) ; 
 int SOLO_VO_DISP_ERASE_ON ; 
 int SOLO_VO_DISP_ON ; 
 int SOLO_VO_FMT_ENC ; 
 scalar_t__ SOLO_VO_FMT_TYPE_NTSC ; 
 int SOLO_VO_FREEZE_CTRL ; 
 int SOLO_VO_H_LEN (int) ; 
 int SOLO_VO_H_START (int) ; 
 int SOLO_VO_H_STOP (int) ; 
 int SOLO_VO_NA_COLOR_CB (int /*<<< orphan*/ ) ; 
 int SOLO_VO_NA_COLOR_CR (int /*<<< orphan*/ ) ; 
 int SOLO_VO_NA_COLOR_Y (int /*<<< orphan*/ ) ; 
 int SOLO_VO_RANGE_HV ; 
 int SOLO_VO_RECTANGLE_CTRL (int) ; 
 int SOLO_VO_RECTANGLE_START (int) ; 
 int SOLO_VO_RECTANGLE_STOP (int) ; 
 int SOLO_VO_USER_COLOR_SET_NAH ; 
 int SOLO_VO_USER_COLOR_SET_NAV ; 
 int SOLO_VO_V_LEN (int) ; 
 int SOLO_VO_V_START (int) ; 
 int SOLO_VO_V_STOP (int) ; 
 int SOLO_VO_ZOOM_CTRL ; 
 int /*<<< orphan*/  cpu_to_le16 (int const) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kmalloc (int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * kzalloc (unsigned int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_word (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const*) ; 
 int readl (scalar_t__) ; 
 int solo_p2m_dma (struct solo_dev*,int,int /*<<< orphan*/ *,int,unsigned int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline u32 solo_reg_read(struct solo_dev *solo_dev, int reg)
{
	return readl(solo_dev->reg_base + reg);
}

__attribute__((used)) static inline void solo_reg_write(struct solo_dev *solo_dev, int reg,
				  u32 data)
{
	u16 val;

	writel(data, solo_dev->reg_base + reg);
	pci_read_config_word(solo_dev->pdev, PCI_STATUS, &val);
}

__attribute__((used)) static inline void solo_irq_on(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask |= mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

__attribute__((used)) static inline void solo_irq_off(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask &= ~mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

__attribute__((used)) static void solo_vin_config(struct solo_dev *solo_dev)
{
	solo_dev->vin_hstart = 8;
	solo_dev->vin_vstart = 2;

	solo_reg_write(solo_dev, SOLO_SYS_VCLK,
		       SOLO_VCLK_SELECT(2) |
		       SOLO_VCLK_VIN1415_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN1213_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN1011_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN0809_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN0607_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN0405_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN0203_DELAY(SOLO_VCLK_DELAY) |
		       SOLO_VCLK_VIN0001_DELAY(SOLO_VCLK_DELAY));

	solo_reg_write(solo_dev, SOLO_VI_ACT_I_P,
		       SOLO_VI_H_START(solo_dev->vin_hstart) |
		       SOLO_VI_V_START(solo_dev->vin_vstart) |
		       SOLO_VI_V_STOP(solo_dev->vin_vstart +
				      solo_dev->video_vsize));

	solo_reg_write(solo_dev, SOLO_VI_ACT_I_S,
		       SOLO_VI_H_START(solo_dev->vout_hstart) |
		       SOLO_VI_V_START(solo_dev->vout_vstart) |
		       SOLO_VI_V_STOP(solo_dev->vout_vstart +
				      solo_dev->video_vsize));

	solo_reg_write(solo_dev, SOLO_VI_ACT_P,
		       SOLO_VI_H_START(0) |
		       SOLO_VI_V_START(1) |
		       SOLO_VI_V_STOP(SOLO_PROGRESSIVE_VSIZE));

	solo_reg_write(solo_dev, SOLO_VI_CH_FORMAT,
		       SOLO_VI_FD_SEL_MASK(0) | SOLO_VI_PROG_MASK(0));

	/* On 6110, initialize mozaic darkness stength */
	if (solo_dev->type == SOLO_DEV_6010)
		solo_reg_write(solo_dev, SOLO_VI_FMT_CFG, 0);
	else
		solo_reg_write(solo_dev, SOLO_VI_FMT_CFG, 16 << 22);

	solo_reg_write(solo_dev, SOLO_VI_PAGE_SW, 2);

	if (solo_dev->video_type == SOLO_VO_FMT_TYPE_NTSC) {
		solo_reg_write(solo_dev, SOLO_VI_PB_CONFIG,
			       SOLO_VI_PB_USER_MODE);
		solo_reg_write(solo_dev, SOLO_VI_PB_RANGE_HV,
			       SOLO_VI_PB_HSIZE(858) | SOLO_VI_PB_VSIZE(246));
		solo_reg_write(solo_dev, SOLO_VI_PB_ACT_V,
			       SOLO_VI_PB_VSTART(4) |
			       SOLO_VI_PB_VSTOP(4 + 240));
	} else {
		solo_reg_write(solo_dev, SOLO_VI_PB_CONFIG,
			       SOLO_VI_PB_USER_MODE | SOLO_VI_PB_PAL);
		solo_reg_write(solo_dev, SOLO_VI_PB_RANGE_HV,
			       SOLO_VI_PB_HSIZE(864) | SOLO_VI_PB_VSIZE(294));
		solo_reg_write(solo_dev, SOLO_VI_PB_ACT_V,
			       SOLO_VI_PB_VSTART(4) |
			       SOLO_VI_PB_VSTOP(4 + 288));
	}
	solo_reg_write(solo_dev, SOLO_VI_PB_ACT_H, SOLO_VI_PB_HSTART(16) |
		       SOLO_VI_PB_HSTOP(16 + 720));
}

__attribute__((used)) static void solo_vout_config_cursor(struct solo_dev *dev)
{
	int i;

	/* Load (blank) cursor bitmap mask (2bpp) */
	for (i = 0; i < 20; i++)
		solo_reg_write(dev, SOLO_VO_CURSOR_MASK(i), 0);

	solo_reg_write(dev, SOLO_VO_CURSOR_POS, 0);

	solo_reg_write(dev, SOLO_VO_CURSOR_CLR,
		       (0x80 << 24) | (0x80 << 16) | (0x10 << 8) | 0x80);
	solo_reg_write(dev, SOLO_VO_CURSOR_CLR2, (0xe0 << 8) | 0x80);
}

__attribute__((used)) static void solo_vout_config(struct solo_dev *solo_dev)
{
	solo_dev->vout_hstart = 6;
	solo_dev->vout_vstart = 8;

	solo_reg_write(solo_dev, SOLO_VO_FMT_ENC,
		       solo_dev->video_type |
		       SOLO_VO_USER_COLOR_SET_NAV |
		       SOLO_VO_USER_COLOR_SET_NAH |
		       SOLO_VO_NA_COLOR_Y(0) |
		       SOLO_VO_NA_COLOR_CB(0) |
		       SOLO_VO_NA_COLOR_CR(0));

	solo_reg_write(solo_dev, SOLO_VO_ACT_H,
		       SOLO_VO_H_START(solo_dev->vout_hstart) |
		       SOLO_VO_H_STOP(solo_dev->vout_hstart +
				      solo_dev->video_hsize));

	solo_reg_write(solo_dev, SOLO_VO_ACT_V,
		       SOLO_VO_V_START(solo_dev->vout_vstart) |
		       SOLO_VO_V_STOP(solo_dev->vout_vstart +
				      solo_dev->video_vsize));

	solo_reg_write(solo_dev, SOLO_VO_RANGE_HV,
		       SOLO_VO_H_LEN(solo_dev->video_hsize) |
		       SOLO_VO_V_LEN(solo_dev->video_vsize));

	/* Border & background colors */
	solo_reg_write(solo_dev, SOLO_VO_BORDER_LINE_COLOR,
		       (0xa0 << 24) | (0x88 << 16) | (0xa0 << 8) | 0x88);
	solo_reg_write(solo_dev, SOLO_VO_BORDER_FILL_COLOR,
		       (0x10 << 24) | (0x8f << 16) | (0x10 << 8) | 0x8f);
	solo_reg_write(solo_dev, SOLO_VO_BKG_COLOR,
		       (16 << 24) | (128 << 16) | (16 << 8) | 128);

	solo_reg_write(solo_dev, SOLO_VO_DISP_ERASE, SOLO_VO_DISP_ERASE_ON);

	solo_reg_write(solo_dev, SOLO_VI_WIN_SW, 0);

	solo_reg_write(solo_dev, SOLO_VO_ZOOM_CTRL, 0);
	solo_reg_write(solo_dev, SOLO_VO_FREEZE_CTRL, 0);

	solo_reg_write(solo_dev, SOLO_VO_DISP_CTRL, SOLO_VO_DISP_ON |
		       SOLO_VO_DISP_ERASE_COUNT(8) |
		       SOLO_VO_DISP_BASE(SOLO_DISP_EXT_ADDR));


	solo_vout_config_cursor(solo_dev);

	/* Enable channels we support */
	solo_reg_write(solo_dev, SOLO_VI_CH_ENA,
		       (1 << solo_dev->nr_chans) - 1);
}

__attribute__((used)) static int solo_dma_vin_region(struct solo_dev *solo_dev, u32 off,
			       u16 val, int reg_size)
{
	__le16 *buf;
	const int n = 64, size = n * sizeof(*buf);
	int i, ret = 0;

	buf = kmalloc(size, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	for (i = 0; i < n; i++)
		buf[i] = cpu_to_le16(val);

	for (i = 0; i < reg_size; i += size) {
		ret = solo_p2m_dma(solo_dev, 1, buf,
				   SOLO_MOTION_EXT_ADDR(solo_dev) + off + i,
				   size, 0, 0);

		if (ret)
			break;
	}

	kfree(buf);
	return ret;
}

int solo_set_motion_threshold(struct solo_dev *solo_dev, u8 ch, u16 val)
{
	if (ch > solo_dev->nr_chans)
		return -EINVAL;

	return solo_dma_vin_region(solo_dev, SOLO_MOT_FLAG_AREA +
				   (ch * SOLO_MOT_THRESH_SIZE * 2),
				   val, SOLO_MOT_THRESH_SIZE);
}

int solo_set_motion_block(struct solo_dev *solo_dev, u8 ch,
		const u16 *thresholds)
{
	const unsigned size = sizeof(u16) * 64;
	u32 off = SOLO_MOT_FLAG_AREA + ch * SOLO_MOT_THRESH_SIZE * 2;
	__le16 *buf;
	int x, y;
	int ret = 0;

	buf = kzalloc(size, GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;
	for (y = 0; y < SOLO_MOTION_SZ; y++) {
		for (x = 0; x < SOLO_MOTION_SZ; x++)
			buf[x] = cpu_to_le16(thresholds[y * SOLO_MOTION_SZ + x]);
		ret |= solo_p2m_dma(solo_dev, 1, buf,
			SOLO_MOTION_EXT_ADDR(solo_dev) + off + y * size,
			size, 0, 0);
	}
	kfree(buf);
	return ret;
}

__attribute__((used)) static void solo_motion_config(struct solo_dev *solo_dev)
{
	int i;

	for (i = 0; i < solo_dev->nr_chans; i++) {
		/* Clear motion flag area */
		solo_dma_vin_region(solo_dev, i * SOLO_MOT_FLAG_SIZE, 0x0000,
				    SOLO_MOT_FLAG_SIZE);

		/* Clear working cache table */
		solo_dma_vin_region(solo_dev, SOLO_MOT_FLAG_AREA +
				    (i * SOLO_MOT_THRESH_SIZE * 2) +
				    SOLO_MOT_THRESH_SIZE, 0x0000,
				    SOLO_MOT_THRESH_SIZE);

		/* Set default threshold table */
		solo_set_motion_threshold(solo_dev, i, SOLO_DEF_MOT_THRESH);
	}

	/* Default motion settings */
	solo_reg_write(solo_dev, SOLO_VI_MOT_ADR, SOLO_VI_MOTION_EN(0) |
		       (SOLO_MOTION_EXT_ADDR(solo_dev) >> 16));
	solo_reg_write(solo_dev, SOLO_VI_MOT_CTRL,
		       SOLO_VI_MOTION_FRAME_COUNT(3) |
		       SOLO_VI_MOTION_SAMPLE_LENGTH(solo_dev->video_hsize / 16)
		       /* | SOLO_VI_MOTION_INTR_START_STOP */
		       | SOLO_VI_MOTION_SAMPLE_COUNT(10));

	solo_reg_write(solo_dev, SOLO_VI_MOTION_BORDER, 0);
	solo_reg_write(solo_dev, SOLO_VI_MOTION_BAR, 0);
}

int solo_disp_init(struct solo_dev *solo_dev)
{
	int i;

	solo_dev->video_hsize = 704;
	if (solo_dev->video_type == SOLO_VO_FMT_TYPE_NTSC) {
		solo_dev->video_vsize = 240;
		solo_dev->fps = 30;
	} else {
		solo_dev->video_vsize = 288;
		solo_dev->fps = 25;
	}

	solo_vin_config(solo_dev);
	solo_motion_config(solo_dev);
	solo_vout_config(solo_dev);

	for (i = 0; i < solo_dev->nr_chans; i++)
		solo_reg_write(solo_dev, SOLO_VI_WIN_ON(i), 1);

	return 0;
}

void solo_disp_exit(struct solo_dev *solo_dev)
{
	int i;

	solo_reg_write(solo_dev, SOLO_VO_DISP_CTRL, 0);
	solo_reg_write(solo_dev, SOLO_VO_ZOOM_CTRL, 0);
	solo_reg_write(solo_dev, SOLO_VO_FREEZE_CTRL, 0);

	for (i = 0; i < solo_dev->nr_chans; i++) {
		solo_reg_write(solo_dev, SOLO_VI_WIN_CTRL0(i), 0);
		solo_reg_write(solo_dev, SOLO_VI_WIN_CTRL1(i), 0);
		solo_reg_write(solo_dev, SOLO_VI_WIN_ON(i), 0);
	}

	/* Set default border */
	for (i = 0; i < 5; i++)
		solo_reg_write(solo_dev, SOLO_VO_BORDER_X(i), 0);

	for (i = 0; i < 5; i++)
		solo_reg_write(solo_dev, SOLO_VO_BORDER_Y(i), 0);

	solo_reg_write(solo_dev, SOLO_VO_BORDER_LINE_MASK, 0);
	solo_reg_write(solo_dev, SOLO_VO_BORDER_FILL_MASK, 0);

	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_CTRL(0), 0);
	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_START(0), 0);
	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_STOP(0), 0);

	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_CTRL(1), 0);
	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_START(1), 0);
	solo_reg_write(solo_dev, SOLO_VO_RECTANGLE_STOP(1), 0);
}

