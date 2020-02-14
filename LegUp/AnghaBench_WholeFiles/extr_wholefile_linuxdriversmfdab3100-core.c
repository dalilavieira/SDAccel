#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct notifier_block {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; scalar_t__ addr; int /*<<< orphan*/  adapter; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct ab3100_platform_data {int dummy; } ;
struct ab3100 {int chip_id; int startup_events_read; int* startup_events; struct i2c_client* testreg_client; int /*<<< orphan*/ * chip_name; struct i2c_client* i2c_client; int /*<<< orphan*/ * dev; int /*<<< orphan*/  event_subscribers; int /*<<< orphan*/  access_mutex; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {int id; char* name; } ;
struct TYPE_6__ {int abreg; int setting; int pdata_size; struct ab3100_platform_data* platform_data; } ;

/* Variables and functions */
 int AB3100_CID ; 
 int AB3100_EVENTA1 ; 
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  BLOCKING_INIT_NOTIFIER_HEAD (int /*<<< orphan*/ *) ; 
 int EAGAIN ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 TYPE_1__* ab3100_devs ; 
 TYPE_1__* ab3100_init_settings ; 
 int /*<<< orphan*/  ab3100_ops ; 
 int abx500_register_ops (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct ab3100* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct ab3100_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct ab3100* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct ab3100*) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ab3100*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 TYPE_2__* ids ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ *,int,char*,char*) ; 

__attribute__((used)) static int ab3100_get_chip_id(struct device *dev)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return (int)ab3100->chip_id;
}

__attribute__((used)) static int ab3100_set_register_interruptible(struct ab3100 *ab3100,
	u8 reg, u8 regval)
{
	u8 regandval[2] = {reg, regval};
	int err;

	err = mutex_lock_interruptible(&ab3100->access_mutex);
	if (err)
		return err;

	/*
	 * A two-byte write message with the first byte containing the register
	 * number and the second byte containing the value to be written
	 * effectively sets a register in the AB3100.
	 */
	err = i2c_master_send(ab3100->i2c_client, regandval, 2);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (write register): %d\n",
			err);
	} else if (err != 2) {
		dev_err(ab3100->dev,
			"write error (write register)\n"
			"  %d bytes transferred (expected 2)\n",
			err);
		err = -EIO;
	} else {
		/* All is well */
		err = 0;
	}
	mutex_unlock(&ab3100->access_mutex);
	return err;
}

__attribute__((used)) static int set_register_interruptible(struct device *dev,
	u8 bank, u8 reg, u8 value)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return ab3100_set_register_interruptible(ab3100, reg, value);
}

__attribute__((used)) static int ab3100_set_test_register_interruptible(struct ab3100 *ab3100,
				    u8 reg, u8 regval)
{
	u8 regandval[2] = {reg, regval};
	int err;

	err = mutex_lock_interruptible(&ab3100->access_mutex);
	if (err)
		return err;

	err = i2c_master_send(ab3100->testreg_client, regandval, 2);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (write test register): %d\n",
			err);
	} else if (err != 2) {
		dev_err(ab3100->dev,
			"write error (write test register)\n"
			"  %d bytes transferred (expected 2)\n",
			err);
		err = -EIO;
	} else {
		/* All is well */
		err = 0;
	}
	mutex_unlock(&ab3100->access_mutex);

	return err;
}

__attribute__((used)) static int ab3100_get_register_interruptible(struct ab3100 *ab3100,
					     u8 reg, u8 *regval)
{
	int err;

	err = mutex_lock_interruptible(&ab3100->access_mutex);
	if (err)
		return err;

	/*
	 * AB3100 require an I2C "stop" command between each message, else
	 * it will not work. The only way of achieveing this with the
	 * message transport layer is to send the read and write messages
	 * separately.
	 */
	err = i2c_master_send(ab3100->i2c_client, &reg, 1);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (send register address): %d\n",
			err);
		goto get_reg_out_unlock;
	} else if (err != 1) {
		dev_err(ab3100->dev,
			"write error (send register address)\n"
			"  %d bytes transferred (expected 1)\n",
			err);
		err = -EIO;
		goto get_reg_out_unlock;
	} else {
		/* All is well */
		err = 0;
	}

	err = i2c_master_recv(ab3100->i2c_client, regval, 1);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (read register): %d\n",
			err);
		goto get_reg_out_unlock;
	} else if (err != 1) {
		dev_err(ab3100->dev,
			"write error (read register)\n"
			"  %d bytes transferred (expected 1)\n",
			err);
		err = -EIO;
		goto get_reg_out_unlock;
	} else {
		/* All is well */
		err = 0;
	}

 get_reg_out_unlock:
	mutex_unlock(&ab3100->access_mutex);
	return err;
}

__attribute__((used)) static int get_register_interruptible(struct device *dev, u8 bank, u8 reg,
				      u8 *value)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return ab3100_get_register_interruptible(ab3100, reg, value);
}

