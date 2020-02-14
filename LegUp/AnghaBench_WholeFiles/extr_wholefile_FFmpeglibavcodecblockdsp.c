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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void clear_block_c(int16_t *block)
{
    memset(block, 0, sizeof(int16_t) * 64);
}

__attribute__((used)) static void clear_blocks_c(int16_t *blocks)
{
    memset(blocks, 0, sizeof(int16_t) * 6 * 64);
}

__attribute__((used)) static void fill_block16_c(uint8_t *block, uint8_t value, ptrdiff_t line_size,
                           int h)
{
    int i;

    for (i = 0; i < h; i++) {
        memset(block, value, 16);
        block += line_size;
    }
}

__attribute__((used)) static void fill_block8_c(uint8_t *block, uint8_t value, ptrdiff_t line_size,
                          int h)
{
    int i;

    for (i = 0; i < h; i++) {
        memset(block, value, 8);
        block += line_size;
    }
}

