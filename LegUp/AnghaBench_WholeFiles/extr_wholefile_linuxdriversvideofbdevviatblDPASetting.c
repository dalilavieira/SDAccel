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
struct via_aux_drv {TYPE_1__* bus; int /*<<< orphan*/  addr; int /*<<< orphan*/  chain; } ;
struct i2c_msg {int len; int* buf; int /*<<< orphan*/  flags; int /*<<< orphan*/  addr; } ;
struct TYPE_2__ {int /*<<< orphan*/  adap; int /*<<< orphan*/  drivers; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 struct via_aux_drv* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool via_aux_add(struct via_aux_drv *drv)
{
	struct via_aux_drv *data = kmalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return false;

	*data = *drv;
	list_add_tail(&data->chain, &data->bus->drivers);
	return true;
}

__attribute__((used)) static inline bool via_aux_read(struct via_aux_drv *drv, u8 start, u8 *buf,
	u8 len)
{
	struct i2c_msg msg[2] = {
		{.addr = drv->addr, .flags = 0, .len = 1, .buf = &start},
		{.addr = drv->addr, .flags = I2C_M_RD, .len = len, .buf = buf} };

	return i2c_transfer(drv->bus->adap, msg, 2) == 2;
}

