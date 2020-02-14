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
typedef  scalar_t__ ULONG ;
typedef  char TCHAR ;
typedef  char* LPCTSTR ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BackupBootSector (char*) ; 
 int /*<<< orphan*/  CREATE_NEW ; 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 int /*<<< orphan*/  CloseVolume () ; 
 scalar_t__ CreateFile (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char* ERROR_ALREADY_EXISTS ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GENERIC_WRITE ; 
 char* GetLastError () ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  InstallBootSector (char*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  OpenVolume (char*) ; 
 int /*<<< orphan*/  ReadVolumeSector (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WriteFile (scalar_t__,int /*<<< orphan*/ *,int,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WriteVolumeSector (int,scalar_t__) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  _stprintf (char*,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 scalar_t__ _tcsicmp (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _tprintf (int /*<<< orphan*/ ,...) ; 
 scalar_t__ fat32_data ; 
 scalar_t__ fat_data ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ *,int) ; 

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        _tprintf(_T("syntax: install x: [fs_type]\nwhere fs_type is fat or fat32\n"));
        return -1;
    }

    if (!OpenVolume(argv[1]))
    {
        return -1;
    }

    BackupBootSector(argv[1]);

    InstallBootSector(argv[2]);

    _tprintf(_T("You must now copy freeldr.sys & freeldr.ini to %s.\n"), argv[1]);

    CloseVolume();

    return 0;
}

BOOL BackupBootSector(LPCTSTR lpszVolumeName)
{
    HANDLE    hBackupFile;
    TCHAR    szFileName[MAX_PATH];
    ULONG    Count;
    BYTE    BootSectorBuffer[512];
    DWORD    dwNumberOfBytesWritten;
    BOOL    bRetVal;

    //
    // Find the next unused filename and open it
    //
    for (Count=0; ; Count++)
    {
        //
        // Generate the next filename
        //
        _stprintf(szFileName, _T("%s\\bootsect.%03ld"), lpszVolumeName, Count);

        //
        // Try to create a new file, fail if exists
        //
        hBackupFile = CreateFile(szFileName, GENERIC_WRITE, 0, NULL, CREATE_NEW, /*FILE_ATTRIBUTE_SYSTEM*/0, NULL);

        //
        // Check to see if it worked
        //
        if (hBackupFile != INVALID_HANDLE_VALUE)
        {
            break;
        }

        //
        // Nope, didn't work
        // Check to see if it already existed
        //
        if (!(GetLastError() != ERROR_ALREADY_EXISTS))
        {
            _tprintf(_T("%s:%d: "), __FILE__, __LINE__);
            _tprintf(_T("Boot sector backup failed. Error code %ld.\n"), GetLastError());
            return FALSE;
        }
    }

    //
    // Try to read the boot sector
    //
    if (!ReadVolumeSector(0, BootSectorBuffer))
    {
        CloseHandle(hBackupFile);
        return FALSE;
    }

    //
    // Try to write the boot sector data to the file
    //
    bRetVal = WriteFile(hBackupFile, BootSectorBuffer, 512, &dwNumberOfBytesWritten, NULL);
    if (!bRetVal || (dwNumberOfBytesWritten != 512))
    {
        CloseHandle(hBackupFile);
        _tprintf(_T("%s:%d: "), __FILE__, __LINE__);
        _tprintf(_T("WriteFile() failed. Error code %ld.\n"), GetLastError());
        return FALSE;
    }

    _tprintf(_T("Boot sector backed up to file: %s\n"), szFileName);

    CloseHandle(hBackupFile);

    return TRUE;
}

BOOL InstallBootSector(LPCTSTR lpszVolumeType)
{
    BYTE    BootSectorBuffer[512];

    //
    // Read in the old boot sector
    //
    if (!ReadVolumeSector(0, BootSectorBuffer))
    {
        return FALSE;
    }

    if (_tcsicmp(lpszVolumeType, _T("fat")) == 0)
    {
        //
        // Update the BPB in the new boot sector
        //
        memcpy((fat_data+3), (BootSectorBuffer+3), 59 /*fat BPB length*/);

        //
        // Write out new boot sector
        //
        if (!WriteVolumeSector(0, fat_data))
        {
            return FALSE;
        }
    }
    else if (_tcsicmp(lpszVolumeType, _T("fat32")) == 0)
    {
        //
        // Update the BPB in the new boot sector
        //
        memcpy((fat32_data+3), (BootSectorBuffer+3), 87 /*fat32 BPB length*/);

        //
        // Write out new boot sector
        //
        if (!WriteVolumeSector(0, fat32_data))
        {
            return FALSE;
        }

        //
        // Write out new extra sector
        //
        if (!WriteVolumeSector(14, (fat32_data+512)))
        {
            return FALSE;
        }
    }
    else
    {
        _tprintf(_T("%s:%d: "), __FILE__, __LINE__);
        _tprintf(_T("File system type %s unknown.\n"), lpszVolumeType);
        return FALSE;
    }

    _tprintf(_T("%s boot sector installed.\n"), lpszVolumeType);

    return TRUE;
}

