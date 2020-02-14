#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct tg_color {int color_r_cr; int color_g_y; int color_b_cb; } ;
struct mpcc_state {unsigned int opp_id; unsigned int dpp_id; unsigned int bot_mpcc_id; unsigned int idle; unsigned int busy; int /*<<< orphan*/  overlap_only; int /*<<< orphan*/  pre_multiplied_alpha; int /*<<< orphan*/  alpha_mode; int /*<<< orphan*/  mode; } ;
struct mpcc_sm_cfg {int enable; int /*<<< orphan*/  force_next_field_polarity; int /*<<< orphan*/  force_next_frame_porlarity; int /*<<< orphan*/  field_alt; int /*<<< orphan*/  frame_alt; int /*<<< orphan*/  sm_mode; } ;
struct mpcc_blnd_cfg {int overlap_only; int global_alpha; int global_gain; struct tg_color black_color; int /*<<< orphan*/  pre_multiplied_alpha; int /*<<< orphan*/  alpha_mode; } ;
struct mpcc {int dpp_id; int mpcc_id; struct mpcc* mpcc_bot; struct mpcc_sm_cfg sm_cfg; struct mpcc_blnd_cfg blnd_cfg; } ;
struct mpc_tree {int opp_id; struct mpcc* opp_list; } ;
struct mpc {struct mpcc* mpcc_array; TYPE_1__* funcs; } ;
struct dcn_mpc_shift {int dummy; } ;
struct dcn_mpc_registers {int dummy; } ;
struct dcn_mpc_mask {int dummy; } ;
struct TYPE_4__ {struct mpcc* mpcc_array; int /*<<< orphan*/ * funcs; struct dc_context* ctx; } ;
struct dcn10_mpc {int mpcc_in_use_mask; int num_mpcc; TYPE_2__ base; struct dcn_mpc_mask const* mpc_mask; struct dcn_mpc_shift const* mpc_shift; struct dcn_mpc_registers const* mpc_regs; } ;
struct dc_context {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* update_blending ) (struct mpc*,struct mpcc_blnd_cfg*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int MAX_MPCC ; 
 int MAX_OPP ; 
 int /*<<< orphan*/  MPCC_ALPHA_BLND_MODE ; 
 int /*<<< orphan*/  MPCC_ALPHA_MULTIPLIED_MODE ; 
 int /*<<< orphan*/ * MPCC_BG_B_CB ; 
 int /*<<< orphan*/ * MPCC_BG_G_Y ; 
 int /*<<< orphan*/ * MPCC_BG_R_CR ; 
 int MPCC_BLEND_MODE_TOP_BOT_BLENDING ; 
 int MPCC_BLEND_MODE_TOP_LAYER_PASSTHROUGH ; 
 int /*<<< orphan*/  MPCC_BLND_ACTIVE_OVERLAP_ONLY ; 
 int /*<<< orphan*/ * MPCC_BOT_SEL ; 
 int /*<<< orphan*/ * MPCC_BUSY ; 
 int /*<<< orphan*/ * MPCC_CONTROL ; 
 int /*<<< orphan*/  MPCC_GLOBAL_ALPHA ; 
 int /*<<< orphan*/  MPCC_GLOBAL_GAIN ; 
 int /*<<< orphan*/ * MPCC_IDLE ; 
 int /*<<< orphan*/ * MPCC_MODE ; 
 int /*<<< orphan*/ * MPCC_OPP_ID ; 
 int /*<<< orphan*/ * MPCC_SM_CONTROL ; 
 int /*<<< orphan*/  MPCC_SM_EN ; 
 int /*<<< orphan*/  MPCC_SM_FIELD_ALT ; 
 int /*<<< orphan*/  MPCC_SM_FORCE_NEXT_FRAME_POL ; 
 int /*<<< orphan*/  MPCC_SM_FORCE_NEXT_TOP_POL ; 
 int /*<<< orphan*/  MPCC_SM_FRAME_ALT ; 
 int /*<<< orphan*/  MPCC_SM_MODE ; 
 int /*<<< orphan*/ * MPCC_STATUS ; 
 int /*<<< orphan*/ * MPCC_TOP_SEL ; 
 int /*<<< orphan*/ * MPC_OUT_MUX ; 
 int /*<<< orphan*/ * MUX ; 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned int*) ; 
 int /*<<< orphan*/  REG_GET_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned int*,int /*<<< orphan*/ *,unsigned int*) ; 
 int /*<<< orphan*/  REG_GET_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  REG_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  REG_UPDATE_5 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_6 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_WAIT (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int) ; 
 struct dcn10_mpc* TO_DCN10_MPC (struct mpc*) ; 
 int /*<<< orphan*/  dcn10_mpc_funcs ; 
 struct mpcc* mpc1_get_mpcc (struct mpc*,int) ; 
 int /*<<< orphan*/  stub1 (struct mpc*,struct mpcc_blnd_cfg*,int) ; 

