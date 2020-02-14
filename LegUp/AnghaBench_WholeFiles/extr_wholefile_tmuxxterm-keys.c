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
typedef  int u_int ;
struct xterm_keys_entry {char* template; int key; } ;
typedef  int key_code ;

/* Variables and functions */
 int KEYC_CTRL ; 
 int KEYC_ESCAPE ; 
 int KEYC_MASK_KEY ; 
 int KEYC_SHIFT ; 
 int KEYC_XTERM ; 
 int nitems (struct xterm_keys_entry*) ; 
 size_t strcspn (char*,char*) ; 
 char* xstrdup (char*) ; 
static  int xterm_keys_modifiers (char const*,size_t,size_t*,int*) ; 
 struct xterm_keys_entry* xterm_keys_table ; 

__attribute__((used)) static int
xterm_keys_match(const char *template, const char *buf, size_t len,
    size_t *size, key_code *modifiers)
{
	size_t	pos;
	int	retval;

	*modifiers = 0;

	if (len == 0)
		return (0);

	pos = 0;
	do {
		if (*template == '_') {
			retval = xterm_keys_modifiers(buf, len, &pos,
			    modifiers);
			if (retval != 0)
				return (retval);
			continue;
		}
		if (buf[pos] != *template)
			return (-1);
		pos++;
	} while (*++template != '\0' && pos != len);

	if (*template != '\0')	/* partial */
		return (1);

	*size = pos;
	return (0);
}

__attribute__((used)) static int
xterm_keys_modifiers(const char *buf, size_t len, size_t *pos,
    key_code *modifiers)
{
	u_int	flags;

	if (len - *pos < 2)
		return (1);

	if (buf[*pos] < '0' || buf[*pos] > '9')
		return (-1);
	flags = buf[(*pos)++] - '0';
	if (buf[*pos] >= '0' && buf[*pos] <= '9')
		flags = (flags * 10) + (buf[(*pos)++] - '0');
	flags -= 1;

	*modifiers = 0;
	if (flags & 1)
		*modifiers |= KEYC_SHIFT;
	if (flags & 2)
		*modifiers |= KEYC_ESCAPE;
	if (flags & 4)
		*modifiers |= KEYC_CTRL;
	if (flags & 8)
		*modifiers |= KEYC_ESCAPE;
	return (0);
}

int
xterm_keys_find(const char *buf, size_t len, size_t *size, key_code *key)
{
	const struct xterm_keys_entry	*entry;
	u_int				 i;
	int				 matched;
	key_code			 modifiers;

	for (i = 0; i < nitems(xterm_keys_table); i++) {
		entry = &xterm_keys_table[i];

		matched = xterm_keys_match(entry->template, buf, len, size,
		    &modifiers);
		if (matched == -1)
			continue;
		if (matched == 0)
			*key = (entry->key|modifiers|KEYC_XTERM);
		return (matched);
	}
	return (-1);
}

char *
xterm_keys_lookup(key_code key)
{
	const struct xterm_keys_entry	*entry;
	u_int				 i;
	key_code			 modifiers;
	char				*out;

	modifiers = 1;
	if (key & KEYC_SHIFT)
		modifiers += 1;
	if (key & KEYC_ESCAPE)
		modifiers += 2;
	if (key & KEYC_CTRL)
		modifiers += 4;

	/*
	 * If the key has no modifiers, return NULL and let it fall through to
	 * the normal lookup.
	 */
	if (modifiers == 1)
		return (NULL);

	/*
	 * If this has the escape modifier, but was not originally an xterm
	 * key, it may be a genuine escape + key. So don't pass it through as
	 * an xterm key or programs like vi may be confused.
	 */
	if ((key & (KEYC_ESCAPE|KEYC_XTERM)) == KEYC_ESCAPE)
		return (NULL);

	/* Otherwise, find the key in the table. */
	key &= KEYC_MASK_KEY;
	for (i = 0; i < nitems(xterm_keys_table); i++) {
		entry = &xterm_keys_table[i];
		if (key == entry->key)
			break;
	}
	if (i == nitems(xterm_keys_table))
		return (NULL);

	/* Copy the template and replace the modifier. */
	out = xstrdup(entry->template);
	out[strcspn(out, "_")] = '0' + modifiers;
	return (out);
}