__attribute__((used)) static int ab3100_get_register_page_interruptible(struct ab3100 *ab3100,
			     u8 first_reg, u8 *regvals, u8 numregs)
{
	int err;

	if (ab3100->chip_id == 0xa0 ||
	    ab3100->chip_id == 0xa1)
		/* These don't support paged reads */
		return -EIO;

	err = mutex_lock_interruptible(&ab3100->access_mutex);
	if (err)
		return err;

	/*
	 * Paged read also require an I2C "stop" command.
	 */
	err = i2c_master_send(ab3100->i2c_client, &first_reg, 1);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (send first register address): %d\n",
			err);
		goto get_reg_page_out_unlock;
	} else if (err != 1) {
		dev_err(ab3100->dev,
			"write error (send first register address)\n"
			"  %d bytes transferred (expected 1)\n",
			err);
		err = -EIO;
		goto get_reg_page_out_unlock;
	}

	err = i2c_master_recv(ab3100->i2c_client, regvals, numregs);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (read register page): %d\n",
			err);
		goto get_reg_page_out_unlock;
	} else if (err != numregs) {
		dev_err(ab3100->dev,
			"write error (read register page)\n"
			"  %d bytes transferred (expected %d)\n",
			err, numregs);
		err = -EIO;
		goto get_reg_page_out_unlock;
	}

	/* All is well */
	err = 0;

 get_reg_page_out_unlock:
	mutex_unlock(&ab3100->access_mutex);
	return err;
}

__attribute__((used)) static int get_register_page_interruptible(struct device *dev, u8 bank,
	u8 first_reg, u8 *regvals, u8 numregs)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return ab3100_get_register_page_interruptible(ab3100,
			first_reg, regvals, numregs);
}

__attribute__((used)) static int ab3100_mask_and_set_register_interruptible(struct ab3100 *ab3100,
				 u8 reg, u8 andmask, u8 ormask)
{
	u8 regandval[2] = {reg, 0};
	int err;

	err = mutex_lock_interruptible(&ab3100->access_mutex);
	if (err)
		return err;

	/* First read out the target register */
	err = i2c_master_send(ab3100->i2c_client, &reg, 1);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (maskset send address): %d\n",
			err);
		goto get_maskset_unlock;
	} else if (err != 1) {
		dev_err(ab3100->dev,
			"write error (maskset send address)\n"
			"  %d bytes transferred (expected 1)\n",
			err);
		err = -EIO;
		goto get_maskset_unlock;
	}

	err = i2c_master_recv(ab3100->i2c_client, &regandval[1], 1);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (maskset read register): %d\n",
			err);
		goto get_maskset_unlock;
	} else if (err != 1) {
		dev_err(ab3100->dev,
			"write error (maskset read register)\n"
			"  %d bytes transferred (expected 1)\n",
			err);
		err = -EIO;
		goto get_maskset_unlock;
	}

	/* Modify the register */
	regandval[1] &= andmask;
	regandval[1] |= ormask;

	/* Write the register */
	err = i2c_master_send(ab3100->i2c_client, regandval, 2);
	if (err < 0) {
		dev_err(ab3100->dev,
			"write error (write register): %d\n",
			err);
		goto get_maskset_unlock;
	} else if (err != 2) {
		dev_err(ab3100->dev,
			"write error (write register)\n"
			"  %d bytes transferred (expected 2)\n",
			err);
		err = -EIO;
		goto get_maskset_unlock;
	}

	/* All is well */
	err = 0;

 get_maskset_unlock:
	mutex_unlock(&ab3100->access_mutex);
	return err;
}

__attribute__((used)) static int mask_and_set_register_interruptible(struct device *dev, u8 bank,
	u8 reg, u8 bitmask, u8 bitvalues)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return ab3100_mask_and_set_register_interruptible(ab3100,
			reg, bitmask, (bitmask & bitvalues));
}

int ab3100_event_register(struct ab3100 *ab3100,
			  struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&ab3100->event_subscribers,
					       nb);
}

int ab3100_event_unregister(struct ab3100 *ab3100,
			    struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&ab3100->event_subscribers,
					    nb);
}

__attribute__((used)) static int ab3100_event_registers_startup_state_get(struct device *dev,
					     u8 *event)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	if (!ab3100->startup_events_read)
		return -EAGAIN; /* Try again later */
	memcpy(event, ab3100->startup_events, 3);

	return 0;
}

