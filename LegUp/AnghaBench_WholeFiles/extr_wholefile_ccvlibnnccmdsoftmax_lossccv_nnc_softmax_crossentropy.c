#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint64_t ;
struct TYPE_8__ {int /*<<< orphan*/  dim; } ;
typedef  TYPE_1__ ccv_nnc_tensor_param_t ;
typedef  int /*<<< orphan*/  ccv_nnc_hint_t ;
typedef  int /*<<< orphan*/  ccv_nnc_cmd_param_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int ccv_nnc_tensor_get_c (TYPE_1__) ; 
 int ccv_nnc_tensor_nd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccv_nnc_tensor_set_c (TYPE_1__*,int const,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int _ccv_nnc_softmax_crossentropy_forw_bitmask(const int input_size, const int output_size, const uint64_t* const input_bitmasks, const int input_bitmask_size, const uint64_t* const output_bitmasks, const int output_bitmask_size)
{
	// input: activation, label
	// output: [loss], softmax
	if ((input_bitmasks[0] & 3u) == 3u && output_bitmasks[0] == 3u)
		return 1;
	if ((input_bitmasks[0] & 3u) == 3u && output_bitmasks[0] == 2u)
		return 1;
	return 0;
}

__attribute__((used)) static int _ccv_nnc_softmax_crossentropy_allow_inplace_forw(const int input_idx, const int input_size, const int output_idx, const int output_size)
{
	return (input_idx == 0 && output_idx == 1);
}

__attribute__((used)) static int _ccv_nnc_softmax_crossentropy_back_bitmask(const int input_size, const int output_size, const uint64_t* const input_bitmasks, const int input_bitmask_size, const uint64_t* const output_bitmasks, const int output_bitmask_size)
{
	// input: [gradient of loss], [gradient of softmax], [activation], label, [loss], softmax
	// output: w.r.t activation, [label]
	if ((input_bitmasks[0] & 41u) == 41u && (output_bitmasks[0] & 1u) == 1u)
		return 1;
	return 0;
}

__attribute__((used)) static int _ccv_nnc_softmax_crossentropy_allow_inplace_back(const int input_idx, const int input_size, const int output_idx, const int output_size)
{
	if (input_idx == 1 && output_idx == 0)
		return 1;
	if (input_idx == 2 && output_idx == 0)
		return 1;
	else if (input_idx == 5 && output_idx == 0)
		return 1;
	return 0;
}

__attribute__((used)) static void _ccv_nnc_softmax_crossentropy_tensor_auto_forw(const ccv_nnc_cmd_param_t cmd, const ccv_nnc_tensor_param_t* const inputs, const int input_size, const ccv_nnc_hint_t hint, ccv_nnc_tensor_param_t* const outputs, const int output_size)
{
	assert(input_size == 2);
	assert(output_size >= 1);
	outputs[0] = inputs[0];
	if (output_size > 1)
	{
		outputs[1] = inputs[0];
		// The output should have the same dimentionality of the label data.
		memcpy(outputs[1].dim, inputs[1].dim, sizeof(outputs[1].dim));
		const int nd = ccv_nnc_tensor_nd(outputs[1].dim);
		// Set channel to 1 if it is not..
		if (nd > 1 && ccv_nnc_tensor_get_c(outputs[1]) > 1)
			ccv_nnc_tensor_set_c(&outputs[1], nd, 1);
	}
}

__attribute__((used)) static void _ccv_nnc_softmax_crossentropy_tensor_auto_back(const ccv_nnc_cmd_param_t cmd, const ccv_nnc_tensor_param_t* const inputs, const int input_size, const ccv_nnc_hint_t hint, ccv_nnc_tensor_param_t* const outputs, const int output_size)
{
	assert(input_size >= 6);
	assert(output_size >= 1);
	outputs[0] = inputs[5];
	if (output_size > 1)
		outputs[1] = inputs[3];
}

