#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_51__   TYPE_9__ ;
typedef  struct TYPE_50__   TYPE_8__ ;
typedef  struct TYPE_49__   TYPE_7__ ;
typedef  struct TYPE_48__   TYPE_6__ ;
typedef  struct TYPE_47__   TYPE_5__ ;
typedef  struct TYPE_46__   TYPE_4__ ;
typedef  struct TYPE_45__   TYPE_3__ ;
typedef  struct TYPE_44__   TYPE_2__ ;
typedef  struct TYPE_43__   TYPE_24__ ;
typedef  struct TYPE_42__   TYPE_1__ ;
typedef  struct TYPE_41__   TYPE_12__ ;
typedef  struct TYPE_40__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  int64_t ;
struct TYPE_51__ {int nb_planes; TYPE_2__* planes; scalar_t__ format; } ;
struct TYPE_50__ {int interlaced_frame; int top_field_first; void* hw_frames_ctx; void** buf; int /*<<< orphan*/ ** data; int /*<<< orphan*/  colorspace; int /*<<< orphan*/  color_trc; int /*<<< orphan*/  color_primaries; int /*<<< orphan*/  color_range; int /*<<< orphan*/  pts; void* height; void* width; void* format; } ;
struct TYPE_49__ {void* height; void* width; int /*<<< orphan*/  sw_format; void* format; } ;
struct TYPE_48__ {int size; int /*<<< orphan*/  member_0; int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; } ;
struct TYPE_47__ {TYPE_12__* decoder_ref; } ;
struct TYPE_46__ {int* frame_group; int first_packet; int eos_reached; int nb_objects; int nb_layers; int /*<<< orphan*/ * ctx; TYPE_24__* mpi; TYPE_12__* frames_ref; TYPE_9__* layers; TYPE_1__* objects; TYPE_12__* device_ref; } ;
struct TYPE_45__ {TYPE_12__* decoder_ref; int /*<<< orphan*/ * frame; } ;
struct TYPE_44__ {int offset; int pitch; scalar_t__ object_index; } ;
struct TYPE_43__ {int (* decode_put_packet ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int (* reset ) (int /*<<< orphan*/ *) ;int (* control ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ;int (* decode_get_frame ) (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ;} ;
struct TYPE_42__ {int /*<<< orphan*/  size; int /*<<< orphan*/  fd; } ;
struct TYPE_41__ {scalar_t__ data; } ;
struct TYPE_40__ {int codec_id; int extradata_size; TYPE_5__* priv_data; void* height; void* width; int /*<<< orphan*/ * extradata; void* pix_fmt; } ;
typedef  int RK_S64 ;
typedef  int RK_S32 ;
typedef  TYPE_3__ RKMPPFrameContext ;
typedef  TYPE_4__ RKMPPDecoder ;
typedef  TYPE_5__ RKMPPDecodeContext ;
typedef  int /*<<< orphan*/  MppPacket ;
typedef  int MppFrameFormat ;
typedef  int /*<<< orphan*/ * MppFrame ;
typedef  scalar_t__ MppCodingType ;
typedef  int /*<<< orphan*/ * MppBuffer ;
typedef  TYPE_6__ AVPacket ;
typedef  TYPE_7__ AVHWFramesContext ;
typedef  TYPE_8__ AVFrame ;
typedef  TYPE_9__ AVDRMLayerDescriptor ;
typedef  TYPE_4__ AVDRMFrameDescriptor ;
typedef  TYPE_11__ AVCodecContext ;
typedef  TYPE_12__ AVBufferRef ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int AVERROR_UNKNOWN ; 
 int /*<<< orphan*/  AV_BUFFER_FLAG_READONLY ; 
#define  AV_CODEC_ID_H264 132 
#define  AV_CODEC_ID_HEVC 131 
#define  AV_CODEC_ID_VP8 130 
#define  AV_CODEC_ID_VP9 129 
 int /*<<< orphan*/  AV_HWDEVICE_TYPE_DRM ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 void* AV_PIX_FMT_DRM_PRIME ; 
 int /*<<< orphan*/  AV_PIX_FMT_NONE ; 
 int /*<<< orphan*/  AV_PIX_FMT_NV12 ; 
 scalar_t__ DRM_FORMAT_NV12 ; 
 int /*<<< orphan*/  EAGAIN ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  FRAMEGROUP_MAX_FRAMES ; 
 int INPUT_MAX_PACKETS ; 
 int /*<<< orphan*/  MPP_BUFFER_TYPE_ION ; 
 int /*<<< orphan*/  MPP_CTX_DEC ; 
 int /*<<< orphan*/  MPP_DEC_GET_STREAM_COUNT ; 
 int /*<<< orphan*/  MPP_DEC_SET_EXT_BUF_GROUP ; 
 int /*<<< orphan*/  MPP_DEC_SET_INFO_CHANGE_READY ; 
 int MPP_ERR_BUFFER_FULL ; 
 int MPP_ERR_TIMEOUT ; 
#define  MPP_FMT_YUV420SP 128 
 int MPP_FRAME_FLAG_DEINTERLACED ; 
 int MPP_FRAME_FLAG_FIELD_ORDER_MASK ; 
 int MPP_FRAME_FLAG_TOP_FIRST ; 
 int MPP_NOK ; 
 int MPP_OK ; 
 int MPP_POLL_BLOCK ; 
 int /*<<< orphan*/  MPP_SET_OUTPUT_BLOCK ; 
 int /*<<< orphan*/  MPP_SET_OUTPUT_BLOCK_TIMEOUT ; 
 scalar_t__ MPP_VIDEO_CodingAVC ; 
 scalar_t__ MPP_VIDEO_CodingHEVC ; 
 scalar_t__ MPP_VIDEO_CodingUnused ; 
 scalar_t__ MPP_VIDEO_CodingVP8 ; 
 scalar_t__ MPP_VIDEO_CodingVP9 ; 
 int RECEIVE_FRAME_TIMEOUT ; 
 TYPE_12__* av_buffer_allocz (int) ; 
 void* av_buffer_create (int /*<<< orphan*/ *,int,void (*) (void*,int /*<<< orphan*/ *),TYPE_12__*,int /*<<< orphan*/ ) ; 
 void* av_buffer_ref (TYPE_12__*) ; 
 int /*<<< orphan*/  av_buffer_unref (TYPE_12__**) ; 
 int /*<<< orphan*/  av_free (TYPE_4__*) ; 
 TYPE_12__* av_hwdevice_ctx_alloc (int /*<<< orphan*/ ) ; 
 int av_hwdevice_ctx_init (TYPE_12__*) ; 
 TYPE_12__* av_hwframe_ctx_alloc (TYPE_12__*) ; 
 int av_hwframe_ctx_init (TYPE_12__*) ; 
 int /*<<< orphan*/  av_log (TYPE_11__*,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_4__* av_mallocz (int) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_6__*) ; 
 int ff_decode_get_packet (TYPE_11__*,TYPE_6__*) ; 
 int /*<<< orphan*/  mpp_buffer_get_fd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_buffer_get_size (int /*<<< orphan*/ *) ; 
 int mpp_buffer_group_get_internal (int**,int /*<<< orphan*/ ) ; 
 int mpp_buffer_group_limit_config (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpp_buffer_group_put (int*) ; 
 int mpp_check_support_format (int /*<<< orphan*/ ,scalar_t__) ; 
 int mpp_create (int /*<<< orphan*/ **,TYPE_24__**) ; 
 int /*<<< orphan*/  mpp_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_deinit (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * mpp_frame_get_buffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_get_color_primaries (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_get_color_range (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_get_color_trc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_get_colorspace (int /*<<< orphan*/ *) ; 
 scalar_t__ mpp_frame_get_discard (int /*<<< orphan*/ *) ; 
 scalar_t__ mpp_frame_get_eos (int /*<<< orphan*/ *) ; 
 scalar_t__ mpp_frame_get_errinfo (int /*<<< orphan*/ *) ; 
 int mpp_frame_get_fmt (int /*<<< orphan*/ *) ; 
 void* mpp_frame_get_height (int /*<<< orphan*/ *) ; 
 int mpp_frame_get_hor_stride (int /*<<< orphan*/ *) ; 
 scalar_t__ mpp_frame_get_info_change (int /*<<< orphan*/ *) ; 
 int mpp_frame_get_mode (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpp_frame_get_pts (int /*<<< orphan*/ *) ; 
 int mpp_frame_get_ver_stride (int /*<<< orphan*/ *) ; 
 void* mpp_frame_get_width (int /*<<< orphan*/ *) ; 
 int mpp_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mpp_packet_deinit (int /*<<< orphan*/ *) ; 
 int mpp_packet_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mpp_packet_set_eos (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpp_packet_set_pts (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub2 (int /*<<< orphan*/ *) ; 
 int stub3 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int stub4 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int stub5 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int stub6 (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int stub7 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int stub8 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int stub9 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static MppCodingType rkmpp_get_codingtype(AVCodecContext *avctx)
{
    switch (avctx->codec_id) {
    case AV_CODEC_ID_H264:          return MPP_VIDEO_CodingAVC;
    case AV_CODEC_ID_HEVC:          return MPP_VIDEO_CodingHEVC;
    case AV_CODEC_ID_VP8:           return MPP_VIDEO_CodingVP8;
    case AV_CODEC_ID_VP9:           return MPP_VIDEO_CodingVP9;
    default:                        return MPP_VIDEO_CodingUnused;
    }
}

__attribute__((used)) static uint32_t rkmpp_get_frameformat(MppFrameFormat mppformat)
{
    switch (mppformat) {
    case MPP_FMT_YUV420SP:          return DRM_FORMAT_NV12;
#ifdef DRM_FORMAT_NV12_10
    case MPP_FMT_YUV420SP_10BIT:    return DRM_FORMAT_NV12_10;
#endif
    default:                        return 0;
    }
}

__attribute__((used)) static int rkmpp_write_data(AVCodecContext *avctx, uint8_t *buffer, int size, int64_t pts)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = (RKMPPDecoder *)rk_context->decoder_ref->data;
    int ret;
    MppPacket packet;

    // create the MPP packet
    ret = mpp_packet_init(&packet, buffer, size);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Failed to init MPP packet (code = %d)\n", ret);
        return AVERROR_UNKNOWN;
    }

    mpp_packet_set_pts(packet, pts);

    if (!buffer)
        mpp_packet_set_eos(packet);

    ret = decoder->mpi->decode_put_packet(decoder->ctx, packet);
    if (ret != MPP_OK) {
        if (ret == MPP_ERR_BUFFER_FULL) {
            av_log(avctx, AV_LOG_DEBUG, "Buffer full writing %d bytes to decoder\n", size);
            ret = AVERROR(EAGAIN);
        } else
            ret = AVERROR_UNKNOWN;
    }
    else
        av_log(avctx, AV_LOG_DEBUG, "Wrote %d bytes to decoder\n", size);

    mpp_packet_deinit(&packet);

    return ret;
}

__attribute__((used)) static int rkmpp_close_decoder(AVCodecContext *avctx)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    av_buffer_unref(&rk_context->decoder_ref);
    return 0;
}

__attribute__((used)) static void rkmpp_release_decoder(void *opaque, uint8_t *data)
{
    RKMPPDecoder *decoder = (RKMPPDecoder *)data;

    if (decoder->mpi) {
        decoder->mpi->reset(decoder->ctx);
        mpp_destroy(decoder->ctx);
        decoder->ctx = NULL;
    }

    if (decoder->frame_group) {
        mpp_buffer_group_put(decoder->frame_group);
        decoder->frame_group = NULL;
    }

    av_buffer_unref(&decoder->frames_ref);
    av_buffer_unref(&decoder->device_ref);

    av_free(decoder);
}

__attribute__((used)) static int rkmpp_init_decoder(AVCodecContext *avctx)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = NULL;
    MppCodingType codectype = MPP_VIDEO_CodingUnused;
    int ret;
    RK_S64 paramS64;
    RK_S32 paramS32;

    avctx->pix_fmt = AV_PIX_FMT_DRM_PRIME;

    // create a decoder and a ref to it
    decoder = av_mallocz(sizeof(RKMPPDecoder));
    if (!decoder) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }

    rk_context->decoder_ref = av_buffer_create((uint8_t *)decoder, sizeof(*decoder), rkmpp_release_decoder,
                                               NULL, AV_BUFFER_FLAG_READONLY);
    if (!rk_context->decoder_ref) {
        av_free(decoder);
        ret = AVERROR(ENOMEM);
        goto fail;
    }

    av_log(avctx, AV_LOG_DEBUG, "Initializing RKMPP decoder.\n");

    codectype = rkmpp_get_codingtype(avctx);
    if (codectype == MPP_VIDEO_CodingUnused) {
        av_log(avctx, AV_LOG_ERROR, "Unknown codec type (%d).\n", avctx->codec_id);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    ret = mpp_check_support_format(MPP_CTX_DEC, codectype);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Codec type (%d) unsupported by MPP\n", avctx->codec_id);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    // Create the MPP context
    ret = mpp_create(&decoder->ctx, &decoder->mpi);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Failed to create MPP context (code = %d).\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    // initialize mpp
    ret = mpp_init(decoder->ctx, MPP_CTX_DEC, codectype);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Failed to initialize MPP context (code = %d).\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    // make decode calls blocking with a timeout
    paramS32 = MPP_POLL_BLOCK;
    ret = decoder->mpi->control(decoder->ctx, MPP_SET_OUTPUT_BLOCK, &paramS32);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Failed to set blocking mode on MPI (code = %d).\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    paramS64 = RECEIVE_FRAME_TIMEOUT;
    ret = decoder->mpi->control(decoder->ctx, MPP_SET_OUTPUT_BLOCK_TIMEOUT, &paramS64);
    if (ret != MPP_OK) {
        av_log(avctx, AV_LOG_ERROR, "Failed to set block timeout on MPI (code = %d).\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    ret = mpp_buffer_group_get_internal(&decoder->frame_group, MPP_BUFFER_TYPE_ION);
    if (ret) {
       av_log(avctx, AV_LOG_ERROR, "Failed to retrieve buffer group (code = %d)\n", ret);
       ret = AVERROR_UNKNOWN;
       goto fail;
    }

    ret = decoder->mpi->control(decoder->ctx, MPP_DEC_SET_EXT_BUF_GROUP, decoder->frame_group);
    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "Failed to assign buffer group (code = %d)\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    ret = mpp_buffer_group_limit_config(decoder->frame_group, 0, FRAMEGROUP_MAX_FRAMES);
    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "Failed to set buffer group limit (code = %d)\n", ret);
        ret = AVERROR_UNKNOWN;
        goto fail;
    }

    decoder->first_packet = 1;

    av_log(avctx, AV_LOG_DEBUG, "RKMPP decoder initialized successfully.\n");

    decoder->device_ref = av_hwdevice_ctx_alloc(AV_HWDEVICE_TYPE_DRM);
    if (!decoder->device_ref) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }
    ret = av_hwdevice_ctx_init(decoder->device_ref);
    if (ret < 0)
        goto fail;

    return 0;

fail:
    av_log(avctx, AV_LOG_ERROR, "Failed to initialize RKMPP decoder.\n");
    rkmpp_close_decoder(avctx);
    return ret;
}

__attribute__((used)) static int rkmpp_send_packet(AVCodecContext *avctx, const AVPacket *avpkt)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = (RKMPPDecoder *)rk_context->decoder_ref->data;
    int ret;

    // handle EOF
    if (!avpkt->size) {
        av_log(avctx, AV_LOG_DEBUG, "End of stream.\n");
        decoder->eos_reached = 1;
        ret = rkmpp_write_data(avctx, NULL, 0, 0);
        if (ret)
            av_log(avctx, AV_LOG_ERROR, "Failed to send EOS to decoder (code = %d)\n", ret);
        return ret;
    }

    // on first packet, send extradata
    if (decoder->first_packet) {
        if (avctx->extradata_size) {
            ret = rkmpp_write_data(avctx, avctx->extradata,
                                            avctx->extradata_size,
                                            avpkt->pts);
            if (ret) {
                av_log(avctx, AV_LOG_ERROR, "Failed to write extradata to decoder (code = %d)\n", ret);
                return ret;
            }
        }
        decoder->first_packet = 0;
    }

    // now send packet
    ret = rkmpp_write_data(avctx, avpkt->data, avpkt->size, avpkt->pts);
    if (ret && ret!=AVERROR(EAGAIN))
        av_log(avctx, AV_LOG_ERROR, "Failed to write data to decoder (code = %d)\n", ret);

    return ret;
}

__attribute__((used)) static void rkmpp_release_frame(void *opaque, uint8_t *data)
{
    AVDRMFrameDescriptor *desc = (AVDRMFrameDescriptor *)data;
    AVBufferRef *framecontextref = (AVBufferRef *)opaque;
    RKMPPFrameContext *framecontext = (RKMPPFrameContext *)framecontextref->data;

    mpp_frame_deinit(&framecontext->frame);
    av_buffer_unref(&framecontext->decoder_ref);
    av_buffer_unref(&framecontextref);

    av_free(desc);
}

__attribute__((used)) static int rkmpp_retrieve_frame(AVCodecContext *avctx, AVFrame *frame)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = (RKMPPDecoder *)rk_context->decoder_ref->data;
    RKMPPFrameContext *framecontext = NULL;
    AVBufferRef *framecontextref = NULL;
    int ret;
    MppFrame mppframe = NULL;
    MppBuffer buffer = NULL;
    AVDRMFrameDescriptor *desc = NULL;
    AVDRMLayerDescriptor *layer = NULL;
    int mode;
    MppFrameFormat mppformat;
    uint32_t drmformat;

    ret = decoder->mpi->decode_get_frame(decoder->ctx, &mppframe);
    if (ret != MPP_OK && ret != MPP_ERR_TIMEOUT) {
        av_log(avctx, AV_LOG_ERROR, "Failed to get a frame from MPP (code = %d)\n", ret);
        goto fail;
    }

    if (mppframe) {
        // Check whether we have a special frame or not
        if (mpp_frame_get_info_change(mppframe)) {
            AVHWFramesContext *hwframes;

            av_log(avctx, AV_LOG_INFO, "Decoder noticed an info change (%dx%d), format=%d\n",
                                        (int)mpp_frame_get_width(mppframe), (int)mpp_frame_get_height(mppframe),
                                        (int)mpp_frame_get_fmt(mppframe));

            avctx->width = mpp_frame_get_width(mppframe);
            avctx->height = mpp_frame_get_height(mppframe);

            decoder->mpi->control(decoder->ctx, MPP_DEC_SET_INFO_CHANGE_READY, NULL);

            av_buffer_unref(&decoder->frames_ref);

            decoder->frames_ref = av_hwframe_ctx_alloc(decoder->device_ref);
            if (!decoder->frames_ref) {
                ret = AVERROR(ENOMEM);
                goto fail;
            }

            mppformat = mpp_frame_get_fmt(mppframe);
            drmformat = rkmpp_get_frameformat(mppformat);

            hwframes = (AVHWFramesContext*)decoder->frames_ref->data;
            hwframes->format    = AV_PIX_FMT_DRM_PRIME;
            hwframes->sw_format = drmformat == DRM_FORMAT_NV12 ? AV_PIX_FMT_NV12 : AV_PIX_FMT_NONE;
            hwframes->width     = avctx->width;
            hwframes->height    = avctx->height;
            ret = av_hwframe_ctx_init(decoder->frames_ref);
            if (ret < 0)
                goto fail;

            // here decoder is fully initialized, we need to feed it again with data
            ret = AVERROR(EAGAIN);
            goto fail;
        } else if (mpp_frame_get_eos(mppframe)) {
            av_log(avctx, AV_LOG_DEBUG, "Received a EOS frame.\n");
            decoder->eos_reached = 1;
            ret = AVERROR_EOF;
            goto fail;
        } else if (mpp_frame_get_discard(mppframe)) {
            av_log(avctx, AV_LOG_DEBUG, "Received a discard frame.\n");
            ret = AVERROR(EAGAIN);
            goto fail;
        } else if (mpp_frame_get_errinfo(mppframe)) {
            av_log(avctx, AV_LOG_ERROR, "Received a errinfo frame.\n");
            ret = AVERROR_UNKNOWN;
            goto fail;
        }

        // here we should have a valid frame
        av_log(avctx, AV_LOG_DEBUG, "Received a frame.\n");

        // setup general frame fields
        frame->format           = AV_PIX_FMT_DRM_PRIME;
        frame->width            = mpp_frame_get_width(mppframe);
        frame->height           = mpp_frame_get_height(mppframe);
        frame->pts              = mpp_frame_get_pts(mppframe);
        frame->color_range      = mpp_frame_get_color_range(mppframe);
        frame->color_primaries  = mpp_frame_get_color_primaries(mppframe);
        frame->color_trc        = mpp_frame_get_color_trc(mppframe);
        frame->colorspace       = mpp_frame_get_colorspace(mppframe);

        mode = mpp_frame_get_mode(mppframe);
        frame->interlaced_frame = ((mode & MPP_FRAME_FLAG_FIELD_ORDER_MASK) == MPP_FRAME_FLAG_DEINTERLACED);
        frame->top_field_first  = ((mode & MPP_FRAME_FLAG_FIELD_ORDER_MASK) == MPP_FRAME_FLAG_TOP_FIRST);

        mppformat = mpp_frame_get_fmt(mppframe);
        drmformat = rkmpp_get_frameformat(mppformat);

        // now setup the frame buffer info
        buffer = mpp_frame_get_buffer(mppframe);
        if (buffer) {
            desc = av_mallocz(sizeof(AVDRMFrameDescriptor));
            if (!desc) {
                ret = AVERROR(ENOMEM);
                goto fail;
            }

            desc->nb_objects = 1;
            desc->objects[0].fd = mpp_buffer_get_fd(buffer);
            desc->objects[0].size = mpp_buffer_get_size(buffer);

            desc->nb_layers = 1;
            layer = &desc->layers[0];
            layer->format = drmformat;
            layer->nb_planes = 2;

            layer->planes[0].object_index = 0;
            layer->planes[0].offset = 0;
            layer->planes[0].pitch = mpp_frame_get_hor_stride(mppframe);

            layer->planes[1].object_index = 0;
            layer->planes[1].offset = layer->planes[0].pitch * mpp_frame_get_ver_stride(mppframe);
            layer->planes[1].pitch = layer->planes[0].pitch;

            // we also allocate a struct in buf[0] that will allow to hold additionnal information
            // for releasing properly MPP frames and decoder
            framecontextref = av_buffer_allocz(sizeof(*framecontext));
            if (!framecontextref) {
                ret = AVERROR(ENOMEM);
                goto fail;
            }

            // MPP decoder needs to be closed only when all frames have been released.
            framecontext = (RKMPPFrameContext *)framecontextref->data;
            framecontext->decoder_ref = av_buffer_ref(rk_context->decoder_ref);
            framecontext->frame = mppframe;

            frame->data[0]  = (uint8_t *)desc;
            frame->buf[0]   = av_buffer_create((uint8_t *)desc, sizeof(*desc), rkmpp_release_frame,
                                               framecontextref, AV_BUFFER_FLAG_READONLY);

            if (!frame->buf[0]) {
                ret = AVERROR(ENOMEM);
                goto fail;
            }

            frame->hw_frames_ctx = av_buffer_ref(decoder->frames_ref);
            if (!frame->hw_frames_ctx) {
                ret = AVERROR(ENOMEM);
                goto fail;
            }

            return 0;
        } else {
            av_log(avctx, AV_LOG_ERROR, "Failed to retrieve the frame buffer, frame is dropped (code = %d)\n", ret);
            mpp_frame_deinit(&mppframe);
        }
    } else if (decoder->eos_reached) {
        return AVERROR_EOF;
    } else if (ret == MPP_ERR_TIMEOUT) {
        av_log(avctx, AV_LOG_DEBUG, "Timeout when trying to get a frame from MPP\n");
    }

    return AVERROR(EAGAIN);

fail:
    if (mppframe)
        mpp_frame_deinit(&mppframe);

    if (framecontext)
        av_buffer_unref(&framecontext->decoder_ref);

    if (framecontextref)
        av_buffer_unref(&framecontextref);

    if (desc)
        av_free(desc);

    return ret;
}

__attribute__((used)) static int rkmpp_receive_frame(AVCodecContext *avctx, AVFrame *frame)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = (RKMPPDecoder *)rk_context->decoder_ref->data;
    int ret = MPP_NOK;
    AVPacket pkt = {0};
    RK_S32 usedslots, freeslots;

    if (!decoder->eos_reached) {
        // we get the available slots in decoder
        ret = decoder->mpi->control(decoder->ctx, MPP_DEC_GET_STREAM_COUNT, &usedslots);
        if (ret != MPP_OK) {
            av_log(avctx, AV_LOG_ERROR, "Failed to get decoder used slots (code = %d).\n", ret);
            return ret;
        }

        freeslots = INPUT_MAX_PACKETS - usedslots;
        if (freeslots > 0) {
            ret = ff_decode_get_packet(avctx, &pkt);
            if (ret < 0 && ret != AVERROR_EOF) {
                return ret;
            }

            ret = rkmpp_send_packet(avctx, &pkt);
            av_packet_unref(&pkt);

            if (ret < 0) {
                av_log(avctx, AV_LOG_ERROR, "Failed to send packet to decoder (code = %d)\n", ret);
                return ret;
            }
        }

        // make sure we keep decoder full
        if (freeslots > 1)
            return AVERROR(EAGAIN);
    }

    return rkmpp_retrieve_frame(avctx, frame);
}

__attribute__((used)) static void rkmpp_flush(AVCodecContext *avctx)
{
    RKMPPDecodeContext *rk_context = avctx->priv_data;
    RKMPPDecoder *decoder = (RKMPPDecoder *)rk_context->decoder_ref->data;
    int ret = MPP_NOK;

    av_log(avctx, AV_LOG_DEBUG, "Flush.\n");

    ret = decoder->mpi->reset(decoder->ctx);
    if (ret == MPP_OK) {
        decoder->first_packet = 1;
    } else
        av_log(avctx, AV_LOG_ERROR, "Failed to reset MPI (code = %d)\n", ret);
}

