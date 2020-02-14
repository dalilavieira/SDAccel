#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ time_t ;
struct timeval {scalar_t__ tv_usec; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_10__ {int /*<<< orphan*/  kernel_module; } ;
typedef  TYPE_1__ mrb_state ;
typedef  scalar_t__ mrb_int ;
typedef  int mrb_float ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_value (scalar_t__) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ time (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep (scalar_t__) ; 

__attribute__((used)) static mrb_value
mrb_f_sleep(mrb_state *mrb, mrb_value self)
{
    time_t beg = time(0);
    time_t end;
#ifndef MRB_WITHOUT_FLOAT
    mrb_float sec;

    mrb_get_args(mrb, "f", &sec);
    if (sec >= 0) {
        usleep(sec * 1000000);
    }
    else {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "time interval must not be negative");
    }
#else
    mrb_int sec;

    mrb_get_args(mrb, "i", &sec);
    if (sec >= 0) {
        sleep(sec);
    } else {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "time interval must not be negative");
    }
#endif
    end = time(0) - beg;

    return mrb_fixnum_value(end);
}

__attribute__((used)) static mrb_value
mrb_f_usleep(mrb_state *mrb, mrb_value self)
{
    mrb_int usec;
#ifdef _WIN32
    FILETIME st_ft,ed_ft;
    unsigned __int64 st_time = 0;
    unsigned __int64 ed_time = 0;
#else
    struct timeval st_tm,ed_tm;
#endif
    time_t slp_tm;

#ifdef _WIN32
    GetSystemTimeAsFileTime(&st_ft);
#else
    gettimeofday(&st_tm, NULL);
#endif

    /* not implemented forever sleep (called without an argument)*/
    mrb_get_args(mrb, "i", &usec);

    if (usec >= 0) {
        usleep(usec);
    } else {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "time interval must not be negative integer");
    }

#ifdef _WIN32
    GetSystemTimeAsFileTime(&ed_ft);

    st_time |= st_ft.dwHighDateTime;
    st_time <<=32;
    st_time |= st_ft.dwLowDateTime;
    ed_time |= ed_ft.dwHighDateTime;
    ed_time <<=32;
    ed_time |= ed_ft.dwLowDateTime;

    slp_tm = (ed_time - st_time) / 10;
#else
    gettimeofday(&ed_tm, NULL);

    if (st_tm.tv_usec > ed_tm.tv_usec) {
        slp_tm = 1000000 + ed_tm.tv_usec - st_tm.tv_usec;
    }
    else {
        slp_tm = ed_tm.tv_usec - st_tm.tv_usec;
    }
#endif

    return mrb_fixnum_value(slp_tm);
}

void
mrb_mruby_sleep_gem_init(mrb_state *mrb)
{
    mrb_define_method(mrb, mrb->kernel_module, "sleep",   mrb_f_sleep,   MRB_ARGS_REQ(1));
    mrb_define_method(mrb, mrb->kernel_module, "usleep",  mrb_f_usleep,  MRB_ARGS_REQ(1));
}

void
mrb_mruby_sleep_gem_final(mrb_state *mrb)
{
}

