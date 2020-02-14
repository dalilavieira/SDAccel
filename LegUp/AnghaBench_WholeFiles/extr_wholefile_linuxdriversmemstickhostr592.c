#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct timer_list {int dummy; } ;
struct sg_mapping_iter {unsigned char* addr; int length; } ;
struct r592_device {int parallel_mode; int dummy_dma_page_physical_address; int dma_error; int dma_capable; scalar_t__ dummy_dma_page; struct memstick_host* host; scalar_t__ mmio; int /*<<< orphan*/  irq; TYPE_4__* req; int /*<<< orphan*/  io_thread; int /*<<< orphan*/  detect_timer; int /*<<< orphan*/  pio_fifo; int /*<<< orphan*/  dma_done; int /*<<< orphan*/  io_thread_lock; int /*<<< orphan*/  irq_lock; struct pci_dev* pci_dev; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct memstick_host {void (* request ) (struct memstick_host*) ;int (* set_param ) (struct memstick_host*,int,int) ;int /*<<< orphan*/  caps; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum memstick_param { ____Placeholder_memstick_param } memstick_param ;
struct TYPE_7__ {int length; } ;
struct TYPE_8__ {scalar_t__ data_dir; scalar_t__ tpc; unsigned char* data; int data_len; int error; int /*<<< orphan*/  int_reg; scalar_t__ need_card_int; TYPE_1__ sg; scalar_t__ long_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int DMA_IRQ_ACK_MASK ; 
 int DMA_IRQ_EN_MASK ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int EAGAIN ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int ENXIO ; 
 int ETIME ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_KFIFO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MEMSTICK_CAP_PAR4 ; 
#define  MEMSTICK_INTERFACE 133 
 int /*<<< orphan*/  MEMSTICK_INT_BREQ ; 
 int /*<<< orphan*/  MEMSTICK_INT_CED ; 
 int /*<<< orphan*/  MEMSTICK_INT_CMDNAK ; 
 int /*<<< orphan*/  MEMSTICK_INT_ERR ; 
#define  MEMSTICK_PAR4 132 
#define  MEMSTICK_POWER 131 
#define  MEMSTICK_POWER_OFF 130 
#define  MEMSTICK_POWER_ON 129 
#define  MEMSTICK_SERIAL 128 
 scalar_t__ MS_TPC_SET_RW_REG_ADRS ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PCI_DMA_FROMDEVICE ; 
 int /*<<< orphan*/  PCI_DMA_TODEVICE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int R592_FIFO_DMA ; 
 int R592_FIFO_DMA_SETTINGS ; 
 int R592_FIFO_DMA_SETTINGS_CAP ; 
 int R592_FIFO_DMA_SETTINGS_DIR ; 
 int R592_FIFO_DMA_SETTINGS_EN ; 
 int R592_FIFO_PIO ; 
 int R592_IO ; 
 int R592_IO_DIRECTION ; 
 int R592_IO_MODE ; 
 int R592_IO_MODE_PARALLEL ; 
 int R592_IO_MODE_SERIAL ; 
 int R592_IO_RESET ; 
 int R592_IO_SERIAL1 ; 
 int R592_IO_SERIAL2 ; 
 int R592_LFIFO_SIZE ; 
 int R592_POWER ; 
 int R592_POWER_0 ; 
 int R592_POWER_1 ; 
 int R592_POWER_20 ; 
 int R592_REG_MSC ; 
 int R592_REG_MSC_FIFO_DMA_DONE ; 
 int R592_REG_MSC_FIFO_DMA_ERR ; 
 int R592_REG_MSC_FIFO_EMPTY ; 
 int R592_REG_MSC_IRQ_INSERT ; 
 int R592_REG_MSC_IRQ_REMOVE ; 
 int R592_REG_MSC_LED ; 
 int R592_REG_MSC_PRSNT ; 
 int R592_STATUS ; 
 int R592_STATUS_CED ; 
 int R592_STATUS_P_BREQ ; 
 int R592_STATUS_P_CED ; 
 int R592_STATUS_P_CMDNACK ; 
 int R592_STATUS_P_INTERR ; 
 int R592_STATUS_RDY ; 
 int R592_STATUS_RECV_ERR ; 
 int R592_STATUS_SEND_ERR ; 
 int R592_TPC_EXEC ; 
 int R592_TPC_EXEC_BIG_FIFO ; 
 int R592_TPC_EXEC_LEN_SHIFT ; 
 int R592_TPC_EXEC_TPC_SHIFT ; 
 int SG_MITER_ATOMIC ; 
 int SG_MITER_FROM_SG ; 
 int SG_MITER_TO_SG ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  TASK_RUNNING ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ WRITE ; 
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int be32_to_cpu (int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dbg (char*,...) ; 
 int /*<<< orphan*/  dbg_reg (char*,int,int,...) ; 
 int /*<<< orphan*/  dbg_verbose (char*) ; 
 int /*<<< orphan*/  detect_timer ; 
 struct r592_device* dev ; 
 scalar_t__ dma_alloc_coherent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int dma_map_sg (int /*<<< orphan*/ *,TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int dma_set_mask (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_unmap_sg (int /*<<< orphan*/ *,TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct r592_device*) ; 
 struct r592_device* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 unsigned long jiffies ; 
 int kfifo_in (int /*<<< orphan*/ *,unsigned char*,int) ; 
 scalar_t__ kfifo_is_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfifo_is_full (int /*<<< orphan*/ *) ; 
 int kfifo_out (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  kfifo_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kthread_run (int (*) (void*),struct r592_device*,char*) ; 
 scalar_t__ kthread_should_stop () ; 
 int /*<<< orphan*/  kthread_stop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 scalar_t__ memstick_add_host (struct memstick_host*) ; 
 struct memstick_host* memstick_alloc_host (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memstick_detect_change (struct memstick_host*) ; 
 int /*<<< orphan*/  memstick_free_host (struct memstick_host*) ; 
 int memstick_next_req (struct memstick_host*,TYPE_4__**) ; 
 struct r592_device* memstick_priv (struct memstick_host*) ; 
 int /*<<< orphan*/  memstick_remove_host (struct memstick_host*) ; 
 int /*<<< orphan*/  message (char*,...) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct r592_device* pci_get_drvdata (struct pci_dev*) ; 
 scalar_t__ pci_ioremap_bar (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct r592_device*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 scalar_t__ r592_enable_dma ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 scalar_t__ request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct r592_device*) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 int sg_dma_address (TYPE_1__*) ; 
 int sg_dma_len (TYPE_1__*) ; 
 scalar_t__ sg_miter_next (struct sg_mapping_iter*) ; 
 int /*<<< orphan*/  sg_miter_start (struct sg_mapping_iter*,TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  sg_miter_stop (struct sg_mapping_iter*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 char const** tpc_names ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ wake_up_process (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

const char *memstick_debug_get_tpc_name(int tpc)
{
	return tpc_names[tpc-1];
}

__attribute__((used)) static inline u32 r592_read_reg(struct r592_device *dev, int address)
{
	u32 value = readl(dev->mmio + address);
	dbg_reg("reg #%02d == 0x%08x", address, value);
	return value;
}

__attribute__((used)) static inline void r592_write_reg(struct r592_device *dev,
							int address, u32 value)
{
	dbg_reg("reg #%02d <- 0x%08x", address, value);
	writel(value, dev->mmio + address);
}

__attribute__((used)) static inline u32 r592_read_reg_raw_be(struct r592_device *dev, int address)
{
	u32 value = __raw_readl(dev->mmio + address);
	dbg_reg("reg #%02d == 0x%08x", address, value);
	return be32_to_cpu(value);
}

__attribute__((used)) static inline void r592_write_reg_raw_be(struct r592_device *dev,
							int address, u32 value)
{
	dbg_reg("reg #%02d <- 0x%08x", address, value);
	__raw_writel(cpu_to_be32(value), dev->mmio + address);
}

__attribute__((used)) static inline void r592_set_reg_mask(struct r592_device *dev,
							int address, u32 mask)
{
	u32 reg = readl(dev->mmio + address);
	dbg_reg("reg #%02d |= 0x%08x (old =0x%08x)", address, mask, reg);
	writel(reg | mask , dev->mmio + address);
}

__attribute__((used)) static inline void r592_clear_reg_mask(struct r592_device *dev,
						int address, u32 mask)
{
	u32 reg = readl(dev->mmio + address);
	dbg_reg("reg #%02d &= 0x%08x (old = 0x%08x, mask = 0x%08x)",
						address, ~mask, reg, mask);
	writel(reg & ~mask, dev->mmio + address);
}

__attribute__((used)) static int r592_wait_status(struct r592_device *dev, u32 mask, u32 wanted_mask)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(1000);
	u32 reg = r592_read_reg(dev, R592_STATUS);

	if ((reg & mask) == wanted_mask)
		return 0;

	while (time_before(jiffies, timeout)) {

		reg = r592_read_reg(dev, R592_STATUS);

		if ((reg & mask) == wanted_mask)
			return 0;

		if (reg & (R592_STATUS_SEND_ERR | R592_STATUS_RECV_ERR))
			return -EIO;

		cpu_relax();
	}
	return -ETIME;
}

__attribute__((used)) static int r592_enable_device(struct r592_device *dev, bool enable)
{
	dbg("%sabling the device", enable ? "en" : "dis");

	if (enable) {

		/* Power up the card */
		r592_write_reg(dev, R592_POWER, R592_POWER_0 | R592_POWER_1);

		/* Perform a reset */
		r592_set_reg_mask(dev, R592_IO, R592_IO_RESET);

		msleep(100);
	} else
		/* Power down the card */
		r592_write_reg(dev, R592_POWER, 0);

	return 0;
}

__attribute__((used)) static int r592_set_mode(struct r592_device *dev, bool parallel_mode)
{
	if (!parallel_mode) {
		dbg("switching to serial mode");

		/* Set serial mode */
		r592_write_reg(dev, R592_IO_MODE, R592_IO_MODE_SERIAL);

		r592_clear_reg_mask(dev, R592_POWER, R592_POWER_20);

	} else {
		dbg("switching to parallel mode");

		/* This setting should be set _before_ switch TPC */
		r592_set_reg_mask(dev, R592_POWER, R592_POWER_20);

		r592_clear_reg_mask(dev, R592_IO,
			R592_IO_SERIAL1 | R592_IO_SERIAL2);

		/* Set the parallel mode now */
		r592_write_reg(dev, R592_IO_MODE, R592_IO_MODE_PARALLEL);
	}

	dev->parallel_mode = parallel_mode;
	return 0;
}

__attribute__((used)) static void r592_host_reset(struct r592_device *dev)
{
	r592_set_reg_mask(dev, R592_IO, R592_IO_RESET);
	msleep(100);
	r592_set_mode(dev, dev->parallel_mode);
}

__attribute__((used)) static int r592_test_io_error(struct r592_device *dev)
{
	if (!(r592_read_reg(dev, R592_STATUS) &
		(R592_STATUS_SEND_ERR | R592_STATUS_RECV_ERR)))
		return 0;

	return -EIO;
}

__attribute__((used)) static int r592_test_fifo_empty(struct r592_device *dev)
{
	if (r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_FIFO_EMPTY)
		return 0;

	dbg("FIFO not ready, trying to reset the device");
	r592_host_reset(dev);

	if (r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_FIFO_EMPTY)
		return 0;

	message("FIFO still not ready, giving up");
	return -EIO;
}

__attribute__((used)) static void r592_start_dma(struct r592_device *dev, bool is_write)
{
	unsigned long flags;
	u32 reg;
	spin_lock_irqsave(&dev->irq_lock, flags);

	/* Ack interrupts (just in case) + enable them */
	r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_ACK_MASK);
	r592_set_reg_mask(dev, R592_REG_MSC, DMA_IRQ_EN_MASK);

	/* Set DMA address */
	r592_write_reg(dev, R592_FIFO_DMA, sg_dma_address(&dev->req->sg));

	/* Enable the DMA */
	reg = r592_read_reg(dev, R592_FIFO_DMA_SETTINGS);
	reg |= R592_FIFO_DMA_SETTINGS_EN;

	if (!is_write)
		reg |= R592_FIFO_DMA_SETTINGS_DIR;
	else
		reg &= ~R592_FIFO_DMA_SETTINGS_DIR;
	r592_write_reg(dev, R592_FIFO_DMA_SETTINGS, reg);

	spin_unlock_irqrestore(&dev->irq_lock, flags);
}

__attribute__((used)) static void r592_stop_dma(struct r592_device *dev, int error)
{
	r592_clear_reg_mask(dev, R592_FIFO_DMA_SETTINGS,
		R592_FIFO_DMA_SETTINGS_EN);

	/* This is only a precation */
	r592_write_reg(dev, R592_FIFO_DMA,
			dev->dummy_dma_page_physical_address);

	r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_EN_MASK);
	r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_ACK_MASK);
	dev->dma_error = error;
}

__attribute__((used)) static void r592_check_dma(struct r592_device *dev)
{
	dev->dma_capable = r592_enable_dma &&
		(r592_read_reg(dev, R592_FIFO_DMA_SETTINGS) &
			R592_FIFO_DMA_SETTINGS_CAP);
}

__attribute__((used)) static int r592_transfer_fifo_dma(struct r592_device *dev)
{
	int len, sg_count;
	bool is_write;

	if (!dev->dma_capable || !dev->req->long_data)
		return -EINVAL;

	len = dev->req->sg.length;
	is_write = dev->req->data_dir == WRITE;

	if (len != R592_LFIFO_SIZE)
		return -EINVAL;

	dbg_verbose("doing dma transfer");

	dev->dma_error = 0;
	reinit_completion(&dev->dma_done);

	/* TODO: hidden assumption about nenth beeing always 1 */
	sg_count = dma_map_sg(&dev->pci_dev->dev, &dev->req->sg, 1, is_write ?
		PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE);

	if (sg_count != 1 || sg_dma_len(&dev->req->sg) < R592_LFIFO_SIZE) {
		message("problem in dma_map_sg");
		return -EIO;
	}

	r592_start_dma(dev, is_write);

	/* Wait for DMA completion */
	if (!wait_for_completion_timeout(
			&dev->dma_done, msecs_to_jiffies(1000))) {
		message("DMA timeout");
		r592_stop_dma(dev, -ETIMEDOUT);
	}

	dma_unmap_sg(&dev->pci_dev->dev, &dev->req->sg, 1, is_write ?
		PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE);


	return dev->dma_error;
}

__attribute__((used)) static void r592_write_fifo_pio(struct r592_device *dev,
					unsigned char *buffer, int len)
{
	/* flush spill from former write */
	if (!kfifo_is_empty(&dev->pio_fifo)) {

		u8 tmp[4] = {0};
		int copy_len = kfifo_in(&dev->pio_fifo, buffer, len);

		if (!kfifo_is_full(&dev->pio_fifo))
			return;
		len -= copy_len;
		buffer += copy_len;

		copy_len = kfifo_out(&dev->pio_fifo, tmp, 4);
		WARN_ON(copy_len != 4);
		r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)tmp);
	}

	WARN_ON(!kfifo_is_empty(&dev->pio_fifo));

	/* write full dwords */
	while (len >= 4) {
		r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)buffer);
		buffer += 4;
		len -= 4;
	}

	/* put remaining bytes to the spill */
	if (len)
		kfifo_in(&dev->pio_fifo, buffer, len);
}

__attribute__((used)) static void r592_flush_fifo_write(struct r592_device *dev)
{
	u8 buffer[4] = { 0 };
	int len;

	if (kfifo_is_empty(&dev->pio_fifo))
		return;

	len = kfifo_out(&dev->pio_fifo, buffer, 4);
	r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)buffer);
}

__attribute__((used)) static void r592_read_fifo_pio(struct r592_device *dev,
						unsigned char *buffer, int len)
{
	u8 tmp[4];

	/* Read from last spill */
	if (!kfifo_is_empty(&dev->pio_fifo)) {
		int bytes_copied =
			kfifo_out(&dev->pio_fifo, buffer, min(4, len));
		buffer += bytes_copied;
		len -= bytes_copied;

		if (!kfifo_is_empty(&dev->pio_fifo))
			return;
	}

	/* Reads dwords from FIFO */
	while (len >= 4) {
		*(u32 *)buffer = r592_read_reg_raw_be(dev, R592_FIFO_PIO);
		buffer += 4;
		len -= 4;
	}

	if (len) {
		*(u32 *)tmp = r592_read_reg_raw_be(dev, R592_FIFO_PIO);
		kfifo_in(&dev->pio_fifo, tmp, 4);
		len -= kfifo_out(&dev->pio_fifo, buffer, len);
	}

	WARN_ON(len);
	return;
}

__attribute__((used)) static int r592_transfer_fifo_pio(struct r592_device *dev)
{
	unsigned long flags;

	bool is_write = dev->req->tpc >= MS_TPC_SET_RW_REG_ADRS;
	struct sg_mapping_iter miter;

	kfifo_reset(&dev->pio_fifo);

	if (!dev->req->long_data) {
		if (is_write) {
			r592_write_fifo_pio(dev, dev->req->data,
							dev->req->data_len);
			r592_flush_fifo_write(dev);
		} else
			r592_read_fifo_pio(dev, dev->req->data,
							dev->req->data_len);
		return 0;
	}

	local_irq_save(flags);
	sg_miter_start(&miter, &dev->req->sg, 1, SG_MITER_ATOMIC |
		(is_write ? SG_MITER_FROM_SG : SG_MITER_TO_SG));

	/* Do the transfer fifo<->memory*/
	while (sg_miter_next(&miter))
		if (is_write)
			r592_write_fifo_pio(dev, miter.addr, miter.length);
		else
			r592_read_fifo_pio(dev, miter.addr, miter.length);


	/* Write last few non aligned bytes*/
	if (is_write)
		r592_flush_fifo_write(dev);

	sg_miter_stop(&miter);
	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static void r592_execute_tpc(struct r592_device *dev)
{
	bool is_write;
	int len, error;
	u32 status, reg;

	if (!dev->req) {
		message("BUG: tpc execution without request!");
		return;
	}

	is_write = dev->req->tpc >= MS_TPC_SET_RW_REG_ADRS;
	len = dev->req->long_data ?
		dev->req->sg.length : dev->req->data_len;

	/* Ensure that FIFO can hold the input data */
	if (len > R592_LFIFO_SIZE) {
		message("IO: hardware doesn't support TPCs longer that 512");
		error = -ENOSYS;
		goto out;
	}

	if (!(r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_PRSNT)) {
		dbg("IO: refusing to send TPC because card is absent");
		error = -ENODEV;
		goto out;
	}

	dbg("IO: executing %s LEN=%d",
			memstick_debug_get_tpc_name(dev->req->tpc), len);

	/* Set IO direction */
	if (is_write)
		r592_set_reg_mask(dev, R592_IO, R592_IO_DIRECTION);
	else
		r592_clear_reg_mask(dev, R592_IO, R592_IO_DIRECTION);


	error = r592_test_fifo_empty(dev);
	if (error)
		goto out;

	/* Transfer write data */
	if (is_write) {
		error = r592_transfer_fifo_dma(dev);
		if (error == -EINVAL)
			error = r592_transfer_fifo_pio(dev);
	}

	if (error)
		goto out;

	/* Trigger the TPC */
	reg = (len << R592_TPC_EXEC_LEN_SHIFT) |
		(dev->req->tpc << R592_TPC_EXEC_TPC_SHIFT) |
			R592_TPC_EXEC_BIG_FIFO;

	r592_write_reg(dev, R592_TPC_EXEC, reg);

	/* Wait for TPC completion */
	status = R592_STATUS_RDY;
	if (dev->req->need_card_int)
		status |= R592_STATUS_CED;

	error = r592_wait_status(dev, status, status);
	if (error) {
		message("card didn't respond");
		goto out;
	}

	/* Test IO errors */
	error = r592_test_io_error(dev);
	if (error) {
		dbg("IO error");
		goto out;
	}

	/* Read data from FIFO */
	if (!is_write) {
		error = r592_transfer_fifo_dma(dev);
		if (error == -EINVAL)
			error = r592_transfer_fifo_pio(dev);
	}

	/* read INT reg. This can be shortened with shifts, but that way
		its more readable */
	if (dev->parallel_mode && dev->req->need_card_int) {

		dev->req->int_reg = 0;
		status = r592_read_reg(dev, R592_STATUS);

		if (status & R592_STATUS_P_CMDNACK)
			dev->req->int_reg |= MEMSTICK_INT_CMDNAK;
		if (status & R592_STATUS_P_BREQ)
			dev->req->int_reg |= MEMSTICK_INT_BREQ;
		if (status & R592_STATUS_P_INTERR)
			dev->req->int_reg |= MEMSTICK_INT_ERR;
		if (status & R592_STATUS_P_CED)
			dev->req->int_reg |= MEMSTICK_INT_CED;
	}

	if (error)
		dbg("FIFO read error");
out:
	dev->req->error = error;
	r592_clear_reg_mask(dev, R592_REG_MSC, R592_REG_MSC_LED);
	return;
}

__attribute__((used)) static int r592_process_thread(void *data)
{
	int error;
	struct r592_device *dev = (struct r592_device *)data;
	unsigned long flags;

	while (!kthread_should_stop()) {
		spin_lock_irqsave(&dev->io_thread_lock, flags);
		set_current_state(TASK_INTERRUPTIBLE);
		error = memstick_next_req(dev->host, &dev->req);
		spin_unlock_irqrestore(&dev->io_thread_lock, flags);

		if (error) {
			if (error == -ENXIO || error == -EAGAIN) {
				dbg_verbose("IO: done IO, sleeping");
			} else {
				dbg("IO: unknown error from "
					"memstick_next_req %d", error);
			}

			if (kthread_should_stop())
				set_current_state(TASK_RUNNING);

			schedule();
		} else {
			set_current_state(TASK_RUNNING);
			r592_execute_tpc(dev);
		}
	}
	return 0;
}

__attribute__((used)) static void r592_update_card_detect(struct r592_device *dev)
{
	u32 reg = r592_read_reg(dev, R592_REG_MSC);
	bool card_detected = reg & R592_REG_MSC_PRSNT;

	dbg("update card detect. card state: %s", card_detected ?
		"present" : "absent");

	reg &= ~((R592_REG_MSC_IRQ_REMOVE | R592_REG_MSC_IRQ_INSERT) << 16);

	if (card_detected)
		reg |= (R592_REG_MSC_IRQ_REMOVE << 16);
	else
		reg |= (R592_REG_MSC_IRQ_INSERT << 16);

	r592_write_reg(dev, R592_REG_MSC, reg);
}

__attribute__((used)) static void r592_detect_timer(struct timer_list *t)
{
	struct r592_device *dev = from_timer(dev, t, detect_timer);
	r592_update_card_detect(dev);
	memstick_detect_change(dev->host);
}

__attribute__((used)) static irqreturn_t r592_irq(int irq, void *data)
{
	struct r592_device *dev = (struct r592_device *)data;
	irqreturn_t ret = IRQ_NONE;
	u32 reg;
	u16 irq_enable, irq_status;
	unsigned long flags;
	int error;

	spin_lock_irqsave(&dev->irq_lock, flags);

	reg = r592_read_reg(dev, R592_REG_MSC);
	irq_enable = reg >> 16;
	irq_status = reg & 0xFFFF;

	/* Ack the interrupts */
	reg &= ~irq_status;
	r592_write_reg(dev, R592_REG_MSC, reg);

	/* Get the IRQ status minus bits that aren't enabled */
	irq_status &= (irq_enable);

	/* Due to limitation of memstick core, we don't look at bits that
		indicate that card was removed/inserted and/or present */
	if (irq_status & (R592_REG_MSC_IRQ_INSERT | R592_REG_MSC_IRQ_REMOVE)) {

		bool card_was_added = irq_status & R592_REG_MSC_IRQ_INSERT;
		ret = IRQ_HANDLED;

		message("IRQ: card %s", card_was_added ? "added" : "removed");

		mod_timer(&dev->detect_timer,
			jiffies + msecs_to_jiffies(card_was_added ? 500 : 50));
	}

	if (irq_status &
		(R592_REG_MSC_FIFO_DMA_DONE | R592_REG_MSC_FIFO_DMA_ERR)) {
		ret = IRQ_HANDLED;

		if (irq_status & R592_REG_MSC_FIFO_DMA_ERR) {
			message("IRQ: DMA error");
			error = -EIO;
		} else {
			dbg_verbose("IRQ: dma done");
			error = 0;
		}

		r592_stop_dma(dev, error);
		complete(&dev->dma_done);
	}

	spin_unlock_irqrestore(&dev->irq_lock, flags);
	return ret;
}

__attribute__((used)) static int r592_set_param(struct memstick_host *host,
			enum memstick_param param, int value)
{
	struct r592_device *dev = memstick_priv(host);

	switch (param) {
	case MEMSTICK_POWER:
		switch (value) {
		case MEMSTICK_POWER_ON:
			return r592_enable_device(dev, true);
		case MEMSTICK_POWER_OFF:
			return r592_enable_device(dev, false);
		default:
			return -EINVAL;
		}
	case MEMSTICK_INTERFACE:
		switch (value) {
		case MEMSTICK_SERIAL:
			return r592_set_mode(dev, 0);
		case MEMSTICK_PAR4:
			return r592_set_mode(dev, 1);
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static void r592_submit_req(struct memstick_host *host)
{
	struct r592_device *dev = memstick_priv(host);
	unsigned long flags;

	if (dev->req)
		return;

	spin_lock_irqsave(&dev->io_thread_lock, flags);
	if (wake_up_process(dev->io_thread))
		dbg_verbose("IO thread woken to process requests");
	spin_unlock_irqrestore(&dev->io_thread_lock, flags);
}

__attribute__((used)) static int r592_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	int error = -ENOMEM;
	struct memstick_host *host;
	struct r592_device *dev;

	/* Allocate memory */
	host = memstick_alloc_host(sizeof(struct r592_device), &pdev->dev);
	if (!host)
		goto error1;

	dev = memstick_priv(host);
	dev->host = host;
	dev->pci_dev = pdev;
	pci_set_drvdata(pdev, dev);

	/* pci initialization */
	error = pci_enable_device(pdev);
	if (error)
		goto error2;

	pci_set_master(pdev);
	error = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
	if (error)
		goto error3;

	error = pci_request_regions(pdev, DRV_NAME);
	if (error)
		goto error3;

	dev->mmio = pci_ioremap_bar(pdev, 0);
	if (!dev->mmio)
		goto error4;

	dev->irq = pdev->irq;
	spin_lock_init(&dev->irq_lock);
	spin_lock_init(&dev->io_thread_lock);
	init_completion(&dev->dma_done);
	INIT_KFIFO(dev->pio_fifo);
	timer_setup(&dev->detect_timer, r592_detect_timer, 0);

	/* Host initialization */
	host->caps = MEMSTICK_CAP_PAR4;
	host->request = r592_submit_req;
	host->set_param = r592_set_param;
	r592_check_dma(dev);

	dev->io_thread = kthread_run(r592_process_thread, dev, "r592_io");
	if (IS_ERR(dev->io_thread)) {
		error = PTR_ERR(dev->io_thread);
		goto error5;
	}

	/* This is just a precation, so don't fail */
	dev->dummy_dma_page = dma_alloc_coherent(&pdev->dev, PAGE_SIZE,
		&dev->dummy_dma_page_physical_address, GFP_KERNEL);
	r592_stop_dma(dev , 0);

	if (request_irq(dev->irq, &r592_irq, IRQF_SHARED,
			  DRV_NAME, dev))
		goto error6;

	r592_update_card_detect(dev);
	if (memstick_add_host(host))
		goto error7;

	message("driver successfully loaded");
	return 0;
error7:
	free_irq(dev->irq, dev);
error6:
	if (dev->dummy_dma_page)
		dma_free_coherent(&pdev->dev, PAGE_SIZE, dev->dummy_dma_page,
			dev->dummy_dma_page_physical_address);

	kthread_stop(dev->io_thread);
error5:
	iounmap(dev->mmio);
error4:
	pci_release_regions(pdev);
error3:
	pci_disable_device(pdev);
error2:
	memstick_free_host(host);
error1:
	return error;
}

__attribute__((used)) static void r592_remove(struct pci_dev *pdev)
{
	int error = 0;
	struct r592_device *dev = pci_get_drvdata(pdev);

	/* Stop the processing thread.
	That ensures that we won't take any more requests */
	kthread_stop(dev->io_thread);

	r592_enable_device(dev, false);

	while (!error && dev->req) {
		dev->req->error = -ETIME;
		error = memstick_next_req(dev->host, &dev->req);
	}
	memstick_remove_host(dev->host);

	free_irq(dev->irq, dev);
	iounmap(dev->mmio);
	pci_release_regions(pdev);
	pci_disable_device(pdev);
	memstick_free_host(dev->host);

	if (dev->dummy_dma_page)
		dma_free_coherent(&pdev->dev, PAGE_SIZE, dev->dummy_dma_page,
			dev->dummy_dma_page_physical_address);
}

