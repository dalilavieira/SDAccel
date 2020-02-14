#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  const u16 ;
struct tpm_input_header {void* length; void* tag; void* ordinal; } ;
struct tpm_chip {int /*<<< orphan*/  dev; } ;
struct tpm_buf {int flags; int /*<<< orphan*/ * data; int /*<<< orphan*/  data_page; } ;
struct pnp_device_id {int /*<<< orphan*/  id; } ;
struct pnp_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
typedef  void* __be32 ;
typedef  void* __be16 ;
struct TYPE_2__ {scalar_t__ iotype; unsigned char data_regs; unsigned char config_port; int index_off; int config_size; int data_size; unsigned char map_base; int /*<<< orphan*/  map_size; int /*<<< orphan*/ * mem_base; } ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 unsigned char CHIP_ID1 ; 
 unsigned char CHIP_ID2 ; 
 unsigned char CMD ; 
 unsigned char DISABLE_REGISTER_PAIR ; 
 int EINVAL ; 
 int EIO ; 
 unsigned char ENABLE_REGISTER_PAIR ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_HIGHUSER ; 
 unsigned char IDPDH ; 
 unsigned char IDPDL ; 
 unsigned char IDVENH ; 
 unsigned char IDVENL ; 
 unsigned char IOLIMH ; 
 unsigned char IOLIML ; 
 int IORESOURCE_DISABLED ; 
 scalar_t__ IS_ERR (struct tpm_chip*) ; 
 unsigned int PAGE_SIZE ; 
 int PTR_ERR (struct tpm_chip*) ; 
 unsigned char RDFIFO ; 
 unsigned char RESET_LP_IRQC_DISABLE ; 
 unsigned char STAT ; 
 int STAT_RDA ; 
 int STAT_XFE ; 
 int TPM_ADDR ; 
 int TPM_BUF_OVERFLOW ; 
 int TPM_CTRL_DATA ; 
 int TPM_CTRL_ERROR ; 
 int TPM_CTRL_WTX ; 
 int TPM_CTRL_WTX_ABORT ; 
 int TPM_CTRL_WTX_ABORT_ACK ; 
 unsigned char TPM_DAR ; 
 int TPM_INFINEON_DEV_VEN_VALUE ; 
 unsigned char TPM_INF_ADDR ; 
 unsigned char TPM_INF_DATA ; 
 scalar_t__ TPM_INF_IO_MEM ; 
 scalar_t__ TPM_INF_IO_PORT ; 
 int TPM_INF_NAK ; 
 int TPM_MAX_TRIES ; 
 scalar_t__ TPM_MAX_WTX_PACKAGES ; 
 unsigned int TPM_MSLEEP_TIME ; 
 scalar_t__ TPM_TIMEOUT_RANGE_US ; 
 int TPM_VL_CHANNEL_TPM ; 
 int TPM_VL_VER ; 
 unsigned int TPM_WTX_MSLEEP_TIME ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 unsigned char WRFIFO ; 
 int /*<<< orphan*/  __free_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  const be16_to_cpu (void*) ; 
 unsigned int be32_to_cpu (void*) ; 
 void* cpu_to_be16 (int /*<<< orphan*/  const) ; 
 void* cpu_to_be32 (unsigned int const) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 unsigned char inb (unsigned char) ; 
 int /*<<< orphan*/ * ioremap (unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,unsigned char const*,unsigned int) ; 
 scalar_t__ number_of_wtx ; 
 int /*<<< orphan*/  outb (unsigned char,unsigned char) ; 
 struct tpm_chip* pnp_get_drvdata (struct pnp_dev*) ; 
 int pnp_mem_flags (struct pnp_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_mem_len (struct pnp_dev*,int /*<<< orphan*/ ) ; 
 unsigned char pnp_mem_start (struct pnp_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ pnp_mem_valid (struct pnp_dev*,int /*<<< orphan*/ ) ; 
 int pnp_port_flags (struct pnp_dev*,int /*<<< orphan*/ ) ; 
 void* pnp_port_len (struct pnp_dev*,int) ; 
 void* pnp_port_start (struct pnp_dev*,int) ; 
 scalar_t__ pnp_port_valid (struct pnp_dev*,int) ; 
 unsigned char readb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  release_mem_region (unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (unsigned char,int) ; 
 int /*<<< orphan*/ * request_mem_region (unsigned char,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * request_region (unsigned char,int,char*) ; 
 int tpm_chip_register (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_chip_unregister (struct tpm_chip*) ; 
 TYPE_1__ tpm_dev ; 
 int /*<<< orphan*/  tpm_inf ; 
 struct tpm_chip* tpmm_chip_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  writeb (unsigned char,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void tpm_buf_reset(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	struct tpm_input_header *head;
	head = (struct tpm_input_header *)buf->data;
	head->tag = cpu_to_be16(tag);
	head->length = cpu_to_be32(sizeof(*head));
	head->ordinal = cpu_to_be32(ordinal);
}

__attribute__((used)) static inline int tpm_buf_init(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	buf->data_page = alloc_page(GFP_HIGHUSER);
	if (!buf->data_page)
		return -ENOMEM;

	buf->flags = 0;
	buf->data = kmap(buf->data_page);
	tpm_buf_reset(buf, tag, ordinal);
	return 0;
}

__attribute__((used)) static inline void tpm_buf_destroy(struct tpm_buf *buf)
{
	kunmap(buf->data_page);
	__free_page(buf->data_page);
}

__attribute__((used)) static inline u32 tpm_buf_length(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be32_to_cpu(head->length);
}

__attribute__((used)) static inline u16 tpm_buf_tag(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be16_to_cpu(head->tag);
}

__attribute__((used)) static inline void tpm_buf_append(struct tpm_buf *buf,
				  const unsigned char *new_data,
				  unsigned int new_len)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;
	u32 len = tpm_buf_length(buf);

	/* Return silently if overflow has already happened. */
	if (buf->flags & TPM_BUF_OVERFLOW)
		return;

	if ((len + new_len) > PAGE_SIZE) {
		WARN(1, "tpm_buf: overflow\n");
		buf->flags |= TPM_BUF_OVERFLOW;
		return;
	}

	memcpy(&buf->data[len], new_data, new_len);
	head->length = cpu_to_be32(len + new_len);
}

__attribute__((used)) static inline void tpm_buf_append_u8(struct tpm_buf *buf, const u8 value)
{
	tpm_buf_append(buf, &value, 1);
}

__attribute__((used)) static inline void tpm_buf_append_u16(struct tpm_buf *buf, const u16 value)
{
	__be16 value2 = cpu_to_be16(value);

	tpm_buf_append(buf, (u8 *) &value2, 2);
}

__attribute__((used)) static inline void tpm_buf_append_u32(struct tpm_buf *buf, const u32 value)
{
	__be32 value2 = cpu_to_be32(value);

	tpm_buf_append(buf, (u8 *) &value2, 4);
}

__attribute__((used)) static inline void tpm_msleep(unsigned int delay_msec)
{
	usleep_range((delay_msec * 1000) - TPM_TIMEOUT_RANGE_US,
		     delay_msec * 1000);
}

__attribute__((used)) static inline void tpm_add_ppi(struct tpm_chip *chip)
{
}

__attribute__((used)) static inline u32 tpm2_rc_value(u32 rc)
{
	return (rc & BIT(7)) ? rc & 0xff : rc;
}

__attribute__((used)) static inline void tpm_data_out(unsigned char data, unsigned char offset)
{
	if (tpm_dev.iotype == TPM_INF_IO_PORT)
		outb(data, tpm_dev.data_regs + offset);
	else
		writeb(data, tpm_dev.mem_base + tpm_dev.data_regs + offset);
}

__attribute__((used)) static inline unsigned char tpm_data_in(unsigned char offset)
{
	if (tpm_dev.iotype == TPM_INF_IO_PORT)
		return inb(tpm_dev.data_regs + offset);
	else
		return readb(tpm_dev.mem_base + tpm_dev.data_regs + offset);
}

__attribute__((used)) static inline void tpm_config_out(unsigned char data, unsigned char offset)
{
	if (tpm_dev.iotype == TPM_INF_IO_PORT)
		outb(data, tpm_dev.config_port + offset);
	else
		writeb(data, tpm_dev.mem_base + tpm_dev.index_off + offset);
}

__attribute__((used)) static inline unsigned char tpm_config_in(unsigned char offset)
{
	if (tpm_dev.iotype == TPM_INF_IO_PORT)
		return inb(tpm_dev.config_port + offset);
	else
		return readb(tpm_dev.mem_base + tpm_dev.index_off + offset);
}

__attribute__((used)) static int empty_fifo(struct tpm_chip *chip, int clear_wrfifo)
{
	int status;
	int check = 0;
	int i;

	if (clear_wrfifo) {
		for (i = 0; i < 4096; i++) {
			status = tpm_data_in(WRFIFO);
			if (status == 0xff) {
				if (check == 5)
					break;
				else
					check++;
			}
		}
	}
	/* Note: The values which are currently in the FIFO of the TPM
	   are thrown away since there is no usage for them. Usually,
	   this has nothing to say, since the TPM will give its answer
	   immediately or will be aborted anyway, so the data here is
	   usually garbage and useless.
	   We have to clean this, because the next communication with
	   the TPM would be rubbish, if there is still some old data
	   in the Read FIFO.
	 */
	i = 0;
	do {
		status = tpm_data_in(RDFIFO);
		status = tpm_data_in(STAT);
		i++;
		if (i == TPM_MAX_TRIES)
			return -EIO;
	} while ((status & (1 << STAT_RDA)) != 0);
	return 0;
}

__attribute__((used)) static int wait(struct tpm_chip *chip, int wait_for_bit)
{
	int status;
	int i;
	for (i = 0; i < TPM_MAX_TRIES; i++) {
		status = tpm_data_in(STAT);
		/* check the status-register if wait_for_bit is set */
		if (status & 1 << wait_for_bit)
			break;
		tpm_msleep(TPM_MSLEEP_TIME);
	}
	if (i == TPM_MAX_TRIES) {	/* timeout occurs */
		if (wait_for_bit == STAT_XFE)
			dev_err(&chip->dev, "Timeout in wait(STAT_XFE)\n");
		if (wait_for_bit == STAT_RDA)
			dev_err(&chip->dev, "Timeout in wait(STAT_RDA)\n");
		return -EIO;
	}
	return 0;
}

__attribute__((used)) static void wait_and_send(struct tpm_chip *chip, u8 sendbyte)
{
	wait(chip, STAT_XFE);
	tpm_data_out(sendbyte, WRFIFO);
}

__attribute__((used)) static void tpm_wtx(struct tpm_chip *chip)
{
	number_of_wtx++;
	dev_info(&chip->dev, "Granting WTX (%02d / %02d)\n",
		 number_of_wtx, TPM_MAX_WTX_PACKAGES);
	wait_and_send(chip, TPM_VL_VER);
	wait_and_send(chip, TPM_CTRL_WTX);
	wait_and_send(chip, 0x00);
	wait_and_send(chip, 0x00);
	tpm_msleep(TPM_WTX_MSLEEP_TIME);
}

__attribute__((used)) static void tpm_wtx_abort(struct tpm_chip *chip)
{
	dev_info(&chip->dev, "Aborting WTX\n");
	wait_and_send(chip, TPM_VL_VER);
	wait_and_send(chip, TPM_CTRL_WTX_ABORT);
	wait_and_send(chip, 0x00);
	wait_and_send(chip, 0x00);
	number_of_wtx = 0;
	tpm_msleep(TPM_WTX_MSLEEP_TIME);
}

__attribute__((used)) static int tpm_inf_recv(struct tpm_chip *chip, u8 * buf, size_t count)
{
	int i;
	int ret;
	u32 size = 0;
	number_of_wtx = 0;

recv_begin:
	/* start receiving header */
	for (i = 0; i < 4; i++) {
		ret = wait(chip, STAT_RDA);
		if (ret)
			return -EIO;
		buf[i] = tpm_data_in(RDFIFO);
	}

	if (buf[0] != TPM_VL_VER) {
		dev_err(&chip->dev,
			"Wrong transport protocol implementation!\n");
		return -EIO;
	}

	if (buf[1] == TPM_CTRL_DATA) {
		/* size of the data received */
		size = ((buf[2] << 8) | buf[3]);

		for (i = 0; i < size; i++) {
			wait(chip, STAT_RDA);
			buf[i] = tpm_data_in(RDFIFO);
		}

		if ((size == 0x6D00) && (buf[1] == 0x80)) {
			dev_err(&chip->dev, "Error handling on vendor layer!\n");
			return -EIO;
		}

		for (i = 0; i < size; i++)
			buf[i] = buf[i + 6];

		size = size - 6;
		return size;
	}

	if (buf[1] == TPM_CTRL_WTX) {
		dev_info(&chip->dev, "WTX-package received\n");
		if (number_of_wtx < TPM_MAX_WTX_PACKAGES) {
			tpm_wtx(chip);
			goto recv_begin;
		} else {
			tpm_wtx_abort(chip);
			goto recv_begin;
		}
	}

	if (buf[1] == TPM_CTRL_WTX_ABORT_ACK) {
		dev_info(&chip->dev, "WTX-abort acknowledged\n");
		return size;
	}

	if (buf[1] == TPM_CTRL_ERROR) {
		dev_err(&chip->dev, "ERROR-package received:\n");
		if (buf[4] == TPM_INF_NAK)
			dev_err(&chip->dev,
				"-> Negative acknowledgement"
				" - retransmit command!\n");
		return -EIO;
	}
	return -EIO;
}

__attribute__((used)) static int tpm_inf_send(struct tpm_chip *chip, u8 * buf, size_t count)
{
	int i;
	int ret;
	u8 count_high, count_low, count_4, count_3, count_2, count_1;

	/* Disabling Reset, LP and IRQC */
	tpm_data_out(RESET_LP_IRQC_DISABLE, CMD);

	ret = empty_fifo(chip, 1);
	if (ret) {
		dev_err(&chip->dev, "Timeout while clearing FIFO\n");
		return -EIO;
	}

	ret = wait(chip, STAT_XFE);
	if (ret)
		return -EIO;

	count_4 = (count & 0xff000000) >> 24;
	count_3 = (count & 0x00ff0000) >> 16;
	count_2 = (count & 0x0000ff00) >> 8;
	count_1 = (count & 0x000000ff);
	count_high = ((count + 6) & 0xffffff00) >> 8;
	count_low = ((count + 6) & 0x000000ff);

	/* Sending Header */
	wait_and_send(chip, TPM_VL_VER);
	wait_and_send(chip, TPM_CTRL_DATA);
	wait_and_send(chip, count_high);
	wait_and_send(chip, count_low);

	/* Sending Data Header */
	wait_and_send(chip, TPM_VL_VER);
	wait_and_send(chip, TPM_VL_CHANNEL_TPM);
	wait_and_send(chip, count_4);
	wait_and_send(chip, count_3);
	wait_and_send(chip, count_2);
	wait_and_send(chip, count_1);

	/* Sending Data */
	for (i = 0; i < count; i++) {
		wait_and_send(chip, buf[i]);
	}
	return 0;
}

__attribute__((used)) static void tpm_inf_cancel(struct tpm_chip *chip)
{
	/*
	   Since we are using the legacy mode to communicate
	   with the TPM, we have no cancel functions, but have
	   a workaround for interrupting the TPM through WTX.
	 */
}

__attribute__((used)) static u8 tpm_inf_status(struct tpm_chip *chip)
{
	return tpm_data_in(STAT);
}

__attribute__((used)) static int tpm_inf_pnp_probe(struct pnp_dev *dev,
				       const struct pnp_device_id *dev_id)
{
	int rc = 0;
	u8 iol, ioh;
	int vendorid[2];
	int version[2];
	int productid[2];
	const char *chipname;
	struct tpm_chip *chip;

	/* read IO-ports through PnP */
	if (pnp_port_valid(dev, 0) && pnp_port_valid(dev, 1) &&
	    !(pnp_port_flags(dev, 0) & IORESOURCE_DISABLED)) {

		tpm_dev.iotype = TPM_INF_IO_PORT;

		tpm_dev.config_port = pnp_port_start(dev, 0);
		tpm_dev.config_size = pnp_port_len(dev, 0);
		tpm_dev.data_regs = pnp_port_start(dev, 1);
		tpm_dev.data_size = pnp_port_len(dev, 1);
		if ((tpm_dev.data_size < 4) || (tpm_dev.config_size < 2)) {
			rc = -EINVAL;
			goto err_last;
		}
		dev_info(&dev->dev, "Found %s with ID %s\n",
			 dev->name, dev_id->id);
		if (!((tpm_dev.data_regs >> 8) & 0xff)) {
			rc = -EINVAL;
			goto err_last;
		}
		/* publish my base address and request region */
		if (request_region(tpm_dev.data_regs, tpm_dev.data_size,
				   "tpm_infineon0") == NULL) {
			rc = -EINVAL;
			goto err_last;
		}
		if (request_region(tpm_dev.config_port, tpm_dev.config_size,
				   "tpm_infineon0") == NULL) {
			release_region(tpm_dev.data_regs, tpm_dev.data_size);
			rc = -EINVAL;
			goto err_last;
		}
	} else if (pnp_mem_valid(dev, 0) &&
		   !(pnp_mem_flags(dev, 0) & IORESOURCE_DISABLED)) {

		tpm_dev.iotype = TPM_INF_IO_MEM;

		tpm_dev.map_base = pnp_mem_start(dev, 0);
		tpm_dev.map_size = pnp_mem_len(dev, 0);

		dev_info(&dev->dev, "Found %s with ID %s\n",
			 dev->name, dev_id->id);

		/* publish my base address and request region */
		if (request_mem_region(tpm_dev.map_base, tpm_dev.map_size,
				       "tpm_infineon0") == NULL) {
			rc = -EINVAL;
			goto err_last;
		}

		tpm_dev.mem_base = ioremap(tpm_dev.map_base, tpm_dev.map_size);
		if (tpm_dev.mem_base == NULL) {
			release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
			rc = -EINVAL;
			goto err_last;
		}

		/*
		 * The only known MMIO based Infineon TPM system provides
		 * a single large mem region with the device config
		 * registers at the default TPM_ADDR.  The data registers
		 * seem like they could be placed anywhere within the MMIO
		 * region, but lets just put them at zero offset.
		 */
		tpm_dev.index_off = TPM_ADDR;
		tpm_dev.data_regs = 0x0;
	} else {
		rc = -EINVAL;
		goto err_last;
	}

	/* query chip for its vendor, its version number a.s.o. */
	tpm_config_out(ENABLE_REGISTER_PAIR, TPM_INF_ADDR);
	tpm_config_out(IDVENL, TPM_INF_ADDR);
	vendorid[1] = tpm_config_in(TPM_INF_DATA);
	tpm_config_out(IDVENH, TPM_INF_ADDR);
	vendorid[0] = tpm_config_in(TPM_INF_DATA);
	tpm_config_out(IDPDL, TPM_INF_ADDR);
	productid[1] = tpm_config_in(TPM_INF_DATA);
	tpm_config_out(IDPDH, TPM_INF_ADDR);
	productid[0] = tpm_config_in(TPM_INF_DATA);
	tpm_config_out(CHIP_ID1, TPM_INF_ADDR);
	version[1] = tpm_config_in(TPM_INF_DATA);
	tpm_config_out(CHIP_ID2, TPM_INF_ADDR);
	version[0] = tpm_config_in(TPM_INF_DATA);

	switch ((productid[0] << 8) | productid[1]) {
	case 6:
		chipname = " (SLD 9630 TT 1.1)";
		break;
	case 11:
		chipname = " (SLB 9635 TT 1.2)";
		break;
	default:
		chipname = " (unknown chip)";
		break;
	}

	if ((vendorid[0] << 8 | vendorid[1]) == (TPM_INFINEON_DEV_VEN_VALUE)) {

		/* configure TPM with IO-ports */
		tpm_config_out(IOLIMH, TPM_INF_ADDR);
		tpm_config_out((tpm_dev.data_regs >> 8) & 0xff, TPM_INF_DATA);
		tpm_config_out(IOLIML, TPM_INF_ADDR);
		tpm_config_out((tpm_dev.data_regs & 0xff), TPM_INF_DATA);

		/* control if IO-ports are set correctly */
		tpm_config_out(IOLIMH, TPM_INF_ADDR);
		ioh = tpm_config_in(TPM_INF_DATA);
		tpm_config_out(IOLIML, TPM_INF_ADDR);
		iol = tpm_config_in(TPM_INF_DATA);

		if ((ioh << 8 | iol) != tpm_dev.data_regs) {
			dev_err(&dev->dev,
				"Could not set IO-data registers to 0x%x\n",
				tpm_dev.data_regs);
			rc = -EIO;
			goto err_release_region;
		}

		/* activate register */
		tpm_config_out(TPM_DAR, TPM_INF_ADDR);
		tpm_config_out(0x01, TPM_INF_DATA);
		tpm_config_out(DISABLE_REGISTER_PAIR, TPM_INF_ADDR);

		/* disable RESET, LP and IRQC */
		tpm_data_out(RESET_LP_IRQC_DISABLE, CMD);

		/* Finally, we're done, print some infos */
		dev_info(&dev->dev, "TPM found: "
			 "config base 0x%lx, "
			 "data base 0x%lx, "
			 "chip version 0x%02x%02x, "
			 "vendor id 0x%x%x (Infineon), "
			 "product id 0x%02x%02x"
			 "%s\n",
			 tpm_dev.iotype == TPM_INF_IO_PORT ?
			 tpm_dev.config_port :
			 tpm_dev.map_base + tpm_dev.index_off,
			 tpm_dev.iotype == TPM_INF_IO_PORT ?
			 tpm_dev.data_regs :
			 tpm_dev.map_base + tpm_dev.data_regs,
			 version[0], version[1],
			 vendorid[0], vendorid[1],
			 productid[0], productid[1], chipname);

		chip = tpmm_chip_alloc(&dev->dev, &tpm_inf);
		if (IS_ERR(chip)) {
			rc = PTR_ERR(chip);
			goto err_release_region;
		}

		rc = tpm_chip_register(chip);
		if (rc)
			goto err_release_region;

		return 0;
	} else {
		rc = -ENODEV;
		goto err_release_region;
	}

err_release_region:
	if (tpm_dev.iotype == TPM_INF_IO_PORT) {
		release_region(tpm_dev.data_regs, tpm_dev.data_size);
		release_region(tpm_dev.config_port, tpm_dev.config_size);
	} else {
		iounmap(tpm_dev.mem_base);
		release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
	}

err_last:
	return rc;
}

__attribute__((used)) static void tpm_inf_pnp_remove(struct pnp_dev *dev)
{
	struct tpm_chip *chip = pnp_get_drvdata(dev);

	tpm_chip_unregister(chip);

	if (tpm_dev.iotype == TPM_INF_IO_PORT) {
		release_region(tpm_dev.data_regs, tpm_dev.data_size);
		release_region(tpm_dev.config_port,
			       tpm_dev.config_size);
	} else {
		iounmap(tpm_dev.mem_base);
		release_mem_region(tpm_dev.map_base, tpm_dev.map_size);
	}
}

