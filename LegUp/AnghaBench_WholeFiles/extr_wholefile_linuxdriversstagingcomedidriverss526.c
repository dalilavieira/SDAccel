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
struct s526_private {unsigned int* gpct_config; unsigned int ai_ctrl; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; unsigned int* readback; unsigned int state; int io_bits; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int len_chanlist; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {struct comedi_subdevice* subdevices; scalar_t__ iobase; struct s526_private* private; } ;
struct comedi_devconfig {int /*<<< orphan*/ * options; } ;
struct TYPE_11__ {TYPE_1__* range; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_2__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_SUBD_AI ; 
 int /*<<< orphan*/  COMEDI_SUBD_AO ; 
 int /*<<< orphan*/  COMEDI_SUBD_COUNTER ; 
 int /*<<< orphan*/  COMEDI_SUBD_DIO ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR 130 
#define  INSN_CONFIG_GPCT_QUADRATURE_ENCODER 129 
#define  INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR 128 
 int RF_EXTERNAL ; 
 unsigned int S526_AI_CTRL_CONV (unsigned int) ; 
 unsigned int S526_AI_CTRL_DELAY ; 
 unsigned int S526_AI_CTRL_READ (unsigned int) ; 
 scalar_t__ S526_AI_CTRL_REG ; 
 unsigned int S526_AI_CTRL_START ; 
 scalar_t__ S526_AI_REG ; 
 unsigned int S526_AO_CTRL_CHAN (unsigned int) ; 
 scalar_t__ S526_AO_CTRL_REG ; 
 unsigned int S526_AO_CTRL_START ; 
 scalar_t__ S526_AO_REG ; 
 unsigned int S526_DIO_CTRL_GRP1_OUT ; 
 unsigned int S526_DIO_CTRL_GRP2_OUT ; 
 scalar_t__ S526_DIO_CTRL_REG ; 
 unsigned int S526_GPCT_CTRL_CT_RESET ; 
 scalar_t__ S526_GPCT_CTRL_REG (unsigned int) ; 
 scalar_t__ S526_GPCT_LSB_REG (unsigned int) ; 
 unsigned int S526_GPCT_MODE_AUTOLOAD_MASK ; 
 unsigned int S526_GPCT_MODE_AUTOLOAD_NONE ; 
 unsigned int S526_GPCT_MODE_PR_SELECT_MASK ; 
 unsigned int S526_GPCT_MODE_PR_SELECT_PR0 ; 
 unsigned int S526_GPCT_MODE_PR_SELECT_PR1 ; 
 scalar_t__ S526_GPCT_MODE_REG (unsigned int) ; 
 scalar_t__ S526_GPCT_MSB_REG (unsigned int) ; 
 int /*<<< orphan*/  S526_INT_AI ; 
 int /*<<< orphan*/  S526_INT_AO ; 
 scalar_t__ S526_INT_STATUS_REG ; 
 int SDF_DIFF ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_INVALID ; 
 struct s526_private* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdev_readback (struct comedi_subdevice*) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int comedi_dio_insn_config (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*,unsigned int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int comedi_request_region (struct comedi_device*,int /*<<< orphan*/ ,int) ; 
 int comedi_timeout (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,int (*) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned long),int /*<<< orphan*/ ) ; 
 int inw (scalar_t__) ; 
 int /*<<< orphan*/  outw (unsigned int,scalar_t__) ; 
 TYPE_5__ range_bipolar10 ; 
 TYPE_5__ range_digital ; 

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

__attribute__((used)) static void s526_gpct_write(struct comedi_device *dev,
			    unsigned int chan, unsigned int val)
{
	/* write high word then low word */
	outw((val >> 16) & 0xffff, dev->iobase + S526_GPCT_MSB_REG(chan));
	outw(val & 0xffff, dev->iobase + S526_GPCT_LSB_REG(chan));
}

__attribute__((used)) static unsigned int s526_gpct_read(struct comedi_device *dev,
				   unsigned int chan)
{
	unsigned int val;

	/* read the low word then high word */
	val = inw(dev->iobase + S526_GPCT_LSB_REG(chan)) & 0xffff;
	val |= (inw(dev->iobase + S526_GPCT_MSB_REG(chan)) & 0xff) << 16;

	return val;
}

__attribute__((used)) static int s526_gpct_rinsn(struct comedi_device *dev,
			   struct comedi_subdevice *s,
			   struct comedi_insn *insn,
			   unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	int i;

	for (i = 0; i < insn->n; i++)
		data[i] = s526_gpct_read(dev, chan);

	return insn->n;
}

__attribute__((used)) static int s526_gpct_insn_config(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn,
				 unsigned int *data)
{
	struct s526_private *devpriv = dev->private;
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val;

	/*
	 * Check what type of Counter the user requested
	 * data[0] contains the Application type
	 */
	switch (data[0]) {
	case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
		/*
		 * data[0]: Application Type
		 * data[1]: Counter Mode Register Value
		 * data[2]: Pre-load Register Value
		 * data[3]: Conter Control Register
		 */
		devpriv->gpct_config[chan] = data[0];

#if 1
		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/*  Reset the counter if it is software preload */
		if ((val & S526_GPCT_MODE_AUTOLOAD_MASK) ==
		    S526_GPCT_MODE_AUTOLOAD_NONE) {
			/*  Reset the counter */
			outw(S526_GPCT_CTRL_CT_RESET,
			     dev->iobase + S526_GPCT_CTRL_REG(chan));
			/*
			 * Load the counter from PR0
			 * outw(S526_GPCT_CTRL_CT_LOAD,
			 *      dev->iobase + S526_GPCT_CTRL_REG(chan));
			 */
		}
#else
		val = S526_GPCT_MODE_CTDIR_CTRL_QUAD;

		/*  data[1] contains GPCT_X1, GPCT_X2 or GPCT_X4 */
		if (data[1] == GPCT_X2)
			val |= S526_GPCT_MODE_CLK_SRC_QUADX2;
		else if (data[1] == GPCT_X4)
			val |= S526_GPCT_MODE_CLK_SRC_QUADX4;
		else
			val |= S526_GPCT_MODE_CLK_SRC_QUADX1;

		/*  When to take into account the indexpulse: */
		/*
		 * if (data[2] == GPCT_IndexPhaseLowLow) {
		 * } else if (data[2] == GPCT_IndexPhaseLowHigh) {
		 * } else if (data[2] == GPCT_IndexPhaseHighLow) {
		 * } else if (data[2] == GPCT_IndexPhaseHighHigh) {
		 * }
		 */
		/*  Take into account the index pulse? */
		if (data[3] == GPCT_RESET_COUNTER_ON_INDEX) {
			/*  Auto load with INDEX^ */
			val |= S526_GPCT_MODE_AUTOLOAD_IXRISE;
		}

		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/*  Load the pre-load register */
		s526_gpct_write(dev, chan, data[2]);

		/*  Write the Counter Control Register */
		if (data[3])
			outw(data[3] & 0xffff,
			     dev->iobase + S526_GPCT_CTRL_REG(chan));

		/*  Reset the counter if it is software preload */
		if ((val & S526_GPCT_MODE_AUTOLOAD_MASK) ==
		    S526_GPCT_MODE_AUTOLOAD_NONE) {
			/*  Reset the counter */
			outw(S526_GPCT_CTRL_CT_RESET,
			     dev->iobase + S526_GPCT_CTRL_REG(chan));
			/*  Load the counter from PR0 */
			outw(S526_GPCT_CTRL_CT_LOAD,
			     dev->iobase + S526_GPCT_CTRL_REG(chan));
		}
#endif
		break;

	case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
		/*
		 * data[0]: Application Type
		 * data[1]: Counter Mode Register Value
		 * data[2]: Pre-load Register 0 Value
		 * data[3]: Pre-load Register 1 Value
		 * data[4]: Conter Control Register
		 */
		devpriv->gpct_config[chan] = data[0];

		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		/* Select PR0 */
		val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
		val |= S526_GPCT_MODE_PR_SELECT_PR0;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/* Load the pre-load register 0 */
		s526_gpct_write(dev, chan, data[2]);

		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		/* Select PR1 */
		val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
		val |= S526_GPCT_MODE_PR_SELECT_PR1;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/* Load the pre-load register 1 */
		s526_gpct_write(dev, chan, data[3]);

		/*  Write the Counter Control Register */
		if (data[4]) {
			val = data[4] & 0xffff;
			outw(val, dev->iobase + S526_GPCT_CTRL_REG(chan));
		}
		break;

	case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
		/*
		 * data[0]: Application Type
		 * data[1]: Counter Mode Register Value
		 * data[2]: Pre-load Register 0 Value
		 * data[3]: Pre-load Register 1 Value
		 * data[4]: Conter Control Register
		 */
		devpriv->gpct_config[chan] = data[0];

		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		/* Select PR0 */
		val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
		val |= S526_GPCT_MODE_PR_SELECT_PR0;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/* Load the pre-load register 0 */
		s526_gpct_write(dev, chan, data[2]);

		/*  Set Counter Mode Register */
		val = data[1] & 0xffff;
		/* Select PR1 */
		val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
		val |= S526_GPCT_MODE_PR_SELECT_PR1;
		outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));

