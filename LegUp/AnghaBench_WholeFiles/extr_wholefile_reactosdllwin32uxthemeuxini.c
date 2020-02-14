#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  UXINI_FILE ;
struct TYPE_13__ {char* lpIni; char* lpCurLoc; char* lpEnd; } ;
typedef  TYPE_1__* PUXINI_FILE ;
typedef  char* LPCWSTR ;
typedef  int /*<<< orphan*/  HRSRC ;
typedef  int /*<<< orphan*/  HMODULE ;
typedef  int DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ CSTR_EQUAL ; 
 scalar_t__ CompareStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,char*,int) ; 
 int FALSE ; 
 int /*<<< orphan*/  FindResourceW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 TYPE_1__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  LOCALE_SYSTEM_DEFAULT ; 
 char* LoadResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NORM_IGNORECASE ; 
 int SizeofResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 
 int TRUE ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
 scalar_t__ isspace (char) ; 
 int /*<<< orphan*/  szTextFileResource ; 

PUXINI_FILE UXINI_LoadINI(HMODULE hTheme, LPCWSTR lpName) {
    HRSRC hrsc;
    LPCWSTR lpThemesIni = NULL;
    PUXINI_FILE uf;
    DWORD dwIniSize;

    TRACE("Loading resource INI %s\n", debugstr_w(lpName));

    if((hrsc = FindResourceW(hTheme, lpName, szTextFileResource))) {
        if(!(lpThemesIni = LoadResource(hTheme, hrsc))) {
            TRACE("%s resource not found\n", debugstr_w(lpName));
            return NULL;
        }
    }

    dwIniSize = SizeofResource(hTheme, hrsc) / sizeof(WCHAR);
    uf = HeapAlloc(GetProcessHeap(), 0, sizeof(UXINI_FILE));
    uf->lpIni = lpThemesIni;
    uf->lpCurLoc = lpThemesIni;
    uf->lpEnd = lpThemesIni + dwIniSize;
    return uf;
}

void UXINI_CloseINI(PUXINI_FILE uf)
{
    HeapFree(GetProcessHeap(), 0, uf);
}

__attribute__((used)) static inline BOOL UXINI_eof(PUXINI_FILE uf)
{
    return uf->lpCurLoc >= uf->lpEnd;
}

__attribute__((used)) static inline BOOL UXINI_isspace(WCHAR c)
{
    if (isspace(c)) return TRUE;
    if (c=='\r') return TRUE;
    return FALSE;
}

__attribute__((used)) static LPCWSTR UXINI_GetNextLine(PUXINI_FILE uf, DWORD *dwLen)
{
    LPCWSTR lpLineEnd;
    LPCWSTR lpLineStart;
    DWORD len;
    do {
        if(UXINI_eof(uf)) return NULL;
        /* Skip whitespace and empty lines */
        while(!UXINI_eof(uf) && (UXINI_isspace(*uf->lpCurLoc) || *uf->lpCurLoc == '\n')) uf->lpCurLoc++;
        lpLineStart = uf->lpCurLoc;
        lpLineEnd = uf->lpCurLoc;
        while(!UXINI_eof(uf) && *uf->lpCurLoc != '\n' && *uf->lpCurLoc != ';') lpLineEnd = ++uf->lpCurLoc;
        /* If comment was found, skip the rest of the line */
        if(*uf->lpCurLoc == ';')
            while(!UXINI_eof(uf) && *uf->lpCurLoc != '\n') uf->lpCurLoc++;
        len = (lpLineEnd - lpLineStart);
        if(*lpLineStart != ';' && len == 0)
            return NULL;
    } while(*lpLineStart == ';');
    /* Remove whitespace from end of line */
    while(UXINI_isspace(lpLineStart[len-1])) len--;
    *dwLen = len;

    return lpLineStart;
}

__attribute__((used)) static inline void UXINI_UnGetToLine(PUXINI_FILE uf, LPCWSTR lpLine)
{
    uf->lpCurLoc = lpLine;
}

LPCWSTR UXINI_GetNextSection(PUXINI_FILE uf, DWORD *dwLen)
{
    LPCWSTR lpLine;
    while((lpLine = UXINI_GetNextLine(uf, dwLen))) {
        /* Assuming a ']' ending to the section name */
        if(lpLine[0] == '[') {
            lpLine++;
            *dwLen -= 2;
            break;
        }
    }
    return lpLine;
}

BOOL UXINI_FindSection(PUXINI_FILE uf, LPCWSTR lpName)
{
    LPCWSTR lpSection;
    DWORD dwLen;
    while((lpSection = UXINI_GetNextSection(uf, &dwLen))) {
        if(CompareStringW(LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE, lpSection, dwLen, lpName, -1) == CSTR_EQUAL) {
            return TRUE;
        }
    }
    return FALSE;
}

LPCWSTR UXINI_GetNextValue(PUXINI_FILE uf, DWORD *dwNameLen, LPCWSTR *lpValue, DWORD *dwValueLen)
{
    LPCWSTR lpLine;
    LPCWSTR lpLineEnd;
    LPCWSTR name = NULL;
    LPCWSTR value = NULL;
    DWORD vallen = 0;
    DWORD namelen = 0;
    DWORD dwLen;
    lpLine = UXINI_GetNextLine(uf, &dwLen);
    if(!lpLine)
        return NULL;
    if(lpLine[0] == '[') {
        UXINI_UnGetToLine(uf, lpLine);
        return NULL;
    }
    lpLineEnd = lpLine + dwLen;

    name = lpLine;
    while(namelen < dwLen && *lpLine != '=') {
        lpLine++;
        namelen++;
    }
    if(*lpLine != '=') return NULL;
    lpLine++;

    /* Remove whitespace from end of name */
    while(UXINI_isspace(name[namelen-1])) namelen--;
    /* Remove whitespace from beginning of value */
    while(UXINI_isspace(*lpLine) && lpLine < lpLineEnd) lpLine++;
    value = lpLine;
    vallen = dwLen-(value-name);

    *dwNameLen = namelen;
    *dwValueLen = vallen;
    *lpValue = value;

    return name;
}

BOOL UXINI_FindValue(PUXINI_FILE uf, LPCWSTR lpName, LPCWSTR *lpValue, DWORD *dwValueLen)
{
    LPCWSTR name;
    DWORD namelen;

    while((name = UXINI_GetNextValue(uf, &namelen, lpValue, dwValueLen))) {
        if(CompareStringW(LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE, name, namelen, lpName, -1) == CSTR_EQUAL) {
            return TRUE;
        }
    }
    return FALSE;
}

