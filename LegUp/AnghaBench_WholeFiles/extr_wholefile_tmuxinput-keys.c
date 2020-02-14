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
typedef  int u_int ;
typedef  char u_char ;
struct window_pane {int id; int /*<<< orphan*/  event; struct screen* screen; TYPE_1__* window; } ;
struct utf8_data {int* data; size_t size; } ;
struct screen {int mode; } ;
struct mouse_event {int wp; int b; char sgr_type; int sgr_b; int lb; } ;
struct input_key_ent {int flags; int key; char* data; } ;
typedef  int key_code ;
struct TYPE_2__ {int /*<<< orphan*/  options; } ;

/* Variables and functions */
 int ALL_MOUSE_MODES ; 
 int INPUTKEY_CURSOR ; 
 int INPUTKEY_KEYPAD ; 
 int KEYC_BASE ; 
 int KEYC_ESCAPE ; 
 scalar_t__ KEYC_IS_MOUSE (int) ; 
 int KEYC_XTERM ; 
 int MODE_KCURSOR ; 
 int MODE_KKEYPAD ; 
 int MODE_MOUSE_ALL ; 
 int MODE_MOUSE_BUTTON ; 
 int MODE_MOUSE_SGR ; 
 int MODE_MOUSE_UTF8 ; 
 int MOUSE_BUTTONS (int) ; 
 scalar_t__ MOUSE_DRAG (int) ; 
 scalar_t__ UTF8_DONE ; 
 int /*<<< orphan*/  bufferevent_write (int /*<<< orphan*/ ,char*,size_t) ; 
 scalar_t__ cmd_mouse_at (struct window_pane*,struct mouse_event*,int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
static  void input_key_mouse (struct window_pane*,struct mouse_event*) ; 
 struct input_key_ent* input_keys ; 
 char* key_string_lookup_key (int) ; 
 int /*<<< orphan*/  log_debug (char*,int,...) ; 
 int nitems (struct input_key_ent*) ; 
 scalar_t__ options_get_number (int /*<<< orphan*/ ,char*) ; 
 size_t strlen (char*) ; 
 scalar_t__ utf8_split (int,struct utf8_data*) ; 
 int /*<<< orphan*/  window_pane_visible (struct window_pane*) ; 
 size_t xsnprintf (char*,int,char*,...) ; 
 char* xterm_keys_lookup (int) ; 

__attribute__((used)) static size_t
input_split2(u_int c, u_char *dst)
{
	if (c > 0x7f) {
		dst[0] = (c >> 6) | 0xc0;
		dst[1] = (c & 0x3f) | 0x80;
		return (2);
	}
	dst[0] = c;
	return (1);
}

void
input_key(struct window_pane *wp, key_code key, struct mouse_event *m)
{
	const struct input_key_ent	*ike;
	u_int				 i;
	size_t				 dlen;
	char				*out;
	key_code			 justkey;
	struct utf8_data		 ud;

	log_debug("writing key 0x%llx (%s) to %%%u", key,
	    key_string_lookup_key(key), wp->id);

	/* If this is a mouse key, pass off to mouse function. */
	if (KEYC_IS_MOUSE(key)) {
		if (m != NULL && m->wp != -1 && (u_int)m->wp == wp->id)
			input_key_mouse(wp, m);
		return;
	}

	/*
	 * If this is a normal 7-bit key, just send it, with a leading escape
	 * if necessary. If it is a UTF-8 key, split it and send it.
	 */
	justkey = (key & ~(KEYC_XTERM|KEYC_ESCAPE));
	if (justkey <= 0x7f) {
		if (key & KEYC_ESCAPE)
			bufferevent_write(wp->event, "\033", 1);
		ud.data[0] = justkey;
		bufferevent_write(wp->event, &ud.data[0], 1);
		return;
	}
	if (justkey > 0x7f && justkey < KEYC_BASE) {
		if (utf8_split(justkey, &ud) != UTF8_DONE)
			return;
		if (key & KEYC_ESCAPE)
			bufferevent_write(wp->event, "\033", 1);
		bufferevent_write(wp->event, ud.data, ud.size);
		return;
	}

	/*
	 * Then try to look this up as an xterm key, if the flag to output them
	 * is set.
	 */
	if (options_get_number(wp->window->options, "xterm-keys")) {
		if ((out = xterm_keys_lookup(key)) != NULL) {
			bufferevent_write(wp->event, out, strlen(out));
			free(out);
			return;
		}
	}
	key &= ~KEYC_XTERM;

	/* Otherwise look the key up in the table. */
	for (i = 0; i < nitems(input_keys); i++) {
		ike = &input_keys[i];

		if ((ike->flags & INPUTKEY_KEYPAD) &&
		    !(wp->screen->mode & MODE_KKEYPAD))
			continue;
		if ((ike->flags & INPUTKEY_CURSOR) &&
		    !(wp->screen->mode & MODE_KCURSOR))
			continue;

		if ((key & KEYC_ESCAPE) && (ike->key | KEYC_ESCAPE) == key)
			break;
		if (ike->key == key)
			break;
	}
	if (i == nitems(input_keys)) {
		log_debug("key 0x%llx missing", key);
		return;
	}
	dlen = strlen(ike->data);
	log_debug("found key 0x%llx: \"%s\"", key, ike->data);

	/* Prefix a \033 for escape. */
	if (key & KEYC_ESCAPE)
		bufferevent_write(wp->event, "\033", 1);
	bufferevent_write(wp->event, ike->data, dlen);
}

__attribute__((used)) static void
input_key_mouse(struct window_pane *wp, struct mouse_event *m)
{
	struct screen	*s = wp->screen;
	int		 mode = s->mode;
	char		 buf[40];
	size_t		 len;
	u_int		 x, y;

	if ((mode & ALL_MOUSE_MODES) == 0)
		return;
	if (cmd_mouse_at(wp, m, &x, &y, 0) != 0)
		return;
	if (!window_pane_visible(wp))
		return;

	/* If this pane is not in button or all mode, discard motion events. */
	if (MOUSE_DRAG(m->b) &&
	    (mode & (MODE_MOUSE_BUTTON|MODE_MOUSE_ALL)) == 0)
	    return;

	/*
	 * If this event is a release event and not in all mode, discard it.
	 * In SGR mode we can tell absolutely because a release is normally
	 * shown by the last character. Without SGR, we check if the last
	 * buttons was also a release.
	 */
	if (m->sgr_type != ' ') {
		if (MOUSE_DRAG(m->sgr_b) &&
		    MOUSE_BUTTONS(m->sgr_b) == 3 &&
		    (~mode & MODE_MOUSE_ALL))
			return;
	} else {
		if (MOUSE_DRAG(m->b) &&
		    MOUSE_BUTTONS(m->b) == 3 &&
		    MOUSE_BUTTONS(m->lb) == 3 &&
		    (~mode & MODE_MOUSE_ALL))
			return;
	}

	/*
	 * Use the SGR (1006) extension only if the application requested it
	 * and the underlying terminal also sent the event in this format (this
	 * is because an old style mouse release event cannot be converted into
	 * the new SGR format, since the released button is unknown). Otherwise
	 * pretend that tmux doesn't speak this extension, and fall back to the
	 * UTF-8 (1005) extension if the application requested, or to the
	 * legacy format.
	 */
	if (m->sgr_type != ' ' && (s->mode & MODE_MOUSE_SGR)) {
		len = xsnprintf(buf, sizeof buf, "\033[<%u;%u;%u%c",
		    m->sgr_b, x + 1, y + 1, m->sgr_type);
	} else if (s->mode & MODE_MOUSE_UTF8) {
		if (m->b > 0x7ff - 32 || x > 0x7ff - 33 || y > 0x7ff - 33)
			return;
		len = xsnprintf(buf, sizeof buf, "\033[M");
		len += input_split2(m->b + 32, &buf[len]);
		len += input_split2(x + 33, &buf[len]);
		len += input_split2(y + 33, &buf[len]);
	} else {
		if (m->b > 223)
			return;
		len = xsnprintf(buf, sizeof buf, "\033[M");
		buf[len++] = m->b + 32;
		buf[len++] = x + 33;
		buf[len++] = y + 33;
	}
	log_debug("writing mouse %.*s to %%%u", (int)len, buf, wp->id);
	bufferevent_write(wp->event, buf, len);
}

