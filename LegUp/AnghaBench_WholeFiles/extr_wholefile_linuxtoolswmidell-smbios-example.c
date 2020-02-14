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
struct TYPE_2__ {int cmd_class; int cmd_select; int* input; int* output; } ;
struct dell_wmi_smbios_buffer {char length; TYPE_1__ std; } ;
typedef  char __u64 ;
typedef  int __u16 ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int CAPSULE_DIS_TOKEN ; 
 int CAPSULE_EN_TOKEN ; 
 int CLASS_FLASH_INTERFACE ; 
 int CLASS_TOKEN_READ ; 
 int CLASS_TOKEN_WRITE ; 
 int /*<<< orphan*/  DELL_WMI_SMBIOS_CMD ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  O_NONBLOCK ; 
 int SELECT_FLASH_INTERFACE ; 
 void* SELECT_TOKEN_STD ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fread (char*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (struct dell_wmi_smbios_buffer*) ; 
 int ioctl (int,int /*<<< orphan*/ ,struct dell_wmi_smbios_buffer*) ; 
 char* ioctl_devfs ; 
 struct dell_wmi_smbios_buffer* malloc (char) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int sprintf (char*,char*,char*,int) ; 
 scalar_t__ strtol (char*,int /*<<< orphan*/ *,int) ; 
 char* token_sysfs ; 

__attribute__((used)) static void show_buffer(struct dell_wmi_smbios_buffer *buffer)
{
	printf("Call: %x/%x [%x,%x,%x,%x]\nResults: [%8x,%8x,%8x,%8x]\n",
	buffer->std.cmd_class, buffer->std.cmd_select,
	buffer->std.input[0], buffer->std.input[1],
	buffer->std.input[2], buffer->std.input[3],
	buffer->std.output[0], buffer->std.output[1],
	buffer->std.output[2], buffer->std.output[3]);
}

__attribute__((used)) static int run_wmi_smbios_cmd(struct dell_wmi_smbios_buffer *buffer)
{
	int fd;
	int ret;

	fd = open(ioctl_devfs, O_NONBLOCK);
	ret = ioctl(fd, DELL_WMI_SMBIOS_CMD, buffer);
	close(fd);
	return ret;
}

__attribute__((used)) static int find_token(__u16 token, __u16 *location, __u16 *value)
{
	char location_sysfs[60];
	char value_sysfs[57];
	char buf[4096];
	FILE *f;
	int ret;

	ret = sprintf(value_sysfs, "%s/%04x_value", token_sysfs, token);
	if (ret < 0) {
		printf("sprintf value failed\n");
		return 2;
	}
	f = fopen(value_sysfs, "rb");
	if (!f) {
		printf("failed to open %s\n", value_sysfs);
		return 2;
	}
	fread(buf, 1, 4096, f);
	fclose(f);
	*value = (__u16) strtol(buf, NULL, 16);

	ret = sprintf(location_sysfs, "%s/%04x_location", token_sysfs, token);
	if (ret < 0) {
		printf("sprintf location failed\n");
		return 1;
	}
	f = fopen(location_sysfs, "rb");
	if (!f) {
		printf("failed to open %s\n", location_sysfs);
		return 2;
	}
	fread(buf, 1, 4096, f);
	fclose(f);
	*location = (__u16) strtol(buf, NULL, 16);

	if (*location)
		return 0;
	return 2;
}

__attribute__((used)) static int token_is_active(__u16 *location, __u16 *cmpvalue,
			   struct dell_wmi_smbios_buffer *buffer)
{
	int ret;

	buffer->std.cmd_class = CLASS_TOKEN_READ;
	buffer->std.cmd_select = SELECT_TOKEN_STD;
	buffer->std.input[0] = *location;
	ret = run_wmi_smbios_cmd(buffer);
	if (ret != 0 || buffer->std.output[0] != 0)
		return ret;
	ret = (buffer->std.output[1] == *cmpvalue);
	return ret;
}

__attribute__((used)) static int query_token(__u16 token, struct dell_wmi_smbios_buffer *buffer)
{
	__u16 location;
	__u16 value;
	int ret;

	ret = find_token(token, &location, &value);
	if (ret != 0) {
		printf("unable to find token %04x\n", token);
		return 1;
	}
	return token_is_active(&location, &value, buffer);
}

__attribute__((used)) static int activate_token(struct dell_wmi_smbios_buffer *buffer,
		   __u16 token)
{
	__u16 location;
	__u16 value;
	int ret;

	ret = find_token(token, &location, &value);
	if (ret != 0) {
		printf("unable to find token %04x\n", token);
		return 1;
	}
	buffer->std.cmd_class = CLASS_TOKEN_WRITE;
	buffer->std.cmd_select = SELECT_TOKEN_STD;
	buffer->std.input[0] = location;
	buffer->std.input[1] = 1;
	ret = run_wmi_smbios_cmd(buffer);
	return ret;
}

__attribute__((used)) static int query_buffer_size(__u64 *buffer_size)
{
	FILE *f;

	f = fopen(ioctl_devfs, "rb");
	if (!f)
		return -EINVAL;
	fread(buffer_size, sizeof(__u64), 1, f);
	fclose(f);
	return EXIT_SUCCESS;
}

int main(void)
{
	struct dell_wmi_smbios_buffer *buffer;
	int ret;
	__u64 value = 0;

	ret = query_buffer_size(&value);
	if (ret == EXIT_FAILURE || !value) {
		printf("Unable to read buffer size\n");
		goto out;
	}
	printf("Detected required buffer size %lld\n", value);

	buffer = malloc(value);
	if (buffer == NULL) {
		printf("failed to alloc memory for ioctl\n");
		ret = -ENOMEM;
		goto out;
	}
	buffer->length = value;

	/* simple SMBIOS call for looking up TPM info */
	buffer->std.cmd_class = CLASS_FLASH_INTERFACE;
	buffer->std.cmd_select = SELECT_FLASH_INTERFACE;
	buffer->std.input[0] = 2;
	ret = run_wmi_smbios_cmd(buffer);
	if (ret) {
		printf("smbios ioctl failed: %d\n", ret);
		ret = EXIT_FAILURE;
		goto out;
	}
	show_buffer(buffer);

	/* query some tokens */
	ret = query_token(CAPSULE_EN_TOKEN, buffer);
	printf("UEFI Capsule enabled token is: %d\n", ret);
	ret = query_token(CAPSULE_DIS_TOKEN, buffer);
	printf("UEFI Capsule disabled token is: %d\n", ret);

	/* activate UEFI capsule token if disabled */
	if (ret) {
		printf("Enabling UEFI capsule token");
		if (activate_token(buffer, CAPSULE_EN_TOKEN)) {
			printf("activate failed\n");
			ret = -1;
			goto out;
		}
	}
	ret = EXIT_SUCCESS;
out:
	free(buffer);
	return ret;
}

