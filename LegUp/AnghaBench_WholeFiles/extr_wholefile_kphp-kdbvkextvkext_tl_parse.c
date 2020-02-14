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
struct TYPE_2__ {char* error; scalar_t__ errnum; } ;

/* Variables and functions */
 double do_rpc_fetch_double (char**) ; 
 int /*<<< orphan*/  do_rpc_fetch_eof (char**) ; 
 int do_rpc_fetch_get_pos (char**) ; 
 int do_rpc_fetch_int (char**) ; 
 long long do_rpc_fetch_long (char**) ; 
 int /*<<< orphan*/  do_rpc_fetch_set_pos (int,char**) ; 
 int do_rpc_fetch_string (char**) ; 
 char* emalloc (int) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 void* strdup (char const*) ; 
 TYPE_1__ tl ; 

__attribute__((used)) static __inline__ unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

void tl_parse_init (void) {
  if (tl.error) {
    free (tl.error);
    tl.error = 0;
  }
  tl.errnum = 0;
}

int tl_parse_int (void) {
  if (tl.error) { return -1; }
  return do_rpc_fetch_int (&tl.error);
}

long long tl_parse_long (void) {
  if (tl.error) { return -1; }
  return do_rpc_fetch_long (&tl.error);
}

double tl_parse_double (void) {
  if (tl.error) { return -1; }
  return do_rpc_fetch_double (&tl.error);
}

int tl_parse_string (char **s) {
  if (tl.error) { return -1; }
  int len = do_rpc_fetch_string (s);
  if (len < 0) {
    tl.error = strdup (*s);
    *s = 0;
    return -1;
  }
  char *t = malloc (len + 1);
  memcpy (t, *s, len);
  t[len] = 0;
  *s = t;
  return len;
}

int tl_eparse_string (char **s) {
  if (tl.error) { return -1; }
  int len = do_rpc_fetch_string (s);
  if (len < 0) {
    tl.error = strdup (*s);
    *s = 0;
    return -1;
  }
  char *t = emalloc (len + 1);
  memcpy (t, *s, len);
  t[len] = 0;
  *s = t;
  return len;
}

char *tl_parse_error (void) {
  return tl.error;
}

void tl_set_error (const char *error) {
  if (tl.error) { return; }
  tl.error = strdup (error);
}

void tl_parse_end (void) {
  if (tl.error) { return; }
  if (!do_rpc_fetch_eof (&tl.error)) {
    tl_set_error ("Extra data");
  }
}

int tl_parse_save_pos (void) {
  char *error = 0;
  int r = do_rpc_fetch_get_pos (&error);
  if (error) {
    tl_set_error (error);
    return 0;
  } else {
    return r;
  }
}

int tl_parse_restore_pos (int pos) {
  char *error = 0;
  do_rpc_fetch_set_pos (pos, &error);
  if (error) {  
    tl_set_error (error);
    return 0;
  } else {
    return 1;
  }
}

void tl_parse_clear_error (void) {
  if (tl.error) {
    free (tl.error);
    tl.error = 0;
  }
}

