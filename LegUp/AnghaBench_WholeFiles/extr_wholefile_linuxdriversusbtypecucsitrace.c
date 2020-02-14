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
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  int u32 ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (char const**) ; 
 int BIT (int) ; 
 int GENMASK (int,int /*<<< orphan*/ ) ; 
 char const** ucsi_ack_strs ; 
 char const** ucsi_cmd_strs ; 

__attribute__((used)) static inline const char *ucsi_cmd_str(u64 raw_cmd)
{
	u8 cmd = raw_cmd & GENMASK(7, 0);

	return ucsi_cmd_strs[(cmd >= ARRAY_SIZE(ucsi_cmd_strs)) ? 0 : cmd];
}

__attribute__((used)) static inline const char *ucsi_ack_str(u8 ack)
{
	return ucsi_ack_strs[(ack >= ARRAY_SIZE(ucsi_ack_strs)) ? 0 : ack];
}

__attribute__((used)) static inline const char *ucsi_cci_str(u32 cci)
{
	if (cci & GENMASK(7, 0)) {
		if (cci & BIT(29))
			return "Event pending (ACK completed)";
		if (cci & BIT(31))
			return "Event pending (command completed)";
		return "Connector Change";
	}
	if (cci & BIT(29))
		return "ACK completed";
	if (cci & BIT(31))
		return "Command completed";

	return "";
}

