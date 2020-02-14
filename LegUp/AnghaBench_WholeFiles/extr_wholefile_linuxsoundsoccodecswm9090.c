#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {unsigned int* agc; scalar_t__ agc_ena; scalar_t__ lin2_diff; scalar_t__ lin1_diff; } ;
struct wm9090_priv {TYPE_1__ pdata; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_kcontrol {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  platform_data; } ;
struct i2c_client {TYPE_2__ dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 173 
#define  SND_SOC_BIAS_ON 172 
#define  SND_SOC_BIAS_PREPARE 171 
#define  SND_SOC_BIAS_STANDBY 170 
#define  SND_SOC_DAPM_POST_PMU 169 
#define  SND_SOC_DAPM_PRE_PMD 168 
#define  WM9090_AGC_CONTROL_0 167 
#define  WM9090_AGC_CONTROL_1 166 
#define  WM9090_AGC_CONTROL_2 165 
 int WM9090_AGC_ENA ; 
#define  WM9090_ANALOGUE_HP_0 164 
#define  WM9090_ANTIPOP2 163 
 int WM9090_BIAS_ENA ; 
#define  WM9090_CHARGE_PUMP_1 162 
#define  WM9090_CLASSD3 161 
#define  WM9090_CLOCKING_1 160 
 int WM9090_CP_ENA ; 
 unsigned int WM9090_DCS_CAL_COMPLETE_MASK ; 
 unsigned int WM9090_DCS_ENA_CHAN_0 ; 
 unsigned int WM9090_DCS_ENA_CHAN_1 ; 
 unsigned int WM9090_DCS_TRIG_STARTUP_0 ; 
 unsigned int WM9090_DCS_TRIG_STARTUP_1 ; 
#define  WM9090_DC_SERVO_0 159 
#define  WM9090_DC_SERVO_1 158 
#define  WM9090_DC_SERVO_3 157 
#define  WM9090_DC_SERVO_READBACK_0 156 
#define  WM9090_DC_SERVO_READBACK_1 155 
#define  WM9090_DC_SERVO_READBACK_2 154 
 unsigned int WM9090_HPOUT1L_DLY ; 
 int WM9090_HPOUT1L_ENA ; 
 unsigned int WM9090_HPOUT1L_OUTP ; 
 unsigned int WM9090_HPOUT1L_RMV_SHORT ; 
 int WM9090_HPOUT1L_ZC ; 
 unsigned int WM9090_HPOUT1R_DLY ; 
 int WM9090_HPOUT1R_ENA ; 
 unsigned int WM9090_HPOUT1R_OUTP ; 
 unsigned int WM9090_HPOUT1R_RMV_SHORT ; 
 int WM9090_HPOUT1R_ZC ; 
 int WM9090_HPOUT1_VU ; 
 int WM9090_IN1A_ZC ; 
 int WM9090_IN1B_ZC ; 
#define  WM9090_IN1_LINE_CONTROL 153 
#define  WM9090_IN1_LINE_INPUT_A_VOLUME 152 
#define  WM9090_IN1_LINE_INPUT_B_VOLUME 151 
 int WM9090_IN1_VU ; 
 int WM9090_IN2A_ZC ; 
 int WM9090_IN2B_ZC ; 
#define  WM9090_IN2_LINE_CONTROL 150 
#define  WM9090_IN2_LINE_INPUT_A_VOLUME 149 
#define  WM9090_IN2_LINE_INPUT_B_VOLUME 148 
 int WM9090_IN2_VU ; 
#define  WM9090_LEFT_OUTPUT_VOLUME 147 
#define  WM9090_OUTPUT_MIXER1 146 
#define  WM9090_OUTPUT_MIXER2 145 
#define  WM9090_OUTPUT_MIXER3 144 
#define  WM9090_OUTPUT_MIXER4 143 
#define  WM9090_POWER_MANAGEMENT_1 142 
#define  WM9090_POWER_MANAGEMENT_2 141 
#define  WM9090_POWER_MANAGEMENT_3 140 
#define  WM9090_RIGHT_OUTPUT_VOLUME 139 
#define  WM9090_SOFTWARE_RESET 138 
#define  WM9090_SPEAKER_MIXER 137 
#define  WM9090_SPEAKER_VOLUME_LEFT 136 
#define  WM9090_SPKMIXL_ATTENUATION 135 
 int WM9090_SPKOUTL_ZC ; 
#define  WM9090_SPKOUT_MIXERS 134 
 int WM9090_SPKOUT_VU ; 
 int WM9090_TOCLK_ENA ; 
 int WM9090_VMID_ENA ; 
 int WM9090_VMID_RES_MASK ; 
 int WM9090_VMID_RES_SHIFT ; 
#define  WM9090_WRITE_SEQUENCER_0 133 
#define  WM9090_WRITE_SEQUENCER_1 132 
#define  WM9090_WRITE_SEQUENCER_2 131 
#define  WM9090_WRITE_SEQUENCER_3 130 
#define  WM9090_WRITE_SEQUENCER_4 129 
#define  WM9090_WRITE_SEQUENCER_5 128 
 unsigned int* audio_map ; 
 unsigned int* audio_map_in1_diff ; 
 unsigned int* audio_map_in1_se ; 
 unsigned int* audio_map_in2_diff ; 
 unsigned int* audio_map_in2_se ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct wm9090_priv* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct wm9090_priv*) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,unsigned int*,int) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct wm9090_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 unsigned int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int const,unsigned int) ; 
 int /*<<< orphan*/  snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,unsigned int*,int) ; 
 int /*<<< orphan*/  snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,unsigned int*,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm9090 ; 
 unsigned int* wm9090_controls ; 
 unsigned int* wm9090_dapm_widgets ; 
 unsigned int* wm9090_in1_se_controls ; 
 unsigned int* wm9090_in2_se_controls ; 
 int /*<<< orphan*/  wm9090_regmap ; 