		/* Load the pre-load register 1 */
		s526_gpct_write(dev, chan, data[3]);

		/*  Write the Counter Control Register */
		if (data[4]) {
			val = data[4] & 0xffff;
			outw(val, dev->iobase + S526_GPCT_CTRL_REG(chan));
		}
		break;

	default:
		return -EINVAL;
	}

	return insn->n;
}

__attribute__((used)) static int s526_gpct_winsn(struct comedi_device *dev,
			   struct comedi_subdevice *s,
			   struct comedi_insn *insn,
			   unsigned int *data)
{
	struct s526_private *devpriv = dev->private;
	unsigned int chan = CR_CHAN(insn->chanspec);

	inw(dev->iobase + S526_GPCT_MODE_REG(chan));	/* Is this required? */

	/*  Check what Application of Counter this channel is configured for */
	switch (devpriv->gpct_config[chan]) {
	case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
		/*
		 * data[0] contains the PULSE_WIDTH
		 * data[1] contains the PULSE_PERIOD
		 * @pre PULSE_PERIOD > PULSE_WIDTH > 0
		 * The above periods must be expressed as a multiple of the
		 * pulse frequency on the selected source
		 */
		if ((data[1] <= data[0]) || !data[0])
			return -EINVAL;
		/* to write the PULSE_WIDTH */
		/* fall through */
	case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
	case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
		s526_gpct_write(dev, chan, data[0]);
		break;

	default:
		return -EINVAL;
	}

	return insn->n;
}

