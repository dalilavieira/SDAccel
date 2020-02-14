#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int wchar_t ;
struct TYPE_6__ {char* cFileName; int dwFileAttributes; } ;
typedef  TYPE_1__ WIN32_FIND_DATA ;
struct TYPE_7__ {int LowPart; int /*<<< orphan*/  HighPart; } ;
typedef  int* PWCHAR ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int (* PKULL_M_FILE_FIND_CALLBACK ) (int,int*,int*,int /*<<< orphan*/ ) ;
typedef  int* PDWORD ;
typedef  char* PCWCHAR ;
typedef  int* PBYTE ;
typedef  int* LPWSTR ;
typedef  scalar_t__ LPCVOID ;
typedef  TYPE_2__ LARGE_INTEGER ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int ARRAYSIZE (int*) ; 
 int /*<<< orphan*/  CREATE_ALWAYS ; 
 int /*<<< orphan*/  CRYPT_STRING_BASE64 ; 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateFile (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int CryptBinaryToString (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int*,int*) ; 
 int ExpandEnvironmentStrings (char*,int*,int) ; 
 int FALSE ; 
 int FILE_ATTRIBUTE_DIRECTORY ; 
 int /*<<< orphan*/  FILE_SHARE_READ ; 
 int /*<<< orphan*/  FindClose (scalar_t__) ; 
 scalar_t__ FindFirstFile (int*,TYPE_1__*) ; 
 scalar_t__ FindNextFile (scalar_t__,TYPE_1__*) ; 
 int FlushFileBuffers (scalar_t__) ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 int /*<<< orphan*/  GENERIC_WRITE ; 
 int GetCurrentDirectory (int,int*) ; 
 int GetFileAttributes (char*) ; 
 scalar_t__ GetFileSizeEx (scalar_t__,TYPE_2__*) ; 
 int INVALID_FILE_ATTRIBUTES ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ LocalFree (int*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 int PathCanonicalize (int*,char*) ; 
 int /*<<< orphan*/ * PathCombine (int*,int*,char*) ; 
 scalar_t__ PathIsRelative (char*) ; 
 scalar_t__ ReadFile (scalar_t__,int*,int,int*,int /*<<< orphan*/ *) ; 
 int TRUE ; 
 scalar_t__ WriteFile (scalar_t__,scalar_t__,int,int*,int /*<<< orphan*/ *) ; 
 scalar_t__ _wcsicmp (char*,char*) ; 
 scalar_t__ isBase64InterceptInput ; 
 scalar_t__ isBase64InterceptOutput ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 int* kull_m_file_forbiddenChars ; 
 int kull_m_string_quick_base64_to_Binary (char*,int**,int*) ; 
 scalar_t__ wcscat_s (int*,int,char*) ; 
 scalar_t__ wcscpy_s (int*,int,char*) ; 
 scalar_t__ wcslen (int*) ; 

BOOL kull_m_file_getCurrentDirectory(wchar_t ** ppDirName)
{
	BOOL reussite = FALSE;
	DWORD tailleRequise = GetCurrentDirectory(0, NULL);
	if(*ppDirName = (wchar_t *) LocalAlloc(LPTR, tailleRequise * sizeof(wchar_t)))
		if(!(reussite = (tailleRequise > 0 && (GetCurrentDirectory(tailleRequise, *ppDirName) == tailleRequise - 1))))
			LocalFree(*ppDirName);

	return reussite;
}

BOOL kull_m_file_getAbsolutePathOf(PCWCHAR thisData, wchar_t ** reponse)
{
	BOOL reussite = FALSE;
	wchar_t *monRep;
	*reponse = (wchar_t *) LocalAlloc(LPTR, MAX_PATH * sizeof(wchar_t));

	if(PathIsRelative(thisData))
	{
		if(kull_m_file_getCurrentDirectory(&monRep))
		{
			reussite = (PathCombine(*reponse , monRep, thisData) != NULL);
			LocalFree(monRep);
		}
	}
	else reussite = PathCanonicalize(*reponse, thisData);

	if(!reussite)
		LocalFree(*reponse);

	return reussite;
}

BOOL kull_m_file_isFileExist(PCWCHAR fileName)
{
	BOOL reussite = FALSE;
	HANDLE hFile = NULL;

	reussite = ((hFile = CreateFile(fileName, 0, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)) && hFile != INVALID_HANDLE_VALUE);
	if(reussite)
		CloseHandle(hFile);
	return reussite;
}

BOOL kull_m_file_writeData(PCWCHAR fileName, LPCVOID data, DWORD lenght)
{
	BOOL reussite = FALSE;
	DWORD dwBytesWritten = 0, i;
	HANDLE hFile = NULL;
	LPWSTR base64;

	if(isBase64InterceptOutput)
	{
		if(CryptBinaryToString((const BYTE *) data, lenght, CRYPT_STRING_BASE64, NULL, &dwBytesWritten))
		{
			if(base64 = (LPWSTR) LocalAlloc(LPTR, dwBytesWritten * sizeof(wchar_t)))
			{
				if(reussite = CryptBinaryToString((const BYTE *) data, lenght, CRYPT_STRING_BASE64, base64, &dwBytesWritten))
				{
					kprintf(L"\n====================\nBase64 of file : %s\n====================\n", fileName);
					for(i = 0; i < dwBytesWritten; i++)
						kprintf(L"%c", base64[i]);
					kprintf(L"====================\n");
				}
				LocalFree(base64);
			}
		}
	}
	else if((hFile = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL)) && hFile != INVALID_HANDLE_VALUE)
	{
		if(WriteFile(hFile, data, lenght, &dwBytesWritten, NULL) && (lenght == dwBytesWritten))
			reussite = FlushFileBuffers(hFile);
		CloseHandle(hFile);
	}
	return reussite;
}

BOOL kull_m_file_readData(PCWCHAR fileName, PBYTE * data, PDWORD lenght)	// for ""little"" files !
{
	BOOL reussite = FALSE;
	DWORD dwBytesReaded;
	LARGE_INTEGER filesize;
	HANDLE hFile = NULL;

	if(isBase64InterceptInput)
	{
		if(!(reussite = kull_m_string_quick_base64_to_Binary(fileName, data, lenght)))
			PRINT_ERROR_AUTO(L"kull_m_string_quick_base64_to_Binary");
	}
	else if((hFile = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)) && hFile != INVALID_HANDLE_VALUE)
	{
		if(GetFileSizeEx(hFile, &filesize) && !filesize.HighPart)
		{
			*lenght = filesize.LowPart;
			if(*data = (PBYTE) LocalAlloc(LPTR, *lenght))
			{
				if(!(reussite = ReadFile(hFile, *data, *lenght, &dwBytesReaded, NULL) && (*lenght == dwBytesReaded)))
					LocalFree(*data);
			}
		}
		CloseHandle(hFile);
	}
	return reussite;
}

