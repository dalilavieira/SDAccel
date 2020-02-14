#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_9__ {int width; int height; } ;
struct TYPE_8__ {int x; int y; } ;
struct position {TYPE_2__ screen_size; TYPE_1__ point; } ;
struct control_event_queue {int tail; int head; struct control_event* data; } ;
struct TYPE_14__ {int /*<<< orphan*/  text; } ;
struct TYPE_13__ {unsigned char action; } ;
struct TYPE_12__ {int /*<<< orphan*/  vscroll; int /*<<< orphan*/  hscroll; struct position position; } ;
struct TYPE_11__ {unsigned char action; int buttons; struct position position; } ;
struct TYPE_10__ {unsigned char action; int keycode; int metastate; } ;
struct control_event {unsigned char type; TYPE_7__ text_event; TYPE_6__ command_event; TYPE_5__ scroll_event; TYPE_4__ mouse_event; TYPE_3__ keycode_event; } ;

/* Variables and functions */
 int CONTROL_EVENT_QUEUE_SIZE ; 
#define  CONTROL_EVENT_TYPE_COMMAND 132 
#define  CONTROL_EVENT_TYPE_KEYCODE 131 
#define  CONTROL_EVENT_TYPE_MOUSE 130 
#define  CONTROL_EVENT_TYPE_SCROLL 129 
#define  CONTROL_EVENT_TYPE_TEXT 128 
 int /*<<< orphan*/  LOGW (char*,unsigned int) ; 
 int /*<<< orphan*/  SDL_free (int /*<<< orphan*/ ) ; 
 size_t TEXT_MAX_LENGTH ; 
 int /*<<< orphan*/  memcpy (unsigned char*,int /*<<< orphan*/ ,size_t) ; 
 size_t strlen (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
buffer_write16be(uint8_t *buf, uint16_t value) {
    buf[0] = value >> 8;
    buf[1] = value;
}

__attribute__((used)) static inline void
buffer_write32be(uint8_t *buf, uint32_t value) {
    buf[0] = value >> 24;
    buf[1] = value >> 16;
    buf[2] = value >> 8;
    buf[3] = value;
}

__attribute__((used)) static inline uint32_t
buffer_read32be(uint8_t *buf) {
    return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
}

__attribute__((used)) static inline
uint64_t buffer_read64be(uint8_t *buf) {
    uint32_t msb = buffer_read32be(buf);
    uint32_t lsb = buffer_read32be(&buf[4]);
    return ((uint64_t) msb << 32) | lsb;
}

__attribute__((used)) static void
write_position(uint8_t *buf, const struct position *position) {
    buffer_write32be(&buf[0], position->point.x);
    buffer_write32be(&buf[4], position->point.y);
    buffer_write16be(&buf[8], position->screen_size.width);
    buffer_write16be(&buf[10], position->screen_size.height);
}

int
control_event_serialize(const struct control_event *event, unsigned char *buf) {
    buf[0] = event->type;
    switch (event->type) {
        case CONTROL_EVENT_TYPE_KEYCODE:
            buf[1] = event->keycode_event.action;
            buffer_write32be(&buf[2], event->keycode_event.keycode);
            buffer_write32be(&buf[6], event->keycode_event.metastate);
            return 10;
        case CONTROL_EVENT_TYPE_TEXT: {
            // write length (2 bytes) + string (non nul-terminated)
            size_t len = strlen(event->text_event.text);
            if (len > TEXT_MAX_LENGTH) {
                // injecting a text takes time, so limit the text length
                len = TEXT_MAX_LENGTH;
            }
            buffer_write16be(&buf[1], (uint16_t) len);
            memcpy(&buf[3], event->text_event.text, len);
            return 3 + len;
        }
        case CONTROL_EVENT_TYPE_MOUSE:
            buf[1] = event->mouse_event.action;
            buffer_write32be(&buf[2], event->mouse_event.buttons);
            write_position(&buf[6], &event->mouse_event.position);
            return 18;
        case CONTROL_EVENT_TYPE_SCROLL:
            write_position(&buf[1], &event->scroll_event.position);
            buffer_write32be(&buf[13], (uint32_t) event->scroll_event.hscroll);
            buffer_write32be(&buf[17], (uint32_t) event->scroll_event.vscroll);
            return 21;
        case CONTROL_EVENT_TYPE_COMMAND:
            buf[1] = event->command_event.action;
            return 2;
        default:
            LOGW("Unknown event type: %u", (unsigned) event->type);
            return 0;
    }
}

void
control_event_destroy(struct control_event *event) {
    if (event->type == CONTROL_EVENT_TYPE_TEXT) {
        SDL_free(event->text_event.text);
    }
}

void
control_event_queue_destroy(struct control_event_queue *queue) {
    int i = queue->tail;
    while (i != queue->head) {
        control_event_destroy(&queue->data[i]);
        i = (i + 1) % CONTROL_EVENT_QUEUE_SIZE;
    }
}

