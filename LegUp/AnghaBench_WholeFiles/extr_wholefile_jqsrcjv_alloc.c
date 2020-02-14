#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  jv_nomem_handler_f ;
typedef  int /*<<< orphan*/  jv ;
struct TYPE_2__ {void* data; int /*<<< orphan*/  handler; } ;

/* Variables and functions */
 scalar_t__ JV_KIND_INVALID ; 
 int /*<<< orphan*/  abort () ; 
 void* calloc (size_t,size_t) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ jv_get_kind (int /*<<< orphan*/ ) ; 
 char jv_mem_uninitialised ; 
 void* malloc (int) ; 
 TYPE_1__ nomem_handler ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stderr ; 
 char* strdup (char const*) ; 

__attribute__((used)) static int jv_is_valid(jv x) { return jv_get_kind(x) != JV_KIND_INVALID; }

__attribute__((used)) static void jv_mem_invalidate(void* mem, size_t n) {
#ifndef NDEBUG
  char* m = mem;
  while (n--) *m++ ^= jv_mem_uninitialised ^ jv_mem_uninitialised;
#endif
}

void jv_nomem_handler(jv_nomem_handler_f handler, void *data) {
  nomem_handler.handler = handler;
  nomem_handler.data = data;
}

__attribute__((used)) static void memory_exhausted() {
  fprintf(stderr, "jq: error: cannot allocate memory\n");
  abort();
}

void* jv_mem_alloc(size_t sz) {
  void* p = malloc(sz);
  if (!p) {
    memory_exhausted();
  }
  return p;
}

void* jv_mem_alloc_unguarded(size_t sz) {
  return malloc(sz);
}

void* jv_mem_calloc(size_t nemb, size_t sz) {
  void* p = calloc(nemb, sz);
  if (!p) {
    memory_exhausted();
  }
  return p;
}

void* jv_mem_calloc_unguarded(size_t nemb, size_t sz) {
  return calloc(nemb, sz);
}

char* jv_mem_strdup(const char *s) {
  char *p = strdup(s);
  if (!p) {
    memory_exhausted();
  }
  return p;
}

char* jv_mem_strdup_unguarded(const char *s) {
  return strdup(s);
}

void jv_mem_free(void* p) {
  free(p);
}

void* jv_mem_realloc(void* p, size_t sz) {
  p = realloc(p, sz);
  if (!p) {
    memory_exhausted();
  }
  return p;
}

__attribute__((constructor)) void jv_mem_uninit_setup(){
  // ignore warning that this reads uninitialized memory - that's the point!
#ifndef __clang_analyzer__
  char* p = malloc(1);
  jv_mem_uninitialised = *p;
  free(p);
#endif
}

