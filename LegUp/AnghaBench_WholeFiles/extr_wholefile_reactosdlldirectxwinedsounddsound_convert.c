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
typedef  int WORD ;
typedef  int ULONG ;
typedef  int UINT ;
typedef  int SHORT ;
typedef  int LONGLONG ;
typedef  int INT8 ;
typedef  int INT32 ;
typedef  int INT16 ;
typedef  int INT ;
typedef  int DWORD ;
typedef  int BYTE ;

/* Variables and functions */
 int DSOUND_FREQSHIFT ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int le16 (int const) ; 
 int le32 (int const) ; 

__attribute__((used)) static inline void src_advance(const void **src, UINT stride, INT *count, UINT *freqAcc, UINT adj)
{
    *freqAcc += adj;
    if (*freqAcc >= (1 << DSOUND_FREQSHIFT))
    {
        ULONG adv = (*freqAcc >> DSOUND_FREQSHIFT);
        *freqAcc &= (1 << DSOUND_FREQSHIFT) - 1;
        *(const char **)src += adv * stride;
        *count -= adv;
    }
}

__attribute__((used)) static void convert_8_to_8 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        *(BYTE *)dst = *(const BYTE *)src;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_8_to_16 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        WORD dest = *(const BYTE *)src, *dest16 = dst;
        *dest16 = le16(dest * 257 - 32768);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_8_to_24 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        BYTE dest = *(const BYTE *)src;
        BYTE *dest24 = dst;
        dest24[0] = dest;
        dest24[1] = dest;
        dest24[2] = dest - 0x80;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_8_to_32 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD dest = *(const BYTE *)src, *dest32 = dst;
        *dest32 = le32(dest * 16843009 - 2147483648U);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_16_to_8 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        BYTE *dst8 = dst;
        *dst8 = (le16(*(const WORD *)src)) / 256;
        *dst8 -= 0x80;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_16_to_16 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        *(WORD *)dst = *(const WORD *)src;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_16_to_24 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        WORD dest = le16(*(const WORD *)src);
        BYTE *dest24 = dst;

        dest24[0] = dest / 256;
        dest24[1] = dest;
        dest24[2] = dest / 256;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_16_to_32 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD dest = *(const WORD *)src, *dest32 = dst;
        *dest32 = dest * 65537;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_24_to_8 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        BYTE *dst8 = dst;
        *dst8 = ((const BYTE *)src)[2];

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_24_to_16 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        WORD *dest16 = dst;
        const BYTE *source = src;
        *dest16 = le16(source[2] * 256 + source[1]);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_24_to_24 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        BYTE *dest24 = dst;
        const BYTE *src24 = src;

        dest24[0] = src24[0];
        dest24[1] = src24[1];
        dest24[2] = src24[2];

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_24_to_32 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD *dest32 = dst;
        const BYTE *source = src;
        *dest32 = le32(source[2] * 16777217 + source[1] * 65536 + source[0] * 256);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_32_to_8 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        BYTE *dst8 = dst;
        *dst8 = (le32(*(const DWORD *)src) / 16777216);
        *dst8 -= 0x80;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_32_to_16 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        WORD *dest16 = dst;
        *dest16 = le16(le32(*(const DWORD *)src) / 65536);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_32_to_24 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD dest = le32(*(const DWORD *)src);
        BYTE *dest24 = dst;

        dest24[0] = dest / 256;
        dest24[1] = dest / 65536;
        dest24[2] = dest / 16777216;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_32_to_32 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD *dest = dst;
        *dest = *(const DWORD *)src;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_ieee_32_to_8 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD src_le = le32(*(DWORD *) src);
        float v = *((float *) &src_le);
        INT8 d = 0;

        if (v < -1.0f)
            d = -128;
        else if (v >  1.0f)
            d = 127;
        else
            d = v * 127.5f - 0.5f;

        *(BYTE *) dst = d ^ 0x80;

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_ieee_32_to_16 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD src_le = le32(*(DWORD *) src);
        float v = *((float *) &src_le);

        INT16 *d = (INT16 *) dst;

        if (v < -1.0f)
            *d = -32768;
        else if (v >  1.0f)
            *d = 32767;
        else
            *d = v * 32767.5f - 0.5f;

        *d = le16(*d);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_ieee_32_to_24 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD src_le = le32(*(DWORD *) src);
        float v = *((float *) &src_le);
        BYTE *dest24 = dst;

        if (v < -1.0f)
        {
            dest24[0] = 0;
            dest24[1] = 0;
            dest24[2] = 0x80;
        }
        else if (v > 1.0f)
        {
            dest24[0] = 0xff;
            dest24[1] = 0xff;
            dest24[2] = 0x7f;
        }
        else if (v < 0.0f)
        {
            dest24[0] = v * 8388608.0f;
            dest24[1] = v * 32768.0f;
            dest24[2] = v * 128.0f;
        }
        else if (v >= 0.0f)
        {
            dest24[0] = v * 8388608.0f;
            dest24[1] = v * 32768.0f;
            dest24[2] = v * 127.0f;
        }

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void convert_ieee_32_to_32 (const void *src, void *dst, UINT src_stride,
        UINT dst_stride, INT count, UINT freqAcc, UINT adj)
{
    while (count > 0)
    {
        DWORD src_le = le32(*(DWORD *) src);
        float v = *((float *) &src_le);
        INT32 *d = (INT32 *) dst;

        if (v < -1.0f)
            *d = -2147483647 - 1; /* silence warning */
        else if (v >  1.0f)
            *d = 2147483647;
        else
            *d = v * 2147483647.5f - 0.5f;

        *d = le32(*d);

        dst = (char *)dst + dst_stride;
        src_advance(&src, src_stride, &count, &freqAcc, adj);
    }
}

