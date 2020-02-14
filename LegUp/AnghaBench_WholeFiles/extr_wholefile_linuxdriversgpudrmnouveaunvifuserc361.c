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
typedef  int /*<<< orphan*/  u32 ;
struct nvif_user {int /*<<< orphan*/  object; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvif_wr32 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
nvif_userc361_doorbell(struct nvif_user *user, u32 token)
{
	nvif_wr32(&user->object, 0x90, token);
}