void mpc1_set_bg_color(struct mpc *mpc,
		struct tg_color *bg_color,
		int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);

	/* mpc color is 12 bit.  tg_color is 10 bit */
	/* todo: might want to use 16 bit to represent color and have each
	 * hw block translate to correct color depth.
	 */
	uint32_t bg_r_cr = bg_color->color_r_cr << 2;
	uint32_t bg_g_y = bg_color->color_g_y << 2;
	uint32_t bg_b_cb = bg_color->color_b_cb << 2;

	REG_SET(MPCC_BG_R_CR[mpcc_id], 0,
			MPCC_BG_R_CR, bg_r_cr);
	REG_SET(MPCC_BG_G_Y[mpcc_id], 0,
			MPCC_BG_G_Y, bg_g_y);
	REG_SET(MPCC_BG_B_CB[mpcc_id], 0,
			MPCC_BG_B_CB, bg_b_cb);
}

__attribute__((used)) static void mpc1_update_blending(
	struct mpc *mpc,
	struct mpcc_blnd_cfg *blnd_cfg,
	int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	struct mpcc *mpcc = mpc1_get_mpcc(mpc, mpcc_id);

	REG_UPDATE_5(MPCC_CONTROL[mpcc_id],
			MPCC_ALPHA_BLND_MODE,		blnd_cfg->alpha_mode,
			MPCC_ALPHA_MULTIPLIED_MODE,	blnd_cfg->pre_multiplied_alpha,
			MPCC_BLND_ACTIVE_OVERLAP_ONLY,	blnd_cfg->overlap_only,
			MPCC_GLOBAL_ALPHA,		blnd_cfg->global_alpha,
			MPCC_GLOBAL_GAIN,		blnd_cfg->global_gain);

	mpc1_set_bg_color(mpc, &blnd_cfg->black_color, mpcc_id);
	mpcc->blnd_cfg = *blnd_cfg;
}

void mpc1_update_stereo_mix(
	struct mpc *mpc,
	struct mpcc_sm_cfg *sm_cfg,
	int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);

	REG_UPDATE_6(MPCC_SM_CONTROL[mpcc_id],
			MPCC_SM_EN,			sm_cfg->enable,
			MPCC_SM_MODE,			sm_cfg->sm_mode,
			MPCC_SM_FRAME_ALT,		sm_cfg->frame_alt,
			MPCC_SM_FIELD_ALT,		sm_cfg->field_alt,
			MPCC_SM_FORCE_NEXT_FRAME_POL,	sm_cfg->force_next_frame_porlarity,
			MPCC_SM_FORCE_NEXT_TOP_POL,	sm_cfg->force_next_field_polarity);
}

void mpc1_assert_idle_mpcc(struct mpc *mpc, int id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);

	ASSERT(!(mpc10->mpcc_in_use_mask & 1 << id));
	REG_WAIT(MPCC_STATUS[id],
			MPCC_IDLE, 1,
			1, 100000);
}

struct mpcc *mpc1_get_mpcc(struct mpc *mpc, int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);

	ASSERT(mpcc_id < mpc10->num_mpcc);
	return &(mpc->mpcc_array[mpcc_id]);
}

struct mpcc *mpc1_get_mpcc_for_dpp(struct mpc_tree *tree, int dpp_id)
{
	struct mpcc *tmp_mpcc = tree->opp_list;

	while (tmp_mpcc != NULL) {
		if (tmp_mpcc->dpp_id == dpp_id)
			return tmp_mpcc;
		tmp_mpcc = tmp_mpcc->mpcc_bot;
	}
	return NULL;
}