__attribute__((used)) static void mix8(signed char *src, INT *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    while (len--)
        /* 8-bit WAV is unsigned, it's here converted to signed, normalize function will convert it back again */
        *(dst++) += (signed char)((BYTE)*(src++) - (BYTE)0x80);
}

__attribute__((used)) static void mix16(SHORT *src, INT *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 2;
    while (len--)
    {
        *dst += le16(*src);
        ++dst; ++src;
    }
}

__attribute__((used)) static void mix24(BYTE *src, INT *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 3;
    while (len--)
    {
        DWORD field;
        field = ((DWORD)src[2] << 16) + ((DWORD)src[1] << 8) + (DWORD)src[0];
        if (src[2] & 0x80)
            field |= 0xFF000000U;
        *(dst++) += field;
        ++src;
    }
}

__attribute__((used)) static void mix32(INT *src, LONGLONG *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 4;
    while (len--)
        *(dst++) += le32(*(src++));
}

__attribute__((used)) static void norm8(INT *src, signed char *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    while (len--)
    {
        *dst = (*src) + 0x80;
        if (*src < -0x80)
            *dst = 0;
        else if (*src > 0x7f)
            *dst = 0xff;
        ++dst;
        ++src;
    }
}

__attribute__((used)) static void norm16(INT *src, SHORT *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 2;
    while (len--)
    {
        *dst = le16(*src);
        if (*src <= -0x8000)
            *dst = le16(0x8000);
        else if (*src > 0x7fff)
            *dst = le16(0x7fff);
        ++dst;
        ++src;
    }
}

__attribute__((used)) static void norm24(INT *src, BYTE *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 3;
    while (len--)
    {
        if (*src <= -0x800000)
        {
            dst[0] = 0;
            dst[1] = 0;
            dst[2] = 0x80;
        }
        else if (*src > 0x7fffff)
        {
            dst[0] = 0xff;
            dst[1] = 0xff;
            dst[2] = 0x7f;
        }
        else
        {
            dst[0] = *src;
            dst[1] = *src >> 8;
            dst[2] = *src >> 16;
        }
        ++dst;
        ++src;
    }
}

__attribute__((used)) static void norm32(LONGLONG *src, INT *dst, unsigned len)
{
    TRACE("%p - %p %d\n", src, dst, len);
    len /= 4;
    while (len--)
    {
        *dst = le32(*src);
        if (*src <= -(LONGLONG)0x80000000)
            *dst = le32(0x80000000);
        else if (*src > 0x7fffffff)
            *dst = le32(0x7fffffff);
        ++dst;
        ++src;
    }
}

