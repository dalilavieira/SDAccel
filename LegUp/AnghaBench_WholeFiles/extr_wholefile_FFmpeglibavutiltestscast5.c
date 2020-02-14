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
struct AVCAST5 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 struct AVCAST5* av_cast5_alloc () ; 
 int /*<<< orphan*/  av_cast5_crypt (struct AVCAST5*,int*,int const*,int,int) ; 
 int /*<<< orphan*/  av_cast5_crypt2 (struct AVCAST5*,int*,int const*,int,int*,int) ; 
 int /*<<< orphan*/  av_cast5_init (struct AVCAST5*,int const*,int const) ; 
 int /*<<< orphan*/  av_free (struct AVCAST5*) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int,int const,int) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 

int main(int argc, char** argv)
{

    static const uint8_t Key[3][16] = {
        {0x01, 0x23, 0x45, 0x67, 0x12, 0x34, 0x56, 0x78, 0x23, 0x45, 0x67, 0x89, 0x34, 0x56, 0x78, 0x9a},
        {0x01, 0x23, 0x45, 0x67, 0x12, 0x34, 0x56, 0x78, 0x23, 0x45},
        {0x01, 0x23, 0x45, 0x67, 0x12}
    };
    static const uint8_t rpt[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    static const uint8_t rct[3][8] = {
        {0x23, 0x8b, 0x4f, 0xe5, 0x84, 0x7e, 0x44, 0xb2},
        {0xeb, 0x6a, 0x71, 0x1a, 0x2c, 0x02, 0x27, 0x1b},
        {0x7a, 0xc8, 0x16, 0xd1, 0x6e, 0x9b, 0x30, 0x2e}
    };
    static const uint8_t rct2[2][16] = {
        {0xee, 0xa9, 0xd0, 0xa2, 0x49, 0xfd, 0x3b, 0xa6, 0xb3, 0x43, 0x6f, 0xb8, 0x9d, 0x6d, 0xca, 0x92},
        {0xb2, 0xc9, 0x5e, 0xb0, 0x0c, 0x31, 0xad, 0x71, 0x80, 0xac, 0x05, 0xb8, 0xe8, 0x3d, 0x69, 0x6e}
    };
    static const uint8_t iv[8] = {0xee, 0xa9, 0xd0, 0xa2, 0x49, 0xfd, 0x3b, 0xa6};
    static uint8_t rpt2[2][16];
    int i, j, err = 0;
    static const int key_bits[3] = {128, 80, 40};
    uint8_t temp[8];
    struct AVCAST5 *cs;
    cs = av_cast5_alloc();
    if (!cs)
        return 1;
    for (j = 0; j < 3; j++){

        av_cast5_init(cs, Key[j], key_bits[j]);
        av_cast5_crypt(cs, temp, rpt, 1, 0);
        for (i = 0;i < 8; i++){
            if (rct[j][i] != temp[i]){
                av_log(NULL, AV_LOG_ERROR, "%d %02x %02x\n", i, rct[j][i], temp[i]);
                err = 1;
            }
        }

        av_cast5_crypt(cs, temp, rct[j], 1, 1);
        for (i =0; i < 8; i++) {
            if (rpt[i] != temp[i]) {
                av_log(NULL, AV_LOG_ERROR, "%d %02x %02x\n", i, rpt[i], temp[i]);
                err = 1;
            }
        }
    }
    memcpy(rpt2[0], Key[0], 16);
    memcpy(rpt2[1], Key[0], 16);
    for (i = 0; i < 1000000; i++){
        av_cast5_init(cs, rpt2[1], 128);
        av_cast5_crypt(cs, rpt2[0], rpt2[0], 2, 0);
        av_cast5_init(cs, rpt2[0], 128);
        av_cast5_crypt(cs, rpt2[1], rpt2[1], 2, 0);
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 16; i++) {
            if (rct2[j][i] != rpt2[j][i]) {
                av_log(NULL, AV_LOG_ERROR, "%d %02x %02x\n", i, rct2[j][i], rpt2[j][i]);
                err = 1;
            }
        }
    }
    for (j = 0; j < 3; j++) {

        av_cast5_init(cs, Key[j], key_bits[j]);
        memcpy(temp, iv, 8);
        av_cast5_crypt2(cs, rpt2[0], rct2[0], 2, temp, 0);
        memcpy(temp, iv, 8);
        av_cast5_crypt2(cs, rpt2[0], rpt2[0], 2, temp, 1);
        for (i = 0; i < 16; i++) {
            if (rct2[0][i] != rpt2[0][i]) {
                av_log(NULL, AV_LOG_ERROR, "%d %02x %02x\n", i, rct2[0][i], rpt2[0][i]);
                err = 1;
            }
        }
    }
    av_free(cs);
    return err;
}

