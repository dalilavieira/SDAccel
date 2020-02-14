#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct drm_property_blob {int length; scalar_t__ data; } ;
struct drm_crtc_state {struct drm_property_blob* degamma_lut; } ;
struct drm_color_lut {scalar_t__ red; scalar_t__ green; scalar_t__ blue; } ;
struct drm_color_ctm {unsigned long long* matrix; } ;
struct TYPE_9__ {struct drm_property_blob* ctm; struct drm_property_blob* gamma_lut; } ;
struct dm_crtc_state {struct dc_stream_state* stream; TYPE_3__ base; } ;
struct TYPE_7__ {int enable_remap; TYPE_6__* matrix; } ;
struct dc_stream_state {TYPE_1__ gamut_remap_matrix; TYPE_4__* out_transfer_func; } ;
struct dc_plane_state {TYPE_5__* in_transfer_func; } ;
struct TYPE_8__ {void** blue; void** green; void** red; } ;
struct dc_gamma {int num_entries; scalar_t__ type; TYPE_2__ entries; } ;
typedef  unsigned long long int64_t ;
typedef  enum dc_transfer_func_type { ____Placeholder_dc_transfer_func_type } dc_transfer_func_type ;
struct TYPE_12__ {unsigned long long value; } ;
struct TYPE_11__ {void* type; void* tf; } ;
struct TYPE_10__ {int type; void* tf; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ GAMMA_CS_TFM_1D ; 
 scalar_t__ GAMMA_CUSTOM ; 
 scalar_t__ GAMMA_RGB_256 ; 
 int MAX_COLOR_LEGACY_LUT_ENTRIES ; 
 int MAX_COLOR_LUT_ENTRIES ; 
 int MAX_DRM_LUT_VALUE ; 
 void* TF_TYPE_BYPASS ; 
 void* TF_TYPE_DISTRIBUTED_POINTS ; 
 void* TF_TYPE_PREDEFINED ; 
 void* TRANSFER_FUNCTION_LINEAR ; 
 void* TRANSFER_FUNCTION_SRGB ; 
 struct dc_gamma* dc_create_gamma () ; 
 void* dc_fixpt_from_fraction (int,int) ; 
 void* dc_fixpt_from_int (int) ; 
 TYPE_6__ dc_fixpt_zero ; 
 int /*<<< orphan*/  dc_gamma_release (struct dc_gamma**) ; 
 int drm_color_lut_extract (scalar_t__,int) ; 
 int mod_color_calculate_degamma_params (TYPE_5__*,struct dc_gamma*,int) ; 
 int mod_color_calculate_regamma_params (TYPE_4__*,struct dc_gamma*,int) ; 
 int /*<<< orphan*/  setup_x_points_distribution () ; 

void amdgpu_dm_init_color_mod(void)
{
	setup_x_points_distribution();
}

__attribute__((used)) static bool __is_lut_linear(struct drm_color_lut *lut, uint32_t size)
{
	int i;
	uint32_t expected;
	int delta;

	for (i = 0; i < size; i++) {
		/* All color values should equal */
		if ((lut[i].red != lut[i].green) || (lut[i].green != lut[i].blue))
			return false;

		expected = i * MAX_DRM_LUT_VALUE / (size-1);

		/* Allow a +/-1 error. */
		delta = lut[i].red - expected;
		if (delta < -1 || 1 < delta)
			return false;
	}
	return true;
}

__attribute__((used)) static void __drm_lut_to_dc_gamma(struct drm_color_lut *lut,
				  struct dc_gamma *gamma,
				  bool is_legacy)
{
	uint32_t r, g, b;
	int i;

	if (is_legacy) {
		for (i = 0; i < MAX_COLOR_LEGACY_LUT_ENTRIES; i++) {
			r = drm_color_lut_extract(lut[i].red, 16);
			g = drm_color_lut_extract(lut[i].green, 16);
			b = drm_color_lut_extract(lut[i].blue, 16);

			gamma->entries.red[i] = dc_fixpt_from_int(r);
			gamma->entries.green[i] = dc_fixpt_from_int(g);
			gamma->entries.blue[i] = dc_fixpt_from_int(b);
		}
		return;
	}

	/* else */
	for (i = 0; i < MAX_COLOR_LUT_ENTRIES; i++) {
		r = drm_color_lut_extract(lut[i].red, 16);
		g = drm_color_lut_extract(lut[i].green, 16);
		b = drm_color_lut_extract(lut[i].blue, 16);

		gamma->entries.red[i] = dc_fixpt_from_fraction(r, MAX_DRM_LUT_VALUE);
		gamma->entries.green[i] = dc_fixpt_from_fraction(g, MAX_DRM_LUT_VALUE);
		gamma->entries.blue[i] = dc_fixpt_from_fraction(b, MAX_DRM_LUT_VALUE);
	}
}

int amdgpu_dm_set_regamma_lut(struct dm_crtc_state *crtc)
{
	struct drm_property_blob *blob = crtc->base.gamma_lut;
	struct dc_stream_state *stream = crtc->stream;
	struct drm_color_lut *lut;
	uint32_t lut_size;
	struct dc_gamma *gamma;
	enum dc_transfer_func_type old_type = stream->out_transfer_func->type;

	bool ret;

	if (!blob) {
		/* By default, use the SRGB predefined curve.*/
		stream->out_transfer_func->type = TF_TYPE_PREDEFINED;
		stream->out_transfer_func->tf = TRANSFER_FUNCTION_SRGB;
		return 0;
	}

	lut = (struct drm_color_lut *)blob->data;
	lut_size = blob->length / sizeof(struct drm_color_lut);

	gamma = dc_create_gamma();
	if (!gamma)
		return -ENOMEM;

	gamma->num_entries = lut_size;
	if (gamma->num_entries == MAX_COLOR_LEGACY_LUT_ENTRIES)
		gamma->type = GAMMA_RGB_256;
	else if (gamma->num_entries == MAX_COLOR_LUT_ENTRIES)
		gamma->type = GAMMA_CS_TFM_1D;
	else {
		/* Invalid lut size */
		dc_gamma_release(&gamma);
		return -EINVAL;
	}

	/* Convert drm_lut into dc_gamma */
	__drm_lut_to_dc_gamma(lut, gamma, gamma->type == GAMMA_RGB_256);

	/* Call color module to translate into something DC understands. Namely
	 * a transfer function.
	 */
	stream->out_transfer_func->type = TF_TYPE_DISTRIBUTED_POINTS;
	ret = mod_color_calculate_regamma_params(stream->out_transfer_func,
						 gamma, true);
	dc_gamma_release(&gamma);
	if (!ret) {
		stream->out_transfer_func->type = old_type;
		DRM_ERROR("Out of memory when calculating regamma params\n");
		return -ENOMEM;
	}

	return 0;
}

void amdgpu_dm_set_ctm(struct dm_crtc_state *crtc)
{

	struct drm_property_blob *blob = crtc->base.ctm;
	struct dc_stream_state *stream = crtc->stream;
	struct drm_color_ctm *ctm;
	int64_t val;
	int i;

	if (!blob) {
		stream->gamut_remap_matrix.enable_remap = false;
		return;
	}

	stream->gamut_remap_matrix.enable_remap = true;
	ctm = (struct drm_color_ctm *)blob->data;
	/*
	 * DRM gives a 3x3 matrix, but DC wants 3x4. Assuming we're operating
	 * with homogeneous coordinates, augment the matrix with 0's.
	 *
	 * The format provided is S31.32, using signed-magnitude representation.
	 * Our fixed31_32 is also S31.32, but is using 2's complement. We have
	 * to convert from signed-magnitude to 2's complement.
	 */
	for (i = 0; i < 12; i++) {
		/* Skip 4th element */
		if (i % 4 == 3) {
			stream->gamut_remap_matrix.matrix[i] = dc_fixpt_zero;
			continue;
		}

		/* gamut_remap_matrix[i] = ctm[i - floor(i/4)] */
		val = ctm->matrix[i - (i/4)];
		/* If negative, convert to 2's complement. */
		if (val & (1ULL << 63))
			val = -(val & ~(1ULL << 63));

		stream->gamut_remap_matrix.matrix[i].value = val;
	}
}

int amdgpu_dm_set_degamma_lut(struct drm_crtc_state *crtc_state,
			      struct dc_plane_state *dc_plane_state)
{
	struct drm_property_blob *blob = crtc_state->degamma_lut;
	struct drm_color_lut *lut;
	uint32_t lut_size;
	struct dc_gamma *gamma;
	bool ret;

