#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_61__   TYPE_9__ ;
typedef  struct TYPE_60__   TYPE_8__ ;
typedef  struct TYPE_59__   TYPE_7__ ;
typedef  struct TYPE_58__   TYPE_6__ ;
typedef  struct TYPE_57__   TYPE_5__ ;
typedef  struct TYPE_56__   TYPE_4__ ;
typedef  struct TYPE_55__   TYPE_3__ ;
typedef  struct TYPE_54__   TYPE_2__ ;
typedef  struct TYPE_53__   TYPE_1__ ;
typedef  struct TYPE_52__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  enum AVHWDeviceType { ____Placeholder_AVHWDeviceType } AVHWDeviceType ;
struct TYPE_56__ {scalar_t__ codec; scalar_t__* profiles; TYPE_5__* guid; } ;
typedef  TYPE_4__ dxva_mode ;
typedef  int UINT ;
struct TYPE_61__ {void** data; scalar_t__* buf; } ;
struct TYPE_60__ {scalar_t__ type; } ;
struct TYPE_59__ {scalar_t__ format; int initial_pool_size; TYPE_8__* device_ctx; void* height; void* width; int /*<<< orphan*/  sw_format; } ;
struct TYPE_58__ {scalar_t__ pix_fmt; TYPE_11__* decoder_ref; TYPE_8__* device_ctx; int /*<<< orphan*/  workaround; } ;
struct TYPE_57__ {int /*<<< orphan*/ * Data4; int /*<<< orphan*/  Data3; int /*<<< orphan*/  Data2; scalar_t__ Data1; } ;
struct TYPE_55__ {scalar_t__ codec_id; int hwaccel_flags; scalar_t__ profile; scalar_t__ sw_pix_fmt; scalar_t__ pix_fmt; TYPE_2__* hw_frames_ctx; TYPE_1__* hwaccel; scalar_t__ hwaccel_context; int /*<<< orphan*/  coded_height; int /*<<< orphan*/  coded_width; } ;
struct TYPE_54__ {scalar_t__ data; } ;
struct TYPE_53__ {scalar_t__ pix_fmt; } ;
struct TYPE_52__ {scalar_t__ data; } ;
typedef  int /*<<< orphan*/  IUnknown ;
typedef  scalar_t__ HRESULT ;
typedef  TYPE_5__ GUID ;
typedef  TYPE_6__ FFDXVASharedContext ;
typedef  int /*<<< orphan*/  DECODER_BUFFER_DESC ;
typedef  TYPE_7__ AVHWFramesContext ;
typedef  TYPE_8__ AVHWDeviceContext ;
typedef  TYPE_9__ AVFrame ;
typedef  int /*<<< orphan*/  AVDXVAContext ;
typedef  TYPE_3__ AVCodecContext ;
typedef  TYPE_11__ AVBufferRef ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ AV_CODEC_ID_H264 ; 
 scalar_t__ AV_CODEC_ID_HEVC ; 
 scalar_t__ AV_CODEC_ID_MPEG2VIDEO ; 
 scalar_t__ AV_CODEC_ID_VP9 ; 
 int AV_HWACCEL_FLAG_ALLOW_PROFILE_MISMATCH ; 
 scalar_t__ AV_HWDEVICE_TYPE_D3D11VA ; 
 scalar_t__ AV_HWDEVICE_TYPE_DXVA2 ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_VERBOSE ; 
 int AV_NUM_DATA_POINTERS ; 
 scalar_t__ AV_PIX_FMT_D3D11 ; 
 scalar_t__ AV_PIX_FMT_D3D11VA_VLD ; 
 scalar_t__ AV_PIX_FMT_DXVA2_VLD ; 
 int /*<<< orphan*/  AV_PIX_FMT_NV12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_P010 ; 
 scalar_t__ AV_PIX_FMT_YUV420P10 ; 
 scalar_t__ CONFIG_D3D11VA ; 
 int /*<<< orphan*/ * DXVA_CONTEXT (TYPE_3__*) ; 
 TYPE_6__* DXVA_SHARED_CONTEXT (TYPE_3__*) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 scalar_t__ E_PENDING ; 
 scalar_t__ FAILED (scalar_t__) ; 
 void* FFALIGN (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FF_DXVA2_WORKAROUND_INTEL_CLEARVIDEO ; 
 scalar_t__ FF_PROFILE_UNKNOWN ; 
 int /*<<< orphan*/  IUnknown_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IsEqualGUID (TYPE_5__*,TYPE_5__ const*) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_11__* av_buffer_create (int /*<<< orphan*/ *,int,void (*) (void*,int /*<<< orphan*/ *),int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ av_buffer_ref (TYPE_11__*) ; 
 int /*<<< orphan*/  av_buffer_unref (TYPE_11__**) ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_usleep (int) ; 
 TYPE_4__* dxva_modes ; 
 TYPE_5__ const ff_DXVA2_NoEncrypt ; 
 TYPE_5__ const ff_DXVADDI_Intel_ModeH264_E ; 
 TYPE_5__ const ff_GUID_NULL ; 
 int ff_decode_get_hw_frames_ctx (TYPE_3__*,int) ; 
 int ff_dxva2_decode_uninit (TYPE_3__*) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,unsigned int) ; 

__attribute__((used)) static int dxva_get_decoder_configuration(AVCodecContext *avctx,
                                          const void *cfg_list,
                                          unsigned cfg_count)
{
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
    unsigned i, best_score = 0;
    int best_cfg = -1;

    for (i = 0; i < cfg_count; i++) {
        unsigned score;
        UINT ConfigBitstreamRaw;
        GUID guidConfigBitstreamEncryption;

#if CONFIG_D3D11VA
        if (sctx->pix_fmt == AV_PIX_FMT_D3D11) {
            D3D11_VIDEO_DECODER_CONFIG *cfg = &((D3D11_VIDEO_DECODER_CONFIG *)cfg_list)[i];
            ConfigBitstreamRaw = cfg->ConfigBitstreamRaw;
            guidConfigBitstreamEncryption = cfg->guidConfigBitstreamEncryption;
        }
#endif
#if CONFIG_DXVA2
        if (sctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
            DXVA2_ConfigPictureDecode *cfg = &((DXVA2_ConfigPictureDecode *)cfg_list)[i];
            ConfigBitstreamRaw = cfg->ConfigBitstreamRaw;
            guidConfigBitstreamEncryption = cfg->guidConfigBitstreamEncryption;
        }
#endif

        if (ConfigBitstreamRaw == 1)
            score = 1;
        else if (avctx->codec_id == AV_CODEC_ID_H264 && ConfigBitstreamRaw == 2)
            score = 2;
        else
            continue;
        if (IsEqualGUID(&guidConfigBitstreamEncryption, &ff_DXVA2_NoEncrypt))
            score += 16;
        if (score > best_score) {
            best_score = score;
            best_cfg = i;
        }
    }

    if (!best_score) {
        av_log(avctx, AV_LOG_VERBOSE, "No valid decoder configuration available\n");
        return AVERROR(EINVAL);
    }

    return best_cfg;
}

__attribute__((used)) static int dxva_check_codec_compatibility(AVCodecContext *avctx, const dxva_mode *mode)
{
    if (mode->codec != avctx->codec_id)
            return 0;

    if (mode->profiles && !(avctx->hwaccel_flags & AV_HWACCEL_FLAG_ALLOW_PROFILE_MISMATCH)) {
        int i, found = 0;
        for (i = 0; mode->profiles[i] != FF_PROFILE_UNKNOWN; i++) {
            if (avctx->profile == mode->profiles[i]) {
                found = 1;
                break;
            }
        }
        if (!found)
            return 0;
    }

    return 1;
}

__attribute__((used)) static void dxva_list_guids_debug(AVCodecContext *avctx, void *service,
                                 unsigned guid_count, const GUID *guid_list)
{
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
    int i;

    av_log(avctx, AV_LOG_VERBOSE, "Decoder GUIDs reported as supported:\n");

    for (i = 0; i < guid_count; i++) {
        const GUID *guid = &guid_list[i];

        av_log(avctx, AV_LOG_VERBOSE,
             "{%8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x}",
             (unsigned) guid->Data1, guid->Data2, guid->Data3,
             guid->Data4[0], guid->Data4[1],
             guid->Data4[2], guid->Data4[3],
             guid->Data4[4], guid->Data4[5],
             guid->Data4[6], guid->Data4[7]);

#if CONFIG_D3D11VA
        if (sctx->pix_fmt == AV_PIX_FMT_D3D11) {
            DXGI_FORMAT format;
            // We don't know the maximum valid DXGI_FORMAT, so use 200 as
            // arbitrary upper bound (that could become outdated).
            for (format = 0; format < 200; format++) {
                if (d3d11va_validate_output(service, *guid, &format))
                    av_log(avctx, AV_LOG_VERBOSE, " %d", (int)format);
            }
        }
#endif
#if CONFIG_DXVA2
        if (sctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
            const D3DFORMAT formats[] = {MKTAG('N', 'V', '1', '2'),
                                         MKTAG('P', '0', '1', '0')};
            int i;
            for (i = 0; i < FF_ARRAY_ELEMS(formats); i++) {
                if (dxva2_validate_output(service, *guid, &formats[i]))
                    av_log(avctx, AV_LOG_VERBOSE, " %d", i);
            }
        }
#endif
        av_log(avctx, AV_LOG_VERBOSE, "\n");
    }
}

__attribute__((used)) static int dxva_get_decoder_guid(AVCodecContext *avctx, void *service, void *surface_format,
                                 unsigned guid_count, const GUID *guid_list, GUID *decoder_guid)
{
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
    unsigned i, j;

    dxva_list_guids_debug(avctx, service, guid_count, guid_list);

    *decoder_guid = ff_GUID_NULL;
    for (i = 0; dxva_modes[i].guid; i++) {
        const dxva_mode *mode = &dxva_modes[i];
        int validate;
        if (!dxva_check_codec_compatibility(avctx, mode))
            continue;

        for (j = 0; j < guid_count; j++) {
            if (IsEqualGUID(mode->guid, &guid_list[j]))
                break;
        }
        if (j == guid_count)
            continue;

#if CONFIG_D3D11VA
        if (sctx->pix_fmt == AV_PIX_FMT_D3D11)
            validate = d3d11va_validate_output(service, *mode->guid, surface_format);
#endif
#if CONFIG_DXVA2
        if (sctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD)
            validate = dxva2_validate_output(service, *mode->guid, surface_format);
#endif
        if (validate) {
            *decoder_guid = *mode->guid;
            break;
        }
    }

    if (IsEqualGUID(decoder_guid, &ff_GUID_NULL)) {
        av_log(avctx, AV_LOG_VERBOSE, "No decoder device for codec found\n");
        return AVERROR(EINVAL);
    }

    if (IsEqualGUID(decoder_guid, &ff_DXVADDI_Intel_ModeH264_E))
        sctx->workaround |= FF_DXVA2_WORKAROUND_INTEL_CLEARVIDEO;

    return 0;
}

__attribute__((used)) static void bufref_free_interface(void *opaque, uint8_t *data)
{
    IUnknown_Release((IUnknown *)opaque);
}

__attribute__((used)) static AVBufferRef *bufref_wrap_interface(IUnknown *iface)
{
    return av_buffer_create((uint8_t*)iface, 1, bufref_free_interface, iface, 0);
}

__attribute__((used)) static void ff_dxva2_lock(AVCodecContext *avctx)
{
#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx)) {
        FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
        AVDXVAContext *ctx = DXVA_CONTEXT(avctx);
        if (D3D11VA_CONTEXT(ctx)->context_mutex != INVALID_HANDLE_VALUE)
            WaitForSingleObjectEx(D3D11VA_CONTEXT(ctx)->context_mutex, INFINITE, FALSE);
        if (sctx->device_ctx) {
            AVD3D11VADeviceContext *hwctx = sctx->device_ctx->hwctx;
            hwctx->lock(hwctx->lock_ctx);
        }
    }
#endif
}

