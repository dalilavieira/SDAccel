#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct mpv_global {int dummy; } ;
struct mp_swresample {struct mp_filter* f; } ;
struct mp_resample_opts {scalar_t__ normalize; int /*<<< orphan*/ * avopts; } ;
struct mp_filter {int dummy; } ;
struct m_option {int /*<<< orphan*/ * type; } ;
struct af_resample {scalar_t__ global_normalize; struct mp_resample_opts opts; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_WARN (struct mp_filter*,char*) ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  m_option_copy (struct m_option*,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  m_option_type_keyvalue_list ; 
 struct mp_resample_opts* mp_get_config_group (struct af_resample*,struct mpv_global*,int /*<<< orphan*/ *) ; 
 struct mp_swresample* mp_swresample_create (struct mp_filter*,struct mp_resample_opts*) ; 
 int /*<<< orphan*/  resample_conf ; 
 int /*<<< orphan*/  talloc_free (struct af_resample*) ; 

__attribute__((used)) static void set_defaults(struct mpv_global *global, void *p)
{
    struct af_resample *s = p;

    struct mp_resample_opts *opts = &s->opts;

    struct mp_resample_opts *src_opts =
        mp_get_config_group(s, global, &resample_conf);

    s->global_normalize = src_opts->normalize;

    assert(!opts->avopts); // we don't set a default value, so it must be NULL

    *opts = *src_opts;

    opts->avopts = NULL;
    struct m_option dummy = {.type = &m_option_type_keyvalue_list};
    m_option_copy(&dummy, &opts->avopts, &src_opts->avopts);
}

__attribute__((used)) static struct mp_filter *af_lavrresample_create(struct mp_filter *parent,
                                                void *options)
{
    struct af_resample *s = options;

    if (s->opts.normalize < 0)
        s->opts.normalize = s->global_normalize;

    struct mp_swresample *swr = mp_swresample_create(parent, &s->opts);
    if (!swr)
        abort();

    MP_WARN(swr->f, "This filter is deprecated! Use the --audio-resample- options"
            " to customize resampling, or the --af=aresample filter.\n");

    talloc_free(s);
    return swr->f;
}

