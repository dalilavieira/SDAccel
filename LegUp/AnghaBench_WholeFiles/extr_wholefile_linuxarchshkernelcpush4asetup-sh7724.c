#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct notifier_block {int dummy; } ;
struct TYPE_2__ {int mmselr; int cs0bcr; int cs4bcr; int cs5abcr; int cs5bbcr; int cs6abcr; int cs6bbcr; int cs4wcr; int cs5awcr; int cs5bwcr; int cs6awcr; int cs6bwcr; int ipra; int iprb; int iprc; int iprd; int ipre; int iprf; int iprg; int iprh; int ipri; int iprj; int iprk; int iprl; int rwtcnt; int rwtcsr; int irdaclk; int spuclk; void* imr12; void* imr11; void* imr10; void* imr9; void* imr8; void* imr7; void* imr6; void* imr5; void* imr4; void* imr3; void* imr2; void* imr1; void* imr0; } ;

/* Variables and functions */
 int NOTIFY_DONE ; 
 unsigned long SUSP_SH_RSTANDBY ; 
 void* __raw_readb (int) ; 
 void* __raw_readl (int) ; 
 void* __raw_readw (int) ; 
 int /*<<< orphan*/  __raw_writeb (void*,int) ; 
 int /*<<< orphan*/  __raw_writel (int,int) ; 
 int /*<<< orphan*/  __raw_writew (int,int) ; 
 TYPE_1__ sh7724_rstandby_state ; 

__attribute__((used)) static int sh7724_pre_sleep_notifier_call(struct notifier_block *nb,
					  unsigned long flags, void *unused)
{
	if (!(flags & SUSP_SH_RSTANDBY))
		return NOTIFY_DONE;

	/* BCR */
	sh7724_rstandby_state.mmselr = __raw_readl(0xff800020); /* MMSELR */
	sh7724_rstandby_state.mmselr |= 0xa5a50000;
	sh7724_rstandby_state.cs0bcr = __raw_readl(0xfec10004); /* CS0BCR */
	sh7724_rstandby_state.cs4bcr = __raw_readl(0xfec10010); /* CS4BCR */
	sh7724_rstandby_state.cs5abcr = __raw_readl(0xfec10014); /* CS5ABCR */
	sh7724_rstandby_state.cs5bbcr = __raw_readl(0xfec10018); /* CS5BBCR */
	sh7724_rstandby_state.cs6abcr = __raw_readl(0xfec1001c); /* CS6ABCR */
	sh7724_rstandby_state.cs6bbcr = __raw_readl(0xfec10020); /* CS6BBCR */
	sh7724_rstandby_state.cs4wcr = __raw_readl(0xfec10030); /* CS4WCR */
	sh7724_rstandby_state.cs5awcr = __raw_readl(0xfec10034); /* CS5AWCR */
	sh7724_rstandby_state.cs5bwcr = __raw_readl(0xfec10038); /* CS5BWCR */
	sh7724_rstandby_state.cs6awcr = __raw_readl(0xfec1003c); /* CS6AWCR */
	sh7724_rstandby_state.cs6bwcr = __raw_readl(0xfec10040); /* CS6BWCR */

	/* INTC */
	sh7724_rstandby_state.ipra = __raw_readw(0xa4080000); /* IPRA */
	sh7724_rstandby_state.iprb = __raw_readw(0xa4080004); /* IPRB */
	sh7724_rstandby_state.iprc = __raw_readw(0xa4080008); /* IPRC */
	sh7724_rstandby_state.iprd = __raw_readw(0xa408000c); /* IPRD */
	sh7724_rstandby_state.ipre = __raw_readw(0xa4080010); /* IPRE */
	sh7724_rstandby_state.iprf = __raw_readw(0xa4080014); /* IPRF */
	sh7724_rstandby_state.iprg = __raw_readw(0xa4080018); /* IPRG */
	sh7724_rstandby_state.iprh = __raw_readw(0xa408001c); /* IPRH */
	sh7724_rstandby_state.ipri = __raw_readw(0xa4080020); /* IPRI */
	sh7724_rstandby_state.iprj = __raw_readw(0xa4080024); /* IPRJ */
	sh7724_rstandby_state.iprk = __raw_readw(0xa4080028); /* IPRK */
	sh7724_rstandby_state.iprl = __raw_readw(0xa408002c); /* IPRL */
	sh7724_rstandby_state.imr0 = __raw_readb(0xa4080080); /* IMR0 */
	sh7724_rstandby_state.imr1 = __raw_readb(0xa4080084); /* IMR1 */
	sh7724_rstandby_state.imr2 = __raw_readb(0xa4080088); /* IMR2 */
	sh7724_rstandby_state.imr3 = __raw_readb(0xa408008c); /* IMR3 */
	sh7724_rstandby_state.imr4 = __raw_readb(0xa4080090); /* IMR4 */
	sh7724_rstandby_state.imr5 = __raw_readb(0xa4080094); /* IMR5 */
	sh7724_rstandby_state.imr6 = __raw_readb(0xa4080098); /* IMR6 */
	sh7724_rstandby_state.imr7 = __raw_readb(0xa408009c); /* IMR7 */
	sh7724_rstandby_state.imr8 = __raw_readb(0xa40800a0); /* IMR8 */
	sh7724_rstandby_state.imr9 = __raw_readb(0xa40800a4); /* IMR9 */
	sh7724_rstandby_state.imr10 = __raw_readb(0xa40800a8); /* IMR10 */
	sh7724_rstandby_state.imr11 = __raw_readb(0xa40800ac); /* IMR11 */
	sh7724_rstandby_state.imr12 = __raw_readb(0xa40800b0); /* IMR12 */

	/* RWDT */
	sh7724_rstandby_state.rwtcnt = __raw_readb(0xa4520000); /* RWTCNT */
	sh7724_rstandby_state.rwtcnt |= 0x5a00;
	sh7724_rstandby_state.rwtcsr = __raw_readb(0xa4520004); /* RWTCSR */
	sh7724_rstandby_state.rwtcsr |= 0xa500;
	__raw_writew(sh7724_rstandby_state.rwtcsr & 0x07, 0xa4520004);

	/* CPG */
	sh7724_rstandby_state.irdaclk = __raw_readl(0xa4150018); /* IRDACLKCR */
	sh7724_rstandby_state.spuclk = __raw_readl(0xa415003c); /* SPUCLKCR */

	return NOTIFY_DONE;
}

