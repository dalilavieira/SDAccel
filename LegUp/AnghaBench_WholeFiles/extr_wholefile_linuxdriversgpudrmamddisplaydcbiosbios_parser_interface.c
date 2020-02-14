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
struct dc_bios {TYPE_1__* funcs; } ;
struct bp_init_data {int dummy; } ;
typedef  enum dce_version { ____Placeholder_dce_version } dce_version ;
struct TYPE_2__ {int /*<<< orphan*/  (* bios_parser_destroy ) (struct dc_bios**) ;} ;

/* Variables and functions */
 struct dc_bios* bios_parser_create (struct bp_init_data*,int) ; 
 struct dc_bios* firmware_parser_create (struct bp_init_data*,int) ; 
 int /*<<< orphan*/  stub1 (struct dc_bios**) ; 

struct dc_bios *dal_bios_parser_create(
	struct bp_init_data *init,
	enum dce_version dce_version)
{
	struct dc_bios *bios = NULL;

	bios = firmware_parser_create(init, dce_version);

	/* Fall back to old bios parser for older asics */
	if (bios == NULL)
		bios = bios_parser_create(init, dce_version);

	return bios;
}

void dal_bios_parser_destroy(struct dc_bios **dcb)
{
	struct dc_bios *bios = *dcb;

	bios->funcs->bios_parser_destroy(dcb);
}

