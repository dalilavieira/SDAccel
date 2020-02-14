#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_52__   TYPE_9__ ;
typedef  struct TYPE_51__   TYPE_8__ ;
typedef  struct TYPE_50__   TYPE_7__ ;
typedef  struct TYPE_49__   TYPE_6__ ;
typedef  struct TYPE_48__   TYPE_5__ ;
typedef  struct TYPE_47__   TYPE_4__ ;
typedef  struct TYPE_46__   TYPE_3__ ;
typedef  struct TYPE_45__   TYPE_2__ ;
typedef  struct TYPE_44__   TYPE_1__ ;
typedef  struct TYPE_43__   TYPE_12__ ;
typedef  struct TYPE_42__   TYPE_11__ ;
typedef  struct TYPE_41__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int ssize_t ;
typedef  int int32_t ;
struct TYPE_45__ {scalar_t__ const* base; size_t len; } ;
typedef  TYPE_2__ h2o_iovec_t ;
struct TYPE_46__ {int window_size_increment; } ;
typedef  TYPE_3__ h2o_http2_window_update_payload_t ;
struct TYPE_47__ {int header_table_size; int enable_push; int max_concurrent_streams; int initial_window_size; int max_frame_size; } ;
typedef  TYPE_4__ h2o_http2_settings_t ;
struct TYPE_48__ {int error_code; } ;
typedef  TYPE_5__ h2o_http2_rst_stream_payload_t ;
struct TYPE_49__ {int exclusive; int dependency; int weight; } ;
typedef  TYPE_6__ h2o_http2_priority_t ;
struct TYPE_50__ {scalar_t__* data; } ;
typedef  TYPE_7__ h2o_http2_ping_payload_t ;
struct TYPE_51__ {scalar_t__ const* headers; int headers_len; TYPE_6__ priority; } ;
typedef  TYPE_8__ h2o_http2_headers_payload_t ;
struct TYPE_44__ {int len; char* base; } ;
struct TYPE_52__ {int last_stream_id; int error_code; TYPE_1__ debug_data; } ;
typedef  TYPE_9__ h2o_http2_goaway_payload_t ;
struct TYPE_41__ {size_t length; scalar_t__ type; scalar_t__ flags; int stream_id; scalar_t__ const* payload; } ;
typedef  TYPE_10__ h2o_http2_frame_t ;
struct TYPE_42__ {scalar_t__* data; scalar_t__ length; } ;
typedef  TYPE_11__ h2o_http2_data_payload_t ;
struct TYPE_43__ {int /*<<< orphan*/  size; } ;
typedef  TYPE_12__ h2o_buffer_t ;

/* Variables and functions */
 int H2O_HTTP2_ERROR_FLOW_CONTROL ; 
 int H2O_HTTP2_ERROR_FRAME_SIZE ; 
 int H2O_HTTP2_ERROR_INCOMPLETE ; 
 int H2O_HTTP2_ERROR_PROTOCOL ; 
 scalar_t__ H2O_HTTP2_FRAME_FLAG_ACK ; 
 int H2O_HTTP2_FRAME_FLAG_PADDED ; 
 int H2O_HTTP2_FRAME_FLAG_PRIORITY ; 
 size_t H2O_HTTP2_FRAME_HEADER_SIZE ; 
 scalar_t__ H2O_HTTP2_FRAME_TYPE_GOAWAY ; 
 scalar_t__ H2O_HTTP2_FRAME_TYPE_ORIGIN ; 
 scalar_t__ H2O_HTTP2_FRAME_TYPE_PING ; 
 scalar_t__ H2O_HTTP2_FRAME_TYPE_RST_STREAM ; 
 scalar_t__ H2O_HTTP2_FRAME_TYPE_WINDOW_UPDATE ; 
