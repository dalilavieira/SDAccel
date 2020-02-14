#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int ulong64 ;
typedef  int ulong32 ;
struct TYPE_9__ {int* ek; int* dk; } ;
typedef  TYPE_1__ des_key ;
struct TYPE_10__ {int** ek; int** dk; } ;
typedef  TYPE_2__ des3_key ;

/* Variables and functions */
 int CRYPT_INVALID_KEYSIZE ; 
 int CRYPT_INVALID_ROUNDS ; 
 int CRYPT_OK ; 
 short DE1 ; 
 short EN0 ; 
 int /*<<< orphan*/  LOAD32H (int,unsigned char const*) ; 
 int* SP1 ; 
 int* SP2 ; 
 int* SP3 ; 
 int* SP4 ; 
 int* SP5 ; 
 int* SP6 ; 
 int* SP7 ; 
 int* SP8 ; 
 int /*<<< orphan*/  STORE32H (int,unsigned char*) ; 
 int* bigbyte ; 
 size_t byte (int,int) ; 
 unsigned char const* bytebit ; 
static  void cookey (int const*,int*) ; 
 int** des_fp ; 
 int** des_ip ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 scalar_t__* pc1 ; 
 scalar_t__* pc2 ; 
 scalar_t__* totrot ; 

__attribute__((used)) static inline unsigned ROR(unsigned word, int i)
{
   __asm__("rorl %%cl,%0"
      :"=r" (word)
      :"0" (word),"c" (i));
   return word;
}

__attribute__((used)) static void deskey(const unsigned char *key, short edf, ulong32 *keyout)
{
    ulong32 i, j, l, m, n, kn[32];
    unsigned char pc1m[56], pcr[56];

    for (j=0; j < 56; j++) {
        l = (ulong32)pc1[j];
        m = l & 7;
        pc1m[j] = (unsigned char)((key[l >> 3U] & bytebit[m]) == bytebit[m] ? 1 : 0);
    }

    for (i=0; i < 16; i++) {
        if (edf == DE1) {
           m = (15 - i) << 1;
        } else {
           m = i << 1;
        }
        n = m + 1;
        kn[m] = kn[n] = 0L;
        for (j=0; j < 28; j++) {
            l = j + (ulong32)totrot[i];
            if (l < 28) {
               pcr[j] = pc1m[l];
            } else {
               pcr[j] = pc1m[l - 28];
            }
        }
        for (/*j = 28*/; j < 56; j++) {
            l = j + (ulong32)totrot[i];
            if (l < 56) {
               pcr[j] = pc1m[l];
            } else {
               pcr[j] = pc1m[l - 28];
            }
        }
        for (j=0; j < 24; j++)  {
            if ((int)pcr[(int)pc2[j]] != 0) {
               kn[m] |= bigbyte[j];
            }
            if ((int)pcr[(int)pc2[j+24]] != 0) {
               kn[n] |= bigbyte[j];
            }
        }
    }

    cookey(kn, keyout);
}

__attribute__((used)) static void cookey(const ulong32 *raw1, ulong32 *keyout)
{
    ulong32 *cook;
    const ulong32 *raw0;
    ulong32 dough[32];
    int i;

    cook = dough;
    for(i=0; i < 16; i++, raw1++)
    {
        raw0 = raw1++;
        *cook    = (*raw0 & 0x00fc0000L) << 6;
        *cook   |= (*raw0 & 0x00000fc0L) << 10;
        *cook   |= (*raw1 & 0x00fc0000L) >> 10;
        *cook++ |= (*raw1 & 0x00000fc0L) >> 6;
        *cook    = (*raw0 & 0x0003f000L) << 12;
        *cook   |= (*raw0 & 0x0000003fL) << 16;
        *cook   |= (*raw1 & 0x0003f000L) >> 4;
        *cook++ |= (*raw1 & 0x0000003fL);
    }

    memcpy(keyout, dough, sizeof dough);
}

