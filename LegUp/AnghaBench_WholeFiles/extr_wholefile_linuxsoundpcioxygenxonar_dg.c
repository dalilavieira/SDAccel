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
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_info_buffer {int dummy; } ;
struct oxygen {struct dg* model_data; int /*<<< orphan*/  card; } ;
struct dg {unsigned int* cs4245_shadow; int output_sel; int /*<<< orphan*/  input_sel; } ;
typedef  enum cs4245_shadow_operation { ____Placeholder_cs4245_shadow_operation } cs4245_shadow_operation ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (unsigned int*) ; 
 int /*<<< orphan*/  CAPTURE_SRC_MIC ; 
 size_t CS4245_ADC_CTRL ; 
 unsigned char CS4245_ADC_DIF_LJUST ; 
 unsigned char CS4245_ADC_FM_DOUBLE ; 
 unsigned char CS4245_ADC_FM_MASK ; 
 unsigned char CS4245_ADC_FM_QUAD ; 
 unsigned char CS4245_ADC_FM_SINGLE ; 
 size_t CS4245_ANALOG_IN ; 
 int CS4245_ASYNCH ; 
 int CS4245_A_OUT_SEL_DAC ; 
 size_t CS4245_DAC_A_CTRL ; 
 size_t CS4245_DAC_B_CTRL ; 
 size_t CS4245_DAC_CTRL_1 ; 
 size_t CS4245_DAC_CTRL_2 ; 
 unsigned char CS4245_DAC_DIF_LJUST ; 
 unsigned char CS4245_DAC_FM_DOUBLE ; 
 unsigned char CS4245_DAC_FM_MASK ; 
 unsigned char CS4245_DAC_FM_QUAD ; 
 unsigned char CS4245_DAC_FM_SINGLE ; 
 int CS4245_DAC_SOFT ; 
 int CS4245_DAC_ZERO ; 
 int CS4245_INT_STATUS ; 
 int CS4245_INVERT_DAC ; 
 int CS4245_LOAD_FROM_SHADOW ; 
 unsigned char CS4245_MCLK1_MASK ; 
 unsigned char CS4245_MCLK1_SHIFT ; 
 unsigned char CS4245_MCLK2_MASK ; 
 unsigned char CS4245_MCLK2_SHIFT ; 
 unsigned char CS4245_MCLK_1 ; 
 unsigned char CS4245_MCLK_2 ; 
 size_t CS4245_MCLK_FREQ ; 
 size_t CS4245_PGA_A_CTRL ; 
 size_t CS4245_PGA_B_CTRL ; 
 int CS4245_PGA_SOFT ; 
 int CS4245_PGA_ZERO ; 
 size_t CS4245_POWER_CTRL ; 
 int CS4245_SAVE_TO_SHADOW ; 
 size_t CS4245_SIGNAL_SEL ; 
 int CS4245_SPI_ADDRESS ; 
 int CS4245_SPI_READ ; 
 int CS4245_SPI_WRITE ; 
 int GPIO_HP_REAR ; 
 int GPIO_INPUT_ROUTE ; 
 int GPIO_OUTPUT_ENABLE ; 
 unsigned int OXYGEN_GPIO_CONTROL ; 
 unsigned int OXYGEN_GPIO_DATA ; 
 unsigned int OXYGEN_PLAY_DAC0_SOURCE_MASK ; 
 unsigned int OXYGEN_PLAY_DAC0_SOURCE_SHIFT ; 
 unsigned int OXYGEN_PLAY_DAC1_SOURCE_MASK ; 
 unsigned int OXYGEN_PLAY_DAC1_SOURCE_SHIFT ; 
 unsigned int OXYGEN_PLAY_DAC2_SOURCE_MASK ; 
 unsigned int OXYGEN_PLAY_DAC2_SOURCE_SHIFT ; 
 unsigned int OXYGEN_PLAY_DAC3_SOURCE_MASK ; 
 unsigned int OXYGEN_PLAY_DAC3_SOURCE_SHIFT ; 
 int OXYGEN_PLAY_MUTE01 ; 
 int OXYGEN_PLAY_MUTE23 ; 
 int OXYGEN_PLAY_MUTE45 ; 
 int OXYGEN_PLAY_MUTE67 ; 
 int OXYGEN_PLAY_MUTE_MASK ; 
 unsigned int OXYGEN_PLAY_ROUTING ; 
 int OXYGEN_SPI_CEN_LATCH_CLOCK_HI ; 
 int OXYGEN_SPI_CLOCK_1280 ; 
 int OXYGEN_SPI_CODEC_SHIFT ; 
 int /*<<< orphan*/  OXYGEN_SPI_DATA1 ; 
 int OXYGEN_SPI_DATA_LENGTH_2 ; 
 int OXYGEN_SPI_DATA_LENGTH_3 ; 
 int OXYGEN_SPI_TRIGGER ; 
