#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct TYPE_10__ {int expires; } ;
struct das16_private_struct {int ctrl_reg; int timer_running; int can_burst; scalar_t__ extra_iobase; struct comedi_isadma* dma; struct comedi_device* dev; TYPE_3__ timer; } ;
struct das16_board {unsigned int ai_pg; unsigned int ai_speed; int id; int size; unsigned int ai_maxdata; int /*<<< orphan*/  i8255_offset; scalar_t__ has_8255; scalar_t__ has_ao; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; unsigned int n_chan; unsigned int* readback; unsigned int state; int len_chanlist; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;void (* munge ) (struct comedi_device*,struct comedi_subdevice*,void*,unsigned int,unsigned int) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;struct comedi_lrange const* range_table; int /*<<< orphan*/  type; struct comedi_async* async; TYPE_2__** range_table_list; } ;
typedef  struct comedi_lrange {int length; struct comedi_krange* range; } const comedi_lrange ;
struct comedi_krange {scalar_t__ min; int flags; unsigned int max; } ;
struct comedi_isadma_desc {unsigned int maxsize; unsigned int size; unsigned int chan; int /*<<< orphan*/  virt_addr; } ;
struct comedi_isadma {size_t cur_dma; unsigned int chan; struct comedi_isadma_desc* desc; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {scalar_t__ iobase; struct das16_private_struct* private; struct das16_board* board_ptr; int /*<<< orphan*/  irq; struct comedi_subdevice* subdevices; struct comedi_subdevice* read_subdev; int /*<<< orphan*/  pacer; int /*<<< orphan*/  class_dev; int /*<<< orphan*/  spinlock; } ;
struct comedi_devconfig {unsigned int* options; } ;
struct comedi_cmd {unsigned int stop_src; scalar_t__ stop_arg; int chanlist_len; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int start_arg; unsigned int scan_begin_arg; unsigned int scan_end_arg; unsigned int convert_arg; unsigned int flags; int /*<<< orphan*/ * chanlist; } ;
struct comedi_async {unsigned int buf_write_count; unsigned int buf_read_count; scalar_t__ scans_done; struct comedi_cmd cmd; int /*<<< orphan*/  events; } ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_9__ {TYPE_1__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int CMDF_PRIORITY ; 
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 int /*<<< orphan*/  COMEDI_CB_ERROR ; 
 char COMEDI_ISADMA_READ ; 
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int /*<<< orphan*/  COMEDI_SUBD_AO ; 
 int /*<<< orphan*/  COMEDI_SUBD_DI ; 
 int /*<<< orphan*/  COMEDI_SUBD_DO ; 
 int /*<<< orphan*/  COMEDI_SUBD_UNUSED ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 unsigned int CR_RANGE (int /*<<< orphan*/ ) ; 
 scalar_t__ DAS1600_BURST_REG ; 
 unsigned int DAS1600_BURST_VAL ; 
 unsigned int DAS1600_CONV_DISABLE ; 
 scalar_t__ DAS1600_CONV_REG ; 
 scalar_t__ DAS1600_ENABLE_REG ; 
 unsigned int DAS1600_ENABLE_VAL ; 
 unsigned int DAS1600_STATUS_CLK_10MHZ ; 
 scalar_t__ DAS1600_STATUS_REG ; 
 scalar_t__ DAS16_AI_LSB_REG ; 
 scalar_t__ DAS16_AI_MSB_REG ; 
 scalar_t__ DAS16_AO_LSB_REG (unsigned int) ; 
 scalar_t__ DAS16_AO_MSB_REG (unsigned int) ; 
 int DAS16_CTRL_DMAE ; 
 int DAS16_CTRL_EXT_PACER ; 
 int DAS16_CTRL_INTE ; 
 int DAS16_CTRL_INT_PACER ; 
 unsigned int DAS16_CTRL_IRQ (int /*<<< orphan*/ ) ; 
 int DAS16_CTRL_PACING_MASK ; 
 scalar_t__ DAS16_CTRL_REG ; 
 scalar_t__ DAS16_DIO_REG ; 
 unsigned int DAS16_DMA_SIZE ; 
 scalar_t__ DAS16_GAIN_REG ; 
 scalar_t__ DAS16_MUX_REG ; 
 unsigned int DAS16_PACER_BURST_LEN (int) ; 
 scalar_t__ DAS16_PACER_REG ; 
 unsigned int DAS16_STATUS_BUSY ; 
 unsigned int DAS16_STATUS_MUXBIT ; 
 scalar_t__ DAS16_STATUS_REG ; 
 unsigned int DAS16_STATUS_UNIPOLAR ; 
 scalar_t__ DAS16_TIMER_BASE_REG ; 
 scalar_t__ DAS16_TRIG_REG ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int HZ ; 
 int /*<<< orphan*/  I8254_IO8 ; 
 unsigned int I8254_OSC_BASE_10MHZ ; 
 unsigned int I8254_OSC_BASE_1MHZ ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_DIFF ; 
 int SDF_GROUND ; 
 int SDF_LSAMPL ; 
 void* SDF_READABLE ; 
 void* SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_FOLLOW ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 unsigned int TRIG_TIMER ; 
 void* UNIT_volt ; 
 int __comedi_request_region (struct comedi_device*,scalar_t__,int) ; 
 int /*<<< orphan*/  add_timer (TYPE_3__*) ; 
 int /*<<< orphan*/  comedi_8254_cascade_ns_to_timer (int /*<<< orphan*/ ,unsigned int*,unsigned int) ; 
 int /*<<< orphan*/  comedi_8254_init (scalar_t__,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_8254_pacer_enable (int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  comedi_8254_update_divisors (int /*<<< orphan*/ ) ; 
 struct das16_private_struct* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 struct comedi_lrange const* comedi_alloc_spriv (struct comedi_subdevice*,int) ; 
 int comedi_alloc_subdev_readback (struct comedi_subdevice*) ; 
 int comedi_alloc_subdevices (struct comedi_device*,scalar_t__) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  comedi_legacy_detach (struct comedi_device*) ; 
 unsigned int comedi_nsamples_left (struct comedi_subdevice*,unsigned int) ; 
 int comedi_request_region (struct comedi_device*,int,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 struct comedi_lrange const** das16_ai_bip_lranges ; 
 struct comedi_lrange const** das16_ai_uni_lranges ; 
 unsigned int** das16_gainlists ; 
 unsigned int das16_pg_none ; 
 int /*<<< orphan*/  del_timer (TYPE_3__*) ; 
 int /*<<< orphan*/  del_timer_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 struct das16_private_struct* devpriv ; 
 struct das16_private_struct* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int jiffies ; 
 unsigned short le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod_timer (TYPE_3__*,int) ; 
 int /*<<< orphan*/  outb (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  outb_p (int /*<<< orphan*/ ,scalar_t__) ; 
 struct comedi_lrange const range_digital ; 
 struct comedi_lrange const range_unknown ; 
 int /*<<< orphan*/  release_region (scalar_t__,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int subdev_8255_init (struct comedi_device*,struct comedi_subdevice*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (TYPE_3__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static inline int timer_period(void)
{
	return HZ / 20;
}

__attribute__((used)) static void das16_ai_setup_dma(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       unsigned int unread_samples)
{
	struct das16_private_struct *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
	unsigned int max_samples = comedi_bytes_to_samples(s, desc->maxsize);
	unsigned int nsamples;

	/*
	 * Determine dma size based on the buffer size plus the number of
	 * unread samples and the number of samples remaining in the command.
	 */
	nsamples = comedi_nsamples_left(s, max_samples + unread_samples);
	if (nsamples > unread_samples) {
		nsamples -= unread_samples;
		desc->size = comedi_samples_to_bytes(s, nsamples);
		comedi_isadma_program(desc);
	}
}

__attribute__((used)) static void das16_interrupt(struct comedi_device *dev)
{
	struct das16_private_struct *devpriv = dev->private;
	struct comedi_subdevice *s = dev->read_subdev;
	struct comedi_async *async = s->async;
	struct comedi_cmd *cmd = &async->cmd;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
	unsigned long spin_flags;
	unsigned int residue;
	unsigned int nbytes;
	unsigned int nsamples;

	spin_lock_irqsave(&dev->spinlock, spin_flags);
	if (!(devpriv->ctrl_reg & DAS16_CTRL_DMAE)) {
		spin_unlock_irqrestore(&dev->spinlock, spin_flags);
		return;
	}

	/*
	 * The pc104-das16jr (at least) has problems if the dma
	 * transfer is interrupted in the middle of transferring
	 * a 16 bit sample.
	 */
	residue = comedi_isadma_disable_on_sample(desc->chan,
						  comedi_bytes_per_sample(s));

	/* figure out how many samples to read */
	if (residue > desc->size) {
		dev_err(dev->class_dev, "residue > transfer size!\n");
		async->events |= COMEDI_CB_ERROR;
		nbytes = 0;
	} else {
		nbytes = desc->size - residue;
	}
	nsamples = comedi_bytes_to_samples(s, nbytes);

	/* restart DMA if more samples are needed */
	if (nsamples) {
		dma->cur_dma = 1 - dma->cur_dma;
		das16_ai_setup_dma(dev, s, nsamples);
	}

	spin_unlock_irqrestore(&dev->spinlock, spin_flags);

	comedi_buf_write_samples(s, desc->virt_addr, nsamples);

	if (cmd->stop_src == TRIG_COUNT && async->scans_done >= cmd->stop_arg)
		async->events |= COMEDI_CB_EOA;

	comedi_handle_events(dev, s);
}

__attribute__((used)) static void das16_timer_interrupt(struct timer_list *t)
{
	struct das16_private_struct *devpriv = from_timer(devpriv, t, timer);
	struct comedi_device *dev = devpriv->dev;
	unsigned long flags;

	das16_interrupt(dev);

	spin_lock_irqsave(&dev->spinlock, flags);
	if (devpriv->timer_running)
		mod_timer(&devpriv->timer, jiffies + timer_period());
	spin_unlock_irqrestore(&dev->spinlock, flags);
}

__attribute__((used)) static void das16_ai_set_mux_range(struct comedi_device *dev,
				   unsigned int first_chan,
				   unsigned int last_chan,
				   unsigned int range)
{
	const struct das16_board *board = dev->board_ptr;

	/* set multiplexer */
	outb(first_chan | (last_chan << 4), dev->iobase + DAS16_MUX_REG);

	/* some boards do not have programmable gain */
	if (board->ai_pg == das16_pg_none)
		return;

	/*
	 * Set gain (this is also burst rate register but according to
	 * computer boards manual, burst rate does nothing, even on
	 * keithley cards).
	 */
	outb((das16_gainlists[board->ai_pg])[range],
	     dev->iobase + DAS16_GAIN_REG);
}

__attribute__((used)) static int das16_ai_check_chanlist(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_cmd *cmd)
{
	unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
	unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
	int i;

	for (i = 1; i < cmd->chanlist_len; i++) {
		unsigned int chan = CR_CHAN(cmd->chanlist[i]);
		unsigned int range = CR_RANGE(cmd->chanlist[i]);

		if (chan != ((chan0 + i) % s->n_chan)) {
			dev_dbg(dev->class_dev,
				"entries in chanlist must be consecutive channels, counting upwards\n");
			return -EINVAL;
		}

		if (range != range0) {
			dev_dbg(dev->class_dev,
				"entries in chanlist must all have the same gain\n");
			return -EINVAL;
		}
	}

	return 0;
}

__attribute__((used)) static int das16_cmd_test(struct comedi_device *dev, struct comedi_subdevice *s,
			  struct comedi_cmd *cmd)
{
	const struct das16_board *board = dev->board_ptr;
	struct das16_private_struct *devpriv = dev->private;
	int err = 0;
	unsigned int trig_mask;
	unsigned int arg;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);

	trig_mask = TRIG_FOLLOW;
	if (devpriv->can_burst)
		trig_mask |= TRIG_TIMER | TRIG_EXT;
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, trig_mask);

	trig_mask = TRIG_TIMER | TRIG_EXT;
	if (devpriv->can_burst)
		trig_mask |= TRIG_NOW;
	err |= comedi_check_trigger_src(&cmd->convert_src, trig_mask);

	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */

	err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
	err |= comedi_check_trigger_is_unique(cmd->convert_src);
	err |= comedi_check_trigger_is_unique(cmd->stop_src);

	/* Step 2b : and mutually compatible */

	/*  make sure scan_begin_src and convert_src don't conflict */
	if (cmd->scan_begin_src == TRIG_FOLLOW && cmd->convert_src == TRIG_NOW)
		err |= -EINVAL;
	if (cmd->scan_begin_src != TRIG_FOLLOW && cmd->convert_src != TRIG_NOW)
		err |= -EINVAL;

	if (err)
		return 2;

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);

	if (cmd->scan_begin_src == TRIG_FOLLOW)	/* internal trigger */
		err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);

	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);

	/* check against maximum frequency */
	if (cmd->scan_begin_src == TRIG_TIMER) {
		err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
						    board->ai_speed *
						    cmd->chanlist_len);
	}

	if (cmd->convert_src == TRIG_TIMER) {
		err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
						    board->ai_speed);
	}

	if (cmd->stop_src == TRIG_COUNT)
		err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
	else	/* TRIG_NONE */
		err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/*  step 4: fix up arguments */
	if (cmd->scan_begin_src == TRIG_TIMER) {
		arg = cmd->scan_begin_arg;
		comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
		err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
	}
	if (cmd->convert_src == TRIG_TIMER) {
		arg = cmd->convert_arg;
		comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
		err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
	}
	if (err)
		return 4;

	/* Step 5: check channel list if it exists */
	if (cmd->chanlist && cmd->chanlist_len > 0)
		err |= das16_ai_check_chanlist(dev, s, cmd);

	if (err)
		return 5;

	return 0;
}

__attribute__((used)) static unsigned int das16_set_pacer(struct comedi_device *dev, unsigned int ns,
				    unsigned int flags)
{
	comedi_8254_cascade_ns_to_timer(dev->pacer, &ns, flags);
	comedi_8254_update_divisors(dev->pacer);
	comedi_8254_pacer_enable(dev->pacer, 1, 2, true);

	return ns;
}

__attribute__((used)) static int das16_cmd_exec(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct das16_private_struct *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_async *async = s->async;
	struct comedi_cmd *cmd = &async->cmd;
	unsigned int first_chan = CR_CHAN(cmd->chanlist[0]);
	unsigned int last_chan = CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]);
	unsigned int range = CR_RANGE(cmd->chanlist[0]);
	unsigned int byte;
	unsigned long flags;

