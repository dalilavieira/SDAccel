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
struct user_dirid {int id; char const* str; } ;
typedef  int /*<<< orphan*/  buffer ;
typedef  char WCHAR ;
typedef  int UINT ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  HINF ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int CSIDL_PROFILE ; 
 int DIRID_ABSOLUTE ; 
 int DIRID_ABSOLUTE_16BIT ; 
#define  DIRID_APPS 145 
#define  DIRID_BOOT 144 
#define  DIRID_COLOR 143 
#define  DIRID_DRIVERS 142 
#define  DIRID_FONTS 141 
#define  DIRID_HELP 140 
#define  DIRID_INF 139 
#define  DIRID_LOADER 138 
#define  DIRID_NULL 137 
#define  DIRID_PRINTPROCESSOR 136 
#define  DIRID_SHARED 135 
#define  DIRID_SPOOL 134 
#define  DIRID_SPOOLDRIVERS 133 
#define  DIRID_SYSTEM 132 
#define  DIRID_SYSTEM16 131 
 int DIRID_USER ; 
#define  DIRID_USERPROFILE 130 
#define  DIRID_VIEWERS 129 
#define  DIRID_WINDOWS 128 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int) ; 
 int /*<<< orphan*/  GetEnvironmentVariableW (char const*,char*,int) ; 
 int /*<<< orphan*/  GetPrintProcessorDirectoryW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int GetSystemDirectoryW (char*,int) ; 
 int /*<<< orphan*/  GetWindowsDirectoryW (char*,int) ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 struct user_dirid* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct user_dirid*,int) ; 
 int MAX_CSIDL_DIRID ; 
 int MAX_PATH ; 
 int MAX_SYSTEM_DIRID ; 
 int MIN_CSIDL_DIRID ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,char*,int) ; 
 int /*<<< orphan*/  SHGetSpecialFolderPathW (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 int alloc_user_dirids ; 
 char const** csidl_dirids ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
static  char const* get_csidl_dir (int) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int nb_user_dirids ; 
 int /*<<< orphan*/  strcatW (char*,char const*) ; 
 int strlenW (char const*) ; 
 char const** system_dirids ; 
 struct user_dirid* user_dirids ; 

__attribute__((used)) inline static WCHAR *strdupAtoW( const char *str )
{
    WCHAR *ret = NULL;
    if (str)
    {
        DWORD len = MultiByteToWideChar( CP_ACP, 0, str, -1, NULL, 0 );
        if ((ret = HeapAlloc( GetProcessHeap(), 0, len * sizeof(WCHAR) )))
            MultiByteToWideChar( CP_ACP, 0, str, -1, ret, len );
    }
    return ret;
}

__attribute__((used)) static const WCHAR *get_unknown_dirid(void)
{
    static WCHAR *unknown_dirid;
    static const WCHAR unknown_str[] = {'\\','u','n','k','n','o','w','n',0};

    if (!unknown_dirid)
    {
        UINT len = GetSystemDirectoryW( NULL, 0 ) + strlenW(unknown_str);
        if (!(unknown_dirid = HeapAlloc( GetProcessHeap(), 0, len * sizeof(WCHAR) ))) return NULL;
        GetSystemDirectoryW( unknown_dirid, len );
        strcatW( unknown_dirid, unknown_str );
    }
    return unknown_dirid;
}

__attribute__((used)) static const WCHAR *create_system_dirid( int dirid )
{
    static const WCHAR Null[]    = {0};
    static const WCHAR C_Root[]  = {'C',':','\\',0};
    static const WCHAR Drivers[] = {'\\','d','r','i','v','e','r','s',0};
    static const WCHAR Inf[]     = {'\\','i','n','f',0};
    static const WCHAR Help[]    = {'\\','h','e','l','p',0};
    static const WCHAR Fonts[]   = {'\\','f','o','n','t','s',0};
    static const WCHAR Viewers[] = {'\\','v','i','e','w','e','r','s',0};
    static const WCHAR System[]  = {'\\','s','y','s','t','e','m',0};
    static const WCHAR Spool[]   = {'\\','s','p','o','o','l',0};
    static const WCHAR UserProfile[] = {'U','S','E','R','P','R','O','F','I','L','E',0};

    WCHAR buffer[MAX_PATH+32], *str;
    int len;
    DWORD needed;

    switch(dirid)
    {
    case DIRID_NULL:
        return Null;
    case DIRID_WINDOWS:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        break;
    case DIRID_SYSTEM:
        GetSystemDirectoryW( buffer, MAX_PATH );
        break;
    case DIRID_DRIVERS:
        GetSystemDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Drivers );
        break;
    case DIRID_INF:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Inf );
        break;
    case DIRID_HELP:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Help );
        break;
    case DIRID_FONTS:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Fonts );
        break;
    case DIRID_VIEWERS:
        GetSystemDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Viewers );
        break;
    case DIRID_APPS:
        return C_Root;  /* FIXME */
    case DIRID_SHARED:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        break;
    case DIRID_BOOT:
        return C_Root;  /* FIXME */
    case DIRID_SYSTEM16:
        GetWindowsDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, System );
        break;
    case DIRID_SPOOL:
    case DIRID_SPOOLDRIVERS:  /* FIXME */
        GetWindowsDirectoryW( buffer, MAX_PATH );
        strcatW( buffer, Spool );
        break;
    case DIRID_USERPROFILE:
        if (GetEnvironmentVariableW( UserProfile, buffer, MAX_PATH )) break;
        return get_csidl_dir(CSIDL_PROFILE);
    case DIRID_LOADER:
        return C_Root;  /* FIXME */
    case DIRID_PRINTPROCESSOR:
        if (!GetPrintProcessorDirectoryW(NULL, NULL, 1, (LPBYTE)buffer, sizeof(buffer), &needed))
        {
            WARN( "cannot retrieve print processor directory\n" );
            return get_unknown_dirid();
        }
        break;
    case DIRID_COLOR:  /* FIXME */
    default:
        FIXME( "unknown dirid %d\n", dirid );
        return get_unknown_dirid();
    }
    len = (strlenW(buffer) + 1) * sizeof(WCHAR);
    if ((str = HeapAlloc( GetProcessHeap(), 0, len ))) memcpy( str, buffer, len );
    return str;
}

