#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u_char ;
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct spi_transfer {scalar_t__* tx_buf; int len; scalar_t__* rx_buf; } ;
struct spi_message {int actual_length; } ;
struct TYPE_10__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {int chip_select; TYPE_3__ dev; TYPE_1__* master; } ;
struct TYPE_9__ {TYPE_3__* parent; } ;
struct mtd_info {int size; int erasesize; int writesize; int (* _erase ) (struct mtd_info*,struct erase_info*) ;int (* _read ) (struct mtd_info*,scalar_t__,size_t,size_t*,scalar_t__*) ;int (* _write ) (struct mtd_info*,scalar_t__,size_t,size_t*,scalar_t__ const*) ;TYPE_2__ dev; struct dataflash* priv; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; scalar_t__ name; } ;
struct flash_platform_data {int /*<<< orphan*/  nr_parts; int /*<<< orphan*/ * parts; scalar_t__ name; } ;
struct flash_info {int flags; scalar_t__ jedec_id; char* name; int nr_pages; int pagesize; int pageoffset; } ;
struct erase_info {scalar_t__ addr; scalar_t__ len; } ;
struct dataflash {int page_size; unsigned int page_offset; struct mtd_info mtd; scalar_t__ name; struct spi_device* spi; int /*<<< orphan*/  lock; scalar_t__* command; } ;
typedef  scalar_t__ loff_t ;
typedef  int /*<<< orphan*/  jedec ;
typedef  int /*<<< orphan*/  __be64 ;
struct TYPE_8__ {int bus_num; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct flash_info*) ; 
 scalar_t__ CFI_MFR_ATMEL ; 
 scalar_t__ DATAFLASH_SHIFT_EXTID ; 
 scalar_t__ DATAFLASH_SHIFT_ID ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct flash_info* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct flash_info*) ; 
 int IS_POW2PS ; 
 int /*<<< orphan*/  MTD_DATAFLASH ; 
 int /*<<< orphan*/  MTD_WRITEABLE ; 
 scalar_t__ OP_ERASE_BLOCK ; 
 scalar_t__ OP_ERASE_PAGE ; 
 scalar_t__ OP_PROGRAM_VIA_BUF1 ; 
 scalar_t__ OP_READ_CONTINUOUS ; 
 scalar_t__ OP_READ_ID ; 
 int /*<<< orphan*/  OP_READ_STATUS ; 
 scalar_t__ OP_TRANSFER_BUF1 ; 
 int PTR_ERR (struct flash_info*) ; 
 int SUP_EXTID ; 
 int SUP_POW2PS ; 
 scalar_t__ be64_to_cpup (int /*<<< orphan*/ *) ; 
 struct flash_info* dataflash_data ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,unsigned int,int) ; 
 struct flash_platform_data* dev_get_platdata (TYPE_3__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,scalar_t__) ; 
 unsigned int div_u64 (scalar_t__,int) ; 
 int /*<<< orphan*/  div_u64_rem (scalar_t__,int,scalar_t__*) ; 
 int /*<<< orphan*/  kfree (struct dataflash*) ; 
 struct dataflash* kzalloc (int,int /*<<< orphan*/ ) ; 
 int mtd_device_register (struct mtd_info*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int mtd_device_unregister (struct mtd_info*) ; 
 int /*<<< orphan*/  mtd_set_of_node (struct mtd_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct dataflash* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct dataflash*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_transfer_del (struct spi_transfer*) ; 
 int spi_w8r8 (struct spi_device*,int /*<<< orphan*/ ) ; 
 int spi_write_then_read (struct spi_device*,scalar_t__*,int,scalar_t__*,unsigned int const) ; 
 int /*<<< orphan*/  sprintf (scalar_t__,char*,int,int,char*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline int dataflash_status(struct spi_device *spi)
{
	/* NOTE:  at45db321c over 25 MHz wants to write
	 * a dummy byte after the opcode...
	 */
	return spi_w8r8(spi, OP_READ_STATUS);
}

__attribute__((used)) static int dataflash_waitready(struct spi_device *spi)
{
	int	status;

	for (;;) {
		status = dataflash_status(spi);
		if (status < 0) {
			dev_dbg(&spi->dev, "status %d?\n", status);
			status = 0;
		}

		if (status & (1 << 7))	/* RDY/nBSY */
			return status;

		usleep_range(3000, 4000);
	}
}

__attribute__((used)) static int dataflash_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	struct dataflash	*priv = mtd->priv;
	struct spi_device	*spi = priv->spi;
	struct spi_transfer	x = { };
	struct spi_message	msg;
	unsigned		blocksize = priv->page_size << 3;
	u8			*command;
	u32			rem;

	dev_dbg(&spi->dev, "erase addr=0x%llx len 0x%llx\n",
		(long long)instr->addr, (long long)instr->len);

	div_u64_rem(instr->len, priv->page_size, &rem);
	if (rem)
		return -EINVAL;
	div_u64_rem(instr->addr, priv->page_size, &rem);
	if (rem)
		return -EINVAL;

	spi_message_init(&msg);

	x.tx_buf = command = priv->command;
	x.len = 4;
	spi_message_add_tail(&x, &msg);

	mutex_lock(&priv->lock);
	while (instr->len > 0) {
		unsigned int	pageaddr;
		int		status;
		int		do_block;

		/* Calculate flash page address; use block erase (for speed) if
		 * we're at a block boundary and need to erase the whole block.
		 */
		pageaddr = div_u64(instr->addr, priv->page_size);
		do_block = (pageaddr & 0x7) == 0 && instr->len >= blocksize;
		pageaddr = pageaddr << priv->page_offset;

		command[0] = do_block ? OP_ERASE_BLOCK : OP_ERASE_PAGE;
		command[1] = (u8)(pageaddr >> 16);
		command[2] = (u8)(pageaddr >> 8);
		command[3] = 0;

		dev_dbg(&spi->dev, "ERASE %s: (%x) %x %x %x [%i]\n",
			do_block ? "block" : "page",
			command[0], command[1], command[2], command[3],
			pageaddr);

		status = spi_sync(spi, &msg);
		(void) dataflash_waitready(spi);

		if (status < 0) {
			dev_err(&spi->dev, "erase %x, err %d\n",
				pageaddr, status);
			/* REVISIT:  can retry instr->retries times; or
			 * giveup and instr->fail_addr = instr->addr;
			 */
			continue;
		}

		if (do_block) {
			instr->addr += blocksize;
			instr->len -= blocksize;
		} else {
			instr->addr += priv->page_size;
			instr->len -= priv->page_size;
		}
	}
	mutex_unlock(&priv->lock);

	return 0;
}

__attribute__((used)) static int dataflash_read(struct mtd_info *mtd, loff_t from, size_t len,
			       size_t *retlen, u_char *buf)
{
	struct dataflash	*priv = mtd->priv;
	struct spi_transfer	x[2] = { };
	struct spi_message	msg;
	unsigned int		addr;
	u8			*command;
	int			status;

	dev_dbg(&priv->spi->dev, "read 0x%x..0x%x\n",
		  (unsigned int)from, (unsigned int)(from + len));

	/* Calculate flash page/byte address */
	addr = (((unsigned)from / priv->page_size) << priv->page_offset)
		+ ((unsigned)from % priv->page_size);

	command = priv->command;

	dev_dbg(&priv->spi->dev, "READ: (%x) %x %x %x\n",
		command[0], command[1], command[2], command[3]);

	spi_message_init(&msg);

	x[0].tx_buf = command;
	x[0].len = 8;
	spi_message_add_tail(&x[0], &msg);

	x[1].rx_buf = buf;
	x[1].len = len;
	spi_message_add_tail(&x[1], &msg);

	mutex_lock(&priv->lock);

	/* Continuous read, max clock = f(car) which may be less than
	 * the peak rate available.  Some chips support commands with
	 * fewer "don't care" bytes.  Both buffers stay unchanged.
	 */
	command[0] = OP_READ_CONTINUOUS;
	command[1] = (u8)(addr >> 16);
	command[2] = (u8)(addr >> 8);
	command[3] = (u8)(addr >> 0);
	/* plus 4 "don't care" bytes */

	status = spi_sync(priv->spi, &msg);
	mutex_unlock(&priv->lock);

	if (status >= 0) {
		*retlen = msg.actual_length - 8;
		status = 0;
	} else
		dev_dbg(&priv->spi->dev, "read %x..%x --> %d\n",
			(unsigned)from, (unsigned)(from + len),
			status);
	return status;
}

__attribute__((used)) static int dataflash_write(struct mtd_info *mtd, loff_t to, size_t len,
				size_t * retlen, const u_char * buf)
{
	struct dataflash	*priv = mtd->priv;
	struct spi_device	*spi = priv->spi;
	struct spi_transfer	x[2] = { };
	struct spi_message	msg;
	unsigned int		pageaddr, addr, offset, writelen;
	size_t			remaining = len;
	u_char			*writebuf = (u_char *) buf;
	int			status = -EINVAL;
	u8			*command;

	dev_dbg(&spi->dev, "write 0x%x..0x%x\n",
		(unsigned int)to, (unsigned int)(to + len));

	spi_message_init(&msg);

	x[0].tx_buf = command = priv->command;
	x[0].len = 4;
	spi_message_add_tail(&x[0], &msg);

	pageaddr = ((unsigned)to / priv->page_size);
	offset = ((unsigned)to % priv->page_size);
	if (offset + len > priv->page_size)
		writelen = priv->page_size - offset;
	else
		writelen = len;

	mutex_lock(&priv->lock);
	while (remaining > 0) {
		dev_dbg(&spi->dev, "write @ %i:%i len=%i\n",
			pageaddr, offset, writelen);

		/* REVISIT:
		 * (a) each page in a sector must be rewritten at least
		 *     once every 10K sibling erase/program operations.
		 * (b) for pages that are already erased, we could
		 *     use WRITE+MWRITE not PROGRAM for ~30% speedup.
		 * (c) WRITE to buffer could be done while waiting for
		 *     a previous MWRITE/MWERASE to complete ...
		 * (d) error handling here seems to be mostly missing.
		 *
		 * Two persistent bits per page, plus a per-sector counter,
		 * could support (a) and (b) ... we might consider using
		 * the second half of sector zero, which is just one block,
		 * to track that state.  (On AT91, that sector should also
		 * support boot-from-DataFlash.)
		 */

		addr = pageaddr << priv->page_offset;

		/* (1) Maybe transfer partial page to Buffer1 */
		if (writelen != priv->page_size) {
			command[0] = OP_TRANSFER_BUF1;
			command[1] = (addr & 0x00FF0000) >> 16;
			command[2] = (addr & 0x0000FF00) >> 8;
			command[3] = 0;

			dev_dbg(&spi->dev, "TRANSFER: (%x) %x %x %x\n",
				command[0], command[1], command[2], command[3]);

			status = spi_sync(spi, &msg);
			if (status < 0)
				dev_dbg(&spi->dev, "xfer %u -> %d\n",
					addr, status);

			(void) dataflash_waitready(priv->spi);
		}

		/* (2) Program full page via Buffer1 */
		addr += offset;
		command[0] = OP_PROGRAM_VIA_BUF1;
		command[1] = (addr & 0x00FF0000) >> 16;
		command[2] = (addr & 0x0000FF00) >> 8;
		command[3] = (addr & 0x000000FF);

		dev_dbg(&spi->dev, "PROGRAM: (%x) %x %x %x\n",
			command[0], command[1], command[2], command[3]);

		x[1].tx_buf = writebuf;
		x[1].len = writelen;
		spi_message_add_tail(x + 1, &msg);
		status = spi_sync(spi, &msg);
		spi_transfer_del(x + 1);
		if (status < 0)
			dev_dbg(&spi->dev, "pgm %u/%u -> %d\n",
				addr, writelen, status);

		(void) dataflash_waitready(priv->spi);


#ifdef CONFIG_MTD_DATAFLASH_WRITE_VERIFY

		/* (3) Compare to Buffer1 */
		addr = pageaddr << priv->page_offset;
		command[0] = OP_COMPARE_BUF1;
		command[1] = (addr & 0x00FF0000) >> 16;
		command[2] = (addr & 0x0000FF00) >> 8;
		command[3] = 0;

		dev_dbg(&spi->dev, "COMPARE: (%x) %x %x %x\n",
			command[0], command[1], command[2], command[3]);

		status = spi_sync(spi, &msg);
		if (status < 0)
			dev_dbg(&spi->dev, "compare %u -> %d\n",
				addr, status);

		status = dataflash_waitready(priv->spi);

		/* Check result of the compare operation */
		if (status & (1 << 6)) {
			dev_err(&spi->dev, "compare page %u, err %d\n",
				pageaddr, status);
			remaining = 0;
			status = -EIO;
			break;
		} else
			status = 0;

#endif	/* CONFIG_MTD_DATAFLASH_WRITE_VERIFY */

		remaining = remaining - writelen;
		pageaddr++;
		offset = 0;
		writebuf += writelen;
		*retlen += writelen;

		if (remaining > priv->page_size)
			writelen = priv->page_size;
		else
			writelen = remaining;
	}
	mutex_unlock(&priv->lock);

	return status;
}

__attribute__((used)) static char *otp_setup(struct mtd_info *device, char revision)
{
	return " (OTP)";
}

__attribute__((used)) static int add_dataflash_otp(struct spi_device *spi, char *name, int nr_pages,
			     int pagesize, int pageoffset, char revision)
{
	struct dataflash		*priv;
	struct mtd_info			*device;
	struct flash_platform_data	*pdata = dev_get_platdata(&spi->dev);
	char				*otp_tag = "";
	int				err = 0;

	priv = kzalloc(sizeof *priv, GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	mutex_init(&priv->lock);
	priv->spi = spi;
	priv->page_size = pagesize;
	priv->page_offset = pageoffset;

	/* name must be usable with cmdlinepart */
	sprintf(priv->name, "spi%d.%d-%s",
			spi->master->bus_num, spi->chip_select,
			name);

	device = &priv->mtd;
	device->name = (pdata && pdata->name) ? pdata->name : priv->name;
	device->size = nr_pages * pagesize;
	device->erasesize = pagesize;
	device->writesize = pagesize;
	device->type = MTD_DATAFLASH;
	device->flags = MTD_WRITEABLE;
	device->_erase = dataflash_erase;
	device->_read = dataflash_read;
	device->_write = dataflash_write;
	device->priv = priv;

	device->dev.parent = &spi->dev;
	mtd_set_of_node(device, spi->dev.of_node);

	if (revision >= 'c')
		otp_tag = otp_setup(device, revision);

	dev_info(&spi->dev, "%s (%lld KBytes) pagesize %d bytes%s\n",
			name, (long long)((device->size + 1023) >> 10),
			pagesize, otp_tag);
	spi_set_drvdata(spi, priv);

	err = mtd_device_register(device,
			pdata ? pdata->parts : NULL,
			pdata ? pdata->nr_parts : 0);

	if (!err)
		return 0;

	kfree(priv);
	return err;
}

__attribute__((used)) static inline int add_dataflash(struct spi_device *spi, char *name,
				int nr_pages, int pagesize, int pageoffset)
{
	return add_dataflash_otp(spi, name, nr_pages, pagesize,
			pageoffset, 0);
}

__attribute__((used)) static struct flash_info *jedec_lookup(struct spi_device *spi,
				       u64 jedec, bool use_extid)
{
	struct flash_info *info;
	int status;

	for (info = dataflash_data;
	     info < dataflash_data + ARRAY_SIZE(dataflash_data);
	     info++) {
		if (use_extid && !(info->flags & SUP_EXTID))
			continue;

		if (info->jedec_id == jedec) {
			dev_dbg(&spi->dev, "OTP, sector protect%s\n",
				(info->flags & SUP_POW2PS) ?
				", binary pagesize" : "");
			if (info->flags & SUP_POW2PS) {
				status = dataflash_status(spi);
				if (status < 0) {
					dev_dbg(&spi->dev, "status error %d\n",
						status);
					return ERR_PTR(status);
				}
				if (status & 0x1) {
					if (info->flags & IS_POW2PS)
						return info;
				} else {
					if (!(info->flags & IS_POW2PS))
						return info;
				}
			} else
				return info;
		}
	}

	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static struct flash_info *jedec_probe(struct spi_device *spi)
{
	int ret;
	u8 code = OP_READ_ID;
	u64 jedec;
	u8 id[sizeof(jedec)] = {0};
	const unsigned int id_size = 5;
	struct flash_info *info;

	/*
	 * JEDEC also defines an optional "extended device information"
	 * string for after vendor-specific data, after the three bytes
	 * we use here.  Supporting some chips might require using it.
	 *
	 * If the vendor ID isn't Atmel's (0x1f), assume this call failed.
	 * That's not an error; only rev C and newer chips handle it, and
	 * only Atmel sells these chips.
	 */
	ret = spi_write_then_read(spi, &code, 1, id, id_size);
	if (ret < 0) {
		dev_dbg(&spi->dev, "error %d reading JEDEC ID\n", ret);
		return ERR_PTR(ret);
	}

	if (id[0] != CFI_MFR_ATMEL)
		return NULL;

	jedec = be64_to_cpup((__be64 *)id);

	/*
	 * First, try to match device using extended device
	 * information
	 */
	info = jedec_lookup(spi, jedec >> DATAFLASH_SHIFT_EXTID, true);
	if (!IS_ERR(info))
		return info;
	/*
	 * If that fails, make another pass using regular ID
	 * information
	 */
	info = jedec_lookup(spi, jedec >> DATAFLASH_SHIFT_ID, false);
	if (!IS_ERR(info))
		return info;
	/*
	 * Treat other chips as errors ... we won't know the right page
	 * size (it might be binary) even when we can tell which density
	 * class is involved (legacy chip id scheme).
	 */
	dev_warn(&spi->dev, "JEDEC id %016llx not handled\n", jedec);
	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static int dataflash_probe(struct spi_device *spi)
{
	int status;
	struct flash_info	*info;

	/*
	 * Try to detect dataflash by JEDEC ID.
	 * If it succeeds we know we have either a C or D part.
	 * D will support power of 2 pagesize option.
	 * Both support the security register, though with different
	 * write procedures.
	 */
	info = jedec_probe(spi);
	if (IS_ERR(info))
		return PTR_ERR(info);
	if (info != NULL)
		return add_dataflash_otp(spi, info->name, info->nr_pages,
				info->pagesize, info->pageoffset,
				(info->flags & SUP_POW2PS) ? 'd' : 'c');

	/*
	 * Older chips support only legacy commands, identifing
	 * capacity using bits in the status byte.
	 */
	status = dataflash_status(spi);
	if (status <= 0 || status == 0xff) {
		dev_dbg(&spi->dev, "status error %d\n", status);
		if (status == 0 || status == 0xff)
			status = -ENODEV;
		return status;
	}

	/* if there's a device there, assume it's dataflash.
	 * board setup should have set spi->max_speed_max to
	 * match f(car) for continuous reads, mode 0 or 3.
	 */
	switch (status & 0x3c) {
	case 0x0c:	/* 0 0 1 1 x x */
		status = add_dataflash(spi, "AT45DB011B", 512, 264, 9);
		break;
	case 0x14:	/* 0 1 0 1 x x */
		status = add_dataflash(spi, "AT45DB021B", 1024, 264, 9);
		break;
	case 0x1c:	/* 0 1 1 1 x x */
		status = add_dataflash(spi, "AT45DB041x", 2048, 264, 9);
		break;
	case 0x24:	/* 1 0 0 1 x x */
		status = add_dataflash(spi, "AT45DB081B", 4096, 264, 9);
		break;
	case 0x2c:	/* 1 0 1 1 x x */
		status = add_dataflash(spi, "AT45DB161x", 4096, 528, 10);
		break;
	case 0x34:	/* 1 1 0 1 x x */
		status = add_dataflash(spi, "AT45DB321x", 8192, 528, 10);
		break;
	case 0x38:	/* 1 1 1 x x x */
	case 0x3c:
		status = add_dataflash(spi, "AT45DB642x", 8192, 1056, 11);
		break;
	/* obsolete AT45DB1282 not (yet?) supported */
	default:
		dev_info(&spi->dev, "unsupported device (%x)\n",
				status & 0x3c);
		status = -ENODEV;
	}

	if (status < 0)
		dev_dbg(&spi->dev, "add_dataflash --> %d\n", status);

	return status;
}

__attribute__((used)) static int dataflash_remove(struct spi_device *spi)
{
	struct dataflash	*flash = spi_get_drvdata(spi);
	int			status;

	dev_dbg(&spi->dev, "remove\n");

	status = mtd_device_unregister(&flash->mtd);
	if (status == 0)
		kfree(flash);
	return status;
}

