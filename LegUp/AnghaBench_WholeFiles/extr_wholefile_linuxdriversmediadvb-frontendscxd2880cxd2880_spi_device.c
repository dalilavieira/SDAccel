#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  tx ;
struct spi_transfer {scalar_t__ len; int /*<<< orphan*/  const* tx_buf; } ;
struct spi_message {int dummy; } ;
struct spi_device {int bits_per_word; scalar_t__ max_speed_hz; int /*<<< orphan*/  mode; } ;
struct cxd2880_spi_device {struct spi_device* spi; } ;
struct cxd2880_spi {int (* write ) (struct cxd2880_spi*,int /*<<< orphan*/  const*,scalar_t__) ;int (* write_read ) (struct cxd2880_spi*,int /*<<< orphan*/  const*,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ;struct cxd2880_spi_device* user; scalar_t__ flags; int /*<<< orphan*/ * read; } ;
typedef  enum cxd2880_spi_mode { ____Placeholder_cxd2880_spi_mode } cxd2880_spi_mode ;

/* Variables and functions */
#define  CXD2880_SPI_MODE_0 131 
#define  CXD2880_SPI_MODE_1 130 
#define  CXD2880_SPI_MODE_2 129 
#define  CXD2880_SPI_MODE_3 128 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  SPI_MODE_0 ; 
 int /*<<< orphan*/  SPI_MODE_1 ; 
 int /*<<< orphan*/  SPI_MODE_2 ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  memset (struct spi_transfer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_write_then_read (struct spi_device*,int /*<<< orphan*/  const*,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static int cxd2880_spi_device_write(struct cxd2880_spi *spi,
				    const u8 *data, u32 size)
{
	struct cxd2880_spi_device *spi_device = NULL;
	struct spi_message msg;
	struct spi_transfer tx;
	int result = 0;

	if (!spi || !spi->user || !data || size == 0)
		return -EINVAL;

	spi_device = spi->user;

	memset(&tx, 0, sizeof(tx));
	tx.tx_buf = data;
	tx.len = size;

	spi_message_init(&msg);
	spi_message_add_tail(&tx, &msg);
	result = spi_sync(spi_device->spi, &msg);

	if (result < 0)
		return -EIO;

	return 0;
}

__attribute__((used)) static int cxd2880_spi_device_write_read(struct cxd2880_spi *spi,
					 const u8 *tx_data,
					 u32 tx_size,
					 u8 *rx_data,
					 u32 rx_size)
{
	struct cxd2880_spi_device *spi_device = NULL;
	int result = 0;

	if (!spi || !spi->user || !tx_data ||
	    !tx_size || !rx_data || !rx_size)
		return -EINVAL;

	spi_device = spi->user;

	result = spi_write_then_read(spi_device->spi, tx_data,
				     tx_size, rx_data, rx_size);
	if (result < 0)
		return -EIO;

	return 0;
}

int
cxd2880_spi_device_initialize(struct cxd2880_spi_device *spi_device,
			      enum cxd2880_spi_mode mode,
			      u32 speed_hz)
{
	int result = 0;
	struct spi_device *spi = spi_device->spi;

	switch (mode) {
	case CXD2880_SPI_MODE_0:
		spi->mode = SPI_MODE_0;
		break;
	case CXD2880_SPI_MODE_1:
		spi->mode = SPI_MODE_1;
		break;
	case CXD2880_SPI_MODE_2:
		spi->mode = SPI_MODE_2;
		break;
	case CXD2880_SPI_MODE_3:
		spi->mode = SPI_MODE_3;
		break;
	default:
		return -EINVAL;
	}

	spi->max_speed_hz = speed_hz;
	spi->bits_per_word = 8;
	result = spi_setup(spi);
	if (result != 0) {
		pr_err("spi_setup failed %d\n", result);
		return -EINVAL;
	}

	return 0;
}

int cxd2880_spi_device_create_spi(struct cxd2880_spi *spi,
				  struct cxd2880_spi_device *spi_device)
{
	if (!spi || !spi_device)
		return -EINVAL;

	spi->read = NULL;
	spi->write = cxd2880_spi_device_write;
	spi->write_read = cxd2880_spi_device_write_read;
	spi->flags = 0;
	spi->user = spi_device;

	return 0;
}

