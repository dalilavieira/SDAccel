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
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  iscntrl (int) ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  printf (char*,char*,char*) ; 
 scalar_t__ sprintf (char*,char*,char const) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char const*,size_t) ; 

__attribute__((used)) static char *_escape(const char *s, size_t n) {
  size_t i, j;
  char *res = (char *) malloc(n * 4 + 1);
  for (i = j = 0; s[i] != '\0' && i < n; i++) {
    if (!iscntrl((int) s[i])) {
      res[j++] = s[i];
    } else {
      j += sprintf(res + j, "\\x%02x", s[i]);
    }
  }
  res[j] = '\0';
  return res;
}

void _strfail(const char *a, const char *e, int len) {
  char *ae, *ee;
  if (len < 0) {
    len = strlen(a);
    if (strlen(e) > (size_t) len) len = strlen(e);
  }
  ae = _escape(a, len);
  ee = _escape(e, len);
  printf("Expected: %s\nActual  : %s\n", ee, ae);
  free(ae);
  free(ee);
}

int _assert_streq(const char *actual, const char *expected) {
  if (strcmp(actual, expected) != 0) {
    _strfail(actual, expected, -1);
    return 0;
  }
  return 1;
}

int _assert_streq_nz(const char *actual, const char *expected) {
  size_t n = strlen(expected);
  if (strncmp(actual, expected, n) != 0) {
    _strfail(actual, expected, n);
    return 0;
  }
  return 1;
}