#define  H2O_HTTP2_SETTINGS_ENABLE_PUSH 132 
#define  H2O_HTTP2_SETTINGS_HEADER_TABLE_SIZE 131 
#define  H2O_HTTP2_SETTINGS_INITIAL_WINDOW_SIZE 130 
#define  H2O_HTTP2_SETTINGS_MAX_CONCURRENT_STREAMS 129 
#define  H2O_HTTP2_SETTINGS_MAX_FRAME_SIZE 128 
 int UINT32_MAX ; 
 TYPE_2__ h2o_buffer_reserve (TYPE_12__**,size_t) ; 
 int /*<<< orphan*/  h2o_fatal (char*) ; 
 int h2o_http2_decode16u (scalar_t__ const*) ; 
 size_t h2o_http2_decode24u (scalar_t__ const*) ; 
 int h2o_http2_decode32u (scalar_t__ const*) ; 
 TYPE_6__ h2o_http2_default_priority ; 
 scalar_t__* h2o_http2_encode24u (scalar_t__*,int) ; 
 scalar_t__* h2o_http2_encode32u (scalar_t__*,int) ; 
 int /*<<< orphan*/  h2o_memcpy (scalar_t__*,scalar_t__ const*,size_t) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__ const*,int) ; 

int h2o_http2_update_peer_settings(h2o_http2_settings_t *settings, const uint8_t *src, size_t len, const char **err_desc)
{
    for (; len >= 6; len -= 6, src += 6) {
        uint16_t identifier = h2o_http2_decode16u(src);
        uint32_t value = h2o_http2_decode32u(src + 2);
        switch (identifier) {
#define SET(label, member, min, max, err_code)                                                                                     \
    case H2O_HTTP2_SETTINGS_##label:                                                                                               \
        if (!(min <= value && value <= max)) {                                                                                     \
            *err_desc = "invalid SETTINGS frame";                                                                                  \
            return err_code;                                                                                                       \
        }                                                                                                                          \
        settings->member = value;                                                                                                  \
        break
            SET(HEADER_TABLE_SIZE, header_table_size, 0, UINT32_MAX, 0);
            SET(ENABLE_PUSH, enable_push, 0, 1, H2O_HTTP2_ERROR_PROTOCOL);
            SET(MAX_CONCURRENT_STREAMS, max_concurrent_streams, 0, UINT32_MAX, 0);
            SET(INITIAL_WINDOW_SIZE, initial_window_size, 0, 0x7fffffff, H2O_HTTP2_ERROR_FLOW_CONTROL);
            SET(MAX_FRAME_SIZE, max_frame_size, 16384, 16777215, H2O_HTTP2_ERROR_PROTOCOL);
#undef SET
        default:
            /* ignore unknown (5.5) */
            break;
        }
    }

    if (len != 0)
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    return 0;
}

uint8_t *h2o_http2_encode_frame_header(uint8_t *dst, size_t length, uint8_t type, uint8_t flags, int32_t stream_id)
{
    if (length > 0xffffff)
        h2o_fatal("invalid length");

    dst = h2o_http2_encode24u(dst, (uint32_t)length);
    *dst++ = type;
    *dst++ = flags;
    dst = h2o_http2_encode32u(dst, stream_id);

    return dst;
}

__attribute__((used)) static uint8_t *allocate_frame(h2o_buffer_t **buf, size_t length, uint8_t type, uint8_t flags, int32_t stream_id)
{
    h2o_iovec_t alloced = h2o_buffer_reserve(buf, H2O_HTTP2_FRAME_HEADER_SIZE + length);
    (*buf)->size += H2O_HTTP2_FRAME_HEADER_SIZE + length;
    return h2o_http2_encode_frame_header((uint8_t *)alloced.base, length, type, flags, stream_id);
}

void h2o_http2__encode_rst_stream_frame(h2o_buffer_t **buf, uint32_t stream_id, int errnum)
{
    uint8_t *dst = allocate_frame(buf, 4, H2O_HTTP2_FRAME_TYPE_RST_STREAM, 0, stream_id);
    dst = h2o_http2_encode32u(dst, errnum);
}

