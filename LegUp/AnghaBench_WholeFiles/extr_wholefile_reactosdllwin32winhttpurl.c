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
typedef  char WCHAR ;
typedef  char const* LPCWSTR ;
typedef  int INTERNET_PORT ;
typedef  int DWORD ;
typedef  void* BOOL ;

/* Variables and functions */
 int ERROR_INVALID_PARAMETER ; 
 int ERROR_SUCCESS ; 
 int ERROR_WINHTTP_INVALID_URL ; 
 void* FALSE ; 
 int ICU_DECODE ; 
 int ICU_ESCAPE ; 
 void* TRUE ; 
 char* heap_alloc (int) ; 
 scalar_t__ isalnumW (char) ; 
 scalar_t__ isdigitW (char const) ; 
 scalar_t__ isxdigitW (char const) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
 int /*<<< orphan*/  strcpyW (char*,char const*) ; 
 char* strrchrW (char const*,char) ; 
 int /*<<< orphan*/  strtolW (char*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static DWORD set_component( WCHAR **str, DWORD *str_len, WCHAR *value, DWORD len, DWORD flags, BOOL *overflow )
{
    if (*str && !*str_len) return ERROR_INVALID_PARAMETER;
    if (!*str_len) return ERROR_SUCCESS;
    if (!*str)
    {
        if (len && *str_len && (flags & (ICU_DECODE|ICU_ESCAPE))) return ERROR_INVALID_PARAMETER;
        *str = value;
        *str_len = len;
    }
    else
    {
        if (len >= *str_len)
        {
            *str_len = len+1;
            *overflow = TRUE;
            return ERROR_SUCCESS;
        }
        memcpy( *str, value, len * sizeof(WCHAR) );
        (*str)[len] = 0;
        *str_len = len;
    }
    return ERROR_SUCCESS;
}

__attribute__((used)) static WCHAR *decode_url( LPCWSTR url, DWORD *len )
{
    const WCHAR *p = url;
    WCHAR hex[3], *q, *ret;

    if (!(ret = heap_alloc( *len * sizeof(WCHAR) ))) return NULL;
    q = ret;
    while (*len > 0)
    {
        if (p[0] == '%' && isxdigitW( p[1] ) && isxdigitW( p[2] ))
        {
            hex[0] = p[1];
            hex[1] = p[2];
            hex[2] = 0;
            *q++ = strtolW( hex, NULL, 16 );
            p += 3;
            *len -= 3;
        }
        else
        {
            *q++ = *p++;
            *len -= 1;
        }
    }
    *len = q - ret;
    return ret;
}

__attribute__((used)) static BOOL need_escape( WCHAR c )
{
    if (isalnumW( c )) return FALSE;

    if (c <= 31 || c >= 127) return TRUE;
    else
    {
        switch (c)
        {
        case ' ':
        case '"':
        case '#':
        case '%':
        case '<':
        case '>':
        case ']':
        case '\\':
        case '[':
        case '^':
        case '`':
        case '{':
        case '|':
        case '}':
        case '~':
            return TRUE;
        default:
            return FALSE;
        }
    }
}

__attribute__((used)) static DWORD copy_escape( WCHAR *dst, const WCHAR *src, DWORD len )
{
    static const WCHAR hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    DWORD ret = len;
    unsigned int i;
    WCHAR *p = dst;

    for (i = 0; i < len; i++, p++)
    {
        if (need_escape( src[i] ))
        {
            p[0] = '%';
            p[1] = hex[(src[i] >> 4) & 0xf];
            p[2] = hex[src[i] & 0xf];
            ret += 2;
            p += 2;
        }
        else *p = src[i];
    }
    dst[ret] = 0;
    return ret;
}

__attribute__((used)) static WCHAR *escape_url( LPCWSTR url, DWORD *len )
{
    WCHAR *ret;
    const WCHAR *p, *q;

    if ((p = q = strrchrW( url, '/' )))
    {
        while (*q)
        {
            if (need_escape( *q )) *len += 2;
            q++;
        }
    }
    if (!(ret = heap_alloc( (*len + 1) * sizeof(WCHAR) ))) return NULL;
    if (!p) strcpyW( ret, url );
    else
    {
        memcpy( ret, url, (p - url) * sizeof(WCHAR) );
        copy_escape( ret + (p - url), p, q - p );
    }
    return ret;
}

__attribute__((used)) static DWORD parse_port( const WCHAR *str, DWORD len, INTERNET_PORT *ret )
{
    const WCHAR *p = str;
    DWORD port = 0;
    while (len && isdigitW( *p ))
    {
        if ((port = port * 10 + *p - '0') > 65535) return ERROR_WINHTTP_INVALID_URL;
        p++; len--;
    }
    *ret = port;
    return ERROR_SUCCESS;
}

