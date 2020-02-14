#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  video_y ;
typedef  int /*<<< orphan*/  video_v ;
typedef  int /*<<< orphan*/  video_u ;
struct TYPE_29__ {int incoming; size_t state; } ;
typedef  TYPE_1__ uint8_t ;
typedef  size_t uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int time_t ;
struct TYPE_30__ {size_t friend_number; TYPE_1__* BobCC; TYPE_1__* AliceCC; int /*<<< orphan*/ * BobAV; int /*<<< orphan*/ * AliceAV; } ;
typedef  TYPE_2__ thread_data ;
typedef  int /*<<< orphan*/  int32_t ;
typedef  TYPE_1__ int16_t ;
typedef  int /*<<< orphan*/  ToxAV ;
typedef  int /*<<< orphan*/  Tox ;
typedef  scalar_t__ TOXAV_ERR_NEW ;
typedef  scalar_t__ TOXAV_ERR_CALL_CONTROL ;
typedef  scalar_t__ TOXAV_ERR_CALL ;
typedef  scalar_t__ TOXAV_ERR_ANSWER ;
typedef  int /*<<< orphan*/  PCM ;
typedef  TYPE_1__ CallControl ;

/* Variables and functions */
 int /*<<< orphan*/  TOXAV_CALL_CONTROL_CANCEL ; 
 scalar_t__ TOXAV_ERR_ANSWER_OK ; 
 scalar_t__ TOXAV_ERR_CALL_CONTROL_OK ; 
 scalar_t__ TOXAV_ERR_CALL_OK ; 
 scalar_t__ TOXAV_ERR_NEW_OK ; 
 int /*<<< orphan*/  c_sleep (int) ; 
 int /*<<< orphan*/  ck_assert (int) ; 
 scalar_t__ memcmp (char*,TYPE_1__ const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_AV_three_calls () ; 
 int time (int /*<<< orphan*/ *) ; 
 size_t tox_friend_add_norequest (int /*<<< orphan*/ *,TYPE_1__ const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  toxav_answer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,scalar_t__*) ; 
 int /*<<< orphan*/  toxav_audio_send_frame (int /*<<< orphan*/ *,size_t,TYPE_1__*,int,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  toxav_call (int /*<<< orphan*/ *,size_t,int,int,scalar_t__*) ; 
 int /*<<< orphan*/  toxav_call_control (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  toxav_callback_audio_receive_frame (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_1__ const*,size_t,TYPE_1__,size_t,void*),TYPE_1__*) ; 
 int /*<<< orphan*/  toxav_callback_call (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,int,int,void*),TYPE_1__*) ; 
 int /*<<< orphan*/  toxav_callback_call_state (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,size_t,void*),TYPE_1__*) ; 
 int /*<<< orphan*/  toxav_callback_video_receive_frame (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__ const*,TYPE_1__ const*,TYPE_1__ const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*),TYPE_1__*) ; 
 int /*<<< orphan*/  toxav_iterate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * toxav_new (int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  toxav_video_send_frame (int /*<<< orphan*/ *,size_t,int,int,TYPE_1__*,TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ *) ; 

void t_toxav_call_cb(ToxAV *av, uint32_t friend_number, bool audio_enabled, bool video_enabled, void *user_data)
{
    (void) av;
    (void) audio_enabled;
    (void) video_enabled;

    printf("Handling CALL callback\n");
    ((CallControl *)user_data)[friend_number].incoming = true;
}

void t_toxav_call_state_cb(ToxAV *av, uint32_t friend_number, uint32_t state, void *user_data)
{
    printf("Handling CALL STATE callback: %d %p\n", state, av);
    ((CallControl *)user_data)[friend_number].state = state;
}

void t_toxav_receive_video_frame_cb(ToxAV *av, uint32_t friend_number,
                                    uint16_t width, uint16_t height,
                                    uint8_t const *y, uint8_t const *u, uint8_t const *v,
                                    int32_t ystride, int32_t ustride, int32_t vstride,
                                    void *user_data)
{
    (void) av;
    (void) friend_number;
    (void) width;
    (void) height;
    (void) y;
    (void) u;
    (void) v;
    (void) ystride;
    (void) ustride;
    (void) vstride;
    (void) user_data;
}

void t_toxav_receive_audio_frame_cb(ToxAV *av, uint32_t friend_number,
                                    int16_t const *pcm,
                                    size_t sample_count,
                                    uint8_t channels,
                                    uint32_t sampling_rate,
                                    void *user_data)
{
    (void) av;
    (void) friend_number;
    (void) pcm;
    (void) sample_count;
    (void) channels;
    (void) sampling_rate;
    (void) user_data;
}

void t_accept_friend_request_cb(Tox *m, const uint8_t *public_key, const uint8_t *data, size_t length, void *userdata)
{
    (void) userdata;

    if (length == 7 && memcmp("gentoo", data, 7) == 0) {
        ck_assert(tox_friend_add_norequest(m, public_key, NULL) != (uint32_t) ~0);
    }
}

ToxAV *setup_av_instance(Tox *tox, CallControl *CC)
{
    TOXAV_ERR_NEW error;

    ToxAV *av = toxav_new(tox, &error);
    ck_assert(error == TOXAV_ERR_NEW_OK);

    toxav_callback_call(av, t_toxav_call_cb, CC);
    toxav_callback_call_state(av, t_toxav_call_state_cb, CC);
    toxav_callback_video_receive_frame(av, t_toxav_receive_video_frame_cb, CC);
    toxav_callback_audio_receive_frame(av, t_toxav_receive_audio_frame_cb, CC);

    return av;
}

void *call_thread(void *pd)
{
    ToxAV *AliceAV = ((thread_data *) pd)->AliceAV;
    ToxAV *BobAV = ((thread_data *) pd)->BobAV;
    CallControl *AliceCC = ((thread_data *) pd)->AliceCC;
    CallControl *BobCC = ((thread_data *) pd)->BobCC;
    uint32_t friend_number = ((thread_data *) pd)->friend_number;


    memset(AliceCC, 0, sizeof(CallControl));
    memset(BobCC, 0, sizeof(CallControl));

    { /* Call */
        TOXAV_ERR_CALL rc;
        toxav_call(AliceAV, friend_number, 48, 3000, &rc);

        if (rc != TOXAV_ERR_CALL_OK) {
            printf("toxav_call failed: %d\n", rc);
            ck_assert(0);
        }
    }

    while (!BobCC->incoming)
        c_sleep(10);

    { /* Answer */
        TOXAV_ERR_ANSWER rc;
        toxav_answer(BobAV, 0, 8, 500, &rc);

        if (rc != TOXAV_ERR_ANSWER_OK) {
            printf("toxav_answer failed: %d\n", rc);
            ck_assert(0);
        }
    }

    c_sleep(30);

    int16_t PCM[960];
    uint8_t video_y[800 * 600];
    uint8_t video_u[800 * 600 / 2];
    uint8_t video_v[800 * 600 / 2];

    memset(PCM, 0, sizeof(PCM));
    memset(video_y, 0, sizeof(video_y));
    memset(video_u, 0, sizeof(video_u));
    memset(video_v, 0, sizeof(video_v));

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 4) {
        toxav_iterate(AliceAV);
        toxav_iterate(BobAV);

        toxav_audio_send_frame(AliceAV, friend_number, PCM, 960, 1, 48000, NULL);
        toxav_audio_send_frame(BobAV, 0, PCM, 960, 1, 48000, NULL);

        toxav_video_send_frame(AliceAV, friend_number, 800, 600, video_y, video_u, video_v, NULL);
        toxav_video_send_frame(BobAV, 0, 800, 600, video_y, video_u, video_v, NULL);

        c_sleep(10);
    }

    { /* Hangup */
        TOXAV_ERR_CALL_CONTROL rc;
        toxav_call_control(AliceAV, friend_number, TOXAV_CALL_CONTROL_CANCEL, &rc);

        if (rc != TOXAV_ERR_CALL_CONTROL_OK) {
            printf("toxav_call_control failed: %d %p %p\n", rc, AliceAV, BobAV);
        }
    }

    c_sleep(30);

    printf ("Closing thread\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    test_AV_three_calls();
    return 0;
}