	if (cmd->flags & CMDF_PRIORITY) {
		dev_err(dev->class_dev,
			"isa dma transfers cannot be performed with CMDF_PRIORITY, aborting\n");
		return -1;
	}

	if (devpriv->can_burst)
		outb(DAS1600_CONV_DISABLE, dev->iobase + DAS1600_CONV_REG);

	/* set mux and range for chanlist scan */
	das16_ai_set_mux_range(dev, first_chan, last_chan, range);

	/* set counter mode and counts */
	cmd->convert_arg = das16_set_pacer(dev, cmd->convert_arg, cmd->flags);

	/* enable counters */
	byte = 0;
	if (devpriv->can_burst) {
		if (cmd->convert_src == TRIG_NOW) {
			outb(DAS1600_BURST_VAL,
			     dev->iobase + DAS1600_BURST_REG);
			/*  set burst length */
			byte |= DAS16_PACER_BURST_LEN(cmd->chanlist_len - 1);
		} else {
			outb(0, dev->iobase + DAS1600_BURST_REG);
		}
	}
	outb(byte, dev->iobase + DAS16_PACER_REG);

	/* set up dma transfer */
	dma->cur_dma = 0;
	das16_ai_setup_dma(dev, s, 0);

	/*  set up timer */
	spin_lock_irqsave(&dev->spinlock, flags);
	devpriv->timer_running = 1;
	devpriv->timer.expires = jiffies + timer_period();
	add_timer(&devpriv->timer);

