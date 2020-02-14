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

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 char* _ (char*) ; 
 void* calloc (size_t,size_t) ; 
 int /*<<< orphan*/  error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 void* realloc (void*,size_t) ; 
 scalar_t__ xalloc_oversized (size_t,size_t) ; 
 int /*<<< orphan*/  xmalloc_exit_failure ; 

void
xalloc_die ()
{
  error (xmalloc_exit_failure, 0, _("memory exhausted"));
  /* _Noreturn cannot be given to error, since it may return if
     its first argument is 0.  To help compilers understand the
     xalloc_die does terminate, call exit. */
  exit (EXIT_FAILURE);
}

__attribute__((used)) static void *
fixup_null_alloc (size_t n)
{
  void *p;

  p = NULL;
  if (n == 0)
    p = malloc ((size_t) 1);
  if (p == NULL)
    xalloc_die ();
  return p;
}

void *
xmalloc (size_t n)
{
  void *p;

  p = malloc (n);
  if (p == NULL)
    p = fixup_null_alloc (n);
  return p;
}

void *
xnmalloc (size_t nmemb, size_t size)
{
  size_t n;
  void *p;

  if (xalloc_oversized (nmemb, size))
    xalloc_die ();
  n = nmemb * size;
  p = malloc (n);
  if (p == NULL)
    p = fixup_null_alloc (n);
  return p;
}

void *
xzalloc (size_t size)
{
  void *p;

  p = xmalloc (size);
  memset (p, 0, size);
  return p;
}

void *
xcalloc (size_t n, size_t s)
{
  void *p;

  p = calloc (n, s);
  if (p == NULL)
    p = fixup_null_alloc (n);
  return p;
}

void *
xrealloc (void *p, size_t n)
{
  if (p == NULL)
    return xmalloc (n);
  p = realloc (p, n);
  if (p == NULL)
    p = fixup_null_alloc (n);
  return p;
}

