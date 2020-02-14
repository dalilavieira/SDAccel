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
typedef  int /*<<< orphan*/  xsltLocaleChar ;
typedef  int /*<<< orphan*/  xsltLocale ;
typedef  int xmlChar ;

/* Variables and functions */
 int /*<<< orphan*/  xmlFree (int /*<<< orphan*/ *) ; 
 int xmlStrcmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  xsltTransformError (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 

void
xsltFreeLocales(void) {
#ifdef XSLT_LOCALE_WINAPI
    xmlRMutexLock(xsltLocaleMutex);
    xmlFree(xsltLocaleList);
    xsltLocaleList = NULL;
    xmlRMutexUnlock(xsltLocaleMutex);
#endif
}

xsltLocale
xsltNewLocale(const xmlChar *languageTag) {
#ifdef XSLT_LOCALE_POSIX
    xsltLocale locale;
    char localeName[XSLTMAX_LANGTAGLEN+6]; /* 6 chars for ".utf8\0" */
    const xmlChar *p = languageTag;
    const char *region = NULL;
    char *q = localeName;
    int i, llen;

    /* Convert something like "pt-br" to "pt_BR.utf8" */

    if (languageTag == NULL)
	return(NULL);

    for (i=0; i<XSLTMAX_ISO639LANGLEN && ISALPHA(*p); ++i)
	*q++ = TOLOWER(*p++);

    if (i == 0)
	return(NULL);

    llen = i;

    if (*p) {
	if (*p++ != '-')
	    return(NULL);
        *q++ = '_';

	for (i=0; i<XSLTMAX_ISO3166CNTRYLEN && ISALPHA(*p); ++i)
	    *q++ = TOUPPER(*p++);

	if (i == 0 || *p)
	    return(NULL);

        memcpy(q, ".utf8", 6);
        locale = newlocale(LC_COLLATE_MASK, localeName, NULL);
        if (locale != NULL)
            return(locale);

        /* Continue without using country code */

        q = localeName + llen;
    }

    /* Try locale without territory, e.g. for Esperanto (eo) */

    memcpy(q, ".utf8", 6);
    locale = newlocale(LC_COLLATE_MASK, localeName, NULL);
    if (locale != NULL)
        return(locale);

    /* Try to find most common country for language */

    if (llen != 2)
        return(NULL);

    region = (char *)xsltDefaultRegion((xmlChar *)localeName);
    if (region == NULL)
        return(NULL);

    q = localeName + llen;
    *q++ = '_';
    *q++ = region[0];
    *q++ = region[1];
    memcpy(q, ".utf8", 6);
    locale = newlocale(LC_COLLATE_MASK, localeName, NULL);

    return(locale);
#endif

#ifdef XSLT_LOCALE_WINAPI
{
    xsltLocale    locale = (xsltLocale)0;
    xmlChar       localeName[XSLTMAX_LANGTAGLEN+1];
    xmlChar       *q = localeName;
    const xmlChar *p = languageTag;
    int           i, llen;
    const xmlChar *region = NULL;

    if (languageTag == NULL) goto end;

    xsltEnumSupportedLocales();

    for (i=0; i<XSLTMAX_ISO639LANGLEN && ISALPHA(*p); ++i)
	*q++ = TOLOWER(*p++);
    if (i == 0) goto end;

    llen = i;
    *q++ = '-';
    if (*p) { /*if country tag is given*/
	if (*p++ != '-') goto end;

	for (i=0; i<XSLTMAX_ISO3166CNTRYLEN && ISALPHA(*p); ++i)
	    *q++ = TOUPPER(*p++);
	if (i == 0 || *p) goto end;

	*q = '\0';
	locale = xslt_locale_WINAPI(localeName);
	if (locale != (xsltLocale)0) goto end;
    }
    /* Try to find most common country for language */
    region = xsltDefaultRegion(localeName);
    if (region == NULL) goto end;

    strcpy((char *) localeName + llen + 1, (char *) region);
    locale = xslt_locale_WINAPI(localeName);
end:
    return(locale);
}
#endif

#ifdef XSLT_LOCALE_NONE
    return(NULL);
#endif
}

__attribute__((used)) static const xmlChar*
xsltDefaultRegion(const xmlChar *localeName) {
    xmlChar c;
    /* region should be xmlChar, but gcc warns on all string assignments */
    const char *region = NULL;

    c = localeName[1];
    /* This is based on the locales from glibc 2.3.3 */

    switch (localeName[0]) {
        case 'a':
            if (c == 'a' || c == 'm') region = "ET";
            else if (c == 'f') region = "ZA";
            else if (c == 'n') region = "ES";
            else if (c == 'r') region = "AE";
            else if (c == 'z') region = "AZ";
            break;
        case 'b':
            if (c == 'e') region = "BY";
            else if (c == 'g') region = "BG";
            else if (c == 'n') region = "BD";
            else if (c == 'r') region = "FR";
            else if (c == 's') region = "BA";
            break;
        case 'c':
            if (c == 'a') region = "ES";
            else if (c == 's') region = "CZ";
            else if (c == 'y') region = "GB";
            break;
        case 'd':
            if (c == 'a') region = "DK";
            else if (c == 'e') region = "DE";
            break;
        case 'e':
            if (c == 'l') region = "GR";
            else if (c == 'n' || c == 'o') region = "US";
            else if (c == 's' || c == 'u') region = "ES";
            else if (c == 't') region = "EE";
            break;
        case 'f':
            if (c == 'a') region = "IR";
            else if (c == 'i') region = "FI";
            else if (c == 'o') region = "FO";
            else if (c == 'r') region = "FR";
            break;
        case 'g':
            if (c == 'a') region = "IE";
            else if (c == 'l') region = "ES";
            else if (c == 'v') region = "GB";
            break;
        case 'h':
            if (c == 'e') region = "IL";
            else if (c == 'i') region = "IN";
            else if (c == 'r') region = "HT";
            else if (c == 'u') region = "HU";
            break;
        case 'i':
            if (c == 'd') region = "ID";
            else if (c == 's') region = "IS";
            else if (c == 't') region = "IT";
            else if (c == 'w') region = "IL";
            break;
        case 'j':
            if (c == 'a') region = "JP";
            break;
        case 'k':
            if (c == 'l') region = "GL";
            else if (c == 'o') region = "KR";
            else if (c == 'w') region = "GB";
            break;
        case 'l':
            if (c == 't') region = "LT";
            else if (c == 'v') region = "LV";
            break;
        case 'm':
            if (c == 'k') region = "MK";
            else if (c == 'l' || c == 'r') region = "IN";
            else if (c == 'n') region = "MN";
            else if (c == 's') region = "MY";
            else if (c == 't') region = "MT";
            break;
        case 'n':
            if (c == 'b' || c == 'n' || c == 'o') region = "NO";
            else if (c == 'e') region = "NP";
            else if (c == 'l') region = "NL";
            break;
        case 'o':
            if (c == 'm') region = "ET";
            break;
        case 'p':
            if (c == 'a') region = "IN";
            else if (c == 'l') region = "PL";
            else if (c == 't') region = "PT";
            break;
        case 'r':
            if (c == 'o') region = "RO";
            else if (c == 'u') region = "RU";
            break;
        case 's':
            switch (c) {
                case 'e': region = "NO"; break;
                case 'h': region = "YU"; break;
                case 'k': region = "SK"; break;
                case 'l': region = "SI"; break;
                case 'o': region = "ET"; break;
                case 'q': region = "AL"; break;
                case 't': region = "ZA"; break;
                case 'v': region = "SE"; break;
            }
            break;
        case 't':
            if (c == 'a' || c == 'e') region = "IN";
            else if (c == 'h') region = "TH";
            else if (c == 'i') region = "ER";
            else if (c == 'r') region = "TR";
            else if (c == 't') region = "RU";
            break;
        case 'u':
            if (c == 'k') region = "UA";
            else if (c == 'r') region = "PK";
            break;
        case 'v':
            if (c == 'i') region = "VN";
            break;
        case 'w':
            if (c == 'a') region = "BE";
            break;
        case 'x':
            if (c == 'h') region = "ZA";
            break;
        case 'z':
            if (c == 'h') region = "CN";
            else if (c == 'u') region = "ZA";
            break;
    }
    return((xmlChar *)region);
}

void
xsltFreeLocale(xsltLocale locale) {
#ifdef XSLT_LOCALE_POSIX
    freelocale(locale);
#endif
}

xsltLocaleChar *
xsltStrxfrm(xsltLocale locale, const xmlChar *string)
{
#ifdef XSLT_LOCALE_NONE
    return(NULL);
#else
    size_t xstrlen, r;
    xsltLocaleChar *xstr;

#ifdef XSLT_LOCALE_POSIX
    xstrlen = strxfrm_l(NULL, (const char *)string, 0, locale) + 1;
    xstr = (xsltLocaleChar *) xmlMalloc(xstrlen);
    if (xstr == NULL) {
	xsltTransformError(NULL, NULL, NULL,
	    "xsltStrxfrm : out of memory error\n");
	return(NULL);
    }

    r = strxfrm_l((char *)xstr, (const char *)string, xstrlen, locale);
#endif

#ifdef XSLT_LOCALE_WINAPI
    xstrlen = MultiByteToWideChar(CP_UTF8, 0, (char *) string, -1, NULL, 0);
    if (xstrlen == 0) {
        xsltTransformError(NULL, NULL, NULL, "xsltStrxfrm : MultiByteToWideChar check failed\n");
        return(NULL);
    }
    xstr = (xsltLocaleChar*) xmlMalloc(xstrlen * sizeof(xsltLocaleChar));
    if (xstr == NULL) {
        xsltTransformError(NULL, NULL, NULL, "xsltStrxfrm : out of memory\n");
        return(NULL);
    }
    r = MultiByteToWideChar(CP_UTF8, 0, (char *) string, -1, xstr, xstrlen);
    if (r == 0) {
        xsltTransformError(NULL, NULL, NULL, "xsltStrxfrm : MultiByteToWideChar failed\n");
        xmlFree(xstr);
        return(NULL);
    }
    return(xstr);
#endif /* XSLT_LOCALE_WINAPI */

    if (r >= xstrlen) {
	xsltTransformError(NULL, NULL, NULL, "xsltStrxfrm : strxfrm failed\n");
        xmlFree(xstr);
        return(NULL);
    }

    return(xstr);
#endif /* XSLT_LOCALE_NONE */
}

int
xsltLocaleStrcmp(xsltLocale locale, const xsltLocaleChar *str1, const xsltLocaleChar *str2) {
    (void)locale;
#ifdef XSLT_LOCALE_WINAPI
{
    int ret;
    if (str1 == str2) return(0);
    if (str1 == NULL) return(-1);
    if (str2 == NULL) return(1);
    ret = CompareStringW(locale, 0, str1, -1, str2, -1);
    if (ret == 0) {
        xsltTransformError(NULL, NULL, NULL, "xsltLocaleStrcmp : CompareStringW fail\n");
        return(0);
    }
    return(ret - 2);
}
#else
    return(xmlStrcmp(str1, str2));
#endif
}

