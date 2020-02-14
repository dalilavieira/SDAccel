#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
struct TYPE_28__ {int (* open_audio ) (TYPE_1__*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ;void (* close_audio ) (TYPE_1__*) ;double (* func_get_latency_seconds ) (TYPE_1__*) ;double minimal_latency_seconds; int (* func_get_audio_session_id ) (TYPE_1__*) ;int (* func_get_audio_persecond_callbacks ) (TYPE_1__*) ;int /*<<< orphan*/  (* func_set_playback_volume ) (TYPE_1__*,float) ;int /*<<< orphan*/  (* func_set_playback_rate ) (TYPE_1__*,float) ;int /*<<< orphan*/  (* func_set_default_latency_seconds ) (TYPE_1__*,double) ;int /*<<< orphan*/  (* free_l ) (TYPE_1__*) ;int /*<<< orphan*/  (* set_volume ) (TYPE_1__*,float,float) ;int /*<<< orphan*/  (* flush_audio ) (TYPE_1__*) ;int /*<<< orphan*/  (* pause_audio ) (TYPE_1__*,int) ;} ;
typedef  int /*<<< orphan*/  SDL_AudioSpec ;
typedef  TYPE_1__ SDL_Aout ;

/* Variables and functions */
 int SDL_AUDIO_MAX_CALLBACKS_PER_SEC ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int stub1 (TYPE_1__*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub10 (TYPE_1__*,float) ; 
 int stub11 (TYPE_1__*) ; 
 int stub12 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*,float,float) ; 
 void stub5 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_1__*) ; 
 double stub7 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_1__*,double) ; 
 int /*<<< orphan*/  stub9 (TYPE_1__*,float) ; 

int SDL_AoutOpenAudio(SDL_Aout *aout, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained)
{
    if (aout && desired && aout->open_audio)
        return aout->open_audio(aout, desired, obtained);

    return -1;
}

void SDL_AoutPauseAudio(SDL_Aout *aout, int pause_on)
{
    if (aout && aout->pause_audio)
        aout->pause_audio(aout, pause_on);
}

void SDL_AoutFlushAudio(SDL_Aout *aout)
{
    if (aout && aout->flush_audio)
        aout->flush_audio(aout);
}

void SDL_AoutSetStereoVolume(SDL_Aout *aout, float left_volume, float right_volume)
{
    if (aout && aout->set_volume)
        aout->set_volume(aout, left_volume, right_volume);
}

void SDL_AoutCloseAudio(SDL_Aout *aout)
{
    if (aout && aout->close_audio)
        return aout->close_audio(aout);
}

void SDL_AoutFree(SDL_Aout *aout)
{
    if (!aout)
        return;

    if (aout->free_l)
        aout->free_l(aout);
    else
        free(aout);
}

void SDL_AoutFreeP(SDL_Aout **paout)
{
    if (!paout)
        return;

    SDL_AoutFree(*paout);
    *paout = NULL;
}

double SDL_AoutGetLatencySeconds(SDL_Aout *aout)
{
    if (!aout)
        return 0;

    if (aout->func_get_latency_seconds)
        return aout->func_get_latency_seconds(aout);

    return aout->minimal_latency_seconds;
}

void SDL_AoutSetDefaultLatencySeconds(SDL_Aout *aout, double latency)
{
    if (aout) {
        if (aout->func_set_default_latency_seconds)
            aout->func_set_default_latency_seconds(aout, latency);
        aout->minimal_latency_seconds = latency;
    }
}

void SDL_AoutSetPlaybackRate(SDL_Aout *aout, float playbackRate)
{
    if (aout) {
        if (aout->func_set_playback_rate)
            aout->func_set_playback_rate(aout, playbackRate);
    }
}

void SDL_AoutSetPlaybackVolume(SDL_Aout *aout, float volume)
{
    if (aout) {
        if (aout->func_set_playback_volume)
            aout->func_set_playback_volume(aout, volume);
    }
}

int SDL_AoutGetAudioSessionId(SDL_Aout *aout)
{
    if (aout) {
        if (aout->func_get_audio_session_id) {
            return aout->func_get_audio_session_id(aout);
        }
    }
    return 0;
}

int SDL_AoutGetAudioPerSecondCallBacks(SDL_Aout *aout)
{
    if (aout) {
        if (aout->func_get_audio_persecond_callbacks) {
            return aout->func_get_audio_persecond_callbacks(aout);
        }
    }
    return SDL_AUDIO_MAX_CALLBACKS_PER_SEC;
}

