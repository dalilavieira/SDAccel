#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  size_t temp ;
typedef  int /*<<< orphan*/  t ;
typedef  size_t s3 ;
typedef  size_t s2 ;
typedef  size_t s1 ;
typedef  size_t s0 ;
struct TYPE_6__ {int* rd_key; int rounds; } ;
typedef  TYPE_1__ AES_KEY ;

/* Variables and functions */
 int const GETU32 (unsigned char const*) ; 
 int const* Td0 ; 
 int const* Td1 ; 
 int const* Td2 ; 
 int const* Td3 ; 
 scalar_t__* Td4 ; 
 int const* Te0 ; 
 int const* Te1 ; 
 int const* Te2 ; 
 int const* Te3 ; 
 scalar_t__* Te4 ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int* rcon ; 

__attribute__((used)) static void prefetch256(const void *table)
{
    volatile unsigned long *t=(void *)table,ret;
    unsigned long sum;
    int i;

    /* 32 is common least cache-line size */
    for (sum=0,i=0;i<256/sizeof(t[0]);i+=32/sizeof(t[0]))   sum ^= t[i];

    ret = sum;
}

int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
                        AES_KEY *key)
{

    u32 *rk;
    int i = 0;
    u32 temp;

    if (!userKey || !key)
        return -1;
    if (bits != 128 && bits != 192 && bits != 256)
        return -2;

    rk = key->rd_key;

    if (bits==128)
        key->rounds = 10;
    else if (bits==192)
        key->rounds = 12;
    else
        key->rounds = 14;

    rk[0] = GETU32(userKey     );
    rk[1] = GETU32(userKey +  4);
    rk[2] = GETU32(userKey +  8);
    rk[3] = GETU32(userKey + 12);
    if (bits == 128) {
        while (1) {
            temp  = rk[3];
            rk[4] = rk[0] ^
                ((u32)Te4[(temp >>  8) & 0xff]      ) ^
                ((u32)Te4[(temp >> 16) & 0xff] <<  8) ^
                ((u32)Te4[(temp >> 24)       ] << 16) ^
                ((u32)Te4[(temp      ) & 0xff] << 24) ^
                rcon[i];
            rk[5] = rk[1] ^ rk[4];
            rk[6] = rk[2] ^ rk[5];
            rk[7] = rk[3] ^ rk[6];
            if (++i == 10) {
                return 0;
            }
            rk += 4;
        }
    }
    rk[4] = GETU32(userKey + 16);
    rk[5] = GETU32(userKey + 20);
    if (bits == 192) {
        while (1) {
            temp = rk[ 5];
            rk[ 6] = rk[ 0] ^
                ((u32)Te4[(temp >>  8) & 0xff]      ) ^
                ((u32)Te4[(temp >> 16) & 0xff] <<  8) ^
                ((u32)Te4[(temp >> 24)       ] << 16) ^
                ((u32)Te4[(temp      ) & 0xff] << 24) ^
                rcon[i];
            rk[ 7] = rk[ 1] ^ rk[ 6];
            rk[ 8] = rk[ 2] ^ rk[ 7];
            rk[ 9] = rk[ 3] ^ rk[ 8];
            if (++i == 8) {
                return 0;
            }
            rk[10] = rk[ 4] ^ rk[ 9];
            rk[11] = rk[ 5] ^ rk[10];
            rk += 6;
        }
    }
    rk[6] = GETU32(userKey + 24);
    rk[7] = GETU32(userKey + 28);
    if (bits == 256) {
        while (1) {
            temp = rk[ 7];
            rk[ 8] = rk[ 0] ^
                ((u32)Te4[(temp >>  8) & 0xff]      ) ^
                ((u32)Te4[(temp >> 16) & 0xff] <<  8) ^
                ((u32)Te4[(temp >> 24)       ] << 16) ^
                ((u32)Te4[(temp      ) & 0xff] << 24) ^
                rcon[i];
            rk[ 9] = rk[ 1] ^ rk[ 8];
            rk[10] = rk[ 2] ^ rk[ 9];
            rk[11] = rk[ 3] ^ rk[10];
            if (++i == 7) {
                return 0;
            }
            temp = rk[11];
            rk[12] = rk[ 4] ^
                ((u32)Te4[(temp      ) & 0xff]      ) ^
                ((u32)Te4[(temp >>  8) & 0xff] <<  8) ^
                ((u32)Te4[(temp >> 16) & 0xff] << 16) ^
                ((u32)Te4[(temp >> 24)       ] << 24);
            rk[13] = rk[ 5] ^ rk[12];
            rk[14] = rk[ 6] ^ rk[13];
            rk[15] = rk[ 7] ^ rk[14];

            rk += 8;
            }
    }
    return 0;
}

