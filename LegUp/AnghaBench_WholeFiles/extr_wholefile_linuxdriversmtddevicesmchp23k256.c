#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
typedef  int /*<<< orphan*/  transfer ;
struct spi_transfer {unsigned char* tx_buf; int len; unsigned char* rx_buf; } ;
struct spi_message {int actual_length; } ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {TYPE_3__ dev; } ;
struct mtd_info {int dummy; } ;
struct TYPE_10__ {TYPE_3__* parent; } ;
struct TYPE_13__ {int writesize; int (* _read ) (struct mtd_info*,unsigned int,size_t,size_t*,unsigned char*) ;int (* _write ) (struct mtd_info*,unsigned int,size_t,size_t*,unsigned char const*) ;int /*<<< orphan*/  size; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; TYPE_1__ dev; } ;
struct mchp23k256_flash {TYPE_4__ mtd; TYPE_2__* caps; int /*<<< orphan*/  lock; struct spi_device* spi; } ;
struct flash_platform_data {int /*<<< orphan*/  nr_parts; int /*<<< orphan*/ * parts; } ;
typedef  unsigned int loff_t ;
typedef  int /*<<< orphan*/  command ;
struct TYPE_11__ {int addr_width; int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MAX_CMD_SIZE ; 
 unsigned char MCHP23K256_CMD_READ ; 
 unsigned char MCHP23K256_CMD_WRITE ; 
 unsigned char MCHP23K256_CMD_WRITE_STATUS ; 
 unsigned char MCHP23K256_MODE_SEQ ; 
 int /*<<< orphan*/  MTD_CAP_RAM ; 
 int /*<<< orphan*/  MTD_RAM ; 
 struct flash_platform_data* dev_get_platdata (TYPE_3__*) ; 
 struct mchp23k256_flash* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 TYPE_2__ mchp23k256_caps ; 
 int /*<<< orphan*/  memset (struct spi_transfer**,int /*<<< orphan*/ ,int) ; 
 int mtd_device_register (TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int mtd_device_unregister (TYPE_4__*) ; 
 int /*<<< orphan*/  mtd_set_of_node (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_2__* of_device_get_match_data (TYPE_3__*) ; 
 struct mchp23k256_flash* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct mchp23k256_flash*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 struct mchp23k256_flash* to_mchp23k256_flash (struct mtd_info*) ; 

__attribute__((used)) static void mchp23k256_addr2cmd(struct mchp23k256_flash *flash,
				unsigned int addr, u8 *cmd)
{
	int i;

	/*
	 * Address is sent in big endian (MSB first) and we skip
	 * the first entry of the cmd array which contains the cmd
	 * opcode.
	 */
	for (i = flash->caps->addr_width; i > 0; i--, addr >>= 8)
		cmd[i] = addr;
}

__attribute__((used)) static int mchp23k256_cmdsz(struct mchp23k256_flash *flash)
{
	return 1 + flash->caps->addr_width;
}

__attribute__((used)) static int mchp23k256_write(struct mtd_info *mtd, loff_t to, size_t len,
			    size_t *retlen, const unsigned char *buf)
{
	struct mchp23k256_flash *flash = to_mchp23k256_flash(mtd);
	struct spi_transfer transfer[2] = {};
	struct spi_message message;
	unsigned char command[MAX_CMD_SIZE];
	int ret;

	spi_message_init(&message);

	command[0] = MCHP23K256_CMD_WRITE;
	mchp23k256_addr2cmd(flash, to, command);

	transfer[0].tx_buf = command;
	transfer[0].len = mchp23k256_cmdsz(flash);
	spi_message_add_tail(&transfer[0], &message);

	transfer[1].tx_buf = buf;
	transfer[1].len = len;
	spi_message_add_tail(&transfer[1], &message);

	mutex_lock(&flash->lock);

	ret = spi_sync(flash->spi, &message);

	mutex_unlock(&flash->lock);

	if (ret)
		return ret;

	if (retlen && message.actual_length > sizeof(command))
		*retlen += message.actual_length - sizeof(command);

	return 0;
}

__attribute__((used)) static int mchp23k256_read(struct mtd_info *mtd, loff_t from, size_t len,
			   size_t *retlen, unsigned char *buf)
{
	struct mchp23k256_flash *flash = to_mchp23k256_flash(mtd);
	struct spi_transfer transfer[2] = {};
	struct spi_message message;
	unsigned char command[MAX_CMD_SIZE];
	int ret;

	spi_message_init(&message);

	memset(&transfer, 0, sizeof(transfer));
	command[0] = MCHP23K256_CMD_READ;
	mchp23k256_addr2cmd(flash, from, command);

	transfer[0].tx_buf = command;
	transfer[0].len = mchp23k256_cmdsz(flash);
	spi_message_add_tail(&transfer[0], &message);

	transfer[1].rx_buf = buf;
	transfer[1].len = len;
	spi_message_add_tail(&transfer[1], &message);

	mutex_lock(&flash->lock);

	ret = spi_sync(flash->spi, &message);

	mutex_unlock(&flash->lock);

	if (ret)
		return ret;

	if (retlen && message.actual_length > sizeof(command))
		*retlen += message.actual_length - sizeof(command);

	return 0;
}

__attribute__((used)) static int mchp23k256_set_mode(struct spi_device *spi)
{
	struct spi_transfer transfer = {};
	struct spi_message message;
	unsigned char command[2];

	spi_message_init(&message);

	command[0] = MCHP23K256_CMD_WRITE_STATUS;
	command[1] = MCHP23K256_MODE_SEQ;

	transfer.tx_buf = command;
	transfer.len = sizeof(command);
	spi_message_add_tail(&transfer, &message);

	return spi_sync(spi, &message);
}

__attribute__((used)) static int mchp23k256_probe(struct spi_device *spi)
{
	struct mchp23k256_flash *flash;
	struct flash_platform_data *data;
	int err;

	flash = devm_kzalloc(&spi->dev, sizeof(*flash), GFP_KERNEL);
	if (!flash)
		return -ENOMEM;

	flash->spi = spi;
	mutex_init(&flash->lock);
	spi_set_drvdata(spi, flash);

	err = mchp23k256_set_mode(spi);
	if (err)
		return err;

	data = dev_get_platdata(&spi->dev);

	flash->caps = of_device_get_match_data(&spi->dev);
	if (!flash->caps)
		flash->caps = &mchp23k256_caps;

	mtd_set_of_node(&flash->mtd, spi->dev.of_node);
	flash->mtd.dev.parent	= &spi->dev;
	flash->mtd.type		= MTD_RAM;
	flash->mtd.flags	= MTD_CAP_RAM;
	flash->mtd.writesize	= 1;
	flash->mtd.size		= flash->caps->size;
	flash->mtd._read	= mchp23k256_read;
	flash->mtd._write	= mchp23k256_write;

	err = mtd_device_register(&flash->mtd, data ? data->parts : NULL,
				  data ? data->nr_parts : 0);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static int mchp23k256_remove(struct spi_device *spi)
{
	struct mchp23k256_flash *flash = spi_get_drvdata(spi);

	return mtd_device_unregister(&flash->mtd);
}

