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
typedef  unsigned long long uint64_t ;
struct BlackRock {unsigned long long range; unsigned long long a; unsigned long long a_bits; unsigned long long a_mask; unsigned long long b; unsigned long long b_bits; unsigned long long b_mask; unsigned int rounds; unsigned long long seed; } ;
typedef  size_t T ;

/* Variables and functions */
 unsigned char* CALLOC (int,size_t) ; 
 unsigned long long* SB1 ; 
 unsigned long long* SB2 ; 
 unsigned long long* SB3 ; 
 unsigned long long* SB4 ; 
 unsigned long long* SB5 ; 
 unsigned long long* SB6 ; 
 unsigned long long* SB7 ; 
 unsigned long long* SB8 ; 
 int /*<<< orphan*/  UNUSEDPARM (unsigned long long) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 unsigned long long pixie_nanotime () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ sqrt (unsigned long long) ; 
 int /*<<< orphan*/  stderr ; 
 unsigned long long time (int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint64_t
next_power_of_two(uint64_t num)
{
    uint64_t power_of_two = 1;

    num++;

    while ((uint64_t)(1ULL << power_of_two) < num)
        power_of_two++;

    return (1ULL << power_of_two);
}

__attribute__((used)) static uint64_t
bit_count(uint64_t num)
{
    uint64_t bits = 0;

    while ((num >> bits) > 1)
        bits++;

    return bits;
}

void
blackrock2_init(struct BlackRock *br, uint64_t range, uint64_t seed, unsigned rounds)
{
    uint64_t a;
    uint64_t b;

    a = next_power_of_two(
                                (uint64_t)sqrt(range * 1.0)
                          );
    b = next_power_of_two(range/a);

    //printf("a=%llu b=%llu seed = 0x%llu\n", a, b, seed);

    br->range = range;

    br->a = a;
    br->a_bits = bit_count(br->a);
    br->a_mask = br->a - 1ULL;

    br->b = b;
    br->b_bits = bit_count(br->b);
    br->b_mask = br->b - 1ULL;

    //printf("a: 0x%llx / %llu\n", br->a_mask, br->a_bits);
    //printf("b: 0x%llx / %llu\n", br->b_mask, br->b_bits);

    br->rounds = rounds;
    br->seed = seed;
    br->range = range;
}

__attribute__((used)) static inline uint64_t
ROUND(uint64_t r, uint64_t R, uint64_t seed)
{
#define GETBYTE(R,n) ((uint64_t)(((((R)>>(n*8ULL)))&0xFFULL)))
#if 0    
    uint64_t r0, r1, r2, r3;
#endif
    uint64_t T, Y;

    T = R ^ ((seed>>r) | (seed<<(64-r)));


    if (r & 1) {
        Y = SB8[ (T      ) & 0x3F ] ^              \
             SB6[ (T >>  8) & 0x3F ] ^              \
             SB4[ (T >> 16) & 0x3F ] ^              \
             SB2[ (T >> 24) & 0x3F ];               \
    } else {
        Y = SB7[ (T      ) & 0x3F ] ^              \
             SB5[ (T >>  8) & 0x3F ] ^              \
             SB3[ (T >> 16) & 0x3F ] ^              \
             SB1[ (T >> 24) & 0x3F ]; 
    }
    return Y;
#if 0
    r0 = sbox2[GETBYTE(R,0)]<< 6 | sbox2[GETBYTE(R,1)]<< 0;
    r1 = sbox2[GETBYTE(R,2)]<< 6 | sbox2[GETBYTE(R,5)]<< 0;
    r2 = sbox2[GETBYTE(R,4)]<< 6 | sbox2[GETBYTE(R,5)]<< 0;
    r3 = sbox2[GETBYTE(R,6)]<< 6 | sbox2[GETBYTE(R,7)]<< 0;

    R = r0 ^ (r1<<12) * (r2 << 24) ^ (r3 << 36) * r;

    return R;
    /*return((uint64_t)sbox2[GETBYTE(R,7ULL)]<< 0ULL)
        | ((uint64_t)sbox2[GETBYTE(R,6ULL)]<< 8ULL)
        | ((uint64_t)sbox2[GETBYTE(R,5ULL)]<<16ULL)
        | ((uint64_t)sbox2[GETBYTE(R,4ULL)]<<24ULL)
        | ((uint64_t)sbox2[GETBYTE(R,3ULL)]<<32ULL)
        | ((uint64_t)sbox2[GETBYTE(R,2ULL)]<<40ULL)
        | ((uint64_t)sbox2[GETBYTE(R,1ULL)]<<48ULL)
        | ((uint64_t)sbox2[GETBYTE(R,0ULL)]<<56ULL)
        ;*/
    return R;
#endif
}

__attribute__((used)) static inline uint64_t
ENCRYPT(unsigned r, uint64_t a_bits, uint64_t a_mask, uint64_t b_bits, uint64_t b_mask, uint64_t m, uint64_t seed)
{
    uint64_t L, R;
    unsigned j = 1;
    uint64_t tmp;

    UNUSEDPARM(b_bits);

    L = m & a_mask;
    R = m >> a_bits;

    for (j=1; j<=r; j++) {
        tmp = (L + ROUND(j, R, seed)) & a_mask;
        L = R;
        R = tmp;
        j++;

        tmp = (L + ROUND(j, R, seed)) & b_mask;
        L = R;
        R = tmp;
    }

    if ((j-1) & 1) {
        return (L << (a_bits)) + R;
    } else {
        return (R << (a_bits)) + L;
    }
}

__attribute__((used)) static inline uint64_t
DECRYPT(unsigned r, uint64_t a, uint64_t b, uint64_t m, uint64_t seed)
{
    uint64_t L, R;
    unsigned j;
    uint64_t tmp;

    if (r & 1) {
        R = m % a;
        L = m / a;
    } else {
        L = m % a;
        R = m / a;
    }

    for (j=r; j>=1; j--) {
        if (j & 1) {
            tmp = ROUND(j, L, seed);
            if (tmp > R) {
                tmp = (tmp - R);
                tmp = a - (tmp%a);
                if (tmp == a)
                    tmp = 0;
            } else {
                tmp = (R - tmp);
                tmp %= a;
            }
        } else {
            tmp = ROUND(j, L, seed);
            if (tmp > R) {
                tmp = (tmp - R);
                tmp = b - (tmp%b);
                if (tmp == b)
                    tmp = 0;
            } else {
                tmp = (R - tmp);
                tmp %= b;
            }
        }
        R = L;
        L = tmp;
    }
    return a * R + L;
}

uint64_t
blackrock2_shuffle(const struct BlackRock *br, uint64_t m)
{
    uint64_t c;

    c = ENCRYPT(br->rounds, br->a_bits, br->a_mask, br->b_bits, br->b_mask, m, br->seed);
    while (c >= br->range)
        c = ENCRYPT(br->rounds, br->a_bits, br->a_mask, br->b_bits, br->b_mask, c, br->seed);

    return c;
}

uint64_t
blackrock2_unshuffle(const struct BlackRock *br, uint64_t m)
{
    uint64_t c;

    c = DECRYPT(br->rounds, br->a, br->b, m, br->seed);
    while (c >= br->range)
        c = DECRYPT(br->rounds, br->a, br->b,  c, br->seed);

    return c;
}

__attribute__((used)) static unsigned
verify(struct BlackRock *br, uint64_t max)
{
    unsigned char *list;
    uint64_t i;
    unsigned is_success = 1;
    uint64_t range = br->range;

    /* Allocate a list of 1-byte counters */
    list = CALLOC(1, (size_t)((range<max)?range:max));
    
    /* For all numbers in the range, verify increment the counter for the
     * the output. */
    for (i=0; i<range; i++) {
        uint64_t x = blackrock2_shuffle(br, i);
        if (x < max)
            list[x]++;
    }

    /* Now check the output to make sure that every counter is set exactly
     * to the value of '1'. */
    for (i=0; i<max && i<range; i++) {
        if (list[i] != 1)
            is_success = 0;
    }

    free(list);

    return is_success;
}

void
blackrock2_benchmark(unsigned rounds)
{
    struct BlackRock br;
    uint64_t range = 0x010356789123UL;
    uint64_t i;
    uint64_t result = 0;
    uint64_t start, stop;
    static const uint64_t ITERATIONS = 5000000UL;

    printf("-- blackrock-2 -- \n");
    printf("rounds = %u\n", rounds);
    blackrock2_init(&br, range, 1, rounds);
/*printf("range = 0x%10" PRIx64 "\n", range);
printf("rangex= 0x%10" PRIx64 "\n", br.a*br.b);
printf("    a = 0x%10" PRIx64 "\n", br.a);
printf("    b = 0x%10" PRIx64 "\n", br.b);*/

    /*
     * Time the the algorithm
     */
    start = pixie_nanotime();
    for (i=0; i<ITERATIONS; i++) {
        result += blackrock2_shuffle(&br, i);
    }
    stop = pixie_nanotime();

    /*
     * Print the results
     */
    if (result) {
        double elapsed = ((double)(stop - start))/(1000000000.0);
        double rate = ITERATIONS/elapsed;

        rate /= 1000000.0;

        printf("iterations/second = %5.3f-million\n", rate);

    }

    printf("\n");

}

int
blackrock2_selftest(void)
{
    uint64_t i;
    int is_success = 0;
    uint64_t range;

    /* @marshray
     * Basic test of decryption. I take the index, encrypt it, then decrypt it,
     * which means I should get the original index back again. Only, it's not
     * working. The decryption fails. The reason it's failing is obvious -- I'm
     * just not seeing it though. The error is probably in the 'unfe()'
     * function above.
     */
    {
        struct BlackRock br;
        uint64_t result, result2;
        blackrock2_init(&br, 1000, 0, 6);

        for (i=0; i<10; i++) {
            result = blackrock2_shuffle(&br, i);
            result2 = blackrock2_unshuffle(&br, result);
            if (i != result2)
                return 1; /*fail*/
        }

    }


    range = 3015 * 3;

    for (i=0; i<5; i++) {
        struct BlackRock br;

        range += 11 + i;
        range *= 1 + i;

        blackrock2_init(&br, range, time(0), 6);

        is_success = verify(&br, range);

        if (!is_success) {
            fprintf(stderr, "BLACKROCK: randomization failed\n");
            return 1; /*fail*/
        }
    }

    return 0; /*success*/
}

