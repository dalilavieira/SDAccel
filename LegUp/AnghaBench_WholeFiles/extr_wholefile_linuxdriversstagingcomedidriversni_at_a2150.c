#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int len_chanlist; int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;TYPE_4__* range_table; int /*<<< orphan*/  type; struct comedi_async* async; TYPE_3__** range_table_list; } ;
struct comedi_isadma_desc {unsigned short* virt_addr; unsigned int chan; unsigned int size; int maxsize; } ;
struct comedi_isadma {struct comedi_isadma_desc* desc; } ;
struct comedi_insn {unsigned int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {unsigned int irq; scalar_t__ iobase; int /*<<< orphan*/  class_dev; struct comedi_subdevice* read_subdev; struct comedi_subdevice* subdevices; int /*<<< orphan*/  pacer; int /*<<< orphan*/  board_name; struct a2150_board const* board_ptr; struct a2150_private* private; int /*<<< orphan*/  attached; } ;
struct comedi_devconfig {unsigned int* options; } ;
struct comedi_cmd {unsigned int stop_src; int chanlist_len; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int start_arg; unsigned int convert_arg; unsigned int scan_end_arg; unsigned int stop_arg; unsigned int scan_begin_arg; unsigned int flags; int /*<<< orphan*/ * chanlist; } ;
struct comedi_async {unsigned int buf_write_count; unsigned int buf_read_count; struct comedi_cmd cmd; int /*<<< orphan*/  events; } ;
struct a2150_private {unsigned int count; int irq_dma_bits; unsigned int config_bits; struct comedi_isadma* dma; } ;
typedef  struct a2150_board {int* clock; int num_clocks; unsigned int ai_speed; int /*<<< orphan*/  name; } const a2150_board ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_8__ {TYPE_1__* range; } ;
struct TYPE_7__ {TYPE_2__* range; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;
struct TYPE_5__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 unsigned int A2150_DMA_BUFFER_SIZE ; 
 unsigned int AC0_BIT ; 
 unsigned int AC1_BIT ; 
 unsigned int APD_BIT ; 
 scalar_t__ AREF_OTHER ; 
 int ARRAY_SIZE (struct a2150_board const*) ; 
 int CHANNEL_BITS (int) ; 
 int CHANNEL_MASK ; 
 int CLOCK_DIVISOR_BITS (int) ; 
 unsigned int CLOCK_MASK ; 
 int CLOCK_SELECT_BITS (int) ; 
 int CMDF_PRIORITY ; 
#define  CMDF_ROUND_DOWN 130 
 unsigned int CMDF_ROUND_MASK ; 
#define  CMDF_ROUND_NEAREST 129 
#define  CMDF_ROUND_UP 128 
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 int /*<<< orphan*/  COMEDI_CB_ERROR ; 
 char COMEDI_ISADMA_READ ; 
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 scalar_t__ CONFIG_REG ; 
 scalar_t__ CR_AREF (int /*<<< orphan*/ ) ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 int DCAL_BIT ; 
 unsigned int DELAY_TRIGGER_BITS ; 
 int DMA_CHAN_BITS (unsigned int) ; 
 int DMA_EN_BIT ; 
 int DMA_INTR_EN_BIT ; 
 int DMA_TC_BIT ; 
 scalar_t__ DMA_TC_CLEAR_REG ; 
 unsigned int DPD_BIT ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENABLE0_BIT ; 
 int ENABLE1_BIT ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETIME ; 
 scalar_t__ FIFO_DATA_REG ; 
 scalar_t__ FIFO_RESET_REG ; 
 scalar_t__ FIFO_START_REG ; 
 unsigned int FNE_BIT ; 
 unsigned int HW_TRIG_EN ; 
 scalar_t__ I8253_BASE_REG ; 
 int I8254_BINARY ; 
 int /*<<< orphan*/  I8254_IO8 ; 
 int I8254_MODE0 ; 
 int ID_BITS (int) ; 
 int INTR_BIT ; 
 scalar_t__ IRQ_DMA_CNTRL_REG ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int IRQ_LVL_BITS (unsigned int) ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int OVFL_BIT ; 
 unsigned int POST_TRIGGER_BITS ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_GROUND ; 
 int SDF_LSAMPL ; 
 int SDF_OTHER ; 
 int SDF_READABLE ; 
 scalar_t__ STATUS_REG ; 
 scalar_t__ TRIGGER_REG ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 unsigned int TRIG_OTHER ; 
 unsigned int TRIG_TIMER ; 
 struct a2150_board const* a2150_boards ; 
 int /*<<< orphan*/  comedi_8254_init (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_8254_load (int /*<<< orphan*/ ,int,int,int) ; 
 struct a2150_private* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned short*,int) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  comedi_legacy_detach (struct comedi_device*) ; 
 int comedi_request_region (struct comedi_device*,unsigned int,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free_irq (unsigned int,struct comedi_device*) ; 
 int inw (scalar_t__) ; 
 int /*<<< orphan*/  outw (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  outw_p (unsigned int,scalar_t__) ; 
 TYPE_4__ range_a2150 ; 
 scalar_t__ request_irq (unsigned int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct comedi_device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

__attribute__((used)) static irqreturn_t a2150_interrupt(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct a2150_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[0];
	struct comedi_subdevice *s = dev->read_subdev;
	struct comedi_async *async = s->async;
	struct comedi_cmd *cmd = &async->cmd;
	unsigned short *buf = desc->virt_addr;
	unsigned int max_points, num_points, residue, leftover;
	unsigned short dpnt;
	int status;
	int i;

	if (!dev->attached)
		return IRQ_HANDLED;

	status = inw(dev->iobase + STATUS_REG);
	if ((status & INTR_BIT) == 0)
		return IRQ_NONE;

	if (status & OVFL_BIT) {
		async->events |= COMEDI_CB_ERROR;
		comedi_handle_events(dev, s);
	}

	if ((status & DMA_TC_BIT) == 0) {
		async->events |= COMEDI_CB_ERROR;
		comedi_handle_events(dev, s);
		return IRQ_HANDLED;
	}

	/*
	 * residue is the number of bytes left to be done on the dma
	 * transfer.  It should always be zero at this point unless
	 * the stop_src is set to external triggering.
	 */
	residue = comedi_isadma_disable(desc->chan);

	/* figure out how many points to read */
	max_points = comedi_bytes_to_samples(s, desc->size);
	num_points = max_points - comedi_bytes_to_samples(s, residue);
	if (devpriv->count < num_points && cmd->stop_src == TRIG_COUNT)
		num_points = devpriv->count;

	/* figure out how many points will be stored next time */
	leftover = 0;
	if (cmd->stop_src == TRIG_NONE) {
		leftover = comedi_bytes_to_samples(s, desc->size);
	} else if (devpriv->count > max_points) {
		leftover = devpriv->count - max_points;
		if (leftover > max_points)
			leftover = max_points;
	}
	/*
	 * There should only be a residue if collection was stopped by having
	 * the stop_src set to an external trigger, in which case there
	 * will be no more data
	 */
	if (residue)
		leftover = 0;

	for (i = 0; i < num_points; i++) {
		/* write data point to comedi buffer */
		dpnt = buf[i];
		/* convert from 2's complement to unsigned coding */
		dpnt ^= 0x8000;
		comedi_buf_write_samples(s, &dpnt, 1);
		if (cmd->stop_src == TRIG_COUNT) {
			if (--devpriv->count == 0) {	/* end of acquisition */
				async->events |= COMEDI_CB_EOA;
				break;
			}
		}
	}
	/* re-enable dma */
	if (leftover) {
		desc->size = comedi_samples_to_bytes(s, leftover);
		comedi_isadma_program(desc);
	}

	comedi_handle_events(dev, s);

	/* clear interrupt */
	outw(0x00, dev->iobase + DMA_TC_CLEAR_REG);

	return IRQ_HANDLED;
}

__attribute__((used)) static int a2150_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct a2150_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[0];

	/* disable dma on card */
	devpriv->irq_dma_bits &= ~DMA_INTR_EN_BIT & ~DMA_EN_BIT;
	outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);

	/* disable computer's dma */
	comedi_isadma_disable(desc->chan);

	/* clear fifo and reset triggering circuitry */
	outw(0, dev->iobase + FIFO_RESET_REG);

	return 0;
}

__attribute__((used)) static int a2150_get_timing(struct comedi_device *dev, unsigned int *period,
			    unsigned int flags)
{
	const struct a2150_board *board = dev->board_ptr;
	struct a2150_private *devpriv = dev->private;
	int lub, glb, temp;
	int lub_divisor_shift, lub_index, glb_divisor_shift, glb_index;
	int i, j;

	/* initialize greatest lower and least upper bounds */
	lub_divisor_shift = 3;
	lub_index = 0;
	lub = board->clock[lub_index] * (1 << lub_divisor_shift);
	glb_divisor_shift = 0;
	glb_index = board->num_clocks - 1;
	glb = board->clock[glb_index] * (1 << glb_divisor_shift);

	/* make sure period is in available range */
	if (*period < glb)
		*period = glb;
	if (*period > lub)
		*period = lub;

	/* we can multiply period by 1, 2, 4, or 8, using (1 << i) */
	for (i = 0; i < 4; i++) {
		/* there are a maximum of 4 master clocks */
		for (j = 0; j < board->num_clocks; j++) {
			/* temp is the period in nanosec we are evaluating */
			temp = board->clock[j] * (1 << i);
			/* if it is the best match yet */
			if (temp < lub && temp >= *period) {
				lub_divisor_shift = i;
				lub_index = j;
				lub = temp;
			}
			if (temp > glb && temp <= *period) {
				glb_divisor_shift = i;
				glb_index = j;
				glb = temp;
			}
		}
	}
	switch (flags & CMDF_ROUND_MASK) {
	case CMDF_ROUND_NEAREST:
	default:
		/* if least upper bound is better approximation */
		if (lub - *period < *period - glb)
			*period = lub;
		else
			*period = glb;
		break;
	case CMDF_ROUND_UP:
		*period = lub;
		break;
	case CMDF_ROUND_DOWN:
		*period = glb;
		break;
	}

	/* set clock bits for config register appropriately */
	devpriv->config_bits &= ~CLOCK_MASK;
	if (*period == lub) {
		devpriv->config_bits |=
		    CLOCK_SELECT_BITS(lub_index) |
		    CLOCK_DIVISOR_BITS(lub_divisor_shift);
	} else {
		devpriv->config_bits |=
		    CLOCK_SELECT_BITS(glb_index) |
		    CLOCK_DIVISOR_BITS(glb_divisor_shift);
	}

	return 0;
}

__attribute__((used)) static int a2150_set_chanlist(struct comedi_device *dev,
			      unsigned int start_channel,
			      unsigned int num_channels)
{
	struct a2150_private *devpriv = dev->private;

	if (start_channel + num_channels > 4)
		return -1;

	devpriv->config_bits &= ~CHANNEL_MASK;

	switch (num_channels) {
	case 1:
		devpriv->config_bits |= CHANNEL_BITS(0x4 | start_channel);
		break;
	case 2:
		if (start_channel == 0)
			devpriv->config_bits |= CHANNEL_BITS(0x2);
		else if (start_channel == 2)
			devpriv->config_bits |= CHANNEL_BITS(0x3);
		else
			return -1;
		break;
	case 4:
		devpriv->config_bits |= CHANNEL_BITS(0x1);
		break;
	default:
		return -1;
	}

	return 0;
}

__attribute__((used)) static int a2150_ai_check_chanlist(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_cmd *cmd)
{
	unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
	unsigned int aref0 = CR_AREF(cmd->chanlist[0]);
	int i;

	if (cmd->chanlist_len == 2 && (chan0 == 1 || chan0 == 3)) {
		dev_dbg(dev->class_dev,
			"length 2 chanlist must be channels 0,1 or channels 2,3\n");
		return -EINVAL;
	}

	if (cmd->chanlist_len == 3) {
		dev_dbg(dev->class_dev,
			"chanlist must have 1,2 or 4 channels\n");
		return -EINVAL;
	}

	for (i = 1; i < cmd->chanlist_len; i++) {
		unsigned int chan = CR_CHAN(cmd->chanlist[i]);
		unsigned int aref = CR_AREF(cmd->chanlist[i]);

		if (chan != (chan0 + i)) {
			dev_dbg(dev->class_dev,
				"entries in chanlist must be consecutive channels, counting upwards\n");
			return -EINVAL;
		}

		if (chan == 2)
			aref0 = aref;
		if (aref != aref0) {
			dev_dbg(dev->class_dev,
				"channels 0/1 and 2/3 must have the same analog reference\n");
			return -EINVAL;
		}
	}

	return 0;
}

__attribute__((used)) static int a2150_ai_cmdtest(struct comedi_device *dev,
			    struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
	const struct a2150_board *board = dev->board_ptr;
	int err = 0;
	unsigned int arg;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
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

	if (cmd->convert_src == TRIG_TIMER) {
		err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
						    board->ai_speed);
	}

	err |= comedi_check_trigger_arg_min(&cmd->chanlist_len, 1);
	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);

