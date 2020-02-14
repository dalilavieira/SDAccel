#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_13__ ;

/* Type definitions */
typedef  int WPARAM ;
typedef  int WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_18__ {size_t NumDigits; size_t LeadingZero; size_t NegativeOrder; scalar_t__ lpThousandSep; scalar_t__ lpDecimalSep; int /*<<< orphan*/  Grouping; } ;
struct TYPE_17__ {size_t nNumDigits; size_t nNumGrouping; size_t nNumNegFormat; size_t nNumLeadingZero; size_t nNumMeasure; scalar_t__ szNumListSep; scalar_t__ szNumNegativeSign; scalar_t__ szNumThousandSep; scalar_t__ szNumDecimalSep; int /*<<< orphan*/  UserLCID; } ;
struct TYPE_16__ {int /*<<< orphan*/  nInteger; } ;
typedef  int /*<<< orphan*/ * PWSTR ;
typedef  TYPE_1__* PGLOBALDATA ;
typedef  TYPE_2__ NUMBERFMT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  size_t INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CB_ADDSTRING ; 
 size_t CB_ERR ; 
 int /*<<< orphan*/  CB_LIMITTEXT ; 
 int /*<<< orphan*/  CB_RESETCONTENT ; 
 int /*<<< orphan*/  CB_SELECTSTRING ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  DECIMAL_RADIX ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetNumberFormatW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*,int*,int) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetSelectedComboBoxIndex (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t*) ; 
 int /*<<< orphan*/  GetSelectedComboBoxText (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 TYPE_13__* GroupingFormats ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IDC_NUMBERDSYMBOL ; 
 int /*<<< orphan*/  IDC_NUMBERSDGROUPING ; 
 int /*<<< orphan*/  IDC_NUMBERSDIGITGRSYM ; 
 int /*<<< orphan*/  IDC_NUMBERSDISPLEADZER ; 
 int /*<<< orphan*/  IDC_NUMBERSLSEP ; 
 int /*<<< orphan*/  IDC_NUMBERSMEASSYS ; 
 int /*<<< orphan*/  IDC_NUMBERSNDIGDEC ; 
 int /*<<< orphan*/  IDC_NUMBERSNEGSAMPLE ; 
 int /*<<< orphan*/  IDC_NUMBERSNNUMFORMAT ; 
 int /*<<< orphan*/  IDC_NUMBERSNSIGNSYM ; 
 int /*<<< orphan*/  IDC_NUMBERSPOSSAMPLE ; 
 size_t IDS_METRIC ; 
 int /*<<< orphan*/ * InsSpacesFmt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,size_t,int*,int) ; 
 size_t MAX_FIELD_DIG_SAMPLES ; 
 size_t MAX_FIELD_SEP_SAMPLES ; 
 int MAX_FMT_SIZE ; 
 size_t MAX_FRAC_NUM_SAMPLES ; 
 size_t MAX_LEAD_ZEROES_SAMPLES ; 
 size_t MAX_LIST_SEP_SAMPLES ; 
 size_t MAX_NEG_NUMBERS_SAMPLES ; 
 size_t MAX_NEG_SIGN_SAMPLES ; 
 int MAX_NUMDECIMALSEP ; 
 int MAX_NUMLISTSEP ; 
 int MAX_NUMNEGATIVESIGN ; 
 int MAX_NUMTHOUSANDSEP ; 
 size_t MAX_NUM_SEP_SAMPLES ; 
 int MAX_SAMPLES_STR_SIZE ; 
 size_t MAX_UNITS_SYS_SAMPLES ; 
 int /*<<< orphan*/ * ReplaceSubStr (int /*<<< orphan*/ *,scalar_t__,char*) ; 
 int /*<<< orphan*/  SAMPLE_NEG_NUMBER ; 
 int /*<<< orphan*/  SAMPLE_NUMBER ; 
 int /*<<< orphan*/  SendDlgItemMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t SendDlgItemMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WM_SETTEXT ; 
 int /*<<< orphan*/  _itow (size_t,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hApplet ; 
 int /*<<< orphan*/ * lpFieldDigNumSamples ; 
 scalar_t__* lpFieldSepSamples ; 
 int /*<<< orphan*/ ** lpLeadNumFmtSamples ; 
 scalar_t__* lpListSepSamples ; 
 int /*<<< orphan*/ ** lpNegNumFmtSamples ; 
 scalar_t__* lpNegSignSamples ; 
 scalar_t__* lpNumSepSamples ; 
 int /*<<< orphan*/  wcscpy (scalar_t__,int*) ; 

__attribute__((used)) static VOID
InitNumDecimalSepCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    INT nCBIndex;
    INT nRetCode;

    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                        CB_LIMITTEXT,
                        MAX_NUMDECIMALSEP - 1,
                        0);

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of decimal separators */
    for (nCBIndex = 0; nCBIndex < MAX_NUM_SEP_SAMPLES; nCBIndex++)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)lpNumSepSamples[nCBIndex]);
    }

    /* Set current item to value from registry */
    nRetCode = SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                                   CB_SELECTSTRING,
                                   -1,
                                   (LPARAM)pGlobalData->szNumDecimalSep);

    /* If it is not successful, add new values to list and select them */
    if (nRetCode == CB_ERR)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                            CB_ADDSTRING,
                            MAX_NUM_SEP_SAMPLES,
                            (LPARAM)pGlobalData->szNumDecimalSep);
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERDSYMBOL,
                            CB_SELECTSTRING,
                            -1,
                            (LPARAM)pGlobalData->szNumDecimalSep);
    }
}

