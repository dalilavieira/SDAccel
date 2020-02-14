#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t wchar_t ;
typedef  size_t u_int ;
typedef  int u_char ;
struct utf8_data {size_t size; int /*<<< orphan*/  data; } ;
typedef  size_t key_code ;
typedef  enum utf8_state { ____Placeholder_utf8_state } utf8_state ;
struct TYPE_3__ {char* string; size_t key; } ;

/* Variables and functions */
 size_t KEYC_ANY ; 
 size_t KEYC_BASE ; 
 size_t KEYC_BSPACE ; 
 size_t KEYC_CTRL ; 
 size_t KEYC_DRAGGING ; 
 size_t KEYC_ESCAPE ; 
 size_t KEYC_FOCUS_IN ; 
 size_t KEYC_FOCUS_OUT ; 
 size_t KEYC_MASK_KEY ; 
 size_t KEYC_MASK_MOD ; 
 size_t KEYC_MOUSE ; 
 size_t KEYC_MOUSEMOVE_BORDER ; 
 size_t KEYC_MOUSEMOVE_PANE ; 
 size_t KEYC_MOUSEMOVE_STATUS ; 
 size_t KEYC_MOUSEMOVE_STATUS_LEFT ; 
 size_t KEYC_MOUSEMOVE_STATUS_RIGHT ; 
 size_t KEYC_NONE ; 
 size_t KEYC_NUSER ; 
 size_t KEYC_PASTE_END ; 
 size_t KEYC_PASTE_START ; 
 size_t KEYC_SHIFT ; 
 size_t KEYC_UNKNOWN ; 
 size_t KEYC_USER ; 
 int UTF8_DONE ; 
 int UTF8_MORE ; 
 TYPE_1__* key_string_table ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,size_t) ; 
 size_t nitems (TYPE_1__*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,size_t) ; 
 int sscanf (char const*,char*,size_t*) ; 
 scalar_t__ strcasecmp (char const*,char*) ; 
 int /*<<< orphan*/  strchr (char const*,size_t) ; 
 int /*<<< orphan*/  strlcat (char*,char*,int) ; 
 size_t strlen (char const*) ; 
 int utf8_append (struct utf8_data*,int) ; 
 int utf8_combine (struct utf8_data*,size_t*) ; 
 int utf8_open (struct utf8_data*,int) ; 
 int utf8_split (size_t,struct utf8_data*) ; 
 int /*<<< orphan*/  xsnprintf (char*,int,char*,size_t) ; 

__attribute__((used)) static key_code
key_string_search_table(const char *string)
{
	u_int	i, user;

	for (i = 0; i < nitems(key_string_table); i++) {
		if (strcasecmp(string, key_string_table[i].string) == 0)
			return (key_string_table[i].key);
	}

	if (sscanf(string, "User%u", &user) == 1 && user < KEYC_NUSER)
		return (KEYC_USER + user);

	return (KEYC_UNKNOWN);
}

__attribute__((used)) static key_code
key_string_get_modifiers(const char **string)
{
	key_code	modifiers;

	modifiers = 0;
	while (((*string)[0] != '\0') && (*string)[1] == '-') {
		switch ((*string)[0]) {
		case 'C':
		case 'c':
			modifiers |= KEYC_CTRL;
			break;
		case 'M':
		case 'm':
			modifiers |= KEYC_ESCAPE;
			break;
		case 'S':
		case 's':
			modifiers |= KEYC_SHIFT;
			break;
		default:
			*string = NULL;
			return (0);
		}
		*string += 2;
	}
	return (modifiers);
}

key_code
key_string_lookup_string(const char *string)
{
	static const char	*other = "!#()+,-.0123456789:;<=>?'\r\t";
	key_code		 key;
	u_int			 u;
	key_code		 modifiers;
	struct utf8_data	 ud;
	u_int			 i;
	enum utf8_state		 more;
	wchar_t			 wc;

	/* Is this no key or any key? */
	if (strcasecmp(string, "None") == 0)
		return (KEYC_NONE);
	if (strcasecmp(string, "Any") == 0)
		return (KEYC_ANY);

	/* Is this a hexadecimal value? */
	if (string[0] == '0' && string[1] == 'x') {
	        if (sscanf(string + 2, "%x", &u) != 1)
	                return (KEYC_UNKNOWN);
		if (u > 0x1fffff)
	                return (KEYC_UNKNOWN);
	        return (u);
	}

	/* Check for modifiers. */
	modifiers = 0;
	if (string[0] == '^' && string[1] != '\0') {
		modifiers |= KEYC_CTRL;
		string++;
	}
	modifiers |= key_string_get_modifiers(&string);
	if (string == NULL || string[0] == '\0')
		return (KEYC_UNKNOWN);

	/* Is this a standard ASCII key? */
	if (string[1] == '\0' && (u_char)string[0] <= 127) {
		key = (u_char)string[0];
		if (key < 32 || key == 127)
			return (KEYC_UNKNOWN);
	} else {
		/* Try as a UTF-8 key. */
		if ((more = utf8_open(&ud, (u_char)*string)) == UTF8_MORE) {
			if (strlen(string) != ud.size)
				return (KEYC_UNKNOWN);
			for (i = 1; i < ud.size; i++)
				more = utf8_append(&ud, (u_char)string[i]);
			if (more != UTF8_DONE)
				return (KEYC_UNKNOWN);
			if (utf8_combine(&ud, &wc) != UTF8_DONE)
				return (KEYC_UNKNOWN);
			return (wc | modifiers);
		}

		/* Otherwise look the key up in the table. */
		key = key_string_search_table(string);
		if (key == KEYC_UNKNOWN)
			return (KEYC_UNKNOWN);
	}

	/* Convert the standard control keys. */
	if (key < KEYC_BASE && (modifiers & KEYC_CTRL) && !strchr(other, key)) {
		if (key >= 97 && key <= 122)
			key -= 96;
		else if (key >= 64 && key <= 95)
			key -= 64;
		else if (key == 32)
			key = 0;
		else if (key == 63)
			key = KEYC_BSPACE;
		else
			return (KEYC_UNKNOWN);
		modifiers &= ~KEYC_CTRL;
	}

	return (key | modifiers);
}