__attribute__((used)) static int s526_eoc(struct comedi_device *dev,
		    struct comedi_subdevice *s,
		    struct comedi_insn *insn,
		    unsigned long context)
{
	unsigned int status;

	status = inw(dev->iobase + S526_INT_STATUS_REG);
	if (status & context) {
		/* we got our eoc event, clear it */
		outw(context, dev->iobase + S526_INT_STATUS_REG);
		return 0;
	}
	return -EBUSY;
}

__attribute__((used)) static int s526_ai_insn_read(struct comedi_device *dev,
			     struct comedi_subdevice *s,
			     struct comedi_insn *insn,
			     unsigned int *data)
{
	struct s526_private *devpriv = dev->private;
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int ctrl;
	unsigned int val;
	int ret;
	int i;

	ctrl = S526_AI_CTRL_CONV(chan) | S526_AI_CTRL_READ(chan) |
	       S526_AI_CTRL_START;
	if (ctrl != devpriv->ai_ctrl) {
		/*
		 * The multiplexor needs to change, enable the 15us
		 * delay for the first sample.
		 */
		devpriv->ai_ctrl = ctrl;
		ctrl |= S526_AI_CTRL_DELAY;
	}

	for (i = 0; i < insn->n; i++) {
		/* trigger conversion */
		outw(ctrl, dev->iobase + S526_AI_CTRL_REG);
		ctrl &= ~S526_AI_CTRL_DELAY;

		/* wait for conversion to end */
		ret = comedi_timeout(dev, s, insn, s526_eoc, S526_INT_AI);
		if (ret)
			return ret;

		val = inw(dev->iobase + S526_AI_REG);
		data[i] = comedi_offset_munge(s, val);
	}

	return insn->n;
}

