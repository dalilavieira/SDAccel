#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ demangle_func ;
struct TYPE_7__ {struct TYPE_7__* symbol; scalar_t__ demangle; } ;
typedef  TYPE_1__ SDemangler ;
typedef  int EManglingType ;
typedef  scalar_t__ EDemanglerErr ;

/* Variables and functions */
 int /*<<< orphan*/  R_FREE (TYPE_1__*) ; 
 scalar_t__ eDemanglerErrMemoryAllocation ; 
 scalar_t__ eDemanglerErrOK ; 
 scalar_t__ eDemanglerErrUnkown ; 
 scalar_t__ eDemanglerErrUnsupportedMangling ; 
 int eManglingMicrosoft ; 
#define  eManglingUnknown 129 
#define  eManglingUnsupported 128 
 scalar_t__ malloc (int) ; 
 scalar_t__ microsoft_demangle ; 
 TYPE_1__* strdup (char*) ; 

__attribute__((used)) static EManglingType get_mangling_type(char *sym)
{
	EManglingType mangling_type = eManglingUnsupported;
	if (sym == 0) {
		mangling_type = eManglingUnknown;
		goto get_mangling_type_err;
	}

	switch (*sym) {
	case '?':
		mangling_type = eManglingMicrosoft;
		break;
	default:
		break;
	}

get_mangling_type_err:
	return mangling_type;
}

EDemanglerErr create_demangler(SDemangler **demangler)
{
	EDemanglerErr err = eDemanglerErrOK;

	*demangler = (SDemangler *) malloc(sizeof(SDemangler));

	if (!*demangler) {
		err = eDemanglerErrMemoryAllocation;
		goto create_demagler_err;
	}

	(*demangler)->demangle = 0;
	(*demangler)->symbol = 0;

create_demagler_err:
	return err;
}

EDemanglerErr init_demangler(SDemangler *demangler, char *sym)
{
	EManglingType mangling_type = eManglingUnsupported;
	EDemanglerErr err = eDemanglerErrOK;

	// !!! sequence in this array need to be same as in EManglingType enum !!!
	demangle_func demangle_funcs[] = {
		microsoft_demangle,	// Microsoft demangling function
		0,					// Unsupported demangling
		0					// Unknown demangling
	};

	if (demangler == 0) {
		err =  eDemanglerErrMemoryAllocation;
		goto init_demangler_err;
	}

	mangling_type = get_mangling_type(sym);
	switch (mangling_type) {
	case eManglingUnsupported:
		err = eDemanglerErrUnsupportedMangling;
		break;
	case eManglingUnknown:
		err = eDemanglerErrUnkown;
		break;
	default:
		break;
	}

	if (err != eDemanglerErrOK) {
		goto init_demangler_err;
	}

	demangler->symbol = strdup(sym);
	demangler->demangle = demangle_funcs[mangling_type];

init_demangler_err:
	return err;
}

void free_demangler(SDemangler *demangler)
{
	R_FREE(demangler->symbol);
	R_FREE(demangler);
}

