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
typedef  int /*<<< orphan*/  uiTextWeight ;
typedef  size_t uiTextStretch ;
typedef  size_t uiTextItalic ;
struct TYPE_4__ {size_t Italic; size_t Stretch; int /*<<< orphan*/  Size; int /*<<< orphan*/  Weight; int /*<<< orphan*/  Family; } ;
typedef  TYPE_1__ uiFontDescriptor ;
typedef  int /*<<< orphan*/  PangoWeight ;
typedef  scalar_t__ PangoStyle ;
typedef  scalar_t__ PangoStretch ;
typedef  int /*<<< orphan*/  PangoFontDescription ;

/* Variables and functions */
 scalar_t__* pangoItalics ; 
 scalar_t__* pangoStretches ; 
 int /*<<< orphan*/  pango_font_description_get_family (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pango_font_description_get_size (int /*<<< orphan*/ *) ; 
 scalar_t__ pango_font_description_get_stretch (int /*<<< orphan*/ *) ; 
 scalar_t__ pango_font_description_get_style (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pango_font_description_get_weight (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pango_font_description_new () ; 
 int /*<<< orphan*/  pango_font_description_set_family (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_font_description_set_size (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_font_description_set_stretch (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  pango_font_description_set_style (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  pango_font_description_set_weight (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_units_from_double (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_units_to_double (int /*<<< orphan*/ ) ; 
 size_t uiTextItalicItalic ; 
 size_t uiTextItalicNormal ; 
 size_t uiTextStretchUltraCondensed ; 
 size_t uiTextStretchUltraExpanded ; 
 int /*<<< orphan*/  uiUnixStrdupText (int /*<<< orphan*/ ) ; 

PangoWeight uiprivWeightToPangoWeight(uiTextWeight w)
{
	return (PangoWeight) w;
}

PangoStyle uiprivItalicToPangoStyle(uiTextItalic i)
{
	return pangoItalics[i];
}

PangoStretch uiprivStretchToPangoStretch(uiTextStretch s)
{
	return pangoStretches[s];
}

PangoFontDescription *uiprivFontDescriptorToPangoFontDescription(const uiFontDescriptor *uidesc)
{
	PangoFontDescription *desc;

	desc = pango_font_description_new();
	pango_font_description_set_family(desc, uidesc->Family);
	// see https://developer.gnome.org/pango/1.30/pango-Fonts.html#pango-font-description-set-size and https://developer.gnome.org/pango/1.30/pango-Glyph-Storage.html#pango-units-from-double
	pango_font_description_set_size(desc, pango_units_from_double(uidesc->Size));
	pango_font_description_set_weight(desc, uiprivWeightToPangoWeight(uidesc->Weight));
	pango_font_description_set_style(desc, uiprivItalicToPangoStyle(uidesc->Italic));
	pango_font_description_set_stretch(desc, uiprivStretchToPangoStretch(uidesc->Stretch));
	return desc;
}

void uiprivFontDescriptorFromPangoFontDescription(PangoFontDescription *pdesc, uiFontDescriptor *uidesc)
{
	PangoStyle pitalic;
	PangoStretch pstretch;

	uidesc->Family = uiUnixStrdupText(pango_font_description_get_family(pdesc));
	pitalic = pango_font_description_get_style(pdesc);
	// TODO reverse the above misalignment if it is corrected
	uidesc->Weight = pango_font_description_get_weight(pdesc);
	pstretch = pango_font_description_get_stretch(pdesc);
	// absolute size does not matter because, as above, 1 device unit == 1 cairo point
	uidesc->Size = pango_units_to_double(pango_font_description_get_size(pdesc));

	for (uidesc->Italic = uiTextItalicNormal; uidesc->Italic < uiTextItalicItalic; uidesc->Italic++)
		if (pangoItalics[uidesc->Italic] == pitalic)
			break;
	for (uidesc->Stretch = uiTextStretchUltraCondensed; uidesc->Stretch < uiTextStretchUltraExpanded; uidesc->Stretch++)
		if (pangoStretches[uidesc->Stretch] == pstretch)
			break;
}

