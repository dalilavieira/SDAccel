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
typedef  int /*<<< orphan*/  AAC_RENAME ;

/* Variables and functions */
 int /*<<< orphan*/  WRITE_ARRAY (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_cbrt_tab ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  uint32_t ; 

__attribute__((used)) static inline void write_fileheader(void)
{
    printf("/* This file was automatically generated. */\n");
    printf("#include <stdint.h>\n");
}

int main(void)
{
    AAC_RENAME(ff_cbrt_tableinit)();

    write_fileheader();

#if USE_FIXED
    WRITE_ARRAY("const", uint32_t, ff_cbrt_tab_fixed);
#else
    WRITE_ARRAY("const", uint32_t, ff_cbrt_tab);
#endif

    return 0;
}

