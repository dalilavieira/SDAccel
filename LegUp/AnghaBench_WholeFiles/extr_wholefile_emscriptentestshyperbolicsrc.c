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
 double acosh (double) ; 
 double asinh (double) ; 
 double atanh (double) ; 
 double cosh (double) ; 
 int /*<<< orphan*/  isnan (double) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 double sinh (double) ; 
 double tanh (double) ; 

void printCanonicalizedNan(char* funcName, double value) {
  if (!isnan(value)) {
    printf("%s: %g\n", funcName, value);
  } else {
    printf("%s: nan\n", funcName);
  }
}

int main() {
  double i;
  for (i = -10; i < 10; i += 0.125) {
    printf("i: %g\n", i);
    printf("sinh: %g\n", sinh(i));
    printf("cosh: %g\n", cosh(i));
    printf("tanh: %g\n", tanh(i));
    printCanonicalizedNan("asinh", asinh(i));
    printCanonicalizedNan("acosh", acosh(i));
    printCanonicalizedNan("atanh", atanh(i));
    printf("\n");
  }
  return 0;
}

