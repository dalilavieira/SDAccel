#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {unsigned short def_char; } ;
struct dbcs_table {unsigned char* cp2uni_leadbytes; scalar_t__* cp2uni; unsigned short* uni2cp_low; unsigned short* uni2cp_high; TYPE_2__ info; } ;
struct TYPE_4__ {int def_char; } ;
struct sbcs_table {scalar_t__* cp2uni; unsigned char* uni2cp_low; unsigned short* uni2cp_high; TYPE_1__ info; } ;
struct TYPE_6__ {int char_size; } ;
union cptable {struct dbcs_table dbcs; struct sbcs_table sbcs; TYPE_3__ info; } ;
typedef  scalar_t__ WCHAR ;

/* Variables and functions */
 int WC_COMPOSITECHECK ; 
 int WC_DEFAULTCHAR ; 
 int WC_DISCARDNS ; 
 int WC_NO_BEST_FIT_CHARS ; 
 scalar_t__ wine_compose (scalar_t__ const*) ; 

__attribute__((used)) static inline int is_valid_sbcs_mapping( const struct sbcs_table *table, int flags,
                                         WCHAR wch, unsigned char ch )
{
    if ((flags & WC_NO_BEST_FIT_CHARS) || ch == (unsigned char)table->info.def_char)
        return (table->cp2uni[ch] == wch);
    return 1;
}

__attribute__((used)) static int get_length_sbcs( const struct sbcs_table *table, int flags,
                            const WCHAR *src, unsigned int srclen, int *used )
{
    const unsigned char  * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    int ret, tmp;
    WCHAR composed;

    if (!used) used = &tmp;  /* avoid checking on every char */
    *used = 0;

    for (ret = 0; srclen; ret++, src++, srclen--)
    {
        WCHAR wch = *src;
        unsigned char ch;

        if ((flags & WC_COMPOSITECHECK) && (srclen > 1) && (composed = wine_compose(src)))
        {
            /* now check if we can use the composed char */
            ch = uni2cp_low[uni2cp_high[composed >> 8] + (composed & 0xff)];
            if (is_valid_sbcs_mapping( table, flags, composed, ch ))
            {
                /* we have a good mapping, use it */
                src++;
                srclen--;
                continue;
            }
            /* no mapping for the composed char, check the other flags */
            if (flags & WC_DEFAULTCHAR) /* use the default char instead */
            {
                *used = 1;
                src++;  /* skip the non-spacing char */
                srclen--;
                continue;
            }
            if (flags & WC_DISCARDNS) /* skip the second char of the composition */
            {
                src++;
                srclen--;
            }
            /* WC_SEPCHARS is the default */
        }
        if (!*used)
        {
            ch = uni2cp_low[uni2cp_high[wch >> 8] + (wch & 0xff)];
            *used = !is_valid_sbcs_mapping( table, flags, wch, ch );
        }
    }
    return ret;
}

