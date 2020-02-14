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
typedef  int /*<<< orphan*/  val ;
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
struct i2c_client {int dummy; } ;
struct drm_encoder {int dummy; } ;
struct drm_display_mode {scalar_t__ clock; scalar_t__ hdisplay; scalar_t__ vdisplay; scalar_t__ vtotal; scalar_t__ htotal; } ;
struct ch7006_tv_norm_info {int black_level; int subc_freq; int vtotal; int hvirtual; int vdisplay; int voffset; } ;
struct ch7006_state {int* regs; } ;
struct ch7006_priv {int norm; int brightness; int select_subconnector; int subconnector; scalar_t__ last_dpms; int chip_version; int flicker; int contrast; int hmargin; int vmargin; struct ch7006_mode* mode; struct ch7006_state state; } ;
struct ch7006_mode {int valid_norms; int subc_coeff; int enc_hdisp; scalar_t__ enc_vdisp; struct drm_display_mode mode; } ;
typedef  int int32_t ;
typedef  int fixed ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 size_t CH7006_BCLKOUT ; 
 size_t CH7006_BLACK_LEVEL ; 
 int /*<<< orphan*/  CH7006_BLACK_LEVEL_0 ; 
 size_t CH7006_BWIDTH ; 
 size_t CH7006_CALC_SUBC_INC0 ; 
 size_t CH7006_CLKMODE ; 
 size_t CH7006_CONTRAST ; 
 int /*<<< orphan*/  CH7006_CONTRAST_0 ; 
 size_t CH7006_DETECT ; 
 size_t CH7006_DISPMODE ; 
 size_t CH7006_FFILTER ; 
 int /*<<< orphan*/  CH7006_FFILTER_CHROMA ; 
 int /*<<< orphan*/  CH7006_FFILTER_LUMA ; 
 int /*<<< orphan*/  CH7006_FFILTER_TEXT ; 
 int CH7006_FREQ0 ; 
 size_t CH7006_HPOS ; 
 size_t CH7006_INPUT_FORMAT ; 
 int CH7006_INPUT_FORMAT_DAC_GAIN ; 
 size_t CH7006_INPUT_SYNC ; 
 int CH7006_MAXM ; 
 int CH7006_MAXN ; 
 size_t CH7006_PLLM ; 
 int /*<<< orphan*/  CH7006_PLLM_0 ; 
 size_t CH7006_PLLN ; 
 int /*<<< orphan*/  CH7006_PLLN_0 ; 
 size_t CH7006_PLLOV ; 
 int /*<<< orphan*/  CH7006_PLLOV_M_8 ; 
 int /*<<< orphan*/  CH7006_PLLOV_N_8 ; 
 size_t CH7006_PLL_CONTROL ; 
 int CH7006_PLL_CONTROL_CAPACITOR ; 
 size_t CH7006_POV ; 
 size_t CH7006_POWER ; 
 int /*<<< orphan*/  CH7006_POWER_LEVEL ; 
 int CH7006_POWER_RESET ; 
 int CH7006_POWER_SCART ; 
 size_t CH7006_START_ACTIVE ; 
 size_t CH7006_SUBC_INC0 ; 
 size_t CH7006_SUBC_INC1 ; 
 size_t CH7006_SUBC_INC2 ; 
 size_t CH7006_SUBC_INC3 ; 
 size_t CH7006_SUBC_INC4 ; 
 size_t CH7006_SUBC_INC5 ; 
 size_t CH7006_SUBC_INC6 ; 
 size_t CH7006_SUBC_INC7 ; 
 size_t CH7006_VPOS ; 
 int /*<<< orphan*/  CVBS_OFF ; 
 scalar_t__ DRM_MODE_DPMS_ON ; 