bool mpc1_is_mpcc_idle(struct mpc *mpc, int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	unsigned int top_sel;
	unsigned int opp_id;
	unsigned int idle;

	REG_GET(MPCC_TOP_SEL[mpcc_id], MPCC_TOP_SEL, &top_sel);
	REG_GET(MPCC_OPP_ID[mpcc_id],  MPCC_OPP_ID, &opp_id);
	REG_GET(MPCC_STATUS[mpcc_id],  MPCC_IDLE,   &idle);
	if (top_sel == 0xf && opp_id == 0xf && idle)
		return true;
	else
		return false;
}

void mpc1_assert_mpcc_idle_before_connect(struct mpc *mpc, int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	unsigned int top_sel, mpc_busy, mpc_idle;

	REG_GET(MPCC_TOP_SEL[mpcc_id],
			MPCC_TOP_SEL, &top_sel);

	if (top_sel == 0xf) {
		REG_GET_2(MPCC_STATUS[mpcc_id],
				MPCC_BUSY, &mpc_busy,
				MPCC_IDLE, &mpc_idle);

		ASSERT(mpc_busy == 0);
		ASSERT(mpc_idle == 1);
	}
}

struct mpcc *mpc1_insert_plane(
	struct mpc *mpc,
	struct mpc_tree *tree,
	struct mpcc_blnd_cfg *blnd_cfg,
	struct mpcc_sm_cfg *sm_cfg,
	struct mpcc *insert_above_mpcc,
	int dpp_id,
	int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	struct mpcc *new_mpcc = NULL;

	/* sanity check parameters */
	ASSERT(mpcc_id < mpc10->num_mpcc);
	ASSERT(!(mpc10->mpcc_in_use_mask & 1 << mpcc_id));

	if (insert_above_mpcc) {
		/* check insert_above_mpcc exist in tree->opp_list */
		struct mpcc *temp_mpcc = tree->opp_list;

		while (temp_mpcc && temp_mpcc->mpcc_bot != insert_above_mpcc)
			temp_mpcc = temp_mpcc->mpcc_bot;
		if (temp_mpcc == NULL)
			return NULL;
	}

	/* Get and update MPCC struct parameters */
	new_mpcc = mpc1_get_mpcc(mpc, mpcc_id);
	new_mpcc->dpp_id = dpp_id;

	/* program mux and MPCC_MODE */
	if (insert_above_mpcc) {
		new_mpcc->mpcc_bot = insert_above_mpcc;
		REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, insert_above_mpcc->mpcc_id);
		REG_UPDATE(MPCC_CONTROL[mpcc_id], MPCC_MODE, MPCC_BLEND_MODE_TOP_BOT_BLENDING);
	} else {
		new_mpcc->mpcc_bot = NULL;
		REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, 0xf);
		REG_UPDATE(MPCC_CONTROL[mpcc_id], MPCC_MODE, MPCC_BLEND_MODE_TOP_LAYER_PASSTHROUGH);
	}
	REG_SET(MPCC_TOP_SEL[mpcc_id], 0, MPCC_TOP_SEL, dpp_id);
	REG_SET(MPCC_OPP_ID[mpcc_id], 0, MPCC_OPP_ID, tree->opp_id);

	/* update mpc tree mux setting */
	if (tree->opp_list == insert_above_mpcc) {
		/* insert the toppest mpcc */
		tree->opp_list = new_mpcc;
		REG_UPDATE(MUX[tree->opp_id], MPC_OUT_MUX, mpcc_id);
	} else {
		/* find insert position */
		struct mpcc *temp_mpcc = tree->opp_list;

		while (temp_mpcc && temp_mpcc->mpcc_bot != insert_above_mpcc)
			temp_mpcc = temp_mpcc->mpcc_bot;
		if (temp_mpcc && temp_mpcc->mpcc_bot == insert_above_mpcc) {
			REG_SET(MPCC_BOT_SEL[temp_mpcc->mpcc_id], 0, MPCC_BOT_SEL, mpcc_id);
			temp_mpcc->mpcc_bot = new_mpcc;
			if (!insert_above_mpcc)
				REG_UPDATE(MPCC_CONTROL[temp_mpcc->mpcc_id],
						MPCC_MODE, MPCC_BLEND_MODE_TOP_BOT_BLENDING);
		}
	}

	/* update the blending configuration */
	mpc->funcs->update_blending(mpc, blnd_cfg, mpcc_id);

	/* update the stereo mix settings, if provided */
	if (sm_cfg != NULL) {
		new_mpcc->sm_cfg = *sm_cfg;
		mpc1_update_stereo_mix(mpc, sm_cfg, mpcc_id);
	}

	/* mark this mpcc as in use */
	mpc10->mpcc_in_use_mask |= 1 << mpcc_id;

	return new_mpcc;
}