__attribute__((used)) static inline int wcstombs_sbcs( const struct sbcs_table *table,
                                 const WCHAR *src, unsigned int srclen,
                                 char *dst, unsigned int dstlen )
{
    const unsigned char  * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    int ret = srclen;

    if (dstlen < srclen)
    {
        /* buffer too small: fill it up to dstlen and return error */
        srclen = dstlen;
        ret = -1;
    }

    while (srclen >= 16)
    {
        dst[0]  = uni2cp_low[uni2cp_high[src[0]  >> 8] + (src[0]  & 0xff)];
        dst[1]  = uni2cp_low[uni2cp_high[src[1]  >> 8] + (src[1]  & 0xff)];
        dst[2]  = uni2cp_low[uni2cp_high[src[2]  >> 8] + (src[2]  & 0xff)];
        dst[3]  = uni2cp_low[uni2cp_high[src[3]  >> 8] + (src[3]  & 0xff)];
        dst[4]  = uni2cp_low[uni2cp_high[src[4]  >> 8] + (src[4]  & 0xff)];
        dst[5]  = uni2cp_low[uni2cp_high[src[5]  >> 8] + (src[5]  & 0xff)];
        dst[6]  = uni2cp_low[uni2cp_high[src[6]  >> 8] + (src[6]  & 0xff)];
        dst[7]  = uni2cp_low[uni2cp_high[src[7]  >> 8] + (src[7]  & 0xff)];
        dst[8]  = uni2cp_low[uni2cp_high[src[8]  >> 8] + (src[8]  & 0xff)];
        dst[9]  = uni2cp_low[uni2cp_high[src[9]  >> 8] + (src[9]  & 0xff)];
        dst[10] = uni2cp_low[uni2cp_high[src[10] >> 8] + (src[10] & 0xff)];
        dst[11] = uni2cp_low[uni2cp_high[src[11] >> 8] + (src[11] & 0xff)];
        dst[12] = uni2cp_low[uni2cp_high[src[12] >> 8] + (src[12] & 0xff)];
        dst[13] = uni2cp_low[uni2cp_high[src[13] >> 8] + (src[13] & 0xff)];
        dst[14] = uni2cp_low[uni2cp_high[src[14] >> 8] + (src[14] & 0xff)];
        dst[15] = uni2cp_low[uni2cp_high[src[15] >> 8] + (src[15] & 0xff)];
        src += 16;
        dst += 16;
        srclen -= 16;
    }

    /* now handle remaining characters */
    src += srclen;
    dst += srclen;
    switch(srclen)
    {
    case 15: dst[-15] = uni2cp_low[uni2cp_high[src[-15] >> 8] + (src[-15] & 0xff)];
    case 14: dst[-14] = uni2cp_low[uni2cp_high[src[-14] >> 8] + (src[-14] & 0xff)];
    case 13: dst[-13] = uni2cp_low[uni2cp_high[src[-13] >> 8] + (src[-13] & 0xff)];
    case 12: dst[-12] = uni2cp_low[uni2cp_high[src[-12] >> 8] + (src[-12] & 0xff)];
    case 11: dst[-11] = uni2cp_low[uni2cp_high[src[-11] >> 8] + (src[-11] & 0xff)];
    case 10: dst[-10] = uni2cp_low[uni2cp_high[src[-10] >> 8] + (src[-10] & 0xff)];
    case 9:  dst[-9]  = uni2cp_low[uni2cp_high[src[-9]  >> 8] + (src[-9]  & 0xff)];
    case 8:  dst[-8]  = uni2cp_low[uni2cp_high[src[-8]  >> 8] + (src[-8]  & 0xff)];
    case 7:  dst[-7]  = uni2cp_low[uni2cp_high[src[-7]  >> 8] + (src[-7]  & 0xff)];
    case 6:  dst[-6]  = uni2cp_low[uni2cp_high[src[-6]  >> 8] + (src[-6]  & 0xff)];
    case 5:  dst[-5]  = uni2cp_low[uni2cp_high[src[-5]  >> 8] + (src[-5]  & 0xff)];
    case 4:  dst[-4]  = uni2cp_low[uni2cp_high[src[-4]  >> 8] + (src[-4]  & 0xff)];
    case 3:  dst[-3]  = uni2cp_low[uni2cp_high[src[-3]  >> 8] + (src[-3]  & 0xff)];
    case 2:  dst[-2]  = uni2cp_low[uni2cp_high[src[-2]  >> 8] + (src[-2]  & 0xff)];
    case 1:  dst[-1]  = uni2cp_low[uni2cp_high[src[-1]  >> 8] + (src[-1]  & 0xff)];
    case 0: break;
    }
    return ret;
}

