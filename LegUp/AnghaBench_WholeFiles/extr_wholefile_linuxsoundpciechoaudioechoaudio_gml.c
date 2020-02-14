#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u32 ;
struct echoaudio {int asic_loaded; int digital_in_automute; int pipe_alloc_mask; int digital_modes; int digital_mode; int sample_rate; char professional_spdif; TYPE_2__* card; TYPE_1__* comm_page; int /*<<< orphan*/  lock; int /*<<< orphan*/ * output_gain; int /*<<< orphan*/ ** monitor_gain; scalar_t__ bad_board; int /*<<< orphan*/  input_clock; } ;
typedef  scalar_t__ __le32 ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {scalar_t__ control_register; } ;

/* Variables and functions */
 scalar_t__ ASIC_ALREADY_LOADED ; 
 int DIGITAL_MODE_ADAT ; 
 int /*<<< orphan*/  DSP_VC_TEST_ASIC ; 
 int /*<<< orphan*/  DSP_VC_WRITE_CONTROL_REG ; 
 int EAGAIN ; 
 int EINVAL ; 
 int EIO ; 
 scalar_t__ GML_DIGITAL_IN_AUTO_MUTE ; 
 scalar_t__ GML_SPDIF_24_BIT ; 
 scalar_t__ GML_SPDIF_COPY_PERMIT ; 
 scalar_t__ GML_SPDIF_FORMAT_CLEAR_MASK ; 
 scalar_t__ GML_SPDIF_PRO_MODE ; 
 scalar_t__ GML_SPDIF_SAMPLE_RATE0 ; 
 scalar_t__ GML_SPDIF_SAMPLE_RATE1 ; 
 scalar_t__ GML_SPDIF_TWO_CHANNEL ; 
 int /*<<< orphan*/  clear_handshake (struct echoaudio*) ; 
 scalar_t__ cpu_to_le32 (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int dsp_set_digital_mode (struct echoaudio*,int) ; 
 scalar_t__ le32_to_cpu (scalar_t__) ; 
 int num_busses_in (struct echoaudio*) ; 
 int num_busses_out (struct echoaudio*) ; 
 scalar_t__ read_dsp (struct echoaudio*,scalar_t__*) ; 
 int send_vector (struct echoaudio*,int /*<<< orphan*/ ) ; 
 int set_input_clock (struct echoaudio*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_monitor_gain (struct echoaudio*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_output_gain (struct echoaudio*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  update_output_line_level (struct echoaudio*) ; 
 scalar_t__ wait_handshake (struct echoaudio*) ; 

__attribute__((used)) static int check_asic_status(struct echoaudio *chip)
{
	u32 asic_status;

	send_vector(chip, DSP_VC_TEST_ASIC);

	/* The DSP will return a value to indicate whether or not the
	   ASIC is currently loaded */
	if (read_dsp(chip, &asic_status) < 0) {
		dev_err(chip->card->dev,
			"check_asic_status: failed on read_dsp\n");
		chip->asic_loaded = false;
		return -EIO;
	}

	chip->asic_loaded = (asic_status == ASIC_ALREADY_LOADED);
	return chip->asic_loaded ? 0 : -EIO;
}

__attribute__((used)) static int write_control_reg(struct echoaudio *chip, u32 value, char force)
{
	__le32 reg_value;

	/* Handle the digital input auto-mute */
	if (chip->digital_in_automute)
		value |= GML_DIGITAL_IN_AUTO_MUTE;
	else
		value &= ~GML_DIGITAL_IN_AUTO_MUTE;

	dev_dbg(chip->card->dev, "write_control_reg: 0x%x\n", value);

	/* Write the control register */
	reg_value = cpu_to_le32(value);
	if (reg_value != chip->comm_page->control_register || force) {
		if (wait_handshake(chip))
			return -EIO;
		chip->comm_page->control_register = reg_value;
		clear_handshake(chip);
		return send_vector(chip, DSP_VC_WRITE_CONTROL_REG);
	}
	return 0;
}

__attribute__((used)) static int set_input_auto_mute(struct echoaudio *chip, int automute)
{
	dev_dbg(chip->card->dev, "set_input_auto_mute %d\n", automute);

	chip->digital_in_automute = automute;

	/* Re-set the input clock to the current value - indirectly causes
	the auto-mute flag to be sent to the DSP */
	return set_input_clock(chip, chip->input_clock);
}

__attribute__((used)) static int set_digital_mode(struct echoaudio *chip, u8 mode)
{
	u8 previous_mode;
	int err, i, o;

	if (chip->bad_board)
		return -EIO;

	/* All audio channels must be closed before changing the digital mode */
	if (snd_BUG_ON(chip->pipe_alloc_mask))
		return -EAGAIN;

	if (snd_BUG_ON(!(chip->digital_modes & (1 << mode))))
		return -EINVAL;

	previous_mode = chip->digital_mode;
	err = dsp_set_digital_mode(chip, mode);

	/* If we successfully changed the digital mode from or to ADAT,
	   then make sure all output, input and monitor levels are
	   updated by the DSP comm object. */
	if (err >= 0 && previous_mode != mode &&
	    (previous_mode == DIGITAL_MODE_ADAT || mode == DIGITAL_MODE_ADAT)) {
		spin_lock_irq(&chip->lock);
		for (o = 0; o < num_busses_out(chip); o++)
			for (i = 0; i < num_busses_in(chip); i++)
				set_monitor_gain(chip, o, i,
						 chip->monitor_gain[o][i]);

#ifdef ECHOCARD_HAS_INPUT_GAIN
		for (i = 0; i < num_busses_in(chip); i++)
			set_input_gain(chip, i, chip->input_gain[i]);
		update_input_line_level(chip);
#endif

		for (o = 0; o < num_busses_out(chip); o++)
			set_output_gain(chip, o, chip->output_gain[o]);
		update_output_line_level(chip);
		spin_unlock_irq(&chip->lock);
	}

	return err;
}

__attribute__((used)) static int set_professional_spdif(struct echoaudio *chip, char prof)
{
	u32 control_reg;
	int err;

	/* Clear the current S/PDIF flags */
	control_reg = le32_to_cpu(chip->comm_page->control_register);
	control_reg &= GML_SPDIF_FORMAT_CLEAR_MASK;

	/* Set the new S/PDIF flags depending on the mode */
	control_reg |= GML_SPDIF_TWO_CHANNEL | GML_SPDIF_24_BIT |
		GML_SPDIF_COPY_PERMIT;
	if (prof) {
		/* Professional mode */
		control_reg |= GML_SPDIF_PRO_MODE;

		switch (chip->sample_rate) {
		case 32000:
			control_reg |= GML_SPDIF_SAMPLE_RATE0 |
				GML_SPDIF_SAMPLE_RATE1;
			break;
		case 44100:
			control_reg |= GML_SPDIF_SAMPLE_RATE0;
			break;
		case 48000:
			control_reg |= GML_SPDIF_SAMPLE_RATE1;
			break;
		}
	} else {
		/* Consumer mode */
		switch (chip->sample_rate) {
		case 32000:
			control_reg |= GML_SPDIF_SAMPLE_RATE0 |
				GML_SPDIF_SAMPLE_RATE1;
			break;
		case 48000:
			control_reg |= GML_SPDIF_SAMPLE_RATE1;
			break;
		}
	}

	if ((err = write_control_reg(chip, control_reg, false)))
		return err;
	chip->professional_spdif = prof;
	dev_dbg(chip->card->dev, "set_professional_spdif to %s\n",
		prof ? "Professional" : "Consumer");
	return 0;
}

