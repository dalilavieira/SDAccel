#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_18__ {int* data; int /*<<< orphan*/  stream_index; } ;
struct TYPE_17__ {int /*<<< orphan*/  index; } ;
struct TYPE_16__ {int size; size_t pos; int* data; } ;
struct TYPE_15__ {int interleave_size; int interleave_index; int group_finished; int* next_data; int next_size; int /*<<< orphan*/  next_timestamp; TYPE_2__* group; } ;
typedef  TYPE_1__ PayloadContext ;
typedef  TYPE_2__ InterleavePacket ;
typedef  TYPE_3__ AVStream ;
typedef  TYPE_4__ AVPacket ;
typedef  int /*<<< orphan*/  AVFormatContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int const FF_ARRAY_ELEMS (int*) ; 
 int /*<<< orphan*/  RTP_NOTS_VALUE ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int,...) ; 
 int av_new_packet (TYPE_4__*,int) ; 
 int* frame_sizes ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 
static  int return_stored_frame (int /*<<< orphan*/ *,TYPE_1__*,TYPE_3__*,TYPE_4__*,int /*<<< orphan*/ *,int const*,int) ; 

__attribute__((used)) static int store_packet(AVFormatContext *ctx, PayloadContext *data,
                        AVStream *st, AVPacket *pkt, uint32_t *timestamp,
                        const uint8_t *buf, int len)
{
    int interleave_size, interleave_index;
    int frame_size, ret;
    InterleavePacket* ip;

    if (len < 2)
        return AVERROR_INVALIDDATA;

    interleave_size  = buf[0] >> 3 & 7;
    interleave_index = buf[0]      & 7;

    if (interleave_size > 5) {
        av_log(ctx, AV_LOG_ERROR, "Invalid interleave size %d\n",
                                   interleave_size);
        return AVERROR_INVALIDDATA;
    }
    if (interleave_index > interleave_size) {
        av_log(ctx, AV_LOG_ERROR, "Invalid interleave index %d/%d\n",
                                   interleave_index, interleave_size);
        return AVERROR_INVALIDDATA;
    }
    if (interleave_size != data->interleave_size) {
        int i;
        /* First packet, or changed interleave size */
        data->interleave_size = interleave_size;
        data->interleave_index = 0;
        for (i = 0; i < 6; i++)
            data->group[i].size = 0;
    }

    if (interleave_index < data->interleave_index) {
        /* Wrapped around - missed the last packet of the previous group. */
        if (data->group_finished) {
            /* No more data in the packets in this interleaving group, just
             * start processing the next one */
            data->interleave_index = 0;
        } else {
            /* Stash away the current packet, emit everything we have of the
             * previous group. */
            for (; data->interleave_index <= interleave_size;
                 data->interleave_index++)
                data->group[data->interleave_index].size = 0;

            if (len > sizeof(data->next_data))
                return AVERROR_INVALIDDATA;
            memcpy(data->next_data, buf, len);
            data->next_size = len;
            data->next_timestamp = *timestamp;
            *timestamp = RTP_NOTS_VALUE;

            data->interleave_index = 0;
            return return_stored_frame(ctx, data, st, pkt, timestamp, buf, len);
        }
    }
    if (interleave_index > data->interleave_index) {
        /* We missed a packet */
        for (; data->interleave_index < interleave_index;
             data->interleave_index++)
            data->group[data->interleave_index].size = 0;
    }
    data->interleave_index = interleave_index;

    if (buf[1] >= FF_ARRAY_ELEMS(frame_sizes))
        return AVERROR_INVALIDDATA;
    frame_size = frame_sizes[buf[1]];
    if (1 + frame_size > len)
        return AVERROR_INVALIDDATA;

    if (len - 1 - frame_size > sizeof(data->group[0].data))
        return AVERROR_INVALIDDATA;

    if ((ret = av_new_packet(pkt, frame_size)) < 0)
        return ret;
    memcpy(pkt->data, &buf[1], frame_size);
    pkt->stream_index = st->index;

    ip = &data->group[data->interleave_index];
    ip->size = len - 1 - frame_size;
    ip->pos = 0;
    memcpy(ip->data, &buf[1 + frame_size], ip->size);
    /* Each packet must contain the same number of frames according to the
     * RFC. If there's no data left in this packet, there shouldn't be any
     * in any of the other frames in the interleaving group either. */
    data->group_finished = ip->size == 0;

    if (interleave_index == interleave_size) {
        data->interleave_index = 0;
        return !data->group_finished;
    } else {
        data->interleave_index++;
        return 0;
    }
}

__attribute__((used)) static int return_stored_frame(AVFormatContext *ctx, PayloadContext *data,
                               AVStream *st, AVPacket *pkt, uint32_t *timestamp,
                               const uint8_t *buf, int len)
{
    InterleavePacket* ip = &data->group[data->interleave_index];
    int frame_size, ret;

    if (data->group_finished && data->interleave_index == 0) {
        *timestamp = data->next_timestamp;
        ret = store_packet(ctx, data, st, pkt, timestamp, data->next_data,
                           data->next_size);
        data->next_size = 0;
        return ret;
    }

    if (ip->size == 0) {
        /* No stored data for this interleave block, output an empty packet */
        if ((ret = av_new_packet(pkt, 1)) < 0)
            return ret;
        pkt->data[0] = 0; // Blank - could also be 14, Erasure
    } else {
        if (ip->pos >= ip->size)
            return AVERROR_INVALIDDATA;
        if (ip->data[ip->pos] >= FF_ARRAY_ELEMS(frame_sizes))
            return AVERROR_INVALIDDATA;
        frame_size = frame_sizes[ip->data[ip->pos]];
        if (ip->pos + frame_size > ip->size)
            return AVERROR_INVALIDDATA;

        if ((ret = av_new_packet(pkt, frame_size)) < 0)
            return ret;
        memcpy(pkt->data, &ip->data[ip->pos], frame_size);

        ip->pos += frame_size;
        data->group_finished = ip->pos >= ip->size;
    }
    pkt->stream_index = st->index;

    if (data->interleave_index == data->interleave_size) {
        data->interleave_index = 0;
        if (!data->group_finished)
            return 1;
        else
            return data->next_size > 0;
    } else {
        data->interleave_index++;
        return 1;
    }
}

__attribute__((used)) static int qcelp_parse_packet(AVFormatContext *ctx, PayloadContext *data,
                              AVStream *st, AVPacket *pkt, uint32_t *timestamp,
                              const uint8_t *buf, int len, uint16_t seq,
                              int flags)
{
    if (buf)
        return store_packet(ctx, data, st, pkt, timestamp, buf, len);
    else
        return return_stored_frame(ctx, data, st, pkt, timestamp, buf, len);
}

