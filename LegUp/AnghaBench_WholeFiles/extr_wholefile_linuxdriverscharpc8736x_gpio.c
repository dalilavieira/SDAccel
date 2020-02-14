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
struct file {int /*<<< orphan*/ * private_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int PC8736X_GPIO_CT ; 
 int PORT_IN ; 
 int PORT_OUT ; 
 int SIO_BASE1 ; 
 int SIO_BASE2 ; 
 int SIO_GPIO_PIN_CONFIG ; 
 int SIO_GPIO_PIN_SELECT ; 
 unsigned int SIO_GPIO_UNIT ; 
 int SIO_SID ; 
 int SIO_SID_PC87365 ; 
 int SIO_SID_PC87366 ; 
 int SIO_UNIT_SEL ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,unsigned int,...) ; 
 unsigned int iminor (struct inode*) ; 
 int inb_p (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int nonseekable_open (struct inode*,struct file*) ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int pc8736x_gpio_base ; 
 int /*<<< orphan*/  pc8736x_gpio_config_lock ; 
 int /*<<< orphan*/  pc8736x_gpio_ops ; 
 int* pc8736x_gpio_shadow ; 
 TYPE_1__* pdev ; 
 int* port_offset ; 
 unsigned int selected_device ; 
 int superio_cmd ; 

__attribute__((used)) static inline void superio_outb(int addr, int val)
{
	outb_p(addr, superio_cmd);
	outb_p(val, superio_cmd + 1);
}

__attribute__((used)) static inline int superio_inb(int addr)
{
	outb_p(addr, superio_cmd);
	return inb_p(superio_cmd + 1);
}

__attribute__((used)) static int pc8736x_superio_present(void)
{
	int id;

	/* try the 2 possible values, read a hardware reg to verify */
	superio_cmd = SIO_BASE1;
	id = superio_inb(SIO_SID);
	if (id == SIO_SID_PC87365 || id == SIO_SID_PC87366)
		return superio_cmd;

	superio_cmd = SIO_BASE2;
	id = superio_inb(SIO_SID);
	if (id == SIO_SID_PC87365 || id == SIO_SID_PC87366)
		return superio_cmd;

	return 0;
}

__attribute__((used)) static void device_select(unsigned devldn)
{
	superio_outb(SIO_UNIT_SEL, devldn);
	selected_device = devldn;
}

__attribute__((used)) static void select_pin(unsigned iminor)
{
	/* select GPIO port/pin from device minor number */
	device_select(SIO_GPIO_UNIT);
	superio_outb(SIO_GPIO_PIN_SELECT,
		     ((iminor << 1) & 0xF0) | (iminor & 0x7));
}

__attribute__((used)) static inline u32 pc8736x_gpio_configure_fn(unsigned index, u32 mask, u32 bits,
					    u32 func_slct)
{
	u32 config, new_config;

	mutex_lock(&pc8736x_gpio_config_lock);

	device_select(SIO_GPIO_UNIT);
	select_pin(index);

	/* read current config value */
	config = superio_inb(func_slct);

	/* set new config */
	new_config = (config & mask) | bits;
	superio_outb(func_slct, new_config);

	mutex_unlock(&pc8736x_gpio_config_lock);

	return config;
}

__attribute__((used)) static u32 pc8736x_gpio_configure(unsigned index, u32 mask, u32 bits)
{
	return pc8736x_gpio_configure_fn(index, mask, bits,
					 SIO_GPIO_PIN_CONFIG);
}

__attribute__((used)) static int pc8736x_gpio_get(unsigned minor)
{
	int port, bit, val;

	port = minor >> 3;
	bit = minor & 7;
	val = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_IN);
	val >>= bit;
	val &= 1;

	dev_dbg(&pdev->dev, "_gpio_get(%d from %x bit %d) == val %d\n",
		minor, pc8736x_gpio_base + port_offset[port] + PORT_IN, bit,
		val);

	return val;
}

__attribute__((used)) static void pc8736x_gpio_set(unsigned minor, int val)
{
	int port, bit, curval;

	minor &= 0x1f;
	port = minor >> 3;
	bit = minor & 7;
	curval = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_OUT);

	dev_dbg(&pdev->dev, "addr:%x cur:%x bit-pos:%d cur-bit:%x + new:%d -> bit-new:%d\n",
		pc8736x_gpio_base + port_offset[port] + PORT_OUT,
		curval, bit, (curval & ~(1 << bit)), val, (val << bit));

	val = (curval & ~(1 << bit)) | (val << bit);

	dev_dbg(&pdev->dev, "gpio_set(minor:%d port:%d bit:%d)"
		" %2x -> %2x\n", minor, port, bit, curval, val);

	outb_p(val, pc8736x_gpio_base + port_offset[port] + PORT_OUT);

	curval = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_OUT);
	val = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_IN);

	dev_dbg(&pdev->dev, "wrote %x, read: %x\n", curval, val);
	pc8736x_gpio_shadow[port] = val;
}

__attribute__((used)) static int pc8736x_gpio_current(unsigned minor)
{
	int port, bit;
	minor &= 0x1f;
	port = minor >> 3;
	bit = minor & 7;
	return ((pc8736x_gpio_shadow[port] >> bit) & 0x01);
}

__attribute__((used)) static void pc8736x_gpio_change(unsigned index)
{
	pc8736x_gpio_set(index, !pc8736x_gpio_current(index));
}

__attribute__((used)) static int pc8736x_gpio_open(struct inode *inode, struct file *file)
{
	unsigned m = iminor(inode);
	file->private_data = &pc8736x_gpio_ops;

	dev_dbg(&pdev->dev, "open %d\n", m);

	if (m >= PC8736X_GPIO_CT)
		return -EINVAL;
	return nonseekable_open(inode, file);
}

