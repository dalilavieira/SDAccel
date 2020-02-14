#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct pcmuio_private {int irq2; struct pcmuio_asic* asics; } ;
struct pcmuio_board {int num_asics; } ;
struct pcmuio_asic {unsigned int enabled_mask; int active; int /*<<< orphan*/  spinlock; int /*<<< orphan*/  pagelock; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int index; int n_chan; unsigned int state; unsigned int io_bits; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int len_chanlist; int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; } ;
struct comedi_device {unsigned long iobase; int irq; int n_subdevices; struct pcmuio_private* private; struct comedi_subdevice* read_subdev; struct comedi_subdevice* subdevices; int /*<<< orphan*/  board_name; struct pcmuio_board* board_ptr; } ;
struct comedi_devconfig {scalar_t__* options; } ;
struct comedi_cmd {unsigned int chanlist_len; unsigned int* chanlist; unsigned int stop_src; scalar_t__ stop_arg; unsigned int start_arg; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int scan_begin_arg; unsigned int convert_arg; unsigned int scan_end_arg; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {TYPE_1__* range; } ;
struct TYPE_9__ {unsigned int buf_write_count; unsigned int buf_read_count; int (* inttrig ) (struct comedi_device*,struct comedi_subdevice*,unsigned int) ;scalar_t__ scans_done; struct comedi_cmd cmd; int /*<<< orphan*/  events; } ;
struct TYPE_8__ {TYPE_2__* range; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 int /*<<< orphan*/  COMEDI_SUBD_DIO ; 
 unsigned int CR_AREF (unsigned int) ; 
 unsigned int CR_CHAN (unsigned int) ; 
 unsigned int CR_RANGE (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 unsigned int INSN_CONFIG_DIO_INPUT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int PCMUIO_ASIC_IOSIZE ; 
 scalar_t__ PCMUIO_INT_PENDING_REG ; 
 int PCMUIO_MAX_ASICS ; 
 unsigned int PCMUIO_PAGE (int) ; 
 int PCMUIO_PAGE_ENAB ; 
 int PCMUIO_PAGE_INT_ID ; 
 scalar_t__ PCMUIO_PAGE_LOCK_REG ; 
 int PCMUIO_PAGE_POL ; 
 scalar_t__ PCMUIO_PAGE_REG (int) ; 
 scalar_t__ PCMUIO_PORT_REG (int) ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_LSAMPL ; 
 int SDF_PACKED ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_INT ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 struct pcmuio_private* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned int*,int) ; 
 int comedi_dio_insn_config (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*,int /*<<< orphan*/ ) ; 
 unsigned int comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  comedi_legacy_detach (struct comedi_device*) ; 
 int comedi_request_region (struct comedi_device*,scalar_t__,int) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct comedi_device*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (unsigned int,scalar_t__) ; 
 TYPE_5__ range_digital ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct comedi_device*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline bool comedi_range_is_bipolar(struct comedi_subdevice *s,
					   unsigned int range)
{
	return s->range_table->range[range].min < 0;
}

__attribute__((used)) static inline bool comedi_range_is_unipolar(struct comedi_subdevice *s,
					    unsigned int range)
{
	return s->range_table->range[range].min >= 0;
}

__attribute__((used)) static inline bool comedi_range_is_external(struct comedi_subdevice *s,
					    unsigned int range)
{
	return !!(s->range_table->range[range].flags & RF_EXTERNAL);
}

__attribute__((used)) static inline bool comedi_chan_range_is_bipolar(struct comedi_subdevice *s,
						unsigned int chan,
						unsigned int range)
{
	return s->range_table_list[chan]->range[range].min < 0;
}

__attribute__((used)) static inline bool comedi_chan_range_is_unipolar(struct comedi_subdevice *s,
						 unsigned int chan,
						 unsigned int range)
{
	return s->range_table_list[chan]->range[range].min >= 0;
}

__attribute__((used)) static inline bool comedi_chan_range_is_external(struct comedi_subdevice *s,
						 unsigned int chan,
						 unsigned int range)
{
	return !!(s->range_table_list[chan]->range[range].flags & RF_EXTERNAL);
}

__attribute__((used)) static inline unsigned int comedi_offset_munge(struct comedi_subdevice *s,
					       unsigned int val)
{
	return val ^ s->maxdata ^ (s->maxdata >> 1);
}

__attribute__((used)) static inline unsigned int comedi_bytes_per_sample(struct comedi_subdevice *s)
{
	return s->subdev_flags & SDF_LSAMPL ? sizeof(int) : sizeof(short);
}

__attribute__((used)) static inline unsigned int comedi_sample_shift(struct comedi_subdevice *s)
{
	return s->subdev_flags & SDF_LSAMPL ? 2 : 1;
}

__attribute__((used)) static inline unsigned int comedi_bytes_to_samples(struct comedi_subdevice *s,
						   unsigned int nbytes)
{
	return nbytes >> comedi_sample_shift(s);
}

__attribute__((used)) static inline unsigned int comedi_samples_to_bytes(struct comedi_subdevice *s,
						   unsigned int nsamples)
{
	return nsamples << comedi_sample_shift(s);
}

__attribute__((used)) static inline int comedi_check_trigger_src(unsigned int *src,
					   unsigned int flags)
{
	unsigned int orig_src = *src;

	*src = orig_src & flags;
	if (*src == TRIG_INVALID || *src != orig_src)
		return -EINVAL;
	return 0;
}

__attribute__((used)) static inline int comedi_check_trigger_is_unique(unsigned int src)
{
	/* this test is true if more than one _src bit is set */
	if ((src & (src - 1)) != 0)
		return -EINVAL;
	return 0;
}

__attribute__((used)) static inline int comedi_check_trigger_arg_is(unsigned int *arg,
					      unsigned int val)
{
	if (*arg != val) {
		*arg = val;
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static inline int comedi_check_trigger_arg_min(unsigned int *arg,
					       unsigned int val)
{
	if (*arg < val) {
		*arg = val;
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static inline int comedi_check_trigger_arg_max(unsigned int *arg,
					       unsigned int val)
{
	if (*arg > val) {
		*arg = val;
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static inline unsigned int comedi_buf_n_bytes_ready(struct comedi_subdevice *s)
{
	return s->async->buf_write_count - s->async->buf_read_count;
}

__attribute__((used)) static inline unsigned long pcmuio_asic_iobase(struct comedi_device *dev,
					       int asic)
{
	return dev->iobase + (asic * PCMUIO_ASIC_IOSIZE);
}

__attribute__((used)) static inline int pcmuio_subdevice_to_asic(struct comedi_subdevice *s)
{
	/*
	 * subdevice 0 and 1 are handled by the first asic
	 * subdevice 2 and 3 are handled by the second asic
	 */
	return s->index / 2;
}

__attribute__((used)) static inline int pcmuio_subdevice_to_port(struct comedi_subdevice *s)
{
	/*
	 * subdevice 0 and 2 use port registers 0-2
	 * subdevice 1 and 3 use port registers 3-5
	 */
	return (s->index % 2) ? 3 : 0;
}

__attribute__((used)) static void pcmuio_write(struct comedi_device *dev, unsigned int val,
			 int asic, int page, int port)
{
	struct pcmuio_private *devpriv = dev->private;
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	unsigned long iobase = pcmuio_asic_iobase(dev, asic);
	unsigned long flags;

	spin_lock_irqsave(&chip->pagelock, flags);
	if (page == 0) {
		/* Port registers are valid for any page */
		outb(val & 0xff, iobase + PCMUIO_PORT_REG(port + 0));
		outb((val >> 8) & 0xff, iobase + PCMUIO_PORT_REG(port + 1));
		outb((val >> 16) & 0xff, iobase + PCMUIO_PORT_REG(port + 2));
	} else {
		outb(PCMUIO_PAGE(page), iobase + PCMUIO_PAGE_LOCK_REG);
		outb(val & 0xff, iobase + PCMUIO_PAGE_REG(0));
		outb((val >> 8) & 0xff, iobase + PCMUIO_PAGE_REG(1));
		outb((val >> 16) & 0xff, iobase + PCMUIO_PAGE_REG(2));
	}
	spin_unlock_irqrestore(&chip->pagelock, flags);
}

__attribute__((used)) static unsigned int pcmuio_read(struct comedi_device *dev,
				int asic, int page, int port)
{
	struct pcmuio_private *devpriv = dev->private;
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	unsigned long iobase = pcmuio_asic_iobase(dev, asic);
	unsigned long flags;
	unsigned int val;

	spin_lock_irqsave(&chip->pagelock, flags);
	if (page == 0) {
		/* Port registers are valid for any page */
		val = inb(iobase + PCMUIO_PORT_REG(port + 0));
		val |= (inb(iobase + PCMUIO_PORT_REG(port + 1)) << 8);
		val |= (inb(iobase + PCMUIO_PORT_REG(port + 2)) << 16);
	} else {
		outb(PCMUIO_PAGE(page), iobase + PCMUIO_PAGE_LOCK_REG);
		val = inb(iobase + PCMUIO_PAGE_REG(0));
		val |= (inb(iobase + PCMUIO_PAGE_REG(1)) << 8);
		val |= (inb(iobase + PCMUIO_PAGE_REG(2)) << 16);
	}
	spin_unlock_irqrestore(&chip->pagelock, flags);

	return val;
}

__attribute__((used)) static int pcmuio_dio_insn_bits(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	int asic = pcmuio_subdevice_to_asic(s);
	int port = pcmuio_subdevice_to_port(s);
	unsigned int chanmask = (1 << s->n_chan) - 1;
	unsigned int mask;
	unsigned int val;

	mask = comedi_dio_update_state(s, data);
	if (mask) {
		/*
		 * Outputs are inverted, invert the state and
		 * update the channels.
		 *
		 * The s->io_bits mask makes sure the input channels
		 * are '0' so that the outputs pins stay in a high
		 * z-state.
		 */
		val = ~s->state & chanmask;
		val &= s->io_bits;
		pcmuio_write(dev, val, asic, 0, port);
	}

	/* get inverted state of the channels from the port */
	val = pcmuio_read(dev, asic, 0, port);

	/* return the true state of the channels */
	data[1] = ~val & chanmask;

	return insn->n;
}

__attribute__((used)) static int pcmuio_dio_insn_config(struct comedi_device *dev,
				  struct comedi_subdevice *s,
				  struct comedi_insn *insn,
				  unsigned int *data)
{
	int asic = pcmuio_subdevice_to_asic(s);
	int port = pcmuio_subdevice_to_port(s);
	int ret;

	ret = comedi_dio_insn_config(dev, s, insn, data, 0);
	if (ret)
		return ret;

	if (data[0] == INSN_CONFIG_DIO_INPUT)
		pcmuio_write(dev, s->io_bits, asic, 0, port);

	return insn->n;
}

__attribute__((used)) static void pcmuio_reset(struct comedi_device *dev)
{
	const struct pcmuio_board *board = dev->board_ptr;
	int asic;

	for (asic = 0; asic < board->num_asics; ++asic) {
		/* first, clear all the DIO port bits */
		pcmuio_write(dev, 0, asic, 0, 0);
		pcmuio_write(dev, 0, asic, 0, 3);

		/* Next, clear all the paged registers for each page */
		pcmuio_write(dev, 0, asic, PCMUIO_PAGE_POL, 0);
		pcmuio_write(dev, 0, asic, PCMUIO_PAGE_ENAB, 0);
		pcmuio_write(dev, 0, asic, PCMUIO_PAGE_INT_ID, 0);
	}
}

__attribute__((used)) static void pcmuio_stop_intr(struct comedi_device *dev,
			     struct comedi_subdevice *s)
{
	struct pcmuio_private *devpriv = dev->private;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];

	chip->enabled_mask = 0;
	chip->active = 0;
	s->async->inttrig = NULL;

	/* disable all intrs for this subdev.. */
	pcmuio_write(dev, 0, asic, PCMUIO_PAGE_ENAB, 0);
}

__attribute__((used)) static void pcmuio_handle_intr_subdev(struct comedi_device *dev,
				      struct comedi_subdevice *s,
				      unsigned int triggered)
{
	struct pcmuio_private *devpriv = dev->private;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned int val = 0;
	unsigned long flags;
	unsigned int i;

	spin_lock_irqsave(&chip->spinlock, flags);

	if (!chip->active)
		goto done;

	if (!(triggered & chip->enabled_mask))
		goto done;

	for (i = 0; i < cmd->chanlist_len; i++) {
		unsigned int chan = CR_CHAN(cmd->chanlist[i]);

		if (triggered & (1 << chan))
			val |= (1 << i);
	}

	comedi_buf_write_samples(s, &val, 1);

	if (cmd->stop_src == TRIG_COUNT &&
	    s->async->scans_done >= cmd->stop_arg)
		s->async->events |= COMEDI_CB_EOA;

done:
	spin_unlock_irqrestore(&chip->spinlock, flags);

	comedi_handle_events(dev, s);
}

__attribute__((used)) static int pcmuio_handle_asic_interrupt(struct comedi_device *dev, int asic)
{
	/* there are could be two asics so we can't use dev->read_subdev */
	struct comedi_subdevice *s = &dev->subdevices[asic * 2];
	unsigned long iobase = pcmuio_asic_iobase(dev, asic);
	unsigned int val;

	/* are there any interrupts pending */
	val = inb(iobase + PCMUIO_INT_PENDING_REG) & 0x07;
	if (!val)
		return 0;

	/* get, and clear, the pending interrupts */
	val = pcmuio_read(dev, asic, PCMUIO_PAGE_INT_ID, 0);
	pcmuio_write(dev, 0, asic, PCMUIO_PAGE_INT_ID, 0);

	/* handle the pending interrupts */
	pcmuio_handle_intr_subdev(dev, s, val);

	return 1;
}

__attribute__((used)) static irqreturn_t pcmuio_interrupt(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct pcmuio_private *devpriv = dev->private;
	int handled = 0;

	if (irq == dev->irq)
		handled += pcmuio_handle_asic_interrupt(dev, 0);
	if (irq == devpriv->irq2)
		handled += pcmuio_handle_asic_interrupt(dev, 1);

	return handled ? IRQ_HANDLED : IRQ_NONE;
}

__attribute__((used)) static void pcmuio_start_intr(struct comedi_device *dev,
			      struct comedi_subdevice *s)
{
	struct pcmuio_private *devpriv = dev->private;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned int bits = 0;
	unsigned int pol_bits = 0;
	int i;

	chip->enabled_mask = 0;
	chip->active = 1;
	if (cmd->chanlist) {
		for (i = 0; i < cmd->chanlist_len; i++) {
			unsigned int chanspec = cmd->chanlist[i];
			unsigned int chan = CR_CHAN(chanspec);
			unsigned int range = CR_RANGE(chanspec);
			unsigned int aref = CR_AREF(chanspec);

			bits |= (1 << chan);
			pol_bits |= ((aref || range) ? 1 : 0) << chan;
		}
	}
	bits &= ((1 << s->n_chan) - 1);
	chip->enabled_mask = bits;

	/* set pol and enab intrs for this subdev.. */
	pcmuio_write(dev, pol_bits, asic, PCMUIO_PAGE_POL, 0);
	pcmuio_write(dev, bits, asic, PCMUIO_PAGE_ENAB, 0);
}

__attribute__((used)) static int pcmuio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct pcmuio_private *devpriv = dev->private;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	unsigned long flags;

	spin_lock_irqsave(&chip->spinlock, flags);
	if (chip->active)
		pcmuio_stop_intr(dev, s);
	spin_unlock_irqrestore(&chip->spinlock, flags);

	return 0;
}

__attribute__((used)) static int pcmuio_inttrig_start_intr(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     unsigned int trig_num)
{
	struct pcmuio_private *devpriv = dev->private;
	struct comedi_cmd *cmd = &s->async->cmd;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	unsigned long flags;

	if (trig_num != cmd->start_arg)
		return -EINVAL;

	spin_lock_irqsave(&chip->spinlock, flags);
	s->async->inttrig = NULL;
	if (chip->active)
		pcmuio_start_intr(dev, s);

	spin_unlock_irqrestore(&chip->spinlock, flags);

	return 1;
}

__attribute__((used)) static int pcmuio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct pcmuio_private *devpriv = dev->private;
	struct comedi_cmd *cmd = &s->async->cmd;
	int asic = pcmuio_subdevice_to_asic(s);
	struct pcmuio_asic *chip = &devpriv->asics[asic];
	unsigned long flags;

	spin_lock_irqsave(&chip->spinlock, flags);
	chip->active = 1;

	/* Set up start of acquisition. */
	if (cmd->start_src == TRIG_INT)
		s->async->inttrig = pcmuio_inttrig_start_intr;
	else	/* TRIG_NOW */
		pcmuio_start_intr(dev, s);

	spin_unlock_irqrestore(&chip->spinlock, flags);

	return 0;
}

__attribute__((used)) static int pcmuio_cmdtest(struct comedi_device *dev,
			  struct comedi_subdevice *s,
			  struct comedi_cmd *cmd)
{
	int err = 0;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
	err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */

	err |= comedi_check_trigger_is_unique(cmd->start_src);
	err |= comedi_check_trigger_is_unique(cmd->stop_src);

	/* Step 2b : and mutually compatible */

	if (err)
		return 2;

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);

	if (cmd->stop_src == TRIG_COUNT)
		err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
	else	/* TRIG_NONE */
		err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* step 4: fix up any arguments */

	/* if (err) return 4; */

	return 0;
}

__attribute__((used)) static int pcmuio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	const struct pcmuio_board *board = dev->board_ptr;
	struct comedi_subdevice *s;
	struct pcmuio_private *devpriv;
	int ret;
	int i;

	ret = comedi_request_region(dev, it->options[0],
				    board->num_asics * PCMUIO_ASIC_IOSIZE);
	if (ret)
		return ret;

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;

	for (i = 0; i < PCMUIO_MAX_ASICS; ++i) {
		struct pcmuio_asic *chip = &devpriv->asics[i];

		spin_lock_init(&chip->pagelock);
		spin_lock_init(&chip->spinlock);
	}

	pcmuio_reset(dev);

	if (it->options[1]) {
		/* request the irq for the 1st asic */
		ret = request_irq(it->options[1], pcmuio_interrupt, 0,
				  dev->board_name, dev);
		if (ret == 0)
			dev->irq = it->options[1];
	}

	if (board->num_asics == 2) {
		if (it->options[2] == dev->irq) {
			/* the same irq (or none) is used by both asics */
			devpriv->irq2 = it->options[2];
		} else if (it->options[2]) {
			/* request the irq for the 2nd asic */
			ret = request_irq(it->options[2], pcmuio_interrupt, 0,
					  dev->board_name, dev);
			if (ret == 0)
				devpriv->irq2 = it->options[2];
		}
	}

	ret = comedi_alloc_subdevices(dev, board->num_asics * 2);
	if (ret)
		return ret;

	for (i = 0; i < dev->n_subdevices; ++i) {
		s = &dev->subdevices[i];
		s->type		= COMEDI_SUBD_DIO;
		s->subdev_flags	= SDF_READABLE | SDF_WRITABLE;
		s->n_chan	= 24;
		s->maxdata	= 1;
		s->range_table	= &range_digital;
		s->insn_bits	= pcmuio_dio_insn_bits;
		s->insn_config	= pcmuio_dio_insn_config;

		/* subdevices 0 and 2 can support interrupts */
		if ((i == 0 && dev->irq) || (i == 2 && devpriv->irq2)) {
			/* setup the interrupt subdevice */
			dev->read_subdev = s;
			s->subdev_flags	|= SDF_CMD_READ | SDF_LSAMPL |
					   SDF_PACKED;
			s->len_chanlist	= s->n_chan;
			s->cancel	= pcmuio_cancel;
			s->do_cmd	= pcmuio_cmd;
			s->do_cmdtest	= pcmuio_cmdtest;
		}
	}

	return 0;
}

__attribute__((used)) static void pcmuio_detach(struct comedi_device *dev)
{
	struct pcmuio_private *devpriv = dev->private;

	if (devpriv) {
		pcmuio_reset(dev);

		/* free the 2nd irq if used, the core will free the 1st one */
		if (devpriv->irq2 && devpriv->irq2 != dev->irq)
			free_irq(devpriv->irq2, dev);
	}
	comedi_legacy_detach(dev);
}

