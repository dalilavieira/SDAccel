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
 int /*<<< orphan*/  __buildEnvironment (void*) ; 
 int daylight ; 
 char** environ ; 
 long timezone ; 
 scalar_t__ tzname ; 

void* _get_tzname() {
  return (void*)tzname;
}

int* _get_daylight() {
  return &daylight;
}

long* _get_timezone() {
  return &timezone;
}

char*** _get_environ() {
  return &environ;
}

__attribute__((constructor))
void __emscripten_environ_constructor(void) {
  __buildEnvironment((void*)&environ);
}

