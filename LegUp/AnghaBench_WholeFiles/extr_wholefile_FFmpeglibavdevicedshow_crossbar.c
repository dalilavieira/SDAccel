#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct dshow_ctx {int crossbar_video_input_pin_number; int crossbar_audio_input_pin_number; char** device_name; scalar_t__ show_analog_tv_tuner_audio_dialog; scalar_t__ show_analog_tv_tuner_dialog; scalar_t__ show_audio_crossbar_connection_dialog; scalar_t__ show_video_crossbar_connection_dialog; scalar_t__ list_options; } ;
typedef  enum dshowDeviceType { ____Placeholder_dshowDeviceType } dshowDeviceType ;
struct TYPE_6__ {struct dshow_ctx* priv_data; } ;
typedef  int /*<<< orphan*/  ICaptureGraphBuilder2 ;
typedef  int /*<<< orphan*/  IBaseFilter ;
typedef  int /*<<< orphan*/  IAMTVTuner ;
typedef  int /*<<< orphan*/  IAMCrossbar ;
typedef  int /*<<< orphan*/  IAMAudioInputMixer ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/  GUID ;
typedef  TYPE_1__ AVFormatContext ;

/* Variables and functions */
 scalar_t__ AVERROR (int /*<<< orphan*/ ) ; 
 int AV_LOG_DEBUG ; 
 int AV_LOG_ERROR ; 
 int AV_LOG_INFO ; 
 int AV_LOG_WARNING ; 
 int AudioDevice ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ IAMCrossbar_CanRoute (int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ IAMCrossbar_QueryInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/  IAMCrossbar_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IAMCrossbar_Route (int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ IAMCrossbar_get_CrossbarPinInfo (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,long*,long*) ; 
 scalar_t__ IAMCrossbar_get_IsRoutedTo (int /*<<< orphan*/ *,int,long*) ; 
 scalar_t__ IAMCrossbar_get_PinCounts (int /*<<< orphan*/ *,long*,long*) ; 
 int /*<<< orphan*/  IAMTVTuner_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IBaseFilter_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ ICaptureGraphBuilder2_FindInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/  IID_IAMCrossbar ; 
 int /*<<< orphan*/  IID_IAMTVAudio ; 
 int /*<<< orphan*/  IID_IAMTVTuner ; 
 int /*<<< orphan*/  IID_IBaseFilter ; 
 int /*<<< orphan*/  LOOK_UPSTREAM_ONLY ; 
#define  PhysConn_Audio_1394 150 
#define  PhysConn_Audio_AESDigital 149 
#define  PhysConn_Audio_AUX 148 
#define  PhysConn_Audio_AudioDecoder 147 
#define  PhysConn_Audio_Line 146 
#define  PhysConn_Audio_Mic 145 
#define  PhysConn_Audio_SCSI 144 
#define  PhysConn_Audio_SPDIFDigital 143 
#define  PhysConn_Audio_Tuner 142 
#define  PhysConn_Audio_USB 141 
#define  PhysConn_Video_1394 140 
#define  PhysConn_Video_AUX 139 
#define  PhysConn_Video_Composite 138 
#define  PhysConn_Video_ParallelDigital 137 
#define  PhysConn_Video_RGB 136 
#define  PhysConn_Video_SCSI 135 
#define  PhysConn_Video_SVideo 134 
#define  PhysConn_Video_SerialDigital 133 
#define  PhysConn_Video_Tuner 132 
#define  PhysConn_Video_USB 131 
#define  PhysConn_Video_VideoDecoder 130 
#define  PhysConn_Video_VideoEncoder 129 
#define  PhysConn_Video_YRYBY 128 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  TRUE ; 
 int VideoDevice ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int,char*,...) ; 
 int /*<<< orphan*/  dshow_show_filter_properties (int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static inline void nothing(void *foo)
{
}

__attribute__((used)) static const char *
GetPhysicalPinName(long pin_type)
{
    switch (pin_type)
    {
    case PhysConn_Video_Tuner:            return "Video Tuner";
    case PhysConn_Video_Composite:        return "Video Composite";
    case PhysConn_Video_SVideo:           return "S-Video";
    case PhysConn_Video_RGB:              return "Video RGB";
    case PhysConn_Video_YRYBY:            return "Video YRYBY";
    case PhysConn_Video_SerialDigital:    return "Video Serial Digital";
    case PhysConn_Video_ParallelDigital:  return "Video Parallel Digital";
    case PhysConn_Video_SCSI:             return "Video SCSI";
    case PhysConn_Video_AUX:              return "Video AUX";
    case PhysConn_Video_1394:             return "Video 1394";
    case PhysConn_Video_USB:              return "Video USB";
    case PhysConn_Video_VideoDecoder:     return "Video Decoder";
    case PhysConn_Video_VideoEncoder:     return "Video Encoder";

    case PhysConn_Audio_Tuner:            return "Audio Tuner";
    case PhysConn_Audio_Line:             return "Audio Line";
    case PhysConn_Audio_Mic:              return "Audio Microphone";
    case PhysConn_Audio_AESDigital:       return "Audio AES/EBU Digital";
    case PhysConn_Audio_SPDIFDigital:     return "Audio S/PDIF";
    case PhysConn_Audio_SCSI:             return "Audio SCSI";
    case PhysConn_Audio_AUX:              return "Audio AUX";
    case PhysConn_Audio_1394:             return "Audio 1394";
    case PhysConn_Audio_USB:              return "Audio USB";
    case PhysConn_Audio_AudioDecoder:     return "Audio Decoder";
    default:                              return "Unknown Crossbar Pin Type—Please report!";
    }
}

__attribute__((used)) static HRESULT
setup_crossbar_options(IAMCrossbar *cross_bar, enum dshowDeviceType devtype, AVFormatContext *avctx)
{
    struct dshow_ctx *ctx = avctx->priv_data;
    long count_output_pins, count_input_pins;
    int i;
    int log_level = ctx->list_options ? AV_LOG_INFO : AV_LOG_DEBUG;
    int video_input_pin = ctx->crossbar_video_input_pin_number;
    int audio_input_pin = ctx->crossbar_audio_input_pin_number;
    const char *device_name = ctx->device_name[devtype];
    HRESULT hr;

    av_log(avctx, log_level, "Crossbar Switching Information for %s:\n", device_name);
    hr = IAMCrossbar_get_PinCounts(cross_bar, &count_output_pins, &count_input_pins);
    if (hr != S_OK) {
        av_log(avctx, AV_LOG_ERROR, "Unable to get crossbar pin counts\n");
        return hr;
    }

    for (i = 0; i < count_output_pins; i++)
    {
        int j;
        long related_pin, pin_type, route_to_pin;
        hr = IAMCrossbar_get_CrossbarPinInfo(cross_bar, FALSE, i, &related_pin, &pin_type);
        if (pin_type == PhysConn_Video_VideoDecoder) {
            /* assume there is only one "Video (and one Audio) Decoder" output pin, and it's all we care about routing to...for now */
            if (video_input_pin != -1) {
                av_log(avctx, log_level, "Routing video input from pin %d\n", video_input_pin);
                hr = IAMCrossbar_Route(cross_bar, i, video_input_pin);
                if (hr != S_OK) {
                    av_log(avctx, AV_LOG_ERROR, "Unable to route video input from pin %d\n", video_input_pin);
                    return AVERROR(EIO);
                }
            }
        } else if (pin_type == PhysConn_Audio_AudioDecoder) {
            if (audio_input_pin != -1) {
                av_log(avctx, log_level, "Routing audio input from pin %d\n", audio_input_pin);
                hr = IAMCrossbar_Route(cross_bar, i, audio_input_pin);
                if (hr != S_OK) {
                    av_log(avctx, AV_LOG_ERROR, "Unable to route audio input from pin %d\n", audio_input_pin);
                    return hr;
                }
            }
        } else {
            av_log(avctx, AV_LOG_WARNING, "Unexpected output pin type, please report the type if you want to use this (%s)", GetPhysicalPinName(pin_type));
        }

        hr = IAMCrossbar_get_IsRoutedTo(cross_bar, i, &route_to_pin);
        if (hr != S_OK) {
            av_log(avctx, AV_LOG_ERROR, "Unable to get crossbar is routed to from pin %d\n", i);
            return hr;
        }
        av_log(avctx, log_level, "  Crossbar Output pin %d: \"%s\" related output pin: %ld ", i, GetPhysicalPinName(pin_type), related_pin);
        av_log(avctx, log_level, "current input pin: %ld ", route_to_pin);
        av_log(avctx, log_level, "compatible input pins: ");

        for (j = 0; j < count_input_pins; j++)
        {
            hr = IAMCrossbar_CanRoute(cross_bar, i, j);
            if (hr == S_OK)
                av_log(avctx, log_level ,"%d ", j);
        }
        av_log(avctx, log_level, "\n");
    }

    for (i = 0; i < count_input_pins; i++)
    {
        long related_pin, pin_type;
        hr = IAMCrossbar_get_CrossbarPinInfo(cross_bar, TRUE, i, &related_pin, &pin_type);
        if (hr != S_OK) {
            av_log(avctx, AV_LOG_ERROR, "unable to get crossbar info audio input from pin %d\n", i);
            return hr;
        }
        av_log(avctx, log_level, "  Crossbar Input pin %d - \"%s\" ", i, GetPhysicalPinName(pin_type));
        av_log(avctx, log_level, "related input pin: %ld\n", related_pin);
    }
    return S_OK;
}

HRESULT
dshow_try_setup_crossbar_options(ICaptureGraphBuilder2 *graph_builder2,
    IBaseFilter *device_filter, enum dshowDeviceType devtype, AVFormatContext *avctx)
{
    struct dshow_ctx *ctx = avctx->priv_data;
    IAMCrossbar *cross_bar = NULL;
    IBaseFilter *cross_bar_base_filter = NULL;
    IAMTVTuner *tv_tuner_filter = NULL;
    IBaseFilter *tv_tuner_base_filter = NULL;
    IAMAudioInputMixer *tv_audio_filter = NULL;
    IBaseFilter *tv_audio_base_filter = NULL;
    HRESULT hr;

    hr = ICaptureGraphBuilder2_FindInterface(graph_builder2, &LOOK_UPSTREAM_ONLY, (const GUID *) NULL,
            device_filter, &IID_IAMCrossbar, (void**) &cross_bar);
    if (hr != S_OK) {
        /* no crossbar found */
        hr = S_OK;
        goto end;
    }
    /* TODO some TV tuners apparently have multiple crossbars? */

    if (devtype == VideoDevice && ctx->show_video_crossbar_connection_dialog ||
        devtype == AudioDevice && ctx->show_audio_crossbar_connection_dialog) {
        hr = IAMCrossbar_QueryInterface(cross_bar, &IID_IBaseFilter, (void **) &cross_bar_base_filter);
        if (hr != S_OK)
            goto end;
        dshow_show_filter_properties(cross_bar_base_filter, avctx);
    }

    if (devtype == VideoDevice && ctx->show_analog_tv_tuner_dialog) {
        hr = ICaptureGraphBuilder2_FindInterface(graph_builder2, &LOOK_UPSTREAM_ONLY, NULL,
             device_filter, &IID_IAMTVTuner, (void**) &tv_tuner_filter);
        if (hr == S_OK) {
            hr = IAMCrossbar_QueryInterface(tv_tuner_filter, &IID_IBaseFilter, (void **) &tv_tuner_base_filter);
            if (hr != S_OK)
                goto end;
            dshow_show_filter_properties(tv_tuner_base_filter, avctx);
        } else {
            av_log(avctx, AV_LOG_WARNING, "unable to find a tv tuner to display dialog for!");
        }
    }
    if (devtype == AudioDevice && ctx->show_analog_tv_tuner_audio_dialog) {
        hr = ICaptureGraphBuilder2_FindInterface(graph_builder2, &LOOK_UPSTREAM_ONLY, NULL,
             device_filter, &IID_IAMTVAudio, (void**) &tv_audio_filter);
        if (hr == S_OK) {
            hr = IAMCrossbar_QueryInterface(tv_audio_filter, &IID_IBaseFilter, (void **) &tv_audio_base_filter);
            if (hr != S_OK)
                goto end;
            dshow_show_filter_properties(tv_audio_base_filter, avctx);
        } else {
            av_log(avctx, AV_LOG_WARNING, "unable to find a tv audio tuner to display dialog for!");
        }
    }

    hr = setup_crossbar_options(cross_bar, devtype, avctx);
    if (hr != S_OK)
        goto end;

end:
    if (cross_bar)
        IAMCrossbar_Release(cross_bar);
    if (cross_bar_base_filter)
        IBaseFilter_Release(cross_bar_base_filter);
    if (tv_tuner_filter)
        IAMTVTuner_Release(tv_tuner_filter);
    if (tv_tuner_base_filter)
        IBaseFilter_Release(tv_tuner_base_filter);
    return hr;
}

