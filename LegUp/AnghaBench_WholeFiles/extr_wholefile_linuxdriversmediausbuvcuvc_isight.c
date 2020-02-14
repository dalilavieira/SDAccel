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
typedef  int u8 ;
struct v4l2_ext_control {int dummy; } ;
struct uvc_video_queue {int /*<<< orphan*/  queue; } ;
struct uvc_streaming {struct uvc_video_queue queue; } ;
struct uvc_fh {int dummy; } ;
struct uvc_buffer {scalar_t__ state; scalar_t__ bytesused; unsigned int length; int* mem; } ;
struct urb {int number_of_packets; int* transfer_buffer; TYPE_1__* iso_frame_desc; } ;
struct TYPE_2__ {scalar_t__ status; int offset; unsigned int actual_length; } ;

/* Variables and functions */
 int EAGAIN ; 
 scalar_t__ UVC_BUF_STATE_ACTIVE ; 
 scalar_t__ UVC_BUF_STATE_DONE ; 
 scalar_t__ UVC_BUF_STATE_ERROR ; 
 int /*<<< orphan*/  UVC_TRACE_FRAME ; 
 int __uvc_ctrl_commit (struct uvc_fh*,int,struct v4l2_ext_control const*,unsigned int) ; 
 scalar_t__ memcmp (int const*,int const*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,unsigned int) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 struct uvc_buffer* uvc_queue_next_buffer (struct uvc_video_queue*,struct uvc_buffer*) ; 
 int /*<<< orphan*/  uvc_trace (int /*<<< orphan*/ ,char*,...) ; 
 int vb2_is_streaming (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int uvc_queue_streaming(struct uvc_video_queue *queue)
{
	return vb2_is_streaming(&queue->queue);
}

__attribute__((used)) static inline int uvc_ctrl_commit(struct uvc_fh *handle,
				  const struct v4l2_ext_control *xctrls,
				  unsigned int xctrls_count)
{
	return __uvc_ctrl_commit(handle, 0, xctrls, xctrls_count);
}

__attribute__((used)) static inline int uvc_ctrl_rollback(struct uvc_fh *handle)
{
	return __uvc_ctrl_commit(handle, 1, NULL, 0);
}

__attribute__((used)) static int isight_decode(struct uvc_video_queue *queue, struct uvc_buffer *buf,
		const u8 *data, unsigned int len)
{
	static const u8 hdr[] = {
		0x11, 0x22, 0x33, 0x44,
		0xde, 0xad, 0xbe, 0xef,
		0xde, 0xad, 0xfa, 0xce
	};

	unsigned int maxlen, nbytes;
	u8 *mem;
	int is_header = 0;

	if (buf == NULL)
		return 0;

	if ((len >= 14 && memcmp(&data[2], hdr, 12) == 0) ||
	    (len >= 15 && memcmp(&data[3], hdr, 12) == 0)) {
		uvc_trace(UVC_TRACE_FRAME, "iSight header found\n");
		is_header = 1;
	}

	/* Synchronize to the input stream by waiting for a header packet. */
	if (buf->state != UVC_BUF_STATE_ACTIVE) {
		if (!is_header) {
			uvc_trace(UVC_TRACE_FRAME, "Dropping packet (out of "
				  "sync).\n");
			return 0;
		}

		buf->state = UVC_BUF_STATE_ACTIVE;
	}

	/* Mark the buffer as done if we're at the beginning of a new frame.
	 *
	 * Empty buffers (bytesused == 0) don't trigger end of frame detection
	 * as it doesn't make sense to return an empty buffer.
	 */
	if (is_header && buf->bytesused != 0) {
		buf->state = UVC_BUF_STATE_DONE;
		return -EAGAIN;
	}

	/* Copy the video data to the buffer. Skip header packets, as they
	 * contain no data.
	 */
	if (!is_header) {
		maxlen = buf->length - buf->bytesused;
		mem = buf->mem + buf->bytesused;
		nbytes = min(len, maxlen);
		memcpy(mem, data, nbytes);
		buf->bytesused += nbytes;

		if (len > maxlen || buf->bytesused == buf->length) {
			uvc_trace(UVC_TRACE_FRAME, "Frame complete "
				  "(overflow).\n");
			buf->state = UVC_BUF_STATE_DONE;
		}
	}

	return 0;
}

void uvc_video_decode_isight(struct urb *urb, struct uvc_streaming *stream,
			struct uvc_buffer *buf, struct uvc_buffer *meta_buf)
{
	int ret, i;

	for (i = 0; i < urb->number_of_packets; ++i) {
		if (urb->iso_frame_desc[i].status < 0) {
			uvc_trace(UVC_TRACE_FRAME, "USB isochronous frame "
				  "lost (%d).\n",
				  urb->iso_frame_desc[i].status);
		}

		/* Decode the payload packet.
		 * uvc_video_decode is entered twice when a frame transition
		 * has been detected because the end of frame can only be
		 * reliably detected when the first packet of the new frame
		 * is processed. The first pass detects the transition and
		 * closes the previous frame's buffer, the second pass
		 * processes the data of the first payload of the new frame.
		 */
		do {
			ret = isight_decode(&stream->queue, buf,
					urb->transfer_buffer +
					urb->iso_frame_desc[i].offset,
					urb->iso_frame_desc[i].actual_length);

			if (buf == NULL)
				break;

			if (buf->state == UVC_BUF_STATE_DONE ||
			    buf->state == UVC_BUF_STATE_ERROR)
				buf = uvc_queue_next_buffer(&stream->queue,
							buf);
		} while (ret == -EAGAIN);
	}
}