	if (cmd->stop_src == TRIG_COUNT)
		err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
	else	/* TRIG_NONE */
		err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* step 4: fix up any arguments */

	if (cmd->scan_begin_src == TRIG_TIMER) {
		arg = cmd->scan_begin_arg;
		a2150_get_timing(dev, &arg, cmd->flags);
		err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
	}

	if (err)
		return 4;

	/* Step 5: check channel list if it exists */
	if (cmd->chanlist && cmd->chanlist_len > 0)
		err |= a2150_ai_check_chanlist(dev, s, cmd);

	if (err)
		return 5;

	return 0;
}

__attribute__((used)) static int a2150_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct a2150_private *devpriv = dev->private;
	struct comedi_isadma *dma = devpriv->dma;
	struct comedi_isadma_desc *desc = &dma->desc[0];
	struct comedi_async *async = s->async;
	struct comedi_cmd *cmd = &async->cmd;
	unsigned int old_config_bits = devpriv->config_bits;
	unsigned int trigger_bits;

	if (cmd->flags & CMDF_PRIORITY) {
		dev_err(dev->class_dev,
			"dma incompatible with hard real-time interrupt (CMDF_PRIORITY), aborting\n");
		return -1;
	}
	/* clear fifo and reset triggering circuitry */
	outw(0, dev->iobase + FIFO_RESET_REG);

