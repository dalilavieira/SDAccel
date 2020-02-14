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
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; unsigned int n_chan; unsigned int* readback; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int len_chanlist; int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {unsigned int chanspec; int n; } ;
struct comedi_device {struct comedi_subdevice* subdevices; struct comedi_subdevice* read_subdev; scalar_t__ irq; int /*<<< orphan*/  board_name; int /*<<< orphan*/  class_dev; scalar_t__ iobase; int /*<<< orphan*/  attached; } ;
struct comedi_devconfig {scalar_t__* options; } ;
struct comedi_cmd {unsigned int* chanlist; int chanlist_len; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int stop_src; unsigned int start_arg; unsigned int scan_begin_arg; int convert_arg; unsigned int scan_end_arg; unsigned int stop_arg; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_11__ {TYPE_1__* range; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; scalar_t__ scans_done; int /*<<< orphan*/  events; struct comedi_cmd cmd; } ;
struct TYPE_9__ {TYPE_2__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int /*<<< orphan*/  COMEDI_SUBD_AO ; 
 unsigned int CR_CHAN (unsigned int) ; 
 unsigned int CR_RANGE (unsigned int) ; 
 int /*<<< orphan*/  DMM32AT_8255_IOBASE ; 
 scalar_t__ DMM32AT_AI_CFG_REG ; 
 scalar_t__ DMM32AT_AI_HI_CHAN_REG ; 
 scalar_t__ DMM32AT_AI_LO_CHAN_REG ; 
 scalar_t__ DMM32AT_AI_LSB_REG ; 
 scalar_t__ DMM32AT_AI_MSB_REG ; 
 scalar_t__ DMM32AT_AI_READBACK_REG ; 
 scalar_t__ DMM32AT_AI_START_CONV_REG ; 
 scalar_t__ DMM32AT_AI_STATUS_REG ; 
 unsigned char DMM32AT_AI_STATUS_SD0 ; 
 unsigned char DMM32AT_AI_STATUS_SD1 ; 
 unsigned char DMM32AT_AI_STATUS_STS ; 
 scalar_t__ DMM32AT_AO_LSB_REG ; 
 unsigned int DMM32AT_AO_MSB_DACH (unsigned int) ; 
 scalar_t__ DMM32AT_AO_MSB_REG ; 
 unsigned char DMM32AT_AUX_DI_DACBUSY ; 
 scalar_t__ DMM32AT_AUX_DI_REG ; 
 scalar_t__ DMM32AT_CLK1 ; 
 scalar_t__ DMM32AT_CLK2 ; 
 scalar_t__ DMM32AT_CLKCT ; 
 int DMM32AT_CLKCT1 ; 
 int DMM32AT_CLKCT2 ; 
 scalar_t__ DMM32AT_CTRDIO_CFG_REG ; 
 int DMM32AT_CTRL_INTRST ; 
 int DMM32AT_CTRL_PAGE_8254 ; 
 int DMM32AT_CTRL_PAGE_8255 ; 
 scalar_t__ DMM32AT_CTRL_REG ; 
 int DMM32AT_CTRL_RESETA ; 
 int DMM32AT_FIFO_CTRL_FIFORST ; 
 scalar_t__ DMM32AT_FIFO_CTRL_REG ; 
 int DMM32AT_FIFO_CTRL_SCANEN ; 
 unsigned char DMM32AT_FIFO_STATUS_EF ; 
 scalar_t__ DMM32AT_FIFO_STATUS_REG ; 
 unsigned char DMM32AT_INTCLK_ADINT ; 
 unsigned char DMM32AT_INTCLK_CLKEN ; 
 unsigned char DMM32AT_INTCLK_CLKSEL ; 
 scalar_t__ DMM32AT_INTCLK_REG ; 
 int DMM32AT_RANGE_U10 ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_DIFF ; 
 int SDF_GROUND ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 unsigned int TRIG_TIMER ; 
 int comedi_alloc_subdev_readback (struct comedi_subdevice*) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned int*,int) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int comedi_request_region (struct comedi_device*,scalar_t__,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 TYPE_5__ dmm32at_airanges ; 
 TYPE_5__ dmm32at_aoranges ; 
 int* dmm32at_rangebits ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct comedi_device*) ; 
 int subdev_8255_init (struct comedi_device*,struct comedi_subdevice*,int (*) (struct comedi_device*,int,int,int,unsigned long),int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static void dmm32at_ai_set_chanspec(struct comedi_device *dev,
				    struct comedi_subdevice *s,
				    unsigned int chanspec, int nchan)
{
	unsigned int chan = CR_CHAN(chanspec);
	unsigned int range = CR_RANGE(chanspec);
	unsigned int last_chan = (chan + nchan - 1) % s->n_chan;

	outb(DMM32AT_FIFO_CTRL_FIFORST, dev->iobase + DMM32AT_FIFO_CTRL_REG);

	if (nchan > 1)
		outb(DMM32AT_FIFO_CTRL_SCANEN,
		     dev->iobase + DMM32AT_FIFO_CTRL_REG);

	outb(chan, dev->iobase + DMM32AT_AI_LO_CHAN_REG);
	outb(last_chan, dev->iobase + DMM32AT_AI_HI_CHAN_REG);
	outb(dmm32at_rangebits[range], dev->iobase + DMM32AT_AI_CFG_REG);
}

__attribute__((used)) static unsigned int dmm32at_ai_get_sample(struct comedi_device *dev,
					  struct comedi_subdevice *s)
{
	unsigned int val;

	val = inb(dev->iobase + DMM32AT_AI_LSB_REG);
	val |= (inb(dev->iobase + DMM32AT_AI_MSB_REG) << 8);

	/* munge two's complement value to offset binary */
	return comedi_offset_munge(s, val);
}

__attribute__((used)) static int dmm32at_ai_status(struct comedi_device *dev,
			     struct comedi_subdevice *s,
			     struct comedi_insn *insn,
			     unsigned long context)
{
	unsigned char status;

	status = inb(dev->iobase + context);
	if ((status & DMM32AT_AI_STATUS_STS) == 0)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int dmm32at_ai_insn_read(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	int ret;
	int i;

	dmm32at_ai_set_chanspec(dev, s, insn->chanspec, 1);

	/* wait for circuit to settle */
	ret = comedi_timeout(dev, s, insn, dmm32at_ai_status,
			     DMM32AT_AI_READBACK_REG);
	if (ret)
		return ret;

	for (i = 0; i < insn->n; i++) {
		outb(0xff, dev->iobase + DMM32AT_AI_START_CONV_REG);

		ret = comedi_timeout(dev, s, insn, dmm32at_ai_status,
				     DMM32AT_AI_STATUS_REG);
		if (ret)
			return ret;

		data[i] = dmm32at_ai_get_sample(dev, s);
	}

	return insn->n;
}

__attribute__((used)) static int dmm32at_ai_check_chanlist(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     struct comedi_cmd *cmd)
{
	unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
	unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
	int i;

	for (i = 1; i < cmd->chanlist_len; i++) {
		unsigned int chan = CR_CHAN(cmd->chanlist[i]);
		unsigned int range = CR_RANGE(cmd->chanlist[i]);

		if (chan != (chan0 + i) % s->n_chan) {
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

__attribute__((used)) static int dmm32at_ai_cmdtest(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_cmd *cmd)
{
	int err = 0;
	unsigned int arg;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
	err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */

	err |= comedi_check_trigger_is_unique(cmd->stop_src);

	/* Step 2b : and mutually compatible */

	if (err)
		return 2;

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);

	err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg, 1000000);
	err |= comedi_check_trigger_arg_max(&cmd->scan_begin_arg, 1000000000);

	if (cmd->convert_arg >= 17500)
		cmd->convert_arg = 20000;
	else if (cmd->convert_arg >= 12500)
		cmd->convert_arg = 15000;
	else if (cmd->convert_arg >= 7500)
		cmd->convert_arg = 10000;
	else
		cmd->convert_arg = 5000;

	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);

	if (cmd->stop_src == TRIG_COUNT)
		err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
	else /* TRIG_NONE */
		err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* Step 4: fix up any arguments */

	arg = cmd->convert_arg * cmd->scan_end_arg;
	err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg, arg);

	if (err)
		return 4;

	/* Step 5: check channel list if it exists */
	if (cmd->chanlist && cmd->chanlist_len > 0)
		err |= dmm32at_ai_check_chanlist(dev, s, cmd);

	if (err)
		return 5;

	return 0;
}

__attribute__((used)) static void dmm32at_setaitimer(struct comedi_device *dev, unsigned int nansec)
{
	unsigned char lo1, lo2, hi2;
	unsigned short both2;

	/* based on 10mhz clock */
	lo1 = 200;
	both2 = nansec / 20000;
	hi2 = (both2 & 0xff00) >> 8;
	lo2 = both2 & 0x00ff;

	/* set counter clocks to 10MHz, disable all aux dio */
	outb(0, dev->iobase + DMM32AT_CTRDIO_CFG_REG);

	/* get access to the clock regs */
	outb(DMM32AT_CTRL_PAGE_8254, dev->iobase + DMM32AT_CTRL_REG);

	/* write the counter 1 control word and low byte to counter */
	outb(DMM32AT_CLKCT1, dev->iobase + DMM32AT_CLKCT);
	outb(lo1, dev->iobase + DMM32AT_CLK1);

	/* write the counter 2 control word and low byte then to counter */
	outb(DMM32AT_CLKCT2, dev->iobase + DMM32AT_CLKCT);
	outb(lo2, dev->iobase + DMM32AT_CLK2);
	outb(hi2, dev->iobase + DMM32AT_CLK2);

	/* enable the ai conversion interrupt and the clock to start scans */
	outb(DMM32AT_INTCLK_ADINT |
	     DMM32AT_INTCLK_CLKEN | DMM32AT_INTCLK_CLKSEL,
	     dev->iobase + DMM32AT_INTCLK_REG);
}

__attribute__((used)) static int dmm32at_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
	struct comedi_cmd *cmd = &s->async->cmd;
	int ret;

	dmm32at_ai_set_chanspec(dev, s, cmd->chanlist[0], cmd->chanlist_len);

	/* reset the interrupt just in case */
	outb(DMM32AT_CTRL_INTRST, dev->iobase + DMM32AT_CTRL_REG);

	/*
	 * wait for circuit to settle
	 * we don't have the 'insn' here but it's not needed
	 */
	ret = comedi_timeout(dev, s, NULL, dmm32at_ai_status,
			     DMM32AT_AI_READBACK_REG);
	if (ret)
		return ret;

	if (cmd->stop_src == TRIG_NONE || cmd->stop_arg > 1) {
		/* start the clock and enable the interrupts */
		dmm32at_setaitimer(dev, cmd->scan_begin_arg);
	} else {
		/* start the interrupts and initiate a single scan */
		outb(DMM32AT_INTCLK_ADINT, dev->iobase + DMM32AT_INTCLK_REG);
		outb(0xff, dev->iobase + DMM32AT_AI_START_CONV_REG);
	}

	return 0;
}

__attribute__((used)) static int dmm32at_ai_cancel(struct comedi_device *dev,
			     struct comedi_subdevice *s)
{
	/* disable further interrupts and clocks */
	outb(0x0, dev->iobase + DMM32AT_INTCLK_REG);
	return 0;
}

__attribute__((used)) static irqreturn_t dmm32at_isr(int irq, void *d)
{
	struct comedi_device *dev = d;
	unsigned char intstat;
	unsigned int val;
	int i;

	if (!dev->attached) {
		dev_err(dev->class_dev, "spurious interrupt\n");
		return IRQ_HANDLED;
	}

	intstat = inb(dev->iobase + DMM32AT_INTCLK_REG);

	if (intstat & DMM32AT_INTCLK_ADINT) {
		struct comedi_subdevice *s = dev->read_subdev;
		struct comedi_cmd *cmd = &s->async->cmd;

		for (i = 0; i < cmd->chanlist_len; i++) {
			val = dmm32at_ai_get_sample(dev, s);
			comedi_buf_write_samples(s, &val, 1);
		}

		if (cmd->stop_src == TRIG_COUNT &&
		    s->async->scans_done >= cmd->stop_arg)
			s->async->events |= COMEDI_CB_EOA;

		comedi_handle_events(dev, s);
	}

	/* reset the interrupt */
	outb(DMM32AT_CTRL_INTRST, dev->iobase + DMM32AT_CTRL_REG);
	return IRQ_HANDLED;
}

__attribute__((used)) static int dmm32at_ao_eoc(struct comedi_device *dev,
			  struct comedi_subdevice *s,
			  struct comedi_insn *insn,
			  unsigned long context)
{
	unsigned char status;

	status = inb(dev->iobase + DMM32AT_AUX_DI_REG);
	if ((status & DMM32AT_AUX_DI_DACBUSY) == 0)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int dmm32at_ao_insn_write(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn,
				 unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	int i;

	for (i = 0; i < insn->n; i++) {
		unsigned int val = data[i];
		int ret;

		/* write LSB then MSB + chan to load DAC */
		outb(val & 0xff, dev->iobase + DMM32AT_AO_LSB_REG);
		outb((val >> 8) | DMM32AT_AO_MSB_DACH(chan),
		     dev->iobase + DMM32AT_AO_MSB_REG);

		/* wait for circuit to settle */
		ret = comedi_timeout(dev, s, insn, dmm32at_ao_eoc, 0);
		if (ret)
			return ret;

		/* dummy read to update DAC */
		inb(dev->iobase + DMM32AT_AO_MSB_REG);

		s->readback[chan] = val;
	}

	return insn->n;
}

__attribute__((used)) static int dmm32at_8255_io(struct comedi_device *dev,
			   int dir, int port, int data, unsigned long regbase)
{
	/* get access to the DIO regs */
	outb(DMM32AT_CTRL_PAGE_8255, dev->iobase + DMM32AT_CTRL_REG);

	if (dir) {
		outb(data, dev->iobase + regbase + port);
		return 0;
	}
	return inb(dev->iobase + regbase + port);
}

__attribute__((used)) static int dmm32at_reset(struct comedi_device *dev)
{
	unsigned char aihi, ailo, fifostat, aistat, intstat, airback;

	/* reset the board */
	outb(DMM32AT_CTRL_RESETA, dev->iobase + DMM32AT_CTRL_REG);

	/* allow a millisecond to reset */
	usleep_range(1000, 3000);

	/* zero scan and fifo control */
	outb(0x0, dev->iobase + DMM32AT_FIFO_CTRL_REG);

	/* zero interrupt and clock control */
	outb(0x0, dev->iobase + DMM32AT_INTCLK_REG);

	/* write a test channel range, the high 3 bits should drop */
	outb(0x80, dev->iobase + DMM32AT_AI_LO_CHAN_REG);
	outb(0xff, dev->iobase + DMM32AT_AI_HI_CHAN_REG);

	/* set the range at 10v unipolar */
	outb(DMM32AT_RANGE_U10, dev->iobase + DMM32AT_AI_CFG_REG);

	/* should take 10 us to settle, here's a hundred */
	usleep_range(100, 200);

	/* read back the values */
	ailo = inb(dev->iobase + DMM32AT_AI_LO_CHAN_REG);
	aihi = inb(dev->iobase + DMM32AT_AI_HI_CHAN_REG);
	fifostat = inb(dev->iobase + DMM32AT_FIFO_STATUS_REG);
	aistat = inb(dev->iobase + DMM32AT_AI_STATUS_REG);
	intstat = inb(dev->iobase + DMM32AT_INTCLK_REG);
	airback = inb(dev->iobase + DMM32AT_AI_READBACK_REG);

	/*
	 * NOTE: The (DMM32AT_AI_STATUS_SD1 | DMM32AT_AI_STATUS_SD0)
	 * test makes this driver only work if the board is configured
	 * with all A/D channels set for single-ended operation.
	 */
	if (ailo != 0x00 || aihi != 0x1f ||
	    fifostat != DMM32AT_FIFO_STATUS_EF ||
	    aistat != (DMM32AT_AI_STATUS_SD1 | DMM32AT_AI_STATUS_SD0) ||
	    intstat != 0x00 || airback != 0x0c)
		return -EIO;

	return 0;
}

__attribute__((used)) static int dmm32at_attach(struct comedi_device *dev,
			  struct comedi_devconfig *it)
{
	struct comedi_subdevice *s;
	int ret;

	ret = comedi_request_region(dev, it->options[0], 0x10);
	if (ret)
		return ret;

	ret = dmm32at_reset(dev);
	if (ret) {
		dev_err(dev->class_dev, "board detection failed\n");
		return ret;
	}

	if (it->options[1]) {
		ret = request_irq(it->options[1], dmm32at_isr, 0,
				  dev->board_name, dev);
		if (ret == 0)
			dev->irq = it->options[1];
	}

	ret = comedi_alloc_subdevices(dev, 3);
	if (ret)
		return ret;

	/* Analog Input subdevice */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_READABLE | SDF_GROUND | SDF_DIFF;
	s->n_chan	= 32;
	s->maxdata	= 0xffff;
	s->range_table	= &dmm32at_airanges;
	s->insn_read	= dmm32at_ai_insn_read;
	if (dev->irq) {
		dev->read_subdev = s;
		s->subdev_flags	|= SDF_CMD_READ;
		s->len_chanlist	= s->n_chan;
		s->do_cmd	= dmm32at_ai_cmd;
		s->do_cmdtest	= dmm32at_ai_cmdtest;
		s->cancel	= dmm32at_ai_cancel;
	}

	/* Analog Output subdevice */
	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_AO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 4;
	s->maxdata	= 0x0fff;
	s->range_table	= &dmm32at_aoranges;
	s->insn_write	= dmm32at_ao_insn_write;

	ret = comedi_alloc_subdev_readback(s);
	if (ret)
		return ret;

	/* Digital I/O subdevice */
	s = &dev->subdevices[2];
	return subdev_8255_init(dev, s, dmm32at_8255_io, DMM32AT_8255_IOBASE);
}

