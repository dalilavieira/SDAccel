#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct BWController_s {int dummy; } ;
struct BWCMessage {int lost; int recv; } ;
typedef  int /*<<< orphan*/  p_msg ;
struct TYPE_16__ {scalar_t__ lsu; scalar_t__ lfu; int lost; int recv; scalar_t__ lru; } ;
struct TYPE_15__ {int* rb_s; int /*<<< orphan*/  rb; } ;
struct TYPE_17__ {void (* mcb ) (TYPE_3__*,int,float,void*) ;void* mcb_data; int friend_number; TYPE_2__ cycle; int /*<<< orphan*/ * m; TYPE_1__ rcvpkt; } ;
typedef  int /*<<< orphan*/  Messenger ;
typedef  TYPE_3__ BWController ;

/* Variables and functions */
 int BWC_AVG_PKT_COUNT ; 
 int /*<<< orphan*/  BWC_PACKET_ID ; 
 scalar_t__ BWC_REFRESH_INTERVAL_MS ; 
 scalar_t__ BWC_SEND_INTERVAL_MS ; 
 int /*<<< orphan*/  LOGGER_DEBUG (char*,...) ; 
 int /*<<< orphan*/  LOGGER_WARNING (char*,int,int /*<<< orphan*/ ) ; 
 int bwc_handle_data (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*,int,void*) ; 
 TYPE_3__* calloc (int,int) ; 
 scalar_t__ current_time_monotonic () ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  free (TYPE_3__*) ; 
 void* htonl (int) ; 
 int /*<<< orphan*/  m_callback_rtp_packet (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,...) ; 
 void* ntohl (int) ; 
 int /*<<< orphan*/  rb_data (int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  rb_kill (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rb_new (int) ; 
 int /*<<< orphan*/  rb_read (int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  rb_write (int /*<<< orphan*/ ,int*) ; 
 int send_custom_lossy_packet (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ; 
 void send_update (TYPE_3__*) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 void stub1 (TYPE_3__*,int,float,void*) ; 

BWController *bwc_new(Messenger *m, uint32_t friendnumber,
                      void (*mcb) (BWController *, uint32_t, float, void *),
                      void *udata)
{
    BWController *retu = calloc(sizeof(struct BWController_s), 1);

    retu->mcb = mcb;
    retu->mcb_data = udata;
    retu->m = m;
    retu->friend_number = friendnumber;
    retu->cycle.lsu = retu->cycle.lfu = current_time_monotonic();
    retu->rcvpkt.rb = rb_new(BWC_AVG_PKT_COUNT);

    /* Fill with zeros */
    int i = 0;

    for (; i < BWC_AVG_PKT_COUNT; i ++)
        rb_write(retu->rcvpkt.rb, retu->rcvpkt.rb_s + i);

    m_callback_rtp_packet(m, friendnumber, BWC_PACKET_ID, bwc_handle_data, retu);

    return retu;
}

void bwc_kill(BWController *bwc)
{
    if (!bwc)
        return;

    m_callback_rtp_packet(bwc->m, bwc->friend_number, BWC_PACKET_ID, NULL, NULL);

    rb_kill(bwc->rcvpkt.rb);
    free(bwc);
}

void bwc_feed_avg(BWController *bwc, uint32_t bytes)
{
    uint32_t *p;

    rb_read(bwc->rcvpkt.rb, (void **) &p);
    rb_write(bwc->rcvpkt.rb, p);

    *p = bytes;
}

void bwc_add_lost(BWController *bwc, uint32_t bytes)
{
    if (!bwc)
        return;

    if (!bytes) {
        uint32_t *t_avg[BWC_AVG_PKT_COUNT], c = 1;

        rb_data(bwc->rcvpkt.rb, (void **) t_avg);

        int i = 0;

        for (; i < BWC_AVG_PKT_COUNT; i ++) {
            bytes += *(t_avg[i]);

            if (*(t_avg[i]))
                c++;
        }

        bytes /= c;
    }

    bwc->cycle.lost += bytes;
    send_update(bwc);
}

void bwc_add_recv(BWController *bwc, uint32_t bytes)
{
    if (!bwc || !bytes)
        return;

    bwc->cycle.recv += bytes;
    send_update(bwc);
}

void send_update(BWController *bwc)
{
    if (current_time_monotonic() - bwc->cycle.lfu > BWC_REFRESH_INTERVAL_MS) {

        bwc->cycle.lost /= 10;
        bwc->cycle.recv /= 10;
        bwc->cycle.lfu = current_time_monotonic();
    } else if (current_time_monotonic() - bwc->cycle.lsu > BWC_SEND_INTERVAL_MS) {

        if (bwc->cycle.lost) {
            LOGGER_DEBUG ("%p Sent update rcv: %u lost: %u",
                          bwc, bwc->cycle.recv, bwc->cycle.lost);

            uint8_t p_msg[sizeof(struct BWCMessage) + 1];
            struct BWCMessage *b_msg = (struct BWCMessage *)(p_msg + 1);

            p_msg[0] = BWC_PACKET_ID;
            b_msg->lost = htonl(bwc->cycle.lost);
            b_msg->recv = htonl(bwc->cycle.recv);

            if (-1 == send_custom_lossy_packet(bwc->m, bwc->friend_number, p_msg, sizeof(p_msg)))
                LOGGER_WARNING("BWC send failed (len: %d)! std error: %s", sizeof(p_msg), strerror(errno));
        }

        bwc->cycle.lsu = current_time_monotonic();
    }
}

int on_update (BWController *bwc, struct BWCMessage *msg)
{
    LOGGER_DEBUG ("%p Got update from peer", bwc);

    /* Peer must respect time boundary */
    if (current_time_monotonic() < bwc->cycle.lru + BWC_SEND_INTERVAL_MS) {
        LOGGER_DEBUG("%p Rejecting extra update", bwc);
        return -1;
    }

    bwc->cycle.lru = current_time_monotonic();

    msg->recv = ntohl(msg->recv);
    msg->lost = ntohl(msg->lost);

    LOGGER_DEBUG ("recved: %u lost: %u", msg->recv, msg->lost);

    if (msg->lost && bwc->mcb)
        bwc->mcb(bwc, bwc->friend_number,
                 ((float) (msg->lost) / (msg->recv + msg->lost)),
                 bwc->mcb_data);

    return 0;
}

int bwc_handle_data(Messenger *m, uint32_t friendnumber, const uint8_t *data, uint16_t length, void *object)
{
    if (length - 1 != sizeof(struct BWCMessage))
        return -1;

    /* NOTE the data is mutable */
    return on_update(object, (struct BWCMessage *) (data + 1));
}

