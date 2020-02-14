#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut64 ;
typedef  int /*<<< orphan*/  ut32 ;
struct TYPE_7__ {char* (* cmdstrf ) (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  core; } ;
struct TYPE_10__ {TYPE_1__ coreb; } ;
struct TYPE_8__ {TYPE_4__* anal; } ;
struct TYPE_9__ {TYPE_2__ analb; } ;
typedef  TYPE_3__ RParse ;
typedef  int /*<<< orphan*/  RAnalFunction ;
typedef  TYPE_4__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  r_cons_pop () ; 
 int /*<<< orphan*/  r_cons_push () ; 
 int /*<<< orphan*/  r_num_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char*,char*,int) ; 
 char* stub1 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static char* get_fcn_name(RAnal *anal, ut32 fcn_id) {
	r_cons_push ();
	char *s = anal->coreb.cmdstrf (anal->coreb.core, "is~FUNC[6:%u]", fcn_id);
	r_cons_pop ();
	if (s) {
		size_t namelen = strlen (s);
		s[namelen - 1] = 0;
	}
	return s;
}

__attribute__((used)) static bool varsub(RParse *p, RAnalFunction *f, ut64 addr, int oplen, char *data, char *str, int len) {
	char *fcn_name = NULL;
	str[0] = 0;
	if (!strncmp (data, "call ", 5)) {
		ut32 fcn_id = (ut32) r_num_get (NULL, data + 5);
		if (!(fcn_name = get_fcn_name (p->analb.anal, fcn_id))) {
			return false;
		}
		snprintf (str, len, "call sym.%s", fcn_name);
		free (fcn_name);
		return true;
	}
	return false;
}

