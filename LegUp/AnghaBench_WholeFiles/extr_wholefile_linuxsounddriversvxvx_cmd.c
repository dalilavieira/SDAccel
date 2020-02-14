#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct vx_rmh {int* Cmd; int /*<<< orphan*/  DspStat; int /*<<< orphan*/  LgStat; int /*<<< orphan*/  LgCmd; } ;
struct TYPE_2__ {int opcode; int /*<<< orphan*/  st_type; int /*<<< orphan*/  st_length; int /*<<< orphan*/  length; } ;

/* Variables and functions */
 unsigned int CMD_LAST_INDEX ; 
 int COMMAND_RECORD_MASK ; 
 int FIELD_SIZE ; 
 int MASK_DSP_WORD ; 
 int MASK_FIRST_FIELD ; 
 scalar_t__ snd_BUG_ON (int) ; 
 TYPE_1__* vx_dsp_cmds ; 

__attribute__((used)) static inline void vx_set_pipe_cmd_params(struct vx_rmh *rmh, int is_capture,
					  int param1, int param2)
{
	if (is_capture)
		rmh->Cmd[0] |= COMMAND_RECORD_MASK;
	rmh->Cmd[0] |= (((u32)param1 & MASK_FIRST_FIELD) << FIELD_SIZE) & MASK_DSP_WORD;
		
	if (param2)
		rmh->Cmd[0] |= ((u32)param2 & MASK_FIRST_FIELD) & MASK_DSP_WORD;
	
}

__attribute__((used)) static inline void vx_set_stream_cmd_params(struct vx_rmh *rmh, int is_capture, int pipe)
{
	if (is_capture)
		rmh->Cmd[0] |= COMMAND_RECORD_MASK;
	rmh->Cmd[0] |= (((u32)pipe & MASK_FIRST_FIELD) << FIELD_SIZE) & MASK_DSP_WORD;
}

void vx_init_rmh(struct vx_rmh *rmh, unsigned int cmd)
{
	if (snd_BUG_ON(cmd >= CMD_LAST_INDEX))
		return;
	rmh->LgCmd = vx_dsp_cmds[cmd].length;
	rmh->LgStat = vx_dsp_cmds[cmd].st_length;
	rmh->DspStat = vx_dsp_cmds[cmd].st_type;
	rmh->Cmd[0] = vx_dsp_cmds[cmd].opcode;
}

