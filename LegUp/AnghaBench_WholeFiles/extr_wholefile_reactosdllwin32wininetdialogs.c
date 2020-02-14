#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {char const* member_0; size_t member_1; } ;
typedef  TYPE_1__ substr_t ;
struct TYPE_16__ {int /*<<< orphan*/  ref; } ;
typedef  TYPE_2__ req_file_t ;
struct TYPE_17__ {char* userName; char* password; TYPE_5__* appInfo; } ;
typedef  TYPE_3__ http_session_t ;
struct TYPE_18__ {TYPE_3__* session; } ;
typedef  TYPE_4__ http_request_t ;
struct TYPE_19__ {char* proxyUsername; char* proxyPassword; } ;
typedef  TYPE_5__ appinfo_t ;
typedef  int WORD ;
typedef  char WCHAR ;
typedef  int UINT ;
struct TYPE_21__ {int /*<<< orphan*/  cAlternateFileName; int /*<<< orphan*/  cFileName; int /*<<< orphan*/  dwReserved1; int /*<<< orphan*/  dwReserved0; int /*<<< orphan*/  nFileSizeLow; int /*<<< orphan*/  nFileSizeHigh; int /*<<< orphan*/  ftLastWriteTime; int /*<<< orphan*/  ftLastAccessTime; int /*<<< orphan*/  ftCreationTime; int /*<<< orphan*/  dwFileAttributes; } ;
struct TYPE_20__ {int /*<<< orphan*/  cAlternateFileName; int /*<<< orphan*/  cFileName; int /*<<< orphan*/  dwReserved1; int /*<<< orphan*/  dwReserved0; int /*<<< orphan*/  nFileSizeLow; int /*<<< orphan*/  nFileSizeHigh; int /*<<< orphan*/  ftLastWriteTime; int /*<<< orphan*/  ftLastAccessTime; int /*<<< orphan*/  ftCreationTime; int /*<<< orphan*/  dwFileAttributes; } ;
typedef  char* LPWSTR ;
typedef  TYPE_6__* LPWIN32_FIND_DATAW ;
typedef  TYPE_7__* LPWIN32_FIND_DATAA ;
typedef  char const* LPCWSTR ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HINTERNET ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  ERR (char*,int /*<<< orphan*/ ) ; 
 int FALSE ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowTextW (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ HTTP_QUERY_PROXY_AUTHENTICATE ; 
 scalar_t__ HTTP_QUERY_WWW_AUTHENTICATE ; 
 int /*<<< orphan*/  HttpQueryInfoW (int /*<<< orphan*/ ,scalar_t__,char*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  IDC_PASSWORD ; 
 int /*<<< orphan*/  IDC_USERNAME ; 
 int /*<<< orphan*/  InterlockedIncrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetWindowTextW (int /*<<< orphan*/ ,char*) ; 
 int TRUE ; 
 scalar_t__ WN_SUCCESS ; 
 scalar_t__ WNetCachePassword (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ WNetGetCachedPassword (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int*,scalar_t__) ; 
 int /*<<< orphan*/  WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
 int /*<<< orphan*/  heap_free (char*) ; 
 char* heap_strdupW (char*) ; 
 int /*<<< orphan*/  lstrcatW (char*,char const*) ; 
 int /*<<< orphan*/  lstrcpyW (char*,char const*) ; 
 char* strchrW (char*,char) ; 
 int /*<<< orphan*/  strcpyW (char*,char*) ; 
 int strlenW (char const*) ; 
 scalar_t__ strncmpW (char*,char const*,int) ; 
 char* strrchrW (char*,char) ; 

__attribute__((used)) static inline substr_t substr(const WCHAR *str, size_t len)
{
    substr_t r = {str, len};
    return r;
}

__attribute__((used)) static inline substr_t substrz(const WCHAR *str)
{
    return substr(str, strlenW(str));
}

__attribute__((used)) static inline void WININET_find_data_WtoA(LPWIN32_FIND_DATAW dataW, LPWIN32_FIND_DATAA dataA)
{
    dataA->dwFileAttributes = dataW->dwFileAttributes;
    dataA->ftCreationTime   = dataW->ftCreationTime;
    dataA->ftLastAccessTime = dataW->ftLastAccessTime;
    dataA->ftLastWriteTime  = dataW->ftLastWriteTime;
    dataA->nFileSizeHigh    = dataW->nFileSizeHigh;
    dataA->nFileSizeLow     = dataW->nFileSizeLow;
    dataA->dwReserved0      = dataW->dwReserved0;
    dataA->dwReserved1      = dataW->dwReserved1;
    WideCharToMultiByte(CP_ACP, 0, dataW->cFileName, -1, 
        dataA->cFileName, sizeof(dataA->cFileName),
        NULL, NULL);
    WideCharToMultiByte(CP_ACP, 0, dataW->cAlternateFileName, -1, 
        dataA->cAlternateFileName, sizeof(dataA->cAlternateFileName),
        NULL, NULL);
}

__attribute__((used)) static inline req_file_t *req_file_addref(req_file_t *req_file)
{
    InterlockedIncrement(&req_file->ref);
    return req_file;
}

__attribute__((used)) static BOOL WININET_GetAuthRealm( HINTERNET hRequest, LPWSTR szBuf, DWORD sz, BOOL proxy )
{
    LPWSTR p, q;
    DWORD index, query;
    static const WCHAR szRealm[] = { 'r','e','a','l','m','=',0 };

    if (proxy)
        query = HTTP_QUERY_PROXY_AUTHENTICATE;
    else
        query = HTTP_QUERY_WWW_AUTHENTICATE;

    /* extract the Realm from the response and show it */
    index = 0;
    if( !HttpQueryInfoW( hRequest, query, szBuf, &sz, &index) )
        return FALSE;

    /*
     * FIXME: maybe we should check that we're
     * dealing with 'Basic' Authentication
     */
    p = strchrW( szBuf, ' ' );
    if( !p || strncmpW( p+1, szRealm, strlenW(szRealm) ) )
    {
        ERR("response wrong? (%s)\n", debugstr_w(szBuf));
        return FALSE;
    }

    /* remove quotes */
    p += 7;
    if( *p == '"' )
    {
        p++;
        q = strrchrW( p, '"' );
        if( q )
            *q = 0;
    }
    strcpyW( szBuf, p );

    return TRUE;
}

__attribute__((used)) static BOOL WININET_GetSetPassword( HWND hdlg, LPCWSTR szServer, 
                                    LPCWSTR szRealm, BOOL bSet )
{
    WCHAR szResource[0x80], szUserPass[0x40];
    LPWSTR p;
    HWND hUserItem, hPassItem;
    DWORD r, dwMagic = 19;
    UINT r_len, u_len;
    WORD sz;
    static const WCHAR szColon[] = { ':',0 };
    static const WCHAR szbs[] = { '/', 0 };

    hUserItem = GetDlgItem( hdlg, IDC_USERNAME );
    hPassItem = GetDlgItem( hdlg, IDC_PASSWORD );

    /* now try fetch the username and password */
    lstrcpyW( szResource, szServer);
    lstrcatW( szResource, szbs);
    lstrcatW( szResource, szRealm);

    /*
     * WNetCachePassword is only concerned with the length
     * of the data stored (which we tell it) and it does
     * not use strlen() internally so we can add WCHAR data
     * instead of ASCII data and get it back the same way.
     */
    if( bSet )
    {
        szUserPass[0] = 0;
        GetWindowTextW( hUserItem, szUserPass, 
                        (sizeof szUserPass-1)/sizeof(WCHAR) );
        lstrcatW(szUserPass, szColon);
        u_len = strlenW( szUserPass );
        GetWindowTextW( hPassItem, szUserPass+u_len, 
                        (sizeof szUserPass)/sizeof(WCHAR)-u_len );

        r_len = (strlenW( szResource ) + 1)*sizeof(WCHAR);
        u_len = (strlenW( szUserPass ) + 1)*sizeof(WCHAR);
        r = WNetCachePassword( (CHAR*)szResource, r_len,
                               (CHAR*)szUserPass, u_len, dwMagic, 0 );

        return ( r == WN_SUCCESS );
    }

    sz = sizeof szUserPass;
    r_len = (strlenW( szResource ) + 1)*sizeof(WCHAR);
    r = WNetGetCachedPassword( (CHAR*)szResource, r_len,
                               (CHAR*)szUserPass, &sz, dwMagic );
    if( r != WN_SUCCESS )
        return FALSE;

    p = strchrW( szUserPass, ':' );
    if( p )
    {
        *p = 0;
        SetWindowTextW( hUserItem, szUserPass );
        SetWindowTextW( hPassItem, p+1 );
    }

    return TRUE;
}

__attribute__((used)) static BOOL WININET_SetAuthorization( http_request_t *request, LPWSTR username,
                                      LPWSTR password, BOOL proxy )
{
    http_session_t *session = request->session;
    LPWSTR p, q;

    p = heap_strdupW(username);
    if( !p )
        return FALSE;

    q = heap_strdupW(password);
    if( !q )
    {
        heap_free(p);
        return FALSE;
    }

    if (proxy)
    {
        appinfo_t *hIC = session->appInfo;

        heap_free(hIC->proxyUsername);
        hIC->proxyUsername = p;

        heap_free(hIC->proxyPassword);
        hIC->proxyPassword = q;
    }
    else
    {
        heap_free(session->userName);
        session->userName = p;

        heap_free(session->password);
        session->password = q;
    }

    return TRUE;
}

