#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_11__ ;

/* Type definitions */
typedef  int WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_16__ {int NumDigits; int Grouping; char* lpDecimalSep; char* lpThousandSep; int NegativeOrder; int PositiveOrder; char* lpCurrencySymbol; scalar_t__ LeadingZero; } ;
struct TYPE_15__ {int nCurrDigits; size_t nCurrGrouping; char* szCurrDecimalSep; char* szCurrThousandSep; int nCurrNegFormat; int nCurrPosFormat; char* szCurrSymbol; int /*<<< orphan*/  UserLCID; scalar_t__ nNumLeadingZero; } ;
struct TYPE_14__ {int nInteger; } ;
typedef  TYPE_1__* PGLOBALDATA ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  TYPE_2__ CURRENCYFMTW ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int /*<<< orphan*/  CB_INSERTSTRING ; 
 int /*<<< orphan*/  CB_LIMITTEXT ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetCurrencyFormatW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_2__*,int*,int) ; 
 int /*<<< orphan*/  GetSelectedComboBoxIndex (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  GetSelectedComboBoxText (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 TYPE_11__* GroupingFormats ; 
 int /*<<< orphan*/  IDC_CURRENCYDECNUM ; 
 int /*<<< orphan*/  IDC_CURRENCYDECSEP ; 
 int /*<<< orphan*/  IDC_CURRENCYGRPNUM ; 
 int /*<<< orphan*/  IDC_CURRENCYGRPSEP ; 
 int /*<<< orphan*/  IDC_CURRENCYNEGSAMPLE ; 
 int /*<<< orphan*/  IDC_CURRENCYNEGVALUE ; 
 int /*<<< orphan*/  IDC_CURRENCYPOSSAMPLE ; 
 int /*<<< orphan*/  IDC_CURRENCYPOSVALUE ; 
 int /*<<< orphan*/  IDC_CURRENCYSYMBOL ; 
 int MAX_CURRDECIMALSEP ; 
 int MAX_CURRSYMBOL ; 
 int MAX_CURRTHOUSANDSEP ; 
 int MAX_FMT_SIZE ; 
 int MAX_GROUPINGFORMATS ; 
 char* NEGATIVE_EXAMPLE ; 
 char* POSITIVE_EXAMPLE ; 
 int /*<<< orphan*/  SendDlgItemMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WM_SETTEXT ; 
 int /*<<< orphan*/  wcscpy (char*,int*) ; 

__attribute__((used)) static VOID
UpdateExamples(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szBuffer[MAX_FMT_SIZE];
    CURRENCYFMTW CurrencyFormat;

    CurrencyFormat.NumDigits = pGlobalData->nCurrDigits;
    CurrencyFormat.LeadingZero = pGlobalData->nNumLeadingZero;
    CurrencyFormat.Grouping = GroupingFormats[pGlobalData->nCurrGrouping].nInteger;
    CurrencyFormat.lpDecimalSep = pGlobalData->szCurrDecimalSep;
    CurrencyFormat.lpThousandSep = pGlobalData->szCurrThousandSep;
    CurrencyFormat.NegativeOrder = pGlobalData->nCurrNegFormat;
    CurrencyFormat.PositiveOrder = pGlobalData->nCurrPosFormat;
    CurrencyFormat.lpCurrencySymbol = pGlobalData->szCurrSymbol;

    /* Positive example */
    GetCurrencyFormatW(pGlobalData->UserLCID, 0,
                       POSITIVE_EXAMPLE,
                       &CurrencyFormat, szBuffer, MAX_FMT_SIZE);

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYPOSSAMPLE, WM_SETTEXT, 0, (LPARAM)szBuffer);

    /* Negative example */
    GetCurrencyFormatW(pGlobalData->UserLCID, 0,
                       NEGATIVE_EXAMPLE,
                       &CurrencyFormat, szBuffer, MAX_FMT_SIZE);

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYNEGSAMPLE, WM_SETTEXT, 0, (LPARAM)szBuffer);
}

