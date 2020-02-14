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
struct TYPE_8__ {int* mem; int mx; int n; int rn; } ;
typedef  TYPE_1__ vector ;

/* Variables and functions */
 int O_CREAT ; 
 int O_RDONLY ; 
 int O_RDWR ; 
 int O_TRUNC ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  assert (int) ; 
 void* calloc (size_t,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int f_inited ; 
 void* fcurr ; 
 int* fd ; 
 char** fnames ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 void free (void*) ; 
 scalar_t__* fsize ; 
 scalar_t__ lseek (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* malloc (size_t) ; 
 size_t memory_used ; 
 int open (char*,int,int) ; 
 char* progname ; 
 int rand () ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ verbosity ; 

void *qmalloc (size_t x) {
  memory_used += x;
  void *res = malloc (x);
  assert (x == 0 || res != NULL);
  return res;
}

void *qmalloc0 (size_t x) {
  memory_used += x;
  void *res = calloc (x, 1);
  assert (x == 0 || res != NULL);
  return res;
}

void *qrealloc (void *p, size_t x, size_t old) {
  memory_used += x - old;
  void *res = realloc (p, x);
  assert (x == 0 || res != NULL);
  return res;
}

long get_memory_used (void) {
  return memory_used;
}

void qfree (void *p, size_t x) {
  memory_used -= x;
  return free (p);
}

void vct_init (vector *v) {
  v->mem = qmalloc (sizeof (int));
  v->mx = 1, v->n = 0;
  v->rn = 0;
}

void vct_add (vector *v, int x) {
  if (v->mx == v->n) {
    v->mem = qrealloc (v->mem, sizeof (int) * v->mx * 2, sizeof (int) * v->mx);
    v->mx *= 2;
  }
  v->mem[v->n++] = x;
}

void vct_add_lim (vector *v, int x, int lim)  {
  if (v->mx == v->n && v->mx != lim) {
    int new_len = v->mx * 2;
    if (new_len > lim) {
      new_len = lim;
    }
    v->mem = qrealloc (v->mem, sizeof (int) * new_len, sizeof (int) * v->mx);
    v->mx = new_len;
  }

  v->rn++;
  if (v->n < lim) {
    v->mem[v->n++] = x;
  } else {
    int i = rand() % v->rn;
    if (i < v->n) {
      v->mem[i] = x;
    }
  }
}

void vct_free (vector *v) {
  qfree (v->mem, sizeof (int) * v->mx);
  v->mx = 0, v->n = 0;
}

int vct_back (vector *v) {
  if (v->n) {
    return v->mem[v->n - 1];
  }
  return 0;
}

void vct_set_add (vector *v, int val) {
  if (vct_back (v) != val) {
    vct_add (v, val);
  }
}

void init_files (int fn) {
  assert (!f_inited);
  fnames = qmalloc0 (sizeof (char *) * fn);
  fd = qmalloc0 (sizeof (int) * fn);
  fsize = qmalloc0 (sizeof (long long) * fn);
  fcurr = qmalloc0 (sizeof (long long) * fn);
  f_inited = fn;
}

int open_file (int x, char *fname, int creat) {
  assert (f_inited);
  assert (0 <= x && x < f_inited);

  //fprintf (stderr, "open %d %s %d\n", x, fname, creat);

  fnames[x] = fname;
  int options;
  if (creat > 0) {
    options = O_RDWR | O_CREAT;
    if (creat == 2) {
      options |= O_TRUNC;
    }
  } else {
    options = O_RDONLY;
  }

  fd[x] = open (fname, options, 0600);
  if (creat < 0 && fd[x] < 0) {
    if (fd[x] < 0) {
      fprintf (stderr, "%s: cannot open %s: %m\n", progname, fname);
    }
    return -1;
  }
  if (fd[x] < 0) {
    fprintf (stderr, "%s: cannot open %s: %m\n", progname, fname);
    exit (1);
  }
  fsize[x] = lseek (fd[x], 0, SEEK_END);
  if (fsize[x] < 0) {
    fprintf (stderr, "%s: cannot seek %s: %m\n", progname, fname);
    exit (2);
  }
  lseek (fd[x], 0, SEEK_SET);
  if (verbosity) {
    fprintf (stderr, "opened file %s, fd=%d, size=%lld\n", fname, fd[x], fsize[x]);
  }
  return fd[x];
}

