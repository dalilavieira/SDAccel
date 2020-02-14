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
struct dio200_subdev_intr {unsigned int mmio; unsigned int iobase; unsigned int ofs; unsigned int valid_isns; int active; unsigned int enabled_isns; unsigned int* gate_src; unsigned int* clock_src; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int /*<<< orphan*/  spinlock; } ;
struct dio200_subdev_8255 {unsigned int mmio; unsigned int iobase; unsigned int ofs; unsigned int valid_isns; int active; unsigned int enabled_isns; unsigned int* gate_src; unsigned int* clock_src; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int /*<<< orphan*/  spinlock; } ;
struct dio200_board {int* sdtype; unsigned int* sdinfo; int /*<<< orphan*/  n_subdevs; scalar_t__ has_clk_gat_sce; scalar_t__ is_pcie; scalar_t__ has_int_sce; } ;
struct comedi_subdevice {unsigned int maxdata; int subdev_flags; int n_chan; int len_chanlist; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* do_cmdtest ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_cmd*) ;int (* do_cmd ) (struct comedi_device*,struct comedi_subdevice*) ;int (* cancel ) (struct comedi_device*,struct comedi_subdevice*) ;int io_bits; int state; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;void* type; TYPE_5__* range_table; struct dio200_subdev_intr* private; TYPE_4__* async; TYPE_3__** range_table_list; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {unsigned int mmio; unsigned int iobase; unsigned int n_subdevices; unsigned int irq; int /*<<< orphan*/  class_dev; int /*<<< orphan*/  board_name; struct comedi_subdevice* read_subdev; struct comedi_subdevice* subdevices; struct dio200_board* board_ptr; int /*<<< orphan*/  attached; } ;
struct comedi_cmd {unsigned int chanlist_len; unsigned int start_arg; unsigned int stop_src; scalar_t__ stop_arg; unsigned int start_src; unsigned int scan_begin_src; unsigned int convert_src; unsigned int scan_end_src; unsigned int scan_begin_arg; unsigned int convert_arg; unsigned int scan_end_arg; int /*<<< orphan*/ * chanlist; } ;
struct comedi_8254 {unsigned int mmio; unsigned int iobase; unsigned int ofs; unsigned int valid_isns; int active; unsigned int enabled_isns; unsigned int* gate_src; unsigned int* clock_src; int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int /*<<< orphan*/  spinlock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {TYPE_1__* range; } ;
struct TYPE_9__ {unsigned int buf_write_count; unsigned int buf_read_count; int (* inttrig ) (struct comedi_device*,struct comedi_subdevice*,unsigned int) ;scalar_t__ scans_done; struct comedi_cmd cmd; int /*<<< orphan*/  events; } ;
struct TYPE_8__ {TYPE_2__* range; } ;
struct TYPE_7__ {scalar_t__ min; int flags; } ;
struct TYPE_6__ {scalar_t__ min; int flags; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (unsigned int*) ; 
 int /*<<< orphan*/  COMEDI_CB_EOA ; 
 void* COMEDI_SUBD_DI ; 
 void* COMEDI_SUBD_DIO ; 
 void* COMEDI_SUBD_TIMER ; 
 void* COMEDI_SUBD_UNUSED ; 
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 unsigned int DIO200_CLK_SCE (unsigned int) ; 
 unsigned int DIO200_ENHANCE ; 
 unsigned int DIO200_GAT_SCE (unsigned int) ; 
 unsigned int DIO200_INT_SCE ; 
 void* DIO200_MAX_ISNS ; 
 unsigned int DIO200_TS_CONFIG ; 
 unsigned int DIO200_TS_COUNT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  I8254_IO8 ; 
 int I8255_CTRL_A_IO ; 
 int I8255_CTRL_B_IO ; 
 int I8255_CTRL_CW ; 
 int I8255_CTRL_C_HI_IO ; 
 int I8255_CTRL_C_LO_IO ; 
 unsigned int I8255_CTRL_REG ; 
 unsigned int I8255_DATA_A_REG ; 
 unsigned int I8255_DATA_B_REG ; 
 unsigned int I8255_DATA_C_REG ; 
#define  INSN_CONFIG_GET_CLOCK_SRC 136 
#define  INSN_CONFIG_GET_GATE_SRC 135 
#define  INSN_CONFIG_RESET 134 
#define  INSN_CONFIG_SET_CLOCK_SRC 133 
#define  INSN_CONFIG_SET_GATE_SRC 132 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_RETVAL (int) ; 
 int RF_EXTERNAL ; 
 int SDF_CMD_READ ; 
 int SDF_LSAMPL ; 
 int SDF_PACKED ; 
 int SDF_READABLE ; 
 int SDF_WRITABLE ; 
 unsigned int TRIG_COUNT ; 
 unsigned int TRIG_EXT ; 
 unsigned int TRIG_INT ; 
 unsigned int TRIG_INVALID ; 
 unsigned int TRIG_NONE ; 
 unsigned int TRIG_NOW ; 
 unsigned int TS_CONFIG_CLK_SRC_MASK ; 
 unsigned int TS_CONFIG_MAX_CLK_SRC ; 
 unsigned int TS_CONFIG_RESET ; 
 unsigned int* clock_period ; 
 struct dio200_subdev_intr* comedi_8254_init (unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 struct dio200_subdev_intr* comedi_8254_mm_init (unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  comedi_8254_subdevice_init (struct comedi_subdevice*,struct dio200_subdev_intr*) ; 
 void* comedi_alloc_spriv (struct comedi_subdevice*,int) ; 
 int comedi_alloc_subdevices (struct comedi_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comedi_buf_write_samples (struct comedi_subdevice*,unsigned short*,int) ; 
 int comedi_dio_insn_config (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*,unsigned int) ; 
 unsigned int comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 int /*<<< orphan*/  comedi_handle_events (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  comedi_set_spriv_auto_free (struct comedi_subdevice*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,unsigned int) ; 
 unsigned char inb (unsigned int) ; 
 unsigned int inl (unsigned int) ; 
 int /*<<< orphan*/  outb (unsigned char,unsigned int) ; 
 int /*<<< orphan*/  outl (unsigned int,unsigned int) ; 
 TYPE_5__ range_digital ; 
 unsigned char readb (unsigned int) ; 
 unsigned int readl (unsigned int) ; 
 scalar_t__ request_irq (unsigned int,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct comedi_device*) ; 
#define  sd_8254 131 
#define  sd_8255 130 
#define  sd_intr 129 
#define  sd_timer 128 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int* ts_clock_period ; 
 int /*<<< orphan*/  writeb (unsigned char,unsigned int) ; 
 int /*<<< orphan*/  writel (unsigned int,unsigned int) ; 

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

__attribute__((used)) static unsigned char clk_gat_sce(unsigned int which, unsigned int chan,
				 unsigned int source)
{
	return (which << 5) | (chan << 3) |
	       ((source & 030) << 3) | (source & 007);
}

__attribute__((used)) static unsigned char clk_sce(unsigned int which, unsigned int chan,
			     unsigned int source)
{
	return clk_gat_sce(which, chan, source);
}

__attribute__((used)) static unsigned char gat_sce(unsigned int which, unsigned int chan,
			     unsigned int source)
{
	return clk_gat_sce(which, chan, source);
}

__attribute__((used)) static unsigned char dio200_read8(struct comedi_device *dev,
				  unsigned int offset)
{
	const struct dio200_board *board = dev->board_ptr;

	if (board->is_pcie)
		offset <<= 3;

	if (dev->mmio)
		return readb(dev->mmio + offset);
	return inb(dev->iobase + offset);
}

__attribute__((used)) static void dio200_write8(struct comedi_device *dev,
			  unsigned int offset, unsigned char val)
{
	const struct dio200_board *board = dev->board_ptr;

	if (board->is_pcie)
		offset <<= 3;

	if (dev->mmio)
		writeb(val, dev->mmio + offset);
	else
		outb(val, dev->iobase + offset);
}

__attribute__((used)) static unsigned int dio200_read32(struct comedi_device *dev,
				  unsigned int offset)
{
	const struct dio200_board *board = dev->board_ptr;

	if (board->is_pcie)
		offset <<= 3;

	if (dev->mmio)
		return readl(dev->mmio + offset);
	return inl(dev->iobase + offset);
}

__attribute__((used)) static void dio200_write32(struct comedi_device *dev,
			   unsigned int offset, unsigned int val)
{
	const struct dio200_board *board = dev->board_ptr;

	if (board->is_pcie)
		offset <<= 3;

	if (dev->mmio)
		writel(val, dev->mmio + offset);
	else
		outl(val, dev->iobase + offset);
}

__attribute__((used)) static unsigned int dio200_subdev_8254_offset(struct comedi_device *dev,
					      struct comedi_subdevice *s)
{
	const struct dio200_board *board = dev->board_ptr;
	struct comedi_8254 *i8254 = s->private;
	unsigned int offset;

	/* get the offset that was passed to comedi_8254_*_init() */
	if (dev->mmio)
		offset = i8254->mmio - dev->mmio;
	else
		offset = i8254->iobase - dev->iobase;

	/* remove the shift that was added for PCIe boards */
	if (board->is_pcie)
		offset >>= 3;

	/* this offset now works for the dio200_{read,write} helpers */
	return offset;
}

__attribute__((used)) static int dio200_subdev_intr_insn_bits(struct comedi_device *dev,
					struct comedi_subdevice *s,
					struct comedi_insn *insn,
					unsigned int *data)
{
	const struct dio200_board *board = dev->board_ptr;
	struct dio200_subdev_intr *subpriv = s->private;

	if (board->has_int_sce) {
		/* Just read the interrupt status register.  */
		data[1] = dio200_read8(dev, subpriv->ofs) & subpriv->valid_isns;
	} else {
		/* No interrupt status register. */
		data[0] = 0;
	}

	return insn->n;
}

__attribute__((used)) static void dio200_stop_intr(struct comedi_device *dev,
			     struct comedi_subdevice *s)
{
	const struct dio200_board *board = dev->board_ptr;
	struct dio200_subdev_intr *subpriv = s->private;

	subpriv->active = false;
	subpriv->enabled_isns = 0;
	if (board->has_int_sce)
		dio200_write8(dev, subpriv->ofs, 0);
}

__attribute__((used)) static void dio200_start_intr(struct comedi_device *dev,
			      struct comedi_subdevice *s)
{
	const struct dio200_board *board = dev->board_ptr;
	struct dio200_subdev_intr *subpriv = s->private;
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned int n;
	unsigned int isn_bits;

	/* Determine interrupt sources to enable. */
	isn_bits = 0;
	if (cmd->chanlist) {
		for (n = 0; n < cmd->chanlist_len; n++)
			isn_bits |= (1U << CR_CHAN(cmd->chanlist[n]));
	}
	isn_bits &= subpriv->valid_isns;
	/* Enable interrupt sources. */
	subpriv->enabled_isns = isn_bits;
	if (board->has_int_sce)
		dio200_write8(dev, subpriv->ofs, isn_bits);
}

__attribute__((used)) static int dio200_inttrig_start_intr(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     unsigned int trig_num)
{
	struct dio200_subdev_intr *subpriv = s->private;
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned long flags;

	if (trig_num != cmd->start_arg)
		return -EINVAL;

	spin_lock_irqsave(&subpriv->spinlock, flags);
	s->async->inttrig = NULL;
	if (subpriv->active)
		dio200_start_intr(dev, s);

	spin_unlock_irqrestore(&subpriv->spinlock, flags);

	return 1;
}

__attribute__((used)) static void dio200_read_scan_intr(struct comedi_device *dev,
				  struct comedi_subdevice *s,
				  unsigned int triggered)
{
	struct comedi_cmd *cmd = &s->async->cmd;
	unsigned short val;
	unsigned int n, ch;

	val = 0;
	for (n = 0; n < cmd->chanlist_len; n++) {
		ch = CR_CHAN(cmd->chanlist[n]);
		if (triggered & (1U << ch))
			val |= (1U << n);
	}

	comedi_buf_write_samples(s, &val, 1);

	if (cmd->stop_src == TRIG_COUNT &&
	    s->async->scans_done >= cmd->stop_arg)
		s->async->events |= COMEDI_CB_EOA;
}

__attribute__((used)) static int dio200_handle_read_intr(struct comedi_device *dev,
				   struct comedi_subdevice *s)
{
	const struct dio200_board *board = dev->board_ptr;
	struct dio200_subdev_intr *subpriv = s->private;
	unsigned int triggered;
	unsigned int intstat;
	unsigned int cur_enabled;
	unsigned long flags;

	triggered = 0;

	spin_lock_irqsave(&subpriv->spinlock, flags);
	if (board->has_int_sce) {
		/*
		 * Collect interrupt sources that have triggered and disable
		 * them temporarily.  Loop around until no extra interrupt
		 * sources have triggered, at which point, the valid part of
		 * the interrupt status register will read zero, clearing the
		 * cause of the interrupt.
		 *
		 * Mask off interrupt sources already seen to avoid infinite
		 * loop in case of misconfiguration.
		 */
		cur_enabled = subpriv->enabled_isns;
		while ((intstat = (dio200_read8(dev, subpriv->ofs) &
				   subpriv->valid_isns & ~triggered)) != 0) {
			triggered |= intstat;
			cur_enabled &= ~triggered;
			dio200_write8(dev, subpriv->ofs, cur_enabled);
		}
	} else {
		/*
		 * No interrupt status register.  Assume the single interrupt
		 * source has triggered.
		 */
		triggered = subpriv->enabled_isns;
	}

	if (triggered) {
		/*
		 * Some interrupt sources have triggered and have been
		 * temporarily disabled to clear the cause of the interrupt.
		 *
		 * Reenable them NOW to minimize the time they are disabled.
		 */
		cur_enabled = subpriv->enabled_isns;
		if (board->has_int_sce)
			dio200_write8(dev, subpriv->ofs, cur_enabled);

		if (subpriv->active) {
			/*
			 * The command is still active.
			 *
			 * Ignore interrupt sources that the command isn't
			 * interested in (just in case there's a race
			 * condition).
			 */
			if (triggered & subpriv->enabled_isns) {
				/* Collect scan data. */
				dio200_read_scan_intr(dev, s, triggered);
			}
		}
	}
	spin_unlock_irqrestore(&subpriv->spinlock, flags);

	comedi_handle_events(dev, s);

	return (triggered != 0);
}

__attribute__((used)) static int dio200_subdev_intr_cancel(struct comedi_device *dev,
				     struct comedi_subdevice *s)
{
	struct dio200_subdev_intr *subpriv = s->private;
	unsigned long flags;

	spin_lock_irqsave(&subpriv->spinlock, flags);
	if (subpriv->active)
		dio200_stop_intr(dev, s);

	spin_unlock_irqrestore(&subpriv->spinlock, flags);

	return 0;
}

__attribute__((used)) static int dio200_subdev_intr_cmdtest(struct comedi_device *dev,
				      struct comedi_subdevice *s,
				      struct comedi_cmd *cmd)
{
	int err = 0;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
	err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */

	err |= comedi_check_trigger_is_unique(cmd->start_src);
	err |= comedi_check_trigger_is_unique(cmd->stop_src);

	/* Step 2b : and mutually compatible */

	if (err)
		return 2;

	/* Step 3: check if arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);

	if (cmd->stop_src == TRIG_COUNT)
		err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
	else	/* TRIG_NONE */
		err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* step 4: fix up any arguments */

	/* if (err) return 4; */

	return 0;
}

__attribute__((used)) static int dio200_subdev_intr_cmd(struct comedi_device *dev,
				  struct comedi_subdevice *s)
{
	struct comedi_cmd *cmd = &s->async->cmd;
	struct dio200_subdev_intr *subpriv = s->private;
	unsigned long flags;

	spin_lock_irqsave(&subpriv->spinlock, flags);

	subpriv->active = true;

	if (cmd->start_src == TRIG_INT)
		s->async->inttrig = dio200_inttrig_start_intr;
	else	/* TRIG_NOW */
		dio200_start_intr(dev, s);

	spin_unlock_irqrestore(&subpriv->spinlock, flags);

	return 0;
}

__attribute__((used)) static int dio200_subdev_intr_init(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   unsigned int offset,
				   unsigned int valid_isns)
{
	const struct dio200_board *board = dev->board_ptr;
	struct dio200_subdev_intr *subpriv;

	subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
	if (!subpriv)
		return -ENOMEM;

	subpriv->ofs = offset;
	subpriv->valid_isns = valid_isns;
	spin_lock_init(&subpriv->spinlock);

	if (board->has_int_sce)
		/* Disable interrupt sources. */
		dio200_write8(dev, subpriv->ofs, 0);

	s->type = COMEDI_SUBD_DI;
	s->subdev_flags = SDF_READABLE | SDF_CMD_READ | SDF_PACKED;
	if (board->has_int_sce) {
		s->n_chan = DIO200_MAX_ISNS;
		s->len_chanlist = DIO200_MAX_ISNS;
	} else {
		/* No interrupt source register.  Support single channel. */
		s->n_chan = 1;
		s->len_chanlist = 1;
	}
	s->range_table = &range_digital;
	s->maxdata = 1;
	s->insn_bits = dio200_subdev_intr_insn_bits;
	s->do_cmdtest = dio200_subdev_intr_cmdtest;
	s->do_cmd = dio200_subdev_intr_cmd;
	s->cancel = dio200_subdev_intr_cancel;

	return 0;
}

__attribute__((used)) static irqreturn_t dio200_interrupt(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct comedi_subdevice *s = dev->read_subdev;
	int handled;

	if (!dev->attached)
		return IRQ_NONE;

	handled = dio200_handle_read_intr(dev, s);

	return IRQ_RETVAL(handled);
}

__attribute__((used)) static void dio200_subdev_8254_set_gate_src(struct comedi_device *dev,
					    struct comedi_subdevice *s,
					    unsigned int chan,
					    unsigned int src)
{
	unsigned int offset = dio200_subdev_8254_offset(dev, s);

	dio200_write8(dev, DIO200_GAT_SCE(offset >> 3),
		      gat_sce((offset >> 2) & 1, chan, src));
}

__attribute__((used)) static void dio200_subdev_8254_set_clock_src(struct comedi_device *dev,
					     struct comedi_subdevice *s,
					     unsigned int chan,
					     unsigned int src)
{
	unsigned int offset = dio200_subdev_8254_offset(dev, s);

	dio200_write8(dev, DIO200_CLK_SCE(offset >> 3),
		      clk_sce((offset >> 2) & 1, chan, src));
}

__attribute__((used)) static int dio200_subdev_8254_config(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     struct comedi_insn *insn,
				     unsigned int *data)
{
	const struct dio200_board *board = dev->board_ptr;
	struct comedi_8254 *i8254 = s->private;
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int max_src = board->is_pcie ? 31 : 7;
	unsigned int src;

	if (!board->has_clk_gat_sce)
		return -EINVAL;

	switch (data[0]) {
	case INSN_CONFIG_SET_GATE_SRC:
		src = data[2];
		if (src > max_src)
			return -EINVAL;

		dio200_subdev_8254_set_gate_src(dev, s, chan, src);
		i8254->gate_src[chan] = src;
		break;
	case INSN_CONFIG_GET_GATE_SRC:
		data[2] = i8254->gate_src[chan];
		break;
	case INSN_CONFIG_SET_CLOCK_SRC:
		src = data[1];
		if (src > max_src)
			return -EINVAL;

		dio200_subdev_8254_set_clock_src(dev, s, chan, src);
		i8254->clock_src[chan] = src;
		break;
	case INSN_CONFIG_GET_CLOCK_SRC:
		data[1] = i8254->clock_src[chan];
		data[2] = clock_period[i8254->clock_src[chan]];
		break;
	default:
		return -EINVAL;
	}

	return insn->n;
}

__attribute__((used)) static int dio200_subdev_8254_init(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   unsigned int offset)
{
	const struct dio200_board *board = dev->board_ptr;
	struct comedi_8254 *i8254;
	unsigned int regshift;
	int chan;

	/*
	 * PCIe boards need the offset shifted in order to get the
	 * correct base address of the timer.
	 */
	if (board->is_pcie) {
		offset <<= 3;
		regshift = 3;
	} else {
		regshift = 0;
	}

	if (dev->mmio) {
		i8254 = comedi_8254_mm_init(dev->mmio + offset,
					    0, I8254_IO8, regshift);
	} else {
		i8254 = comedi_8254_init(dev->iobase + offset,
					 0, I8254_IO8, regshift);
	}
	if (!i8254)
		return -ENOMEM;

	comedi_8254_subdevice_init(s, i8254);

	i8254->insn_config = dio200_subdev_8254_config;

	/*
	 * There could be multiple timers so this driver does not
	 * use dev->pacer to save the i8254 pointer. Instead,
	 * comedi_8254_subdevice_init() saved the i8254 pointer in
	 * s->private.  Mark the subdevice as having private data
	 * to be automatically freed when the device is detached.
	 */
	comedi_set_spriv_auto_free(s);

	/* Initialize channels. */
	if (board->has_clk_gat_sce) {
		for (chan = 0; chan < 3; chan++) {
			/* Gate source 0 is VCC (logic 1). */
			dio200_subdev_8254_set_gate_src(dev, s, chan, 0);
			/* Clock source 0 is the dedicated clock input. */
			dio200_subdev_8254_set_clock_src(dev, s, chan, 0);
		}
	}

	return 0;
}

__attribute__((used)) static void dio200_subdev_8255_set_dir(struct comedi_device *dev,
				       struct comedi_subdevice *s)
{
	struct dio200_subdev_8255 *subpriv = s->private;
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
	dio200_write8(dev, subpriv->ofs + I8255_CTRL_REG, config);
}

__attribute__((used)) static int dio200_subdev_8255_bits(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_insn *insn,
				   unsigned int *data)
{
	struct dio200_subdev_8255 *subpriv = s->private;
	unsigned int mask;
	unsigned int val;

	mask = comedi_dio_update_state(s, data);
	if (mask) {
		if (mask & 0xff) {
			dio200_write8(dev, subpriv->ofs + I8255_DATA_A_REG,
				      s->state & 0xff);
		}
		if (mask & 0xff00) {
			dio200_write8(dev, subpriv->ofs + I8255_DATA_B_REG,
				      (s->state >> 8) & 0xff);
		}
		if (mask & 0xff0000) {
			dio200_write8(dev, subpriv->ofs + I8255_DATA_C_REG,
				      (s->state >> 16) & 0xff);
		}
	}

	val = dio200_read8(dev, subpriv->ofs + I8255_DATA_A_REG);
	val |= dio200_read8(dev, subpriv->ofs + I8255_DATA_B_REG) << 8;
	val |= dio200_read8(dev, subpriv->ofs + I8255_DATA_C_REG) << 16;

	data[1] = val;

	return insn->n;
}

__attribute__((used)) static int dio200_subdev_8255_config(struct comedi_device *dev,
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

	dio200_subdev_8255_set_dir(dev, s);

	return insn->n;
}

__attribute__((used)) static int dio200_subdev_8255_init(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   unsigned int offset)
{
	struct dio200_subdev_8255 *subpriv;

	subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
	if (!subpriv)
		return -ENOMEM;

	subpriv->ofs = offset;

	s->type = COMEDI_SUBD_DIO;
	s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
	s->n_chan = 24;
	s->range_table = &range_digital;
	s->maxdata = 1;
	s->insn_bits = dio200_subdev_8255_bits;
	s->insn_config = dio200_subdev_8255_config;
	dio200_subdev_8255_set_dir(dev, s);
	return 0;
}

__attribute__((used)) static int dio200_subdev_timer_read(struct comedi_device *dev,
				    struct comedi_subdevice *s,
				    struct comedi_insn *insn,
				    unsigned int *data)
{
	unsigned int n;

	for (n = 0; n < insn->n; n++)
		data[n] = dio200_read32(dev, DIO200_TS_COUNT);
	return n;
}

__attribute__((used)) static void dio200_subdev_timer_reset(struct comedi_device *dev,
				      struct comedi_subdevice *s)
{
	unsigned int clock;

	clock = dio200_read32(dev, DIO200_TS_CONFIG) & TS_CONFIG_CLK_SRC_MASK;
	dio200_write32(dev, DIO200_TS_CONFIG, clock | TS_CONFIG_RESET);
	dio200_write32(dev, DIO200_TS_CONFIG, clock);
}

__attribute__((used)) static void dio200_subdev_timer_get_clock_src(struct comedi_device *dev,
					      struct comedi_subdevice *s,
					      unsigned int *src,
					      unsigned int *period)
{
	unsigned int clk;

	clk = dio200_read32(dev, DIO200_TS_CONFIG) & TS_CONFIG_CLK_SRC_MASK;
	*src = clk;
	*period = (clk < ARRAY_SIZE(ts_clock_period)) ?
		  ts_clock_period[clk] : 0;
}

__attribute__((used)) static int dio200_subdev_timer_set_clock_src(struct comedi_device *dev,
					     struct comedi_subdevice *s,
					     unsigned int src)
{
	if (src > TS_CONFIG_MAX_CLK_SRC)
		return -EINVAL;
	dio200_write32(dev, DIO200_TS_CONFIG, src);
	return 0;
}

__attribute__((used)) static int dio200_subdev_timer_config(struct comedi_device *dev,
				      struct comedi_subdevice *s,
				      struct comedi_insn *insn,
				      unsigned int *data)
{
	int ret = 0;

	switch (data[0]) {
	case INSN_CONFIG_RESET:
		dio200_subdev_timer_reset(dev, s);
		break;
	case INSN_CONFIG_SET_CLOCK_SRC:
		ret = dio200_subdev_timer_set_clock_src(dev, s, data[1]);
		if (ret < 0)
			ret = -EINVAL;
		break;
	case INSN_CONFIG_GET_CLOCK_SRC:
		dio200_subdev_timer_get_clock_src(dev, s, &data[1], &data[2]);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret < 0 ? ret : insn->n;
}

void amplc_dio200_set_enhance(struct comedi_device *dev, unsigned char val)
{
	dio200_write8(dev, DIO200_ENHANCE, val);
}

int amplc_dio200_common_attach(struct comedi_device *dev, unsigned int irq,
			       unsigned long req_irq_flags)
{
	const struct dio200_board *board = dev->board_ptr;
	struct comedi_subdevice *s;
	unsigned int n;
	int ret;

	ret = comedi_alloc_subdevices(dev, board->n_subdevs);
	if (ret)
		return ret;

	for (n = 0; n < dev->n_subdevices; n++) {
		s = &dev->subdevices[n];
		switch (board->sdtype[n]) {
		case sd_8254:
			/* counter subdevice (8254) */
			ret = dio200_subdev_8254_init(dev, s,
						      board->sdinfo[n]);
			if (ret < 0)
				return ret;
			break;
		case sd_8255:
			/* digital i/o subdevice (8255) */
			ret = dio200_subdev_8255_init(dev, s,
						      board->sdinfo[n]);
			if (ret < 0)
				return ret;
			break;
		case sd_intr:
			/* 'INTERRUPT' subdevice */
			if (irq && !dev->read_subdev) {
				ret = dio200_subdev_intr_init(dev, s,
							      DIO200_INT_SCE,
							      board->sdinfo[n]);
				if (ret < 0)
					return ret;
				dev->read_subdev = s;
			} else {
				s->type = COMEDI_SUBD_UNUSED;
			}
			break;
		case sd_timer:
			s->type		= COMEDI_SUBD_TIMER;
			s->subdev_flags	= SDF_READABLE | SDF_LSAMPL;
			s->n_chan	= 1;
			s->maxdata	= 0xffffffff;
			s->insn_read	= dio200_subdev_timer_read;
			s->insn_config	= dio200_subdev_timer_config;
			break;
		default:
			s->type = COMEDI_SUBD_UNUSED;
			break;
		}
	}

	if (irq && dev->read_subdev) {
		if (request_irq(irq, dio200_interrupt, req_irq_flags,
				dev->board_name, dev) >= 0) {
			dev->irq = irq;
		} else {
			dev_warn(dev->class_dev,
				 "warning! irq %u unavailable!\n", irq);
		}
	}

	return 0;
}