__attribute__((used)) static void desfunc(ulong32 *block, const ulong32 *keys)
{
    ulong64 tmp;
    ulong32 work, right, leftt;
    int cur_round;

    leftt = block[0];
    right = block[1];

    tmp = des_ip[0][byte(leftt, 0)] ^
          des_ip[1][byte(leftt, 1)] ^
          des_ip[2][byte(leftt, 2)] ^
          des_ip[3][byte(leftt, 3)] ^
          des_ip[4][byte(right, 0)] ^
          des_ip[5][byte(right, 1)] ^
          des_ip[6][byte(right, 2)] ^
          des_ip[7][byte(right, 3)];
    leftt = (ulong32)(tmp >> 32);
    right = (ulong32)(tmp & 0xFFFFFFFFUL);

    for (cur_round = 0; cur_round < 8; cur_round++) {
        work  = ROR(right, 4) ^ *keys++;
        leftt ^= SP7[work        & 0x3fL]
              ^ SP5[(work >>  8) & 0x3fL]
              ^ SP3[(work >> 16) & 0x3fL]
              ^ SP1[(work >> 24) & 0x3fL];
        work  = right ^ *keys++;
        leftt ^= SP8[ work        & 0x3fL]
              ^  SP6[(work >>  8) & 0x3fL]
              ^  SP4[(work >> 16) & 0x3fL]
              ^  SP2[(work >> 24) & 0x3fL];

        work = ROR(leftt, 4) ^ *keys++;
        right ^= SP7[ work        & 0x3fL]
              ^  SP5[(work >>  8) & 0x3fL]
              ^  SP3[(work >> 16) & 0x3fL]
              ^  SP1[(work >> 24) & 0x3fL];
        work  = leftt ^ *keys++;
        right ^= SP8[ work        & 0x3fL]
              ^  SP6[(work >>  8) & 0x3fL]
              ^  SP4[(work >> 16) & 0x3fL]
              ^  SP2[(work >> 24) & 0x3fL];
    }

    tmp = des_fp[0][byte(leftt, 0)] ^
          des_fp[1][byte(leftt, 1)] ^
          des_fp[2][byte(leftt, 2)] ^
          des_fp[3][byte(leftt, 3)] ^
          des_fp[4][byte(right, 0)] ^
          des_fp[5][byte(right, 1)] ^
          des_fp[6][byte(right, 2)] ^
          des_fp[7][byte(right, 3)];
    leftt = (ulong32)(tmp >> 32);
    right = (ulong32)(tmp & 0xFFFFFFFFUL);
    
    block[0] = right;
    block[1] = leftt;
}

int des_setup(const unsigned char *key, int keylen, int num_rounds, des_key *des)
{
    if (num_rounds != 0 && num_rounds != 16) {
        return CRYPT_INVALID_ROUNDS;
    }

    if (keylen != 8) {
        return CRYPT_INVALID_KEYSIZE;
    }

    deskey(key, EN0, des->ek);
    deskey(key, DE1, des->dk);

    return CRYPT_OK;
}

int des3_setup(const unsigned char *key, int keylen, int num_rounds, des3_key *des3)
{
    if(num_rounds != 0 && num_rounds != 16) {
        return CRYPT_INVALID_ROUNDS;
    }

    if (keylen != 24) {
        return CRYPT_INVALID_KEYSIZE;
    }

    deskey(key,    EN0, des3->ek[0]);
    deskey(key+8,  DE1, des3->ek[1]);
    deskey(key+16, EN0, des3->ek[2]);

    deskey(key,    DE1, des3->dk[2]);
    deskey(key+8,  EN0, des3->dk[1]);
    deskey(key+16, DE1, des3->dk[0]);

    return CRYPT_OK;
}

void des_ecb_encrypt(const unsigned char *pt, unsigned char *ct, const des_key *des)
{
    ulong32 work[2];
    LOAD32H(work[0], pt+0);
    LOAD32H(work[1], pt+4);
    desfunc(work, des->ek);
    STORE32H(work[0],ct+0);
    STORE32H(work[1],ct+4);
}

void des_ecb_decrypt(const unsigned char *ct, unsigned char *pt, const des_key *des)
{
    ulong32 work[2];
    LOAD32H(work[0], ct+0);
    LOAD32H(work[1], ct+4);
    desfunc(work, des->dk);
    STORE32H(work[0],pt+0);
    STORE32H(work[1],pt+4);
}

void des3_ecb_encrypt(const unsigned char *pt, unsigned char *ct, const des3_key *des3)
{
    ulong32 work[2];
    LOAD32H(work[0], pt+0);
    LOAD32H(work[1], pt+4);
    desfunc(work, des3->ek[0]);
    desfunc(work, des3->ek[1]);
    desfunc(work, des3->ek[2]);
    STORE32H(work[0],ct+0);
    STORE32H(work[1],ct+4);
}

void des3_ecb_decrypt(const unsigned char *ct, unsigned char *pt, const des3_key *des3)
{
    ulong32 work[2];
    LOAD32H(work[0], ct+0);
    LOAD32H(work[1], ct+4);
    desfunc(work, des3->dk[0]);
    desfunc(work, des3->dk[1]);
    desfunc(work, des3->dk[2]);
    STORE32H(work[0],pt+0);
    STORE32H(work[1],pt+4);
}