__attribute__((used)) static VOID
InitCurrencySymbols(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYSYMBOL,
                        CB_LIMITTEXT,
                        MAX_CURRSYMBOL - 1,
                        0);

    /* Set currency symbols */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYSYMBOL,
                        CB_ADDSTRING,
                        0,
                        (LPARAM)pGlobalData->szCurrSymbol);

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYSYMBOL,
                        CB_SETCURSEL,
                        0, /* Index */
                        0);
}

__attribute__((used)) static VOID
InitCurrencyPositiveFormats(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szBuffer[MAX_FMT_SIZE];
    CURRENCYFMTW cyFmt;
    INT i;

    /* positive currency values */
    cyFmt.NumDigits = pGlobalData->nCurrDigits;
    cyFmt.LeadingZero = 0;
    cyFmt.Grouping = 3;
    cyFmt.lpDecimalSep = pGlobalData->szCurrDecimalSep;
    cyFmt.lpThousandSep = pGlobalData->szCurrThousandSep;
    cyFmt.lpCurrencySymbol = pGlobalData->szCurrSymbol;
    cyFmt.NegativeOrder = 0;

    for (i = 0; i < 4; i++)
    {
        cyFmt.PositiveOrder = i;
        GetCurrencyFormatW(pGlobalData->UserLCID, 0,
                           L"1.1",
                           &cyFmt, szBuffer, MAX_FMT_SIZE);

        SendDlgItemMessageW(hwndDlg, IDC_CURRENCYPOSVALUE,
                            CB_INSERTSTRING,
                            -1,
                            (LPARAM)szBuffer);
    }

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYPOSVALUE,
                        CB_SETCURSEL,
                        pGlobalData->nCurrPosFormat,
                        0);
}

__attribute__((used)) static VOID
InitCurrencyNegativeFormats(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szBuffer[MAX_FMT_SIZE];
    CURRENCYFMTW cyFmt;
    int i;

    /* negative currency values */
    cyFmt.NumDigits = pGlobalData->nCurrDigits;
    cyFmt.LeadingZero = 0;
    cyFmt.Grouping = 3;
    cyFmt.lpDecimalSep = pGlobalData->szCurrDecimalSep;
    cyFmt.lpThousandSep = pGlobalData->szCurrThousandSep;
    cyFmt.lpCurrencySymbol = pGlobalData->szCurrSymbol;
    cyFmt.PositiveOrder = 0;

    for (i = 0; i < 16; i++)
    {
        cyFmt.NegativeOrder = i;
        GetCurrencyFormatW(pGlobalData->UserLCID, 0,
                           L"-1.1",
                           &cyFmt, szBuffer, MAX_FMT_SIZE);

        SendDlgItemMessageW(hwndDlg, IDC_CURRENCYNEGVALUE,
                            CB_INSERTSTRING,
                            -1,
                            (LPARAM)szBuffer);
    }

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYNEGVALUE,
                        CB_SETCURSEL,
                        pGlobalData->nCurrNegFormat,
                        0);
}

__attribute__((used)) static VOID
InitCurrencyDecimalSeparators(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYDECSEP,
                        CB_LIMITTEXT,
                        MAX_CURRDECIMALSEP - 1,
                        0);

    /* Decimal separator */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYDECSEP,
                        CB_ADDSTRING,
                        0,
                        (LPARAM)pGlobalData->szCurrDecimalSep);

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYDECSEP,
                        CB_SETCURSEL,
                        0, /* Index */
                        0);
}

__attribute__((used)) static VOID
InitCurrencyNumFracDigits(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szBuffer[MAX_FMT_SIZE];
    int i;

    /* Create standard list of fractional symbols */
    for (i = 0; i < 10; i++)
    {
        szBuffer[0] = L'0' + i;
        szBuffer[1] = 0;
        SendDlgItemMessageW(hwndDlg, IDC_CURRENCYDECNUM,
                            CB_ADDSTRING,
                            0,
                            (LPARAM)szBuffer);
    }

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYDECNUM,
                        CB_SETCURSEL,
                        pGlobalData->nCurrDigits,
                        0);
}

