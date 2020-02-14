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
typedef  int int32_t ;
typedef  int int16_t ;
typedef  int* DCTBLOCK ;

/* Variables and functions */
 int /*<<< orphan*/  AV_WN32A (int /*<<< orphan*/ *,int) ; 
 int CONST_BITS ; 
 int CONST_SCALE ; 
 int DCTSIZE ; 
 size_t DCTSTRIDE ; 
 scalar_t__ DESCALE (int,int) ; 
 int /*<<< orphan*/  FIX_0_211164243 ; 
 int /*<<< orphan*/  FIX_0_275899380 ; 
 int /*<<< orphan*/  FIX_0_298631336 ; 
 int /*<<< orphan*/  FIX_0_390180644 ; 
 int /*<<< orphan*/  FIX_0_509795579 ; 
 int /*<<< orphan*/  FIX_0_541196100 ; 
 int /*<<< orphan*/  FIX_0_601344887 ; 
 int /*<<< orphan*/  FIX_0_765366865 ; 
 int /*<<< orphan*/  FIX_0_785694958 ; 
 int /*<<< orphan*/  FIX_0_899976223 ; 
 int /*<<< orphan*/  FIX_1_061594337 ; 
 int /*<<< orphan*/  FIX_1_111140466 ; 
 int /*<<< orphan*/  FIX_1_175875602 ; 
 int /*<<< orphan*/  FIX_1_306562965 ; 
 int /*<<< orphan*/  FIX_1_387039845 ; 
 int /*<<< orphan*/  FIX_1_451774981 ; 
 int /*<<< orphan*/  FIX_1_501321110 ; 
 int /*<<< orphan*/  FIX_1_662939225 ; 
 int /*<<< orphan*/  FIX_1_847759065 ; 
 int /*<<< orphan*/  FIX_1_961570560 ; 
 int /*<<< orphan*/  FIX_2_053119869 ; 
 int /*<<< orphan*/  FIX_2_172734803 ; 
 int /*<<< orphan*/  FIX_2_562915447 ; 
 int /*<<< orphan*/  FIX_3_072711026 ; 
 int MULTIPLY (int,int /*<<< orphan*/ ) ; 
 int PASS1_BITS ; 
 int /*<<< orphan*/  ff_add_pixels_clamped_c (int*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_put_pixels_clamped_c (int*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void ff_j_rev_dct(DCTBLOCK data)
{
  int32_t tmp0, tmp1, tmp2, tmp3;
  int32_t tmp10, tmp11, tmp12, tmp13;
  int32_t z1, z2, z3, z4, z5;
  int32_t d0, d1, d2, d3, d4, d5, d6, d7;
  register int16_t *dataptr;
  int rowctr;

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  dataptr = data;

  for (rowctr = DCTSIZE-1; rowctr >= 0; rowctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any row in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * row DCT calculations can be simplified this way.
     */

    register uint8_t *idataptr = (uint8_t*)dataptr;

    /* WARNING: we do the same permutation as MMX idct to simplify the
       video core */
    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];
    d1 = dataptr[4];
    d3 = dataptr[5];
    d5 = dataptr[6];
    d7 = dataptr[7];

    if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0) {
      /* AC terms all zero */
      if (d0) {
          /* Compute a 32 bit value to assign. */
          int16_t dcval = (int16_t) (d0 * (1 << PASS1_BITS));
          register int v = (dcval & 0xffff) | ((dcval * (1 << 16)) & 0xffff0000);

          AV_WN32A(&idataptr[ 0], v);
          AV_WN32A(&idataptr[ 4], v);
          AV_WN32A(&idataptr[ 8], v);
          AV_WN32A(&idataptr[12], v);
      }

      dataptr += DCTSIZE;       /* advance pointer to next row */
      continue;
    }

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
{
    if (d6) {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 != 0 */
                    z1 = MULTIPLY(d2 + d6, FIX_0_541196100);
                    tmp2 = z1 + MULTIPLY(-d6, FIX_1_847759065);
                    tmp3 = z1 + MULTIPLY(d2, FIX_0_765366865);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 != 0 */
                    tmp2 = MULTIPLY(-d6, FIX_1_306562965);
                    tmp3 = MULTIPLY(d6, FIX_0_541196100);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            }
    } else {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 == 0 */
                    tmp2 = MULTIPLY(d2, FIX_0_541196100);
                    tmp3 = MULTIPLY(d2, FIX_1_306562965);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 == 0 */
                    tmp10 = tmp13 = (d0 + d4) * CONST_SCALE;
                    tmp11 = tmp12 = (d0 - d4) * CONST_SCALE;
            }
      }

    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */

    if (d7) {
        if (d5) {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 != 0, d7 != 0 */
                    z1 = d7 + d1;
                    z2 = d5 + d3;
                    z3 = d7 + d3;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(z3 + z4, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 != 0, d7 != 0 */
                    z2 = d5 + d3;
                    z3 = d7 + d3;
                    z5 = MULTIPLY(z3 + d5, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 = z1 + z4;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 != 0, d7 != 0 */
                    z1 = d7 + d1;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(d7 + z4, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 = z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 == 0, d5 != 0, d7 != 0 */
                    tmp0 = MULTIPLY(-d7, FIX_0_601344887);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    tmp1 = MULTIPLY(-d5, FIX_0_509795579);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);
                    z5 = MULTIPLY(d5 + d7, FIX_1_175875602);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z3;
                    tmp1 += z4;
                    tmp2 = z2 + z3;
                    tmp3 = z1 + z4;
                }
            }
        } else {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 == 0, d7 != 0 */
                    z1 = d7 + d1;
                    z3 = d7 + d3;
                    z5 = MULTIPLY(z3 + d1, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-d3, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-d1, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 = z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 == 0, d7 != 0 */
                    z3 = d7 + d3;

                    tmp0 = MULTIPLY(-d7, FIX_0_601344887);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    tmp2 = MULTIPLY(d3, FIX_0_509795579);
                    z2 = MULTIPLY(-d3, FIX_2_562915447);
                    z5 = MULTIPLY(z3, FIX_1_175875602);
                    z3 = MULTIPLY(-z3, FIX_0_785694958);

                    tmp0 += z3;
                    tmp1 = z2 + z5;
                    tmp2 += z3;
                    tmp3 = z1 + z5;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 == 0, d7 != 0 */
                    z1 = d7 + d1;
                    z5 = MULTIPLY(z1, FIX_1_175875602);

                    z1 = MULTIPLY(z1, FIX_0_275899380);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    tmp0 = MULTIPLY(-d7, FIX_1_662939225);
                    z4 = MULTIPLY(-d1, FIX_0_390180644);
                    tmp3 = MULTIPLY(d1, FIX_1_111140466);

                    tmp0 += z1;
                    tmp1 = z4 + z5;
                    tmp2 = z3 + z5;
                    tmp3 += z1;
                } else {
                    /* d1 == 0, d3 == 0, d5 == 0, d7 != 0 */
                    tmp0 = MULTIPLY(-d7, FIX_1_387039845);
                    tmp1 = MULTIPLY(d7, FIX_1_175875602);
                    tmp2 = MULTIPLY(-d7, FIX_0_785694958);
                    tmp3 = MULTIPLY(d7, FIX_0_275899380);
                }
            }
        }
    } else {
        if (d5) {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 != 0, d7 == 0 */
                    z2 = d5 + d3;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(d3 + z4, FIX_1_175875602);

                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-d1, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-d3, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 = z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 != 0, d7 == 0 */
                    z2 = d5 + d3;

                    z5 = MULTIPLY(z2, FIX_1_175875602);
                    tmp1 = MULTIPLY(d5, FIX_1_662939225);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);
                    z2 = MULTIPLY(-z2, FIX_1_387039845);
                    tmp2 = MULTIPLY(d3, FIX_1_111140466);
                    z3 = MULTIPLY(-d3, FIX_1_961570560);

                    tmp0 = z3 + z5;
                    tmp1 += z2;
                    tmp2 += z2;
                    tmp3 = z4 + z5;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 != 0, d7 == 0 */
                    z4 = d5 + d1;

                    z5 = MULTIPLY(z4, FIX_1_175875602);
                    z1 = MULTIPLY(-d1, FIX_0_899976223);
                    tmp3 = MULTIPLY(d1, FIX_0_601344887);
                    tmp1 = MULTIPLY(-d5, FIX_0_509795579);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z4 = MULTIPLY(z4, FIX_0_785694958);

                    tmp0 = z1 + z5;
                    tmp1 += z4;
                    tmp2 = z2 + z5;
                    tmp3 += z4;
                } else {
                    /* d1 == 0, d3 == 0, d5 != 0, d7 == 0 */
                    tmp0 = MULTIPLY(d5, FIX_1_175875602);
                    tmp1 = MULTIPLY(d5, FIX_0_275899380);
                    tmp2 = MULTIPLY(-d5, FIX_1_387039845);
                    tmp3 = MULTIPLY(d5, FIX_0_785694958);
                }
            }
        } else {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 == 0, d7 == 0 */
                    z5 = d1 + d3;
                    tmp3 = MULTIPLY(d1, FIX_0_211164243);
                    tmp2 = MULTIPLY(-d3, FIX_1_451774981);
                    z1 = MULTIPLY(d1, FIX_1_061594337);
                    z2 = MULTIPLY(-d3, FIX_2_172734803);
                    z4 = MULTIPLY(z5, FIX_0_785694958);
                    z5 = MULTIPLY(z5, FIX_1_175875602);

                    tmp0 = z1 - z4;
                    tmp1 = z2 + z4;
                    tmp2 += z5;
                    tmp3 += z5;
                } else {
                    /* d1 == 0, d3 != 0, d5 == 0, d7 == 0 */
                    tmp0 = MULTIPLY(-d3, FIX_0_785694958);
                    tmp1 = MULTIPLY(-d3, FIX_1_387039845);
                    tmp2 = MULTIPLY(-d3, FIX_0_275899380);
                    tmp3 = MULTIPLY(d3, FIX_1_175875602);
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 == 0, d7 == 0 */
                    tmp0 = MULTIPLY(d1, FIX_0_275899380);
                    tmp1 = MULTIPLY(d1, FIX_0_785694958);
                    tmp2 = MULTIPLY(d1, FIX_1_175875602);
                    tmp3 = MULTIPLY(d1, FIX_1_387039845);
                } else {
                    /* d1 == 0, d3 == 0, d5 == 0, d7 == 0 */
                    tmp0 = tmp1 = tmp2 = tmp3 = 0;
                }
            }
        }
    }
}
    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    dataptr[0] = (int16_t) DESCALE(tmp10 + tmp3, CONST_BITS-PASS1_BITS);
    dataptr[7] = (int16_t) DESCALE(tmp10 - tmp3, CONST_BITS-PASS1_BITS);
    dataptr[1] = (int16_t) DESCALE(tmp11 + tmp2, CONST_BITS-PASS1_BITS);
    dataptr[6] = (int16_t) DESCALE(tmp11 - tmp2, CONST_BITS-PASS1_BITS);
    dataptr[2] = (int16_t) DESCALE(tmp12 + tmp1, CONST_BITS-PASS1_BITS);
    dataptr[5] = (int16_t) DESCALE(tmp12 - tmp1, CONST_BITS-PASS1_BITS);
    dataptr[3] = (int16_t) DESCALE(tmp13 + tmp0, CONST_BITS-PASS1_BITS);
    dataptr[4] = (int16_t) DESCALE(tmp13 - tmp0, CONST_BITS-PASS1_BITS);

    dataptr += DCTSIZE;         /* advance pointer to next row */
  }

  /* Pass 2: process columns. */
  /* Note that we must descale the results by a factor of 8 == 2**3, */
  /* and also undo the PASS1_BITS scaling. */

  dataptr = data;
  for (rowctr = DCTSIZE-1; rowctr >= 0; rowctr--) {
    /* Columns of zeroes can be exploited in the same way as we did with rows.
     * However, the row calculation has created many nonzero AC terms, so the
     * simplification applies less often (typically 5% to 10% of the time).
     * On machines with very fast multiplication, it's possible that the
     * test takes more time than it's worth.  In that case this section
     * may be commented out.
     */

    d0 = dataptr[DCTSIZE*0];
    d1 = dataptr[DCTSIZE*1];
    d2 = dataptr[DCTSIZE*2];
    d3 = dataptr[DCTSIZE*3];
    d4 = dataptr[DCTSIZE*4];
    d5 = dataptr[DCTSIZE*5];
    d6 = dataptr[DCTSIZE*6];
    d7 = dataptr[DCTSIZE*7];

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
    if (d6) {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 != 0 */
                    z1 = MULTIPLY(d2 + d6, FIX_0_541196100);
                    tmp2 = z1 + MULTIPLY(-d6, FIX_1_847759065);
                    tmp3 = z1 + MULTIPLY(d2, FIX_0_765366865);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 != 0 */
                    tmp2 = MULTIPLY(-d6, FIX_1_306562965);
                    tmp3 = MULTIPLY(d6, FIX_0_541196100);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            }
    } else {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 == 0 */
                    tmp2 = MULTIPLY(d2, FIX_0_541196100);
                    tmp3 = MULTIPLY(d2, FIX_1_306562965);

                    tmp0 = (d0 + d4) * CONST_SCALE;
                    tmp1 = (d0 - d4) * CONST_SCALE;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 == 0 */
                    tmp10 = tmp13 = (d0 + d4) * CONST_SCALE;
                    tmp11 = tmp12 = (d0 - d4) * CONST_SCALE;
            }
    }

    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */
    if (d7) {
        if (d5) {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 != 0, d7 != 0 */
                    z1 = d7 + d1;
                    z2 = d5 + d3;
                    z3 = d7 + d3;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(z3 + z4, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 != 0, d7 != 0 */
                    z2 = d5 + d3;
                    z3 = d7 + d3;
                    z5 = MULTIPLY(z3 + d5, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 = z1 + z4;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 != 0, d7 != 0 */
                    z1 = d7 + d1;
                    z3 = d7;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(z3 + z4, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 = z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 == 0, d5 != 0, d7 != 0 */
                    tmp0 = MULTIPLY(-d7, FIX_0_601344887);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    tmp1 = MULTIPLY(-d5, FIX_0_509795579);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);
                    z5 = MULTIPLY(d5 + d7, FIX_1_175875602);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z3;
                    tmp1 += z4;
                    tmp2 = z2 + z3;
                    tmp3 = z1 + z4;
                }
            }
        } else {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 == 0, d7 != 0 */
                    z1 = d7 + d1;
                    z3 = d7 + d3;
                    z5 = MULTIPLY(z3 + d1, FIX_1_175875602);

                    tmp0 = MULTIPLY(d7, FIX_0_298631336);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-z1, FIX_0_899976223);
                    z2 = MULTIPLY(-d3, FIX_2_562915447);
                    z3 = MULTIPLY(-z3, FIX_1_961570560);
                    z4 = MULTIPLY(-d1, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 += z1 + z3;
                    tmp1 = z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 == 0, d7 != 0 */
                    z3 = d7 + d3;

                    tmp0 = MULTIPLY(-d7, FIX_0_601344887);
                    z1 = MULTIPLY(-d7, FIX_0_899976223);
                    tmp2 = MULTIPLY(d3, FIX_0_509795579);
                    z2 = MULTIPLY(-d3, FIX_2_562915447);
                    z5 = MULTIPLY(z3, FIX_1_175875602);
                    z3 = MULTIPLY(-z3, FIX_0_785694958);

                    tmp0 += z3;
                    tmp1 = z2 + z5;
                    tmp2 += z3;
                    tmp3 = z1 + z5;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 == 0, d7 != 0 */
                    z1 = d7 + d1;
                    z5 = MULTIPLY(z1, FIX_1_175875602);

                    z1 = MULTIPLY(z1, FIX_0_275899380);
                    z3 = MULTIPLY(-d7, FIX_1_961570560);
                    tmp0 = MULTIPLY(-d7, FIX_1_662939225);
                    z4 = MULTIPLY(-d1, FIX_0_390180644);
                    tmp3 = MULTIPLY(d1, FIX_1_111140466);

                    tmp0 += z1;
                    tmp1 = z4 + z5;
                    tmp2 = z3 + z5;
                    tmp3 += z1;
                } else {
                    /* d1 == 0, d3 == 0, d5 == 0, d7 != 0 */
                    tmp0 = MULTIPLY(-d7, FIX_1_387039845);
                    tmp1 = MULTIPLY(d7, FIX_1_175875602);
                    tmp2 = MULTIPLY(-d7, FIX_0_785694958);
                    tmp3 = MULTIPLY(d7, FIX_0_275899380);
                }
            }
        }
    } else {
        if (d5) {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 != 0, d7 == 0 */
                    z2 = d5 + d3;
                    z4 = d5 + d1;
                    z5 = MULTIPLY(d3 + z4, FIX_1_175875602);

                    tmp1 = MULTIPLY(d5, FIX_2_053119869);
                    tmp2 = MULTIPLY(d3, FIX_3_072711026);
                    tmp3 = MULTIPLY(d1, FIX_1_501321110);
                    z1 = MULTIPLY(-d1, FIX_0_899976223);
                    z2 = MULTIPLY(-z2, FIX_2_562915447);
                    z3 = MULTIPLY(-d3, FIX_1_961570560);
                    z4 = MULTIPLY(-z4, FIX_0_390180644);

                    z3 += z5;
                    z4 += z5;

                    tmp0 = z1 + z3;
                    tmp1 += z2 + z4;
                    tmp2 += z2 + z3;
                    tmp3 += z1 + z4;
                } else {
                    /* d1 == 0, d3 != 0, d5 != 0, d7 == 0 */
                    z2 = d5 + d3;

                    z5 = MULTIPLY(z2, FIX_1_175875602);
                    tmp1 = MULTIPLY(d5, FIX_1_662939225);
                    z4 = MULTIPLY(-d5, FIX_0_390180644);
                    z2 = MULTIPLY(-z2, FIX_1_387039845);
                    tmp2 = MULTIPLY(d3, FIX_1_111140466);
                    z3 = MULTIPLY(-d3, FIX_1_961570560);

                    tmp0 = z3 + z5;
                    tmp1 += z2;
                    tmp2 += z2;
                    tmp3 = z4 + z5;
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 != 0, d7 == 0 */
                    z4 = d5 + d1;

                    z5 = MULTIPLY(z4, FIX_1_175875602);
                    z1 = MULTIPLY(-d1, FIX_0_899976223);
                    tmp3 = MULTIPLY(d1, FIX_0_601344887);
                    tmp1 = MULTIPLY(-d5, FIX_0_509795579);
                    z2 = MULTIPLY(-d5, FIX_2_562915447);
                    z4 = MULTIPLY(z4, FIX_0_785694958);

                    tmp0 = z1 + z5;
                    tmp1 += z4;
                    tmp2 = z2 + z5;
                    tmp3 += z4;
                } else {
                    /* d1 == 0, d3 == 0, d5 != 0, d7 == 0 */
                    tmp0 = MULTIPLY(d5, FIX_1_175875602);
                    tmp1 = MULTIPLY(d5, FIX_0_275899380);
                    tmp2 = MULTIPLY(-d5, FIX_1_387039845);
                    tmp3 = MULTIPLY(d5, FIX_0_785694958);
                }
            }
        } else {
            if (d3) {
                if (d1) {
                    /* d1 != 0, d3 != 0, d5 == 0, d7 == 0 */
                    z5 = d1 + d3;
                    tmp3 = MULTIPLY(d1, FIX_0_211164243);
                    tmp2 = MULTIPLY(-d3, FIX_1_451774981);
                    z1 = MULTIPLY(d1, FIX_1_061594337);
                    z2 = MULTIPLY(-d3, FIX_2_172734803);
                    z4 = MULTIPLY(z5, FIX_0_785694958);
                    z5 = MULTIPLY(z5, FIX_1_175875602);

                    tmp0 = z1 - z4;
                    tmp1 = z2 + z4;
                    tmp2 += z5;
                    tmp3 += z5;
                } else {
                    /* d1 == 0, d3 != 0, d5 == 0, d7 == 0 */
                    tmp0 = MULTIPLY(-d3, FIX_0_785694958);
                    tmp1 = MULTIPLY(-d3, FIX_1_387039845);
                    tmp2 = MULTIPLY(-d3, FIX_0_275899380);
                    tmp3 = MULTIPLY(d3, FIX_1_175875602);
                }
            } else {
                if (d1) {
                    /* d1 != 0, d3 == 0, d5 == 0, d7 == 0 */
                    tmp0 = MULTIPLY(d1, FIX_0_275899380);
                    tmp1 = MULTIPLY(d1, FIX_0_785694958);
                    tmp2 = MULTIPLY(d1, FIX_1_175875602);
                    tmp3 = MULTIPLY(d1, FIX_1_387039845);
                } else {
                    /* d1 == 0, d3 == 0, d5 == 0, d7 == 0 */
                    tmp0 = tmp1 = tmp2 = tmp3 = 0;
                }
            }
        }
    }

    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    dataptr[DCTSIZE*0] = (int16_t) DESCALE(tmp10 + tmp3,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*7] = (int16_t) DESCALE(tmp10 - tmp3,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*1] = (int16_t) DESCALE(tmp11 + tmp2,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*6] = (int16_t) DESCALE(tmp11 - tmp2,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*2] = (int16_t) DESCALE(tmp12 + tmp1,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*5] = (int16_t) DESCALE(tmp12 - tmp1,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*3] = (int16_t) DESCALE(tmp13 + tmp0,
                                           CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSIZE*4] = (int16_t) DESCALE(tmp13 - tmp0,
                                           CONST_BITS+PASS1_BITS+3);

    dataptr++;                  /* advance pointer to next column */
  }
}

