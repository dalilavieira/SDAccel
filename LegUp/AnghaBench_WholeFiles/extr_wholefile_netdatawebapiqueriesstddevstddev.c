#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct grouping_stddev {int count; double m_oldM; double m_newM; double m_oldS; double m_newS; } ;
typedef  double calculated_number ;
struct TYPE_9__ {int /*<<< orphan*/ * grouping_data; } ;
struct TYPE_10__ {long group; TYPE_1__ internal; } ;
typedef  int /*<<< orphan*/  RRDR_VALUE_FLAGS ;
typedef  TYPE_2__ RRDR ;
typedef  int /*<<< orphan*/  LONG_DOUBLE ;

/* Variables and functions */
 int /*<<< orphan*/  RRDR_VALUE_EMPTY ; 
 scalar_t__ calculated_number_isnumber (double) ; 
 void* callocz (int,int) ; 
 int /*<<< orphan*/  freez (int /*<<< orphan*/ *) ; 
 scalar_t__ likely (int) ; 
 double sqrtl (double) ; 
 scalar_t__ unlikely (int) ; 

void *grouping_create_stddev(RRDR *r) {
    long entries = r->group;
    if(entries < 0) entries = 0;

    return callocz(1, sizeof(struct grouping_stddev) + entries * sizeof(LONG_DOUBLE));
}

void grouping_reset_stddev(RRDR *r) {
    struct grouping_stddev *g = (struct grouping_stddev *)r->internal.grouping_data;
    g->count = 0;
}

void grouping_free_stddev(RRDR *r) {
    freez(r->internal.grouping_data);
    r->internal.grouping_data = NULL;
}

void grouping_add_stddev(RRDR *r, calculated_number value) {
    struct grouping_stddev *g = (struct grouping_stddev *)r->internal.grouping_data;

    if(calculated_number_isnumber(value)) {
        g->count++;

        // See Knuth TAOCP vol 2, 3rd edition, page 232
        if (g->count == 1) {
            g->m_oldM = g->m_newM = value;
            g->m_oldS = 0.0;
        }
        else {
            g->m_newM = g->m_oldM + (value - g->m_oldM) / g->count;
            g->m_newS = g->m_oldS + (value - g->m_oldM) * (value - g->m_newM);

            // set up for next iteration
            g->m_oldM = g->m_newM;
            g->m_oldS = g->m_newS;
        }
    }
}

__attribute__((used)) static inline calculated_number mean(struct grouping_stddev *g) {
    return (g->count > 0) ? g->m_newM : 0.0;
}

__attribute__((used)) static inline calculated_number variance(struct grouping_stddev *g) {
    return ( (g->count > 1) ? g->m_newS/(g->count - 1) : 0.0 );
}

__attribute__((used)) static inline calculated_number stddev(struct grouping_stddev *g) {
    return sqrtl(variance(g));
}

calculated_number grouping_flush_stddev(RRDR *r, RRDR_VALUE_FLAGS *rrdr_value_options_ptr) {
    struct grouping_stddev *g = (struct grouping_stddev *)r->internal.grouping_data;

    calculated_number value;

    if(likely(g->count > 1)) {
        value = stddev(g);

        if(!calculated_number_isnumber(value)) {
            value = 0.0;
            *rrdr_value_options_ptr |= RRDR_VALUE_EMPTY;
        }
    }
    else if(g->count == 1) {
        value = 0.0;
    }
    else {
        value = 0.0;
        *rrdr_value_options_ptr |= RRDR_VALUE_EMPTY;
    }

    grouping_reset_stddev(r);

    return  value;
}

calculated_number grouping_flush_coefficient_of_variation(RRDR *r, RRDR_VALUE_FLAGS *rrdr_value_options_ptr) {
    struct grouping_stddev *g = (struct grouping_stddev *)r->internal.grouping_data;

    calculated_number value;

    if(likely(g->count > 1)) {
        calculated_number m = mean(g);
        value = 100.0 * stddev(g) / ((m < 0)? -m : m);

        if(unlikely(!calculated_number_isnumber(value))) {
            value = 0.0;
            *rrdr_value_options_ptr |= RRDR_VALUE_EMPTY;
        }
    }
    else if(g->count == 1) {
        // one value collected
        value = 0.0;
    }
    else {
        // no values collected
        value = 0.0;
        *rrdr_value_options_ptr |= RRDR_VALUE_EMPTY;
    }

    grouping_reset_stddev(r);

    return  value;
}