__attribute__((used)) static bool wm9090_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM9090_SOFTWARE_RESET:
	case WM9090_DC_SERVO_0:
	case WM9090_DC_SERVO_READBACK_0:
	case WM9090_DC_SERVO_READBACK_1:
	case WM9090_DC_SERVO_READBACK_2:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static bool wm9090_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM9090_SOFTWARE_RESET:
	case WM9090_POWER_MANAGEMENT_1:
	case WM9090_POWER_MANAGEMENT_2:
	case WM9090_POWER_MANAGEMENT_3:
	case WM9090_CLOCKING_1:
	case WM9090_IN1_LINE_CONTROL:
	case WM9090_IN2_LINE_CONTROL:
	case WM9090_IN1_LINE_INPUT_A_VOLUME:
	case WM9090_IN1_LINE_INPUT_B_VOLUME:
	case WM9090_IN2_LINE_INPUT_A_VOLUME:
	case WM9090_IN2_LINE_INPUT_B_VOLUME:
	case WM9090_LEFT_OUTPUT_VOLUME:
	case WM9090_RIGHT_OUTPUT_VOLUME:
	case WM9090_SPKMIXL_ATTENUATION:
	case WM9090_SPKOUT_MIXERS:
	case WM9090_CLASSD3:
	case WM9090_SPEAKER_VOLUME_LEFT:
	case WM9090_OUTPUT_MIXER1:
	case WM9090_OUTPUT_MIXER2:
	case WM9090_OUTPUT_MIXER3:
	case WM9090_OUTPUT_MIXER4:
	case WM9090_SPEAKER_MIXER:
	case WM9090_ANTIPOP2:
	case WM9090_WRITE_SEQUENCER_0:
	case WM9090_WRITE_SEQUENCER_1:
	case WM9090_WRITE_SEQUENCER_2:
	case WM9090_WRITE_SEQUENCER_3:
	case WM9090_WRITE_SEQUENCER_4:
	case WM9090_WRITE_SEQUENCER_5:
	case WM9090_CHARGE_PUMP_1:
	case WM9090_DC_SERVO_0:
	case WM9090_DC_SERVO_1:
	case WM9090_DC_SERVO_3:
	case WM9090_DC_SERVO_READBACK_0:
	case WM9090_DC_SERVO_READBACK_1:
	case WM9090_DC_SERVO_READBACK_2:
	case WM9090_ANALOGUE_HP_0:
	case WM9090_AGC_CONTROL_0:
	case WM9090_AGC_CONTROL_1:
	case WM9090_AGC_CONTROL_2:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static void wait_for_dc_servo(struct snd_soc_component *component)
{
	unsigned int reg;
	int count = 0;

	dev_dbg(component->dev, "Waiting for DC servo...\n");
	do {
		count++;
		msleep(1);
		reg = snd_soc_component_read32(component, WM9090_DC_SERVO_READBACK_0);
		dev_dbg(component->dev, "DC servo status: %x\n", reg);
	} while ((reg & WM9090_DCS_CAL_COMPLETE_MASK)
		 != WM9090_DCS_CAL_COMPLETE_MASK && count < 1000);

	if ((reg & WM9090_DCS_CAL_COMPLETE_MASK)
	    != WM9090_DCS_CAL_COMPLETE_MASK)
		dev_err(component->dev, "Timed out waiting for DC Servo\n");
}

