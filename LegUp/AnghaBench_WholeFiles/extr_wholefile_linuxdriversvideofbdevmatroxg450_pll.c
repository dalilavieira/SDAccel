#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_13__ ;

/* Type definitions */
struct TYPE_21__ {unsigned long vaddr; } ;
typedef  TYPE_5__ vaddr_t ;
typedef  int u_int8_t ;
typedef  int u_int32_t ;
typedef  int /*<<< orphan*/  u_int16_t ;
struct matrox_pll_limits {unsigned int vcomin; unsigned int vcomax; } ;
struct matrox_pll_cache {scalar_t__ valid; TYPE_13__* data; } ;
struct matrox_hw_state {unsigned int* DACclk; } ;
struct TYPE_20__ {struct matrox_pll_cache video; struct matrox_pll_cache system; struct matrox_pll_cache pixel; } ;
struct TYPE_19__ {struct matrox_pll_limits video; struct matrox_pll_limits system; struct matrox_pll_limits pixel; } ;
struct TYPE_17__ {unsigned int ref_freq; } ;
struct TYPE_18__ {TYPE_1__ pll; } ;
typedef  struct matrox_fb_info {unsigned int max_pixel_clock_panellink; struct matrox_hw_state hw; TYPE_4__ cache; TYPE_3__ limits; int /*<<< orphan*/  pcidev; TYPE_2__ features; } const matrox_fb_info ;
struct TYPE_16__ {unsigned int mnp_key; unsigned int mnp_value; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (TYPE_13__*) ; 
 unsigned int DAC1064_XSYSPLLM ; 
 unsigned int DAC1064_XSYSPLLN ; 
 unsigned int DAC1064_XSYSPLLP ; 
 unsigned int DAC1064_XSYSPLLSTAT ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 unsigned int G450_MNP_FREQBITS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int M1064_XDVICLKCTRL_C1DVICLKEN ; 
 int M1064_XDVICLKCTRL_C1DVICLKSEL ; 
 int M1064_XDVICLKCTRL_DVIDATAPATHSEL ; 
 int M1064_XDVICLKCTRL_DVILOOPCTL ; 
 int M1064_XDVICLKCTRL_P1LOOPBWDTCTL ; 
 unsigned int M1064_XPIXCLKCTRL ; 
 int M1064_XPIXCLKCTRL_DIS ; 
 int M1064_XPIXCLKCTRL_PLL_UP ; 
 unsigned int M1064_XPIXPLLAM ; 
 unsigned int M1064_XPIXPLLAN ; 
 unsigned int M1064_XPIXPLLAP ; 
 unsigned int M1064_XPIXPLLBM ; 
 unsigned int M1064_XPIXPLLBN ; 
 unsigned int M1064_XPIXPLLBP ; 
 unsigned int M1064_XPIXPLLCM ; 
 unsigned int M1064_XPIXPLLCN ; 
 unsigned int M1064_XPIXPLLCP ; 
 unsigned int M1064_XPIXPLLSTAT ; 
 unsigned int M1064_XPWRCTRL ; 
 int M1064_XPWRCTRL_PANELPDN ; 
 unsigned int M1064_XVIDPLLM ; 
 unsigned int M1064_XVIDPLLN ; 
 unsigned int M1064_XVIDPLLP ; 
 unsigned int M1064_XVIDPLLSTAT ; 
 int MNP_TABLE_SIZE ; 
 int /*<<< orphan*/  M_MISC_REG ; 
 int /*<<< orphan*/  M_MISC_REG_READ ; 
#define  M_PIXEL_PLL_A 132 
#define  M_PIXEL_PLL_B 131 
#define  M_PIXEL_PLL_C 130 
 int M_SEQ1 ; 
 int M_SEQ1_SCROFF ; 
 int /*<<< orphan*/  M_SEQ_DATA ; 
 int /*<<< orphan*/  M_SEQ_INDEX ; 
#define  M_SYSTEM_PLL 129 
#define  M_VIDEO_PLL 128 
 unsigned int NO_MORE_MNP ; 
 int /*<<< orphan*/  PCI_OPTION_REG ; 
 int /*<<< orphan*/  iowrite32_rep (unsigned long,void const*,int) ; 
 int /*<<< orphan*/  kfree (unsigned int*) ; 
 unsigned int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int matroxfb_DAC_in (struct matrox_fb_info const*,unsigned int) ; 
 int /*<<< orphan*/  matroxfb_DAC_lock_irqsave (unsigned long) ; 
 int /*<<< orphan*/  matroxfb_DAC_out (struct matrox_fb_info const*,unsigned int,int) ; 
 int /*<<< orphan*/  matroxfb_DAC_unlock_irqrestore (unsigned long) ; 
 int /*<<< orphan*/  memmove (TYPE_13__*,TYPE_13__*,unsigned int) ; 
 int mga_inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mga_outb (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_read_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 unsigned int readb (unsigned long) ; 
 int readl (unsigned long) ; 
 int /*<<< orphan*/  writeb (int,unsigned long) ; 
 int /*<<< orphan*/  writel (int,unsigned long) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static inline unsigned int mga_readb(vaddr_t va, unsigned int offs) {
	return readb(va.vaddr + offs);
}

__attribute__((used)) static inline void mga_writeb(vaddr_t va, unsigned int offs, u_int8_t value) {
	writeb(value, va.vaddr + offs);
}

__attribute__((used)) static inline void mga_writew(vaddr_t va, unsigned int offs, u_int16_t value) {
	writew(value, va.vaddr + offs);
}

__attribute__((used)) static inline u_int32_t mga_readl(vaddr_t va, unsigned int offs) {
	return readl(va.vaddr + offs);
}

__attribute__((used)) static inline void mga_writel(vaddr_t va, unsigned int offs, u_int32_t value) {
	writel(value, va.vaddr + offs);
}

__attribute__((used)) static inline void mga_memcpy_toio(vaddr_t va, const void* src, int len) {
#if defined(__alpha__) || defined(__i386__) || defined(__x86_64__)
	/*
	 * iowrite32_rep works for us if:
	 *  (1) Copies data as 32bit quantities, not byte after byte,
	 *  (2) Performs LE ordered stores, and
	 *  (3) It copes with unaligned source (destination is guaranteed to be page
	 *      aligned and length is guaranteed to be multiple of 4).
	 */
	iowrite32_rep(va.vaddr, src, len >> 2);
#else
        u_int32_t __iomem* addr = va.vaddr;

	if ((unsigned long)src & 3) {
		while (len >= 4) {
			fb_writel(get_unaligned((u32 *)src), addr);
			addr++;
			len -= 4;
			src += 4;
		}
	} else {
		while (len >= 4) {
			fb_writel(*(u32 *)src, addr);
			addr++;
			len -= 4;
			src += 4;
		}
	}
#endif
}

__attribute__((used)) static inline void vaddr_add(vaddr_t* va, unsigned long offs) {
	va->vaddr += offs;
}

__attribute__((used)) static inline unsigned int g450_vco2f(unsigned char p, unsigned int fvco) {
	return (p & 0x40) ? fvco : fvco >> ((p & 3) + 1);
}

__attribute__((used)) static inline unsigned int g450_f2vco(unsigned char p, unsigned int fin) {
	return (p & 0x40) ? fin : fin << ((p & 3) + 1);
}

__attribute__((used)) static unsigned int g450_mnp2vco(const struct matrox_fb_info *minfo,
				 unsigned int mnp)
{
	unsigned int m, n;

	m = ((mnp >> 16) & 0x0FF) + 1;
	n = ((mnp >>  7) & 0x1FE) + 4;
	return (minfo->features.pll.ref_freq * n + (m >> 1)) / m;
}

unsigned int g450_mnp2f(const struct matrox_fb_info *minfo, unsigned int mnp)
{
	return g450_vco2f(mnp, g450_mnp2vco(minfo, mnp));
}

__attribute__((used)) static inline unsigned int pll_freq_delta(unsigned int f1, unsigned int f2) {
	if (f2 < f1) {
    		f2 = f1 - f2;
	} else {
		f2 = f2 - f1;
	}
	return f2;
}

__attribute__((used)) static unsigned int g450_nextpll(const struct matrox_fb_info *minfo,
				 const struct matrox_pll_limits *pi,
				 unsigned int *fvco, unsigned int mnp)
{
	unsigned int m, n, p;
	unsigned int tvco = *fvco;

	m = (mnp >> 16) & 0xFF;
	p = mnp & 0xFF;

	do {
		if (m == 0 || m == 0xFF) {
			if (m == 0) {
				if (p & 0x40) {
					return NO_MORE_MNP;
				}
			        if (p & 3) {
					p--;
				} else {
					p = 0x40;
				}
				tvco >>= 1;
				if (tvco < pi->vcomin) {
					return NO_MORE_MNP;
				}
				*fvco = tvco;
			}

			p &= 0x43;
			if (tvco < 550000) {
/*				p |= 0x00; */
			} else if (tvco < 700000) {
				p |= 0x08;
			} else if (tvco < 1000000) {
				p |= 0x10;
			} else if (tvco < 1150000) {
				p |= 0x18;
			} else {
				p |= 0x20;
			}
			m = 9;
		} else {
			m--;
		}
		n = ((tvco * (m+1) + minfo->features.pll.ref_freq) / (minfo->features.pll.ref_freq * 2)) - 2;
	} while (n < 0x03 || n > 0x7A);
	return (m << 16) | (n << 8) | p;
}

__attribute__((used)) static unsigned int g450_firstpll(const struct matrox_fb_info *minfo,
				  const struct matrox_pll_limits *pi,
				  unsigned int *vco, unsigned int fout)
{
	unsigned int p;
	unsigned int vcomax;

	vcomax = pi->vcomax;
	if (fout > (vcomax / 2)) {
		if (fout > vcomax) {
			*vco = vcomax;
		} else {
			*vco = fout;
		}
		p = 0x40;
	} else {
		unsigned int tvco;

		p = 3;
		tvco = g450_f2vco(p, fout);
		while (p && (tvco > vcomax)) {
			p--;
			tvco >>= 1;
		}
		if (tvco < pi->vcomin) {
			tvco = pi->vcomin;
		}
		*vco = tvco;
	}
	return g450_nextpll(minfo, pi, vco, 0xFF0000 | p);
}

__attribute__((used)) static inline unsigned int g450_setpll(const struct matrox_fb_info *minfo,
				       unsigned int mnp, unsigned int pll)
{
	switch (pll) {
		case M_PIXEL_PLL_A:
			matroxfb_DAC_out(minfo, M1064_XPIXPLLAM, mnp >> 16);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLAN, mnp >> 8);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLAP, mnp);
			return M1064_XPIXPLLSTAT;

		case M_PIXEL_PLL_B:
			matroxfb_DAC_out(minfo, M1064_XPIXPLLBM, mnp >> 16);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLBN, mnp >> 8);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLBP, mnp);
			return M1064_XPIXPLLSTAT;

		case M_PIXEL_PLL_C:
			matroxfb_DAC_out(minfo, M1064_XPIXPLLCM, mnp >> 16);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLCN, mnp >> 8);
			matroxfb_DAC_out(minfo, M1064_XPIXPLLCP, mnp);
			return M1064_XPIXPLLSTAT;

		case M_SYSTEM_PLL:
			matroxfb_DAC_out(minfo, DAC1064_XSYSPLLM, mnp >> 16);
			matroxfb_DAC_out(minfo, DAC1064_XSYSPLLN, mnp >> 8);
			matroxfb_DAC_out(minfo, DAC1064_XSYSPLLP, mnp);
			return DAC1064_XSYSPLLSTAT;

		case M_VIDEO_PLL:
			matroxfb_DAC_out(minfo, M1064_XVIDPLLM, mnp >> 16);
			matroxfb_DAC_out(minfo, M1064_XVIDPLLN, mnp >> 8);
			matroxfb_DAC_out(minfo, M1064_XVIDPLLP, mnp);
			return M1064_XVIDPLLSTAT;
	}
	return 0;
}

