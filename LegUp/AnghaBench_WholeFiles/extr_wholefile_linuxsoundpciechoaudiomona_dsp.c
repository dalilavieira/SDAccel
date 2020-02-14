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
typedef  int u32 ;
typedef  int u16 ;
struct echoaudio {int device_id; int subdevice_id; int bad_board; int input_clock_types; int digital_modes; int digital_mode; int professional_spdif; int digital_in_automute; short asic_code; scalar_t__ input_clock; int sample_rate; TYPE_1__* card; int /*<<< orphan*/  lock; TYPE_2__* comm_page; int /*<<< orphan*/  opencount; scalar_t__ asic_loaded; int /*<<< orphan*/  dsp_code_to_load; } ;
struct TYPE_4__ {int /*<<< orphan*/  control_register; int /*<<< orphan*/  status_clocks; void* sample_rate; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ DEVICE_ID_56361 ; 
#define  DIGITAL_MODE_ADAT 134 
#define  DIGITAL_MODE_SPDIF_OPTICAL 133 
#define  DIGITAL_MODE_SPDIF_RCA 132 
 int /*<<< orphan*/  DSP_FNC_LOAD_MONA_EXTERNAL_ASIC ; 
 int /*<<< orphan*/  DSP_FNC_LOAD_MONA_PCI_CARD_ASIC ; 
 int EAGAIN ; 
 int ECHOCAPS_HAS_DIGITAL_MODE_ADAT ; 
 int ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_OPTICAL ; 
 int ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_RCA ; 
#define  ECHO_CLOCK_ADAT 131 
 int ECHO_CLOCK_BIT_ADAT ; 
 int ECHO_CLOCK_BIT_INTERNAL ; 
 int ECHO_CLOCK_BIT_SPDIF ; 
 int ECHO_CLOCK_BIT_WORD ; 
#define  ECHO_CLOCK_INTERNAL 130 
#define  ECHO_CLOCK_SPDIF 129 
#define  ECHO_CLOCK_WORD 128 
 int EINVAL ; 
 int ENODEV ; 
 short FW_MONA_2_ASIC ; 
 short FW_MONA_301_1_ASIC48 ; 
 short FW_MONA_301_1_ASIC96 ; 
 int /*<<< orphan*/  FW_MONA_301_DSP ; 
 short FW_MONA_361_1_ASIC48 ; 
 short FW_MONA_361_1_ASIC96 ; 
 int /*<<< orphan*/  FW_MONA_361_DSP ; 
 int GML_11KHZ ; 
 int GML_16KHZ ; 
 int GML_22KHZ ; 
 int GML_32KHZ ; 
 int GML_44KHZ ; 
 int GML_48KHZ ; 
 int GML_88KHZ ; 
 int GML_8KHZ ; 
 int GML_96KHZ ; 
 int GML_ADAT_CLOCK ; 
 int GML_ADAT_MODE ; 
 int GML_CLOCK_CLEAR_MASK ; 
 int GML_CLOCK_DETECT_BIT_ADAT ; 
 int GML_CLOCK_DETECT_BIT_SPDIF ; 
 int GML_CLOCK_DETECT_BIT_SPDIF96 ; 
 int GML_CLOCK_DETECT_BIT_WORD ; 
 int GML_CLOCK_DETECT_BIT_WORD96 ; 
 int GML_CONVERTER_ENABLE ; 
 int GML_DIGITAL_MODE_CLEAR_MASK ; 
 int GML_DOUBLE_SPEED_MODE ; 
 int GML_SPDIF_CLOCK ; 
 int GML_SPDIF_OPTICAL_MODE ; 
 int GML_SPDIF_PRO_MODE ; 
 int GML_SPDIF_RATE_CLEAR_MASK ; 
 int GML_SPDIF_SAMPLE_RATE0 ; 
 int GML_SPDIF_SAMPLE_RATE1 ; 
 int GML_WORD_CLOCK ; 
 int MONA ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int check_asic_status (struct echoaudio*) ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int init_dsp_comm_page (struct echoaudio*) ; 
 int init_line_levels (struct echoaudio*) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int load_asic_generic (struct echoaudio*,int /*<<< orphan*/ ,short) ; 
 int load_firmware (struct echoaudio*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int write_control_reg (struct echoaudio*,int,int) ; 

__attribute__((used)) static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
	int err;

	if (snd_BUG_ON((subdevice_id & 0xfff0) != MONA))
		return -ENODEV;

	if ((err = init_dsp_comm_page(chip))) {
		dev_err(chip->card->dev,
			"init_hw - could not initialize DSP comm page\n");
		return err;
	}

	chip->device_id = device_id;
	chip->subdevice_id = subdevice_id;
	chip->bad_board = true;
	chip->input_clock_types =
		ECHO_CLOCK_BIT_INTERNAL | ECHO_CLOCK_BIT_SPDIF |
		ECHO_CLOCK_BIT_WORD | ECHO_CLOCK_BIT_ADAT;
	chip->digital_modes =
		ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_RCA |
		ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_OPTICAL |
		ECHOCAPS_HAS_DIGITAL_MODE_ADAT;

	/* Mona comes in both '301 and '361 flavors */
	if (chip->device_id == DEVICE_ID_56361)
		chip->dsp_code_to_load = FW_MONA_361_DSP;
	else
		chip->dsp_code_to_load = FW_MONA_301_DSP;

	if ((err = load_firmware(chip)) < 0)
		return err;
	chip->bad_board = false;

	return err;
}

__attribute__((used)) static int set_mixer_defaults(struct echoaudio *chip)
{
	chip->digital_mode = DIGITAL_MODE_SPDIF_RCA;
	chip->professional_spdif = false;
	chip->digital_in_automute = true;
	return init_line_levels(chip);
}

__attribute__((used)) static u32 detect_input_clocks(const struct echoaudio *chip)
{
	u32 clocks_from_dsp, clock_bits;

	/* Map the DSP clock detect bits to the generic driver clock
	   detect bits */
	clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);