__attribute__((used)) static irqreturn_t ab3100_irq_handler(int irq, void *data)
{
	struct ab3100 *ab3100 = data;
	u8 event_regs[3];
	u32 fatevent;
	int err;

	err = ab3100_get_register_page_interruptible(ab3100, AB3100_EVENTA1,
				       event_regs, 3);
	if (err)
		goto err_event;

	fatevent = (event_regs[0] << 16) |
		(event_regs[1] << 8) |
		event_regs[2];

	if (!ab3100->startup_events_read) {
		ab3100->startup_events[0] = event_regs[0];
		ab3100->startup_events[1] = event_regs[1];
		ab3100->startup_events[2] = event_regs[2];
		ab3100->startup_events_read = true;
	}
	/*
	 * The notified parties will have to mask out the events
	 * they're interested in and react to them. They will be
	 * notified on all events, then they use the fatevent value
	 * to determine if they're interested.
	 */
	blocking_notifier_call_chain(&ab3100->event_subscribers,
				     fatevent, NULL);

	dev_dbg(ab3100->dev,
		"IRQ Event: 0x%08x\n", fatevent);

	return IRQ_HANDLED;

 err_event:
	dev_dbg(ab3100->dev,
		"error reading event status\n");
	return IRQ_HANDLED;
}

__attribute__((used)) static inline void ab3100_setup_debugfs(struct ab3100 *ab3100)
{
}

__attribute__((used)) static int ab3100_setup(struct ab3100 *ab3100)
{
	int err = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(ab3100_init_settings); i++) {
		err = ab3100_set_register_interruptible(ab3100,
					  ab3100_init_settings[i].abreg,
					  ab3100_init_settings[i].setting);
		if (err)
			goto exit_no_setup;
	}

	/*
	 * Special trick to make the AB3100 use the 32kHz clock (RTC)
	 * bit 3 in test register 0x02 is a special, undocumented test
	 * register bit that only exist in AB3100 P1E
	 */
	if (ab3100->chip_id == 0xc4) {
		dev_warn(ab3100->dev,
			 "AB3100 P1E variant detected forcing chip to 32KHz\n");
		err = ab3100_set_test_register_interruptible(ab3100,
			0x02, 0x08);
	}

 exit_no_setup:
	return err;
}

__attribute__((used)) static int ab3100_probe(struct i2c_client *client,
				  const struct i2c_device_id *id)
{
	struct ab3100 *ab3100;
	struct ab3100_platform_data *ab3100_plf_data =
		dev_get_platdata(&client->dev);
	int err;
	int i;

	ab3100 = devm_kzalloc(&client->dev, sizeof(struct ab3100), GFP_KERNEL);
	if (!ab3100)
		return -ENOMEM;

	/* Initialize data structure */
	mutex_init(&ab3100->access_mutex);
	BLOCKING_INIT_NOTIFIER_HEAD(&ab3100->event_subscribers);

	ab3100->i2c_client = client;
	ab3100->dev = &ab3100->i2c_client->dev;

	i2c_set_clientdata(client, ab3100);

	/* Read chip ID register */
	err = ab3100_get_register_interruptible(ab3100, AB3100_CID,
						&ab3100->chip_id);
	if (err) {
		dev_err(&client->dev,
			"failed to communicate with AB3100 chip\n");
		goto exit_no_detect;
	}

	for (i = 0; ids[i].id != 0x0; i++) {
		if (ids[i].id == ab3100->chip_id) {
			if (ids[i].name)
				break;

			dev_err(&client->dev, "AB3000 is not supported\n");
			goto exit_no_detect;
		}
	}

	snprintf(&ab3100->chip_name[0],
		 sizeof(ab3100->chip_name) - 1, "AB3100 %s", ids[i].name);

	if (ids[i].id == 0x0) {
		dev_err(&client->dev, "unknown analog baseband chip id: 0x%x\n",
			ab3100->chip_id);
		dev_err(&client->dev,
			"accepting it anyway. Please update the driver.\n");
		goto exit_no_detect;
	}

	dev_info(&client->dev, "Detected chip: %s\n",
		 &ab3100->chip_name[0]);

	/* Attach a second dummy i2c_client to the test register address */
	ab3100->testreg_client = i2c_new_dummy(client->adapter,
					       client->addr + 1);
	if (!ab3100->testreg_client) {
		err = -ENOMEM;
		goto exit_no_testreg_client;
	}

	err = ab3100_setup(ab3100);
	if (err)
		goto exit_no_setup;

	err = devm_request_threaded_irq(&client->dev,
					client->irq, NULL, ab3100_irq_handler,
					IRQF_ONESHOT, "ab3100-core", ab3100);
	if (err)
		goto exit_no_irq;

	err = abx500_register_ops(&client->dev, &ab3100_ops);
	if (err)
		goto exit_no_ops;

	/* Set up and register the platform devices. */
	for (i = 0; i < ARRAY_SIZE(ab3100_devs); i++) {
		ab3100_devs[i].platform_data = ab3100_plf_data;
		ab3100_devs[i].pdata_size = sizeof(struct ab3100_platform_data);
	}

	err = mfd_add_devices(&client->dev, 0, ab3100_devs,
			      ARRAY_SIZE(ab3100_devs), NULL, 0, NULL);

	ab3100_setup_debugfs(ab3100);

	return 0;

 exit_no_ops:
 exit_no_irq:
 exit_no_setup:
	i2c_unregister_device(ab3100->testreg_client);
 exit_no_testreg_client:
 exit_no_detect:
	return err;
}

