#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_11__ {scalar_t__ name; } ;
typedef  TYPE_1__ luaL_Reg ;
struct TYPE_12__ {int lvl; int /*<<< orphan*/ * L; int /*<<< orphan*/  buffer; int /*<<< orphan*/  p; } ;
typedef  TYPE_2__ luaL_Buffer ;
typedef  scalar_t__ lu_mem ;
struct TYPE_13__ {size_t memlimit; scalar_t__ totalbytes; scalar_t__ gcstate; int egcmode; } ;
typedef  TYPE_3__ global_State ;
struct TYPE_15__ {char const* buff; int /*<<< orphan*/  f; scalar_t__ extraline; } ;
struct TYPE_14__ {size_t size; char const* s; } ;
typedef  TYPE_4__ LoadS ;
typedef  TYPE_5__ LoadFSF ;

/* Variables and functions */
 int EGC_ALWAYS ; 
 int EGC_ON_ALLOC_FAILURE ; 
 int EGC_ON_MEM_LIMIT ; 
 TYPE_3__* G (int /*<<< orphan*/ *) ; 
 scalar_t__ GCSpause ; 
 scalar_t__ LIMIT ; 
 int LUA_ERRFILE ; 
 size_t bufflen (TYPE_2__*) ; 
 int /*<<< orphan*/  c_free (void*) ; 
 int /*<<< orphan*/  is_block_gc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaC_fullgc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaC_step (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_typerror (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_concat (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushfstring (int /*<<< orphan*/ *,char*,char const*,char const*) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  lua_remove (int /*<<< orphan*/ *,int) ; 
 size_t lua_strlen (int /*<<< orphan*/ *,int) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_typename (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luai_writestringerror (char*,char*) ; 
 size_t system_get_free_heap_size () ; 
 scalar_t__ this_realloc (void*,size_t,size_t) ; 
 scalar_t__ vfs_eof (int /*<<< orphan*/ ) ; 
 size_t vfs_read (int /*<<< orphan*/ ,char const*,int) ; 

__attribute__((used)) static void tag_error (lua_State *L, int narg, int tag) {
  luaL_typerror(L, narg, lua_typename(L, tag));
}

__attribute__((used)) static int libsize (const luaL_Reg *l) {
  int size = 0;
  for (; l->name; l++) size++;
  return size;
}

__attribute__((used)) static int emptybuffer (luaL_Buffer *B) {
  size_t l = bufflen(B);
  if (l == 0) return 0;  /* put nothing on stack */
  else {
    lua_pushlstring(B->L, B->buffer, l);
    B->p = B->buffer;
    B->lvl++;
    return 1;
  }
}

__attribute__((used)) static void adjuststack (luaL_Buffer *B) {
  if (B->lvl > 1) {
    lua_State *L = B->L;
    int toget = 1;  /* number of levels to concat */
    size_t toplen = lua_strlen(L, -1);
    do {
      size_t l = lua_strlen(L, -(toget+1));
      if (B->lvl - toget + 1 >= LIMIT || toplen > l) {
        toplen += l;
        toget++;
      }
      else break;
    } while (toget < B->lvl);
    lua_concat(L, toget);
    B->lvl = B->lvl - toget + 1;
  }
}

__attribute__((used)) static const char *getFSF (lua_State *L, void *ud, size_t *size) {
  LoadFSF *lf = (LoadFSF *)ud;
  (void)L;

  if (L == NULL && size == NULL) // Direct mode check
    return NULL;

  if (lf->extraline) {
    lf->extraline = 0;
    *size = 1;
    return "\n";
  }

  if (vfs_eof(lf->f)) return NULL;
  *size = vfs_read(lf->f, lf->buff, sizeof(lf->buff));

  return (*size > 0) ? lf->buff : NULL;
}

__attribute__((used)) static int errfsfile (lua_State *L, const char *what, int fnameindex) {
  const char *filename = lua_tostring(L, fnameindex) + 1;
  lua_pushfstring(L, "cannot %s %s", what, filename);
  lua_remove(L, fnameindex);
  return LUA_ERRFILE;
}

__attribute__((used)) static const char *getS (lua_State *L, void *ud, size_t *size) {
  LoadS *ls = (LoadS *)ud;
  (void)L;
  if (L == NULL && size == NULL) // direct mode check
    return NULL;
  if (ls->size == 0) return NULL;
  *size = ls->size;
  ls->size = 0;
  return ls->s;
}

__attribute__((used)) static int l_check_memlimit(lua_State *L, size_t needbytes) {
  global_State *g = G(L);
  int cycle_count = 0;
  lu_mem limit = g->memlimit - needbytes;
  /* don't allow allocation if it requires more memory then the total limit. */
  if (needbytes > g->memlimit) return 1;
  /* make sure the GC is not disabled. */
  if (!is_block_gc(L)) {
    while (g->totalbytes >= limit) {
      /* only allow the GC to finished atleast 1 full cycle. */
      if (g->gcstate == GCSpause && ++cycle_count > 1) break;
      luaC_step(L);
    }
  }
  return (g->totalbytes >= limit) ? 1 : 0;
}

__attribute__((used)) static void *l_alloc (void *ud, void *ptr, size_t osize, size_t nsize) {
  lua_State *L = (lua_State *)ud;
  int mode = L == NULL ? 0 : G(L)->egcmode;
  void *nptr;

  if (nsize == 0) {
#ifdef DEBUG_ALLOCATOR
    return (void *)this_realloc(ptr, osize, nsize);
#else
    c_free(ptr);
    return NULL;
#endif
  }
  if (L != NULL && (mode & EGC_ALWAYS)) /* always collect memory if requested */
    luaC_fullgc(L);
#ifndef LUA_CROSS_COMPILER
  if (L != NULL && (mode & EGC_ON_MEM_LIMIT) && G(L)->memlimit < 0 &&
      (system_get_free_heap_size() < (-G(L)->memlimit)))
    luaC_fullgc(L);
#endif
  if(nsize > osize && L != NULL) {
#if defined(LUA_STRESS_EMERGENCY_GC)
    luaC_fullgc(L);
#endif
    if(G(L)->memlimit > 0 && (mode & EGC_ON_MEM_LIMIT) && l_check_memlimit(L, nsize - osize))
      return NULL;
  }
  nptr = (void *)this_realloc(ptr, osize, nsize);
  if (nptr == NULL && L != NULL && (mode & EGC_ON_ALLOC_FAILURE)) {
    luaC_fullgc(L); /* emergency full collection. */
    nptr = (void *)this_realloc(ptr, osize, nsize); /* try allocation again */
  }
  return nptr;
}

__attribute__((used)) static int panic (lua_State *L) {
  (void)L;  /* to avoid warnings */
#if defined(LUA_USE_STDIO)
  c_fprintf(c_stderr, "PANIC: unprotected error in call to Lua API (%s)\n",
                   lua_tostring(L, -1));
#else
  luai_writestringerror("PANIC: unprotected error in call to Lua API (%s)\n",
                   lua_tostring(L, -1));
#endif
  while (1) {}
  return 0;
}