void kull_m_file_cleanFilename(PWCHAR fileName)
{
	DWORD i, j;
	for(i = 0; fileName[i]; i++)
		for(j = 0; j < ARRAYSIZE(kull_m_file_forbiddenChars); j++)
			if(fileName[i] == kull_m_file_forbiddenChars[j])
				fileName[i] = L'~';
}

PWCHAR kull_m_file_fullPath(PCWCHAR fileName)
{
	PWCHAR buffer = NULL;
	DWORD bufferLen;
	if(fileName)
		if(bufferLen = ExpandEnvironmentStrings(fileName, NULL, 0))
			if(buffer = (PWCHAR) LocalAlloc(LPTR, bufferLen * sizeof(wchar_t)))
				if(bufferLen != ExpandEnvironmentStrings(fileName, buffer, bufferLen))
					buffer = (PWCHAR) LocalFree(buffer);
	return buffer;
}

BOOL kull_m_file_Find(PCWCHAR directory, PCWCHAR filter, BOOL isRecursive /*TODO*/, DWORD level, BOOL isPrintInfos, PKULL_M_FILE_FIND_CALLBACK callback, PVOID pvArg)
{
	BOOL status = FALSE;
	DWORD dwAttrib;
	HANDLE hFind;
	WIN32_FIND_DATA fData;
	PWCHAR fullpath;

	dwAttrib = GetFileAttributes(directory);
	if((dwAttrib != INVALID_FILE_ATTRIBUTES) && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY))
	{
		if(isPrintInfos && !level)
		{
			kprintf(L"%*s" L"Directory \'%s\'", level << 1, L"", directory);
			if(filter)
				kprintf(L" (%s)", filter);
			kprintf(L"\n");
		}
		if(fullpath = (wchar_t *) LocalAlloc(LPTR, MAX_PATH * sizeof(wchar_t)))
		{
			if(wcscpy_s(fullpath, MAX_PATH, directory) == 0)
			{
				if(wcscat_s(fullpath, MAX_PATH, L"\\") == 0)
				{
					if(wcscat_s(fullpath, MAX_PATH, filter ? filter : L"*") == 0)
					{
						hFind = FindFirstFile(fullpath, &fData);
						if(hFind != INVALID_HANDLE_VALUE)
						{
							do
							{
								if(_wcsicmp(fData.cFileName, L".") && _wcsicmp(fData.cFileName, L".."))
								{
									if(wcscpy_s(fullpath, MAX_PATH, directory) == 0)
									{
										if(wcscat_s(fullpath, MAX_PATH, L"\\") == 0)
										{
											dwAttrib = (DWORD) wcslen(fullpath);
											if(wcscat_s(fullpath, MAX_PATH, fData.cFileName) == 0)
											{
												if(isPrintInfos)
													kprintf(L"%*s" L"%3u %c|'%s\'\n", level << 1, L"", level, (fData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? L'D' : L'F' , fData.cFileName);
												if(!(fData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
												{
													if(callback)
														status = callback(level, fullpath, fullpath + dwAttrib, pvArg);
												}
												else if(isRecursive && fData.cFileName)
													status = kull_m_file_Find(fullpath, filter, TRUE, level + 1, isPrintInfos, callback, pvArg);
											}
										}
									}
								}
							} while(!status && FindNextFile(hFind, &fData));
							FindClose(hFind);
						}
					}
				}
			}
		}
		LocalFree(fullpath);
	}
	return status;
}

