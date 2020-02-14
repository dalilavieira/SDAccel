#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct TYPE_20__ {scalar_t__ runtime; int remove; int status; size_t restore_timer; size_t remove_timer; size_t status_timer; scalar_t__ stdin_timeout_abort; scalar_t__ hwmon_temp_abort; } ;
typedef  TYPE_1__ user_options_t ;
typedef  size_t u32 ;
typedef  scalar_t__ time_t ;
struct TYPE_21__ {double msec_paused; scalar_t__ devices_status; scalar_t__ runtime_start; int shutdown_inner; scalar_t__ stdin_read_timeout_cnt; int /*<<< orphan*/  mux_hwmon; int /*<<< orphan*/  mux_display; int /*<<< orphan*/  timer_paused; } ;
typedef  TYPE_2__ status_ctx_t ;
struct TYPE_22__ {int enabled; } ;
typedef  TYPE_3__ restore_ctx_t ;
struct TYPE_23__ {size_t devices_cnt; TYPE_6__* devices_param; } ;
typedef  TYPE_4__ opencl_ctx_t ;
struct TYPE_24__ {int enabled; } ;
typedef  TYPE_5__ hwmon_ctx_t ;
struct TYPE_25__ {int skipped; int device_type; int skipped_warning; } ;
typedef  TYPE_6__ hc_device_param_t ;
struct TYPE_26__ {scalar_t__ hashlist_mode; scalar_t__ digests_saved; scalar_t__ digests_done; } ;
typedef  TYPE_7__ hashes_t ;
struct TYPE_27__ {TYPE_1__* user_options; TYPE_2__* status_ctx; TYPE_3__* restore_ctx; TYPE_4__* opencl_ctx; TYPE_5__* hwmon_ctx; TYPE_7__* hashes; } ;
typedef  TYPE_8__ hashcat_ctx_t ;

/* Variables and functions */
 int CL_DEVICE_TYPE_GPU ; 
 int /*<<< orphan*/  EVENT_DATA (int /*<<< orphan*/ ,size_t*,int) ; 
 int /*<<< orphan*/  EVENT_MONITOR_NOINPUT_ABORT ; 
 int /*<<< orphan*/  EVENT_MONITOR_NOINPUT_HINT ; 
 int /*<<< orphan*/  EVENT_MONITOR_PERFORMANCE_HINT ; 
 int /*<<< orphan*/  EVENT_MONITOR_RUNTIME_LIMIT ; 
 int /*<<< orphan*/  EVENT_MONITOR_STATUS_REFRESH ; 
 int /*<<< orphan*/  EVENT_MONITOR_TEMP_ABORT ; 
 int /*<<< orphan*/  EVENT_MONITOR_THROTTLE1 ; 
 int /*<<< orphan*/  EVENT_MONITOR_THROTTLE2 ; 
 int /*<<< orphan*/  EVENT_MONITOR_THROTTLE3 ; 
 scalar_t__ HL_MODE_FILE_BINARY ; 
 scalar_t__ HL_MODE_FILE_PLAIN ; 
 scalar_t__ STATUS_INIT ; 
 scalar_t__ STATUS_PAUSED ; 
 int STDIN_TIMEOUT_WARN ; 
 int cycle_restore (TYPE_8__*) ; 
 int /*<<< orphan*/  hc_thread_mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hc_thread_mutex_unlock (int /*<<< orphan*/ ) ; 
 double hc_timer_get (int /*<<< orphan*/ ) ; 
 int hm_get_temperature_with_device_id (TYPE_8__*,size_t) ; 
 int hm_get_throttle_with_device_id (TYPE_8__*,size_t) ; 
 int hm_get_utilization_with_device_id (TYPE_8__*,size_t) ; 
 int /*<<< orphan*/  myabort (TYPE_8__*) ; 
 int /*<<< orphan*/  myabort_runtime (TYPE_8__*) ; 
 int save_hash (TYPE_8__*) ; 
 int /*<<< orphan*/  sleep (int const) ; 
 double status_get_exec_msec_dev (TYPE_8__*,size_t) ; 
 scalar_t__ status_get_progress_done (TYPE_8__*) ; 
 int /*<<< orphan*/  time (scalar_t__*) ; 