void mpc1_remove_mpcc(
	struct mpc *mpc,
	struct mpc_tree *tree,
	struct mpcc *mpcc_to_remove)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	bool found = false;
	int mpcc_id = mpcc_to_remove->mpcc_id;

	if (tree->opp_list == mpcc_to_remove) {
		found = true;
		/* remove MPCC from top of tree */
		if (mpcc_to_remove->mpcc_bot) {
			/* set the next MPCC in list to be the top MPCC */
			tree->opp_list = mpcc_to_remove->mpcc_bot;
			REG_UPDATE(MUX[tree->opp_id], MPC_OUT_MUX, tree->opp_list->mpcc_id);
		} else {
			/* there are no other MPCC is list */
			tree->opp_list = NULL;
			REG_UPDATE(MUX[tree->opp_id], MPC_OUT_MUX, 0xf);
		}
	} else {
		/* find mpcc to remove MPCC list */
		struct mpcc *temp_mpcc = tree->opp_list;

		while (temp_mpcc && temp_mpcc->mpcc_bot != mpcc_to_remove)
			temp_mpcc = temp_mpcc->mpcc_bot;

		if (temp_mpcc && temp_mpcc->mpcc_bot == mpcc_to_remove) {
			found = true;
			temp_mpcc->mpcc_bot = mpcc_to_remove->mpcc_bot;
			if (mpcc_to_remove->mpcc_bot) {
				/* remove MPCC in middle of list */
				REG_SET(MPCC_BOT_SEL[temp_mpcc->mpcc_id], 0,
						MPCC_BOT_SEL, mpcc_to_remove->mpcc_bot->mpcc_id);
			} else {
				/* remove MPCC from bottom of list */
				REG_SET(MPCC_BOT_SEL[temp_mpcc->mpcc_id], 0,
						MPCC_BOT_SEL, 0xf);
				REG_UPDATE(MPCC_CONTROL[temp_mpcc->mpcc_id],
						MPCC_MODE, MPCC_BLEND_MODE_TOP_LAYER_PASSTHROUGH);
			}
		}
	}

	if (found) {
		/* turn off MPCC mux registers */
		REG_SET(MPCC_TOP_SEL[mpcc_id], 0, MPCC_TOP_SEL, 0xf);
		REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, 0xf);
		REG_SET(MPCC_OPP_ID[mpcc_id],  0, MPCC_OPP_ID,  0xf);

		/* mark this mpcc as not in use */
		mpc10->mpcc_in_use_mask &= ~(1 << mpcc_id);
		mpcc_to_remove->dpp_id = 0xf;
		mpcc_to_remove->mpcc_bot = NULL;
	} else {
		/* In case of resume from S3/S4, remove mpcc from bios left over */
		REG_SET(MPCC_TOP_SEL[mpcc_id], 0, MPCC_TOP_SEL, 0xf);
		REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, 0xf);
		REG_SET(MPCC_OPP_ID[mpcc_id],  0, MPCC_OPP_ID,  0xf);
	}
}

__attribute__((used)) static void mpc1_init_mpcc(struct mpcc *mpcc, int mpcc_inst)
{
	mpcc->mpcc_id = mpcc_inst;
	mpcc->dpp_id = 0xf;
	mpcc->mpcc_bot = NULL;
	mpcc->blnd_cfg.overlap_only = false;
	mpcc->blnd_cfg.global_alpha = 0xff;
	mpcc->blnd_cfg.global_gain = 0xff;
	mpcc->sm_cfg.enable = false;
}

void mpc1_mpc_init(struct mpc *mpc)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	int mpcc_id;
	int opp_id;

	mpc10->mpcc_in_use_mask = 0;
	for (mpcc_id = 0; mpcc_id < mpc10->num_mpcc; mpcc_id++) {
		REG_SET(MPCC_TOP_SEL[mpcc_id], 0, MPCC_TOP_SEL, 0xf);
		REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, 0xf);
		REG_SET(MPCC_OPP_ID[mpcc_id],  0, MPCC_OPP_ID,  0xf);

		mpc1_init_mpcc(&(mpc->mpcc_array[mpcc_id]), mpcc_id);
	}

	for (opp_id = 0; opp_id < MAX_OPP; opp_id++) {
		if (REG(MUX[opp_id]))
			REG_UPDATE(MUX[opp_id], MPC_OUT_MUX, 0xf);
	}
}

