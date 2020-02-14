#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {int parm0; int parm1; } ;
typedef  TYPE_2__ wt_voice_t ;
struct TYPE_18__ {int* mixwt; int /*<<< orphan*/  mmio; TYPE_1__* card; int /*<<< orphan*/ * mixplayb; int /*<<< orphan*/  fixed_res; TYPE_2__* wt_voice; } ;
typedef  TYPE_3__ vortex_t ;
typedef  int u32 ;
struct TYPE_16__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADB_MIXIN (int) ; 
 int /*<<< orphan*/  ADB_WTOUT (int,int) ; 
 int NR_WT ; 
 int NR_WT_PB ; 
 scalar_t__ VORTEX_IS_QUAD (TYPE_3__*) ; 
 int /*<<< orphan*/  VORTEX_RESOURCE_MIXIN ; 
 int WT_ARAMP (int) ; 
 int WT_CTRL (int) ; 
 int WT_DELAY (int,int) ; 
 int WT_DSREG (int) ; 
 int WT_GMODE (int) ; 
 int WT_MRAMP (int) ; 
 int WT_MUTE (int) ; 
 int WT_PARM (int,int) ; 
 int WT_RUN (int) ; 
 int WT_SRAMP (int) ; 
 int WT_STEREO (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,unsigned char,int) ; 
 int hwread (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,int,int) ; 
 int vortex_adb_checkinout (TYPE_3__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_connection_mixin_mix (TYPE_3__*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_fifo_setwtvalid (TYPE_3__*,int,int) ; 
 int /*<<< orphan*/  vortex_fifo_wtinitialize (TYPE_3__*,int,int) ; 
 int /*<<< orphan*/  vortex_route (TYPE_3__*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vortex_wt_setstereo(vortex_t * vortex, u32 wt, u32 stereo)
{
	int temp;

	//temp = hwread(vortex->mmio, 0x80 + ((wt >> 0x5)<< 0xf) + (((wt & 0x1f) >> 1) << 2));
	temp = hwread(vortex->mmio, WT_STEREO(wt));
	temp = (temp & 0xfe) | (stereo & 1);
	//hwwrite(vortex->mmio, 0x80 + ((wt >> 0x5)<< 0xf) + (((wt & 0x1f) >> 1) << 2), temp);
	hwwrite(vortex->mmio, WT_STEREO(wt), temp);
}

__attribute__((used)) static void vortex_wt_setdsout(vortex_t * vortex, u32 wt, int en)
{
	int temp;

	/* There is one DSREG register for each bank (32 voices each). */
	temp = hwread(vortex->mmio, WT_DSREG((wt >= 0x20) ? 1 : 0));
	if (en)
		temp |= (1 << (wt & 0x1f));
	else
		temp &= ~(1 << (wt & 0x1f));
	hwwrite(vortex->mmio, WT_DSREG((wt >= 0x20) ? 1 : 0), temp);
}

__attribute__((used)) static int vortex_wt_allocroute(vortex_t * vortex, int wt, int nr_ch)
{
	wt_voice_t *voice = &(vortex->wt_voice[wt]);
	int temp;

	//FIXME: WT audio routing.
	if (nr_ch) {
		vortex_fifo_wtinitialize(vortex, wt, 1);
		vortex_fifo_setwtvalid(vortex, wt, 1);
		vortex_wt_setstereo(vortex, wt, nr_ch - 1);
	} else
		vortex_fifo_setwtvalid(vortex, wt, 0);
	
	/* Set mixdown mode. */
	vortex_wt_setdsout(vortex, wt, 1);
	/* Set other parameter registers. */
	hwwrite(vortex->mmio, WT_SRAMP(0), 0x880000);
	//hwwrite(vortex->mmio, WT_GMODE(0), 0xffffffff);
#ifdef CHIP_AU8830
	hwwrite(vortex->mmio, WT_SRAMP(1), 0x880000);
	//hwwrite(vortex->mmio, WT_GMODE(1), 0xffffffff);
#endif
	hwwrite(vortex->mmio, WT_PARM(wt, 0), 0);
	hwwrite(vortex->mmio, WT_PARM(wt, 1), 0);
	hwwrite(vortex->mmio, WT_PARM(wt, 2), 0);

	temp = hwread(vortex->mmio, WT_PARM(wt, 3));
	dev_dbg(vortex->card->dev, "WT PARM3: %x\n", temp);
	//hwwrite(vortex->mmio, WT_PARM(wt, 3), temp);

	hwwrite(vortex->mmio, WT_DELAY(wt, 0), 0);
	hwwrite(vortex->mmio, WT_DELAY(wt, 1), 0);
	hwwrite(vortex->mmio, WT_DELAY(wt, 2), 0);
	hwwrite(vortex->mmio, WT_DELAY(wt, 3), 0);

	dev_dbg(vortex->card->dev, "WT GMODE: %x\n",
		hwread(vortex->mmio, WT_GMODE(wt)));

	hwwrite(vortex->mmio, WT_PARM(wt, 2), 0xffffffff);
	hwwrite(vortex->mmio, WT_PARM(wt, 3), 0xcff1c810);

	voice->parm0 = voice->parm1 = 0xcfb23e2f;
	hwwrite(vortex->mmio, WT_PARM(wt, 0), voice->parm0);
	hwwrite(vortex->mmio, WT_PARM(wt, 1), voice->parm1);
	dev_dbg(vortex->card->dev, "WT GMODE 2 : %x\n",
		hwread(vortex->mmio, WT_GMODE(wt)));
	return 0;
}

__attribute__((used)) static void vortex_wt_connect(vortex_t * vortex, int en)
{
	int i, ii, mix;

#define NR_WTROUTES 6
#ifdef CHIP_AU8830
#define NR_WTBLOCKS 2
#else
#define NR_WTBLOCKS 1
#endif

	for (i = 0; i < NR_WTBLOCKS; i++) {
		for (ii = 0; ii < NR_WTROUTES; ii++) {
			mix =
			    vortex_adb_checkinout(vortex,
						  vortex->fixed_res, en,
						  VORTEX_RESOURCE_MIXIN);
			vortex->mixwt[(i * NR_WTROUTES) + ii] = mix;

			vortex_route(vortex, en, 0x11,
				     ADB_WTOUT(i, ii + 0x20), ADB_MIXIN(mix));

			vortex_connection_mixin_mix(vortex, en, mix,
						    vortex->mixplayb[ii % 2], 0);
			if (VORTEX_IS_QUAD(vortex))
				vortex_connection_mixin_mix(vortex, en,
							    mix,
							    vortex->mixplayb[2 +
								     (ii % 2)], 0);
		}
	}
	for (i = 0; i < NR_WT; i++) {
		hwwrite(vortex->mmio, WT_RUN(i), 1);
	}
}

__attribute__((used)) static int
vortex_wt_SetReg(vortex_t * vortex, unsigned char reg, int wt,
		 u32 val)
{
	int ecx;

	if ((reg == 5) || ((reg >= 7) && (reg <= 10)) || (reg == 0xc)) {
		if (wt >= (NR_WT / NR_WT_PB)) {
			dev_warn(vortex->card->dev,
				 "WT SetReg: bank out of range. reg=0x%x, wt=%d\n",
				 reg, wt);
			return 0;
		}
	} else {
		if (wt >= NR_WT) {
			dev_err(vortex->card->dev,
				"WT SetReg: voice out of range\n");
			return 0;
		}
	}
	if (reg > 0xc)
		return 0;

	switch (reg) {
		/* Voice specific parameters */
	case 0:		/* running */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_RUN(wt), (int)val);
		*/
		hwwrite(vortex->mmio, WT_RUN(wt), val);
		return 0xc;
	case 1:		/* param 0 */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_PARM(wt,0), (int)val);
		*/
		hwwrite(vortex->mmio, WT_PARM(wt, 0), val);
		return 0xc;
	case 2:		/* param 1 */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_PARM(wt,1), (int)val);
		*/
		hwwrite(vortex->mmio, WT_PARM(wt, 1), val);
		return 0xc;
	case 3:		/* param 2 */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_PARM(wt,2), (int)val);
		*/
		hwwrite(vortex->mmio, WT_PARM(wt, 2), val);
		return 0xc;
	case 4:		/* param 3 */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_PARM(wt,3), (int)val);
		*/
		hwwrite(vortex->mmio, WT_PARM(wt, 3), val);
		return 0xc;
	case 6:		/* mute */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_MUTE(wt), (int)val);
		*/
		hwwrite(vortex->mmio, WT_MUTE(wt), val);
		return 0xc;
	case 0xb:
			/* delay */
		/*
		pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n",
		       WT_DELAY(wt,0), (int)val);
		*/
		hwwrite(vortex->mmio, WT_DELAY(wt, 3), val);
		hwwrite(vortex->mmio, WT_DELAY(wt, 2), val);
		hwwrite(vortex->mmio, WT_DELAY(wt, 1), val);
		hwwrite(vortex->mmio, WT_DELAY(wt, 0), val);
		return 0xc;
		/* Global WT block parameters */
	case 5:		/* sramp */
		ecx = WT_SRAMP(wt);
		break;
	case 8:		/* aramp */
		ecx = WT_ARAMP(wt);
		break;
	case 9:		/* mramp */
		ecx = WT_MRAMP(wt);
		break;
	case 0xa:		/* ctrl */
		ecx = WT_CTRL(wt);
		break;
	case 0xc:		/* ds_reg */
		ecx = WT_DSREG(wt);
		break;
	default:
		return 0;
	}
	/*
	pr_debug( "vortex: WT SetReg(0x%x) = 0x%08x\n", ecx, (int)val);
	*/
	hwwrite(vortex->mmio, ecx, val);
	return 1;
}

