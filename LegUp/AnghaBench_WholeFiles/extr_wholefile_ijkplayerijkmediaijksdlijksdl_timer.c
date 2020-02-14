#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct timespec {int tv_sec; int tv_nsec; } ;
typedef  scalar_t__ int64_t ;
typedef  float Uint64 ;
typedef  int Uint32 ;
struct TYPE_13__ {int max_sample; float begin_time; int total_counter; int sample_elapsed; int sample_counter; int average_elapsed; float sample_per_seconds; int capacity; float* samples; size_t next_index; int count; int first_index; float last_log_time; int sample_range; scalar_t__ last_profile_tick; scalar_t__ last_profile_duration; scalar_t__ last_profile_quantity; int last_profile_speed; int /*<<< orphan*/  total_elapsed; } ;
typedef  TYPE_1__ SDL_SpeedSampler2 ;
typedef  TYPE_1__ SDL_SpeedSampler ;
typedef  TYPE_1__ SDL_Profiler ;

/* Variables and functions */
 int /*<<< orphan*/  ALOGW (char*,char const*,float) ; 
 scalar_t__ llabs (scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int nanosleep (struct timespec*,struct timespec*) ; 

void SDL_Delay(Uint32 ms)
{
    int was_error;
    struct timespec elapsed, tv;

    /* Set the timeout interval */
    elapsed.tv_sec = ms / 1000;
    elapsed.tv_nsec = (ms % 1000) * 1000000;
    do {
        tv.tv_sec = elapsed.tv_sec;
        tv.tv_nsec = elapsed.tv_nsec;
        was_error = nanosleep(&tv, &elapsed);
    } while (was_error);
}

Uint64 SDL_GetTickHR(void)
{
    Uint64 clock;
#if defined(__ANDROID__)
    struct timespec now;
#ifdef CLOCK_MONOTONIC_COARSE
    clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
#else
    clock_gettime(CLOCK_MONOTONIC_HR, &now);
#endif
    clock = now.tv_sec * 1000 + now.tv_nsec / 1000000;
#elif defined(__APPLE__)
    if (!g_is_mach_base_info_inited) {
        g_mach_base_info_ret = mach_timebase_info(&g_mach_base_info);
        g_is_mach_base_info_inited = 1;
    }
    if (g_mach_base_info_ret == 0) {
        uint64_t now = mach_absolute_time();
        clock = now * g_mach_base_info.numer / g_mach_base_info.denom / 1000000;
    } else {
        struct timeval now;
        gettimeofday(&now, NULL);
        clock = now.tv_sec  * 1000 + now.tv_usec / 1000;
    }
#endif
    return (clock);
}

void SDL_ProfilerReset(SDL_Profiler* profiler, int max_sample)
{
    memset(profiler, 0, sizeof(SDL_Profiler));
    if (max_sample < 0)
        profiler->max_sample = 3;
    else
        profiler->max_sample = max_sample;
}

void SDL_ProfilerBegin(SDL_Profiler* profiler)
{
    profiler->begin_time = SDL_GetTickHR();
}

int64_t SDL_ProfilerEnd(SDL_Profiler* profiler)
{
    int64_t delta = SDL_GetTickHR() - profiler->begin_time;

    if (profiler->max_sample > 0) {
        profiler->total_elapsed += delta;
        profiler->total_counter += 1;

        profiler->sample_elapsed += delta;
        profiler->sample_counter  += 1;

        if (profiler->sample_counter > profiler->max_sample) {
            profiler->sample_elapsed -= profiler->average_elapsed;
            profiler->sample_counter -= 1;
        }

        if (profiler->sample_counter > 0) {
            profiler->average_elapsed = profiler->sample_elapsed / profiler->sample_counter;
        }
        if (profiler->sample_elapsed > 0) {
            profiler->sample_per_seconds = profiler->sample_counter * 1000.f / profiler->sample_elapsed;
        }
    }

    return delta;
}

void SDL_SpeedSamplerReset(SDL_SpeedSampler *sampler)
{
    memset(sampler, 0, sizeof(SDL_SpeedSampler));
    sampler->capacity = sizeof(sampler->samples) / sizeof(Uint64);
}

float SDL_SpeedSamplerAdd(SDL_SpeedSampler *sampler, int enable_log, const char *log_tag)
{
    Uint64 current = SDL_GetTickHR();
    sampler->samples[sampler->next_index] = current;
    sampler->next_index++;
    sampler->next_index %= sampler->capacity;
    if (sampler->count + 1 >= sampler->capacity) {
        sampler->first_index++;
        sampler->first_index %= sampler->capacity;
    } else {
        sampler->count++;
    }

    if (sampler->count < 2)
        return 0;

    float samples_per_second = 1000.0f * (sampler->count - 1) / (current - sampler->samples[sampler->first_index]);

    if (enable_log && (sampler->last_log_time + 1000 < current || sampler->last_log_time > current)) {
        sampler->last_log_time = current;
        ALOGW("%s: %.2f\n", log_tag ? log_tag : "N/A", samples_per_second);
    }

    return samples_per_second;
}

void SDL_SpeedSampler2Reset(SDL_SpeedSampler2 *sampler, int sample_range)
{
    memset(sampler, 0, sizeof(SDL_SpeedSampler2));
    sampler->sample_range      = sample_range;
    sampler->last_profile_tick = (int64_t)SDL_GetTickHR();
}

int64_t SDL_SpeedSampler2Add(SDL_SpeedSampler2 *sampler, int quantity)
{
    if (quantity < 0)
        return 0;

    int64_t sample_range  = sampler->sample_range;
    int64_t last_tick     = sampler->last_profile_tick;
    int64_t last_duration = sampler->last_profile_duration;
    int64_t last_quantity = sampler->last_profile_quantity;
    int64_t now           = (int64_t)SDL_GetTickHR();
    int64_t elapsed       = (int64_t)llabs(now - last_tick);
    if (elapsed < 0 || elapsed >= sample_range) {
        // overflow, reset to initialized state
        sampler->last_profile_tick     = now;
        sampler->last_profile_duration = sample_range;
        sampler->last_profile_quantity = quantity;
        sampler->last_profile_speed    = quantity * 1000 / sample_range;
        return sampler->last_profile_speed;
    }

    int64_t new_quantity = last_quantity + quantity;
    int64_t new_duration = last_duration + elapsed;
    if (new_duration > sample_range) {
        new_quantity = new_quantity * sample_range / new_duration;
        new_duration = sample_range;
    }

    sampler->last_profile_tick     = now;
    sampler->last_profile_duration = new_duration;
    sampler->last_profile_quantity = new_quantity;
    if (new_duration > 0)
        sampler->last_profile_speed = new_quantity * 1000 / new_duration;
    return sampler->last_profile_speed;
}

int64_t SDL_SpeedSampler2GetSpeed(SDL_SpeedSampler2 *sampler)
{
    int64_t sample_range  = sampler->sample_range;
    int64_t last_tick     = sampler->last_profile_tick;
    int64_t last_quantity = sampler->last_profile_quantity;
    int64_t last_duration = sampler->last_profile_duration;
    int64_t now           = (int64_t)SDL_GetTickHR();
    int64_t elapsed       = (int64_t)llabs(now - last_tick);
    if (elapsed < 0 || elapsed >= sample_range)
        return 0;

    int64_t new_quantity = last_quantity;
    int64_t new_duration = last_duration + elapsed;
    if (new_duration > sample_range) {
        new_quantity = new_quantity * sample_range / new_duration;
        new_duration = sample_range;
    }

    if (new_duration <= 0)
        return 0;

    return new_quantity * 1000 / new_duration;
}

