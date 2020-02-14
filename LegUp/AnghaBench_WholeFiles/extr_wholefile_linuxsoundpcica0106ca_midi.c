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
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct snd_rawmidi {int info_flags; void (* private_free ) (struct snd_rawmidi*) ;struct snd_ca_midi* private_data; int /*<<< orphan*/  name; } ;
struct snd_ca_midi {int tx_enable; int rx_enable; unsigned int ipr_rx; int midi_mode; unsigned int ipr_tx; scalar_t__ ack; unsigned char reset; unsigned char enter_uart; void (* interrupt ) (struct snd_ca_midi*,unsigned int) ;struct snd_rawmidi* rmidi; int /*<<< orphan*/  output_lock; int /*<<< orphan*/  input_lock; int /*<<< orphan*/  open_lock; void* dev_id; int /*<<< orphan*/  (* get_dev_id_card ) (void*) ;int /*<<< orphan*/  (* get_dev_id_port ) (void*) ;int /*<<< orphan*/ * write; int /*<<< orphan*/ * read; int /*<<< orphan*/  (* interrupt_disable ) (struct snd_ca_midi*,int) ;int /*<<< orphan*/  (* interrupt_enable ) (struct snd_ca_midi*,int) ;struct snd_rawmidi_substream* substream_output; struct snd_rawmidi_substream* substream_input; } ;
struct TYPE_2__ {struct snd_ca_midi* private_data; } ;

