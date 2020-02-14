#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szValue ;
typedef  int /*<<< orphan*/  szNumberA ;
typedef  int /*<<< orphan*/  szNumber ;
typedef  int /*<<< orphan*/  szGrpNameA ;
typedef  int /*<<< orphan*/  szGrpName ;
typedef  int /*<<< orphan*/  ret ;
typedef  int /*<<< orphan*/  attr ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  UNICODE_STRING ;
typedef  int ULONG ;
typedef  scalar_t__ UINT ;
struct TYPE_12__ {int (* procW ) (void*,scalar_t__,char*,int /*<<< orphan*/ ) ;int (* procA ) (void*,scalar_t__,char*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  lParam; void* lgrpid; scalar_t__ dwFlags; } ;
struct TYPE_11__ {int dwFlags; int (* procW ) (void*,char*,char*,int const,int /*<<< orphan*/ ) ;int (* procA ) (void*,char*,char*,int const,int /*<<< orphan*/ ) ;int /*<<< orphan*/  lParam; } ;
struct TYPE_10__ {int dwFlags; int (* procW ) (char*) ;int (* procA ) (char*) ;} ;
struct TYPE_9__ {int Length; void* RootDirectory; int /*<<< orphan*/ * SecurityQualityOfService; int /*<<< orphan*/ * SecurityDescriptor; scalar_t__ Attributes; int /*<<< orphan*/ * ObjectName; } ;
typedef  TYPE_1__ OBJECT_ATTRIBUTES ;
typedef  void* LGRPID ;
typedef  int LCTYPE ;
typedef  scalar_t__ LCID ;
typedef  void* HANDLE ;
typedef  TYPE_2__ ENUMSYSTEMCODEPAGES_CALLBACKS ;
typedef  TYPE_3__ ENUMLANGUAGEGROUP_CALLBACKS ;
typedef  TYPE_4__ ENUMLANGUAGEGROUPLOCALE_CALLBACKS ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
#define  CP_INSTALLED 227 
#define  CP_SUPPORTED 226 
 scalar_t__ ConvertDefaultLocale (scalar_t__) ; 
 int /*<<< orphan*/  ERROR_INVALID_FLAGS ; 
 int /*<<< orphan*/  ERROR_INVALID_PARAMETER ; 
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  GetLocaleInfoW (scalar_t__,int,char*,int) ; 
 int /*<<< orphan*/  KEY_ALL_ACCESS ; 
 void* LGRPID_ARMENIAN ; 
#define  LGRPID_INSTALLED 225 
#define  LGRPID_SUPPORTED 224 
#define  LOCALE_FONTSIGNATURE 223 
#define  LOCALE_ICALENDARTYPE 222 
#define  LOCALE_ICENTURY 221 
#define  LOCALE_ICOUNTRY 220 
#define  LOCALE_ICURRDIGITS 219 
#define  LOCALE_ICURRENCY 218 
#define  LOCALE_IDATE 217 
#define  LOCALE_IDAYLZERO 216 
#define  LOCALE_IDEFAULTANSICODEPAGE 215 
#define  LOCALE_IDEFAULTCODEPAGE 214 
#define  LOCALE_IDEFAULTEBCDICCODEPAGE 213 
#define  LOCALE_IDEFAULTMACCODEPAGE 212 
#define  LOCALE_IDEFAULTUNIXCODEPAGE 211 
#define  LOCALE_IDIGITS 210 
#define  LOCALE_IDIGITSUBSTITUTION 209 
#define  LOCALE_IFIRSTDAYOFWEEK 208 
#define  LOCALE_IFIRSTWEEKOFYEAR 207 
#define  LOCALE_IINTLCURRDIGITS 206 
#define  LOCALE_ILDATE 205 
#define  LOCALE_ILZERO 204 
#define  LOCALE_IMEASURE 203 
#define  LOCALE_IMONLZERO 202 
#define  LOCALE_INEGCURR 201 
#define  LOCALE_INEGNUMBER 200 
#define  LOCALE_INEGSEPBYSPACE 199 
#define  LOCALE_INEGSIGNPOSN 198 
#define  LOCALE_INEGSYMPRECEDES 197 
#define  LOCALE_IOPTIONALCALENDAR 196 
#define  LOCALE_IPAPERSIZE 195 
#define  LOCALE_IPOSSEPBYSPACE 194 
#define  LOCALE_IPOSSIGNPOSN 193 
#define  LOCALE_IPOSSYMPRECEDES 192 
#define  LOCALE_ITIME 191 
#define  LOCALE_ITIMEMARKPOSN 190 
#define  LOCALE_ITLZERO 189 
 scalar_t__ LOCALE_NEUTRAL ; 
 int LOCALE_RETURN_NUMBER ; 
#define  LOCALE_S1159 188 
#define  LOCALE_S2359 187 
#define  LOCALE_SABBREVDAYNAME1 186 
#define  LOCALE_SABBREVDAYNAME2 185 
#define  LOCALE_SABBREVDAYNAME3 184 
#define  LOCALE_SABBREVDAYNAME4 183 
#define  LOCALE_SABBREVDAYNAME5 182 
#define  LOCALE_SABBREVDAYNAME6 181 
#define  LOCALE_SABBREVDAYNAME7 180 
#define  LOCALE_SABBREVMONTHNAME1 179 
#define  LOCALE_SABBREVMONTHNAME10 178 
#define  LOCALE_SABBREVMONTHNAME11 177 
#define  LOCALE_SABBREVMONTHNAME12 176 
#define  LOCALE_SABBREVMONTHNAME13 175 
#define  LOCALE_SABBREVMONTHNAME2 174 
#define  LOCALE_SABBREVMONTHNAME3 173 
#define  LOCALE_SABBREVMONTHNAME4 172 
#define  LOCALE_SABBREVMONTHNAME5 171 
#define  LOCALE_SABBREVMONTHNAME6 170 
#define  LOCALE_SABBREVMONTHNAME7 169 
#define  LOCALE_SABBREVMONTHNAME8 168 
#define  LOCALE_SABBREVMONTHNAME9 167 
#define  LOCALE_SCURRENCY 166 
#define  LOCALE_SDATE 165 
#define  LOCALE_SDAYNAME1 164 
#define  LOCALE_SDAYNAME2 163 
#define  LOCALE_SDAYNAME3 162 
#define  LOCALE_SDAYNAME4 161 
#define  LOCALE_SDAYNAME5 160 
#define  LOCALE_SDAYNAME6 159 
#define  LOCALE_SDAYNAME7 158 
#define  LOCALE_SDECIMAL 157 
#define  LOCALE_SGROUPING 156 
#define  LOCALE_SINTLSYMBOL 155 
#define  LOCALE_SLONGDATE 154 
#define  LOCALE_SMONDECIMALSEP 153 
#define  LOCALE_SMONGROUPING 152 
#define  LOCALE_SMONTHNAME1 151 
#define  LOCALE_SMONTHNAME10 150 
#define  LOCALE_SMONTHNAME11 149 
#define  LOCALE_SMONTHNAME12 148 
#define  LOCALE_SMONTHNAME13 147 
#define  LOCALE_SMONTHNAME2 146 
#define  LOCALE_SMONTHNAME3 145 
#define  LOCALE_SMONTHNAME4 144 
#define  LOCALE_SMONTHNAME5 143 
#define  LOCALE_SMONTHNAME6 142 
#define  LOCALE_SMONTHNAME7 141 
#define  LOCALE_SMONTHNAME8 140 
#define  LOCALE_SMONTHNAME9 139 
#define  LOCALE_SMONTHOUSANDSEP 138 
#define  LOCALE_SNATIVECURRNAME 137 
#define  LOCALE_SNATIVEDIGITS 136 
#define  LOCALE_SNEGATIVESIGN 135 
#define  LOCALE_SPOSITIVESIGN 134 
#define  LOCALE_SSHORTDATE 133 
#define  LOCALE_SSORTNAME 132 
#define  LOCALE_STHOUSAND 131 
#define  LOCALE_STIME 130 
#define  LOCALE_STIMEFORMAT 129 
#define  LOCALE_SYEARMONTH 128 
 scalar_t__ LOCALE_SYSTEM_DEFAULT ; 
 scalar_t__ LOCALE_USER_DEFAULT ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  NLS_GetLanguageGroupName (void*,char*,int) ; 
 scalar_t__ NLS_RegEnumValue (void*,int,char*,int,char*,int) ; 
 void* NLS_RegOpenKey (void*,char const*) ; 
 int /*<<< orphan*/  NtClose (void*) ; 
 scalar_t__ NtCreateKey (void**,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlInitUnicodeString (int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ RtlOpenCurrentUser (int /*<<< orphan*/ ,void**) ; 
 scalar_t__ STATUS_SUCCESS ; 
 int /*<<< orphan*/  SetLastError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ,char*,...) ; 
 int TRUE ; 
 int /*<<< orphan*/  WARN (char*) ; 
 int /*<<< orphan*/  WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
 scalar_t__ lcid_LC_COLLATE ; 
 scalar_t__ lcid_LC_CTYPE ; 
 scalar_t__ lcid_LC_MEASUREMENT ; 
 scalar_t__ lcid_LC_MONETARY ; 
 scalar_t__ lcid_LC_NUMERIC ; 
 scalar_t__ lcid_LC_PAPER ; 
 scalar_t__ lcid_LC_TELEPHONE ; 
 scalar_t__ lcid_LC_TIME ; 
 void* strtoulW (char*,int /*<<< orphan*/ *,int) ; 
 int stub1 (void*,char*,char*,int const,int /*<<< orphan*/ ) ; 
 int stub2 (void*,char*,char*,int const,int /*<<< orphan*/ ) ; 
 int stub3 (void*,scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int stub4 (void*,scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int stub5 (char*) ; 
 int stub6 (char*) ; 
 char* szLangGroupsKeyName ; 
 char* szLocaleKeyName ; 
 int wcslen (char*) ; 

__attribute__((used)) static inline void strcpynAtoW( WCHAR *dst, const char *src, size_t n )
{
    while (n > 1 && *src)
    {
        *dst++ = (unsigned char)*src++;
        n--;
    }
    if (n) *dst = 0;
}

__attribute__((used)) static inline UINT get_lcid_codepage( LCID lcid )
{
    UINT ret;
    if (!GetLocaleInfoW( lcid, LOCALE_IDEFAULTANSICODEPAGE|LOCALE_RETURN_NUMBER, (WCHAR *)&ret,
                         sizeof(ret)/sizeof(WCHAR) )) ret = 0;
    return ret;
}

__attribute__((used)) static LCID convert_default_lcid( LCID lcid, LCTYPE lctype )
{
    if (lcid == LOCALE_SYSTEM_DEFAULT ||
        lcid == LOCALE_USER_DEFAULT ||
        lcid == LOCALE_NEUTRAL)
    {
        LCID default_id = 0;

        switch(lctype & 0xffff)
        {
        case LOCALE_SSORTNAME:
            default_id = lcid_LC_COLLATE;
            break;

        case LOCALE_FONTSIGNATURE:
        case LOCALE_IDEFAULTANSICODEPAGE:
        case LOCALE_IDEFAULTCODEPAGE:
        case LOCALE_IDEFAULTEBCDICCODEPAGE:
        case LOCALE_IDEFAULTMACCODEPAGE:
        case LOCALE_IDEFAULTUNIXCODEPAGE:
            default_id = lcid_LC_CTYPE;
            break;

        case LOCALE_ICURRDIGITS:
        case LOCALE_ICURRENCY:
        case LOCALE_IINTLCURRDIGITS:
        case LOCALE_INEGCURR:
        case LOCALE_INEGSEPBYSPACE:
        case LOCALE_INEGSIGNPOSN:
        case LOCALE_INEGSYMPRECEDES:
        case LOCALE_IPOSSEPBYSPACE:
        case LOCALE_IPOSSIGNPOSN:
        case LOCALE_IPOSSYMPRECEDES:
        case LOCALE_SCURRENCY:
        case LOCALE_SINTLSYMBOL:
        case LOCALE_SMONDECIMALSEP:
        case LOCALE_SMONGROUPING:
        case LOCALE_SMONTHOUSANDSEP:
        case LOCALE_SNATIVECURRNAME:
            default_id = lcid_LC_MONETARY;
            break;

        case LOCALE_IDIGITS:
        case LOCALE_IDIGITSUBSTITUTION:
        case LOCALE_ILZERO:
        case LOCALE_INEGNUMBER:
        case LOCALE_SDECIMAL:
        case LOCALE_SGROUPING:
        //case LOCALE_SNAN:
        case LOCALE_SNATIVEDIGITS:
        case LOCALE_SNEGATIVESIGN:
        //case LOCALE_SNEGINFINITY:
        //case LOCALE_SPOSINFINITY:
        case LOCALE_SPOSITIVESIGN:
        case LOCALE_STHOUSAND:
            default_id = lcid_LC_NUMERIC;
            break;

        case LOCALE_ICALENDARTYPE:
        case LOCALE_ICENTURY:
        case LOCALE_IDATE:
        case LOCALE_IDAYLZERO:
        case LOCALE_IFIRSTDAYOFWEEK:
        case LOCALE_IFIRSTWEEKOFYEAR:
        case LOCALE_ILDATE:
        case LOCALE_IMONLZERO:
        case LOCALE_IOPTIONALCALENDAR:
        case LOCALE_ITIME:
        case LOCALE_ITIMEMARKPOSN:
        case LOCALE_ITLZERO:
        case LOCALE_S1159:
        case LOCALE_S2359:
        case LOCALE_SABBREVDAYNAME1:
        case LOCALE_SABBREVDAYNAME2:
        case LOCALE_SABBREVDAYNAME3:
        case LOCALE_SABBREVDAYNAME4:
        case LOCALE_SABBREVDAYNAME5:
        case LOCALE_SABBREVDAYNAME6:
        case LOCALE_SABBREVDAYNAME7:
        case LOCALE_SABBREVMONTHNAME1:
        case LOCALE_SABBREVMONTHNAME2:
        case LOCALE_SABBREVMONTHNAME3:
        case LOCALE_SABBREVMONTHNAME4:
        case LOCALE_SABBREVMONTHNAME5:
        case LOCALE_SABBREVMONTHNAME6:
        case LOCALE_SABBREVMONTHNAME7:
        case LOCALE_SABBREVMONTHNAME8:
        case LOCALE_SABBREVMONTHNAME9:
        case LOCALE_SABBREVMONTHNAME10:
        case LOCALE_SABBREVMONTHNAME11:
        case LOCALE_SABBREVMONTHNAME12:
        case LOCALE_SABBREVMONTHNAME13:
        case LOCALE_SDATE:
        case LOCALE_SDAYNAME1:
        case LOCALE_SDAYNAME2:
        case LOCALE_SDAYNAME3:
        case LOCALE_SDAYNAME4:
        case LOCALE_SDAYNAME5:
        case LOCALE_SDAYNAME6:
        case LOCALE_SDAYNAME7:
        //case LOCALE_SDURATION:
        case LOCALE_SLONGDATE:
        case LOCALE_SMONTHNAME1:
        case LOCALE_SMONTHNAME2:
        case LOCALE_SMONTHNAME3:
        case LOCALE_SMONTHNAME4:
        case LOCALE_SMONTHNAME5:
        case LOCALE_SMONTHNAME6:
        case LOCALE_SMONTHNAME7:
        case LOCALE_SMONTHNAME8:
        case LOCALE_SMONTHNAME9:
        case LOCALE_SMONTHNAME10:
        case LOCALE_SMONTHNAME11:
        case LOCALE_SMONTHNAME12:
        case LOCALE_SMONTHNAME13:
        case LOCALE_SSHORTDATE:
        //case LOCALE_SSHORTESTDAYNAME1:
        //case LOCALE_SSHORTESTDAYNAME2:
        //case LOCALE_SSHORTESTDAYNAME3:
        //case LOCALE_SSHORTESTDAYNAME4:
        //case LOCALE_SSHORTESTDAYNAME5:
        //case LOCALE_SSHORTESTDAYNAME6:
        //case LOCALE_SSHORTESTDAYNAME7:
        case LOCALE_STIME:
        case LOCALE_STIMEFORMAT:
        case LOCALE_SYEARMONTH:
            default_id = lcid_LC_TIME;
            break;

        case LOCALE_IPAPERSIZE:
            default_id = lcid_LC_PAPER;
            break;

        case LOCALE_IMEASURE:
            default_id = lcid_LC_MEASUREMENT;
            break;

        case LOCALE_ICOUNTRY:
            default_id = lcid_LC_TELEPHONE;
            break;
        }
        if (default_id) lcid = default_id;
    }
    return ConvertDefaultLocale( lcid );
}

__attribute__((used)) static BOOL is_genitive_name_supported( LCTYPE lctype )
{
    switch(lctype & 0xffff)
    {
    case LOCALE_SMONTHNAME1:
    case LOCALE_SMONTHNAME2:
    case LOCALE_SMONTHNAME3:
    case LOCALE_SMONTHNAME4:
    case LOCALE_SMONTHNAME5:
    case LOCALE_SMONTHNAME6:
    case LOCALE_SMONTHNAME7:
    case LOCALE_SMONTHNAME8:
    case LOCALE_SMONTHNAME9:
    case LOCALE_SMONTHNAME10:
    case LOCALE_SMONTHNAME11:
    case LOCALE_SMONTHNAME12:
    case LOCALE_SMONTHNAME13:
         return TRUE;
    default:
         return FALSE;
    }
}

__attribute__((used)) static inline HANDLE create_registry_key(void)
{
    static const WCHAR cplW[] = {'C','o','n','t','r','o','l',' ','P','a','n','e','l',0};
    static const WCHAR intlW[] = {'I','n','t','e','r','n','a','t','i','o','n','a','l',0};
    OBJECT_ATTRIBUTES attr;
    UNICODE_STRING nameW;
    HANDLE cpl_key, hkey = 0;

    if (RtlOpenCurrentUser( KEY_ALL_ACCESS, &hkey ) != STATUS_SUCCESS) return 0;

    attr.Length = sizeof(attr);
    attr.RootDirectory = hkey;
    attr.ObjectName = &nameW;
    attr.Attributes = 0;
    attr.SecurityDescriptor = NULL;
    attr.SecurityQualityOfService = NULL;
    RtlInitUnicodeString( &nameW, cplW );

    if (!NtCreateKey( &cpl_key, KEY_ALL_ACCESS, &attr, 0, NULL, 0, NULL ))
    {
        NtClose( attr.RootDirectory );
        attr.RootDirectory = cpl_key;
        RtlInitUnicodeString( &nameW, intlW );
        if (NtCreateKey( &hkey, KEY_ALL_ACCESS, &attr, 0, NULL, 0, NULL )) hkey = 0;
    }
    NtClose( attr.RootDirectory );
    return hkey;
}

__attribute__((used)) static BOOL NLS_EnumSystemLanguageGroups(ENUMLANGUAGEGROUP_CALLBACKS *lpProcs)
{
    WCHAR szNumber[10], szValue[4];
    HANDLE hKey;
    BOOL bContinue = TRUE;
    ULONG ulIndex = 0;

    if (!lpProcs)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    switch (lpProcs->dwFlags)
    {
    case 0:
        /* Default to LGRPID_INSTALLED */
        lpProcs->dwFlags = LGRPID_INSTALLED;
        /* Fall through... */
    case LGRPID_INSTALLED:
    case LGRPID_SUPPORTED:
        break;
    default:
        SetLastError(ERROR_INVALID_FLAGS);
        return FALSE;
    }

    hKey = NLS_RegOpenKey( 0, szLangGroupsKeyName );

    if (!hKey)
        FIXME("NLS registry key not found. Please apply the default registry file 'wine.inf'\n");

    while (bContinue)
    {
        if (NLS_RegEnumValue( hKey, ulIndex, szNumber, sizeof(szNumber),
                              szValue, sizeof(szValue) ))
        {
            BOOL bInstalled = szValue[0] == '1';
            LGRPID lgrpid = strtoulW( szNumber, NULL, 16 );

            TRACE("grpid %s (%sinstalled)\n", debugstr_w(szNumber),
                   bInstalled ? "" : "not ");

            if (lpProcs->dwFlags == LGRPID_SUPPORTED || bInstalled)
            {
                WCHAR szGrpName[48];

                if (!NLS_GetLanguageGroupName( lgrpid, szGrpName, sizeof(szGrpName) / sizeof(WCHAR) ))
                    szGrpName[0] = '\0';

                if (lpProcs->procW)
                    bContinue = lpProcs->procW( lgrpid, szNumber, szGrpName, lpProcs->dwFlags,
                                                lpProcs->lParam );
                else
                {
                    char szNumberA[sizeof(szNumber)/sizeof(WCHAR)];
                    char szGrpNameA[48];

                    /* FIXME: MSDN doesn't say which code page the W->A translation uses,
                     *        or whether the language names are ever localised. Assume CP_ACP.
                     */

                    WideCharToMultiByte(CP_ACP, 0, szNumber, -1, szNumberA, sizeof(szNumberA), 0, 0);
                    WideCharToMultiByte(CP_ACP, 0, szGrpName, -1, szGrpNameA, sizeof(szGrpNameA), 0, 0);

                    bContinue = lpProcs->procA( lgrpid, szNumberA, szGrpNameA, lpProcs->dwFlags,
                                                lpProcs->lParam );
                }
            }

            ulIndex++;
        }
        else
            bContinue = FALSE;

        if (!bContinue)
            break;
    }

    if (hKey)
        NtClose( hKey );

    return TRUE;
}

__attribute__((used)) static BOOL NLS_EnumLanguageGroupLocales(ENUMLANGUAGEGROUPLOCALE_CALLBACKS *lpProcs)
{
    static const WCHAR szAlternateSortsKeyName[] = {
      'A','l','t','e','r','n','a','t','e',' ','S','o','r','t','s','\0'
    };
    WCHAR szNumber[10], szValue[4];
    HANDLE hKey;
    BOOL bContinue = TRUE, bAlternate = FALSE;
    LGRPID lgrpid;
    ULONG ulIndex = 1;  /* Ignore default entry of 1st key */

    if (!lpProcs || !lpProcs->lgrpid || lpProcs->lgrpid > LGRPID_ARMENIAN)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    if (lpProcs->dwFlags)
    {
        SetLastError(ERROR_INVALID_FLAGS);
        return FALSE;
    }

    hKey = NLS_RegOpenKey( 0, szLocaleKeyName );

    if (!hKey)
        WARN("NLS registry key not found. Please apply the default registry file 'wine.inf'\n");

    while (bContinue)
    {
        if (NLS_RegEnumValue( hKey, ulIndex, szNumber, sizeof(szNumber),
                              szValue, sizeof(szValue) ))
        {
            lgrpid = strtoulW( szValue, NULL, 16 );

            TRACE("lcid %s, grpid %d (%smatched)\n", debugstr_w(szNumber),
                   lgrpid, lgrpid == lpProcs->lgrpid ? "" : "not ");

            if (lgrpid == lpProcs->lgrpid)
            {
                LCID lcid;

                lcid = strtoulW( szNumber, NULL, 16 );

                /* FIXME: native returns extra text for a few (17/150) locales, e.g:
                 * '00000437          ;Georgian'
                 * At present we only pass the LCID string.
                 */

                if (lpProcs->procW)
                    bContinue = lpProcs->procW( lgrpid, lcid, szNumber, lpProcs->lParam );
                else
                {
                    char szNumberA[sizeof(szNumber)/sizeof(WCHAR)];

                    WideCharToMultiByte(CP_ACP, 0, szNumber, -1, szNumberA, sizeof(szNumberA), 0, 0);

                    bContinue = lpProcs->procA( lgrpid, lcid, szNumberA, lpProcs->lParam );
                }
            }

            ulIndex++;
        }
        else
        {
            /* Finished enumerating this key */
            if (!bAlternate)
            {
                /* Enumerate alternate sorts also */
                hKey = NLS_RegOpenKey( hKey, szAlternateSortsKeyName );
                bAlternate = TRUE;
                ulIndex = 0;
            }
            else
                bContinue = FALSE; /* Finished both keys */
        }

        if (!bContinue)
            break;
    }

    if (hKey)
        NtClose( hKey );

    return TRUE;
}

__attribute__((used)) static BOOL NLS_EnumSystemCodePages(ENUMSYSTEMCODEPAGES_CALLBACKS *lpProcs)
{
    WCHAR szNumber[5 + 1], szValue[MAX_PATH];
    HANDLE hKey;
    BOOL bContinue = TRUE;
    ULONG ulIndex = 0;

    if (!lpProcs)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    switch (lpProcs->dwFlags)
    {
        case CP_INSTALLED:
        case CP_SUPPORTED:
            break;
        default:
            SetLastError(ERROR_INVALID_FLAGS);
            return FALSE;
    }

    hKey = NLS_RegOpenKey(0, L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\NLS\\CodePage");
    if (!hKey)
    {
        WARN("NLS_RegOpenKey() failed\n");
        return FALSE;
    }

    while (bContinue)
    {
        if (NLS_RegEnumValue(hKey, ulIndex, szNumber, sizeof(szNumber),
                             szValue, sizeof(szValue)))
        {
            if ((lpProcs->dwFlags == CP_SUPPORTED)||
                ((lpProcs->dwFlags == CP_INSTALLED)&&(wcslen(szValue) > 2)))
            {
                if (lpProcs->procW)
                {
                    bContinue = lpProcs->procW(szNumber);
                }
                else
                {
                    char szNumberA[sizeof(szNumber)/sizeof(WCHAR)];

                    WideCharToMultiByte(CP_ACP, 0, szNumber, -1, szNumberA, sizeof(szNumberA), 0, 0);
                    bContinue = lpProcs->procA(szNumberA);
                }
            }

            ulIndex++;

        } else bContinue = FALSE;

        if (!bContinue)
            break;
    }

    if (hKey)
        NtClose(hKey);

    return TRUE;
}

