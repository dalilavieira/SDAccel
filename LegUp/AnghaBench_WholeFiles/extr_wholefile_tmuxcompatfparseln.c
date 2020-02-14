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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int FPARSELN_UNESCALL ; 
 int FPARSELN_UNESCCOMM ; 
 int FPARSELN_UNESCCONT ; 
 int FPARSELN_UNESCESC ; 
 int FPARSELN_UNESCREST ; 
 char* fgetln (int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 
 char* realloc (char*,size_t) ; 
 int /*<<< orphan*/ * strchr (char*,char) ; 
 size_t strlen (char*) ; 

__attribute__((used)) static int
isescaped(const char *sp, const char *p, int esc)
{
	const char     *cp;
	size_t		ne;

	/* No escape character */
	if (esc == '\0')
		return 1;

	/* Count the number of escape characters that precede ours */
	for (ne = 0, cp = p; --cp >= sp && *cp == esc; ne++)
		continue;

	/* Return true if odd number of escape characters */
	return (ne & 1) != 0;
}

char *
fparseln(FILE *fp, size_t *size, size_t *lineno, const char str[3],
    int flags)
{
	static const char dstr[3] = { '\\', '\\', '#' };
	char	*buf = NULL, *ptr, *cp, esc, con, nl, com;
	size_t	s, len = 0;
	int	cnt = 1;

	if (str == NULL)
		str = dstr;

	esc = str[0];
	con = str[1];
	com = str[2];

	/*
	 * XXX: it would be cool to be able to specify the newline character,
	 * but unfortunately, fgetln does not let us
	 */
	nl  = '\n';

	while (cnt) {
		cnt = 0;

		if (lineno)
			(*lineno)++;

		if ((ptr = fgetln(fp, &s)) == NULL)
			break;

		if (s && com) {		/* Check and eliminate comments */
			for (cp = ptr; cp < ptr + s; cp++)
				if (*cp == com && !isescaped(ptr, cp, esc)) {
					s = cp - ptr;
					cnt = s == 0 && buf == NULL;
					break;
				}
		}

		if (s && nl) {		/* Check and eliminate newlines */
			cp = &ptr[s - 1];

			if (*cp == nl)
				s--;	/* forget newline */
		}

		if (s && con) {		/* Check and eliminate continuations */
			cp = &ptr[s - 1];

			if (*cp == con && !isescaped(ptr, cp, esc)) {
				s--;	/* forget escape */
				cnt = 1;
			}
		}

		if (s == 0 && buf != NULL)
			continue;

		if ((cp = realloc(buf, len + s + 1)) == NULL) {
			free(buf);
			return NULL;
		}
		buf = cp;

		(void) memcpy(buf + len, ptr, s);
		len += s;
		buf[len] = '\0';
	}

	if ((flags & FPARSELN_UNESCALL) != 0 && esc && buf != NULL &&
	    strchr(buf, esc) != NULL) {
		ptr = cp = buf;
		while (cp[0] != '\0') {
			int skipesc;

			while (cp[0] != '\0' && cp[0] != esc)
				*ptr++ = *cp++;
			if (cp[0] == '\0' || cp[1] == '\0')
				break;

			skipesc = 0;
			if (cp[1] == com)
				skipesc += (flags & FPARSELN_UNESCCOMM);
			if (cp[1] == con)
				skipesc += (flags & FPARSELN_UNESCCONT);
			if (cp[1] == esc)
				skipesc += (flags & FPARSELN_UNESCESC);
			if (cp[1] != com && cp[1] != con && cp[1] != esc)
				skipesc = (flags & FPARSELN_UNESCREST);

			if (skipesc)
				cp++;
			else
				*ptr++ = *cp++;
			*ptr++ = *cp++;
		}
		*ptr = '\0';
		len = strlen(buf);
	}

	if (size)
		*size = len;
	return buf;
}

