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
struct parm {unsigned int width; unsigned int shift; int /*<<< orphan*/  reg_off; } ;
struct meson_clk_phase_data {struct parm ph; } ;
struct clk_regmap_mux_data {int dummy; } ;
struct clk_regmap_gate_data {int dummy; } ;
struct clk_regmap_div_data {int dummy; } ;
struct clk_regmap {struct regmap* map; scalar_t__ data; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned int DIV_ROUND_CLOSEST (int,unsigned int) ; 
 unsigned int PARM_GET (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  SETPMASK (unsigned int,unsigned int) ; 
 unsigned int phase_step (unsigned int) ; 
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

__attribute__((used)) static inline struct meson_clk_phase_data *
meson_clk_phase_data(struct clk_regmap *clk)
{
	return (struct meson_clk_phase_data *)clk->data;
}

int meson_clk_degrees_from_val(unsigned int val, unsigned int width)
{
	return phase_step(width) * val;
}

unsigned int meson_clk_degrees_to_val(int degrees, unsigned int width)
{
	unsigned int val = DIV_ROUND_CLOSEST(degrees, phase_step(width));

	/*
	 * This last calculation is here for cases when degrees is rounded
	 * to 360, in which case val == (1 << width).
	 */
	return val % (1 << width);
}

__attribute__((used)) static int meson_clk_phase_get_phase(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_phase_data *phase = meson_clk_phase_data(clk);
	unsigned int val;

	val = meson_parm_read(clk->map, &phase->ph);

	return meson_clk_degrees_from_val(val, phase->ph.width);
}

__attribute__((used)) static int meson_clk_phase_set_phase(struct clk_hw *hw, int degrees)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_phase_data *phase = meson_clk_phase_data(clk);
	unsigned int val;

	val = meson_clk_degrees_to_val(degrees, phase->ph.width);
	meson_parm_write(clk->map, &phase->ph, val);

	return 0;
}

