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
struct cpuinfo_x86 {char* x86_model_id; unsigned char x86_model; unsigned char x86_stepping; int x86_cache_size; int cpuid_level; int x86; char* x86_vendor_id; int /*<<< orphan*/  x86_vendor; int /*<<< orphan*/  loops_per_jiffy; } ;

/* Variables and functions */
 int CX86_CCR2 ; 
 int CX86_CCR3 ; 
 int CX86_CCR4 ; 
 int CX86_CCR5 ; 
 int CX86_CCR7 ; 
 int CX86_DIR0 ; 
 int CX86_DIR1 ; 
 int CX86_PCR0 ; 
 char** Cx486D_name ; 
 char** Cx486S_name ; 
 char** Cx486_name ; 
 char* Cx86_cb ; 
 int Cx86_dir0_msb ; 
 char** Cx86_model ; 
 int /*<<< orphan*/  X86_BUG_COMA ; 
 int X86_CR0_NW ; 
 int /*<<< orphan*/  X86_FEATURE_CXMMX ; 
 int /*<<< orphan*/  X86_FEATURE_CYRIX_ARR ; 
 int /*<<< orphan*/  X86_FEATURE_FPU ; 
 int /*<<< orphan*/  X86_VENDOR_CYRIX ; 
 int /*<<< orphan*/  boot_cpu_has (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  calibrate_delay () ; 
 int /*<<< orphan*/  clear_cpu_cap (struct cpuinfo_x86*,int) ; 
 int /*<<< orphan*/  cpu_detect_cache_sizes (struct cpuinfo_x86*) ; 
 char* cyrix_model_mult1 ; 
 char* cyrix_model_mult2 ; 
 int getCx86 (int) ; 
 int getCx86_old (int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  loops_per_jiffy ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int read_cr0 () ; 
 int /*<<< orphan*/  setCx86 (int,unsigned char) ; 
 int /*<<< orphan*/  setCx86_old (int,int) ; 
 int /*<<< orphan*/  set_cpu_bug (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_cpu_cap (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ test_cpu_cap (struct cpuinfo_x86*,int) ; 
 int /*<<< orphan*/  write_cr0 (int) ; 

__attribute__((used)) static void __do_cyrix_devid(unsigned char *dir0, unsigned char *dir1)
{
	unsigned char ccr2, ccr3;

	/* we test for DEVID by checking whether CCR3 is writable */
	ccr3 = getCx86(CX86_CCR3);
	setCx86(CX86_CCR3, ccr3 ^ 0x80);
	getCx86(0xc0);   /* dummy to change bus */

	if (getCx86(CX86_CCR3) == ccr3) {       /* no DEVID regs. */
		ccr2 = getCx86(CX86_CCR2);
		setCx86(CX86_CCR2, ccr2 ^ 0x04);
		getCx86(0xc0);  /* dummy */

		if (getCx86(CX86_CCR2) == ccr2) /* old Cx486SLC/DLC */
			*dir0 = 0xfd;
		else {                          /* Cx486S A step */
			setCx86(CX86_CCR2, ccr2);
			*dir0 = 0xfe;
		}
	} else {
		setCx86(CX86_CCR3, ccr3);  /* restore CCR3 */

		/* read DIR0 and DIR1 CPU registers */
		*dir0 = getCx86(CX86_DIR0);
		*dir1 = getCx86(CX86_DIR1);
	}
}

__attribute__((used)) static void do_cyrix_devid(unsigned char *dir0, unsigned char *dir1)
{
	unsigned long flags;

	local_irq_save(flags);
	__do_cyrix_devid(dir0, dir1);
	local_irq_restore(flags);
}

__attribute__((used)) static void check_cx686_slop(struct cpuinfo_x86 *c)
{
	unsigned long flags;

	if (Cx86_dir0_msb == 3) {
		unsigned char ccr3, ccr5;

		local_irq_save(flags);
		ccr3 = getCx86(CX86_CCR3);
		setCx86(CX86_CCR3, (ccr3 & 0x0f) | 0x10); /* enable MAPEN */
		ccr5 = getCx86(CX86_CCR5);
		if (ccr5 & 2)
			setCx86(CX86_CCR5, ccr5 & 0xfd);  /* reset SLOP */
		setCx86(CX86_CCR3, ccr3);                 /* disable MAPEN */
		local_irq_restore(flags);

		if (ccr5 & 2) { /* possible wrong calibration done */
			pr_info("Recalibrating delay loop with SLOP bit reset\n");
			calibrate_delay();
			c->loops_per_jiffy = loops_per_jiffy;
		}
	}
}

__attribute__((used)) static void set_cx86_reorder(void)
{
	u8 ccr3;

	pr_info("Enable Memory access reorder on Cyrix/NSC processor.\n");
	ccr3 = getCx86(CX86_CCR3);
	setCx86(CX86_CCR3, (ccr3 & 0x0f) | 0x10); /* enable MAPEN */

	/* Load/Store Serialize to mem access disable (=reorder it) */
	setCx86(CX86_PCR0, getCx86(CX86_PCR0) & ~0x80);
	/* set load/store serialize from 1GB to 4GB */
	ccr3 |= 0xe0;
	setCx86(CX86_CCR3, ccr3);
}

__attribute__((used)) static void set_cx86_memwb(void)
{
	pr_info("Enable Memory-Write-back mode on Cyrix/NSC processor.\n");

	/* CCR2 bit 2: unlock NW bit */
	setCx86(CX86_CCR2, getCx86(CX86_CCR2) & ~0x04);
	/* set 'Not Write-through' */
	write_cr0(read_cr0() | X86_CR0_NW);
	/* CCR2 bit 2: lock NW bit and set WT1 */
	setCx86(CX86_CCR2, getCx86(CX86_CCR2) | 0x14);
}

__attribute__((used)) static void geode_configure(void)
{
	unsigned long flags;
	u8 ccr3;
	local_irq_save(flags);

	/* Suspend on halt power saving and enable #SUSP pin */
	setCx86(CX86_CCR2, getCx86(CX86_CCR2) | 0x88);

	ccr3 = getCx86(CX86_CCR3);
	setCx86(CX86_CCR3, (ccr3 & 0x0f) | 0x10);	/* enable MAPEN */


	/* FPU fast, DTE cache, Mem bypass */
	setCx86(CX86_CCR4, getCx86(CX86_CCR4) | 0x38);
	setCx86(CX86_CCR3, ccr3);			/* disable MAPEN */

	set_cx86_memwb();
	set_cx86_reorder();

	local_irq_restore(flags);
}

__attribute__((used)) static void early_init_cyrix(struct cpuinfo_x86 *c)
{
	unsigned char dir0, dir0_msn, dir1 = 0;

	__do_cyrix_devid(&dir0, &dir1);
	dir0_msn = dir0 >> 4; /* identifies CPU "family"   */

	switch (dir0_msn) {
	case 3: /* 6x86/6x86L */
		/* Emulate MTRRs using Cyrix's ARRs. */
		set_cpu_cap(c, X86_FEATURE_CYRIX_ARR);
		break;
	case 5: /* 6x86MX/M II */
		/* Emulate MTRRs using Cyrix's ARRs. */
		set_cpu_cap(c, X86_FEATURE_CYRIX_ARR);
		break;
	}
}

__attribute__((used)) static void init_cyrix(struct cpuinfo_x86 *c)
{
	unsigned char dir0, dir0_msn, dir0_lsn, dir1 = 0;
	char *buf = c->x86_model_id;
	const char *p = NULL;

	/*
	 * Bit 31 in normal CPUID used for nonstandard 3DNow ID;
	 * 3DNow is IDd by bit 31 in extended CPUID (1*32+31) anyway
	 */
	clear_cpu_cap(c, 0*32+31);

	/* Cyrix used bit 24 in extended (AMD) CPUID for Cyrix MMX extensions */
	if (test_cpu_cap(c, 1*32+24)) {
		clear_cpu_cap(c, 1*32+24);
		set_cpu_cap(c, X86_FEATURE_CXMMX);
	}

	do_cyrix_devid(&dir0, &dir1);

	check_cx686_slop(c);

	Cx86_dir0_msb = dir0_msn = dir0 >> 4; /* identifies CPU "family"   */
	dir0_lsn = dir0 & 0xf;                /* model or clock multiplier */

	/* common case step number/rev -- exceptions handled below */
	c->x86_model = (dir1 >> 4) + 1;
	c->x86_stepping = dir1 & 0xf;

	/* Now cook; the original recipe is by Channing Corn, from Cyrix.
	 * We do the same thing for each generation: we work out
	 * the model, multiplier and stepping.  Black magic included,
	 * to make the silicon step/rev numbers match the printed ones.
	 */

	switch (dir0_msn) {
		unsigned char tmp;

	case 0: /* Cx486SLC/DLC/SRx/DRx */
		p = Cx486_name[dir0_lsn & 7];
		break;

	case 1: /* Cx486S/DX/DX2/DX4 */
		p = (dir0_lsn & 8) ? Cx486D_name[dir0_lsn & 5]
			: Cx486S_name[dir0_lsn & 3];
		break;

	case 2: /* 5x86 */
		Cx86_cb[2] = cyrix_model_mult1[dir0_lsn & 5];
		p = Cx86_cb+2;
		break;

	case 3: /* 6x86/6x86L */
		Cx86_cb[1] = ' ';
		Cx86_cb[2] = cyrix_model_mult1[dir0_lsn & 5];
		if (dir1 > 0x21) { /* 686L */
			Cx86_cb[0] = 'L';
			p = Cx86_cb;
			(c->x86_model)++;
		} else             /* 686 */
			p = Cx86_cb+1;
		/* Emulate MTRRs using Cyrix's ARRs. */
		set_cpu_cap(c, X86_FEATURE_CYRIX_ARR);
		/* 6x86's contain this bug */
		set_cpu_bug(c, X86_BUG_COMA);
		break;

	case 4: /* MediaGX/GXm or Geode GXM/GXLV/GX1 */
	case 11: /* GX1 with inverted Device ID */
#ifdef CONFIG_PCI
	{
		u32 vendor, device;
		/*
		 * It isn't really a PCI quirk directly, but the cure is the
		 * same. The MediaGX has deep magic SMM stuff that handles the
		 * SB emulation. It throws away the fifo on disable_dma() which
		 * is wrong and ruins the audio.
		 *
		 *  Bug2: VSA1 has a wrap bug so that using maximum sized DMA
		 *  causes bad things. According to NatSemi VSA2 has another
		 *  bug to do with 'hlt'. I've not seen any boards using VSA2
		 *  and X doesn't seem to support it either so who cares 8).
		 *  VSA1 we work around however.
		 */

		pr_info("Working around Cyrix MediaGX virtual DMA bugs.\n");
		isa_dma_bridge_buggy = 2;

		/* We do this before the PCI layer is running. However we
		   are safe here as we know the bridge must be a Cyrix
		   companion and must be present */
		vendor = read_pci_config_16(0, 0, 0x12, PCI_VENDOR_ID);
		device = read_pci_config_16(0, 0, 0x12, PCI_DEVICE_ID);

		/*
		 *  The 5510/5520 companion chips have a funky PIT.
		 */
		if (vendor == PCI_VENDOR_ID_CYRIX &&
			(device == PCI_DEVICE_ID_CYRIX_5510 ||
					device == PCI_DEVICE_ID_CYRIX_5520))
			mark_tsc_unstable("cyrix 5510/5520 detected");
	}
#endif
		c->x86_cache_size = 16;	/* Yep 16K integrated cache thats it */

		/* GXm supports extended cpuid levels 'ala' AMD */
		if (c->cpuid_level == 2) {
			/* Enable cxMMX extensions (GX1 Datasheet 54) */
			setCx86(CX86_CCR7, getCx86(CX86_CCR7) | 1);

			/*
			 * GXm : 0x30 ... 0x5f GXm  datasheet 51
			 * GXlv: 0x6x          GXlv datasheet 54
			 *  ?  : 0x7x
			 * GX1 : 0x8x          GX1  datasheet 56
			 */
			if ((0x30 <= dir1 && dir1 <= 0x6f) ||
					(0x80 <= dir1 && dir1 <= 0x8f))
				geode_configure();
			return;
		} else { /* MediaGX */
			Cx86_cb[2] = (dir0_lsn & 1) ? '3' : '4';
			p = Cx86_cb+2;
			c->x86_model = (dir1 & 0x20) ? 1 : 2;
		}
		break;

	case 5: /* 6x86MX/M II */
		if (dir1 > 7) {
			dir0_msn++;  /* M II */
			/* Enable MMX extensions (App note 108) */
			setCx86(CX86_CCR7, getCx86(CX86_CCR7)|1);
		} else {
			/* A 6x86MX - it has the bug. */
			set_cpu_bug(c, X86_BUG_COMA);
		}
		tmp = (!(dir0_lsn & 7) || dir0_lsn & 1) ? 2 : 0;
		Cx86_cb[tmp] = cyrix_model_mult2[dir0_lsn & 7];
		p = Cx86_cb+tmp;
		if (((dir1 & 0x0f) > 4) || ((dir1 & 0xf0) == 0x20))
			(c->x86_model)++;
		/* Emulate MTRRs using Cyrix's ARRs. */
		set_cpu_cap(c, X86_FEATURE_CYRIX_ARR);
		break;

	case 0xf:  /* Cyrix 486 without DEVID registers */
		switch (dir0_lsn) {
		case 0xd:  /* either a 486SLC or DLC w/o DEVID */
			dir0_msn = 0;
			p = Cx486_name[!!boot_cpu_has(X86_FEATURE_FPU)];
			break;

		case 0xe:  /* a 486S A step */
			dir0_msn = 0;
			p = Cx486S_name[0];
			break;
		}
		break;

	default:  /* unknown (shouldn't happen, we know everyone ;-) */
		dir0_msn = 7;
		break;
	}
	strcpy(buf, Cx86_model[dir0_msn & 7]);
	if (p)
		strcat(buf, p);
	return;
}

__attribute__((used)) static void init_nsc(struct cpuinfo_x86 *c)
{
	/*
	 * There may be GX1 processors in the wild that are branded
	 * NSC and not Cyrix.
	 *
	 * This function only handles the GX processor, and kicks every
	 * thing else to the Cyrix init function above - that should
	 * cover any processors that might have been branded differently
	 * after NSC acquired Cyrix.
	 *
	 * If this breaks your GX1 horribly, please e-mail
	 * info-linux@ldcmail.amd.com to tell us.
	 */

	/* Handle the GX (Formally known as the GX2) */

	if (c->x86 == 5 && c->x86_model == 5)
		cpu_detect_cache_sizes(c);
	else
		init_cyrix(c);
}

__attribute__((used)) static inline int test_cyrix_52div(void)
{
	unsigned int test;

	__asm__ __volatile__(
	     "sahf\n\t"		/* clear flags (%eax = 0x0005) */
	     "div %b2\n\t"	/* divide 5 by 2 */
	     "lahf"		/* store flags into %ah */
	     : "=a" (test)
	     : "0" (5), "q" (2)
	     : "cc");

	/* AH is 0x02 on Cyrix after the divide.. */
	return (unsigned char) (test >> 8) == 0x02;
}

__attribute__((used)) static void cyrix_identify(struct cpuinfo_x86 *c)
{
	/* Detect Cyrix with disabled CPUID */
	if (c->x86 == 4 && test_cyrix_52div()) {
		unsigned char dir0, dir1;

		strcpy(c->x86_vendor_id, "CyrixInstead");
		c->x86_vendor = X86_VENDOR_CYRIX;

		/* Actually enable cpuid on the older cyrix */

		/* Retrieve CPU revisions */

		do_cyrix_devid(&dir0, &dir1);

		dir0 >>= 4;

		/* Check it is an affected model */

		if (dir0 == 5 || dir0 == 3) {
			unsigned char ccr3;
			unsigned long flags;
			pr_info("Enabling CPUID on Cyrix processor.\n");
			local_irq_save(flags);
			ccr3 = getCx86(CX86_CCR3);
			/* enable MAPEN  */
			setCx86(CX86_CCR3, (ccr3 & 0x0f) | 0x10);
			/* enable cpuid  */
			setCx86_old(CX86_CCR4, getCx86_old(CX86_CCR4) | 0x80);
			/* disable MAPEN */
			setCx86(CX86_CCR3, ccr3);
			local_irq_restore(flags);
		}
	}
}

