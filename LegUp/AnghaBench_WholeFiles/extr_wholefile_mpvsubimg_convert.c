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
struct sub_bitmaps {int num_parts; struct sub_bitmap* parts; } ;
struct sub_bitmap {scalar_t__ dh; scalar_t__ y; scalar_t__ dw; scalar_t__ x; int /*<<< orphan*/  bitmap; int /*<<< orphan*/  stride; int /*<<< orphan*/  h; int /*<<< orphan*/  w; } ;
struct mp_rect {int x0; int x1; int y0; int y1; scalar_t__ member_3; scalar_t__ member_2; scalar_t__ member_1; scalar_t__ member_0; } ;
struct mp_image {int /*<<< orphan*/ * planes; int /*<<< orphan*/ * stride; int /*<<< orphan*/  member_0; } ;

/* Variables and functions */
 int /*<<< orphan*/  IMGFMT_BGRA ; 
 int MERGE_RC_PIXELS ; 
 int /*<<< orphan*/  MP_TARRAY_REMOVE_AT (struct mp_rect*,int,int) ; 
 struct mp_image* mp_image_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_image_copy (struct mp_image*,struct mp_image*) ; 
 int /*<<< orphan*/  mp_image_set_size (struct mp_image*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_image_setfmt (struct mp_image*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_image_sw_blur_scale (struct mp_image*,struct mp_image*,double) ; 
 int /*<<< orphan*/  mp_rect_union (struct mp_rect*,struct mp_rect*) ; 
 int /*<<< orphan*/  talloc_free (struct mp_image*) ; 

void mp_blur_rgba_sub_bitmap(struct sub_bitmap *d, double gblur)
{
    struct mp_image *tmp1 = mp_image_alloc(IMGFMT_BGRA, d->w, d->h);
    if (tmp1) { // on OOM, skip region
        struct mp_image s = {0};
        mp_image_setfmt(&s, IMGFMT_BGRA);
        mp_image_set_size(&s, d->w, d->h);
        s.stride[0] = d->stride;
        s.planes[0] = d->bitmap;

        mp_image_copy(tmp1, &s);

        mp_image_sw_blur_scale(&s, tmp1, gblur);
    }
    talloc_free(tmp1);
}

__attribute__((used)) static void remove_intersecting_rcs(struct mp_rect *list, int *count)
{
    int M = MERGE_RC_PIXELS;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int a = 0; a < *count; a++) {
            struct mp_rect *rc_a = &list[a];
            for (int b = *count - 1; b > a; b--) {
                struct mp_rect *rc_b = &list[b];
                if (rc_a->x0 - M <= rc_b->x1 && rc_a->x1 + M >= rc_b->x0 &&
                    rc_a->y0 - M <= rc_b->y1 && rc_a->y1 + M >= rc_b->y0)
                {
                    mp_rect_union(rc_a, rc_b);
                    MP_TARRAY_REMOVE_AT(list, *count, b);
                    changed = true;
                }
            }
        }
    }
}

int mp_get_sub_bb_list(struct sub_bitmaps *sbs, struct mp_rect *out_rc_list,
                       int rc_list_count)
{
    int M = MERGE_RC_PIXELS;
    int num_rc = 0;
    for (int n = 0; n < sbs->num_parts; n++) {
        struct sub_bitmap *sb = &sbs->parts[n];
        struct mp_rect bb = {sb->x, sb->y, sb->x + sb->dw, sb->y + sb->dh};
        bool intersects = false;
        for (int r = 0; r < num_rc; r++) {
            struct mp_rect *rc = &out_rc_list[r];
            if ((bb.x0 - M <= rc->x1 && bb.x1 + M >= rc->x0 &&
                 bb.y0 - M <= rc->y1 && bb.y1 + M >= rc->y0) ||
                num_rc == rc_list_count)
            {
                mp_rect_union(rc, &bb);
                intersects = true;
                break;
            }
        }
        if (!intersects) {
            out_rc_list[num_rc++] = bb;
            remove_intersecting_rcs(out_rc_list, &num_rc);
        }
    }
    remove_intersecting_rcs(out_rc_list, &num_rc);
    return num_rc;
}

