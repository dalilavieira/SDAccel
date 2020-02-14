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
struct timer_list {int dummy; } ;
struct snd_sb {int open; scalar_t__ hardware; struct snd_rawmidi* rmidi; int /*<<< orphan*/  midi_timer; int /*<<< orphan*/  card; int /*<<< orphan*/  open_lock; struct snd_rawmidi_substream* midi_substream_output; struct snd_rawmidi_substream* midi_substream_input; int /*<<< orphan*/  midi_input_lock; } ;
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct snd_rawmidi {int info_flags; struct snd_sb* private_data; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {struct snd_sb* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  DATA_AVAIL ; 
 int EAGAIN ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  READ ; 
 int /*<<< orphan*/  SBP (struct snd_sb*,int /*<<< orphan*/ ) ; 
 char SB_DSP_MIDI_INPUT_IRQ ; 
 char SB_DSP_MIDI_OUTPUT ; 
 char SB_DSP_MIDI_UART_IRQ ; 
 scalar_t__ SB_HW_20 ; 
 int SB_OPEN_MIDI_INPUT ; 
 int SB_OPEN_MIDI_INPUT_TRIGGER ; 
 int SB_OPEN_MIDI_OUTPUT ; 
 int SB_OPEN_MIDI_OUTPUT_TRIGGER ; 
 int SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int SNDRV_RAWMIDI_INFO_INPUT ; 
 int SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 int /*<<< orphan*/  STATUS ; 
 int /*<<< orphan*/  WRITE ; 
 struct snd_sb* chip ; 
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 struct snd_sb* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int inb (int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  midi_timer ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  outb (char,int /*<<< orphan*/ ) ; 
 int snd_rawmidi_new (int /*<<< orphan*/ ,char*,int,int,int,struct snd_rawmidi**) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (struct snd_rawmidi_substream*,char*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_set_ops (struct snd_rawmidi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_rawmidi_transmit_ack (struct snd_rawmidi_substream*,int) ; 
 int snd_rawmidi_transmit_peek (struct snd_rawmidi_substream*,char*,int) ; 
 int /*<<< orphan*/  snd_sb8dsp_midi_input ; 
 int /*<<< orphan*/  snd_sb8dsp_midi_output ; 
 int /*<<< orphan*/  snd_sbdsp_command (struct snd_sb*,char) ; 
 int /*<<< orphan*/  snd_sbdsp_reset (struct snd_sb*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 

irqreturn_t snd_sb8dsp_midi_interrupt(struct snd_sb *chip)
{
	struct snd_rawmidi *rmidi;
	int max = 64;
	char byte;

	if (!chip)
		return IRQ_NONE;
	
	rmidi = chip->rmidi;
	if (!rmidi) {
		inb(SBP(chip, DATA_AVAIL));	/* ack interrupt */
		return IRQ_NONE;
	}

	spin_lock(&chip->midi_input_lock);
	while (max-- > 0) {
		if (inb(SBP(chip, DATA_AVAIL)) & 0x80) {
			byte = inb(SBP(chip, READ));
			if (chip->open & SB_OPEN_MIDI_INPUT_TRIGGER) {
				snd_rawmidi_receive(chip->midi_substream_input, &byte, 1);
			}
		}
	}
	spin_unlock(&chip->midi_input_lock);
	return IRQ_HANDLED;
}

__attribute__((used)) static int snd_sb8dsp_midi_input_open(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip;
	unsigned int valid_open_flags;

	chip = substream->rmidi->private_data;
	valid_open_flags = chip->hardware >= SB_HW_20
		? SB_OPEN_MIDI_OUTPUT | SB_OPEN_MIDI_OUTPUT_TRIGGER : 0;
	spin_lock_irqsave(&chip->open_lock, flags);
	if (chip->open & ~valid_open_flags) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		return -EAGAIN;
	}
	chip->open |= SB_OPEN_MIDI_INPUT;
	chip->midi_substream_input = substream;
	if (!(chip->open & SB_OPEN_MIDI_OUTPUT)) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		snd_sbdsp_reset(chip);		/* reset DSP */
		if (chip->hardware >= SB_HW_20)
			snd_sbdsp_command(chip, SB_DSP_MIDI_UART_IRQ);
	} else {
		spin_unlock_irqrestore(&chip->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int snd_sb8dsp_midi_output_open(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip;
	unsigned int valid_open_flags;

	chip = substream->rmidi->private_data;
	valid_open_flags = chip->hardware >= SB_HW_20
		? SB_OPEN_MIDI_INPUT | SB_OPEN_MIDI_INPUT_TRIGGER : 0;
	spin_lock_irqsave(&chip->open_lock, flags);
	if (chip->open & ~valid_open_flags) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		return -EAGAIN;
	}
	chip->open |= SB_OPEN_MIDI_OUTPUT;
	chip->midi_substream_output = substream;
	if (!(chip->open & SB_OPEN_MIDI_INPUT)) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		snd_sbdsp_reset(chip);		/* reset DSP */
		if (chip->hardware >= SB_HW_20)
			snd_sbdsp_command(chip, SB_DSP_MIDI_UART_IRQ);
	} else {
		spin_unlock_irqrestore(&chip->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int snd_sb8dsp_midi_input_close(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip;

	chip = substream->rmidi->private_data;
	spin_lock_irqsave(&chip->open_lock, flags);
	chip->open &= ~(SB_OPEN_MIDI_INPUT | SB_OPEN_MIDI_INPUT_TRIGGER);
	chip->midi_substream_input = NULL;
	if (!(chip->open & SB_OPEN_MIDI_OUTPUT)) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		snd_sbdsp_reset(chip);		/* reset DSP */
	} else {
		spin_unlock_irqrestore(&chip->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int snd_sb8dsp_midi_output_close(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip;

	chip = substream->rmidi->private_data;
	del_timer_sync(&chip->midi_timer);
	spin_lock_irqsave(&chip->open_lock, flags);
	chip->open &= ~(SB_OPEN_MIDI_OUTPUT | SB_OPEN_MIDI_OUTPUT_TRIGGER);
	chip->midi_substream_output = NULL;
	if (!(chip->open & SB_OPEN_MIDI_INPUT)) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		snd_sbdsp_reset(chip);		/* reset DSP */
	} else {
		spin_unlock_irqrestore(&chip->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static void snd_sb8dsp_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	unsigned long flags;
	struct snd_sb *chip;

	chip = substream->rmidi->private_data;
	spin_lock_irqsave(&chip->open_lock, flags);
	if (up) {
		if (!(chip->open & SB_OPEN_MIDI_INPUT_TRIGGER)) {
			if (chip->hardware < SB_HW_20)
				snd_sbdsp_command(chip, SB_DSP_MIDI_INPUT_IRQ);
			chip->open |= SB_OPEN_MIDI_INPUT_TRIGGER;
		}
	} else {
		if (chip->open & SB_OPEN_MIDI_INPUT_TRIGGER) {
			if (chip->hardware < SB_HW_20)
				snd_sbdsp_command(chip, SB_DSP_MIDI_INPUT_IRQ);
			chip->open &= ~SB_OPEN_MIDI_INPUT_TRIGGER;
		}
	}
	spin_unlock_irqrestore(&chip->open_lock, flags);
}

__attribute__((used)) static void snd_sb8dsp_midi_output_write(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip;
	char byte;
	int max = 32;

	/* how big is Tx FIFO? */
	chip = substream->rmidi->private_data;
	while (max-- > 0) {
		spin_lock_irqsave(&chip->open_lock, flags);
		if (snd_rawmidi_transmit_peek(substream, &byte, 1) != 1) {
			chip->open &= ~SB_OPEN_MIDI_OUTPUT_TRIGGER;
			del_timer(&chip->midi_timer);
			spin_unlock_irqrestore(&chip->open_lock, flags);
			break;
		}
		if (chip->hardware >= SB_HW_20) {
			int timeout = 8;
			while ((inb(SBP(chip, STATUS)) & 0x80) != 0 && --timeout > 0)
				;
			if (timeout == 0) {
				/* Tx FIFO full - try again later */
				spin_unlock_irqrestore(&chip->open_lock, flags);
				break;
			}
			outb(byte, SBP(chip, WRITE));
		} else {
			snd_sbdsp_command(chip, SB_DSP_MIDI_OUTPUT);
			snd_sbdsp_command(chip, byte);
		}
		snd_rawmidi_transmit_ack(substream, 1);
		spin_unlock_irqrestore(&chip->open_lock, flags);
	}
}

__attribute__((used)) static void snd_sb8dsp_midi_output_timer(struct timer_list *t)
{
	struct snd_sb *chip = from_timer(chip, t, midi_timer);
	struct snd_rawmidi_substream *substream = chip->midi_substream_output;
	unsigned long flags;

	spin_lock_irqsave(&chip->open_lock, flags);
	mod_timer(&chip->midi_timer, 1 + jiffies);
	spin_unlock_irqrestore(&chip->open_lock, flags);	
	snd_sb8dsp_midi_output_write(substream);
}

__attribute__((used)) static void snd_sb8dsp_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
	unsigned long flags;
	struct snd_sb *chip;

	chip = substream->rmidi->private_data;
	spin_lock_irqsave(&chip->open_lock, flags);
	if (up) {
		if (!(chip->open & SB_OPEN_MIDI_OUTPUT_TRIGGER)) {
			mod_timer(&chip->midi_timer, 1 + jiffies);
			chip->open |= SB_OPEN_MIDI_OUTPUT_TRIGGER;
		}
	} else {
		if (chip->open & SB_OPEN_MIDI_OUTPUT_TRIGGER) {
			chip->open &= ~SB_OPEN_MIDI_OUTPUT_TRIGGER;
		}
	}
	spin_unlock_irqrestore(&chip->open_lock, flags);

	if (up)
		snd_sb8dsp_midi_output_write(substream);
}

int snd_sb8dsp_midi(struct snd_sb *chip, int device)
{
	struct snd_rawmidi *rmidi;
	int err;

	if ((err = snd_rawmidi_new(chip->card, "SB8 MIDI", device, 1, 1, &rmidi)) < 0)
		return err;
	strcpy(rmidi->name, "SB8 MIDI");
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &snd_sb8dsp_midi_output);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &snd_sb8dsp_midi_input);
	rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT | SNDRV_RAWMIDI_INFO_INPUT;
	if (chip->hardware >= SB_HW_20)
		rmidi->info_flags |= SNDRV_RAWMIDI_INFO_DUPLEX;
	rmidi->private_data = chip;
	timer_setup(&chip->midi_timer, snd_sb8dsp_midi_output_timer, 0);
	chip->rmidi = rmidi;
	return 0;
}