__attribute__((used)) static inline unsigned int g450_cmppll(const struct matrox_fb_info *minfo,
				       unsigned int mnp, unsigned int pll)
{
	unsigned char m = mnp >> 16;
	unsigned char n = mnp >> 8;
	unsigned char p = mnp;

	switch (pll) {
		case M_PIXEL_PLL_A:
			return (matroxfb_DAC_in(minfo, M1064_XPIXPLLAM) != m ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLAN) != n ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLAP) != p);

		case M_PIXEL_PLL_B:
			return (matroxfb_DAC_in(minfo, M1064_XPIXPLLBM) != m ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLBN) != n ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLBP) != p);

		case M_PIXEL_PLL_C:
			return (matroxfb_DAC_in(minfo, M1064_XPIXPLLCM) != m ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLCN) != n ||
				matroxfb_DAC_in(minfo, M1064_XPIXPLLCP) != p);

		case M_SYSTEM_PLL:
			return (matroxfb_DAC_in(minfo, DAC1064_XSYSPLLM) != m ||
				matroxfb_DAC_in(minfo, DAC1064_XSYSPLLN) != n ||
				matroxfb_DAC_in(minfo, DAC1064_XSYSPLLP) != p);

		case M_VIDEO_PLL:
			return (matroxfb_DAC_in(minfo, M1064_XVIDPLLM) != m ||
				matroxfb_DAC_in(minfo, M1064_XVIDPLLN) != n ||
				matroxfb_DAC_in(minfo, M1064_XVIDPLLP) != p);
	}
	return 1;
}

