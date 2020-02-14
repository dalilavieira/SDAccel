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
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int n_chan; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int /*<<< orphan*/  type; struct addi_watchdog_private* private; TYPE_5__* async; TYPE_4__** range_table_list; TYPE_2__* range_table; } ;
struct comedi_insn {int n; } ;
struct comedi_device {int /*<<< orphan*/  class_dev; } ;
struct addi_watchdog_private {int wdog_ctrl; unsigned long iobase; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_3__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {TYPE_1__* range; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int ADDI_TCW_CTRL_ENA ; 
 unsigned long ADDI_TCW_CTRL_REG ; 
 int ADDI_TCW_CTRL_TRIG ; 
 unsigned long ADDI_TCW_RELOAD_REG ; 
 unsigned long ADDI_TCW_STATUS_REG ; 
 int /*<<< orphan*/  COMEDI_SUBD_TIMER ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  INSN_CONFIG_ARM 129 
#define  INSN_CONFIG_DISARM 128 
 int RF_EXTERNAL ; 
 int SDF_LSAMPL ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_INVALID ; 
 struct addi_watchdog_private* comedi_alloc_spriv (struct comedi_subdevice*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 unsigned int inl (unsigned long) ; 
 int /*<<< orphan*/  outl (int,unsigned long) ; 

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

__attribute__((used)) static int addi_watchdog_insn_config(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     struct comedi_insn *insn,
				     unsigned int *data)
{
	struct addi_watchdog_private *spriv = s->private;
	unsigned int reload;

	switch (data[0]) {
	case INSN_CONFIG_ARM:
		spriv->wdog_ctrl = ADDI_TCW_CTRL_ENA;
		reload = data[1] & s->maxdata;
		outl(reload, spriv->iobase + ADDI_TCW_RELOAD_REG);

		/* Time base is 20ms, let the user know the timeout */
		dev_info(dev->class_dev, "watchdog enabled, timeout:%dms\n",
			 20 * reload + 20);
		break;
	case INSN_CONFIG_DISARM:
		spriv->wdog_ctrl = 0;
		break;
	default:
		return -EINVAL;
	}

	outl(spriv->wdog_ctrl, spriv->iobase + ADDI_TCW_CTRL_REG);

	return insn->n;
}

__attribute__((used)) static int addi_watchdog_insn_read(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_insn *insn,
				   unsigned int *data)
{
	struct addi_watchdog_private *spriv = s->private;
	int i;

	for (i = 0; i < insn->n; i++)
		data[i] = inl(spriv->iobase + ADDI_TCW_STATUS_REG);

	return insn->n;
}

__attribute__((used)) static int addi_watchdog_insn_write(struct comedi_device *dev,
				    struct comedi_subdevice *s,
				    struct comedi_insn *insn,
				    unsigned int *data)
{
	struct addi_watchdog_private *spriv = s->private;
	int i;

	if (spriv->wdog_ctrl == 0) {
		dev_warn(dev->class_dev, "watchdog is disabled\n");
		return -EINVAL;
	}

	/* "ping" the watchdog */
	for (i = 0; i < insn->n; i++) {
		outl(spriv->wdog_ctrl | ADDI_TCW_CTRL_TRIG,
		     spriv->iobase + ADDI_TCW_CTRL_REG);
	}

	return insn->n;
}

void addi_watchdog_reset(unsigned long iobase)
{
	outl(0x0, iobase + ADDI_TCW_CTRL_REG);
	outl(0x0, iobase + ADDI_TCW_RELOAD_REG);
}

int addi_watchdog_init(struct comedi_subdevice *s, unsigned long iobase)
{
	struct addi_watchdog_private *spriv;

	spriv = comedi_alloc_spriv(s, sizeof(*spriv));
	if (!spriv)
		return -ENOMEM;

	spriv->iobase = iobase;

	s->type		= COMEDI_SUBD_TIMER;
	s->subdev_flags	= SDF_WRITABLE;
	s->n_chan	= 1;
	s->maxdata	= 0xff;
	s->insn_config	= addi_watchdog_insn_config;
	s->insn_read	= addi_watchdog_insn_read;
	s->insn_write	= addi_watchdog_insn_write;

	return 0;
}

