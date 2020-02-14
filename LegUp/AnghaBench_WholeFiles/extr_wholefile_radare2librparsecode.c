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
struct TYPE_2__ {int /*<<< orphan*/  sdb_types; } ;
typedef  TYPE_1__ RAnal ;

/* Variables and functions */
 int VT_STRUCT ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 
 char* sdb_anext (char*,char**) ; 
 char* sdb_fmt (char*,char const*,...) ; 
 char* sdb_get (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int sdb_num_get (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 char* strdup (char const*) ; 
 int strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 int /*<<< orphan*/  tcc_sym_push (char*,int,int) ; 

__attribute__((used)) static void appendstring(const char *msg, char **s) {
	if (!s) {
		printf ("%s\n", msg);
	} else if (*s) {
		char *p = malloc (strlen (msg) + strlen (*s) + 1);
		if (!p) {
			return;
		}
		strcpy (p, *s);
		free (*s);
		*s = p;
		strcpy (p + strlen (p), msg);
	} else {
		*s = strdup (msg);
	}
}

__attribute__((used)) static int typeload(void *p, const char *k, const char *v) {
	if (!p) {
		return -1;
	}
	int btype = 0;
	RAnal *anal = (RAnal*)p;
	//r_cons_printf ("tk %s=%s\n", k, v);
	// TODO: Add unions support
	if (!strncmp (v, "struct", 6) && strncmp(k, "struct.", 7)) {
		// structure
		btype = VT_STRUCT;
		const char *typename = k;
		int typesize = 0;
		// TODO: Add typesize here
		char* query = sdb_fmt ("struct.%s", k);
		char *members = sdb_get (anal->sdb_types, query, 0);
		char *next, *ptr = members;
		if (members) {
			do {
				char *name = sdb_anext (ptr, &next);
				if (!name) {
					break;
				}
				query = sdb_fmt ("struct.%s.%s", k, name);
				char *subtype = sdb_get (anal->sdb_types, query, 0);
				if (!subtype) {
					break;
				}
				char *tmp = strchr (subtype, ',');
				if (tmp) {
					*tmp++ = 0;
					tmp = strchr (tmp, ',');
					if (tmp) {
						*tmp++ = 0;
					}
					char *subname = tmp;
					// TODO: Go recurse here
					query = sdb_fmt ("struct.%s.%s.meta", subtype, subname);
					btype = sdb_num_get (anal->sdb_types, query, 0);
					tcc_sym_push (subtype, 0, btype);
				}
				free (subtype);
				ptr = next;
			} while (next);
			free (members);
		}
		tcc_sym_push ((char *)typename, typesize, btype);
	}
	return 0;
}

__attribute__((used)) static void error_func(void *opaque, const char *msg) {
	appendstring (msg, opaque);
	char **p = (char **)opaque;
	if (p && *p) {
		int n = strlen(*p);
		char *ptr = malloc (n + 2);
		if (!ptr) {
			return;
		}
		strcpy (ptr, *p);
		ptr[n] = '\n';
		ptr[n + 1] = 0;
		free (*p);
		*p = ptr;
	}
}

