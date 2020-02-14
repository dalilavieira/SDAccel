#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  enum qeth_ipa_return_codes { ____Placeholder_qeth_ipa_return_codes } qeth_ipa_return_codes ;
typedef  enum qeth_ipa_cmds { ____Placeholder_qeth_ipa_cmds } qeth_ipa_cmds ;
struct TYPE_4__ {int rc; char const* msg; int cmd; char const* name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
#define  QETH_CLEAR_CHANNEL_PARM 130 
#define  QETH_HALT_CHANNEL_PARM 129 
#define  QETH_RCD_PARM 128 
 TYPE_1__* qeth_ipa_cmd_names ; 
 TYPE_1__* qeth_ipa_rc_msg ; 

__attribute__((used)) static inline bool qeth_intparm_is_iob(unsigned long intparm)
{
	switch (intparm) {
	case QETH_CLEAR_CHANNEL_PARM:
	case QETH_HALT_CHANNEL_PARM:
	case QETH_RCD_PARM:
	case 0:
		return false;
	}
	return true;
}

const char *qeth_get_ipa_msg(enum qeth_ipa_return_codes rc)
{
	int x;

	for (x = 0; x < ARRAY_SIZE(qeth_ipa_rc_msg) - 1; x++)
		if (qeth_ipa_rc_msg[x].rc == rc)
			return qeth_ipa_rc_msg[x].msg;
	return qeth_ipa_rc_msg[x].msg;
}

const char *qeth_get_ipa_cmd_name(enum qeth_ipa_cmds cmd)
{
	int x;

	for (x = 0; x < ARRAY_SIZE(qeth_ipa_cmd_names) - 1; x++)
		if (qeth_ipa_cmd_names[x].cmd == cmd)
			return qeth_ipa_cmd_names[x].name;
	return qeth_ipa_cmd_names[x].name;
}

