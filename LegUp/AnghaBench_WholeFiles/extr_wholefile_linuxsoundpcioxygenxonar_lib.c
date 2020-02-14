#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  unsigned int u16 ;
struct xonar_generic {unsigned int output_enable_bit; int ext_power_bit; int has_power; unsigned int ext_power_int_reg; int /*<<< orphan*/  ext_power_reg; int /*<<< orphan*/  anti_pop_delay; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {unsigned int private_value; struct oxygen* private_data; } ;
struct TYPE_7__ {int* value; } ;
struct TYPE_8__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_6__ {void (* gpio_changed ) (struct oxygen*) ;} ;
struct oxygen {int /*<<< orphan*/  reg_lock; TYPE_2__ model; int /*<<< orphan*/  interrupt_mask; struct xonar_generic* model_data; TYPE_1__* card; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned int GPIO_CS53x1_M_DOUBLE ; 
 unsigned int GPIO_CS53x1_M_MASK ; 
 unsigned int GPIO_CS53x1_M_QUAD ; 
 unsigned int GPIO_CS53x1_M_SINGLE ; 
 unsigned int OXYGEN_GPIO_CONTROL ; 
 unsigned int OXYGEN_GPIO_DATA ; 
 int /*<<< orphan*/  OXYGEN_INT_GPIO ; 
 int XONAR_GPIO_BIT_INVERT ; 
 int /*<<< orphan*/  dev_crit (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 unsigned int oxygen_read16 (struct oxygen*,unsigned int) ; 
 int oxygen_read8 (struct oxygen*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write16 (struct oxygen*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  oxygen_write16_masked (struct oxygen*,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  oxygen_write32_masked (struct oxygen*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oxygen_write8_masked (struct oxygen*,unsigned int,int,int) ; 
 int /*<<< orphan*/  oxygen_write_ac97_masked (struct oxygen*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

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

void xonar_enable_output(struct oxygen *chip)
{
	struct xonar_generic *data = chip->model_data;

	oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL, data->output_enable_bit);
	msleep(data->anti_pop_delay);
	oxygen_set_bits16(chip, OXYGEN_GPIO_DATA, data->output_enable_bit);
}

void xonar_disable_output(struct oxygen *chip)
{
	struct xonar_generic *data = chip->model_data;

	oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA, data->output_enable_bit);
}

__attribute__((used)) static void xonar_ext_power_gpio_changed(struct oxygen *chip)
{
	struct xonar_generic *data = chip->model_data;
	u8 has_power;

	has_power = !!(oxygen_read8(chip, data->ext_power_reg)
		       & data->ext_power_bit);
	if (has_power != data->has_power) {
		data->has_power = has_power;
		if (has_power) {
			dev_notice(chip->card->dev, "power restored\n");
		} else {
			dev_crit(chip->card->dev,
				   "Hey! Don't unplug the power cable!\n");
			/* TODO: stop PCMs */
		}
	}
}

void xonar_init_ext_power(struct oxygen *chip)
{
	struct xonar_generic *data = chip->model_data;

	oxygen_set_bits8(chip, data->ext_power_int_reg,
			 data->ext_power_bit);
	chip->interrupt_mask |= OXYGEN_INT_GPIO;
	chip->model.gpio_changed = xonar_ext_power_gpio_changed;
	data->has_power = !!(oxygen_read8(chip, data->ext_power_reg)
			     & data->ext_power_bit);
}

void xonar_init_cs53x1(struct oxygen *chip)
{
	oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL, GPIO_CS53x1_M_MASK);
	oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
			      GPIO_CS53x1_M_SINGLE, GPIO_CS53x1_M_MASK);
}

void xonar_set_cs53x1_params(struct oxygen *chip,
			     struct snd_pcm_hw_params *params)
{
	unsigned int value;

	if (params_rate(params) <= 54000)
		value = GPIO_CS53x1_M_SINGLE;
	else if (params_rate(params) <= 108000)
		value = GPIO_CS53x1_M_DOUBLE;
	else
		value = GPIO_CS53x1_M_QUAD;
	oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
			      value, GPIO_CS53x1_M_MASK);
}

int xonar_gpio_bit_switch_get(struct snd_kcontrol *ctl,
			      struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	u16 bit = ctl->private_value;
	bool invert = ctl->private_value & XONAR_GPIO_BIT_INVERT;

	value->value.integer.value[0] =
		!!(oxygen_read16(chip, OXYGEN_GPIO_DATA) & bit) ^ invert;
	return 0;
}

int xonar_gpio_bit_switch_put(struct snd_kcontrol *ctl,
			      struct snd_ctl_elem_value *value)
{
	struct oxygen *chip = ctl->private_data;
	u16 bit = ctl->private_value;
	bool invert = ctl->private_value & XONAR_GPIO_BIT_INVERT;
	u16 old_bits, new_bits;
	int changed;

	spin_lock_irq(&chip->reg_lock);
	old_bits = oxygen_read16(chip, OXYGEN_GPIO_DATA);
	if (!!value->value.integer.value[0] ^ invert)
		new_bits = old_bits | bit;
	else
		new_bits = old_bits & ~bit;
	changed = new_bits != old_bits;
	if (changed)
		oxygen_write16(chip, OXYGEN_GPIO_DATA, new_bits);
	spin_unlock_irq(&chip->reg_lock);
	return changed;
}

