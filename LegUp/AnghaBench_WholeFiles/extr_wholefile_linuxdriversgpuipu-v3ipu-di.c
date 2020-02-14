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
typedef  int uint32_t ;
typedef  int u32 ;
struct videomode {int vfront_porch; int vback_porch; int vsync_len; } ;
struct ipu_soc {unsigned int idmac_reg; struct ipu_di** di_priv; struct device* dev; } ;
struct TYPE_2__ {int hactive; int hsync_len; int hback_porch; int hfront_porch; int vactive; int vsync_len; int vback_porch; int vfront_porch; int pixelclock; int flags; } ;
struct ipu_di_signal_cfg {int v_to_h_sync; int hsync_pin; int vsync_pin; int clkflags; scalar_t__ data_pol; scalar_t__ enable_pol; scalar_t__ clk_pol; TYPE_1__ mode; } ;
struct ipu_di {unsigned int base; int id; int module; int inuse; struct ipu_soc* ipu; struct clk* clk_ipu; struct clk* clk_di; struct clk* clk_di_pixel; } ;
struct di_sync_config {int run_count; int offset_count; int repeat_count; int cnt_up; int cnt_down; int run_src; int offset_src; int cnt_polarity_gen_en; int cnt_clr_src; int cnt_polarity_trigger_src; int /*<<< orphan*/  cnt_polarity_clr_src; } ;
struct device {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct di_sync_config*) ; 
 int DISPLAY_FLAGS_HSYNC_HIGH ; 
 int DISPLAY_FLAGS_INTERLACED ; 
 int DISPLAY_FLAGS_VSYNC_HIGH ; 
 unsigned int DIV_ROUND_CLOSEST (unsigned long,int) ; 
 unsigned int DI_BS_CLKGEN0 ; 
 unsigned int DI_BS_CLKGEN1 ; 
 unsigned int DI_DW_GEN (int) ; 
 int DI_DW_GEN_ACCESS_SIZE_OFFSET ; 
 int DI_DW_GEN_COMPONENT_SIZE_OFFSET ; 
 unsigned int DI_DW_SET (int,int) ; 
 unsigned int DI_GENERAL ; 
 int DI_GEN_DI_CLK_EXT ; 
 int DI_GEN_DI_VSYNC_EXT ; 
 int DI_GEN_POLARITY_1 ; 
 int DI_GEN_POLARITY_2 ; 
 int DI_GEN_POLARITY_3 ; 
 int DI_GEN_POLARITY_4 ; 
 int DI_GEN_POLARITY_5 ; 
 int DI_GEN_POLARITY_6 ; 
 int DI_GEN_POLARITY_7 ; 
 int DI_GEN_POLARITY_8 ; 
 int DI_GEN_POLARITY_DISP_CLK ; 
 int DI_PIN15 ; 
 unsigned int DI_POL ; 
 int DI_POL_DRDY_DATA_POLARITY ; 
 int DI_POL_DRDY_POLARITY_15 ; 
 unsigned int DI_SCR_CONF ; 
 unsigned int DI_STP_REP (int) ; 
 unsigned int DI_SW_GEN0 (int) ; 
 int DI_SW_GEN0_OFFSET_COUNT (int) ; 
 int DI_SW_GEN0_OFFSET_SRC (int) ; 
 int DI_SW_GEN0_RUN_COUNT (int) ; 
 int DI_SW_GEN0_RUN_SRC (int) ; 
 unsigned int DI_SW_GEN1 (int) ; 
 int DI_SW_GEN1_AUTO_RELOAD ; 
 int DI_SW_GEN1_CNT_CLR_SRC (int) ; 
 int DI_SW_GEN1_CNT_DOWN (int) ; 
 int DI_SW_GEN1_CNT_POL_CLR_SRC (int /*<<< orphan*/ ) ; 
 int DI_SW_GEN1_CNT_POL_GEN_EN (int) ; 
 int DI_SW_GEN1_CNT_POL_TRIGGER_SRC (int) ; 
 int DI_SW_GEN1_CNT_UP (int) ; 
 unsigned int DI_SYNC_AS_GEN ; 
 int DI_SYNC_CLK ; 
 int DI_SYNC_CNT1 ; 
 int DI_SYNC_CNT4 ; 
 int DI_SYNC_CNT5 ; 
 int DI_SYNC_HSYNC ; 
 int DI_SYNC_INT_HSYNC ; 
 int DI_SYNC_VSYNC ; 
 int DI_VSYNC_SEL_OFFSET ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ipu_di* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IPU_DI_CLKMODE_EXT ; 
 int IPU_DI_CLKMODE_SYNC ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct clk*) ; 
 int SYNC_WAVE ; 
 int /*<<< orphan*/  WARN_ON (scalar_t__) ; 
 unsigned int clamp (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct clk*) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 int clk_prepare_enable (struct clk*) ; 
 int /*<<< orphan*/  clk_set_rate (struct clk*,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct clk* devm_clk_get (struct device*,char*) ; 
 unsigned int devm_ioremap (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 struct ipu_di* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  di_mutex ; 
 int /*<<< orphan*/  ipu_di_lock ; 
 int /*<<< orphan*/  ipu_module_disable (struct ipu_soc*,int) ; 
 int /*<<< orphan*/  ipu_module_enable (struct ipu_soc*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl (unsigned int) ; 
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

__attribute__((used)) static inline u32 ipu_di_read(struct ipu_di *di, unsigned offset)
{
	return readl(di->base + offset);
}

__attribute__((used)) static inline void ipu_di_write(struct ipu_di *di, u32 value, unsigned offset)
{
	writel(value, di->base + offset);
}

__attribute__((used)) static void ipu_di_data_wave_config(struct ipu_di *di,
				     int wave_gen,
				     int access_size, int component_size)
{
	u32 reg;
	reg = (access_size << DI_DW_GEN_ACCESS_SIZE_OFFSET) |
	    (component_size << DI_DW_GEN_COMPONENT_SIZE_OFFSET);
	ipu_di_write(di, reg, DI_DW_GEN(wave_gen));
}

__attribute__((used)) static void ipu_di_data_pin_config(struct ipu_di *di, int wave_gen, int di_pin,
		int set, int up, int down)
{
	u32 reg;

	reg = ipu_di_read(di, DI_DW_GEN(wave_gen));
	reg &= ~(0x3 << (di_pin * 2));
	reg |= set << (di_pin * 2);
	ipu_di_write(di, reg, DI_DW_GEN(wave_gen));

	ipu_di_write(di, (down << 16) | up, DI_DW_SET(wave_gen, set));
}

__attribute__((used)) static void ipu_di_sync_config(struct ipu_di *di, struct di_sync_config *config,
		int start, int count)
{
	u32 reg;
	int i;

	for (i = 0; i < count; i++) {
		struct di_sync_config *c = &config[i];
		int wave_gen = start + i + 1;

		if ((c->run_count >= 0x1000) || (c->offset_count >= 0x1000) ||
				(c->repeat_count >= 0x1000) ||
				(c->cnt_up >= 0x400) ||
				(c->cnt_down >= 0x400)) {
			dev_err(di->ipu->dev, "DI%d counters out of range.\n",
					di->id);
			return;
		}

		reg = DI_SW_GEN0_RUN_COUNT(c->run_count) |
			DI_SW_GEN0_RUN_SRC(c->run_src) |
			DI_SW_GEN0_OFFSET_COUNT(c->offset_count) |
			DI_SW_GEN0_OFFSET_SRC(c->offset_src);
		ipu_di_write(di, reg, DI_SW_GEN0(wave_gen));

		reg = DI_SW_GEN1_CNT_POL_GEN_EN(c->cnt_polarity_gen_en) |
			DI_SW_GEN1_CNT_CLR_SRC(c->cnt_clr_src) |
			DI_SW_GEN1_CNT_POL_TRIGGER_SRC(
					c->cnt_polarity_trigger_src) |
			DI_SW_GEN1_CNT_POL_CLR_SRC(c->cnt_polarity_clr_src) |
			DI_SW_GEN1_CNT_DOWN(c->cnt_down) |
			DI_SW_GEN1_CNT_UP(c->cnt_up);

		/* Enable auto reload */
		if (c->repeat_count == 0)
			reg |= DI_SW_GEN1_AUTO_RELOAD;

		ipu_di_write(di, reg, DI_SW_GEN1(wave_gen));

		reg = ipu_di_read(di, DI_STP_REP(wave_gen));
		reg &= ~(0xffff << (16 * ((wave_gen - 1) & 0x1)));
		reg |= c->repeat_count << (16 * ((wave_gen - 1) & 0x1));
		ipu_di_write(di, reg, DI_STP_REP(wave_gen));
	}
}

__attribute__((used)) static void ipu_di_sync_config_interlaced(struct ipu_di *di,
		struct ipu_di_signal_cfg *sig)
{
	u32 h_total = sig->mode.hactive + sig->mode.hsync_len +
		sig->mode.hback_porch + sig->mode.hfront_porch;
	u32 v_total = sig->mode.vactive + sig->mode.vsync_len +
		sig->mode.vback_porch + sig->mode.vfront_porch;
	struct di_sync_config cfg[] = {
		{
			/* 1: internal VSYNC for each frame */
			.run_count = v_total * 2 - 1,
			.run_src = 3,			/* == counter 7 */
		}, {
			/* PIN2: HSYNC waveform */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_CLK,
			.cnt_down = sig->mode.hsync_len * 2,
		}, {
			/* PIN3: VSYNC waveform */
			.run_count = v_total - 1,
			.run_src = 4,			/* == counter 7 */
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = 4,	/* == counter 7 */
			.cnt_down = sig->mode.vsync_len * 2,
			.cnt_clr_src = DI_SYNC_CNT1,
		}, {
			/* 4: Field */
			.run_count = v_total / 2,
			.run_src = DI_SYNC_HSYNC,
			.offset_count = h_total / 2,
			.offset_src = DI_SYNC_CLK,
			.repeat_count = 2,
			.cnt_clr_src = DI_SYNC_CNT1,
		}, {
			/* 5: Active lines */
			.run_src = DI_SYNC_HSYNC,
			.offset_count = (sig->mode.vsync_len +
					 sig->mode.vback_porch) / 2,
			.offset_src = DI_SYNC_HSYNC,
			.repeat_count = sig->mode.vactive / 2,
			.cnt_clr_src = DI_SYNC_CNT4,
		}, {
			/* 6: Active pixel, referenced by DC */
			.run_src = DI_SYNC_CLK,
			.offset_count = sig->mode.hsync_len +
					sig->mode.hback_porch,
			.offset_src = DI_SYNC_CLK,
			.repeat_count = sig->mode.hactive,
			.cnt_clr_src = DI_SYNC_CNT5,
		}, {
			/* 7: Half line HSYNC */
			.run_count = h_total / 2 - 1,
			.run_src = DI_SYNC_CLK,
		}
	};

	ipu_di_sync_config(di, cfg, 0, ARRAY_SIZE(cfg));

	ipu_di_write(di, v_total / 2 - 1, DI_SCR_CONF);
}

__attribute__((used)) static void ipu_di_sync_config_noninterlaced(struct ipu_di *di,
		struct ipu_di_signal_cfg *sig, int div)
{
	u32 h_total = sig->mode.hactive + sig->mode.hsync_len +
		sig->mode.hback_porch + sig->mode.hfront_porch;
	u32 v_total = sig->mode.vactive + sig->mode.vsync_len +
		sig->mode.vback_porch + sig->mode.vfront_porch;
	struct di_sync_config cfg[] = {
		{
			/* 1: INT_HSYNC */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
		} , {
			/* PIN2: HSYNC */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
			.offset_count = div * sig->v_to_h_sync,
			.offset_src = DI_SYNC_CLK,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_CLK,
			.cnt_down = sig->mode.hsync_len * 2,
		} , {
			/* PIN3: VSYNC */
			.run_count = v_total - 1,
			.run_src = DI_SYNC_INT_HSYNC,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
			.cnt_down = sig->mode.vsync_len * 2,
		} , {
			/* 4: Line Active */
			.run_src = DI_SYNC_HSYNC,
			.offset_count = sig->mode.vsync_len +
					sig->mode.vback_porch,
			.offset_src = DI_SYNC_HSYNC,
			.repeat_count = sig->mode.vactive,
			.cnt_clr_src = DI_SYNC_VSYNC,
		} , {
			/* 5: Pixel Active, referenced by DC */
			.run_src = DI_SYNC_CLK,
			.offset_count = sig->mode.hsync_len +
					sig->mode.hback_porch,
			.offset_src = DI_SYNC_CLK,
			.repeat_count = sig->mode.hactive,
			.cnt_clr_src = 5, /* Line Active */
		} , {
			/* unused */
		} , {
			/* unused */
		} , {
			/* unused */
		} , {
			/* unused */
		},
	};
	/* can't use #7 and #8 for line active and pixel active counters */
	struct di_sync_config cfg_vga[] = {
		{
			/* 1: INT_HSYNC */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
		} , {
			/* 2: VSYNC */
			.run_count = v_total - 1,
			.run_src = DI_SYNC_INT_HSYNC,
		} , {
			/* 3: Line Active */
			.run_src = DI_SYNC_INT_HSYNC,
			.offset_count = sig->mode.vsync_len +
					sig->mode.vback_porch,
			.offset_src = DI_SYNC_INT_HSYNC,
			.repeat_count = sig->mode.vactive,
			.cnt_clr_src = 3 /* VSYNC */,
		} , {
			/* PIN4: HSYNC for VGA via TVEv2 on TQ MBa53 */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
			.offset_count = div * sig->v_to_h_sync + 18, /* magic value from Freescale TVE driver */
			.offset_src = DI_SYNC_CLK,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_CLK,
			.cnt_down = sig->mode.hsync_len * 2,
		} , {
			/* 5: Pixel Active signal to DC */
			.run_src = DI_SYNC_CLK,
			.offset_count = sig->mode.hsync_len +
					sig->mode.hback_porch,
			.offset_src = DI_SYNC_CLK,
			.repeat_count = sig->mode.hactive,
			.cnt_clr_src = 4, /* Line Active */
		} , {
			/* PIN6: VSYNC for VGA via TVEv2 on TQ MBa53 */
			.run_count = v_total - 1,
			.run_src = DI_SYNC_INT_HSYNC,
			.offset_count = 1, /* magic value from Freescale TVE driver */
			.offset_src = DI_SYNC_INT_HSYNC,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
			.cnt_down = sig->mode.vsync_len * 2,
		} , {
			/* PIN4: HSYNC for VGA via TVEv2 on i.MX53-QSB */
			.run_count = h_total - 1,
			.run_src = DI_SYNC_CLK,
			.offset_count = div * sig->v_to_h_sync + 18, /* magic value from Freescale TVE driver */
			.offset_src = DI_SYNC_CLK,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_CLK,
			.cnt_down = sig->mode.hsync_len * 2,
		} , {
			/* PIN6: VSYNC for VGA via TVEv2 on i.MX53-QSB */
			.run_count = v_total - 1,
			.run_src = DI_SYNC_INT_HSYNC,
			.offset_count = 1, /* magic value from Freescale TVE driver */
			.offset_src = DI_SYNC_INT_HSYNC,
			.cnt_polarity_gen_en = 1,
			.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
			.cnt_down = sig->mode.vsync_len * 2,
		} , {
			/* unused */
		},
	};

	ipu_di_write(di, v_total - 1, DI_SCR_CONF);
	if (sig->hsync_pin == 2 && sig->vsync_pin == 3)
		ipu_di_sync_config(di, cfg, 0, ARRAY_SIZE(cfg));
	else
		ipu_di_sync_config(di, cfg_vga, 0, ARRAY_SIZE(cfg_vga));
}

__attribute__((used)) static void ipu_di_config_clock(struct ipu_di *di,
	const struct ipu_di_signal_cfg *sig)
{
	struct clk *clk;
	unsigned clkgen0;
	uint32_t val;

	if (sig->clkflags & IPU_DI_CLKMODE_EXT) {
		/*
		 * CLKMODE_EXT means we must use the DI clock: this is
		 * needed for things like LVDS which needs to feed the
		 * DI and LDB with the same pixel clock.
		 */
		clk = di->clk_di;

		if (sig->clkflags & IPU_DI_CLKMODE_SYNC) {
			/*
			 * CLKMODE_SYNC means that we want the DI to be
			 * clocked at the same rate as the parent clock.
			 * This is needed (eg) for LDB which needs to be
			 * fed with the same pixel clock.  We assume that
			 * the LDB clock has already been set correctly.
			 */
			clkgen0 = 1 << 4;
		} else {
			/*
			 * We can use the divider.  We should really have
			 * a flag here indicating whether the bridge can
			 * cope with a fractional divider or not.  For the
			 * time being, let's go for simplicitly and
			 * reliability.
			 */
			unsigned long in_rate;
			unsigned div;

			clk_set_rate(clk, sig->mode.pixelclock);

			in_rate = clk_get_rate(clk);
			div = DIV_ROUND_CLOSEST(in_rate, sig->mode.pixelclock);
			div = clamp(div, 1U, 255U);

			clkgen0 = div << 4;
		}
	} else {
		/*
		 * For other interfaces, we can arbitarily select between
		 * the DI specific clock and the internal IPU clock.  See
		 * DI_GENERAL bit 20.  We select the IPU clock if it can
		 * give us a clock rate within 1% of the requested frequency,
		 * otherwise we use the DI clock.
		 */
		unsigned long rate, clkrate;
		unsigned div, error;

		clkrate = clk_get_rate(di->clk_ipu);
		div = DIV_ROUND_CLOSEST(clkrate, sig->mode.pixelclock);
		div = clamp(div, 1U, 255U);
		rate = clkrate / div;

		error = rate / (sig->mode.pixelclock / 1000);

		dev_dbg(di->ipu->dev, "  IPU clock can give %lu with divider %u, error %d.%u%%\n",
			rate, div, (signed)(error - 1000) / 10, error % 10);

		/* Allow a 1% error */
		if (error < 1010 && error >= 990) {
			clk = di->clk_ipu;

			clkgen0 = div << 4;
		} else {
			unsigned long in_rate;
			unsigned div;

			clk = di->clk_di;

			clk_set_rate(clk, sig->mode.pixelclock);

			in_rate = clk_get_rate(clk);
			div = DIV_ROUND_CLOSEST(in_rate, sig->mode.pixelclock);
			div = clamp(div, 1U, 255U);

			clkgen0 = div << 4;
		}
	}

	di->clk_di_pixel = clk;

	/* Set the divider */
	ipu_di_write(di, clkgen0, DI_BS_CLKGEN0);

	/*
	 * Set the high/low periods.  Bits 24:16 give us the falling edge,
	 * and bits 8:0 give the rising edge.  LSB is fraction, and is
	 * based on the divider above.  We want a 50% duty cycle, so set
	 * the falling edge to be half the divider.
	 */
	ipu_di_write(di, (clkgen0 >> 4) << 16, DI_BS_CLKGEN1);

	/* Finally select the input clock */
	val = ipu_di_read(di, DI_GENERAL) & ~DI_GEN_DI_CLK_EXT;
	if (clk == di->clk_di)
		val |= DI_GEN_DI_CLK_EXT;
	ipu_di_write(di, val, DI_GENERAL);

	dev_dbg(di->ipu->dev, "Want %luHz IPU %luHz DI %luHz using %s, %luHz\n",
		sig->mode.pixelclock,
		clk_get_rate(di->clk_ipu),
		clk_get_rate(di->clk_di),
		clk == di->clk_di ? "DI" : "IPU",
		clk_get_rate(di->clk_di_pixel) / (clkgen0 >> 4));
}

int ipu_di_adjust_videomode(struct ipu_di *di, struct videomode *mode)
{
	u32 diff;

	if (mode->vfront_porch >= 2)
		return 0;

	diff = 2 - mode->vfront_porch;

	if (mode->vback_porch >= diff) {
		mode->vfront_porch = 2;
		mode->vback_porch -= diff;
	} else if (mode->vsync_len > diff) {
		mode->vfront_porch = 2;
		mode->vsync_len = mode->vsync_len - diff;
	} else {
		dev_warn(di->ipu->dev, "failed to adjust videomode\n");
		return -EINVAL;
	}

	dev_dbg(di->ipu->dev, "videomode adapted for IPU restrictions\n");
	return 0;
}

__attribute__((used)) static u32 ipu_di_gen_polarity(int pin)
{
	switch (pin) {
	case 1:
		return DI_GEN_POLARITY_1;
	case 2:
		return DI_GEN_POLARITY_2;
	case 3:
		return DI_GEN_POLARITY_3;
	case 4:
		return DI_GEN_POLARITY_4;
	case 5:
		return DI_GEN_POLARITY_5;
	case 6:
		return DI_GEN_POLARITY_6;
	case 7:
		return DI_GEN_POLARITY_7;
	case 8:
		return DI_GEN_POLARITY_8;
	}
	return 0;
}

int ipu_di_init_sync_panel(struct ipu_di *di, struct ipu_di_signal_cfg *sig)
{
	u32 reg;
	u32 di_gen, vsync_cnt;
	u32 div;

	dev_dbg(di->ipu->dev, "disp %d: panel size = %d x %d\n",
		di->id, sig->mode.hactive, sig->mode.vactive);

	dev_dbg(di->ipu->dev, "Clocks: IPU %luHz DI %luHz Needed %luHz\n",
		clk_get_rate(di->clk_ipu),
		clk_get_rate(di->clk_di),
		sig->mode.pixelclock);

	mutex_lock(&di_mutex);

	ipu_di_config_clock(di, sig);

	div = ipu_di_read(di, DI_BS_CLKGEN0) & 0xfff;
	div = div / 16;		/* Now divider is integer portion */

	/* Setup pixel clock timing */
	/* Down time is half of period */
	ipu_di_write(di, (div << 16), DI_BS_CLKGEN1);

	ipu_di_data_wave_config(di, SYNC_WAVE, div - 1, div - 1);
	ipu_di_data_pin_config(di, SYNC_WAVE, DI_PIN15, 3, 0, div * 2);

	di_gen = ipu_di_read(di, DI_GENERAL) & DI_GEN_DI_CLK_EXT;
	di_gen |= DI_GEN_DI_VSYNC_EXT;

	if (sig->mode.flags & DISPLAY_FLAGS_INTERLACED) {
		ipu_di_sync_config_interlaced(di, sig);

		/* set y_sel = 1 */
		di_gen |= 0x10000000;

		vsync_cnt = 3;
	} else {
		ipu_di_sync_config_noninterlaced(di, sig, div);

		vsync_cnt = 3;
		if (di->id == 1)
			/*
			 * TODO: change only for TVEv2, parallel display
			 * uses pin 2 / 3
			 */
			if (!(sig->hsync_pin == 2 && sig->vsync_pin == 3))
				vsync_cnt = 6;
	}

	if (sig->mode.flags & DISPLAY_FLAGS_HSYNC_HIGH)
		di_gen |= ipu_di_gen_polarity(sig->hsync_pin);
	if (sig->mode.flags & DISPLAY_FLAGS_VSYNC_HIGH)
		di_gen |= ipu_di_gen_polarity(sig->vsync_pin);

	if (sig->clk_pol)
		di_gen |= DI_GEN_POLARITY_DISP_CLK;

	ipu_di_write(di, di_gen, DI_GENERAL);

	ipu_di_write(di, (--vsync_cnt << DI_VSYNC_SEL_OFFSET) | 0x00000002,
		     DI_SYNC_AS_GEN);

	reg = ipu_di_read(di, DI_POL);
	reg &= ~(DI_POL_DRDY_DATA_POLARITY | DI_POL_DRDY_POLARITY_15);

	if (sig->enable_pol)
		reg |= DI_POL_DRDY_POLARITY_15;
	if (sig->data_pol)
		reg |= DI_POL_DRDY_DATA_POLARITY;

	ipu_di_write(di, reg, DI_POL);

	mutex_unlock(&di_mutex);

	return 0;
}

int ipu_di_enable(struct ipu_di *di)
{
	int ret;

	WARN_ON(IS_ERR(di->clk_di_pixel));

	ret = clk_prepare_enable(di->clk_di_pixel);
	if (ret)
		return ret;

	ipu_module_enable(di->ipu, di->module);

	return 0;
}

int ipu_di_disable(struct ipu_di *di)
{
	WARN_ON(IS_ERR(di->clk_di_pixel));

	ipu_module_disable(di->ipu, di->module);

	clk_disable_unprepare(di->clk_di_pixel);

	return 0;
}

int ipu_di_get_num(struct ipu_di *di)
{
	return di->id;
}

struct ipu_di *ipu_di_get(struct ipu_soc *ipu, int disp)
{
	struct ipu_di *di;

	if (disp > 1)
		return ERR_PTR(-EINVAL);

	di = ipu->di_priv[disp];

	mutex_lock(&ipu_di_lock);

	if (di->inuse) {
		di = ERR_PTR(-EBUSY);
		goto out;
	}

	di->inuse = true;
out:
	mutex_unlock(&ipu_di_lock);

	return di;
}

void ipu_di_put(struct ipu_di *di)
{
	mutex_lock(&ipu_di_lock);

	di->inuse = false;

	mutex_unlock(&ipu_di_lock);
}

int ipu_di_init(struct ipu_soc *ipu, struct device *dev, int id,
		unsigned long base,
		u32 module, struct clk *clk_ipu)
{
	struct ipu_di *di;

	if (id > 1)
		return -ENODEV;

	di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	ipu->di_priv[id] = di;

	di->clk_di = devm_clk_get(dev, id ? "di1" : "di0");
	if (IS_ERR(di->clk_di))
		return PTR_ERR(di->clk_di);

	di->module = module;
	di->id = id;
	di->clk_ipu = clk_ipu;
	di->base = devm_ioremap(dev, base, PAGE_SIZE);
	if (!di->base)
		return -ENOMEM;

	ipu_di_write(di, 0x10, DI_BS_CLKGEN0);

	dev_dbg(dev, "DI%d base: 0x%08lx remapped to %p\n",
			id, base, di->base);
	di->inuse = false;
	di->ipu = ipu;

	return 0;
}

void ipu_di_exit(struct ipu_soc *ipu, int id)
{
}