__attribute__((used)) static VOID
InitNumOfFracSymbCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szFracCount[MAX_SAMPLES_STR_SIZE];
    INT nCBIndex;

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNDIGDEC,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of fractional symbols */
    for (nCBIndex = 0; nCBIndex < MAX_FRAC_NUM_SAMPLES; nCBIndex++)
    {
        /* Convert to wide char */
        _itow(nCBIndex, szFracCount, DECIMAL_RADIX);

        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNDIGDEC,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)szFracCount);
    }

    /* Set current item to value from registry */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNDIGDEC,
                        CB_SETCURSEL,
                        (WPARAM)pGlobalData->nNumDigits,
                        (LPARAM)0);
}

__attribute__((used)) static VOID
InitNumFieldSepCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    INT nCBIndex;
    INT nRetCode;

    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                        CB_LIMITTEXT,
                        MAX_NUMTHOUSANDSEP - 1,
                        0);

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of field separators */
    for (nCBIndex = 0; nCBIndex < MAX_FIELD_SEP_SAMPLES; nCBIndex++)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)lpFieldSepSamples[nCBIndex]);
    }

    /* Set current item to value from registry */
    nRetCode = SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                                   CB_SELECTSTRING,
                                   -1,
                                   (LPARAM)pGlobalData->szNumThousandSep);

    /* If it is not success, add new values to list and select them */
    if (nRetCode == CB_ERR)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)pGlobalData->szNumThousandSep);
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDIGITGRSYM,
                            CB_SELECTSTRING,
                            -1,
                            (LPARAM)pGlobalData->szNumThousandSep);
    }
}

__attribute__((used)) static VOID
InitFieldDigNumCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    PWSTR pszFieldDigNumSmpl;
    INT nCBIndex;

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDGROUPING,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of field digits num */
    for (nCBIndex = 0; nCBIndex < MAX_FIELD_DIG_SAMPLES; nCBIndex++)
    {
        pszFieldDigNumSmpl = InsSpacesFmt(SAMPLE_NUMBER, lpFieldDigNumSamples[nCBIndex]);
        if (pszFieldDigNumSmpl != NULL)
        {
            SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDGROUPING,
                                CB_ADDSTRING,
                                0,
                                (LPARAM)pszFieldDigNumSmpl);
            HeapFree(GetProcessHeap(), 0, pszFieldDigNumSmpl);
        }
    }

    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDGROUPING,
                        CB_SETCURSEL,
                        (WPARAM)pGlobalData->nNumGrouping,
                        (LPARAM)0);
}

__attribute__((used)) static VOID
InitNegSignCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    INT nCBIndex;
    INT nRetCode;

    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                        CB_LIMITTEXT,
                        MAX_NUMNEGATIVESIGN - 1,
                        0);

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of signs */
    for (nCBIndex = 0; nCBIndex < MAX_NEG_SIGN_SAMPLES; nCBIndex++)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)lpNegSignSamples[nCBIndex]);
    }

    /* Set current item to value from registry */
    nRetCode = SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                                   CB_SELECTSTRING,
                                   -1,
                                   (LPARAM)pGlobalData->szNumNegativeSign);

    /* If  it is not successful, add new values to list and select them */
    if (nRetCode == CB_ERR)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)pGlobalData->szNumNegativeSign);
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNSIGNSYM,
                            CB_SELECTSTRING,
                            -1,
                            (LPARAM)pGlobalData->szNumNegativeSign);
    }
}