#define  DRM_MODE_SUBCONNECTOR_Composite 130 
#define  DRM_MODE_SUBCONNECTOR_SCART 129 
#define  DRM_MODE_SUBCONNECTOR_SVIDEO 128 
 int /*<<< orphan*/  FULL_POWER_OFF ; 
 int HPOS_8 ; 
 int /*<<< orphan*/  NORMAL ; 
 int /*<<< orphan*/  POWER_OFF ; 
 int /*<<< orphan*/  SVIDEO_OFF ; 
 int VPOS_8 ; 
 scalar_t__ abs (scalar_t__) ; 
 int bitf (int /*<<< orphan*/ ,int) ; 
 int bitfs (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ch7006_dbg (struct i2c_client*,char*,int,...) ; 
 int /*<<< orphan*/  ch7006_err (struct i2c_client*,char*,int,int) ; 
 int /*<<< orphan*/  ch7006_load_reg (struct i2c_client*,struct ch7006_state*,size_t) ; 
 struct ch7006_mode* ch7006_modes ; 
 int /*<<< orphan*/  ch7006_save_reg (struct i2c_client*,struct ch7006_state*,size_t) ; 
 struct ch7006_tv_norm_info* ch7006_tv_norms ; 
 int /*<<< orphan*/  do_div (int,scalar_t__) ; 
 struct i2c_client* drm_i2c_encoder_get_client (struct drm_encoder*) ; 
 int fixed1 ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  setbitf (struct ch7006_state*,size_t,int,int) ; 
 struct ch7006_priv* to_ch7006_priv (struct drm_encoder*) ; 

__attribute__((used)) static inline int interpolate(int y0, int y1, int y2, int x)
{
	return y1 + (x < 50 ? y1 - y0 : y2 - y1) * (x - 50) / 50;
}

__attribute__((used)) static inline int32_t round_fixed(fixed x)
{
	return (x + fixed1/2) >> 32;
}

const struct ch7006_mode *ch7006_lookup_mode(struct drm_encoder *encoder,
					     const struct drm_display_mode *drm_mode)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	const struct ch7006_mode *mode;

	for (mode = ch7006_modes; mode->mode.clock; mode++) {

		if (~mode->valid_norms & 1<<priv->norm)
			continue;

		if (mode->mode.hdisplay != drm_mode->hdisplay ||
		    mode->mode.vdisplay != drm_mode->vdisplay ||
		    mode->mode.vtotal != drm_mode->vtotal ||
		    mode->mode.htotal != drm_mode->htotal ||
		    mode->mode.clock != drm_mode->clock)
			continue;

		return mode;
	}

	return NULL;
}

void ch7006_setup_levels(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	uint8_t *regs = priv->state.regs;
	const struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
	int gain;
	int black_level;

	/* Set DAC_GAIN if the voltage drop between white and black is
	 * high enough. */
	if (norm->black_level < 339*fixed1/1000) {
		gain = 76;

		regs[CH7006_INPUT_FORMAT] |= CH7006_INPUT_FORMAT_DAC_GAIN;
	} else {
		gain = 71;

		regs[CH7006_INPUT_FORMAT] &= ~CH7006_INPUT_FORMAT_DAC_GAIN;
	}

	black_level = round_fixed(norm->black_level*26625)/gain;

	/* Correct it with the specified brightness. */
	black_level = interpolate(90, black_level, 208, priv->brightness);

	regs[CH7006_BLACK_LEVEL] = bitf(CH7006_BLACK_LEVEL_0, black_level);

	ch7006_dbg(client, "black level: %d\n", black_level);
}

void ch7006_setup_subcarrier(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_state *state = &priv->state;
	const struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
	const struct ch7006_mode *mode = priv->mode;
	uint32_t subc_inc;

	subc_inc = round_fixed((mode->subc_coeff >> 8)
			       * (norm->subc_freq >> 24));

	setbitf(state, CH7006_SUBC_INC0, 28, subc_inc);
	setbitf(state, CH7006_SUBC_INC1, 24, subc_inc);
	setbitf(state, CH7006_SUBC_INC2, 20, subc_inc);
	setbitf(state, CH7006_SUBC_INC3, 16, subc_inc);
	setbitf(state, CH7006_SUBC_INC4, 12, subc_inc);
	setbitf(state, CH7006_SUBC_INC5, 8, subc_inc);
	setbitf(state, CH7006_SUBC_INC6, 4, subc_inc);
	setbitf(state, CH7006_SUBC_INC7, 0, subc_inc);

	ch7006_dbg(client, "subcarrier inc: %u\n", subc_inc);
}

