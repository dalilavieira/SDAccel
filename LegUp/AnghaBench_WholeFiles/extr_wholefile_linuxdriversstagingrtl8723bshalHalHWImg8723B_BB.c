#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_11__ {int BoardType; int CutVersion; int SupportPlatform; int PackageType; int SupportInterface; int TypeGLNA; int TypeGPA; int TypeALNA; int TypeAPA; int PhyRegPgVersion; int /*<<< orphan*/  PhyRegPgValueType; } ;
typedef  TYPE_1__* PDM_ODM_T ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int* Array_MP_8723B_AGC_TAB ; 
 int* Array_MP_8723B_PHY_REG ; 
 int* Array_MP_8723B_PHY_REG_PG ; 
 int BIT0 ; 
 int BIT1 ; 
 int BIT2 ; 
 int BIT28 ; 
 int BIT29 ; 
 int BIT3 ; 
 int BIT4 ; 
 int BIT6 ; 
 int BIT7 ; 
 int COND_ELSE ; 
 int COND_ENDIF ; 
 int /*<<< orphan*/  ODM_COMP_INIT ; 
 int /*<<< orphan*/  ODM_DBG_LOUD ; 
 int /*<<< orphan*/  ODM_DBG_TRACE ; 
 int /*<<< orphan*/  ODM_RT_TRACE (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  PHY_REG_PG_EXACT_VALUE ; 
 int /*<<< orphan*/  READ_NEXT_PAIR (int,int,int) ; 
 int /*<<< orphan*/  bMaskDWord ; 
 int /*<<< orphan*/  odm_ConfigBB_AGC_8723B (TYPE_1__*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  odm_ConfigBB_PHY_8723B (TYPE_1__*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  odm_ConfigBB_PHY_REG_PG_8723B (TYPE_1__*,int,int,int,int,int,int) ; 

__attribute__((used)) static bool CheckPositive(
	PDM_ODM_T pDM_Odm, const u32 Condition1, const u32 Condition2
)
{
	u8 _BoardType =
		((pDM_Odm->BoardType & BIT4) >> 4) << 0 | /*  _GLNA */
		((pDM_Odm->BoardType & BIT3) >> 3) << 1 | /*  _GPA */
		((pDM_Odm->BoardType & BIT7) >> 7) << 2 | /*  _ALNA */
		((pDM_Odm->BoardType & BIT6) >> 6) << 3 | /*  _APA */
		((pDM_Odm->BoardType & BIT2) >> 2) << 4;  /*  _BT */

	u32 cond1 = Condition1, cond2 = Condition2;
	u32 driver1 =
		pDM_Odm->CutVersion << 24 |
		pDM_Odm->SupportPlatform << 16 |
		pDM_Odm->PackageType << 12 |
		pDM_Odm->SupportInterface << 8  |
		_BoardType;

	u32 driver2 =
		pDM_Odm->TypeGLNA << 0 |
		pDM_Odm->TypeGPA << 8 |
		pDM_Odm->TypeALNA << 16 |
		pDM_Odm->TypeAPA << 24;

	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_TRACE,
		(
			"===> [8812A] CheckPositive (cond1, cond2) = (0x%X 0x%X)\n",
			cond1,
			cond2
		)
	);
	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_TRACE,
		(
			"===> [8812A] CheckPositive (driver1, driver2) = (0x%X 0x%X)\n",
			driver1,
			driver2
		)
	);

	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_TRACE,
		("	(Platform, Interface) = (0x%X, 0x%X)\n",
			pDM_Odm->SupportPlatform,
			pDM_Odm->SupportInterface
		)
	);
	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_TRACE,
		(
			"	(Board, Package) = (0x%X, 0x%X)\n",
			pDM_Odm->BoardType,
			pDM_Odm->PackageType
		)
	);


	/*  Value Defined Check =============== */
	/* QFN Type [15:12] and Cut Version [27:24] need to do value check */

	if (((cond1 & 0x0000F000) != 0) && ((cond1 & 0x0000F000) != (driver1 & 0x0000F000)))
		return false;
	if (((cond1 & 0x0F000000) != 0) && ((cond1 & 0x0F000000) != (driver1 & 0x0F000000)))
		return false;

	/*  Bit Defined Check ================ */
	/*  We don't care [31:28] and [23:20] */
	/*  */
	cond1   &= 0x000F0FFF;
	driver1 &= 0x000F0FFF;

	if ((cond1 & driver1) == cond1) {
		u32 bitMask = 0;

		if ((cond1 & 0x0F) == 0) /*  BoardType is DONTCARE */
			return true;

		if ((cond1 & BIT0) != 0) /* GLNA */
			bitMask |= 0x000000FF;
		if ((cond1 & BIT1) != 0) /* GPA */
			bitMask |= 0x0000FF00;
		if ((cond1 & BIT2) != 0) /* ALNA */
			bitMask |= 0x00FF0000;
		if ((cond1 & BIT3) != 0) /* APA */
			bitMask |= 0xFF000000;

		/*  BoardType of each RF path is matched */
		if ((cond2 & bitMask) == (driver2 & bitMask))
			return true;
	}
	return false;
}