int get_runtime_left (const hashcat_ctx_t *hashcat_ctx)
{
  const status_ctx_t   *status_ctx   = hashcat_ctx->status_ctx;
  const user_options_t *user_options = hashcat_ctx->user_options;

  double msec_paused = status_ctx->msec_paused;

  if (status_ctx->devices_status == STATUS_PAUSED)
  {
    double msec_paused_tmp = hc_timer_get (status_ctx->timer_paused);

    msec_paused += msec_paused_tmp;
  }

  time_t runtime_cur;

  time (&runtime_cur);

  const int runtime_left = (int) (status_ctx->runtime_start
                                + user_options->runtime
                                + (msec_paused / 1000)
                                - runtime_cur);

  return runtime_left;
}

__attribute__((used)) static int monitor (hashcat_ctx_t *hashcat_ctx)
{
  hashes_t       *hashes        = hashcat_ctx->hashes;
  hwmon_ctx_t    *hwmon_ctx     = hashcat_ctx->hwmon_ctx;
  opencl_ctx_t   *opencl_ctx    = hashcat_ctx->opencl_ctx;
  restore_ctx_t  *restore_ctx   = hashcat_ctx->restore_ctx;
  status_ctx_t   *status_ctx    = hashcat_ctx->status_ctx;
  user_options_t *user_options  = hashcat_ctx->user_options;

  bool runtime_check      = false;
  bool remove_check       = false;
  bool status_check       = false;
  bool restore_check      = false;
  bool hwmon_check        = false;
  bool performance_check  = false;

  const int    sleep_time = 1;
  const double exec_low   = 50.0;  // in ms
  const double util_low   = 90.0;  // in percent

  if (user_options->runtime)
  {
    runtime_check = true;
  }

  if (restore_ctx->enabled == true)
  {
    restore_check = true;
  }

  if ((user_options->remove == true) && ((hashes->hashlist_mode == HL_MODE_FILE_PLAIN) || (hashes->hashlist_mode == HL_MODE_FILE_BINARY)))
  {
    remove_check = true;
  }

  if (user_options->status == true)
  {
    status_check = true;
  }

  if (hwmon_ctx->enabled == true)
  {
    hwmon_check = true;
  }

  if (hwmon_ctx->enabled == true)
  {
    performance_check = true; // this check simply requires hwmon to work
  }

  if ((runtime_check == false) && (remove_check == false) && (status_check == false) && (restore_check == false) && (hwmon_check == false) && (performance_check == false))
  {
    return 0;
  }

  // timer

  u32 slowdown_warnings    = 0;
  u32 performance_warnings = 0;

  u32 restore_left  = user_options->restore_timer;
  u32 remove_left   = user_options->remove_timer;
  u32 status_left   = user_options->status_timer;

  while (status_ctx->shutdown_inner == false)
  {
    sleep (sleep_time);

    if (status_ctx->devices_status == STATUS_INIT) continue;

    if (hwmon_ctx->enabled == true)
    {
      hc_thread_mutex_lock (status_ctx->mux_hwmon);

      for (u32 device_id = 0; device_id < opencl_ctx->devices_cnt; device_id++)
      {
        hc_device_param_t *device_param = &opencl_ctx->devices_param[device_id];

        if (device_param->skipped == true) continue;

        if ((opencl_ctx->devices_param[device_id].device_type & CL_DEVICE_TYPE_GPU) == 0) continue;

        const int temperature = hm_get_temperature_with_device_id (hashcat_ctx, device_id);

        if (temperature > (int) user_options->hwmon_temp_abort)
        {
          EVENT_DATA (EVENT_MONITOR_TEMP_ABORT, &device_id, sizeof (u32));

          myabort (hashcat_ctx);
        }
      }

      for (u32 device_id = 0; device_id < opencl_ctx->devices_cnt; device_id++)
      {
        hc_device_param_t *device_param = &opencl_ctx->devices_param[device_id];

        if (device_param->skipped == true) continue;

        if (device_param->skipped_warning == true) continue;

        const int rc_throttle = hm_get_throttle_with_device_id (hashcat_ctx, device_id);

        if (rc_throttle == -1) continue;

        if (rc_throttle > 0)
        {
          slowdown_warnings++;

          if (slowdown_warnings == 1) EVENT_DATA (EVENT_MONITOR_THROTTLE1, &device_id, sizeof (u32));
          if (slowdown_warnings == 2) EVENT_DATA (EVENT_MONITOR_THROTTLE2, &device_id, sizeof (u32));
          if (slowdown_warnings == 3) EVENT_DATA (EVENT_MONITOR_THROTTLE3, &device_id, sizeof (u32));
        }
        else
        {
          if (slowdown_warnings > 0) slowdown_warnings--;
        }
      }

      hc_thread_mutex_unlock (status_ctx->mux_hwmon);
    }

    if (restore_check == true)
    {
      restore_left--;

      if (restore_left == 0)
      {
        const int rc = cycle_restore (hashcat_ctx);

        if (rc == -1) return -1;

        restore_left = user_options->restore_timer;
      }
    }

    if ((runtime_check == true) && (status_ctx->runtime_start > 0))
    {
      const int runtime_left = get_runtime_left (hashcat_ctx);

      if (runtime_left <= 0)
      {
        EVENT_DATA (EVENT_MONITOR_RUNTIME_LIMIT, NULL, 0);

        myabort_runtime (hashcat_ctx);
      }
    }

    if (remove_check == true)
    {
      remove_left--;

      if (remove_left == 0)
      {
        if (hashes->digests_saved != hashes->digests_done)
        {
          hashes->digests_saved = hashes->digests_done;

          const int rc = save_hash (hashcat_ctx);

          if (rc == -1) return -1;
        }

        remove_left = user_options->remove_timer;
      }
    }

    if (status_check == true)
    {
      status_left--;

      if (status_left == 0)
      {
        hc_thread_mutex_lock (status_ctx->mux_display);

        EVENT_DATA (EVENT_MONITOR_STATUS_REFRESH, NULL, 0);

        hc_thread_mutex_unlock (status_ctx->mux_display);

        status_left = user_options->status_timer;
      }
    }

    if (performance_check == true)
    {
      int exec_cnt = 0;
      int util_cnt = 0;

      double exec_total = 0;
      double util_total = 0;

      hc_thread_mutex_lock (status_ctx->mux_hwmon);

      for (u32 device_id = 0; device_id < opencl_ctx->devices_cnt; device_id++)
      {
        hc_device_param_t *device_param = &opencl_ctx->devices_param[device_id];

        if (device_param->skipped == true) continue;

        if (device_param->skipped_warning == true) continue;

        exec_cnt++;

        const double exec = status_get_exec_msec_dev (hashcat_ctx, device_id);

        exec_total += exec;

        const int util = hm_get_utilization_with_device_id (hashcat_ctx, device_id);

        if (util == -1) continue;

        util_total += (double) util;

        util_cnt++;
      }

      hc_thread_mutex_unlock (status_ctx->mux_hwmon);

      double exec_avg = 0;
      double util_avg = 0;

      if (exec_cnt > 0) exec_avg = exec_total / exec_cnt;
      if (util_cnt > 0) util_avg = util_total / util_cnt;

      if ((exec_avg > 0) && (exec_avg < exec_low))
      {
        performance_warnings++;

        if (performance_warnings == 10) EVENT_DATA (EVENT_MONITOR_PERFORMANCE_HINT, NULL, 0);
      }

      if ((util_avg > 0) && (util_avg < util_low))
      {
        performance_warnings++;

        if (performance_warnings == 10) EVENT_DATA (EVENT_MONITOR_PERFORMANCE_HINT, NULL, 0);
      }
    }

    // stdin read timeout check
    // note: we skip the stdin timeout check if it was disabled with stdin_timeout_abort set to 0

    if (user_options->stdin_timeout_abort != 0)
    {
      if (status_get_progress_done (hashcat_ctx) == 0)
      {
        if (status_ctx->stdin_read_timeout_cnt > 0)
        {
          if (status_ctx->stdin_read_timeout_cnt >= user_options->stdin_timeout_abort)
          {
            EVENT_DATA (EVENT_MONITOR_NOINPUT_ABORT, NULL, 0);

            myabort (hashcat_ctx);

            status_ctx->shutdown_inner = true;

            break;
          }

          if ((status_ctx->stdin_read_timeout_cnt % STDIN_TIMEOUT_WARN) == 0)
          {
            EVENT_DATA (EVENT_MONITOR_NOINPUT_HINT, NULL, 0);
          }
        }
      }
    }
  }

  // final round of save_hash

  if (remove_check == true)
  {
    if (hashes->digests_saved != hashes->digests_done)
    {
      const int rc = save_hash (hashcat_ctx);

      if (rc == -1) return -1;
    }
  }

  // final round of cycle_restore

  if (restore_check == true)
  {
    const int rc = cycle_restore (hashcat_ctx);

    if (rc == -1) return -1;
  }

  return 0;
}

