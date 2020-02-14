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
typedef  int uint32 ;
typedef  int /*<<< orphan*/ * lut_fcn ;
typedef  int /*<<< orphan*/ * exec_fcn ;

/* Variables and functions */
#define  BUCKET_LOOKUP 133 
#define  BUCKET_LOOKUP_INSERT 132 
#define  COUNT_PACKETS 131 
#define  NORMAL_LUT_WO_INSERT 130 
#define  NORMAL_LUT_W_INSERT 129 
#define  TCP_SESSION 128 
 int /*<<< orphan*/  bucket_lookup ; 
 int /*<<< orphan*/  bucket_lookup_insert ; 
 int /*<<< orphan*/  count_packets ; 
 int /*<<< orphan*/  normal_lut_w_insert ; 
 int /*<<< orphan*/  normal_lut_wo_insert ; 
 int /*<<< orphan*/  tcp_session ; 

lut_fcn lut_fcn_mapper(uint32 index)
{

	switch (index)
	{
	case NORMAL_LUT_W_INSERT:
		return (lut_fcn) normal_lut_w_insert;

	case NORMAL_LUT_WO_INSERT:
		return (lut_fcn) normal_lut_wo_insert;

	case BUCKET_LOOKUP:
		return (lut_fcn) bucket_lookup;

	case BUCKET_LOOKUP_INSERT:
		return (lut_fcn) bucket_lookup_insert;
	
	default:
		return NULL;
	}
	
	return NULL;

}

exec_fcn exec_fcn_mapper(uint32 index)
{
	switch (index)
	{
	case COUNT_PACKETS:
		return (exec_fcn) count_packets;
	
	case TCP_SESSION:
		return (exec_fcn) tcp_session;
	default:
		return NULL;
	}
	
	return NULL;
}

