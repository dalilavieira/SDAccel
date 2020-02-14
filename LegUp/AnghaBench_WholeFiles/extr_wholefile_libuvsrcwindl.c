#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
struct TYPE_8__ {char const* errmsg; int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_lib_t ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  LPSTR ;
typedef  scalar_t__ DWORD_PTR ;
typedef  scalar_t__ DWORD ;
typedef  char CHAR ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CP_UTF8 ; 
 scalar_t__ ERROR_BAD_EXE_FORMAT ; 
 scalar_t__ ERROR_MUI_FILE_NOT_FOUND ; 
 scalar_t__ ERROR_RESOURCE_TYPE_NOT_FOUND ; 
 int FORMAT_MESSAGE_ALLOCATE_BUFFER ; 
 int FORMAT_MESSAGE_ARGUMENT_ARRAY ; 
 int FORMAT_MESSAGE_FROM_STRING ; 
 int FORMAT_MESSAGE_FROM_SYSTEM ; 
 int FORMAT_MESSAGE_IGNORE_INSERTS ; 
 scalar_t__ FormatMessageA (int,char const*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeLibrary (int /*<<< orphan*/ *) ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ GetProcAddress (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  LANG_ENGLISH ; 
 int /*<<< orphan*/  LOAD_WITH_ALTERED_SEARCH_PATH ; 
 int /*<<< orphan*/ * LoadLibraryExW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LocalFree (char*) ; 
 int /*<<< orphan*/  MAKELANGID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUBLANG_ENGLISH_US ; 
 scalar_t__ strstr (char*,char*) ; 
static  int uv__dlerror (TYPE_1__*,char const*,scalar_t__) ; 

int uv_dlopen(const char* filename, uv_lib_t* lib) {
  WCHAR filename_w[32768];

  lib->handle = NULL;
  lib->errmsg = NULL;

  if (!MultiByteToWideChar(CP_UTF8,
                           0,
                           filename,
                           -1,
                           filename_w,
                           ARRAY_SIZE(filename_w))) {
    return uv__dlerror(lib, filename, GetLastError());
  }

  lib->handle = LoadLibraryExW(filename_w, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
  if (lib->handle == NULL) {
    return uv__dlerror(lib, filename, GetLastError());
  }

  return 0;
}

void uv_dlclose(uv_lib_t* lib) {
  if (lib->errmsg) {
    LocalFree((void*)lib->errmsg);
    lib->errmsg = NULL;
  }

  if (lib->handle) {
    /* Ignore errors. No good way to signal them without leaking memory. */
    FreeLibrary(lib->handle);
    lib->handle = NULL;
  }
}

int uv_dlsym(uv_lib_t* lib, const char* name, void** ptr) {
  /* Cast though integer to suppress pedantic warning about forbidden cast. */
  *ptr = (void*)(uintptr_t) GetProcAddress(lib->handle, name);
  return uv__dlerror(lib, "", *ptr ? 0 : GetLastError());
}

const char* uv_dlerror(const uv_lib_t* lib) {
  return lib->errmsg ? lib->errmsg : "no error";
}

__attribute__((used)) static void uv__format_fallback_error(uv_lib_t* lib, int errorno){
  static const CHAR fallback_error[] = "error: %1!d!";
  DWORD_PTR args[1];
  args[0] = (DWORD_PTR) errorno;

  FormatMessageA(FORMAT_MESSAGE_FROM_STRING |
                 FORMAT_MESSAGE_ARGUMENT_ARRAY |
                 FORMAT_MESSAGE_ALLOCATE_BUFFER,
                 fallback_error, 0, 0,
                 (LPSTR) &lib->errmsg,
                 0, (va_list*) args);
}

__attribute__((used)) static int uv__dlerror(uv_lib_t* lib, const char* filename, DWORD errorno) {
  DWORD_PTR arg;
  DWORD res;
  char* msg;

  if (lib->errmsg) {
    LocalFree(lib->errmsg);
    lib->errmsg = NULL;
  }

  if (errorno == 0)
    return 0;

  res = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                       FORMAT_MESSAGE_FROM_SYSTEM |
                       FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorno,
                       MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                       (LPSTR) &lib->errmsg, 0, NULL);

  if (!res && (GetLastError() == ERROR_MUI_FILE_NOT_FOUND ||
               GetLastError() == ERROR_RESOURCE_TYPE_NOT_FOUND)) {
    res = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                         FORMAT_MESSAGE_FROM_SYSTEM |
                         FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorno,
                         0, (LPSTR) &lib->errmsg, 0, NULL);
  }

  if (res && errorno == ERROR_BAD_EXE_FORMAT && strstr(lib->errmsg, "%1")) {
    msg = lib->errmsg;
    lib->errmsg = NULL;
    arg = (DWORD_PTR) filename;
    res = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                         FORMAT_MESSAGE_ARGUMENT_ARRAY |
                         FORMAT_MESSAGE_FROM_STRING,
                         msg,
                         0, 0, (LPSTR) &lib->errmsg, 0, (va_list*) &arg);
    LocalFree(msg);
  }

  if (!res)
    uv__format_fallback_error(lib, errorno);

  return -1;
}

