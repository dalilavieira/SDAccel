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

/* Variables and functions */
 int /*<<< orphan*/  boot_text_mapped ; 
 scalar_t__ calc_base (int /*<<< orphan*/ ,int) ; 
 int dispDeviceDepth ; 
 int* dispDeviceRect ; 
 int dispDeviceRowBytes ; 
 int /*<<< orphan*/  draw_byte (char,int /*<<< orphan*/ ,int) ; 
 scalar_t__ expand_bits_16 ; 
 scalar_t__ expand_bits_8 ; 
 scalar_t__ g_loc_X ; 
 int g_loc_Y ; 
 scalar_t__ g_max_loc_X ; 
 int g_max_loc_Y ; 
 char hex_asc_hi (unsigned long) ; 
 char hex_asc_lo (unsigned long) ; 
 int /*<<< orphan*/  scrollscreen () ; 

__attribute__((used)) static inline void rmci_maybe_on(void)
{
#if defined(CONFIG_PPC_EARLY_DEBUG_BOOTX) && defined(CONFIG_PPC64)
	if (!(mfmsr() & MSR_DR))
		rmci_on();
#endif
}

__attribute__((used)) static inline void rmci_maybe_off(void)
{
#if defined(CONFIG_PPC_EARLY_DEBUG_BOOTX) && defined(CONFIG_PPC64)
	if (!(mfmsr() & MSR_DR))
		rmci_off();
#endif
}

void btext_clearscreen(void)
{
	unsigned int *base	= (unsigned int *)calc_base(0, 0);
	unsigned long width 	= ((dispDeviceRect[2] - dispDeviceRect[0]) *
					(dispDeviceDepth >> 3)) >> 2;
	int i,j;

	rmci_maybe_on();
	for (i=0; i<(dispDeviceRect[3] - dispDeviceRect[1]); i++)
	{
		unsigned int *ptr = base;
		for(j=width; j; --j)
			*(ptr++) = 0;
		base += (dispDeviceRowBytes >> 2);
	}
	rmci_maybe_off();
}

void btext_flushscreen(void)
{
	unsigned int *base	= (unsigned int *)calc_base(0, 0);
	unsigned long width 	= ((dispDeviceRect[2] - dispDeviceRect[0]) *
					(dispDeviceDepth >> 3)) >> 2;
	int i,j;

	for (i=0; i < (dispDeviceRect[3] - dispDeviceRect[1]); i++)
	{
		unsigned int *ptr = base;
		for(j = width; j > 0; j -= 8) {
			__asm__ __volatile__ ("dcbst 0,%0" :: "r" (ptr));
			ptr += 8;
		}
		base += (dispDeviceRowBytes >> 2);
	}
	__asm__ __volatile__ ("sync" ::: "memory");
}

void btext_flushline(void)
{
	unsigned int *base	= (unsigned int *)calc_base(0, g_loc_Y << 4);
	unsigned long width 	= ((dispDeviceRect[2] - dispDeviceRect[0]) *
					(dispDeviceDepth >> 3)) >> 2;
	int i,j;

	for (i=0; i < 16; i++)
	{
		unsigned int *ptr = base;
		for(j = width; j > 0; j -= 8) {
			__asm__ __volatile__ ("dcbst 0,%0" :: "r" (ptr));
			ptr += 8;
		}
		base += (dispDeviceRowBytes >> 2);
	}
	__asm__ __volatile__ ("sync" ::: "memory");
}

__attribute__((used)) static void draw_byte_32(unsigned char *font, unsigned int *base, int rb)
{
	int l, bits;
	int fg = 0xFFFFFFFFUL;
	int bg = 0x00000000UL;

	for (l = 0; l < 16; ++l)
	{
		bits = *font++;
		base[0] = (-(bits >> 7) & fg) ^ bg;
		base[1] = (-((bits >> 6) & 1) & fg) ^ bg;
		base[2] = (-((bits >> 5) & 1) & fg) ^ bg;
		base[3] = (-((bits >> 4) & 1) & fg) ^ bg;
		base[4] = (-((bits >> 3) & 1) & fg) ^ bg;
		base[5] = (-((bits >> 2) & 1) & fg) ^ bg;
		base[6] = (-((bits >> 1) & 1) & fg) ^ bg;
		base[7] = (-(bits & 1) & fg) ^ bg;
		base = (unsigned int *) ((char *)base + rb);
	}
}

