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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  E2BIG ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  SET_ERRNO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 

unsigned int
lzf_decompress (const void *const in_data,  unsigned int in_len,
                void             *out_data, unsigned int out_len)
{
  u8 const *ip = (const u8 *)in_data;
  u8       *op = (u8 *)out_data;
  u8 const *const in_end  = ip + in_len;
  u8       *const out_end = op + out_len;

  do
    {
      unsigned int ctrl = *ip++;

      if (ctrl < (1 << 5)) /* literal run */
        {
          ctrl++;

          if (op + ctrl > out_end)
            {
              SET_ERRNO (E2BIG);
              return 0;
            }

#if CHECK_INPUT
          if (ip + ctrl > in_end)
            {
              SET_ERRNO (EINVAL);
              return 0;
            }
#endif

#ifdef lzf_movsb
          lzf_movsb (op, ip, ctrl);
#else
          switch (ctrl)
            {
              case 32: *op++ = *ip++; case 31: *op++ = *ip++; case 30: *op++ = *ip++; case 29: *op++ = *ip++;
              case 28: *op++ = *ip++; case 27: *op++ = *ip++; case 26: *op++ = *ip++; case 25: *op++ = *ip++;
              case 24: *op++ = *ip++; case 23: *op++ = *ip++; case 22: *op++ = *ip++; case 21: *op++ = *ip++;
              case 20: *op++ = *ip++; case 19: *op++ = *ip++; case 18: *op++ = *ip++; case 17: *op++ = *ip++;
              case 16: *op++ = *ip++; case 15: *op++ = *ip++; case 14: *op++ = *ip++; case 13: *op++ = *ip++;
              case 12: *op++ = *ip++; case 11: *op++ = *ip++; case 10: *op++ = *ip++; case  9: *op++ = *ip++;
              case  8: *op++ = *ip++; case  7: *op++ = *ip++; case  6: *op++ = *ip++; case  5: *op++ = *ip++;
              case  4: *op++ = *ip++; case  3: *op++ = *ip++; case  2: *op++ = *ip++; case  1: *op++ = *ip++;
            }
#endif
        }
      else /* back reference */
        {
          unsigned int len = ctrl >> 5;

          u8 *ref = op - ((ctrl & 0x1f) << 8) - 1;

#if CHECK_INPUT
          if (ip >= in_end)
            {
              SET_ERRNO (EINVAL);
              return 0;
            }
#endif
          if (len == 7)
            {
              len += *ip++;
#if CHECK_INPUT
              if (ip >= in_end)
                {
                  SET_ERRNO (EINVAL);
                  return 0;
                }
#endif
            }

          ref -= *ip++;

          if (op + len + 2 > out_end)
            {
              SET_ERRNO (E2BIG);
              return 0;
            }

          if (ref < (u8 *)out_data)
            {
              SET_ERRNO (EINVAL);
              return 0;
            }

#ifdef lzf_movsb
          len += 2;
          lzf_movsb (op, ref, len);
#else
          switch (len)
            {
              default:
                len += 2;

                if (op >= ref + len)
                  {
                    /* disjunct areas */
                    memcpy (op, ref, len);
                    op += len;
                  }
                else
                  {
                    /* overlapping, use octte by octte copying */
                    do
                      *op++ = *ref++;
                    while (--len);
                  }

                break;

              case 9: *op++ = *ref++; /* fall-thru */
              case 8: *op++ = *ref++; /* fall-thru */
              case 7: *op++ = *ref++; /* fall-thru */
              case 6: *op++ = *ref++; /* fall-thru */
              case 5: *op++ = *ref++; /* fall-thru */
              case 4: *op++ = *ref++; /* fall-thru */
              case 3: *op++ = *ref++; /* fall-thru */
              case 2: *op++ = *ref++; /* fall-thru */
              case 1: *op++ = *ref++; /* fall-thru */
              case 0: *op++ = *ref++; /* two octets more */
                      *op++ = *ref++; /* fall-thru */
            }
#endif
        }
    }
  while (ip < in_end);

  return op - (u8 *)out_data;
}

