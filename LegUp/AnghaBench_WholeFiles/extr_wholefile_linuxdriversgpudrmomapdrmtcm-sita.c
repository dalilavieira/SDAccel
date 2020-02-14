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
struct TYPE_4__ {int y; int x; } ;
struct TYPE_3__ {int y; int x; } ;
struct tcm_area {int is2d; TYPE_2__ p1; TYPE_1__ p0; struct tcm* tcm; } ;
struct tcm {void (* deinit ) (struct tcm*) ;scalar_t__ height; scalar_t__ width; scalar_t__ (* reserve_2d ) (struct tcm*,scalar_t__,scalar_t__,scalar_t__,unsigned long,scalar_t__,struct tcm_area*) ;scalar_t__ (* reserve_1d ) (struct tcm*,int,struct tcm_area*) ;scalar_t__ (* free ) (struct tcm*,struct tcm_area*) ;unsigned long* bitmap; size_t map_size; int /*<<< orphan*/  lock; } ;
typedef  scalar_t__ s32 ;
typedef  unsigned long s16 ;

/* Variables and functions */
 unsigned long ALIGN (unsigned long,unsigned long) ; 
 unsigned long BITS_PER_LONG ; 
 int BITS_TO_LONGS (scalar_t__) ; 
 scalar_t__ EINVAL ; 
 scalar_t__ ENODEV ; 
 scalar_t__ ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  bitmap_clear (unsigned long*,unsigned long,scalar_t__) ; 
 unsigned long bitmap_find_next_zero_area (unsigned long*,size_t,unsigned long,scalar_t__,scalar_t__) ; 
 scalar_t__ bitmap_intersects (unsigned long*,unsigned long*,unsigned long) ; 
 int /*<<< orphan*/  bitmap_set (unsigned long*,unsigned long,scalar_t__) ; 
 unsigned long find_next_bit (unsigned long*,size_t,unsigned long) ; 
 int /*<<< orphan*/  kfree (struct tcm*) ; 
 struct tcm* kzalloc (int,int /*<<< orphan*/ ) ; 
 unsigned long* mask ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 void stub1 (struct tcm*) ; 
 scalar_t__ stub2 (struct tcm*,scalar_t__,scalar_t__,scalar_t__,unsigned long,scalar_t__,struct tcm_area*) ; 
 scalar_t__ stub3 (struct tcm*,int,struct tcm_area*) ; 
 scalar_t__ stub4 (struct tcm*,struct tcm_area*) ; 

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

__attribute__((used)) static void free_slots(unsigned long pos, u16 w, u16 h,
		unsigned long *map, u16 stride)
{
	int i;

	for (i = 0; i < h; i++, pos += stride)
		bitmap_clear(map, pos, w);
}

__attribute__((used)) static int r2l_b2t_1d(u16 w, unsigned long *pos, unsigned long *map,
		size_t num_bits)
{
	unsigned long search_count = 0;
	unsigned long bit;
	bool area_found = false;

	*pos = num_bits - w;

	while (search_count < num_bits) {
		bit = find_next_bit(map, num_bits, *pos);

		if (bit - *pos >= w) {
			/* found a long enough free area */
			bitmap_set(map, *pos, w);
			area_found = true;
			break;
		}

		search_count = num_bits - bit + w;
		*pos = bit - w;
	}

	return (area_found) ? 0 : -ENOMEM;
}

