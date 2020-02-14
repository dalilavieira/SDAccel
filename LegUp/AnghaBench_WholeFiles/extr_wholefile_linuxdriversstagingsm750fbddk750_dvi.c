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
typedef  scalar_t__ u32 ;
struct dvi_ctrl_device {int (* pfnInit ) (unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char) ;} ;

/* Variables and functions */
 struct dvi_ctrl_device* g_dcftSupportedDviController ; 
 scalar_t__ mmio750 ; 
 scalar_t__ readl (scalar_t__) ; 
 int stub1 (unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline u32 peek32(u32 addr)
{
	return readl(addr + mmio750);
}

__attribute__((used)) static inline void poke32(u32 addr, u32 data)
{
	writel(data, addr + mmio750);
}

int dviInit(unsigned char edgeSelect,
	    unsigned char busSelect,
	    unsigned char dualEdgeClkSelect,
	    unsigned char hsyncEnable,
	    unsigned char vsyncEnable,
	    unsigned char deskewEnable,
	    unsigned char deskewSetting,
	    unsigned char continuousSyncEnable,
	    unsigned char pllFilterEnable,
	    unsigned char pllFilterValue)
{
	struct dvi_ctrl_device *pCurrentDviCtrl;

	pCurrentDviCtrl = g_dcftSupportedDviController;
	if (pCurrentDviCtrl->pfnInit) {
		return pCurrentDviCtrl->pfnInit(edgeSelect,
						busSelect,
						dualEdgeClkSelect,
						hsyncEnable,
						vsyncEnable,
						deskewEnable,
						deskewSetting,
						continuousSyncEnable,
						pllFilterEnable,
						pllFilterValue);
	}
	return -1; /* error */
}