__attribute__((used)) static int hp_ev(struct snd_soc_dapm_widget *w,
		 struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	unsigned int reg = snd_soc_component_read32(component, WM9090_ANALOGUE_HP_0);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, WM9090_CHARGE_PUMP_1,
				    WM9090_CP_ENA, WM9090_CP_ENA);

		msleep(5);

		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_1,
				    WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA,
				    WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA);

		reg |= WM9090_HPOUT1L_DLY | WM9090_HPOUT1R_DLY;
		snd_soc_component_write(component, WM9090_ANALOGUE_HP_0, reg);

		/* Start the DC servo.  We don't currently use the
		 * ability to save the state since we don't have full
		 * control of the analogue paths and they can change
		 * DC offsets; see the WM8904 driver for an example of
		 * doing so.
		 */
		snd_soc_component_write(component, WM9090_DC_SERVO_0,
			      WM9090_DCS_ENA_CHAN_0 |
			      WM9090_DCS_ENA_CHAN_1 |
			      WM9090_DCS_TRIG_STARTUP_1 |
			      WM9090_DCS_TRIG_STARTUP_0);
		wait_for_dc_servo(component);

		reg |= WM9090_HPOUT1R_OUTP | WM9090_HPOUT1R_RMV_SHORT |
			WM9090_HPOUT1L_OUTP | WM9090_HPOUT1L_RMV_SHORT;
		snd_soc_component_write(component, WM9090_ANALOGUE_HP_0, reg);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		reg &= ~(WM9090_HPOUT1L_RMV_SHORT |
			 WM9090_HPOUT1L_DLY |
			 WM9090_HPOUT1L_OUTP |
			 WM9090_HPOUT1R_RMV_SHORT |
			 WM9090_HPOUT1R_DLY |
			 WM9090_HPOUT1R_OUTP);

		snd_soc_component_write(component, WM9090_ANALOGUE_HP_0, reg);

		snd_soc_component_write(component, WM9090_DC_SERVO_0, 0);

		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_1,
				    WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA,
				    0);

		snd_soc_component_update_bits(component, WM9090_CHARGE_PUMP_1,
				    WM9090_CP_ENA, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int wm9090_add_controls(struct snd_soc_component *component)
{
	struct wm9090_priv *wm9090 = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	int i;

	snd_soc_dapm_new_controls(dapm, wm9090_dapm_widgets,
				  ARRAY_SIZE(wm9090_dapm_widgets));

	snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));

	snd_soc_add_component_controls(component, wm9090_controls,
			     ARRAY_SIZE(wm9090_controls));

	if (wm9090->pdata.lin1_diff) {
		snd_soc_dapm_add_routes(dapm, audio_map_in1_diff,
					ARRAY_SIZE(audio_map_in1_diff));
	} else {
		snd_soc_dapm_add_routes(dapm, audio_map_in1_se,
					ARRAY_SIZE(audio_map_in1_se));
		snd_soc_add_component_controls(component, wm9090_in1_se_controls,
				     ARRAY_SIZE(wm9090_in1_se_controls));
	}

	if (wm9090->pdata.lin2_diff) {
		snd_soc_dapm_add_routes(dapm, audio_map_in2_diff,
					ARRAY_SIZE(audio_map_in2_diff));
	} else {
		snd_soc_dapm_add_routes(dapm, audio_map_in2_se,
					ARRAY_SIZE(audio_map_in2_se));
		snd_soc_add_component_controls(component, wm9090_in2_se_controls,
				     ARRAY_SIZE(wm9090_in2_se_controls));
	}

	if (wm9090->pdata.agc_ena) {
		for (i = 0; i < ARRAY_SIZE(wm9090->pdata.agc); i++)
			snd_soc_component_write(component, WM9090_AGC_CONTROL_0 + i,
				      wm9090->pdata.agc[i]);
		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_3,
				    WM9090_AGC_ENA, WM9090_AGC_ENA);
	} else {
		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_3,
				    WM9090_AGC_ENA, 0);
	}

	return 0;

}