int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
                        AES_KEY *key)
{

    u32 *rk;
    int i, j, status;
    u32 temp;

    /* first, start with an encryption schedule */
    status = AES_set_encrypt_key(userKey, bits, key);
    if (status < 0)
        return status;

    rk = key->rd_key;

    /* invert the order of the round keys: */
    for (i = 0, j = 4*(key->rounds); i < j; i += 4, j -= 4) {
        temp = rk[i    ]; rk[i    ] = rk[j    ]; rk[j    ] = temp;
        temp = rk[i + 1]; rk[i + 1] = rk[j + 1]; rk[j + 1] = temp;
        temp = rk[i + 2]; rk[i + 2] = rk[j + 2]; rk[j + 2] = temp;
        temp = rk[i + 3]; rk[i + 3] = rk[j + 3]; rk[j + 3] = temp;
    }
    /* apply the inverse MixColumn transform to all round keys but the first and the last: */
    for (i = 1; i < (key->rounds); i++) {
        rk += 4;
#if 1
        for (j = 0; j < 4; j++) {
            u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;

            tp1 = rk[j];
            m = tp1 & 0x80808080;
            tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp2 & 0x80808080;
            tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp4 & 0x80808080;
            tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            tp9 = tp8 ^ tp1;
            tpb = tp9 ^ tp2;
            tpd = tp9 ^ tp4;
            tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
            rk[j] = tpe ^ ROTATE(tpd,16) ^
                ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
            rk[j] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
                (tp9 >> 24) ^ (tp9 << 8) ^
                (tpb >> 8) ^ (tpb << 24);
#endif
        }
#else
        rk[0] =
            Td0[Te2[(rk[0]      ) & 0xff] & 0xff] ^
            Td1[Te2[(rk[0] >>  8) & 0xff] & 0xff] ^
            Td2[Te2[(rk[0] >> 16) & 0xff] & 0xff] ^
            Td3[Te2[(rk[0] >> 24)       ] & 0xff];
        rk[1] =
            Td0[Te2[(rk[1]      ) & 0xff] & 0xff] ^
            Td1[Te2[(rk[1] >>  8) & 0xff] & 0xff] ^
            Td2[Te2[(rk[1] >> 16) & 0xff] & 0xff] ^
            Td3[Te2[(rk[1] >> 24)       ] & 0xff];
        rk[2] =
            Td0[Te2[(rk[2]      ) & 0xff] & 0xff] ^
            Td1[Te2[(rk[2] >>  8) & 0xff] & 0xff] ^
            Td2[Te2[(rk[2] >> 16) & 0xff] & 0xff] ^
            Td3[Te2[(rk[2] >> 24)       ] & 0xff];
        rk[3] =
            Td0[Te2[(rk[3]      ) & 0xff] & 0xff] ^
            Td1[Te2[(rk[3] >>  8) & 0xff] & 0xff] ^
            Td2[Te2[(rk[3] >> 16) & 0xff] & 0xff] ^
            Td3[Te2[(rk[3] >> 24)       ] & 0xff];
#endif
    }
    return 0;
}

