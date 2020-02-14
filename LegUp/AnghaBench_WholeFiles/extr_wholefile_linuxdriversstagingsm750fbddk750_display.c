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
typedef  unsigned long u32 ;
typedef  enum disp_output { ____Placeholder_disp_output } disp_output ;

/* Variables and functions */
 int CRT_2_MASK ; 
 int CRT_2_OFFSET ; 
 int CRT_2_USAGE ; 
 void* CRT_DISPLAY_CTRL ; 
 unsigned int CRT_DISPLAY_CTRL_BLANK ; 
 unsigned long CRT_DISPLAY_CTRL_RESERVED_MASK ; 
 unsigned int CRT_DISPLAY_CTRL_SELECT_MASK ; 
 int CRT_DISPLAY_CTRL_SELECT_SHIFT ; 
 int DAC_MASK ; 
 int DAC_OFFSET ; 
 int DAC_USAGE ; 
 unsigned long DISPLAY_CTRL_PLANE ; 
 unsigned long DISPLAY_CTRL_TIMING ; 
 int DPMS_MASK ; 
 int DPMS_OFFSET ; 
 int DPMS_USAGE ; 
 void* PANEL_DISPLAY_CTRL ; 
 unsigned int PANEL_DISPLAY_CTRL_DATA ; 
 unsigned int PANEL_DISPLAY_CTRL_FPEN ; 
 unsigned long PANEL_DISPLAY_CTRL_RESERVED_MASK ; 
 unsigned int PANEL_DISPLAY_CTRL_SELECT_MASK ; 
 int PANEL_DISPLAY_CTRL_SELECT_SHIFT ; 
 unsigned int PANEL_DISPLAY_CTRL_VBIASEN ; 
 unsigned long PANEL_PLL_CTRL ; 
 unsigned long PLL_CTRL_POWER ; 
 int PNL_2_MASK ; 
 int PNL_2_OFFSET ; 
 int PNL_2_USAGE ; 
 int PNL_SEQ_MASK ; 
 int PNL_SEQ_OFFSET ; 
 int PNL_SEQ_USAGE ; 
 int PRI_TP_MASK ; 
 int PRI_TP_OFFSET ; 
 int PRI_TP_USAGE ; 
 int SEC_TP_MASK ; 
 int SEC_TP_OFFSET ; 
 int SEC_TP_USAGE ; 
 unsigned long SYSTEM_CTRL ; 
 unsigned int SYSTEM_CTRL_PANEL_VSYNC_ACTIVE ; 
 int /*<<< orphan*/  ddk750_set_dpms (int) ; 
 unsigned long mmio750 ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 unsigned long readl (unsigned long) ; 
 int /*<<< orphan*/  setDAC (int) ; 
 int /*<<< orphan*/  writel (unsigned long,unsigned long) ; 

__attribute__((used)) static inline u32 peek32(u32 addr)
{
	return readl(addr + mmio750);
}

__attribute__((used)) static inline void poke32(u32 addr, u32 data)
{
	writel(data, addr + mmio750);
}

__attribute__((used)) static void setDisplayControl(int ctrl, int disp_state)
{
	/* state != 0 means turn on both timing & plane en_bit */
	unsigned long reg, val, reserved;
	int cnt = 0;

	if (!ctrl) {
		reg = PANEL_DISPLAY_CTRL;
		reserved = PANEL_DISPLAY_CTRL_RESERVED_MASK;
	} else {
		reg = CRT_DISPLAY_CTRL;
		reserved = CRT_DISPLAY_CTRL_RESERVED_MASK;
	}

	val = peek32(reg);
	if (disp_state) {
		/*
		 * Timing should be enabled first before enabling the
		 * plane because changing at the same time does not
		 * guarantee that the plane will also enabled or
		 * disabled.
		 */
		val |= DISPLAY_CTRL_TIMING;
		poke32(reg, val);

		val |= DISPLAY_CTRL_PLANE;

		/*
		 * Somehow the register value on the plane is not set
		 * until a few delay. Need to write and read it a
		 * couple times
		 */
		do {
			cnt++;
			poke32(reg, val);
		} while ((peek32(reg) & ~reserved) != (val & ~reserved));
		pr_debug("Set Plane enbit:after tried %d times\n", cnt);
	} else {
		/*
		 * When turning off, there is no rule on the
		 * programming sequence since whenever the clock is
		 * off, then it does not matter whether the plane is
		 * enabled or disabled.  Note: Modifying the plane bit
		 * will take effect on the next vertical sync. Need to
		 * find out if it is necessary to wait for 1 vsync
		 * before modifying the timing enable bit.
		 */
		val &= ~DISPLAY_CTRL_PLANE;
		poke32(reg, val);

		val &= ~DISPLAY_CTRL_TIMING;
		poke32(reg, val);
	}
}