__attribute__((used)) static void vortex_wt_init(vortex_t * vortex)
{
	u32 var4, var8, varc, var10 = 0, edi;

	var10 &= 0xFFFFFFE3;
	var10 |= 0x22;
	var10 &= 0xFFFFFEBF;
	var10 |= 0x80;
	var10 |= 0x200;
	var10 &= 0xfffffffe;
	var10 &= 0xfffffbff;
	var10 |= 0x1800;
	// var10 = 0x1AA2
	var4 = 0x10000000;
	varc = 0x00830000;
	var8 = 0x00830000;

	/* Init Bank registers. */
	for (edi = 0; edi < (NR_WT / NR_WT_PB); edi++) {
		vortex_wt_SetReg(vortex, 0xc, edi, 0);	/* ds_reg */
		vortex_wt_SetReg(vortex, 0xa, edi, var10);	/* ctrl  */
		vortex_wt_SetReg(vortex, 0x9, edi, var4);	/* mramp */
		vortex_wt_SetReg(vortex, 0x8, edi, varc);	/* aramp */
		vortex_wt_SetReg(vortex, 0x5, edi, var8);	/* sramp */
	}
	/* Init Voice registers. */
	for (edi = 0; edi < NR_WT; edi++) {
		vortex_wt_SetReg(vortex, 0x4, edi, 0);	/* param 3 0x20c */
		vortex_wt_SetReg(vortex, 0x3, edi, 0);	/* param 2 0x208 */
		vortex_wt_SetReg(vortex, 0x2, edi, 0);	/* param 1 0x204 */
		vortex_wt_SetReg(vortex, 0x1, edi, 0);	/* param 0 0x200 */
		vortex_wt_SetReg(vortex, 0xb, edi, 0);	/* delay 0x400 - 0x40c */
	}
	var10 |= 1;
	for (edi = 0; edi < (NR_WT / NR_WT_PB); edi++)
		vortex_wt_SetReg(vortex, 0xa, edi, var10);	/* ctrl */
}

