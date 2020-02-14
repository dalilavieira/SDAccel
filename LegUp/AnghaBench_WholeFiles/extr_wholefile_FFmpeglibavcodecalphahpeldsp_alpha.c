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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;

/* Variables and functions */
 int /*<<< orphan*/  put_pixels_axp_asm (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline uint64_t BYTE_VEC(uint64_t x)
{
    x |= x <<  8;
    x |= x << 16;
    x |= x << 32;
    return x;
}

__attribute__((used)) static inline uint64_t WORD_VEC(uint64_t x)
{
    x |= x << 16;
    x |= x << 32;
    return x;
}

__attribute__((used)) static inline uint64_t avg2_no_rnd(uint64_t a, uint64_t b)
{
    return (a & b) + (((a ^ b) & BYTE_VEC(0xfe)) >> 1);
}

__attribute__((used)) static inline uint64_t avg2(uint64_t a, uint64_t b)
{
    return (a | b) - (((a ^ b) & BYTE_VEC(0xfe)) >> 1);
}

__attribute__((used)) static void put_pixels16_axp_asm(uint8_t *block, const uint8_t *pixels,
                                 ptrdiff_t line_size, int h)
{
    put_pixels_axp_asm(block,     pixels,     line_size, h);
    put_pixels_axp_asm(block + 8, pixels + 8, line_size, h);
}