	/* setup chanlist */
	if (a2150_set_chanlist(dev, CR_CHAN(cmd->chanlist[0]),
			       cmd->chanlist_len) < 0)
		return -1;

	/* setup ac/dc coupling */
	if (CR_AREF(cmd->chanlist[0]) == AREF_OTHER)
		devpriv->config_bits |= AC0_BIT;
	else
		devpriv->config_bits &= ~AC0_BIT;
	if (CR_AREF(cmd->chanlist[2]) == AREF_OTHER)
		devpriv->config_bits |= AC1_BIT;
	else
		devpriv->config_bits &= ~AC1_BIT;

	/* setup timing */
	a2150_get_timing(dev, &cmd->scan_begin_arg, cmd->flags);

	/* send timing, channel, config bits */
	outw(devpriv->config_bits, dev->iobase + CONFIG_REG);

	/* initialize number of samples remaining */
	devpriv->count = cmd->stop_arg * cmd->chanlist_len;

	comedi_isadma_disable(desc->chan);

	/* set size of transfer to fill in 1/3 second */
#define ONE_THIRD_SECOND 333333333
	desc->size = comedi_bytes_per_sample(s) * cmd->chanlist_len *
		    ONE_THIRD_SECOND / cmd->scan_begin_arg;
	if (desc->size > desc->maxsize)
		desc->size = desc->maxsize;
	if (desc->size < comedi_bytes_per_sample(s))
		desc->size = comedi_bytes_per_sample(s);
	desc->size -= desc->size % comedi_bytes_per_sample(s);

