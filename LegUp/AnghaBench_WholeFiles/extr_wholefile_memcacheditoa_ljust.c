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
typedef  unsigned int uint64_t ;
typedef  unsigned int uint32_t ;
typedef  char const uint16_t ;
typedef  scalar_t__ int64_t ;
typedef  scalar_t__ int32_t ;

/* Variables and functions */
 scalar_t__ lut ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 

__attribute__((used)) static inline char* out2(const int d, char* p) {
    memcpy(p, &((uint16_t *)lut)[d], 2);
    return p + 2;
}

__attribute__((used)) static inline char* out1(const char in, char* p) {
    memcpy(p, &in, 1);
    return p + 1;
}

__attribute__((used)) static inline int digits( uint32_t u, unsigned k, int* d, char** p, int n ) {
    if (u < k*10) {
        *d = u / k;
        *p = out1('0'+*d, *p);
        --n;
    }
    return n;
}

__attribute__((used)) static inline char* itoa(uint32_t u, char* p, int d, int n) {
    switch(n) {
    case 10: d  = u / 100000000; p = out2( d, p );
    case  9: u -= d * 100000000;
    case  8: d  = u /   1000000; p = out2( d, p );
    case  7: u -= d *   1000000;
    case  6: d  = u /     10000; p = out2( d, p );
    case  5: u -= d *     10000;
    case  4: d  = u /       100; p = out2( d, p );
    case  3: u -= d *       100;
    case  2: d  = u /         1; p = out2( d, p );
    case  1: ;
    }
    *p = '\0';
    return p;
}

char* itoa_u32(uint32_t u, char* p) {
    int d = 0,n;
         if (u >=100000000) n = digits(u, 100000000, &d, &p, 10);
    else if (u <       100) n = digits(u,         1, &d, &p,  2);
    else if (u <     10000) n = digits(u,       100, &d, &p,  4);
    else if (u <   1000000) n = digits(u,     10000, &d, &p,  6);
    else                    n = digits(u,   1000000, &d, &p,  8);
    return itoa( u, p, d, n );
}

char* itoa_32(int32_t i, char* p) {
    uint32_t u = i;
    if (i < 0) {
        *p++ = '-';
        u = -u;
    }
    return itoa_u32(u, p);
}

char* itoa_u64(uint64_t u, char* p) {
    int d;

    uint32_t lower = (uint32_t)u;
    if (lower == u) return itoa_u32(lower, p);

    uint64_t upper = u / 1000000000;
    p = itoa_u64(upper, p);
    lower = u - (upper * 1000000000);
    d = lower / 100000000;
    p = out1('0'+d,p);
    return itoa( lower, p, d, 9 );
}

char* itoa_64(int64_t i, char* p) {
    uint64_t u = i;
    if (i < 0) {
        *p++ = '-';
        u = -u;
    }
    return itoa_u64(u, p);
}

