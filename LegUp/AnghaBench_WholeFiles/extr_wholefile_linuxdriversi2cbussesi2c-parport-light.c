#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct lineop {unsigned char port; unsigned char val; scalar_t__ inverted; } ;
struct TYPE_12__ {struct lineop init; scalar_t__ smbus_alert; struct lineop getsda; struct lineop getscl; struct lineop setsda; struct lineop setscl; } ;
struct TYPE_11__ {scalar_t__ irq; } ;
struct TYPE_9__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_10__ {TYPE_1__ dev; } ;

/* Variables and functions */
 TYPE_8__* adapter_parm ; 
 TYPE_4__ alert_data ; 
 int /*<<< orphan*/ * ara ; 
 scalar_t__ base ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int i2c_bit_add_bus (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/ * i2c_setup_smbus_alert (TYPE_2__*,TYPE_4__*) ; 
 int /*<<< orphan*/  i2c_unregister_device (int /*<<< orphan*/ *) ; 
 unsigned char inb (scalar_t__) ; 
 scalar_t__ irq ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb (unsigned char,scalar_t__) ; 
 TYPE_2__ parport_adapter ; 
 struct lineop parport_ctrl_irq ; 
 size_t type ; 

__attribute__((used)) static inline void port_write(unsigned char p, unsigned char d)
{
	outb(d, base+p);
}

__attribute__((used)) static inline unsigned char port_read(unsigned char p)
{
	return inb(base+p);
}

__attribute__((used)) static inline void line_set(int state, const struct lineop *op)
{
	u8 oldval = port_read(op->port);

	/* Touch only the bit(s) needed */
	if ((op->inverted && !state) || (!op->inverted && state))
		port_write(op->port, oldval | op->val);
	else
		port_write(op->port, oldval & ~op->val);
}

__attribute__((used)) static inline int line_get(const struct lineop *op)
{
	u8 oldval = port_read(op->port);

	return ((op->inverted && (oldval & op->val) != op->val)
	    || (!op->inverted && (oldval & op->val) == op->val));
}

__attribute__((used)) static void parport_setscl(void *data, int state)
{
	line_set(state, &adapter_parm[type].setscl);
}

__attribute__((used)) static void parport_setsda(void *data, int state)
{
	line_set(state, &adapter_parm[type].setsda);
}

__attribute__((used)) static int parport_getscl(void *data)
{
	return line_get(&adapter_parm[type].getscl);
}

__attribute__((used)) static int parport_getsda(void *data)
{
	return line_get(&adapter_parm[type].getsda);
}

__attribute__((used)) static int i2c_parport_probe(struct platform_device *pdev)
{
	int err;

	/* Reset hardware to a sane state (SCL and SDA high) */
	parport_setsda(NULL, 1);
	parport_setscl(NULL, 1);
	/* Other init if needed (power on...) */
	if (adapter_parm[type].init.val) {
		line_set(1, &adapter_parm[type].init);
		/* Give powered devices some time to settle */
		msleep(100);
	}

	parport_adapter.dev.parent = &pdev->dev;
	err = i2c_bit_add_bus(&parport_adapter);
	if (err) {
		dev_err(&pdev->dev, "Unable to register with I2C\n");
		return err;
	}

	/* Setup SMBus alert if supported */
	if (adapter_parm[type].smbus_alert && irq) {
		alert_data.irq = irq;
		ara = i2c_setup_smbus_alert(&parport_adapter, &alert_data);
		if (ara)
			line_set(1, &parport_ctrl_irq);
		else
			dev_warn(&pdev->dev, "Failed to register ARA client\n");
	}

	return 0;
}

__attribute__((used)) static int i2c_parport_remove(struct platform_device *pdev)
{
	if (ara) {
		line_set(0, &parport_ctrl_irq);
		i2c_unregister_device(ara);
		ara = NULL;
	}
	i2c_del_adapter(&parport_adapter);

	/* Un-init if needed (power off...) */
	if (adapter_parm[type].init.val)
		line_set(0, &adapter_parm[type].init);

	return 0;
}