__attribute__((used)) static void ff_dxva2_unlock(AVCodecContext *avctx)
{
#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx)) {
        FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
        AVDXVAContext *ctx = DXVA_CONTEXT(avctx);
        if (D3D11VA_CONTEXT(ctx)->context_mutex != INVALID_HANDLE_VALUE)
            ReleaseMutex(D3D11VA_CONTEXT(ctx)->context_mutex);
        if (sctx->device_ctx) {
            AVD3D11VADeviceContext *hwctx = sctx->device_ctx->hwctx;
            hwctx->unlock(hwctx->lock_ctx);
        }
    }
#endif
}

int ff_dxva2_common_frame_params(AVCodecContext *avctx,
                                 AVBufferRef *hw_frames_ctx)
{
    AVHWFramesContext *frames_ctx = (AVHWFramesContext *)hw_frames_ctx->data;
    AVHWDeviceContext *device_ctx = frames_ctx->device_ctx;
    int surface_alignment, num_surfaces;

    if (device_ctx->type == AV_HWDEVICE_TYPE_DXVA2) {
        frames_ctx->format = AV_PIX_FMT_DXVA2_VLD;
    } else if (device_ctx->type == AV_HWDEVICE_TYPE_D3D11VA) {
        frames_ctx->format = AV_PIX_FMT_D3D11;
    } else {
        return AVERROR(EINVAL);
    }

    /* decoding MPEG-2 requires additional alignment on some Intel GPUs,
    but it causes issues for H.264 on certain AMD GPUs..... */
    if (avctx->codec_id == AV_CODEC_ID_MPEG2VIDEO)
        surface_alignment = 32;
    /* the HEVC DXVA2 spec asks for 128 pixel aligned surfaces to ensure
    all coding features have enough room to work with */
    else if (avctx->codec_id == AV_CODEC_ID_HEVC)
        surface_alignment = 128;
    else
        surface_alignment = 16;

    /* 1 base work surface */
    num_surfaces = 1;

    /* add surfaces based on number of possible refs */
    if (avctx->codec_id == AV_CODEC_ID_H264 || avctx->codec_id == AV_CODEC_ID_HEVC)
        num_surfaces += 16;
    else if (avctx->codec_id == AV_CODEC_ID_VP9)
        num_surfaces += 8;
    else
        num_surfaces += 2;

    frames_ctx->sw_format = avctx->sw_pix_fmt == AV_PIX_FMT_YUV420P10 ?
                            AV_PIX_FMT_P010 : AV_PIX_FMT_NV12;
    frames_ctx->width = FFALIGN(avctx->coded_width, surface_alignment);
    frames_ctx->height = FFALIGN(avctx->coded_height, surface_alignment);
    frames_ctx->initial_pool_size = num_surfaces;


#if CONFIG_DXVA2
    if (frames_ctx->format == AV_PIX_FMT_DXVA2_VLD) {
        AVDXVA2FramesContext *frames_hwctx = frames_ctx->hwctx;

        frames_hwctx->surface_type = DXVA2_VideoDecoderRenderTarget;
    }
#endif

#if CONFIG_D3D11VA
    if (frames_ctx->format == AV_PIX_FMT_D3D11) {
        AVD3D11VAFramesContext *frames_hwctx = frames_ctx->hwctx;

        frames_hwctx->BindFlags |= D3D11_BIND_DECODER;
    }
#endif

    return 0;
}

