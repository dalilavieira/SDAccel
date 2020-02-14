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
 int /*<<< orphan*/  MAJOR ; 
 scalar_t__ MINOR ; 
 scalar_t__ abs (int) ; 
 scalar_t__ alloca (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  jb ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  setjmp (int /*<<< orphan*/ ) ; 
 scalar_t__ temp ; 

__attribute__((noinline)) int get_stack()
{
  int dummy;
  int ptr = (int)&dummy;
  return ptr;
}

__attribute__((noinline)) void bar()
{
  printf("before longjmp: %d\n", get_stack());
  longjmp(jb, 1);
}

__attribute__((noinline)) void foo()
{
  temp = alloca(MAJOR);
  printf("major allocation at: %d\n", (int)temp);
#ifdef __asmjs__
  // asmjs stack grows up, but wasm backend stack grows down, so the delta
  // between get_stack() and temp isn't related to the size of the alloca for
  // wasm backend
  assert(abs(get_stack() - (int)temp) >= MAJOR);
#endif
  bar();
}

int main()
{
  int before = get_stack();
  printf("before setjmp: %d\n", before);

  if (!setjmp(jb)) {
    foo();
    return 0;
  } else {
    int after = get_stack();
    printf("before setjmp: %d\n", after);
    assert(abs(after - before) < MINOR); // stack has been unwound (but may have minor printf changes
    printf("ok.\n");
    return 1;
  }
}

