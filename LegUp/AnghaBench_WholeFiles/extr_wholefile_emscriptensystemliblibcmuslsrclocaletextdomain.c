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

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 size_t NAME_MAX ; 
 char* current_domain ; 
 char* dgettext (int /*<<< orphan*/ ,char const*) ; 
 char* dngettext (int /*<<< orphan*/ ,char const*,char const*,unsigned long) ; 
 int /*<<< orphan*/  errno ; 
 char* malloc (size_t) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 size_t strlen (char const*) ; 

char *__gettextdomain()
{
	return current_domain ? current_domain : "messages";
}

char *textdomain(const char *domainname)
{
	if (!domainname) return __gettextdomain();

	size_t domlen = strlen(domainname);
	if (domlen > NAME_MAX) {
		errno = EINVAL;
		return 0;
	}

	if (!current_domain) {
		current_domain = malloc(NAME_MAX+1);
		if (!current_domain) return 0;
	}

	memcpy(current_domain, domainname, domlen+1);

	return current_domain;
}

char *gettext(const char *msgid)
{
	return dgettext(0, msgid);
}

char *ngettext(const char *msgid1, const char *msgid2, unsigned long int n)
{
	return dngettext(0, msgid1, msgid2, n);
}