int ff_dxva2_decode_init(AVCodecContext *avctx)
{
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
    AVHWFramesContext *frames_ctx;
    enum AVHWDeviceType dev_type = avctx->hwaccel->pix_fmt == AV_PIX_FMT_DXVA2_VLD
                            ? AV_HWDEVICE_TYPE_DXVA2 : AV_HWDEVICE_TYPE_D3D11VA;
    int ret = 0;

    // Old API.
    if (avctx->hwaccel_context)
        return 0;

    // (avctx->pix_fmt is not updated yet at this point)
    sctx->pix_fmt = avctx->hwaccel->pix_fmt;

    ret = ff_decode_get_hw_frames_ctx(avctx, dev_type);
    if (ret < 0)
        return ret;

    frames_ctx = (AVHWFramesContext*)avctx->hw_frames_ctx->data;
    sctx->device_ctx = frames_ctx->device_ctx;

    if (frames_ctx->format != sctx->pix_fmt) {
        av_log(avctx, AV_LOG_ERROR, "Invalid pixfmt for hwaccel!\n");
        ret = AVERROR(EINVAL);
        goto fail;
    }

#if CONFIG_D3D11VA
    if (sctx->pix_fmt == AV_PIX_FMT_D3D11) {
        AVD3D11VADeviceContext *device_hwctx = frames_ctx->device_ctx->hwctx;
        AVD3D11VAContext *d3d11_ctx = &sctx->ctx.d3d11va;

        ff_dxva2_lock(avctx);
        ret = d3d11va_create_decoder(avctx);
        ff_dxva2_unlock(avctx);
        if (ret < 0)
            goto fail;

        d3d11_ctx->decoder       = sctx->d3d11_decoder;
        d3d11_ctx->video_context = device_hwctx->video_context;
        d3d11_ctx->cfg           = &sctx->d3d11_config;
        d3d11_ctx->surface_count = sctx->nb_d3d11_views;
        d3d11_ctx->surface       = sctx->d3d11_views;
        d3d11_ctx->workaround    = sctx->workaround;
        d3d11_ctx->context_mutex = INVALID_HANDLE_VALUE;
    }
#endif

#if CONFIG_DXVA2
    if (sctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
        AVDXVA2FramesContext *frames_hwctx = frames_ctx->hwctx;
        struct dxva_context *dxva_ctx = &sctx->ctx.dxva2;

        ff_dxva2_lock(avctx);
        ret = dxva2_create_decoder(avctx);
        ff_dxva2_unlock(avctx);
        if (ret < 0)
            goto fail;

        dxva_ctx->decoder       = sctx->dxva2_decoder;
        dxva_ctx->cfg           = &sctx->dxva2_config;
        dxva_ctx->surface       = frames_hwctx->surfaces;
        dxva_ctx->surface_count = frames_hwctx->nb_surfaces;
        dxva_ctx->workaround    = sctx->workaround;
    }
#endif

    return 0;

fail:
    ff_dxva2_decode_uninit(avctx);
    return ret;
}