	if (!blob) {
		/* Default to SRGB */
		dc_plane_state->in_transfer_func->type = TF_TYPE_PREDEFINED;
		dc_plane_state->in_transfer_func->tf = TRANSFER_FUNCTION_SRGB;
		return 0;
	}

	lut = (struct drm_color_lut *)blob->data;
	if (__is_lut_linear(lut, MAX_COLOR_LUT_ENTRIES)) {
		dc_plane_state->in_transfer_func->type = TF_TYPE_BYPASS;
		dc_plane_state->in_transfer_func->tf = TRANSFER_FUNCTION_LINEAR;
		return 0;
	}

	gamma = dc_create_gamma();
	if (!gamma)
		return -ENOMEM;

	lut_size = blob->length / sizeof(struct drm_color_lut);
	gamma->num_entries = lut_size;
	if (gamma->num_entries == MAX_COLOR_LUT_ENTRIES)
		gamma->type = GAMMA_CUSTOM;
	else {
		dc_gamma_release(&gamma);
		return -EINVAL;
	}

	__drm_lut_to_dc_gamma(lut, gamma, false);

	dc_plane_state->in_transfer_func->type = TF_TYPE_DISTRIBUTED_POINTS;
	ret = mod_color_calculate_degamma_params(dc_plane_state->in_transfer_func, gamma, true);
	dc_gamma_release(&gamma);
	if (!ret) {
		dc_plane_state->in_transfer_func->type = TF_TYPE_BYPASS;
		DRM_ERROR("Out of memory when calculating degamma params\n");
		return -ENOMEM;
	}

	return 0;
}

