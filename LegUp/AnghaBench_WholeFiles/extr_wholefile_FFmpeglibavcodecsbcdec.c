#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
struct sbc_frame {int frequency; int blocks; int allocation; int mode; int channels; int subbands; int bitpool; int joint; int** scale_factor; int*** sb_sample; int /*<<< orphan*/  crc_ctx; } ;
struct sbc_decoder_state {int** V; int** offset; } ;
typedef  int int32_t ;
struct TYPE_16__ {TYPE_1__* priv_data; } ;
struct TYPE_15__ {int channels; int nb_samples; int /*<<< orphan*/  format; int /*<<< orphan*/ ** data; } ;
struct TYPE_14__ {int* data; size_t size; } ;
struct TYPE_13__ {struct sbc_frame frame; struct sbc_decoder_state dsp; } ;
typedef  TYPE_1__ SBCDecContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_CRC_8_EBU ; 
 int /*<<< orphan*/  AV_SAMPLE_FMT_S16P ; 
 int /*<<< orphan*/  AV_WN16A (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int DUAL_CHANNEL ; 
 int /*<<< orphan*/  EIO ; 
 int FF_ARRAY_ELEMS (int*) ; 
 int JOINT_STEREO ; 
 int LOUDNESS ; 
 int MONO ; 
 int MSBC_BLOCKS ; 
 int const MSBC_SYNCWORD ; 
 int SBCDEC_FIXED_EXTRA_BITS ; 
 int SBC_FREQ_16000 ; 
 int const SBC_SYNCWORD ; 
 int STEREO ; 
 int /*<<< orphan*/  av_clip_int16 (int) ; 
 int /*<<< orphan*/  av_crc_get_table (int /*<<< orphan*/ ) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_sbc_calculate_bits (struct sbc_frame*,int**) ; 
 int const ff_sbc_crc8 (int /*<<< orphan*/ ,int*,int) ; 
 int* ff_sbc_proto_4_40m0 ; 
 int* ff_sbc_proto_4_40m1 ; 
 int* ff_sbc_proto_8_80m0 ; 
 int* ff_sbc_proto_8_80m1 ; 
 int** ff_synmatrix4 ; 
 int** ff_synmatrix8 ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int**,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int sbc_unpack_frame(const uint8_t *data, struct sbc_frame *frame,
                            size_t len)
{
    unsigned int consumed;
    /* Will copy the parts of the header that are relevant to crc
     * calculation here */
    uint8_t crc_header[11] = { 0 };
    int crc_pos;
    int32_t temp;

    uint32_t audio_sample;
    int ch, sb, blk, bit;   /* channel, subband, block and bit standard
                               counters */
    int bits[2][8];         /* bits distribution */
    uint32_t levels[2][8];  /* levels derived from that */

    if (len < 4)
        return -1;

    if (data[0] == MSBC_SYNCWORD) {
        if (data[1] != 0)
            return -2;
        if (data[2] != 0)
            return -2;

        frame->frequency = SBC_FREQ_16000;
        frame->blocks = MSBC_BLOCKS;
        frame->allocation = LOUDNESS;
        frame->mode = MONO;
        frame->channels = 1;
        frame->subbands = 8;
        frame->bitpool = 26;
    } else if (data[0] == SBC_SYNCWORD) {
        frame->frequency  = (data[1] >> 6) & 0x03;
        frame->blocks = 4 * ((data[1] >> 4) & 0x03) + 4;
        frame->mode = (data[1] >> 2) & 0x03;
        frame->channels = frame->mode == MONO ? 1 : 2;
        frame->allocation = (data[1] >> 1) & 0x01;
        frame->subbands = data[1] & 0x01 ? 8 : 4;
        frame->bitpool = data[2];

        if ((frame->mode == MONO || frame->mode == DUAL_CHANNEL) &&
            frame->bitpool > 16 * frame->subbands)
            return -4;

        if ((frame->mode == STEREO || frame->mode == JOINT_STEREO) &&
            frame->bitpool > 32 * frame->subbands)
            return -4;
    } else
        return -2;

    consumed = 32;
    crc_header[0] = data[1];
    crc_header[1] = data[2];
    crc_pos = 16;

    if (frame->mode == JOINT_STEREO) {
        if (len * 8 < consumed + frame->subbands)
            return -1;

        frame->joint = 0x00;
        for (sb = 0; sb < frame->subbands - 1; sb++)
            frame->joint |= ((data[4] >> (7 - sb)) & 0x01) << sb;
        if (frame->subbands == 4)
            crc_header[crc_pos / 8] = data[4] & 0xf0;
        else
            crc_header[crc_pos / 8] = data[4];

        consumed += frame->subbands;
        crc_pos += frame->subbands;
    }

    if (len * 8 < consumed + (4 * frame->subbands * frame->channels))
        return -1;

    for (ch = 0; ch < frame->channels; ch++) {
        for (sb = 0; sb < frame->subbands; sb++) {
            /* FIXME assert(consumed % 4 == 0); */
            frame->scale_factor[ch][sb] =
                (data[consumed >> 3] >> (4 - (consumed & 0x7))) & 0x0F;
            crc_header[crc_pos >> 3] |=
                frame->scale_factor[ch][sb] << (4 - (crc_pos & 0x7));

            consumed += 4;
            crc_pos += 4;
        }
    }

    if (data[3] != ff_sbc_crc8(frame->crc_ctx, crc_header, crc_pos))
        return -3;

    ff_sbc_calculate_bits(frame, bits);

    for (ch = 0; ch < frame->channels; ch++) {
        for (sb = 0; sb < frame->subbands; sb++)
            levels[ch][sb] = (1 << bits[ch][sb]) - 1;
    }

    for (blk = 0; blk < frame->blocks; blk++) {
        for (ch = 0; ch < frame->channels; ch++) {
            for (sb = 0; sb < frame->subbands; sb++) {
                uint32_t shift;

                if (levels[ch][sb] == 0) {
                    frame->sb_sample[blk][ch][sb] = 0;
                    continue;
                }

                shift = frame->scale_factor[ch][sb] +
                        1 + SBCDEC_FIXED_EXTRA_BITS;

                audio_sample = 0;
                for (bit = 0; bit < bits[ch][sb]; bit++) {
                    if (consumed > len * 8)
                        return -1;

                    if ((data[consumed >> 3] >> (7 - (consumed & 0x7))) & 0x01)
                        audio_sample |= 1 << (bits[ch][sb] - bit - 1);

                    consumed++;
                }

                frame->sb_sample[blk][ch][sb] = (int32_t)
                    (((((uint64_t) audio_sample << 1) | 1) << shift) /
                    levels[ch][sb]) - (1 << shift);
            }
        }
    }

    if (frame->mode == JOINT_STEREO) {
        for (blk = 0; blk < frame->blocks; blk++) {
            for (sb = 0; sb < frame->subbands; sb++) {
                if (frame->joint & (0x01 << sb)) {
                    temp = frame->sb_sample[blk][0][sb] +
                           frame->sb_sample[blk][1][sb];
                    frame->sb_sample[blk][1][sb] =
                        frame->sb_sample[blk][0][sb] -
                        frame->sb_sample[blk][1][sb];
                    frame->sb_sample[blk][0][sb] = temp;
                }
            }
        }
    }

    if ((consumed & 0x7) != 0)
        consumed += 8 - (consumed & 0x7);

    return consumed >> 3;
}

__attribute__((used)) static inline void sbc_synthesize_four(struct sbc_decoder_state *state,
                                       struct sbc_frame *frame,
                                       int ch, int blk, AVFrame *output_frame)
{
    int i, k, idx;
    int32_t *v = state->V[ch];
    int *offset = state->offset[ch];

    for (i = 0; i < 8; i++) {
        /* Shifting */
        offset[i]--;
        if (offset[i] < 0) {
            offset[i] = 79;
            memcpy(v + 80, v, 9 * sizeof(*v));
        }

        /* Distribute the new matrix value to the shifted position */
        v[offset[i]] =
            ( ff_synmatrix4[i][0] * frame->sb_sample[blk][ch][0] +
              ff_synmatrix4[i][1] * frame->sb_sample[blk][ch][1] +
              ff_synmatrix4[i][2] * frame->sb_sample[blk][ch][2] +
              ff_synmatrix4[i][3] * frame->sb_sample[blk][ch][3] ) >> 15;
    }

    /* Compute the samples */
    for (idx = 0, i = 0; i < 4; i++, idx += 5) {
        k = (i + 4) & 0xf;

        /* Store in output, Q0 */
        AV_WN16A(&output_frame->data[ch][blk * 8 + i * 2], av_clip_int16(
            ( v[offset[i] + 0] * ff_sbc_proto_4_40m0[idx + 0] +
              v[offset[k] + 1] * ff_sbc_proto_4_40m1[idx + 0] +
              v[offset[i] + 2] * ff_sbc_proto_4_40m0[idx + 1] +
              v[offset[k] + 3] * ff_sbc_proto_4_40m1[idx + 1] +
              v[offset[i] + 4] * ff_sbc_proto_4_40m0[idx + 2] +
              v[offset[k] + 5] * ff_sbc_proto_4_40m1[idx + 2] +
              v[offset[i] + 6] * ff_sbc_proto_4_40m0[idx + 3] +
              v[offset[k] + 7] * ff_sbc_proto_4_40m1[idx + 3] +
              v[offset[i] + 8] * ff_sbc_proto_4_40m0[idx + 4] +
              v[offset[k] + 9] * ff_sbc_proto_4_40m1[idx + 4] ) >> 15));
    }
}

__attribute__((used)) static inline void sbc_synthesize_eight(struct sbc_decoder_state *state,
                                        struct sbc_frame *frame,
                                        int ch, int blk, AVFrame *output_frame)
{
    int i, k, idx;
    int32_t *v = state->V[ch];
    int *offset = state->offset[ch];

    for (i = 0; i < 16; i++) {
        /* Shifting */
        offset[i]--;
        if (offset[i] < 0) {
            offset[i] = 159;
            memcpy(v + 160, v, 9 * sizeof(*v));
        }

        /* Distribute the new matrix value to the shifted position */
        v[offset[i]] =
            ( ff_synmatrix8[i][0] * frame->sb_sample[blk][ch][0] +
              ff_synmatrix8[i][1] * frame->sb_sample[blk][ch][1] +
              ff_synmatrix8[i][2] * frame->sb_sample[blk][ch][2] +
              ff_synmatrix8[i][3] * frame->sb_sample[blk][ch][3] +
              ff_synmatrix8[i][4] * frame->sb_sample[blk][ch][4] +
              ff_synmatrix8[i][5] * frame->sb_sample[blk][ch][5] +
              ff_synmatrix8[i][6] * frame->sb_sample[blk][ch][6] +
              ff_synmatrix8[i][7] * frame->sb_sample[blk][ch][7] ) >> 15;
    }

    /* Compute the samples */
    for (idx = 0, i = 0; i < 8; i++, idx += 5) {
        k = (i + 8) & 0xf;

        /* Store in output, Q0 */
        AV_WN16A(&output_frame->data[ch][blk * 16 + i * 2], av_clip_int16(
            ( v[offset[i] + 0] * ff_sbc_proto_8_80m0[idx + 0] +
              v[offset[k] + 1] * ff_sbc_proto_8_80m1[idx + 0] +
              v[offset[i] + 2] * ff_sbc_proto_8_80m0[idx + 1] +
              v[offset[k] + 3] * ff_sbc_proto_8_80m1[idx + 1] +
              v[offset[i] + 4] * ff_sbc_proto_8_80m0[idx + 2] +
              v[offset[k] + 5] * ff_sbc_proto_8_80m1[idx + 2] +
              v[offset[i] + 6] * ff_sbc_proto_8_80m0[idx + 3] +
              v[offset[k] + 7] * ff_sbc_proto_8_80m1[idx + 3] +
              v[offset[i] + 8] * ff_sbc_proto_8_80m0[idx + 4] +
              v[offset[k] + 9] * ff_sbc_proto_8_80m1[idx + 4] ) >> 15));
    }
}

__attribute__((used)) static void sbc_synthesize_audio(struct sbc_decoder_state *state,
                                 struct sbc_frame *frame, AVFrame *output_frame)
{
    int ch, blk;

    switch (frame->subbands) {
    case 4:
        for (ch = 0; ch < frame->channels; ch++)
            for (blk = 0; blk < frame->blocks; blk++)
                sbc_synthesize_four(state, frame, ch, blk, output_frame);
        break;

    case 8:
        for (ch = 0; ch < frame->channels; ch++)
            for (blk = 0; blk < frame->blocks; blk++)
                sbc_synthesize_eight(state, frame, ch, blk, output_frame);
        break;
    }
}

__attribute__((used)) static int sbc_decode_init(AVCodecContext *avctx)
{
    SBCDecContext *sbc = avctx->priv_data;
    int i, ch;

    sbc->frame.crc_ctx = av_crc_get_table(AV_CRC_8_EBU);

    memset(sbc->dsp.V, 0, sizeof(sbc->dsp.V));
    for (ch = 0; ch < 2; ch++)
        for (i = 0; i < FF_ARRAY_ELEMS(sbc->dsp.offset[0]); i++)
            sbc->dsp.offset[ch][i] = (10 * i + 10);
    return 0;
}

__attribute__((used)) static int sbc_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame_ptr,
                            AVPacket *avpkt)
{
    SBCDecContext *sbc = avctx->priv_data;
    AVFrame *frame = data;
    int ret, frame_length;

    if (!sbc)
        return AVERROR(EIO);

    frame_length = sbc_unpack_frame(avpkt->data, &sbc->frame, avpkt->size);
    if (frame_length <= 0)
        return frame_length;

    frame->channels = sbc->frame.channels;
    frame->format = AV_SAMPLE_FMT_S16P;
    frame->nb_samples = sbc->frame.blocks * sbc->frame.subbands;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    sbc_synthesize_audio(&sbc->dsp, &sbc->frame, frame);

    *got_frame_ptr = 1;

    return frame_length;
}