void mpc1_init_mpcc_list_from_hw(
	struct mpc *mpc,
	struct mpc_tree *tree)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	unsigned int opp_id;
	unsigned int top_sel;
	unsigned int bot_sel;
	unsigned int out_mux;
	struct mpcc *mpcc;
	int mpcc_id;
	int bot_mpcc_id;

	REG_GET(MUX[tree->opp_id], MPC_OUT_MUX, &out_mux);

	if (out_mux != 0xf) {
		for (mpcc_id = 0; mpcc_id < mpc10->num_mpcc; mpcc_id++) {
			REG_GET(MPCC_OPP_ID[mpcc_id],  MPCC_OPP_ID,  &opp_id);
			REG_GET(MPCC_TOP_SEL[mpcc_id], MPCC_TOP_SEL, &top_sel);
			REG_GET(MPCC_BOT_SEL[mpcc_id],  MPCC_BOT_SEL, &bot_sel);

			if (bot_sel == mpcc_id)
				bot_sel = 0xf;

			if ((opp_id == tree->opp_id) && (top_sel != 0xf)) {
				mpcc = mpc1_get_mpcc(mpc, mpcc_id);
				mpcc->dpp_id = top_sel;
				mpc10->mpcc_in_use_mask |= 1 << mpcc_id;

				if (out_mux == mpcc_id)
					tree->opp_list = mpcc;
				if (bot_sel != 0xf && bot_sel < mpc10->num_mpcc) {
					bot_mpcc_id = bot_sel;
					REG_GET(MPCC_OPP_ID[bot_mpcc_id],  MPCC_OPP_ID,  &opp_id);
					REG_GET(MPCC_TOP_SEL[bot_mpcc_id], MPCC_TOP_SEL, &top_sel);
					if ((opp_id == tree->opp_id) && (top_sel != 0xf)) {
						struct mpcc *mpcc_bottom = mpc1_get_mpcc(mpc, bot_mpcc_id);

						mpcc->mpcc_bot = mpcc_bottom;
					}
				}
			}
		}
	}
}

void mpc1_read_mpcc_state(
		struct mpc *mpc,
		int mpcc_inst,
		struct mpcc_state *s)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);

	REG_GET(MPCC_OPP_ID[mpcc_inst], MPCC_OPP_ID, &s->opp_id);
	REG_GET(MPCC_TOP_SEL[mpcc_inst], MPCC_TOP_SEL, &s->dpp_id);
	REG_GET(MPCC_BOT_SEL[mpcc_inst], MPCC_BOT_SEL, &s->bot_mpcc_id);
	REG_GET_4(MPCC_CONTROL[mpcc_inst], MPCC_MODE, &s->mode,
			MPCC_ALPHA_BLND_MODE, &s->alpha_mode,
			MPCC_ALPHA_MULTIPLIED_MODE, &s->pre_multiplied_alpha,
			MPCC_BLND_ACTIVE_OVERLAP_ONLY, &s->overlap_only);
	REG_GET_2(MPCC_STATUS[mpcc_inst], MPCC_IDLE, &s->idle,
			MPCC_BUSY, &s->busy);
}

void dcn10_mpc_construct(struct dcn10_mpc *mpc10,
	struct dc_context *ctx,
	const struct dcn_mpc_registers *mpc_regs,
	const struct dcn_mpc_shift *mpc_shift,
	const struct dcn_mpc_mask *mpc_mask,
	int num_mpcc)
{
	int i;

	mpc10->base.ctx = ctx;

	mpc10->base.funcs = &dcn10_mpc_funcs;

	mpc10->mpc_regs = mpc_regs;
	mpc10->mpc_shift = mpc_shift;
	mpc10->mpc_mask = mpc_mask;

	mpc10->mpcc_in_use_mask = 0;
	mpc10->num_mpcc = num_mpcc;

	for (i = 0; i < MAX_MPCC; i++)
		mpc1_init_mpcc(&mpc10->base.mpcc_array[i], i);
}

