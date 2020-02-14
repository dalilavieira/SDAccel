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
typedef  int /*<<< orphan*/  (* block128_f ) (unsigned char*,unsigned char*,void const*) ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (unsigned char*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub2 (unsigned char*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub3 (unsigned char*,unsigned char*,void const*) ; 

void CRYPTO_ofb128_encrypt(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16], int *num, block128_f block)
{
    unsigned int n;
    size_t l = 0;

    n = *num;

#if !defined(OPENSSL_SMALL_FOOTPRINT)
    if (16 % sizeof(size_t) == 0) { /* always true actually */
        do {
            while (n && len) {
                *(out++) = *(in++) ^ ivec[n];
                --len;
                n = (n + 1) % 16;
            }
# if defined(STRICT_ALIGNMENT)
            if (((size_t)in | (size_t)out | (size_t)ivec) % sizeof(size_t) !=
                0)
                break;
# endif
            while (len >= 16) {
                (*block) (ivec, ivec, key);
                for (; n < 16; n += sizeof(size_t))
                    *(size_t *)(out + n) =
                        *(size_t *)(in + n) ^ *(size_t *)(ivec + n);
                len -= 16;
                out += 16;
                in += 16;
                n = 0;
            }
            if (len) {
                (*block) (ivec, ivec, key);
                while (len--) {
                    out[n] = in[n] ^ ivec[n];
                    ++n;
                }
            }
            *num = n;
            return;
        } while (0);
    }
    /* the rest would be commonly eliminated by x86* compiler */
#endif
    while (l < len) {
        if (n == 0) {
            (*block) (ivec, ivec, key);
        }
        out[l] = in[l] ^ ivec[n];
        ++l;
        n = (n + 1) % 16;
    }

    *num = n;
}

