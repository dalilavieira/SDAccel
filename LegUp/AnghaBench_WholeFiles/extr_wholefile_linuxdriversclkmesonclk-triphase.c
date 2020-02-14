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
struct regmap {int dummy; } ;
struct parm {unsigned int shift; int /*<<< orphan*/  width; int /*<<< orphan*/  reg_off; } ;
struct meson_clk_triphase_data {struct parm ph2; struct parm ph1; struct parm ph0; } ;
struct clk_regmap_mux_data {int dummy; } ;
struct clk_regmap_gate_data {int dummy; } ;
struct clk_regmap_div_data {int dummy; } ;
struct clk_regmap {struct regmap* map; scalar_t__ data; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned int PARM_GET (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  SETPMASK (int /*<<< orphan*/ ,unsigned int) ; 
 int meson_clk_degrees_from_val (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int meson_clk_degrees_to_val (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 struct clk_regmap* to_clk_regmap (struct clk_hw*) ; 

__attribute__((used)) static inline struct clk_regmap_gate_data *
clk_get_regmap_gate_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_gate_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_div_data *
clk_get_regmap_div_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_div_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_mux_data *
clk_get_regmap_mux_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_mux_data *)clk->data;
}

__attribute__((used)) static inline unsigned int meson_parm_read(struct regmap *map, struct parm *p)
{
	unsigned int val;

	regmap_read(map, p->reg_off, &val);
	return PARM_GET(p->width, p->shift, val);
}

__attribute__((used)) static inline void meson_parm_write(struct regmap *map, struct parm *p,
				    unsigned int val)
{
	regmap_update_bits(map, p->reg_off, SETPMASK(p->width, p->shift),
			   val << p->shift);
}

__attribute__((used)) static inline struct meson_clk_triphase_data *
meson_clk_triphase_data(struct clk_regmap *clk)
{
	return (struct meson_clk_triphase_data *)clk->data;
}

__attribute__((used)) static void meson_clk_triphase_sync(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_triphase_data *tph = meson_clk_triphase_data(clk);
	unsigned int val;

	/* Get phase 0 and sync it to phase 1 and 2 */
	val = meson_parm_read(clk->map, &tph->ph0);
	meson_parm_write(clk->map, &tph->ph1, val);
	meson_parm_write(clk->map, &tph->ph2, val);
}

__attribute__((used)) static int meson_clk_triphase_get_phase(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_triphase_data *tph = meson_clk_triphase_data(clk);
	unsigned int val;

	/* Phase are in sync, reading phase 0 is enough */
	val = meson_parm_read(clk->map, &tph->ph0);

	return meson_clk_degrees_from_val(val, tph->ph0.width);
}

__attribute__((used)) static int meson_clk_triphase_set_phase(struct clk_hw *hw, int degrees)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_triphase_data *tph = meson_clk_triphase_data(clk);
	unsigned int val;

	val = meson_clk_degrees_to_val(degrees, tph->ph0.width);
	meson_parm_write(clk->map, &tph->ph0, val);
	meson_parm_write(clk->map, &tph->ph1, val);
	meson_parm_write(clk->map, &tph->ph2, val);

	return 0;
}

