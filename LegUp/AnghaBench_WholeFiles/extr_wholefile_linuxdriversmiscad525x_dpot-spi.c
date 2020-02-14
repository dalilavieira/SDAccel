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
typedef  int u16 ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct ad_dpot_bus_data {int /*<<< orphan*/ * bops; struct spi_device* client; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; int /*<<< orphan*/  driver_data; } ;

/* Variables and functions */
 int ad_dpot_probe (int /*<<< orphan*/ *,struct ad_dpot_bus_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ad_dpot_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bops ; 
 TYPE_1__* spi_get_device_id (struct spi_device*) ; 
 int spi_read (void*,int*,int) ; 
 int spi_write (void*,int*,int) ; 

__attribute__((used)) static int write8(void *client, u8 val)
{
	u8 data = val;

	return spi_write(client, &data, 1);
}

__attribute__((used)) static int write16(void *client, u8 reg, u8 val)
{
	u8 data[2] = {reg, val};

	return spi_write(client, data, 2);
}

__attribute__((used)) static int write24(void *client, u8 reg, u16 val)
{
	u8 data[3] = {reg, val >> 8, val};

	return spi_write(client, data, 3);
}

__attribute__((used)) static int read8(void *client)
{
	int ret;
	u8 data;

	ret = spi_read(client, &data, 1);
	if (ret < 0)
		return ret;

	return data;
}

__attribute__((used)) static int read16(void *client, u8 reg)
{
	int ret;
	u8 buf_rx[2];

	write16(client, reg, 0);
	ret = spi_read(client, buf_rx, 2);
	if (ret < 0)
		return ret;

	return (buf_rx[0] << 8) |  buf_rx[1];
}

__attribute__((used)) static int read24(void *client, u8 reg)
{
	int ret;
	u8 buf_rx[3];

	write24(client, reg, 0);
	ret = spi_read(client, buf_rx, 3);
	if (ret < 0)
		return ret;

	return (buf_rx[1] << 8) |  buf_rx[2];
}

__attribute__((used)) static int ad_dpot_spi_probe(struct spi_device *spi)
{
	struct ad_dpot_bus_data bdata = {
		.client = spi,
		.bops = &bops,
	};

	return ad_dpot_probe(&spi->dev, &bdata,
			     spi_get_device_id(spi)->driver_data,
			     spi_get_device_id(spi)->name);
}

__attribute__((used)) static int ad_dpot_spi_remove(struct spi_device *spi)
{
	return ad_dpot_remove(&spi->dev);
}