__attribute__((used)) static int s526_ao_insn_write(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int ctrl = S526_AO_CTRL_CHAN(chan);
	unsigned int val = s->readback[chan];
	int ret;
	int i;

	outw(ctrl, dev->iobase + S526_AO_CTRL_REG);
	ctrl |= S526_AO_CTRL_START;

	for (i = 0; i < insn->n; i++) {
		val = data[i];
		outw(val, dev->iobase + S526_AO_REG);
		outw(ctrl, dev->iobase + S526_AO_CTRL_REG);

		/* wait for conversion to end */
		ret = comedi_timeout(dev, s, insn, s526_eoc, S526_INT_AO);
		if (ret)
			return ret;
	}
	s->readback[chan] = val;

	return insn->n;
}

__attribute__((used)) static int s526_dio_insn_bits(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	if (comedi_dio_update_state(s, data))
		outw(s->state, dev->iobase + S526_DIO_CTRL_REG);

	data[1] = inw(dev->iobase + S526_DIO_CTRL_REG) & 0xff;

	return insn->n;
}

__attribute__((used)) static int s526_dio_insn_config(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int mask;
	int ret;

	/*
	 * Digital I/O can be configured as inputs or outputs in
	 * groups of 4; DIO group 1 (DIO0-3) and DIO group 2 (DIO4-7).
	 */
	if (chan < 4)
		mask = 0x0f;
	else
		mask = 0xf0;

	ret = comedi_dio_insn_config(dev, s, insn, data, mask);
	if (ret)
		return ret;

	if (s->io_bits & 0x0f)
		s->state |= S526_DIO_CTRL_GRP1_OUT;
	else
		s->state &= ~S526_DIO_CTRL_GRP1_OUT;
	if (s->io_bits & 0xf0)
		s->state |= S526_DIO_CTRL_GRP2_OUT;
	else
		s->state &= ~S526_DIO_CTRL_GRP2_OUT;

	outw(s->state, dev->iobase + S526_DIO_CTRL_REG);

	return insn->n;
}

__attribute__((used)) static int s526_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
	struct s526_private *devpriv;
	struct comedi_subdevice *s;
	int ret;

	ret = comedi_request_region(dev, it->options[0], 0x40);
	if (ret)
		return ret;

	devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
	if (!devpriv)
		return -ENOMEM;

	ret = comedi_alloc_subdevices(dev, 4);
	if (ret)
		return ret;

	/* General-Purpose Counter/Timer (GPCT) */
	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_COUNTER;
	s->subdev_flags	= SDF_READABLE | SDF_WRITABLE | SDF_LSAMPL;
	s->n_chan	= 4;
	s->maxdata	= 0x00ffffff;
	s->insn_read	= s526_gpct_rinsn;
	s->insn_config	= s526_gpct_insn_config;
	s->insn_write	= s526_gpct_winsn;

	/*
	 * Analog Input subdevice
	 * channels 0 to 7 are the regular differential inputs
	 * channel 8 is "reference 0" (+10V)
	 * channel 9 is "reference 1" (0V)
	 */
	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_AI;
	s->subdev_flags	= SDF_READABLE | SDF_DIFF;
	s->n_chan	= 10;
	s->maxdata	= 0xffff;
	s->range_table	= &range_bipolar10;
	s->len_chanlist	= 16;
	s->insn_read	= s526_ai_insn_read;

	/* Analog Output subdevice */
	s = &dev->subdevices[2];
	s->type		= COMEDI_SUBD_AO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 4;
	s->maxdata	= 0xffff;
	s->range_table	= &range_bipolar10;
	s->insn_write	= s526_ao_insn_write;

	ret = comedi_alloc_subdev_readback(s);
	if (ret)
		return ret;

	/* Digital I/O subdevice */
	s = &dev->subdevices[3];
	s->type		= COMEDI_SUBD_DIO;
	s->subdev_flags	= SDF_READABLE | SDF_WRITABLE;
	s->n_chan	= 8;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= s526_dio_insn_bits;
	s->insn_config	= s526_dio_insn_config;

	return 0;
}

