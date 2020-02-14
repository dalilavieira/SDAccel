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
typedef  scalar_t__ int64 ;

/* Variables and functions */
 int JSDOUBLE_HI32_SIGNBIT ; 
 int /*<<< orphan*/  printf (char*,int,int,int,int) ; 

bool JSDOUBLE_IS_NEGZERO(double d) {
  union {
    struct {
      unsigned int lo, hi;
    } s;
    double d;
  } x;
  if (d != 0) return false;
  x.d = d;
  return (x.s.hi & JSDOUBLE_HI32_SIGNBIT) != 0;
}

bool JSINT64_IS_NEGZERO(int64 l) {
  union {
    int64 i;
    double d;
  } x;
  if (l != 0) return false;
  x.i = l;
  return x.d == -0;
}

int main(int argc, char* argv[]) {
  printf("*%d,%d,%d,%d*\n", JSDOUBLE_IS_NEGZERO(0), JSDOUBLE_IS_NEGZERO(-0),
         JSDOUBLE_IS_NEGZERO(-1), JSDOUBLE_IS_NEGZERO(+1));
  printf("*%d,%d,%d,%d*\n", JSINT64_IS_NEGZERO(0), JSINT64_IS_NEGZERO(-0),
         JSINT64_IS_NEGZERO(-1), JSINT64_IS_NEGZERO(+1));
  return 0;
}

