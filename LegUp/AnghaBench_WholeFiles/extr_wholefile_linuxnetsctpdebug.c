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
union sctp_subtype {size_t chunk; size_t primitive; size_t other; scalar_t__ timeout; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (char const**) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
#define  SCTP_CID_ASCONF 134 
#define  SCTP_CID_ASCONF_ACK 133 
#define  SCTP_CID_AUTH 132 
 size_t SCTP_CID_BASE_MAX ; 
#define  SCTP_CID_FWD_TSN 131 
#define  SCTP_CID_I_DATA 130 
#define  SCTP_CID_I_FWD_TSN 129 
#define  SCTP_CID_RECONF 128 
 size_t SCTP_EVENT_OTHER_MAX ; 
 size_t SCTP_EVENT_PRIMITIVE_MAX ; 
 scalar_t__ SCTP_EVENT_TIMEOUT_MAX ; 
 char const** sctp_cid_tbl ; 
 char const** sctp_other_tbl ; 
 char const** sctp_primitive_tbl ; 
 char const** sctp_timer_tbl ; 

const char *sctp_cname(const union sctp_subtype cid)
{
	if (cid.chunk <= SCTP_CID_BASE_MAX)
		return sctp_cid_tbl[cid.chunk];

	switch (cid.chunk) {
	case SCTP_CID_ASCONF:
		return "ASCONF";

	case SCTP_CID_ASCONF_ACK:
		return "ASCONF_ACK";

	case SCTP_CID_FWD_TSN:
		return "FWD_TSN";

	case SCTP_CID_AUTH:
		return "AUTH";

	case SCTP_CID_RECONF:
		return "RECONF";

	case SCTP_CID_I_DATA:
		return "I_DATA";

	case SCTP_CID_I_FWD_TSN:
		return "I_FWD_TSN";

	default:
		break;
	}

	return "unknown chunk";
}

const char *sctp_pname(const union sctp_subtype id)
{
	if (id.primitive <= SCTP_EVENT_PRIMITIVE_MAX)
		return sctp_primitive_tbl[id.primitive];
	return "unknown_primitive";
}

const char *sctp_oname(const union sctp_subtype id)
{
	if (id.other <= SCTP_EVENT_OTHER_MAX)
		return sctp_other_tbl[id.other];
	return "unknown 'other' event";
}

const char *sctp_tname(const union sctp_subtype id)
{
	BUILD_BUG_ON(SCTP_EVENT_TIMEOUT_MAX + 1 != ARRAY_SIZE(sctp_timer_tbl));

	if (id.timeout < ARRAY_SIZE(sctp_timer_tbl))
		return sctp_timer_tbl[id.timeout];
	return "unknown_timer";
}