	/* enable DMA interrupt with external or internal pacing */
	devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE | DAS16_CTRL_PACING_MASK);
	devpriv->ctrl_reg |= DAS16_CTRL_DMAE;
	if (cmd->convert_src == TRIG_EXT)
		devpriv->ctrl_reg |= DAS16_CTRL_EXT_PACER;
	else
		devpriv->ctrl_reg |= DAS16_CTRL_INT_PACER;
	outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);

	if (devpriv->can_burst)
		outb(0, dev->iobase + DAS1600_CONV_REG);
	spin_unlock_irqrestore(&dev->spinlock, flags);

	return 0;
}

__attribute__((used)) static int das16_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct das16_private_struct *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	unsigned long flags;

	spin_lock_irqsave(&dev->spinlock, flags);

	/* disable interrupts, dma and pacer clocked conversions */
	devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE | DAS16_CTRL_DMAE |
			       DAS16_CTRL_PACING_MASK);
	outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);

	comedi_isadma_disable(dma->chan);

	/*  disable SW timer */
	if (devpriv->timer_running) {
		devpriv->timer_running = 0;
		del_timer(&devpriv->timer);
	}

	if (devpriv->can_burst)
		outb(0, dev->iobase + DAS1600_BURST_REG);

	spin_unlock_irqrestore(&dev->spinlock, flags);

	return 0;
}

