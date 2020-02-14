#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint64 ;
typedef  int uint32 ;
typedef  int uint16 ;
typedef  int int64 ;
typedef  int int32 ;
struct TYPE_38__ {int* as_uint32; unsigned char* as_uint8; } ;
typedef  TYPE_2__ fe25519 ;
typedef  int /*<<< orphan*/  UN_512bitValue ;
struct TYPE_37__ {unsigned char* as_uint8; } ;
struct TYPE_39__ {int nextScalarBitToProcess; int previousProcessedBit; TYPE_2__ xp; TYPE_2__ zp; TYPE_2__ x0; TYPE_2__ zq; TYPE_2__ xq; TYPE_1__ s; } ;
typedef  TYPE_3__ ST_curve25519ladderstepWorkingState ;

/* Variables and functions */
 int /*<<< orphan*/  fe25519_mpyWith121666 (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  fe25519_reduceTo256Bits_asm (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  multiply256x256 (int /*<<< orphan*/ *,TYPE_2__ const*,TYPE_2__ const*) ; 
 int /*<<< orphan*/  square256 (int /*<<< orphan*/ *,TYPE_2__ const*) ; 

__attribute__((used)) static void
fe25519_cpy(
    fe25519*       dest,
    const fe25519* source
)
{
    uint32 ctr;

    for (ctr = 0; ctr < 8; ctr++)
    {
        dest->as_uint32[ctr] = source->as_uint32[ctr];
    }
}

__attribute__((used)) static void
fe25519_unpack(
    volatile fe25519*            out,
    const unsigned char in[32]
)
{
    uint8 ctr;

    for (ctr = 0; ctr < 32; ctr++)
    {
        out->as_uint8[ctr] = in[ctr];
    }
    out->as_uint8[31] &= 0x7f; // make sure that the last bit is cleared.
}

__attribute__((used)) static void
fe25519_sub(
    fe25519*       out,
    const fe25519* baseValue,
    const fe25519* valueToSubstract
)
{
    uint16 ctr;
    int64  accu = 0;

    // First subtract the most significant word, so that we may
    // reduce the result "on the fly".
    accu = baseValue->as_uint32[7];
    accu -= valueToSubstract->as_uint32[7];

    // We always set bit #31, and compensate this by subtracting 1 from the reduction
    // value.
    out->as_uint32[7] = ((uint32)accu) | 0x80000000ul;

    accu = 19 * ((int32)(accu >> 31) - 1);
    // ^ "-1" is the compensation for the "| 0x80000000ul" above.
    // This choice makes sure, that the result will be positive!

    for (ctr = 0; ctr < 7; ctr += 1)
    {
        accu += baseValue->as_uint32[ctr];
        accu -= valueToSubstract->as_uint32[ctr];

        out->as_uint32[ctr] = (uint32)accu;
        accu >>= 32;
    }
    accu += out->as_uint32[7];
    out->as_uint32[7] = (uint32)accu;
}

__attribute__((used)) static void
fe25519_add(
    fe25519*       out,
    const fe25519* baseValue,
    const fe25519* valueToAdd
)
{
    uint16 ctr = 0;
    uint64 accu = 0;

    // We first add the most significant word, so that we may reduce
    // "on the fly".
    accu = baseValue->as_uint32[7];
    accu += valueToAdd->as_uint32[7];
    out->as_uint32[7] = ((uint32)accu) & 0x7ffffffful;

    accu = ((uint32)(accu >> 31)) * 19;

    for (ctr = 0; ctr < 7; ctr += 1)
    {
        accu += baseValue->as_uint32[ctr];
        accu += valueToAdd->as_uint32[ctr];

        out->as_uint32[ctr] = (uint32)accu;
        accu >>= 32;
    }
    accu += out->as_uint32[7];
    out->as_uint32[7] = (uint32)accu;
}

__attribute__((used)) static void
fe25519_mul(
    fe25519*       result,
    const fe25519* in1,
    const fe25519* in2
)
{
    UN_512bitValue tmp;

    multiply256x256(&tmp, in1, in2);
    fe25519_reduceTo256Bits_asm(result,&tmp);
}

__attribute__((used)) static void
fe25519_square(
    fe25519*       result,
    const fe25519* in
)
{
    UN_512bitValue tmp;

    square256(&tmp, in);
    fe25519_reduceTo256Bits_asm(result,&tmp);
}

__attribute__((used)) static void
fe25519_reduceCompletely(
    volatile fe25519* inout
)
{
    uint32 numberOfTimesToSubstractPrime;
    uint32 initialGuessForNumberOfTimesToSubstractPrime = inout->as_uint32[7] >>
                                                          31;
    uint64 accu;
    uint8  ctr;

    // add one additional 19 to the estimated number of reductions.
    // Do the calculation without writing back the results to memory.
    //
    // The initial guess of required numbers of reductions is based
    // on bit #32 of the most significant word.
    // This initial guess may be wrong, since we might have a value
    // v in the range
    // 2^255 - 19 <= v < 2^255
    // . After adding 19 to the value, we will be having the correct
    // Number of required subtractions.
    accu = initialGuessForNumberOfTimesToSubstractPrime * 19 + 19;

    for (ctr = 0; ctr < 7; ctr++)
    {
        accu += inout->as_uint32[ctr];
        accu >>= 32;
    }
    accu += inout->as_uint32[7];

    numberOfTimesToSubstractPrime = (uint32)(accu >> 31);

    // Do the reduction.
    accu = numberOfTimesToSubstractPrime * 19;

    for (ctr = 0; ctr < 7; ctr++)
    {
        accu += inout->as_uint32[ctr];
        inout->as_uint32[ctr] = (uint32)accu;
        accu >>= 32;
    }
    accu += inout->as_uint32[7];
    inout->as_uint32[7] = accu & 0x7ffffffful;
}

__attribute__((used)) static void
fe25519_pack(
    unsigned char out[32],
    volatile fe25519*      in
)
{
    uint8 ctr;

    fe25519_reduceCompletely(in);

    for (ctr = 0; ctr < 32; ctr++)
    {
        out[ctr] = in->as_uint8[ctr];
    }
}

__attribute__((used)) static void
fe25519_invert_useProvidedScratchBuffers(
    fe25519*       r,
    const fe25519* x,
    fe25519*       t0,
    fe25519*       t1,
    fe25519*       t2    
)
{
    fe25519 *z11 = r; // store z11 in r (in order to save one temporary).
    fe25519 *z2_10_0 = t1;    
    fe25519 *z2_50_0 = t2;
    fe25519 *z2_100_0 = z2_10_0;

    uint8   i;

    {
         fe25519 *z2 = z2_50_0;

        /* 2 */ fe25519_square(z2, x);
        /* 4 */ fe25519_square(t0, z2);
        /* 8 */ fe25519_square(t0, t0);
        /* 9 */ fe25519_mul(z2_10_0, t0, x);
        /* 11 */ fe25519_mul(z11, z2_10_0, z2);
        
        // z2 is dead.
    }
	
    /* 22 */ fe25519_square(t0, z11);
    /* 2^5 - 2^0 = 31 */ fe25519_mul(z2_10_0, t0, z2_10_0);

    /* 2^6 - 2^1 */ fe25519_square(t0, z2_10_0);
    /* 2^7 - 2^2 */ fe25519_square(t0, t0);
    /* 2^8 - 2^3 */ fe25519_square(t0, t0);
    /* 2^9 - 2^4 */ fe25519_square(t0, t0);
    /* 2^10 - 2^5 */ fe25519_square(t0, t0);
    /* 2^10 - 2^0 */ fe25519_mul(z2_10_0, t0, z2_10_0);

    /* 2^11 - 2^1 */ fe25519_square(t0, z2_10_0);

    /* 2^20 - 2^10 */ for (i = 1; i < 10; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^20 - 2^0 */ fe25519_mul(z2_50_0, t0, z2_10_0);

    /* 2^21 - 2^1 */ fe25519_square(t0, z2_50_0);

    /* 2^40 - 2^20 */ for (i = 1; i < 20; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^40 - 2^0 */ fe25519_mul(t0, t0, z2_50_0);

    /* 2^41 - 2^1 */ fe25519_square(t0, t0);

    /* 2^50 - 2^10 */ for (i = 1; i < 10; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^50 - 2^0 */ fe25519_mul(z2_50_0, t0, z2_10_0);

    /* 2^51 - 2^1 */ fe25519_square(t0, z2_50_0);

    /* 2^100 - 2^50 */ for (i = 1; i < 50; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^100 - 2^0 */ fe25519_mul(z2_100_0, t0, z2_50_0);

    /* 2^101 - 2^1 */ fe25519_square(t0, z2_100_0);

    /* 2^200 - 2^100 */ for (i = 1; i < 100; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^200 - 2^0 */ fe25519_mul(t0, t0, z2_100_0);

    /* 2^250 - 2^50 */ for (i = 0; i < 50; i ++)
    {
        fe25519_square(t0, t0);
    }
    /* 2^250 - 2^0 */ fe25519_mul(t0, t0, z2_50_0);

    /* 2^255 - 2^5 */ for (i = 0; i < 5; i ++)
    {
         fe25519_square(t0, t0);
    }
    /* 2^255 - 21 */ fe25519_mul(r, t0, z11);
}

__attribute__((used)) static void
fe25519_setzero(
    fe25519* out
)
{
    uint8 ctr;

    for (ctr = 0; ctr < 8; ctr++)
    {
        out->as_uint32[ctr] = 0;
    }
}

__attribute__((used)) static void
fe25519_setone(
    fe25519* out
)
{
    uint8 ctr;

    out->as_uint32[0] = 1;

    for (ctr = 1; ctr < 8; ctr++)
    {
        out->as_uint32[ctr] = 0;
    }
}

__attribute__((used)) static void
fe25519_cswap(
    fe25519* in1,
    fe25519* in2,
    int      condition
)
{
    int32 mask = condition;
    uint32 ctr;

    mask = -mask;

    for (ctr = 0; ctr < 8; ctr++)
    {
    	uint32 val1 = in1->as_uint32[ctr];
    	uint32 val2 = in2->as_uint32[ctr];
    	uint32 temp = val1;

    	val1 ^= mask & (val2 ^ val1);
    	val2 ^= mask & (val2 ^ temp);


    	in1->as_uint32[ctr] = val1;
    	in2->as_uint32[ctr] = val2;
    }
}

__attribute__((used)) static void
curve25519_ladderstep(
    ST_curve25519ladderstepWorkingState* pState
)
{
    // Implements the "ladd-1987-m-3" differential-addition-and-doubling formulas
    // Source: 1987 Montgomery "Speeding the Pollard and elliptic curve methods of factorization", page 261,
    //         fifth and sixth displays, plus common-subexpression elimination.
    //
    // Notation from the explicit formulas database:
    // (X2,Z2) corresponds to (xp,zp),
    // (X3,Z3) corresponds to (xq,zq)
    // Result (X4,Z4) (X5,Z5) expected in (xp,zp) and (xq,zq)
    //
    // A = X2+Z2; AA = A^2; B = X2-Z2; BB = B^2; E = AA-BB; C = X3+Z3; D = X3-Z3;
    // DA = D*A; CB = C*B; t0 = DA+CB; t1 = t0^2; X5 = Z1*t1; t2 = DA-CB;
    // t3 = t2^2; Z5 = X1*t3; X4 = AA*BB; t4 = a24*E; t5 = BB+t4; Z4 = E*t5 ;
    //
    // Re-Ordered for using less temporaries.

    fe25519 t1, t2;

    #ifdef DH_SWAP_BY_POINTERS
    fe25519 *b1=pState->pXp; fe25519 *b2=pState->pZp;
    fe25519 *b3=pState->pXq; fe25519 *b4=pState->pZq;
    #else
    fe25519 *b1=&pState->xp; fe25519 *b2=&pState->zp;
    fe25519 *b3=&pState->xq; fe25519 *b4=&pState->zq;
    #endif

    fe25519 *b5= &t1; fe25519 *b6=&t2;

    fe25519_add(b5,b1,b2); // A = X2+Z2
    fe25519_sub(b6,b1,b2); // B = X2-Z2
    fe25519_add(b1,b3,b4); // C = X3+Z3
    fe25519_sub(b2,b3,b4); // D = X3-Z3
    fe25519_mul(b3,b2,b5); // DA= D*A
    fe25519_mul(b2,b1,b6); // CB= C*B
    fe25519_add(b1,b2,b3); // T0= DA+CB
    fe25519_sub(b4,b3,b2); // T2= DA-CB
    fe25519_square(b3,b1); // X5==T1= T0^2
    fe25519_square(b1,b4); // T3= t2^2
    fe25519_mul(b4,b1,&pState->x0); // Z5=X1*t3
    fe25519_square(b1,b5); // AA=A^2
    fe25519_square(b5,b6); // BB=B^2
    fe25519_sub(b2,b1,b5); // E=AA-BB
    fe25519_mul(b1,b5,b1); // X4= AA*BB
    fe25519_mpyWith121666 (b6,b2); // T4 = a24*E
    fe25519_add(b6,b6,b5); // T5 = BB + t4
    fe25519_mul(b2,b6,b2); // Z4 = E*t5
}

__attribute__((used)) static void
curve25519_cswap(
    ST_curve25519ladderstepWorkingState* state,
    uint8                                b
)
{
    #ifdef DH_SWAP_BY_POINTERS
    swapPointersConditionally ((void **) &state->pXp,(void **) &state->pXq,b);
    swapPointersConditionally ((void **) &state->pZp,(void **) &state->pZq,b);
    #else
    fe25519_cswap (&state->xp, &state->xq,b);
    fe25519_cswap (&state->zp, &state->zq,b);
    #endif
}

int
crypto_scalarmult_curve25519(
    unsigned char*       r,
    const unsigned char* s,
    const unsigned char* p
)
{
    ST_curve25519ladderstepWorkingState state;
    unsigned char i;


    // Prepare the scalar within the working state buffer.
    for (i = 0; i < 32; i++)
    {
        state.s.as_uint8 [i] = s[i];
    }
#if DH_REPLACE_LAST_THREE_LADDERSTEPS_WITH_DOUBLINGS    
    // Due to explicit final doubling for the last three bits instead of a full ladderstep, 
    // the following line is no longer necessary.
#else
    state.s.as_uint8 [0] &= 248; 
#endif
    state.s.as_uint8 [31] &= 127;
    state.s.as_uint8 [31] |= 64;

    // Copy the affine x-axis of the base point to the state.
    fe25519_unpack (&state.x0, p);

    // Prepare the working points within the working state struct.

    fe25519_setone (&state.zq);
    fe25519_cpy (&state.xq, &state.x0);

    fe25519_setone(&state.xp);
    fe25519_setzero(&state.zp);

    state.nextScalarBitToProcess = 254;

#ifdef DH_SWAP_BY_POINTERS
    // we need to initially assign the pointers correctly.
    state.pXp = &state.xp;
    state.pZp = &state.zp;
    state.pXq = &state.xq;
    state.pZq = &state.zq;
#endif

    state.previousProcessedBit = 0;

#if DH_REPLACE_LAST_THREE_LADDERSTEPS_WITH_DOUBLINGS          
    // Process all the bits except for the last three where we explicitly double the result.
    while (state.nextScalarBitToProcess >= 3)
#else
    // Process all the bits except for the last three where we explicitly double the result.
    while (state.nextScalarBitToProcess >= 0)
#endif    
    {
    	uint8 byteNo = state.nextScalarBitToProcess >> 3;
    	uint8 bitNo = state.nextScalarBitToProcess & 7;
        uint8 bit;
        uint8 swap;

        bit = 1 & (state.s.as_uint8 [byteNo] >> bitNo);
        swap = bit ^ state.previousProcessedBit;
        state.previousProcessedBit = bit;
        curve25519_cswap(&state, swap);
        curve25519_ladderstep(&state);
        state.nextScalarBitToProcess --;
    }

    curve25519_cswap(&state,state.previousProcessedBit);

#if DH_REPLACE_LAST_THREE_LADDERSTEPS_WITH_DOUBLINGS        
    curve25519_doublePointP (&state);
    curve25519_doublePointP (&state);
    curve25519_doublePointP (&state);
#endif

#ifdef DH_SWAP_BY_POINTERS
    // optimize for stack usage.
    fe25519_invert_useProvidedScratchBuffers (state.pZp, state.pZp, state.pXq,state.pZq,&state.x0);
    fe25519_mul(state.pXp, state.pXp, state.pZp);
    fe25519_reduceCompletely(state.pXp);

    fe25519_pack (r, state.pXp);
#else
    // optimize for stack usage.
    fe25519_invert_useProvidedScratchBuffers (&state.zp, &state.zp, &state.xq, &state.zq, &state.x0);    
    fe25519_mul(&state.xp, &state.xp, &state.zp);
    fe25519_reduceCompletely(&state.xp);

    fe25519_pack (r, &state.xp);
#endif

    return 0;
}

int
crypto_scalarmult_curve25519_base(
    unsigned char*       q,
    const unsigned char* n
)
{
    static const uint8 base[32] =
    {
        9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    return crypto_scalarmult_curve25519(q, n, base);
}