__attribute__((used)) static VOID
InitNegNumFmtCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    PWSTR pszString1, pszString2;
    INT nCBIndex;

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNNUMFORMAT,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of negative numbers formats */
    for (nCBIndex = 0; nCBIndex < MAX_NEG_NUMBERS_SAMPLES; nCBIndex++)
    {
        /* Replace standard separator to setted */
        pszString1 = ReplaceSubStr(lpNegNumFmtSamples[nCBIndex],
                                   pGlobalData->szNumDecimalSep,
                                   L",");
        if (pszString1 != NULL)
        {
            /* Replace standard negative sign to setted */
            pszString2 = ReplaceSubStr(pszString1,
                                       pGlobalData->szNumNegativeSign,
                                       L"-");
            if (pszString2 != NULL)
            {
                SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNNUMFORMAT,
                                    CB_ADDSTRING,
                                    0,
                                    (LPARAM)pszString2);

                HeapFree(GetProcessHeap(), 0, pszString2);
            }

            HeapFree(GetProcessHeap(), 0, pszString1);
        }
    }

    /* Set current item to value from registry */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNNUMFORMAT,
                        CB_SETCURSEL,
                        (WPARAM)pGlobalData->nNumNegFormat,
                        (LPARAM)0);
}

__attribute__((used)) static VOID
InitLeadingZeroesCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    PWSTR pszResultStr;
    INT nCBIndex;

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDISPLEADZER,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create list of standard leading zeroes formats */
    for (nCBIndex = 0; nCBIndex < MAX_LEAD_ZEROES_SAMPLES; nCBIndex++)
    {
        pszResultStr = ReplaceSubStr(lpLeadNumFmtSamples[nCBIndex],
                                     pGlobalData->szNumDecimalSep,
                                     L",");
        if (pszResultStr != NULL)
        {
            SendDlgItemMessage(hwndDlg, IDC_NUMBERSDISPLEADZER,
                               CB_ADDSTRING,
                               0,
                               (LPARAM)pszResultStr);
            HeapFree(GetProcessHeap(), 0, pszResultStr);
        }
    }

    /* Set current item to value from registry */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSDISPLEADZER,
                        CB_SETCURSEL,
                        (WPARAM)pGlobalData->nNumLeadingZero,
                        (LPARAM)0);
}

__attribute__((used)) static VOID
InitListSepCB(HWND hwndDlg,
              PGLOBALDATA pGlobalData)
{
    INT nCBIndex;
    INT nRetCode;

    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                        CB_LIMITTEXT,
                        MAX_NUMLISTSEP - 1,
                        0);

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create standard list of signs */
    for (nCBIndex = 0; nCBIndex < MAX_LIST_SEP_SAMPLES; nCBIndex++)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)lpListSepSamples[nCBIndex]);
    }

    /* Set current item to value from registry */
    nRetCode = SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                                   CB_SELECTSTRING,
                                   -1,
                                   (LPARAM)pGlobalData->szNumListSep);

    /* If it is not successful, add new values to list and select them */
    if (nRetCode == CB_ERR)
    {
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)pGlobalData->szNumListSep);
        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSLSEP,
                            CB_SELECTSTRING,
                            -1,
                            (LPARAM)pGlobalData->szNumListSep);
    }
}

__attribute__((used)) static VOID
InitUnitsSysCB(HWND hwndDlg,
               PGLOBALDATA pGlobalData)
{
    WCHAR szUnitName[128];
    INT nCBIndex;

    /* Clear all box content */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSMEASSYS,
                        CB_RESETCONTENT,
                        (WPARAM)0,
                        (LPARAM)0);

    /* Create list of standard system of units */
    for (nCBIndex = 0; nCBIndex < MAX_UNITS_SYS_SAMPLES; nCBIndex++)
    {
        LoadStringW(hApplet, IDS_METRIC + nCBIndex, szUnitName, 128);

        SendDlgItemMessageW(hwndDlg, IDC_NUMBERSMEASSYS,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)szUnitName);
    }

    /* Set current item to value from registry */
    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSMEASSYS,
                        CB_SETCURSEL,
                        (WPARAM)pGlobalData->nNumMeasure,
                        (LPARAM)0);
}

