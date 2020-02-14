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
struct odm_dm_struct {int BoardType; int SupportPlatform; int SupportInterface; } ;
struct hal_data_8188e {struct bb_reg_def* PHYRegDef; struct odm_dm_struct odmpriv; } ;
struct bb_reg_def {int /*<<< orphan*/  rfintfs; int /*<<< orphan*/  rfHSSIPara2; int /*<<< orphan*/  rfintfo; int /*<<< orphan*/  rfintfe; } ;
struct adapter {struct hal_data_8188e* HalData; } ;
typedef  enum rf_radio_path { ____Placeholder_rf_radio_path } rf_radio_path ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int* Array_RadioA_1T_8188E ; 
 int B3WIREADDREAALENGTH ; 
 int B3WIREDATALENGTH ; 
 int BRFSI_RFENV ; 
 int /*<<< orphan*/  READ_NEXT_PAIR (int,int,int) ; 
 size_t RF90_PATH_A ; 
 int RFREG_OFFSET_MASK ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int phy_query_bb_reg (struct adapter*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_set_bb_reg (struct adapter*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  phy_set_rf_reg (struct adapter*,int,int,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static bool check_condition(struct adapter *adapt, const u32  condition)
{
	struct odm_dm_struct *odm = &adapt->HalData->odmpriv;
	u32 _board = odm->BoardType;
	u32 _platform = odm->SupportPlatform;
	u32 _interface = odm->SupportInterface;
	u32 cond = condition;

	if (condition == 0xCDCDCDCD)
		return true;

	cond = condition & 0x000000FF;
	if ((_board == cond) && cond != 0x00)
		return false;

	cond = condition & 0x0000FF00;
	cond >>= 8;
	if ((_interface & cond) == 0 && cond != 0x07)
		return false;

	cond = condition & 0x00FF0000;
	cond >>= 16;
	if ((_platform & cond) == 0 && cond != 0x0F)
		return false;
	return true;
}

__attribute__((used)) static void rtl_rfreg_delay(struct adapter *adapt, enum rf_radio_path rfpath, u32 addr, u32 mask, u32 data)
{
	if (addr == 0xfe) {
		mdelay(50);
	} else if (addr == 0xfd) {
		mdelay(5);
	} else if (addr == 0xfc) {
		mdelay(1);
	} else if (addr == 0xfb) {
		udelay(50);
	} else if (addr == 0xfa) {
		udelay(5);
	} else if (addr == 0xf9) {
		udelay(1);
	} else {
		phy_set_rf_reg(adapt, rfpath, addr, mask, data);
		udelay(1);
	}
}

__attribute__((used)) static void rtl8188e_config_rf_reg(struct adapter *adapt,
	u32 addr, u32 data)
{
	u32 content = 0x1000; /*RF Content: radio_a_txt*/
	u32 maskforphyset = content & 0xE000;

	rtl_rfreg_delay(adapt, RF90_PATH_A, addr | maskforphyset,
			RFREG_OFFSET_MASK,
			data);
}

__attribute__((used)) static bool rtl88e_phy_config_rf_with_headerfile(struct adapter *adapt)
{
	u32 i;
	u32 array_len = ARRAY_SIZE(Array_RadioA_1T_8188E);
	u32 *array = Array_RadioA_1T_8188E;

	for (i = 0; i < array_len; i += 2) {
		u32 v1 = array[i];
		u32 v2 = array[i+1];

		if (v1 < 0xCDCDCDCD) {
			rtl8188e_config_rf_reg(adapt, v1, v2);
			continue;
		} else {
			if (!check_condition(adapt, array[i])) {
				READ_NEXT_PAIR(v1, v2, i);
				while (v2 != 0xDEAD && v2 != 0xCDEF &&
				       v2 != 0xCDCD && i < array_len - 2)
					READ_NEXT_PAIR(v1, v2, i);
				i -= 2;
			} else {
				READ_NEXT_PAIR(v1, v2, i);
				while (v2 != 0xDEAD && v2 != 0xCDEF &&
				       v2 != 0xCDCD && i < array_len - 2) {
						rtl8188e_config_rf_reg(adapt, v1, v2);
						READ_NEXT_PAIR(v1, v2, i);
				}

				while (v2 != 0xDEAD && i < array_len - 2)
					READ_NEXT_PAIR(v1, v2, i);
			}
		}
	}
	return true;
}

__attribute__((used)) static bool rf6052_conf_para(struct adapter *adapt)
{
	struct hal_data_8188e *hal_data = adapt->HalData;
	u32 u4val = 0;
	bool rtstatus = true;
	struct bb_reg_def *pphyreg;

	pphyreg = &hal_data->PHYRegDef[RF90_PATH_A];
	u4val = phy_query_bb_reg(adapt, pphyreg->rfintfs, BRFSI_RFENV);

	phy_set_bb_reg(adapt, pphyreg->rfintfe, BRFSI_RFENV << 16, 0x1);
	udelay(1);

	phy_set_bb_reg(adapt, pphyreg->rfintfo, BRFSI_RFENV, 0x1);
	udelay(1);

	phy_set_bb_reg(adapt, pphyreg->rfHSSIPara2, B3WIREADDREAALENGTH, 0x0);
	udelay(1);

	phy_set_bb_reg(adapt, pphyreg->rfHSSIPara2, B3WIREDATALENGTH, 0x0);
	udelay(1);

	rtstatus = rtl88e_phy_config_rf_with_headerfile(adapt);

	phy_set_bb_reg(adapt, pphyreg->rfintfs, BRFSI_RFENV, u4val);

	return rtstatus;
}

__attribute__((used)) static bool rtl88e_phy_rf6052_config(struct adapter *adapt)
{
	return rf6052_conf_para(adapt);
}

bool rtl88eu_phy_rf_config(struct adapter *adapt)
{
	return rtl88e_phy_rf6052_config(adapt);
}

