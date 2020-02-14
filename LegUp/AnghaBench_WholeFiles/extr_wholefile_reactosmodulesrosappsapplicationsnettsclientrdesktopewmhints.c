#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32 ;
struct TYPE_19__ {unsigned int* l; } ;
struct TYPE_20__ {int format; TYPE_1__ data; void* message_type; void* window; } ;
struct TYPE_22__ {TYPE_2__ xclient; void* type; } ;
typedef  TYPE_4__ XEvent ;
typedef  void* Window ;
struct TYPE_21__ {int state_maximized_vert_atom; int state_maximized_horz_atom; int state_hidden_atom; scalar_t__ state_skip_taskbar_atom; scalar_t__ state_skip_pager_atom; scalar_t__ state_modal_atom; void* utf8_string_atom; void* name_atom; } ;
struct TYPE_23__ {TYPE_3__ ewmhints; int /*<<< orphan*/  display; void* net_wm_desktop_atom; void* net_wm_state_atom; } ;
typedef  int /*<<< orphan*/  Status ;
typedef  TYPE_5__ RDPCLIENT ;
typedef  scalar_t__ BOOL ;
typedef  scalar_t__ Atom ;

/* Variables and functions */
 int /*<<< orphan*/  AnyPropertyType ; 
 void* ClientMessage ; 
 void* DefaultRootWindow (int /*<<< orphan*/ ) ; 
 scalar_t__ False ; 
 scalar_t__ None ; 
 int /*<<< orphan*/  PropModeAppend ; 
 int /*<<< orphan*/  PropModeReplace ; 
 int SEAMLESSRDP_MAXIMIZED ; 
 int SEAMLESSRDP_MINIMIZED ; 
 int SEAMLESSRDP_NORMAL ; 
 int SubstructureNotifyMask ; 
 int SubstructureRedirectMask ; 
 int Success ; 
 scalar_t__ True ; 
 int WithdrawnState ; 
 void* XA_ATOM ; 
 int /*<<< orphan*/  XChangeProperty (int /*<<< orphan*/ ,void*,void*,void*,int,int /*<<< orphan*/ ,unsigned char*,int) ; 
 int /*<<< orphan*/  XFree (unsigned char*) ; 
 int XGetWindowProperty (int /*<<< orphan*/ ,void*,scalar_t__,int /*<<< orphan*/ ,long,scalar_t__,int /*<<< orphan*/ ,scalar_t__*,int*,unsigned long*,unsigned long*,unsigned char**) ; 
 void* XInternAtom (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  XSendEvent (int /*<<< orphan*/ ,void*,scalar_t__,int,TYPE_4__*) ; 
 unsigned int _NET_WM_STATE_ADD ; 
 unsigned int _NET_WM_STATE_REMOVE ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  memmove (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  stderr ; 
 int strlen (char const*) ; 

__attribute__((used)) static int
get_property_value(RDPCLIENT * This, Window wnd, char *propname, long max_length,
		   unsigned long *nitems_return, unsigned char **prop_return, int nowarn)
{
	int result;
	Atom property;
	Atom actual_type_return;
	int actual_format_return;
	unsigned long bytes_after_return;

	property = XInternAtom(This->display, propname, True);
	if (property == None)
	{
		fprintf(stderr, "Atom %s does not exist\n", propname);
		return (-1);
	}

	result = XGetWindowProperty(This->display, wnd, property, 0,	/* long_offset */
				    max_length,	/* long_length */
				    False,	/* delete */
				    AnyPropertyType,	/* req_type */
				    &actual_type_return,
				    &actual_format_return,
				    nitems_return, &bytes_after_return, prop_return);

	if (result != Success)
	{
		fprintf(stderr, "XGetWindowProperty failed\n");
		return (-1);
	}

	if (actual_type_return == None || actual_format_return == 0)
	{
		if (!nowarn)
			fprintf(stderr, "Window is missing property %s\n", propname);
		return (-1);
	}

	if (bytes_after_return)
	{
		fprintf(stderr, "%s is too big for me\n", propname);
		return (-1);
	}

	if (actual_format_return != 32)
	{
		fprintf(stderr, "%s has bad format\n", propname);
		return (-1);
	}

	return (0);
}

__attribute__((used)) static int
get_current_desktop(RDPCLIENT * This)
{
	unsigned long nitems_return;
	unsigned char *prop_return;
	int current_desktop;

	if (get_property_value
	    (This, DefaultRootWindow(This->display), "_NET_CURRENT_DESKTOP", 1, &nitems_return,
	     &prop_return, 0) < 0)
		return (-1);

	if (nitems_return != 1)
	{
		fprintf(stderr, "_NET_CURRENT_DESKTOP has bad length\n");
		return (-1);
	}

	current_desktop = *prop_return;
	XFree(prop_return);
	return current_desktop;
}

int
get_current_workarea(RDPCLIENT * This, uint32 * x, uint32 * y, uint32 * width, uint32 * height)
{
	int current_desktop;
	unsigned long nitems_return;
	unsigned char *prop_return;
	uint32 *return_words;
	const uint32 net_workarea_x_offset = 0;
	const uint32 net_workarea_y_offset = 1;
	const uint32 net_workarea_width_offset = 2;
	const uint32 net_workarea_height_offset = 3;
	const uint32 max_prop_length = 32 * 4;	/* Max 32 desktops */

	if (get_property_value
	    (This, DefaultRootWindow(This->display), "_NET_WORKAREA", max_prop_length, &nitems_return,
	     &prop_return, 0) < 0)
		return (-1);

	if (nitems_return % 4)
	{
		fprintf(stderr, "_NET_WORKAREA has odd length\n");
		return (-1);
	}

	current_desktop = get_current_desktop(This);

	if (current_desktop < 0)
		return -1;

	return_words = (uint32 *) prop_return;

	*x = return_words[current_desktop * 4 + net_workarea_x_offset];
	*y = return_words[current_desktop * 4 + net_workarea_y_offset];
	*width = return_words[current_desktop * 4 + net_workarea_width_offset];
	*height = return_words[current_desktop * 4 + net_workarea_height_offset];

	XFree(prop_return);

	return (0);

}

void
ewmh_init(RDPCLIENT * This)
{
	/* FIXME: Use XInternAtoms */
	This->ewmhints.state_maximized_vert_atom =
		XInternAtom(This->display, "_NET_WM_STATE_MAXIMIZED_VERT", False);
	This->ewmhints.state_maximized_horz_atom =
		XInternAtom(This->display, "_NET_WM_STATE_MAXIMIZED_HORZ", False);
	This->ewmhints.state_hidden_atom = XInternAtom(This->display, "_NET_WM_STATE_HIDDEN", False);
	This->ewmhints.state_skip_taskbar_atom =
		XInternAtom(This->display, "_NET_WM_STATE_SKIP_TASKBAR", False);
	This->ewmhints.state_skip_pager_atom = XInternAtom(This->display, "_NET_WM_STATE_SKIP_PAGER", False);
	This->ewmhints.state_modal_atom = XInternAtom(This->display, "_NET_WM_STATE_MODAL", False);
	This->net_wm_state_atom = XInternAtom(This->display, "_NET_WM_STATE", False);
	This->net_wm_desktop_atom = XInternAtom(This->display, "_NET_WM_DESKTOP", False);
	This->ewmhints.name_atom = XInternAtom(This->display, "_NET_WM_NAME", False);
	This->ewmhints.utf8_string_atom = XInternAtom(This->display, "UTF8_STRING", False);
}

int
ewmh_get_window_state(RDPCLIENT * This, Window w)
{
	unsigned long nitems_return;
	unsigned char *prop_return;
	uint32 *return_words;
	unsigned long item;
	BOOL maximized_vert, maximized_horz, hidden;

	maximized_vert = maximized_horz = hidden = False;

	if (get_property_value(This, w, "_NET_WM_STATE", 64, &nitems_return, &prop_return, 0) < 0)
		return SEAMLESSRDP_NORMAL;

	return_words = (uint32 *) prop_return;

	for (item = 0; item < nitems_return; item++)
	{
		if (return_words[item] == This->ewmhints.state_maximized_vert_atom)
			maximized_vert = True;
		if (return_words[item] == This->ewmhints.state_maximized_horz_atom)
			maximized_horz = True;
		if (return_words[item] == This->ewmhints.state_hidden_atom)
			hidden = True;
	}

	XFree(prop_return);

	if (maximized_vert && maximized_horz)
		return SEAMLESSRDP_MAXIMIZED;
	else if (hidden)
		return SEAMLESSRDP_MINIMIZED;
	else
		return SEAMLESSRDP_NORMAL;
}

__attribute__((used)) static int
ewmh_modify_state(RDPCLIENT * This, Window wnd, int add, Atom atom1, Atom atom2)
{
	Status status;
	XEvent xevent;

	int result;
	unsigned long nitems;
	unsigned char *props;
	uint32 state = WithdrawnState;

	/* The spec states that the window manager must respect any
	   _NET_WM_STATE attributes on a withdrawn window. In order words, we
	   modify the attributes directly for withdrawn windows and ask the WM
	   to do it for active windows. */
	result = get_property_value(This, wnd, "WM_STATE", 64, &nitems, &props, 1);
	if ((result >= 0) && nitems)
	{
		state = *(uint32 *) props;
		XFree(props);
	}

	if (state == WithdrawnState)
	{
		if (add)
		{
			Atom atoms[2];

			atoms[0] = atom1;
			nitems = 1;
			if (atom2)
			{
				atoms[1] = atom2;
				nitems = 2;
			}

			XChangeProperty(This->display, wnd, This->net_wm_state_atom, XA_ATOM,
					32, PropModeAppend, (unsigned char *) atoms, nitems);
		}
		else
		{
			Atom *atoms;
			int i;

			if (get_property_value(This, wnd, "_NET_WM_STATE", 64, &nitems, &props, 1) < 0)
				return 0;

			atoms = (Atom *) props;

			for (i = 0; i < nitems; i++)
			{
				if ((atoms[i] == atom1) || (atom2 && (atoms[i] == atom2)))
				{
					if (i != (nitems - 1))
						memmove(&atoms[i], &atoms[i + 1],
							sizeof(Atom) * (nitems - i - 1));
					nitems--;
					i--;
				}
			}

			XChangeProperty(This->display, wnd, This->net_wm_state_atom, XA_ATOM,
					32, PropModeReplace, (unsigned char *) atoms, nitems);

			XFree(props);
		}

		return 0;
	}

	xevent.type = ClientMessage;
	xevent.xclient.window = wnd;
	xevent.xclient.message_type = This->net_wm_state_atom;
	xevent.xclient.format = 32;
	if (add)
		xevent.xclient.data.l[0] = _NET_WM_STATE_ADD;
	else
		xevent.xclient.data.l[0] = _NET_WM_STATE_REMOVE;
	xevent.xclient.data.l[1] = atom1;
	xevent.xclient.data.l[2] = atom2;
	xevent.xclient.data.l[3] = 0;
	xevent.xclient.data.l[4] = 0;
	status = XSendEvent(This->display, DefaultRootWindow(This->display), False,
			    SubstructureNotifyMask | SubstructureRedirectMask, &xevent);
	if (!status)
		return -1;

	return 0;
}

int
ewmh_change_state(RDPCLIENT * This, Window wnd, int state)
{
	/*
	 * Deal with the max atoms
	 */
	if (state == SEAMLESSRDP_MAXIMIZED)
	{
		if (ewmh_modify_state
		    (This, wnd, 1, This->ewmhints.state_maximized_vert_atom,
		     This->ewmhints.state_maximized_horz_atom) < 0)
			return -1;
	}
	else
	{
		if (ewmh_modify_state
		    (This, wnd, 0, This->ewmhints.state_maximized_vert_atom,
		     This->ewmhints.state_maximized_horz_atom) < 0)
			return -1;
	}

	return 0;
}

int
ewmh_get_window_desktop(RDPCLIENT * This, Window wnd)
{
	unsigned long nitems_return;
	unsigned char *prop_return;
	int desktop;

	if (get_property_value(This, wnd, "_NET_WM_DESKTOP", 1, &nitems_return, &prop_return, 0) < 0)
		return (-1);

	if (nitems_return != 1)
	{
		fprintf(stderr, "_NET_WM_DESKTOP has bad length\n");
		return (-1);
	}

	desktop = *prop_return;
	XFree(prop_return);
	return desktop;
}

int
ewmh_move_to_desktop(RDPCLIENT * This, Window wnd, unsigned int desktop)
{
	Status status;
	XEvent xevent;

	xevent.type = ClientMessage;
	xevent.xclient.window = wnd;
	xevent.xclient.message_type = This->net_wm_desktop_atom;
	xevent.xclient.format = 32;
	xevent.xclient.data.l[0] = desktop;
	xevent.xclient.data.l[1] = 0;
	xevent.xclient.data.l[2] = 0;
	xevent.xclient.data.l[3] = 0;
	xevent.xclient.data.l[4] = 0;
	status = XSendEvent(This->display, DefaultRootWindow(This->display), False,
			    SubstructureNotifyMask | SubstructureRedirectMask, &xevent);
	if (!status)
		return -1;

	return 0;
}

void
ewmh_set_wm_name(RDPCLIENT * This, Window wnd, const char *title)
{
	int len;

	len = strlen(title);
	XChangeProperty(This->display, wnd, This->ewmhints.name_atom, This->ewmhints.utf8_string_atom,
			8, PropModeReplace, (unsigned char *) title, len);
}

int
ewmh_set_window_popup(RDPCLIENT * This, Window wnd)
{
	if (ewmh_modify_state
	    (This, wnd, 1, This->ewmhints.state_skip_taskbar_atom, This->ewmhints.state_skip_pager_atom) < 0)
		return -1;
	return 0;
}

int
ewmh_set_window_modal(RDPCLIENT * This, Window wnd)
{
	if (ewmh_modify_state(This, wnd, 1, This->ewmhints.state_modal_atom, 0) < 0)
		return -1;
	return 0;
}

