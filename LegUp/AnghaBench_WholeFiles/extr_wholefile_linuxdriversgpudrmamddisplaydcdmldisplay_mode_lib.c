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
struct _vcs_dpi_ip_params_st {int dummy; } ;
struct _vcs_dpi_soc_bounding_box_st {int dummy; } ;
struct display_mode_lib {int project; struct _vcs_dpi_ip_params_st ip; struct _vcs_dpi_soc_bounding_box_st soc; } ;
typedef  enum dml_project { ____Placeholder_dml_project } dml_project ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
#define  DML_PROJECT_RAVEN1 128 
 struct _vcs_dpi_ip_params_st dcn1_0_ip ; 
 struct _vcs_dpi_soc_bounding_box_st dcn1_0_soc ; 

__attribute__((used)) static void set_soc_bounding_box(struct _vcs_dpi_soc_bounding_box_st *soc, enum dml_project project)
{
	switch (project) {
	case DML_PROJECT_RAVEN1:
		*soc = dcn1_0_soc;
		break;
	default:
		ASSERT(0);
		break;
	}
}

__attribute__((used)) static void set_ip_params(struct _vcs_dpi_ip_params_st *ip, enum dml_project project)
{
	switch (project) {
	case DML_PROJECT_RAVEN1:
		*ip = dcn1_0_ip;
		break;
	default:
		ASSERT(0);
		break;
	}
}

void dml_init_instance(struct display_mode_lib *lib, enum dml_project project)
{
	if (lib->project != project) {
		set_soc_bounding_box(&lib->soc, project);
		set_ip_params(&lib->ip, project);
		lib->project = project;
	}
}

