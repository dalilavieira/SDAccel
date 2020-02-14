#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int** xtalk_state_t ;
typedef  int* xtalk_instate_t ;
typedef  int* xtalk_gains_t ;
typedef  int* xtalk_dline_t ;
typedef  int** xtalk_coefs_t ;
struct TYPE_25__ {int /*<<< orphan*/  mmio; } ;
typedef  TYPE_1__ vortex_t ;
typedef  int u32 ;

/* Variables and functions */
 int XTGAINS_SZ ; 
 int* alXtalkDlineZeros ; 
 int** asDiamondCoefsLeftEq ; 
 int** asDiamondCoefsLeftXt ; 
 int** asDiamondCoefsRightEq ; 
 int** asXtalkCoefsPipe ; 
 int** asXtalkCoefsZeros ; 
 int* asXtalkGainsAllChan ; 
 int* asXtalkGainsZeros ; 
 int* asXtalkInStateZeros ; 
 int** asXtalkNarrowCoefsLeftEq ; 
 int** asXtalkNarrowCoefsLeftXt ; 
 int** asXtalkNarrowCoefsRightEq ; 
 int** asXtalkOutStateZeros ; 
 int** asXtalkWideCoefsLeftEq ; 
 int** asXtalkWideCoefsLeftXt ; 
 int** asXtalkWideCoefsRightEq ; 
 int hwread (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,int,int) ; 
 short sDiamondKLeftEq ; 
 short sDiamondKLeftXt ; 
 short sDiamondKRightEq ; 
 short sDiamondShiftLeftEq ; 
 short sDiamondShiftLeftXt ; 
 short sDiamondShiftRightEq ; 
 short sXtalkNarrowKLeftEq ; 
 short sXtalkNarrowKLeftXt ; 
 short sXtalkNarrowKRightEq ; 
 short sXtalkNarrowShiftLeftEq ; 
 short sXtalkNarrowShiftLeftXt ; 
 short sXtalkNarrowShiftRightEq ; 
 short sXtalkWideKLeftEq ; 
 short sXtalkWideKLeftXt ; 
 short sXtalkWideKRightEq ; 
 short sXtalkWideShiftLeftEq ; 
 short sXtalkWideShiftLeftXt ; 
 short sXtalkWideShiftRightEq ; 
 unsigned short wDiamondLeftDelay ; 
 unsigned short wDiamondRightDelay ; 
 unsigned short wXtalkNarrowLeftDelay ; 
 unsigned short wXtalkNarrowRightDelay ; 
 unsigned short wXtalkWideLeftDelay ; 
 unsigned short wXtalkWideRightDelay ; 

__attribute__((used)) static void
vortex_XtalkHw_SetLeftEQ(vortex_t * vortex, short arg_0, short arg_4,
			 xtalk_coefs_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x24200 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x24204 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x24208 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x2420c + i * 0x24, coefs[i][3]);
		hwwrite(vortex->mmio, 0x24210 + i * 0x24, coefs[i][4]);
	}
	hwwrite(vortex->mmio, 0x24538, arg_0 & 0xffff);
	hwwrite(vortex->mmio, 0x2453C, arg_4 & 0xffff);
}

__attribute__((used)) static void
vortex_XtalkHw_SetRightEQ(vortex_t * vortex, short arg_0, short arg_4,
			  xtalk_coefs_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x242b4 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x242b8 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x242bc + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x242c0 + i * 0x24, coefs[i][3]);
		hwwrite(vortex->mmio, 0x242c4 + i * 0x24, coefs[i][4]);
	}
	hwwrite(vortex->mmio, 0x24540, arg_0 & 0xffff);
	hwwrite(vortex->mmio, 0x24544, arg_4 & 0xffff);
}

__attribute__((used)) static void
vortex_XtalkHw_SetLeftXT(vortex_t * vortex, short arg_0, short arg_4,
			 xtalk_coefs_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x24368 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x2436c + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x24370 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x24374 + i * 0x24, coefs[i][3]);
		hwwrite(vortex->mmio, 0x24378 + i * 0x24, coefs[i][4]);
	}
	hwwrite(vortex->mmio, 0x24548, arg_0 & 0xffff);
	hwwrite(vortex->mmio, 0x2454C, arg_4 & 0xffff);
}

