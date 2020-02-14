#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WCHAR ;
typedef  int ULONG ;
struct TYPE_5__ {int usrmod0_force_logoff; int usrmod0_min_passwd_len; int usrmod0_max_passwd_age; int usrmod0_min_passwd_age; int usrmod0_password_hist_len; int usrmod3_lockout_threshold; int usrmod3_lockout_duration; int usrmod3_lockout_observation_window; scalar_t__ usrmod1_role; } ;
typedef  TYPE_1__* PUSER_MODALS_INFO_3 ;
typedef  TYPE_1__* PUSER_MODALS_INFO_1 ;
typedef  TYPE_1__* PUSER_MODALS_INFO_0 ;
typedef  scalar_t__ NT_PRODUCT_TYPE ;
typedef  scalar_t__ NET_API_STATUS ;
typedef  scalar_t__* LPWSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  size_t INT ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ConPrintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ConPuts (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  MSG_ACCOUNTS_HELP ; 
 int /*<<< orphan*/  MSG_ACCOUNTS_SYNTAX ; 
 scalar_t__ NERR_Success ; 
 int /*<<< orphan*/  NetApiBufferFree (TYPE_1__*) ; 
 scalar_t__ NetUserModalsGet (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 scalar_t__ NetUserModalsSet (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ NtProductLanManNt ; 
 scalar_t__ NtProductServer ; 
 int /*<<< orphan*/  PrintMessageString (int) ; 
 int /*<<< orphan*/  PrintMessageStringV (int,char*) ; 
 int /*<<< orphan*/  PrintNetMessage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PrintPaddedMessageString (int,size_t) ; 
 int /*<<< orphan*/  RtlGetNtProductType (scalar_t__*) ; 
 int /*<<< orphan*/  StdErr ; 
 int /*<<< orphan*/  StdOut ; 
 int TIMEQ_FOREVER ; 
 scalar_t__ TRUE ; 
 scalar_t__ UAS_ROLE_PRIMARY ; 
 int ULONG_MAX ; 
 scalar_t__ _wcsicmp (scalar_t__*,char*) ; 
 scalar_t__ _wcsnicmp (scalar_t__*,char*,int) ; 
 scalar_t__ wcsicmp (scalar_t__*,char*) ; 
 int wcstoul (scalar_t__*,scalar_t__**,int) ; 

INT
cmdAccounts(
    INT argc,
    WCHAR **argv)
{
    PUSER_MODALS_INFO_0 Info0 = NULL;
    PUSER_MODALS_INFO_1 Info1 = NULL;
    PUSER_MODALS_INFO_3 Info3 = NULL;
    NT_PRODUCT_TYPE ProductType;
    LPWSTR p;
    LPWSTR endptr;
    DWORD ParamErr;
    ULONG value;
    INT i;
    BOOL Modified = FALSE;
#if 0
    BOOL Domain = FALSE;
#endif
    INT nPaddedLength = 58;
    NET_API_STATUS Status;
    INT result = 0;

    for (i = 2; i < argc; i++)
    {
        if (_wcsicmp(argv[i], L"help") == 0)
        {
            /* Print short syntax help */
            PrintMessageString(4381);
            ConPuts(StdOut, L"\n");
            PrintNetMessage(MSG_ACCOUNTS_SYNTAX);
            return 0;
        }

        if (_wcsicmp(argv[i], L"/help") == 0)
        {
            /* Print full help text*/
            PrintMessageString(4381);
            ConPuts(StdOut, L"\n");
            PrintNetMessage(MSG_ACCOUNTS_SYNTAX);
            PrintNetMessage(MSG_ACCOUNTS_HELP);
            return 0;
        }

        if (_wcsicmp(argv[i], L"/domain") == 0)
        {
            ConPuts(StdErr, L"The /DOMAIN option is not supported yet.\n");
#if 0
            Domain = TRUE;
#endif
        }
    }

    Status = NetUserModalsGet(NULL, 0, (LPBYTE*)&Info0);
    if (Status != NERR_Success)
        goto done;

    for (i = 2; i < argc; i++)
    {
        if (_wcsnicmp(argv[i], L"/forcelogoff:", 13) == 0)
        {
            p = &argv[i][13];
            if (wcsicmp(p, L"no") == 0)
            {
                Info0->usrmod0_force_logoff = TIMEQ_FOREVER;
                Modified = TRUE;
            }
            else
            {
                value = wcstoul(p, &endptr, 10);
                if (*endptr != 0)
                {
                    PrintMessageStringV(3952, L"/FORCELOGOFF");
                    result = 1;
                    goto done;
                }

                Info0->usrmod0_force_logoff = value * 60;
                Modified = TRUE;
            }
        }
        else if (_wcsnicmp(argv[i], L"/minpwlen:", 10) == 0)
        {
            p = &argv[i][10];
            value = wcstoul(p, &endptr, 10);
            if (*endptr != 0)
            {
                PrintMessageStringV(3952, L"/MINPWLEN");
                result = 1;
                goto done;
            }

            Info0->usrmod0_min_passwd_len = value;
            Modified = TRUE;
        }
        else if (_wcsnicmp(argv[i], L"/maxpwage:", 10) == 0)
        {
            p = &argv[i][10];

            if (wcsicmp(p, L"unlimited"))
            {
                Info0->usrmod0_max_passwd_age = ULONG_MAX;
                Modified = TRUE;
            }
            else
            {
                value = wcstoul(p, &endptr, 10);
                if (*endptr != 0)
                {
                    PrintMessageStringV(3952, L"/MAXPWLEN");
                    result = 1;
                    goto done;
                }

                Info0->usrmod0_max_passwd_age = value * 86400;
                Modified = TRUE;
            }
        }
        else if (_wcsnicmp(argv[i], L"/minpwage:", 10) == 0)
        {
            p = &argv[i][10];
            value = wcstoul(p, &endptr, 10);
            if (*endptr != 0)
            {
                PrintMessageStringV(3952, L"/MINPWAGE");
                result = 1;
                goto done;
            }

            Info0->usrmod0_min_passwd_age = value * 86400;
            Modified = TRUE;
        }
        else if (_wcsnicmp(argv[i], L"/uniquepw:", 10) == 0)
        {
            p = &argv[i][10];
            value = wcstoul(p, &endptr, 10);
            if (*endptr != 0)
            {
                PrintMessageStringV(3952, L"/UNIQUEPW");
                result = 1;
                goto done;
            }

            Info0->usrmod0_password_hist_len = value;
            Modified = TRUE;
        }
    }

    if (Modified == TRUE)
    {
        Status = NetUserModalsSet(NULL, 0, (LPBYTE)Info0, &ParamErr);
        if (Status != NERR_Success)
            goto done;
    }
    else
    {
        Status = NetUserModalsGet(NULL, 1, (LPBYTE*)&Info1);
        if (Status != NERR_Success)
            goto done;

        Status = NetUserModalsGet(NULL, 3, (LPBYTE*)&Info3);
        if (Status != NERR_Success)
            goto done;

        RtlGetNtProductType(&ProductType);

        PrintPaddedMessageString(4570, nPaddedLength);
        if (Info0->usrmod0_force_logoff == TIMEQ_FOREVER)
            PrintMessageString(4305);
        else
            ConPrintf(StdOut, L"%lu", Info0->usrmod0_force_logoff);
        ConPuts(StdOut, L"\n");

        PrintPaddedMessageString(4572, nPaddedLength);
        ConPrintf(StdOut, L"%lu\n", Info0->usrmod0_min_passwd_age / 86400);

        PrintPaddedMessageString(4573, nPaddedLength);
        ConPrintf(StdOut, L"%lu\n", Info0->usrmod0_max_passwd_age / 86400);

        PrintPaddedMessageString(4574, nPaddedLength);
        ConPrintf(StdOut, L"%lu\n", Info0->usrmod0_min_passwd_len);

        PrintPaddedMessageString(4575, nPaddedLength);
        if (Info0->usrmod0_password_hist_len == 0)
            PrintMessageString(4303);
        else
            ConPrintf(StdOut, L"%lu", Info0->usrmod0_password_hist_len);
        ConPuts(StdOut, L"\n");

        PrintPaddedMessageString(4578, nPaddedLength);
        if (Info3->usrmod3_lockout_threshold == 0)
            PrintMessageString(4305);
        else
            ConPrintf(StdOut, L"%lu", Info3->usrmod3_lockout_threshold);
        ConPuts(StdOut, L"\n");

        PrintPaddedMessageString(4579, nPaddedLength);
        ConPrintf(StdOut, L"%lu\n", Info3->usrmod3_lockout_duration / 60);

        PrintPaddedMessageString(4580, nPaddedLength);
        ConPrintf(StdOut, L"%lu\n", Info3->usrmod3_lockout_observation_window / 60);

        PrintPaddedMessageString(4576, nPaddedLength);
        if (Info1->usrmod1_role == UAS_ROLE_PRIMARY)
        {
            if (ProductType == NtProductLanManNt)
            {
                PrintMessageString(5070);
            }
            else if (ProductType == NtProductServer)
            {
                PrintMessageString(5073);
            }
            else
            {
                PrintMessageString(5072);
            }
        }
        else
        {
            PrintMessageString(5071);
        }
        ConPuts(StdOut, L"\n");
    }

done:
    if (Info3 != NULL)
        NetApiBufferFree(Info3);

    if (Info1 != NULL)
        NetApiBufferFree(Info1);

    if (Info0 != NULL)
        NetApiBufferFree(Info0);

    return result;
}

