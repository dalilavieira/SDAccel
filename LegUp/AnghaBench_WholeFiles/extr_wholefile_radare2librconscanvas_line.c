#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int color; int symbol; int dot_style; } ;
struct TYPE_14__ {TYPE_2__* context; scalar_t__ dotted_lines; } ;
struct TYPE_13__ {scalar_t__ sy; scalar_t__ h; scalar_t__ sx; scalar_t__ w; int /*<<< orphan*/  attr; int /*<<< orphan*/  color; } ;
struct TYPE_11__ {int /*<<< orphan*/  graph_trufae; int /*<<< orphan*/  graph_false; int /*<<< orphan*/  graph_true; } ;
struct TYPE_12__ {TYPE_1__ pal; } ;
typedef  TYPE_3__ RConsCanvas ;
typedef  TYPE_4__ RCons ;
typedef  TYPE_5__ RCanvasLineStyle ;

/* Variables and functions */
#define  APEX_DOT 145 
 int /*<<< orphan*/  Color_RESET ; 
 char* DASHED_LINE_HORIZ ; 
 char* DASHED_LINE_VERT ; 
 char* DOTTED_LINE_HORIZ ; 
 char* DOTTED_LINE_VERT ; 
#define  DOT_APEX 144 
#define  DOT_DOT 143 
#define  DOT_NRM 142 
#define  DOT_STYLE_BACKEDGE 141 
#define  DOT_STYLE_CONDITIONAL 140 
#define  DOT_STYLE_NORMAL 139 
 scalar_t__ G (int,int) ; 
#define  LINE_FALSE 138 
#define  LINE_NONE 137 
#define  LINE_NOSYM_HORIZ 136 
#define  LINE_NOSYM_VERT 135 
#define  LINE_TRUE 134 
#define  LINE_UNCJMP 133 
#define  NRM_APEX 132 
#define  NRM_DOT 131 
#define  NRM_NRM 130 
#define  REV_APEX_APEX 129 
#define  REV_APEX_NRM 128 
 char* RUNECODESTR_CORNER_BL ; 
 char* RUNECODESTR_CORNER_BR ; 
 char* RUNECODESTR_CORNER_TL ; 
 char* RUNECODESTR_CORNER_TR ; 
 char* RUNECODESTR_CURVE_CORNER_BL ; 
 char* RUNECODESTR_CURVE_CORNER_BR ; 
 char* RUNECODESTR_CURVE_CORNER_TL ; 
 char* RUNECODESTR_CURVE_CORNER_TR ; 
 char* RUNECODESTR_LINE_HORIZ ; 
 char* RUNECODESTR_LINE_VERT ; 
 int /*<<< orphan*/  W (char const*) ; 
 int /*<<< orphan*/  r_cons_break_pop () ; 
 int /*<<< orphan*/  r_cons_break_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ r_cons_is_breaked () ; 
 TYPE_4__* r_cons_singleton () ; 
 scalar_t__ useUtf8 ; 
 int /*<<< orphan*/  useUtf8Curvy ; 

__attribute__((used)) static char* utf8_line_vert (int dot_style) {
	if (r_cons_singleton ()->dotted_lines) {
		switch (dot_style) {
		case DOT_STYLE_NORMAL:      return RUNECODESTR_LINE_VERT;
		case DOT_STYLE_CONDITIONAL: return DOTTED_LINE_VERT;
		case DOT_STYLE_BACKEDGE:    return DASHED_LINE_VERT;
		}
	}
	return RUNECODESTR_LINE_VERT;
}

__attribute__((used)) static char* utf8_line_horiz (int dot_style) {
	if (r_cons_singleton ()->dotted_lines) {
		switch (dot_style) {
		case DOT_STYLE_NORMAL:      return RUNECODESTR_LINE_HORIZ;
		case DOT_STYLE_CONDITIONAL: return DOTTED_LINE_HORIZ;
		case DOT_STYLE_BACKEDGE:    return DASHED_LINE_HORIZ;
		}
	}
	return RUNECODESTR_LINE_HORIZ;
}

__attribute__((used)) static void apply_line_style(RConsCanvas *c, int x, int y, int x2, int y2,
		RCanvasLineStyle *style, int isvert) {
	RCons *cons = r_cons_singleton ();
	switch (style->color) {
	case LINE_UNCJMP:
		c->attr = cons->context->pal.graph_trufae;
		break;
	case LINE_TRUE:
		c->attr = cons->context->pal.graph_true;
		break;
	case LINE_FALSE:
		c->attr = cons->context->pal.graph_false;
		break;
	case LINE_NONE:
	default:
		c->attr = cons->context->pal.graph_trufae;
		break;
	}
	if (!c->color) {
		c->attr = Color_RESET;
	}
	switch (style->symbol) {
	case LINE_UNCJMP:
		if (G (x, y)) {
			if (isvert) {
				W ("v");
			} else {
				W (">");
			}
		}
		break;
	case LINE_TRUE:
		if (G (x, y)) {
			W ("t"); //\\");
		}
		break;
	case LINE_FALSE:
		if (G (x, y)) {
			W ("f");
		}
		break;
	case LINE_NOSYM_VERT:
		if (G (x, y)) {
			W (useUtf8 ? utf8_line_vert (style->dot_style) : "|");
		}
		break;
	case LINE_NOSYM_HORIZ:
		if (G (x, y)) {
			W (useUtf8 ? utf8_line_horiz (style->dot_style) : "-");
		}
		break;
	case LINE_NONE:
	default:
		break;
	}
}

