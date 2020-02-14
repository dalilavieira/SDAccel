#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct i2c_adapter {int /*<<< orphan*/  name; } ;
struct mantis_pci {struct dvb_frontend* fe; struct i2c_adapter adapter; int /*<<< orphan*/  intmask_lock; } ;
struct i2c_msg {int addr; int* buf; int len; scalar_t__ flags; } ;
struct TYPE_8__ {int (* set_params ) (struct dvb_frontend*) ;} ;
struct TYPE_9__ {TYPE_2__ tuner_ops; int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dtv_frontend_properties {int frequency; } ;
struct dvb_frontend {TYPE_3__ ops; TYPE_1__* dvb; struct dtv_frontend_properties dtv_property_cache; } ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_10__ {int /*<<< orphan*/  demod_address; } ;
struct TYPE_7__ {struct mantis_pci* priv; } ;

/* Variables and functions */
 int EIO ; 
 scalar_t__ I2C_M_RD ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int /*<<< orphan*/  POWER_ON ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 struct dvb_frontend* dvb_attach (int /*<<< orphan*/ ,TYPE_4__*,struct i2c_adapter*,int) ; 
 int i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 int mantis_frontend_power (struct mantis_pci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mantis_frontend_soft_reset (struct mantis_pci*) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  stub2 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  stub3 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  tda10021_attach ; 
 int /*<<< orphan*/  tda10023_attach ; 
 TYPE_4__ vp2033_tda10023_cu1216_config ; 
 TYPE_4__ vp2033_tda1002x_cu1216_config ; 

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

__attribute__((used)) static u8 read_pwm(struct mantis_pci *mantis)
{
	struct i2c_adapter *adapter = &mantis->adapter;

	u8 b = 0xff;
	u8 pwm;
	struct i2c_msg msg[] = {
		{.addr = 0x50, .flags = 0, .buf = &b, .len = 1},
		{.addr = 0x50, .flags = I2C_M_RD, .buf = &pwm, .len = 1}
	};

	if ((i2c_transfer(adapter, msg, 2) != 2)
	    || (pwm == 0xff))
		pwm = 0x48;

	return pwm;
}

__attribute__((used)) static int tda1002x_cu1216_tuner_set(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *p = &fe->dtv_property_cache;
	struct mantis_pci *mantis = fe->dvb->priv;
	struct i2c_adapter *adapter = &mantis->adapter;

	u8 buf[6];
	struct i2c_msg msg = {.addr = 0x60, .flags = 0, .buf = buf, .len = sizeof(buf)};
	int i;

#define CU1216_IF 36125000
#define TUNER_MUL 62500

	u32 div = (p->frequency + CU1216_IF + TUNER_MUL / 2) / TUNER_MUL;

	buf[0] = (div >> 8) & 0x7f;
	buf[1] = div & 0xff;
	buf[2] = 0xce;
	buf[3] = (p->frequency < 150000000 ? 0x01 :
		  p->frequency < 445000000 ? 0x02 : 0x04);
	buf[4] = 0xde;
	buf[5] = 0x20;

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);

	if (i2c_transfer(adapter, &msg, 1) != 1)
		return -EIO;

	/* wait for the pll lock */
	msg.flags = I2C_M_RD;
	msg.len = 1;
	for (i = 0; i < 20; i++) {
		if (fe->ops.i2c_gate_ctrl)
			fe->ops.i2c_gate_ctrl(fe, 1);

		if (i2c_transfer(adapter, &msg, 1) == 1 && (buf[0] & 0x40))
			break;

		msleep(10);
	}

	/* switch the charge pump to the lower current */
	msg.flags = 0;
	msg.len = 2;
	msg.buf = &buf[2];
	buf[2] &= ~0x40;
	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);

	if (i2c_transfer(adapter, &msg, 1) != 1)
		return -EIO;

	return 0;
}

__attribute__((used)) static int vp2033_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
	struct i2c_adapter *adapter = &mantis->adapter;

	int err = 0;

	err = mantis_frontend_power(mantis, POWER_ON);
	if (err == 0) {
		mantis_frontend_soft_reset(mantis);
		msleep(250);

		dprintk(MANTIS_ERROR, 1, "Probing for CU1216 (DVB-C)");
		fe = dvb_attach(tda10021_attach, &vp2033_tda1002x_cu1216_config,
				     adapter,
				     read_pwm(mantis));

		if (fe) {
			dprintk(MANTIS_ERROR, 1,
				"found Philips CU1216 DVB-C frontend (TDA10021) @ 0x%02x",
				vp2033_tda1002x_cu1216_config.demod_address);
		} else {
			fe = dvb_attach(tda10023_attach, &vp2033_tda10023_cu1216_config,
					     adapter,
					     read_pwm(mantis));

			if (fe) {
				dprintk(MANTIS_ERROR, 1,
					"found Philips CU1216 DVB-C frontend (TDA10023) @ 0x%02x",
					vp2033_tda1002x_cu1216_config.demod_address);
			}
		}

		if (fe) {
			fe->ops.tuner_ops.set_params = tda1002x_cu1216_tuner_set;
			dprintk(MANTIS_ERROR, 1, "Mantis DVB-C Philips CU1216 frontend attach success");
		} else {
			return -1;
		}
	} else {
		dprintk(MANTIS_ERROR, 1, "Frontend on <%s> POWER ON failed! <%d>",
			adapter->name,
			err);

		return -EIO;
	}

	mantis->fe = fe;
	dprintk(MANTIS_DEBUG, 1, "Done!");

	return 0;
}

