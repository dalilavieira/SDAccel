#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
typedef  size_t UINT ;
struct TYPE_4__ {int pFiles; int /*<<< orphan*/  fWide; } ;
struct TYPE_3__ {size_t cidl; int* aoffset; } ;
typedef  char* LPITEMIDLIST ;
typedef  TYPE_1__* LPIDA ;
typedef  char* LPBYTE ;
typedef  int /*<<< orphan*/ * HGLOBAL ;
typedef  TYPE_2__ DROPFILES ;
typedef  int /*<<< orphan*/  CIDA ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int GHND ; 
 int GMEM_SHARE ; 
 int /*<<< orphan*/ * GlobalAlloc (int,int) ; 
 void* GlobalLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GlobalUnlock (int /*<<< orphan*/ *) ; 
 char* ILCombine (char*,char*) ; 
 int ILGetSize (char*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  PathAddBackslashW (char*) ; 
 int /*<<< orphan*/  SHFree (char*) ; 
 int /*<<< orphan*/  SHGetPathFromIDListA (char*,char*) ; 
 int /*<<< orphan*/  SHGetPathFromIDListW (char*,char*) ; 
 int /*<<< orphan*/  TRACE (char*,char*,char**,size_t) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  _ILSimpleGetTextW (char*,char*,int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  strcpyW (char*,char*) ; 
 int strlen (char*) ; 
 int strlenW (char*) ; 

HGLOBAL RenderHDROP(LPITEMIDLIST pidlRoot, LPITEMIDLIST * apidl, UINT cidl)
{
	UINT i;
#ifdef __REACTOS__
        int size = 0;
#else
	int rootlen = 0,size = 0;
	WCHAR wszRootPath[MAX_PATH];
#endif
	WCHAR wszFileName[MAX_PATH];
	HGLOBAL hGlobal = NULL;
	DROPFILES *pDropFiles;
	int offset;
#ifdef __REACTOS__
        LPITEMIDLIST *pidls;
#endif

	TRACE("(%p,%p,%u)\n", pidlRoot, apidl, cidl);

#ifdef __REACTOS__
        pidls = (LPITEMIDLIST *)HeapAlloc(GetProcessHeap(), 0, cidl * sizeof(*pidls));
        if (!pidls)
            goto cleanup;
#endif

	/* get the size needed */
	size = sizeof(DROPFILES);

#ifndef __REACTOS__
	SHGetPathFromIDListW(pidlRoot, wszRootPath);
	PathAddBackslashW(wszRootPath);
	rootlen = strlenW(wszRootPath);
#endif

	for (i=0; i<cidl;i++)
	{
#ifdef __REACTOS__
          pidls[i] = ILCombine(pidlRoot, apidl[i]);
          SHGetPathFromIDListW(pidls[i], wszFileName);
          size += (wcslen(wszFileName) + 1) * sizeof(WCHAR);
#else
	  _ILSimpleGetTextW(apidl[i], wszFileName, MAX_PATH);
	  size += (rootlen + strlenW(wszFileName) + 1) * sizeof(WCHAR);
#endif
	}

	size += sizeof(WCHAR);

	/* Fill the structure */
	hGlobal = GlobalAlloc(GHND|GMEM_SHARE, size);
#ifdef __REACTOS__
        if(!hGlobal) goto cleanup;
#else
	if(!hGlobal) return hGlobal;
#endif

        pDropFiles = GlobalLock(hGlobal);
	offset = (sizeof(DROPFILES) + sizeof(WCHAR) - 1) / sizeof(WCHAR);
        pDropFiles->pFiles = offset * sizeof(WCHAR);
        pDropFiles->fWide = TRUE;

#ifndef __REACTOS__
	strcpyW(wszFileName, wszRootPath);
#endif

	for (i=0; i<cidl;i++)
	{

#ifdef __REACTOS__
          SHGetPathFromIDListW(pidls[i], wszFileName);
          wcscpy(((WCHAR*)pDropFiles)+offset, wszFileName);
          offset += wcslen(wszFileName) + 1;
          ILFree(pidls[i]);
#else
	  _ILSimpleGetTextW(apidl[i], wszFileName + rootlen, MAX_PATH - rootlen);
	  strcpyW(((WCHAR*)pDropFiles)+offset, wszFileName);
	  offset += strlenW(wszFileName) + 1;
#endif
	}

	((WCHAR*)pDropFiles)[offset] = 0;
	GlobalUnlock(hGlobal);

#ifdef __REACTOS__
cleanup:
    if(pidls)
        HeapFree(GetProcessHeap(), 0, pidls);
#endif

	return hGlobal;
}

HGLOBAL RenderSHELLIDLIST (LPITEMIDLIST pidlRoot, LPITEMIDLIST * apidl, UINT cidl)
{
	UINT i;
	int offset = 0, sizePidl, size;
	HGLOBAL hGlobal;
	LPIDA	pcida;

	TRACE("(%p,%p,%u)\n", pidlRoot, apidl, cidl);

	/* get the size needed */
	size = sizeof(CIDA) + sizeof (UINT)*(cidl);	/* header */
	size += ILGetSize (pidlRoot);			/* root pidl */
	for(i=0; i<cidl; i++)
	{
	  size += ILGetSize(apidl[i]);			/* child pidls */
	}

	/* fill the structure */
	hGlobal = GlobalAlloc(GHND|GMEM_SHARE, size);
	if(!hGlobal) return hGlobal;
	pcida = GlobalLock (hGlobal);
	pcida->cidl = cidl;

	/* root pidl */
	offset = sizeof(CIDA) + sizeof (UINT)*(cidl);
	pcida->aoffset[0] = offset;			/* first element */
	sizePidl = ILGetSize (pidlRoot);
	memcpy(((LPBYTE)pcida)+offset, pidlRoot, sizePidl);
	offset += sizePidl;

	for(i=0; i<cidl; i++)				/* child pidls */
	{
	  pcida->aoffset[i+1] = offset;
	  sizePidl = ILGetSize(apidl[i]);
	  memcpy(((LPBYTE)pcida)+offset, apidl[i], sizePidl);
	  offset += sizePidl;
	}

	GlobalUnlock(hGlobal);
	return hGlobal;
}

HGLOBAL RenderFILENAMEA (LPITEMIDLIST pidlRoot, LPITEMIDLIST * apidl, UINT cidl)
{
	int size = 0;
	char szTemp[MAX_PATH], *szFileName;
	LPITEMIDLIST pidl;
	HGLOBAL hGlobal;
	BOOL bSuccess;

	TRACE("(%p,%p,%u)\n", pidlRoot, apidl, cidl);

	/* get path of combined pidl */
	pidl = ILCombine(pidlRoot, apidl[0]);
	if (!pidl)
		return 0;

	bSuccess = SHGetPathFromIDListA(pidl, szTemp);
	SHFree(pidl);
	if (!bSuccess)
		return 0;

	size = strlen(szTemp) + 1;

	/* fill the structure */
	hGlobal = GlobalAlloc(GHND|GMEM_SHARE, size);
	if(!hGlobal) return hGlobal;
	szFileName = GlobalLock(hGlobal);
	memcpy(szFileName, szTemp, size);
	GlobalUnlock(hGlobal);

	return hGlobal;
}

HGLOBAL RenderFILENAMEW (LPITEMIDLIST pidlRoot, LPITEMIDLIST * apidl, UINT cidl)
{
	int size = 0;
	WCHAR szTemp[MAX_PATH], *szFileName;
	LPITEMIDLIST pidl;
	HGLOBAL hGlobal;
	BOOL bSuccess;

	TRACE("(%p,%p,%u)\n", pidlRoot, apidl, cidl);

	/* get path of combined pidl */
	pidl = ILCombine(pidlRoot, apidl[0]);
	if (!pidl)
		return 0;

	bSuccess = SHGetPathFromIDListW(pidl, szTemp);
	SHFree(pidl);
	if (!bSuccess)
		return 0;

	size = (strlenW(szTemp)+1) * sizeof(WCHAR);

	/* fill the structure */
	hGlobal = GlobalAlloc(GHND|GMEM_SHARE, size);
	if(!hGlobal) return hGlobal;
	szFileName = GlobalLock(hGlobal);
	memcpy(szFileName, szTemp, size);
	GlobalUnlock(hGlobal);

	return hGlobal;
}

