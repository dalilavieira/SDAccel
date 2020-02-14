#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
struct TYPE_3__ {int cx; } ;
typedef  TYPE_1__ SIZE ;
typedef  int /*<<< orphan*/  SCRIPT_STRING_ANALYSIS ;
typedef  int* LPWSTR ;
typedef  int* LPINT ;
typedef  int* LPCWSTR ;
typedef  int INT ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/  HPEN ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CreatePen (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int GetFileVersionInfoSizeW (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetFileVersionInfoW (char*,int /*<<< orphan*/ ,int,void*) ; 
 int GetLayout (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetModuleFileNameW (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int GetTextAlign (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetTextColor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetTextExtentPointW (int /*<<< orphan*/ ,int*,int,TYPE_1__*) ; 
 int GetUserDefaultLangID () ; 
 int /*<<< orphan*/  HIWORD (int) ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int LAYOUT_RTL ; 
 scalar_t__ LOWORD (int) ; 
 int /*<<< orphan*/  LineTo (int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ MAKELANGID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  MoveToEx (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *) ; 
 int PREFIX ; 
 int /*<<< orphan*/  PRIMARYLANGID (int) ; 
 int /*<<< orphan*/  PS_SOLID ; 
 int /*<<< orphan*/  SIC_COMPLEX ; 
 int SSA_GLYPHS ; 
 int SSA_RTL ; 
 int /*<<< orphan*/  SUBLANG_NEUTRAL ; 
 scalar_t__ S_FALSE ; 
 scalar_t__ S_OK ; 
 scalar_t__ ScriptIsComplex (int*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ ScriptStringAnalyse (int /*<<< orphan*/ ,int*,int,int,int,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ScriptStringCPtoX (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ScriptStringFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SelectObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetProcessDefaultLayout (int) ; 
 int TA_RTLREADING ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  VerQueryValueW (void*,char const*,void**,int*) ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
 scalar_t__ iswspace (int) ; 
 int /*<<< orphan*/  sprintfW (char*,char const*,scalar_t__,int /*<<< orphan*/ ) ; 
 int wcslen (int*) ; 

__attribute__((used)) static int PSM_FindLastPrefix(LPCWSTR str, int count)
{
    int i, prefix_count = 0, index = -1;

    for (i = 0; i < count - 1; i++)
    {
        if (str[i] == PREFIX && str[i + 1] != PREFIX)
        {
            index = i - prefix_count;
            prefix_count++;
        }
        else if (str[i] == PREFIX && str[i + 1] == PREFIX)
        {
            i++;
        }
    }
    return index;
}

__attribute__((used)) static void PSM_PrepareToDraw(LPCWSTR str, INT count, LPWSTR new_str, LPINT new_count)
{
    int len, i = 0, j = 0;

    while (i < count)
    {
        if (str[i] == PREFIX || (iswspace(str[i]) && str[i] != L' '))
        {
            if (i < count - 1 && str[i + 1] == PREFIX)
                new_str[j++] = str[i++];
            else
                i++;
        }
        else
        {
            new_str[j++] = str[i++];
        }
    }

    new_str[j] = L'\0';   
    len = wcslen(new_str);
    *new_count = len;
}

__attribute__((used)) static void LPK_DrawUnderscore(HDC hdc, int x, int y, LPCWSTR str, int count, int offset)
{
    SCRIPT_STRING_ANALYSIS ssa;
    DWORD dwSSAFlags = SSA_GLYPHS;
    int prefix_x;
    int prefix_end;
    int pos;
    SIZE size;
    HPEN hpen;
    HPEN oldPen;
    HRESULT hr = S_FALSE;

    if (offset == -1)
        return;

    if (ScriptIsComplex(str, count, SIC_COMPLEX) == S_OK)
    {
        if (GetLayout(hdc) & LAYOUT_RTL || GetTextAlign(hdc) & TA_RTLREADING)
            dwSSAFlags |= SSA_RTL;
        
        hr = ScriptStringAnalyse(hdc, str, count, (3 * count / 2 + 16),
                                 -1, dwSSAFlags, -1, NULL, NULL, NULL, NULL, NULL, &ssa);
    }

    if (hr == S_OK)
    {
        ScriptStringCPtoX(ssa, offset, FALSE, &pos);
        prefix_x = x + pos;
        ScriptStringCPtoX(ssa, offset, TRUE, &pos);
        prefix_end = x + pos;
        ScriptStringFree(&ssa);
    }
    else
    {
        GetTextExtentPointW(hdc, str, offset, &size);
        prefix_x = x + size.cx;
        GetTextExtentPointW(hdc, str, offset + 1, &size);
        prefix_end = x + size.cx - 1;
    }
    hpen = CreatePen(PS_SOLID, 1, GetTextColor(hdc));
    oldPen = SelectObject(hdc, hpen);
    MoveToEx(hdc, prefix_x, y, NULL);
    LineTo(hdc, prefix_end, y);
    SelectObject(hdc, oldPen);
    DeleteObject(hpen);
}

__attribute__((used)) static void LPK_ApplyMirroring()
{  
    static const WCHAR translationW[] = { '\\','V','a','r','F','i','l','e','I','n','f','o',
                                          '\\','T','r','a','n','s','l','a','t','i','o','n', 0 };
    static const WCHAR filedescW[] = { '\\','S','t','r','i','n','g','F','i','l','e','I','n','f','o',
                                       '\\','%','0','4','x','%','0','4','x',
                                       '\\','F','i','l','e','D','e','s','c','r','i','p','t','i','o','n',0 };
    WCHAR *str, buffer[MAX_PATH];
#ifdef __REACTOS__
    DWORD i, version_layout = 0;
    UINT len;
#else
    DWORD i, len, version_layout = 0;
#endif
    DWORD user_lang = GetUserDefaultLangID();
    DWORD *languages;
    void *data = NULL;

    GetModuleFileNameW( 0, buffer, MAX_PATH );
    if (!(len = GetFileVersionInfoSizeW( buffer, NULL ))) goto done;
    if (!(data = HeapAlloc( GetProcessHeap(), 0, len ))) goto done;
    if (!GetFileVersionInfoW( buffer, 0, len, data )) goto done;
    if (!VerQueryValueW( data, translationW, (void **)&languages, &len ) || !len) goto done;

    len /= sizeof(DWORD);
    for (i = 0; i < len; i++) if (LOWORD(languages[i]) == user_lang) break;
    if (i == len)  /* try neutral language */
    for (i = 0; i < len; i++)
        if (LOWORD(languages[i]) == MAKELANGID( PRIMARYLANGID(user_lang), SUBLANG_NEUTRAL )) break;
    if (i == len) i = 0;  /* default to the first one */

    sprintfW( buffer, filedescW, LOWORD(languages[i]), HIWORD(languages[i]) );
    if (!VerQueryValueW( data, buffer, (void **)&str, &len )) goto done;
    TRACE( "found description %s\n", debugstr_w( str ));
    if (str[0] == 0x200e && str[1] == 0x200e) version_layout = LAYOUT_RTL;

done:
    HeapFree( GetProcessHeap(), 0, data );
    SetProcessDefaultLayout(version_layout);
}

