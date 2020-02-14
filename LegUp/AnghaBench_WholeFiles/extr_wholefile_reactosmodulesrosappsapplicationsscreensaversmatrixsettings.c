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
typedef  int ULONG ;
typedef  scalar_t__ TCHAR ;
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int /*<<< orphan*/  BYTE ;

/* Variables and functions */
 scalar_t__ DENSITY_MAX ; 
 scalar_t__ DENSITY_MIN ; 
 scalar_t__ ERROR_SUCCESS ; 
 void* FALSE ; 
 scalar_t__ FONT_MAX ; 
 scalar_t__ FONT_MIN ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  KEY_READ ; 
 int /*<<< orphan*/  KEY_WRITE ; 
 int MAXMSG_LENGTH ; 
 scalar_t__ MSGSPEED_MAX ; 
 scalar_t__ MSGSPEED_MIN ; 
 int /*<<< orphan*/  REG_DWORD ; 
 int /*<<< orphan*/  REG_MULTI_SZ ; 
 int /*<<< orphan*/  REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegCreateKeyEx (int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueEx (int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  RegSetValueEx (int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ SPEED_MAX ; 
 scalar_t__ SPEED_MIN ; 
 void* TRUE ; 
 int /*<<< orphan*/  ZeroMemory (scalar_t__*,int) ; 
 scalar_t__* _T (char*) ; 
 scalar_t__ _istascii (scalar_t__) ; 
 int /*<<< orphan*/  free (scalar_t__*) ; 
 scalar_t__ g_fFontBold ; 
 scalar_t__ g_fRandomizeMessages ; 
 scalar_t__ g_nDensity ; 
 scalar_t__ g_nFontSize ; 
 scalar_t__ g_nMatrixSpeed ; 
 scalar_t__ g_nMessageSpeed ; 
 size_t g_nNumMessages ; 
 scalar_t__* g_szFontName ; 
 scalar_t__** g_szMessages ; 
 int /*<<< orphan*/  lstrcpy (scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  lstrcpyn (scalar_t__*,scalar_t__*,int) ; 
 int lstrlen (scalar_t__*) ; 
 scalar_t__* malloc (int) ; 

void LoadSettings()
{
	HKEY hkey;
	LONG value;
	ULONG len;
	TCHAR *hugechar = malloc(4096);
	TCHAR *hptr = hugechar;

	if(hugechar == 0)
		return;

	ZeroMemory(hugechar, 4096);

	RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\Catch22\\Matrix Screen Saver"), 0,
		_T(""), 0, KEY_READ, NULL, &hkey, NULL);

	len = sizeof value;
	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("MessageSpeed"), 0, 0, (BYTE *)&value, &len))
	{
		if(value >= MSGSPEED_MIN && value <= MSGSPEED_MAX)
			g_nMessageSpeed = value;
	}

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("MatrixSpeed"),  0, 0, (BYTE *)&value, &len))
	{
		if(value >= SPEED_MIN && value <= SPEED_MAX)
			g_nMatrixSpeed  = value;
	}

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("Density"),      0, 0, (BYTE *)&value, &len))
	{
		if(value >= DENSITY_MIN && value <= DENSITY_MAX)
			g_nDensity      = value;
	}

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("FontSize"),      0, 0, (BYTE *)&value, &len))
	{
		if(value >= FONT_MIN && value <= FONT_MAX)
			g_nFontSize	 = value;
	}

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("FontBold"),      0, 0, (BYTE *)&value, &len))
		g_fFontBold = (value == 0 ? FALSE : TRUE);

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("Randomize"),      0, 0, (BYTE *)&value, &len))
		g_fRandomizeMessages = (value == 0 ? FALSE : TRUE);

	len = 512;
	if(RegQueryValueEx(hkey, _T("FontName"),  0, 0, (BYTE *)g_szFontName, &len) != ERROR_SUCCESS)
		lstrcpy(g_szFontName, _T("Arial"));

	len = 4096;

	if(ERROR_SUCCESS == RegQueryValueEx(hkey, _T("Messages"),      0, 0 , (BYTE *)hugechar, &len))
	{
		while(len > 0 && *hptr && _istascii(*hptr))
		{
			if(lstrlen(hptr) > 0)
			{
				lstrcpyn(g_szMessages[g_nNumMessages], hptr, MAXMSG_LENGTH);
				++g_nNumMessages;
				hptr += lstrlen(hptr) + 1;
			}
		}
	}
	else
	{
		/* built-in coded message for first run */
		lstrcpyn(g_szMessages[0], _T("ReactOS"), MAXMSG_LENGTH);
		++g_nNumMessages;
	}

	RegCloseKey(hkey);
	free(hugechar);
}

void SaveSettings()
{
	HKEY hkey;
	TCHAR *hugechar = malloc(4096 * sizeof(TCHAR));
	TCHAR *msgptr = hugechar;
	int totallen = 0;
	int i,len;
	LONG value;

	if(hugechar == 0)
		return;

	ZeroMemory(hugechar, 4096 * sizeof(TCHAR));
	msgptr = hugechar;

	RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\Catch22\\Matrix Screen Saver"), 0,
		_T(""), 0, KEY_WRITE, NULL, &hkey, NULL);

	value = g_nMessageSpeed;
	RegSetValueEx(hkey, _T("MessageSpeed"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	value = g_nMatrixSpeed;
	RegSetValueEx(hkey, _T("MatrixSpeed"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	value = g_nDensity;
	RegSetValueEx(hkey, _T("Density"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	value = g_nFontSize;
	RegSetValueEx(hkey, _T("FontSize"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	value = g_fRandomizeMessages;
	RegSetValueEx(hkey, _T("Randomize"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	value = g_fFontBold;
	RegSetValueEx(hkey, _T("FontBold"), 0, REG_DWORD, (BYTE *)&value, sizeof value);

	RegSetValueEx(hkey, _T("FontName"), 0, REG_SZ, (BYTE *)g_szFontName, lstrlen(g_szFontName) * sizeof(TCHAR));

	for(i = 0; i < g_nNumMessages; i++)
	{
		len = lstrlen(g_szMessages[i]);

		if(len > 0 && totallen+len < 4096)
		{
			lstrcpyn(msgptr, g_szMessages[i], 4096-totallen);
			totallen += len + 1;
			msgptr += len + 1;
		}
	}

	//*msgptr = _T('\0');
	totallen++;

	RegSetValueEx(hkey, _T("Messages"), 0, REG_MULTI_SZ, (BYTE *)hugechar, totallen * sizeof(TCHAR));
	RegCloseKey(hkey);

	free(hugechar);
}

