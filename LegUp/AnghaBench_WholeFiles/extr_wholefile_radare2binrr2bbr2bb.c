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
struct TYPE_2__ {char* (* cb ) (char const*) ;char* cmd; } ;

/* Variables and functions */
 TYPE_1__* bbcmds ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 char* stub1 (char const*) ; 

__attribute__((used)) static int run(int i, const char *arg) {
	char *res = bbcmds[i].cb (arg);
	if (res) {
		printf ("%s", res);
		free (res);
		return 0;
	}
	return 1;
}

int main(int argc, char **argv) {
	int i;
	for (i = 0; bbcmds[i].cmd; i++) {
		if (!strcmp (bbcmds[i].cmd, argv[0])) {
			const char *arg = argc > 1? argv[1]: NULL;
			return run (i, arg);
		}
	}
	if (argc > 1) {
		for (i = 0; bbcmds[i].cmd; i++) {
			if (!strcmp (bbcmds[i].cmd, argv[1])) {
				const char *arg = argc > 2? argv[2]: NULL;
				return run (i, arg);
			}
		}
	}
	for (i = 0; bbcmds[i].cmd; i++) {
		printf ("%s\n", bbcmds[i].cmd);
	}
	return 1;
}

