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
typedef  int u_long ;
typedef  int u_int ;
typedef  int boolean_t ;

/* Variables and functions */
 int FALSE ; 
 int TRUE ; 
 int const_strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kCopyrightToken ; 
 int /*<<< orphan*/  kRightsToken ; 
 int kYearLen ; 
 int kYearRangeLen ; 
 char* kxld_alloc (int) ; 
 int /*<<< orphan*/  kxld_free (char*,int) ; 
 char* kxld_strstr (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

__attribute__((used)) static boolean_t
is_space(const char c)
{
    switch (c) {
    case ' ':
    case '\t':
    case '\n':
    case '\v':
    case '\f':
    case '\r':
        return TRUE;
    }

    return FALSE;
}

__attribute__((used)) static boolean_t
is_token_delimiter(const char c)
{
    return (is_space(c) || (',' == c) || ('\0' == c));
}

__attribute__((used)) static boolean_t
is_token_break(const char *str) 
{
    /* This is safe because '\0' is a token delimiter, so the second check
     * will not execute if we reach the end of the string.
     */
    return (!is_token_delimiter(str[0]) && is_token_delimiter(str[1]));
}

__attribute__((used)) static boolean_t
token_is_year(const char *str)
{
    boolean_t result = FALSE;
    u_int i = 0;

    for (i = 0; i < kYearLen - 1; ++i) {
        if (str[i] < '0' || str[i] > '9') goto finish;
    }

    if (str[i] != '\0') goto finish;
    
    result = TRUE;
finish:
    return result;
}

__attribute__((used)) static boolean_t
token_is_yearRange(const char *str)
{
    boolean_t result = FALSE;
    u_int i = 0;

    for (i = 0; i < kYearLen - 1; ++i) {
        if (str[i] < '0' || str[i] > '9') goto finish;
    }

    if (str[i] != '-') goto finish;
    
    for (i = kYearLen; i < kYearRangeLen - 1; ++i) {
        if (str[i] < '0' || str[i] > '9') goto finish;
    }

    if (str[i] != '\0') goto finish;

    result = TRUE;
finish:
    return result;
}

__attribute__((used)) static boolean_t
dates_are_valid(const char *str, const u_long len)
{
    boolean_t result = FALSE;
    const char *token_ptr = NULL;
    char token_buffer[kYearRangeLen];
    u_int token_index = 0;

    token_index = 0;
    for (token_ptr = str; token_ptr < str + len; ++token_ptr) {
        if (is_token_delimiter(*token_ptr) && !token_index) continue;

        /* If we exceed the length of a year range, the test will not succeed,
         * so just fail now.  This limits the length of the token buffer that
         * we have to keep around.
         */
        if (token_index == kYearRangeLen) goto finish;

        token_buffer[token_index++] = *token_ptr;
        if (is_token_break(token_ptr)) {
            if (!token_index) continue;

            token_buffer[token_index] = '\0';

            if (!token_is_year(token_buffer) && 
                !token_is_yearRange(token_buffer)) 
            {
                goto finish;
            }

            token_index = 0;
        }
    }

    result = TRUE;
finish:
    return result;
}

boolean_t 
kxld_validate_copyright_string(const char *str)
{
    boolean_t result = FALSE;
    const char *copyright = NULL;
    const char *rights = NULL;
    char *date_str = NULL;
    u_long len = 0;

    copyright = kxld_strstr(str, kCopyrightToken);
    rights = kxld_strstr(str, kRightsToken);

    if (!copyright || !rights || copyright > rights) goto finish;

    str = copyright + const_strlen(kCopyrightToken);

    len = rights - str;
    date_str = kxld_alloc(len+1);
    if (!date_str) goto finish;

    strncpy(date_str, str, len);
    date_str[len] = '\0';

    if (!dates_are_valid(date_str, len)) goto finish;

    result = TRUE;
finish:
    if (date_str) kxld_free(date_str, len+1);
    return result;
}

