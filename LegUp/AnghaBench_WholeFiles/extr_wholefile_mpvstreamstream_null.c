#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ buf_pos; scalar_t__ buf_len; int* buffer; int eof; scalar_t__ pos; } ;
typedef  TYPE_1__ stream_t ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 scalar_t__ stream_fill_buffer (TYPE_1__*) ; 

__attribute__((used)) inline static int stream_read_char(stream_t *s)
{
    return (s->buf_pos < s->buf_len) ? s->buffer[s->buf_pos++] :
           (stream_fill_buffer(s) ? s->buffer[s->buf_pos++] : -256);
}

__attribute__((used)) inline static int stream_eof(stream_t *s)
{
    return s->eof;
}

__attribute__((used)) inline static int64_t stream_tell(stream_t *s)
{
    return s->pos + s->buf_pos - s->buf_len;
}

__attribute__((used)) static int open_s(stream_t *stream)
{
  return 1;
}