__attribute__((used)) static void primary_wait_vertical_sync(int delay)
{
	unsigned int status;

	/*
	 * Do not wait when the Primary PLL is off or display control is
	 * already off. This will prevent the software to wait forever.
	 */
	if (!(peek32(PANEL_PLL_CTRL) & PLL_CTRL_POWER) ||
	    !(peek32(PANEL_DISPLAY_CTRL) & DISPLAY_CTRL_TIMING))
		return;

	while (delay-- > 0) {
		/* Wait for end of vsync. */
		do {
			status = peek32(SYSTEM_CTRL);
		} while (status & SYSTEM_CTRL_PANEL_VSYNC_ACTIVE);

		/* Wait for start of vsync. */
		do {
			status = peek32(SYSTEM_CTRL);
		} while (!(status & SYSTEM_CTRL_PANEL_VSYNC_ACTIVE));
	}
}

__attribute__((used)) static void swPanelPowerSequence(int disp, int delay)
{
	unsigned int reg;

	/* disp should be 1 to open sequence */
	reg = peek32(PANEL_DISPLAY_CTRL);
	reg |= (disp ? PANEL_DISPLAY_CTRL_FPEN : 0);
	poke32(PANEL_DISPLAY_CTRL, reg);
	primary_wait_vertical_sync(delay);

	reg = peek32(PANEL_DISPLAY_CTRL);
	reg |= (disp ? PANEL_DISPLAY_CTRL_DATA : 0);
	poke32(PANEL_DISPLAY_CTRL, reg);
	primary_wait_vertical_sync(delay);

	reg = peek32(PANEL_DISPLAY_CTRL);
	reg |= (disp ? PANEL_DISPLAY_CTRL_VBIASEN : 0);
	poke32(PANEL_DISPLAY_CTRL, reg);
	primary_wait_vertical_sync(delay);

	reg = peek32(PANEL_DISPLAY_CTRL);
	reg |= (disp ? PANEL_DISPLAY_CTRL_FPEN : 0);
	poke32(PANEL_DISPLAY_CTRL, reg);
	primary_wait_vertical_sync(delay);
}

void ddk750_setLogicalDispOut(enum disp_output output)
{
	unsigned int reg;

	if (output & PNL_2_USAGE) {
		/* set panel path controller select */
		reg = peek32(PANEL_DISPLAY_CTRL);
		reg &= ~PANEL_DISPLAY_CTRL_SELECT_MASK;
		reg |= (((output & PNL_2_MASK) >> PNL_2_OFFSET) <<
			PANEL_DISPLAY_CTRL_SELECT_SHIFT);
		poke32(PANEL_DISPLAY_CTRL, reg);
	}

	if (output & CRT_2_USAGE) {
		/* set crt path controller select */
		reg = peek32(CRT_DISPLAY_CTRL);
		reg &= ~CRT_DISPLAY_CTRL_SELECT_MASK;
		reg |= (((output & CRT_2_MASK) >> CRT_2_OFFSET) <<
			CRT_DISPLAY_CTRL_SELECT_SHIFT);
		/*se blank off */
		reg &= ~CRT_DISPLAY_CTRL_BLANK;
		poke32(CRT_DISPLAY_CTRL, reg);
	}

	if (output & PRI_TP_USAGE) {
		/* set primary timing and plane en_bit */
		setDisplayControl(0, (output & PRI_TP_MASK) >> PRI_TP_OFFSET);
	}

	if (output & SEC_TP_USAGE) {
		/* set secondary timing and plane en_bit*/
		setDisplayControl(1, (output & SEC_TP_MASK) >> SEC_TP_OFFSET);
	}

	if (output & PNL_SEQ_USAGE) {
		/* set  panel sequence */
		swPanelPowerSequence((output & PNL_SEQ_MASK) >> PNL_SEQ_OFFSET,
				     4);
	}

	if (output & DAC_USAGE)
		setDAC((output & DAC_MASK) >> DAC_OFFSET);

	if (output & DPMS_USAGE)
		ddk750_set_dpms((output & DPMS_MASK) >> DPMS_OFFSET);
}