__attribute__((used)) static void
vortex_XtalkHw_SetRightXT(vortex_t * vortex, short arg_0, short arg_4,
			  xtalk_coefs_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x2441C + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x24420 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x24424 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x24428 + i * 0x24, coefs[i][3]);
		hwwrite(vortex->mmio, 0x2442C + i * 0x24, coefs[i][4]);
	}
	hwwrite(vortex->mmio, 0x24550, arg_0 & 0xffff);
	hwwrite(vortex->mmio, 0x24554, arg_4 & 0xffff);
}

__attribute__((used)) static void
vortex_XtalkHw_SetLeftEQStates(vortex_t * vortex,
			       xtalk_instate_t const arg_0,
			       xtalk_state_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x24214 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x24218 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x2421C + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x24220 + i * 0x24, coefs[i][3]);
	}
	hwwrite(vortex->mmio, 0x244F8, arg_0[0]);
	hwwrite(vortex->mmio, 0x244FC, arg_0[1]);
	hwwrite(vortex->mmio, 0x24500, arg_0[2]);
	hwwrite(vortex->mmio, 0x24504, arg_0[3]);
}

__attribute__((used)) static void
vortex_XtalkHw_SetRightEQStates(vortex_t * vortex,
				xtalk_instate_t const arg_0,
				xtalk_state_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x242C8 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x242CC + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x242D0 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x244D4 + i * 0x24, coefs[i][3]);
	}
	hwwrite(vortex->mmio, 0x24508, arg_0[0]);
	hwwrite(vortex->mmio, 0x2450C, arg_0[1]);
	hwwrite(vortex->mmio, 0x24510, arg_0[2]);
	hwwrite(vortex->mmio, 0x24514, arg_0[3]);
}

__attribute__((used)) static void
vortex_XtalkHw_SetLeftXTStates(vortex_t * vortex,
			       xtalk_instate_t const arg_0,
			       xtalk_state_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x2437C + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x24380 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x24384 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x24388 + i * 0x24, coefs[i][3]);
	}
	hwwrite(vortex->mmio, 0x24518, arg_0[0]);
	hwwrite(vortex->mmio, 0x2451C, arg_0[1]);
	hwwrite(vortex->mmio, 0x24520, arg_0[2]);
	hwwrite(vortex->mmio, 0x24524, arg_0[3]);
}

__attribute__((used)) static void
vortex_XtalkHw_SetRightXTStates(vortex_t * vortex,
				xtalk_instate_t const arg_0,
				xtalk_state_t const coefs)
{
	int i;

	for (i = 0; i < 5; i++) {
		hwwrite(vortex->mmio, 0x24430 + i * 0x24, coefs[i][0]);
		hwwrite(vortex->mmio, 0x24434 + i * 0x24, coefs[i][1]);
		hwwrite(vortex->mmio, 0x24438 + i * 0x24, coefs[i][2]);
		hwwrite(vortex->mmio, 0x2443C + i * 0x24, coefs[i][3]);
	}
	hwwrite(vortex->mmio, 0x24528, arg_0[0]);
	hwwrite(vortex->mmio, 0x2452C, arg_0[1]);
	hwwrite(vortex->mmio, 0x24530, arg_0[2]);
	hwwrite(vortex->mmio, 0x24534, arg_0[3]);
}

__attribute__((used)) static void
vortex_XtalkHw_SetGains(vortex_t * vortex, xtalk_gains_t const gains)
{
	int i;

	for (i = 0; i < XTGAINS_SZ; i++) {
		hwwrite(vortex->mmio, 0x244D0 + (i * 4), gains[i]);
	}
}

__attribute__((used)) static void
vortex_XtalkHw_SetGainsAllChan(vortex_t * vortex)
{
	vortex_XtalkHw_SetGains(vortex, asXtalkGainsAllChan);
}

