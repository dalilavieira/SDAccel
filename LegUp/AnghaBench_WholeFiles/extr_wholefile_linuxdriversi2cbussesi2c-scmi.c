#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; int word; int* block; } ;
struct TYPE_10__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_11__ {int class; TYPE_4__ dev; union acpi_object* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct TYPE_9__ {int value; } ;
struct TYPE_8__ {union acpi_object* elements; } ;
struct TYPE_7__ {int length; int /*<<< orphan*/  pointer; } ;
union acpi_object {scalar_t__ type; int cap_read; int cap_write; int cap_info; TYPE_5__ adapter; struct acpi_handle* handle; struct smbus_methods_t* methods; TYPE_3__ integer; TYPE_2__ package; TYPE_1__ buffer; } ;
typedef  unsigned char u8 ;
typedef  int u32 ;
typedef  unsigned char u16 ;
struct smbus_methods_t {char* mt_sbr; char* mt_sbw; char* mt_info; } ;
struct i2c_adapter {union acpi_object* algo_data; int /*<<< orphan*/  dev; } ;
struct acpi_smbus_cmi {scalar_t__ type; int cap_read; int cap_write; int cap_info; TYPE_5__ adapter; struct acpi_handle* handle; struct smbus_methods_t* methods; TYPE_3__ integer; TYPE_2__ package; TYPE_1__ buffer; } ;
struct acpi_object_list {int count; union acpi_object* pointer; } ;
struct acpi_handle {int dummy; } ;
struct acpi_device_id {char const* id; scalar_t__ driver_data; } ;
struct acpi_device {union acpi_object* driver_data; int /*<<< orphan*/  dev; struct acpi_handle* handle; } ;
struct acpi_buffer {int member_0; char* member_1; union acpi_object* pointer; } ;
typedef  int /*<<< orphan*/  node_name ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 int ACPI_ALLOCATE_BUFFER ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_SINGLE_NAME ; 
 int /*<<< orphan*/  ACPI_SMBUS_HC_CLASS ; 
 int /*<<< orphan*/  ACPI_SMBUS_HC_DEVICE_NAME ; 
 unsigned char ACPI_SMBUS_PRTCL_BLOCK_DATA ; 
 unsigned char ACPI_SMBUS_PRTCL_BYTE ; 
 unsigned char ACPI_SMBUS_PRTCL_BYTE_DATA ; 
 unsigned char ACPI_SMBUS_PRTCL_QUICK ; 
 unsigned char ACPI_SMBUS_PRTCL_READ ; 
 unsigned char ACPI_SMBUS_PRTCL_WORD_DATA ; 
 unsigned char ACPI_SMBUS_PRTCL_WRITE ; 
#define  ACPI_SMBUS_STATUS_BUSY 136 
#define  ACPI_SMBUS_STATUS_DNAK 135 
#define  ACPI_SMBUS_STATUS_OK 134 
#define  ACPI_SMBUS_STATUS_TIMEOUT 133 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_TYPE_BUFFER ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 int /*<<< orphan*/  ACPI_TYPE_METHOD ; 
 scalar_t__ ACPI_TYPE_PACKAGE ; 
 int /*<<< orphan*/  AE_OK ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_CLASS_HWMON ; 
 int I2C_CLASS_SPD ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_READ_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_READ_BYTE ; 
 int I2C_FUNC_SMBUS_READ_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_WORD_DATA ; 
#define  I2C_SMBUS_BLOCK_DATA 132 
 int I2C_SMBUS_BLOCK_MAX ; 
#define  I2C_SMBUS_BYTE 131 
#define  I2C_SMBUS_BYTE_DATA 130 
#define  I2C_SMBUS_QUICK 129 
 char I2C_SMBUS_READ ; 
#define  I2C_SMBUS_WORD_DATA 128 
 char I2C_SMBUS_WRITE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 char* acpi_device_class (struct acpi_device*) ; 
 char* acpi_device_hid (struct acpi_device*) ; 
 char* acpi_device_name (struct acpi_device*) ; 
 union acpi_object* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_evaluate_object (struct acpi_handle*,char*,struct acpi_object_list*,struct acpi_buffer*) ; 
 int /*<<< orphan*/  acpi_get_name (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct acpi_buffer*) ; 
 int /*<<< orphan*/  acpi_handle_debug (struct acpi_handle*,char*,...) ; 
 int /*<<< orphan*/  acpi_handle_err (struct acpi_handle*,char*,...) ; 
 int /*<<< orphan*/  acpi_smbus_cmi_algorithm ; 
 struct acpi_device_id* acpi_smbus_cmi_ids ; 
 int /*<<< orphan*/  acpi_walk_namespace (int /*<<< orphan*/ ,struct acpi_handle*,int,int /*<<< orphan*/  (*) (int /*<<< orphan*/ ,int,void*,void**),int /*<<< orphan*/ *,union acpi_object*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int i2c_add_adapter (TYPE_5__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_5__*) ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 union acpi_object* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
acpi_smbus_cmi_access(struct i2c_adapter *adap, u16 addr, unsigned short flags,
		   char read_write, u8 command, int size,
		   union i2c_smbus_data *data)
{
	int result = 0;
	struct acpi_smbus_cmi *smbus_cmi = adap->algo_data;
	unsigned char protocol;
	acpi_status status = 0;
	struct acpi_object_list input;
	union acpi_object mt_params[5];
	struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
	union acpi_object *obj;
	union acpi_object *pkg;
	char *method;
	int len = 0;

	dev_dbg(&adap->dev, "access size: %d %s\n", size,
		(read_write) ? "READ" : "WRITE");
	switch (size) {
	case I2C_SMBUS_QUICK:
		protocol = ACPI_SMBUS_PRTCL_QUICK;
		command = 0;
		if (read_write == I2C_SMBUS_WRITE) {
			mt_params[3].type = ACPI_TYPE_INTEGER;
			mt_params[3].integer.value = 0;
			mt_params[4].type = ACPI_TYPE_INTEGER;
			mt_params[4].integer.value = 0;
		}
		break;

	case I2C_SMBUS_BYTE:
		protocol = ACPI_SMBUS_PRTCL_BYTE;
		if (read_write == I2C_SMBUS_WRITE) {
			mt_params[3].type = ACPI_TYPE_INTEGER;
			mt_params[3].integer.value = 0;
			mt_params[4].type = ACPI_TYPE_INTEGER;
			mt_params[4].integer.value = 0;
		} else {
			command = 0;
		}
		break;

	case I2C_SMBUS_BYTE_DATA:
		protocol = ACPI_SMBUS_PRTCL_BYTE_DATA;
		if (read_write == I2C_SMBUS_WRITE) {
			mt_params[3].type = ACPI_TYPE_INTEGER;
			mt_params[3].integer.value = 1;
			mt_params[4].type = ACPI_TYPE_INTEGER;
			mt_params[4].integer.value = data->byte;
		}
		break;

	case I2C_SMBUS_WORD_DATA:
		protocol = ACPI_SMBUS_PRTCL_WORD_DATA;
		if (read_write == I2C_SMBUS_WRITE) {
			mt_params[3].type = ACPI_TYPE_INTEGER;
			mt_params[3].integer.value = 2;
			mt_params[4].type = ACPI_TYPE_INTEGER;
			mt_params[4].integer.value = data->word;
		}
		break;

	case I2C_SMBUS_BLOCK_DATA:
		protocol = ACPI_SMBUS_PRTCL_BLOCK_DATA;
		if (read_write == I2C_SMBUS_WRITE) {
			len = data->block[0];
			if (len == 0 || len > I2C_SMBUS_BLOCK_MAX)
				return -EINVAL;
			mt_params[3].type = ACPI_TYPE_INTEGER;
			mt_params[3].integer.value = len;
			mt_params[4].type = ACPI_TYPE_BUFFER;
			mt_params[4].buffer.length = len;
			mt_params[4].buffer.pointer = data->block + 1;
		}
		break;

	default:
		dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	if (read_write == I2C_SMBUS_READ) {
		protocol |= ACPI_SMBUS_PRTCL_READ;
		method = smbus_cmi->methods->mt_sbr;
		input.count = 3;
	} else {
		protocol |= ACPI_SMBUS_PRTCL_WRITE;
		method = smbus_cmi->methods->mt_sbw;
		input.count = 5;
	}

	input.pointer = mt_params;
	mt_params[0].type = ACPI_TYPE_INTEGER;
	mt_params[0].integer.value = protocol;
	mt_params[1].type = ACPI_TYPE_INTEGER;
	mt_params[1].integer.value = addr;
	mt_params[2].type = ACPI_TYPE_INTEGER;
	mt_params[2].integer.value = command;

	status = acpi_evaluate_object(smbus_cmi->handle, method, &input,
				      &buffer);
	if (ACPI_FAILURE(status)) {
		acpi_handle_err(smbus_cmi->handle,
				"Failed to evaluate %s: %i\n", method, status);
		return -EIO;
	}

	pkg = buffer.pointer;
	if (pkg && pkg->type == ACPI_TYPE_PACKAGE)
		obj = pkg->package.elements;
	else {
		acpi_handle_err(smbus_cmi->handle, "Invalid argument type\n");
		result = -EIO;
		goto out;
	}
	if (obj == NULL || obj->type != ACPI_TYPE_INTEGER) {
		acpi_handle_err(smbus_cmi->handle, "Invalid argument type\n");
		result = -EIO;
		goto out;
	}

	result = obj->integer.value;
	acpi_handle_debug(smbus_cmi->handle,  "%s return status: %i\n", method,
			  result);

	switch (result) {
	case ACPI_SMBUS_STATUS_OK:
		result = 0;
		break;
	case ACPI_SMBUS_STATUS_BUSY:
		result = -EBUSY;
		goto out;
	case ACPI_SMBUS_STATUS_TIMEOUT:
		result = -ETIMEDOUT;
		goto out;
	case ACPI_SMBUS_STATUS_DNAK:
		result = -ENXIO;
		goto out;
	default:
		result = -EIO;
		goto out;
	}

	if (read_write == I2C_SMBUS_WRITE || size == I2C_SMBUS_QUICK)
		goto out;

	obj = pkg->package.elements + 1;
	if (obj->type != ACPI_TYPE_INTEGER) {
		acpi_handle_err(smbus_cmi->handle, "Invalid argument type\n");
		result = -EIO;
		goto out;
	}

	len = obj->integer.value;
	obj = pkg->package.elements + 2;
	switch (size) {
	case I2C_SMBUS_BYTE:
	case I2C_SMBUS_BYTE_DATA:
	case I2C_SMBUS_WORD_DATA:
		if (obj->type != ACPI_TYPE_INTEGER) {
			acpi_handle_err(smbus_cmi->handle,
					"Invalid argument type\n");
			result = -EIO;
			goto out;
		}
		if (len == 2)
			data->word = obj->integer.value;
		else
			data->byte = obj->integer.value;
		break;
	case I2C_SMBUS_BLOCK_DATA:
		if (obj->type != ACPI_TYPE_BUFFER) {
			acpi_handle_err(smbus_cmi->handle,
					"Invalid argument type\n");
			result = -EIO;
			goto out;
		}
		if (len == 0 || len > I2C_SMBUS_BLOCK_MAX)
			return -EPROTO;
		data->block[0] = len;
		memcpy(data->block + 1, obj->buffer.pointer, len);
		break;
	}

out:
	kfree(buffer.pointer);
	dev_dbg(&adap->dev, "Transaction status: %i\n", result);
	return result;
}

__attribute__((used)) static u32 acpi_smbus_cmi_func(struct i2c_adapter *adapter)
{
	struct acpi_smbus_cmi *smbus_cmi = adapter->algo_data;
	u32 ret;

	ret = smbus_cmi->cap_read | smbus_cmi->cap_write ?
		I2C_FUNC_SMBUS_QUICK : 0;

	ret |= smbus_cmi->cap_read ?
		(I2C_FUNC_SMBUS_READ_BYTE |
		I2C_FUNC_SMBUS_READ_BYTE_DATA |
		I2C_FUNC_SMBUS_READ_WORD_DATA |
		I2C_FUNC_SMBUS_READ_BLOCK_DATA) : 0;

	ret |= smbus_cmi->cap_write ?
		(I2C_FUNC_SMBUS_WRITE_BYTE |
		I2C_FUNC_SMBUS_WRITE_BYTE_DATA |
		I2C_FUNC_SMBUS_WRITE_WORD_DATA |
		I2C_FUNC_SMBUS_WRITE_BLOCK_DATA) : 0;

	return ret;
}

__attribute__((used)) static int acpi_smbus_cmi_add_cap(struct acpi_smbus_cmi *smbus_cmi,
				  const char *name)
{
	struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
	struct acpi_handle *handle = smbus_cmi->handle;
	union acpi_object *obj;
	acpi_status status;

	if (!strcmp(name, smbus_cmi->methods->mt_info)) {
		status = acpi_evaluate_object(smbus_cmi->handle,
					smbus_cmi->methods->mt_info,
					NULL, &buffer);
		if (ACPI_FAILURE(status)) {
			acpi_handle_err(handle, "Failed to evaluate %s: %i\n",
					smbus_cmi->methods->mt_info, status);
			return -EIO;
		}

		obj = buffer.pointer;
		if (obj && obj->type == ACPI_TYPE_PACKAGE)
			obj = obj->package.elements;
		else {
			acpi_handle_err(handle, "Invalid argument type\n");
			kfree(buffer.pointer);
			return -EIO;
		}

		if (obj->type != ACPI_TYPE_INTEGER) {
			acpi_handle_err(handle, "Invalid argument type\n");
			kfree(buffer.pointer);
			return -EIO;
		} else
			acpi_handle_debug(handle, "SMBus CMI Version %x\n",
					  (int)obj->integer.value);

		kfree(buffer.pointer);
		smbus_cmi->cap_info = 1;
	} else if (!strcmp(name, smbus_cmi->methods->mt_sbr))
		smbus_cmi->cap_read = 1;
	else if (!strcmp(name, smbus_cmi->methods->mt_sbw))
		smbus_cmi->cap_write = 1;
	else
		acpi_handle_debug(handle, "Unsupported CMI method: %s\n", name);

	return 0;
}

__attribute__((used)) static acpi_status acpi_smbus_cmi_query_methods(acpi_handle handle, u32 level,
			void *context, void **return_value)
{
	char node_name[5];
	struct acpi_buffer buffer = { sizeof(node_name), node_name };
	struct acpi_smbus_cmi *smbus_cmi = context;
	acpi_status status;

	status = acpi_get_name(handle, ACPI_SINGLE_NAME, &buffer);

	if (ACPI_SUCCESS(status))
		acpi_smbus_cmi_add_cap(smbus_cmi, node_name);

	return AE_OK;
}

__attribute__((used)) static int acpi_smbus_cmi_add(struct acpi_device *device)
{
	struct acpi_smbus_cmi *smbus_cmi;
	const struct acpi_device_id *id;
	int ret;

	smbus_cmi = kzalloc(sizeof(struct acpi_smbus_cmi), GFP_KERNEL);
	if (!smbus_cmi)
		return -ENOMEM;

	smbus_cmi->handle = device->handle;
	strcpy(acpi_device_name(device), ACPI_SMBUS_HC_DEVICE_NAME);
	strcpy(acpi_device_class(device), ACPI_SMBUS_HC_CLASS);
	device->driver_data = smbus_cmi;
	smbus_cmi->cap_info = 0;
	smbus_cmi->cap_read = 0;
	smbus_cmi->cap_write = 0;

	for (id = acpi_smbus_cmi_ids; id->id[0]; id++)
		if (!strcmp(id->id, acpi_device_hid(device)))
			smbus_cmi->methods =
				(struct smbus_methods_t *) id->driver_data;

	acpi_walk_namespace(ACPI_TYPE_METHOD, smbus_cmi->handle, 1,
			    acpi_smbus_cmi_query_methods, NULL, smbus_cmi, NULL);

	if (smbus_cmi->cap_info == 0) {
		ret = -ENODEV;
		goto err;
	}

	snprintf(smbus_cmi->adapter.name, sizeof(smbus_cmi->adapter.name),
		"SMBus CMI adapter %s",
		acpi_device_name(device));
	smbus_cmi->adapter.owner = THIS_MODULE;
	smbus_cmi->adapter.algo = &acpi_smbus_cmi_algorithm;
	smbus_cmi->adapter.algo_data = smbus_cmi;
	smbus_cmi->adapter.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
	smbus_cmi->adapter.dev.parent = &device->dev;

	ret = i2c_add_adapter(&smbus_cmi->adapter);
	if (ret) {
		dev_err(&device->dev, "Couldn't register adapter!\n");
		goto err;
	}

	return 0;

err:
	kfree(smbus_cmi);
	device->driver_data = NULL;
	return ret;
}

__attribute__((used)) static int acpi_smbus_cmi_remove(struct acpi_device *device)
{
	struct acpi_smbus_cmi *smbus_cmi = acpi_driver_data(device);

	i2c_del_adapter(&smbus_cmi->adapter);
	kfree(smbus_cmi);
	device->driver_data = NULL;

	return 0;
}

