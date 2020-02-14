#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  bits_per_raw_sample; int /*<<< orphan*/  dct_algo; int /*<<< orphan*/  idct_algo; } ;
struct TYPE_9__ {int /*<<< orphan*/  bits_per_sample; int /*<<< orphan*/  dct_algo; int /*<<< orphan*/  idct_algo; int /*<<< orphan*/  const* av_class; } ;
typedef  TYPE_1__ AVDCT ;
typedef  TYPE_2__ AVCodecContext ;
typedef  int /*<<< orphan*/  AVClass ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENOMEM ; 
 TYPE_1__* av_mallocz (int) ; 
 int /*<<< orphan*/  av_opt_set_defaults (TYPE_1__*) ; 
 TYPE_2__* avcodec_alloc_context3 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avcodec_free_context (TYPE_2__**) ; 
 int /*<<< orphan*/  const avdct_class ; 

const AVClass *avcodec_dct_get_class(void)
{
    return &avdct_class;
}

AVDCT *avcodec_dct_alloc(void)
{
    AVDCT *dsp = av_mallocz(sizeof(AVDCT));

    if (!dsp)
        return NULL;

    dsp->av_class = &avdct_class;
    av_opt_set_defaults(dsp);

    return dsp;
}

int avcodec_dct_init(AVDCT *dsp)
{
    AVCodecContext *avctx = avcodec_alloc_context3(NULL);

    if (!avctx)
        return AVERROR(ENOMEM);

    avctx->idct_algo = dsp->idct_algo;
    avctx->dct_algo  = dsp->dct_algo;
    avctx->bits_per_raw_sample = dsp->bits_per_sample;

#define COPY(src, name) memcpy(&dsp->name, &src.name, sizeof(dsp->name))

#if CONFIG_IDCTDSP
    {
        IDCTDSPContext idsp;
        ff_idctdsp_init(&idsp, avctx);
        COPY(idsp, idct);
        COPY(idsp, idct_permutation);
    }
#endif

#if CONFIG_FDCTDSP
    {
        FDCTDSPContext fdsp;
        ff_fdctdsp_init(&fdsp, avctx);
        COPY(fdsp, fdct);
    }
#endif

#if CONFIG_PIXBLOCKDSP
    {
        PixblockDSPContext pdsp;
        ff_pixblockdsp_init(&pdsp, avctx);
        COPY(pdsp, get_pixels);
    }
#endif

    avcodec_free_context(&avctx);

    return 0;
}