__attribute__((used)) static int sh7724_post_sleep_notifier_call(struct notifier_block *nb,
					   unsigned long flags, void *unused)
{
	if (!(flags & SUSP_SH_RSTANDBY))
		return NOTIFY_DONE;

	/* BCR */
	__raw_writel(sh7724_rstandby_state.mmselr, 0xff800020); /* MMSELR */
	__raw_writel(sh7724_rstandby_state.cs0bcr, 0xfec10004); /* CS0BCR */
	__raw_writel(sh7724_rstandby_state.cs4bcr, 0xfec10010); /* CS4BCR */
	__raw_writel(sh7724_rstandby_state.cs5abcr, 0xfec10014); /* CS5ABCR */
	__raw_writel(sh7724_rstandby_state.cs5bbcr, 0xfec10018); /* CS5BBCR */
	__raw_writel(sh7724_rstandby_state.cs6abcr, 0xfec1001c); /* CS6ABCR */
	__raw_writel(sh7724_rstandby_state.cs6bbcr, 0xfec10020); /* CS6BBCR */
	__raw_writel(sh7724_rstandby_state.cs4wcr, 0xfec10030); /* CS4WCR */
	__raw_writel(sh7724_rstandby_state.cs5awcr, 0xfec10034); /* CS5AWCR */
	__raw_writel(sh7724_rstandby_state.cs5bwcr, 0xfec10038); /* CS5BWCR */
	__raw_writel(sh7724_rstandby_state.cs6awcr, 0xfec1003c); /* CS6AWCR */
	__raw_writel(sh7724_rstandby_state.cs6bwcr, 0xfec10040); /* CS6BWCR */

	/* INTC */
	__raw_writew(sh7724_rstandby_state.ipra, 0xa4080000); /* IPRA */
	__raw_writew(sh7724_rstandby_state.iprb, 0xa4080004); /* IPRB */
	__raw_writew(sh7724_rstandby_state.iprc, 0xa4080008); /* IPRC */
	__raw_writew(sh7724_rstandby_state.iprd, 0xa408000c); /* IPRD */
	__raw_writew(sh7724_rstandby_state.ipre, 0xa4080010); /* IPRE */
	__raw_writew(sh7724_rstandby_state.iprf, 0xa4080014); /* IPRF */
	__raw_writew(sh7724_rstandby_state.iprg, 0xa4080018); /* IPRG */
	__raw_writew(sh7724_rstandby_state.iprh, 0xa408001c); /* IPRH */
	__raw_writew(sh7724_rstandby_state.ipri, 0xa4080020); /* IPRI */
	__raw_writew(sh7724_rstandby_state.iprj, 0xa4080024); /* IPRJ */
	__raw_writew(sh7724_rstandby_state.iprk, 0xa4080028); /* IPRK */
	__raw_writew(sh7724_rstandby_state.iprl, 0xa408002c); /* IPRL */
	__raw_writeb(sh7724_rstandby_state.imr0, 0xa4080080); /* IMR0 */
	__raw_writeb(sh7724_rstandby_state.imr1, 0xa4080084); /* IMR1 */
	__raw_writeb(sh7724_rstandby_state.imr2, 0xa4080088); /* IMR2 */
	__raw_writeb(sh7724_rstandby_state.imr3, 0xa408008c); /* IMR3 */
	__raw_writeb(sh7724_rstandby_state.imr4, 0xa4080090); /* IMR4 */
	__raw_writeb(sh7724_rstandby_state.imr5, 0xa4080094); /* IMR5 */
	__raw_writeb(sh7724_rstandby_state.imr6, 0xa4080098); /* IMR6 */
	__raw_writeb(sh7724_rstandby_state.imr7, 0xa408009c); /* IMR7 */
	__raw_writeb(sh7724_rstandby_state.imr8, 0xa40800a0); /* IMR8 */
	__raw_writeb(sh7724_rstandby_state.imr9, 0xa40800a4); /* IMR9 */
	__raw_writeb(sh7724_rstandby_state.imr10, 0xa40800a8); /* IMR10 */
	__raw_writeb(sh7724_rstandby_state.imr11, 0xa40800ac); /* IMR11 */
	__raw_writeb(sh7724_rstandby_state.imr12, 0xa40800b0); /* IMR12 */

	/* RWDT */
	__raw_writew(sh7724_rstandby_state.rwtcnt, 0xa4520000); /* RWTCNT */
	__raw_writew(sh7724_rstandby_state.rwtcsr, 0xa4520004); /* RWTCSR */

	/* CPG */
	__raw_writel(sh7724_rstandby_state.irdaclk, 0xa4150018); /* IRDACLKCR */
	__raw_writel(sh7724_rstandby_state.spuclk, 0xa415003c); /* SPUCLKCR */

	return NOTIFY_DONE;
}