__attribute__((used)) static bool CheckNegative(
	PDM_ODM_T pDM_Odm, const u32  Condition1, const u32 Condition2
)
{
	return true;
}

void ODM_ReadAndConfig_MP_8723B_AGC_TAB(PDM_ODM_T pDM_Odm)
{
	u32 i = 0;
	u32 ArrayLen = ARRAY_SIZE(Array_MP_8723B_AGC_TAB);
	u32 *Array = Array_MP_8723B_AGC_TAB;

	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_LOUD,
		("===> ODM_ReadAndConfig_MP_8723B_AGC_TAB\n")
	);

	for (i = 0; i < ArrayLen; i += 2) {
		u32 v1 = Array[i];
		u32 v2 = Array[i+1];

		/*  This (offset, data) pair doesn't care the condition. */
		if (v1 < 0x40000000) {
			odm_ConfigBB_AGC_8723B(pDM_Odm, v1, bMaskDWord, v2);
			continue;
		} else {
			/*  This line is the beginning of branch. */
			bool bMatched = true;
			u8  cCond  = (u8)((v1 & (BIT29|BIT28)) >> 28);

			if (cCond == COND_ELSE) { /*  ELSE, ENDIF */
				bMatched = true;
				READ_NEXT_PAIR(v1, v2, i);
			} else if (!CheckPositive(pDM_Odm, v1, v2)) {
				bMatched = false;
				READ_NEXT_PAIR(v1, v2, i);
				READ_NEXT_PAIR(v1, v2, i);
			} else {
				READ_NEXT_PAIR(v1, v2, i);
				if (!CheckNegative(pDM_Odm, v1, v2))
					bMatched = false;
				else
					bMatched = true;
				READ_NEXT_PAIR(v1, v2, i);
			}

			if (bMatched == false) {
				/*  Condition isn't matched.
				*   Discard the following (offset, data) pairs.
				*/
				while (v1 < 0x40000000 && i < ArrayLen-2)
					READ_NEXT_PAIR(v1, v2, i);

				i -= 2; /*  prevent from for-loop += 2 */
			} else {
				/*  Configure matched pairs and skip to end of if-else. */
				while (v1 < 0x40000000 && i < ArrayLen-2) {
					odm_ConfigBB_AGC_8723B(pDM_Odm, v1, bMaskDWord, v2);
					READ_NEXT_PAIR(v1, v2, i);
				}

				/*  Keeps reading until ENDIF. */
				cCond = (u8)((v1 & (BIT29|BIT28)) >> 28);
				while (cCond != COND_ENDIF && i < ArrayLen-2) {
					READ_NEXT_PAIR(v1, v2, i);
					cCond = (u8)((v1 & (BIT29|BIT28)) >> 28);
				}
			}
		}
	}
}

