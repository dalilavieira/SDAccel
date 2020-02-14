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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  size_t uint32_t ;
struct msm_kms {int dummy; } ;
struct msm_format {size_t pixel_format; } ;
struct mdp_kms_funcs {int /*<<< orphan*/  base; } ;
struct mdp_kms {int /*<<< orphan*/  base; int /*<<< orphan*/  irq_list; struct mdp_kms_funcs const* funcs; } ;
struct mdp_format {struct msm_format const base; } ;
struct csc_cfg {int dummy; } ;
typedef  enum csc_type { ____Placeholder_csc_type } csc_type ;

/* Variables and functions */
 int ARRAY_SIZE (struct mdp_format*) ; 
 int CSC_MAX ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 scalar_t__ MDP_FORMAT_IS_YUV (struct mdp_format const*) ; 
 size_t MDP_PIPE_CAP_CSC ; 
 size_t MDP_PIPE_CAP_SCALE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 struct csc_cfg* csc_convert ; 
 struct mdp_format* formats ; 
 int /*<<< orphan*/  msm_kms_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void mdp_kms_init(struct mdp_kms *mdp_kms,
		const struct mdp_kms_funcs *funcs)
{
	mdp_kms->funcs = funcs;
	INIT_LIST_HEAD(&mdp_kms->irq_list);
	msm_kms_init(&mdp_kms->base, &funcs->base);
}

__attribute__((used)) static inline bool pipe_supports_yuv(uint32_t pipe_caps)
{
	return (pipe_caps & MDP_PIPE_CAP_SCALE) &&
		(pipe_caps & MDP_PIPE_CAP_CSC);
}

uint32_t mdp_get_formats(uint32_t *pixel_formats, uint32_t max_formats,
		bool rgb_only)
{
	uint32_t i;
	for (i = 0; i < ARRAY_SIZE(formats); i++) {
		const struct mdp_format *f = &formats[i];

		if (i == max_formats)
			break;

		if (rgb_only && MDP_FORMAT_IS_YUV(f))
			break;

		pixel_formats[i] = f->base.pixel_format;
	}

	return i;
}

const struct msm_format *mdp_get_format(struct msm_kms *kms, uint32_t format,
		uint64_t modifier)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(formats); i++) {
		const struct mdp_format *f = &formats[i];
		if (f->base.pixel_format == format)
			return &f->base;
	}
	return NULL;
}

struct csc_cfg *mdp_get_default_csc_cfg(enum csc_type type)
{
	if (unlikely(WARN_ON(type >= CSC_MAX)))
		return NULL;

	return &csc_convert[type];
}

