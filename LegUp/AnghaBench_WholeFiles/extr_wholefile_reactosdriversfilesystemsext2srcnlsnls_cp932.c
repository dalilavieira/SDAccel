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
typedef  int wchar_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENAMETOOLONG ; 
 int** page_charset2uni ; 
 unsigned char** page_uni2charset ; 
 unsigned char** u2c_00hi ; 

__attribute__((used)) static int uni2char(const wchar_t uni,
                    unsigned char *out, int boundlen)
{
    unsigned char *uni2charset;
    unsigned char cl = uni&0xFF;
    unsigned char ch = (uni>>8)&0xFF;

    if (boundlen <= 0)
        return -ENAMETOOLONG;

    if (ch == 0xFF && 0x61 <= cl && cl <= 0x9F) {
        out[0] = cl + 0x40;
        return 1;
    }
    uni2charset = page_uni2charset[ch];
    if (uni2charset) {
        if (boundlen < 2)
            return -ENAMETOOLONG;

        out[0] = uni2charset[cl*2];
        out[1] = uni2charset[cl*2+1];
        if (out[0] == 0x00 && out[1] == 0x00)
            return -EINVAL;
        return 2;
    } else if (ch == 0) {
        if (cl <= 0x7F) {
            out[0] = cl;
            return 1;
        } else if (0xA0 <= cl) {
            out[0] = u2c_00hi[cl - 0xA0][0];
            out[1] = u2c_00hi[cl - 0xA0][1];
            if (out[0] && out[1])
                return 2;
        }
        return -EINVAL;
    }
    else
        return -EINVAL;
}

__attribute__((used)) static int char2uni(const unsigned char *rawstring, int boundlen,
                    wchar_t *uni)
{
    unsigned char ch, cl;
    wchar_t *charset2uni;

    if (boundlen <= 0)
        return -ENAMETOOLONG;

    if (rawstring[0] <= 0x7F) {
        *uni = rawstring[0];
        return 1;
    }
    if (0xA1 <= rawstring[0] && rawstring[0] <= 0xDF) {
        *uni = 0xFF00 | (rawstring[0] - 0x40);
        return 1;
    }

    if (boundlen < 2)
        return -ENAMETOOLONG;
    ch = rawstring[0];
    cl = rawstring[1];
    charset2uni = page_charset2uni[ch];
    if (charset2uni && cl) {
        *uni = charset2uni[cl];
        if (*uni == 0x0000)
            return -EINVAL;
        return 2;
    }
    else
        return -EINVAL;
}

