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
struct mp_log {int dummy; } ;
typedef  int /*<<< orphan*/  bstr ;

/* Variables and functions */
 int MP_ICONV_ALLOW_CUTOFF ; 
 int MP_NO_LATIN1_FALLBACK ; 
 int /*<<< orphan*/  bstr_sanitize_utf8_latin1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ bstr_startswith0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bstr_validate_utf8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_err (struct mp_log*,char*) ; 
 int /*<<< orphan*/  mp_verbose (struct mp_log*,char*,...) ; 
 scalar_t__ strcasecmp (char const*,char*) ; 
 scalar_t__ strchr (char const*,char) ; 
 scalar_t__ strncasecmp (char const*,char*,int) ; 
 int /*<<< orphan*/ * utf_bom ; 
 char const** utf_enc ; 

__attribute__((used)) static const char *ms_bom_guess(bstr buf)
{
    for (int n = 0; n < 3; n++) {
        if (bstr_startswith0(buf, utf_bom[n]))
            return utf_enc[n];
    }
    return NULL;
}

const char *mp_charset_guess(void *talloc_ctx, struct mp_log *log,  bstr buf,
                             const char *user_cp, int flags)
{
    if (strcasecmp(user_cp, "enca") == 0 || strcasecmp(user_cp, "guess") == 0 ||
        strcasecmp(user_cp, "uchardet") == 0 || strchr(user_cp, ':'))
    {
        mp_err(log, "This syntax for the --sub-codepage option was deprecated "
                    "and has been removed.\n");
        if (strncasecmp(user_cp, "utf8:", 5) == 0) {
            user_cp = user_cp + 5;
        } else {
            user_cp = "";
        }
    }

    if (user_cp[0] == '+') {
        mp_verbose(log, "Forcing charset '%s'.\n", user_cp + 1);
        return user_cp + 1;
    }

    const char *bom_cp = ms_bom_guess(buf);
    if (bom_cp) {
        mp_verbose(log, "Data has a BOM, assuming %s as charset.\n", bom_cp);
        return bom_cp;
    }

    int r = bstr_validate_utf8(buf);
    if (r >= 0 || (r > -8 && (flags & MP_ICONV_ALLOW_CUTOFF))) {
        mp_verbose(log, "Data looks like UTF-8, ignoring user-provided charset.\n");
        return "utf-8";
    }

    const char *res = NULL;
    if (strcasecmp(user_cp, "auto") == 0) {
#if HAVE_UCHARDET
        res = mp_uchardet(talloc_ctx, log, buf);
#endif
        if (!res) {
            mp_verbose(log, "Charset auto-detection failed.\n");
            res = "UTF-8-BROKEN";
        }
    } else {
        res = user_cp;
    }

    mp_verbose(log, "Using charset '%s'.\n", res);
    return res;
}

bstr mp_iconv_to_utf8(struct mp_log *log, bstr buf, const char *cp, int flags)
{
#if HAVE_ICONV
    if (!cp || !cp[0] || mp_charset_is_utf8(cp))
        return buf;

    if (strcasecmp(cp, "ASCII") == 0)
        return buf;

    if (strcasecmp(cp, "UTF-8-BROKEN") == 0)
        return bstr_sanitize_utf8_latin1(NULL, buf);

    // Force CP949 over EUC-KR since iconv distinguishes them and
    // EUC-KR causes error on CP949 encoded data
    if (strcasecmp(cp, "EUC-KR") == 0)
      cp = "CP949";

    iconv_t icdsc;
    if ((icdsc = iconv_open("UTF-8", cp)) == (iconv_t) (-1)) {
        if (flags & MP_ICONV_VERBOSE)
            mp_err(log, "Error opening iconv with codepage '%s'\n", cp);
        goto failure;
    }

    size_t size = buf.len;
    size_t osize = size;
    size_t ileft = size;
    size_t oleft = size - 1;

    char *outbuf = talloc_size(NULL, osize);
    char *ip = buf.start;
    char *op = outbuf;

    while (1) {
        int clear = 0;
        size_t rc;
        if (ileft)
            rc = iconv(icdsc, &ip, &ileft, &op, &oleft);
        else {
            clear = 1; // clear the conversion state and leave
            rc = iconv(icdsc, NULL, NULL, &op, &oleft);
        }
        if (rc == (size_t) (-1)) {
            if (errno == E2BIG) {
                size_t offset = op - outbuf;
                outbuf = talloc_realloc_size(NULL, outbuf, osize + size);
                op = outbuf + offset;
                osize += size;
                oleft += size;
            } else {
                if (errno == EINVAL && (flags & MP_ICONV_ALLOW_CUTOFF)) {
                    // This is intended for cases where the input buffer is cut
                    // at a random byte position. If this happens in the middle
                    // of the buffer, it should still be an error. We say it's
                    // fine if the error is within 10 bytes of the end.
                    if (ileft <= 10)
                        break;
                }
                if (flags & MP_ICONV_VERBOSE) {
                    mp_err(log, "Error recoding text with codepage '%s'\n", cp);
                }
                talloc_free(outbuf);
                iconv_close(icdsc);
                goto failure;
            }
        } else if (clear)
            break;
    }

    iconv_close(icdsc);

    outbuf[osize - oleft - 1] = 0;
    return (bstr){outbuf, osize - oleft - 1};
#endif

failure:
    if (flags & MP_NO_LATIN1_FALLBACK) {
        return buf;
    } else {
        return bstr_sanitize_utf8_latin1(NULL, buf);
    }
}

