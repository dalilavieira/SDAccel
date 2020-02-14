#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiUnderlineColor ;
typedef  int /*<<< orphan*/  uiOpenTypeFeatures ;
typedef  int /*<<< orphan*/  uiForEach ;
struct TYPE_21__ {int /*<<< orphan*/  String; } ;
typedef  TYPE_1__ uiDrawTextLayoutParams ;
typedef  int /*<<< orphan*/  uiAttributedString ;
typedef  int /*<<< orphan*/  uiAttribute ;
struct foreachParams {int /*<<< orphan*/ * attrs; } ;
typedef  int guint16 ;
struct TYPE_23__ {int /*<<< orphan*/  str; } ;
struct TYPE_22__ {size_t start_index; size_t end_index; } ;
typedef  int /*<<< orphan*/  PangoUnderline ;
typedef  TYPE_2__ PangoAttribute ;
typedef  int /*<<< orphan*/  PangoAttrList ;
typedef  TYPE_3__ GString ;

/* Variables and functions */
 int /*<<< orphan*/  PANGO_UNDERLINE_DOUBLE ; 
 int /*<<< orphan*/  PANGO_UNDERLINE_ERROR ; 
 int /*<<< orphan*/  PANGO_UNDERLINE_NONE ; 
 int /*<<< orphan*/  PANGO_UNDERLINE_SINGLE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  cairoToPango (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_string_free (TYPE_3__*,int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_background_new (int,int,int) ; 
 TYPE_2__* pango_attr_family_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_foreground_new (int,int,int) ; 
 int /*<<< orphan*/  pango_attr_list_insert (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/ * pango_attr_list_new () ; 
 TYPE_2__* pango_attr_size_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_stretch_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_style_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_underline_color_new (int,int,int) ; 
 TYPE_2__* pango_attr_underline_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* pango_attr_weight_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiAttributeColor (int /*<<< orphan*/  const*,double*,double*,double*,double*) ; 
 int /*<<< orphan*/  uiAttributeFamily (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * uiAttributeFeatures (int /*<<< orphan*/  const*) ; 
 int uiAttributeGetType (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiAttributeItalic (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiAttributeSize (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiAttributeStretch (int /*<<< orphan*/  const*) ; 
#define  uiAttributeTypeBackground 145 
#define  uiAttributeTypeColor 144 
#define  uiAttributeTypeFamily 143 
#define  uiAttributeTypeFeatures 142 
#define  uiAttributeTypeItalic 141 
#define  uiAttributeTypeSize 140 
#define  uiAttributeTypeStretch 139 
#define  uiAttributeTypeUnderline 138 
#define  uiAttributeTypeUnderlineColor 137 
#define  uiAttributeTypeWeight 136 
 int /*<<< orphan*/  uiAttributeUnderline (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiAttributeUnderlineColor (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,double*,double*,double*,double*) ; 
 int /*<<< orphan*/  uiAttributeWeight (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiAttributedStringForEachAttribute (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,size_t,size_t,void*),struct foreachParams*) ; 
 int /*<<< orphan*/  uiForEachContinue ; 
#define  uiUnderlineColorAuxiliary 135 
#define  uiUnderlineColorCustom 134 
#define  uiUnderlineColorGrammar 133 
#define  uiUnderlineColorSpelling 132 
#define  uiUnderlineDouble 131 
#define  uiUnderlineNone 130 
#define  uiUnderlineSingle 129 
#define  uiUnderlineSuggestion 128 
 TYPE_2__* uiprivFUTURE_pango_attr_background_alpha_new (int) ; 
 TYPE_2__* uiprivFUTURE_pango_attr_font_features_new (int /*<<< orphan*/ ) ; 
 TYPE_2__* uiprivFUTURE_pango_attr_foreground_alpha_new (int) ; 
 int /*<<< orphan*/  uiprivItalicToPangoStyle (int /*<<< orphan*/ ) ; 
 TYPE_3__* uiprivOpenTypeFeaturesToPangoCSSFeaturesString (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiprivStretchToPangoStretch (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiprivWeightToPangoWeight (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void addattr(struct foreachParams *p, size_t start, size_t end, PangoAttribute *attr)
{
	if (attr == NULL)		// in case of a future attribute
		return;
	attr->start_index = start;
	attr->end_index = end;
	pango_attr_list_insert(p->attrs, attr);
}

__attribute__((used)) static uiForEach processAttribute(const uiAttributedString *s, const uiAttribute *attr, size_t start, size_t end, void *data)
{
	struct foreachParams *p = (struct foreachParams *) data;
	double r, g, b, a;
	PangoUnderline underline;
	uiUnderlineColor colorType;
	const uiOpenTypeFeatures *features;
	GString *featurestr;

	switch (uiAttributeGetType(attr)) {
	case uiAttributeTypeFamily:
		addattr(p, start, end,
			pango_attr_family_new(uiAttributeFamily(attr)));
		break;
	case uiAttributeTypeSize:
		addattr(p, start, end,
			pango_attr_size_new(cairoToPango(uiAttributeSize(attr))));
		break;
	case uiAttributeTypeWeight:
		// TODO reverse the misalignment from drawtext.c if it is corrected 
		addattr(p, start, end,
			pango_attr_weight_new(uiprivWeightToPangoWeight(uiAttributeWeight(attr))));
		break;
	case uiAttributeTypeItalic:
		addattr(p, start, end,
			pango_attr_style_new(uiprivItalicToPangoStyle(uiAttributeItalic(attr))));
		break;
	case uiAttributeTypeStretch:
		addattr(p, start, end,
			pango_attr_stretch_new(uiprivStretchToPangoStretch(uiAttributeStretch(attr))));
		break;
	case uiAttributeTypeColor:
		uiAttributeColor(attr, &r, &g, &b, &a);
		addattr(p, start, end,
			pango_attr_foreground_new(
				(guint16) (r * 65535.0),
				(guint16) (g * 65535.0),
				(guint16) (b * 65535.0)));
		addattr(p, start, end,
			uiprivFUTURE_pango_attr_foreground_alpha_new(
				(guint16) (a * 65535.0)));
		break;
	case uiAttributeTypeBackground:
		// TODO make sure this works properly with line paragraph spacings (after figuring out what that means, of course)
		uiAttributeColor(attr, &r, &g, &b, &a);
		addattr(p, start, end,
			pango_attr_background_new(
				(guint16) (r * 65535.0),
				(guint16) (g * 65535.0),
				(guint16) (b * 65535.0)));
		addattr(p, start, end,
			uiprivFUTURE_pango_attr_background_alpha_new(
				(guint16) (a * 65535.0)));
		break;
	case uiAttributeTypeUnderline:
		switch (uiAttributeUnderline(attr)) {
		case uiUnderlineNone:
			underline = PANGO_UNDERLINE_NONE;
			break;
		case uiUnderlineSingle:
			underline = PANGO_UNDERLINE_SINGLE;
			break;
		case uiUnderlineDouble:
			underline = PANGO_UNDERLINE_DOUBLE;
			break;
		case uiUnderlineSuggestion:
			underline = PANGO_UNDERLINE_ERROR;
			break;
		}
		addattr(p, start, end,
			pango_attr_underline_new(underline));
		break;
	case uiAttributeTypeUnderlineColor:
		uiAttributeUnderlineColor(attr, &colorType, &r, &g, &b, &a);
		switch (colorType) {
		case uiUnderlineColorCustom:
			addattr(p, start, end,
				pango_attr_underline_color_new(
					(guint16) (r * 65535.0),
					(guint16) (g * 65535.0),
					(guint16) (b * 65535.0)));
			break;
		case uiUnderlineColorSpelling:
			// TODO GtkTextView style property error-underline-color
			addattr(p, start, end,
				pango_attr_underline_color_new(65535, 0, 0));
			break;
		case uiUnderlineColorGrammar:
			// TODO find a more appropriate color
			addattr(p, start, end,
				pango_attr_underline_color_new(0, 65535, 0));
			break;
		case uiUnderlineColorAuxiliary:
			// TODO find a more appropriate color
			addattr(p, start, end,
				pango_attr_underline_color_new(0, 0, 65535));
			break;
		}
		break;
	case uiAttributeTypeFeatures:
		// only generate an attribute if the features object is not NULL
		// TODO state that this is allowed
		features = uiAttributeFeatures(attr);
		if (features == NULL)
			break;
		featurestr = uiprivOpenTypeFeaturesToPangoCSSFeaturesString(features);
		addattr(p, start, end,
			uiprivFUTURE_pango_attr_font_features_new(featurestr->str));
		g_string_free(featurestr, TRUE);
		break;
	default:
		// TODO complain
		;
	}
	return uiForEachContinue;
}

PangoAttrList *uiprivAttributedStringToPangoAttrList(uiDrawTextLayoutParams *p)
{
	struct foreachParams fep;

	fep.attrs = pango_attr_list_new();
	uiAttributedStringForEachAttribute(p->String, processAttribute, &fep);
	return fep.attrs;
}

