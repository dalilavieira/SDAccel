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
struct TYPE_8__ {int /*<<< orphan*/  delta; int /*<<< orphan*/  input; } ;
typedef  TYPE_1__ network ;
struct TYPE_9__ {int batch; int inputs; int outputs; void (* forward ) (TYPE_2__ const,TYPE_1__) ;void (* backward ) (TYPE_2__ const,TYPE_1__) ;int out_w; int out_h; void* delta; int /*<<< orphan*/  out_c; void* scales; void* output; int /*<<< orphan*/  type; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ layer ;

/* Variables and functions */
 int /*<<< orphan*/  L2NORM ; 
 int /*<<< orphan*/  axpy_cpu (int,int,void*,int,int /*<<< orphan*/ ,int) ; 
 void backward_l2norm_layer (TYPE_2__ const,TYPE_1__) ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  copy_cpu (int,int /*<<< orphan*/ ,int,void*,int) ; 
 int exp (int) ; 
 float floor (float) ; 
 void forward_l2norm_layer (TYPE_2__ const,TYPE_1__) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  l2normalize_cpu (void*,void*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static inline float distance_from_edge(int x, int max)
{
    int dx = (max/2) - x;
    if (dx < 0) dx = -dx;
    dx = (max/2) + 1 - dx;
    dx *= 2;
    float dist = (float)dx/max;
    if (dist > 1) dist = 1;
    return dist;
}

__attribute__((used)) static inline float stair_activate(float x)
{
    int n = floor(x);
    if (n%2 == 0) return floor(x/2.);
    else return (x - n) + floor(x/2.);
}

__attribute__((used)) static inline float hardtan_activate(float x)
{
    if (x < -1) return -1;
    if (x > 1) return 1;
    return x;
}

__attribute__((used)) static inline float linear_activate(float x){return x;}

__attribute__((used)) static inline float logistic_activate(float x){return 1./(1. + exp(-x));}

__attribute__((used)) static inline float loggy_activate(float x){return 2./(1. + exp(-x)) - 1;}

__attribute__((used)) static inline float relu_activate(float x){return x*(x>0);}

__attribute__((used)) static inline float elu_activate(float x){return (x >= 0)*x + (x < 0)*(exp(x)-1);}

__attribute__((used)) static inline float selu_activate(float x){return (x >= 0)*1.0507*x + (x < 0)*1.0507*1.6732*(exp(x)-1);}

__attribute__((used)) static inline float relie_activate(float x){return (x>0) ? x : .01*x;}

__attribute__((used)) static inline float ramp_activate(float x){return x*(x>0)+.1*x;}

__attribute__((used)) static inline float leaky_activate(float x){return (x>0) ? x : .1*x;}

__attribute__((used)) static inline float tanh_activate(float x){return (exp(2*x)-1)/(exp(2*x)+1);}

__attribute__((used)) static inline float plse_activate(float x)
{
    if(x < -4) return .01 * (x + 4);
    if(x > 4)  return .01 * (x - 4) + 1;
    return .125*x + .5;
}

__attribute__((used)) static inline float lhtan_activate(float x)
{
    if(x < 0) return .001*x;
    if(x > 1) return .001*(x-1) + 1;
    return x;
}

__attribute__((used)) static inline float lhtan_gradient(float x)
{
    if(x > 0 && x < 1) return 1;
    return .001;
}

__attribute__((used)) static inline float hardtan_gradient(float x)
{
    if (x > -1 && x < 1) return 1;
    return 0;
}

__attribute__((used)) static inline float linear_gradient(float x){return 1;}

__attribute__((used)) static inline float logistic_gradient(float x){return (1-x)*x;}

__attribute__((used)) static inline float loggy_gradient(float x)
{
    float y = (x+1.)/2.;
    return 2*(1-y)*y;
}

__attribute__((used)) static inline float stair_gradient(float x)
{
    if (floor(x) == x) return 0;
    return 1;
}

__attribute__((used)) static inline float relu_gradient(float x){return (x>0);}

__attribute__((used)) static inline float elu_gradient(float x){return (x >= 0) + (x < 0)*(x + 1);}

__attribute__((used)) static inline float selu_gradient(float x){return (x >= 0)*1.0507 + (x < 0)*(x + 1.0507*1.6732);}

__attribute__((used)) static inline float relie_gradient(float x){return (x>0) ? 1 : .01;}

__attribute__((used)) static inline float ramp_gradient(float x){return (x>0)+.1;}

__attribute__((used)) static inline float leaky_gradient(float x){return (x>0) ? 1 : .1;}

__attribute__((used)) static inline float tanh_gradient(float x){return 1-x*x;}

__attribute__((used)) static inline float plse_gradient(float x){return (x < 0 || x > 1) ? .01 : .125;}

layer make_l2norm_layer(int batch, int inputs)
{
    fprintf(stderr, "l2norm                                         %4d\n",  inputs);
    layer l = {0};
    l.type = L2NORM;
    l.batch = batch;
    l.inputs = inputs;
    l.outputs = inputs;
    l.output = calloc(inputs*batch, sizeof(float));
    l.scales = calloc(inputs*batch, sizeof(float));
    l.delta = calloc(inputs*batch, sizeof(float));

    l.forward = forward_l2norm_layer;
    l.backward = backward_l2norm_layer;
    #ifdef GPU
    l.forward_gpu = forward_l2norm_layer_gpu;
    l.backward_gpu = backward_l2norm_layer_gpu;

    l.output_gpu = cuda_make_array(l.output, inputs*batch); 
    l.scales_gpu = cuda_make_array(l.output, inputs*batch); 
    l.delta_gpu = cuda_make_array(l.delta, inputs*batch); 
    #endif
    return l;
}

void forward_l2norm_layer(const layer l, network net)
{
    copy_cpu(l.outputs*l.batch, net.input, 1, l.output, 1);
    l2normalize_cpu(l.output, l.scales, l.batch, l.out_c, l.out_w*l.out_h);
}

void backward_l2norm_layer(const layer l, network net)
{
    //axpy_cpu(l.inputs*l.batch, 1, l.scales, 1, l.delta, 1);
    axpy_cpu(l.inputs*l.batch, 1, l.delta, 1, net.delta, 1);
}

