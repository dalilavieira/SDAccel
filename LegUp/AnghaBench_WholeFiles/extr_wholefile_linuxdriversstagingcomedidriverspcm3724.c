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
struct priv_pcm3724 {unsigned int dio_1; unsigned int dio_2; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int io_bits; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;TYPE_5__* async; TYPE_4__** range_table_list; TYPE_2__* range_table; } ;
struct comedi_insn {int chanspec; int n; } ;
struct comedi_device {int iobase; int n_subdevices; struct comedi_subdevice* subdevices; struct priv_pcm3724* private; } ;
struct comedi_devconfig {int /*<<< orphan*/ * options; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_3__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {TYPE_1__* range; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int CR_CHAN (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int I8255_CTRL_A_IO ; 
 int I8255_CTRL_B_IO ; 
 int I8255_CTRL_CW ; 
 int I8255_CTRL_C_HI_IO ; 
 int I8255_CTRL_C_LO_IO ; 
 int I8255_CTRL_REG ; 
 int I8255_SIZE ; 
 int PCM3724_DIO_DIR_A0_OUT ; 
 int PCM3724_DIO_DIR_A1_OUT ; 
 int PCM3724_DIO_DIR_B0_OUT ; 
 int PCM3724_DIO_DIR_B1_OUT ; 
 int PCM3724_DIO_DIR_C0_OUT ; 
 int PCM3724_DIO_DIR_C1_OUT ; 
 unsigned long PCM3724_DIO_DIR_REG ; 
 int PCM3724_GATE_CTRL_A0_ENA ; 
 int PCM3724_GATE_CTRL_A1_ENA ; 
 int PCM3724_GATE_CTRL_B0_ENA ; 
 int PCM3724_GATE_CTRL_B1_ENA ; 
 int PCM3724_GATE_CTRL_C0_ENA ; 
 int PCM3724_GATE_CTRL_C1_ENA ; 
 int /*<<< orphan*/  PCM3724_GATE_CTRL_REG ; 
 int RF_EXTERNAL ; 
 int SDF_LSAMPL ; 
 unsigned int TRIG_INVALID ; 
 struct priv_pcm3724* comedi_alloc_devpriv (struct comedi_device*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int) ; 
 int comedi_dio_insn_config (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*,unsigned int) ; 
 int comedi_request_region (struct comedi_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outb (int,unsigned long) ; 
 int subdev_8255_init (struct comedi_device*,struct comedi_subdevice*,int /*<<< orphan*/ *,int) ; 

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

__attribute__((used)) static int compute_buffer(int config, int devno, struct comedi_subdevice *s)
{
	/* 1 in io_bits indicates output */
	if (s->io_bits & 0x0000ff) {
		if (devno == 0)
			config |= PCM3724_DIO_DIR_A0_OUT;
		else
			config |= PCM3724_DIO_DIR_A1_OUT;
	}
	if (s->io_bits & 0x00ff00) {
		if (devno == 0)
			config |= PCM3724_DIO_DIR_B0_OUT;
		else
			config |= PCM3724_DIO_DIR_B1_OUT;
	}
	if (s->io_bits & 0xff0000) {
		if (devno == 0)
			config |= PCM3724_DIO_DIR_C0_OUT;
		else
			config |= PCM3724_DIO_DIR_C1_OUT;
	}
	return config;
}

__attribute__((used)) static void do_3724_config(struct comedi_device *dev,
			   struct comedi_subdevice *s, int chanspec)
{
	struct comedi_subdevice *s_dio1 = &dev->subdevices[0];
	struct comedi_subdevice *s_dio2 = &dev->subdevices[1];
	int config;
	int buffer_config;
	unsigned long port_8255_cfg;

	config = I8255_CTRL_CW;
	buffer_config = 0;

	/* 1 in io_bits indicates output, 1 in config indicates input */
	if (!(s->io_bits & 0x0000ff))
		config |= I8255_CTRL_A_IO;

	if (!(s->io_bits & 0x00ff00))
		config |= I8255_CTRL_B_IO;

	if (!(s->io_bits & 0xff0000))
		config |= I8255_CTRL_C_HI_IO | I8255_CTRL_C_LO_IO;

	buffer_config = compute_buffer(0, 0, s_dio1);
	buffer_config = compute_buffer(buffer_config, 1, s_dio2);

	if (s == s_dio1)
		port_8255_cfg = dev->iobase + I8255_CTRL_REG;
	else
		port_8255_cfg = dev->iobase + I8255_SIZE + I8255_CTRL_REG;

	outb(buffer_config, dev->iobase + PCM3724_DIO_DIR_REG);

	outb(config, port_8255_cfg);
}

__attribute__((used)) static void enable_chan(struct comedi_device *dev, struct comedi_subdevice *s,
			int chanspec)
{
	struct priv_pcm3724 *priv = dev->private;
	struct comedi_subdevice *s_dio1 = &dev->subdevices[0];
	unsigned int mask;
	int gatecfg;

	gatecfg = 0;

	mask = 1 << CR_CHAN(chanspec);
	if (s == s_dio1)
		priv->dio_1 |= mask;
	else
		priv->dio_2 |= mask;

	if (priv->dio_1 & 0xff0000)
		gatecfg |= PCM3724_GATE_CTRL_C0_ENA;

	if (priv->dio_1 & 0xff00)
		gatecfg |= PCM3724_GATE_CTRL_B0_ENA;

	if (priv->dio_1 & 0xff)
		gatecfg |= PCM3724_GATE_CTRL_A0_ENA;

	if (priv->dio_2 & 0xff0000)
		gatecfg |= PCM3724_GATE_CTRL_C1_ENA;

	if (priv->dio_2 & 0xff00)
		gatecfg |= PCM3724_GATE_CTRL_B1_ENA;

	if (priv->dio_2 & 0xff)
		gatecfg |= PCM3724_GATE_CTRL_A1_ENA;

	outb(gatecfg, dev->iobase + PCM3724_GATE_CTRL_REG);
}

__attribute__((used)) static int subdev_3724_insn_config(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_insn *insn,
				   unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int mask;
	int ret;

	if (chan < 8)
		mask = 0x0000ff;
	else if (chan < 16)
		mask = 0x00ff00;
	else if (chan < 20)
		mask = 0x0f0000;
	else
		mask = 0xf00000;

	ret = comedi_dio_insn_config(dev, s, insn, data, mask);
	if (ret)
		return ret;

	do_3724_config(dev, s, insn->chanspec);
	enable_chan(dev, s, insn->chanspec);

	return insn->n;
}

__attribute__((used)) static int pcm3724_attach(struct comedi_device *dev,
			  struct comedi_devconfig *it)
{
	struct priv_pcm3724 *priv;
	struct comedi_subdevice *s;
	int ret, i;

	priv = comedi_alloc_devpriv(dev, sizeof(*priv));
	if (!priv)
		return -ENOMEM;

	ret = comedi_request_region(dev, it->options[0], 0x10);
	if (ret)
		return ret;

	ret = comedi_alloc_subdevices(dev, 2);
	if (ret)
		return ret;

	for (i = 0; i < dev->n_subdevices; i++) {
		s = &dev->subdevices[i];
		ret = subdev_8255_init(dev, s, NULL, i * I8255_SIZE);
		if (ret)
			return ret;
		s->insn_config = subdev_3724_insn_config;
	}
	return 0;
}