const char *
key_string_lookup_key(key_code key)
{
	static char		out[32];
	char			tmp[8];
	u_int			i;
	struct utf8_data	ud;
	size_t			off;

	*out = '\0';

	/* Handle no key. */
	if (key == KEYC_NONE)
		return ("None");

	/* Handle special keys. */
	if (key == KEYC_UNKNOWN)
		return ("Unknown");
	if (key == KEYC_ANY)
		return ("Any");
	if (key == KEYC_FOCUS_IN)
		return ("FocusIn");
	if (key == KEYC_FOCUS_OUT)
		return ("FocusOut");
	if (key == KEYC_PASTE_START)
		return ("PasteStart");
	if (key == KEYC_PASTE_END)
		return ("PasteEnd");
	if (key == KEYC_MOUSE)
		return ("Mouse");
	if (key == KEYC_DRAGGING)
		return ("Dragging");
	if (key == KEYC_MOUSEMOVE_PANE)
		return ("MouseMovePane");
	if (key == KEYC_MOUSEMOVE_STATUS)
		return ("MouseMoveStatus");
	if (key == KEYC_MOUSEMOVE_STATUS_LEFT)
		return ("MouseMoveStatusLeft");
	if (key == KEYC_MOUSEMOVE_STATUS_RIGHT)
		return ("MouseMoveStatusRight");
	if (key == KEYC_MOUSEMOVE_BORDER)
		return ("MouseMoveBorder");
	if (key >= KEYC_USER && key < KEYC_USER + KEYC_NUSER) {
		snprintf(out, sizeof out, "User%u", (u_int)(key - KEYC_USER));
		return (out);
	}

	/*
	 * Special case: display C-@ as C-Space. Could do this below in
	 * the (key >= 0 && key <= 32), but this way we let it be found
	 * in key_string_table, for the unlikely chance that we might
	 * change its name.
	 */
	if ((key & KEYC_MASK_KEY) == 0)
	    key = ' ' | KEYC_CTRL | (key & KEYC_MASK_MOD);

	/* Fill in the modifiers. */
	if (key & KEYC_CTRL)
		strlcat(out, "C-", sizeof out);
	if (key & KEYC_ESCAPE)
		strlcat(out, "M-", sizeof out);
	if (key & KEYC_SHIFT)
		strlcat(out, "S-", sizeof out);
	key &= KEYC_MASK_KEY;

	/* Try the key against the string table. */
	for (i = 0; i < nitems(key_string_table); i++) {
		if (key == key_string_table[i].key)
			break;
	}
	if (i != nitems(key_string_table)) {
		strlcat(out, key_string_table[i].string, sizeof out);
		return (out);
	}

	/* Is this a UTF-8 key? */
	if (key > 127 && key < KEYC_BASE) {
		if (utf8_split(key, &ud) == UTF8_DONE) {
			off = strlen(out);
			memcpy(out + off, ud.data, ud.size);
			out[off + ud.size] = '\0';
			return (out);
		}
	}

	/* Invalid keys are errors. */
	if (key == 127 || key > 255) {
		snprintf(out, sizeof out, "Invalid#%llx", key);
		return (out);
	}

	/* Check for standard or control key. */
	if (key <= 32) {
		if (key == 0 || key > 26)
			xsnprintf(tmp, sizeof tmp, "C-%c", (int)(64 + key));
		else
			xsnprintf(tmp, sizeof tmp, "C-%c", (int)(96 + key));
	} else if (key >= 32 && key <= 126) {
		tmp[0] = key;
		tmp[1] = '\0';
	} else if (key >= 128)
		xsnprintf(tmp, sizeof tmp, "\\%llo", key);

	strlcat(out, tmp, sizeof out);
	return (out);
}

