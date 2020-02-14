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
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/ * LPCSTR ;
typedef  int* LPCLSID ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int INT ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/  CLSID ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 scalar_t__ CO_E_CLASSSTRING ; 
 scalar_t__ ERROR_SUCCESS ; 
 int FALSE ; 
 int /*<<< orphan*/  HKEY_CLASSES_ROOT ; 
 scalar_t__ RegQueryValueA (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  TRACE (char*,int const*,int*) ; 
 int lstrlenA (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * strrchrW (int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  wsprintfA (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static HRESULT AVIFILE_CLSIDFromString(LPCSTR idstr, LPCLSID id)
{
  BYTE const *s;
  BYTE *p;
  INT   i;
  BYTE table[256];

  if (!idstr) {
    memset(id, 0, sizeof(CLSID));
    return S_OK;
  }

  /* validate the CLSID string */
  if (lstrlenA(idstr) != 38)
    return CO_E_CLASSSTRING;

  s = (BYTE const*)idstr;
  if ((s[0]!='{') || (s[9]!='-') || (s[14]!='-') || (s[19]!='-') ||
      (s[24]!='-') || (s[37]!='}'))
    return CO_E_CLASSSTRING;

  for (i = 1; i < 37; i++) {
    if ((i == 9) || (i == 14) || (i == 19) || (i == 24))
      continue;
    if (!(((s[i] >= '0') && (s[i] <= '9'))  ||
        ((s[i] >= 'a') && (s[i] <= 'f'))  ||
        ((s[i] >= 'A') && (s[i] <= 'F')))
       )
      return CO_E_CLASSSTRING;
  }

  TRACE("%s -> %p\n", s, id);

  /* quick lookup table */
  memset(table, 0, 256);

  for (i = 0; i < 10; i++)
    table['0' + i] = i;

  for (i = 0; i < 6; i++) {
    table['A' + i] = i+10;
    table['a' + i] = i+10;
  }

  /* in form {XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX} */
  p = (BYTE *) id;

  s++;	/* skip leading brace  */
  for (i = 0; i < 4; i++) {
    p[3 - i] = table[*s]<<4 | table[*(s+1)];
    s += 2;
  }
  p += 4;
  s++;	/* skip - */

  for (i = 0; i < 2; i++) {
    p[1-i] = table[*s]<<4 | table[*(s+1)];
    s += 2;
  }
  p += 2;
  s++;	/* skip - */

  for (i = 0; i < 2; i++) {
    p[1-i] = table[*s]<<4 | table[*(s+1)];
    s += 2;
  }
  p += 2;
  s++;	/* skip - */

  /* these are just sequential bytes */
  for (i = 0; i < 2; i++) {
    *p++ = table[*s]<<4 | table[*(s+1)];
    s += 2;
  }
  s++;	/* skip - */

  for (i = 0; i < 6; i++) {
    *p++ = table[*s]<<4 | table[*(s+1)];
    s += 2;
  }

  return S_OK;
}

__attribute__((used)) static BOOL AVIFILE_GetFileHandlerByExtension(LPCWSTR szFile, LPCLSID lpclsid)
{
  CHAR   szRegKey[25];
  CHAR   szValue[100];
  LPWSTR szExt = strrchrW(szFile, '.');
  LONG   len = ARRAY_SIZE(szValue);

  if (szExt == NULL)
    return FALSE;

  szExt++;

  wsprintfA(szRegKey, "AVIFile\\Extensions\\%.3ls", szExt);
  if (RegQueryValueA(HKEY_CLASSES_ROOT, szRegKey, szValue, &len) != ERROR_SUCCESS)
    return FALSE;

  return (AVIFILE_CLSIDFromString(szValue, lpclsid) == S_OK);
}