	clock_bits = ECHO_CLOCK_BIT_INTERNAL;

	if (clocks_from_dsp & GML_CLOCK_DETECT_BIT_SPDIF)
		clock_bits |= ECHO_CLOCK_BIT_SPDIF;

	if (clocks_from_dsp & GML_CLOCK_DETECT_BIT_ADAT)
		clock_bits |= ECHO_CLOCK_BIT_ADAT;

	if (clocks_from_dsp & GML_CLOCK_DETECT_BIT_WORD)
		clock_bits |= ECHO_CLOCK_BIT_WORD;

	return clock_bits;
}

__attribute__((used)) static int load_asic(struct echoaudio *chip)
{
	u32 control_reg;
	int err;
	short asic;

	if (chip->asic_loaded)
		return 0;

	mdelay(10);

	if (chip->device_id == DEVICE_ID_56361)
		asic = FW_MONA_361_1_ASIC48;
	else
		asic = FW_MONA_301_1_ASIC48;

	err = load_asic_generic(chip, DSP_FNC_LOAD_MONA_PCI_CARD_ASIC, asic);
	if (err < 0)
		return err;

	chip->asic_code = asic;
	mdelay(10);

	/* Do the external one */
	err = load_asic_generic(chip, DSP_FNC_LOAD_MONA_EXTERNAL_ASIC,
				FW_MONA_2_ASIC);
	if (err < 0)
		return err;

	mdelay(10);
	err = check_asic_status(chip);

	/* Set up the control register if the load succeeded -
	   48 kHz, internal clock, S/PDIF RCA mode */
	if (!err) {
		control_reg = GML_CONVERTER_ENABLE | GML_48KHZ;
		err = write_control_reg(chip, control_reg, true);
	}

	return err;
}

__attribute__((used)) static int switch_asic(struct echoaudio *chip, char double_speed)
{
	int err;
	short asic;

	/* Check the clock detect bits to see if this is
	a single-speed clock or a double-speed clock; load
	a new ASIC if necessary. */
	if (chip->device_id == DEVICE_ID_56361) {
		if (double_speed)
			asic = FW_MONA_361_1_ASIC96;
		else
			asic = FW_MONA_361_1_ASIC48;
	} else {
		if (double_speed)
			asic = FW_MONA_301_1_ASIC96;
		else
			asic = FW_MONA_301_1_ASIC48;
	}

	if (asic != chip->asic_code) {
		/* Load the desired ASIC */
		err = load_asic_generic(chip, DSP_FNC_LOAD_MONA_PCI_CARD_ASIC,
					asic);
		if (err < 0)
			return err;
		chip->asic_code = asic;
	}

	return 0;
}

