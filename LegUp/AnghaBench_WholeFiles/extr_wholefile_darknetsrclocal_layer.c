#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {float learning_rate; float momentum; float decay; int batch; } ;
typedef  TYPE_1__ update_args ;
struct TYPE_14__ {float* input; scalar_t__ delta; int /*<<< orphan*/  workspace; } ;
typedef  TYPE_2__ network ;
struct TYPE_15__ {int h; int pad; int size; int stride; int w; int c; int n; int batch; int out_h; int out_w; int out_c; int outputs; int inputs; float* weights; float* weight_updates; float* biases; float* bias_updates; float* output; float* delta; int workspace_size; void (* forward ) (TYPE_3__ const,TYPE_2__) ;void (* backward ) (TYPE_3__,TYPE_2__) ;void (* update ) (TYPE_3__,TYPE_1__) ;float learning_rate_scale; int /*<<< orphan*/  activation; int /*<<< orphan*/  type; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_3__ local_layer ;
typedef  int /*<<< orphan*/  ACTIVATION ;

/* Variables and functions */
 int /*<<< orphan*/  LOCAL ; 
 int /*<<< orphan*/  activate_array (float*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  axpy_cpu (int,float,float*,int,float*,int) ; 
 void backward_local_layer (TYPE_3__,TYPE_2__) ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  col2im_cpu (int /*<<< orphan*/ ,int,int,int,int,int,int,scalar_t__) ; 
 int /*<<< orphan*/  copy_cpu (int,float*,int,float*,int) ; 
 int exp (int) ; 
 float floor (float) ; 
 void forward_local_layer (TYPE_3__ const,TYPE_2__) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  gemm (int,int,int,int,int,int,float*,int,float*,int,int,float*,int) ; 
 int /*<<< orphan*/  gradient_array (float*,int,int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  im2col_cpu (float*,int,int,int,int,int,int,int /*<<< orphan*/ ) ; 
 float rand_uniform (int,int) ; 
 int /*<<< orphan*/  scal_cpu (int,float,float*,int) ; 
 float sqrt (int) ; 
 int /*<<< orphan*/  stderr ; 
 void update_local_layer (TYPE_3__,TYPE_1__) ; 

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

int local_out_height(local_layer l)
{
    int h = l.h;
    if (!l.pad) h -= l.size;
    else h -= 1;
    return h/l.stride + 1;
}

int local_out_width(local_layer l)
{
    int w = l.w;
    if (!l.pad) w -= l.size;
    else w -= 1;
    return w/l.stride + 1;
}

local_layer make_local_layer(int batch, int h, int w, int c, int n, int size, int stride, int pad, ACTIVATION activation)
{
    int i;
    local_layer l = {0};
    l.type = LOCAL;

    l.h = h;
    l.w = w;
    l.c = c;
    l.n = n;
    l.batch = batch;
    l.stride = stride;
    l.size = size;
    l.pad = pad;

    int out_h = local_out_height(l);
    int out_w = local_out_width(l);
    int locations = out_h*out_w;
    l.out_h = out_h;
    l.out_w = out_w;
    l.out_c = n;
    l.outputs = l.out_h * l.out_w * l.out_c;
    l.inputs = l.w * l.h * l.c;

    l.weights = calloc(c*n*size*size*locations, sizeof(float));
    l.weight_updates = calloc(c*n*size*size*locations, sizeof(float));

    l.biases = calloc(l.outputs, sizeof(float));
    l.bias_updates = calloc(l.outputs, sizeof(float));

    // float scale = 1./sqrt(size*size*c);
    float scale = sqrt(2./(size*size*c));
    for(i = 0; i < c*n*size*size; ++i) l.weights[i] = scale*rand_uniform(-1,1);

    l.output = calloc(l.batch*out_h * out_w * n, sizeof(float));
    l.delta  = calloc(l.batch*out_h * out_w * n, sizeof(float));

    l.workspace_size = out_h*out_w*size*size*c;
    
    l.forward = forward_local_layer;
    l.backward = backward_local_layer;
    l.update = update_local_layer;

#ifdef GPU
    l.forward_gpu = forward_local_layer_gpu;
    l.backward_gpu = backward_local_layer_gpu;
    l.update_gpu = update_local_layer_gpu;

    l.weights_gpu = cuda_make_array(l.weights, c*n*size*size*locations);
    l.weight_updates_gpu = cuda_make_array(l.weight_updates, c*n*size*size*locations);

    l.biases_gpu = cuda_make_array(l.biases, l.outputs);
    l.bias_updates_gpu = cuda_make_array(l.bias_updates, l.outputs);

    l.delta_gpu = cuda_make_array(l.delta, l.batch*out_h*out_w*n);
    l.output_gpu = cuda_make_array(l.output, l.batch*out_h*out_w*n);

#endif
    l.activation = activation;

    fprintf(stderr, "Local Layer: %d x %d x %d image, %d filters -> %d x %d x %d image\n", h,w,c,n, out_h, out_w, n);

    return l;
}

void forward_local_layer(const local_layer l, network net)
{
    int out_h = local_out_height(l);
    int out_w = local_out_width(l);
    int i, j;
    int locations = out_h * out_w;

    for(i = 0; i < l.batch; ++i){
        copy_cpu(l.outputs, l.biases, 1, l.output + i*l.outputs, 1);
    }

    for(i = 0; i < l.batch; ++i){
        float *input = net.input + i*l.w*l.h*l.c;
        im2col_cpu(input, l.c, l.h, l.w, 
                l.size, l.stride, l.pad, net.workspace);
        float *output = l.output + i*l.outputs;
        for(j = 0; j < locations; ++j){
            float *a = l.weights + j*l.size*l.size*l.c*l.n;
            float *b = net.workspace + j;
            float *c = output + j;

            int m = l.n;
            int n = 1;
            int k = l.size*l.size*l.c;

            gemm(0,0,m,n,k,1,a,k,b,locations,1,c,locations);
        }
    }
    activate_array(l.output, l.outputs*l.batch, l.activation);
}

void backward_local_layer(local_layer l, network net)
{
    int i, j;
    int locations = l.out_w*l.out_h;

    gradient_array(l.output, l.outputs*l.batch, l.activation, l.delta);

    for(i = 0; i < l.batch; ++i){
        axpy_cpu(l.outputs, 1, l.delta + i*l.outputs, 1, l.bias_updates, 1);
    }

    for(i = 0; i < l.batch; ++i){
        float *input = net.input + i*l.w*l.h*l.c;
        im2col_cpu(input, l.c, l.h, l.w, 
                l.size, l.stride, l.pad, net.workspace);

        for(j = 0; j < locations; ++j){ 
            float *a = l.delta + i*l.outputs + j;
            float *b = net.workspace + j;
            float *c = l.weight_updates + j*l.size*l.size*l.c*l.n;
            int m = l.n;
            int n = l.size*l.size*l.c;
            int k = 1;

            gemm(0,1,m,n,k,1,a,locations,b,locations,1,c,n);
        }

        if(net.delta){
            for(j = 0; j < locations; ++j){ 
                float *a = l.weights + j*l.size*l.size*l.c*l.n;
                float *b = l.delta + i*l.outputs + j;
                float *c = net.workspace + j;

                int m = l.size*l.size*l.c;
                int n = 1;
                int k = l.n;

                gemm(1,0,m,n,k,1,a,m,b,locations,0,c,locations);
            }

            col2im_cpu(net.workspace, l.c,  l.h,  l.w,  l.size,  l.stride, l.pad, net.delta+i*l.c*l.h*l.w);
        }
    }
}

void update_local_layer(local_layer l, update_args a)
{
    float learning_rate = a.learning_rate*l.learning_rate_scale;
    float momentum = a.momentum;
    float decay = a.decay;
    int batch = a.batch;

    int locations = l.out_w*l.out_h;
    int size = l.size*l.size*l.c*l.n*locations;
    axpy_cpu(l.outputs, learning_rate/batch, l.bias_updates, 1, l.biases, 1);
    scal_cpu(l.outputs, momentum, l.bias_updates, 1);

    axpy_cpu(size, -decay*batch, l.weights, 1, l.weight_updates, 1);
    axpy_cpu(size, learning_rate/batch, l.weight_updates, 1, l.weights, 1);
    scal_cpu(size, momentum, l.weight_updates, 1);
}

