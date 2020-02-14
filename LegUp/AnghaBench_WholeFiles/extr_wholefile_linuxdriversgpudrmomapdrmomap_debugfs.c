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
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct tcm_pt {scalar_t__ x; int y; } ;
struct TYPE_3__ {int y; int x; } ;
struct TYPE_4__ {int y; int x; } ;
struct tcm_area {int is2d; struct tcm* tcm; TYPE_1__ p0; TYPE_2__ p1; } ;
struct tcm {scalar_t__ height; scalar_t__ width; scalar_t__ (* reserve_2d ) (struct tcm*,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,struct tcm_area*) ;scalar_t__ (* reserve_1d ) (struct tcm*,int,struct tcm_area*) ;scalar_t__ (* free ) (struct tcm*,struct tcm_area*) ;int /*<<< orphan*/  (* deinit ) (struct tcm*) ;} ;
struct omap_dss_device {int src; scalar_t__ state; } ;
struct drm_device {int dummy; } ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  s16 ;
typedef  enum tiler_fmt { ____Placeholder_tiler_fmt } tiler_fmt ;

/* Variables and functions */
 scalar_t__ EINVAL ; 
 scalar_t__ ENODEV ; 
 scalar_t__ ENOMEM ; 
 int OMAP_BO_TILED ; 
#define  OMAP_BO_TILED_16 134 
#define  OMAP_BO_TILED_32 133 
#define  OMAP_BO_TILED_8 132 
 scalar_t__ OMAP_DSS_DISPLAY_ACTIVE ; 
#define  TILFMT_16BIT 131 
#define  TILFMT_32BIT 130 
#define  TILFMT_8BIT 129 
#define  TILFMT_PAGE 128 
 int /*<<< orphan*/  omapdss_get_dss () ; 
 int /*<<< orphan*/  stub1 (struct tcm*) ; 
 scalar_t__ stub2 (struct tcm*,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,struct tcm_area*) ; 
 scalar_t__ stub3 (struct tcm*,int,struct tcm_area*) ; 
 scalar_t__ stub4 (struct tcm*,struct tcm_area*) ; 

__attribute__((used)) static inline bool omapdss_is_initialized(void)
{
	return !!omapdss_get_dss();
}

__attribute__((used)) static inline bool omapdss_device_is_connected(struct omap_dss_device *dssdev)
{
	return dssdev->src;
}

__attribute__((used)) static inline bool omapdss_device_is_enabled(struct omap_dss_device *dssdev)
{
	return dssdev->state == OMAP_DSS_DISPLAY_ACTIVE;
}

__attribute__((used)) static inline void omap_fbdev_init(struct drm_device *dev)
{
}

__attribute__((used)) static inline void omap_fbdev_fini(struct drm_device *dev)
{
}

__attribute__((used)) static inline void tcm_deinit(struct tcm *tcm)
{
	if (tcm)
		tcm->deinit(tcm);
}

__attribute__((used)) static inline s32 tcm_reserve_2d(struct tcm *tcm, u16 width, u16 height,
				u16 align, s16 offset, u16 slot_bytes,
				struct tcm_area *area)
{
	/* perform rudimentary error checking */
	s32 res = tcm  == NULL ? -ENODEV :
		(area == NULL || width == 0 || height == 0 ||
		 /* align must be a 2 power */
		 (align & (align - 1))) ? -EINVAL :
		(height > tcm->height || width > tcm->width) ? -ENOMEM : 0;

	if (!res) {
		area->is2d = true;
		res = tcm->reserve_2d(tcm, height, width, align, offset,
					slot_bytes, area);
		area->tcm = res ? NULL : tcm;
	}

	return res;
}

__attribute__((used)) static inline s32 tcm_reserve_1d(struct tcm *tcm, u32 slots,
				 struct tcm_area *area)
{
	/* perform rudimentary error checking */
	s32 res = tcm  == NULL ? -ENODEV :
		(area == NULL || slots == 0) ? -EINVAL :
		slots > (tcm->width * (u32) tcm->height) ? -ENOMEM : 0;

	if (!res) {
		area->is2d = false;
		res = tcm->reserve_1d(tcm, slots, area);
		area->tcm = res ? NULL : tcm;
	}

