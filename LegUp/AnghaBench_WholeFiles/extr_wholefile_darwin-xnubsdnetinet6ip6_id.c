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
typedef  int u_int64_t ;
typedef  int u_int32_t ;
typedef  scalar_t__ time_t ;
struct randomtab {unsigned int ru_x; unsigned int ru_m; unsigned int ru_seed; int ru_bits; unsigned int ru_seed2; unsigned int ru_b; int ru_a; int ru_agen; unsigned int ru_n; int* pfacts; int ru_g; int ru_gen; scalar_t__ ru_counter; scalar_t__ ru_reseed; scalar_t__ ru_out; unsigned int ru_msb; scalar_t__ ru_max; } ;

/* Variables and functions */
 unsigned int RandomULong () ; 
 int /*<<< orphan*/  net_uptime () ; 
 struct randomtab randomtab_20 ; 
 struct randomtab randomtab_32 ; 

__attribute__((used)) static u_int32_t
pmod(u_int32_t gen, u_int32_t expo, u_int32_t mod)
{
	u_int64_t s, t, u;

	s = 1;
	t = gen;
	u = expo;

	while (u) {
		if (u & 1)
			s = (s * t) % mod;
		u >>= 1;
		t = (t * t) % mod;
	}
	return (s);
}

__attribute__((used)) static void
initid(struct randomtab *p)
{
	time_t curtime = (time_t)net_uptime();
	u_int32_t j, i;
	int noprime = 1;

	p->ru_x = RandomULong() % p->ru_m;

	/* (bits - 1) bits of random seed */
	p->ru_seed = RandomULong() & (~0U >> (32 - p->ru_bits + 1));
	p->ru_seed2 = RandomULong() & (~0U >> (32 - p->ru_bits + 1));

	/* Determine the LCG we use */
	p->ru_b = (RandomULong() & (~0U >> (32 - p->ru_bits))) | 1;
	p->ru_a = pmod(p->ru_agen,
	    (RandomULong() & (~0U >> (32 - p->ru_bits))) & (~1U), p->ru_m);
	while (p->ru_b % 3 == 0)
		p->ru_b += 2;

	j = RandomULong() % p->ru_n;

	/*
	 * Do a fast gcd(j, RU_N - 1), so we can find a j with
	 * gcd(j, RU_N - 1) == 1, giving a new generator for
	 * RU_GEN^j mod RU_N
	 */
	while (noprime) {
		for (i = 0; p->pfacts[i] > 0; i++)
			if (j % p->pfacts[i] == 0)
				break;

		if (p->pfacts[i] == 0)
			noprime = 0;
		else
			j = (j + 1) % p->ru_n;
	}

	p->ru_g = pmod(p->ru_gen, j, p->ru_n);
	p->ru_counter = 0;

	p->ru_reseed = curtime + p->ru_out;
	p->ru_msb = p->ru_msb ? 0 : (1U << (p->ru_bits - 1));
}

__attribute__((used)) static u_int32_t
randomid(struct randomtab *p)
{
	time_t curtime = (time_t)net_uptime();
	int i, n;
	u_int32_t tmp;

	if (p->ru_counter >= p->ru_max || curtime > p->ru_reseed)
		initid(p);

	tmp = RandomULong();

	/* Skip a random number of ids */
	n = tmp & 0x3; tmp = tmp >> 2;
	if (p->ru_counter + n >= p->ru_max)
		initid(p);

	for (i = 0; i <= n; i++) {
		/* Linear Congruential Generator */
		p->ru_x = ((u_int64_t)p->ru_a * p->ru_x + p->ru_b) % p->ru_m;
	}

	p->ru_counter += i;

	return ((p->ru_seed ^ pmod(p->ru_g, p->ru_seed2 ^ p->ru_x, p->ru_n)) |
	    p->ru_msb);
}

u_int32_t
ip6_randomid(void)
{

	return (randomid(&randomtab_32));
}

u_int32_t
ip6_randomflowlabel(void)
{

	return (randomid(&randomtab_20) & 0xfffff);
}

