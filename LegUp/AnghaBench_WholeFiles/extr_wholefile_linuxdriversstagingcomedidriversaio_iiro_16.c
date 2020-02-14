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
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int state; int n_chan; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int len_chanlist; int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; } ;
struct comedi_device {int irq; struct comedi_subdevice* read_subdev; struct comedi_subdevice* subdevices; scalar_t__ iobase; int /*<<< orphan*/  board_name; } ;
struct comedi_devconfig {int* options; } ;
struct comedi_cmd {unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int stop_src; unsigned int start_arg; unsigned int scan_begin_arg; unsigned int convert_arg; unsigned int scan_end_arg; unsigned int chanlist_len; unsigned int stop_arg; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {TYPE_1__* range; } ;
struct TYPE_9__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_8__ {TYPE_2__* range; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 scalar_t__ AIO_IIRO_16_INPUT_0_7 ; 
 scalar_t__ AIO_IIRO_16_INPUT_8_15 ; 
 scalar_t__ AIO_IIRO_16_IRQ ; 
 scalar_t__ AIO_IIRO_16_RELAY_0_7 ; 
 scalar_t__ AIO_IIRO_16_RELAY_8_15 ; 
 scalar_t__ AIO_IIRO_16_STATUS ; 
 unsigned int AIO_IIRO_16_STATUS_IRQE ; 
 int /*<<< orphan*/  COMEDI_SUBD_DI ; 
 int /*<<< orphan*/  COMEDI_SUBD_DO ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_FOLLOW ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned int*,int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int comedi_request_region (struct comedi_device*,int,int) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 TYPE_5__ range_digital ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct comedi_device*) ; 

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

__attribute__((used)) static unsigned int aio_iiro_16_read_inputs(struct comedi_device *dev)
{
	unsigned int val;

	val = inb(dev->iobase + AIO_IIRO_16_INPUT_0_7);
	val |= inb(dev->iobase + AIO_IIRO_16_INPUT_8_15) << 8;

	return val;
}

__attribute__((used)) static irqreturn_t aio_iiro_16_cos(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct comedi_subdevice *s = dev->read_subdev;
	unsigned int status;
	unsigned int val;

	status = inb(dev->iobase + AIO_IIRO_16_STATUS);
	if (!(status & AIO_IIRO_16_STATUS_IRQE))
		return IRQ_NONE;

	val = aio_iiro_16_read_inputs(dev);
	val |= (status << 16);

	comedi_buf_write_samples(s, &val, 1);
	comedi_handle_events(dev, s);

	return IRQ_HANDLED;
}

__attribute__((used)) static void aio_iiro_enable_irq(struct comedi_device *dev, bool enable)
{
	if (enable)
		inb(dev->iobase + AIO_IIRO_16_IRQ);
	else
		outb(0, dev->iobase + AIO_IIRO_16_IRQ);
}

__attribute__((used)) static int aio_iiro_16_cos_cancel(struct comedi_device *dev,
				  struct comedi_subdevice *s)
{
	aio_iiro_enable_irq(dev, false);

	return 0;
}

__attribute__((used)) static int aio_iiro_16_cos_cmd(struct comedi_device *dev,
			       struct comedi_subdevice *s)
{
	aio_iiro_enable_irq(dev, true);

	return 0;
}

__attribute__((used)) static int aio_iiro_16_cos_cmdtest(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_cmd *cmd)
{
	int err = 0;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
	err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */
	/* Step 2b : and mutually compatible */

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);
	err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* Step 4: fix up any arguments */

	/* Step 5: check channel list if it exists */

	return 0;
}

__attribute__((used)) static int aio_iiro_16_do_insn_bits(struct comedi_device *dev,
				    struct comedi_subdevice *s,
				    struct comedi_insn *insn,
				    unsigned int *data)
{
	if (comedi_dio_update_state(s, data)) {
		outb(s->state & 0xff, dev->iobase + AIO_IIRO_16_RELAY_0_7);
		outb((s->state >> 8) & 0xff,
		     dev->iobase + AIO_IIRO_16_RELAY_8_15);
	}

	data[1] = s->state;

	return insn->n;
}

__attribute__((used)) static int aio_iiro_16_di_insn_bits(struct comedi_device *dev,
				    struct comedi_subdevice *s,
				    struct comedi_insn *insn,
				    unsigned int *data)
{
	data[1] = aio_iiro_16_read_inputs(dev);

	return insn->n;
}

__attribute__((used)) static int aio_iiro_16_attach(struct comedi_device *dev,
			      struct comedi_devconfig *it)
{
	struct comedi_subdevice *s;
	int ret;

	ret = comedi_request_region(dev, it->options[0], 0x8);
	if (ret)
		return ret;

	aio_iiro_enable_irq(dev, false);

	/*
	 * Digital input change of state interrupts are optionally supported
	 * using IRQ 2-7, 10-12, 14, or 15.
	 */
	if ((1 << it->options[1]) & 0xdcfc) {
		ret = request_irq(it->options[1], aio_iiro_16_cos, 0,
				  dev->board_name, dev);
		if (ret == 0)
			dev->irq = it->options[1];
	}

	ret = comedi_alloc_subdevices(dev, 2);
	if (ret)
		return ret;

	/* Digital Output subdevice */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_DO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= aio_iiro_16_do_insn_bits;

	/* get the initial state of the relays */
	s->state = inb(dev->iobase + AIO_IIRO_16_RELAY_0_7) |
		   (inb(dev->iobase + AIO_IIRO_16_RELAY_8_15) << 8);

	/* Digital Input subdevice */
	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_DI;
	s->subdev_flags	= SDF_READABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= aio_iiro_16_di_insn_bits;
	if (dev->irq) {
		dev->read_subdev = s;
		s->subdev_flags	|= SDF_CMD_READ | SDF_LSAMPL;
		s->len_chanlist	= 1;
		s->do_cmdtest	= aio_iiro_16_cos_cmdtest;
		s->do_cmd	= aio_iiro_16_cos_cmd;
		s->cancel	= aio_iiro_16_cos_cancel;
	}

	return 0;
}

