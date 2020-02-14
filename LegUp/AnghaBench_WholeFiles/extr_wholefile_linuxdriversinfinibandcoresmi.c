#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
struct TYPE_3__ {size_t* initial_path; size_t* return_path; scalar_t__ dr_dlid; scalar_t__ dr_slid; } ;
struct TYPE_4__ {TYPE_1__ dr; } ;
struct opa_smp {scalar_t__ hop_ptr; scalar_t__ hop_cnt; TYPE_2__ route; } ;
struct ib_smp {scalar_t__ hop_ptr; scalar_t__ hop_cnt; size_t* initial_path; size_t* return_path; scalar_t__ dr_dlid; scalar_t__ dr_slid; } ;
struct ib_device {scalar_t__ process_mad; } ;
typedef  enum smi_forward_action { ____Placeholder_smi_forward_action } smi_forward_action ;
typedef  enum smi_action { ____Placeholder_smi_action } smi_action ;

/* Variables and functions */
 scalar_t__ IB_LID_PERMISSIVE ; 
 int IB_SMI_DISCARD ; 
 int IB_SMI_FORWARD ; 
 int IB_SMI_HANDLE ; 
 int IB_SMI_LOCAL ; 
 int IB_SMI_SEND ; 
 size_t IB_SMP_MAX_PATH_HOPS ; 
 scalar_t__ OPA_LID_PERMISSIVE ; 
 size_t ib_get_smp_direction (struct ib_smp*) ; 
 size_t opa_get_smp_direction (struct opa_smp*) ; 

__attribute__((used)) static inline enum smi_action smi_check_local_smp(struct ib_smp *smp,
						  struct ib_device *device)
{
	/* C14-9:3 -- We're at the end of the DR segment of path */
	/* C14-9:4 -- Hop Pointer = Hop Count + 1 -> give to SMA/SM */
	return ((device->process_mad &&
		!ib_get_smp_direction(smp) &&
		(smp->hop_ptr == smp->hop_cnt + 1)) ?
		IB_SMI_HANDLE : IB_SMI_DISCARD);
}

