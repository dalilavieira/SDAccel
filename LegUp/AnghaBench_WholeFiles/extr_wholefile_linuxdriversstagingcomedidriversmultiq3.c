#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; unsigned int* readback; unsigned int state; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_3__* async; TYPE_2__** range_table_list; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {struct comedi_subdevice* subdevices; scalar_t__ iobase; } ;
struct comedi_devconfig {int* options; } ;
struct TYPE_12__ {TYPE_4__* range; } ;
struct TYPE_11__ {scalar_t__ min; int flags; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_1__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int /*<<< orphan*/  COMEDI_SUBD_AO ; 
 int /*<<< orphan*/  COMEDI_SUBD_COUNTER ; 
 int /*<<< orphan*/  COMEDI_SUBD_DI ; 
 int /*<<< orphan*/  COMEDI_SUBD_DO ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
#define  INSN_CONFIG_RESET 128 
 scalar_t__ MULTIQ3_AI_CONV_REG ; 
 scalar_t__ MULTIQ3_AI_REG ; 
 scalar_t__ MULTIQ3_AO_REG ; 
 int /*<<< orphan*/  MULTIQ3_BP_RESET ; 
 int /*<<< orphan*/  MULTIQ3_CLOCK_DATA ; 
 int /*<<< orphan*/  MULTIQ3_CLOCK_SETUP ; 
 int /*<<< orphan*/  MULTIQ3_CNTR_RESET ; 
 unsigned int MULTIQ3_CTRL_AI_CHAN (unsigned int) ; 
 unsigned int MULTIQ3_CTRL_AO_CHAN (unsigned int) ; 
 unsigned int MULTIQ3_CTRL_CLK ; 
 unsigned int MULTIQ3_CTRL_EN ; 
 unsigned int MULTIQ3_CTRL_E_CHAN (unsigned int) ; 
 unsigned int MULTIQ3_CTRL_LD ; 
 scalar_t__ MULTIQ3_CTRL_REG ; 
 unsigned int MULTIQ3_CTRL_SH ; 
 scalar_t__ MULTIQ3_DI_REG ; 
 scalar_t__ MULTIQ3_DO_REG ; 
 int /*<<< orphan*/  MULTIQ3_EFLAG_RESET ; 
 scalar_t__ MULTIQ3_ENC_CTRL_REG ; 
 scalar_t__ MULTIQ3_ENC_DATA_REG ; 
 int /*<<< orphan*/  MULTIQ3_INPUT_SETUP ; 
 int /*<<< orphan*/  MULTIQ3_QUAD_X4 ; 
 int /*<<< orphan*/  MULTIQ3_STATUS_EOC ; 
 int /*<<< orphan*/  MULTIQ3_STATUS_EOC_I ; 
 scalar_t__ MULTIQ3_STATUS_REG ; 
 int /*<<< orphan*/  MULTIQ3_TRSFRCNTR_OL ; 
 int RF_EXTERNAL ; 
 int SDF_GROUND ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 void* SDF_WRITABLE ; 
 unsigned int TRIG_INVALID ; 
 int comedi_alloc_subdev_readback (struct comedi_subdevice*) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int comedi_request_region (struct comedi_device*,int,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 unsigned int inw (scalar_t__) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  outw (unsigned int,scalar_t__) ; 
 TYPE_5__ range_bipolar5 ; 
 TYPE_5__ range_digital ; 
 TYPE_5__ range_unknown ; 

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

__attribute__((used)) static void multiq3_set_ctrl(struct comedi_device *dev, unsigned int bits)
{
	/*
	 * According to the programming manual, the SH and CLK bits should
	 * be kept high at all times.
	 */
	outw(MULTIQ3_CTRL_SH | MULTIQ3_CTRL_CLK | bits,
	     dev->iobase + MULTIQ3_CTRL_REG);
}

__attribute__((used)) static int multiq3_ai_status(struct comedi_device *dev,
			     struct comedi_subdevice *s,
			     struct comedi_insn *insn,
			     unsigned long context)
{
	unsigned int status;

	status = inw(dev->iobase + MULTIQ3_STATUS_REG);
	if (status & context)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int multiq3_ai_insn_read(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val;
	int ret;
	int i;

	multiq3_set_ctrl(dev, MULTIQ3_CTRL_EN | MULTIQ3_CTRL_AI_CHAN(chan));

	ret = comedi_timeout(dev, s, insn, multiq3_ai_status,
			     MULTIQ3_STATUS_EOC);
	if (ret)
		return ret;

	for (i = 0; i < insn->n; i++) {
		outw(0, dev->iobase + MULTIQ3_AI_CONV_REG);

		ret = comedi_timeout(dev, s, insn, multiq3_ai_status,
				     MULTIQ3_STATUS_EOC_I);
		if (ret)
			return ret;

		/* get a 16-bit sample; mask it to the subdevice resolution */
		val = inb(dev->iobase + MULTIQ3_AI_REG) << 8;
		val |= inb(dev->iobase + MULTIQ3_AI_REG);
		val &= s->maxdata;

		/* munge the 2's complement value to offset binary */
		data[i] = comedi_offset_munge(s, val);
	}

	return insn->n;
}

__attribute__((used)) static int multiq3_ao_insn_write(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn,
				 unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val = s->readback[chan];
	int i;

	for (i = 0; i < insn->n; i++) {
		val = data[i];
		multiq3_set_ctrl(dev, MULTIQ3_CTRL_LD |
				      MULTIQ3_CTRL_AO_CHAN(chan));
		outw(val, dev->iobase + MULTIQ3_AO_REG);
		multiq3_set_ctrl(dev, 0);
	}
	s->readback[chan] = val;

	return insn->n;
}

__attribute__((used)) static int multiq3_di_insn_bits(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn, unsigned int *data)
{
	data[1] = inw(dev->iobase + MULTIQ3_DI_REG);

	return insn->n;
}

__attribute__((used)) static int multiq3_do_insn_bits(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	if (comedi_dio_update_state(s, data))
		outw(s->state, dev->iobase + MULTIQ3_DO_REG);

	data[1] = s->state;

	return insn->n;
}

__attribute__((used)) static int multiq3_encoder_insn_read(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     struct comedi_insn *insn,
				     unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val;
	int i;

	for (i = 0; i < insn->n; i++) {
		/* select encoder channel */
		multiq3_set_ctrl(dev, MULTIQ3_CTRL_EN |
				      MULTIQ3_CTRL_E_CHAN(chan));

		/* reset the byte pointer */
		outb(MULTIQ3_BP_RESET, dev->iobase + MULTIQ3_ENC_CTRL_REG);

		/* latch the data */
		outb(MULTIQ3_TRSFRCNTR_OL, dev->iobase + MULTIQ3_ENC_CTRL_REG);

		/* read the 24-bit encoder data (lsb/mid/msb) */
		val = inb(dev->iobase + MULTIQ3_ENC_DATA_REG);
		val |= (inb(dev->iobase + MULTIQ3_ENC_DATA_REG) << 8);
		val |= (inb(dev->iobase + MULTIQ3_ENC_DATA_REG) << 16);

		/*
		 * Munge the data so that the reset value is in the middle
		 * of the maxdata range, i.e.:
		 *
		 * real value	comedi value
		 * 0xffffff	0x7fffff	1 negative count
		 * 0x000000	0x800000	reset value
		 * 0x000001	0x800001	1 positive count
		 *
		 * It's possible for the 24-bit counter to overflow but it
		 * would normally take _quite_ a few turns. A 2000 line
		 * encoder in quadrature results in 8000 counts/rev. So about
		 * 1048 turns in either direction can be measured without
		 * an overflow.
		 */
		data[i] = (val + ((s->maxdata + 1) >> 1)) & s->maxdata;
	}

	return insn->n;
}

__attribute__((used)) static void multiq3_encoder_reset(struct comedi_device *dev,
				  unsigned int chan)
{
	multiq3_set_ctrl(dev, MULTIQ3_CTRL_EN | MULTIQ3_CTRL_E_CHAN(chan));
	outb(MULTIQ3_EFLAG_RESET, dev->iobase + MULTIQ3_ENC_CTRL_REG);
	outb(MULTIQ3_BP_RESET, dev->iobase + MULTIQ3_ENC_CTRL_REG);
	outb(MULTIQ3_CLOCK_DATA, dev->iobase + MULTIQ3_ENC_DATA_REG);
	outb(MULTIQ3_CLOCK_SETUP, dev->iobase + MULTIQ3_ENC_CTRL_REG);
	outb(MULTIQ3_INPUT_SETUP, dev->iobase + MULTIQ3_ENC_CTRL_REG);
	outb(MULTIQ3_QUAD_X4, dev->iobase + MULTIQ3_ENC_CTRL_REG);
	outb(MULTIQ3_CNTR_RESET, dev->iobase + MULTIQ3_ENC_CTRL_REG);
}

__attribute__((used)) static int multiq3_encoder_insn_config(struct comedi_device *dev,
				       struct comedi_subdevice *s,
				       struct comedi_insn *insn,
				       unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);

	switch (data[0]) {
	case INSN_CONFIG_RESET:
		multiq3_encoder_reset(dev, chan);
		break;
	default:
		return -EINVAL;
	}

	return insn->n;
}

__attribute__((used)) static int multiq3_attach(struct comedi_device *dev,
			  struct comedi_devconfig *it)
{
	struct comedi_subdevice *s;
	int ret;
	int i;

	ret = comedi_request_region(dev, it->options[0], 0x10);
	if (ret)
		return ret;

	ret = comedi_alloc_subdevices(dev, 5);
	if (ret)
		return ret;

	/* Analog Input subdevice */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_READABLE | SDF_GROUND;
	s->n_chan	= 8;
	s->maxdata	= 0x1fff;
	s->range_table	= &range_bipolar5;
	s->insn_read	= multiq3_ai_insn_read;

	/* Analog Output subdevice */
	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_AO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 8;
	s->maxdata	= 0x0fff;
	s->range_table	= &range_bipolar5;
	s->insn_write	= multiq3_ao_insn_write;

	ret = comedi_alloc_subdev_readback(s);
	if (ret)
		return ret;

	/* Digital Input subdevice */
	s = &dev->subdevices[2];
	s->type		= COMEDI_SUBD_DI;
	s->subdev_flags	= SDF_READABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= multiq3_di_insn_bits;

	/* Digital Output subdevice */
	s = &dev->subdevices[3];
	s->type		= COMEDI_SUBD_DO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 16;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= multiq3_do_insn_bits;

	/* Encoder (Counter) subdevice */
	s = &dev->subdevices[4];
	s->type		= COMEDI_SUBD_COUNTER;
	s->subdev_flags	= SDF_READABLE | SDF_LSAMPL;
	s->n_chan	= it->options[2] * 2;
	s->maxdata	= 0x00ffffff;
	s->range_table	= &range_unknown;
	s->insn_read	= multiq3_encoder_insn_read;
	s->insn_config	= multiq3_encoder_insn_config;

	for (i = 0; i < s->n_chan; i++)
		multiq3_encoder_reset(dev, i);

	return 0;
}

