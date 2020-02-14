#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_8__ ;
typedef  struct TYPE_17__   TYPE_7__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct saa7146_pci_extension_data {int dummy; } ;
struct TYPE_16__ {int dma_handle; } ;
struct saa7146_dev {struct budget_patch* ext_priv; TYPE_6__ d_rps1; TYPE_5__* pci; } ;
struct i2c_msg {int addr; int* buf; int len; int /*<<< orphan*/  flags; } ;
struct TYPE_12__ {int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dtv_frontend_properties {int frequency; } ;
struct dvb_frontend {TYPE_2__ ops; TYPE_1__* dvb; struct dtv_frontend_properties dtv_property_cache; } ;
struct dvb_diseqc_master_cmd {int msg_len; int* msg; } ;
struct TYPE_18__ {struct budget_patch* priv; } ;
struct budget_patch {int buffer_height; TYPE_7__* dvb_frontend; TYPE_8__ dvb_adapter; struct saa7146_dev* dev; int /*<<< orphan*/  i2c_adap; } ;
struct budget {int buffer_height; TYPE_7__* dvb_frontend; TYPE_8__ dvb_adapter; struct saa7146_dev* dev; int /*<<< orphan*/  i2c_adap; } ;
struct av7110 {int /*<<< orphan*/  debilock; int /*<<< orphan*/  debi_virt; } ;
typedef  enum fe_sec_tone_mode { ____Placeholder_fe_sec_tone_mode } fe_sec_tone_mode ;
typedef  enum fe_sec_mini_cmd { ____Placeholder_fe_sec_mini_cmd } fe_sec_mini_cmd ;
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_13__ {int (* set_params ) (struct dvb_frontend*) ;} ;
struct TYPE_14__ {int (* diseqc_send_master_cmd ) (struct dvb_frontend*,struct dvb_diseqc_master_cmd*) ;int (* diseqc_send_burst ) (struct dvb_frontend*,int) ;int (* set_tone ) (struct dvb_frontend*,int) ;TYPE_3__ tuner_ops; } ;
struct TYPE_17__ {TYPE_4__ ops; int /*<<< orphan*/ * tuner_priv; } ;
struct TYPE_15__ {int subsystem_device; int /*<<< orphan*/  subsystem_vendor; int /*<<< orphan*/  device; int /*<<< orphan*/  vendor; } ;
struct TYPE_11__ {scalar_t__ priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  AV7110_FW_AUDIO_COMMAND ; 
 int /*<<< orphan*/  AV7110_FW_VIDEO_COMMAND ; 
 int /*<<< orphan*/  AudioDAC ; 
 int CMD_JUMP ; 
 int CMD_PAUSE ; 
 int CMD_STOP ; 
 int CMD_WR_REG_MASK ; 
 scalar_t__ COMMAND ; 
 int COMTYPE_AUDIODAC ; 
 int /*<<< orphan*/  COMTYPE_ENCODER ; 
 int /*<<< orphan*/  COMTYPE_MISC ; 
 int DEBINOSWAP ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EVT_HS ; 
 int EVT_VBI_B ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO3_MSK ; 
 int GPIO_CTRL ; 
 int IRQ_RX ; 
 int MASK_12 ; 
 int MASK_13 ; 
 int MASK_28 ; 
 int MASK_29 ; 
 int /*<<< orphan*/  MC1 ; 
 int OFF22K ; 
 int ON22K ; 
 int /*<<< orphan*/  RPS_ADDR1 ; 
 int RPS_INV ; 
 int /*<<< orphan*/  RPS_THRESH1 ; 
 int /*<<< orphan*/  RPS_TOV1 ; 
 int SAA7146_GPIO_OUTHI ; 
 int SAA7146_GPIO_OUTLO ; 
#define  SEC_TONE_OFF 129 
#define  SEC_TONE_ON 128 
 int SendDiSEqC ; 
 int /*<<< orphan*/  SetVidMode ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  WRITE_RPS1 (int) ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  alps_bsru6_config ; 
 int alps_bsru6_tuner_set_params (struct dvb_frontend*) ; 
 int /*<<< orphan*/  alps_bsrv2_config ; 
 int av7110_debiread (struct av7110*,int,int,int) ; 
 int /*<<< orphan*/  av7110_debiwrite (struct av7110*,int,int,int,int) ; 
 int av7110_fw_cmd (struct av7110*,int,int,int,...) ; 
 int /*<<< orphan*/  dprintk (int,char*,struct budget_patch*) ; 
 void* dvb_attach (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dvb_frontend_detach (TYPE_7__*) ; 
 scalar_t__ dvb_register_frontend (TYPE_8__*,TYPE_7__*) ; 
 int /*<<< orphan*/  dvb_unregister_frontend (TYPE_7__*) ; 
 int /*<<< orphan*/  grundig_29504_451_config ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  kfree (struct budget_patch*) ; 
 struct budget_patch* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int saa7146_read (struct saa7146_dev*,int) ; 
 int /*<<< orphan*/  saa7146_setgpio (struct saa7146_dev*,int,int) ; 
 int /*<<< orphan*/  saa7146_write (struct saa7146_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  stub2 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  stv0299_attach ; 
 int /*<<< orphan*/  tda8083_attach ; 
 int /*<<< orphan*/  ttpci_budget_debiwrite (struct budget_patch*,int,scalar_t__,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ttpci_budget_deinit (struct budget_patch*) ; 
 int ttpci_budget_init (struct budget_patch*,struct saa7146_dev*,struct saa7146_pci_extension_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ttpci_budget_init_hooks (struct budget_patch*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  ves1x93_attach ; 

__attribute__((used)) static inline void iwdebi(struct av7110 *av7110, u32 config, int addr, u32 val, unsigned int count)
{
	av7110_debiwrite(av7110, config, addr, val, count);
}

__attribute__((used)) static inline void mwdebi(struct av7110 *av7110, u32 config, int addr,
			  const u8 *val, int count)
{
	memcpy(av7110->debi_virt, val, count);
	av7110_debiwrite(av7110, config, addr, 0, count);
}

__attribute__((used)) static inline u32 irdebi(struct av7110 *av7110, u32 config, int addr, u32 val, unsigned int count)
{
	u32 res;

	res=av7110_debiread(av7110, config, addr, count);
	if (count<=4)
		memcpy(av7110->debi_virt, (char *) &res, count);
	return res;
}

__attribute__((used)) static inline void wdebi(struct av7110 *av7110, u32 config, int addr, u32 val, unsigned int count)
{
	unsigned long flags;

	spin_lock_irqsave(&av7110->debilock, flags);
	av7110_debiwrite(av7110, config, addr, val, count);
	spin_unlock_irqrestore(&av7110->debilock, flags);
}

__attribute__((used)) static inline u32 rdebi(struct av7110 *av7110, u32 config, int addr, u32 val, unsigned int count)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&av7110->debilock, flags);
	res=av7110_debiread(av7110, config, addr, count);
	spin_unlock_irqrestore(&av7110->debilock, flags);
	return res;
}

__attribute__((used)) static inline void ARM_ResetMailBox(struct av7110 *av7110)
{
	unsigned long flags;

	spin_lock_irqsave(&av7110->debilock, flags);
	av7110_debiread(av7110, DEBINOSWAP, IRQ_RX, 2);
	av7110_debiwrite(av7110, DEBINOSWAP, IRQ_RX, 0, 2);
	spin_unlock_irqrestore(&av7110->debilock, flags);
}

__attribute__((used)) static inline void ARM_ClearMailBox(struct av7110 *av7110)
{
	iwdebi(av7110, DEBINOSWAP, IRQ_RX, 0, 2);
}

__attribute__((used)) static inline void ARM_ClearIrq(struct av7110 *av7110)
{
	irdebi(av7110, DEBINOSWAP, IRQ_RX, 0, 2);
}

__attribute__((used)) static inline int SendDAC(struct av7110 *av7110, u8 addr, u8 data)
{
	return av7110_fw_cmd(av7110, COMTYPE_AUDIODAC, AudioDAC, 2, addr, data);
}

__attribute__((used)) static inline int av7710_set_video_mode(struct av7110 *av7110, int mode)
{
	return av7110_fw_cmd(av7110, COMTYPE_ENCODER, SetVidMode, 1, mode);
}

__attribute__((used)) static inline int vidcom(struct av7110 *av7110, u32 com, u32 arg)
{
	return av7110_fw_cmd(av7110, COMTYPE_MISC, AV7110_FW_VIDEO_COMMAND, 4,
			     (com>>16), (com&0xffff),
			     (arg>>16), (arg&0xffff));
}

__attribute__((used)) static inline int audcom(struct av7110 *av7110, u32 com)
{
	return av7110_fw_cmd(av7110, COMTYPE_MISC, AV7110_FW_AUDIO_COMMAND, 2,
			     (com>>16), (com&0xffff));
}

__attribute__((used)) static inline int Set22K(struct av7110 *av7110, int state)
{
	return av7110_fw_cmd(av7110, COMTYPE_AUDIODAC, (state ? ON22K : OFF22K), 0);
}

__attribute__((used)) static void gpio_Set22K (struct budget *budget, int state)
{
	struct saa7146_dev *dev=budget->dev;
	dprintk(2, "budget: %p\n", budget);
	saa7146_setgpio(dev, 3, (state ? SAA7146_GPIO_OUTHI : SAA7146_GPIO_OUTLO));
}

__attribute__((used)) static void DiseqcSendBit (struct budget *budget, int data)
{
	struct saa7146_dev *dev=budget->dev;
	dprintk(2, "budget: %p\n", budget);

	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
	udelay(data ? 500 : 1000);
	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
	udelay(data ? 1000 : 500);
}

__attribute__((used)) static void DiseqcSendByte (struct budget *budget, int data)
{
	int i, par=1, d;

	dprintk(2, "budget: %p\n", budget);

	for (i=7; i>=0; i--) {
		d = (data>>i)&1;
		par ^= d;
		DiseqcSendBit(budget, d);
	}

	DiseqcSendBit(budget, par);
}

__attribute__((used)) static int SendDiSEqCMsg (struct budget *budget, int len, u8 *msg, unsigned long burst)
{
	struct saa7146_dev *dev=budget->dev;
	int i;

	dprintk(2, "budget: %p\n", budget);

	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
	mdelay(16);

	for (i=0; i<len; i++)
		DiseqcSendByte(budget, msg[i]);

	mdelay(16);

	if (burst!=-1) {
		if (burst)
			DiseqcSendByte(budget, 0xff);
		else {
			saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
			mdelay(12);
			udelay(500);
			saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
		}
		msleep(20);
	}

	return 0;
}

__attribute__((used)) static int budget_set_tone(struct dvb_frontend *fe,
			   enum fe_sec_tone_mode tone)
{
	struct budget* budget = (struct budget*) fe->dvb->priv;

	switch (tone) {
	case SEC_TONE_ON:
		gpio_Set22K (budget, 1);
		break;

	case SEC_TONE_OFF:
		gpio_Set22K (budget, 0);
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int budget_diseqc_send_master_cmd(struct dvb_frontend* fe, struct dvb_diseqc_master_cmd* cmd)
{
	struct budget* budget = (struct budget*) fe->dvb->priv;

	SendDiSEqCMsg (budget, cmd->msg_len, cmd->msg, 0);

	return 0;
}

__attribute__((used)) static int budget_diseqc_send_burst(struct dvb_frontend *fe,
				    enum fe_sec_mini_cmd minicmd)
{
	struct budget* budget = (struct budget*) fe->dvb->priv;

	SendDiSEqCMsg (budget, 0, NULL, minicmd);

	return 0;
}

__attribute__((used)) static int budget_av7110_send_fw_cmd(struct budget_patch *budget, u16* buf, int length)
{
	int i;

	dprintk(2, "budget: %p\n", budget);

	for (i = 2; i < length; i++)
	{
		  ttpci_budget_debiwrite(budget, DEBINOSWAP, COMMAND + 2*i, 2, (u32) buf[i], 0,0);
		  msleep(5);
	}
	if (length)
		  ttpci_budget_debiwrite(budget, DEBINOSWAP, COMMAND + 2, 2, (u32) buf[1], 0,0);
	else
		  ttpci_budget_debiwrite(budget, DEBINOSWAP, COMMAND + 2, 2, 0, 0,0);
	msleep(5);
	ttpci_budget_debiwrite(budget, DEBINOSWAP, COMMAND, 2, (u32) buf[0], 0,0);
	msleep(5);
	return 0;
}

__attribute__((used)) static void av7110_set22k(struct budget_patch *budget, int state)
{
	u16 buf[2] = {( COMTYPE_AUDIODAC << 8) | (state ? ON22K : OFF22K), 0};

	dprintk(2, "budget: %p\n", budget);
	budget_av7110_send_fw_cmd(budget, buf, 2);
}

__attribute__((used)) static int av7110_send_diseqc_msg(struct budget_patch *budget, int len, u8 *msg, int burst)
{
	int i;
	u16 buf[18] = { ((COMTYPE_AUDIODAC << 8) | SendDiSEqC),
		16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	dprintk(2, "budget: %p\n", budget);

	if (len>10)
		len=10;

	buf[1] = len+2;
	buf[2] = len;

	if (burst != -1)
		buf[3]=burst ? 0x01 : 0x00;
	else
		buf[3]=0xffff;

	for (i=0; i<len; i++)
		buf[i+4]=msg[i];

	budget_av7110_send_fw_cmd(budget, buf, 18);
	return 0;
}

__attribute__((used)) static int budget_patch_set_tone(struct dvb_frontend *fe,
				 enum fe_sec_tone_mode tone)
{
	struct budget_patch* budget = (struct budget_patch*) fe->dvb->priv;

	switch (tone) {
	case SEC_TONE_ON:
		av7110_set22k (budget, 1);
		break;

	case SEC_TONE_OFF:
		av7110_set22k (budget, 0);
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int budget_patch_diseqc_send_master_cmd(struct dvb_frontend* fe, struct dvb_diseqc_master_cmd* cmd)
{
	struct budget_patch* budget = (struct budget_patch*) fe->dvb->priv;

	av7110_send_diseqc_msg (budget, cmd->msg_len, cmd->msg, 0);

	return 0;
}

__attribute__((used)) static int budget_patch_diseqc_send_burst(struct dvb_frontend *fe,
					  enum fe_sec_mini_cmd minicmd)
{
	struct budget_patch* budget = (struct budget_patch*) fe->dvb->priv;

	av7110_send_diseqc_msg (budget, 0, NULL, minicmd);

	return 0;
}

__attribute__((used)) static int alps_bsrv2_tuner_set_params(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *p = &fe->dtv_property_cache;
	struct budget_patch* budget = (struct budget_patch*) fe->dvb->priv;
	u8 pwr = 0;
	u8 buf[4];
	struct i2c_msg msg = { .addr = 0x61, .flags = 0, .buf = buf, .len = sizeof(buf) };
	u32 div = (p->frequency + 479500) / 125;

	if (p->frequency > 2000000)
		pwr = 3;
	else if (p->frequency > 1800000)
		pwr = 2;
	else if (p->frequency > 1600000)
		pwr = 1;
	else if (p->frequency > 1200000)
		pwr = 0;
	else if (p->frequency >= 1100000)
		pwr = 1;
	else pwr = 2;

	buf[0] = (div >> 8) & 0x7f;
	buf[1] = div & 0xff;
	buf[2] = ((div & 0x18000) >> 10) | 0x95;
	buf[3] = (pwr << 6) | 0x30;

	// NOTE: since we're using a prescaler of 2, we set the
	// divisor frequency to 62.5kHz and divide by 125 above

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);
	if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1)
		return -EIO;
	return 0;
}

__attribute__((used)) static int grundig_29504_451_tuner_set_params(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *p = &fe->dtv_property_cache;
	struct budget_patch* budget = (struct budget_patch*) fe->dvb->priv;
	u32 div;
	u8 data[4];
	struct i2c_msg msg = { .addr = 0x61, .flags = 0, .buf = data, .len = sizeof(data) };

	div = p->frequency / 125;
	data[0] = (div >> 8) & 0x7f;
	data[1] = div & 0xff;
	data[2] = 0x8e;
	data[3] = 0x00;

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);
	if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1)
		return -EIO;
	return 0;
}

__attribute__((used)) static void frontend_init(struct budget_patch* budget)
{
	switch(budget->dev->pci->subsystem_device) {
	case 0x0000: // Hauppauge/TT WinTV DVB-S rev1.X
	case 0x1013: // SATELCO Multimedia PCI

		// try the ALPS BSRV2 first of all
		budget->dvb_frontend = dvb_attach(ves1x93_attach, &alps_bsrv2_config, &budget->i2c_adap);
		if (budget->dvb_frontend) {
			budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsrv2_tuner_set_params;
			budget->dvb_frontend->ops.diseqc_send_master_cmd = budget_patch_diseqc_send_master_cmd;
			budget->dvb_frontend->ops.diseqc_send_burst = budget_patch_diseqc_send_burst;
			budget->dvb_frontend->ops.set_tone = budget_patch_set_tone;
			break;
		}

		// try the ALPS BSRU6 now
		budget->dvb_frontend = dvb_attach(stv0299_attach, &alps_bsru6_config, &budget->i2c_adap);
		if (budget->dvb_frontend) {
			budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsru6_tuner_set_params;
			budget->dvb_frontend->tuner_priv = &budget->i2c_adap;

			budget->dvb_frontend->ops.diseqc_send_master_cmd = budget_diseqc_send_master_cmd;
			budget->dvb_frontend->ops.diseqc_send_burst = budget_diseqc_send_burst;
			budget->dvb_frontend->ops.set_tone = budget_set_tone;
			break;
		}

		// Try the grundig 29504-451
		budget->dvb_frontend = dvb_attach(tda8083_attach, &grundig_29504_451_config, &budget->i2c_adap);
		if (budget->dvb_frontend) {
			budget->dvb_frontend->ops.tuner_ops.set_params = grundig_29504_451_tuner_set_params;
			budget->dvb_frontend->ops.diseqc_send_master_cmd = budget_diseqc_send_master_cmd;
			budget->dvb_frontend->ops.diseqc_send_burst = budget_diseqc_send_burst;
			budget->dvb_frontend->ops.set_tone = budget_set_tone;
			break;
		}
		break;
	}

	if (budget->dvb_frontend == NULL) {
		printk("dvb-ttpci: A frontend driver was not found for device [%04x:%04x] subsystem [%04x:%04x]\n",
		       budget->dev->pci->vendor,
		       budget->dev->pci->device,
		       budget->dev->pci->subsystem_vendor,
		       budget->dev->pci->subsystem_device);
	} else {
		if (dvb_register_frontend(&budget->dvb_adapter, budget->dvb_frontend)) {
			printk("budget-av: Frontend registration failed!\n");
			dvb_frontend_detach(budget->dvb_frontend);
			budget->dvb_frontend = NULL;
		}
	}
}

__attribute__((used)) static int budget_patch_attach (struct saa7146_dev* dev, struct saa7146_pci_extension_data *info)
{
	struct budget_patch *budget;
	int err;
	int count = 0;
	int detected = 0;

#define PATCH_RESET 0
#define RPS_IRQ 0
#define HPS_SETUP 0
#if PATCH_RESET
	saa7146_write(dev, MC1, MASK_31);
	msleep(40);
#endif
#if HPS_SETUP
	// initialize registers. Better to have it like this
	// than leaving something unconfigured
	saa7146_write(dev, DD1_STREAM_B, 0);
	// port B VSYNC at rising edge
	saa7146_write(dev, DD1_INIT, 0x00000200);  // have this in budget-core too!
	saa7146_write(dev, BRS_CTRL, 0x00000000);  // VBI

	// debi config
	// saa7146_write(dev, DEBI_CONFIG, MASK_30|MASK_28|MASK_18);

	// zero all HPS registers
	saa7146_write(dev, HPS_H_PRESCALE, 0);                  // r68
	saa7146_write(dev, HPS_H_SCALE, 0);                     // r6c
	saa7146_write(dev, BCS_CTRL, 0);                        // r70
	saa7146_write(dev, HPS_V_SCALE, 0);                     // r60
	saa7146_write(dev, HPS_V_GAIN, 0);                      // r64
	saa7146_write(dev, CHROMA_KEY_RANGE, 0);                // r74
	saa7146_write(dev, CLIP_FORMAT_CTRL, 0);                // r78
	// Set HPS prescaler for port B input
	saa7146_write(dev, HPS_CTRL, (1<<30) | (0<<29) | (1<<28) | (0<<12) );
	saa7146_write(dev, MC2,
	  0 * (MASK_08 | MASK_24)  |   // BRS control
	  0 * (MASK_09 | MASK_25)  |   // a
	  0 * (MASK_10 | MASK_26)  |   // b
	  1 * (MASK_06 | MASK_22)  |   // HPS_CTRL1
	  1 * (MASK_05 | MASK_21)  |   // HPS_CTRL2
	  0 * (MASK_01 | MASK_15)      // DEBI
	   );
#endif
	// Disable RPS1 and RPS0
	saa7146_write(dev, MC1, ( MASK_29 | MASK_28));
	// RPS1 timeout disable
	saa7146_write(dev, RPS_TOV1, 0);

	// code for autodetection
	// will wait for VBI_B event (vertical blank at port B)
	// and will reset GPIO3 after VBI_B is detected.
	// (GPIO3 should be raised high by CPU to
	// test if GPIO3 will generate vertical blank signal
	// in budget patch GPIO3 is connected to VSYNC_B
	count = 0;
#if 0
	WRITE_RPS1(CMD_UPLOAD |
	  MASK_10 | MASK_09 | MASK_08 | MASK_06 | MASK_05 | MASK_04 | MASK_03 | MASK_02 );
#endif
	WRITE_RPS1(CMD_PAUSE | EVT_VBI_B);
	WRITE_RPS1(CMD_WR_REG_MASK | (GPIO_CTRL>>2));
	WRITE_RPS1(GPIO3_MSK);
	WRITE_RPS1(SAA7146_GPIO_OUTLO<<24);
#if RPS_IRQ
	// issue RPS1 interrupt to increment counter
	WRITE_RPS1(CMD_INTERRUPT);
	// at least a NOP is neede between two interrupts
	WRITE_RPS1(CMD_NOP);
	// interrupt again
	WRITE_RPS1(CMD_INTERRUPT);
#endif
	WRITE_RPS1(CMD_STOP);

#if RPS_IRQ
	// set event counter 1 source as RPS1 interrupt (0x03)          (rE4 p53)
	// use 0x03 to track RPS1 interrupts - increase by 1 every gpio3 is toggled
	// use 0x15 to track VPE  interrupts - increase by 1 every vpeirq() is called
	saa7146_write(dev, EC1SSR, (0x03<<2) | 3 );
	// set event counter 1 threshold to maximum allowed value        (rEC p55)
	saa7146_write(dev, ECT1R,  0x3fff );
#endif
	// Fix VSYNC level
	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
	// Set RPS1 Address register to point to RPS code               (r108 p42)
	saa7146_write(dev, RPS_ADDR1, dev->d_rps1.dma_handle);
	// Enable RPS1,                                                 (rFC p33)
	saa7146_write(dev, MC1, (MASK_13 | MASK_29 ));


	mdelay(50);
	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
	mdelay(150);


	if( (saa7146_read(dev, GPIO_CTRL) & 0x10000000) == 0)
		detected = 1;

#if RPS_IRQ
	printk("Event Counter 1 0x%04x\n", saa7146_read(dev, EC1R) & 0x3fff );
#endif
	// Disable RPS1
	saa7146_write(dev, MC1, ( MASK_29 ));

	if(detected == 0)
		printk("budget-patch not detected or saa7146 in non-default state.\n"
		       "try enabling resetting of 7146 with MASK_31 in MC1 register\n");

	else
		printk("BUDGET-PATCH DETECTED.\n");


/*      OLD (Original design by Roberto Deza):
**      This code will setup the SAA7146_RPS1 to generate a square
**      wave on GPIO3, changing when a field (TS_HEIGHT/2 "lines" of
**      TS_WIDTH packets) has been acquired on SAA7146_D1B video port;
**      then, this GPIO3 output which is connected to the D1B_VSYNC
**      input, will trigger the acquisition of the alternate field
**      and so on.
**      Currently, the TT_budget / WinTV_Nova cards have two ICs
**      (74HCT4040, LVC74) for the generation of this VSYNC signal,
**      which seems that can be done perfectly without this :-)).
*/

/*      New design (By Emard)
**      this rps1 code will copy internal HS event to GPIO3 pin.
**      GPIO3 is in budget-patch hardware connected to port B VSYNC

**      HS is an internal event of 7146, accessible with RPS
**      and temporarily raised high every n lines
**      (n in defined in the RPS_THRESH1 counter threshold)
**      I think HS is raised high on the beginning of the n-th line
**      and remains high until this n-th line that triggered
**      it is completely received. When the reception of n-th line
**      ends, HS is lowered.

**      To transmit data over DMA, 7146 needs changing state at
**      port B VSYNC pin. Any changing of port B VSYNC will
**      cause some DMA data transfer, with more or less packets loss.
**      It depends on the phase and frequency of VSYNC and
**      the way of 7146 is instructed to trigger on port B (defined
**      in DD1_INIT register, 3rd nibble from the right valid
**      numbers are 0-7, see datasheet)
**
**      The correct triggering can minimize packet loss,
**      dvbtraffic should give this stable bandwidths:
**        22k transponder = 33814 kbit/s
**      27.5k transponder = 38045 kbit/s
**      by experiment it is found that the best results
**      (stable bandwidths and almost no packet loss)
**      are obtained using DD1_INIT triggering number 2
**      (Va at rising edge of VS Fa = HS x VS-failing forced toggle)
**      and a VSYNC phase that occurs in the middle of DMA transfer
**      (about byte 188*512=96256 in the DMA window).
**
**      Phase of HS is still not clear to me how to control,
**      It just happens to be so. It can be seen if one enables
**      RPS_IRQ and print Event Counter 1 in vpeirq(). Every
**      time RPS_INTERRUPT is called, the Event Counter 1 will
**      increment. That's how the 7146 is programmed to do event
**      counting in this budget-patch.c
**      I *think* HPS setting has something to do with the phase
**      of HS but I can't be 100% sure in that.

**      hardware debug note: a working budget card (including budget patch)
**      with vpeirq() interrupt setup in mode "0x90" (every 64K) will
**      generate 3 interrupts per 25-Hz DMA frame of 2*188*512 bytes
**      and that means 3*25=75 Hz of interrupt frequency, as seen by
**      watch cat /proc/interrupts
**
**      If this frequency is 3x lower (and data received in the DMA
**      buffer don't start with 0x47, but in the middle of packets,
**      whose lengths appear to be like 188 292 188 104 etc.
**      this means VSYNC line is not connected in the hardware.
**      (check soldering pcb and pins)
**      The same behaviour of missing VSYNC can be duplicated on budget
**      cards, by setting DD1_INIT trigger mode 7 in 3rd nibble.
*/

	// Setup RPS1 "program" (p35)
	count = 0;


	// Wait Source Line Counter Threshold                           (p36)
	WRITE_RPS1(CMD_PAUSE | EVT_HS);
	// Set GPIO3=1                                                  (p42)
	WRITE_RPS1(CMD_WR_REG_MASK | (GPIO_CTRL>>2));
	WRITE_RPS1(GPIO3_MSK);
	WRITE_RPS1(SAA7146_GPIO_OUTHI<<24);
#if RPS_IRQ
	// issue RPS1 interrupt
	WRITE_RPS1(CMD_INTERRUPT);
#endif
	// Wait reset Source Line Counter Threshold                     (p36)
	WRITE_RPS1(CMD_PAUSE | RPS_INV | EVT_HS);
	// Set GPIO3=0                                                  (p42)
	WRITE_RPS1(CMD_WR_REG_MASK | (GPIO_CTRL>>2));
	WRITE_RPS1(GPIO3_MSK);
	WRITE_RPS1(SAA7146_GPIO_OUTLO<<24);
#if RPS_IRQ
	// issue RPS1 interrupt
	WRITE_RPS1(CMD_INTERRUPT);
#endif
	// Jump to begin of RPS program                                 (p37)
	WRITE_RPS1(CMD_JUMP);
	WRITE_RPS1(dev->d_rps1.dma_handle);

	// Fix VSYNC level
	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
	// Set RPS1 Address register to point to RPS code               (r108 p42)
	saa7146_write(dev, RPS_ADDR1, dev->d_rps1.dma_handle);

	if (!(budget = kmalloc (sizeof(struct budget_patch), GFP_KERNEL)))
		return -ENOMEM;

	dprintk(2, "budget: %p\n", budget);

	err = ttpci_budget_init(budget, dev, info, THIS_MODULE, adapter_nr);
	if (err) {
		kfree(budget);
		return err;
	}

	// Set Source Line Counter Threshold, using BRS                 (rCC p43)
	// It generates HS event every TS_HEIGHT lines
	// this is related to TS_WIDTH set in register
	// NUM_LINE_BYTE3 in budget-core.c. If NUM_LINE_BYTE
	// low 16 bits are set to TS_WIDTH bytes (TS_WIDTH=2*188
	//,then RPS_THRESH1
	// should be set to trigger every TS_HEIGHT (512) lines.
	//
	saa7146_write(dev, RPS_THRESH1, budget->buffer_height | MASK_12 );

	// saa7146_write(dev, RPS_THRESH0, ((TS_HEIGHT/2)<<16) |MASK_28| (TS_HEIGHT/2) |MASK_12 );
	// Enable RPS1                                                  (rFC p33)
	saa7146_write(dev, MC1, (MASK_13 | MASK_29));


	dev->ext_priv = budget;

	budget->dvb_adapter.priv = budget;
	frontend_init(budget);

	ttpci_budget_init_hooks(budget);

	return 0;
}

__attribute__((used)) static int budget_patch_detach (struct saa7146_dev* dev)
{
	struct budget_patch *budget = (struct budget_patch*) dev->ext_priv;
	int err;

	if (budget->dvb_frontend) {
		dvb_unregister_frontend(budget->dvb_frontend);
		dvb_frontend_detach(budget->dvb_frontend);
	}
	err = ttpci_budget_deinit (budget);

	kfree (budget);

	return err;
}

