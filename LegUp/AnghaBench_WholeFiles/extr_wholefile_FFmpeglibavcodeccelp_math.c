#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int /*<<< orphan*/  int64_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_4__ {float (* dot_productf ) (float const*,float const*,int) ;} ;
typedef  TYPE_1__ CELPMContext ;

/* Variables and functions */
 scalar_t__ HAVE_MIPSFPU ; 
 scalar_t__ MUL16 (int /*<<< orphan*/  const,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 int av_log2 (int) ; 
 int* exp2a ; 
 unsigned int* exp2b ; 
 int /*<<< orphan*/  ff_celp_math_init_mips (TYPE_1__*) ; 
 int* tab_log2 ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static inline int bidir_sal(int value, int offset)
{
    if(offset < 0) return value >> -offset;
    else           return value <<  offset;
}

int ff_exp2(uint16_t power)
{
    unsigned int result= exp2a[power>>10] + 0x10000;

    av_assert2(power <= 0x7fff);

    result= (result<<3) + ((result*exp2b[(power>>5)&31])>>17);
    return result + ((result*(power&31)*89)>>22);
}

int ff_log2_q15(uint32_t value)
{
    uint8_t  power_int;
    uint8_t  frac_x0;
    uint16_t frac_dx;

    // Stripping zeros from beginning
    power_int = av_log2(value);
    value <<= (31 - power_int);

    // b31 is always non-zero now
    frac_x0 = (value & 0x7c000000) >> 26; // b26-b31 and [32..63] -> [0..31]
    frac_dx = (value & 0x03fff800) >> 11;

    value = tab_log2[frac_x0];
    value += (frac_dx * (tab_log2[frac_x0+1] - tab_log2[frac_x0])) >> 15;

    return (power_int << 15) + value;
}

int64_t ff_dot_product(const int16_t *a, const int16_t *b, int length)
{
    int i;
    int64_t sum = 0;

    for (i = 0; i < length; i++)
        sum += MUL16(a[i], b[i]);

    return sum;
}

float ff_dot_productf(const float* a, const float* b, int length)
{
    float sum = 0;
    int i;

    for(i=0; i<length; i++)
        sum += a[i] * b[i];

    return sum;
}

void ff_celp_math_init(CELPMContext *c)
{
    c->dot_productf   = ff_dot_productf;

    if(HAVE_MIPSFPU)
        ff_celp_math_init_mips(c);
}