int ff_dxva2_decode_uninit(AVCodecContext *avctx)
{
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
    int i;

    av_buffer_unref(&sctx->decoder_ref);

#if CONFIG_D3D11VA
    for (i = 0; i < sctx->nb_d3d11_views; i++) {
        if (sctx->d3d11_views[i])
            ID3D11VideoDecoderOutputView_Release(sctx->d3d11_views[i]);
    }
    av_freep(&sctx->d3d11_views);
#endif

#if CONFIG_DXVA2
    if (sctx->dxva2_service)
        IDirectXVideoDecoderService_Release(sctx->dxva2_service);
#endif

    return 0;
}

__attribute__((used)) static void *get_surface(const AVCodecContext *avctx, const AVFrame *frame)
{
#if CONFIG_D3D11VA
    if (frame->format == AV_PIX_FMT_D3D11) {
        FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);
        intptr_t index = (intptr_t)frame->data[1];
        if (index < 0 || index >= sctx->nb_d3d11_views ||
            sctx->d3d11_texture != (ID3D11Texture2D *)frame->data[0]) {
            av_log((void *)avctx, AV_LOG_ERROR, "get_buffer frame is invalid!\n");
            return NULL;
        }
        return sctx->d3d11_views[index];
    }
#endif
    return frame->data[3];
}