	comedi_isadma_program(desc);

	/*
	 * Clear dma interrupt before enabling it, to try and get rid of
	 * that one spurious interrupt that has been happening.
	 */
	outw(0x00, dev->iobase + DMA_TC_CLEAR_REG);

	/* enable dma on card */
	devpriv->irq_dma_bits |= DMA_INTR_EN_BIT | DMA_EN_BIT;
	outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);

	/* may need to wait 72 sampling periods if timing was changed */
	comedi_8254_load(dev->pacer, 2, 72, I8254_MODE0 | I8254_BINARY);

	/* setup start triggering */
	trigger_bits = 0;
	/* decide if we need to wait 72 periods for valid data */
	if (cmd->start_src == TRIG_NOW &&
	    (old_config_bits & CLOCK_MASK) !=
	    (devpriv->config_bits & CLOCK_MASK)) {
		/* set trigger source to delay trigger */
		trigger_bits |= DELAY_TRIGGER_BITS;
	} else {
		/* otherwise no delay */
		trigger_bits |= POST_TRIGGER_BITS;
	}
	/* enable external hardware trigger */
	if (cmd->start_src == TRIG_EXT) {
		trigger_bits |= HW_TRIG_EN;
	} else if (cmd->start_src == TRIG_OTHER) {
		/*
		 * XXX add support for level/slope start trigger
		 * using TRIG_OTHER
		 */
		dev_err(dev->class_dev, "you shouldn't see this?\n");
	}
	/* send trigger config bits */
	outw(trigger_bits, dev->iobase + TRIGGER_REG);

	/* start acquisition for soft trigger */
	if (cmd->start_src == TRIG_NOW)
		outw(0, dev->iobase + FIFO_START_REG);

	return 0;
}