__attribute__((used)) static int wcstombs_sbcs_slow( const struct sbcs_table *table, int flags,
                               const WCHAR *src, unsigned int srclen,
                               char *dst, unsigned int dstlen,
                               const char *defchar, int *used )
{
    const unsigned char  * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    unsigned char def;
    unsigned int len;
    int tmp;
    WCHAR composed;

    if (!defchar)
        def = table->info.def_char & 0xff;
    else
        def = *defchar;

    if (!used) used = &tmp;  /* avoid checking on every char */
    *used = 0;

    for (len = dstlen; srclen && len; dst++, len--, src++, srclen--)
    {
        WCHAR wch = *src;

        if ((flags & WC_COMPOSITECHECK) && (srclen > 1) && (composed = wine_compose(src)))
        {
            /* now check if we can use the composed char */
            *dst = uni2cp_low[uni2cp_high[composed >> 8] + (composed & 0xff)];
            if (is_valid_sbcs_mapping( table, flags, composed, *dst ))
            {
                /* we have a good mapping, use it */
                src++;
                srclen--;
                continue;
            }
            /* no mapping for the composed char, check the other flags */
            if (flags & WC_DEFAULTCHAR) /* use the default char instead */
            {
                *dst = def;
                *used = 1;
                src++;  /* skip the non-spacing char */
                srclen--;
                continue;
            }
            if (flags & WC_DISCARDNS) /* skip the second char of the composition */
            {
                src++;
                srclen--;
            }
            /* WC_SEPCHARS is the default */
        }

        *dst = uni2cp_low[uni2cp_high[wch >> 8] + (wch & 0xff)];
        if (!is_valid_sbcs_mapping( table, flags, wch, *dst ))
        {
            *dst = def;
            *used = 1;
        }
    }
    if (srclen) return -1;  /* overflow */
    return dstlen - len;
}

__attribute__((used)) static inline int is_valid_dbcs_mapping( const struct dbcs_table *table, int flags,
                                         WCHAR wch, unsigned short ch )
{
    if ((flags & WC_NO_BEST_FIT_CHARS) || ch == table->info.def_char)
    {
        /* check if char maps back to the same Unicode value */
        if (ch & 0xff00)
        {
            unsigned char off = table->cp2uni_leadbytes[ch >> 8];
            return (table->cp2uni[(off << 8) + (ch & 0xff)] == wch);
        }
        return (table->cp2uni[ch & 0xff] == wch);
    }
    return 1;
}

__attribute__((used)) static inline WCHAR get_defchar_dbcs( const struct dbcs_table *table, const char *defchar )
{
    if (!defchar) return table->info.def_char;
    if (!defchar[1]) return (unsigned char)defchar[0];
    return ((unsigned char)defchar[0] << 8) | (unsigned char)defchar[1];
}

__attribute__((used)) static int get_length_dbcs( const struct dbcs_table *table, int flags,
                            const WCHAR *src, unsigned int srclen,
                            const char *defchar, int *used )
{
    const unsigned short * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    WCHAR defchar_value, composed;
    int len, tmp;

    if (!defchar && !used && !(flags & WC_COMPOSITECHECK))
    {
        for (len = 0; srclen; srclen--, src++, len++)
        {
            if (uni2cp_low[uni2cp_high[*src >> 8] + (*src & 0xff)] & 0xff00) len++;
        }
        return len;
    }

    defchar_value = get_defchar_dbcs( table, defchar );
    if (!used) used = &tmp;  /* avoid checking on every char */
    *used = 0;
    for (len = 0; srclen; len++, srclen--, src++)
    {
        unsigned short res;
        WCHAR wch = *src;

        if ((flags & WC_COMPOSITECHECK) && (srclen > 1) && (composed = wine_compose(src)))
        {
            /* now check if we can use the composed char */
            res = uni2cp_low[uni2cp_high[composed >> 8] + (composed & 0xff)];

            if (is_valid_dbcs_mapping( table, flags, composed, res ))
            {
                /* we have a good mapping for the composed char, use it */
                if (res & 0xff00) len++;
                src++;
                srclen--;
                continue;
            }
            /* no mapping for the composed char, check the other flags */
            if (flags & WC_DEFAULTCHAR) /* use the default char instead */
            {
                if (defchar_value & 0xff00) len++;
                *used = 1;
                src++;  /* skip the non-spacing char */
                srclen--;
                continue;
            }
            if (flags & WC_DISCARDNS) /* skip the second char of the composition */
            {
                src++;
                srclen--;
            }
            /* WC_SEPCHARS is the default */
        }

        res = uni2cp_low[uni2cp_high[wch >> 8] + (wch & 0xff)];
        if (!is_valid_dbcs_mapping( table, flags, wch, res ))
        {
            res = defchar_value;
            *used = 1;
        }
        if (res & 0xff00) len++;
    }
    return len;
}

