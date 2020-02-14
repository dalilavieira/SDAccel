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
typedef  int u32 ;
struct i2c_adapter {int /*<<< orphan*/  name; } ;
struct mantis_pci {struct dvb_frontend* fe; struct mantis_hwconfig* hwconfig; struct i2c_adapter adapter; int /*<<< orphan*/  intmask_lock; } ;
struct mantis_hwconfig {int /*<<< orphan*/  reset; } ;
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int /*<<< orphan*/  POWER_ON ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 struct dvb_frontend* dvb_attach (int /*<<< orphan*/ ,struct dvb_frontend*,struct i2c_adapter*,...) ; 
 int /*<<< orphan*/  env57h12d5_config ; 
 int mantis_frontend_power (struct mantis_pci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mantis_gpio_set_bits (struct mantis_pci*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mantis_vp3030_config ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tda665x_attach ; 
 int /*<<< orphan*/  zl10353_attach ; 

__attribute__((used)) static inline void mantis_mask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) & ~mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static inline void mantis_unmask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) | mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static int vp3030_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
	struct i2c_adapter *adapter	= &mantis->adapter;
	struct mantis_hwconfig *config	= mantis->hwconfig;
	int err = 0;

	mantis_gpio_set_bits(mantis, config->reset, 0);
	msleep(100);
	err = mantis_frontend_power(mantis, POWER_ON);
	msleep(100);
	mantis_gpio_set_bits(mantis, config->reset, 1);

	if (err == 0) {
		msleep(250);
		dprintk(MANTIS_ERROR, 1, "Probing for 10353 (DVB-T)");
		fe = dvb_attach(zl10353_attach, &mantis_vp3030_config, adapter);

		if (!fe)
			return -1;

		dvb_attach(tda665x_attach, fe, &env57h12d5_config, adapter);
	} else {
		dprintk(MANTIS_ERROR, 1, "Frontend on <%s> POWER ON failed! <%d>",
			adapter->name,
			err);

		return -EIO;

	}
	mantis->fe = fe;
	dprintk(MANTIS_ERROR, 1, "Done!");

	return 0;
}

