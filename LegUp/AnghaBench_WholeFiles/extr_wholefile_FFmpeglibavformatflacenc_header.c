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
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  AVIOContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 scalar_t__ AV_CH_LAYOUT_5POINT0 ; 
 scalar_t__ AV_CH_LAYOUT_5POINT1 ; 
 scalar_t__ AV_CH_LAYOUT_6POINT1 ; 
 scalar_t__ AV_CH_LAYOUT_7POINT1 ; 
 scalar_t__ AV_CH_LAYOUT_MONO ; 
 scalar_t__ AV_CH_LAYOUT_QUAD ; 
 scalar_t__ AV_CH_LAYOUT_STEREO ; 
 scalar_t__ AV_CH_LAYOUT_SURROUND ; 
 int FLAC_STREAMINFO_SIZE ; 
 int /*<<< orphan*/  avio_write (int /*<<< orphan*/ *,int*,int) ; 

int ff_flac_write_header(AVIOContext *pb, uint8_t *extradata,
                         int extradata_size, int last_block)
{
    uint8_t header[8] = {
        0x66, 0x4C, 0x61, 0x43, 0x00, 0x00, 0x00, 0x22
    };

    header[4] = last_block ? 0x80 : 0x00;

    if (extradata_size < FLAC_STREAMINFO_SIZE)
        return AVERROR_INVALIDDATA;

    /* write "fLaC" stream marker and first metadata block header */
    avio_write(pb, header, 8);

    /* write STREAMINFO */
    avio_write(pb, extradata, FLAC_STREAMINFO_SIZE);

    return 0;
}

int ff_flac_is_native_layout(uint64_t channel_layout)
{
    if (channel_layout == AV_CH_LAYOUT_MONO     ||
        channel_layout == AV_CH_LAYOUT_STEREO   ||
        channel_layout == AV_CH_LAYOUT_SURROUND ||
        channel_layout == AV_CH_LAYOUT_QUAD     ||
        channel_layout == AV_CH_LAYOUT_5POINT0  ||
        channel_layout == AV_CH_LAYOUT_5POINT1  ||
        channel_layout == AV_CH_LAYOUT_6POINT1  ||
        channel_layout == AV_CH_LAYOUT_7POINT1)
        return 1;
    return 0;
}