__attribute__((used)) static inline int wcstombs_dbcs( const struct dbcs_table *table,
                                 const WCHAR *src, unsigned int srclen,
                                 char *dst, unsigned int dstlen )
{
    const unsigned short * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    int len;

    for (len = dstlen; srclen && len; len--, srclen--, src++)
    {
        unsigned short res = uni2cp_low[uni2cp_high[*src >> 8] + (*src & 0xff)];
        if (res & 0xff00)
        {
            if (len == 1) break;  /* do not output a partial char */
            len--;
            *dst++ = res >> 8;
        }
        *dst++ = (char)res;
    }
    if (srclen) return -1;  /* overflow */
    return dstlen - len;
}

__attribute__((used)) static int wcstombs_dbcs_slow( const struct dbcs_table *table, int flags,
                               const WCHAR *src, unsigned int srclen,
                               char *dst, unsigned int dstlen,
                               const char *defchar, int *used )
{
    const unsigned short * const uni2cp_low = table->uni2cp_low;
    const unsigned short * const uni2cp_high = table->uni2cp_high;
    WCHAR defchar_value = get_defchar_dbcs( table, defchar );
    WCHAR composed;
    int len, tmp;

    if (!used) used = &tmp;  /* avoid checking on every char */
    *used = 0;

    for (len = dstlen; srclen && len; len--, srclen--, src++)
    {
        unsigned short res;
        WCHAR wch = *src;

        if ((flags & WC_COMPOSITECHECK) && (srclen > 1) && (composed = wine_compose(src)))
        {
            /* now check if we can use the composed char */
            res = uni2cp_low[uni2cp_high[composed >> 8] + (composed & 0xff)];

            if (is_valid_dbcs_mapping( table, flags, composed, res ))
            {
                /* we have a good mapping for the composed char, use it */
                src++;
                srclen--;
                goto output_char;
            }
            /* no mapping for the composed char, check the other flags */
            if (flags & WC_DEFAULTCHAR) /* use the default char instead */
            {
                res = defchar_value;
                *used = 1;
                src++;  /* skip the non-spacing char */
                srclen--;
                goto output_char;
            }
            if (flags & WC_DISCARDNS) /* skip the second char of the composition */
            {
                src++;
                srclen--;
            }
            /* WC_SEPCHARS is the default */
        }

        res = uni2cp_low[uni2cp_high[wch >> 8] + (wch & 0xff)];
        if (!is_valid_dbcs_mapping( table, flags, wch, res ))
        {
            res = defchar_value;
            *used = 1;
        }

    output_char:
        if (res & 0xff00)
        {
            if (len == 1) break;  /* do not output a partial char */
            len--;
            *dst++ = res >> 8;
        }
        *dst++ = (char)res;
    }
    if (srclen) return -1;  /* overflow */
    return dstlen - len;
}

int wine_cp_wcstombs( const union cptable *table, int flags,
                      const WCHAR *src, int srclen,
                      char *dst, int dstlen, const char *defchar, int *used )
{
    if (table->info.char_size == 1)
    {
        if (flags || defchar || used)
        {
            if (!dstlen) return get_length_sbcs( &table->sbcs, flags, src, srclen, used );
            return wcstombs_sbcs_slow( &table->sbcs, flags, src, srclen,
                                       dst, dstlen, defchar, used );
        }
        if (!dstlen) return srclen;
        return wcstombs_sbcs( &table->sbcs, src, srclen, dst, dstlen );
    }
    else /* mbcs */
    {
        if (!dstlen) return get_length_dbcs( &table->dbcs, flags, src, srclen, defchar, used );
        if (flags || defchar || used)
            return wcstombs_dbcs_slow( &table->dbcs, flags, src, srclen,
                                       dst, dstlen, defchar, used );
        return wcstombs_dbcs( &table->dbcs, src, srclen, dst, dstlen );
    }
}

