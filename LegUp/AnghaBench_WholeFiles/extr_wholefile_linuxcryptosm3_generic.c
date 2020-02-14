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
typedef  int /*<<< orphan*/  wt ;
typedef  int /*<<< orphan*/  w ;
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned int u32 ;
struct sm3_state {unsigned int* state; } ;
struct shash_desc {int dummy; } ;
typedef  int /*<<< orphan*/  __u32 ;

/* Variables and functions */
 int /*<<< orphan*/  SM3_BLOCK_SIZE ; 
 unsigned int SM3_T1 ; 
 unsigned int SM3_T2 ; 
 unsigned int get_unaligned_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memzero_explicit (unsigned int*,int) ; 
 unsigned int rol32 (unsigned int,int) ; 
 int /*<<< orphan*/  sm3_base_do_finalize (struct shash_desc*,void (*) (struct sm3_state*,int /*<<< orphan*/  const*,int)) ; 
 int sm3_base_do_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int,void (*) (struct sm3_state*,int /*<<< orphan*/  const*,int)) ; 
 int sm3_base_finish (struct shash_desc*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u32 p0(u32 x)
{
	return x ^ rol32(x, 9) ^ rol32(x, 17);
}

__attribute__((used)) static inline u32 p1(u32 x)
{
	return x ^ rol32(x, 15) ^ rol32(x, 23);
}

__attribute__((used)) static inline u32 ff(unsigned int n, u32 a, u32 b, u32 c)
{
	return (n < 16) ? (a ^ b ^ c) : ((a & b) | (a & c) | (b & c));
}

__attribute__((used)) static inline u32 gg(unsigned int n, u32 e, u32 f, u32 g)
{
	return (n < 16) ? (e ^ f ^ g) : ((e & f) | ((~e) & g));
}

__attribute__((used)) static inline u32 t(unsigned int n)
{
	return (n < 16) ? SM3_T1 : SM3_T2;
}

__attribute__((used)) static void sm3_expand(u32 *t, u32 *w, u32 *wt)
{
	int i;
	unsigned int tmp;

	/* load the input */
	for (i = 0; i <= 15; i++)
		w[i] = get_unaligned_be32((__u32 *)t + i);

	for (i = 16; i <= 67; i++) {
		tmp = w[i - 16] ^ w[i - 9] ^ rol32(w[i - 3], 15);
		w[i] = p1(tmp) ^ (rol32(w[i - 13], 7)) ^ w[i - 6];
	}

	for (i = 0; i <= 63; i++)
		wt[i] = w[i] ^ w[i + 4];
}

__attribute__((used)) static void sm3_compress(u32 *w, u32 *wt, u32 *m)
{
	u32 ss1;
	u32 ss2;
	u32 tt1;
	u32 tt2;
	u32 a, b, c, d, e, f, g, h;
	int i;

	a = m[0];
	b = m[1];
	c = m[2];
	d = m[3];
	e = m[4];
	f = m[5];
	g = m[6];
	h = m[7];

	for (i = 0; i <= 63; i++) {

		ss1 = rol32((rol32(a, 12) + e + rol32(t(i), i & 31)), 7);

		ss2 = ss1 ^ rol32(a, 12);

		tt1 = ff(i, a, b, c) + d + ss2 + *wt;
		wt++;

		tt2 = gg(i, e, f, g) + h + ss1 + *w;
		w++;

		d = c;
		c = rol32(b, 9);
		b = a;
		a = tt1;
		h = g;
		g = rol32(f, 19);
		f = e;
		e = p0(tt2);
	}

	m[0] = a ^ m[0];
	m[1] = b ^ m[1];
	m[2] = c ^ m[2];
	m[3] = d ^ m[3];
	m[4] = e ^ m[4];
	m[5] = f ^ m[5];
	m[6] = g ^ m[6];
	m[7] = h ^ m[7];

	a = b = c = d = e = f = g = h = ss1 = ss2 = tt1 = tt2 = 0;
}

__attribute__((used)) static void sm3_transform(struct sm3_state *sst, u8 const *src)
{
	unsigned int w[68];
	unsigned int wt[64];

	sm3_expand((u32 *)src, w, wt);
	sm3_compress(w, wt, sst->state);

	memzero_explicit(w, sizeof(w));
	memzero_explicit(wt, sizeof(wt));
}

__attribute__((used)) static void sm3_generic_block_fn(struct sm3_state *sst, u8 const *src,
				    int blocks)
{
	while (blocks--) {
		sm3_transform(sst, src);
		src += SM3_BLOCK_SIZE;
	}
}

int crypto_sm3_update(struct shash_desc *desc, const u8 *data,
			  unsigned int len)
{
	return sm3_base_do_update(desc, data, len, sm3_generic_block_fn);
}

__attribute__((used)) static int sm3_final(struct shash_desc *desc, u8 *out)
{
	sm3_base_do_finalize(desc, sm3_generic_block_fn);
	return sm3_base_finish(desc, out);
}

int crypto_sm3_finup(struct shash_desc *desc, const u8 *data,
			unsigned int len, u8 *hash)
{
	sm3_base_do_update(desc, data, len, sm3_generic_block_fn);
	return sm3_final(desc, hash);
}

