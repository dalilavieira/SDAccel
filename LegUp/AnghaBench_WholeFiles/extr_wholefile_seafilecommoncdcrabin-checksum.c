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
typedef  char u_int ;
typedef  int u_char ;

/* Variables and functions */
 int INT64 (int) ; 
 int MSB64 ; 
 int* T ; 
 unsigned int* U ; 
 char* bytemsb ; 
 int poly ; 
 unsigned int rabin_rolling_checksum (unsigned int,int,char,char) ; 
 int shift ; 

__attribute__((used)) static inline u_int fls32 (u_int32_t v)
{
    if (v & 0xffff0000) {
        if (v & 0xff000000)
            return 24 + bytemsb[v>>24];
        else
            return 16 + bytemsb[v>>16];
    }
    if (v & 0x0000ff00)
        return 8 + bytemsb[v>>8];
    else
        return bytemsb[v];
}

__attribute__((used)) static inline char fls64 (u_int64_t v)
{
    u_int32_t h;
    if ((h = v >> 32))
        return 32 + fls32 (h);
    else
        return fls32 ((u_int32_t) v);
}

u_int64_t polymod (u_int64_t nh, u_int64_t nl, u_int64_t d)
{
    int i = 0;
    int k = fls64 (d) - 1;

    d <<= 63 - k;

    if (nh) {
        if (nh & MSB64)
            nh ^= d;
        for (i = 62; i >= 0; i--)
            if (nh & ((u_int64_t) 1) << i) {
                nh ^= d >> (63 - i);
                nl ^= d << (i + 1);
            }
    }
    for (i = 63; i >= k; i--)
    {  
        if (nl & INT64 (1) << i)
            nl ^= d >> (63 - i);
    }
  
    return nl;
}

void polymult (u_int64_t *php, u_int64_t *plp, u_int64_t x, u_int64_t y)
{
    int i;
    u_int64_t ph = 0, pl = 0;
    if (x & 1)
        pl = y;
    for (i = 1; i < 64; i++)
        if (x & (INT64 (1) << i)) {
            ph ^= y >> (64 - i);
            pl ^= y << i;
        }
    if (php)
        *php = ph;
    if (plp)
        *plp = pl;
}

u_int64_t polymmult (u_int64_t x, u_int64_t y, u_int64_t d)
{
    u_int64_t h, l;
    polymult (&h, &l, x, y);
    return polymod (h, l, d);
}

__attribute__((used)) static u_int64_t append8 (u_int64_t p, u_char m)
{
    return ((p << 8) | m) ^ T[p >> shift];
}

__attribute__((used)) static void calcT (u_int64_t poly)
{
    int j = 0;
    int xshift = fls64 (poly) - 1;
    shift = xshift - 8;
    u_int64_t T1 = polymod (0, INT64 (1) << xshift, poly);
    for (j = 0; j < 256; j++) {
        T[j] = polymmult (j, T1, poly) | ((u_int64_t) j << xshift);
    }
}

__attribute__((used)) static void calcU(int size)
{
    int i;
    u_int64_t sizeshift = 1;
    for (i = 1; i < size; i++)
        sizeshift = append8 (sizeshift, 0);
    for (i = 0; i < 256; i++)
        U[i] = polymmult (i, sizeshift, poly);
}

void rabin_init(int len)
{
    calcT(poly);
    calcU(len);
}

unsigned int rabin_checksum(char *buf, int len)
{
    int i;
    unsigned int sum = 0;
    for (i = 0; i < len; ++i) {
        sum = rabin_rolling_checksum (sum, len, 0, buf[i]);
    }
    return sum;
}

unsigned int rabin_rolling_checksum(unsigned int csum, int len,
                                    char c1, char c2)
{
    return append8(csum ^ U[(unsigned char)c1], c2);
}