unsigned ff_dxva2_get_surface_index(const AVCodecContext *avctx,
                                    const AVDXVAContext *ctx,
                                    const AVFrame *frame)
{
    void *surface = get_surface(avctx, frame);
    unsigned i;

#if CONFIG_D3D11VA
    if (avctx->pix_fmt == AV_PIX_FMT_D3D11)
        return (intptr_t)frame->data[1];
    if (avctx->pix_fmt == AV_PIX_FMT_D3D11VA_VLD) {
        D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
        ID3D11VideoDecoderOutputView_GetDesc((ID3D11VideoDecoderOutputView*) surface, &viewDesc);
        return viewDesc.Texture2D.ArraySlice;
    }
#endif
#if CONFIG_DXVA2
    for (i = 0; i < DXVA_CONTEXT_COUNT(avctx, ctx); i++) {
        if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD && ctx->dxva2.surface[i] == surface)
            return i;
    }
#endif

    assert(0);
    return 0;
}

int ff_dxva2_commit_buffer(AVCodecContext *avctx,
                           AVDXVAContext *ctx,
                           DECODER_BUFFER_DESC *dsc,
                           unsigned type, const void *data, unsigned size,
                           unsigned mb_count)
{
    void     *dxva_data;
    unsigned dxva_size;
    int      result;
    HRESULT hr = 0;

#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx))
        hr = ID3D11VideoContext_GetDecoderBuffer(D3D11VA_CONTEXT(ctx)->video_context,
                                                 D3D11VA_CONTEXT(ctx)->decoder,
                                                 type,
                                                 &dxva_size, &dxva_data);
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD)
        hr = IDirectXVideoDecoder_GetBuffer(DXVA2_CONTEXT(ctx)->decoder, type,
                                            &dxva_data, &dxva_size);