__attribute__((used)) static void draw_horizontal_line (RConsCanvas *c, int x, int y, int width, int style, int dot_style) {
	const char *l_corner = "?", *r_corner = "?";
	int i;

	if (width < 1) {
		return;
	}
	/* do not render offscreen horizontal lines */
	if (y + c->sy < 0) {
		return;
	}
	if (y + c->sy > c->h) {
		return;
	}

	switch (style) {
	case APEX_DOT:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_BL;
				r_corner = RUNECODESTR_CURVE_CORNER_TR;
			} else {
				l_corner = RUNECODESTR_CORNER_BL;
				r_corner = RUNECODESTR_CORNER_TR;
			}
		} else {
			l_corner = "'";
			r_corner = ".";
		}
		break;
	case DOT_APEX:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_TL;
				r_corner = RUNECODESTR_CURVE_CORNER_BR;
			} else {
				l_corner = RUNECODESTR_CORNER_TL;
				r_corner = RUNECODESTR_CORNER_BR;
			}
		} else {
			l_corner = ".";
			r_corner = "'";
		}
		break;
	case REV_APEX_APEX:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_BL;
				r_corner = RUNECODESTR_CURVE_CORNER_BR;
			} else {
				l_corner = RUNECODESTR_CORNER_BL;
				r_corner = RUNECODESTR_CORNER_BR;
			}
		} else {
			l_corner = "`";
			r_corner = "'";
		}
		break;
	case DOT_DOT:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_TL;
				r_corner = RUNECODESTR_CURVE_CORNER_TR;
			} else {
				l_corner = RUNECODESTR_CORNER_TL;
				r_corner = RUNECODESTR_CORNER_TR;
			}
		} else {
			l_corner = r_corner = ".";
		}
		break;
	case NRM_DOT:
		if (useUtf8) {
			l_corner = utf8_line_horiz (dot_style);
			if (useUtf8Curvy) {
				r_corner = RUNECODESTR_CURVE_CORNER_TR;
			} else {
				r_corner = RUNECODESTR_CORNER_TR;
			}
		} else {
			l_corner = "-";
			r_corner = ".";
		}
		break;
	case NRM_APEX:
		if (useUtf8) {
			l_corner = utf8_line_horiz (dot_style);
			if (useUtf8Curvy) {
				r_corner = RUNECODESTR_CURVE_CORNER_BR;
			} else {
				r_corner = RUNECODESTR_CORNER_BR;
			}
		} else {
			l_corner = "-";
			r_corner = "'";
		}
		break;
	case DOT_NRM:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_TL;
			} else {
				l_corner = RUNECODESTR_CORNER_TL;
			}
			r_corner = utf8_line_horiz (dot_style);
		} else {
			l_corner = ".";
			r_corner = "-";
		}
		break;
	case REV_APEX_NRM:
		if (useUtf8) {
			if (useUtf8Curvy) {
				l_corner = RUNECODESTR_CURVE_CORNER_BL;
			} else {
				l_corner = RUNECODESTR_CORNER_BL;
			}
			r_corner = utf8_line_horiz (dot_style);
		} else {
			l_corner = "`";
			r_corner = "-";
		}
		break;
	case NRM_NRM:
	default:
		if (useUtf8) {
			l_corner = r_corner = utf8_line_horiz (dot_style);
		} else {
			l_corner = r_corner = "-";
		}
		break;
	}

	if (G (x, y)) {
		W (l_corner);
	}

	const char *hline = useUtf8 ? utf8_line_horiz (dot_style) : "-";
	r_cons_break_push (NULL, NULL);
	for (i = x + 1; i < x + width - 1; i++) {
		if (r_cons_is_breaked ()) {
			break;
		}
		if (G (i, y)) {
			W (hline);
		}
	}
	r_cons_break_pop ();

	if (G (x + width - 1, y)) {
		W (r_corner);
	}
}

__attribute__((used)) static void draw_vertical_line (RConsCanvas *c, int x, int y, int height, int dot_style) {
	int i;
	/* do not render offscreen vertical lines */
	if (x + c->sx < 0) {
		return;
	}
	if (x + c->sx > c->w) {
		return;
	}
	const char *vline = useUtf8 ? utf8_line_vert (dot_style) : "|";
	r_cons_break_push (NULL, NULL);
	for (i = y; i < y + height; i++) {
		if (r_cons_is_breaked ()) {
			break;
		}
		if (G (x, i)) {
			W (vline);
		}
	}
	r_cons_break_pop ();
}

