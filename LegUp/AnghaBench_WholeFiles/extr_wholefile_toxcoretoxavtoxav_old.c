#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct Tox {int dummy; } ;
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_2__ {int /*<<< orphan*/  group_chat_object; } ;
typedef  TYPE_1__ Messenger ;

/* Variables and functions */
 int add_av_groupchat (int /*<<< orphan*/ ,void (*) (void*,int,int,int16_t const*,unsigned int,uint8_t,unsigned int,void*),void*) ; 
 int group_send_audio (int /*<<< orphan*/ ,int,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ ,unsigned int) ; 
 int join_av_groupchat (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,void (*) (void*,int,int,int16_t const*,unsigned int,int /*<<< orphan*/ ,unsigned int,void*),void*) ; 

int toxav_add_av_groupchat(struct Tox *tox, void (*audio_callback)(void *, int, int, const int16_t *, unsigned int,
                           uint8_t, unsigned int, void *), void *userdata)
{
    Messenger *m = (Messenger *)tox;
    return add_av_groupchat(m->group_chat_object, audio_callback, userdata);
}

int toxav_join_av_groupchat(struct Tox *tox, int32_t friendnumber, const uint8_t *data, uint16_t length,
                            void (*audio_callback)(void *, int, int, const int16_t *, unsigned int, uint8_t, unsigned int, void *),
                            void *userdata)
{
    Messenger *m = (Messenger *)tox;
    return join_av_groupchat(m->group_chat_object, friendnumber, data, length, audio_callback, userdata);
}

int toxav_group_send_audio(struct Tox *tox, int groupnumber, const int16_t *pcm, unsigned int samples, uint8_t channels,
                           unsigned int sample_rate)
{
    Messenger *m = (Messenger *)tox;
    return group_send_audio(m->group_chat_object, groupnumber, pcm, samples, channels, sample_rate);
}

