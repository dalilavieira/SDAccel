#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_8__ {struct TYPE_8__* parent; } ;
struct i2c_adapter {int /*<<< orphan*/  name; TYPE_3__ dev; struct serio* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; } ;
struct taos_data {char* buffer; scalar_t__ addr; int pos; int state; struct i2c_adapter adapter; struct i2c_client* client; } ;
struct serio_driver {int dummy; } ;
struct serio {TYPE_3__ dev; } ;
struct i2c_client {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {int /*<<< orphan*/  addr; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPROTO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
#define  I2C_SMBUS_BYTE 132 
#define  I2C_SMBUS_BYTE_DATA 131 
 char I2C_SMBUS_WRITE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  TAOS_BUFFER_SIZE ; 
 char TAOS_CMD_ECHO_OFF ; 
 char TAOS_CMD_RESET ; 
#define  TAOS_STATE_EOFF 130 
 void* TAOS_STATE_IDLE ; 
#define  TAOS_STATE_INIT 129 
#define  TAOS_STATE_RECV 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,int) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 struct i2c_client* i2c_new_device (struct i2c_adapter*,TYPE_1__*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  kfree (struct taos_data*) ; 
 scalar_t__ kstrtou8 (char*,int,int*) ; 
 struct taos_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct taos_data* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct taos_data*) ; 
 int /*<<< orphan*/  serio_write (struct serio*,char) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strncmp (int /*<<< orphan*/ ,char*,int) ; 
 char* strstr (char*,char*) ; 
 int /*<<< orphan*/  taos_algorithm ; 
 TYPE_1__ tsl2550_info ; 
 int /*<<< orphan*/  wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wq ; 

__attribute__((used)) static struct i2c_client *taos_instantiate_device(struct i2c_adapter *adapter)
{
	if (!strncmp(adapter->name, "TAOS TSL2550 EVM", 16)) {
		dev_info(&adapter->dev, "Instantiating device %s at 0x%02x\n",
			tsl2550_info.type, tsl2550_info.addr);
		return i2c_new_device(adapter, &tsl2550_info);
	}

	return NULL;
}

__attribute__((used)) static int taos_smbus_xfer(struct i2c_adapter *adapter, u16 addr,
			   unsigned short flags, char read_write, u8 command,
			   int size, union i2c_smbus_data *data)
{
	struct serio *serio = adapter->algo_data;
	struct taos_data *taos = serio_get_drvdata(serio);
	char *p;

	/* Encode our transaction. "@" is for the device address, "$" for the
	   SMBus command and "#" for the data. */
	p = taos->buffer;

	/* The device remembers the last used address, no need to send it
	   again if it's the same */
	if (addr != taos->addr)
		p += sprintf(p, "@%02X", addr);

	switch (size) {
	case I2C_SMBUS_BYTE:
		if (read_write == I2C_SMBUS_WRITE)
			sprintf(p, "$#%02X", command);
		else
			sprintf(p, "$");
		break;
	case I2C_SMBUS_BYTE_DATA:
		if (read_write == I2C_SMBUS_WRITE)
			sprintf(p, "$%02X#%02X", command, data->byte);
		else
			sprintf(p, "$%02X", command);
		break;
	default:
		dev_warn(&adapter->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	/* Send the transaction to the TAOS EVM */
	dev_dbg(&adapter->dev, "Command buffer: %s\n", taos->buffer);
	for (p = taos->buffer; *p; p++)
		serio_write(serio, *p);

	taos->addr = addr;

	/* Start the transaction and read the answer */
	taos->pos = 0;
	taos->state = TAOS_STATE_RECV;
	serio_write(serio, read_write == I2C_SMBUS_WRITE ? '>' : '<');
	wait_event_interruptible_timeout(wq, taos->state == TAOS_STATE_IDLE,
					 msecs_to_jiffies(150));
	if (taos->state != TAOS_STATE_IDLE
	 || taos->pos != 5) {
		dev_err(&adapter->dev, "Transaction timeout (pos=%d)\n",
			taos->pos);
		return -EIO;
	}
	dev_dbg(&adapter->dev, "Answer buffer: %s\n", taos->buffer);

	/* Interpret the returned string */
	p = taos->buffer + 1;
	p[3] = '\0';
	if (!strcmp(p, "NAK"))
		return -ENODEV;

	if (read_write == I2C_SMBUS_WRITE) {
		if (!strcmp(p, "ACK"))
			return 0;
	} else {
		if (p[0] == 'x') {
			/*
			 * Voluntarily dropping error code of kstrtou8 since all
			 * error code that it could return are invalid according
			 * to Documentation/i2c/fault-codes.
			 */
			if (kstrtou8(p + 1, 16, &data->byte))
				return -EPROTO;
			return 0;
		}
	}

	return -EIO;
}

__attribute__((used)) static u32 taos_smbus_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_BYTE_DATA;
}

__attribute__((used)) static irqreturn_t taos_interrupt(struct serio *serio, unsigned char data,
				  unsigned int flags)
{
	struct taos_data *taos = serio_get_drvdata(serio);

	switch (taos->state) {
	case TAOS_STATE_INIT:
		taos->buffer[taos->pos++] = data;
		if (data == ':'
		 || taos->pos == TAOS_BUFFER_SIZE - 1) {
			taos->buffer[taos->pos] = '\0';
			taos->state = TAOS_STATE_IDLE;
			wake_up_interruptible(&wq);
		}
		break;
	case TAOS_STATE_EOFF:
		taos->state = TAOS_STATE_IDLE;
		wake_up_interruptible(&wq);
		break;
	case TAOS_STATE_RECV:
		taos->buffer[taos->pos++] = data;
		if (data == ']') {
			taos->buffer[taos->pos] = '\0';
			taos->state = TAOS_STATE_IDLE;
			wake_up_interruptible(&wq);
		}
		break;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static char *taos_adapter_name(char *buffer)
{
	char *start, *end;

	start = strstr(buffer, "TAOS ");
	if (!start)
		return NULL;

	end = strchr(start, '\r');
	if (!end)
		return NULL;
	*end = '\0';

	return start;
}

__attribute__((used)) static int taos_connect(struct serio *serio, struct serio_driver *drv)
{
	struct taos_data *taos;
	struct i2c_adapter *adapter;
	char *name;
	int err;

	taos = kzalloc(sizeof(struct taos_data), GFP_KERNEL);
	if (!taos) {
		err = -ENOMEM;
		goto exit;
	}
	taos->state = TAOS_STATE_INIT;
	serio_set_drvdata(serio, taos);

	err = serio_open(serio, drv);
	if (err)
		goto exit_kfree;

	adapter = &taos->adapter;
	adapter->owner = THIS_MODULE;
	adapter->algo = &taos_algorithm;
	adapter->algo_data = serio;
	adapter->dev.parent = &serio->dev;

	/* Reset the TAOS evaluation module to identify it */
	serio_write(serio, TAOS_CMD_RESET);
	wait_event_interruptible_timeout(wq, taos->state == TAOS_STATE_IDLE,
					 msecs_to_jiffies(2000));

	if (taos->state != TAOS_STATE_IDLE) {
		err = -ENODEV;
		dev_err(&serio->dev, "TAOS EVM reset failed (state=%d, "
			"pos=%d)\n", taos->state, taos->pos);
		goto exit_close;
	}

	name = taos_adapter_name(taos->buffer);
	if (!name) {
		err = -ENODEV;
		dev_err(&serio->dev, "TAOS EVM identification failed\n");
		goto exit_close;
	}
	strlcpy(adapter->name, name, sizeof(adapter->name));

	/* Turn echo off for better performance */
	taos->state = TAOS_STATE_EOFF;
	serio_write(serio, TAOS_CMD_ECHO_OFF);

	wait_event_interruptible_timeout(wq, taos->state == TAOS_STATE_IDLE,
					 msecs_to_jiffies(250));
	if (taos->state != TAOS_STATE_IDLE) {
		err = -ENODEV;
		dev_err(&serio->dev, "TAOS EVM echo off failed "
			"(state=%d)\n", taos->state);
		goto exit_close;
	}

	err = i2c_add_adapter(adapter);
	if (err)
		goto exit_close;
	dev_info(&serio->dev, "Connected to TAOS EVM\n");

	taos->client = taos_instantiate_device(adapter);
	return 0;

 exit_close:
	serio_close(serio);
 exit_kfree:
	kfree(taos);
 exit:
	return err;
}

__attribute__((used)) static void taos_disconnect(struct serio *serio)
{
	struct taos_data *taos = serio_get_drvdata(serio);

	i2c_unregister_device(taos->client);
	i2c_del_adapter(&taos->adapter);
	serio_close(serio);
	kfree(taos);

	dev_info(&serio->dev, "Disconnected from TAOS EVM\n");
}