__attribute__((used)) static inline int g450_isplllocked(const struct matrox_fb_info *minfo,
				   unsigned int regidx)
{
	unsigned int j;

	for (j = 0; j < 1000; j++) {
		if (matroxfb_DAC_in(minfo, regidx) & 0x40) {
			unsigned int r = 0;
			int i;

			for (i = 0; i < 100; i++) {
				r += matroxfb_DAC_in(minfo, regidx) & 0x40;
			}
			return r >= (90 * 0x40);
		}
		/* udelay(1)... but DAC_in is much slower... */
	}
	return 0;
}

__attribute__((used)) static int g450_testpll(const struct matrox_fb_info *minfo, unsigned int mnp,
			unsigned int pll)
{
	return g450_isplllocked(minfo, g450_setpll(minfo, mnp, pll));
}

__attribute__((used)) static void updatehwstate_clk(struct matrox_hw_state* hw, unsigned int mnp, unsigned int pll) {
	switch (pll) {
		case M_SYSTEM_PLL:
			hw->DACclk[3] = mnp >> 16;
			hw->DACclk[4] = mnp >> 8;
			hw->DACclk[5] = mnp;
			break;
	}
}

void matroxfb_g450_setpll_cond(struct matrox_fb_info *minfo, unsigned int mnp,
			       unsigned int pll)
{
	if (g450_cmppll(minfo, mnp, pll)) {
		g450_setpll(minfo, mnp, pll);
	}
}