void AES_encrypt(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key)
{

    const u32 *rk;
    u32 s0, s1, s2, s3, t[4];
    int r;

    assert(in && out && key);
    rk = key->rd_key;

    /*
     * map byte array block to cipher state
     * and add initial round key:
     */
    s0 = GETU32(in     ) ^ rk[0];
    s1 = GETU32(in +  4) ^ rk[1];
    s2 = GETU32(in +  8) ^ rk[2];
    s3 = GETU32(in + 12) ^ rk[3];

#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
    prefetch256(Te4);

    t[0] = (u32)Te4[(s0      ) & 0xff]       ^
           (u32)Te4[(s1 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s2 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s3 >> 24)       ] << 24;
    t[1] = (u32)Te4[(s1      ) & 0xff]       ^
           (u32)Te4[(s2 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s3 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s0 >> 24)       ] << 24;
    t[2] = (u32)Te4[(s2      ) & 0xff]       ^
           (u32)Te4[(s3 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s0 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s1 >> 24)       ] << 24;
    t[3] = (u32)Te4[(s3      ) & 0xff]       ^
           (u32)Te4[(s0 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s1 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s2 >> 24)       ] << 24;

    /* now do the linear transform using words */
    {   int i;
        u32 r0, r1, r2;

        for (i = 0; i < 4; i++) {
            r0 = t[i];
            r1 = r0 & 0x80808080;
            r2 = ((r0 & 0x7f7f7f7f) << 1) ^
                ((r1 - (r1 >> 7)) & 0x1b1b1b1b);
#if defined(ROTATE)
            t[i] = r2 ^ ROTATE(r2,24) ^ ROTATE(r0,24) ^
                ROTATE(r0,16) ^ ROTATE(r0,8);
#else
            t[i] = r2 ^ ((r2 ^ r0) << 24) ^ ((r2 ^ r0) >> 8) ^
                (r0 << 16) ^ (r0 >> 16) ^
                (r0 << 8) ^ (r0 >> 24);
#endif
            t[i] ^= rk[4+i];
        }
    }
#else
    t[0] =  Te0[(s0      ) & 0xff] ^
        Te1[(s1 >>  8) & 0xff] ^
        Te2[(s2 >> 16) & 0xff] ^
        Te3[(s3 >> 24)       ] ^
        rk[4];
    t[1] =  Te0[(s1      ) & 0xff] ^
        Te1[(s2 >>  8) & 0xff] ^
        Te2[(s3 >> 16) & 0xff] ^
        Te3[(s0 >> 24)       ] ^
        rk[5];
    t[2] =  Te0[(s2      ) & 0xff] ^
        Te1[(s3 >>  8) & 0xff] ^
        Te2[(s0 >> 16) & 0xff] ^
        Te3[(s1 >> 24)       ] ^
        rk[6];
    t[3] =  Te0[(s3      ) & 0xff] ^
        Te1[(s0 >>  8) & 0xff] ^
        Te2[(s1 >> 16) & 0xff] ^
        Te3[(s2 >> 24)       ] ^
        rk[7];
#endif
    s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];

    /*
     * Nr - 2 full rounds:
     */
    for (rk+=8,r=key->rounds-2; r>0; rk+=4,r--) {
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
        t[0] = (u32)Te4[(s0      ) & 0xff]       ^
               (u32)Te4[(s1 >>  8) & 0xff] <<  8 ^
               (u32)Te4[(s2 >> 16) & 0xff] << 16 ^
               (u32)Te4[(s3 >> 24)       ] << 24;
        t[1] = (u32)Te4[(s1      ) & 0xff]       ^
               (u32)Te4[(s2 >>  8) & 0xff] <<  8 ^
               (u32)Te4[(s3 >> 16) & 0xff] << 16 ^
               (u32)Te4[(s0 >> 24)       ] << 24;
        t[2] = (u32)Te4[(s2      ) & 0xff]       ^
               (u32)Te4[(s3 >>  8) & 0xff] <<  8 ^
               (u32)Te4[(s0 >> 16) & 0xff] << 16 ^
               (u32)Te4[(s1 >> 24)       ] << 24;
        t[3] = (u32)Te4[(s3      ) & 0xff]       ^
               (u32)Te4[(s0 >>  8) & 0xff] <<  8 ^
               (u32)Te4[(s1 >> 16) & 0xff] << 16 ^
               (u32)Te4[(s2 >> 24)       ] << 24;

        /* now do the linear transform using words */
        {
            int i;
            u32 r0, r1, r2;

            for (i = 0; i < 4; i++) {
                r0 = t[i];
                r1 = r0 & 0x80808080;
                r2 = ((r0 & 0x7f7f7f7f) << 1) ^
                    ((r1 - (r1 >> 7)) & 0x1b1b1b1b);
#if defined(ROTATE)
                t[i] = r2 ^ ROTATE(r2,24) ^ ROTATE(r0,24) ^
                    ROTATE(r0,16) ^ ROTATE(r0,8);
#else
                t[i] = r2 ^ ((r2 ^ r0) << 24) ^ ((r2 ^ r0) >> 8) ^
                    (r0 << 16) ^ (r0 >> 16) ^
                    (r0 << 8) ^ (r0 >> 24);
#endif
                t[i] ^= rk[i];
            }
        }
#else
        t[0] =  Te0[(s0      ) & 0xff] ^
            Te1[(s1 >>  8) & 0xff] ^
            Te2[(s2 >> 16) & 0xff] ^
            Te3[(s3 >> 24)       ] ^
            rk[0];
        t[1] =  Te0[(s1      ) & 0xff] ^
            Te1[(s2 >>  8) & 0xff] ^
            Te2[(s3 >> 16) & 0xff] ^
            Te3[(s0 >> 24)       ] ^
            rk[1];
        t[2] =  Te0[(s2      ) & 0xff] ^
            Te1[(s3 >>  8) & 0xff] ^
            Te2[(s0 >> 16) & 0xff] ^
            Te3[(s1 >> 24)       ] ^
            rk[2];
        t[3] =  Te0[(s3      ) & 0xff] ^
            Te1[(s0 >>  8) & 0xff] ^
            Te2[(s1 >> 16) & 0xff] ^
            Te3[(s2 >> 24)       ] ^
            rk[3];
#endif
        s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
    }
    /*
     * apply last round and
     * map cipher state to byte array block:
     */
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
    prefetch256(Te4);

    *(u32*)(out+0) =
           (u32)Te4[(s0      ) & 0xff]       ^
           (u32)Te4[(s1 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s2 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s3 >> 24)       ] << 24 ^
        rk[0];
    *(u32*)(out+4) =
           (u32)Te4[(s1      ) & 0xff]       ^
           (u32)Te4[(s2 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s3 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s0 >> 24)       ] << 24 ^
        rk[1];
    *(u32*)(out+8) =
           (u32)Te4[(s2      ) & 0xff]       ^
           (u32)Te4[(s3 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s0 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s1 >> 24)       ] << 24 ^
        rk[2];
    *(u32*)(out+12) =
           (u32)Te4[(s3      ) & 0xff]       ^
           (u32)Te4[(s0 >>  8) & 0xff] <<  8 ^
           (u32)Te4[(s1 >> 16) & 0xff] << 16 ^
           (u32)Te4[(s2 >> 24)       ] << 24 ^
        rk[3];
