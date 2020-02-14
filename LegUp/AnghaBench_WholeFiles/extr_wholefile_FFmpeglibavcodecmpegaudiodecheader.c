#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  enum AVCodecID { ____Placeholder_AVCodecID } AVCodecID ;
struct TYPE_3__ {int lsf; int layer; int sample_rate_index; int error_protection; int sample_rate; int mode; int mode_ext; int nb_channels; int bit_rate; int frame_size; } ;
typedef  TYPE_1__ MPADecodeHeader ;

/* Variables and functions */
 int AV_CODEC_ID_MP1 ; 
 int AV_CODEC_ID_MP2 ; 
 int AV_CODEC_ID_MP3 ; 
 int AV_CODEC_ID_MP3ADU ; 
 int FF_ARRAY_ELEMS (int*) ; 
 int MPA_MONO ; 
 int*** avpriv_mpa_bitrate_tab ; 
 int* avpriv_mpa_freq_tab ; 

__attribute__((used)) static inline int ff_mpa_check_header(uint32_t header){
    /* header */
    if ((header & 0xffe00000) != 0xffe00000)
        return -1;
    /* version check */
    if ((header & (3<<19)) == 1<<19)
        return -1;
    /* layer check */
    if ((header & (3<<17)) == 0)
        return -1;
    /* bit rate */
    if ((header & (0xf<<12)) == 0xf<<12)
        return -1;
    /* frequency */
    if ((header & (3<<10)) == 3<<10)
        return -1;
    return 0;
}

int avpriv_mpegaudio_decode_header(MPADecodeHeader *s, uint32_t header)
{
    int sample_rate, frame_size, mpeg25, padding;
    int sample_rate_index, bitrate_index;
    int ret;

    ret = ff_mpa_check_header(header);
    if (ret < 0)
        return ret;

    if (header & (1<<20)) {
        s->lsf = (header & (1<<19)) ? 0 : 1;
        mpeg25 = 0;
    } else {
        s->lsf = 1;
        mpeg25 = 1;
    }

    s->layer = 4 - ((header >> 17) & 3);
    /* extract frequency */
    sample_rate_index = (header >> 10) & 3;
    if (sample_rate_index >= FF_ARRAY_ELEMS(avpriv_mpa_freq_tab))
        sample_rate_index = 0;
    sample_rate = avpriv_mpa_freq_tab[sample_rate_index] >> (s->lsf + mpeg25);
    sample_rate_index += 3 * (s->lsf + mpeg25);
    s->sample_rate_index = sample_rate_index;
    s->error_protection = ((header >> 16) & 1) ^ 1;
    s->sample_rate = sample_rate;

    bitrate_index = (header >> 12) & 0xf;
    padding = (header >> 9) & 1;
    //extension = (header >> 8) & 1;
    s->mode = (header >> 6) & 3;
    s->mode_ext = (header >> 4) & 3;
    //copyright = (header >> 3) & 1;
    //original = (header >> 2) & 1;
    //emphasis = header & 3;

    if (s->mode == MPA_MONO)
        s->nb_channels = 1;
    else
        s->nb_channels = 2;

    if (bitrate_index != 0) {
        frame_size = avpriv_mpa_bitrate_tab[s->lsf][s->layer - 1][bitrate_index];
        s->bit_rate = frame_size * 1000;
        switch(s->layer) {
        case 1:
            frame_size = (frame_size * 12000) / sample_rate;
            frame_size = (frame_size + padding) * 4;
            break;
        case 2:
            frame_size = (frame_size * 144000) / sample_rate;
            frame_size += padding;
            break;
        default:
        case 3:
            frame_size = (frame_size * 144000) / (sample_rate << s->lsf);
            frame_size += padding;
            break;
        }
        s->frame_size = frame_size;
    } else {
        /* if no frame size computed, signal it */
        return 1;
    }

#if defined(DEBUG)
    ff_dlog(NULL, "layer%d, %d Hz, %d kbits/s, ",
           s->layer, s->sample_rate, s->bit_rate);
    if (s->nb_channels == 2) {
        if (s->layer == 3) {
            if (s->mode_ext & MODE_EXT_MS_STEREO)
                ff_dlog(NULL, "ms-");
            if (s->mode_ext & MODE_EXT_I_STEREO)
                ff_dlog(NULL, "i-");
        }
        ff_dlog(NULL, "stereo");
    } else {
        ff_dlog(NULL, "mono");
    }
    ff_dlog(NULL, "\n");
#endif
    return 0;
}

int ff_mpa_decode_header(uint32_t head, int *sample_rate, int *channels, int *frame_size, int *bit_rate, enum AVCodecID *codec_id)
{
    MPADecodeHeader s1, *s = &s1;

    if (avpriv_mpegaudio_decode_header(s, head) != 0) {
        return -1;
    }

    switch(s->layer) {
    case 1:
        *codec_id = AV_CODEC_ID_MP1;
        *frame_size = 384;
        break;
    case 2:
        *codec_id = AV_CODEC_ID_MP2;
        *frame_size = 1152;
        break;
    default:
    case 3:
        if (*codec_id != AV_CODEC_ID_MP3ADU)
            *codec_id = AV_CODEC_ID_MP3;
        if (s->lsf)
            *frame_size = 576;
        else
            *frame_size = 1152;
        break;
    }

    *sample_rate = s->sample_rate;
    *channels = s->nb_channels;
    *bit_rate = s->bit_rate;
    return s->frame_size;
}

