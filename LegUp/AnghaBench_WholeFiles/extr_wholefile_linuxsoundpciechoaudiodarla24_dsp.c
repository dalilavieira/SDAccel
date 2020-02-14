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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct echoaudio {int device_id; int subdevice_id; int bad_board; int asic_loaded; int input_clock_types; int sample_rate; scalar_t__ input_clock; TYPE_2__* comm_page; TYPE_1__* card; int /*<<< orphan*/  dsp_code_to_load; } ;
struct TYPE_4__ {int /*<<< orphan*/  gd_clock_state; int /*<<< orphan*/  sample_rate; int /*<<< orphan*/  status_clocks; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int DARLA24 ; 
 int /*<<< orphan*/  DSP_VC_SET_GD_AUDIO_STATE ; 
 int ECHO_CLOCK_BIT_ESYNC ; 
 int ECHO_CLOCK_BIT_INTERNAL ; 
 scalar_t__ ECHO_CLOCK_ESYNC ; 
 int ECHO_CLOCK_INTERNAL ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  FW_DARLA24_DSP ; 
 int /*<<< orphan*/  GD24_11025 ; 
 int /*<<< orphan*/  GD24_16000 ; 
 int /*<<< orphan*/  GD24_22050 ; 
 int /*<<< orphan*/  GD24_32000 ; 
 int /*<<< orphan*/  GD24_44100 ; 
 int /*<<< orphan*/  GD24_48000 ; 
 int /*<<< orphan*/  GD24_8000 ; 
 int /*<<< orphan*/  GD24_88200 ; 
 int /*<<< orphan*/  GD24_96000 ; 
 int /*<<< orphan*/  GD24_EXT_SYNC ; 
 int GLDM_CLOCK_DETECT_BIT_ESYNC ; 
 int /*<<< orphan*/  clear_handshake (struct echoaudio*) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int init_dsp_comm_page (struct echoaudio*) ; 
 int init_line_levels (struct echoaudio*) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int load_firmware (struct echoaudio*) ; 
 int send_vector (struct echoaudio*,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 scalar_t__ wait_handshake (struct echoaudio*) ; 

__attribute__((used)) static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
	int err;

	if (snd_BUG_ON((subdevice_id & 0xfff0) != DARLA24))
		return -ENODEV;

	if ((err = init_dsp_comm_page(chip))) {
		dev_err(chip->card->dev,
			"init_hw: could not initialize DSP comm page\n");
		return err;
	}

	chip->device_id = device_id;
	chip->subdevice_id = subdevice_id;
	chip->bad_board = true;
	chip->dsp_code_to_load = FW_DARLA24_DSP;
	/* Since this card has no ASIC, mark it as loaded so everything
	   works OK */
	chip->asic_loaded = true;
	chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL |
		ECHO_CLOCK_BIT_ESYNC;

	if ((err = load_firmware(chip)) < 0)
		return err;
	chip->bad_board = false;

	return err;
}

__attribute__((used)) static int set_mixer_defaults(struct echoaudio *chip)
{
	return init_line_levels(chip);
}

__attribute__((used)) static u32 detect_input_clocks(const struct echoaudio *chip)
{
	u32 clocks_from_dsp, clock_bits;

	/* Map the DSP clock detect bits to the generic driver clock
	   detect bits */
	clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);

	clock_bits = ECHO_CLOCK_BIT_INTERNAL;

	if (clocks_from_dsp & GLDM_CLOCK_DETECT_BIT_ESYNC)
		clock_bits |= ECHO_CLOCK_BIT_ESYNC;

	return clock_bits;
}

__attribute__((used)) static int load_asic(struct echoaudio *chip)
{
	return 0;
}

__attribute__((used)) static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
	u8 clock;

	switch (rate) {
	case 96000:
		clock = GD24_96000;
		break;
	case 88200:
		clock = GD24_88200;
		break;
	case 48000:
		clock = GD24_48000;
		break;
	case 44100:
		clock = GD24_44100;
		break;
	case 32000:
		clock = GD24_32000;
		break;
	case 22050:
		clock = GD24_22050;
		break;
	case 16000:
		clock = GD24_16000;
		break;
	case 11025:
		clock = GD24_11025;
		break;
	case 8000:
		clock = GD24_8000;
		break;
	default:
		dev_err(chip->card->dev,
			"set_sample_rate: Error, invalid sample rate %d\n",
			rate);
		return -EINVAL;
	}

	if (wait_handshake(chip))
		return -EIO;

	dev_dbg(chip->card->dev,
		"set_sample_rate: %d clock %d\n", rate, clock);
	chip->sample_rate = rate;

	/* Override the sample rate if this card is set to Echo sync. */
	if (chip->input_clock == ECHO_CLOCK_ESYNC)
		clock = GD24_EXT_SYNC;

	chip->comm_page->sample_rate = cpu_to_le32(rate);	/* ignored by the DSP ? */
	chip->comm_page->gd_clock_state = clock;
	clear_handshake(chip);
	return send_vector(chip, DSP_VC_SET_GD_AUDIO_STATE);
}

__attribute__((used)) static int set_input_clock(struct echoaudio *chip, u16 clock)
{
	if (snd_BUG_ON(clock != ECHO_CLOCK_INTERNAL &&
		       clock != ECHO_CLOCK_ESYNC))
		return -EINVAL;
	chip->input_clock = clock;
	return set_sample_rate(chip, chip->sample_rate);
}