__attribute__((used)) static void
vortex_XtalkHw_SetDelay(vortex_t * vortex, unsigned short right,
			unsigned short left)
{
	u32 esp0 = 0;

	esp0 &= 0x1FFFFFFF;
	esp0 |= 0xA0000000;
	esp0 = (esp0 & 0xffffE0ff) | ((right & 0x1F) << 8);
	esp0 = (esp0 & 0xfffc1fff) | ((left & 0x1F) << 0xd);

	hwwrite(vortex->mmio, 0x24660, esp0);
}

__attribute__((used)) static void
vortex_XtalkHw_SetLeftDline(vortex_t * vortex, xtalk_dline_t const dline)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		hwwrite(vortex->mmio, 0x24000 + (i << 2), dline[i] & 0xffff);
		hwwrite(vortex->mmio, 0x24080 + (i << 2), dline[i] >> 0x10);
	}
}

__attribute__((used)) static void
vortex_XtalkHw_SetRightDline(vortex_t * vortex, xtalk_dline_t const dline)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		hwwrite(vortex->mmio, 0x24100 + (i << 2), dline[i] & 0xffff);
		hwwrite(vortex->mmio, 0x24180 + (i << 2), dline[i] >> 0x10);
	}
}

__attribute__((used)) static void vortex_XtalkHw_SetSampleRate(vortex_t * vortex, u32 sr)
{
	u32 temp;

	temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
	temp = (temp & 0xffffff07) | ((sr & 0x1f) << 3);
	hwwrite(vortex->mmio, 0x24660, temp);
}

__attribute__((used)) static void vortex_XtalkHw_Enable(vortex_t * vortex)
{
	u32 temp;

	temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
	temp |= 1;
	hwwrite(vortex->mmio, 0x24660, temp);

}

__attribute__((used)) static void vortex_XtalkHw_Disable(vortex_t * vortex)
{
	u32 temp;

	temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
	temp &= 0xfffffffe;
	hwwrite(vortex->mmio, 0x24660, temp);

}

__attribute__((used)) static void vortex_XtalkHw_ZeroIO(vortex_t * vortex)
{
	int i;

	for (i = 0; i < 20; i++)
		hwwrite(vortex->mmio, 0x24600 + (i << 2), 0);
	for (i = 0; i < 4; i++)
		hwwrite(vortex->mmio, 0x24650 + (i << 2), 0);
}

__attribute__((used)) static void vortex_XtalkHw_ZeroState(vortex_t * vortex)
{
	vortex_XtalkHw_ZeroIO(vortex);	// inlined

	vortex_XtalkHw_SetLeftEQ(vortex, 0, 0, asXtalkCoefsZeros);
	vortex_XtalkHw_SetRightEQ(vortex, 0, 0, asXtalkCoefsZeros);

	vortex_XtalkHw_SetLeftXT(vortex, 0, 0, asXtalkCoefsZeros);
	vortex_XtalkHw_SetRightXT(vortex, 0, 0, asXtalkCoefsZeros);

	vortex_XtalkHw_SetGains(vortex, asXtalkGainsZeros);	// inlined

	vortex_XtalkHw_SetDelay(vortex, 0, 0);	// inlined

	vortex_XtalkHw_SetLeftDline(vortex, alXtalkDlineZeros);	// inlined
	vortex_XtalkHw_SetRightDline(vortex, alXtalkDlineZeros);	// inlined
	vortex_XtalkHw_SetLeftDline(vortex, alXtalkDlineZeros);	// inlined
	vortex_XtalkHw_SetRightDline(vortex, alXtalkDlineZeros);	// inlined

	vortex_XtalkHw_SetLeftEQStates(vortex, asXtalkInStateZeros,
				       asXtalkOutStateZeros);
	vortex_XtalkHw_SetRightEQStates(vortex, asXtalkInStateZeros,
					asXtalkOutStateZeros);
	vortex_XtalkHw_SetLeftXTStates(vortex, asXtalkInStateZeros,
				       asXtalkOutStateZeros);
	vortex_XtalkHw_SetRightXTStates(vortex, asXtalkInStateZeros,
					asXtalkOutStateZeros);
}

