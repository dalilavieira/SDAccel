#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char const* errmsg; int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_lib_t ;

/* Variables and functions */
 int /*<<< orphan*/  RTLD_LAZY ; 
 int /*<<< orphan*/  dlclose (int /*<<< orphan*/ *) ; 
 char* dlerror () ; 
 int /*<<< orphan*/ * dlopen (char const*,int /*<<< orphan*/ ) ; 
 void* dlsym (int /*<<< orphan*/ *,char const*) ; 
static  int uv__dlerror (TYPE_1__*) ; 
 int /*<<< orphan*/  uv__free (char const*) ; 
 char const* uv__strdup (char const*) ; 

int uv_dlopen(const char* filename, uv_lib_t* lib) {
  dlerror(); /* Reset error status. */
  lib->errmsg = NULL;
  lib->handle = dlopen(filename, RTLD_LAZY);
  return lib->handle ? 0 : uv__dlerror(lib);
}

void uv_dlclose(uv_lib_t* lib) {
  uv__free(lib->errmsg);
  lib->errmsg = NULL;

  if (lib->handle) {
    /* Ignore errors. No good way to signal them without leaking memory. */
    dlclose(lib->handle);
    lib->handle = NULL;
  }
}

int uv_dlsym(uv_lib_t* lib, const char* name, void** ptr) {
  dlerror(); /* Reset error status. */
  *ptr = dlsym(lib->handle, name);
  return uv__dlerror(lib);
}

const char* uv_dlerror(const uv_lib_t* lib) {
  return lib->errmsg ? lib->errmsg : "no error";
}

__attribute__((used)) static int uv__dlerror(uv_lib_t* lib) {
  const char* errmsg;

  uv__free(lib->errmsg);

  errmsg = dlerror();

  if (errmsg) {
    lib->errmsg = uv__strdup(errmsg);
    return -1;
  }
  else {
    lib->errmsg = NULL;
    return 0;
  }
}

