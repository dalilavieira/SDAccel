#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WORD ;
typedef  int /*<<< orphan*/  const WCHAR ;
struct TYPE_16__ {scalar_t__ cb; } ;
struct TYPE_17__ {TYPE_1__ mkid; } ;
typedef  int /*<<< orphan*/  STRRET ;
typedef  int /*<<< orphan*/  const* LPWSTR ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  char* LPSTR ;
typedef  scalar_t__ LPSHELLFOLDER ;
typedef  TYPE_2__* LPCITEMIDLIST ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  E_FAIL ; 
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int) ; 
 int GetVersion () ; 
 int /*<<< orphan*/  IID_IShellFolder ; 
#define  ILGDN_FORPARSING 130 
#define  ILGDN_INFOLDER 129 
#define  ILGDN_NORMAL 128 
 int ILGetDisplayNameExW (scalar_t__,TYPE_2__*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  IShellFolder_GetDisplayNameOf (scalar_t__,TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IShellFolder_Release (scalar_t__) ; 
 int MAX_PATH ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  NO_ERROR ; 
 scalar_t__ SHAlloc (int) ; 
 int /*<<< orphan*/  SHBindToParent (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__**) ; 
 int SHGDN_FORADDRESSBAR ; 
 int SHGDN_FORPARSING ; 
 int SHGDN_INFOLDER ; 
 int SHGDN_NORMAL ; 
 int /*<<< orphan*/  SHGetDesktopFolder (scalar_t__*) ; 
 int SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StrRetToStrNW (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  TRACE (char*,scalar_t__,TYPE_2__*,char*,...) ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int _ILIsDesktop (TYPE_2__*) ; 
 int /*<<< orphan*/  debugstr_a (char*) ; 
 int /*<<< orphan*/  debugstr_w (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int lstrlenW (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  memcmp (TYPE_2__*,TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char const*) ; 

__attribute__((used)) static inline 
BOOL    _ILIsEqualSimple        (LPCITEMIDLIST pidlA, LPCITEMIDLIST pidlB)
{
    return (pidlA->mkid.cb > 0 && !memcmp(pidlA, pidlB, pidlA->mkid.cb)) ||
            (!pidlA->mkid.cb && !pidlB->mkid.cb);
}

__attribute__((used)) static inline
BOOL    _ILIsEmpty              (LPCITEMIDLIST pidl) { return _ILIsDesktop(pidl); }

__attribute__((used)) static __inline BOOL SHELL_OsIsUnicode(void)
{
    /* if high-bit of version is 0, we are emulating NT */
    return !(GetVersion() & 0x80000000);
}

__attribute__((used)) static __inline void __SHCloneStrA(char **target, const char *source)
{
	*target = (char *)SHAlloc(strlen(source) + 1);
	strcpy(*target, source);
}

__attribute__((used)) static __inline void __SHCloneStrWtoA(char **target, const WCHAR *source)
{
	int len = WideCharToMultiByte(CP_ACP, 0, source, -1, NULL, 0, NULL, NULL);
	*target = (char *)SHAlloc(len);
	WideCharToMultiByte(CP_ACP, 0, source, -1, *target, len, NULL, NULL);
}

__attribute__((used)) static __inline void __SHCloneStrW(WCHAR **target, const WCHAR *source)
{
	*target = (WCHAR *)SHAlloc((lstrlenW(source) + 1) * sizeof(WCHAR) );
	lstrcpyW(*target, source);
}

__attribute__((used)) static __inline LPWSTR __SHCloneStrAtoW(WCHAR **target, const char *source)
{
	int len = MultiByteToWideChar(CP_ACP, 0, source, -1, NULL, 0);
	*target = (WCHAR *)SHAlloc(len * sizeof(WCHAR));
	MultiByteToWideChar(CP_ACP, 0, source, -1, *target, len);
	return *target;
}

__attribute__((used)) static BOOL ILGetDisplayNameExA(LPSHELLFOLDER psf, LPCITEMIDLIST pidl, LPSTR path, DWORD type)
{
    BOOL ret = FALSE;
    WCHAR wPath[MAX_PATH];

    TRACE("%p %p %p %d\n", psf, pidl, path, type);

    if (!pidl || !path)
        return FALSE;

    ret = ILGetDisplayNameExW(psf, pidl, wPath, type);
    WideCharToMultiByte(CP_ACP, 0, wPath, -1, path, MAX_PATH, NULL, NULL);
    TRACE("%p %p %s\n", psf, pidl, debugstr_a(path));

    return ret;
}

BOOL ILGetDisplayNameExW(LPSHELLFOLDER psf, LPCITEMIDLIST pidl, LPWSTR path, DWORD type)
{
    LPSHELLFOLDER psfParent, lsf = psf;
    HRESULT ret = NO_ERROR;
    LPCITEMIDLIST pidllast;
    STRRET strret;
    DWORD flag;

    TRACE("%p %p %p %x\n", psf, pidl, path, type);

    if (!pidl || !path)
        return FALSE;

    if (!lsf)
    {
        ret = SHGetDesktopFolder(&lsf);
        if (FAILED(ret))
            return FALSE;
    }

    switch (type)
    {
    case ILGDN_FORPARSING:
        flag = SHGDN_FORPARSING | SHGDN_FORADDRESSBAR;
        break;
    case ILGDN_NORMAL:
        flag = SHGDN_NORMAL;
        break;
    case ILGDN_INFOLDER:
        flag = SHGDN_INFOLDER;
        break;
    default:
        FIXME("Unknown type parameter = %x\n", type);
        flag = SHGDN_FORPARSING | SHGDN_FORADDRESSBAR;
        break;
    }

    if (!*(const WORD*)pidl || type == ILGDN_FORPARSING)
    {
        ret = IShellFolder_GetDisplayNameOf(lsf, pidl, flag, &strret);
        if (SUCCEEDED(ret))
        {
            if(!StrRetToStrNW(path, MAX_PATH, &strret, pidl))
                ret = E_FAIL;
        }
    }
    else
    {
        ret = SHBindToParent(pidl, &IID_IShellFolder, (LPVOID*)&psfParent, &pidllast);
        if (SUCCEEDED(ret))
        {
            ret = IShellFolder_GetDisplayNameOf(psfParent, pidllast, flag, &strret);
            if (SUCCEEDED(ret))
            {
                if(!StrRetToStrNW(path, MAX_PATH, &strret, pidllast))
                    ret = E_FAIL;
            }
            IShellFolder_Release(psfParent);
        }
    }

    TRACE("%p %p %s\n", psf, pidl, debugstr_w(path));

    if (!psf)
        IShellFolder_Release(lsf);
    return SUCCEEDED(ret);
}

