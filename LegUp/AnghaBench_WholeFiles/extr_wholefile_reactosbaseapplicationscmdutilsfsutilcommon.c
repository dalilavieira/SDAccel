#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT ;
struct TYPE_4__ {int (* Handler ) (int,int const**) ;int /*<<< orphan*/  Desc; int /*<<< orphan*/  Command; } ;
typedef  int TCHAR ;
typedef  TYPE_1__ HandlerItem ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  scalar_t__ BOOLEAN ;

/* Variables and functions */
 scalar_t__ CreateFile (int*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ DRIVE_REMOTE ; 
 int /*<<< orphan*/  FILE_ATTRIBUTE_NORMAL ; 
 int FILE_SHARE_READ ; 
 int FILE_SHARE_WRITE ; 
 int FORMAT_MESSAGE_ALLOCATE_BUFFER ; 
 int FORMAT_MESSAGE_FROM_SYSTEM ; 
 scalar_t__ FormatMessageW (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 scalar_t__ GetDriveType (int const*) ; 
 int GetLastError () ; 
 int /*<<< orphan*/  GetVolumeInformation (int*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*,int) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LocalFree (int*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int PATH_MAX ; 
 int PrintErrorMessage (int) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  _ftprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  _stprintf (int*,int /*<<< orphan*/ ,int const*) ; 
 scalar_t__ _tcscmp (int*,int /*<<< orphan*/ ) ; 
 scalar_t__ _tcsicmp (int const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int stub1 (int,int const**) ; 

int FindHandler(int argc,
                const TCHAR *argv[],
                HandlerItem * HandlersList,
                int HandlerListCount,
                void (*UsageHelper)(const TCHAR *))
{
    int i;
    int ret;
    const TCHAR * Command;

    ret = 1;
    Command = NULL;
    i = HandlerListCount;

    /* If we have a command, does it match a known one? */
    if (argc > 1)
    {
        /* Browse all the known commands finding the right one */
        Command = argv[1];
        for (i = 0; i < HandlerListCount; ++i)
        {
            if (_tcsicmp(Command, HandlersList[i].Command) == 0)
            {
                ret = HandlersList[i].Handler(argc - 1, &argv[1]);
                break;
            }
        }
    }

    /* We failed finding someone to handle the caller's needs, print out */
    if (i == HandlerListCount)
    {
        UsageHelper(Command);
    }

    return ret;
}

HANDLE OpenVolume(const TCHAR * Volume,
                  BOOLEAN AllowRemote,
                  BOOLEAN NtfsOnly)
{
    UINT Type;
    HANDLE hVolume;
    TCHAR VolumeID[PATH_MAX];

    /* Get volume type */
    if (!AllowRemote && Volume[1] == L':')
    {
        Type = GetDriveType(Volume);
        if (Type == DRIVE_REMOTE)
        {
            _ftprintf(stderr, _T("FSUTIL needs a local device\n"));
            return INVALID_HANDLE_VALUE;
        }
    }

    /* Get filesystem type */
    if (NtfsOnly)
    {
        TCHAR FileSystem[MAX_PATH + 1];

        _stprintf(VolumeID, _T("\\\\.\\%s\\"), Volume);
        if (!GetVolumeInformation(VolumeID, NULL,  0, NULL, NULL, NULL, FileSystem, MAX_PATH + 1))
        {
            PrintErrorMessage(GetLastError());
            return INVALID_HANDLE_VALUE;
        }

        if (_tcscmp(FileSystem, _T("NTFS")) != 0)
        {
            _ftprintf(stderr, _T("FSUTIL needs a NTFS device\n"));
            return INVALID_HANDLE_VALUE;
        }
    }

    /* Create full name */
    _stprintf(VolumeID, _T("\\\\.\\%s"), Volume);

    /* Open the volume */
    hVolume = CreateFile(VolumeID, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                         NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hVolume == INVALID_HANDLE_VALUE)
    {
        PrintErrorMessage(GetLastError());
        return INVALID_HANDLE_VALUE;
    }

    return hVolume;
}

void PrintDefaultUsage(const TCHAR * Command,
                       const TCHAR * SubCommand,
                       HandlerItem * HandlersList,
                       int HandlerListCount)
{
    int i;

    /* If we were given a command, print it's not supported */
    if (SubCommand != NULL)
    {
        _ftprintf(stderr, _T("Unhandled%scommand: %s\n"), Command, SubCommand);
    }

    /* And dump any available command */
    _ftprintf(stderr, _T("---- Handled%scommands ----\n\n"), Command);
    for (i = 0; i < HandlerListCount; ++i)
    {
        _ftprintf(stderr, _T("%s\t%s\n"), HandlersList[i].Command, HandlersList[i].Desc);
    }
}

int PrintErrorMessage(DWORD Error)
{
    TCHAR * String;

    /* Try to get textual error */
    if (FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                       NULL, Error, 0, (TCHAR *)&String, 0, NULL) != 0)
    {
        /* And print it */
        _ftprintf(stderr, _T("Error: %s\n"), String);
        LocalFree(String);
    }
    else
    {
        /* Otherwise, just print the error number */
        _ftprintf(stderr, _T("Error: %d\n"), Error);
    }

    return Error;
}

