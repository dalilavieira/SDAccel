#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct c67x00_sie {int sie_num; struct c67x00_device* dev; } ;
struct c67x00_lcp_int_data {int* regs; } ;
struct TYPE_5__ {int last_msg; int /*<<< orphan*/  msg_received; int /*<<< orphan*/  mutex; } ;
struct TYPE_6__ {int regstep; TYPE_2__ lcp; int /*<<< orphan*/  lock; scalar_t__ base; } ;
struct c67x00_device {TYPE_3__ hpi; TYPE_1__* pdev; } ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int C67X00_SIES ; 
 int COMM_EXEC_INT ; 
 int COMM_INT_NUM ; 
 int COMM_R (int) ; 
 int COMM_REGS ; 
 int COMM_RESET ; 
 int DONE_IRQ_EN ; 
 int EIO ; 
 int HOST_FRAME_REG (int) ; 
 int HOST_IRQ_EN_REG (int) ; 
 int HOST_MODE ; 
 int HOST_STAT_MASK ; 
 int HPI_ADDR ; 
 int HPI_DATA ; 
 int HPI_IRQ_ROUTING_REG ; 
 int HPI_MAILBOX ; 
 int HPI_STATUS ; 
 int /*<<< orphan*/  HPI_T_CYC_NS ; 
 int HUSB_RESET_INT ; 
 int HUSB_SIE_INIT_INT (int) ; 
 int HUSB_SIE_pCurrentTDPtr (int) ; 
 int HUSB_pEOT ; 
 int HZ ; 
 int MBX_OUT_FLG ; 
 int PORT_CONNECT_CHANGE (int) ; 
 int PORT_RES_EN (int) ; 
 int SIEMSG_REG (int) ; 
 int SOFEOP_TO_CPU_EN (int) ; 
 int SOFEOP_TO_HPI_EN (int) ; 
 int SOF_EOP_IRQ_EN ; 
 int USB_CTL_REG (int) ; 
 int USB_STAT_REG (int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __raw_readw (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writew (int,scalar_t__) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ndelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sie_dev (struct c67x00_sie*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int wait_for_completion_timeout (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline u16 hpi_read_reg(struct c67x00_device *dev, int reg)
{
	ndelay(HPI_T_CYC_NS);
	return __raw_readw(dev->hpi.base + reg * dev->hpi.regstep);
}

__attribute__((used)) static inline void hpi_write_reg(struct c67x00_device *dev, int reg, u16 value)
{
	ndelay(HPI_T_CYC_NS);
	__raw_writew(value, dev->hpi.base + reg * dev->hpi.regstep);
}

__attribute__((used)) static inline u16 hpi_read_word_nolock(struct c67x00_device *dev, u16 reg)
{
	hpi_write_reg(dev, HPI_ADDR, reg);
	return hpi_read_reg(dev, HPI_DATA);
}

__attribute__((used)) static u16 hpi_read_word(struct c67x00_device *dev, u16 reg)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_word_nolock(dev, reg);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);

	return value;
}

__attribute__((used)) static void hpi_write_word_nolock(struct c67x00_device *dev, u16 reg, u16 value)
{
	hpi_write_reg(dev, HPI_ADDR, reg);
	hpi_write_reg(dev, HPI_DATA, value);
}

__attribute__((used)) static void hpi_write_word(struct c67x00_device *dev, u16 reg, u16 value)
{
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	hpi_write_word_nolock(dev, reg, value);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}

__attribute__((used)) static void hpi_write_words_le16(struct c67x00_device *dev, u16 addr,
				 __le16 *data, u16 count)
{
	unsigned long flags;
	int i;

	spin_lock_irqsave(&dev->hpi.lock, flags);

	hpi_write_reg(dev, HPI_ADDR, addr);
	for (i = 0; i < count; i++)
		hpi_write_reg(dev, HPI_DATA, le16_to_cpu(*data++));

	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}

__attribute__((used)) static void hpi_read_words_le16(struct c67x00_device *dev, u16 addr,
				__le16 *data, u16 count)
{
	unsigned long flags;
	int i;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	hpi_write_reg(dev, HPI_ADDR, addr);
	for (i = 0; i < count; i++)
		*data++ = cpu_to_le16(hpi_read_reg(dev, HPI_DATA));

	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}

__attribute__((used)) static void hpi_set_bits(struct c67x00_device *dev, u16 reg, u16 mask)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_word_nolock(dev, reg);
	hpi_write_word_nolock(dev, reg, value | mask);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}

__attribute__((used)) static void hpi_clear_bits(struct c67x00_device *dev, u16 reg, u16 mask)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_word_nolock(dev, reg);
	hpi_write_word_nolock(dev, reg, value & ~mask);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}