#endif
    if (FAILED(hr)) {
        av_log(avctx, AV_LOG_ERROR, "Failed to get a buffer for %u: 0x%x\n",
               type, (unsigned)hr);
        return -1;
    }
    if (size <= dxva_size) {
        memcpy(dxva_data, data, size);

#if CONFIG_D3D11VA
        if (ff_dxva2_is_d3d11(avctx)) {
            D3D11_VIDEO_DECODER_BUFFER_DESC *dsc11 = dsc;
            memset(dsc11, 0, sizeof(*dsc11));
            dsc11->BufferType           = type;
            dsc11->DataSize             = size;
            dsc11->NumMBsInBuffer       = mb_count;
        }
#endif
#if CONFIG_DXVA2
        if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
            DXVA2_DecodeBufferDesc *dsc2 = dsc;
            memset(dsc2, 0, sizeof(*dsc2));
            dsc2->CompressedBufferType = type;
            dsc2->DataSize             = size;
            dsc2->NumMBsInBuffer       = mb_count;
        }
#endif

        result = 0;
    } else {
        av_log(avctx, AV_LOG_ERROR, "Buffer for type %u was too small\n", type);
        result = -1;
    }

#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx))
        hr = ID3D11VideoContext_ReleaseDecoderBuffer(D3D11VA_CONTEXT(ctx)->video_context, D3D11VA_CONTEXT(ctx)->decoder, type);
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD)
        hr = IDirectXVideoDecoder_ReleaseBuffer(DXVA2_CONTEXT(ctx)->decoder, type);
#endif
    if (FAILED(hr)) {
        av_log(avctx, AV_LOG_ERROR,
               "Failed to release buffer type %u: 0x%x\n",
               type, (unsigned)hr);
        result = -1;
    }
    return result;
}

__attribute__((used)) static int frame_add_buf(AVFrame *frame, AVBufferRef *ref)
{
    int i;

    for (i = 0; i < AV_NUM_DATA_POINTERS; i++) {
        if (!frame->buf[i]) {
            frame->buf[i] = av_buffer_ref(ref);
            return frame->buf[i] ? 0 : AVERROR(ENOMEM);
        }
    }

    // For now we expect that the caller does not use more than
    // AV_NUM_DATA_POINTERS-1 buffers if the user uses a custom pool.
    return AVERROR(EINVAL);
}

int ff_dxva2_common_end_frame(AVCodecContext *avctx, AVFrame *frame,
                              const void *pp, unsigned pp_size,
                              const void *qm, unsigned qm_size,
                              int (*commit_bs_si)(AVCodecContext *,
                                                  DECODER_BUFFER_DESC *bs,
                                                  DECODER_BUFFER_DESC *slice))
{
    AVDXVAContext *ctx = DXVA_CONTEXT(avctx);
    unsigned               buffer_count = 0;
#if CONFIG_D3D11VA
    D3D11_VIDEO_DECODER_BUFFER_DESC buffer11[4];
#endif
#if CONFIG_DXVA2
    DXVA2_DecodeBufferDesc          buffer2[4];
#endif
    DECODER_BUFFER_DESC             *buffer = NULL, *buffer_slice = NULL;
    int result, runs = 0;
    HRESULT hr;
    unsigned type;
    FFDXVASharedContext *sctx = DXVA_SHARED_CONTEXT(avctx);

    if (sctx->decoder_ref) {
        result = frame_add_buf(frame, sctx->decoder_ref);
        if (result < 0)
            return result;
    }

    do {
        ff_dxva2_lock(avctx);
#if CONFIG_D3D11VA
        if (ff_dxva2_is_d3d11(avctx))
            hr = ID3D11VideoContext_DecoderBeginFrame(D3D11VA_CONTEXT(ctx)->video_context, D3D11VA_CONTEXT(ctx)->decoder,
                                                      get_surface(avctx, frame),
                                                      0, NULL);
#endif
#if CONFIG_DXVA2
        if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD)
            hr = IDirectXVideoDecoder_BeginFrame(DXVA2_CONTEXT(ctx)->decoder,
                                                 get_surface(avctx, frame),
                                                 NULL);
#endif
        if (hr != E_PENDING || ++runs > 50)
            break;
        ff_dxva2_unlock(avctx);
        av_usleep(2000);
    } while(1);

    if (FAILED(hr)) {
        av_log(avctx, AV_LOG_ERROR, "Failed to begin frame: 0x%x\n", (unsigned)hr);
        ff_dxva2_unlock(avctx);
        return -1;
    }

