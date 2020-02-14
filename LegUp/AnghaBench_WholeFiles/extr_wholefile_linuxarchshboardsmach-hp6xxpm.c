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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
typedef  int /*<<< orphan*/  suspend_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  DACR ; 
 int /*<<< orphan*/  FRQCR ; 
 int FRQCR_PLLEN ; 
 int FRQCR_PSTBY ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  HD64461_SCPUCR ; 
 scalar_t__ INTR_OFFSET ; 
 int /*<<< orphan*/  MCR ; 
 int MCR_RFSH ; 
 int MCR_RMODE ; 
 int /*<<< orphan*/  RTCNT ; 
 int /*<<< orphan*/  STBCR ; 
 int /*<<< orphan*/  STBCR2 ; 
 int STBCR_MSTP2 ; 
 int STBCR_STBY ; 
 int WTCSR_CKS_4096 ; 
 int WTCSR_TME ; 
 int __raw_readb (int /*<<< orphan*/ ) ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bl_bit () ; 
 int /*<<< orphan*/  cpu_sleep () ; 
 int /*<<< orphan*/  free_page (scalar_t__) ; 
 scalar_t__ get_zeroed_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  outw (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bl_bit () ; 
 int sh_wdt_read_csr () ; 
 int /*<<< orphan*/  sh_wdt_write_cnt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh_wdt_write_csr (int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wakeup_end ; 
 int /*<<< orphan*/  wakeup_start ; 

__attribute__((used)) static void pm_enter(void)
{
	u8 stbcr, csr;
	u16 frqcr, mcr;
	u32 vbr_new, vbr_old;

	set_bl_bit();

	/* set wdt */
	csr = sh_wdt_read_csr();
	csr &= ~WTCSR_TME;
	csr |= WTCSR_CKS_4096;
	sh_wdt_write_csr(csr);
	csr = sh_wdt_read_csr();
	sh_wdt_write_cnt(0);

	/* disable PLL1 */
	frqcr = __raw_readw(FRQCR);
	frqcr &= ~(FRQCR_PLLEN | FRQCR_PSTBY);
	__raw_writew(frqcr, FRQCR);

	/* enable standby */
	stbcr = __raw_readb(STBCR);
	__raw_writeb(stbcr | STBCR_STBY | STBCR_MSTP2, STBCR);

	/* set self-refresh */
	mcr = __raw_readw(MCR);
	__raw_writew(mcr & ~MCR_RFSH, MCR);

	/* set interrupt handler */
	asm volatile("stc vbr, %0" : "=r" (vbr_old));
	vbr_new = get_zeroed_page(GFP_ATOMIC);
	udelay(50);
	memcpy((void*)(vbr_new + INTR_OFFSET),
	       &wakeup_start, &wakeup_end - &wakeup_start);
	asm volatile("ldc %0, vbr" : : "r" (vbr_new));

	__raw_writew(0, RTCNT);
	__raw_writew(mcr | MCR_RFSH | MCR_RMODE, MCR);

	cpu_sleep();

	asm volatile("ldc %0, vbr" : : "r" (vbr_old));

	free_page(vbr_new);

	/* enable PLL1 */
	frqcr = __raw_readw(FRQCR);
	frqcr |= FRQCR_PSTBY;
	__raw_writew(frqcr, FRQCR);
	udelay(50);
	frqcr |= FRQCR_PLLEN;
	__raw_writew(frqcr, FRQCR);

	__raw_writeb(stbcr, STBCR);

	clear_bl_bit();
}

__attribute__((used)) static int hp6x0_pm_enter(suspend_state_t state)
{
	u8 stbcr, stbcr2;
#ifdef CONFIG_HD64461_ENABLER
	u8 scr;
	u16 hd64461_stbcr;
#endif

#ifdef CONFIG_HD64461_ENABLER
	outb(0, HD64461_PCC1CSCIER);

	scr = inb(HD64461_PCC1SCR);
	scr |= HD64461_PCCSCR_VCC1;
	outb(scr, HD64461_PCC1SCR);

	hd64461_stbcr = inw(HD64461_STBCR);
	hd64461_stbcr |= HD64461_STBCR_SPC1ST;
	outw(hd64461_stbcr, HD64461_STBCR);
#endif

	__raw_writeb(0x1f, DACR);

	stbcr = __raw_readb(STBCR);
	__raw_writeb(0x01, STBCR);

	stbcr2 = __raw_readb(STBCR2);
	__raw_writeb(0x7f , STBCR2);

	outw(0xf07f, HD64461_SCPUCR);

	pm_enter();

	outw(0, HD64461_SCPUCR);
	__raw_writeb(stbcr, STBCR);
	__raw_writeb(stbcr2, STBCR2);

#ifdef CONFIG_HD64461_ENABLER
	hd64461_stbcr = inw(HD64461_STBCR);
	hd64461_stbcr &= ~HD64461_STBCR_SPC1ST;
	outw(hd64461_stbcr, HD64461_STBCR);

	outb(0x4c, HD64461_PCC1CSCIER);
	outb(0x00, HD64461_PCC1CSCR);
#endif

	return 0;
}

