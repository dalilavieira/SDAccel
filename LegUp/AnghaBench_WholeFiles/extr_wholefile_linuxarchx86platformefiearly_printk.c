#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned int u32 ;
typedef  unsigned int u16 ;
struct screen_info {unsigned int lfb_linelength; unsigned int lfb_height; unsigned int lfb_width; } ;
struct console {int dummy; } ;
struct TYPE_4__ {struct screen_info screen_info; } ;
struct TYPE_3__ {unsigned int height; int* data; unsigned int width; } ;

/* Variables and functions */
 TYPE_2__ boot_params ; 
 void* early_efi_map (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  early_efi_unmap (void*,unsigned int) ; 
 unsigned int efi_x ; 
 unsigned int efi_y ; 
 TYPE_1__* font ; 
 int /*<<< orphan*/  memmove (unsigned long*,unsigned long*,unsigned int) ; 
 int /*<<< orphan*/  memset (unsigned long*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void early_efi_clear_scanline(unsigned int y)
{
	unsigned long *dst;
	u16 len;

	len = boot_params.screen_info.lfb_linelength;
	dst = early_efi_map(y*len, len);
	if (!dst)
		return;

	memset(dst, 0, len);
	early_efi_unmap(dst, len);
}

__attribute__((used)) static void early_efi_scroll_up(void)
{
	unsigned long *dst, *src;
	u16 len;
	u32 i, height;

	len = boot_params.screen_info.lfb_linelength;
	height = boot_params.screen_info.lfb_height;

	for (i = 0; i < height - font->height; i++) {
		dst = early_efi_map(i*len, len);
		if (!dst)
			return;

		src = early_efi_map((i + font->height) * len, len);
		if (!src) {
			early_efi_unmap(dst, len);
			return;
		}

		memmove(dst, src, len);

		early_efi_unmap(src, len);
		early_efi_unmap(dst, len);
	}
}

__attribute__((used)) static void early_efi_write_char(u32 *dst, unsigned char c, unsigned int h)
{
	const u32 color_black = 0x00000000;
	const u32 color_white = 0x00ffffff;
	const u8 *src;
	u8 s8;
	int m;

	src = font->data + c * font->height;
	s8 = *(src + h);

	for (m = 0; m < 8; m++) {
		if ((s8 >> (7 - m)) & 1)
			*dst = color_white;
		else
			*dst = color_black;
		dst++;
	}
}

__attribute__((used)) static void
early_efi_write(struct console *con, const char *str, unsigned int num)
{
	struct screen_info *si;
	unsigned int len;
	const char *s;
	void *dst;

	si = &boot_params.screen_info;
	len = si->lfb_linelength;

	while (num) {
		unsigned int linemax;
		unsigned int h, count = 0;

		for (s = str; *s && *s != '\n'; s++) {
			if (count == num)
				break;
			count++;
		}

		linemax = (si->lfb_width - efi_x) / font->width;
		if (count > linemax)
			count = linemax;

		for (h = 0; h < font->height; h++) {
			unsigned int n, x;

			dst = early_efi_map((efi_y + h) * len, len);
			if (!dst)
				return;

			s = str;
			n = count;
			x = efi_x;

			while (n-- > 0) {
				early_efi_write_char(dst + x*4, *s, h);
				x += font->width;
				s++;
			}

			early_efi_unmap(dst, len);
		}

		num -= count;
		efi_x += count * font->width;
		str += count;

		if (num > 0 && *s == '\n') {
			efi_x = 0;
			efi_y += font->height;
			str++;
			num--;
		}

		if (efi_x + font->width > si->lfb_width) {
			efi_x = 0;
			efi_y += font->height;
		}

		if (efi_y + font->height > si->lfb_height) {
			u32 i;

			efi_y -= font->height;
			early_efi_scroll_up();

			for (i = 0; i < font->height; i++)
				early_efi_clear_scanline(efi_y + i);
		}
	}
}