__attribute__((used)) static inline unsigned int g450_findworkingpll(struct matrox_fb_info *minfo,
					       unsigned int pll,
					       unsigned int *mnparray,
					       unsigned int mnpcount)
{
	unsigned int found = 0;
	unsigned int idx;
	unsigned int mnpfound = mnparray[0];
		
	for (idx = 0; idx < mnpcount; idx++) {
		unsigned int sarray[3];
		unsigned int *sptr;
		{
			unsigned int mnp;
		
			sptr = sarray;
			mnp = mnparray[idx];
			if (mnp & 0x38) {
				*sptr++ = mnp - 8;
			}
			if ((mnp & 0x38) != 0x38) {
				*sptr++ = mnp + 8;
			}
			*sptr = mnp;
		}
		while (sptr >= sarray) {
			unsigned int mnp = *sptr--;
		
			if (g450_testpll(minfo, mnp - 0x0300, pll) &&
			    g450_testpll(minfo, mnp + 0x0300, pll) &&
			    g450_testpll(minfo, mnp - 0x0200, pll) &&
			    g450_testpll(minfo, mnp + 0x0200, pll) &&
			    g450_testpll(minfo, mnp - 0x0100, pll) &&
			    g450_testpll(minfo, mnp + 0x0100, pll)) {
				if (g450_testpll(minfo, mnp, pll)) {
					return mnp;
				}
			} else if (!found && g450_testpll(minfo, mnp, pll)) {
				mnpfound = mnp;
				found = 1;
			}
		}
	}
	g450_setpll(minfo, mnpfound, pll);
	return mnpfound;
}

