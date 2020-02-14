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
 void* calloc (size_t,int) ; 
 void free (void*) ; 
 int /*<<< orphan*/  good_string_to_utf8 (unsigned char*,int*) ; 
 void* malloc (size_t) ; 
 size_t memory_used ; 
 void* realloc (void*,size_t) ; 
 int remove_diacritics (int) ; 

__attribute__((used)) static inline int get_char_utf8 (unsigned int *x, const char *s) {
#define CHECK(condition) if (!(condition)) {*x = 0xFFFFFFFF; return -1;}
  int a = (unsigned char)s[0];
  if ((a & 0x80) == 0) {
    *x = a;
    return (a != 0);
  }

  CHECK ((a & 0x40) != 0);

  int b = (unsigned char)s[1];
  CHECK((b & 0xc0) == 0x80);
  if ((a & 0x20) == 0) {
    CHECK((a & 0x1e) > 0);
    *x = (((a & 0x1f) << 6) | (b & 0x3f));
    return 2;
  }

  int c = (unsigned char)s[2];
  CHECK((c & 0xc0) == 0x80);
  if ((a & 0x10) == 0) {
    CHECK(((a & 0x0f) | (b & 0x20)) > 0);
    *x = (((a & 0x0f) << 12) | ((b & 0x3f) << 6) | (c & 0x3f));
    return 3;
  }

  int d = (unsigned char)s[3];
  CHECK((d & 0xc0) == 0x80);
  if ((a & 0x08) == 0) {
    CHECK(((a & 0x07) | (b & 0x30)) > 0);
    *x = (((a & 0x07) << 18) | ((b & 0x3f) << 12) | ((c & 0x3f) << 6) | (d & 0x3f));
    return 4;
  }
  
  int e = (unsigned char)s[4];
  CHECK((e & 0xc0) == 0x80);
  if ((a & 0x04) == 0) {
    CHECK(((a & 0x03) | (b & 0x38)) > 0);
    *x = (((a & 0x03) << 24) | ((b & 0x3f) << 18) | ((c & 0x3f) << 12) | ((d & 0x3f) << 6) | (e & 0x3f));
    return 5;
  }
  
  int f = (unsigned char)s[5];
  CHECK((f & 0xc0) == 0x80);
  if ((a & 0x02) == 0) {
    CHECK(((a & 0x01) | (b & 0x3c)) > 0);
    *x = (((a & 0x01) << 30) | ((b & 0x3f) << 24) | ((c & 0x3f) << 18) | ((d & 0x3f) << 12) | ((e & 0x3f) << 6) | (f & 0x3f));
    return 6;
  }

  CHECK(0);
#undef CHECK
}

__attribute__((used)) static inline int put_char_utf8 (unsigned int x, char *s) {
  if (x <= 0x7f) {
    s[0] = x;
    return 1;
  } else if (x <= 0x7ff) {
    s[0] = ((x >>  6) | 0xc0) & 0xdf;
    s[1] = ((x      ) | 0x80) & 0xbf;
    return 2;
  } else if (x <= 0xffff) {
    s[0] = ((x >> 12) | 0xe0) & 0xef;
    s[1] = ((x >>  6) | 0x80) & 0xbf;
    s[2] = ((x      ) | 0x80) & 0xbf;
    return 3;
  } else if (x <= 0x1fffff) {
    s[0] = ((x >> 18) | 0xf0) & 0xf7;
    s[1] = ((x >> 12) | 0x80) & 0xbf;
    s[2] = ((x >>  6) | 0x80) & 0xbf;
    s[3] = ((x      ) | 0x80) & 0xbf;
    return 4;
  } else {
    //ASSERT(0, "bad output");
  }
  return 0;
}

void *qmalloc (size_t x) {
  memory_used += x;
  return malloc (x);
}

void *qmalloc0 (size_t x) {
  memory_used += x;
  return calloc (x, 1);
}

void *qrealloc (void *p, size_t x, size_t old) {
  memory_used += x - old;
  return realloc (p, x);
}

void qfree (void *p, size_t x) {
  memory_used -= x;
  return free (p);
}

long get_memory_used (void) {
  return memory_used;
}

void bayes_string_to_utf8 (unsigned char *s, int *v) {
  good_string_to_utf8 (s, v);

  int i;
  for (i = 0; v[i]; i++) {
    v[i] = remove_diacritics (v[i]);
  }

/*
  int j;
  for (i = j = 0; v[i]; i++) {
    if (v[i + 1] == '#' && (v[i] == '&' || v[i] == '$')) {
      int r = 0, ti = i;
      if (v[i + 2] != 'x') {
        for (i += 2; v[i] != ';' && v[i]; i++) {
          if ('0' <= v[i] && v[i]<='9') {
            r = r * 10 + v[i] - '0';
          } else {
            break;
          }
        }
      } else {
        for (i += 3; v[i] != ';' && v[i]; i++) {
          if (('0' <= v[i] && v[i]<='9') ||
              ('a' <= v[i] && v[i] <= 'f') ||
              ('A' <= v[i] && v[i] <= 'F')) {
            r = r * 16;
            if (v[i] <= '9') {
              r += v[i] -'0';
            } else if (v[i] <= 'F') {
              r += v[i] -'A' + 10;
            } else {
              r += v[i] -'a' + 10;
            }
          } else {
            break;
          }
        }
      }
      if (r == 0) {
        v[j++] = v[i = ti];
      } else {
        v[j++] = r;
        if (v[i] != ';') {
          i--;
        }
      }
    } else if (v[i] == '%' && '0' <= v[i + 1] && v[i + 1] <= '7' &&
                            (('0' <= v[i + 2] && v[i + 2] <= '9') ||
                             ('a' <= v[i + 2] && v[i + 2] <= 'f') ||
                             ('A' <= v[i + 2] && v[i + 2] <= 'F'))) {
      int r;
      if (v[i + 2] <= '9') {
        r = v[i + 2] -'0';
      } else if (v[i + 2] <= 'F') {
        r = v[i + 2] -'A' + 10;
      } else {
        r = v[i + 2] -'a' + 10;
      }
      r += (v[i + 1] - '0') * 16;
      i += 2;
      v[j++] = r;
    } else {
      v[j++] = v[i];
    }
  }
  v[j++] = 0;*/
}