void ff_j_rev_dct4(DCTBLOCK data)
{
  int32_t tmp0, tmp1, tmp2, tmp3;
  int32_t tmp10, tmp11, tmp12, tmp13;
  int32_t z1;
  int32_t d0, d2, d4, d6;
  register int16_t *dataptr;
  int rowctr;

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  data[0] += 4;

  dataptr = data;

  for (rowctr = DCTSIZE-1; rowctr >= 0; rowctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any row in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * row DCT calculations can be simplified this way.
     */

    register uint8_t *idataptr = (uint8_t*)dataptr;

    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];

    if ((d2 | d4 | d6) == 0) {
      /* AC terms all zero */
      if (d0) {
          /* Compute a 32 bit value to assign. */
          int16_t dcval = (int16_t) (d0 << PASS1_BITS);
          register int v = (dcval & 0xffff) | ((dcval << 16) & 0xffff0000);

          AV_WN32A(&idataptr[0], v);
          AV_WN32A(&idataptr[4], v);
      }

      dataptr += DCTSTRIDE;     /* advance pointer to next row */
      continue;
    }

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
    if (d6) {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 != 0 */
                    z1 = MULTIPLY(d2 + d6, FIX_0_541196100);
                    tmp2 = z1 + MULTIPLY(-d6, FIX_1_847759065);
                    tmp3 = z1 + MULTIPLY(d2, FIX_0_765366865);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 != 0 */
                    tmp2 = MULTIPLY(-d6, FIX_1_306562965);
                    tmp3 = MULTIPLY(d6, FIX_0_541196100);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            }
    } else {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 == 0 */
                    tmp2 = MULTIPLY(d2, FIX_0_541196100);
                    tmp3 = MULTIPLY(d2, FIX_1_306562965);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 == 0 */
                    tmp10 = tmp13 = (d0 + d4) << CONST_BITS;
                    tmp11 = tmp12 = (d0 - d4) << CONST_BITS;
            }
      }

    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    dataptr[0] = (int16_t) DESCALE(tmp10, CONST_BITS-PASS1_BITS);
    dataptr[1] = (int16_t) DESCALE(tmp11, CONST_BITS-PASS1_BITS);
    dataptr[2] = (int16_t) DESCALE(tmp12, CONST_BITS-PASS1_BITS);
    dataptr[3] = (int16_t) DESCALE(tmp13, CONST_BITS-PASS1_BITS);

    dataptr += DCTSTRIDE;       /* advance pointer to next row */
  }

  /* Pass 2: process columns. */
  /* Note that we must descale the results by a factor of 8 == 2**3, */
  /* and also undo the PASS1_BITS scaling. */

  dataptr = data;
  for (rowctr = DCTSIZE-1; rowctr >= 0; rowctr--) {
    /* Columns of zeroes can be exploited in the same way as we did with rows.
     * However, the row calculation has created many nonzero AC terms, so the
     * simplification applies less often (typically 5% to 10% of the time).
     * On machines with very fast multiplication, it's possible that the
     * test takes more time than it's worth.  In that case this section
     * may be commented out.
     */

    d0 = dataptr[DCTSTRIDE*0];
    d2 = dataptr[DCTSTRIDE*1];
    d4 = dataptr[DCTSTRIDE*2];
    d6 = dataptr[DCTSTRIDE*3];

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
    if (d6) {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 != 0 */
                    z1 = MULTIPLY(d2 + d6, FIX_0_541196100);
                    tmp2 = z1 + MULTIPLY(-d6, FIX_1_847759065);
                    tmp3 = z1 + MULTIPLY(d2, FIX_0_765366865);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 != 0 */
                    tmp2 = MULTIPLY(-d6, FIX_1_306562965);
                    tmp3 = MULTIPLY(d6, FIX_0_541196100);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            }
    } else {
            if (d2) {
                    /* d0 != 0, d2 != 0, d4 != 0, d6 == 0 */
                    tmp2 = MULTIPLY(d2, FIX_0_541196100);
                    tmp3 = MULTIPLY(d2, FIX_1_306562965);

                    tmp0 = (d0 + d4) << CONST_BITS;
                    tmp1 = (d0 - d4) << CONST_BITS;

                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
            } else {
                    /* d0 != 0, d2 == 0, d4 != 0, d6 == 0 */
                    tmp10 = tmp13 = (d0 + d4) << CONST_BITS;
                    tmp11 = tmp12 = (d0 - d4) << CONST_BITS;
            }
    }

    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    dataptr[DCTSTRIDE*0] = tmp10 >> (CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSTRIDE*1] = tmp11 >> (CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSTRIDE*2] = tmp12 >> (CONST_BITS+PASS1_BITS+3);
    dataptr[DCTSTRIDE*3] = tmp13 >> (CONST_BITS+PASS1_BITS+3);

    dataptr++;                  /* advance pointer to next column */
  }
}