__attribute__((used)) static const WCHAR *get_csidl_dir( DWORD csidl )
{
    WCHAR buffer[MAX_PATH], *str;
    int len;

    if (!SHGetSpecialFolderPathW( NULL, buffer, csidl, TRUE ))
    {
        FIXME( "CSIDL %x not found\n", csidl );
        return get_unknown_dirid();
    }
    len = (strlenW(buffer) + 1) * sizeof(WCHAR);
    if ((str = HeapAlloc( GetProcessHeap(), 0, len ))) memcpy( str, buffer, len );
    return str;
}

const WCHAR *DIRID_get_string( int dirid )
{
    int i;

    if (dirid == DIRID_ABSOLUTE || dirid == DIRID_ABSOLUTE_16BIT) dirid = DIRID_NULL;

    if (dirid >= DIRID_USER)
    {
        for (i = 0; i < nb_user_dirids; i++)
            if (user_dirids[i].id == dirid) return user_dirids[i].str;
        WARN("user id %d not found\n", dirid );
        return NULL;
    }
    else if (dirid >= MIN_CSIDL_DIRID)
    {
        if (dirid > MAX_CSIDL_DIRID) return get_unknown_dirid();
        dirid -= MIN_CSIDL_DIRID;
        if (!csidl_dirids[dirid]) csidl_dirids[dirid] = get_csidl_dir( dirid );
        return csidl_dirids[dirid];
    }
    else
    {
        if (dirid > MAX_SYSTEM_DIRID) return get_unknown_dirid();
        if (!system_dirids[dirid]) system_dirids[dirid] = create_system_dirid( dirid );
        return system_dirids[dirid];
    }
}

__attribute__((used)) static BOOL store_user_dirid( HINF hinf, int id, WCHAR *str )
{
    int i;

    for (i = 0; i < nb_user_dirids; i++) if (user_dirids[i].id == id) break;

    if (i < nb_user_dirids) HeapFree( GetProcessHeap(), 0, user_dirids[i].str );
    else
    {
        if (nb_user_dirids >= alloc_user_dirids)
        {
            int new_size = max( 32, alloc_user_dirids * 2 );

	    struct user_dirid *new;

	    if (user_dirids)
                new = HeapReAlloc( GetProcessHeap(), 0, user_dirids,
                                                  new_size * sizeof(*new) );
	    else
                new = HeapAlloc( GetProcessHeap(), 0, 
                                                  new_size * sizeof(*new) );

            if (!new) return FALSE;
            user_dirids = new;
            alloc_user_dirids = new_size;
        }
        nb_user_dirids++;
    }
    user_dirids[i].id  = id;
    user_dirids[i].str = str;
    TRACE("id %d -> %s\n", id, debugstr_w(str) );
    return TRUE;
}