void h2o_http2_encode_ping_frame(h2o_buffer_t **buf, int is_ack, const uint8_t *data)
{
    uint8_t *dst = allocate_frame(buf, 8, H2O_HTTP2_FRAME_TYPE_PING, is_ack ? H2O_HTTP2_FRAME_FLAG_ACK : 0, 0);
    memcpy(dst, data, 8);
    dst += 8;
}

void h2o_http2_encode_goaway_frame(h2o_buffer_t **buf, uint32_t last_stream_id, int errnum, h2o_iovec_t additional_data)
{
    uint8_t *dst = allocate_frame(buf, 8 + additional_data.len, H2O_HTTP2_FRAME_TYPE_GOAWAY, 0, 0);
    dst = h2o_http2_encode32u(dst, last_stream_id);
    dst = h2o_http2_encode32u(dst, (uint32_t)-errnum);
    h2o_memcpy(dst, additional_data.base, additional_data.len);
}

void h2o_http2_encode_window_update_frame(h2o_buffer_t **buf, uint32_t stream_id, int32_t window_size_increment)
{
    uint8_t *dst = allocate_frame(buf, 4, H2O_HTTP2_FRAME_TYPE_WINDOW_UPDATE, 0, stream_id);
    dst = h2o_http2_encode32u(dst, window_size_increment);
}

void h2o_http2_encode_origin_frame(h2o_buffer_t **buf, h2o_iovec_t payload)
{
    uint8_t *dst = allocate_frame(buf, payload.len, H2O_HTTP2_FRAME_TYPE_ORIGIN, 0, 0);
    memcpy(dst, payload.base, payload.len);
}

ssize_t h2o_http2_decode_frame(h2o_http2_frame_t *frame, const uint8_t *src, size_t len, size_t max_frame_size,
                               const char **err_desc)
{
    if (len < H2O_HTTP2_FRAME_HEADER_SIZE)
        return H2O_HTTP2_ERROR_INCOMPLETE;

    frame->length = h2o_http2_decode24u(src);
    frame->type = src[3];
    frame->flags = src[4];
    frame->stream_id = h2o_http2_decode32u(src + 5) & 0x7fffffff;

    if (frame->length > max_frame_size)
        return H2O_HTTP2_ERROR_FRAME_SIZE;

    if (len < H2O_HTTP2_FRAME_HEADER_SIZE + frame->length)
        return H2O_HTTP2_ERROR_INCOMPLETE;

    frame->payload = src + H2O_HTTP2_FRAME_HEADER_SIZE;

    return H2O_HTTP2_FRAME_HEADER_SIZE + frame->length;
}