__attribute__((used)) static int a2150_ai_eoc(struct comedi_device *dev,
			struct comedi_subdevice *s,
			struct comedi_insn *insn,
			unsigned long context)
{
	unsigned int status;

	status = inw(dev->iobase + STATUS_REG);
	if (status & FNE_BIT)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int a2150_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
			  struct comedi_insn *insn, unsigned int *data)
{
	struct a2150_private *devpriv = dev->private;
	unsigned int n;
	int ret;

	/* clear fifo and reset triggering circuitry */
	outw(0, dev->iobase + FIFO_RESET_REG);

	/* setup chanlist */
	if (a2150_set_chanlist(dev, CR_CHAN(insn->chanspec), 1) < 0)
		return -1;

	/* set dc coupling */
	devpriv->config_bits &= ~AC0_BIT;
	devpriv->config_bits &= ~AC1_BIT;

	/* send timing, channel, config bits */
	outw(devpriv->config_bits, dev->iobase + CONFIG_REG);

	/* disable dma on card */
	devpriv->irq_dma_bits &= ~DMA_INTR_EN_BIT & ~DMA_EN_BIT;
	outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);

	/* setup start triggering */
	outw(0, dev->iobase + TRIGGER_REG);

	/* start acquisition for soft trigger */
	outw(0, dev->iobase + FIFO_START_REG);

	/*
	 * there is a 35.6 sample delay for data to get through the
	 * antialias filter
	 */
	for (n = 0; n < 36; n++) {
		ret = comedi_timeout(dev, s, insn, a2150_ai_eoc, 0);
		if (ret)
			return ret;

		inw(dev->iobase + FIFO_DATA_REG);
	}

	/* read data */
	for (n = 0; n < insn->n; n++) {
		ret = comedi_timeout(dev, s, insn, a2150_ai_eoc, 0);
		if (ret)
			return ret;

		data[n] = inw(dev->iobase + FIFO_DATA_REG);
		data[n] ^= 0x8000;
	}

	/* clear fifo and reset triggering circuitry */
	outw(0, dev->iobase + FIFO_RESET_REG);

	return n;
}

__attribute__((used)) static void a2150_alloc_irq_and_dma(struct comedi_device *dev,
				    struct comedi_devconfig *it)
{
	struct a2150_private *devpriv = dev->private;
	unsigned int irq_num = it->options[1];
	unsigned int dma_chan = it->options[2];