	return res;
}

__attribute__((used)) static inline s32 tcm_free(struct tcm_area *area)
{
	s32 res = 0; /* free succeeds by default */

	if (area && area->tcm) {
		res = area->tcm->free(area->tcm, area);
		if (res == 0)
			area->tcm = NULL;
	}

	return res;
}

__attribute__((used)) static inline void tcm_slice(struct tcm_area *parent, struct tcm_area *slice)
{
	*slice = *parent;

	/* check if we need to slice */
	if (slice->tcm && !slice->is2d &&
		slice->p0.y != slice->p1.y &&
		(slice->p0.x || (slice->p1.x != slice->tcm->width - 1))) {
		/* set end point of slice (start always remains) */
		slice->p1.x = slice->tcm->width - 1;
		slice->p1.y = (slice->p0.x) ? slice->p0.y : slice->p1.y - 1;
		/* adjust remaining area */
		parent->p0.x = 0;
		parent->p0.y = slice->p1.y + 1;
	} else {
		/* mark this as the last slice */
		parent->tcm = NULL;
	}
}

__attribute__((used)) static inline bool tcm_area_is_valid(struct tcm_area *area)
{
	return area && area->tcm &&
		/* coordinate bounds */
		area->p1.x < area->tcm->width &&
		area->p1.y < area->tcm->height &&
		area->p0.y <= area->p1.y &&
		/* 1D coordinate relationship + p0.x check */
		((!area->is2d &&
		  area->p0.x < area->tcm->width &&
		  area->p0.x + area->p0.y * area->tcm->width <=
		  area->p1.x + area->p1.y * area->tcm->width) ||
		 /* 2D coordinate relationship */
		 (area->is2d &&
		  area->p0.x <= area->p1.x));
}

__attribute__((used)) static inline bool __tcm_is_in(struct tcm_pt *p, struct tcm_area *a)
{
	u16 i;

	if (a->is2d) {
		return p->x >= a->p0.x && p->x <= a->p1.x &&
		       p->y >= a->p0.y && p->y <= a->p1.y;
	} else {
		i = p->x + p->y * a->tcm->width;
		return i >= a->p0.x + a->p0.y * a->tcm->width &&
		       i <= a->p1.x + a->p1.y * a->tcm->width;
	}
}

__attribute__((used)) static inline u16 __tcm_area_width(struct tcm_area *area)
{
	return area->p1.x - area->p0.x + 1;
}

__attribute__((used)) static inline u16 __tcm_area_height(struct tcm_area *area)
{
	return area->p1.y - area->p0.y + 1;
}

__attribute__((used)) static inline u16 __tcm_sizeof(struct tcm_area *area)
{
	return area->is2d ?
		__tcm_area_width(area) * __tcm_area_height(area) :
		(area->p1.x - area->p0.x + 1) + (area->p1.y - area->p0.y) *
							area->tcm->width;
}

__attribute__((used)) static inline s32 tcm_1d_limit(struct tcm_area *a, u32 num_pg)
{
	if (__tcm_sizeof(a) < num_pg)
		return -ENOMEM;
	if (!num_pg)
		return -EINVAL;

	a->p1.x = (a->p0.x + num_pg - 1) % a->tcm->width;
	a->p1.y = a->p0.y + ((a->p0.x + num_pg - 1) / a->tcm->width);
	return 0;
}

__attribute__((used)) static inline enum tiler_fmt gem2fmt(u32 flags)
{
	switch (flags & OMAP_BO_TILED) {
	case OMAP_BO_TILED_8:
		return TILFMT_8BIT;
	case OMAP_BO_TILED_16:
		return TILFMT_16BIT;
	case OMAP_BO_TILED_32:
		return TILFMT_32BIT;
	default:
		return TILFMT_PAGE;
	}
}

__attribute__((used)) static inline bool validfmt(enum tiler_fmt fmt)
{
	switch (fmt) {
	case TILFMT_8BIT:
	case TILFMT_16BIT:
	case TILFMT_32BIT:
	case TILFMT_PAGE:
		return true;
	default:
		return false;
	}
}

