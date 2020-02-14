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
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct snd_rawmidi {int info_flags; void (* private_free ) (struct snd_rawmidi*) ;struct snd_emu10k1_midi* private_data; int /*<<< orphan*/  name; } ;
struct snd_emu10k1_midi {int tx_enable; int rx_enable; unsigned int ipr_rx; int midi_mode; unsigned int ipr_tx; void (* interrupt ) (struct snd_emu10k1*,unsigned int) ;scalar_t__ port; struct snd_rawmidi* rmidi; int /*<<< orphan*/  output_lock; int /*<<< orphan*/  input_lock; int /*<<< orphan*/  open_lock; struct snd_emu10k1* emu; struct snd_rawmidi_substream* substream_output; struct snd_rawmidi_substream* substream_input; } ;
struct snd_emu10k1 {struct snd_emu10k1_midi midi2; struct snd_emu10k1_midi midi; TYPE_2__* card; scalar_t__ port; scalar_t__ audigy; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {scalar_t__ private_data; } ;

/* Variables and functions */
 scalar_t__ A_MUDATA1 ; 
 scalar_t__ A_MUDATA2 ; 
 int EIO ; 
 int EMU10K1_MIDI_MODE_INPUT ; 
 int EMU10K1_MIDI_MODE_OUTPUT ; 
 int ENXIO ; 
 int INTE_A_MIDIRXENABLE2 ; 
 int INTE_A_MIDITXENABLE2 ; 
 void* INTE_MIDIRXENABLE ; 
 void* INTE_MIDITXENABLE ; 
 unsigned int IPR_A_MIDIRECVBUFEMPTY2 ; 
 unsigned int IPR_A_MIDITRANSBUFEMPTY2 ; 
 void* IPR_MIDIRECVBUFEMPTY ; 
 void* IPR_MIDITRANSBUFEMPTY ; 
 scalar_t__ MPU401_ACK ; 
 unsigned char MPU401_ENTER_UART ; 
 unsigned char MPU401_RESET ; 
 scalar_t__ MUDATA ; 
 int SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int SNDRV_RAWMIDI_INFO_INPUT ; 
 int SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,unsigned char,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 unsigned char inb (scalar_t__) ; 
 scalar_t__ mpu401_input_avail (struct snd_emu10k1*,struct snd_emu10k1_midi*) ; 
 scalar_t__ mpu401_output_ready (struct snd_emu10k1*,struct snd_emu10k1_midi*) ; 
 scalar_t__ mpu401_read_data (struct snd_emu10k1*,struct snd_emu10k1_midi*) ; 
 int /*<<< orphan*/  mpu401_read_stat (struct snd_emu10k1*,struct snd_emu10k1_midi*) ; 
 int /*<<< orphan*/  mpu401_write_cmd (struct snd_emu10k1*,struct snd_emu10k1_midi*,unsigned char) ; 
 int /*<<< orphan*/  mpu401_write_data (struct snd_emu10k1*,struct snd_emu10k1_midi*,unsigned char) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_emu10k1_intr_disable (struct snd_emu10k1*,int) ; 
 int /*<<< orphan*/  snd_emu10k1_intr_enable (struct snd_emu10k1*,int) ; 
 int /*<<< orphan*/  snd_emu10k1_midi_input ; 
 int /*<<< orphan*/  snd_emu10k1_midi_output ; 
 scalar_t__ snd_emu10k1_ptr_read (struct snd_emu10k1*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_emu10k1_ptr_write (struct snd_emu10k1*,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int snd_rawmidi_new (TYPE_2__*,char*,int,int,int,struct snd_rawmidi**) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_set_ops (struct snd_rawmidi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_rawmidi_transmit (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline unsigned char mpu401_read(struct snd_emu10k1 *emu,
					struct snd_emu10k1_midi *mpu, int idx)
{
	if (emu->audigy)
		return (unsigned char)snd_emu10k1_ptr_read(emu, mpu->port + idx, 0);
	else
		return inb(emu->port + mpu->port + idx);
}

__attribute__((used)) static inline void mpu401_write(struct snd_emu10k1 *emu,
				struct snd_emu10k1_midi *mpu, int data, int idx)
{
	if (emu->audigy)
		snd_emu10k1_ptr_write(emu, mpu->port + idx, 0, data);
	else
		outb(data, emu->port + mpu->port + idx);
}

__attribute__((used)) static void mpu401_clear_rx(struct snd_emu10k1 *emu, struct snd_emu10k1_midi *mpu)
{
	int timeout = 100000;
	for (; timeout > 0 && mpu401_input_avail(emu, mpu); timeout--)
		mpu401_read_data(emu, mpu);
#ifdef CONFIG_SND_DEBUG
	if (timeout <= 0)
		dev_err(emu->card->dev,
			"cmd: clear rx timeout (status = 0x%x)\n",
			mpu401_read_stat(emu, mpu));
#endif
}

__attribute__((used)) static void do_emu10k1_midi_interrupt(struct snd_emu10k1 *emu, struct snd_emu10k1_midi *midi, unsigned int status)
{
	unsigned char byte;

	if (midi->rmidi == NULL) {
		snd_emu10k1_intr_disable(emu, midi->tx_enable | midi->rx_enable);
		return;
	}

	spin_lock(&midi->input_lock);
	if ((status & midi->ipr_rx) && mpu401_input_avail(emu, midi)) {
		if (!(midi->midi_mode & EMU10K1_MIDI_MODE_INPUT)) {
			mpu401_clear_rx(emu, midi);
		} else {
			byte = mpu401_read_data(emu, midi);
			if (midi->substream_input)
				snd_rawmidi_receive(midi->substream_input, &byte, 1);
		}
	}
	spin_unlock(&midi->input_lock);

	spin_lock(&midi->output_lock);
	if ((status & midi->ipr_tx) && mpu401_output_ready(emu, midi)) {
		if (midi->substream_output &&
		    snd_rawmidi_transmit(midi->substream_output, &byte, 1) == 1) {
			mpu401_write_data(emu, midi, byte);
		} else {
			snd_emu10k1_intr_disable(emu, midi->tx_enable);
		}
	}
	spin_unlock(&midi->output_lock);
}

__attribute__((used)) static void snd_emu10k1_midi_interrupt(struct snd_emu10k1 *emu, unsigned int status)
{
	do_emu10k1_midi_interrupt(emu, &emu->midi, status);
}

__attribute__((used)) static void snd_emu10k1_midi_interrupt2(struct snd_emu10k1 *emu, unsigned int status)
{
	do_emu10k1_midi_interrupt(emu, &emu->midi2, status);
}

__attribute__((used)) static int snd_emu10k1_midi_cmd(struct snd_emu10k1 * emu, struct snd_emu10k1_midi *midi, unsigned char cmd, int ack)
{
	unsigned long flags;
	int timeout, ok;

	spin_lock_irqsave(&midi->input_lock, flags);
	mpu401_write_data(emu, midi, 0x00);
	/* mpu401_clear_rx(emu, midi); */

	mpu401_write_cmd(emu, midi, cmd);
	if (ack) {
		ok = 0;
		timeout = 10000;
		while (!ok && timeout-- > 0) {
			if (mpu401_input_avail(emu, midi)) {
				if (mpu401_read_data(emu, midi) == MPU401_ACK)
					ok = 1;
			}
		}
		if (!ok && mpu401_read_data(emu, midi) == MPU401_ACK)
			ok = 1;
	} else {
		ok = 1;
	}
	spin_unlock_irqrestore(&midi->input_lock, flags);
	if (!ok) {
		dev_err(emu->card->dev,
			"midi_cmd: 0x%x failed at 0x%lx (status = 0x%x, data = 0x%x)!!!\n",
			   cmd, emu->port,
			   mpu401_read_stat(emu, midi),
			   mpu401_read_data(emu, midi));
		return 1;
	}
	return 0;
}

__attribute__((used)) static int snd_emu10k1_midi_input_open(struct snd_rawmidi_substream *substream)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	unsigned long flags;

	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->midi_mode |= EMU10K1_MIDI_MODE_INPUT;
	midi->substream_input = substream;
	if (!(midi->midi_mode & EMU10K1_MIDI_MODE_OUTPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		if (snd_emu10k1_midi_cmd(emu, midi, MPU401_RESET, 1))
			goto error_out;
		if (snd_emu10k1_midi_cmd(emu, midi, MPU401_ENTER_UART, 1))
			goto error_out;
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;

error_out:
	return -EIO;
}

__attribute__((used)) static int snd_emu10k1_midi_output_open(struct snd_rawmidi_substream *substream)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	unsigned long flags;

	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->midi_mode |= EMU10K1_MIDI_MODE_OUTPUT;
	midi->substream_output = substream;
	if (!(midi->midi_mode & EMU10K1_MIDI_MODE_INPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		if (snd_emu10k1_midi_cmd(emu, midi, MPU401_RESET, 1))
			goto error_out;
		if (snd_emu10k1_midi_cmd(emu, midi, MPU401_ENTER_UART, 1))
			goto error_out;
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;

error_out:
	return -EIO;
}

__attribute__((used)) static int snd_emu10k1_midi_input_close(struct snd_rawmidi_substream *substream)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	unsigned long flags;
	int err = 0;

	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	snd_emu10k1_intr_disable(emu, midi->rx_enable);
	midi->midi_mode &= ~EMU10K1_MIDI_MODE_INPUT;
	midi->substream_input = NULL;
	if (!(midi->midi_mode & EMU10K1_MIDI_MODE_OUTPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		err = snd_emu10k1_midi_cmd(emu, midi, MPU401_RESET, 0);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return err;
}

__attribute__((used)) static int snd_emu10k1_midi_output_close(struct snd_rawmidi_substream *substream)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	unsigned long flags;
	int err = 0;

	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	snd_emu10k1_intr_disable(emu, midi->tx_enable);
	midi->midi_mode &= ~EMU10K1_MIDI_MODE_OUTPUT;
	midi->substream_output = NULL;
	if (!(midi->midi_mode & EMU10K1_MIDI_MODE_INPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		err = snd_emu10k1_midi_cmd(emu, midi, MPU401_RESET, 0);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return err;
}

__attribute__((used)) static void snd_emu10k1_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return;

	if (up)
		snd_emu10k1_intr_enable(emu, midi->rx_enable);
	else
		snd_emu10k1_intr_disable(emu, midi->rx_enable);
}

__attribute__((used)) static void snd_emu10k1_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_emu10k1 *emu;
	struct snd_emu10k1_midi *midi = (struct snd_emu10k1_midi *)substream->rmidi->private_data;
	unsigned long flags;

	emu = midi->emu;
	if (snd_BUG_ON(!emu))
		return;

	if (up) {
		int max = 4;
		unsigned char byte;
	
		/* try to send some amount of bytes here before interrupts */
		spin_lock_irqsave(&midi->output_lock, flags);
		while (max > 0) {
			if (mpu401_output_ready(emu, midi)) {
				if (!(midi->midi_mode & EMU10K1_MIDI_MODE_OUTPUT) ||
				    snd_rawmidi_transmit(substream, &byte, 1) != 1) {
					/* no more data */
					spin_unlock_irqrestore(&midi->output_lock, flags);
					return;
				}
				mpu401_write_data(emu, midi, byte);
				max--;
			} else {
				break;
			}
		}
		spin_unlock_irqrestore(&midi->output_lock, flags);
		snd_emu10k1_intr_enable(emu, midi->tx_enable);
	} else {
		snd_emu10k1_intr_disable(emu, midi->tx_enable);
	}
}

__attribute__((used)) static void snd_emu10k1_midi_free(struct snd_rawmidi *rmidi)
{
	struct snd_emu10k1_midi *midi = rmidi->private_data;
	midi->interrupt = NULL;
	midi->rmidi = NULL;
}

__attribute__((used)) static int emu10k1_midi_init(struct snd_emu10k1 *emu, struct snd_emu10k1_midi *midi, int device, char *name)
{
	struct snd_rawmidi *rmidi;
	int err;

	if ((err = snd_rawmidi_new(emu->card, name, device, 1, 1, &rmidi)) < 0)
		return err;
	midi->emu = emu;
	spin_lock_init(&midi->open_lock);
	spin_lock_init(&midi->input_lock);
	spin_lock_init(&midi->output_lock);
	strcpy(rmidi->name, name);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &snd_emu10k1_midi_output);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &snd_emu10k1_midi_input);
	rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT |
	                     SNDRV_RAWMIDI_INFO_INPUT |
	                     SNDRV_RAWMIDI_INFO_DUPLEX;
	rmidi->private_data = midi;
	rmidi->private_free = snd_emu10k1_midi_free;
	midi->rmidi = rmidi;
	return 0;
}

int snd_emu10k1_midi(struct snd_emu10k1 *emu)
{
	struct snd_emu10k1_midi *midi = &emu->midi;
	int err;

	if ((err = emu10k1_midi_init(emu, midi, 0, "EMU10K1 MPU-401 (UART)")) < 0)
		return err;

	midi->tx_enable = INTE_MIDITXENABLE;
	midi->rx_enable = INTE_MIDIRXENABLE;
	midi->port = MUDATA;
	midi->ipr_tx = IPR_MIDITRANSBUFEMPTY;
	midi->ipr_rx = IPR_MIDIRECVBUFEMPTY;
	midi->interrupt = snd_emu10k1_midi_interrupt;
	return 0;
}

int snd_emu10k1_audigy_midi(struct snd_emu10k1 *emu)
{
	struct snd_emu10k1_midi *midi;
	int err;

	midi = &emu->midi;
	if ((err = emu10k1_midi_init(emu, midi, 0, "Audigy MPU-401 (UART)")) < 0)
		return err;

	midi->tx_enable = INTE_MIDITXENABLE;
	midi->rx_enable = INTE_MIDIRXENABLE;
	midi->port = A_MUDATA1;
	midi->ipr_tx = IPR_MIDITRANSBUFEMPTY;
	midi->ipr_rx = IPR_MIDIRECVBUFEMPTY;
	midi->interrupt = snd_emu10k1_midi_interrupt;

	midi = &emu->midi2;
	if ((err = emu10k1_midi_init(emu, midi, 1, "Audigy MPU-401 #2")) < 0)
		return err;

	midi->tx_enable = INTE_A_MIDITXENABLE2;
	midi->rx_enable = INTE_A_MIDIRXENABLE2;
	midi->port = A_MUDATA2;
	midi->ipr_tx = IPR_A_MIDITRANSBUFEMPTY2;
	midi->ipr_rx = IPR_A_MIDIRECVBUFEMPTY2;
	midi->interrupt = snd_emu10k1_midi_interrupt2;
	return 0;
}

