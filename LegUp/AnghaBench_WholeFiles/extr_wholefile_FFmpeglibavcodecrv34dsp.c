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
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;
typedef  int int16_t ;

/* Variables and functions */
 scalar_t__ av_clip_uint8 (scalar_t__) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rv34_row_transform (int*,int*) ; 

__attribute__((used)) static void rv34_idct_add_c(uint8_t *dst, ptrdiff_t stride, int16_t *block){
    int      temp[16];
    int      i;

    rv34_row_transform(temp, block);
    memset(block, 0, 16*sizeof(int16_t));

    for(i = 0; i < 4; i++){
        const int z0 = 13*(temp[4*0+i] +    temp[4*2+i]) + 0x200;
        const int z1 = 13*(temp[4*0+i] -    temp[4*2+i]) + 0x200;
        const int z2 =  7* temp[4*1+i] - 17*temp[4*3+i];
        const int z3 = 17* temp[4*1+i] +  7*temp[4*3+i];

        dst[0] = av_clip_uint8( dst[0] + ( (z0 + z3) >> 10 ) );
        dst[1] = av_clip_uint8( dst[1] + ( (z1 + z2) >> 10 ) );
        dst[2] = av_clip_uint8( dst[2] + ( (z1 - z2) >> 10 ) );
        dst[3] = av_clip_uint8( dst[3] + ( (z0 - z3) >> 10 ) );

        dst  += stride;
    }
}

__attribute__((used)) static void rv34_inv_transform_noround_c(int16_t *block){
    int temp[16];
    int i;

    rv34_row_transform(temp, block);

    for(i = 0; i < 4; i++){
        const int z0 = 39*(temp[4*0+i] +    temp[4*2+i]);
        const int z1 = 39*(temp[4*0+i] -    temp[4*2+i]);
        const int z2 = 21* temp[4*1+i] - 51*temp[4*3+i];
        const int z3 = 51* temp[4*1+i] + 21*temp[4*3+i];

        block[i*4+0] = (z0 + z3) >> 11;
        block[i*4+1] = (z1 + z2) >> 11;
        block[i*4+2] = (z1 - z2) >> 11;
        block[i*4+3] = (z0 - z3) >> 11;
    }
}

__attribute__((used)) static void rv34_idct_dc_add_c(uint8_t *dst, ptrdiff_t stride, int dc)
{
    int i, j;

    dc = (13*13*dc + 0x200) >> 10;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            dst[j] = av_clip_uint8( dst[j] + dc );

        dst += stride;
    }
}

__attribute__((used)) static void rv34_inv_transform_dc_noround_c(int16_t *block)
{
    int16_t dc = (13 * 13 * 3 * block[0]) >> 11;
    int i, j;

    for (i = 0; i < 4; i++, block += 4)
        for (j = 0; j < 4; j++)
            block[j] = dc;
}

