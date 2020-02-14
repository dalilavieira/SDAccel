#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {TYPE_1__* layers; int /*<<< orphan*/  delta; int /*<<< orphan*/  input; } ;
typedef  TYPE_2__ network ;
struct TYPE_12__ {int batch; int w; int h; int c; int out_w; int out_h; int out_c; int outputs; int inputs; int index; void (* forward ) (TYPE_3__ const,TYPE_2__) ;void (* backward ) (TYPE_3__ const,TYPE_2__) ;int alpha; int /*<<< orphan*/  beta; void* delta; int /*<<< orphan*/  activation; void* output; int /*<<< orphan*/  type; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_3__ layer ;
struct TYPE_10__ {void* delta; void* output; } ;

/* Variables and functions */
 int /*<<< orphan*/  SHORTCUT ; 
 int /*<<< orphan*/  activate_array (void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  axpy_cpu (int,int,void*,int,int /*<<< orphan*/ ,int) ; 
 void backward_shortcut_layer (TYPE_3__ const,TYPE_2__) ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  copy_cpu (int,int /*<<< orphan*/ ,int,void*,int) ; 
 int exp (int) ; 
 float floor (float) ; 
 void forward_shortcut_layer (TYPE_3__ const,TYPE_2__) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  gradient_array (void*,int,int /*<<< orphan*/ ,void*) ; 
 void* realloc (void*,int) ; 
 int /*<<< orphan*/  shortcut_cpu (int,int,int,int,void*,int,int,int,int,int /*<<< orphan*/ ,void*) ; 
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

layer make_shortcut_layer(int batch, int index, int w, int h, int c, int w2, int h2, int c2)
{
    fprintf(stderr, "res  %3d                %4d x%4d x%4d   ->  %4d x%4d x%4d\n",index, w2,h2,c2, w,h,c);
    layer l = {0};
    l.type = SHORTCUT;
    l.batch = batch;
    l.w = w2;
    l.h = h2;
    l.c = c2;
    l.out_w = w;
    l.out_h = h;
    l.out_c = c;
    l.outputs = w*h*c;
    l.inputs = l.outputs;

    l.index = index;

    l.delta =  calloc(l.outputs*batch, sizeof(float));
    l.output = calloc(l.outputs*batch, sizeof(float));;

    l.forward = forward_shortcut_layer;
    l.backward = backward_shortcut_layer;
    #ifdef GPU
    l.forward_gpu = forward_shortcut_layer_gpu;
    l.backward_gpu = backward_shortcut_layer_gpu;

    l.delta_gpu =  cuda_make_array(l.delta, l.outputs*batch);
    l.output_gpu = cuda_make_array(l.output, l.outputs*batch);
    #endif
    return l;
}

void resize_shortcut_layer(layer *l, int w, int h)
{
    assert(l->w == l->out_w);
    assert(l->h == l->out_h);
    l->w = l->out_w = w;
    l->h = l->out_h = h;
    l->outputs = w*h*l->out_c;
    l->inputs = l->outputs;
    l->delta =  realloc(l->delta, l->outputs*l->batch*sizeof(float));
    l->output = realloc(l->output, l->outputs*l->batch*sizeof(float));

#ifdef GPU
    cuda_free(l->output_gpu);
    cuda_free(l->delta_gpu);
    l->output_gpu  = cuda_make_array(l->output, l->outputs*l->batch);
    l->delta_gpu   = cuda_make_array(l->delta,  l->outputs*l->batch);
#endif
    
}

void forward_shortcut_layer(const layer l, network net)
{
    copy_cpu(l.outputs*l.batch, net.input, 1, l.output, 1);
    shortcut_cpu(l.batch, l.w, l.h, l.c, net.layers[l.index].output, l.out_w, l.out_h, l.out_c, l.alpha, l.beta, l.output);
    activate_array(l.output, l.outputs*l.batch, l.activation);
}

void backward_shortcut_layer(const layer l, network net)
{
    gradient_array(l.output, l.outputs*l.batch, l.activation, l.delta);
    axpy_cpu(l.outputs*l.batch, l.alpha, l.delta, 1, net.delta, 1);
    shortcut_cpu(l.batch, l.out_w, l.out_h, l.out_c, l.delta, l.w, l.h, l.c, 1, l.beta, net.layers[l.index].delta);
}

