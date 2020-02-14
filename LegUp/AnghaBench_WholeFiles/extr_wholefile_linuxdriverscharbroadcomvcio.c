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
typedef  int u32 ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  size ;
struct TYPE_2__ {int /*<<< orphan*/  fw; } ;

/* Variables and functions */
 int EFAULT ; 
 long EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IOCTL_MBOX_PROPERTY 128 
 int RPI_FIRMWARE_STATUS_SUCCESS ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 scalar_t__ copy_from_user (int*,void*,int) ; 
 scalar_t__ copy_to_user (void*,int*,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int) ; 
 int rpi_firmware_property_list (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 
 TYPE_1__ vcio ; 

__attribute__((used)) static int vcio_user_property_list(void *user)
{
	u32 *buf, size;
	int ret;

	/* The first 32-bit is the size of the buffer */
	if (copy_from_user(&size, user, sizeof(size)))
		return -EFAULT;

	buf = kmalloc(size, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	if (copy_from_user(buf, user, size)) {
		kfree(buf);
		return -EFAULT;
	}

	/* Strip off protocol encapsulation */
	ret = rpi_firmware_property_list(vcio.fw, &buf[2], size - 12);
	if (ret) {
		kfree(buf);
		return ret;
	}

	buf[1] = RPI_FIRMWARE_STATUS_SUCCESS;
	if (copy_to_user(user, buf, size))
		ret = -EFAULT;

	kfree(buf);

	return ret;
}

__attribute__((used)) static int vcio_device_open(struct inode *inode, struct file *file)
{
	try_module_get(THIS_MODULE);

	return 0;
}

__attribute__((used)) static int vcio_device_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);

	return 0;
}

__attribute__((used)) static long vcio_device_ioctl(struct file *file, unsigned int ioctl_num,
			      unsigned long ioctl_param)
{
	switch (ioctl_num) {
	case IOCTL_MBOX_PROPERTY:
		return vcio_user_property_list((void *)ioctl_param);
	default:
		pr_err("unknown ioctl: %x\n", ioctl_num);
		return -EINVAL;
	}
}

