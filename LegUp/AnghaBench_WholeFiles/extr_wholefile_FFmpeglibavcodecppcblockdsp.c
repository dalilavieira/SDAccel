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
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void clear_blocks_dcbz32_ppc(int16_t *blocks)
{
    register int misal = (unsigned long) blocks & 0x00000010, i = 0;

    if (misal) {
        ((unsigned long *) blocks)[0] = 0L;
        ((unsigned long *) blocks)[1] = 0L;
        ((unsigned long *) blocks)[2] = 0L;
        ((unsigned long *) blocks)[3] = 0L;
        i += 16;
    }
    for (; i < sizeof(int16_t) * 6 * 64 - 31; i += 32)
        __asm__ volatile ("dcbz %0,%1" :: "b" (blocks), "r" (i) : "memory");
    if (misal) {
        ((unsigned long *) blocks)[188] = 0L;
        ((unsigned long *) blocks)[189] = 0L;
        ((unsigned long *) blocks)[190] = 0L;
        ((unsigned long *) blocks)[191] = 0L;
        i += 16;
    }
}

__attribute__((used)) static void clear_blocks_dcbz128_ppc(int16_t *blocks)
{
#if HAVE_DCBZL
    register int misal = (unsigned long) blocks & 0x0000007f, i = 0;

    if (misal) {
        /* We could probably also optimize this case,
         * but there's not much point as the machines
         * aren't available yet (2003-06-26). */
        memset(blocks, 0, sizeof(int16_t) * 6 * 64);
    } else {
        for (; i < sizeof(int16_t) * 6 * 64; i += 128)
            __asm__ volatile ("dcbzl %0,%1" :: "b" (blocks), "r" (i) : "memory");
    }
#else
    memset(blocks, 0, sizeof(int16_t) * 6 * 64);
#endif
}

__attribute__((used)) static long check_dcbzl_effect(void)
{
    long count = 0;
#if HAVE_DCBZL
    register char *fakedata = av_malloc(1024);
    register char *fakedata_middle;
    register long zero = 0, i = 0;

    if (!fakedata)
        return 0L;

    fakedata_middle = fakedata + 512;

    memset(fakedata, 0xFF, 1024);

    /* Below the constraint "b" seems to mean "address base register"
     * in gcc-3.3 / RS/6000 speaks. Seems to avoid using r0, so.... */
    __asm__ volatile ("dcbzl %0, %1" :: "b" (fakedata_middle), "r" (zero));

    for (i = 0; i < 1024; i++)
        if (fakedata[i] == (char) 0)
            count++;

    av_free(fakedata);
#endif

    return count;
}