__attribute__((used)) static void vortex_XtalkHw_ProgramPipe(vortex_t * vortex)
{

	vortex_XtalkHw_SetLeftEQ(vortex, 0, 1, asXtalkCoefsPipe);
	vortex_XtalkHw_SetRightEQ(vortex, 0, 1, asXtalkCoefsPipe);
	vortex_XtalkHw_SetLeftXT(vortex, 0, 0, asXtalkCoefsZeros);
	vortex_XtalkHw_SetRightXT(vortex, 0, 0, asXtalkCoefsZeros);

	vortex_XtalkHw_SetDelay(vortex, 0, 0);	// inlined
}

__attribute__((used)) static void vortex_XtalkHw_ProgramXtalkWide(vortex_t * vortex)
{

	vortex_XtalkHw_SetLeftEQ(vortex, sXtalkWideKLeftEq,
				 sXtalkWideShiftLeftEq, asXtalkWideCoefsLeftEq);
	vortex_XtalkHw_SetRightEQ(vortex, sXtalkWideKRightEq,
				  sXtalkWideShiftRightEq,
				  asXtalkWideCoefsRightEq);
	vortex_XtalkHw_SetLeftXT(vortex, sXtalkWideKLeftXt,
				 sXtalkWideShiftLeftXt, asXtalkWideCoefsLeftXt);
	vortex_XtalkHw_SetRightXT(vortex, sXtalkWideKLeftXt,
				  sXtalkWideShiftLeftXt,
				  asXtalkWideCoefsLeftXt);

	vortex_XtalkHw_SetDelay(vortex, wXtalkWideRightDelay, wXtalkWideLeftDelay);	// inlined
}

__attribute__((used)) static void vortex_XtalkHw_ProgramXtalkNarrow(vortex_t * vortex)
{

	vortex_XtalkHw_SetLeftEQ(vortex, sXtalkNarrowKLeftEq,
				 sXtalkNarrowShiftLeftEq,
				 asXtalkNarrowCoefsLeftEq);
	vortex_XtalkHw_SetRightEQ(vortex, sXtalkNarrowKRightEq,
				  sXtalkNarrowShiftRightEq,
				  asXtalkNarrowCoefsRightEq);
	vortex_XtalkHw_SetLeftXT(vortex, sXtalkNarrowKLeftXt,
				 sXtalkNarrowShiftLeftXt,
				 asXtalkNarrowCoefsLeftXt);
	vortex_XtalkHw_SetRightXT(vortex, sXtalkNarrowKLeftXt,
				  sXtalkNarrowShiftLeftXt,
				  asXtalkNarrowCoefsLeftXt);

	vortex_XtalkHw_SetDelay(vortex, wXtalkNarrowRightDelay, wXtalkNarrowLeftDelay);	// inlined
}

__attribute__((used)) static void vortex_XtalkHw_ProgramDiamondXtalk(vortex_t * vortex)
{

	//sDiamondKLeftEq,sDiamondKRightXt,asDiamondCoefsLeftEq
	vortex_XtalkHw_SetLeftEQ(vortex, sDiamondKLeftEq,
				 sDiamondShiftLeftEq, asDiamondCoefsLeftEq);
	vortex_XtalkHw_SetRightEQ(vortex, sDiamondKRightEq,
				  sDiamondShiftRightEq, asDiamondCoefsRightEq);
	vortex_XtalkHw_SetLeftXT(vortex, sDiamondKLeftXt,
				 sDiamondShiftLeftXt, asDiamondCoefsLeftXt);
	vortex_XtalkHw_SetRightXT(vortex, sDiamondKLeftXt,
				  sDiamondShiftLeftXt, asDiamondCoefsLeftXt);

	vortex_XtalkHw_SetDelay(vortex, wDiamondRightDelay, wDiamondLeftDelay);	// inlined
}

__attribute__((used)) static void vortex_XtalkHw_init(vortex_t * vortex)
{
	vortex_XtalkHw_ZeroState(vortex);
}

