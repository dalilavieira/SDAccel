#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  size_t u32 ;
typedef  TYPE_1__* pSWAT_T ;
typedef  TYPE_2__* pFAT_T ;
struct TYPE_9__ {scalar_t__* AuxAnt_Cnt; scalar_t__* MainAnt_Cnt; scalar_t__* AuxAnt_Sum; scalar_t__* MainAnt_Sum; int /*<<< orphan*/  RxIdleAnt; } ;
struct TYPE_8__ {int try_flag; scalar_t__ Double_chk_flag; scalar_t__ RSSI_Trying; } ;
struct TYPE_10__ {int RSSI_test; TYPE_2__ DM_FatTable; TYPE_1__ DM_SWAT_Table; int /*<<< orphan*/  Adapter; int /*<<< orphan*/  SupportAbility; } ;
typedef  TYPE_3__* PDM_ODM_T ;

/* Variables and functions */
 int /*<<< orphan*/  MAIN_ANT ; 
 size_t ODM_ASSOCIATE_ENTRY_NUM ; 
 int /*<<< orphan*/  ODM_BB_ANT_DIV ; 
 int /*<<< orphan*/  ODM_COMP_ANT_DIV ; 
 int /*<<< orphan*/  ODM_DBG_LOUD ; 
 int /*<<< orphan*/  ODM_RT_TRACE (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  PHY_SetBBReg (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bMaskDWord ; 

void ODM_StopAntennaSwitchDm(PDM_ODM_T pDM_Odm)
{
	// disable ODM antenna diversity
	pDM_Odm->SupportAbility &= ~ODM_BB_ANT_DIV;
	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_ANT_DIV,
		ODM_DBG_LOUD,
		("STOP Antenna Diversity\n")
	);
}

void ODM_SetAntConfig(PDM_ODM_T pDM_Odm, u8 antSetting)// 0=A, 1=B, 2=C, ....
{
	if (antSetting == 0) // ant A
		PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000000);
	else if (antSetting == 1)
		PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
}

void ODM_SwAntDivRestAfterLink(PDM_ODM_T pDM_Odm)
{
	pSWAT_T pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
	pFAT_T pDM_FatTable = &pDM_Odm->DM_FatTable;
	u32 i;

	pDM_Odm->RSSI_test = false;
	pDM_SWAT_Table->try_flag = 0xff;
	pDM_SWAT_Table->RSSI_Trying = 0;
	pDM_SWAT_Table->Double_chk_flag = 0;

	pDM_FatTable->RxIdleAnt = MAIN_ANT;

	for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
		pDM_FatTable->MainAnt_Sum[i] = 0;
		pDM_FatTable->AuxAnt_Sum[i] = 0;
		pDM_FatTable->MainAnt_Cnt[i] = 0;
		pDM_FatTable->AuxAnt_Cnt[i] = 0;
	}
}