	/*
	 * Only IRQs 15, 14, 12-9, and 7-3 are valid.
	 * Only DMA channels 7-5 and 3-0 are valid.
	 */
	if (irq_num > 15 || dma_chan > 7 ||
	    !((1 << irq_num) & 0xdef8) || !((1 << dma_chan) & 0xef))
		return;

	if (request_irq(irq_num, a2150_interrupt, 0, dev->board_name, dev))
		return;

	/* DMA uses 1 buffer */
	devpriv->dma = comedi_isadma_alloc(dev, 1, dma_chan, dma_chan,
					   A2150_DMA_BUFFER_SIZE,
					   COMEDI_ISADMA_READ);
	if (!devpriv->dma) {
		free_irq(irq_num, dev);
	} else {
		dev->irq = irq_num;
		devpriv->irq_dma_bits = IRQ_LVL_BITS(irq_num) |
					DMA_CHAN_BITS(dma_chan);
	}
}

__attribute__((used)) static void a2150_free_dma(struct comedi_device *dev)
{
	struct a2150_private *devpriv = dev->private;

	if (devpriv)
		comedi_isadma_free(devpriv->dma);
}

__attribute__((used)) static const struct a2150_board *a2150_probe(struct comedi_device *dev)
{
	int id = ID_BITS(inw(dev->iobase + STATUS_REG));

	if (id >= ARRAY_SIZE(a2150_boards))
		return NULL;

	return &a2150_boards[id];
}

__attribute__((used)) static int a2150_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	const struct a2150_board *board;
	struct a2150_private *devpriv;
	struct comedi_subdevice *s;
	static const int timeout = 2000;
	int i;
	int ret;

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;

	ret = comedi_request_region(dev, it->options[0], 0x1c);
	if (ret)
		return ret;

	board = a2150_probe(dev);
	if (!board)
		return -ENODEV;
	dev->board_ptr = board;
	dev->board_name = board->name;

	/* an IRQ and DMA are required to support async commands */
	a2150_alloc_irq_and_dma(dev, it);

	dev->pacer = comedi_8254_init(dev->iobase + I8253_BASE_REG,
				      0, I8254_IO8, 0);
	if (!dev->pacer)
		return -ENOMEM;

	ret = comedi_alloc_subdevices(dev, 1);
	if (ret)
		return ret;

	/* analog input subdevice */
	s = &dev->subdevices[0];
	s->type = COMEDI_SUBD_AI;
	s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_OTHER;
	s->n_chan = 4;
	s->maxdata = 0xffff;
	s->range_table = &range_a2150;
	s->insn_read = a2150_ai_rinsn;
	if (dev->irq) {
		dev->read_subdev = s;
		s->subdev_flags |= SDF_CMD_READ;
		s->len_chanlist = s->n_chan;
		s->do_cmd = a2150_ai_cmd;
		s->do_cmdtest = a2150_ai_cmdtest;
		s->cancel = a2150_cancel;
	}

	/* set card's irq and dma levels */
	outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);

	/* reset and sync adc clock circuitry */
	outw_p(DPD_BIT | APD_BIT, dev->iobase + CONFIG_REG);
	outw_p(DPD_BIT, dev->iobase + CONFIG_REG);
	/* initialize configuration register */
	devpriv->config_bits = 0;
	outw(devpriv->config_bits, dev->iobase + CONFIG_REG);
	/* wait until offset calibration is done, then enable analog inputs */
	for (i = 0; i < timeout; i++) {
		if ((DCAL_BIT & inw(dev->iobase + STATUS_REG)) == 0)
			break;
		usleep_range(1000, 3000);
	}
	if (i == timeout) {
		dev_err(dev->class_dev,
			"timed out waiting for offset calibration to complete\n");
		return -ETIME;
	}
	devpriv->config_bits |= ENABLE0_BIT | ENABLE1_BIT;
	outw(devpriv->config_bits, dev->iobase + CONFIG_REG);

	return 0;
}

__attribute__((used)) static void a2150_detach(struct comedi_device *dev)
{
	if (dev->iobase)
		outw(APD_BIT | DPD_BIT, dev->iobase + CONFIG_REG);
	a2150_free_dma(dev);
	comedi_legacy_detach(dev);
}

