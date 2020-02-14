#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int batch; int groups; int inputs; int outputs; void (* forward ) (TYPE_2__ const,TYPE_3__) ;void (* backward ) (TYPE_2__ const,TYPE_3__) ;void* delta; void* loss; int /*<<< orphan*/ * cost; void* output; int /*<<< orphan*/  noloss; int /*<<< orphan*/  temperature; TYPE_1__* softmax_tree; int /*<<< orphan*/  type; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ softmax_layer ;
struct TYPE_11__ {int /*<<< orphan*/  delta; scalar_t__ truth; scalar_t__ input; } ;
typedef  TYPE_3__ network ;
struct TYPE_9__ {int groups; int* group_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOFTMAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  axpy_cpu (int,int,void*,int,int /*<<< orphan*/ ,int) ; 
 void backward_softmax_layer (TYPE_2__ const,TYPE_3__) ; 
 void* calloc (int,int) ; 
 void forward_softmax_layer (TYPE_2__ const,TYPE_3__) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  softmax_cpu (scalar_t__,int,int,int,int,int,int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  softmax_x_ent_cpu (int,void*,scalar_t__,void*,void*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  sum_array (void*,int) ; 

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

softmax_layer make_softmax_layer(int batch, int inputs, int groups)
{
    assert(inputs%groups == 0);
    fprintf(stderr, "softmax                                        %4d\n",  inputs);
    softmax_layer l = {0};
    l.type = SOFTMAX;
    l.batch = batch;
    l.groups = groups;
    l.inputs = inputs;
    l.outputs = inputs;
    l.loss = calloc(inputs*batch, sizeof(float));
    l.output = calloc(inputs*batch, sizeof(float));
    l.delta = calloc(inputs*batch, sizeof(float));
    l.cost = calloc(1, sizeof(float));

    l.forward = forward_softmax_layer;
    l.backward = backward_softmax_layer;
    #ifdef GPU
    l.forward_gpu = forward_softmax_layer_gpu;
    l.backward_gpu = backward_softmax_layer_gpu;

    l.output_gpu = cuda_make_array(l.output, inputs*batch); 
    l.loss_gpu = cuda_make_array(l.loss, inputs*batch); 
    l.delta_gpu = cuda_make_array(l.delta, inputs*batch); 
    #endif
    return l;
}

void forward_softmax_layer(const softmax_layer l, network net)
{
    if(l.softmax_tree){
        int i;
        int count = 0;
        for (i = 0; i < l.softmax_tree->groups; ++i) {
            int group_size = l.softmax_tree->group_size[i];
            softmax_cpu(net.input + count, group_size, l.batch, l.inputs, 1, 0, 1, l.temperature, l.output + count);
            count += group_size;
        }
    } else {
        softmax_cpu(net.input, l.inputs/l.groups, l.batch, l.inputs, l.groups, l.inputs/l.groups, 1, l.temperature, l.output);
    }

    if(net.truth && !l.noloss){
        softmax_x_ent_cpu(l.batch*l.inputs, l.output, net.truth, l.delta, l.loss);
        l.cost[0] = sum_array(l.loss, l.batch*l.inputs);
    }
}

void backward_softmax_layer(const softmax_layer l, network net)
{
    axpy_cpu(l.inputs*l.batch, 1, l.delta, 1, net.delta, 1);
}

