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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  jb ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setjmp (int /*<<< orphan*/ ) ; 

__attribute__((noinline)) void foo(int64_t x) {
  printf("foo: %lld.\n", x);
  longjmp(jb, 1);
}

__attribute__((noinline)) int64_t bar() {
  return (uint64_t)-2;
}

int main()
{
  if (!setjmp(jb)) {
    foo((uint64_t)-1);
    return 0;
  } else {
    printf("bar: %lld.\n", bar());
    return 1;
  }
}

