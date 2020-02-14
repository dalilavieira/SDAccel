#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_1__* bit; } ;
struct TYPE_12__ {int /*<<< orphan*/  next; } ;
struct snd_i2c_device {unsigned char addr; int flags; struct snd_i2c_device* bus; TYPE_2__ hw_ops; TYPE_3__* ops; int /*<<< orphan*/  (* private_free ) (struct snd_i2c_device*) ;TYPE_4__ list; TYPE_4__ devices; int /*<<< orphan*/  name; struct snd_i2c_device* master; TYPE_4__ buses; struct snd_card* card; int /*<<< orphan*/  lock_mutex; } ;
struct snd_i2c_bus {unsigned char addr; int flags; struct snd_i2c_bus* bus; TYPE_2__ hw_ops; TYPE_3__* ops; int /*<<< orphan*/  (* private_free ) (struct snd_i2c_device*) ;TYPE_4__ list; TYPE_4__ devices; int /*<<< orphan*/  name; struct snd_i2c_bus* master; TYPE_4__ buses; struct snd_card* card; int /*<<< orphan*/  lock_mutex; } ;
struct snd_device_ops {int (* dev_free ) (struct snd_device*) ;} ;
struct snd_device {struct snd_i2c_device* device_data; } ;
struct snd_card {int dummy; } ;
struct TYPE_11__ {int (* sendbytes ) (struct snd_i2c_device*,unsigned char*,int) ;int (* readbytes ) (struct snd_i2c_device*,unsigned char*,int) ;int (* probeaddr ) (struct snd_i2c_device*,unsigned short) ;} ;
struct TYPE_9__ {int (* getdata ) (struct snd_i2c_device*,int) ;int /*<<< orphan*/  (* setlines ) (struct snd_i2c_device*,int,int) ;int /*<<< orphan*/  (* direction ) (struct snd_i2c_device*,int,int) ;int /*<<< orphan*/  (* stop ) (struct snd_i2c_device*) ;int /*<<< orphan*/  (* start ) (struct snd_i2c_device*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (TYPE_4__*) ; 
 int /*<<< orphan*/  SNDRV_DEV_BUS ; 
 int SND_I2C_DEVICE_ADDRTEN ; 
 int /*<<< orphan*/  kfree (struct snd_i2c_device*) ; 
 struct snd_i2c_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  list_del (TYPE_4__*) ; 
 int /*<<< orphan*/  list_empty (TYPE_4__*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_device_free (struct snd_card*,struct snd_i2c_device*) ; 
 int snd_device_new (struct snd_card*,int /*<<< orphan*/ ,struct snd_i2c_device*,struct snd_device_ops*) ; 
 TYPE_3__ snd_i2c_bit_ops ; 
 struct snd_i2c_device* snd_i2c_device (int /*<<< orphan*/ ) ; 
 int snd_i2c_device_free (struct snd_i2c_device*) ; 
 struct snd_i2c_device* snd_i2c_slave_bus (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  stub1 (struct snd_i2c_device*) ; 
 int stub10 (struct snd_i2c_device*,int) ; 
 int /*<<< orphan*/  stub2 (struct snd_i2c_device*) ; 
 int stub3 (struct snd_i2c_device*,unsigned char*,int) ; 
 int stub4 (struct snd_i2c_device*,unsigned char*,int) ; 
 int stub5 (struct snd_i2c_device*,unsigned short) ; 
 int /*<<< orphan*/  stub6 (struct snd_i2c_device*) ; 
 int /*<<< orphan*/  stub7 (struct snd_i2c_device*) ; 
 int /*<<< orphan*/  stub8 (struct snd_i2c_device*,int,int) ; 
 int /*<<< orphan*/  stub9 (struct snd_i2c_device*,int,int) ; 

__attribute__((used)) static int snd_i2c_bus_free(struct snd_i2c_bus *bus)
{
	struct snd_i2c_bus *slave;
	struct snd_i2c_device *device;

	if (snd_BUG_ON(!bus))
		return -EINVAL;
	while (!list_empty(&bus->devices)) {
		device = snd_i2c_device(bus->devices.next);
		snd_i2c_device_free(device);
	}
	if (bus->master)
		list_del(&bus->buses);
	else {
		while (!list_empty(&bus->buses)) {
			slave = snd_i2c_slave_bus(bus->buses.next);
			snd_device_free(bus->card, slave);
		}
	}
	if (bus->private_free)
		bus->private_free(bus);
	kfree(bus);
	return 0;
}

__attribute__((used)) static int snd_i2c_bus_dev_free(struct snd_device *device)
{
	struct snd_i2c_bus *bus = device->device_data;
	return snd_i2c_bus_free(bus);
}

int snd_i2c_bus_create(struct snd_card *card, const char *name,
		       struct snd_i2c_bus *master, struct snd_i2c_bus **ri2c)
{
	struct snd_i2c_bus *bus;
	int err;
	static struct snd_device_ops ops = {
		.dev_free =	snd_i2c_bus_dev_free,
	};

	*ri2c = NULL;
	bus = kzalloc(sizeof(*bus), GFP_KERNEL);
	if (bus == NULL)
		return -ENOMEM;
	mutex_init(&bus->lock_mutex);
	INIT_LIST_HEAD(&bus->devices);
	INIT_LIST_HEAD(&bus->buses);
	bus->card = card;
	bus->ops = &snd_i2c_bit_ops;
	if (master) {
		list_add_tail(&bus->buses, &master->buses);
		bus->master = master;
	}
	strlcpy(bus->name, name, sizeof(bus->name));
	err = snd_device_new(card, SNDRV_DEV_BUS, bus, &ops);
	if (err < 0) {
		snd_i2c_bus_free(bus);
		return err;
	}
	*ri2c = bus;
	return 0;
}

int snd_i2c_device_create(struct snd_i2c_bus *bus, const char *name,
			  unsigned char addr, struct snd_i2c_device **rdevice)
{
	struct snd_i2c_device *device;

	*rdevice = NULL;
	if (snd_BUG_ON(!bus))
		return -EINVAL;
	device = kzalloc(sizeof(*device), GFP_KERNEL);
	if (device == NULL)
		return -ENOMEM;
	device->addr = addr;
	strlcpy(device->name, name, sizeof(device->name));
	list_add_tail(&device->list, &bus->devices);
	device->bus = bus;
	*rdevice = device;
	return 0;
}

int snd_i2c_device_free(struct snd_i2c_device *device)
{
	if (device->bus)
		list_del(&device->list);
	if (device->private_free)
		device->private_free(device);
	kfree(device);
	return 0;
}

int snd_i2c_sendbytes(struct snd_i2c_device *device, unsigned char *bytes, int count)
{
	return device->bus->ops->sendbytes(device, bytes, count);
}

int snd_i2c_readbytes(struct snd_i2c_device *device, unsigned char *bytes, int count)
{
	return device->bus->ops->readbytes(device, bytes, count);
}

int snd_i2c_probeaddr(struct snd_i2c_bus *bus, unsigned short addr)
{
	return bus->ops->probeaddr(bus, addr);
}

__attribute__((used)) static inline void snd_i2c_bit_hw_start(struct snd_i2c_bus *bus)
{
	if (bus->hw_ops.bit->start)
		bus->hw_ops.bit->start(bus);
}

__attribute__((used)) static inline void snd_i2c_bit_hw_stop(struct snd_i2c_bus *bus)
{
	if (bus->hw_ops.bit->stop)
		bus->hw_ops.bit->stop(bus);
}

__attribute__((used)) static void snd_i2c_bit_direction(struct snd_i2c_bus *bus, int clock, int data)
{
	if (bus->hw_ops.bit->direction)
		bus->hw_ops.bit->direction(bus, clock, data);
}

__attribute__((used)) static void snd_i2c_bit_set(struct snd_i2c_bus *bus, int clock, int data)
{
	bus->hw_ops.bit->setlines(bus, clock, data);
}

__attribute__((used)) static int snd_i2c_bit_data(struct snd_i2c_bus *bus, int ack)
{
	return bus->hw_ops.bit->getdata(bus, ack);
}

__attribute__((used)) static void snd_i2c_bit_start(struct snd_i2c_bus *bus)
{
	snd_i2c_bit_hw_start(bus);
	snd_i2c_bit_direction(bus, 1, 1);	/* SCL - wr, SDA - wr */
	snd_i2c_bit_set(bus, 1, 1);
	snd_i2c_bit_set(bus, 1, 0);
	snd_i2c_bit_set(bus, 0, 0);
}

__attribute__((used)) static void snd_i2c_bit_stop(struct snd_i2c_bus *bus)
{
	snd_i2c_bit_set(bus, 0, 0);
	snd_i2c_bit_set(bus, 1, 0);
	snd_i2c_bit_set(bus, 1, 1);
	snd_i2c_bit_hw_stop(bus);
}

__attribute__((used)) static void snd_i2c_bit_send(struct snd_i2c_bus *bus, int data)
{
	snd_i2c_bit_set(bus, 0, data);
	snd_i2c_bit_set(bus, 1, data);
	snd_i2c_bit_set(bus, 0, data);
}

__attribute__((used)) static int snd_i2c_bit_ack(struct snd_i2c_bus *bus)
{
	int ack;

	snd_i2c_bit_set(bus, 0, 1);
	snd_i2c_bit_set(bus, 1, 1);
	snd_i2c_bit_direction(bus, 1, 0);	/* SCL - wr, SDA - rd */
	ack = snd_i2c_bit_data(bus, 1);
	snd_i2c_bit_direction(bus, 1, 1);	/* SCL - wr, SDA - wr */
	snd_i2c_bit_set(bus, 0, 1);
	return ack ? -EIO : 0;
}

__attribute__((used)) static int snd_i2c_bit_sendbyte(struct snd_i2c_bus *bus, unsigned char data)
{
	int i, err;

	for (i = 7; i >= 0; i--)
		snd_i2c_bit_send(bus, !!(data & (1 << i)));
	err = snd_i2c_bit_ack(bus);
	if (err < 0)
		return err;
	return 0;
}

__attribute__((used)) static int snd_i2c_bit_readbyte(struct snd_i2c_bus *bus, int last)
{
	int i;
	unsigned char data = 0;

	snd_i2c_bit_set(bus, 0, 1);
	snd_i2c_bit_direction(bus, 1, 0);	/* SCL - wr, SDA - rd */
	for (i = 7; i >= 0; i--) {
		snd_i2c_bit_set(bus, 1, 1);
		if (snd_i2c_bit_data(bus, 0))
			data |= (1 << i);
		snd_i2c_bit_set(bus, 0, 1);
	}
	snd_i2c_bit_direction(bus, 1, 1);	/* SCL - wr, SDA - wr */
	snd_i2c_bit_send(bus, !!last);
	return data;
}

__attribute__((used)) static int snd_i2c_bit_sendbytes(struct snd_i2c_device *device,
				 unsigned char *bytes, int count)
{
	struct snd_i2c_bus *bus = device->bus;
	int err, res = 0;

	if (device->flags & SND_I2C_DEVICE_ADDRTEN)
		return -EIO;		/* not yet implemented */
	snd_i2c_bit_start(bus);
	err = snd_i2c_bit_sendbyte(bus, device->addr << 1);
	if (err < 0) {
		snd_i2c_bit_hw_stop(bus);
		return err;
	}
	while (count-- > 0) {
		err = snd_i2c_bit_sendbyte(bus, *bytes++);
		if (err < 0) {
			snd_i2c_bit_hw_stop(bus);
			return err;
		}
		res++;
	}
	snd_i2c_bit_stop(bus);
	return res;
}

__attribute__((used)) static int snd_i2c_bit_readbytes(struct snd_i2c_device *device,
				 unsigned char *bytes, int count)
{
	struct snd_i2c_bus *bus = device->bus;
	int err, res = 0;

	if (device->flags & SND_I2C_DEVICE_ADDRTEN)
		return -EIO;		/* not yet implemented */
	snd_i2c_bit_start(bus);
	err = snd_i2c_bit_sendbyte(bus, (device->addr << 1) | 1);
	if (err < 0) {
		snd_i2c_bit_hw_stop(bus);
		return err;
	}
	while (count-- > 0) {
		err = snd_i2c_bit_readbyte(bus, count == 0);
		if (err < 0) {
			snd_i2c_bit_hw_stop(bus);
			return err;
		}
		*bytes++ = (unsigned char)err;
		res++;
	}
	snd_i2c_bit_stop(bus);
	return res;
}

__attribute__((used)) static int snd_i2c_bit_probeaddr(struct snd_i2c_bus *bus, unsigned short addr)
{
	int err;

	if (addr & 0x8000)	/* 10-bit address */
		return -EIO;	/* not yet implemented */
	if (addr & 0x7f80)	/* invalid address */
		return -EINVAL;
	snd_i2c_bit_start(bus);
	err = snd_i2c_bit_sendbyte(bus, addr << 1);
	snd_i2c_bit_stop(bus);
	return err;
}

