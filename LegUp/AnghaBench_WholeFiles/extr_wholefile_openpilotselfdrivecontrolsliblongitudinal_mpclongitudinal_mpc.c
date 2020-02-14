#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {double x_l; double v_l; double x_ego; double v_ego; double a_ego; } ;
typedef  TYPE_1__ state_t ;
struct TYPE_7__ {double* x_l; double* v_l; double* a_l; double* t; double* x_ego; double* v_ego; double* a_ego; double* j_ego; int /*<<< orphan*/  cost; } ;
typedef  TYPE_2__ log_t ;
struct TYPE_8__ {double* x; double* u; double* y; double* yN; double* x0; double* W; double* WN; double* od; } ;

/* Variables and functions */
 int N ; 
 int NOD ; 
 int NU ; 
 int NX ; 
 int NY ; 
 int NYN ; 
 TYPE_5__ acadoVariables ; 
 int /*<<< orphan*/  acado_feedbackStep () ; 
 int acado_getNWSR () ; 
 int /*<<< orphan*/  acado_getObjective () ; 
 int /*<<< orphan*/  acado_initializeSolver () ; 
 int /*<<< orphan*/  acado_preparationStep () ; 
 double exp (double) ; 

void init(double ttcCost, double distanceCost, double accelerationCost, double jerkCost){
  acado_initializeSolver();
  int    i;
  const int STEP_MULTIPLIER = 3;

  /* Initialize the states and controls. */
  for (i = 0; i < NX * (N + 1); ++i)  acadoVariables.x[ i ] = 0.0;
  for (i = 0; i < NU * N; ++i)  acadoVariables.u[ i ] = 0.0;

  /* Initialize the measurements/reference. */
  for (i = 0; i < NY * N; ++i)  acadoVariables.y[ i ] = 0.0;
  for (i = 0; i < NYN; ++i)  acadoVariables.yN[ i ] = 0.0;

  /* MPC: initialize the current state feedback. */
  for (i = 0; i < NX; ++i) acadoVariables.x0[ i ] = 0.0;
  // Set weights

  for (i = 0; i < N; i++) {
    int f = 1;
    if (i > 4){
      f = STEP_MULTIPLIER;
    }
    acadoVariables.W[16 * i + 0] = ttcCost * f; // exponential cost for time-to-collision (ttc)
    acadoVariables.W[16 * i + 5] = distanceCost * f; // desired distance
    acadoVariables.W[16 * i + 10] = accelerationCost * f; // acceleration
    acadoVariables.W[16 * i + 15] = jerkCost * f; // jerk
  }
  acadoVariables.WN[0] = ttcCost * STEP_MULTIPLIER; // exponential cost for danger zone
  acadoVariables.WN[4] = distanceCost * STEP_MULTIPLIER; // desired distance
  acadoVariables.WN[8] = accelerationCost * STEP_MULTIPLIER; // acceleration

}

void init_with_simulation(double v_ego, double x_l_0, double v_l_0, double a_l_0, double l){
  int i;

  double x_l = x_l_0;
  double v_l = v_l_0;
  double a_l = a_l_0;

  double x_ego = 0.0;
  double a_ego = -(v_ego - v_l) * (v_ego - v_l) / (2.0 * x_l + 0.01) + a_l;

  if (a_ego > 0){
    a_ego = 0.0;
  }


  double dt = 0.2;
  double t = 0.;

  for (i = 0; i < N + 1; ++i){
    if (i > 4){
      dt = 0.6;
    }

    /* printf("%.2f\t%.2f\t%.2f\t%.2f\n", t, x_ego, v_ego, a_l); */
    acadoVariables.x[i*NX] = x_ego;
    acadoVariables.x[i*NX+1] = v_ego;
    acadoVariables.x[i*NX+2] = a_ego;

    v_ego += a_ego * dt;

    if (v_ego <= 0.0) {
      v_ego = 0.0;
      a_ego = 0.0;
    }

    x_ego += v_ego * dt;
    t += dt;
  }

  for (i = 0; i < NU * N; ++i)  acadoVariables.u[ i ] = 0.0;
  for (i = 0; i < NY * N; ++i)  acadoVariables.y[ i ] = 0.0;
  for (i = 0; i < NYN; ++i)  acadoVariables.yN[ i ] = 0.0;
}

int run_mpc(state_t * x0, log_t * solution, double l, double a_l_0){
  // Calculate lead vehicle predictions
  int i;
  double t = 0.;
  double dt = 0.2;
  double x_l = x0->x_l;
  double v_l = x0->v_l;
  double a_l = a_l_0;

  /* printf("t\tx_l\t_v_l\t_al\n"); */
  for (i = 0; i < N + 1; ++i){
    if (i > 4){
      dt = 0.6;
    }

    /* printf("%.2f\t%.2f\t%.2f\t%.2f\n", t, x_l, v_l, a_l); */

    acadoVariables.od[i*NOD] = x_l;
    acadoVariables.od[i*NOD+1] = v_l;

    solution->x_l[i] = x_l;
    solution->v_l[i] = v_l;
    solution->a_l[i] = a_l;
    solution->t[i] = t;

    a_l = a_l_0 * exp(-l * t * t / 2);
    x_l += v_l * dt;
    v_l += a_l * dt;
    if (v_l < 0.0){
      a_l = 0.0;
      v_l = 0.0;
    }

    t += dt;
  }

  acadoVariables.x[0] = acadoVariables.x0[0] = x0->x_ego;
  acadoVariables.x[1] = acadoVariables.x0[1] = x0->v_ego;
  acadoVariables.x[2] = acadoVariables.x0[2] = x0->a_ego;

  acado_preparationStep();
  acado_feedbackStep();

	for (i = 0; i <= N; i++){
    solution->x_ego[i] = acadoVariables.x[i*NX];
		solution->v_ego[i] = acadoVariables.x[i*NX+1];
    solution->a_ego[i] = acadoVariables.x[i*NX+2];
    solution->j_ego[i] = acadoVariables.u[i];
	}
  solution->cost = acado_getObjective();

  // Dont shift states here. Current solution is closer to next timestep than if
  // we shift by 0.2 seconds.

  return acado_getNWSR();
}