__attribute__((used)) static VOID
InitCurrencyGroupSeparators(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    /* Limit text length */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYGRPSEP,
                        CB_LIMITTEXT,
                        MAX_CURRTHOUSANDSEP - 1,
                        0);

    /* Digit group separator */
    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYGRPSEP,
                        CB_ADDSTRING,
                        0,
                        (LPARAM)pGlobalData->szCurrThousandSep);

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYGRPSEP,
                        CB_SETCURSEL,
                        0, /* Index */
                        0);
}

__attribute__((used)) static VOID
InitDigitGroupCB(HWND hwndDlg, PGLOBALDATA pGlobalData)
{
    WCHAR szBuffer[MAX_FMT_SIZE];
    CURRENCYFMTW cyFmt;
    INT i;

    /* Digit grouping */
    cyFmt.NumDigits = 0;
    cyFmt.LeadingZero = 0;
    cyFmt.lpDecimalSep = L"";
    cyFmt.lpThousandSep = pGlobalData->szCurrThousandSep;
    cyFmt.PositiveOrder = 0;
    cyFmt.NegativeOrder = 0;
    cyFmt.lpCurrencySymbol = L"";

    for (i = 0 ; i < MAX_GROUPINGFORMATS ; i++)
    {
       cyFmt.Grouping = GroupingFormats[i].nInteger;

       GetCurrencyFormatW(pGlobalData->UserLCID, 0,
                          L"123456789",
                          &cyFmt, szBuffer, MAX_FMT_SIZE);
       SendDlgItemMessageW(hwndDlg, IDC_CURRENCYGRPNUM,
                           CB_INSERTSTRING,
                           -1,
                           (LPARAM)szBuffer);
    }

    SendDlgItemMessageW(hwndDlg, IDC_CURRENCYGRPNUM,
                        CB_SETCURSEL,
                        pGlobalData->nCurrGrouping,
                        0);
}

__attribute__((used)) static
BOOL
GetCurrencySetting(
     HWND hwndDlg,
     PGLOBALDATA pGlobalData)
{
    WCHAR szCurrSymbol[MAX_CURRSYMBOL];
    WCHAR szCurrDecimalSep[MAX_CURRDECIMALSEP];
    WCHAR szCurrThousandSep[MAX_CURRTHOUSANDSEP];
    INT nCurrPosFormat;
    INT nCurrNegFormat;
    INT nCurrDigits;
    INT nCurrGrouping;

    /* Currency symbol */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_CURRENCYSYMBOL,
                            szCurrSymbol,
                            MAX_CURRSYMBOL);

    if (szCurrSymbol[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Positive Amount */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_CURRENCYPOSVALUE,
                             &nCurrPosFormat);

    /* Negative Amount */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_CURRENCYNEGVALUE,
                             &nCurrNegFormat);

    /* Decimal separator */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_CURRENCYDECSEP,
                            szCurrDecimalSep,
                            MAX_CURRDECIMALSEP);

    if (szCurrDecimalSep[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Number of fractional digits */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_CURRENCYDECNUM,
                             &nCurrDigits);

    /* Grouping symbol */
    GetSelectedComboBoxText(hwndDlg,
                            IDC_CURRENCYGRPSEP,
                            szCurrThousandSep,
                            MAX_CURRTHOUSANDSEP);

    if (szCurrThousandSep[0] == L'\0')
    {
        /* TODO: Show error message */

        return FALSE;
    }

    /* Digit grouping */
    GetSelectedComboBoxIndex(hwndDlg,
                             IDC_CURRENCYGRPNUM,
                             &nCurrGrouping);

    /* Store settings in global data */
    wcscpy(pGlobalData->szCurrSymbol, szCurrSymbol);
    pGlobalData->nCurrGrouping = nCurrGrouping;
    wcscpy(pGlobalData->szCurrDecimalSep, szCurrDecimalSep);
    wcscpy(pGlobalData->szCurrThousandSep, szCurrThousandSep);
    pGlobalData->nCurrPosFormat = nCurrPosFormat;
    pGlobalData->nCurrNegFormat = nCurrNegFormat;
    pGlobalData->nCurrDigits = nCurrDigits;

    return TRUE;
}