__attribute__((used)) static int l2r_t2b(u16 w, u16 h, u16 a, s16 offset,
		unsigned long *pos, unsigned long slot_bytes,
		unsigned long *map, size_t num_bits, size_t slot_stride)
{
	int i;
	unsigned long index;
	bool area_free = false;
	unsigned long slots_per_band = PAGE_SIZE / slot_bytes;
	unsigned long bit_offset = (offset > 0) ? offset / slot_bytes : 0;
	unsigned long curr_bit = bit_offset;

	/* reset alignment to 1 if we are matching a specific offset */
	/* adjust alignment - 1 to get to the format expected in bitmaps */
	a = (offset > 0) ? 0 : a - 1;

	/* FIXME Return error if slots_per_band > stride */

	while (curr_bit < num_bits) {
		*pos = bitmap_find_next_zero_area(map, num_bits, curr_bit, w,
				a);

		/* skip forward if we are not at right offset */
		if (bit_offset > 0 && (*pos % slots_per_band != bit_offset)) {
			curr_bit = ALIGN(*pos, slots_per_band) + bit_offset;
			continue;
		}

		/* skip forward to next row if we overlap end of row */
		if ((*pos % slot_stride) + w > slot_stride) {
			curr_bit = ALIGN(*pos, slot_stride) + bit_offset;
			continue;
		}

		/* TODO: Handle overlapping 4K boundaries */

		/* break out of look if we will go past end of container */
		if ((*pos + slot_stride * h) > num_bits)
			break;

		/* generate mask that represents out matching pattern */
		bitmap_clear(mask, 0, slot_stride);
		bitmap_set(mask, (*pos % BITS_PER_LONG), w);

		/* assume the area is free until we find an overlap */
		area_free = true;

		/* check subsequent rows to see if complete area is free */
		for (i = 1; i < h; i++) {
			index = *pos / BITS_PER_LONG + i * 8;
			if (bitmap_intersects(&map[index], mask,
				(*pos % BITS_PER_LONG) + w)) {
				area_free = false;
				break;
			}
		}

		if (area_free)
			break;

		/* go forward past this match */
		if (bit_offset > 0)
			curr_bit = ALIGN(*pos, slots_per_band) + bit_offset;
		else
			curr_bit = *pos + a + 1;
	}

	if (area_free) {
		/* set area as in-use. iterate over rows */
		for (i = 0, index = *pos; i < h; i++, index += slot_stride)
			bitmap_set(map, index, w);
	}

	return (area_free) ? 0 : -ENOMEM;
}

__attribute__((used)) static s32 sita_reserve_1d(struct tcm *tcm, u32 num_slots,
			   struct tcm_area *area)
{
	unsigned long pos;
	int ret;

	spin_lock(&(tcm->lock));
	ret = r2l_b2t_1d(num_slots, &pos, tcm->bitmap, tcm->map_size);
	if (!ret) {
		area->p0.x = pos % tcm->width;
		area->p0.y = pos / tcm->width;
		area->p1.x = (pos + num_slots - 1) % tcm->width;
		area->p1.y = (pos + num_slots - 1) / tcm->width;
	}
	spin_unlock(&(tcm->lock));

	return ret;
}

__attribute__((used)) static s32 sita_reserve_2d(struct tcm *tcm, u16 h, u16 w, u16 align,
				s16 offset, u16 slot_bytes,
				struct tcm_area *area)
{
	unsigned long pos;
	int ret;

	spin_lock(&(tcm->lock));
	ret = l2r_t2b(w, h, align, offset, &pos, slot_bytes, tcm->bitmap,
			tcm->map_size, tcm->width);

	if (!ret) {
		area->p0.x = pos % tcm->width;
		area->p0.y = pos / tcm->width;
		area->p1.x = area->p0.x + w - 1;
		area->p1.y = area->p0.y + h - 1;
	}
	spin_unlock(&(tcm->lock));

	return ret;
}

__attribute__((used)) static void sita_deinit(struct tcm *tcm)
{
	kfree(tcm);
}

__attribute__((used)) static s32 sita_free(struct tcm *tcm, struct tcm_area *area)
{
	unsigned long pos;
	u16 w, h;

	pos = area->p0.x + area->p0.y * tcm->width;
	if (area->is2d) {
		w = area->p1.x - area->p0.x + 1;
		h = area->p1.y - area->p0.y + 1;
	} else {
		w = area->p1.x + area->p1.y * tcm->width - pos + 1;
		h = 1;
	}

	spin_lock(&(tcm->lock));
	free_slots(pos, w, h, tcm->bitmap, tcm->width);
	spin_unlock(&(tcm->lock));
	return 0;
}

struct tcm *sita_init(u16 width, u16 height)
{
	struct tcm *tcm;
	size_t map_size = BITS_TO_LONGS(width*height) * sizeof(unsigned long);

	if (width == 0 || height == 0)
		return NULL;

	tcm = kzalloc(sizeof(*tcm) + map_size, GFP_KERNEL);
	if (!tcm)
		goto error;

	/* Updating the pointers to SiTA implementation APIs */
	tcm->height = height;
	tcm->width = width;
	tcm->reserve_2d = sita_reserve_2d;
	tcm->reserve_1d = sita_reserve_1d;
	tcm->free = sita_free;
	tcm->deinit = sita_deinit;

	spin_lock_init(&tcm->lock);
	tcm->bitmap = (unsigned long *)(tcm + 1);
	bitmap_clear(tcm->bitmap, 0, width*height);

	tcm->map_size = width*height;

	return tcm;

error:
	kfree(tcm);
	return NULL;
}

