#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int /*<<< orphan*/  vdec_type; } ;
struct TYPE_19__ {TYPE_1__ stat; scalar_t__ videotoolbox; } ;
struct TYPE_18__ {void (* func_destroy ) (TYPE_3__*) ;int /*<<< orphan*/ * (* func_open_audio_output ) (TYPE_3__*,TYPE_4__*) ;int /*<<< orphan*/ * (* func_open_video_decoder ) (TYPE_3__*,TYPE_4__*) ;TYPE_2__* opaque; } ;
struct TYPE_17__ {int is_videotoolbox_open; TYPE_4__* ffp; } ;
typedef  int /*<<< orphan*/  SDL_Aout ;
typedef  int /*<<< orphan*/  IJKFF_Pipenode ;
typedef  TYPE_2__ IJKFF_Pipeline_Opaque ;
typedef  TYPE_3__ IJKFF_Pipeline ;
typedef  TYPE_4__ FFPlayer ;

/* Variables and functions */
 int /*<<< orphan*/  ALOGE (char*) ; 
 int /*<<< orphan*/  FFP_MSG_VIDEO_DECODER_OPEN ; 
 int /*<<< orphan*/  FFP_PROPV_DECODER_AVCODEC ; 
 int /*<<< orphan*/  FFP_PROPV_DECODER_VIDEOTOOLBOX ; 
 int /*<<< orphan*/ * SDL_AoutIos_CreateForAudioUnit () ; 
 int /*<<< orphan*/  ffp_notify_msg2 (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 TYPE_3__* ffpipeline_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * ffpipenode_create_video_decoder_from_ffplay (TYPE_4__*) ; 
 int /*<<< orphan*/ * ffpipenode_create_video_decoder_from_ios_videotoolbox (TYPE_4__*) ; 
 int /*<<< orphan*/  g_pipeline_class ; 

__attribute__((used)) static void func_destroy(IJKFF_Pipeline *pipeline)
{
}

__attribute__((used)) static IJKFF_Pipenode *func_open_video_decoder(IJKFF_Pipeline *pipeline, FFPlayer *ffp)
{
    IJKFF_Pipenode* node = NULL;
    IJKFF_Pipeline_Opaque *opaque = pipeline->opaque;
    if (ffp->videotoolbox) {
        node = ffpipenode_create_video_decoder_from_ios_videotoolbox(ffp);
        if (!node)
            ALOGE("vtb fail!!! switch to ffmpeg decode!!!! \n");
    }
    if (node == NULL) {
        node = ffpipenode_create_video_decoder_from_ffplay(ffp);
        ffp->stat.vdec_type = FFP_PROPV_DECODER_AVCODEC;
        opaque->is_videotoolbox_open = false;
    } else {
        ffp->stat.vdec_type = FFP_PROPV_DECODER_VIDEOTOOLBOX;
        opaque->is_videotoolbox_open = true;
    }
    ffp_notify_msg2(ffp, FFP_MSG_VIDEO_DECODER_OPEN, opaque->is_videotoolbox_open);
    return node;
}

__attribute__((used)) static SDL_Aout *func_open_audio_output(IJKFF_Pipeline *pipeline, FFPlayer *ffp)
{
    return SDL_AoutIos_CreateForAudioUnit();
}

IJKFF_Pipeline *ffpipeline_create_from_ios(FFPlayer *ffp)
{
    IJKFF_Pipeline *pipeline = ffpipeline_alloc(&g_pipeline_class, sizeof(IJKFF_Pipeline_Opaque));
    if (!pipeline)
        return pipeline;

    IJKFF_Pipeline_Opaque *opaque     = pipeline->opaque;
    opaque->ffp                       = ffp;
    pipeline->func_destroy            = func_destroy;
    pipeline->func_open_video_decoder = func_open_video_decoder;
    pipeline->func_open_audio_output  = func_open_audio_output;

    return pipeline;
}

