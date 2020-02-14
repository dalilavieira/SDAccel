#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {char* name; } ;
typedef  TYPE_1__ RBinSymbol ;

/* Variables and functions */
 int /*<<< orphan*/  strncmp (char*,char*,int) ; 
 scalar_t__ strstr (char*,char*) ; 

__attribute__((used)) static inline bool check_rust(RBinSymbol *sym) {
	return sym->name && strstr (sym->name, "_$LT$");
}

__attribute__((used)) static inline bool check_objc(RBinSymbol *sym) {
	if (sym->name && !strncmp (sym->name, "_OBJC_", 6)) {
		// free (r_bin_demangle_objc (binfile, sym->name));
		return true;
	}
	return false;
}

__attribute__((used)) static bool check_dlang(RBinSymbol *sym) {
	if (!strncmp (sym->name, "_D2", 3)) {
		return true;
	}
	if (!strncmp (sym->name, "_D4", 3)) {
		return true;
	}
	return false;
}

__attribute__((used)) static bool check_swift(RBinSymbol *sym) {
	if (sym->name && strstr (sym->name, "swift_once")) {
		return true;
	}
	return false;
}

__attribute__((used)) static bool check_cxx(RBinSymbol *sym) {
	if (!strncmp (sym->name, "_Z", 2)) {
		return true;
	}
	if (!strncmp (sym->name, "__Z", 3)) {
		return true;
	}
	return false;
}

__attribute__((used)) static bool check_msvc(RBinSymbol *sym) {
	return *sym->name == '?';
}

