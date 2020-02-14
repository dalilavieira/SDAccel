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
struct mpc624_private {unsigned int ai_speed; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {unsigned int chanspec; int n; } ;
struct comedi_device {struct comedi_subdevice* subdevices; scalar_t__ iobase; int /*<<< orphan*/  class_dev; struct mpc624_private* private; } ;
struct comedi_devconfig {int* options; } ;
struct TYPE_11__ {TYPE_1__* range; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_2__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 unsigned char MPC624_ADBUSY ; 
 scalar_t__ MPC624_ADC ; 
 unsigned int MPC624_ADCS ; 
 unsigned int MPC624_ADSCK ; 
 unsigned int MPC624_ADSDI ; 
 int MPC624_ADSDO ; 
 unsigned int MPC624_DMY_BIT ; 
 unsigned int MPC624_EOC_BIT ; 
 scalar_t__ MPC624_GNMUXCH ; 
 unsigned int MPC624_SGN_BIT ; 
 unsigned int MPC624_SPEED_110_HZ ; 
 unsigned int MPC624_SPEED_13_75_HZ ; 
 unsigned int MPC624_SPEED_1_76_KHZ ; 
 unsigned int MPC624_SPEED_220_HZ ; 
 unsigned int MPC624_SPEED_27_5_HZ ; 
 void* MPC624_SPEED_3_52_KHZ ; 
 unsigned int MPC624_SPEED_440_HZ ; 
 unsigned int MPC624_SPEED_55_HZ ; 
 unsigned int MPC624_SPEED_6_875_HZ ; 
 unsigned int MPC624_SPEED_880_HZ ; 
 int RF_EXTERNAL ; 
 int SDF_DIFF ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 unsigned int TRIG_INVALID ; 
 struct mpc624_private* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int comedi_request_region (struct comedi_device*,int,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (unsigned int,scalar_t__) ; 
 TYPE_5__ range_mpc624_bipolar1 ; 
 TYPE_5__ range_mpc624_bipolar10 ; 
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

__attribute__((used)) static unsigned int mpc624_ai_get_sample(struct comedi_device *dev,
					 struct comedi_subdevice *s)
{
	struct mpc624_private *devpriv = dev->private;
	unsigned int data_out = devpriv->ai_speed;
	unsigned int data_in = 0;
	unsigned int bit;
	int i;

	/* Start reading data */
	udelay(1);
	for (i = 0; i < 32; i++) {
		/* Set the clock low */
		outb(0, dev->iobase + MPC624_ADC);
		udelay(1);

		/* Set the ADSDI line for the next bit (send to MPC624) */
		bit = (data_out & BIT(31)) ? MPC624_ADSDI : 0;
		outb(bit, dev->iobase + MPC624_ADC);
		udelay(1);

		/* Set the clock high */
		outb(MPC624_ADSCK | bit, dev->iobase + MPC624_ADC);
		udelay(1);

		/* Read ADSDO on high clock (receive from MPC624) */
		data_in <<= 1;
		data_in |= (inb(dev->iobase + MPC624_ADC) & MPC624_ADSDO) >> 4;
		udelay(1);

		data_out <<= 1;
	}

	/*
	 * Received 32-bit long value consist of:
	 *	31: EOC - (End Of Transmission) bit - should be 0
	 *	30: DMY - (Dummy) bit - should be 0
	 *	29: SIG - (Sign) bit - 1 if positive, 0 if negative
	 *	28: MSB - (Most Significant Bit) - the first bit of the
	 *					   conversion result
	 *	....
	 *	05: LSB - (Least Significant Bit)- the last bit of the
	 *					   conversion result
	 *	04-00: sub-LSB - sub-LSBs are basically noise, but when
	 *			 averaged properly, they can increase
	 *			 conversion precision up to 29 bits;
	 *			 they can be discarded without loss of
	 *			 resolution.
	 */
	if (data_in & MPC624_EOC_BIT)
		dev_dbg(dev->class_dev, "EOC bit is set!");
	if (data_in & MPC624_DMY_BIT)
		dev_dbg(dev->class_dev, "DMY bit is set!");

	if (data_in & MPC624_SGN_BIT) {
		/*
		 * Voltage is positive
		 *
		 * comedi operates on unsigned numbers, so mask off EOC
		 * and DMY and don't clear the SGN bit
		 */
		data_in &= 0x3fffffff;
	} else {
		/*
		 * The voltage is negative
		 *
		 * data_in contains a number in 30-bit two's complement
		 * code and we must deal with it
		 */
		data_in |= MPC624_SGN_BIT;
		data_in = ~data_in;
		data_in += 1;
		/* clear EOC and DMY bits */
		data_in &= ~(MPC624_EOC_BIT | MPC624_DMY_BIT);
		data_in = 0x20000000 - data_in;
	}
	return data_in;
}

__attribute__((used)) static int mpc624_ai_eoc(struct comedi_device *dev,
			 struct comedi_subdevice *s,
			 struct comedi_insn *insn,
			 unsigned long context)
{
	unsigned char status;

	status = inb(dev->iobase + MPC624_ADC);
	if ((status & MPC624_ADBUSY) == 0)
		return 0;
	return -EBUSY;
}

__attribute__((used)) static int mpc624_ai_insn_read(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	int ret;
	int i;

	/*
	 *  WARNING:
	 *  We always write 0 to GNSWA bit, so the channel range is +-/10.1Vdc
	 */
	outb(insn->chanspec, dev->iobase + MPC624_GNMUXCH);

	for (i = 0; i < insn->n; i++) {
		/*  Trigger the conversion */
		outb(MPC624_ADSCK, dev->iobase + MPC624_ADC);
		udelay(1);
		outb(MPC624_ADCS | MPC624_ADSCK, dev->iobase + MPC624_ADC);
		udelay(1);
		outb(0, dev->iobase + MPC624_ADC);
		udelay(1);

		/*  Wait for the conversion to end */
		ret = comedi_timeout(dev, s, insn, mpc624_ai_eoc, 0);
		if (ret)
			return ret;

		data[i] = mpc624_ai_get_sample(dev, s);
	}

	return insn->n;
}

__attribute__((used)) static int mpc624_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	struct mpc624_private *devpriv;
	struct comedi_subdevice *s;
	int ret;

	ret = comedi_request_region(dev, it->options[0], 0x10);
	if (ret)
		return ret;

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;

	switch (it->options[1]) {
	case 0:
		devpriv->ai_speed = MPC624_SPEED_3_52_KHZ;
		break;
	case 1:
		devpriv->ai_speed = MPC624_SPEED_1_76_KHZ;
		break;
	case 2:
		devpriv->ai_speed = MPC624_SPEED_880_HZ;
		break;
	case 3:
		devpriv->ai_speed = MPC624_SPEED_440_HZ;
		break;
	case 4:
		devpriv->ai_speed = MPC624_SPEED_220_HZ;
		break;
	case 5:
		devpriv->ai_speed = MPC624_SPEED_110_HZ;
		break;
	case 6:
		devpriv->ai_speed = MPC624_SPEED_55_HZ;
		break;
	case 7:
		devpriv->ai_speed = MPC624_SPEED_27_5_HZ;
		break;
	case 8:
		devpriv->ai_speed = MPC624_SPEED_13_75_HZ;
		break;
	case 9:
		devpriv->ai_speed = MPC624_SPEED_6_875_HZ;
		break;
	default:
		devpriv->ai_speed = MPC624_SPEED_3_52_KHZ;
	}

	ret = comedi_alloc_subdevices(dev, 1);
	if (ret)
		return ret;

	/* Analog Input subdevice */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_READABLE | SDF_DIFF;
	s->n_chan	= 4;
	s->maxdata	= 0x3fffffff;
	s->range_table	= (it->options[1] == 0) ? &range_mpc624_bipolar1
						: &range_mpc624_bipolar10;
	s->insn_read	= mpc624_ai_insn_read;

	return 0;
}

