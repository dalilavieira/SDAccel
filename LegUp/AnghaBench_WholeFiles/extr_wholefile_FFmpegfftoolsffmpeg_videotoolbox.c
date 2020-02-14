#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_23__ {TYPE_3__* tmp_frame; } ;
typedef  TYPE_1__ VTContext ;
struct TYPE_26__ {TYPE_2__* opaque; int /*<<< orphan*/  codec_tag; } ;
struct TYPE_25__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  format; int /*<<< orphan*/  linesize; int /*<<< orphan*/ * data; } ;
struct TYPE_24__ {void (* hwaccel_uninit ) (TYPE_4__*) ;int (* hwaccel_retrieve_data ) (TYPE_4__*,TYPE_3__*) ;scalar_t__ hwaccel_id; TYPE_1__* hwaccel_ctx; } ;
typedef  int OSType ;
typedef  TYPE_2__ InputStream ;
typedef  scalar_t__ CVReturn ;
typedef  int /*<<< orphan*/  CVPixelBufferRef ;
typedef  int /*<<< orphan*/  CFStringRef ;
typedef  int /*<<< orphan*/  AVVideotoolboxContext ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_UNKNOWN ; 
 int AV_LOG_ERROR ; 
 int AV_LOG_VERBOSE ; 
 int /*<<< orphan*/  AV_PIX_FMT_BGRA ; 
 int /*<<< orphan*/  AV_PIX_FMT_UYVY422 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P ; 
 int /*<<< orphan*/  CFRelease (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CFStringCreateWithCString (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * CVPixelBufferGetBaseAddress (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * CVPixelBufferGetBaseAddressOfPlane (int /*<<< orphan*/ ,int) ; 
 int CVPixelBufferGetBytesPerRow (int /*<<< orphan*/ ) ; 
 int CVPixelBufferGetBytesPerRowOfPlane (int /*<<< orphan*/ ,int) ; 
 int CVPixelBufferGetPixelFormatType (int /*<<< orphan*/ ) ; 
 int CVPixelBufferGetPlaneCount (int /*<<< orphan*/ ) ; 
 scalar_t__ CVPixelBufferIsPlanar (int /*<<< orphan*/ ) ; 
 scalar_t__ CVPixelBufferLockBaseAddress (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CVPixelBufferUnlockBaseAddress (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  ENOSYS ; 
 scalar_t__ HWACCEL_AUTO ; 
 int /*<<< orphan*/  av_fourcc2str (int /*<<< orphan*/ ) ; 
 TYPE_3__* av_frame_alloc () ; 
 int av_frame_copy_props (TYPE_3__*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_free (TYPE_3__**) ; 
 int av_frame_get_buffer (TYPE_3__*,int) ; 
 int /*<<< orphan*/  av_frame_move_ref (TYPE_3__*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_3__*) ; 
 int /*<<< orphan*/  av_freep (TYPE_1__**) ; 
 int /*<<< orphan*/  av_image_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const**,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int,char*,...) ; 
 TYPE_1__* av_mallocz (int) ; 
 int /*<<< orphan*/ * av_videotoolbox_alloc_context () ; 
 int /*<<< orphan*/  av_videotoolbox_default_free (TYPE_4__*) ; 
 int av_videotoolbox_default_init (TYPE_4__*) ; 
 int av_videotoolbox_default_init2 (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kCFAllocatorDefault ; 
 int /*<<< orphan*/  kCFStringEncodingUTF8 ; 
 int /*<<< orphan*/  kCVPixelBufferLock_ReadOnly ; 
#define  kCVPixelFormatType_32BGRA 130 
#define  kCVPixelFormatType_420YpCbCr8Planar 129 
#define  kCVPixelFormatType_422YpCbCr8 128 
 scalar_t__ kCVReturnSuccess ; 
 int /*<<< orphan*/  videotoolbox_pixfmt ; 

__attribute__((used)) static int videotoolbox_retrieve_data(AVCodecContext *s, AVFrame *frame)
{
    InputStream *ist = s->opaque;
    VTContext  *vt = ist->hwaccel_ctx;
    CVPixelBufferRef pixbuf = (CVPixelBufferRef)frame->data[3];
    OSType pixel_format = CVPixelBufferGetPixelFormatType(pixbuf);
    CVReturn err;
    uint8_t *data[4] = { 0 };
    int linesize[4] = { 0 };
    int planes, ret, i;

    av_frame_unref(vt->tmp_frame);

    switch (pixel_format) {
    case kCVPixelFormatType_420YpCbCr8Planar: vt->tmp_frame->format = AV_PIX_FMT_YUV420P; break;
    case kCVPixelFormatType_422YpCbCr8:       vt->tmp_frame->format = AV_PIX_FMT_UYVY422; break;
    case kCVPixelFormatType_32BGRA:           vt->tmp_frame->format = AV_PIX_FMT_BGRA; break;
#ifdef kCFCoreFoundationVersionNumber10_7
    case kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange: vt->tmp_frame->format = AV_PIX_FMT_NV12; break;
#endif
#if HAVE_KCVPIXELFORMATTYPE_420YPCBCR10BIPLANARVIDEORANGE
    case kCVPixelFormatType_420YpCbCr10BiPlanarVideoRange: vt->tmp_frame->format = AV_PIX_FMT_P010; break;
#endif
    default:
        av_log(NULL, AV_LOG_ERROR,
               "%s: Unsupported pixel format: %s\n",
               av_fourcc2str(s->codec_tag), videotoolbox_pixfmt);
        return AVERROR(ENOSYS);
    }

    vt->tmp_frame->width  = frame->width;
    vt->tmp_frame->height = frame->height;
    ret = av_frame_get_buffer(vt->tmp_frame, 32);
    if (ret < 0)
        return ret;

    err = CVPixelBufferLockBaseAddress(pixbuf, kCVPixelBufferLock_ReadOnly);
    if (err != kCVReturnSuccess) {
        av_log(NULL, AV_LOG_ERROR, "Error locking the pixel buffer.\n");
        return AVERROR_UNKNOWN;
    }

    if (CVPixelBufferIsPlanar(pixbuf)) {

        planes = CVPixelBufferGetPlaneCount(pixbuf);
        for (i = 0; i < planes; i++) {
            data[i]     = CVPixelBufferGetBaseAddressOfPlane(pixbuf, i);
            linesize[i] = CVPixelBufferGetBytesPerRowOfPlane(pixbuf, i);
        }
    } else {
        data[0] = CVPixelBufferGetBaseAddress(pixbuf);
        linesize[0] = CVPixelBufferGetBytesPerRow(pixbuf);
    }

    av_image_copy(vt->tmp_frame->data, vt->tmp_frame->linesize,
                  (const uint8_t **)data, linesize, vt->tmp_frame->format,
                  frame->width, frame->height);

    ret = av_frame_copy_props(vt->tmp_frame, frame);
    CVPixelBufferUnlockBaseAddress(pixbuf, kCVPixelBufferLock_ReadOnly);
    if (ret < 0)
        return ret;

    av_frame_unref(frame);
    av_frame_move_ref(frame, vt->tmp_frame);

    return 0;
}

__attribute__((used)) static void videotoolbox_uninit(AVCodecContext *s)
{
    InputStream *ist = s->opaque;
    VTContext  *vt = ist->hwaccel_ctx;

    ist->hwaccel_uninit        = NULL;
    ist->hwaccel_retrieve_data = NULL;

    av_frame_free(&vt->tmp_frame);

    av_videotoolbox_default_free(s);
    av_freep(&ist->hwaccel_ctx);
}

int videotoolbox_init(AVCodecContext *s)
{
    InputStream *ist = s->opaque;
    int loglevel = (ist->hwaccel_id == HWACCEL_AUTO) ? AV_LOG_VERBOSE : AV_LOG_ERROR;
    int ret = 0;
    VTContext *vt;

    vt = av_mallocz(sizeof(*vt));
    if (!vt)
        return AVERROR(ENOMEM);

    ist->hwaccel_ctx           = vt;
    ist->hwaccel_uninit        = videotoolbox_uninit;
    ist->hwaccel_retrieve_data = videotoolbox_retrieve_data;

    vt->tmp_frame = av_frame_alloc();
    if (!vt->tmp_frame) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }

    // TODO: reindent
        if (!videotoolbox_pixfmt) {
            ret = av_videotoolbox_default_init(s);
        } else {
            AVVideotoolboxContext *vtctx = av_videotoolbox_alloc_context();
            CFStringRef pixfmt_str = CFStringCreateWithCString(kCFAllocatorDefault,
                                                               videotoolbox_pixfmt,
                                                               kCFStringEncodingUTF8);
#if HAVE_UTGETOSTYPEFROMSTRING
            vtctx->cv_pix_fmt_type = UTGetOSTypeFromString(pixfmt_str);
#else
            av_log(s, loglevel, "UTGetOSTypeFromString() is not available "
                   "on this platform, %s pixel format can not be honored from "
                   "the command line\n", videotoolbox_pixfmt);
#endif
            ret = av_videotoolbox_default_init2(s, vtctx);
            CFRelease(pixfmt_str);
        }
    if (ret < 0) {
        av_log(NULL, loglevel, "Error creating Videotoolbox decoder.\n");
        goto fail;
    }

    return 0;
fail:
    videotoolbox_uninit(s);
    return ret;
}

