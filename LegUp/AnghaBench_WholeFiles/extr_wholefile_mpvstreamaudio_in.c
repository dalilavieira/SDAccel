#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct mp_log {int dummy; } ;
struct TYPE_10__ {int type; int channels; int samplerate; int blocksize; int bytes_per_sample; int samplesize; scalar_t__ setup; struct mp_log* log; } ;
typedef  TYPE_1__ audio_in_t ;

/* Variables and functions */

int audio_in_init(audio_in_t *ai, struct mp_log *log, int type)
{
    ai->type = type;
    ai->setup = 0;
    ai->log = log;

    ai->channels = -1;
    ai->samplerate = -1;
    ai->blocksize = -1;
    ai->bytes_per_sample = -1;
    ai->samplesize = -1;

    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        ai->alsa.handle = NULL;
        ai->alsa.log = NULL;
        ai->alsa.device = NULL;
        return 0;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        ai->oss.audio_fd = -1;
        ai->oss.device = NULL;
        return 0;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
        ai->sndio.hdl = NULL;
        ai->sndio.device = NULL;
        return 0;
#endif
    default:
        return -1;
    }
}

int audio_in_setup(audio_in_t *ai)
{

    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        if (ai_alsa_init(ai) < 0) return -1;
        ai->setup = 1;
        return 0;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        if (ai_oss_init(ai) < 0) return -1;
        ai->setup = 1;
        return 0;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
        if (ai_sndio_init(ai) < 0) return -1;
        ai->setup = 1;
        return 0;
#endif
    default:
        return -1;
    }
}

int audio_in_set_samplerate(audio_in_t *ai, int rate)
{
    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        ai->req_samplerate = rate;
        if (!ai->setup) return 0;
        if (ai_alsa_setup(ai) < 0) return -1;
        return ai->samplerate;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        ai->req_samplerate = rate;
        if (!ai->setup) return 0;
        if (ai_oss_set_samplerate(ai) < 0) return -1;
        return ai->samplerate;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
        ai->req_samplerate = rate;
        if (!ai->setup) return 0;
        if (ai_sndio_setup(ai) < 0) return -1;
        return ai->samplerate;
#endif
    default:
        return -1;
    }
}

int audio_in_set_channels(audio_in_t *ai, int channels)
{
    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        ai->req_channels = channels;
        if (!ai->setup) return 0;
        if (ai_alsa_setup(ai) < 0) return -1;
        return ai->channels;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        ai->req_channels = channels;
        if (!ai->setup) return 0;
        if (ai_oss_set_channels(ai) < 0) return -1;
        return ai->channels;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
       ai->req_channels = channels;
       if (!ai->setup) return 0;
       if (ai_sndio_setup(ai) < 0) return -1;
       return ai->channels;
#endif
    default:
        return -1;
    }
}

int audio_in_set_device(audio_in_t *ai, char *device)
{
#if HAVE_ALSA
    int i;
#endif
    if (ai->setup) return -1;
    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        free(ai->alsa.device);
        ai->alsa.device = strdup(device);
        if (ai->alsa.device) {
            /* mplayer could not handle colons in arguments */
            for (i = 0; i < (int)strlen(ai->alsa.device); i++) {
                if (ai->alsa.device[i] == '.') ai->alsa.device[i] = ':';
            }
        }
        return 0;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        free(ai->oss.device);
        ai->oss.device = strdup(device);
        return 0;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
       if (ai->sndio.device) free(ai->sndio.device);
       ai->sndio.device = strdup(device);
       return 0;
#endif
    default:
        return -1;
    }
}

int audio_in_uninit(audio_in_t *ai)
{
    if (ai->setup) {
        switch (ai->type) {
#if HAVE_ALSA
        case AUDIO_IN_ALSA:
            if (ai->alsa.log)
                snd_output_close(ai->alsa.log);
            if (ai->alsa.handle) {
                snd_pcm_close(ai->alsa.handle);
            }
            ai->setup = 0;
            return 0;
#endif
#if HAVE_OSS_AUDIO
        case AUDIO_IN_OSS:
            close(ai->oss.audio_fd);
            ai->setup = 0;
            return 0;
#endif
#if HAVE_SNDIO
       case AUDIO_IN_SNDIO:
           if (ai->sndio.hdl)
               sio_close(ai->sndio.hdl);
           ai->setup = 0;
           return 0;
#endif
        }
    }
    return -1;
}

int audio_in_start_capture(audio_in_t *ai)
{
    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        return snd_pcm_start(ai->alsa.handle);
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        return 0;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
       if (!sio_start(ai->sndio.hdl))
           return -1;
       return 0;
#endif
    default:
        return -1;
    }
}

int audio_in_read_chunk(audio_in_t *ai, unsigned char *buffer)
{
    int ret;

    switch (ai->type) {
#if HAVE_ALSA
    case AUDIO_IN_ALSA:
        ret = snd_pcm_readi(ai->alsa.handle, buffer, ai->alsa.chunk_size);
        if (ret != ai->alsa.chunk_size) {
            if (ret < 0) {
                MP_ERR(ai, "\nError reading audio: %s\n", snd_strerror(ret));
                if (ret == -EPIPE) {
                    if (ai_alsa_xrun(ai) == 0) {
                        MP_ERR(ai, "Recovered from cross-run, some frames may be left out!\n");
                    } else {
                        MP_ERR(ai, "Fatal error, cannot recover!\n");
                    }
                }
            } else {
                MP_ERR(ai, "\nNot enough audio samples!\n");
            }
            return -1;
        }
        return ret;
#endif
#if HAVE_OSS_AUDIO
    case AUDIO_IN_OSS:
        ret = read(ai->oss.audio_fd, buffer, ai->blocksize);
       if (ret != ai->blocksize) {
           if (ret < 0) {
               MP_ERR(ai, "\nError reading audio: %s\n", mp_strerror(errno));

           } else {
               MP_ERR(ai, "\nNot enough audio samples!\n");
           }
           return -1;
       }
       return ret;
#endif
#if HAVE_SNDIO
    case AUDIO_IN_SNDIO:
       ret = sio_read(ai->sndio.hdl, buffer, ai->blocksize);
        if (ret != ai->blocksize) {
            if (ret < 0) {
                MP_ERR(ai, "\nError reading audio: %s\n", mp_strerror(errno));
            } else {
                MP_ERR(ai, "\nNot enough audio samples!\n");
            }
            return -1;
        }
        return ret;
#endif
    default:
        return -1;
    }
}

