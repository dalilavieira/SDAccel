#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_30__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ time_t ;
typedef  int /*<<< orphan*/  storage_number ;
typedef  double calculated_number ;
struct TYPE_35__ {struct TYPE_35__* next; int /*<<< orphan*/ * values; int /*<<< orphan*/  name; int /*<<< orphan*/  id; } ;
struct TYPE_31__ {double (* grouping_flush ) (TYPE_3__*,int /*<<< orphan*/ *) ;size_t db_points_read; long result_points_generated; long points_wanted; long resampling_group; double resampling_divisor; int /*<<< orphan*/  (* grouping_free ) (TYPE_3__*) ;int /*<<< orphan*/  (* grouping_reset ) (TYPE_3__*) ;int /*<<< orphan*/  (* grouping_create ) (TYPE_3__*) ;int /*<<< orphan*/  grouping_data; int /*<<< orphan*/  (* grouping_add ) (TYPE_3__*,double) ;} ;
struct TYPE_34__ {int* od; long d; double* v; long rows; long group; double min; double max; scalar_t__ before; scalar_t__ after; int update_every; TYPE_1__ internal; int /*<<< orphan*/  result_options; TYPE_2__* st; int /*<<< orphan*/ * o; scalar_t__* t; } ;
struct TYPE_33__ {char const* name; scalar_t__ hash; scalar_t__ value; double (* flush ) (TYPE_3__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* add ) (TYPE_3__*,double) ;int /*<<< orphan*/  (* free ) (TYPE_3__*) ;int /*<<< orphan*/  (* reset ) (TYPE_3__*) ;int /*<<< orphan*/  (* create ) (TYPE_3__*) ;int /*<<< orphan*/  (* init ) () ;} ;
struct TYPE_32__ {scalar_t__ update_every; long entries; TYPE_4__* dimensions; } ;
typedef  int /*<<< orphan*/  SIMPLE_PATTERN ;
typedef  TYPE_2__ RRDSET ;
typedef  int /*<<< orphan*/  RRDR_VALUE_FLAGS ;
typedef  int RRDR_OPTIONS ;
typedef  scalar_t__ RRDR_GROUPING ;
typedef  TYPE_3__ RRDR ;
typedef  TYPE_4__ RRDDIM ;

