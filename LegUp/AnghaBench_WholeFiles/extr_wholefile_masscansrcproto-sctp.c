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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  time_t ;
struct PreprocessedInfo {unsigned int port_src; unsigned int transport_offset; int* ip_src; int /*<<< orphan*/  mac_src; int /*<<< orphan*/  ip_ttl; } ;
struct Output {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRC32C (unsigned int,unsigned char const) ; 
 int /*<<< orphan*/  PortStatus_Closed ; 
 int /*<<< orphan*/  PortStatus_Open ; 
 int /*<<< orphan*/  UNUSEDPARM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  output_report_status (struct Output*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

unsigned
sctp_checksum(const void *vbuffer, size_t length)
{
    const unsigned char *buffer = (const unsigned char *)vbuffer;
    unsigned i;
    unsigned crc32 = (unsigned)~0;
    unsigned result;
    unsigned char byte0,byte1,byte2,byte3;

    for (i = 0; i < 8; i++) {
        CRC32C(crc32, buffer[i]);
    }

    CRC32C(crc32, 0);
    CRC32C(crc32, 0);
    CRC32C(crc32, 0);
    CRC32C(crc32, 0);

    for (i = 12; i < length; i++) {
        CRC32C(crc32, buffer[i]);
    }
    result = ~crc32;

    /*  result  now holds the negated polynomial remainder;
    *  since the table and algorithm is "reflected" [williams95].
    *  That is,  result has the same value as if we mapped the message
    *  to a polynomial, computed the host-bit-order polynomial
    *  remainder, performed final negation, then did an end-for-end
    *  bit-reversal.
    *  Note that a 32-bit bit-reversal is identical to four inplace
    *  8-bit reversals followed by an end-for-end byteswap.
    *  In other words, the bytes of each bit are in the right order,
    *  but the bytes have been byteswapped.  So we now do an explicit
    *  byteswap.  On a little-endian machine, this byteswap and
    *  the final ntohl cancel out and could be elided.
    */

    byte0 = result & 0xff;
    byte1 = (result>>8) & 0xff;
    byte2 = (result>>16) & 0xff;
    byte3 = (result>>24) & 0xff;

    crc32 = ((byte0 << 24) |
            (byte1 << 16) |
            (byte2 << 8)  |
            byte3);
    return ( crc32 );
}

void
handle_sctp(struct Output *out, time_t timestamp,
            const unsigned char *px, unsigned length, 
            unsigned cookie,
            struct PreprocessedInfo *parsed,
            uint64_t entropy)
{
    unsigned ip_them;
    unsigned port_them = parsed->port_src;
    unsigned verification_tag;
    unsigned offset = parsed->transport_offset;

    UNUSEDPARM(entropy);

    ip_them = parsed->ip_src[0]<<24 | parsed->ip_src[1]<<16
            | parsed->ip_src[2]<< 8 | parsed->ip_src[3]<<0;

    verification_tag = px[offset + 4] << 24 | px[offset + 5] << 16 |
                        px[offset + 6] << 8 | px[offset + 7];
    if (cookie != verification_tag)
        return;

    if (offset + 16 > length)
        return;

    switch (px[offset + 12]) {
    case 2: /* init ack */
        output_report_status(
                        out,
                        timestamp,
                        PortStatus_Open,
                        ip_them,
                        132, /* ip proto = sctp */
                        port_them,
                        0,
                        parsed->ip_ttl,
                        parsed->mac_src);
        break;
    case 6: /* abort */
        output_report_status(
                        out,
                        timestamp,
                        PortStatus_Closed,
                        ip_them,
                        132, /* ip proto = sctp */
                        port_them,
                        0,
                        parsed->ip_ttl,
                        parsed->mac_src);
        break;
    default:
        ;
    }



}

int
sctp_selftest(void)
{
    const char testcase[] = 
        "\xd1\x60\x00\x50\x00\x00\x00\x00\x58\xe4\x5d\x36\x01\x00\x00\x14"
        "\x9e\x8d\x52\x25\x00\x00\x80\x00\x00\x0a\x08\x00\x46\x1a\xdf\x3d";

    unsigned xsum;

    xsum = sctp_checksum(testcase, 32);
    
    if (xsum != 0x58e45d36)
        return 1;

    return 0;
}

