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
typedef  int uint32_t ;
typedef  int int8_t ;
typedef  int int64_t ;

/* Variables and functions */
#define  SQLITERK_CANTOPEN 135 
#define  SQLITERK_DAMAGED 134 
#define  SQLITERK_DISCARD 133 
#define  SQLITERK_IOERR 132 
#define  SQLITERK_MISUSE 131 
#define  SQLITERK_NOMEM 130 
#define  SQLITERK_OK 129 
#define  SQLITERK_SHORT_READ 128 
 int /*<<< orphan*/  memcpy (double*,unsigned char*,int) ; 
 int sqliterkGetMaxVarintLength () ; 
 int sqliterkParseInt64 (unsigned char const*,int,int,int*) ; 
 int sqliterkParseVarint64 (unsigned char const*,int,int*,int*) ; 

int sqliterkParseInt(const unsigned char *data,
                     int offset,
                     int length,
                     int *value)
{
    if (!value || length > sizeof(int)) {
        return SQLITERK_MISUSE;
    }
    int64_t out;
    int rc = sqliterkParseInt64(data, offset, length, &out);
    if (rc != SQLITERK_OK) {
        return rc;
    }
    *value = (int) out;
    return SQLITERK_OK;
}

int sqliterkParseInt64(const unsigned char *data,
                       int offset,
                       int length,
                       int64_t *value)
{
    if (!data || !value)
        return SQLITERK_MISUSE;

    const unsigned char *p = data + offset;
    int64_t out;

    switch (length) {
        case 1:
            out = (int8_t) p[0];
            break;
        case 2:
            out = (((int8_t) p[0]) * 256) | p[1];
            break;
        case 3:
            out = (((int8_t) p[0]) * 65536) | (p[1] << 8) | p[2];
            break;
        case 4:
            out = (((int8_t) p[0]) * 16777216) | (p[1] << 16) | (p[2] << 8) |
                  p[3];
            break;
        case 6:
            out = (((int8_t) p[0]) * 256) | p[1];
            out *= ((int64_t) 1) << 32;
            out +=
                (((uint32_t) p[2]) << 24) | (p[3] << 16) | (p[4] << 8) | p[5];
            break;
        case 8:
            out = (((int8_t) p[0]) * 16777216) | (p[1] << 16) | (p[2] << 8) |
                  p[3];
            out *= ((int64_t) 1) << 32;
            out +=
                (((uint32_t) p[4]) << 24) | (p[5] << 16) | (p[6] << 8) | p[7];
            break;
        default:
            return SQLITERK_MISUSE;
    }

    *value = out;
    return SQLITERK_OK;
}

int sqliterkParseVarint(const unsigned char *data,
                        int offset,
                        int *length,
                        int *value)
{
    if (!value) {
        return SQLITERK_MISUSE;
    }
    int64_t out;
    int rc = sqliterkParseVarint64(data, offset, length, &out);
    if (rc != SQLITERK_OK) {
        return rc;
    }
    *value = (int) out;
    return SQLITERK_OK;
}

int sqliterkParseVarint64(const unsigned char *data,
                          int offset,
                          int *length,
                          int64_t *value)
{
    if (!data || !length || !value) {
        return SQLITERK_MISUSE;
    }
    int64_t out = 0;
    const unsigned char *begin = data + offset;
    int i = 0;
    while ((begin[i] & 0x80) && i < sqliterkGetMaxVarintLength()) {
        out |= (begin[i] & 0x7f);
        out = (out << 7);
        i++;
        if (i >= sqliterkGetMaxVarintLength()) {
            return SQLITERK_DAMAGED;
        }
    }
    out |= begin[i];
    *length = i + 1;
    *value = out;
    return SQLITERK_OK;
}

int sqliterkGetMaxVarintLength()
{
    return 9;
}

int sqliterkParseNumber(const unsigned char *data, int offset, double *value)
{
    if (!data || !value) {
        return SQLITERK_MISUSE;
    }
    unsigned char out[8];
    const unsigned char *begin = data + offset;
    int i;
    for (i = 0; i < 8; i++) {
        // All float values in SQLite is big-endian with 8 lengths.
        // For further informantion, see [Record Format] chapter at
        // https://www.sqlite.org/fileformat2.html
        out[i] = begin[8 - 1 - i];
    }
    memcpy(value, out, 8);
    return SQLITERK_OK;
}

const char *sqliterkGetResultCodeDescription(int result)
{
    switch (result) {
        case SQLITERK_OK:
            return "SQLITERK_OK";
        case SQLITERK_CANTOPEN:
            return "SQLITERK_CANTOPEN";
        case SQLITERK_MISUSE:
            return "SQLITERK_MISUSE";
        case SQLITERK_IOERR:
            return "SQLITERK_IOERR";
        case SQLITERK_NOMEM:
            return "SQLITERK_NOMEM";
        case SQLITERK_SHORT_READ:
            return "SQLITERK_SHORT_READ";
        case SQLITERK_DAMAGED:
            return "SQLITERK_DAMAGED";
        case SQLITERK_DISCARD:
            return "SQLITERK_DISCARD";
        default:
            break;
    }
    return "SQLITERK_UNKNOWN";
}

