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
struct tle62x0_state {unsigned char* tx_buff; unsigned int gpio_state; int nr_gpio; unsigned char* rx_buff; int /*<<< orphan*/  lock; struct spi_device* us; } ;
struct tle62x0_pdata {int gpio_count; int init_state; } ;
struct spi_transfer {unsigned char* tx_buf; unsigned char* rx_buf; int len; } ;
struct spi_message {int dummy; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (struct device_attribute**) ; 
 unsigned char CMD_READ ; 
 unsigned char CMD_SET ; 
#define  DIAG_NORMAL 131 
#define  DIAG_OPEN 130 
#define  DIAG_OVERLOAD 129 
#define  DIAG_SHORTGND 128 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct device_attribute dev_attr_status_show ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct tle62x0_state* dev_get_drvdata (struct device*) ; 
 struct tle62x0_pdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int device_create_file (int /*<<< orphan*/ *,struct device_attribute*) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,struct device_attribute*) ; 
 struct device_attribute** gpio_attrs ; 
 int /*<<< orphan*/  kfree (struct tle62x0_state*) ; 
 struct tle62x0_state* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned long simple_strtoul (char const*,char**,int /*<<< orphan*/ ) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct tle62x0_state* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct tle62x0_state*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_write (struct spi_device*,unsigned char*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned char*) ; 
static  int to_gpio_num (struct device_attribute*) ; 

__attribute__((used)) static inline int tle62x0_write(struct tle62x0_state *st)
{
	unsigned char *buff = st->tx_buff;
	unsigned int gpio_state = st->gpio_state;

	buff[0] = CMD_SET;

	if (st->nr_gpio == 16) {
		buff[1] = gpio_state >> 8;
		buff[2] = gpio_state;
	} else {
		buff[1] = gpio_state;
	}

	dev_dbg(&st->us->dev, "buff %3ph\n", buff);

	return spi_write(st->us, buff, (st->nr_gpio == 16) ? 3 : 2);
}

__attribute__((used)) static inline int tle62x0_read(struct tle62x0_state *st)
{
	unsigned char *txbuff = st->tx_buff;
	struct spi_transfer xfer = {
		.tx_buf		= txbuff,
		.rx_buf		= st->rx_buff,
		.len		= (st->nr_gpio * 2) / 8,
	};
	struct spi_message msg;

	txbuff[0] = CMD_READ;
	txbuff[1] = 0x00;
	txbuff[2] = 0x00;
	txbuff[3] = 0x00;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	return spi_sync(st->us, &msg);
}

__attribute__((used)) static unsigned char *decode_fault(unsigned int fault_code)
{
	fault_code &= 3;

	switch (fault_code) {
	case DIAG_NORMAL:
		return "N";
	case DIAG_OVERLOAD:
		return "V";
	case DIAG_OPEN:
		return "O";
	case DIAG_SHORTGND:
		return "G";
	}

	return "?";
}

__attribute__((used)) static ssize_t tle62x0_status_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct tle62x0_state *st = dev_get_drvdata(dev);
	char *bp = buf;
	unsigned char *buff = st->rx_buff;
	unsigned long fault = 0;
	int ptr;
	int ret;

	mutex_lock(&st->lock);
	ret = tle62x0_read(st);
	dev_dbg(dev, "tle62x0_read() returned %d\n", ret);
	if (ret < 0) {
		mutex_unlock(&st->lock);
		return ret;
	}

	for (ptr = 0; ptr < (st->nr_gpio * 2)/8; ptr += 1) {
		fault <<= 8;
		fault  |= ((unsigned long)buff[ptr]);

		dev_dbg(dev, "byte %d is %02x\n", ptr, buff[ptr]);
	}

	for (ptr = 0; ptr < st->nr_gpio; ptr++) {
		bp += sprintf(bp, "%s ", decode_fault(fault >> (ptr * 2)));
	}

	*bp++ = '\n';

	mutex_unlock(&st->lock);
	return bp - buf;
}

__attribute__((used)) static ssize_t tle62x0_gpio_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct tle62x0_state *st = dev_get_drvdata(dev);
	int gpio_num = to_gpio_num(attr);
	int value;

	mutex_lock(&st->lock);
	value = (st->gpio_state >> gpio_num) & 1;
	mutex_unlock(&st->lock);

	return snprintf(buf, PAGE_SIZE, "%d", value);
}

__attribute__((used)) static ssize_t tle62x0_gpio_store(struct device *dev,
		struct device_attribute *attr,
		const char *buf, size_t len)
{
	struct tle62x0_state *st = dev_get_drvdata(dev);
	int gpio_num = to_gpio_num(attr);
	unsigned long val;
	char *endp;

	val = simple_strtoul(buf, &endp, 0);
	if (buf == endp)
		return -EINVAL;

	dev_dbg(dev, "setting gpio %d to %ld\n", gpio_num, val);

	mutex_lock(&st->lock);

	if (val)
		st->gpio_state |= 1 << gpio_num;
	else
		st->gpio_state &= ~(1 << gpio_num);

	tle62x0_write(st);
	mutex_unlock(&st->lock);

	return len;
}

__attribute__((used)) static int to_gpio_num(struct device_attribute *attr)
{
	int ptr;

	for (ptr = 0; ptr < ARRAY_SIZE(gpio_attrs); ptr++) {
		if (gpio_attrs[ptr] == attr)
			return ptr;
	}

	return -1;
}

__attribute__((used)) static int tle62x0_probe(struct spi_device *spi)
{
	struct tle62x0_state *st;
	struct tle62x0_pdata *pdata;
	int ptr;
	int ret;

	pdata = dev_get_platdata(&spi->dev);
	if (pdata == NULL) {
		dev_err(&spi->dev, "no device data specified\n");
		return -EINVAL;
	}

	st = kzalloc(sizeof(struct tle62x0_state), GFP_KERNEL);
	if (st == NULL)
		return -ENOMEM;

	st->us = spi;
	st->nr_gpio = pdata->gpio_count;
	st->gpio_state = pdata->init_state;

	mutex_init(&st->lock);

	ret = device_create_file(&spi->dev, &dev_attr_status_show);
	if (ret) {
		dev_err(&spi->dev, "cannot create status attribute\n");
		goto err_status;
	}

	for (ptr = 0; ptr < pdata->gpio_count; ptr++) {
		ret = device_create_file(&spi->dev, gpio_attrs[ptr]);
		if (ret) {
			dev_err(&spi->dev, "cannot create gpio attribute\n");
			goto err_gpios;
		}
	}

	/* tle62x0_write(st); */
	spi_set_drvdata(spi, st);
	return 0;

 err_gpios:
	while (--ptr >= 0)
		device_remove_file(&spi->dev, gpio_attrs[ptr]);

	device_remove_file(&spi->dev, &dev_attr_status_show);

 err_status:
	kfree(st);
	return ret;
}

__attribute__((used)) static int tle62x0_remove(struct spi_device *spi)
{
	struct tle62x0_state *st = spi_get_drvdata(spi);
	int ptr;

	for (ptr = 0; ptr < st->nr_gpio; ptr++)
		device_remove_file(&spi->dev, gpio_attrs[ptr]);

	device_remove_file(&spi->dev, &dev_attr_status_show);
	kfree(st);
	return 0;
}