void ch7006_setup_pll(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	uint8_t *regs = priv->state.regs;
	const struct ch7006_mode *mode = priv->mode;
	int n, best_n = 0;
	int m, best_m = 0;
	int freq, best_freq = 0;

	for (n = 0; n < CH7006_MAXN; n++) {
		for (m = 0; m < CH7006_MAXM; m++) {
			freq = CH7006_FREQ0*(n+2)/(m+2);

			if (abs(freq - mode->mode.clock) <
			    abs(best_freq - mode->mode.clock)) {
				best_freq = freq;
				best_n = n;
				best_m = m;
			}
		}
	}

	regs[CH7006_PLLOV] = bitf(CH7006_PLLOV_N_8, best_n) |
		bitf(CH7006_PLLOV_M_8, best_m);

	regs[CH7006_PLLM] = bitf(CH7006_PLLM_0, best_m);
	regs[CH7006_PLLN] = bitf(CH7006_PLLN_0, best_n);

	if (best_n < 108)
		regs[CH7006_PLL_CONTROL] |= CH7006_PLL_CONTROL_CAPACITOR;
	else
		regs[CH7006_PLL_CONTROL] &= ~CH7006_PLL_CONTROL_CAPACITOR;

	ch7006_dbg(client, "n=%d m=%d f=%d c=%d\n",
		   best_n, best_m, best_freq, best_n < 108);
}

void ch7006_setup_power_state(struct drm_encoder *encoder)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	uint8_t *power = &priv->state.regs[CH7006_POWER];
	int subconnector;

	subconnector = priv->select_subconnector ? priv->select_subconnector :
							priv->subconnector;

	*power = CH7006_POWER_RESET;

	if (priv->last_dpms == DRM_MODE_DPMS_ON) {
		switch (subconnector) {
		case DRM_MODE_SUBCONNECTOR_SVIDEO:
			*power |= bitfs(CH7006_POWER_LEVEL, CVBS_OFF);
			break;
		case DRM_MODE_SUBCONNECTOR_Composite:
			*power |= bitfs(CH7006_POWER_LEVEL, SVIDEO_OFF);
			break;
		case DRM_MODE_SUBCONNECTOR_SCART:
			*power |= bitfs(CH7006_POWER_LEVEL, NORMAL) |
				CH7006_POWER_SCART;
			break;
		}

	} else {
		if (priv->chip_version >= 0x20)
			*power |= bitfs(CH7006_POWER_LEVEL, FULL_POWER_OFF);
		else
			*power |= bitfs(CH7006_POWER_LEVEL, POWER_OFF);
	}
}

void ch7006_setup_properties(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_state *state = &priv->state;
	const struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
	const struct ch7006_mode *ch_mode = priv->mode;
	const struct drm_display_mode *mode = &ch_mode->mode;
	uint8_t *regs = state->regs;
	int flicker, contrast, hpos, vpos;
	uint64_t scale, aspect;

	flicker = interpolate(0, 2, 3, priv->flicker);
	regs[CH7006_FFILTER] = bitf(CH7006_FFILTER_TEXT, flicker) |
		bitf(CH7006_FFILTER_LUMA, flicker) |
		bitf(CH7006_FFILTER_CHROMA, 1);

	contrast = interpolate(0, 5, 7, priv->contrast);
	regs[CH7006_CONTRAST] = bitf(CH7006_CONTRAST_0, contrast);

	scale = norm->vtotal*fixed1;
	do_div(scale, mode->vtotal);

	aspect = ch_mode->enc_hdisp*fixed1;
	do_div(aspect, ch_mode->enc_vdisp);

	hpos = round_fixed((norm->hvirtual * aspect - mode->hdisplay * scale)
			   * priv->hmargin * mode->vtotal) / norm->vtotal / 100 / 4;

	setbitf(state, CH7006_POV, HPOS_8, hpos);
	setbitf(state, CH7006_HPOS, 0, hpos);

	vpos = max(0, norm->vdisplay - round_fixed(mode->vdisplay*scale)
		   + norm->voffset) * priv->vmargin / 100 / 2;

	setbitf(state, CH7006_POV, VPOS_8, vpos);
	setbitf(state, CH7006_VPOS, 0, vpos);

	ch7006_dbg(client, "hpos: %d, vpos: %d\n", hpos, vpos);
}

void ch7006_write(struct i2c_client *client, uint8_t addr, uint8_t val)
{
	uint8_t buf[] = {addr, val};
	int ret;

	ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
	if (ret < 0)
		ch7006_err(client, "Error %d writing to subaddress 0x%x\n",
			   ret, addr);
}

uint8_t ch7006_read(struct i2c_client *client, uint8_t addr)
{
	uint8_t val;
	int ret;

	ret = i2c_master_send(client, &addr, sizeof(addr));
	if (ret < 0)
		goto fail;

	ret = i2c_master_recv(client, &val, sizeof(val));
	if (ret < 0)
		goto fail;

	return val;

fail:
	ch7006_err(client, "Error %d reading from subaddress 0x%x\n",
		   ret, addr);
	return 0;
}