__attribute__((used)) static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
	u32 control_reg, clock;
	short asic;
	char force_write;

	/* Only set the clock for internal mode. */
	if (chip->input_clock != ECHO_CLOCK_INTERNAL) {
		dev_dbg(chip->card->dev,
			"Cannot set sample rate - clock not set to CLK_CLOCKININTERNAL\n");
		/* Save the rate anyhow */
		chip->comm_page->sample_rate = cpu_to_le32(rate);
		chip->sample_rate = rate;
		return 0;
	}

	/* Now, check to see if the required ASIC is loaded */
	if (rate >= 88200) {
		if (chip->digital_mode == DIGITAL_MODE_ADAT)
			return -EINVAL;
		if (chip->device_id == DEVICE_ID_56361)
			asic = FW_MONA_361_1_ASIC96;
		else
			asic = FW_MONA_301_1_ASIC96;
	} else {
		if (chip->device_id == DEVICE_ID_56361)
			asic = FW_MONA_361_1_ASIC48;
		else
			asic = FW_MONA_301_1_ASIC48;
	}

	force_write = 0;
	if (asic != chip->asic_code) {
		int err;
		/* Load the desired ASIC (load_asic_generic() can sleep) */
		spin_unlock_irq(&chip->lock);
		err = load_asic_generic(chip, DSP_FNC_LOAD_MONA_PCI_CARD_ASIC,
					asic);
		spin_lock_irq(&chip->lock);

		if (err < 0)
			return err;
		chip->asic_code = asic;
		force_write = 1;
	}

	/* Compute the new control register value */
	clock = 0;
	control_reg = le32_to_cpu(chip->comm_page->control_register);
	control_reg &= GML_CLOCK_CLEAR_MASK;
	control_reg &= GML_SPDIF_RATE_CLEAR_MASK;

	switch (rate) {
	case 96000:
		clock = GML_96KHZ;
		break;
	case 88200:
		clock = GML_88KHZ;
		break;
	case 48000:
		clock = GML_48KHZ | GML_SPDIF_SAMPLE_RATE1;
		break;
	case 44100:
		clock = GML_44KHZ;
		/* Professional mode */
		if (control_reg & GML_SPDIF_PRO_MODE)
			clock |= GML_SPDIF_SAMPLE_RATE0;
		break;
	case 32000:
		clock = GML_32KHZ | GML_SPDIF_SAMPLE_RATE0 |
			GML_SPDIF_SAMPLE_RATE1;
		break;
	case 22050:
		clock = GML_22KHZ;
		break;
	case 16000:
		clock = GML_16KHZ;
		break;
	case 11025:
		clock = GML_11KHZ;
		break;
	case 8000:
		clock = GML_8KHZ;
		break;
	default:
		dev_err(chip->card->dev,
			"set_sample_rate: %d invalid!\n", rate);
		return -EINVAL;
	}

	control_reg |= clock;

	chip->comm_page->sample_rate = cpu_to_le32(rate);	/* ignored by the DSP */
	chip->sample_rate = rate;
	dev_dbg(chip->card->dev,
		"set_sample_rate: %d clock %d\n", rate, clock);

	return write_control_reg(chip, control_reg, force_write);
}

