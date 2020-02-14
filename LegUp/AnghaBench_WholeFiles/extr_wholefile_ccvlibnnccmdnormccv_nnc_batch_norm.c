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
typedef  unsigned int uint64_t ;
struct TYPE_11__ {int* dim; } ;
typedef  TYPE_2__ ccv_nnc_tensor_param_t ;
typedef  int /*<<< orphan*/  ccv_nnc_hint_t ;
struct TYPE_10__ {int count; size_t* axis; } ;
struct TYPE_12__ {TYPE_1__ bnorm; } ;
typedef  TYPE_3__ ccv_nnc_cmd_param_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 

__attribute__((used)) static int _ccv_nnc_batch_norm_forw_bitmask(const int input_size, const int output_size, const uint64_t* const input_bitmasks, const int input_bitmask_size, const uint64_t* const output_bitmasks, const int output_bitmask_size)
{
	// 5 inputs (x, scale, bias, mean, var)
	// 1 outputs (y)
	if (input_bitmasks[0] == 31u && output_bitmasks[0] == 1u)
		return 1;
	// 5 inputs (x, scale, bias, mean, var)
	// 5 outputs (y, mean, var, saved_mean, saved_inv_var)
	// Both mean and var in output is inplace for the input mean, var
	if (input_bitmasks[0] == 31u && output_bitmasks[0] == 31u)
		return 1;
	return 0;
}

__attribute__((used)) static int _ccv_nnc_batch_norm_enforce_inplace(const int input_idx, const int input_size, const int output_idx, const int output_size)
{
	if (input_idx == 3 && output_idx == 1)
		return 1;
	if (input_idx == 4 && output_idx == 2)
		return 1;
	return 0;
}

__attribute__((used)) static int _ccv_nnc_batch_norm_back_bitmask(const int input_size, const int output_size, const uint64_t* const input_bitmasks, const int input_bitmask_size, const uint64_t* const output_bitmasks, const int output_bitmask_size)
{
	// 0b110000001100001
	// Inputs (gradient, 0, 0, 0, 0, x, scale, 0, 0, 0, 0, 0, 0, saved_mean, saved_inv_var)
	// Output the propagated error, dscale and dbias
	if ((input_bitmasks[0] & 24673u) == 24673u && (output_bitmasks[0] & 7u) == 7u)
		return 1;
	return 0;
}

__attribute__((used)) static void _ccv_nnc_batch_norm_tensor_auto_forw(const ccv_nnc_cmd_param_t cmd, const ccv_nnc_tensor_param_t* const inputs, const int input_size, const ccv_nnc_hint_t hint, ccv_nnc_tensor_param_t* const outputs, const int output_size)
{
	assert(input_size == 5);
	assert(output_size == 1 || output_size == 5);
	outputs[0] = inputs[0];
	if (output_size == 1)
		return;
	int i, j;
	for (i = 1; i < output_size; i++)
	{
		outputs[i] = inputs[0];
		for (j = 0; j < cmd.bnorm.count; j++)
			outputs[i].dim[cmd.bnorm.axis[j]] = 1; // Reduce the dimension to 1.
	}
}

__attribute__((used)) static void _ccv_nnc_batch_norm_tensor_auto_back(const ccv_nnc_cmd_param_t cmd, const ccv_nnc_tensor_param_t* const inputs, const int input_size, const ccv_nnc_hint_t hint, ccv_nnc_tensor_param_t* const outputs, const int output_size)
{
	assert(input_size == 15);
	assert(output_size == 5);
	outputs[0] = inputs[0];
	int i, j;
	for (i = 1; i < output_size; i++)
	{
		outputs[i] = inputs[0];
		for (j = 0; j < cmd.bnorm.count; j++)
			outputs[i].dim[cmd.bnorm.axis[j]] = 1; // Reduce the dimension to 1.
	}
}

