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
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  d ;

/* Variables and functions */
 int /*<<< orphan*/  c2p_unsupported () ; 
 unsigned int get_unaligned_be32 (void*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 size_t* perm_c2p_16x8 ; 
 int /*<<< orphan*/  put_unaligned_be32 (unsigned int,void*) ; 

__attribute__((used)) static inline void _transp(u32 d[], unsigned int i1, unsigned int i2,
			   unsigned int shift, u32 mask)
{
	u32 t = (d[i1] ^ (d[i2] >> shift)) & mask;

	d[i1] ^= t;
	d[i2] ^= t << shift;
}

__attribute__((used)) static inline u32 get_mask(unsigned int n)
{
	switch (n) {
	case 1:
		return 0x55555555;

	case 2:
		return 0x33333333;

	case 4:
		return 0x0f0f0f0f;

	case 8:
		return 0x00ff00ff;

	case 16:
		return 0x0000ffff;
	}

	c2p_unsupported();
	return 0;
}

__attribute__((used)) static inline void transp8(u32 d[], unsigned int n, unsigned int m)
{
	u32 mask = get_mask(n);

	switch (m) {
	case 1:
		/* First n x 1 block */
		_transp(d, 0, 1, n, mask);
		/* Second n x 1 block */
		_transp(d, 2, 3, n, mask);
		/* Third n x 1 block */
		_transp(d, 4, 5, n, mask);
		/* Fourth n x 1 block */
		_transp(d, 6, 7, n, mask);
		return;

	case 2:
		/* First n x 2 block */
		_transp(d, 0, 2, n, mask);
		_transp(d, 1, 3, n, mask);
		/* Second n x 2 block */
		_transp(d, 4, 6, n, mask);
		_transp(d, 5, 7, n, mask);
		return;

	case 4:
		/* Single n x 4 block */
		_transp(d, 0, 4, n, mask);
		_transp(d, 1, 5, n, mask);
		_transp(d, 2, 6, n, mask);
		_transp(d, 3, 7, n, mask);
		return;
	}

	c2p_unsupported();
}

__attribute__((used)) static inline void transp4(u32 d[], unsigned int n, unsigned int m)
{
	u32 mask = get_mask(n);

	switch (m) {
	case 1:
		/* First n x 1 block */
		_transp(d, 0, 1, n, mask);
		/* Second n x 1 block */
		_transp(d, 2, 3, n, mask);
		return;

	case 2:
		/* Single n x 2 block */
		_transp(d, 0, 2, n, mask);
		_transp(d, 1, 3, n, mask);
		return;
	}

	c2p_unsupported();
}

__attribute__((used)) static inline void transp4x(u32 d[], unsigned int n, unsigned int m)
{
	u32 mask = get_mask(n);

	switch (m) {
	case 2:
		/* Single n x 2 block */
		_transp(d, 2, 0, n, mask);
		_transp(d, 3, 1, n, mask);
		return;
	}

	c2p_unsupported();
}

__attribute__((used)) static inline u32 comp(u32 a, u32 b, u32 mask)
{
	return ((a ^ b) & mask) ^ b;
}

__attribute__((used)) static void c2p_16x8(u32 d[4])
{
	transp4(d, 8, 2);
	transp4(d, 1, 2);
	transp4x(d, 16, 2);
	transp4x(d, 2, 2);
	transp4(d, 4, 1);
}

__attribute__((used)) static inline void store_iplan2(void *dst, u32 bpp, u32 d[4])
{
	int i;

	for (i = 0; i < bpp/2; i++, dst += 4)
		put_unaligned_be32(d[perm_c2p_16x8[i]], dst);
}

__attribute__((used)) static inline void store_iplan2_masked(void *dst, u32 bpp, u32 d[4], u32 mask)
{
	int i;

	for (i = 0; i < bpp/2; i++, dst += 4)
		put_unaligned_be32(comp(d[perm_c2p_16x8[i]],
					get_unaligned_be32(dst), mask),
				   dst);
}

void c2p_iplan2(void *dst, const void *src, u32 dx, u32 dy, u32 width,
		u32 height, u32 dst_nextline, u32 src_nextline, u32 bpp)
{
	union {
		u8 pixels[16];
		u32 words[4];
	} d;
	u32 dst_idx, first, last, w;
	const u8 *c;
	void *p;

	dst += dy*dst_nextline+(dx & ~15)*bpp;
	dst_idx = dx % 16;
	first = 0xffffU >> dst_idx;
	first |= first << 16;
	last = 0xffffU ^ (0xffffU >> ((dst_idx+width) % 16));
	last |= last << 16;
	while (height--) {
		c = src;
		p = dst;
		w = width;
		if (dst_idx+width <= 16) {
			/* Single destination word */
			first &= last;
			memset(d.pixels, 0, sizeof(d));
			memcpy(d.pixels+dst_idx, c, width);
			c += width;
			c2p_16x8(d.words);
			store_iplan2_masked(p, bpp, d.words, first);
			p += bpp*2;
		} else {
			/* Multiple destination words */
			w = width;
			/* Leading bits */
			if (dst_idx) {
				w = 16 - dst_idx;
				memset(d.pixels, 0, dst_idx);
				memcpy(d.pixels+dst_idx, c, w);
				c += w;
				c2p_16x8(d.words);
				store_iplan2_masked(p, bpp, d.words, first);
				p += bpp*2;
				w = width-w;
			}
			/* Main chunk */
			while (w >= 16) {
				memcpy(d.pixels, c, 16);
				c += 16;
				c2p_16x8(d.words);
				store_iplan2(p, bpp, d.words);
				p += bpp*2;
				w -= 16;
			}
			/* Trailing bits */
			w %= 16;
			if (w > 0) {
				memcpy(d.pixels, c, w);
				memset(d.pixels+w, 0, 16-w);
				c2p_16x8(d.words);
				store_iplan2_masked(p, bpp, d.words, last);
			}
		}
		src += src_nextline;
		dst += dst_nextline;
	}
}

