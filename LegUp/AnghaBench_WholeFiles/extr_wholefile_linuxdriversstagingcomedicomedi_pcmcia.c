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
struct pcmcia_driver {int dummy; } ;
struct pcmcia_device {scalar_t__ config_index; int /*<<< orphan*/  dev; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; TYPE_5__* async; TYPE_4__** range_table_list; TYPE_2__* range_table; } ;
struct comedi_driver {int dummy; } ;
struct comedi_device {scalar_t__ hw_dev; } ;
struct TYPE_10__ {unsigned int buf_write_count; unsigned int buf_read_count; } ;
struct TYPE_9__ {TYPE_3__* range; } ;
struct TYPE_8__ {scalar_t__ min; int flags; } ;
struct TYPE_7__ {TYPE_1__* range; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int RF_EXTERNAL ; 
 int SDF_LSAMPL ; 
 unsigned int TRIG_INVALID ; 
 int comedi_auto_config (int /*<<< orphan*/ *,struct comedi_driver*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_auto_unconfig (int /*<<< orphan*/ *) ; 
 int comedi_driver_register (struct comedi_driver*) ; 
 int /*<<< orphan*/  comedi_driver_unregister (struct comedi_driver*) ; 
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 
 int pcmcia_enable_device (struct pcmcia_device*) ; 
 int pcmcia_loop_config (struct pcmcia_device*,int (*) (struct pcmcia_device*,void*),int /*<<< orphan*/ *) ; 
 int pcmcia_register_driver (struct pcmcia_driver*) ; 
 int pcmcia_request_io (struct pcmcia_device*) ; 
 int /*<<< orphan*/  pcmcia_unregister_driver (struct pcmcia_driver*) ; 
 struct pcmcia_device* to_pcmcia_dev (scalar_t__) ; 

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

struct pcmcia_device *comedi_to_pcmcia_dev(struct comedi_device *dev)
{
	return dev->hw_dev ? to_pcmcia_dev(dev->hw_dev) : NULL;
}

__attribute__((used)) static int comedi_pcmcia_conf_check(struct pcmcia_device *link,
				    void *priv_data)
{
	if (link->config_index == 0)
		return -EINVAL;

	return pcmcia_request_io(link);
}

int comedi_pcmcia_enable(struct comedi_device *dev,
			 int (*conf_check)(struct pcmcia_device *p_dev,
					   void *priv_data))
{
	struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
	int ret;

	if (!link)
		return -ENODEV;

	if (!conf_check)
		conf_check = comedi_pcmcia_conf_check;

	ret = pcmcia_loop_config(link, conf_check, NULL);
	if (ret)
		return ret;

	return pcmcia_enable_device(link);
}

void comedi_pcmcia_disable(struct comedi_device *dev)
{
	struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);

	if (link)
		pcmcia_disable_device(link);
}

int comedi_pcmcia_auto_config(struct pcmcia_device *link,
			      struct comedi_driver *driver)
{
	return comedi_auto_config(&link->dev, driver, 0);
}

void comedi_pcmcia_auto_unconfig(struct pcmcia_device *link)
{
	comedi_auto_unconfig(&link->dev);
}

int comedi_pcmcia_driver_register(struct comedi_driver *comedi_driver,
				  struct pcmcia_driver *pcmcia_driver)
{
	int ret;

	ret = comedi_driver_register(comedi_driver);
	if (ret < 0)
		return ret;

	ret = pcmcia_register_driver(pcmcia_driver);
	if (ret < 0) {
		comedi_driver_unregister(comedi_driver);
		return ret;
	}

	return 0;
}

void comedi_pcmcia_driver_unregister(struct comedi_driver *comedi_driver,
				     struct pcmcia_driver *pcmcia_driver)
{
	pcmcia_unregister_driver(pcmcia_driver);
	comedi_driver_unregister(comedi_driver);
}

