#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_71__   TYPE_9__ ;
typedef  struct TYPE_70__   TYPE_8__ ;
typedef  struct TYPE_69__   TYPE_7__ ;
typedef  struct TYPE_68__   TYPE_6__ ;
typedef  struct TYPE_67__   TYPE_5__ ;
typedef  struct TYPE_66__   TYPE_4__ ;
typedef  struct TYPE_65__   TYPE_3__ ;
typedef  struct TYPE_64__   TYPE_2__ ;
typedef  struct TYPE_63__   TYPE_1__ ;
typedef  struct TYPE_62__   TYPE_18__ ;
typedef  struct TYPE_61__   TYPE_17__ ;
typedef  struct TYPE_60__   TYPE_16__ ;
typedef  struct TYPE_59__   TYPE_15__ ;
typedef  struct TYPE_58__   TYPE_14__ ;
typedef  struct TYPE_57__   TYPE_13__ ;
typedef  struct TYPE_56__   TYPE_12__ ;
typedef  struct TYPE_55__   TYPE_11__ ;
typedef  struct TYPE_54__   TYPE_10__ ;

/* Type definitions */
struct IUnknown {int dummy; } ;
typedef  int /*<<< orphan*/  sm_content ;
typedef  int /*<<< orphan*/  byte ;
struct TYPE_68__ {int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_69__ {int m_iItemSelected; int m_lRefCount; void* m_fAllowDrop; int /*<<< orphan*/ * m_hWnd; TYPE_6__ idt; } ;
typedef  TYPE_7__ WF_IDropTarget ;
struct TYPE_66__ {TYPE_3__* lpVtbl; } ;
struct TYPE_70__ {TYPE_4__ ido; } ;
typedef  TYPE_8__ WF_IDataObject ;
typedef  char WCHAR ;
typedef  int UINT ;
struct TYPE_71__ {int /*<<< orphan*/ * hGlobal; TYPE_13__* pstm; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_67__ {int /*<<< orphan*/  (* Release ) (TYPE_14__*) ;} ;
struct TYPE_65__ {scalar_t__ (* QueryGetData ) (int /*<<< orphan*/ ,TYPE_16__*) ;} ;
struct TYPE_64__ {scalar_t__ (* GetData ) (TYPE_15__*,TYPE_16__*,TYPE_9__*) ;scalar_t__ (* QueryGetData ) (TYPE_15__*,TYPE_16__*) ;} ;
struct TYPE_63__ {scalar_t__ (* Read ) (TYPE_13__*,int /*<<< orphan*/ *,int,int*) ;} ;
struct TYPE_62__ {char* cFileName; } ;
struct TYPE_61__ {unsigned int cItems; TYPE_18__* fgd; } ;
struct TYPE_60__ {unsigned short member_0; int member_3; unsigned int lindex; unsigned short cfFormat; int /*<<< orphan*/  member_4; int /*<<< orphan*/  member_2; int /*<<< orphan*/ * member_1; } ;
struct TYPE_59__ {TYPE_2__* lpVtbl; } ;
struct TYPE_58__ {TYPE_5__* lpVtbl; } ;
struct TYPE_57__ {TYPE_1__* lpVtbl; } ;
struct TYPE_55__ {int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_56__ {int pFiles; int fNC; void* fWide; TYPE_11__ pt; } ;
struct TYPE_54__ {int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
typedef  char TCHAR ;
typedef  TYPE_9__ STGMEDIUM ;
typedef  TYPE_10__ POINTL ;
typedef  TYPE_11__ POINT ;
typedef  int /*<<< orphan*/  PDNODE ;
typedef  int /*<<< orphan*/  LPXDTA ;
typedef  char* LPWSTR ;
typedef  char* LPTSTR ;
typedef  int /*<<< orphan*/  LPDROPTARGET ;
typedef  TYPE_12__* LPDROPFILES ;
typedef  int /*<<< orphan*/  LPDATAOBJECT ;
typedef  scalar_t__ LPBYTE ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  TYPE_13__ IStream ;
typedef  int /*<<< orphan*/  IDropTargetVtbl ;
typedef  TYPE_14__ IDropTarget ;
typedef  TYPE_15__ IDataObject ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/  HLOCAL ;
typedef  int /*<<< orphan*/ * HDROP ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  TYPE_16__ FORMATETC ;
typedef  TYPE_17__ FILEGROUPDESCRIPTOR ;
typedef  TYPE_18__ FILEDESCRIPTOR ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  DROPFILES ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AddBackslash (char*) ; 
 int BLOCK_SIZE ; 
 int /*<<< orphan*/  CFSTR_FILECONTENTS ; 
 int /*<<< orphan*/  CFSTR_FILEDESCRIPTOR ; 
 unsigned short CF_HDROP ; 
 void* CHAR_DQUOTE ; 
 char CHAR_NULL ; 
 int /*<<< orphan*/  CHAR_SPACE ; 
 int COUNTOF (char*) ; 
 int /*<<< orphan*/  CREATE_ALWAYS ; 
 int /*<<< orphan*/  CheckEsc (char*) ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CoLockObjectExternal (struct IUnknown*,void*,void*) ; 
 scalar_t__ CreateDropTarget (int /*<<< orphan*/ *,TYPE_7__**) ; 
 int /*<<< orphan*/ * CreateFile (char*,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DMMoveCopyHelper (char*,char*,int) ; 
 int DROPEFFECT_COPY ; 
 int DROPEFFECT_MOVE ; 
 scalar_t__ DSRectItem (int /*<<< orphan*/ *,int,void*,void*) ; 
 int /*<<< orphan*/  DVASPECT_CONTENT ; 
 int /*<<< orphan*/  DeleteFile (char*) ; 
 int DragQueryFile (int /*<<< orphan*/ *,int,char*,int) ; 
 scalar_t__ E_INVALIDARG ; 
 scalar_t__ E_OUTOFMEMORY ; 
 scalar_t__ FAILED (scalar_t__) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FILE_ATTRIBUTE_TEMPORARY ; 
 int FILE_READ_DATA ; 
 int FILE_SHARE_READ ; 
 int FILE_SHARE_WRITE ; 
 int FILE_WRITE_DATA ; 
 int /*<<< orphan*/  FS_GETDIRECTORY ; 
 int GMEM_DDESHARE ; 
 int GMEM_MOVEABLE ; 
 int GMEM_ZEROINIT ; 
 int /*<<< orphan*/ * GetDlgItem (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetLastError () ; 
 char* GetNextFile (char*,char*,int) ; 
 int /*<<< orphan*/  GetTempPath (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  GetTreePath (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * GlobalAlloc (int,int) ; 
 scalar_t__ GlobalLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GlobalUnlock (int /*<<< orphan*/ *) ; 
 scalar_t__ HRESULT_FROM_WIN32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDCW_LISTBOX ; 
 int /*<<< orphan*/  IDCW_TREELISTBOX ; 
 int /*<<< orphan*/ * INVALID_HANDLE_VALUE ; 
 scalar_t__ LB_ERR ; 
 int /*<<< orphan*/  LB_GETTEXT ; 
 int /*<<< orphan*/  LB_ITEMFROMPOINT ; 
 int /*<<< orphan*/  LMEM_FIXED ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKELPARAM (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MAXPATHLEN ; 
 int /*<<< orphan*/  MAX_PATH ; 
 int MK_CONTROL ; 
 int MK_SHIFT ; 
 char* MemGetFileName (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MessageBeep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QualifyPath (char*) ; 
 scalar_t__ RectTreeItem (int /*<<< orphan*/ *,int,void*) ; 
 unsigned short RegisterClipboardFormat (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegisterDragDrop (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseStgMedium (TYPE_9__*) ; 
 int /*<<< orphan*/  RevokeDragDrop (int /*<<< orphan*/ *) ; 
 scalar_t__ SUCCEEDED (scalar_t__) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  ScreenToClient (int /*<<< orphan*/ *,TYPE_11__*) ; 
 scalar_t__ SendMessage (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetFocus (int /*<<< orphan*/ *) ; 
 char* TEXT (char*) ; 
 void* TRUE ; 
 int /*<<< orphan*/  TYMED_HGLOBAL ; 
 int /*<<< orphan*/  TYMED_ISTREAM ; 
 int /*<<< orphan*/  WriteFile (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int*,int /*<<< orphan*/ *) ; 
 TYPE_7__* calloc (int,int) ; 
 int /*<<< orphan*/  idt_vtbl ; 
 int /*<<< orphan*/  lstrcat (char*,char*) ; 
 int /*<<< orphan*/  lstrcpy (char*,char*) ; 
 int /*<<< orphan*/  memset (TYPE_9__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub1 (TYPE_15__*,TYPE_16__*,TYPE_9__*) ; 
 scalar_t__ stub2 (TYPE_13__*,int /*<<< orphan*/ *,int,int*) ; 
 scalar_t__ stub3 (TYPE_15__*,TYPE_16__*) ; 
 scalar_t__ stub4 (TYPE_15__*,TYPE_16__*) ; 
 scalar_t__ stub5 (TYPE_15__*,TYPE_16__*,TYPE_9__*) ; 
 scalar_t__ stub6 (TYPE_15__*,TYPE_16__*,TYPE_9__*) ; 
 scalar_t__ stub7 (int /*<<< orphan*/ ,TYPE_16__*) ; 
 scalar_t__ stub8 (int /*<<< orphan*/ ,TYPE_16__*) ; 
 int /*<<< orphan*/  stub9 (TYPE_14__*) ; 
 char* szStarDotStar ; 
 int wcslen (char*) ; 

void PaintRectItem(WF_IDropTarget *This, POINTL *ppt)
{
	HWND hwndLB;
	DWORD iItem;
	POINT pt;
	BOOL fTree;
	
	// could be either tree control or directory list box
	hwndLB = GetDlgItem(This->m_hWnd, IDCW_LISTBOX);
	fTree = FALSE;
	if (hwndLB == NULL)
	{
		hwndLB = GetDlgItem(This->m_hWnd, IDCW_TREELISTBOX);
		fTree = TRUE;

		if (hwndLB == NULL)
			return;
	}

	if (ppt != NULL)
	{
		pt.x = ppt->x;
		pt.y = ppt->y;
		ScreenToClient(hwndLB, &pt);
	
		iItem = SendMessage(hwndLB, LB_ITEMFROMPOINT, 0, MAKELPARAM(pt.x, pt.y));
		iItem &= 0xffff;
		if (This->m_iItemSelected != -1 && This->m_iItemSelected == iItem)
			return;
	}

	// unpaint old item
	if (This->m_iItemSelected != -1)
	{
	    if (fTree)
			RectTreeItem(hwndLB, This->m_iItemSelected, FALSE);
		else
			DSRectItem(hwndLB, This->m_iItemSelected, FALSE, FALSE);

		This->m_iItemSelected = (DWORD)-1;
	}

	// if new item, paint it.
	if (ppt != NULL)
	{
	    if (fTree)
		{
			if (RectTreeItem(hwndLB, iItem, TRUE))
				This->m_iItemSelected = iItem;
		}
		else
		{
			if (DSRectItem(hwndLB, iItem, TRUE, FALSE))
				This->m_iItemSelected = iItem;
		}
	}
}

LPWSTR QuotedDropList(IDataObject *pDataObject)
{
	HDROP hdrop;
	DWORD cFiles, iFile, cchFiles;
	LPWSTR szFiles = NULL, pch;
	FORMATETC fmtetc = { CF_HDROP, 0, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stgmed;

	if (pDataObject->lpVtbl->GetData(pDataObject, &fmtetc, &stgmed) == S_OK)
	{
		// Yippie! the data is there, so go get it!
		hdrop = stgmed.hGlobal;

		cFiles = DragQueryFile(hdrop, 0xffffffff, NULL, 0);
		cchFiles = 0;
		for (iFile = 0; iFile < cFiles; iFile++)
			cchFiles += DragQueryFile(hdrop, iFile, NULL, 0) + 1 + 2;

		pch = szFiles = (LPWSTR)LocalAlloc(LMEM_FIXED, cchFiles * sizeof(WCHAR));
		for (iFile = 0; iFile < cFiles; iFile++)
		{
			DWORD cchFile;

			*pch++ = CHAR_DQUOTE;
			
			cchFile = DragQueryFile(hdrop, iFile, pch, cchFiles);
			pch += cchFile;
			*pch++ = CHAR_DQUOTE;

			if (iFile+1 < cFiles)
				*pch++ = CHAR_SPACE;
			else
				*pch = CHAR_NULL;
				
			cchFiles -= cchFile + 1 + 2;
		}

		// release the data using the COM API
		ReleaseStgMedium(&stgmed);
	}

	return szFiles;
}

HDROP CreateDropFiles(POINT pt, BOOL fNC, LPTSTR pszFiles)
{
    HANDLE hDrop;
    LPBYTE lpList;
    UINT cbList;
	LPTSTR szSrc;

    LPDROPFILES lpdfs;
    TCHAR szFile[MAXPATHLEN];

	cbList = sizeof(DROPFILES) + sizeof(TCHAR);

	szSrc = pszFiles;
    while (szSrc = GetNextFile(szSrc, szFile, COUNTOF(szFile))) 
	{
        QualifyPath(szFile);

		cbList += (wcslen(szFile) + 1)*sizeof(TCHAR);
	}

    hDrop = GlobalAlloc(GMEM_DDESHARE|GMEM_MOVEABLE|GMEM_ZEROINIT, cbList);
    if (!hDrop)
        return NULL;

    lpdfs = (LPDROPFILES)GlobalLock(hDrop);

    lpdfs->pFiles = sizeof(DROPFILES);
	lpdfs->pt = pt;
	lpdfs->fNC = fNC;
    lpdfs->fWide = TRUE;

	lpList = (LPBYTE)lpdfs + sizeof(DROPFILES);
	szSrc = pszFiles;

    while (szSrc = GetNextFile(szSrc, szFile, COUNTOF(szFile))) {

       QualifyPath(szFile);

       lstrcpy((LPTSTR)lpList, szFile);

       lpList += (wcslen(szFile) + 1)*sizeof(TCHAR);
    }

	GlobalUnlock(hDrop);

	return hDrop;
}

__attribute__((used)) static HRESULT StreamToFile(IStream *stream, TCHAR *szFile)
{
    byte buffer[BLOCK_SIZE];
    DWORD bytes_read;
    DWORD bytes_written;
    HRESULT hr;
	HANDLE hFile;

    hFile = CreateFile( szFile,
          FILE_READ_DATA | FILE_WRITE_DATA,
          FILE_SHARE_READ | FILE_SHARE_WRITE,
          NULL,
          CREATE_ALWAYS,
          FILE_ATTRIBUTE_TEMPORARY,
          NULL );

    if (hFile != INVALID_HANDLE_VALUE) {
        do {
            hr = stream->lpVtbl->Read(stream, buffer, BLOCK_SIZE, &bytes_read);
			bytes_written = 0;
            if (SUCCEEDED(hr) && bytes_read)
			{
				if (!WriteFile(hFile, buffer, bytes_read, &bytes_written, NULL))
				{
					hr = HRESULT_FROM_WIN32(GetLastError());
					bytes_written = 0;
				}
			}
        } while (S_OK == hr && bytes_written != 0);
        CloseHandle(hFile);
		if (FAILED(hr))
			DeleteFile(szFile);
		else
			hr = S_OK;
    }
    else
	    hr = HRESULT_FROM_WIN32(GetLastError());

    return hr;
}

LPWSTR QuotedContentList(IDataObject *pDataObject)
{
    FILEGROUPDESCRIPTOR *file_group_descriptor;
    FILEDESCRIPTOR file_descriptor;
	HRESULT hr;
	LPWSTR szFiles = NULL;

    unsigned short cp_format_descriptor = RegisterClipboardFormat(CFSTR_FILEDESCRIPTOR);
    unsigned short cp_format_contents = RegisterClipboardFormat(CFSTR_FILECONTENTS);

    //Set up format structure for the descriptor and contents
    FORMATETC descriptor_format = {cp_format_descriptor, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
    FORMATETC contents_format = {cp_format_contents, NULL, DVASPECT_CONTENT, -1, TYMED_ISTREAM};

    // Check for descriptor format type
    hr = pDataObject->lpVtbl->QueryGetData(pDataObject, &descriptor_format);
    if (hr == S_OK) 
	{ 
		// Check for contents format type
        hr = pDataObject->lpVtbl->QueryGetData(pDataObject, &contents_format);
        if (hr == S_OK)
		{ 
            // Get the descriptor information
            STGMEDIUM sm_desc= {0,0,0};
            STGMEDIUM sm_content = {0,0,0};
			unsigned int file_index, cchTempPath, cchFiles;
            WCHAR szTempPath[MAX_PATH+1];

            hr = pDataObject->lpVtbl->GetData(pDataObject, &descriptor_format, &sm_desc);
			if (hr != S_OK)
				return NULL;

            file_group_descriptor = (FILEGROUPDESCRIPTOR *) GlobalLock(sm_desc.hGlobal);

			GetTempPath(MAX_PATH, szTempPath);
			cchTempPath = wcslen(szTempPath);

			// calc total size of file names
			cchFiles = 0;
            for (file_index = 0; file_index < file_group_descriptor->cItems; file_index++) 
			{
                file_descriptor = file_group_descriptor->fgd[file_index];
				cchFiles += 1 + cchTempPath + 1 + wcslen(file_descriptor.cFileName) + 2;
			}

			szFiles = (LPWSTR)LocalAlloc(LMEM_FIXED, cchFiles * sizeof(WCHAR));
			szFiles[0] = '\0';

            // For each file, get the name and copy the stream to a file
            for (file_index = 0; file_index < file_group_descriptor->cItems; file_index++)
			{
                file_descriptor = file_group_descriptor->fgd[file_index];
                contents_format.lindex = file_index;
				memset(&sm_content, 0, sizeof(sm_content));
                hr = pDataObject->lpVtbl->GetData(pDataObject, &contents_format, &sm_content);

                if (hr == S_OK) 
				{
					// Dump stream to a file
					TCHAR szTempFile[MAXPATHLEN*2+1];

					lstrcpy(szTempFile, szTempPath);
		            AddBackslash(szTempFile);
				    lstrcat(szTempFile, file_descriptor.cFileName);

					// TODO: make sure all directories between the temp directory and the file have been created
					// paste from zip archives result in file_descriptor.cFileName with intermediate directories

					hr = StreamToFile(sm_content.pstm, szTempFile);

					if (hr == S_OK)
					{
						CheckEsc(szTempFile);

						if (szFiles[0] != '\0')
							lstrcat(szFiles, TEXT(" "));
						lstrcat(szFiles, szTempFile);
					}

					ReleaseStgMedium(&sm_content);
                }
            }

            GlobalUnlock(sm_desc.hGlobal);
            ReleaseStgMedium(&sm_desc);

			if (szFiles[0] == '\0')
			{
				// nothing to copy
				MessageBeep(0);
				LocalFree((HLOCAL)szFiles);	
				szFiles = NULL;
			}
        }
	}
    return szFiles;
}

__attribute__((used)) static BOOL QueryDataObject(WF_IDataObject *pDataObject)
{
	FORMATETC fmtetc = { CF_HDROP, 0, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    unsigned short cp_format_descriptor = RegisterClipboardFormat(CFSTR_FILEDESCRIPTOR);
    FORMATETC descriptor_format = {0, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
	descriptor_format.cfFormat = cp_format_descriptor;

	// does the data object support CF_HDROP using a HGLOBAL?
	return pDataObject->ido.lpVtbl->QueryGetData((LPDATAOBJECT)pDataObject, &fmtetc) == S_OK || 
			pDataObject->ido.lpVtbl->QueryGetData((LPDATAOBJECT)pDataObject, &descriptor_format) == S_OK;
}

__attribute__((used)) static DWORD DropEffect(DWORD grfKeyState, POINTL pt, DWORD dwAllowed)
{
	DWORD dwEffect = 0;

	// 1. check "pt" -> do we allow a drop at the specified coordinates?
	
	// 2. work out that the drop-effect should be based on grfKeyState
	if(grfKeyState & MK_CONTROL)
	{
		dwEffect = dwAllowed & DROPEFFECT_COPY;
	}
	else if(grfKeyState & MK_SHIFT)
	{
		dwEffect = dwAllowed & DROPEFFECT_MOVE;
	}
	
	// 3. no key-modifiers were specified (or drop effect not allowed), so
	//    base the effect on those allowed by the dropsource
	if(dwEffect == 0)
	{
		if(dwAllowed & DROPEFFECT_COPY) dwEffect = DROPEFFECT_COPY;
		if(dwAllowed & DROPEFFECT_MOVE) dwEffect = DROPEFFECT_MOVE;
	}
	
	return dwEffect;
}

void DropData(WF_IDropTarget *This, IDataObject *pDataObject, DWORD dwEffect)
{
	// construct a FORMATETC object
	HWND hwndLB;
	BOOL fTree;
	LPWSTR szFiles = NULL;
	WCHAR     szDest[MAXPATHLEN];

	hwndLB = GetDlgItem(This->m_hWnd, IDCW_LISTBOX);
	fTree = FALSE;
	if (hwndLB == NULL)
	{
		hwndLB = GetDlgItem(This->m_hWnd, IDCW_TREELISTBOX);
		fTree = TRUE;

		if (hwndLB == NULL)
			return;
	}

	// if item selected, add path
	if (fTree)
	{
	    PDNODE pNode;
		
		// odd
		if (This->m_iItemSelected == -1)
			return;

		if (SendMessage(hwndLB, LB_GETTEXT, This->m_iItemSelected, (LPARAM)&pNode) == LB_ERR)
			return;

		GetTreePath(pNode, szDest);
	}
	else
	{
		LPXDTA    lpxdta;

		SendMessage(This->m_hWnd, FS_GETDIRECTORY, COUNTOF(szDest), (LPARAM)szDest);

		if (This->m_iItemSelected != -1)
		{
			SendMessage(hwndLB, LB_GETTEXT, This->m_iItemSelected,
				(LPARAM)(LPTSTR)&lpxdta);
		
			AddBackslash(szDest);
			lstrcat(szDest, MemGetFileName(lpxdta));
		}
	}

    AddBackslash(szDest);
    lstrcat(szDest, szStarDotStar);   // put files in this dir

    CheckEsc(szDest);

	// See if the dataobject contains any TEXT stored as a HGLOBAL
	if ((szFiles = QuotedDropList(pDataObject)) == NULL)
	{
		szFiles = QuotedContentList(pDataObject);
		dwEffect = DROPEFFECT_MOVE; 
	}

	if (szFiles != NULL)
	{
		SetFocus(This->m_hWnd);

		DMMoveCopyHelper(szFiles, szDest, dwEffect == DROPEFFECT_COPY);

		LocalFree((HLOCAL)szFiles);
	}
}

void RegisterDropWindow(HWND hwnd, WF_IDropTarget **ppDropTarget)
{
	WF_IDropTarget *pDropTarget;
	
	CreateDropTarget(hwnd, &pDropTarget);

	// acquire a strong lock
	CoLockObjectExternal((struct IUnknown*)pDropTarget, TRUE, FALSE);

	// tell OLE that the window is a drop target
	RegisterDragDrop(hwnd, (LPDROPTARGET)pDropTarget);

	*ppDropTarget = pDropTarget;
}

void UnregisterDropWindow(HWND hwnd, IDropTarget *pDropTarget)
{
	// remove drag+drop
	RevokeDragDrop(hwnd);

	// remove the strong lock
	CoLockObjectExternal((struct IUnknown*)pDropTarget, FALSE, TRUE);

	// release our own reference
	pDropTarget->lpVtbl->Release(pDropTarget);
}

WF_IDropTarget * WF_IDropTarget_new(HWND hwnd)
{
  WF_IDropTarget *result;

  result = calloc(1, sizeof(WF_IDropTarget));

  if (result)
  {
	  result->idt.lpVtbl = (IDropTargetVtbl*)&idt_vtbl;

	  result->m_lRefCount = 1;
	  result->m_hWnd = hwnd;
	  result->m_fAllowDrop = FALSE;

	  // return result;
  }

  return result;
}

HRESULT CreateDropTarget(HWND hwnd, WF_IDropTarget **ppDropTarget) 
{
	if(ppDropTarget == 0)
		return E_INVALIDARG;

	*ppDropTarget = WF_IDropTarget_new(hwnd);

	return (*ppDropTarget) ? S_OK : E_OUTOFMEMORY;

}