void ch7006_state_load(struct i2c_client *client,
		       struct ch7006_state *state)
{
	ch7006_load_reg(client, state, CH7006_POWER);

	ch7006_load_reg(client, state, CH7006_DISPMODE);
	ch7006_load_reg(client, state, CH7006_FFILTER);
	ch7006_load_reg(client, state, CH7006_BWIDTH);
	ch7006_load_reg(client, state, CH7006_INPUT_FORMAT);
	ch7006_load_reg(client, state, CH7006_CLKMODE);
	ch7006_load_reg(client, state, CH7006_START_ACTIVE);
	ch7006_load_reg(client, state, CH7006_POV);
	ch7006_load_reg(client, state, CH7006_BLACK_LEVEL);
	ch7006_load_reg(client, state, CH7006_HPOS);
	ch7006_load_reg(client, state, CH7006_VPOS);
	ch7006_load_reg(client, state, CH7006_INPUT_SYNC);
	ch7006_load_reg(client, state, CH7006_DETECT);
	ch7006_load_reg(client, state, CH7006_CONTRAST);
	ch7006_load_reg(client, state, CH7006_PLLOV);
	ch7006_load_reg(client, state, CH7006_PLLM);
	ch7006_load_reg(client, state, CH7006_PLLN);
	ch7006_load_reg(client, state, CH7006_BCLKOUT);
	ch7006_load_reg(client, state, CH7006_SUBC_INC0);
	ch7006_load_reg(client, state, CH7006_SUBC_INC1);
	ch7006_load_reg(client, state, CH7006_SUBC_INC2);
	ch7006_load_reg(client, state, CH7006_SUBC_INC3);
	ch7006_load_reg(client, state, CH7006_SUBC_INC4);
	ch7006_load_reg(client, state, CH7006_SUBC_INC5);
	ch7006_load_reg(client, state, CH7006_SUBC_INC6);
	ch7006_load_reg(client, state, CH7006_SUBC_INC7);
	ch7006_load_reg(client, state, CH7006_PLL_CONTROL);
	ch7006_load_reg(client, state, CH7006_CALC_SUBC_INC0);
}

void ch7006_state_save(struct i2c_client *client,
		       struct ch7006_state *state)
{
	ch7006_save_reg(client, state, CH7006_POWER);

	ch7006_save_reg(client, state, CH7006_DISPMODE);
	ch7006_save_reg(client, state, CH7006_FFILTER);
	ch7006_save_reg(client, state, CH7006_BWIDTH);
	ch7006_save_reg(client, state, CH7006_INPUT_FORMAT);
	ch7006_save_reg(client, state, CH7006_CLKMODE);
	ch7006_save_reg(client, state, CH7006_START_ACTIVE);
	ch7006_save_reg(client, state, CH7006_POV);
	ch7006_save_reg(client, state, CH7006_BLACK_LEVEL);
	ch7006_save_reg(client, state, CH7006_HPOS);
	ch7006_save_reg(client, state, CH7006_VPOS);
	ch7006_save_reg(client, state, CH7006_INPUT_SYNC);
	ch7006_save_reg(client, state, CH7006_DETECT);
	ch7006_save_reg(client, state, CH7006_CONTRAST);
	ch7006_save_reg(client, state, CH7006_PLLOV);
	ch7006_save_reg(client, state, CH7006_PLLM);
	ch7006_save_reg(client, state, CH7006_PLLN);
	ch7006_save_reg(client, state, CH7006_BCLKOUT);
	ch7006_save_reg(client, state, CH7006_SUBC_INC0);
	ch7006_save_reg(client, state, CH7006_SUBC_INC1);
	ch7006_save_reg(client, state, CH7006_SUBC_INC2);
	ch7006_save_reg(client, state, CH7006_SUBC_INC3);
	ch7006_save_reg(client, state, CH7006_SUBC_INC4);
	ch7006_save_reg(client, state, CH7006_SUBC_INC5);
	ch7006_save_reg(client, state, CH7006_SUBC_INC6);
	ch7006_save_reg(client, state, CH7006_SUBC_INC7);
	ch7006_save_reg(client, state, CH7006_PLL_CONTROL);
	ch7006_save_reg(client, state, CH7006_CALC_SUBC_INC0);

	state->regs[CH7006_FFILTER] = (state->regs[CH7006_FFILTER] & 0xf0) |
		(state->regs[CH7006_FFILTER] & 0x0c) >> 2 |
		(state->regs[CH7006_FFILTER] & 0x03) << 2;
}

