#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct grouping_min {double min; scalar_t__ count; } ;
typedef  double calculated_number ;
struct TYPE_8__ {int /*<<< orphan*/ * grouping_data; } ;
struct TYPE_9__ {TYPE_1__ internal; } ;
typedef  int /*<<< orphan*/  RRDR_VALUE_FLAGS ;
typedef  TYPE_2__ RRDR ;

/* Variables and functions */
 int /*<<< orphan*/  RRDR_VALUE_EMPTY ; 
 scalar_t__ calculated_number_fabs (double) ; 
 void* callocz (int,int) ; 
 int /*<<< orphan*/  freez (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  isnan (double) ; 
 scalar_t__ unlikely (int) ; 

void *grouping_create_min(RRDR *r) {
    (void)r;
    return callocz(1, sizeof(struct grouping_min));
}

void grouping_reset_min(RRDR *r) {
    struct grouping_min *g = (struct grouping_min *)r->internal.grouping_data;
    g->min = 0;
    g->count = 0;
}

void grouping_free_min(RRDR *r) {
    freez(r->internal.grouping_data);
    r->internal.grouping_data = NULL;
}

void grouping_add_min(RRDR *r, calculated_number value) {
    if(!isnan(value)) {
        struct grouping_min *g = (struct grouping_min *)r->internal.grouping_data;

        if(!g->count || calculated_number_fabs(value) < calculated_number_fabs(g->min)) {
            g->min = value;
            g->count++;
        }
    }
}

calculated_number grouping_flush_min(RRDR *r, RRDR_VALUE_FLAGS *rrdr_value_options_ptr) {
    struct grouping_min *g = (struct grouping_min *)r->internal.grouping_data;

    calculated_number value;

    if(unlikely(!g->count)) {
        value = 0.0;
        *rrdr_value_options_ptr |= RRDR_VALUE_EMPTY;
    }
    else {
        value = g->min;
    }

    g->min = 0.0;
    g->count = 0;

    return value;
}

