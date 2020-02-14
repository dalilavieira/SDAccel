#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int min; int max; } ;
struct TYPE_13__ {int min; int max; } ;
struct TYPE_12__ {int min; int max; } ;
struct TYPE_11__ {int min; int max; } ;
struct TYPE_10__ {int min; int max; } ;
struct TYPE_9__ {int CNT; } ;
struct TYPE_8__ {int min; int max; } ;

/* Variables and functions */
 scalar_t__ angle_control ; 
 int bosch_hardware ; 
 int brake_prev ; 
 int* cadillac_desired_torque_last ; 
 int cadillac_rt_torque_last ; 
 TYPE_7__ cadillac_torque_driver ; 
 scalar_t__ cadillac_ts_last ; 
 int chrysler_desired_torque_last ; 
 int chrysler_rt_torque_last ; 
 TYPE_6__ chrysler_torque_meas ; 
 scalar_t__ chrysler_ts_last ; 
 int controls_allowed ; 
 int ego_speed ; 
 scalar_t__ gas_interceptor_detected ; 
 int gas_prev ; 
 int gm_desired_torque_last ; 
 int gm_rt_torque_last ; 
 TYPE_5__ gm_torque_driver ; 
 scalar_t__ gm_ts_last ; 
 int honda_alt_brake_msg ; 
 int hyundai_desired_torque_last ; 
 int hyundai_rt_torque_last ; 
 TYPE_4__ hyundai_torque_driver ; 
 scalar_t__ hyundai_ts_last ; 
 int subaru_desired_torque_last ; 
 int subaru_rt_torque_last ; 
 TYPE_3__ subaru_torque_driver ; 
 scalar_t__ subaru_ts_last ; 
 TYPE_2__ timer ; 
 int toyota_desired_torque_last ; 
 int toyota_rt_torque_last ; 
 TYPE_1__ toyota_torque_meas ; 
 scalar_t__ toyota_ts_last ; 

void set_controls_allowed(int c){
  controls_allowed = c;
}

void reset_angle_control(void){
  angle_control = 0;
}

int get_controls_allowed(void){
  return controls_allowed;
}

void set_timer(int t){
  timer.CNT = t;
}

void set_toyota_torque_meas(int min, int max){
  toyota_torque_meas.min = min;
  toyota_torque_meas.max = max;
}

void set_cadillac_torque_driver(int min, int max){
  cadillac_torque_driver.min = min;
  cadillac_torque_driver.max = max;
}

void set_gm_torque_driver(int min, int max){
  gm_torque_driver.min = min;
  gm_torque_driver.max = max;
}

void set_hyundai_torque_driver(int min, int max){
  hyundai_torque_driver.min = min;
  hyundai_torque_driver.max = max;
}

void set_chrysler_torque_meas(int min, int max){
  chrysler_torque_meas.min = min;
  chrysler_torque_meas.max = max;
}

void set_subaru_torque_driver(int min, int max){
  subaru_torque_driver.min = min;
  subaru_torque_driver.max = max;
}

int get_chrysler_torque_meas_min(void){
  return chrysler_torque_meas.min;
}

int get_chrysler_torque_meas_max(void){
  return chrysler_torque_meas.max;
}

int get_toyota_torque_meas_min(void){
  return toyota_torque_meas.min;
}

int get_toyota_torque_meas_max(void){
  return toyota_torque_meas.max;
}

void set_toyota_rt_torque_last(int t){
  toyota_rt_torque_last = t;
}

void set_cadillac_rt_torque_last(int t){
  cadillac_rt_torque_last = t;
}

void set_gm_rt_torque_last(int t){
  gm_rt_torque_last = t;
}

void set_hyundai_rt_torque_last(int t){
  hyundai_rt_torque_last = t;
}

void set_chrysler_rt_torque_last(int t){
  chrysler_rt_torque_last = t;
}

void set_subaru_rt_torque_last(int t){
  subaru_rt_torque_last = t;
}

void set_toyota_desired_torque_last(int t){
  toyota_desired_torque_last = t;
}

void set_cadillac_desired_torque_last(int t){
  for (int i = 0; i < 4; i++) cadillac_desired_torque_last[i] = t;
}

void set_gm_desired_torque_last(int t){
  gm_desired_torque_last = t;
}

void set_hyundai_desired_torque_last(int t){
  hyundai_desired_torque_last = t;
}

void set_chrysler_desired_torque_last(int t){
  chrysler_desired_torque_last = t;
}

void set_subaru_desired_torque_last(int t){
  subaru_desired_torque_last = t;
}

int get_ego_speed(void){
  return ego_speed;
}

int get_brake_prev(void){
  return brake_prev;
}

int get_gas_prev(void){
  return gas_prev;
}

void set_honda_alt_brake_msg(bool c){
  honda_alt_brake_msg = c;
}

void set_bosch_hardware(bool c){
  bosch_hardware = c;
}

void init_tests_toyota(void){
  toyota_torque_meas.min = 0;
  toyota_torque_meas.max = 0;
  toyota_desired_torque_last = 0;
  toyota_rt_torque_last = 0;
  toyota_ts_last = 0;
  set_timer(0);
}

void init_tests_cadillac(void){
  cadillac_torque_driver.min = 0;
  cadillac_torque_driver.max = 0;
  for (int i = 0; i < 4; i++) cadillac_desired_torque_last[i] = 0;
  cadillac_rt_torque_last = 0;
  cadillac_ts_last = 0;
  set_timer(0);
}

void init_tests_gm(void){
  gm_torque_driver.min = 0;
  gm_torque_driver.max = 0;
  gm_desired_torque_last = 0;
  gm_rt_torque_last = 0;
  gm_ts_last = 0;
  set_timer(0);
}

void init_tests_hyundai(void){
  hyundai_torque_driver.min = 0;
  hyundai_torque_driver.max = 0;
  hyundai_desired_torque_last = 0;
  hyundai_rt_torque_last = 0;
  hyundai_ts_last = 0;
  set_timer(0);
}

void init_tests_chrysler(void){
  chrysler_torque_meas.min = 0;
  chrysler_torque_meas.max = 0;
  chrysler_desired_torque_last = 0;
  chrysler_rt_torque_last = 0;
  chrysler_ts_last = 0;
  set_timer(0);
}

void init_tests_subaru(void){
  subaru_torque_driver.min = 0;
  subaru_torque_driver.max = 0;
  subaru_desired_torque_last = 0;
  subaru_rt_torque_last = 0;
  subaru_ts_last = 0;
  set_timer(0);
}

void init_tests_honda(void){
  ego_speed = 0;
  gas_interceptor_detected = 0;
  brake_prev = 0;
  gas_prev = 0;
}

void set_gmlan_digital_output(int to_set){
}

void reset_gmlan_switch_timeout(void){
}

void gmlan_switch_init(int timeout_enable){
}

void lline_relay_init (void) {
}

void lline_relay_release (void) {
}

void set_lline_output(int to_set) {
}

