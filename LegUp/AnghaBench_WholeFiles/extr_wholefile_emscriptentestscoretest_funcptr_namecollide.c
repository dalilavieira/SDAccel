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
 void do_call (void (*) (char const*),char const*) ; 
 int /*<<< orphan*/  puts (char const*) ; 
 void stub1 (char const*) ; 

void do_print(const char *str) {
  if (!str) do_call(NULL, "delusion");
  if ((int)str == -1) do_print(str + 10);
  puts("====");
  puts(str);
  puts("====");
}

void do_call(void (*puts)(const char *), const char *str) {
  if (!str) do_print("confusion");
  if ((int)str == -1) do_call(NULL, str - 10);
  (*puts)(str);
}

int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    do_call(i != 10 ? do_print : NULL, i != 15 ? "waka waka" : NULL);
  }
  return 0;
}

