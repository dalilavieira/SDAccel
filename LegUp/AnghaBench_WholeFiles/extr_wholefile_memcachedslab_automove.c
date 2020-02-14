#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
struct window_data {int window_size; double max_age_ratio; scalar_t__ age; int dirty; int evicted; int window_cur; TYPE_1__* sam_after; TYPE_1__* sam_before; TYPE_1__* iam_after; TYPE_1__* iam_before; struct window_data* window_data; } ;
struct settings {int slab_automove_window; double slab_automove_ratio; } ;
typedef  int /*<<< orphan*/  slab_stats_automove ;
typedef  struct window_data slab_automove ;
typedef  int /*<<< orphan*/  item_stats_automove ;
struct TYPE_5__ {scalar_t__ evicted; scalar_t__ outofmemory; scalar_t__ total_pages; scalar_t__ age; int free_chunks; int chunks_per_page; } ;

/* Variables and functions */
 int MAX_NUMBER_OF_SLAB_CLASSES ; 
 int MIN_PAGES_FOR_RECLAIM ; 
 scalar_t__ MIN_PAGES_FOR_SOURCE ; 
 int POWER_SMALLEST ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  fill_item_stats_automove (TYPE_1__*) ; 
 int /*<<< orphan*/  fill_slab_stats_automove (TYPE_1__*) ; 
 int /*<<< orphan*/  free (struct window_data*) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  memset (struct window_data*,int /*<<< orphan*/ ,int) ; 

void *slab_automove_init(struct settings *settings) {
    uint32_t window_size = settings->slab_automove_window;
    double max_age_ratio = settings->slab_automove_ratio;
    slab_automove *a = calloc(1, sizeof(slab_automove));
    if (a == NULL)
        return NULL;
    a->window_data = calloc(window_size * MAX_NUMBER_OF_SLAB_CLASSES, sizeof(struct window_data));
    a->window_size = window_size;
    a->max_age_ratio = max_age_ratio;
    if (a->window_data == NULL) {
        free(a);
        return NULL;
    }

    // do a dry run to fill the before structs
    fill_item_stats_automove(a->iam_before);
    fill_slab_stats_automove(a->sam_before);

    return (void *)a;
}

void slab_automove_free(void *arg) {
    slab_automove *a = (slab_automove *)arg;
    free(a->window_data);
    free(a);
}

__attribute__((used)) static void window_sum(struct window_data *wd, struct window_data *w, uint32_t size) {
    int x;
    for (x = 0; x < size; x++) {
        struct window_data *d = &wd[x];
        w->age += d->age;
        w->dirty += d->dirty;
        w->evicted += d->evicted;
    }
}

void slab_automove_run(void *arg, int *src, int *dst) {
    slab_automove *a = (slab_automove *)arg;
    int n;
    struct window_data w_sum;
    int oldest = -1;
    uint64_t oldest_age = 0;
    int youngest = -1;
    uint64_t youngest_age = ~0;
    bool youngest_evicting = false;
    *src = -1;
    *dst = -1;

    // fill after structs
    fill_item_stats_automove(a->iam_after);
    fill_slab_stats_automove(a->sam_after);
    a->window_cur++;

    // iterate slabs
    for (n = POWER_SMALLEST; n < MAX_NUMBER_OF_SLAB_CLASSES; n++) {
        int w_offset = n * a->window_size;
        struct window_data *wd = &a->window_data[w_offset + (a->window_cur % a->window_size)];
        memset(wd, 0, sizeof(struct window_data));
        // summarize the window-up-to-now.
        memset(&w_sum, 0, sizeof(struct window_data));
        window_sum(&a->window_data[w_offset], &w_sum, a->window_size);

        // if page delta, or evicted delta, mark window dirty
        // (or outofmemory)
        if (a->iam_after[n].evicted - a->iam_before[n].evicted > 0 ||
            a->iam_after[n].outofmemory - a->iam_before[n].outofmemory > 0) {
            wd->evicted = 1;
            wd->dirty = 1;
        }
        if (a->sam_after[n].total_pages - a->sam_before[n].total_pages > 0) {
            wd->dirty = 1;
        }

        // set age into window
        wd->age = a->iam_after[n].age;

        // grab age as average of window total
        uint64_t age = w_sum.age / a->window_size;

        // if > N free chunks and not dirty, make decision.
        if (a->sam_after[n].free_chunks > a->sam_after[n].chunks_per_page * MIN_PAGES_FOR_RECLAIM) {
            if (w_sum.dirty == 0) {
                *src = n;
                *dst = 0;
                break;
            }
        }

        // if oldest and have enough pages, is oldest
        if (age > oldest_age && a->sam_after[n].total_pages > MIN_PAGES_FOR_SOURCE) {
            oldest = n;
            oldest_age = age;
        }

        // grab evicted count from window
        // if > half the window and youngest, mark as youngest
        if (age < youngest_age && w_sum.evicted > a->window_size / 2) {
            youngest = n;
            youngest_age = age;
            youngest_evicting = wd->evicted ? true : false;
        }
    }

    memcpy(a->iam_before, a->iam_after,
            sizeof(item_stats_automove) * MAX_NUMBER_OF_SLAB_CLASSES);
    memcpy(a->sam_before, a->sam_after,
            sizeof(slab_stats_automove) * MAX_NUMBER_OF_SLAB_CLASSES);
    // if we have a youngest and oldest, and oldest is outside the ratio,
    // also, only make decisions if window has filled once.
    if (youngest != -1 && oldest != -1 && a->window_cur > a->window_size) {
        if (youngest_age < ((double)oldest_age * a->max_age_ratio) && youngest_evicting) {
            *src = oldest;
            *dst = youngest;
        }
    }
    return;
}

