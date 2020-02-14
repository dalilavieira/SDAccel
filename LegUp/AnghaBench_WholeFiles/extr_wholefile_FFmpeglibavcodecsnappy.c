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
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  GetByteContext ;

/* Variables and functions */
 int AVERROR_BUFFER_TOO_SMALL ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  SEEK_END ; 
#define  SNAPPY_COPY_1 131 
#define  SNAPPY_COPY_2 130 
#define  SNAPPY_COPY_4 129 
#define  SNAPPY_LITERAL 128 
 int UINT_MAX ; 
 int /*<<< orphan*/  bytestream2_get_buffer (int /*<<< orphan*/ *,int*,unsigned int) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 scalar_t__ bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le24 (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_seek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int64_t bytestream2_get_levarint(GetByteContext *gb)
{
    uint64_t val = 0;
    int shift = 0;
    int tmp;

    do {
        tmp = bytestream2_get_byte(gb);
        val |= (tmp & 127) << shift;
        shift += 7;
    } while (tmp & 128);

    return val;
}

__attribute__((used)) static int snappy_literal(GetByteContext *gb, uint8_t *p, int size, int val)
{
    unsigned int len = 1;

    switch (val) {
    case 63:
        len += bytestream2_get_le32(gb);
        break;
    case 62:
        len += bytestream2_get_le24(gb);
        break;
    case 61:
        len += bytestream2_get_le16(gb);
        break;
    case 60:
        len += bytestream2_get_byte(gb);
        break;
    default: // val < 60
        len += val;
    }

    if (size < len)
        return AVERROR_INVALIDDATA;

    bytestream2_get_buffer(gb, p, len);

    return len;
}

__attribute__((used)) static int snappy_copy(uint8_t *start, uint8_t *p, int size,
                       unsigned int off, int len)
{
    uint8_t *q;
    int i;
    if (off > p - start || size < len)
        return AVERROR_INVALIDDATA;

    q = p - off;

    for (i = 0; i < len; i++)
        p[i] = q[i];

    return len;
}

__attribute__((used)) static int snappy_copy1(GetByteContext *gb, uint8_t *start, uint8_t *p,
                        int size, int val)
{
    int len          = 4 + (val & 0x7);
    unsigned int off = bytestream2_get_byte(gb) | (val & 0x38) << 5;

    return snappy_copy(start, p, size, off, len);
}

__attribute__((used)) static int snappy_copy2(GetByteContext *gb, uint8_t *start, uint8_t *p,
                        int size, int val)
{
    int len          = 1 + val;
    unsigned int off = bytestream2_get_le16(gb);

    return snappy_copy(start, p, size, off, len);
}

__attribute__((used)) static int snappy_copy4(GetByteContext *gb, uint8_t *start, uint8_t *p,
                        int size, int val)
{
    int len          = 1 + val;
    unsigned int off = bytestream2_get_le32(gb);

    return snappy_copy(start, p, size, off, len);
}

__attribute__((used)) static int64_t decode_len(GetByteContext *gb)
{
    int64_t len = bytestream2_get_levarint(gb);

    if (len < 0 || len > UINT_MAX)
        return AVERROR_INVALIDDATA;

    return len;
}

int64_t ff_snappy_peek_uncompressed_length(GetByteContext *gb)
{
    int pos = bytestream2_get_bytes_left(gb);
    int64_t len = decode_len(gb);

    bytestream2_seek(gb, -pos, SEEK_END);

    return len;
}

int ff_snappy_uncompress(GetByteContext *gb, uint8_t *buf, int64_t *size)
{
    int64_t len = decode_len(gb);
    int ret     = 0;
    uint8_t *p;

    if (len < 0)
        return len;

    if (len > *size)
        return AVERROR_BUFFER_TOO_SMALL;

    *size = len;
    p     = buf;

    while (bytestream2_get_bytes_left(gb) > 0) {
        uint8_t s = bytestream2_get_byte(gb);
        int val   = s >> 2;

        switch (s & 0x03) {
        case SNAPPY_LITERAL:
            ret = snappy_literal(gb, p, len, val);
            break;
        case SNAPPY_COPY_1:
            ret = snappy_copy1(gb, buf, p, len, val);
            break;
        case SNAPPY_COPY_2:
            ret = snappy_copy2(gb, buf, p, len, val);
            break;
        case SNAPPY_COPY_4:
            ret = snappy_copy4(gb, buf, p, len, val);
            break;
        }

        if (ret < 0)
            return ret;

        p   += ret;
        len -= ret;
    }

    return 0;
}