__attribute__((used)) static inline void draw_byte_16(unsigned char *font, unsigned int *base, int rb)
{
	int l, bits;
	int fg = 0xFFFFFFFFUL;
	int bg = 0x00000000UL;
	unsigned int *eb = (int *)expand_bits_16;

	for (l = 0; l < 16; ++l)
	{
		bits = *font++;
		base[0] = (eb[bits >> 6] & fg) ^ bg;
		base[1] = (eb[(bits >> 4) & 3] & fg) ^ bg;
		base[2] = (eb[(bits >> 2) & 3] & fg) ^ bg;
		base[3] = (eb[bits & 3] & fg) ^ bg;
		base = (unsigned int *) ((char *)base + rb);
	}
}

__attribute__((used)) static inline void draw_byte_8(unsigned char *font, unsigned int *base, int rb)
{
	int l, bits;
	int fg = 0x0F0F0F0FUL;
	int bg = 0x00000000UL;
	unsigned int *eb = (int *)expand_bits_8;

	for (l = 0; l < 16; ++l)
	{
		bits = *font++;
		base[0] = (eb[bits >> 4] & fg) ^ bg;
		base[1] = (eb[bits & 0xf] & fg) ^ bg;
		base = (unsigned int *) ((char *)base + rb);
	}
}

void btext_drawchar(char c)
{
	int cline = 0;
#ifdef NO_SCROLL
	int x;
#endif
	if (!boot_text_mapped)
		return;

	switch (c) {
	case '\b':
		if (g_loc_X > 0)
			--g_loc_X;
		break;
	case '\t':
		g_loc_X = (g_loc_X & -8) + 8;
		break;
	case '\r':
		g_loc_X = 0;
		break;
	case '\n':
		g_loc_X = 0;
		g_loc_Y++;
		cline = 1;
		break;
	default:
		draw_byte(c, g_loc_X++, g_loc_Y);
	}
	if (g_loc_X >= g_max_loc_X) {
		g_loc_X = 0;
		g_loc_Y++;
		cline = 1;
	}
#ifndef NO_SCROLL
	while (g_loc_Y >= g_max_loc_Y) {
		scrollscreen();
		g_loc_Y--;
	}
#else
	/* wrap around from bottom to top of screen so we don't
	   waste time scrolling each line.  -- paulus. */
	if (g_loc_Y >= g_max_loc_Y)
		g_loc_Y = 0;
	if (cline) {
		for (x = 0; x < g_max_loc_X; ++x)
			draw_byte(' ', x, g_loc_Y);
	}
#endif
}

void btext_drawstring(const char *c)
{
	if (!boot_text_mapped)
		return;
	while (*c)
		btext_drawchar(*c++);
}

void btext_drawtext(const char *c, unsigned int len)
{
	if (!boot_text_mapped)
		return;
	while (len--)
		btext_drawchar(*c++);
}

void btext_drawhex(unsigned long v)
{
	if (!boot_text_mapped)
		return;
#ifdef CONFIG_PPC64
	btext_drawchar(hex_asc_hi(v >> 56));
	btext_drawchar(hex_asc_lo(v >> 56));
	btext_drawchar(hex_asc_hi(v >> 48));
	btext_drawchar(hex_asc_lo(v >> 48));
	btext_drawchar(hex_asc_hi(v >> 40));
	btext_drawchar(hex_asc_lo(v >> 40));
	btext_drawchar(hex_asc_hi(v >> 32));
	btext_drawchar(hex_asc_lo(v >> 32));
#endif
	btext_drawchar(hex_asc_hi(v >> 24));
	btext_drawchar(hex_asc_lo(v >> 24));
	btext_drawchar(hex_asc_hi(v >> 16));
	btext_drawchar(hex_asc_lo(v >> 16));
	btext_drawchar(hex_asc_hi(v >> 8));
	btext_drawchar(hex_asc_lo(v >> 8));
	btext_drawchar(hex_asc_hi(v));
	btext_drawchar(hex_asc_lo(v));
	btext_drawchar(' ');
}