__attribute__((used)) static void das16_ai_munge(struct comedi_device *dev,
			   struct comedi_subdevice *s, void *array,
			   unsigned int num_bytes,
			   unsigned int start_chan_index)
{
	unsigned short *data = array;
	unsigned int num_samples = comedi_bytes_to_samples(s, num_bytes);
	unsigned int i;
	__le16 *buf = array;

	for (i = 0; i < num_samples; i++) {
		data[i] = le16_to_cpu(buf[i]);
		if (s->maxdata == 0x0fff)
			data[i] >>= 4;
		data[i] &= s->maxdata;
	}
}

__attribute__((used)) static int das16_ai_eoc(struct comedi_device *dev,
			struct comedi_subdevice *s,
			struct comedi_insn *insn,
			unsigned long context)
{
	unsigned int status;

	status = inb(dev->iobase + DAS16_STATUS_REG);
	if ((status & DAS16_STATUS_BUSY) == 0)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int das16_ai_insn_read(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int range = CR_RANGE(insn->chanspec);
	unsigned int val;
	int ret;
	int i;

	/* set mux and range for single channel */
	das16_ai_set_mux_range(dev, chan, chan, range);

	for (i = 0; i < insn->n; i++) {
		/* trigger conversion */
		outb_p(0, dev->iobase + DAS16_TRIG_REG);

		ret = comedi_timeout(dev, s, insn, das16_ai_eoc, 0);
		if (ret)
			return ret;

		val = inb(dev->iobase + DAS16_AI_MSB_REG) << 8;
		val |= inb(dev->iobase + DAS16_AI_LSB_REG);
		if (s->maxdata == 0x0fff)
			val >>= 4;
		val &= s->maxdata;

		data[i] = val;
	}

	return insn->n;
}

__attribute__((used)) static int das16_ao_insn_write(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	int i;

	for (i = 0; i < insn->n; i++) {
		unsigned int val = data[i];

		s->readback[chan] = val;

		val <<= 4;

		outb(val & 0xff, dev->iobase + DAS16_AO_LSB_REG(chan));
		outb((val >> 8) & 0xff, dev->iobase + DAS16_AO_MSB_REG(chan));
	}

	return insn->n;
}

__attribute__((used)) static int das16_di_insn_bits(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	data[1] = inb(dev->iobase + DAS16_DIO_REG) & 0xf;

	return insn->n;
}

__attribute__((used)) static int das16_do_insn_bits(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	if (comedi_dio_update_state(s, data))
		outb(s->state, dev->iobase + DAS16_DIO_REG);

	data[1] = s->state;

	return insn->n;
}

__attribute__((used)) static int das16_probe(struct comedi_device *dev, struct comedi_devconfig *it)
{
	const struct das16_board *board = dev->board_ptr;
	int diobits;

	/* diobits indicates boards */
	diobits = inb(dev->iobase + DAS16_DIO_REG) & 0xf0;
	if (board->id != diobits) {
		dev_err(dev->class_dev,
			"requested board's id bits are incorrect (0x%x != 0x%x)\n",
			board->id, diobits);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static void das16_reset(struct comedi_device *dev)
{
	outb(0, dev->iobase + DAS16_STATUS_REG);
	outb(0, dev->iobase + DAS16_CTRL_REG);
	outb(0, dev->iobase + DAS16_PACER_REG);
}

__attribute__((used)) static void das16_alloc_dma(struct comedi_device *dev, unsigned int dma_chan)
{
	struct das16_private_struct *devpriv = dev->private;

	timer_setup(&devpriv->timer, das16_timer_interrupt, 0);

	/* only DMA channels 3 and 1 are valid */
	if (!(dma_chan == 1 || dma_chan == 3))
		return;

	/* DMA uses two buffers */
	devpriv->dma = comedi_isadma_alloc(dev, 2, dma_chan, dma_chan,
					   DAS16_DMA_SIZE, COMEDI_ISADMA_READ);
}

__attribute__((used)) static void das16_free_dma(struct comedi_device *dev)
{
	struct das16_private_struct *devpriv = dev->private;

	if (devpriv) {
		del_timer_sync(&devpriv->timer);
		comedi_isadma_free(devpriv->dma);
	}
}

__attribute__((used)) static const struct comedi_lrange *das16_ai_range(struct comedi_device *dev,
						  struct comedi_subdevice *s,
						  struct comedi_devconfig *it,
						  unsigned int pg_type,
						  unsigned int status)
{
	unsigned int min = it->options[4];
	unsigned int max = it->options[5];

	/* get any user-defined input range */
	if (pg_type == das16_pg_none && (min || max)) {
		struct comedi_lrange *lrange;
		struct comedi_krange *krange;

		/* allocate single-range range table */
		lrange = comedi_alloc_spriv(s,
					    sizeof(*lrange) + sizeof(*krange));
		if (!lrange)
			return &range_unknown;

		/* initialize ai range */
		lrange->length = 1;
		krange = lrange->range;
		krange->min = min;
		krange->max = max;
		krange->flags = UNIT_volt;

		return lrange;
	}

	/* use software programmable range */
	if (status & DAS16_STATUS_UNIPOLAR)
		return das16_ai_uni_lranges[pg_type];
	return das16_ai_bip_lranges[pg_type];
}

__attribute__((used)) static const struct comedi_lrange *das16_ao_range(struct comedi_device *dev,
						  struct comedi_subdevice *s,
						  struct comedi_devconfig *it)
{
	unsigned int min = it->options[6];
	unsigned int max = it->options[7];

	/* get any user-defined output range */
	if (min || max) {
		struct comedi_lrange *lrange;
		struct comedi_krange *krange;

		/* allocate single-range range table */
		lrange = comedi_alloc_spriv(s,
					    sizeof(*lrange) + sizeof(*krange));
		if (!lrange)
			return &range_unknown;

		/* initialize ao range */
		lrange->length = 1;
		krange = lrange->range;
		krange->min = min;
		krange->max = max;
		krange->flags = UNIT_volt;

		return lrange;
	}

	return &range_unknown;
}

__attribute__((used)) static int das16_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	const struct das16_board *board = dev->board_ptr;
	struct das16_private_struct *devpriv;
	struct comedi_subdevice *s;
	unsigned int osc_base;
	unsigned int status;
	int ret;

	/*  check that clock setting is valid */
	if (it->options[3]) {
		if (it->options[3] != 1 && it->options[3] != 10) {
			dev_err(dev->class_dev,
				"Invalid option. Master clock must be set to 1 or 10 (MHz)\n");
			return -EINVAL;
		}
	}

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;
	devpriv->dev = dev;

	if (board->size < 0x400) {
		ret = comedi_request_region(dev, it->options[0], board->size);
		if (ret)
			return ret;
	} else {
		ret = comedi_request_region(dev, it->options[0], 0x10);
		if (ret)
			return ret;
		/* Request an additional region for the 8255 */
		ret = __comedi_request_region(dev, dev->iobase + 0x400,
					      board->size & 0x3ff);
		if (ret)
			return ret;
		devpriv->extra_iobase = dev->iobase + 0x400;
		devpriv->can_burst = 1;
	}

	/*  probe id bits to make sure they are consistent */
	if (das16_probe(dev, it))
		return -EINVAL;

	/*  get master clock speed */
	osc_base = I8254_OSC_BASE_1MHZ;
	if (devpriv->can_burst) {
		status = inb(dev->iobase + DAS1600_STATUS_REG);
		if (status & DAS1600_STATUS_CLK_10MHZ)
			osc_base = I8254_OSC_BASE_10MHZ;
	} else {
		if (it->options[3])
			osc_base = I8254_OSC_BASE_1MHZ / it->options[3];
	}

	dev->pacer = comedi_8254_init(dev->iobase + DAS16_TIMER_BASE_REG,
				      osc_base, I8254_IO8, 0);
	if (!dev->pacer)
		return -ENOMEM;

	das16_alloc_dma(dev, it->options[2]);

	ret = comedi_alloc_subdevices(dev, 4 + board->has_8255);
	if (ret)
		return ret;

	status = inb(dev->iobase + DAS16_STATUS_REG);

	/* Analog Input subdevice */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_READABLE;
	if (status & DAS16_STATUS_MUXBIT) {
		s->subdev_flags	|= SDF_GROUND;
		s->n_chan	= 16;
	} else {
		s->subdev_flags	|= SDF_DIFF;
		s->n_chan	= 8;
	}
	s->len_chanlist	= s->n_chan;
	s->maxdata	= board->ai_maxdata;
	s->range_table	= das16_ai_range(dev, s, it, board->ai_pg, status);
	s->insn_read	= das16_ai_insn_read;
	if (devpriv->dma) {
		dev->read_subdev = s;
		s->subdev_flags	|= SDF_CMD_READ;
		s->do_cmdtest	= das16_cmd_test;
		s->do_cmd	= das16_cmd_exec;
		s->cancel	= das16_cancel;
		s->munge	= das16_ai_munge;
	}

	/* Analog Output subdevice */
	s = &dev->subdevices[1];
	if (board->has_ao) {
		s->type		= COMEDI_SUBD_AO;
		s->subdev_flags	= SDF_WRITABLE;
		s->n_chan	= 2;
		s->maxdata	= 0x0fff;
		s->range_table	= das16_ao_range(dev, s, it);
		s->insn_write	= das16_ao_insn_write;

		ret = comedi_alloc_subdev_readback(s);
		if (ret)
			return ret;
	} else {
		s->type		= COMEDI_SUBD_UNUSED;
	}

	/* Digital Input subdevice */
	s = &dev->subdevices[2];
	s->type		= COMEDI_SUBD_DI;
	s->subdev_flags	= SDF_READABLE;
	s->n_chan	= 4;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= das16_di_insn_bits;

	/* Digital Output subdevice */
	s = &dev->subdevices[3];
	s->type		= COMEDI_SUBD_DO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 4;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= das16_do_insn_bits;

	/* initialize digital output lines */
	outb(s->state, dev->iobase + DAS16_DIO_REG);

	/* 8255 Digital I/O subdevice */
	if (board->has_8255) {
		s = &dev->subdevices[4];
		ret = subdev_8255_init(dev, s, NULL, board->i8255_offset);
		if (ret)
			return ret;
	}

	das16_reset(dev);
	/* set the interrupt level */
	devpriv->ctrl_reg = DAS16_CTRL_IRQ(dev->irq);
	outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);

	if (devpriv->can_burst) {
		outb(DAS1600_ENABLE_VAL, dev->iobase + DAS1600_ENABLE_REG);
		outb(0, dev->iobase + DAS1600_CONV_REG);
		outb(0, dev->iobase + DAS1600_BURST_REG);
	}

	return 0;
}

__attribute__((used)) static void das16_detach(struct comedi_device *dev)
{
	const struct das16_board *board = dev->board_ptr;
	struct das16_private_struct *devpriv = dev->private;

	if (devpriv) {
		if (dev->iobase)
			das16_reset(dev);
		das16_free_dma(dev);

		if (devpriv->extra_iobase)
			release_region(devpriv->extra_iobase,
				       board->size & 0x3ff);
	}

	comedi_legacy_detach(dev);
}

