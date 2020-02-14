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
typedef  int ptrdiff_t ;
typedef  int int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  IDCT_COL (int*,int const*) ; 
 int /*<<< orphan*/  IDCT_ROW (int /*<<< orphan*/ *,int*) ; 

__attribute__((used)) static inline void ea_idct_col(int16_t *dest, const int16_t *src) {
    if ((src[8]|src[16]|src[24]|src[32]|src[40]|src[48]|src[56])==0) {
        dest[0]  =
        dest[8]  =
        dest[16] =
        dest[24] =
        dest[32] =
        dest[40] =
        dest[48] =
        dest[56] = src[0];
    }else
        IDCT_COL(dest, src);
}

void ff_ea_idct_put_c(uint8_t *dest, ptrdiff_t linesize, int16_t *block)
{
    int i;
    int16_t temp[64];
    block[0] += 4;
    for (i=0; i<8; i++)
        ea_idct_col(&temp[i], &block[i]);
    for (i=0; i<8; i++)
        IDCT_ROW( (&dest[i*linesize]), (&temp[8*i]) );
}

