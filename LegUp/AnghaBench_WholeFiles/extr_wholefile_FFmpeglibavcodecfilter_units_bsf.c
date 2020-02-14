#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_8__ ;
typedef  struct TYPE_32__   TYPE_4__ ;
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;
typedef  struct TYPE_28__   TYPE_16__ ;

/* Type definitions */
struct TYPE_33__ {long* decompose_unit_types; scalar_t__ nb_decompose_unit_types; } ;
struct TYPE_32__ {TYPE_2__* priv_data; int /*<<< orphan*/  par_out; TYPE_16__* par_in; } ;
struct TYPE_31__ {int nb_units; TYPE_1__* units; } ;
struct TYPE_30__ {scalar_t__ mode; int nb_types; scalar_t__* type_list; char* pass_types; char* remove_types; TYPE_8__* cbc; TYPE_3__ fragment; } ;
struct TYPE_29__ {scalar_t__ type; } ;
struct TYPE_28__ {scalar_t__ extradata; int /*<<< orphan*/  codec_id; } ;
typedef  TYPE_2__ FilterUnitsContext ;
typedef  long CodedBitstreamUnitType ;
typedef  TYPE_3__ CodedBitstreamFragment ;
typedef  int /*<<< orphan*/  AVPacket ;
typedef  TYPE_4__ AVBSFContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 scalar_t__ NOOP ; 
 scalar_t__ PASS ; 
 scalar_t__ REMOVE ; 
 int /*<<< orphan*/  av_freep (long**) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*) ; 
 long* av_malloc_array (int,int) ; 
 int av_packet_copy_props (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_packet_free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  av_packet_move_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ff_bsf_get_packet (TYPE_4__*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  ff_cbs_close (TYPE_8__**) ; 
 int /*<<< orphan*/  ff_cbs_delete_unit (TYPE_8__*,TYPE_3__*,int) ; 
 int /*<<< orphan*/  ff_cbs_fragment_free (TYPE_8__*,TYPE_3__*) ; 
 int /*<<< orphan*/  ff_cbs_fragment_reset (TYPE_8__*,TYPE_3__*) ; 
 int ff_cbs_init (TYPE_8__**,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int ff_cbs_read_extradata (TYPE_8__*,TYPE_3__*,TYPE_16__*) ; 
 int ff_cbs_read_packet (TYPE_8__*,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int ff_cbs_write_extradata (TYPE_8__*,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int ff_cbs_write_packet (TYPE_8__*,int /*<<< orphan*/ *,TYPE_3__*) ; 
 long strtol (char const*,char**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int filter_units_make_type_list(const char *list_string,
                                       CodedBitstreamUnitType **type_list,
                                       int *nb_types)
{
    CodedBitstreamUnitType *list = NULL;
    int pass, count;

    for (pass = 1; pass <= 2; pass++) {
        long value, range_start, range_end;
        const char *str;
        char *value_end;

        count = 0;
        for (str = list_string; *str;) {
            value = strtol(str, &value_end, 0);
            if (str == value_end)
                goto invalid;
            str = (const char *)value_end;
            if (*str == '-') {
                ++str;
                range_start = value;
                range_end   = strtol(str, &value_end, 0);
                if (str == value_end)
                    goto invalid;

                for (value = range_start; value < range_end; value++) {
                    if (pass == 2)
                        list[count] = value;
                    ++count;
                }
            } else {
                if (pass == 2)
                    list[count] = value;
                ++count;
            }
            if (*str == '|')
                ++str;
        }
        if (pass == 1) {
            list = av_malloc_array(count, sizeof(*list));
            if (!list)
                return AVERROR(ENOMEM);
        }
    }

    *type_list = list;
    *nb_types  = count;
    return 0;

invalid:
    av_freep(&list);
    return AVERROR(EINVAL);
}

__attribute__((used)) static int filter_units_filter(AVBSFContext *bsf, AVPacket *out)
{
    FilterUnitsContext      *ctx = bsf->priv_data;
    CodedBitstreamFragment *frag = &ctx->fragment;
    AVPacket *in = NULL;
    int err, i, j;

    while (1) {
        err = ff_bsf_get_packet(bsf, &in);
        if (err < 0)
            return err;

        if (ctx->mode == NOOP) {
            av_packet_move_ref(out, in);
            av_packet_free(&in);
            return 0;
        }

        err = ff_cbs_read_packet(ctx->cbc, frag, in);
        if (err < 0) {
            av_log(bsf, AV_LOG_ERROR, "Failed to read packet.\n");
            goto fail;
        }

        for (i = 0; i < frag->nb_units; i++) {
            for (j = 0; j < ctx->nb_types; j++) {
                if (frag->units[i].type == ctx->type_list[j])
                    break;
            }
            if (ctx->mode == REMOVE ? j <  ctx->nb_types
                                    : j >= ctx->nb_types) {
                ff_cbs_delete_unit(ctx->cbc, frag, i);
                --i;
            }
        }

        if (frag->nb_units > 0)
            break;

        // Don't return packets with nothing in them.
        av_packet_free(&in);
        ff_cbs_fragment_reset(ctx->cbc, frag);
    }

    err = ff_cbs_write_packet(ctx->cbc, out, frag);
    if (err < 0) {
        av_log(bsf, AV_LOG_ERROR, "Failed to write packet.\n");
        goto fail;
    }

    err = av_packet_copy_props(out, in);
    if (err < 0)
        goto fail;

fail:
    ff_cbs_fragment_reset(ctx->cbc, frag);
    av_packet_free(&in);

    return err;
}

__attribute__((used)) static int filter_units_init(AVBSFContext *bsf)
{
    FilterUnitsContext *ctx = bsf->priv_data;
    int err;

    if (ctx->pass_types && ctx->remove_types) {
        av_log(bsf, AV_LOG_ERROR, "Exactly one of pass_types or "
               "remove_types is required.\n");
        return AVERROR(EINVAL);
    }

    if (ctx->pass_types) {
        ctx->mode = PASS;
        err = filter_units_make_type_list(ctx->pass_types,
                                          &ctx->type_list, &ctx->nb_types);
        if (err < 0) {
            av_log(bsf, AV_LOG_ERROR, "Failed to parse pass_types.\n");
            return err;
        }
    } else if (ctx->remove_types) {
        ctx->mode = REMOVE;
        err = filter_units_make_type_list(ctx->remove_types,
                                          &ctx->type_list, &ctx->nb_types);
        if (err < 0) {
            av_log(bsf, AV_LOG_ERROR, "Failed to parse remove_types.\n");
            return err;
        }
    } else {
        return 0;
    }

    err = ff_cbs_init(&ctx->cbc, bsf->par_in->codec_id, bsf);
    if (err < 0)
        return err;

    // Don't actually decompose anything, we only want the unit data.
    ctx->cbc->decompose_unit_types    = ctx->type_list;
    ctx->cbc->nb_decompose_unit_types = 0;

    if (bsf->par_in->extradata) {
        CodedBitstreamFragment *frag = &ctx->fragment;

        err = ff_cbs_read_extradata(ctx->cbc, frag, bsf->par_in);
        if (err < 0) {
            av_log(bsf, AV_LOG_ERROR, "Failed to read extradata.\n");
        } else {
            err = ff_cbs_write_extradata(ctx->cbc, bsf->par_out, frag);
            if (err < 0)
                av_log(bsf, AV_LOG_ERROR, "Failed to write extradata.\n");
        }

        ff_cbs_fragment_reset(ctx->cbc, frag);
    }

    return err;
}

__attribute__((used)) static void filter_units_close(AVBSFContext *bsf)
{
    FilterUnitsContext *ctx = bsf->priv_data;

    av_freep(&ctx->type_list);

    ff_cbs_fragment_free(ctx->cbc, &ctx->fragment);
    ff_cbs_close(&ctx->cbc);
}