/* Variables and functions */
 long long API_RELATIVE_TIME_MAX ; 
 double NAN ; 
 int RRDR_DIMENSION_HIDDEN ; 
 int RRDR_DIMENSION_NONZERO ; 
 int RRDR_DIMENSION_SELECTED ; 
 int RRDR_OPTION_MATCH_IDS ; 
 int RRDR_OPTION_MATCH_NAMES ; 
 int RRDR_OPTION_NONZERO ; 
 int RRDR_OPTION_NOT_ALIGNED ; 
 int RRDR_OPTION_PERCENTAGE ; 
 int /*<<< orphan*/  RRDR_RESULT_OPTION_ABSOLUTE ; 
 int /*<<< orphan*/  RRDR_RESULT_OPTION_RELATIVE ; 
 int /*<<< orphan*/  RRDR_VALUE_NOTHING ; 
 int /*<<< orphan*/  RRDR_VALUE_RESET ; 
 int /*<<< orphan*/  SIMPLE_PATTERN_EXACT ; 
 int abs (long long) ; 
 TYPE_30__* api_v1_data_groups ; 
 int did_storage_number_reset (int /*<<< orphan*/ ) ; 
 int does_storage_number_exist (int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  grouping_add_average (TYPE_3__*,double) ; 
 int /*<<< orphan*/  grouping_create_average (TYPE_3__*) ; 
 double grouping_flush_average (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  grouping_free_average (TYPE_3__*) ; 
 int /*<<< orphan*/  grouping_reset_average (TYPE_3__*) ; 
 scalar_t__ likely (int) ; 
 TYPE_3__* rrdr_create (TYPE_2__*,long) ; 
 int /*<<< orphan*/  rrdr_query_completed (size_t,long) ; 
 int /*<<< orphan*/  rrdset_check_rdlock (TYPE_2__*) ; 
 scalar_t__ rrdset_first_entry_t (TYPE_2__*) ; 
 scalar_t__ rrdset_last_entry_t (TYPE_2__*) ; 
 size_t rrdset_time2slot (TYPE_2__*,scalar_t__) ; 
 void* simple_hash (char const*) ; 
 int /*<<< orphan*/ * simple_pattern_create (char const*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  simple_pattern_free (int /*<<< orphan*/ *) ; 
 scalar_t__ simple_pattern_matches (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 (TYPE_3__*,double) ; 
 double stub3 (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub4 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_3__*) ; 
 scalar_t__ unlikely (int) ; 
 double unpack_storage_number (int /*<<< orphan*/ ) ; 

void web_client_api_v1_init_grouping(void) {
    int i;

    for(i = 0; api_v1_data_groups[i].name ; i++) {
        api_v1_data_groups[i].hash = simple_hash(api_v1_data_groups[i].name);

        if(api_v1_data_groups[i].init)
            api_v1_data_groups[i].init();
    }
}

const char *group_method2string(RRDR_GROUPING group) {
    int i;

    for(i = 0; api_v1_data_groups[i].name ; i++) {
        if(api_v1_data_groups[i].value == group) {
            return api_v1_data_groups[i].name;
        }
    }

    return "unknown-group-method";
}

RRDR_GROUPING web_client_api_request_v1_data_group(const char *name, RRDR_GROUPING def) {
    int i;

    uint32_t hash = simple_hash(name);
    for(i = 0; api_v1_data_groups[i].name ; i++)
        if(unlikely(hash == api_v1_data_groups[i].hash && !strcmp(name, api_v1_data_groups[i].name)))
            return api_v1_data_groups[i].value;

    return def;
}

__attribute__((used)) static void rrdr_disable_not_selected_dimensions(RRDR *r, RRDR_OPTIONS options, const char *dims) {
    rrdset_check_rdlock(r->st);

    if(unlikely(!dims || !*dims || (dims[0] == '*' && dims[1] == '\0'))) return;

    int match_ids = 0, match_names = 0;

    if(unlikely(options & RRDR_OPTION_MATCH_IDS))
        match_ids = 1;
    if(unlikely(options & RRDR_OPTION_MATCH_NAMES))
        match_names = 1;

    if(likely(!match_ids && !match_names))
        match_ids = match_names = 1;

    SIMPLE_PATTERN *pattern = simple_pattern_create(dims, ",|\t\r\n\f\v", SIMPLE_PATTERN_EXACT);

    RRDDIM *d;
    long c, dims_selected = 0, dims_not_hidden_not_zero = 0;
    for(c = 0, d = r->st->dimensions; d ;c++, d = d->next) {
        if(    (match_ids   && simple_pattern_matches(pattern, d->id))
               || (match_names && simple_pattern_matches(pattern, d->name))
                ) {
            r->od[c] |= RRDR_DIMENSION_SELECTED;
            if(unlikely(r->od[c] & RRDR_DIMENSION_HIDDEN)) r->od[c] &= ~RRDR_DIMENSION_HIDDEN;
            dims_selected++;

            // since the user needs this dimension
            // make it appear as NONZERO, to return it
            // even if the dimension has only zeros
            // unless option non_zero is set
            if(unlikely(!(options & RRDR_OPTION_NONZERO)))
                r->od[c] |= RRDR_DIMENSION_NONZERO;

            // count the visible dimensions
            if(likely(r->od[c] & RRDR_DIMENSION_NONZERO))
                dims_not_hidden_not_zero++;
        }
        else {
            r->od[c] |= RRDR_DIMENSION_HIDDEN;
            if(unlikely(r->od[c] & RRDR_DIMENSION_SELECTED)) r->od[c] &= ~RRDR_DIMENSION_SELECTED;
        }
    }
    simple_pattern_free(pattern);

    // check if all dimensions are hidden
    if(unlikely(!dims_not_hidden_not_zero && dims_selected)) {
        // there are a few selected dimensions
        // but they are all zero
        // enable the selected ones
        // to avoid returning an empty chart
        for(c = 0, d = r->st->dimensions; d ;c++, d = d->next)
            if(unlikely(r->od[c] & RRDR_DIMENSION_SELECTED))
                r->od[c] |= RRDR_DIMENSION_NONZERO;
    }
}

__attribute__((used)) static inline RRDR_VALUE_FLAGS *rrdr_line_options(RRDR *r, long rrdr_line) {
    return &r->o[ rrdr_line * r->d ];
}

__attribute__((used)) static inline calculated_number *rrdr_line_values(RRDR *r, long rrdr_line) {
    return &r->v[ rrdr_line * r->d ];
}

__attribute__((used)) static inline long rrdr_line_init(RRDR *r, time_t t, long rrdr_line) {
    rrdr_line++;

    #ifdef NETDATA_INTERNAL_CHECKS

    if(unlikely(rrdr_line >= r->n))
        error("INTERNAL ERROR: requested to step above RRDR size for chart '%s'", r->st->name);

    if(unlikely(r->t[rrdr_line] != 0 && r->t[rrdr_line] != t))
        error("INTERNAL ERROR: overwriting the timestamp of RRDR line %zu from %zu to %zu, of chart '%s'", (size_t)rrdr_line, (size_t)r->t[rrdr_line], (size_t)t, r->st->name);

    #endif

    // save the time
    r->t[rrdr_line] = t;

    return rrdr_line;
}

__attribute__((used)) static inline void rrdr_done(RRDR *r, long rrdr_line) {
    r->rows = rrdr_line + 1;
}

__attribute__((used)) static inline void do_dimension(
          RRDR *r
        , long points_wanted
        , RRDDIM *rd
        , long dim_id_in_rrdr
        , long after_slot
        , long before_slot
        , time_t after_wanted
        , time_t before_wanted
){
    (void) before_slot;

    RRDSET *st = r->st;

    time_t
        now = after_wanted,
        dt = st->update_every,
        max_date = 0,
        min_date = 0;

    long
        slot = after_slot,
        group_size = r->group,
        points_added = 0,
        values_in_group = 0,
        values_in_group_non_zero = 0,
        rrdr_line = -1,
        entries = st->entries;

    RRDR_VALUE_FLAGS
        group_value_flags = RRDR_VALUE_NOTHING;

    calculated_number min = r->min, max = r->max;
    size_t db_points_read = 0;
    for( ; points_added < points_wanted ; now += dt, slot++ ) {
        if(unlikely(slot >= entries)) slot = 0;

        // make sure we return data in the proper time range
        if(unlikely(now > before_wanted)) {
            #ifdef NETDATA_INTERNAL_CHECKS
            r->internal.log = "stopped, because attempted to access the db after 'wanted before'";
            #endif
            break;
        }
        if(unlikely(now < after_wanted)) {
            #ifdef NETDATA_INTERNAL_CHECKS
            r->internal.log = "skipped, because attempted to access the db before 'wanted after'";
            #endif
            continue;
        }

        // read the value from the database
        storage_number n = rd->values[slot];
        calculated_number value = NAN;
        if(likely(does_storage_number_exist(n))) {

            value = unpack_storage_number(n);
            if(likely(value != 0.0))
                values_in_group_non_zero++;

            if(unlikely(did_storage_number_reset(n)))
                group_value_flags |= RRDR_VALUE_RESET;

        }

        // add this value for grouping
        r->internal.grouping_add(r, value);
        values_in_group++;
        db_points_read++;

        if(unlikely(values_in_group == group_size)) {
            rrdr_line = rrdr_line_init(r, now, rrdr_line);

            if(unlikely(!min_date)) min_date = now;
            max_date = now;

            // find the place to store our values
            RRDR_VALUE_FLAGS *rrdr_value_options_ptr = &r->o[rrdr_line * r->d + dim_id_in_rrdr];

            // update the dimension options
            if(likely(values_in_group_non_zero))
                r->od[dim_id_in_rrdr] |= RRDR_DIMENSION_NONZERO;

            // store the specific point options
            *rrdr_value_options_ptr = group_value_flags;

            // store the value
            calculated_number value = r->internal.grouping_flush(r, rrdr_value_options_ptr);
            r->v[rrdr_line * r->d + dim_id_in_rrdr] = value;

            if(likely(points_added || dim_id_in_rrdr)) {
                // find the min/max across all dimensions

                if(unlikely(value < min)) min = value;
                if(unlikely(value > max)) max = value;

            }
            else {
                // runs only when dim_id_in_rrdr == 0 && points_added == 0
                // so, on the first point added for the query.
                min = max = value;
            }

            points_added++;
            values_in_group = 0;
            group_value_flags = RRDR_VALUE_NOTHING;
            values_in_group_non_zero = 0;
        }
    }

    r->internal.db_points_read += db_points_read;
    r->internal.result_points_generated += points_added;

    r->min = min;
    r->max = max;
    r->before = max_date;
    r->after = min_date - (r->group - 1) * r->st->update_every;
    rrdr_done(r, rrdr_line);

    #ifdef NETDATA_INTERNAL_CHECKS
    if(unlikely(r->rows != points_added))
        error("INTERNAL ERROR: %s.%s added %zu rows, but RRDR says I added %zu.", r->st->name, rd->name, (size_t)points_added, (size_t)r->rows);
    #endif
}

RRDR *rrd2rrdr(
        RRDSET *st
        , long points_requested
        , long long after_requested
        , long long before_requested
        , RRDR_GROUPING group_method
        , long resampling_time_requested
        , RRDR_OPTIONS options
        , const char *dimensions
) {
    int aligned = !(options & RRDR_OPTION_NOT_ALIGNED);

    int absolute_period_requested = -1;

    time_t first_entry_t = rrdset_first_entry_t(st);
    time_t last_entry_t  = rrdset_last_entry_t(st);

    if(before_requested == 0 && after_requested == 0) {
        // dump the all the data
        before_requested = last_entry_t;
        after_requested = first_entry_t;
        absolute_period_requested = 0;
    }

    // allow relative for before (smaller than API_RELATIVE_TIME_MAX)
    if(((before_requested < 0)?-before_requested:before_requested) <= API_RELATIVE_TIME_MAX) {
        if(abs(before_requested) % st->update_every) {
            // make sure it is multiple of st->update_every
            if(before_requested < 0) before_requested = before_requested - st->update_every - before_requested % st->update_every;
            else           before_requested = before_requested + st->update_every - before_requested % st->update_every;
        }
        if(before_requested > 0) before_requested = first_entry_t + before_requested;
        else           before_requested = last_entry_t  + before_requested;
        absolute_period_requested = 0;
    }

    // allow relative for after (smaller than API_RELATIVE_TIME_MAX)
    if(((after_requested < 0)?-after_requested:after_requested) <= API_RELATIVE_TIME_MAX) {
        if(after_requested == 0) after_requested = -st->update_every;
        if(abs(after_requested) % st->update_every) {
            // make sure it is multiple of st->update_every
            if(after_requested < 0) after_requested = after_requested - st->update_every - after_requested % st->update_every;
            else          after_requested = after_requested + st->update_every - after_requested % st->update_every;
        }
        after_requested = before_requested + after_requested;
        absolute_period_requested = 0;
    }

    if(absolute_period_requested == -1)
        absolute_period_requested = 1;

    // make sure they are within our timeframe
    if(before_requested > last_entry_t)  before_requested = last_entry_t;
    if(before_requested < first_entry_t) before_requested = first_entry_t;

    if(after_requested > last_entry_t)  after_requested = last_entry_t;
    if(after_requested < first_entry_t) after_requested = first_entry_t;

    // check if they are reversed
    if(after_requested > before_requested) {
        time_t tmp = before_requested;
        before_requested = after_requested;
        after_requested = tmp;
    }

    // the duration of the chart
    time_t duration = before_requested - after_requested;
    long available_points = duration / st->update_every;

    if(duration <= 0 || available_points <= 0)
        return rrdr_create(st, 1);

    // check the number of wanted points in the result
    if(unlikely(points_requested < 0)) points_requested = -points_requested;
    if(unlikely(points_requested > available_points)) points_requested = available_points;
    if(unlikely(points_requested == 0)) points_requested = available_points;

    // calculate the desired grouping of source data points
    long group = available_points / points_requested;
    if(unlikely(group <= 0)) group = 1;
    if(unlikely(available_points % points_requested > points_requested / 2)) group++; // rounding to the closest integer

    // resampling_time_requested enforces a certain grouping multiple
    calculated_number resampling_divisor = 1.0;
    long resampling_group = 1;
    if(unlikely(resampling_time_requested > st->update_every)) {
        if (unlikely(resampling_time_requested > duration)) {
            // group_time is above the available duration

            #ifdef NETDATA_INTERNAL_CHECKS
            info("INTERNAL CHECK: %s: requested gtime %ld secs, is greater than the desired duration %ld secs", st->id, resampling_time_requested, duration);
            #endif

            after_requested = before_requested - resampling_time_requested;
            duration = before_requested - after_requested;
            available_points = duration / st->update_every;
            group = available_points / points_requested;
        }

        // if the duration is not aligned to resampling time
        // extend the duration to the past, to avoid a gap at the chart
        // only when the missing duration is above 1/10th of a point
        if(duration % resampling_time_requested) {
            time_t delta = duration % resampling_time_requested;
            if(delta > resampling_time_requested / 10) {
                after_requested -= resampling_time_requested - delta;
                duration = before_requested - after_requested;
                available_points = duration / st->update_every;
                group = available_points / points_requested;
            }
        }

        // the points we should group to satisfy gtime
        resampling_group = resampling_time_requested / st->update_every;
        if(unlikely(resampling_time_requested % st->update_every)) {
            #ifdef NETDATA_INTERNAL_CHECKS
            info("INTERNAL CHECK: %s: requested gtime %ld secs, is not a multiple of the chart's data collection frequency %d secs", st->id, resampling_time_requested, st->update_every);
            #endif

            resampling_group++;
        }

        // adapt group according to resampling_group
        if(unlikely(group < resampling_group)) group  = resampling_group; // do not allow grouping below the desired one
        if(unlikely(group % resampling_group)) group += resampling_group - (group % resampling_group); // make sure group is multiple of resampling_group

        //resampling_divisor = group / resampling_group;
        resampling_divisor = (calculated_number)(group * st->update_every) / (calculated_number)resampling_time_requested;
    }

    // now that we have group,
    // align the requested timeframe to fit it.

    if(aligned) {
        // alignement has been requested, so align the values
        before_requested -= (before_requested % group);
        after_requested  -= (after_requested % group);
    }

    // we align the request on requested_before
    time_t before_wanted = before_requested;
    if(likely(before_wanted > last_entry_t)) {
        #ifdef NETDATA_INTERNAL_CHECKS
        error("INTERNAL ERROR: rrd2rrdr() on %s, before_wanted is after db max", st->name);
        #endif

        before_wanted = last_entry_t - (last_entry_t % ( ((aligned)?group:1) * st->update_every ));
    }
    size_t before_slot = rrdset_time2slot(st, before_wanted);

    // we need to estimate the number of points, for having
    // an integer number of values per point
    long points_wanted = (before_wanted - after_requested) / (st->update_every * group);

    time_t after_wanted  = before_wanted - (points_wanted * group * st->update_every) + st->update_every;
    if(unlikely(after_wanted < first_entry_t)) {
        // hm... we go to the past, calculate again points_wanted using all the db from before_wanted to the beginning
        points_wanted = (before_wanted - first_entry_t) / group;

        // recalculate after wanted with the new number of points
        after_wanted  = before_wanted - (points_wanted * group * st->update_every) + st->update_every;

        if(unlikely(after_wanted < first_entry_t)) {
            #ifdef NETDATA_INTERNAL_CHECKS
            error("INTERNAL ERROR: rrd2rrdr() on %s, after_wanted is before db min", st->name);
            #endif

            after_wanted = first_entry_t - (first_entry_t % ( ((aligned)?group:1) * st->update_every )) + ( ((aligned)?group:1) * st->update_every );
        }
    }
    size_t after_slot  = rrdset_time2slot(st, after_wanted);

    // check if they are reversed
    if(unlikely(after_wanted > before_wanted)) {
        #ifdef NETDATA_INTERNAL_CHECKS
        error("INTERNAL ERROR: rrd2rrdr() on %s, reversed wanted after/before", st->name);
        #endif
        time_t tmp = before_wanted;
        before_wanted = after_wanted;
        after_wanted = tmp;
    }

    // recalculate points_wanted using the final time-frame
    points_wanted   = (before_wanted - after_wanted) / st->update_every / group + 1;
    if(unlikely(points_wanted < 0)) {
        #ifdef NETDATA_INTERNAL_CHECKS
        error("INTERNAL ERROR: rrd2rrdr() on %s, points_wanted is %ld", st->name, points_wanted);
        #endif
        points_wanted = 0;
    }

#ifdef NETDATA_INTERNAL_CHECKS
    duration = before_wanted - after_wanted;

    if(after_wanted < first_entry_t)
        error("INTERNAL CHECK: after_wanted %u is too small, minimum %u", (uint32_t)after_wanted, (uint32_t)first_entry_t);

    if(after_wanted > last_entry_t)
        error("INTERNAL CHECK: after_wanted %u is too big, maximum %u", (uint32_t)after_wanted, (uint32_t)last_entry_t);

    if(before_wanted < first_entry_t)
        error("INTERNAL CHECK: before_wanted %u is too small, minimum %u", (uint32_t)before_wanted, (uint32_t)first_entry_t);

    if(before_wanted > last_entry_t)
        error("INTERNAL CHECK: before_wanted %u is too big, maximum %u", (uint32_t)before_wanted, (uint32_t)last_entry_t);

    if(before_slot >= (size_t)st->entries)
        error("INTERNAL CHECK: before_slot is invalid %zu, expected 0 to %ld", before_slot, st->entries - 1);

    if(after_slot >= (size_t)st->entries)
        error("INTERNAL CHECK: after_slot is invalid %zu, expected 0 to %ld", after_slot, st->entries - 1);

    if(points_wanted > (before_wanted - after_wanted) / group / st->update_every + 1)
        error("INTERNAL CHECK: points_wanted %ld is more than points %ld", points_wanted, (before_wanted - after_wanted) / group / st->update_every + 1);

    if(group < resampling_group)
        error("INTERNAL CHECK: group %ld is less than the desired group points %ld", group, resampling_group);

    if(group > resampling_group && group % resampling_group)
        error("INTERNAL CHECK: group %ld is not a multiple of the desired group points %ld", group, resampling_group);
#endif

    // -------------------------------------------------------------------------
    // initialize our result set
    // this also locks the chart for us

    RRDR *r = rrdr_create(st, points_wanted);
    if(unlikely(!r)) {
        #ifdef NETDATA_INTERNAL_CHECKS
        error("INTERNAL CHECK: Cannot create RRDR for %s, after=%u, before=%u, duration=%u, points=%ld", st->id, (uint32_t)after_wanted, (uint32_t)before_wanted, (uint32_t)duration, points_wanted);
        #endif
        return NULL;
    }

    if(unlikely(!r->d || !points_wanted)) {
        #ifdef NETDATA_INTERNAL_CHECKS
        error("INTERNAL CHECK: Returning empty RRDR (no dimensions in RRDSET) for %s, after=%u, before=%u, duration=%zu, points=%ld", st->id, (uint32_t)after_wanted, (uint32_t)before_wanted, (size_t)duration, points_wanted);
        #endif
        return r;
    }

    if(unlikely(absolute_period_requested == 1))
        r->result_options |= RRDR_RESULT_OPTION_ABSOLUTE;
    else
        r->result_options |= RRDR_RESULT_OPTION_RELATIVE;

    // find how many dimensions we have
    long dimensions_count = r->d;

    // -------------------------------------------------------------------------
    // initialize RRDR

    r->group = group;
    r->update_every = (int)group * st->update_every;
    r->before = before_wanted;
    r->after = after_wanted;
    r->internal.points_wanted = points_wanted;
    r->internal.resampling_group = resampling_group;
    r->internal.resampling_divisor = resampling_divisor;


    // -------------------------------------------------------------------------
    // assign the processor functions

    {
        int i, found = 0;
        for(i = 0; !found && api_v1_data_groups[i].name ;i++) {
            if(api_v1_data_groups[i].value == group_method) {
                r->internal.grouping_create= api_v1_data_groups[i].create;
                r->internal.grouping_reset = api_v1_data_groups[i].reset;
                r->internal.grouping_free  = api_v1_data_groups[i].free;
                r->internal.grouping_add   = api_v1_data_groups[i].add;
                r->internal.grouping_flush = api_v1_data_groups[i].flush;
                found = 1;
            }
        }
        if(!found) {
            errno = 0;
            #ifdef NETDATA_INTERNAL_CHECKS
            error("INTERNAL ERROR: grouping method %u not found for chart '%s'. Using 'average'", (unsigned int)group_method, r->st->name);
            #endif
            r->internal.grouping_create= grouping_create_average;
            r->internal.grouping_reset = grouping_reset_average;
            r->internal.grouping_free  = grouping_free_average;
            r->internal.grouping_add   = grouping_add_average;
            r->internal.grouping_flush = grouping_flush_average;
        }
    }

    // allocate any memory required by the grouping method
    r->internal.grouping_data = r->internal.grouping_create(r);


    // -------------------------------------------------------------------------
    // disable the not-wanted dimensions

    rrdset_check_rdlock(st);

    if(dimensions)
        rrdr_disable_not_selected_dimensions(r, options, dimensions);


    // -------------------------------------------------------------------------
    // do the work for each dimension

    time_t max_after = 0, min_before = 0;
    long max_rows = 0;

    RRDDIM *rd;
    long c, dimensions_used = 0, dimensions_nonzero = 0;
    for(rd = st->dimensions, c = 0 ; rd && c < dimensions_count ; rd = rd->next, c++) {

        // if we need a percentage, we need to calculate all dimensions
        if(unlikely(!(options & RRDR_OPTION_PERCENTAGE) && (r->od[c] & RRDR_DIMENSION_HIDDEN))) {
            if(unlikely(r->od[c] & RRDR_DIMENSION_SELECTED)) r->od[c] &= ~RRDR_DIMENSION_SELECTED;
            continue;
        }
        r->od[c] |= RRDR_DIMENSION_SELECTED;

        // reset the grouping for the new dimension
        r->internal.grouping_reset(r);

        do_dimension(
                r
                , points_wanted
                , rd
                , c
                , after_slot
                , before_slot
                , after_wanted
                , before_wanted
                );

        if(r->od[c] & RRDR_DIMENSION_NONZERO)
            dimensions_nonzero++;

        // verify all dimensions are aligned
        if(unlikely(!dimensions_used)) {
            min_before = r->before;
            max_after = r->after;
            max_rows = r->rows;
        }
        else {
            if(r->after != max_after) {
                #ifdef NETDATA_INTERNAL_CHECKS
                error("INTERNAL ERROR: 'after' mismatch between dimensions for chart '%s': max is %zu, dimension '%s' has %zu",
                        st->name, (size_t)max_after, rd->name, (size_t)r->after);
                #endif
                r->after = (r->after > max_after) ? r->after : max_after;
            }

            if(r->before != min_before) {
                #ifdef NETDATA_INTERNAL_CHECKS
                error("INTERNAL ERROR: 'before' mismatch between dimensions for chart '%s': max is %zu, dimension '%s' has %zu",
                        st->name, (size_t)min_before, rd->name, (size_t)r->before);
                #endif
                r->before = (r->before < min_before) ? r->before : min_before;
            }

            if(r->rows != max_rows) {
                #ifdef NETDATA_INTERNAL_CHECKS
                error("INTERNAL ERROR: 'rows' mismatch between dimensions for chart '%s': max is %zu, dimension '%s' has %zu",
                        st->name, (size_t)max_rows, rd->name, (size_t)r->rows);
                #endif
                r->rows = (r->rows > max_rows) ? r->rows : max_rows;
            }
        }

        dimensions_used++;
    }

    #ifdef NETDATA_INTERNAL_CHECKS

    if(r->internal.log)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, r->internal.log);

    if(r->rows != points_wanted)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "got 'points' is not wanted 'points'");

    if(aligned && (r->before % group) != 0)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "'before' is not aligned but alignment is required");

    // 'after' should not be aligned, since we start inside the first group
    //if(aligned && (r->after % group) != 0)
    //    rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "'after' is not aligned but alignment is required");

    if(r->before != before_requested)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "chart is not aligned to requested 'before'");

    if(r->before != before_wanted)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "got 'before' is not wanted 'before'");

    // reported 'after' varies, depending on group
    if(r->after != after_wanted)
        rrd2rrdr_log_request_response_metdata(r, group_method, aligned, group, resampling_time_requested, resampling_group, after_wanted, after_requested, before_wanted, before_requested, points_requested, points_wanted, after_slot, before_slot, "got 'after' is not wanted 'after'");

    #endif

    // free all resources used by the grouping method
    r->internal.grouping_free(r);

    // when all the dimensions are zero, we should return all of them
    if(unlikely(options & RRDR_OPTION_NONZERO && !dimensions_nonzero)) {
        // all the dimensions are zero
        // mark them as NONZERO to send them all
        for(rd = st->dimensions, c = 0 ; rd && c < dimensions_count ; rd = rd->next, c++) {
            if(unlikely(r->od[c] & RRDR_DIMENSION_HIDDEN)) continue;
            r->od[c] |= RRDR_DIMENSION_NONZERO;
        }
    }

    rrdr_query_completed(r->internal.db_points_read, r->internal.result_points_generated);
    return r;
}

