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
struct rail_alignment {int step_uv; int offset_uv; } ;
struct device {int dummy; } ;
struct cvb_coefficients {int c2; int c1; int c0; } ;
struct cvb_table_freq_entry {unsigned long freq; struct cvb_coefficients coefficients; } ;
struct cvb_table {int min_millivolts; int max_millivolts; int speedo_scale; int voltage_scale; int speedo_id; int process_id; struct cvb_table_freq_entry* entries; struct rail_alignment alignment; } ;

/* Variables and functions */
 int DIV_ROUND_CLOSEST (int,int) ; 
 int DIV_ROUND_UP (int,int) ; 
 int DOWN ; 
 int EINVAL ; 
 struct cvb_table const* ERR_PTR (int) ; 
 int MAX_DVFS_FREQS ; 
 int UP ; 
 int clamp (int,int,int) ; 
 int dev_pm_opp_add (struct device*,unsigned long,int) ; 
 int /*<<< orphan*/  dev_pm_opp_remove (struct device*,unsigned long) ; 
 int max (int,int) ; 

__attribute__((used)) static inline int get_cvb_voltage(int speedo, int s_scale,
				  const struct cvb_coefficients *cvb)
{
	int mv;

	/* apply only speedo scale: output mv = cvb_mv * v_scale */
	mv = DIV_ROUND_CLOSEST(cvb->c2 * speedo, s_scale);
	mv = DIV_ROUND_CLOSEST((mv + cvb->c1) * speedo, s_scale) + cvb->c0;
	return mv;
}

__attribute__((used)) static int round_cvb_voltage(int mv, int v_scale,
			     const struct rail_alignment *align)
{
	/* combined: apply voltage scale and round to cvb alignment step */
	int uv;
	int step = (align->step_uv ? : 1000) * v_scale;
	int offset = align->offset_uv * v_scale;

	uv = max(mv * 1000, offset) - offset;
	uv = DIV_ROUND_UP(uv, step) * align->step_uv + align->offset_uv;
	return uv / 1000;
}

__attribute__((used)) static int round_voltage(int mv, const struct rail_alignment *align, int up)
{
	if (align->step_uv) {
		int uv;

		uv = max(mv * 1000, align->offset_uv) - align->offset_uv;
		uv = (uv + (up ? align->step_uv - 1 : 0)) / align->step_uv;
		return (uv * align->step_uv + align->offset_uv) / 1000;
	}
	return mv;
}

__attribute__((used)) static int build_opp_table(struct device *dev, const struct cvb_table *table,
			   int speedo_value, unsigned long max_freq)
{
	const struct rail_alignment *align = &table->alignment;
	int i, ret, dfll_mv, min_mv, max_mv;

	min_mv = round_voltage(table->min_millivolts, align, UP);
	max_mv = round_voltage(table->max_millivolts, align, DOWN);

	for (i = 0; i < MAX_DVFS_FREQS; i++) {
		const struct cvb_table_freq_entry *entry = &table->entries[i];

		if (!entry->freq || (entry->freq > max_freq))
			break;

		dfll_mv = get_cvb_voltage(speedo_value, table->speedo_scale,
					  &entry->coefficients);
		dfll_mv = round_cvb_voltage(dfll_mv, table->voltage_scale,
					    align);
		dfll_mv = clamp(dfll_mv, min_mv, max_mv);

		ret = dev_pm_opp_add(dev, entry->freq, dfll_mv * 1000);
		if (ret)
			return ret;
	}

	return 0;
}

const struct cvb_table *
tegra_cvb_add_opp_table(struct device *dev, const struct cvb_table *tables,
			size_t count, int process_id, int speedo_id,
			int speedo_value, unsigned long max_freq)
{
	size_t i;
	int ret;

	for (i = 0; i < count; i++) {
		const struct cvb_table *table = &tables[i];

		if (table->speedo_id != -1 && table->speedo_id != speedo_id)
			continue;

		if (table->process_id != -1 && table->process_id != process_id)
			continue;

		ret = build_opp_table(dev, table, speedo_value, max_freq);
		return ret ? ERR_PTR(ret) : table;
	}

	return ERR_PTR(-EINVAL);
}

void tegra_cvb_remove_opp_table(struct device *dev,
				const struct cvb_table *table,
				unsigned long max_freq)
{
	unsigned int i;

	for (i = 0; i < MAX_DVFS_FREQS; i++) {
		const struct cvb_table_freq_entry *entry = &table->entries[i];

		if (!entry->freq || (entry->freq > max_freq))
			break;

		dev_pm_opp_remove(dev, entry->freq);
	}
}