void ODM_ReadAndConfig_MP_8723B_PHY_REG(PDM_ODM_T pDM_Odm)
{
	u32 i = 0;
	u32 ArrayLen = ARRAY_SIZE(Array_MP_8723B_PHY_REG);
	u32 *Array = Array_MP_8723B_PHY_REG;

	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_LOUD,
		("===> ODM_ReadAndConfig_MP_8723B_PHY_REG\n")
	);

	for (i = 0; i < ArrayLen; i += 2) {
		u32 v1 = Array[i];
		u32 v2 = Array[i+1];

		/*  This (offset, data) pair doesn't care the condition. */
		if (v1 < 0x40000000) {
			odm_ConfigBB_PHY_8723B(pDM_Odm, v1, bMaskDWord, v2);
			continue;
		} else {
			/*  This line is the beginning of branch. */
			bool bMatched = true;
			u8  cCond  = (u8)((v1 & (BIT29|BIT28)) >> 28);

			if (cCond == COND_ELSE) { /*  ELSE, ENDIF */
				bMatched = true;
				READ_NEXT_PAIR(v1, v2, i);
			} else if (!CheckPositive(pDM_Odm, v1, v2)) {
				bMatched = false;
				READ_NEXT_PAIR(v1, v2, i);
				READ_NEXT_PAIR(v1, v2, i);
			} else {
				READ_NEXT_PAIR(v1, v2, i);
				if (!CheckNegative(pDM_Odm, v1, v2))
					bMatched = false;
				else
					bMatched = true;
				READ_NEXT_PAIR(v1, v2, i);
			}

			if (bMatched == false) {
				/*  Condition isn't matched.
				*   Discard the following (offset, data) pairs.
				*/
				while (v1 < 0x40000000 && i < ArrayLen-2)
					READ_NEXT_PAIR(v1, v2, i);

				i -= 2; /*  prevent from for-loop += 2 */
			} else { /*  Configure matched pairs and skip to end of if-else. */
				while (v1 < 0x40000000 && i < ArrayLen-2) {
					odm_ConfigBB_PHY_8723B(pDM_Odm, v1, bMaskDWord, v2);
					READ_NEXT_PAIR(v1, v2, i);
				}

				/*  Keeps reading until ENDIF. */
				cCond = (u8)((v1 & (BIT29|BIT28)) >> 28);
				while (cCond != COND_ENDIF && i < ArrayLen-2) {
					READ_NEXT_PAIR(v1, v2, i);
					cCond = (u8)((v1 & (BIT29|BIT28)) >> 28);
				}
			}
		}
	}
}

void ODM_ReadAndConfig_MP_8723B_PHY_REG_PG(PDM_ODM_T pDM_Odm)
{
	u32 i = 0;
	u32 *Array = Array_MP_8723B_PHY_REG_PG;

	ODM_RT_TRACE(
		pDM_Odm,
		ODM_COMP_INIT,
		ODM_DBG_LOUD,
		("===> ODM_ReadAndConfig_MP_8723B_PHY_REG_PG\n")
	);

	pDM_Odm->PhyRegPgVersion = 1;
	pDM_Odm->PhyRegPgValueType = PHY_REG_PG_EXACT_VALUE;

	for (i = 0; i < ARRAY_SIZE(Array_MP_8723B_PHY_REG_PG); i += 6) {
		u32 v1 = Array[i];
		u32 v2 = Array[i+1];
		u32 v3 = Array[i+2];
		u32 v4 = Array[i+3];
		u32 v5 = Array[i+4];
		u32 v6 = Array[i+5];

		odm_ConfigBB_PHY_REG_PG_8723B(pDM_Odm, v1, v2, v3, v4, v5, v6);
	}
}

