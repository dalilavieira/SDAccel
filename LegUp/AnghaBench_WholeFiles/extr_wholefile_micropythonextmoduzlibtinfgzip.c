#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint16_t ;
struct TYPE_6__ {int /*<<< orphan*/  checksum; int /*<<< orphan*/  checksum_type; } ;
typedef  TYPE_1__ TINF_DATA ;

/* Variables and functions */
 unsigned char FCOMMENT ; 
 unsigned char FEXTRA ; 
 unsigned char FHCRC ; 
 unsigned char FNAME ; 
 int /*<<< orphan*/  TINF_CHKSUM_CRC ; 
 int TINF_DATA_ERROR ; 
 int TINF_OK ; 
 int uzlib_get_byte (TYPE_1__*) ; 

void tinf_skip_bytes(TINF_DATA *d, int num)
{
    while (num--) uzlib_get_byte(d);
}

uint16_t tinf_get_uint16(TINF_DATA *d)
{
    unsigned int v = uzlib_get_byte(d);
    v = (uzlib_get_byte(d) << 8) | v;
    return v;
}

int uzlib_gzip_parse_header(TINF_DATA *d)
{
    unsigned char flg;

    /* -- check format -- */

    /* check id bytes */
    if (uzlib_get_byte(d) != 0x1f || uzlib_get_byte(d) != 0x8b) return TINF_DATA_ERROR;

    /* check method is deflate */
    if (uzlib_get_byte(d) != 8) return TINF_DATA_ERROR;

    /* get flag byte */
    flg = uzlib_get_byte(d);

    /* check that reserved bits are zero */
    if (flg & 0xe0) return TINF_DATA_ERROR;

    /* -- find start of compressed data -- */

    /* skip rest of base header of 10 bytes */
    tinf_skip_bytes(d, 6);

    /* skip extra data if present */
    if (flg & FEXTRA)
    {
       unsigned int xlen = tinf_get_uint16(d);
       tinf_skip_bytes(d, xlen);
    }

    /* skip file name if present */
    if (flg & FNAME) { while (uzlib_get_byte(d)); }

    /* skip file comment if present */
    if (flg & FCOMMENT) { while (uzlib_get_byte(d)); }

    /* check header crc if present */
    if (flg & FHCRC)
    {
       /*unsigned int hcrc =*/ tinf_get_uint16(d);

        // TODO: Check!
//       if (hcrc != (tinf_crc32(src, start - src) & 0x0000ffff))
//          return TINF_DATA_ERROR;
    }

    /* initialize for crc32 checksum */
    d->checksum_type = TINF_CHKSUM_CRC;
    d->checksum = ~0;

    return TINF_OK;
}