__attribute__((used)) static inline enum smi_action smi_check_local_returning_smp(struct ib_smp *smp,
						   struct ib_device *device)
{
	/* C14-13:3 -- We're at the end of the DR segment of path */
	/* C14-13:4 -- Hop Pointer == 0 -> give to SM */
	return ((device->process_mad &&
		ib_get_smp_direction(smp) &&
		!smp->hop_ptr) ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}

__attribute__((used)) static inline enum smi_action opa_smi_check_local_smp(struct opa_smp *smp,
						      struct ib_device *device)
{
	/* C14-9:3 -- We're at the end of the DR segment of path */
	/* C14-9:4 -- Hop Pointer = Hop Count + 1 -> give to SMA/SM */
	return (device->process_mad &&
		!opa_get_smp_direction(smp) &&
		(smp->hop_ptr == smp->hop_cnt + 1)) ?
		IB_SMI_HANDLE : IB_SMI_DISCARD;
}

__attribute__((used)) static inline enum smi_action opa_smi_check_local_returning_smp(struct opa_smp *smp,
								struct ib_device *device)
{
	/* C14-13:3 -- We're at the end of the DR segment of path */
	/* C14-13:4 -- Hop Pointer == 0 -> give to SM */
	return (device->process_mad &&
		opa_get_smp_direction(smp) &&
		!smp->hop_ptr) ? IB_SMI_HANDLE : IB_SMI_DISCARD;
}

__attribute__((used)) static enum smi_action __smi_handle_dr_smp_send(bool is_switch, int port_num,
						u8 *hop_ptr, u8 hop_cnt,
						const u8 *initial_path,
						const u8 *return_path,
						u8 direction,
						bool dr_dlid_is_permissive,
						bool dr_slid_is_permissive)
{
	/* See section 14.2.2.2, Vol 1 IB spec */
	/* C14-6 -- valid hop_cnt values are from 0 to 63 */
	if (hop_cnt >= IB_SMP_MAX_PATH_HOPS)
		return IB_SMI_DISCARD;

	if (!direction) {
		/* C14-9:1 */
		if (hop_cnt && *hop_ptr == 0) {
			(*hop_ptr)++;
			return (initial_path[*hop_ptr] ==
				port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-9:2 */
		if (*hop_ptr && *hop_ptr < hop_cnt) {
			if (!is_switch)
				return IB_SMI_DISCARD;

			/* return_path set when received */
			(*hop_ptr)++;
			return (initial_path[*hop_ptr] ==
				port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-9:3 -- We're at the end of the DR segment of path */
		if (*hop_ptr == hop_cnt) {
			/* return_path set when received */
			(*hop_ptr)++;
			return (is_switch ||
				dr_dlid_is_permissive ?
				IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-9:4 -- hop_ptr = hop_cnt + 1 -> give to SMA/SM */
		/* C14-9:5 -- Fail unreasonable hop pointer */
		return (*hop_ptr == hop_cnt + 1 ? IB_SMI_HANDLE : IB_SMI_DISCARD);

	} else {
		/* C14-13:1 */
		if (hop_cnt && *hop_ptr == hop_cnt + 1) {
			(*hop_ptr)--;
			return (return_path[*hop_ptr] ==
				port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:2 */
		if (2 <= *hop_ptr && *hop_ptr <= hop_cnt) {
			if (!is_switch)
				return IB_SMI_DISCARD;

			(*hop_ptr)--;
			return (return_path[*hop_ptr] ==
				port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:3 -- at the end of the DR segment of path */
		if (*hop_ptr == 1) {
			(*hop_ptr)--;
			/* C14-13:3 -- SMPs destined for SM shouldn't be here */
			return (is_switch ||
				dr_slid_is_permissive ?
				IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:4 -- hop_ptr = 0 -> should have gone to SM */
		if (*hop_ptr == 0)
			return IB_SMI_HANDLE;

		/* C14-13:5 -- Check for unreasonable hop pointer */
		return IB_SMI_DISCARD;
	}
}

enum smi_action smi_handle_dr_smp_send(struct ib_smp *smp,
				       bool is_switch, int port_num)
{
	return __smi_handle_dr_smp_send(is_switch, port_num,
					&smp->hop_ptr, smp->hop_cnt,
					smp->initial_path,
					smp->return_path,
					ib_get_smp_direction(smp),
					smp->dr_dlid == IB_LID_PERMISSIVE,
					smp->dr_slid == IB_LID_PERMISSIVE);
}

enum smi_action opa_smi_handle_dr_smp_send(struct opa_smp *smp,
				       bool is_switch, int port_num)
{
	return __smi_handle_dr_smp_send(is_switch, port_num,
					&smp->hop_ptr, smp->hop_cnt,
					smp->route.dr.initial_path,
					smp->route.dr.return_path,
					opa_get_smp_direction(smp),
					smp->route.dr.dr_dlid ==
					OPA_LID_PERMISSIVE,
					smp->route.dr.dr_slid ==
					OPA_LID_PERMISSIVE);
}

__attribute__((used)) static enum smi_action __smi_handle_dr_smp_recv(bool is_switch, int port_num,
						int phys_port_cnt,
						u8 *hop_ptr, u8 hop_cnt,
						const u8 *initial_path,
						u8 *return_path,
						u8 direction,
						bool dr_dlid_is_permissive,
						bool dr_slid_is_permissive)
{
	/* See section 14.2.2.2, Vol 1 IB spec */
	/* C14-6 -- valid hop_cnt values are from 0 to 63 */
	if (hop_cnt >= IB_SMP_MAX_PATH_HOPS)
		return IB_SMI_DISCARD;

	if (!direction) {
		/* C14-9:1 -- sender should have incremented hop_ptr */
		if (hop_cnt && *hop_ptr == 0)
			return IB_SMI_DISCARD;

		/* C14-9:2 -- intermediate hop */
		if (*hop_ptr && *hop_ptr < hop_cnt) {
			if (!is_switch)
				return IB_SMI_DISCARD;

			return_path[*hop_ptr] = port_num;
			/* hop_ptr updated when sending */
			return (initial_path[*hop_ptr+1] <= phys_port_cnt ?
				IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-9:3 -- We're at the end of the DR segment of path */
		if (*hop_ptr == hop_cnt) {
			if (hop_cnt)
				return_path[*hop_ptr] = port_num;
			/* hop_ptr updated when sending */

			return (is_switch ||
				dr_dlid_is_permissive ?
				IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-9:4 -- hop_ptr = hop_cnt + 1 -> give to SMA/SM */
		/* C14-9:5 -- fail unreasonable hop pointer */
		return (*hop_ptr == hop_cnt + 1 ? IB_SMI_HANDLE : IB_SMI_DISCARD);

	} else {

		/* C14-13:1 */
		if (hop_cnt && *hop_ptr == hop_cnt + 1) {
			(*hop_ptr)--;
			return (return_path[*hop_ptr] ==
				port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:2 */
		if (2 <= *hop_ptr && *hop_ptr <= hop_cnt) {
			if (!is_switch)
				return IB_SMI_DISCARD;

			/* hop_ptr updated when sending */
			return (return_path[*hop_ptr-1] <= phys_port_cnt ?
				IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:3 -- We're at the end of the DR segment of path */
		if (*hop_ptr == 1) {
			if (dr_slid_is_permissive) {
				/* giving SMP to SM - update hop_ptr */
				(*hop_ptr)--;
				return IB_SMI_HANDLE;
			}
			/* hop_ptr updated when sending */
			return (is_switch ? IB_SMI_HANDLE : IB_SMI_DISCARD);
		}

		/* C14-13:4 -- hop_ptr = 0 -> give to SM */
		/* C14-13:5 -- Check for unreasonable hop pointer */
		return (*hop_ptr == 0 ? IB_SMI_HANDLE : IB_SMI_DISCARD);
	}
}

enum smi_action smi_handle_dr_smp_recv(struct ib_smp *smp, bool is_switch,
				       int port_num, int phys_port_cnt)
{
	return __smi_handle_dr_smp_recv(is_switch, port_num, phys_port_cnt,
					&smp->hop_ptr, smp->hop_cnt,
					smp->initial_path,
					smp->return_path,
					ib_get_smp_direction(smp),
					smp->dr_dlid == IB_LID_PERMISSIVE,
					smp->dr_slid == IB_LID_PERMISSIVE);
}

enum smi_action opa_smi_handle_dr_smp_recv(struct opa_smp *smp, bool is_switch,
					   int port_num, int phys_port_cnt)
{
	return __smi_handle_dr_smp_recv(is_switch, port_num, phys_port_cnt,
					&smp->hop_ptr, smp->hop_cnt,
					smp->route.dr.initial_path,
					smp->route.dr.return_path,
					opa_get_smp_direction(smp),
					smp->route.dr.dr_dlid ==
					OPA_LID_PERMISSIVE,
					smp->route.dr.dr_slid ==
					OPA_LID_PERMISSIVE);
}

__attribute__((used)) static enum smi_forward_action __smi_check_forward_dr_smp(u8 hop_ptr, u8 hop_cnt,
							  u8 direction,
							  bool dr_dlid_is_permissive,
							  bool dr_slid_is_permissive)
{
	if (!direction) {
		/* C14-9:2 -- intermediate hop */
		if (hop_ptr && hop_ptr < hop_cnt)
			return IB_SMI_FORWARD;

		/* C14-9:3 -- at the end of the DR segment of path */
		if (hop_ptr == hop_cnt)
			return (dr_dlid_is_permissive ?
				IB_SMI_SEND : IB_SMI_LOCAL);

		/* C14-9:4 -- hop_ptr = hop_cnt + 1 -> give to SMA/SM */
		if (hop_ptr == hop_cnt + 1)
			return IB_SMI_SEND;
	} else {
		/* C14-13:2  -- intermediate hop */
		if (2 <= hop_ptr && hop_ptr <= hop_cnt)
			return IB_SMI_FORWARD;

		/* C14-13:3 -- at the end of the DR segment of path */
		if (hop_ptr == 1)
			return (!dr_slid_is_permissive ?
				IB_SMI_SEND : IB_SMI_LOCAL);
	}
	return IB_SMI_LOCAL;

}

enum smi_forward_action smi_check_forward_dr_smp(struct ib_smp *smp)
{
	return __smi_check_forward_dr_smp(smp->hop_ptr, smp->hop_cnt,
					  ib_get_smp_direction(smp),
					  smp->dr_dlid == IB_LID_PERMISSIVE,
					  smp->dr_slid == IB_LID_PERMISSIVE);
}

enum smi_forward_action opa_smi_check_forward_dr_smp(struct opa_smp *smp)
{
	return __smi_check_forward_dr_smp(smp->hop_ptr, smp->hop_cnt,
					  opa_get_smp_direction(smp),
					  smp->route.dr.dr_dlid ==
					  OPA_LID_PERMISSIVE,
					  smp->route.dr.dr_slid ==
					  OPA_LID_PERMISSIVE);
}

int smi_get_fwd_port(struct ib_smp *smp)
{
	return (!ib_get_smp_direction(smp) ? smp->initial_path[smp->hop_ptr+1] :
		smp->return_path[smp->hop_ptr-1]);
}

int opa_smi_get_fwd_port(struct opa_smp *smp)
{
	return !opa_get_smp_direction(smp) ? smp->route.dr.initial_path[smp->hop_ptr+1] :
		smp->route.dr.return_path[smp->hop_ptr-1];
}

