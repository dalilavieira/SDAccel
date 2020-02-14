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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct echoaudio {int device_id; int subdevice_id; int bad_board; scalar_t__ spdif_status; scalar_t__ clock_state; int asic_loaded; int input_clock_types; int sample_rate; TYPE_2__* comm_page; int /*<<< orphan*/  dsp_code_to_load; TYPE_1__* card; } ;
struct TYPE_4__ {int gd_resampler_state; scalar_t__ gd_spdif_status; scalar_t__ gd_clock_state; int /*<<< orphan*/  sample_rate; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int DARLA20 ; 
 int /*<<< orphan*/  DSP_VC_SET_GD_AUDIO_STATE ; 
 int ECHO_CLOCK_BIT_INTERNAL ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  FW_DARLA20_DSP ; 
 scalar_t__ GD_CLOCK_44 ; 
 scalar_t__ GD_CLOCK_48 ; 
 scalar_t__ GD_CLOCK_NOCHANGE ; 
 scalar_t__ GD_CLOCK_UNDEF ; 
 scalar_t__ GD_SPDIF_STATUS_44 ; 
 scalar_t__ GD_SPDIF_STATUS_48 ; 
 scalar_t__ GD_SPDIF_STATUS_NOCHANGE ; 
 scalar_t__ GD_SPDIF_STATUS_UNDEF ; 
 int /*<<< orphan*/  clear_handshake (struct echoaudio*) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int init_dsp_comm_page (struct echoaudio*) ; 
 int init_line_levels (struct echoaudio*) ; 
 int load_firmware (struct echoaudio*) ; 
 int send_vector (struct echoaudio*,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 scalar_t__ wait_handshake (struct echoaudio*) ; 

__attribute__((used)) static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
	int err;

	if (snd_BUG_ON((subdevice_id & 0xfff0) != DARLA20))
		return -ENODEV;

	if ((err = init_dsp_comm_page(chip))) {
		dev_err(chip->card->dev,
			"init_hw: could not initialize DSP comm page\n");
		return err;
	}

	chip->device_id = device_id;
	chip->subdevice_id = subdevice_id;
	chip->bad_board = true;
	chip->dsp_code_to_load = FW_DARLA20_DSP;
	chip->spdif_status = GD_SPDIF_STATUS_UNDEF;
	chip->clock_state = GD_CLOCK_UNDEF;
	/* Since this card has no ASIC, mark it as loaded so everything
	   works OK */
	chip->asic_loaded = true;
	chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL;

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
	return ECHO_CLOCK_BIT_INTERNAL;
}

__attribute__((used)) static int load_asic(struct echoaudio *chip)
{
	return 0;
}

__attribute__((used)) static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
	u8 clock_state, spdif_status;

	if (wait_handshake(chip))
		return -EIO;

	switch (rate) {
	case 44100:
		clock_state = GD_CLOCK_44;
		spdif_status = GD_SPDIF_STATUS_44;
		break;
	case 48000:
		clock_state = GD_CLOCK_48;
		spdif_status = GD_SPDIF_STATUS_48;
		break;
	default:
		clock_state = GD_CLOCK_NOCHANGE;
		spdif_status = GD_SPDIF_STATUS_NOCHANGE;
		break;
	}

	if (chip->clock_state == clock_state)
		clock_state = GD_CLOCK_NOCHANGE;
	if (spdif_status == chip->spdif_status)
		spdif_status = GD_SPDIF_STATUS_NOCHANGE;

	chip->comm_page->sample_rate = cpu_to_le32(rate);
	chip->comm_page->gd_clock_state = clock_state;
	chip->comm_page->gd_spdif_status = spdif_status;
	chip->comm_page->gd_resampler_state = 3;	/* magic number - should always be 3 */

	/* Save the new audio state if it changed */
	if (clock_state != GD_CLOCK_NOCHANGE)
		chip->clock_state = clock_state;
	if (spdif_status != GD_SPDIF_STATUS_NOCHANGE)
		chip->spdif_status = spdif_status;
	chip->sample_rate = rate;

	clear_handshake(chip);
	return send_vector(chip, DSP_VC_SET_GD_AUDIO_STATE);
}