__attribute__((used)) static u16 hpi_recv_mbox(struct c67x00_device *dev)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_reg(dev, HPI_MAILBOX);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);

	return value;
}

__attribute__((used)) static u16 hpi_send_mbox(struct c67x00_device *dev, u16 value)
{
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	hpi_write_reg(dev, HPI_MAILBOX, value);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);

	return value;
}

u16 c67x00_ll_hpi_status(struct c67x00_device *dev)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_reg(dev, HPI_STATUS);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);

	return value;
}

void c67x00_ll_hpi_reg_init(struct c67x00_device *dev)
{
	int i;

	hpi_recv_mbox(dev);
	c67x00_ll_hpi_status(dev);
	hpi_write_word(dev, HPI_IRQ_ROUTING_REG, 0);

	for (i = 0; i < C67X00_SIES; i++) {
		hpi_write_word(dev, SIEMSG_REG(i), 0);
		hpi_read_word(dev, SIEMSG_REG(i));
	}
}

void c67x00_ll_hpi_enable_sofeop(struct c67x00_sie *sie)
{
	hpi_set_bits(sie->dev, HPI_IRQ_ROUTING_REG,
		     SOFEOP_TO_HPI_EN(sie->sie_num));
}

void c67x00_ll_hpi_disable_sofeop(struct c67x00_sie *sie)
{
	hpi_clear_bits(sie->dev, HPI_IRQ_ROUTING_REG,
		       SOFEOP_TO_HPI_EN(sie->sie_num));
}

__attribute__((used)) static inline int ll_recv_msg(struct c67x00_device *dev)
{
	u16 res;

	res = wait_for_completion_timeout(&dev->hpi.lcp.msg_received, 5 * HZ);
	WARN_ON(!res);

	return (res == 0) ? -EIO : 0;
}

u16 c67x00_ll_fetch_siemsg(struct c67x00_device *dev, int sie_num)
{
	u16 val;

	val = hpi_read_word(dev, SIEMSG_REG(sie_num));
	/* clear register to allow next message */
	hpi_write_word(dev, SIEMSG_REG(sie_num), 0);

	return val;
}

u16 c67x00_ll_get_usb_ctl(struct c67x00_sie *sie)
{
	return hpi_read_word(sie->dev, USB_CTL_REG(sie->sie_num));
}

void c67x00_ll_usb_clear_status(struct c67x00_sie *sie, u16 bits)
{
	hpi_write_word(sie->dev, USB_STAT_REG(sie->sie_num), bits);
}

u16 c67x00_ll_usb_get_status(struct c67x00_sie *sie)
{
	return hpi_read_word(sie->dev, USB_STAT_REG(sie->sie_num));
}

__attribute__((used)) static int c67x00_comm_exec_int(struct c67x00_device *dev, u16 nr,
				struct c67x00_lcp_int_data *data)
{
	int i, rc;

	mutex_lock(&dev->hpi.lcp.mutex);
	hpi_write_word(dev, COMM_INT_NUM, nr);
	for (i = 0; i < COMM_REGS; i++)
		hpi_write_word(dev, COMM_R(i), data->regs[i]);
	hpi_send_mbox(dev, COMM_EXEC_INT);
	rc = ll_recv_msg(dev);
	mutex_unlock(&dev->hpi.lcp.mutex);

	return rc;
}

void c67x00_ll_set_husb_eot(struct c67x00_device *dev, u16 value)
{
	mutex_lock(&dev->hpi.lcp.mutex);
	hpi_write_word(dev, HUSB_pEOT, value);
	mutex_unlock(&dev->hpi.lcp.mutex);
}

__attribute__((used)) static inline void c67x00_ll_husb_sie_init(struct c67x00_sie *sie)
{
	struct c67x00_device *dev = sie->dev;
	struct c67x00_lcp_int_data data;
	int rc;

	rc = c67x00_comm_exec_int(dev, HUSB_SIE_INIT_INT(sie->sie_num), &data);
	BUG_ON(rc); /* No return path for error code; crash spectacularly */
}

void c67x00_ll_husb_reset(struct c67x00_sie *sie, int port)
{
	struct c67x00_device *dev = sie->dev;
	struct c67x00_lcp_int_data data;
	int rc;

	data.regs[0] = 50;	/* Reset USB port for 50ms */
	data.regs[1] = port | (sie->sie_num << 1);
	rc = c67x00_comm_exec_int(dev, HUSB_RESET_INT, &data);
	BUG_ON(rc); /* No return path for error code; crash spectacularly */
}