#else
    *(u32*)(out+0) =
        (Te2[(s0      ) & 0xff] & 0x000000ffU) ^
        (Te3[(s1 >>  8) & 0xff] & 0x0000ff00U) ^
        (Te0[(s2 >> 16) & 0xff] & 0x00ff0000U) ^
        (Te1[(s3 >> 24)       ] & 0xff000000U) ^
        rk[0];
    *(u32*)(out+4) =
        (Te2[(s1      ) & 0xff] & 0x000000ffU) ^
        (Te3[(s2 >>  8) & 0xff] & 0x0000ff00U) ^
        (Te0[(s3 >> 16) & 0xff] & 0x00ff0000U) ^
        (Te1[(s0 >> 24)       ] & 0xff000000U) ^
        rk[1];
    *(u32*)(out+8) =
        (Te2[(s2      ) & 0xff] & 0x000000ffU) ^
        (Te3[(s3 >>  8) & 0xff] & 0x0000ff00U) ^
        (Te0[(s0 >> 16) & 0xff] & 0x00ff0000U) ^
        (Te1[(s1 >> 24)       ] & 0xff000000U) ^
        rk[2];
    *(u32*)(out+12) =
        (Te2[(s3      ) & 0xff] & 0x000000ffU) ^
        (Te3[(s0 >>  8) & 0xff] & 0x0000ff00U) ^
        (Te0[(s1 >> 16) & 0xff] & 0x00ff0000U) ^
        (Te1[(s2 >> 24)       ] & 0xff000000U) ^
        rk[3];