#define  PLAYBACK_DST_HP 130 
#define  PLAYBACK_DST_HP_FP 129 
#define  PLAYBACK_DST_MULTICH 128 
 int /*<<< orphan*/  msleep (int) ; 
 unsigned int oxygen_read8 (struct oxygen*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write16 (struct oxygen*,unsigned int,int) ; 
 int /*<<< orphan*/  oxygen_write16_masked (struct oxygen*,unsigned int,int,int) ; 
 int /*<<< orphan*/  oxygen_write32_masked (struct oxygen*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write8_masked (struct oxygen*,unsigned int,int,int) ; 
 int /*<<< orphan*/  oxygen_write_ac97_masked (struct oxygen*,unsigned int,unsigned int,int,int) ; 
 int oxygen_write_spi (struct oxygen*,int,int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_component_add (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 

__attribute__((used)) static inline void oxygen_set_bits8(struct oxygen *chip,
				    unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits16(struct oxygen *chip,
				     unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits32(struct oxygen *chip,
				     unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_clear_bits8(struct oxygen *chip,
				      unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits16(struct oxygen *chip,
				       unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits32(struct oxygen *chip,
				       unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_ac97_set_bits(struct oxygen *chip, unsigned int codec,
					unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, value, value);
}

__attribute__((used)) static inline void oxygen_ac97_clear_bits(struct oxygen *chip,
					  unsigned int codec,
					  unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, 0, value);
}

int cs4245_write_spi(struct oxygen *chip, u8 reg)
{
	struct dg *data = chip->model_data;
	unsigned int packet;

	packet = reg << 8;
	packet |= (CS4245_SPI_ADDRESS | CS4245_SPI_WRITE) << 16;
	packet |= data->cs4245_shadow[reg];

	return oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
				OXYGEN_SPI_DATA_LENGTH_3 |
				OXYGEN_SPI_CLOCK_1280 |
				(0 << OXYGEN_SPI_CODEC_SHIFT) |
				OXYGEN_SPI_CEN_LATCH_CLOCK_HI,
				packet);
}

int cs4245_read_spi(struct oxygen *chip, u8 addr)
{
	struct dg *data = chip->model_data;
	int ret;

	ret = oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
		OXYGEN_SPI_DATA_LENGTH_2 |
		OXYGEN_SPI_CEN_LATCH_CLOCK_HI |
		OXYGEN_SPI_CLOCK_1280 | (0 << OXYGEN_SPI_CODEC_SHIFT),
		((CS4245_SPI_ADDRESS | CS4245_SPI_WRITE) << 8) | addr);
	if (ret < 0)
		return ret;

	ret = oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
		OXYGEN_SPI_DATA_LENGTH_2 |
		OXYGEN_SPI_CEN_LATCH_CLOCK_HI |
		OXYGEN_SPI_CLOCK_1280 | (0 << OXYGEN_SPI_CODEC_SHIFT),
		(CS4245_SPI_ADDRESS | CS4245_SPI_READ) << 8);
	if (ret < 0)
		return ret;

	data->cs4245_shadow[addr] = oxygen_read8(chip, OXYGEN_SPI_DATA1);

	return 0;
}

int cs4245_shadow_control(struct oxygen *chip, enum cs4245_shadow_operation op)
{
	struct dg *data = chip->model_data;
	unsigned char addr;
	int ret;

	for (addr = 1; addr < ARRAY_SIZE(data->cs4245_shadow); addr++) {
		ret = (op == CS4245_SAVE_TO_SHADOW ?
			cs4245_read_spi(chip, addr) :
			cs4245_write_spi(chip, addr));
		if (ret < 0)
			return ret;
	}
	return 0;
}

__attribute__((used)) static void cs4245_init(struct oxygen *chip)
{
	struct dg *data = chip->model_data;

	/* save the initial state: codec version, registers */
	cs4245_shadow_control(chip, CS4245_SAVE_TO_SHADOW);

	/*
	 * Power up the CODEC internals, enable soft ramp & zero cross, work in
	 * async. mode, enable aux output from DAC. Invert DAC output as in the
	 * Windows driver.
	 */
	data->cs4245_shadow[CS4245_POWER_CTRL] = 0;
	data->cs4245_shadow[CS4245_SIGNAL_SEL] =
		CS4245_A_OUT_SEL_DAC | CS4245_ASYNCH;
	data->cs4245_shadow[CS4245_DAC_CTRL_1] =
		CS4245_DAC_FM_SINGLE | CS4245_DAC_DIF_LJUST;
	data->cs4245_shadow[CS4245_DAC_CTRL_2] =
		CS4245_DAC_SOFT | CS4245_DAC_ZERO | CS4245_INVERT_DAC;
	data->cs4245_shadow[CS4245_ADC_CTRL] =
		CS4245_ADC_FM_SINGLE | CS4245_ADC_DIF_LJUST;
	data->cs4245_shadow[CS4245_ANALOG_IN] =
		CS4245_PGA_SOFT | CS4245_PGA_ZERO;
	data->cs4245_shadow[CS4245_PGA_B_CTRL] = 0;
	data->cs4245_shadow[CS4245_PGA_A_CTRL] = 0;
	data->cs4245_shadow[CS4245_DAC_A_CTRL] = 8;
	data->cs4245_shadow[CS4245_DAC_B_CTRL] = 8;

	cs4245_shadow_control(chip, CS4245_LOAD_FROM_SHADOW);
	snd_component_add(chip->card, "CS4245");
}

void dg_init(struct oxygen *chip)
{
	struct dg *data = chip->model_data;

	data->output_sel = PLAYBACK_DST_HP_FP;
	data->input_sel = CAPTURE_SRC_MIC;

	cs4245_init(chip);
	oxygen_write16(chip, OXYGEN_GPIO_CONTROL,
		       GPIO_OUTPUT_ENABLE | GPIO_HP_REAR | GPIO_INPUT_ROUTE);
	/* anti-pop delay, wait some time before enabling the output */
	msleep(2500);
	oxygen_write16(chip, OXYGEN_GPIO_DATA,
		       GPIO_OUTPUT_ENABLE | GPIO_INPUT_ROUTE);
}

void dg_cleanup(struct oxygen *chip)
{
	oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA, GPIO_OUTPUT_ENABLE);
}

void dg_suspend(struct oxygen *chip)
{
	dg_cleanup(chip);
}

void dg_resume(struct oxygen *chip)
{
	cs4245_shadow_control(chip, CS4245_LOAD_FROM_SHADOW);
	msleep(2500);
	oxygen_set_bits16(chip, OXYGEN_GPIO_DATA, GPIO_OUTPUT_ENABLE);
}

void set_cs4245_dac_params(struct oxygen *chip,
				  struct snd_pcm_hw_params *params)
{
	struct dg *data = chip->model_data;
	unsigned char dac_ctrl;
	unsigned char mclk_freq;

	dac_ctrl = data->cs4245_shadow[CS4245_DAC_CTRL_1] & ~CS4245_DAC_FM_MASK;
	mclk_freq = data->cs4245_shadow[CS4245_MCLK_FREQ] & ~CS4245_MCLK1_MASK;
	if (params_rate(params) <= 50000) {
		dac_ctrl |= CS4245_DAC_FM_SINGLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK1_SHIFT;
	} else if (params_rate(params) <= 100000) {
		dac_ctrl |= CS4245_DAC_FM_DOUBLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK1_SHIFT;
	} else {
		dac_ctrl |= CS4245_DAC_FM_QUAD;
		mclk_freq |= CS4245_MCLK_2 << CS4245_MCLK1_SHIFT;
	}
	data->cs4245_shadow[CS4245_DAC_CTRL_1] = dac_ctrl;
	data->cs4245_shadow[CS4245_MCLK_FREQ] = mclk_freq;
	cs4245_write_spi(chip, CS4245_DAC_CTRL_1);
	cs4245_write_spi(chip, CS4245_MCLK_FREQ);
}

void set_cs4245_adc_params(struct oxygen *chip,
				  struct snd_pcm_hw_params *params)
{
	struct dg *data = chip->model_data;
	unsigned char adc_ctrl;
	unsigned char mclk_freq;

	adc_ctrl = data->cs4245_shadow[CS4245_ADC_CTRL] & ~CS4245_ADC_FM_MASK;
	mclk_freq = data->cs4245_shadow[CS4245_MCLK_FREQ] & ~CS4245_MCLK2_MASK;
	if (params_rate(params) <= 50000) {
		adc_ctrl |= CS4245_ADC_FM_SINGLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK2_SHIFT;
	} else if (params_rate(params) <= 100000) {
		adc_ctrl |= CS4245_ADC_FM_DOUBLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK2_SHIFT;
	} else {
		adc_ctrl |= CS4245_ADC_FM_QUAD;
		mclk_freq |= CS4245_MCLK_2 << CS4245_MCLK2_SHIFT;
	}
	data->cs4245_shadow[CS4245_ADC_CTRL] = adc_ctrl;
	data->cs4245_shadow[CS4245_MCLK_FREQ] = mclk_freq;
	cs4245_write_spi(chip, CS4245_ADC_CTRL);
	cs4245_write_spi(chip, CS4245_MCLK_FREQ);
}

__attribute__((used)) static inline unsigned int shift_bits(unsigned int value,
				      unsigned int shift_from,
				      unsigned int shift_to,
				      unsigned int mask)
{
	if (shift_from < shift_to)
		return (value << (shift_to - shift_from)) & mask;
	else
		return (value >> (shift_from - shift_to)) & mask;
}

unsigned int adjust_dg_dac_routing(struct oxygen *chip,
					  unsigned int play_routing)
{
	struct dg *data = chip->model_data;

	switch (data->output_sel) {
	case PLAYBACK_DST_HP:
	case PLAYBACK_DST_HP_FP:
		oxygen_write8_masked(chip, OXYGEN_PLAY_ROUTING,
			OXYGEN_PLAY_MUTE23 | OXYGEN_PLAY_MUTE45 |
			OXYGEN_PLAY_MUTE67, OXYGEN_PLAY_MUTE_MASK);
		break;
	case PLAYBACK_DST_MULTICH:
		oxygen_write8_masked(chip, OXYGEN_PLAY_ROUTING,
			OXYGEN_PLAY_MUTE01, OXYGEN_PLAY_MUTE_MASK);
		break;
	}
	return (play_routing & OXYGEN_PLAY_DAC0_SOURCE_MASK) |
	       shift_bits(play_routing,
			  OXYGEN_PLAY_DAC2_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC1_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC1_SOURCE_MASK) |
	       shift_bits(play_routing,
			  OXYGEN_PLAY_DAC1_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC2_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC2_SOURCE_MASK) |
	       shift_bits(play_routing,
			  OXYGEN_PLAY_DAC0_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC3_SOURCE_SHIFT,
			  OXYGEN_PLAY_DAC3_SOURCE_MASK);
}

void dump_cs4245_registers(struct oxygen *chip,
				  struct snd_info_buffer *buffer)
{
	struct dg *data = chip->model_data;
	unsigned int addr;

	snd_iprintf(buffer, "\nCS4245:");
	cs4245_read_spi(chip, CS4245_INT_STATUS);
	for (addr = 1; addr < ARRAY_SIZE(data->cs4245_shadow); addr++)
		snd_iprintf(buffer, " %02x", data->cs4245_shadow[addr]);
	snd_iprintf(buffer, "\n");
}

