#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
struct TYPE_13__ {size_t used; } ;
typedef  TYPE_1__ mp_map_t ;
struct TYPE_14__ {int /*<<< orphan*/  value; } ;
typedef  TYPE_2__ mp_map_elem_t ;
struct TYPE_15__ {int /*<<< orphan*/  u_obj; int /*<<< orphan*/  u_int; int /*<<< orphan*/  u_bool; } ;
typedef  TYPE_3__ mp_arg_val_t ;
struct TYPE_16__ {int flags; size_t qst; TYPE_3__ defval; } ;
typedef  TYPE_4__ mp_arg_t ;

/* Variables and functions */
 scalar_t__ MICROPY_ERROR_REPORTING ; 
 scalar_t__ MICROPY_ERROR_REPORTING_TERSE ; 
 int MP_ARG_BOOL ; 
 int MP_ARG_INT ; 
 int MP_ARG_KIND_MASK ; 
 int MP_ARG_KW_ONLY ; 
 int MP_ARG_OBJ ; 
 int MP_ARG_REQUIRED ; 
 int /*<<< orphan*/  MP_MAP_LOOKUP ; 
 int /*<<< orphan*/  MP_OBJ_NEW_QSTR (size_t) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  mp_arg_error_terse_mismatch () ; 
 int /*<<< orphan*/  mp_map_init_fixed_table (TYPE_1__*,size_t,int /*<<< orphan*/  const*) ; 
 TYPE_2__* mp_map_lookup (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_get_int (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_is_true (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_new_exception_msg_varg (int /*<<< orphan*/ *,char*,size_t,...) ; 
 int /*<<< orphan*/  mp_raise_TypeError (char*) ; 
 int /*<<< orphan*/  mp_type_TypeError ; 
 int /*<<< orphan*/  nlr_raise (int /*<<< orphan*/ ) ; 

void mp_arg_check_num_sig(size_t n_args, size_t n_kw, uint32_t sig) {
    // TODO maybe take the function name as an argument so we can print nicer error messages

    // The reverse of MP_OBJ_FUN_MAKE_SIG
    bool takes_kw = sig & 1;
    size_t n_args_min = sig >> 17;
    size_t n_args_max = (sig >> 1) & 0xffff;

    if (n_kw && !takes_kw) {
        if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
            mp_arg_error_terse_mismatch();
        } else {
            mp_raise_TypeError("function doesn't take keyword arguments");
        }
    }

    if (n_args_min == n_args_max) {
        if (n_args != n_args_min) {
            if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
                mp_arg_error_terse_mismatch();
            } else {
                nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_TypeError,
                    "function takes %d positional arguments but %d were given",
                    n_args_min, n_args));
            }
        }
    } else {
        if (n_args < n_args_min) {
            if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
                mp_arg_error_terse_mismatch();
            } else {
                nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_TypeError,
                    "function missing %d required positional arguments",
                    n_args_min - n_args));
            }
        } else if (n_args > n_args_max) {
            if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
                mp_arg_error_terse_mismatch();
            } else {
                nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_TypeError,
                    "function expected at most %d arguments, got %d",
                    n_args_max, n_args));
            }
        }
    }
}

void mp_arg_parse_all(size_t n_pos, const mp_obj_t *pos, mp_map_t *kws, size_t n_allowed, const mp_arg_t *allowed, mp_arg_val_t *out_vals) {
    size_t pos_found = 0, kws_found = 0;
    for (size_t i = 0; i < n_allowed; i++) {
        mp_obj_t given_arg;
        if (i < n_pos) {
            if (allowed[i].flags & MP_ARG_KW_ONLY) {
                goto extra_positional;
            }
            pos_found++;
            given_arg = pos[i];
        } else {
            mp_map_elem_t *kw = mp_map_lookup(kws, MP_OBJ_NEW_QSTR(allowed[i].qst), MP_MAP_LOOKUP);
            if (kw == NULL) {
                if (allowed[i].flags & MP_ARG_REQUIRED) {
                    if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
                        mp_arg_error_terse_mismatch();
                    } else {
                        nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_TypeError,
                            "'%q' argument required", allowed[i].qst));
                    }
                }
                out_vals[i] = allowed[i].defval;
                continue;
            } else {
                kws_found++;
                given_arg = kw->value;
            }
        }
        if ((allowed[i].flags & MP_ARG_KIND_MASK) == MP_ARG_BOOL) {
            out_vals[i].u_bool = mp_obj_is_true(given_arg);
        } else if ((allowed[i].flags & MP_ARG_KIND_MASK) == MP_ARG_INT) {
            out_vals[i].u_int = mp_obj_get_int(given_arg);
        } else {
            assert((allowed[i].flags & MP_ARG_KIND_MASK) == MP_ARG_OBJ);
            out_vals[i].u_obj = given_arg;
        }
    }
    if (pos_found < n_pos) {
        extra_positional:
        if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
            mp_arg_error_terse_mismatch();
        } else {
            // TODO better error message
            mp_raise_TypeError("extra positional arguments given");
        }
    }
    if (kws_found < kws->used) {
        if (MICROPY_ERROR_REPORTING == MICROPY_ERROR_REPORTING_TERSE) {
            mp_arg_error_terse_mismatch();
        } else {
            // TODO better error message
            mp_raise_TypeError("extra keyword arguments given");
        }
    }
}

void mp_arg_parse_all_kw_array(size_t n_pos, size_t n_kw, const mp_obj_t *args, size_t n_allowed, const mp_arg_t *allowed, mp_arg_val_t *out_vals) {
    mp_map_t kw_args;
    mp_map_init_fixed_table(&kw_args, n_kw, args + n_pos);
    mp_arg_parse_all(n_pos, args, &kw_args, n_allowed, allowed, out_vals);
}