/* Variables and functions */
 int CA_MIDI_MODE_INPUT ; 
 int CA_MIDI_MODE_OUTPUT ; 
 int ENXIO ; 
 int SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int SNDRV_RAWMIDI_INFO_INPUT ; 
 int SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 int /*<<< orphan*/  ca_midi_input ; 
 scalar_t__ ca_midi_input_avail (struct snd_ca_midi*) ; 
 int /*<<< orphan*/  ca_midi_output ; 
 scalar_t__ ca_midi_output_ready (struct snd_ca_midi*) ; 
 scalar_t__ ca_midi_read_data (struct snd_ca_midi*) ; 
 int /*<<< orphan*/  ca_midi_read_stat (struct snd_ca_midi*) ; 
 int /*<<< orphan*/  ca_midi_write_cmd (struct snd_ca_midi*,unsigned char) ; 
 int /*<<< orphan*/  ca_midi_write_data (struct snd_ca_midi*,unsigned char) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int snd_rawmidi_new (int /*<<< orphan*/ ,char*,int,int,int,struct snd_rawmidi**) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_set_ops (struct snd_rawmidi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_rawmidi_transmit (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub10 (void*) ; 
 int /*<<< orphan*/  stub2 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub3 (void*) ; 
 int /*<<< orphan*/  stub4 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub5 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub6 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub7 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub8 (struct snd_ca_midi*,int) ; 
 int /*<<< orphan*/  stub9 (struct snd_ca_midi*,int) ; 

__attribute__((used)) static void ca_midi_clear_rx(struct snd_ca_midi *midi)
{
	int timeout = 100000;
	for (; timeout > 0 && ca_midi_input_avail(midi); timeout--)
		ca_midi_read_data(midi);
#ifdef CONFIG_SND_DEBUG
	if (timeout <= 0)
		pr_err("ca_midi_clear_rx: timeout (status = 0x%x)\n",
			   ca_midi_read_stat(midi));
#endif
}

__attribute__((used)) static void ca_midi_interrupt(struct snd_ca_midi *midi, unsigned int status)
{
	unsigned char byte;

	if (midi->rmidi == NULL) {
		midi->interrupt_disable(midi,midi->tx_enable | midi->rx_enable);
		return;
	}

	spin_lock(&midi->input_lock);
	if ((status & midi->ipr_rx) && ca_midi_input_avail(midi)) {
		if (!(midi->midi_mode & CA_MIDI_MODE_INPUT)) {
			ca_midi_clear_rx(midi);
		} else {
			byte = ca_midi_read_data(midi);
			if(midi->substream_input)
				snd_rawmidi_receive(midi->substream_input, &byte, 1);


		}
	}
	spin_unlock(&midi->input_lock);

	spin_lock(&midi->output_lock);
	if ((status & midi->ipr_tx) && ca_midi_output_ready(midi)) {
		if (midi->substream_output &&
		    snd_rawmidi_transmit(midi->substream_output, &byte, 1) == 1) {
			ca_midi_write_data(midi, byte);
		} else {
			midi->interrupt_disable(midi,midi->tx_enable);
		}
	}
	spin_unlock(&midi->output_lock);

}

__attribute__((used)) static void ca_midi_cmd(struct snd_ca_midi *midi, unsigned char cmd, int ack)
{
	unsigned long flags;
	int timeout, ok;

	spin_lock_irqsave(&midi->input_lock, flags);
	ca_midi_write_data(midi, 0x00);
	/* ca_midi_clear_rx(midi); */

	ca_midi_write_cmd(midi, cmd);
	if (ack) {
		ok = 0;
		timeout = 10000;
		while (!ok && timeout-- > 0) {
			if (ca_midi_input_avail(midi)) {
				if (ca_midi_read_data(midi) == midi->ack)
					ok = 1;
			}
		}
		if (!ok && ca_midi_read_data(midi) == midi->ack)
			ok = 1;
	} else {
		ok = 1;
	}
	spin_unlock_irqrestore(&midi->input_lock, flags);
	if (!ok)
		pr_err("ca_midi_cmd: 0x%x failed at 0x%x (status = 0x%x, data = 0x%x)!!!\n",
			   cmd,
			   midi->get_dev_id_port(midi->dev_id),
			   ca_midi_read_stat(midi),
			   ca_midi_read_data(midi));
}

__attribute__((used)) static int ca_midi_input_open(struct snd_rawmidi_substream *substream)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;
	
	if (snd_BUG_ON(!midi->dev_id))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->midi_mode |= CA_MIDI_MODE_INPUT;
	midi->substream_input = substream;
	if (!(midi->midi_mode & CA_MIDI_MODE_OUTPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		ca_midi_cmd(midi, midi->reset, 1);
		ca_midi_cmd(midi, midi->enter_uart, 1);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int ca_midi_output_open(struct snd_rawmidi_substream *substream)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;

	if (snd_BUG_ON(!midi->dev_id))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->midi_mode |= CA_MIDI_MODE_OUTPUT;
	midi->substream_output = substream;
	if (!(midi->midi_mode & CA_MIDI_MODE_INPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		ca_midi_cmd(midi, midi->reset, 1);
		ca_midi_cmd(midi, midi->enter_uart, 1);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int ca_midi_input_close(struct snd_rawmidi_substream *substream)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;

	if (snd_BUG_ON(!midi->dev_id))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->interrupt_disable(midi,midi->rx_enable);
	midi->midi_mode &= ~CA_MIDI_MODE_INPUT;
	midi->substream_input = NULL;
	if (!(midi->midi_mode & CA_MIDI_MODE_OUTPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		ca_midi_cmd(midi, midi->reset, 0);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static int ca_midi_output_close(struct snd_rawmidi_substream *substream)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;

	if (snd_BUG_ON(!midi->dev_id))
		return -ENXIO;
	
	spin_lock_irqsave(&midi->open_lock, flags);

	midi->interrupt_disable(midi,midi->tx_enable);
	midi->midi_mode &= ~CA_MIDI_MODE_OUTPUT;
	midi->substream_output = NULL;
	
	if (!(midi->midi_mode & CA_MIDI_MODE_INPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		ca_midi_cmd(midi, midi->reset, 0);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;
}

__attribute__((used)) static void ca_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;

	if (snd_BUG_ON(!midi->dev_id))
		return;

	if (up) {
		midi->interrupt_enable(midi,midi->rx_enable);
	} else {
		midi->interrupt_disable(midi, midi->rx_enable);
	}
}

__attribute__((used)) static void ca_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;

	if (snd_BUG_ON(!midi->dev_id))
		return;

	if (up) {
		int max = 4;
		unsigned char byte;

		spin_lock_irqsave(&midi->output_lock, flags);
	
		/* try to send some amount of bytes here before interrupts */
		while (max > 0) {
			if (ca_midi_output_ready(midi)) {
				if (!(midi->midi_mode & CA_MIDI_MODE_OUTPUT) ||
				    snd_rawmidi_transmit(substream, &byte, 1) != 1) {
					/* no more data */
					spin_unlock_irqrestore(&midi->output_lock, flags);
					return;
				}
				ca_midi_write_data(midi, byte);
				max--;
			} else {
				break;
			}
		}

		spin_unlock_irqrestore(&midi->output_lock, flags);
		midi->interrupt_enable(midi,midi->tx_enable);

	} else {
		midi->interrupt_disable(midi,midi->tx_enable);
	}
}

__attribute__((used)) static void ca_midi_free(struct snd_ca_midi *midi)
{
	midi->interrupt = NULL;
	midi->interrupt_enable = NULL;
	midi->interrupt_disable = NULL;
	midi->read = NULL;
	midi->write = NULL;
	midi->get_dev_id_card = NULL;
	midi->get_dev_id_port = NULL;
	midi->rmidi = NULL;
}

__attribute__((used)) static void ca_rmidi_free(struct snd_rawmidi *rmidi)
{
	ca_midi_free(rmidi->private_data);
}

int ca_midi_init(void *dev_id, struct snd_ca_midi *midi, int device, char *name)
{
	struct snd_rawmidi *rmidi;
	int err;

	if ((err = snd_rawmidi_new(midi->get_dev_id_card(midi->dev_id), name, device, 1, 1, &rmidi)) < 0)
		return err;

	midi->dev_id = dev_id;
	midi->interrupt = ca_midi_interrupt;

	spin_lock_init(&midi->open_lock);
	spin_lock_init(&midi->input_lock);
	spin_lock_init(&midi->output_lock);

	strcpy(rmidi->name, name);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &ca_midi_output);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &ca_midi_input);
	rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT |
	                     SNDRV_RAWMIDI_INFO_INPUT |
	                     SNDRV_RAWMIDI_INFO_DUPLEX;
	rmidi->private_data = midi;
	rmidi->private_free = ca_rmidi_free;
	
	midi->rmidi = rmidi;
	return 0;
}