__attribute__((used)) static int wm9090_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct wm9090_priv *wm9090 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		snd_soc_component_update_bits(component, WM9090_ANTIPOP2, WM9090_VMID_ENA,
				    WM9090_VMID_ENA);
		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_1,
				    WM9090_BIAS_ENA |
				    WM9090_VMID_RES_MASK,
				    WM9090_BIAS_ENA |
				    1 << WM9090_VMID_RES_SHIFT);
		msleep(1);  /* Probably an overestimate */
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			/* Restore the register cache */
			regcache_sync(wm9090->regmap);
		}

		/* We keep VMID off during standby since the combination of
		 * ground referenced outputs and class D speaker mean that
		 * latency is not an issue.
		 */
		snd_soc_component_update_bits(component, WM9090_POWER_MANAGEMENT_1,
				    WM9090_BIAS_ENA | WM9090_VMID_RES_MASK, 0);
		snd_soc_component_update_bits(component, WM9090_ANTIPOP2,
				    WM9090_VMID_ENA, 0);
		break;

	case SND_SOC_BIAS_OFF:
		break;
	}

	return 0;
}

__attribute__((used)) static int wm9090_probe(struct snd_soc_component *component)
{
	/* Configure some defaults; they will be written out when we
	 * bring the bias up.
	 */
	snd_soc_component_update_bits(component, WM9090_IN1_LINE_INPUT_A_VOLUME,
			    WM9090_IN1_VU | WM9090_IN1A_ZC,
			    WM9090_IN1_VU | WM9090_IN1A_ZC);
	snd_soc_component_update_bits(component, WM9090_IN1_LINE_INPUT_B_VOLUME,
			    WM9090_IN1_VU | WM9090_IN1B_ZC,
			    WM9090_IN1_VU | WM9090_IN1B_ZC);
	snd_soc_component_update_bits(component, WM9090_IN2_LINE_INPUT_A_VOLUME,
			    WM9090_IN2_VU | WM9090_IN2A_ZC,
			    WM9090_IN2_VU | WM9090_IN2A_ZC);
	snd_soc_component_update_bits(component, WM9090_IN2_LINE_INPUT_B_VOLUME,
			    WM9090_IN2_VU | WM9090_IN2B_ZC,
			    WM9090_IN2_VU | WM9090_IN2B_ZC);
	snd_soc_component_update_bits(component, WM9090_SPEAKER_VOLUME_LEFT,
			    WM9090_SPKOUT_VU | WM9090_SPKOUTL_ZC,
			    WM9090_SPKOUT_VU | WM9090_SPKOUTL_ZC);
	snd_soc_component_update_bits(component, WM9090_LEFT_OUTPUT_VOLUME,
			    WM9090_HPOUT1_VU | WM9090_HPOUT1L_ZC,
			    WM9090_HPOUT1_VU | WM9090_HPOUT1L_ZC);
	snd_soc_component_update_bits(component, WM9090_RIGHT_OUTPUT_VOLUME,
			    WM9090_HPOUT1_VU | WM9090_HPOUT1R_ZC,
			    WM9090_HPOUT1_VU | WM9090_HPOUT1R_ZC);

	snd_soc_component_update_bits(component, WM9090_CLOCKING_1,
			    WM9090_TOCLK_ENA, WM9090_TOCLK_ENA);

	wm9090_add_controls(component);

	return 0;
}

__attribute__((used)) static int wm9090_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct wm9090_priv *wm9090;
	unsigned int reg;
	int ret;

	wm9090 = devm_kzalloc(&i2c->dev, sizeof(*wm9090), GFP_KERNEL);
	if (!wm9090)
		return -ENOMEM;

	wm9090->regmap = devm_regmap_init_i2c(i2c, &wm9090_regmap);
	if (IS_ERR(wm9090->regmap)) {
		ret = PTR_ERR(wm9090->regmap);
		dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
		return ret;
	}

	ret = regmap_read(wm9090->regmap, WM9090_SOFTWARE_RESET, &reg);
	if (ret < 0)
		return ret;

	if (reg != 0x9093) {
		dev_err(&i2c->dev, "Device is not a WM9090, ID=%x\n", reg);
		return -ENODEV;
	}

	ret = regmap_write(wm9090->regmap, WM9090_SOFTWARE_RESET, 0);
	if (ret < 0)
		return ret;

	if (i2c->dev.platform_data)
		memcpy(&wm9090->pdata, i2c->dev.platform_data,
		       sizeof(wm9090->pdata));

	i2c_set_clientdata(i2c, wm9090);

	ret =  devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_wm9090,  NULL, 0);
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
		return ret;
	}

	return 0;
}