#endif
}

void AES_decrypt(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key)
{

    const u32 *rk;
    u32 s0, s1, s2, s3, t[4];
    int r;

    assert(in && out && key);
    rk = key->rd_key;

    /*
     * map byte array block to cipher state
     * and add initial round key:
     */
    s0 = GETU32(in     ) ^ rk[0];
    s1 = GETU32(in +  4) ^ rk[1];
    s2 = GETU32(in +  8) ^ rk[2];
    s3 = GETU32(in + 12) ^ rk[3];

#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
    prefetch256(Td4);

    t[0] = (u32)Td4[(s0      ) & 0xff]       ^
           (u32)Td4[(s3 >>  8) & 0xff] <<  8 ^
           (u32)Td4[(s2 >> 16) & 0xff] << 16 ^
           (u32)Td4[(s1 >> 24)       ] << 24;
    t[1] = (u32)Td4[(s1      ) & 0xff]       ^
           (u32)Td4[(s0 >>  8) & 0xff] <<  8 ^
           (u32)Td4[(s3 >> 16) & 0xff] << 16 ^
           (u32)Td4[(s2 >> 24)       ] << 24;
    t[2] = (u32)Td4[(s2      ) & 0xff]       ^
           (u32)Td4[(s1 >>  8) & 0xff] <<  8 ^
           (u32)Td4[(s0 >> 16) & 0xff] << 16 ^
           (u32)Td4[(s3 >> 24)       ] << 24;
    t[3] = (u32)Td4[(s3      ) & 0xff]       ^
           (u32)Td4[(s2 >>  8) & 0xff] <<  8 ^
           (u32)Td4[(s1 >> 16) & 0xff] << 16 ^
           (u32)Td4[(s0 >> 24)       ] << 24;

    /* now do the linear transform using words */
    {
        int i;
        u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;

        for (i = 0; i < 4; i++) {
            tp1 = t[i];
            m = tp1 & 0x80808080;
            tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp2 & 0x80808080;
            tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp4 & 0x80808080;
            tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            tp9 = tp8 ^ tp1;
            tpb = tp9 ^ tp2;
            tpd = tp9 ^ tp4;
            tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
            t[i] = tpe ^ ROTATE(tpd,16) ^
                ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
            t[i] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
                (tp9 >> 24) ^ (tp9 << 8) ^
                (tpb >> 8) ^ (tpb << 24);
#endif
            t[i] ^= rk[4+i];
        }
    }
#else
    t[0] =  Td0[(s0      ) & 0xff] ^
        Td1[(s3 >>  8) & 0xff] ^
        Td2[(s2 >> 16) & 0xff] ^
        Td3[(s1 >> 24)       ] ^
        rk[4];
    t[1] =  Td0[(s1      ) & 0xff] ^
        Td1[(s0 >>  8) & 0xff] ^
        Td2[(s3 >> 16) & 0xff] ^
        Td3[(s2 >> 24)       ] ^
        rk[5];
    t[2] =  Td0[(s2      ) & 0xff] ^
        Td1[(s1 >>  8) & 0xff] ^
        Td2[(s0 >> 16) & 0xff] ^
        Td3[(s3 >> 24)       ] ^
        rk[6];
    t[3] =  Td0[(s3      ) & 0xff] ^
        Td1[(s2 >>  8) & 0xff] ^
        Td2[(s1 >> 16) & 0xff] ^
        Td3[(s0 >> 24)       ] ^
        rk[7];
#endif
    s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];

    /*
     * Nr - 2 full rounds:
     */
    for (rk+=8,r=key->rounds-2; r>0; rk+=4,r--) {
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
        t[0] = (u32)Td4[(s0      ) & 0xff]       ^
               (u32)Td4[(s3 >>  8) & 0xff] <<  8 ^
               (u32)Td4[(s2 >> 16) & 0xff] << 16 ^
               (u32)Td4[(s1 >> 24)       ] << 24;
        t[1] = (u32)Td4[(s1      ) & 0xff]       ^
               (u32)Td4[(s0 >>  8) & 0xff] <<  8 ^
               (u32)Td4[(s3 >> 16) & 0xff] << 16 ^
               (u32)Td4[(s2 >> 24)       ] << 24;
        t[2] = (u32)Td4[(s2      ) & 0xff]       ^
               (u32)Td4[(s1 >>  8) & 0xff] <<  8 ^
               (u32)Td4[(s0 >> 16) & 0xff] << 16 ^
               (u32)Td4[(s3 >> 24)       ] << 24;
        t[3] = (u32)Td4[(s3      ) & 0xff]       ^
               (u32)Td4[(s2 >>  8) & 0xff] <<  8 ^
               (u32)Td4[(s1 >> 16) & 0xff] << 16 ^
               (u32)Td4[(s0 >> 24)       ] << 24;

    /* now do the linear transform using words */
    {
        int i;
        u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;

        for (i = 0; i < 4; i++) {
            tp1 = t[i];
            m = tp1 & 0x80808080;
            tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp2 & 0x80808080;
            tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            m = tp4 & 0x80808080;
            tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
                ((m - (m >> 7)) & 0x1b1b1b1b);
            tp9 = tp8 ^ tp1;
            tpb = tp9 ^ tp2;
            tpd = tp9 ^ tp4;
            tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
            t[i] = tpe ^ ROTATE(tpd,16) ^
                ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
            t[i] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
                (tp9 >> 24) ^ (tp9 << 8) ^
                (tpb >> 8) ^ (tpb << 24);
#endif
            t[i] ^= rk[i];
        }
    }
#else
    t[0] =  Td0[(s0      ) & 0xff] ^
        Td1[(s3 >>  8) & 0xff] ^
        Td2[(s2 >> 16) & 0xff] ^
        Td3[(s1 >> 24)       ] ^
        rk[0];
    t[1] =  Td0[(s1      ) & 0xff] ^
        Td1[(s0 >>  8) & 0xff] ^
        Td2[(s3 >> 16) & 0xff] ^
        Td3[(s2 >> 24)       ] ^
        rk[1];
    t[2] =  Td0[(s2      ) & 0xff] ^
        Td1[(s1 >>  8) & 0xff] ^
        Td2[(s0 >> 16) & 0xff] ^
        Td3[(s3 >> 24)       ] ^
        rk[2];
    t[3] =  Td0[(s3      ) & 0xff] ^
        Td1[(s2 >>  8) & 0xff] ^
        Td2[(s1 >> 16) & 0xff] ^
        Td3[(s0 >> 24)       ] ^
        rk[3];
#endif
    s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
    }
    /*
     * apply last round and
     * map cipher state to byte array block:
     */
    prefetch256(Td4);

    *(u32*)(out+0) =
        ((u32)Td4[(s0      ) & 0xff])    ^
        ((u32)Td4[(s3 >>  8) & 0xff] <<  8) ^
        ((u32)Td4[(s2 >> 16) & 0xff] << 16) ^
        ((u32)Td4[(s1 >> 24)       ] << 24) ^
        rk[0];
    *(u32*)(out+4) =
        ((u32)Td4[(s1      ) & 0xff])     ^
        ((u32)Td4[(s0 >>  8) & 0xff] <<  8) ^
        ((u32)Td4[(s3 >> 16) & 0xff] << 16) ^
        ((u32)Td4[(s2 >> 24)       ] << 24) ^
        rk[1];
    *(u32*)(out+8) =
        ((u32)Td4[(s2      ) & 0xff])     ^
        ((u32)Td4[(s1 >>  8) & 0xff] <<  8) ^
        ((u32)Td4[(s0 >> 16) & 0xff] << 16) ^
        ((u32)Td4[(s3 >> 24)       ] << 24) ^
        rk[2];
    *(u32*)(out+12) =
        ((u32)Td4[(s3      ) & 0xff])     ^
        ((u32)Td4[(s2 >>  8) & 0xff] <<  8) ^
        ((u32)Td4[(s1 >> 16) & 0xff] << 16) ^
        ((u32)Td4[(s0 >> 24)       ] << 24) ^
        rk[3];
}