int h2o_http2_decode_data_payload(h2o_http2_data_payload_t *payload, const h2o_http2_frame_t *frame, const char **err_desc)
{
    if (frame->stream_id == 0) {
        *err_desc = "invalid stream id in DATA frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }

    if ((frame->flags & H2O_HTTP2_FRAME_FLAG_PADDED) != 0) {
        uint8_t padding_length;
        if (frame->length < 1) {
            *err_desc = "invalid DATA frame";
            return H2O_HTTP2_ERROR_PROTOCOL;
        }
        padding_length = frame->payload[0];
        if (frame->length < 1 + padding_length) {
            *err_desc = "invalid DATA frame";
            return H2O_HTTP2_ERROR_PROTOCOL;
        }
        payload->data = frame->payload + 1;
        payload->length = frame->length - (1 + padding_length);
    } else {
        payload->data = frame->payload;
        payload->length = frame->length;
    }
    return 0;
}

__attribute__((used)) static const uint8_t *decode_priority(h2o_http2_priority_t *priority, const uint8_t *src)
{
    uint32_t u4 = h2o_http2_decode32u(src);
    src += 4;
    priority->exclusive = u4 >> 31;
    priority->dependency = u4 & 0x7fffffff;
    priority->weight = (uint16_t)*src++ + 1;
    return src;
}

int h2o_http2_decode_headers_payload(h2o_http2_headers_payload_t *payload, const h2o_http2_frame_t *frame, const char **err_desc)
{
    const uint8_t *src = frame->payload, *src_end = frame->payload + frame->length;

    if (frame->stream_id == 0) {
        *err_desc = "invalid stream id in HEADERS frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }

    if ((frame->flags & H2O_HTTP2_FRAME_FLAG_PADDED) != 0) {
        uint32_t padlen;
        if (src == src_end) {
            *err_desc = "invalid HEADERS frame";
            return H2O_HTTP2_ERROR_PROTOCOL;
        }
        padlen = *src++;
        if (src_end - src < padlen) {
            *err_desc = "invalid HEADERS frame";
            return H2O_HTTP2_ERROR_PROTOCOL;
        }
        src_end -= padlen;
    }

    if ((frame->flags & H2O_HTTP2_FRAME_FLAG_PRIORITY) != 0) {
        if (src_end - src < 5)
            return -1;
        src = decode_priority(&payload->priority, src);
    } else {
        payload->priority = h2o_http2_default_priority;
    }

    payload->headers = src;
    payload->headers_len = src_end - src;

    return 0;
}

int h2o_http2_decode_priority_payload(h2o_http2_priority_t *payload, const h2o_http2_frame_t *frame, const char **err_desc)
{
    if (frame->stream_id == 0) {
        *err_desc = "invalid stream id in PRIORITY frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }
    if (frame->length != 5) {
        *err_desc = "invalid PRIORITY frame";
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    }

    decode_priority(payload, frame->payload);
    return 0;
}

int h2o_http2_decode_rst_stream_payload(h2o_http2_rst_stream_payload_t *payload, const h2o_http2_frame_t *frame,
                                        const char **err_desc)
{
    if (frame->stream_id == 0) {
        *err_desc = "invalid stream id in RST_STREAM frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }
    if (frame->length != sizeof(payload->error_code)) {
        *err_desc = "invalid RST_STREAM frame";
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    }

    payload->error_code = h2o_http2_decode32u(frame->payload);
    return 0;
}

int h2o_http2_decode_ping_payload(h2o_http2_ping_payload_t *payload, const h2o_http2_frame_t *frame, const char **err_desc)
{
    if (frame->stream_id != 0) {
        *err_desc = "invalid PING frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }
    if (frame->length != sizeof(payload->data)) {
        *err_desc = "invalid PING frame";
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    }

    memcpy(payload->data, frame->payload, sizeof(payload->data));
    return 0;
}

int h2o_http2_decode_goaway_payload(h2o_http2_goaway_payload_t *payload, const h2o_http2_frame_t *frame, const char **err_desc)
{
    if (frame->stream_id != 0) {
        *err_desc = "invalid stream id in GOAWAY frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }
    if (frame->length < 8) {
        *err_desc = "invalid GOAWAY frame";
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    }

    payload->last_stream_id = h2o_http2_decode32u(frame->payload) & 0x7fffffff;
    payload->error_code = h2o_http2_decode32u(frame->payload + 4);
    if ((payload->debug_data.len = frame->length - 8) != 0)
        payload->debug_data.base = (char *)frame->payload + 8;
    else
        payload->debug_data.base = NULL;

    return 0;
}

int h2o_http2_decode_window_update_payload(h2o_http2_window_update_payload_t *payload, const h2o_http2_frame_t *frame,
                                           const char **err_desc, int *err_is_stream_level)
{
    if (frame->length != 4) {
        *err_is_stream_level = 0;
        *err_desc = "invalid WINDOW_UPDATE frame";
        return H2O_HTTP2_ERROR_FRAME_SIZE;
    }

    payload->window_size_increment = h2o_http2_decode32u(frame->payload) & 0x7fffffff;
    if (payload->window_size_increment == 0) {
        *err_is_stream_level = frame->stream_id != 0;
        *err_desc = "invalid WINDOW_UPDATE frame";
        return H2O_HTTP2_ERROR_PROTOCOL;
    }

    return 0;
}