__attribute__((used)) static void g450_addcache(struct matrox_pll_cache* ci, unsigned int mnp_key, unsigned int mnp_value) {
	if (++ci->valid > ARRAY_SIZE(ci->data)) {
		ci->valid = ARRAY_SIZE(ci->data);
	}
	memmove(ci->data + 1, ci->data, (ci->valid - 1) * sizeof(*ci->data));
	ci->data[0].mnp_key = mnp_key & G450_MNP_FREQBITS;
	ci->data[0].mnp_value = mnp_value;
}

__attribute__((used)) static int g450_checkcache(struct matrox_fb_info *minfo,
			   struct matrox_pll_cache *ci, unsigned int mnp_key)
{
	unsigned int i;
	
	mnp_key &= G450_MNP_FREQBITS;
	for (i = 0; i < ci->valid; i++) {
		if (ci->data[i].mnp_key == mnp_key) {
			unsigned int mnp;
			
			mnp = ci->data[i].mnp_value;
			if (i) {
				memmove(ci->data + 1, ci->data, i * sizeof(*ci->data));
				ci->data[0].mnp_key = mnp_key;
				ci->data[0].mnp_value = mnp;
			}
			return mnp;
		}
	}
	return NO_MORE_MNP;
}

__attribute__((used)) static int __g450_setclk(struct matrox_fb_info *minfo, unsigned int fout,
			 unsigned int pll, unsigned int *mnparray,
			 unsigned int *deltaarray)
{
	unsigned int mnpcount;
	unsigned int pixel_vco;
	const struct matrox_pll_limits* pi;
	struct matrox_pll_cache* ci;

	pixel_vco = 0;
	switch (pll) {
		case M_PIXEL_PLL_A:
		case M_PIXEL_PLL_B:
		case M_PIXEL_PLL_C:
			{
				u_int8_t tmp, xpwrctrl;
				unsigned long flags;
				
				matroxfb_DAC_lock_irqsave(flags);

				xpwrctrl = matroxfb_DAC_in(minfo, M1064_XPWRCTRL);
				matroxfb_DAC_out(minfo, M1064_XPWRCTRL, xpwrctrl & ~M1064_XPWRCTRL_PANELPDN);
				mga_outb(M_SEQ_INDEX, M_SEQ1);
				mga_outb(M_SEQ_DATA, mga_inb(M_SEQ_DATA) | M_SEQ1_SCROFF);
				tmp = matroxfb_DAC_in(minfo, M1064_XPIXCLKCTRL);
				tmp |= M1064_XPIXCLKCTRL_DIS;
				if (!(tmp & M1064_XPIXCLKCTRL_PLL_UP)) {
					tmp |= M1064_XPIXCLKCTRL_PLL_UP;
				}
				matroxfb_DAC_out(minfo, M1064_XPIXCLKCTRL, tmp);
				/* DVI PLL preferred for frequencies up to
				   panel link max, standard PLL otherwise */
				if (fout >= minfo->max_pixel_clock_panellink)
					tmp = 0;
				else tmp =
					M1064_XDVICLKCTRL_DVIDATAPATHSEL |
					M1064_XDVICLKCTRL_C1DVICLKSEL |
					M1064_XDVICLKCTRL_C1DVICLKEN |
					M1064_XDVICLKCTRL_DVILOOPCTL |
					M1064_XDVICLKCTRL_P1LOOPBWDTCTL;
                                /* Setting this breaks PC systems so don't do it */
				/* matroxfb_DAC_out(minfo, M1064_XDVICLKCTRL, tmp); */
				matroxfb_DAC_out(minfo, M1064_XPWRCTRL,
						 xpwrctrl);

				matroxfb_DAC_unlock_irqrestore(flags);
			}
			{
				u_int8_t misc;
		
				misc = mga_inb(M_MISC_REG_READ) & ~0x0C;
				switch (pll) {
					case M_PIXEL_PLL_A:
						break;
					case M_PIXEL_PLL_B:
						misc |=  0x04;
						break;
					default:
						misc |=  0x0C;
						break;
				}
				mga_outb(M_MISC_REG, misc);
			}
			pi = &minfo->limits.pixel;
			ci = &minfo->cache.pixel;
			break;
		case M_SYSTEM_PLL:
			{
				u_int32_t opt;

				pci_read_config_dword(minfo->pcidev, PCI_OPTION_REG, &opt);
				if (!(opt & 0x20)) {
					pci_write_config_dword(minfo->pcidev, PCI_OPTION_REG, opt | 0x20);
				}
			}
			pi = &minfo->limits.system;
			ci = &minfo->cache.system;
			break;
		case M_VIDEO_PLL:
			{
				u_int8_t tmp;
				unsigned int mnp;
				unsigned long flags;
				
				matroxfb_DAC_lock_irqsave(flags);
				tmp = matroxfb_DAC_in(minfo, M1064_XPWRCTRL);
				if (!(tmp & 2)) {
					matroxfb_DAC_out(minfo, M1064_XPWRCTRL, tmp | 2);
				}
				
				mnp = matroxfb_DAC_in(minfo, M1064_XPIXPLLCM) << 16;
				mnp |= matroxfb_DAC_in(minfo, M1064_XPIXPLLCN) << 8;
				pixel_vco = g450_mnp2vco(minfo, mnp);
				matroxfb_DAC_unlock_irqrestore(flags);
			}
			pi = &minfo->limits.video;
			ci = &minfo->cache.video;
			break;
		default:
			return -EINVAL;
	}

	mnpcount = 0;
	{
		unsigned int mnp;
		unsigned int xvco;

		for (mnp = g450_firstpll(minfo, pi, &xvco, fout); mnp != NO_MORE_MNP; mnp = g450_nextpll(minfo, pi, &xvco, mnp)) {
			unsigned int idx;
			unsigned int vco;
			unsigned int delta;

			vco = g450_mnp2vco(minfo, mnp);
#if 0			
			if (pll == M_VIDEO_PLL) {
				unsigned int big, small;

				if (vco < pixel_vco) {
					small = vco;
					big = pixel_vco;
				} else {
					small = pixel_vco;
					big = vco;
				}
				while (big > small) {
					big >>= 1;
				}
				if (big == small) {
					continue;
				}
			}
#endif			
			delta = pll_freq_delta(fout, g450_vco2f(mnp, vco));
			for (idx = mnpcount; idx > 0; idx--) {
				/* == is important; due to nextpll algorithm we get
				   sorted equally good frequencies from lower VCO 
				   frequency to higher - with <= lowest wins, while
				   with < highest one wins */
				if (delta <= deltaarray[idx-1]) {
					/* all else being equal except VCO,
					 * choose VCO not near (within 1/16th or so) VCOmin
					 * (freqs near VCOmin aren't as stable)
					 */
					if (delta == deltaarray[idx-1]
					    && vco != g450_mnp2vco(minfo, mnparray[idx-1])
					    && vco < (pi->vcomin * 17 / 16)) {
						break;
					}
					mnparray[idx] = mnparray[idx-1];
					deltaarray[idx] = deltaarray[idx-1];
				} else {
					break;
				}
			}
			mnparray[idx] = mnp;
			deltaarray[idx] = delta;
			mnpcount++;
		}
	}
	/* VideoPLL and PixelPLL matched: do nothing... In all other cases we should get at least one frequency */
	if (!mnpcount) {
		return -EBUSY;
	}
	{
		unsigned long flags;
		unsigned int mnp;
		
		matroxfb_DAC_lock_irqsave(flags);
		mnp = g450_checkcache(minfo, ci, mnparray[0]);
		if (mnp != NO_MORE_MNP) {
			matroxfb_g450_setpll_cond(minfo, mnp, pll);
		} else {
			mnp = g450_findworkingpll(minfo, pll, mnparray, mnpcount);
			g450_addcache(ci, mnparray[0], mnp);
		}
		updatehwstate_clk(&minfo->hw, mnp, pll);
		matroxfb_DAC_unlock_irqrestore(flags);
		return mnp;
	}
}

int matroxfb_g450_setclk(struct matrox_fb_info *minfo, unsigned int fout,
			 unsigned int pll)
{
	unsigned int* arr;
	
	arr = kmalloc(sizeof(*arr) * MNP_TABLE_SIZE * 2, GFP_KERNEL);
	if (arr) {
		int r;

		r = __g450_setclk(minfo, fout, pll, arr, arr + MNP_TABLE_SIZE);
		kfree(arr);
		return r;
	}
	return -ENOMEM;
}