#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx)) {
        buffer = &buffer11[buffer_count];
        type = D3D11_VIDEO_DECODER_BUFFER_PICTURE_PARAMETERS;
    }
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
        buffer = &buffer2[buffer_count];
        type = DXVA2_PictureParametersBufferType;
    }
#endif
    result = ff_dxva2_commit_buffer(avctx, ctx, buffer,
                                    type,
                                    pp, pp_size, 0);
    if (result) {
        av_log(avctx, AV_LOG_ERROR,
               "Failed to add picture parameter buffer\n");
        goto end;
    }
    buffer_count++;

    if (qm_size > 0) {
#if CONFIG_D3D11VA
        if (ff_dxva2_is_d3d11(avctx)) {
            buffer = &buffer11[buffer_count];
            type = D3D11_VIDEO_DECODER_BUFFER_INVERSE_QUANTIZATION_MATRIX;
        }
#endif
#if CONFIG_DXVA2
        if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
            buffer = &buffer2[buffer_count];
            type = DXVA2_InverseQuantizationMatrixBufferType;
        }
#endif
        result = ff_dxva2_commit_buffer(avctx, ctx, buffer,
                                        type,
                                        qm, qm_size, 0);
        if (result) {
            av_log(avctx, AV_LOG_ERROR,
                   "Failed to add inverse quantization matrix buffer\n");
            goto end;
        }
        buffer_count++;
    }

#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx)) {
        buffer       = &buffer11[buffer_count + 0];
        buffer_slice = &buffer11[buffer_count + 1];
    }
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
        buffer       = &buffer2[buffer_count + 0];
        buffer_slice = &buffer2[buffer_count + 1];
    }
#endif

    result = commit_bs_si(avctx,
                          buffer,
                          buffer_slice);
    if (result) {
        av_log(avctx, AV_LOG_ERROR,
               "Failed to add bitstream or slice control buffer\n");
        goto end;
    }
    buffer_count += 2;

    /* TODO Film Grain when possible */

    assert(buffer_count == 1 + (qm_size > 0) + 2);

#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx))
        hr = ID3D11VideoContext_SubmitDecoderBuffers(D3D11VA_CONTEXT(ctx)->video_context,
                                                     D3D11VA_CONTEXT(ctx)->decoder,
                                                     buffer_count, buffer11);
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD) {
        DXVA2_DecodeExecuteParams exec = {
            .NumCompBuffers     = buffer_count,
            .pCompressedBuffers = buffer2,
            .pExtensionData     = NULL,
        };
        hr = IDirectXVideoDecoder_Execute(DXVA2_CONTEXT(ctx)->decoder, &exec);
    }
#endif
    if (FAILED(hr)) {
        av_log(avctx, AV_LOG_ERROR, "Failed to execute: 0x%x\n", (unsigned)hr);
        result = -1;
    }

end:
#if CONFIG_D3D11VA
    if (ff_dxva2_is_d3d11(avctx))
        hr = ID3D11VideoContext_DecoderEndFrame(D3D11VA_CONTEXT(ctx)->video_context, D3D11VA_CONTEXT(ctx)->decoder);
#endif
#if CONFIG_DXVA2
    if (avctx->pix_fmt == AV_PIX_FMT_DXVA2_VLD)
        hr = IDirectXVideoDecoder_EndFrame(DXVA2_CONTEXT(ctx)->decoder, NULL);
#endif
    ff_dxva2_unlock(avctx);
    if (FAILED(hr)) {
        av_log(avctx, AV_LOG_ERROR, "Failed to end frame: 0x%x\n", (unsigned)hr);
        result = -1;
    }

    return result;
}

int ff_dxva2_is_d3d11(const AVCodecContext *avctx)
{
    if (CONFIG_D3D11VA)
        return avctx->pix_fmt == AV_PIX_FMT_D3D11VA_VLD ||
               avctx->pix_fmt == AV_PIX_FMT_D3D11;
    else
        return 0;
}

