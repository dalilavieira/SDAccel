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
typedef  int WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  void* BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ConInitStdStreams () ; 
 int /*<<< orphan*/  ConMsgPuts (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ConPrintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ConPuts (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ConResPuts (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EWX_LOGOFF ; 
 int /*<<< orphan*/  ExitWindowsEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FORMAT_MESSAGE_FROM_SYSTEM ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  IDS_ILLEGAL_PARAM ; 
 int /*<<< orphan*/  IDS_LOGOFF_LOCAL ; 
 int /*<<< orphan*/  IDS_LOGOFF_REMOTE ; 
 int /*<<< orphan*/  IDS_USAGE ; 
 int /*<<< orphan*/  LANG_USER_DEFAULT ; 
 int /*<<< orphan*/  StdErr ; 
 int /*<<< orphan*/  StdOut ; 
 void* TRUE ; 
 void* bVerbose ; 
 scalar_t__ szRemoteServerName ; 

VOID DisplayError(DWORD dwError)
{
    ConMsgPuts(StdErr, FORMAT_MESSAGE_FROM_SYSTEM,
               NULL, dwError, LANG_USER_DEFAULT);
    ConPrintf(StdErr, L"Error code: %lu\n", dwError);
}

BOOL ParseCommandLine(int argc, WCHAR *argv[])
{
    int i;

    // FIXME: Add handling of command-line arguments to select
    // the session number and name, and also name of remote machine.
    // Example: logoff.exe 4 /SERVER:Master
    // should logoff session number 4 on remote machine called Master.

    for (i = 1; i < argc; i++)
    {
        switch (argv[i][0])
        {
        case L'-':
        case L'/':
            // -v (verbose)
            if (argv[i][1] == L'v')
            {
                bVerbose = TRUE;
                break;
            }
            // -? (usage)
            else if (argv[i][1] == L'?')
            {
                /* Will display the Usage */
                return FALSE;
            }
        /* Fall through */
        default:
            /* Invalid parameter detected */
            ConResPuts(StdErr, IDS_ILLEGAL_PARAM);
            return FALSE;
        }
    }

    return TRUE;
}

int wmain(int argc, WCHAR *argv[])
{
    /* Initialize the Console Standard Streams */
    ConInitStdStreams();

    /* Parse command line */
    if (!ParseCommandLine(argc, argv))
    {
        ConResPuts(StdOut, IDS_USAGE);
        return 1;
    }

    /* Should we log off session on remote server? */
    if (szRemoteServerName)
    {
        if (bVerbose)
            ConResPuts(StdOut, IDS_LOGOFF_REMOTE);

        // FIXME: Add Remote Procedure Call to logoff user on a remote machine
        ConPuts(StdErr, L"Remote Procedure Call in logoff.exe has not been implemented");
    }
    /* Perform logoff of current session on local machine instead */
    else
    {
        if (bVerbose)
        {
            /* Get resource string and print it */
            ConResPuts(StdOut, IDS_LOGOFF_LOCAL);
        }

        /* Actual logoff */
        if (!ExitWindowsEx(EWX_LOGOFF, 0))
        {
            DisplayError(GetLastError());
            return 1;
        }
    }

    return 0;
}

