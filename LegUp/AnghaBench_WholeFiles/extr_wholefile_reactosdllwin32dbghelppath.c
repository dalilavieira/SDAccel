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
typedef  int BOOL ;

/* Variables and functions */
 int strlen (char const*) ; 
 int strlenW (char const*) ; 
 int /*<<< orphan*/  strncpyW (char*,char const*,int) ; 

__attribute__((used)) static inline BOOL is_sep(char ch) {return ch == '/' || ch == '\\';}

__attribute__((used)) static inline BOOL is_sepW(WCHAR ch) {return ch == '/' || ch == '\\';}

__attribute__((used)) static inline const char* file_name(const char* str)
{
    const char*       p;

    for (p = str + strlen(str) - 1; p >= str && !is_sep(*p); p--);
    return p + 1;
}

__attribute__((used)) static inline const WCHAR* file_nameW(const WCHAR* str)
{
    const WCHAR*      p;

    for (p = str + strlenW(str) - 1; p >= str && !is_sepW(*p); p--);
    return p + 1;
}

__attribute__((used)) static inline void file_pathW(const WCHAR* srcFileNameW,
    WCHAR* dstFilePathW)
{
    int len;

    for (len = strlenW(srcFileNameW) - 1; (len > 0) && (!is_sepW(srcFileNameW[len])); len--);

    strncpyW(dstFilePathW, srcFileNameW, len);
    dstFilePathW[len] = L'\0';
}

