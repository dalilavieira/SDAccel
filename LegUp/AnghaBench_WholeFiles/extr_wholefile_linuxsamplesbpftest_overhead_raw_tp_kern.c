#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct bpf_raw_tracepoint_args {int dummy; } ;

/* Variables and functions */

int prog(struct bpf_raw_tracepoint_args *ctx)
{
	return 0;
}

int prog2(struct bpf_raw_tracepoint_args *ctx)
{
	return 0;
}

