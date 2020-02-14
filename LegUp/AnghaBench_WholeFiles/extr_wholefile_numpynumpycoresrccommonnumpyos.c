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
struct lconv {char* decimal_point; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EOF ; 
 int MIN_EXPONENT_DIGITS ; 
 int /*<<< orphan*/  NPY_ALLOW_C_API ; 
 int /*<<< orphan*/  NPY_ALLOW_C_API_DEF ; 
 int /*<<< orphan*/  NPY_DISABLE_C_API ; 
 scalar_t__ NumPyOS_ascii_isspace (int) ; 
 int /*<<< orphan*/  PyErr_Clear () ; 
 scalar_t__ PyErr_Occurred () ; 
 double PyOS_string_to_double (char const*,char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_CHARMASK (char) ; 
 int /*<<< orphan*/  assert (int) ; 
 int getc (int /*<<< orphan*/ *) ; 
 scalar_t__ isdigit (int /*<<< orphan*/ ) ; 
 struct lconv* localeconv () ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  memmove (char*,char*,size_t) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncmp (char*,char const*,size_t) ; 
 char* strpbrk (char const*,char*) ; 
 int /*<<< orphan*/  ungetc (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ensure_minimum_exponent_length(char* buffer, size_t buf_size)
{
    char *p = strpbrk(buffer, "eE");
    if (p && (*(p + 1) == '-' || *(p + 1) == '+')) {
        char *start = p + 2;
        int exponent_digit_cnt = 0;
        int leading_zero_cnt = 0;
        int in_leading_zeros = 1;
        int significant_digit_cnt;

        /* Skip over the exponent and the sign. */
        p += 2;

        /* Find the end of the exponent, keeping track of leading zeros. */
        while (*p && isdigit(Py_CHARMASK(*p))) {
            if (in_leading_zeros && *p == '0') {
                ++leading_zero_cnt;
            }
            if (*p != '0') {
                in_leading_zeros = 0;
            }
            ++p;
            ++exponent_digit_cnt;
        }

        significant_digit_cnt = exponent_digit_cnt - leading_zero_cnt;
        if (exponent_digit_cnt == MIN_EXPONENT_DIGITS) {
            /*
             * If there are 2 exactly digits, we're done,
             * regardless of what they contain
             */
        }
        else if (exponent_digit_cnt > MIN_EXPONENT_DIGITS) {
            int extra_zeros_cnt;

            /*
             * There are more than 2 digits in the exponent.  See
             * if we can delete some of the leading zeros
             */
            if (significant_digit_cnt < MIN_EXPONENT_DIGITS) {
                significant_digit_cnt = MIN_EXPONENT_DIGITS;
            }
            extra_zeros_cnt = exponent_digit_cnt - significant_digit_cnt;

            /*
             * Delete extra_zeros_cnt worth of characters from the
             * front of the exponent
             */
            assert(extra_zeros_cnt >= 0);

            /*
             * Add one to significant_digit_cnt to copy the
             * trailing 0 byte, thus setting the length
             */
            memmove(start, start + extra_zeros_cnt, significant_digit_cnt + 1);
        }
        else {
            /*
             * If there are fewer than 2 digits, add zeros
             * until there are 2, if there's enough room
             */
            int zeros = MIN_EXPONENT_DIGITS - exponent_digit_cnt;
            if (start + zeros + exponent_digit_cnt + 1 < buffer + buf_size) {
                memmove(start + zeros, start, exponent_digit_cnt + 1);
                memset(start, '0', zeros);
            }
        }
    }
}

__attribute__((used)) static void
ensure_decimal_point(char* buffer, size_t buf_size)
{
    int insert_count = 0;
    char* chars_to_insert;

    /* search for the first non-digit character */
    char *p = buffer;
    if (*p == '-' || *p == '+')
        /*
         * Skip leading sign, if present.  I think this could only
         * ever be '-', but it can't hurt to check for both.
         */
        ++p;
    while (*p && isdigit(Py_CHARMASK(*p))) {
        ++p;
    }
    if (*p == '.') {
        if (isdigit(Py_CHARMASK(*(p+1)))) {
            /*
             * Nothing to do, we already have a decimal
             * point and a digit after it.
             */
        }
        else {
            /*
             * We have a decimal point, but no following
             * digit.  Insert a zero after the decimal.
             */
            ++p;
            chars_to_insert = "0";
            insert_count = 1;
        }
    }
    else {
        chars_to_insert = ".0";
        insert_count = 2;
    }
    if (insert_count) {
        size_t buf_len = strlen(buffer);
        if (buf_len + insert_count + 1 >= buf_size) {
            /*
             * If there is not enough room in the buffer
             * for the additional text, just skip it.  It's
             * not worth generating an error over.
             */
        }
        else {
            memmove(p + insert_count, p, buffer + strlen(buffer) - p + 1);
            memcpy(p, chars_to_insert, insert_count);
        }
    }
}

__attribute__((used)) static void
change_decimal_from_locale_to_dot(char* buffer)
{
    struct lconv *locale_data = localeconv();
    const char *decimal_point = locale_data->decimal_point;

    if (decimal_point[0] != '.' || decimal_point[1] != 0) {
        size_t decimal_point_len = strlen(decimal_point);

        if (*buffer == '+' || *buffer == '-') {
            buffer++;
        }
        while (isdigit(Py_CHARMASK(*buffer))) {
            buffer++;
        }
        if (strncmp(buffer, decimal_point, decimal_point_len) == 0) {
            *buffer = '.';
            buffer++;
            if (decimal_point_len > 1) {
                /* buffer needs to get smaller */
                size_t rest_len = strlen(buffer + (decimal_point_len - 1));
                memmove(buffer, buffer + (decimal_point_len - 1), rest_len);
                buffer[rest_len] = 0;
            }
        }
    }
}

__attribute__((used)) static int
check_ascii_format(const char *format)
{
    char format_char;
    size_t format_len = strlen(format);

    /* The last character in the format string must be the format char */
    format_char = format[format_len - 1];

    if (format[0] != '%') {
        return -1;
    }

    /*
     * I'm not sure why this test is here.  It's ensuring that the format
     * string after the first character doesn't have a single quote, a
     * lowercase l, or a percent. This is the reverse of the commented-out
     * test about 10 lines ago.
     */
    if (strpbrk(format + 1, "'l%")) {
        return -1;
    }

    /*
     * Also curious about this function is that it accepts format strings
     * like "%xg", which are invalid for floats.  In general, the
     * interface to this function is not very good, but changing it is
     * difficult because it's a public API.
     */
    if (!(format_char == 'e' || format_char == 'E'
          || format_char == 'f' || format_char == 'F'
          || format_char == 'g' || format_char == 'G')) {
        return -1;
    }

    return 0;
}

__attribute__((used)) static char*
fix_ascii_format(char* buf, size_t buflen, int decimal)
{
    /*
     * Get the current locale, and find the decimal point string.
     * Convert that string back to a dot.
     */
    change_decimal_from_locale_to_dot(buf);

    /*
     * If an exponent exists, ensure that the exponent is at least
     * MIN_EXPONENT_DIGITS digits, providing the buffer is large enough
     * for the extra zeros.  Also, if there are more than
     * MIN_EXPONENT_DIGITS, remove as many zeros as possible until we get
     * back to MIN_EXPONENT_DIGITS
     */
    ensure_minimum_exponent_length(buf, buflen);

    if (decimal != 0) {
        ensure_decimal_point(buf, buflen);
    }

    return buf;
}

__attribute__((used)) static int
NumPyOS_ascii_isalpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

__attribute__((used)) static int
NumPyOS_ascii_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

__attribute__((used)) static int
NumPyOS_ascii_isalnum(char c)
{
    return NumPyOS_ascii_isdigit(c) || NumPyOS_ascii_isalpha(c);
}

__attribute__((used)) static int
NumPyOS_ascii_tolower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a'-'A');
    }
    return c;
}

__attribute__((used)) static int
NumPyOS_ascii_strncasecmp(const char* s1, const char* s2, size_t len)
{
    while (len > 0 && *s1 != '\0' && *s2 != '\0') {
        int diff = NumPyOS_ascii_tolower(*s1) - NumPyOS_ascii_tolower(*s2);
        if (diff != 0) {
            return diff;
        }
        ++s1;
        ++s2;
        --len;
    }
    if (len > 0) {
        return *s1 - *s2;
    }
    return 0;
}

__attribute__((used)) static double
NumPyOS_ascii_strtod_plain(const char *s, char** endptr)
{
    double result;
    NPY_ALLOW_C_API_DEF;
    NPY_ALLOW_C_API;
    result = PyOS_string_to_double(s, endptr, NULL);
    if (PyErr_Occurred()) {
        if (endptr) {
            *endptr = (char*)s;
        }
        PyErr_Clear();
    }
    NPY_DISABLE_C_API;
    return result;
}

__attribute__((used)) static int
read_numberlike_string(FILE *fp, char *buffer, size_t buflen)
{

    char *endp;
    char *p;
    int c;
    int ok;

    /*
     * Fill buffer with the leftmost matching part in regexp
     *
     *     \s*[+-]? ( [0-9]*\.[0-9]+([eE][+-]?[0-9]+)
     *              | nan  (  \([:alphanum:_]*\) )?
     *              | inf(inity)?
     *              )
     *
     * case-insensitively.
     *
     * The "do { ... } while (0)" wrapping in macros ensures that they behave
     * properly eg. in "if ... else" structures.
     */

#define END_MATCH()                                                         \
        goto buffer_filled

#define NEXT_CHAR()                                                         \
        do {                                                                \
            if (c == EOF || endp >= buffer + buflen - 1)            \
                END_MATCH();                                                \
            *endp++ = (char)c;                                              \
            c = getc(fp);                                                   \
        } while (0)

#define MATCH_ALPHA_STRING_NOCASE(string)                                   \
        do {                                                                \
            for (p=(string); *p!='\0' && (c==*p || c+('a'-'A')==*p); ++p)   \
                NEXT_CHAR();                                                \
            if (*p != '\0') END_MATCH();                                    \
        } while (0)

#define MATCH_ONE_OR_NONE(condition)                                        \
        do { if (condition) NEXT_CHAR(); } while (0)

#define MATCH_ONE_OR_MORE(condition)                                        \
        do {                                                                \
            ok = 0;                                                         \
            while (condition) { NEXT_CHAR(); ok = 1; }                      \
            if (!ok) END_MATCH();                                           \
        } while (0)

#define MATCH_ZERO_OR_MORE(condition)                                       \
        while (condition) { NEXT_CHAR(); }

    /* 1. emulate fscanf EOF handling */
    c = getc(fp);
    if (c == EOF) {
        return EOF;
    }
    /* 2. consume leading whitespace unconditionally */
    while (NumPyOS_ascii_isspace(c)) {
        c = getc(fp);
    }

    /* 3. start reading matching input to buffer */
    endp = buffer;

    /* 4.1 sign (optional) */
    MATCH_ONE_OR_NONE(c == '+' || c == '-');

    /* 4.2 nan, inf, infinity; [case-insensitive] */
    if (c == 'n' || c == 'N') {
        NEXT_CHAR();
        MATCH_ALPHA_STRING_NOCASE("an");

        /* accept nan([:alphanum:_]*), similarly to strtod */
        if (c == '(') {
            NEXT_CHAR();
            MATCH_ZERO_OR_MORE(NumPyOS_ascii_isalnum(c) || c == '_');
            if (c == ')') {
                NEXT_CHAR();
            }
        }
        END_MATCH();
    }
    else if (c == 'i' || c == 'I') {
        NEXT_CHAR();
        MATCH_ALPHA_STRING_NOCASE("nfinity");
        END_MATCH();
    }

    /* 4.3 mantissa */
    MATCH_ZERO_OR_MORE(NumPyOS_ascii_isdigit(c));

    if (c == '.') {
        NEXT_CHAR();
        MATCH_ONE_OR_MORE(NumPyOS_ascii_isdigit(c));
    }

    /* 4.4 exponent */
    if (c == 'e' || c == 'E') {
        NEXT_CHAR();
        MATCH_ONE_OR_NONE(c == '+' || c == '-');
        MATCH_ONE_OR_MORE(NumPyOS_ascii_isdigit(c));
    }

    END_MATCH();

buffer_filled:

    ungetc(c, fp);
    *endp = '\0';

    /* return 1 if something read, else 0 */
    return (buffer == endp) ? 0 : 1;
}