__attribute__((used)) static int set_input_clock(struct echoaudio *chip, u16 clock)
{
	u32 control_reg, clocks_from_dsp;
	int err;


	/* Prevent two simultaneous calls to switch_asic() */
	if (atomic_read(&chip->opencount))
		return -EAGAIN;

	/* Mask off the clock select bits */
	control_reg = le32_to_cpu(chip->comm_page->control_register) &
		GML_CLOCK_CLEAR_MASK;
	clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);

	switch (clock) {
	case ECHO_CLOCK_INTERNAL:
		chip->input_clock = ECHO_CLOCK_INTERNAL;
		return set_sample_rate(chip, chip->sample_rate);
	case ECHO_CLOCK_SPDIF:
		if (chip->digital_mode == DIGITAL_MODE_ADAT)
			return -EAGAIN;
		spin_unlock_irq(&chip->lock);
		err = switch_asic(chip, clocks_from_dsp &
				  GML_CLOCK_DETECT_BIT_SPDIF96);
		spin_lock_irq(&chip->lock);
		if (err < 0)
			return err;
		control_reg |= GML_SPDIF_CLOCK;
		if (clocks_from_dsp & GML_CLOCK_DETECT_BIT_SPDIF96)
			control_reg |= GML_DOUBLE_SPEED_MODE;
		else
			control_reg &= ~GML_DOUBLE_SPEED_MODE;
		break;
	case ECHO_CLOCK_WORD:
		spin_unlock_irq(&chip->lock);
		err = switch_asic(chip, clocks_from_dsp &
				  GML_CLOCK_DETECT_BIT_WORD96);
		spin_lock_irq(&chip->lock);
		if (err < 0)
			return err;
		control_reg |= GML_WORD_CLOCK;
		if (clocks_from_dsp & GML_CLOCK_DETECT_BIT_WORD96)
			control_reg |= GML_DOUBLE_SPEED_MODE;
		else
			control_reg &= ~GML_DOUBLE_SPEED_MODE;
		break;
	case ECHO_CLOCK_ADAT:
		dev_dbg(chip->card->dev, "Set Mona clock to ADAT\n");
		if (chip->digital_mode != DIGITAL_MODE_ADAT)
			return -EAGAIN;
		control_reg |= GML_ADAT_CLOCK;
		control_reg &= ~GML_DOUBLE_SPEED_MODE;
		break;
	default:
		dev_err(chip->card->dev,
			"Input clock 0x%x not supported for Mona\n", clock);
		return -EINVAL;
	}

	chip->input_clock = clock;
	return write_control_reg(chip, control_reg, true);
}

__attribute__((used)) static int dsp_set_digital_mode(struct echoaudio *chip, u8 mode)
{
	u32 control_reg;
	int err, incompatible_clock;

	/* Set clock to "internal" if it's not compatible with the new mode */
	incompatible_clock = false;
	switch (mode) {
	case DIGITAL_MODE_SPDIF_OPTICAL:
	case DIGITAL_MODE_SPDIF_RCA:
		if (chip->input_clock == ECHO_CLOCK_ADAT)
			incompatible_clock = true;
		break;
	case DIGITAL_MODE_ADAT:
		if (chip->input_clock == ECHO_CLOCK_SPDIF)
			incompatible_clock = true;
		break;
	default:
		dev_err(chip->card->dev,
			"Digital mode not supported: %d\n", mode);
		return -EINVAL;
	}

	spin_lock_irq(&chip->lock);

	if (incompatible_clock) {	/* Switch to 48KHz, internal */
		chip->sample_rate = 48000;
		set_input_clock(chip, ECHO_CLOCK_INTERNAL);
	}

	/* Clear the current digital mode */
	control_reg = le32_to_cpu(chip->comm_page->control_register);
	control_reg &= GML_DIGITAL_MODE_CLEAR_MASK;

	/* Tweak the control reg */
	switch (mode) {
	case DIGITAL_MODE_SPDIF_OPTICAL:
		control_reg |= GML_SPDIF_OPTICAL_MODE;
		break;
	case DIGITAL_MODE_SPDIF_RCA:
		/* GML_SPDIF_OPTICAL_MODE bit cleared */
		break;
	case DIGITAL_MODE_ADAT:
		/* If the current ASIC is the 96KHz ASIC, switch the ASIC
		   and set to 48 KHz */
		if (chip->asic_code == FW_MONA_361_1_ASIC96 ||
		    chip->asic_code == FW_MONA_301_1_ASIC96) {
			set_sample_rate(chip, 48000);
		}
		control_reg |= GML_ADAT_MODE;
		control_reg &= ~GML_DOUBLE_SPEED_MODE;
		break;
	}

	err = write_control_reg(chip, control_reg, false);
	spin_unlock_irq(&chip->lock);
	if (err < 0)
		return err;
	chip->digital_mode = mode;

	dev_dbg(chip->card->dev, "set_digital_mode to %d\n", mode);
	return incompatible_clock;
}

