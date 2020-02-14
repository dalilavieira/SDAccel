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
 int /*<<< orphan*/  WRITE_ARRAY (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alaw2linear ; 
 int /*<<< orphan*/  build_xlaw_table (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  linear_to_alaw ; 
 int /*<<< orphan*/  linear_to_ulaw ; 
 int /*<<< orphan*/  linear_to_vidc ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  uint8_t ; 
 int /*<<< orphan*/  ulaw2linear ; 
 int /*<<< orphan*/  vidc2linear ; 

__attribute__((used)) static void pcm_alaw_tableinit(void)
{
    build_xlaw_table(linear_to_alaw, alaw2linear, 0xd5);
}

__attribute__((used)) static void pcm_ulaw_tableinit(void)
{
    build_xlaw_table(linear_to_ulaw, ulaw2linear, 0xff);
}

__attribute__((used)) static void pcm_vidc_tableinit(void)
{
    build_xlaw_table(linear_to_vidc, vidc2linear, 0xff);
}

__attribute__((used)) static inline void write_fileheader(void)
{
    printf("/* This file was automatically generated. */\n");
    printf("#include <stdint.h>\n");
}

int main(void)
{
    pcm_alaw_tableinit();
    pcm_ulaw_tableinit();
    pcm_vidc_tableinit();

    write_fileheader();

    WRITE_ARRAY("static const", uint8_t, linear_to_alaw);
    WRITE_ARRAY("static const", uint8_t, linear_to_ulaw);
    WRITE_ARRAY("static const", uint8_t, linear_to_vidc);

    return 0;
}

