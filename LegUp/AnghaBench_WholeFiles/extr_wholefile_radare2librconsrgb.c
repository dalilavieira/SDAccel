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
typedef  scalar_t__ ut8 ;
typedef  int ut32 ;
typedef  int RConsColorMode ;

/* Variables and functions */
 scalar_t__ ALPHA_BG ; 
#define  COLOR_MODE_16 130 
#define  COLOR_MODE_16M 129 
#define  COLOR_MODE_256 128 
 int R_DIM (int,int /*<<< orphan*/ ,int) ; 
 int* color_table ; 
 int snprintf (char*,size_t,char*,scalar_t__,...) ; 
 int* value_range ; 

__attribute__((used)) static void init_color_table() {
	int i, r, g, b;
	// ansi colors
	color_table[0] = 0x000000;
	color_table[1] = 0x800000;
	color_table[2] = 0x008000;
	color_table[3] = 0x808000;
	color_table[4] = 0x000080;
	color_table[5] = 0x800080;
	color_table[6] = 0x008080;
	color_table[7] = 0xc0c0c0;
	color_table[8] = 0x808080;
	color_table[9] = 0xff0000;
	color_table[10] = 0x00ff00;
	color_table[11] = 0xffff00;
	color_table[12] = 0x0000ff;
	color_table[13] = 0xff00ff;
	color_table[14] = 0x00ffff;
	color_table[15] = 0xffffff;
	// color palette
	for (i = 0; i < 216; i++) {
		r = value_range[(i / 36) % 6];
		g = value_range[(i / 6) % 6];
		b = value_range[i % 6];
		color_table[i + 16] = ((r << 16) & 0xffffff) +
			((g << 8) & 0xffff) + (b & 0xff);
	}
	// grayscale
	for (i = 0; i < 24; i++) {
		r = 8 + (i * 10);
		color_table[i + 232] = ((r << 16) & 0xffffff) +
			((r << 8) & 0xffff) + (r & 0xff);
	}
}

__attribute__((used)) static int lookup_rgb(int r, int g, int b) {
	int i, color = (r << 16) + (g << 8) + b;
	// lookup extended colors only, coz non-extended can be changed by users.
	for (i = 16; i < 256; ++i) {
		if (color_table[i] == color) {
			return i;
		}
	}
	return -1;
}

__attribute__((used)) static ut32 approximate_rgb(int r, int g, int b) {
	bool grey = (r > 0 && r < 255 && r == g && r == b);
	if (grey) {
		return 232 + (int)((double)r / (255 / 24.1));
	}
#if 0
	const double M = 16;
	double R = r;
	double G = g;
	double B = b;
	R = R /256 * 216;
	R /= 256 * 216;
	R /= 256 * 216;
	r = R = R_DIM (R / 16, 0, 16);
	g = G = R_DIM (G / 16, 0, 16);
	b = B = R_DIM (B / 16, 0, 16);
	r &= 0xff;
	g &= 0xff;
	b &= 0xff;
	return (ut32)((G * M * M)  + (g * M) + b) + 16;
#else
	const int k = (256.0 / 6);
	r = R_DIM (r / k, 0, 6);
	g = R_DIM (g / k, 0, 6);
	b = R_DIM (b / k, 0, 6);
	return 16 + (r * 36) + (g * 6) + b;
#endif
}

__attribute__((used)) static int rgb(int r, int g, int b) {
	int c = lookup_rgb (r, g, b);
	if (c == -1) {
		return approximate_rgb (r, g, b);
	}
	return c;
}

__attribute__((used)) static void unrgb(int color, int *r, int *g, int *b) {
	if (color < 0 || color > 256) {
		*r = *g = *b = 0;
		return;
	}
	int rgb = color_table[color];
	*r = (rgb >> 16) & 0xff;
	*g = (rgb >> 8) & 0xff;
	*b = rgb & 0xff;
}

__attribute__((used)) static void r_cons_rgb_gen(RConsColorMode mode, char *outstr, size_t sz, ut8 attr, ut8 a, ut8 r, ut8 g, ut8 b) {
	ut8 fgbg = (a == ALPHA_BG)? 48: 38; // ANSI codes for Background/Foreground

	if (sz < 4) { // must have at least room for "<esc>[m\0"
		if (sz > 0) {
			outstr[0] = '\0';
		}
		return;
	}

	size_t i = 2;
	outstr[0] = '\x1b';
	outstr[1] = '[';
	for (; attr; attr &= attr - 1) {
		if (sz < i + 4) { // must have at least room for e.g. "1;m\0"
			outstr[0] = '\0';
			return;
		}
		switch (attr & -attr) {
		case 1u << 1: outstr[i] = '1'; break;
		case 1u << 2: outstr[i] = '2'; break;
		case 1u << 3: outstr[i] = '3'; break;
		case 1u << 4: outstr[i] = '4'; break;
		case 1u << 5: outstr[i] = '5'; break;
		}
		outstr[i + 1] = ';';
		i += 2;
	}

	int written = -1;
	switch (mode) {
	case COLOR_MODE_256: // 256 color palette
		written = snprintf (outstr + i, sz - i, "%d;5;%dm", fgbg, rgb (r, g, b));
		break;
	case COLOR_MODE_16M: // 16M (truecolor)
		written = snprintf (outstr + i, sz - i, "%d;2;%d;%d;%dm", fgbg, r, g, b);
		break;
	case COLOR_MODE_16: // ansi 16 colors
		{
		fgbg -= 8;
		if (r == g && g == b) {
			r = (r > 0x7f) ? 1 : 0;
			g = (g > 0x7f) ? 1 : 0;
			b = (b > 0x7f) ? 1 : 0;
		} else {
			ut8 k = (r + g + b) / 3;
			r = (r >= k) ? 1 : 0;
			g = (g >= k) ? 1 : 0;
			b = (b >= k) ? 1 : 0;
		}
		ut8 c = (r ? 1 : 0) + (g ? (b ? 6 : 2) : (b ? 4 : 0));
		written = snprintf (outstr + i, sz - i, "%dm", fgbg + c);
		}
		break;
	default:
		break;
	}

	if (written < 0 || written >= sz - i) {
		outstr[0] = '\0';
	}
}