void ff_j_rev_dct2(DCTBLOCK data){
  int d00, d01, d10, d11;

  data[0] += 4;
  d00 = data[0+0*DCTSTRIDE] + data[1+0*DCTSTRIDE];
  d01 = data[0+0*DCTSTRIDE] - data[1+0*DCTSTRIDE];
  d10 = data[0+1*DCTSTRIDE] + data[1+1*DCTSTRIDE];
  d11 = data[0+1*DCTSTRIDE] - data[1+1*DCTSTRIDE];

  data[0+0*DCTSTRIDE]= (d00 + d10)>>3;
  data[1+0*DCTSTRIDE]= (d01 + d11)>>3;
  data[0+1*DCTSTRIDE]= (d00 - d10)>>3;
  data[1+1*DCTSTRIDE]= (d01 - d11)>>3;
}

void ff_j_rev_dct1(DCTBLOCK data){
  data[0] = (data[0] + 4)>>3;
}

void ff_jref_idct_put(uint8_t *dest, ptrdiff_t line_size, int16_t *block)
{
    ff_j_rev_dct(block);
    ff_put_pixels_clamped_c(block, dest, line_size);
}

void ff_jref_idct_add(uint8_t *dest, ptrdiff_t line_size, int16_t *block)
{
    ff_j_rev_dct(block);
    ff_add_pixels_clamped_c(block, dest, line_size);
}