__attribute__((used)) static VOID
UpdateNumSamples(HWND hwndDlg,
                 PGLOBALDATA pGlobalData)
{
    WCHAR OutBuffer[MAX_FMT_SIZE];
    NUMBERFMT NumberFormat;

    NumberFormat.NumDigits = pGlobalData->nNumDigits;
    NumberFormat.LeadingZero = pGlobalData->nNumLeadingZero;
    NumberFormat.Grouping = GroupingFormats[pGlobalData->nNumGrouping].nInteger;
    NumberFormat.lpDecimalSep = pGlobalData->szNumDecimalSep;
    NumberFormat.lpThousandSep = pGlobalData->szNumThousandSep;
    NumberFormat.NegativeOrder = pGlobalData->nNumNegFormat;

    /* Get positive number format sample */
    GetNumberFormatW(pGlobalData->UserLCID,
                     0,
                     SAMPLE_NUMBER,
                     &NumberFormat,
                     OutBuffer,
                     MAX_FMT_SIZE);

    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSPOSSAMPLE,
                        WM_SETTEXT,
                        0,
                        (LPARAM)OutBuffer);

    /* Get positive number format sample */
    GetNumberFormatW(pGlobalData->UserLCID,
                     0,
                     SAMPLE_NEG_NUMBER,
                     &NumberFormat,
                     OutBuffer,
                     MAX_FMT_SIZE);

    SendDlgItemMessageW(hwndDlg, IDC_NUMBERSNEGSAMPLE,
                        WM_SETTEXT,
                        0,
                        (LPARAM)OutBuffer);
}

__attribute__((used)) static
BOOL
GetNumberSetting(
    HWND hwndDlg,
    PGLOBALDATA pGlobalData)
{
    WCHAR szNumDecimalSep[MAX_NUMDECIMALSEP];
    WCHAR szNumThousandSep[MAX_NUMTHOUSANDSEP];
    WCHAR szNumNegativeSign[MAX_NUMNEGATIVESIGN];
    WCHAR szNumListSep[MAX_NUMLISTSEP];
    INT nNumDigits;
    INT nNumGrouping;
    INT nNumNegFormat;
    INT nNumLeadingZero;
    INT nNumMeasure;

    /* Decimal symbol */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_NUMBERDSYMBOL,
                            szNumDecimalSep,
                            MAX_NUMDECIMALSEP);

    if (szNumDecimalSep[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Number of digits after decimal */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_NUMBERSNDIGDEC,
                             &nNumDigits);

    /* Digit grouping symbol */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_NUMBERSDIGITGRSYM,
                            szNumThousandSep,
                            MAX_NUMTHOUSANDSEP);

    if (szNumThousandSep[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Digit grouping */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_NUMBERSDGROUPING,
                             &nNumGrouping);

    /* Negative sign symbol */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_NUMBERSNSIGNSYM,
                            szNumNegativeSign,
                            MAX_NUMNEGATIVESIGN);

    if (szNumNegativeSign[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Negative number format */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_NUMBERSNNUMFORMAT,
                             &nNumNegFormat);

    /* Display leading zeros */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_NUMBERSDISPLEADZER,
                             &nNumLeadingZero);

    /* List separator */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_NUMBERSLSEP,
                            szNumListSep,
                            MAX_NUMLISTSEP);

    if (szNumListSep[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Measurement system */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_NUMBERSMEASSYS,
                             &nNumMeasure);

    /* Store settings in global data */
    wcscpy(pGlobalData->szNumDecimalSep, szNumDecimalSep);
    wcscpy(pGlobalData->szNumThousandSep, szNumThousandSep);
    wcscpy(pGlobalData->szNumNegativeSign, szNumNegativeSign);
    wcscpy(pGlobalData->szNumListSep, szNumListSep);
    pGlobalData->nNumGrouping = nNumGrouping;
    pGlobalData->nNumDigits = nNumDigits;
    pGlobalData->nNumNegFormat = nNumNegFormat;
    pGlobalData->nNumLeadingZero = nNumLeadingZero;
    pGlobalData->nNumMeasure = nNumMeasure;

    return TRUE;
}

