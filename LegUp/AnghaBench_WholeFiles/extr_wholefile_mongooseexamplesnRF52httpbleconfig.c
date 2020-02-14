#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  list_of_clients ;
struct TYPE_14__ {void (* ipv6_medium_evt_handler ) (TYPE_2__*) ;void (* ipv6_medium_error_handler ) (int /*<<< orphan*/ *) ;int use_scheduler; } ;
typedef  TYPE_1__ ipv6_medium_init_params_t ;
typedef  int /*<<< orphan*/  ipv6_medium_init_params ;
struct TYPE_15__ {int ipv6_medium_evt_id; } ;
typedef  TYPE_2__ ipv6_medium_evt_t ;
typedef  int /*<<< orphan*/  ipv6_medium_error_t ;
typedef  void* iot_timer_time_in_ms_t ;
struct TYPE_16__ {int member_0; TYPE_4__ const* member_1; } ;
typedef  TYPE_3__ iot_timer_clients_list_t ;
struct TYPE_17__ {void (* member_0 ) (void*) ;int /*<<< orphan*/  member_1; } ;
typedef  TYPE_4__ iot_timer_client_t ;
struct TYPE_18__ {int* identifier; } ;
typedef  TYPE_5__ eui48_t ;
struct TYPE_19__ {int /*<<< orphan*/  ipv6_medium_instance_id; } ;

