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
struct subdev_8255_private {unsigned long regbase; unsigned int (* io ) (struct comedi_device*,int,int,int,unsigned long) ;} ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int state; int io_bits; int n_chan; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;struct subdev_8255_private* private; TYPE_5__* range_table; int /*<<< orphan*/  type; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {scalar_t__ mmio; scalar_t__ iobase; } ;
struct TYPE_10__ {TYPE_1__* range; } ;
struct TYPE_9__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_8__ {TYPE_2__* range; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_SUBD_DIO ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int I8255_CTRL_A_IO ; 
 int I8255_CTRL_B_IO ; 
 int I8255_CTRL_CW ; 
 int I8255_CTRL_C_HI_IO ; 
 int I8255_CTRL_C_LO_IO ; 
 int I8255_CTRL_REG ; 
 int I8255_DATA_A_REG ; 
 int I8255_DATA_B_REG ; 
 int I8255_DATA_C_REG ; 
 int RF_EXTERNAL ; 
 int SDF_LSAMPL ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_INVALID ; 
 struct subdev_8255_private* comedi_alloc_spriv (struct comedi_subdevice*,int) ; 
 int comedi_dio_insn_config (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*,unsigned int) ; 
 unsigned int comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 TYPE_5__ range_digital ; 
 int readb (scalar_t__) ; 
 unsigned int stub1 (struct comedi_device*,int,int,int,unsigned long) ; 
 unsigned int stub2 (struct comedi_device*,int,int,int,unsigned long) ; 
 unsigned int stub3 (struct comedi_device*,int,int,int,unsigned long) ; 
 unsigned int stub4 (struct comedi_device*,int,int,int,unsigned long) ; 
 int stub5 (struct comedi_device*,int,int,int,unsigned long) ; 
 int stub6 (struct comedi_device*,int,int,int,unsigned long) ; 
 int stub7 (struct comedi_device*,int,int,int,unsigned long) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

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

__attribute__((used)) static int subdev_8255_io(struct comedi_device *dev,
			  int dir, int port, int data, unsigned long regbase)
{
	if (dir) {
		outb(data, dev->iobase + regbase + port);
		return 0;
	}
	return inb(dev->iobase + regbase + port);
}

__attribute__((used)) static int subdev_8255_mmio(struct comedi_device *dev,
			    int dir, int port, int data, unsigned long regbase)
{
	if (dir) {
		writeb(data, dev->mmio + regbase + port);
		return 0;
	}
	return readb(dev->mmio + regbase + port);
}

__attribute__((used)) static int subdev_8255_insn(struct comedi_device *dev,
			    struct comedi_subdevice *s,
			    struct comedi_insn *insn,
			    unsigned int *data)
{
	struct subdev_8255_private *spriv = s->private;
	unsigned long regbase = spriv->regbase;
	unsigned int mask;
	unsigned int v;

	mask = comedi_dio_update_state(s, data);
	if (mask) {
		if (mask & 0xff)
			spriv->io(dev, 1, I8255_DATA_A_REG,
				  s->state & 0xff, regbase);
		if (mask & 0xff00)
			spriv->io(dev, 1, I8255_DATA_B_REG,
				  (s->state >> 8) & 0xff, regbase);
		if (mask & 0xff0000)
			spriv->io(dev, 1, I8255_DATA_C_REG,
				  (s->state >> 16) & 0xff, regbase);
	}

	v = spriv->io(dev, 0, I8255_DATA_A_REG, 0, regbase);
	v |= (spriv->io(dev, 0, I8255_DATA_B_REG, 0, regbase) << 8);
	v |= (spriv->io(dev, 0, I8255_DATA_C_REG, 0, regbase) << 16);

	data[1] = v;

	return insn->n;
}

__attribute__((used)) static void subdev_8255_do_config(struct comedi_device *dev,
				  struct comedi_subdevice *s)
{
	struct subdev_8255_private *spriv = s->private;
	unsigned long regbase = spriv->regbase;
	int config;

	config = I8255_CTRL_CW;
	/* 1 in io_bits indicates output, 1 in config indicates input */
	if (!(s->io_bits & 0x0000ff))
		config |= I8255_CTRL_A_IO;
	if (!(s->io_bits & 0x00ff00))
		config |= I8255_CTRL_B_IO;
	if (!(s->io_bits & 0x0f0000))
		config |= I8255_CTRL_C_LO_IO;
	if (!(s->io_bits & 0xf00000))
		config |= I8255_CTRL_C_HI_IO;

	spriv->io(dev, 1, I8255_CTRL_REG, config, regbase);
}

__attribute__((used)) static int subdev_8255_insn_config(struct comedi_device *dev,
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

	subdev_8255_do_config(dev, s);

	return insn->n;
}

__attribute__((used)) static int __subdev_8255_init(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      int (*io)(struct comedi_device *dev,
					int dir, int port, int data,
					unsigned long regbase),
			      unsigned long regbase,
			      bool is_mmio)
{
	struct subdev_8255_private *spriv;

	spriv = comedi_alloc_spriv(s, sizeof(*spriv));
	if (!spriv)
		return -ENOMEM;

	if (io)
		spriv->io = io;
	else if (is_mmio)
		spriv->io = subdev_8255_mmio;
	else
		spriv->io = subdev_8255_io;
	spriv->regbase	= regbase;

	s->type		= COMEDI_SUBD_DIO;
	s->subdev_flags	= SDF_READABLE | SDF_WRITABLE;
	s->n_chan	= 24;
	s->range_table	= &range_digital;
	s->maxdata	= 1;
	s->insn_bits	= subdev_8255_insn;
	s->insn_config	= subdev_8255_insn_config;

	subdev_8255_do_config(dev, s);

	return 0;
}

int subdev_8255_init(struct comedi_device *dev, struct comedi_subdevice *s,
		     int (*io)(struct comedi_device *dev, int dir, int port,
			       int data, unsigned long regbase),
		     unsigned long regbase)
{
	return __subdev_8255_init(dev, s, io, regbase, false);
}

int subdev_8255_mm_init(struct comedi_device *dev, struct comedi_subdevice *s,
			int (*io)(struct comedi_device *dev, int dir, int port,
				  int data, unsigned long regbase),
			unsigned long regbase)
{
	return __subdev_8255_init(dev, s, io, regbase, true);
}

unsigned long subdev_8255_regbase(struct comedi_subdevice *s)
{
	struct subdev_8255_private *spriv = s->private;

	return spriv->regbase;
}

