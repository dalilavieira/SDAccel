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

char* strncat( char* d, const char* s, size_t c ) {
  char* tmp = d;

  if ( c > 0 ) {
    while ( *d ) d++;
    while ( ( *d++ = *s++ ) ) {
      if ( --c == 0 ) {
        *d = 0;
        break;
      }
    }
  }

  return tmp;
}

