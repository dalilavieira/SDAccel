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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  int /*<<< orphan*/ * LPTSTR ;
typedef  scalar_t__ INT ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  HCURSOR ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  COUNTOF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ ,int) ; 
 int FALSE ; 
 int /*<<< orphan*/  GetDlgItem (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * GetNextFile (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetSelectedDirectory (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IDC_WAIT ; 
 int /*<<< orphan*/  IDD_STATUS ; 
 int /*<<< orphan*/  IDOK ; 
 int IDS_ASSOCINCOMPLETE ; 
 int IDS_BADPATHMSG ; 
 int IDS_DDEFAIL ; 
 int IDS_FILENOTFOUNDMSG ; 
 int IDS_NOACCESSFILE ; 
 int IDS_NOASSOCMSG ; 
 int /*<<< orphan*/  IDS_PRINTERRTITLE ; 
 int /*<<< orphan*/  IDS_PRINTINGMSG ; 
 int IDS_PRINTMEMORY ; 
 int IDS_PRINTONLYONE ; 
 int IDS_SHAREERROR ; 
 int /*<<< orphan*/  IDS_WINFILE ; 
 int /*<<< orphan*/  LoadCursor (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LoadString (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MAXPATHLEN ; 
 int MB_ICONEXCLAMATION ; 
 int MB_OK ; 
 int /*<<< orphan*/  MyMessageBox (scalar_t__,int /*<<< orphan*/ ,int,int) ; 
#define  SE_ERR_ASSOCINCOMPLETE 133 
#define  SE_ERR_DDEBUSY 132 
#define  SE_ERR_DDEFAIL 131 
#define  SE_ERR_DDETIMEOUT 130 
#define  SE_ERR_NOASSOC 129 
#define  SE_ERR_SHARE 128 
 int /*<<< orphan*/  SW_SHOWNORMAL ; 
 int /*<<< orphan*/  SetCursor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetDlgItemText (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetErrorMode (int) ; 
 scalar_t__ ShellExecute (scalar_t__,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ ShowCursor (int) ; 
 int TRUE ; 
 int /*<<< orphan*/  hAppInstance ; 
 scalar_t__ hdlgProgress ; 
 scalar_t__ hwndFrame ; 
 int /*<<< orphan*/  szMessage ; 
 int /*<<< orphan*/  szNULL ; 
 int /*<<< orphan*/ * szTitle ; 
 int /*<<< orphan*/  wsprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

DWORD
PrintFile(HWND hwnd, LPTSTR szFile)
{
   DWORD          ret;
   INT           iCurCount;
   INT           i;
   HCURSOR       hCursor;
   WCHAR      szDir[MAXPATHLEN];

   ret = 0;

   hCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
   iCurCount = ShowCursor(TRUE) - 1;

   //
   // This returns Ansi chars, and that's what ShellExecute expects
   //
   GetSelectedDirectory(0, szDir);

   //
   // open the object
   //
   SetErrorMode(0);
   ret = (DWORD)ShellExecute(hwnd, L"print", szFile, szNULL, szDir, SW_SHOWNORMAL);
   SetErrorMode(1);

   switch (ret) {
   case 0:
   case 8:
      ret = IDS_PRINTMEMORY;
      break;

   case 2:
      ret = IDS_FILENOTFOUNDMSG;
      break;

   case 3:
      ret = IDS_BADPATHMSG;
      break;

   case 5:
      ret = IDS_NOACCESSFILE;
      break;

   case SE_ERR_SHARE:
      ret = IDS_SHAREERROR;
      break;

   case SE_ERR_ASSOCINCOMPLETE:
      ret = IDS_ASSOCINCOMPLETE;
      break;

   case SE_ERR_DDETIMEOUT:
   case SE_ERR_DDEFAIL:
   case SE_ERR_DDEBUSY:
      ret = IDS_DDEFAIL;
      break;

   case SE_ERR_NOASSOC:
      ret = IDS_NOASSOCMSG;
      break;

   default:
      if (ret <= 32)
         goto EPExit;
      ret = 0;
   }

EPExit:
   i = ShowCursor(FALSE);

   //
   // Make sure that the cursor count is still balanced.
   //
   if (i != iCurCount)
      ShowCursor(TRUE);

   SetCursor(hCursor);

   return(ret);
}

DWORD
WFPrint(LPTSTR pSel)
{
  TCHAR szFile[MAXPATHLEN];
  TCHAR szTemp[MAXPATHLEN];
  DWORD ret;

  /* Turn off the print button. */
  if (hdlgProgress)
      EnableWindow(GetDlgItem(hdlgProgress, IDOK), FALSE);

  if (!(pSel = GetNextFile(pSel, szFile, COUNTOF(szFile))))
      return TRUE;

  /* See if there is more than one file to print.  Abort if so
   */
  if (pSel = GetNextFile(pSel, szTemp, COUNTOF(szTemp))) {
      MyMessageBox(hwndFrame, IDS_WINFILE, IDS_PRINTONLYONE, MB_OK | MB_ICONEXCLAMATION);
      return(FALSE);
  }

  if (hdlgProgress) {
      /* Display the name of the file being printed. */
      LoadString(hAppInstance, IDS_PRINTINGMSG, szTitle, COUNTOF(szTitle));
      wsprintf(szMessage, szTitle, szFile);
      SetDlgItemText(hdlgProgress, IDD_STATUS, szMessage);
  }

  ret = PrintFile(hdlgProgress ? hdlgProgress : hwndFrame, szFile);

  if (ret) {
     MyMessageBox(hwndFrame, IDS_PRINTERRTITLE, ret, MB_OK | MB_ICONEXCLAMATION);
     return FALSE;
  }

  return TRUE;
}