/* Variables and functions */
 int ALL_APP_LED ; 
 int /*<<< orphan*/  APPL_LOG (char*) ; 
 int /*<<< orphan*/  APP_ERROR_CHECK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  APP_SCHED_INIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  APP_TIMER_INIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  APP_TIMER_MODE_REPEATED ; 
 int /*<<< orphan*/  APP_TIMER_OP_QUEUE_SIZE ; 
 int /*<<< orphan*/  APP_TIMER_PRESCALER ; 
 int /*<<< orphan*/  APP_TIMER_TICKS (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int DISPLAY_LED_0 ; 
 int DISPLAY_LED_1 ; 
 int DISPLAY_LED_2 ; 
 int DISPLAY_LED_3 ; 
 int EUI_48_SIZE ; 
 int /*<<< orphan*/  IOT_TIMER_RESOLUTION_IN_MS ; 
#define  IPV6_MEDIUM_EVT_CONN_DOWN 130 
#define  IPV6_MEDIUM_EVT_CONN_UP 129 
 int /*<<< orphan*/  IPV6_MEDIUM_ID_BLE ; 
 int /*<<< orphan*/  LEDS_CONFIGURE (int) ; 
 int /*<<< orphan*/  LEDS_OFF (int) ; 
 int /*<<< orphan*/  LEDS_ON (int) ; 
 int LED_ONE ; 
 int LED_TWO ; 
#define  LWIP_SYS_TICK_MS 128 
 int /*<<< orphan*/  SCHED_MAX_EVENT_DATA_SIZE ; 
 int /*<<< orphan*/  SCHED_QUEUE_SIZE ; 
 int /*<<< orphan*/  TCP_STATE_DISCONNECTED ; 
 int /*<<< orphan*/  TCP_STATE_REQUEST_CONNECTION ; 
 int /*<<< orphan*/  UNUSED_VARIABLE (void*) ; 
 int /*<<< orphan*/  app_sched_execute () ; 
 int /*<<< orphan*/  app_timer_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void (*) (void*)) ; 
 int /*<<< orphan*/  app_timer_start (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  app_trace_init () ; 
 int /*<<< orphan*/  eui64_local_iid ; 
 int /*<<< orphan*/  iot_timer_client_list_set (TYPE_3__ const*) ; 
 int /*<<< orphan*/  iot_timer_update () ; 
 int /*<<< orphan*/  ipv6_medium_connectable_mode_enter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipv6_medium_eui48_get (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  ipv6_medium_eui48_set (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  ipv6_medium_eui64_get (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ipv6_medium_init (TYPE_1__*,int /*<<< orphan*/ ,TYPE_8__*) ; 
 int /*<<< orphan*/  lwip_init () ; 
 int /*<<< orphan*/  m_iot_timer_tick_src_id ; 
 TYPE_8__ m_ipv6_medium ; 
 int /*<<< orphan*/  m_tcp_state ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  nrf_driver_init () ; 
 int /*<<< orphan*/  nrf_mem_init () ; 
 int /*<<< orphan*/  sys_check_timeouts () ; 

void nrf_driver_interface_up(void)
{
#ifdef COMMISSIONING_ENABLED
  commissioning_joining_mode_timer_ctrl(JOINING_MODE_TIMER_STOP_RESET);
#endif // COMMISSIONING_ENABLED

  APPL_LOG ("[APPL]: IPv6 interface up.\r\n");

  sys_check_timeouts();

  m_tcp_state = TCP_STATE_REQUEST_CONNECTION;

  LEDS_OFF(LED_ONE);
  LEDS_ON(LED_TWO);
}

void nrf_driver_interface_down(void)
{
#ifdef COMMISSIONING_ENABLED
  commissioning_joining_mode_timer_ctrl(JOINING_MODE_TIMER_START);
#endif // COMMISSIONING_ENABLED

  APPL_LOG ("[APPL]: IPv6 interface down.\r\n");

  LEDS_OFF((DISPLAY_LED_0 | DISPLAY_LED_1 | DISPLAY_LED_2 | DISPLAY_LED_3));
  LEDS_ON(LED_ONE);

  m_tcp_state = TCP_STATE_DISCONNECTED;
}

__attribute__((used)) static void system_timer_callback(iot_timer_time_in_ms_t wall_clock_value)
{
  UNUSED_VARIABLE(wall_clock_value);
  sys_check_timeouts();
}

__attribute__((used)) static void connectable_mode_enter(void)
{
  uint32_t err_code = ipv6_medium_connectable_mode_enter(m_ipv6_medium.ipv6_medium_instance_id);
  APP_ERROR_CHECK(err_code);

  APPL_LOG("[APPL]: Physical layer in connectable mode.\r\n");
  LEDS_OFF(LED_TWO);
  LEDS_ON(LED_ONE);
}

__attribute__((used)) static void iot_timer_tick_callback(void * p_context)
{
  UNUSED_VARIABLE(p_context);

  uint32_t err_code = iot_timer_update();
  APP_ERROR_CHECK(err_code);
}

__attribute__((used)) static void leds_init(void)
{
  // Configure application LED pins.
  LEDS_CONFIGURE(ALL_APP_LED);

  // Turn off all LED on initialization.
  LEDS_OFF(ALL_APP_LED);
}

__attribute__((used)) static void timers_init(void)
{
  uint32_t err_code;

  // Initialize timer module.
  APP_TIMER_INIT(APP_TIMER_PRESCALER, APP_TIMER_OP_QUEUE_SIZE, false);

  // Create a sys timer.
  err_code = app_timer_create(&m_iot_timer_tick_src_id,
      APP_TIMER_MODE_REPEATED,
      iot_timer_tick_callback);
  APP_ERROR_CHECK(err_code);
}

__attribute__((used)) static void iot_timer_init(void)
{
  uint32_t err_code;

  static const iot_timer_client_t list_of_clients[] =
  {
    {system_timer_callback,   LWIP_SYS_TICK_MS},
#ifdef COMMISSIONING_ENABLED
    {blink_timeout_handler,   LED_BLINK_INTERVAL_MS},
    {commissioning_time_tick, SEC_TO_MILLISEC(COMMISSIONING_TICK_INTERVAL_SEC)}
#endif // COMMISSIONING_ENABLED
  };

  // The list of IoT Timer clients is declared as a constant.
  static const iot_timer_clients_list_t iot_timer_clients =
  {
    (sizeof(list_of_clients) / sizeof(iot_timer_client_t)),
    &(list_of_clients[0]),
  };

  // Passing the list of clients to the IoT Timer module.
  err_code = iot_timer_client_list_set(&iot_timer_clients);
  APP_ERROR_CHECK(err_code);

  // Starting the app timer instance that is the tick source for the IoT Timer.
  err_code = app_timer_start(m_iot_timer_tick_src_id, \
      APP_TIMER_TICKS(IOT_TIMER_RESOLUTION_IN_MS, APP_TIMER_PRESCALER), \
      NULL);
  APP_ERROR_CHECK(err_code);
}

__attribute__((used)) static void ip_stack_init(void)
{
  uint32_t err_code;

  err_code = ipv6_medium_eui64_get(m_ipv6_medium.ipv6_medium_instance_id, \
      &eui64_local_iid);
  APP_ERROR_CHECK(err_code);

  err_code = nrf_mem_init();
  APP_ERROR_CHECK(err_code);

  //Initialize LwIP stack.
  lwip_init();

  //Initialize LwIP stack driver.
  err_code = nrf_driver_init();
  APP_ERROR_CHECK(err_code);
}

__attribute__((used)) static void scheduler_init(void)
{
  APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);
}

__attribute__((used)) static void on_ipv6_medium_evt(ipv6_medium_evt_t * p_ipv6_medium_evt)
{
  switch (p_ipv6_medium_evt->ipv6_medium_evt_id)
  {
    case IPV6_MEDIUM_EVT_CONN_UP:
      {
        APPL_LOG("[APPL]: Physical layer: connected.\r\n");
        LEDS_OFF(LED_ONE);
        LEDS_ON(LED_TWO);
        break;
      }
    case IPV6_MEDIUM_EVT_CONN_DOWN:
      {
        APPL_LOG("[APPL]: Physical layer: disconnected.\r\n");
        connectable_mode_enter();
        break;
      }
    default:
      {
        break;
      }
  }
}

__attribute__((used)) static void on_ipv6_medium_error(ipv6_medium_error_t * p_ipv6_medium_error)
{
  // Do something.
}

void bleconfig_init(void) {
  uint32_t err_code;

  //Initialize.
  app_trace_init();
  leds_init();
  timers_init();
  iot_timer_init();

#ifdef COMMISSIONING_ENABLED
  err_code = pstorage_init();
  APP_ERROR_CHECK(err_code);

  buttons_init();
#endif // COMMISSIONING_ENABLED

  static ipv6_medium_init_params_t ipv6_medium_init_params;
  memset(&ipv6_medium_init_params, 0x00, sizeof(ipv6_medium_init_params));
  ipv6_medium_init_params.ipv6_medium_evt_handler    = on_ipv6_medium_evt;
  ipv6_medium_init_params.ipv6_medium_error_handler  = on_ipv6_medium_error;
  ipv6_medium_init_params.use_scheduler              = true;
#ifdef COMMISSIONING_ENABLED
  ipv6_medium_init_params.commissioning_id_mode_cb   = commissioning_id_mode_cb;
  ipv6_medium_init_params.commissioning_power_off_cb = commissioning_power_off_cb;
#endif // COMMISSIONING_ENABLED

  err_code = ipv6_medium_init(&ipv6_medium_init_params, \
      IPV6_MEDIUM_ID_BLE,       \
      &m_ipv6_medium);
  APP_ERROR_CHECK(err_code);

  eui48_t ipv6_medium_eui48;
  err_code = ipv6_medium_eui48_get(m_ipv6_medium.ipv6_medium_instance_id, \
      &ipv6_medium_eui48);

  ipv6_medium_eui48.identifier[EUI_48_SIZE - 1] = 0x00;

  err_code = ipv6_medium_eui48_set(m_ipv6_medium.ipv6_medium_instance_id, \
      &ipv6_medium_eui48);
  APP_ERROR_CHECK(err_code);

  ip_stack_init();
  scheduler_init();

  //Start execution.
  connectable_mode_enter();

  APPL_LOG("BLE init done\n");
}

void bleconfig_poll(void) {
  //Execute event schedule.
  app_sched_execute();
  sys_check_timeouts();
}

