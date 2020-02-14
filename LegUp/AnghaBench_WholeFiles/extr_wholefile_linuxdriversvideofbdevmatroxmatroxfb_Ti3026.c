#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {unsigned long vaddr; } ;
typedef  TYPE_2__ vaddr_t ;
typedef  int /*<<< orphan*/  u_int8_t ;
typedef  int /*<<< orphan*/  u_int32_t ;
typedef  int /*<<< orphan*/  u_int16_t ;
struct TYPE_10__ {int /*<<< orphan*/  pll; } ;
struct matrox_fb_info {TYPE_1__ features; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32_rep (unsigned long,void const*,int) ; 
 int matroxfb_PLL_calcclock (int /*<<< orphan*/ *,unsigned int,unsigned int,unsigned int*,unsigned int*,unsigned int*) ; 
 unsigned int readb (unsigned long) ; 
 int /*<<< orphan*/  readl (unsigned long) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,unsigned long) ; 
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

__attribute__((used)) static inline int PLL_calcclock(const struct matrox_fb_info *minfo,
				unsigned int freq, unsigned int fmax,
				unsigned int *in, unsigned int *feed,
				unsigned int *post)
{
	return matroxfb_PLL_calcclock(&minfo->features.pll, freq, fmax, in, feed, post);
}