void c67x00_ll_husb_set_current_td(struct c67x00_sie *sie, u16 addr)
{
	hpi_write_word(sie->dev, HUSB_SIE_pCurrentTDPtr(sie->sie_num), addr);
}

u16 c67x00_ll_husb_get_current_td(struct c67x00_sie *sie)
{
	return hpi_read_word(sie->dev, HUSB_SIE_pCurrentTDPtr(sie->sie_num));
}

u16 c67x00_ll_husb_get_frame(struct c67x00_sie *sie)
{
	return hpi_read_word(sie->dev, HOST_FRAME_REG(sie->sie_num));
}

void c67x00_ll_husb_init_host_port(struct c67x00_sie *sie)
{
	/* Set port into host mode */
	hpi_set_bits(sie->dev, USB_CTL_REG(sie->sie_num), HOST_MODE);
	c67x00_ll_husb_sie_init(sie);
	/* Clear interrupts */
	c67x00_ll_usb_clear_status(sie, HOST_STAT_MASK);
	/* Check */
	if (!(hpi_read_word(sie->dev, USB_CTL_REG(sie->sie_num)) & HOST_MODE))
		dev_warn(sie_dev(sie),
			 "SIE %d not set to host mode\n", sie->sie_num);
}

void c67x00_ll_husb_reset_port(struct c67x00_sie *sie, int port)
{
	/* Clear connect change */
	c67x00_ll_usb_clear_status(sie, PORT_CONNECT_CHANGE(port));

	/* Enable interrupts */
	hpi_set_bits(sie->dev, HPI_IRQ_ROUTING_REG,
		     SOFEOP_TO_CPU_EN(sie->sie_num));
	hpi_set_bits(sie->dev, HOST_IRQ_EN_REG(sie->sie_num),
		     SOF_EOP_IRQ_EN | DONE_IRQ_EN);

	/* Enable pull down transistors */
	hpi_set_bits(sie->dev, USB_CTL_REG(sie->sie_num), PORT_RES_EN(port));
}

void c67x00_ll_irq(struct c67x00_device *dev, u16 int_status)
{
	if ((int_status & MBX_OUT_FLG) == 0)
		return;

	dev->hpi.lcp.last_msg = hpi_recv_mbox(dev);
	complete(&dev->hpi.lcp.msg_received);
}

int c67x00_ll_reset(struct c67x00_device *dev)
{
	int rc;

	mutex_lock(&dev->hpi.lcp.mutex);
	hpi_send_mbox(dev, COMM_RESET);
	rc = ll_recv_msg(dev);
	mutex_unlock(&dev->hpi.lcp.mutex);

	return rc;
}

void c67x00_ll_write_mem_le16(struct c67x00_device *dev, u16 addr,
			      void *data, int len)
{
	u8 *buf = data;

	/* Sanity check */
	if (addr + len > 0xffff) {
		dev_err(&dev->pdev->dev,
			"Trying to write beyond writable region!\n");
		return;
	}

	if (addr & 0x01) {
		/* unaligned access */
		u16 tmp;
		tmp = hpi_read_word(dev, addr - 1);
		tmp = (tmp & 0x00ff) | (*buf++ << 8);
		hpi_write_word(dev, addr - 1, tmp);
		addr++;
		len--;
	}

	hpi_write_words_le16(dev, addr, (__le16 *)buf, len / 2);
	buf += len & ~0x01;
	addr += len & ~0x01;
	len &= 0x01;

	if (len) {
		u16 tmp;
		tmp = hpi_read_word(dev, addr);
		tmp = (tmp & 0xff00) | *buf;
		hpi_write_word(dev, addr, tmp);
	}
}

void c67x00_ll_read_mem_le16(struct c67x00_device *dev, u16 addr,
			     void *data, int len)
{
	u8 *buf = data;

	if (addr & 0x01) {
		/* unaligned access */
		u16 tmp;
		tmp = hpi_read_word(dev, addr - 1);
		*buf++ = (tmp >> 8) & 0x00ff;
		addr++;
		len--;
	}

	hpi_read_words_le16(dev, addr, (__le16 *)buf, len / 2);
	buf += len & ~0x01;
	addr += len & ~0x01;
	len &= 0x01;

	if (len) {
		u16 tmp;
		tmp = hpi_read_word(dev, addr);
		*buf = tmp & 0x00ff;
	}
}

void c67x00_ll_init(struct c67x00_device *dev)
{
	mutex_init(&dev->hpi.lcp.mutex);
	init_completion(&dev->hpi.lcp.msg_received);
}

void c67x00_ll_release(struct c67x00_device *dev)
{
}

