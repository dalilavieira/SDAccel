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
struct rerr {int code; char* name; char* explain; } ;
typedef  int /*<<< orphan*/  convbuf ;
struct TYPE_4__ {int /*<<< orphan*/  re_endp; } ;
typedef  TYPE_1__ RRegex ;

/* Variables and functions */
 int R_REGEX_ATOI ; 
 int R_REGEX_ITOA ; 
 int /*<<< orphan*/  STRLCPY (char*,char*,size_t) ; 
static  char* regatoi (TYPE_1__ const*,char*,int) ; 
 struct rerr* rerrs ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 scalar_t__ strcmp (char*,int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 

size_t
r_regex_error(int errcode, const RRegex *preg, char *errbuf, size_t errbuf_size)
{
	struct rerr *r;
	size_t len;
	int target = errcode &~ R_REGEX_ITOA;
	char *s;
	char convbuf[50];

	if (errcode == R_REGEX_ATOI) {
		s = regatoi(preg, convbuf, sizeof convbuf);
	} else {
		for (r = rerrs; r->code != 0; r++) {
			if (r->code == target) {
				break;
			}
		}

		if (errcode&R_REGEX_ITOA) {
			if (r->code != 0) {
				STRLCPY (convbuf, r->name, sizeof (convbuf)-1);
			} else {
				snprintf (convbuf, sizeof convbuf, "R_REGEX_0x%x", target);
			}
			s = convbuf;
		} else {
			s = r->explain;
		}
	}

	len = strlen(s) + 1;
	if (errbuf_size > 0) {
		STRLCPY(errbuf, s, errbuf_size - 1);
	}

	return len;
}

__attribute__((used)) static char *
regatoi(const RRegex *preg, char *localbuf, int localbufsize)
{
	struct rerr *r;

	for (r = rerrs; r->code != 0; r++) {
		if (strcmp (r->name, preg->re_endp) == 0) {
			break;
		}
	}
	if (r->code == 0) {
		return ("0");
	}

	(void)snprintf(localbuf, localbufsize, "%d", r->code);
	return(localbuf);
}

