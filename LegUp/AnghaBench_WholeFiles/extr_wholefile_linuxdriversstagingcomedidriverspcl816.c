#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct pcl816_private {int ai_cmd_running; int ai_cmd_canceled; unsigned int ai_poll_ptr; struct comedi_isadma* dma; } ;
struct pcl816_board {unsigned int ai_maxdata; int /*<<< orphan*/  ai_chanlist; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int state; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* poll ) (struct comedi_device*,struct comedi_subdevice*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; int /*<<< orphan*/  len_chanlist; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_isadma_desc {unsigned int maxsize; unsigned int size; unsigned short* virt_addr; } ;
struct comedi_isadma {size_t cur_dma; unsigned int chan; struct comedi_isadma_desc* desc; } ;
struct comedi_insn {unsigned int chanspec; int n; } ;
struct comedi_device {int irq; struct comedi_subdevice* read_subdev; struct pcl816_private* private; struct comedi_subdevice* subdevices; int /*<<< orphan*/  pacer; scalar_t__ iobase; struct pcl816_board* board_ptr; int /*<<< orphan*/  board_name; int /*<<< orphan*/  spinlock; int /*<<< orphan*/  class_dev; int /*<<< orphan*/  attached; } ;
struct comedi_devconfig {unsigned int* options; } ;
struct comedi_cmd {unsigned int stop_src; scalar_t__ stop_arg; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int start_arg; unsigned int scan_begin_arg; unsigned int convert_arg; unsigned int scan_end_arg; unsigned int chanlist_len; unsigned int* chanlist; int /*<<< orphan*/  flags; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_11__ {TYPE_1__* range; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; scalar_t__ scans_done; struct comedi_cmd cmd; int /*<<< orphan*/  events; } ;
struct TYPE_9__ {TYPE_2__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 char COMEDI_ISADMA_READ ; 
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int /*<<< orphan*/  COMEDI_SUBD_DI ; 
 int /*<<< orphan*/  COMEDI_SUBD_DO ; 
 int /*<<< orphan*/  COMEDI_SUBD_UNUSED ; 
 int /*<<< orphan*/  CR_AREF (unsigned int) ; 
 unsigned int CR_CHAN (unsigned int) ; 
 unsigned int CR_RANGE (unsigned int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int I8254_BINARY ; 
 int /*<<< orphan*/  I8254_IO8 ; 
 int I8254_MODE1 ; 
 int /*<<< orphan*/  I8254_OSC_BASE_10MHZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int PAGE_SIZE ; 
 scalar_t__ PCL816_AI_LSB_REG ; 
 scalar_t__ PCL816_AI_MSB_REG ; 
 scalar_t__ PCL816_CLRINT_REG ; 
 unsigned int PCL816_CTRL_DMAEN ; 
 unsigned int PCL816_CTRL_DMASRC_SLOT (int /*<<< orphan*/ ) ; 
 unsigned int PCL816_CTRL_EXT_TRIG ; 
 unsigned int PCL816_CTRL_INTEN ; 
 unsigned int PCL816_CTRL_PACER_TRIG ; 
 scalar_t__ PCL816_CTRL_REG ; 
 int PCL816_CTRL_SOFT_TRIG ; 
 scalar_t__ PCL816_DO_DI_LSB_REG ; 
 scalar_t__ PCL816_DO_DI_MSB_REG ; 
 scalar_t__ PCL816_MUX_REG ; 
 int PCL816_MUX_SCAN (unsigned int,unsigned int) ; 
 scalar_t__ PCL816_RANGE_REG ; 
 unsigned int PCL816_STATUS_DRDY ; 
 scalar_t__ PCL816_STATUS_REG ; 
 scalar_t__ PCL816_TIMER_BASE ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_DIFF ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_FOLLOW ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 unsigned int TRIG_TIMER ; 
 int /*<<< orphan*/  comedi_8254_cascade_ns_to_timer (int /*<<< orphan*/ ,unsigned int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_8254_init (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_8254_pacer_enable (int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  comedi_8254_set_mode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  comedi_8254_update_divisors (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_8254_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct pcl816_private* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned short*,int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  comedi_legacy_detach (struct comedi_device*) ; 
 unsigned int comedi_nsamples_left (struct comedi_subdevice*,unsigned int) ; 
 int comedi_request_region (struct comedi_device*,unsigned int,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,unsigned int,unsigned int,unsigned int,unsigned int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free_irq (unsigned int,struct comedi_device*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 TYPE_5__ range_digital ; 
 TYPE_5__ range_pcl816 ; 
 scalar_t__ request_irq (unsigned int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct comedi_device*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

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

__attribute__((used)) static inline void comedi_isadma_program(struct comedi_isadma_desc *desc)
{
}

__attribute__((used)) static inline unsigned int comedi_isadma_disable(unsigned int dma_chan)
{
	return 0;
}

__attribute__((used)) static inline unsigned int
comedi_isadma_disable_on_sample(unsigned int dma_chan, unsigned int size)
{
	return 0;
}

__attribute__((used)) static inline unsigned int comedi_isadma_poll(struct comedi_isadma *dma)
{
	return 0;
}

__attribute__((used)) static inline void comedi_isadma_set_mode(struct comedi_isadma_desc *desc,
					  char dma_dir)
{
}

__attribute__((used)) static inline struct comedi_isadma *
comedi_isadma_alloc(struct comedi_device *dev, int n_desc,
		    unsigned int dma_chan1, unsigned int dma_chan2,
		    unsigned int maxsize, char dma_dir)
{
	return NULL;
}

__attribute__((used)) static inline void comedi_isadma_free(struct comedi_isadma *dma)
{
}

__attribute__((used)) static void pcl816_ai_setup_dma(struct comedi_device *dev,
				struct comedi_subdevice *s,
				unsigned int unread_samples)
{
	struct pcl816_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
	unsigned int max_samples = comedi_bytes_to_samples(s, desc->maxsize);
	unsigned int nsamples;

	comedi_isadma_disable(dma->chan);

	/*
	 * Determine dma size based on the buffer maxsize plus the number of
	 * unread samples and the number of samples remaining in the command.
	 */
	nsamples = comedi_nsamples_left(s, max_samples + unread_samples);
	if (nsamples > unread_samples) {
		nsamples -= unread_samples;
		desc->size = comedi_samples_to_bytes(s, nsamples);
		comedi_isadma_program(desc);
	}
}

__attribute__((used)) static void pcl816_ai_set_chan_range(struct comedi_device *dev,
				     unsigned int chan,
				     unsigned int range)
{
	outb(chan, dev->iobase + PCL816_MUX_REG);
	outb(range, dev->iobase + PCL816_RANGE_REG);
}

__attribute__((used)) static void pcl816_ai_set_chan_scan(struct comedi_device *dev,
				    unsigned int first_chan,
				    unsigned int last_chan)
{
	outb(PCL816_MUX_SCAN(first_chan, last_chan),
	     dev->iobase + PCL816_MUX_REG);
}

__attribute__((used)) static void pcl816_ai_setup_chanlist(struct comedi_device *dev,
				     unsigned int *chanlist,
				     unsigned int seglen)
{
	unsigned int first_chan = CR_CHAN(chanlist[0]);
	unsigned int last_chan;
	unsigned int range;
	unsigned int i;

	/* store range list to card */
	for (i = 0; i < seglen; i++) {
		last_chan = CR_CHAN(chanlist[i]);
		range = CR_RANGE(chanlist[i]);

		pcl816_ai_set_chan_range(dev, last_chan, range);
	}

	udelay(1);

	pcl816_ai_set_chan_scan(dev, first_chan, last_chan);
}

__attribute__((used)) static void pcl816_ai_clear_eoc(struct comedi_device *dev)
{
	/* writing any value clears the interrupt request */
	outb(0, dev->iobase + PCL816_CLRINT_REG);
}

__attribute__((used)) static void pcl816_ai_soft_trig(struct comedi_device *dev)
{
	/* writing any value triggers a software conversion */
	outb(0, dev->iobase + PCL816_AI_LSB_REG);
}

__attribute__((used)) static unsigned int pcl816_ai_get_sample(struct comedi_device *dev,
					 struct comedi_subdevice *s)
{
	unsigned int val;

	val = inb(dev->iobase + PCL816_AI_MSB_REG) << 8;
	val |= inb(dev->iobase + PCL816_AI_LSB_REG);

	return val & s->maxdata;
}

__attribute__((used)) static int pcl816_ai_eoc(struct comedi_device *dev,
			 struct comedi_subdevice *s,
			 struct comedi_insn *insn,
			 unsigned long context)
{
	unsigned int status;

	status = inb(dev->iobase + PCL816_STATUS_REG);
	if ((status & PCL816_STATUS_DRDY) == 0)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static bool pcl816_ai_next_chan(struct comedi_device *dev,
				struct comedi_subdevice *s)
{
	struct comedi_cmd *cmd = &s->async->cmd;

	if (cmd->stop_src == TRIG_COUNT &&
	    s->async->scans_done >= cmd->stop_arg) {
		s->async->events |= COMEDI_CB_EOA;
		return false;
	}

	return true;
}

__attribute__((used)) static void transfer_from_dma_buf(struct comedi_device *dev,
				  struct comedi_subdevice *s,
				  unsigned short *ptr,
				  unsigned int bufptr, unsigned int len)
{
	unsigned short val;
	int i;

	for (i = 0; i < len; i++) {
		val = ptr[bufptr++];
		comedi_buf_write_samples(s, &val, 1);

		if (!pcl816_ai_next_chan(dev, s))
			return;
	}
}

__attribute__((used)) static irqreturn_t pcl816_interrupt(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct comedi_subdevice *s = dev->read_subdev;
	struct pcl816_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
	unsigned int nsamples;
	unsigned int bufptr;

	if (!dev->attached || !devpriv->ai_cmd_running) {
		pcl816_ai_clear_eoc(dev);
		return IRQ_HANDLED;
	}

	if (devpriv->ai_cmd_canceled) {
		devpriv->ai_cmd_canceled = 0;
		pcl816_ai_clear_eoc(dev);
		return IRQ_HANDLED;
	}

	nsamples = comedi_bytes_to_samples(s, desc->size) -
		   devpriv->ai_poll_ptr;
	bufptr = devpriv->ai_poll_ptr;
	devpriv->ai_poll_ptr = 0;

	/* restart dma with the next buffer */
	dma->cur_dma = 1 - dma->cur_dma;
	pcl816_ai_setup_dma(dev, s, nsamples);

	transfer_from_dma_buf(dev, s, desc->virt_addr, bufptr, nsamples);

	pcl816_ai_clear_eoc(dev);

	comedi_handle_events(dev, s);
	return IRQ_HANDLED;
}

__attribute__((used)) static int check_channel_list(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      unsigned int *chanlist,
			      unsigned int chanlen)
{
	unsigned int chansegment[16];
	unsigned int i, nowmustbechan, seglen;

	/*  correct channel and range number check itself comedi/range.c */
	if (chanlen < 1) {
		dev_err(dev->class_dev, "range/channel list is empty!\n");
		return 0;
	}

	if (chanlen > 1) {
		/*  first channel is every time ok */
		chansegment[0] = chanlist[0];
		for (i = 1, seglen = 1; i < chanlen; i++, seglen++) {
			/*  we detect loop, this must by finish */
			if (chanlist[0] == chanlist[i])
				break;
			nowmustbechan =
			    (CR_CHAN(chansegment[i - 1]) + 1) % chanlen;
			if (nowmustbechan != CR_CHAN(chanlist[i])) {
				/*  channel list isn't continuous :-( */
				dev_dbg(dev->class_dev,
					"channel list must be continuous! chanlist[%i]=%d but must be %d or %d!\n",
					i, CR_CHAN(chanlist[i]), nowmustbechan,
					CR_CHAN(chanlist[0]));
				return 0;
			}
			/*  well, this is next correct channel in list */
			chansegment[i] = chanlist[i];
		}

		/*  check whole chanlist */
		for (i = 0; i < chanlen; i++) {
			if (chanlist[i] != chansegment[i % seglen]) {
				dev_dbg(dev->class_dev,
					"bad channel or range number! chanlist[%i]=%d,%d,%d and not %d,%d,%d!\n",
					i, CR_CHAN(chansegment[i]),
					CR_RANGE(chansegment[i]),
					CR_AREF(chansegment[i]),
					CR_CHAN(chanlist[i % seglen]),
					CR_RANGE(chanlist[i % seglen]),
					CR_AREF(chansegment[i % seglen]));
				return 0;	/*  chan/gain list is strange */
			}
		}
	} else {
		seglen = 1;
	}

	return seglen;	/*  we can serve this with MUX logic */
}

__attribute__((used)) static int pcl816_ai_cmdtest(struct comedi_device *dev,
			     struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
	int err = 0;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
	err |= comedi_check_trigger_src(&cmd->convert_src,
					TRIG_EXT | TRIG_TIMER);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */

	err |= comedi_check_trigger_is_unique(cmd->convert_src);
	err |= comedi_check_trigger_is_unique(cmd->stop_src);

	/* Step 2b : and mutually compatible */

	if (err)
		return 2;

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);

	if (cmd->convert_src == TRIG_TIMER)
		err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 10000);
	else	/* TRIG_EXT */
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
	if (cmd->convert_src == TRIG_TIMER) {
		unsigned int arg = cmd->convert_arg;

		comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
		err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
	}

	if (err)
		return 4;

	/* step 5: complain about special chanlist considerations */

	if (cmd->chanlist) {
		if (!check_channel_list(dev, s, cmd->chanlist,
					cmd->chanlist_len))
			return 5;	/*  incorrect channels list */
	}

	return 0;
}

__attribute__((used)) static int pcl816_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct pcl816_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned int ctrl;
	unsigned int seglen;

	if (devpriv->ai_cmd_running)
		return -EBUSY;

	seglen = check_channel_list(dev, s, cmd->chanlist, cmd->chanlist_len);
	if (seglen < 1)
		return -EINVAL;
	pcl816_ai_setup_chanlist(dev, cmd->chanlist, seglen);
	udelay(1);

	devpriv->ai_cmd_running = 1;
	devpriv->ai_poll_ptr = 0;
	devpriv->ai_cmd_canceled = 0;

	/* setup and enable dma for the first buffer */
	dma->cur_dma = 0;
	pcl816_ai_setup_dma(dev, s, 0);

	comedi_8254_set_mode(dev->pacer, 0, I8254_MODE1 | I8254_BINARY);
	comedi_8254_write(dev->pacer, 0, 0x0ff);
	udelay(1);
	comedi_8254_update_divisors(dev->pacer);
	comedi_8254_pacer_enable(dev->pacer, 1, 2, true);

	ctrl = PCL816_CTRL_INTEN | PCL816_CTRL_DMAEN |
	       PCL816_CTRL_DMASRC_SLOT(0);
	if (cmd->convert_src == TRIG_TIMER)
		ctrl |= PCL816_CTRL_PACER_TRIG;
	else	/* TRIG_EXT */
		ctrl |= PCL816_CTRL_EXT_TRIG;

	outb(ctrl, dev->iobase + PCL816_CTRL_REG);
	outb((dma->chan << 4) | dev->irq,
	     dev->iobase + PCL816_STATUS_REG);

	return 0;
}

__attribute__((used)) static int pcl816_ai_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct pcl816_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc;
	unsigned long flags;
	unsigned int poll;
	int ret;

	spin_lock_irqsave(&dev->spinlock, flags);

	poll = comedi_isadma_poll(dma);
	poll = comedi_bytes_to_samples(s, poll);
	if (poll > devpriv->ai_poll_ptr) {
		desc = &dma->desc[dma->cur_dma];
		transfer_from_dma_buf(dev, s, desc->virt_addr,
				      devpriv->ai_poll_ptr,
				      poll - devpriv->ai_poll_ptr);
		/* new buffer position */
		devpriv->ai_poll_ptr = poll;

		comedi_handle_events(dev, s);

		ret = comedi_buf_n_bytes_ready(s);
	} else {
		/* no new samples */
		ret = 0;
	}
	spin_unlock_irqrestore(&dev->spinlock, flags);

	return ret;
}

__attribute__((used)) static int pcl816_ai_cancel(struct comedi_device *dev,
			    struct comedi_subdevice *s)
{
	struct pcl816_private *devpriv = dev->private;

	if (!devpriv->ai_cmd_running)
		return 0;

	outb(0, dev->iobase + PCL816_CTRL_REG);
	pcl816_ai_clear_eoc(dev);

	comedi_8254_pacer_enable(dev->pacer, 1, 2, false);

	devpriv->ai_cmd_running = 0;
	devpriv->ai_cmd_canceled = 1;

	return 0;
}

__attribute__((used)) static int pcl816_ai_insn_read(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int range = CR_RANGE(insn->chanspec);
	int ret = 0;
	int i;

	outb(PCL816_CTRL_SOFT_TRIG, dev->iobase + PCL816_CTRL_REG);

	pcl816_ai_set_chan_range(dev, chan, range);
	pcl816_ai_set_chan_scan(dev, chan, chan);

	for (i = 0; i < insn->n; i++) {
		pcl816_ai_clear_eoc(dev);
		pcl816_ai_soft_trig(dev);

		ret = comedi_timeout(dev, s, insn, pcl816_ai_eoc, 0);
		if (ret)
			break;

		data[i] = pcl816_ai_get_sample(dev, s);
	}
	outb(0, dev->iobase + PCL816_CTRL_REG);
	pcl816_ai_clear_eoc(dev);

	return ret ? ret : insn->n;
}

__attribute__((used)) static int pcl816_di_insn_bits(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	data[1] = inb(dev->iobase + PCL816_DO_DI_LSB_REG) |
		  (inb(dev->iobase + PCL816_DO_DI_MSB_REG) << 8);

	return insn->n;
}

__attribute__((used)) static int pcl816_do_insn_bits(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	if (comedi_dio_update_state(s, data)) {
		outb(s->state & 0xff, dev->iobase + PCL816_DO_DI_LSB_REG);
		outb((s->state >> 8), dev->iobase + PCL816_DO_DI_MSB_REG);
	}

	data[1] = s->state;

	return insn->n;
}

__attribute__((used)) static void pcl816_reset(struct comedi_device *dev)
{
	outb(0, dev->iobase + PCL816_CTRL_REG);
	pcl816_ai_set_chan_range(dev, 0, 0);
	pcl816_ai_clear_eoc(dev);

	/* set all digital outputs low */
	outb(0, dev->iobase + PCL816_DO_DI_LSB_REG);
	outb(0, dev->iobase + PCL816_DO_DI_MSB_REG);
}

__attribute__((used)) static void pcl816_alloc_irq_and_dma(struct comedi_device *dev,
				     struct comedi_devconfig *it)
{
	struct pcl816_private *devpriv = dev->private;
	unsigned int irq_num = it->options[1];
	unsigned int dma_chan = it->options[2];

	/* only IRQs 2-7 and DMA channels 3 and 1 are valid */
	if (!(irq_num >= 2 && irq_num <= 7) ||
	    !(dma_chan == 3 || dma_chan == 1))
		return;

	if (request_irq(irq_num, pcl816_interrupt, 0, dev->board_name, dev))
		return;

	/* DMA uses two 16K buffers */
	devpriv->dma = comedi_isadma_alloc(dev, 2, dma_chan, dma_chan,
					   PAGE_SIZE * 4, COMEDI_ISADMA_READ);
	if (!devpriv->dma)
		free_irq(irq_num, dev);
	else
		dev->irq = irq_num;
}

__attribute__((used)) static void pcl816_free_dma(struct comedi_device *dev)
{
	struct pcl816_private *devpriv = dev->private;

	if (devpriv)
		comedi_isadma_free(devpriv->dma);
}

__attribute__((used)) static int pcl816_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	const struct pcl816_board *board = dev->board_ptr;
	struct pcl816_private *devpriv;
	struct comedi_subdevice *s;
	int ret;

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;

	ret = comedi_request_region(dev, it->options[0], 0x10);
	if (ret)
		return ret;

	/* an IRQ and DMA are required to support async commands */
	pcl816_alloc_irq_and_dma(dev, it);

	dev->pacer = comedi_8254_init(dev->iobase + PCL816_TIMER_BASE,
				      I8254_OSC_BASE_10MHZ, I8254_IO8, 0);
	if (!dev->pacer)
		return -ENOMEM;

	ret = comedi_alloc_subdevices(dev, 4);
	if (ret)
		return ret;

	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_CMD_READ | SDF_DIFF;
	s->n_chan	= 16;
	s->maxdata	= board->ai_maxdata;
	s->range_table	= &range_pcl816;
	s->insn_read	= pcl816_ai_insn_read;
	if (dev->irq) {
		dev->read_subdev = s;
		s->subdev_flags	|= SDF_CMD_READ;
		s->len_chanlist	= board->ai_chanlist;
		s->do_cmdtest	= pcl816_ai_cmdtest;
		s->do_cmd	= pcl816_ai_cmd;
		s->poll		= pcl816_ai_poll;
		s->cancel	= pcl816_ai_cancel;
	}

	/* Piggyback Slot1 subdevice */
	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_UNUSED;

	/* Digital Input subdevice */
	s = &dev->subdevices[2];
	s->type		= COMEDI_SUBD_DI;
	s->subdev_flags	= SDF_READABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= pcl816_di_insn_bits;

	/* Digital Output subdevice */
	s = &dev->subdevices[3];
	s->type		= COMEDI_SUBD_DO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= pcl816_do_insn_bits;

	pcl816_reset(dev);

	return 0;
}

__attribute__((used)) static void pcl816_detach(struct comedi_device *dev)
{
	if (dev->private) {
		pcl816_ai_cancel(dev, dev->read_subdev);
		pcl816_reset(dev);
	}
	pcl816_free_dma(dev);
	comedi_legacy_detach(dev);
}

