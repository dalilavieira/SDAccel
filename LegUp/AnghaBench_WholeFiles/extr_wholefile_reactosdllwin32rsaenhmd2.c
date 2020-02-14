#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {unsigned char* chksum; unsigned char* buf; int* X; int curlen; } ;
typedef  TYPE_1__ md2_state ;

/* Variables and functions */
 int CRYPT_INVALID_ARG ; 
 int CRYPT_OK ; 
 unsigned long MIN (unsigned long,int) ; 
 int* PI_SUBST ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline unsigned ROR(unsigned word, int i)
{
   __asm__("rorl %%cl,%0"
      :"=r" (word)
      :"0" (word),"c" (i));
   return word;
}

__attribute__((used)) static void md2_update_chksum(md2_state *md2)
{
   int j;
   unsigned char L;
   L = md2->chksum[15];
   for (j = 0; j < 16; j++) {

/* caution, the RFC says its "C[j] = S[M[i*16+j] xor L]" but the reference source code [and test vectors] say 
   otherwise.
*/
       L = (md2->chksum[j] ^= PI_SUBST[(int)(md2->buf[j] ^ L)] & 255);
   }
}

__attribute__((used)) static void md2_compress(md2_state *md2)
{
   int j, k;
   unsigned char t;
   
   /* copy block */
   for (j = 0; j < 16; j++) {
       md2->X[16+j] = md2->buf[j];
       md2->X[32+j] = md2->X[j] ^ md2->X[16+j];
   }

   t = 0;

   /* do 18 rounds */
   for (j = 0; j < 18; j++) {
       for (k = 0; k < 48; k++) {
           t = (md2->X[k] ^= PI_SUBST[(int)(t & 255)]);
       }
       t = (t + (unsigned char)j) & 255;
   }
}

int md2_init(md2_state *md2)
{
   /* MD2 uses a zero'ed state... */
   memset(md2->X, 0, sizeof(md2->X));
   memset(md2->chksum, 0, sizeof(md2->chksum));
   memset(md2->buf, 0, sizeof(md2->buf));
   md2->curlen = 0;
   return CRYPT_OK;
}

int md2_process(md2_state *md2, const unsigned char *buf, unsigned long len)
{
    unsigned long n;
    
    if (md2->curlen > sizeof(md2->buf)) {                            
       return CRYPT_INVALID_ARG;                                                           
    }                                                                                       
    while (len > 0) {
        n = MIN(len, (16 - md2->curlen));
        memcpy(md2->buf + md2->curlen, buf, (size_t)n);
        md2->curlen += n;
        buf         += n;
        len         -= n;

        /* is 16 bytes full? */
        if (md2->curlen == 16) {
            md2_compress(md2);
            md2_update_chksum(md2);
            md2->curlen = 0;
        }
    }
    return CRYPT_OK;
}

int md2_done(md2_state * md2, unsigned char *hash)
{
    unsigned long i, k;

    if (md2->curlen >= sizeof(md2->buf)) {
       return CRYPT_INVALID_ARG;
    }

    /* pad the message */
    k = 16 - md2->curlen;
    for (i = md2->curlen; i < 16; i++) {
        md2->buf[i] = (unsigned char)k;
    }

    /* hash and update */
    md2_compress(md2);
    md2_update_chksum(md2);

    /* hash checksum */
    memcpy(md2->buf, md2->chksum, 16);
    md2_compress(md2);

    /* output is lower 16 bytes of X */
    memcpy(hash, md2->X, 16);

    return CRYPT_OK;
}

