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
struct pci_device_id {int /*<<< orphan*/  driver_data; } ;
struct pci_dev {int dummy; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int state; int n_chan; int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {scalar_t__ iobase; struct comedi_subdevice* subdevices; } ;
struct TYPE_11__ {TYPE_1__* range; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_2__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_SUBD_COUNTER ; 
 int /*<<< orphan*/  COMEDI_SUBD_DO ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  INSN_CONFIG_GET_CLOCK_SRC 136 
#define  INSN_CONFIG_RESET 135 
#define  INSN_CONFIG_SET_CLOCK_SRC 134 
#define  KE_CLK_20MHZ 133 
#define  KE_CLK_4MHZ 132 
#define  KE_CLK_EXT 131 
 scalar_t__ KE_DO_REG ; 
 scalar_t__ KE_LATCH_REG (unsigned int) ; 
 scalar_t__ KE_LSB_REG (unsigned int) ; 
 scalar_t__ KE_MID_REG (unsigned int) ; 
 scalar_t__ KE_MSB_REG (unsigned int) ; 
#define  KE_OSC_SEL_20MHZ 130 
#define  KE_OSC_SEL_4MHZ 129 
#define  KE_OSC_SEL_EXT 128 
 scalar_t__ KE_OSC_SEL_REG ; 
 scalar_t__ KE_RESET_REG (unsigned int) ; 
 scalar_t__ KE_SIGN_REG (unsigned int) ; 
 int RF_EXTERNAL ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_INVALID ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int comedi_pci_auto_config (struct pci_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int comedi_pci_enable (struct comedi_device*) ; 
 struct pci_dev* comedi_to_pci_dev (struct comedi_device*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  ke_counter_driver ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 scalar_t__ pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static int ke_counter_insn_write(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn,
				 unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val;
	int i;

	for (i = 0; i < insn->n; i++) {
		val = data[0];

		/* Order matters */
		outb((val >> 24) & 0xff, dev->iobase + KE_SIGN_REG(chan));
		outb((val >> 16) & 0xff, dev->iobase + KE_MSB_REG(chan));
		outb((val >> 8) & 0xff, dev->iobase + KE_MID_REG(chan));
		outb((val >> 0) & 0xff, dev->iobase + KE_LSB_REG(chan));
	}

	return insn->n;
}

__attribute__((used)) static int ke_counter_insn_read(struct comedi_device *dev,
				struct comedi_subdevice *s,
				struct comedi_insn *insn,
				unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int val;
	int i;

	for (i = 0; i < insn->n; i++) {
		/* Order matters */
		inb(dev->iobase + KE_LATCH_REG(chan));

		val = inb(dev->iobase + KE_LSB_REG(chan));
		val |= (inb(dev->iobase + KE_MID_REG(chan)) << 8);
		val |= (inb(dev->iobase + KE_MSB_REG(chan)) << 16);
		val |= (inb(dev->iobase + KE_SIGN_REG(chan)) << 24);

		data[i] = val;
	}

	return insn->n;
}

__attribute__((used)) static void ke_counter_reset(struct comedi_device *dev)
{
	unsigned int chan;

	for (chan = 0; chan < 3; chan++)
		outb(0, dev->iobase + KE_RESET_REG(chan));
}

__attribute__((used)) static int ke_counter_insn_config(struct comedi_device *dev,
				  struct comedi_subdevice *s,
				  struct comedi_insn *insn,
				  unsigned int *data)
{
	unsigned char src;

	switch (data[0]) {
	case INSN_CONFIG_SET_CLOCK_SRC:
		switch (data[1]) {
		case KE_CLK_20MHZ:	/* default */
			src = KE_OSC_SEL_20MHZ;
			break;
		case KE_CLK_4MHZ:	/* option */
			src = KE_OSC_SEL_4MHZ;
			break;
		case KE_CLK_EXT:	/* Pin 21 on D-sub */
			src = KE_OSC_SEL_EXT;
			break;
		default:
			return -EINVAL;
		}
		outb(src, dev->iobase + KE_OSC_SEL_REG);
		break;
	case INSN_CONFIG_GET_CLOCK_SRC:
		src = inb(dev->iobase + KE_OSC_SEL_REG);
		switch (src) {
		case KE_OSC_SEL_20MHZ:
			data[1] = KE_CLK_20MHZ;
			data[2] = 50;	/* 50ns */
			break;
		case KE_OSC_SEL_4MHZ:
			data[1] = KE_CLK_4MHZ;
			data[2] = 250;	/* 250ns */
			break;
		case KE_OSC_SEL_EXT:
			data[1] = KE_CLK_EXT;
			data[2] = 0;	/* Unknown */
			break;
		default:
			return -EINVAL;
		}
		break;
	case INSN_CONFIG_RESET:
		ke_counter_reset(dev);
		break;
	default:
		return -EINVAL;
	}

	return insn->n;
}

__attribute__((used)) static int ke_counter_do_insn_bits(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_insn *insn,
				   unsigned int *data)
{
	if (comedi_dio_update_state(s, data))
		outb(s->state, dev->iobase + KE_DO_REG);

	data[1] = s->state;

	return insn->n;
}

__attribute__((used)) static int ke_counter_auto_attach(struct comedi_device *dev,
				  unsigned long context_unused)
{
	struct pci_dev *pcidev = comedi_to_pci_dev(dev);
	struct comedi_subdevice *s;
	int ret;

	ret = comedi_pci_enable(dev);
	if (ret)
		return ret;
	dev->iobase = pci_resource_start(pcidev, 0);

	ret = comedi_alloc_subdevices(dev, 2);
	if (ret)
		return ret;

	s = &dev->subdevices[0];
	s->type		= COMEDI_SUBD_COUNTER;
	s->subdev_flags	= SDF_READABLE;
	s->n_chan	= 3;
	s->maxdata	= 0x01ffffff;
	s->range_table	= &range_unknown;
	s->insn_read	= ke_counter_insn_read;
	s->insn_write	= ke_counter_insn_write;
	s->insn_config	= ke_counter_insn_config;

	s = &dev->subdevices[1];
	s->type		= COMEDI_SUBD_DO;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 3;
	s->maxdata	= 1;
	s->range_table	= &range_digital;
	s->insn_bits	= ke_counter_do_insn_bits;

	outb(KE_OSC_SEL_20MHZ, dev->iobase + KE_OSC_SEL_REG);

	ke_counter_reset(dev);

	return 0;
}

__attribute__((used)) static int ke_counter_pci_probe(struct pci_dev *dev,
				const struct pci_device_id *id)
{
	return comedi_pci_auto_config(dev, &ke_counter_driver,
				      id->driver_data);
}

