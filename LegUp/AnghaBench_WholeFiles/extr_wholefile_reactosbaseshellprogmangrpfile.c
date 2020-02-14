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
typedef  int /*<<< orphan*/  PROGGROUP ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR_SUCCESS ; 
 int /*<<< orphan*/  TRUE ; 

DWORD GRPFILE_ReadGroupFile(LPCWSTR lpszPath, BOOL bIsCommonGroup)
{
#if 0
  CHAR   szPath_gr[MAX_PATHNAME_LEN];
  BOOL   bFileNameModified = FALSE;
  OFSTRUCT dummy;
  HLOCAL hBuffer, hGroup;
  INT    size;

  /* if `.gr' file exists use that */
  GRPFILE_ModifyFileName(szPath_gr, lpszPath, MAX_PATHNAME_LEN, TRUE);
  if (OpenFile(szPath_gr, &dummy, OF_EXIST) != HFILE_ERROR)
    {
      lpszPath = szPath_gr;
      bFileNameModified = TRUE;
    }

  /* Read the whole file into a buffer */
  if (!GRPFILE_ReadFileToBuffer(lpszPath, &hBuffer, &size))
    {
      MAIN_MessageBoxIDS_s(IDS_GRPFILE_READ_ERROR_s, lpszPath, IDS_ERROR, MB_YESNO);
      return(0);
    }

  /* Interpret buffer */
  hGroup = GRPFILE_ScanGroup(LocalLock(hBuffer), size,
			     lpszPath, bFileNameModified);
  if (!hGroup)
    MAIN_MessageBoxIDS_s(IDS_GRPFILE_READ_ERROR_s, lpszPath, IDS_ERROR, MB_YESNO);

  LocalFree(hBuffer);

  return(hGroup);

#else
    return ERROR_SUCCESS;
#endif
}

BOOL GRPFILE_WriteGroupFile(PROGGROUP* hGroup)
{
#if 0
  CHAR szPath[MAX_PATHNAME_LEN];
  PROGGROUP *group = LocalLock(hGroup);
  OFSTRUCT dummy;
  HFILE file;
  BOOL ret;

  GRPFILE_ModifyFileName(szPath, LocalLock(group->hGrpFile),
			 MAX_PATHNAME_LEN,
			 group->bFileNameModified);

  /* Try not to overwrite original files */

  /* group->bOverwriteFileOk == TRUE only if a file has the modified format */
  if (!group->bOverwriteFileOk &&
      OpenFile(szPath, &dummy, OF_EXIST) != HFILE_ERROR)
    {
      /* Original file exists, try `.gr' extension */
      GRPFILE_ModifyFileName(szPath, LocalLock(group->hGrpFile),
			     MAX_PATHNAME_LEN, TRUE);
      if (OpenFile(szPath, &dummy, OF_EXIST) != HFILE_ERROR)
	{
	  /* File exists. Do not overwrite */
	  MAIN_MessageBoxIDS_s(IDS_FILE_NOT_OVERWRITTEN_s, szPath,
			       IDS_INFO, MB_OK);
	  return FALSE;
	}
      /* Inform about the modified file name */
      if (IDCANCEL ==
	  MAIN_MessageBoxIDS_s(IDS_SAVE_GROUP_AS_s, szPath, IDS_INFO,
			       MB_OKCANCEL | MB_ICONINFORMATION))
	return FALSE;
    }

  {
    /* Warn about the (possible) incompatibility */
    CHAR msg[MAX_PATHNAME_LEN + 200];
    wsprintfA(msg,
	     "Group files written by this DRAFT Program Manager "
	     "possibly cannot be read by the Microsoft Program Manager!!\n"
	     "Are you sure to write %s?", szPath);
    if (IDOK != MessageBoxA(Globals.hMainWnd, msg, "WARNING",
                            MB_OKCANCEL | MB_DEFBUTTON2)) return FALSE;
  }

  /* Open file */
  file = _lcreat(szPath, 0);
  if (file != HFILE_ERROR)
    {
      ret = GRPFILE_DoWriteGroupFile(file, group);
      _lclose(file);
    }
  else ret = FALSE;

  if (!ret)
    MAIN_MessageBoxIDS_s(IDS_FILE_WRITE_ERROR_s, szPath, IDS_ERROR, MB_OK);

  return(ret);

#else
    return TRUE;
#endif
}

