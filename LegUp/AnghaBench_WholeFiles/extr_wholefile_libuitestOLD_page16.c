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
typedef  int /*<<< orphan*/  uiTableModelHandler ;
typedef  int /*<<< orphan*/  uiTableModelColumnType ;
typedef  int /*<<< orphan*/  uiTableModel ;
typedef  int /*<<< orphan*/  uiTableColumn ;
typedef  int /*<<< orphan*/  uiTable ;
typedef  int /*<<< orphan*/  uiBox ;
struct TYPE_3__ {int (* NumColumns ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* NumRows ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void* (* CellValue ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ;void (* SetCellValue ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,void const*) ;int /*<<< orphan*/  (* ColumnType ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  appendImageNamed (void*,char*) ; 
 int* checkStates ; 
 void** img ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__ mh ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 char* row9text ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 void* uiNewImage (int,int) ; 
 int /*<<< orphan*/ * uiNewTable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiNewTableModel (TYPE_1__*) ; 
 int /*<<< orphan*/ * uiTableAppendColumn (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uiTableAppendTextColumn (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiTableColumnAppendButtonPart (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  uiTableColumnAppendCheckboxPart (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiTableColumnAppendImagePart (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiTableColumnAppendProgressBarPart (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiTableColumnAppendTextPart (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  uiTableColumnPartSetEditable (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  uiTableColumnPartSetTextColor (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  uiTableModelColumnColor ; 
 int /*<<< orphan*/  uiTableModelColumnImage ; 
 int /*<<< orphan*/  uiTableModelColumnInt ; 
 int /*<<< orphan*/  uiTableModelColumnString ; 
 void* uiTableModelGiveColor (double,double,double,int) ; 
 void* uiTableModelGiveInt (int) ; 
 void* uiTableModelStrdup (char*) ; 
 int uiTableModelTakeInt (void const*) ; 
 int /*<<< orphan*/  uiTableSetRowBackgroundColorModelColumn (int /*<<< orphan*/ *,int) ; 
 int yellowRow ; 

__attribute__((used)) static int modelNumColumns(uiTableModelHandler *mh, uiTableModel *m)
{
	return 9;
}

__attribute__((used)) static uiTableModelColumnType modelColumnType(uiTableModelHandler *mh, uiTableModel *m, int column)
{
	if (column == 3 || column == 4)
		return uiTableModelColumnColor;
	if (column == 5)
		return uiTableModelColumnImage;
	if (column == 7 || column == 8)
		return uiTableModelColumnInt;
	return uiTableModelColumnString;
}

__attribute__((used)) static int modelNumRows(uiTableModelHandler *mh, uiTableModel *m)
{
	return 15;
}

__attribute__((used)) static void *modelCellValue(uiTableModelHandler *mh, uiTableModel *m, int row, int col)
{
	char buf[256];

	if (col == 3) {
		if (row == yellowRow)
			return uiTableModelGiveColor(1, 1, 0, 1);
		if (row == 3)
			return uiTableModelGiveColor(1, 0, 0, 1);
		if (row == 11)
			return uiTableModelGiveColor(0, 0.5, 1, 0.5);
		return NULL;
	}
	if (col == 4) {
		if ((row % 2) == 1)
			return uiTableModelGiveColor(0.5, 0, 0.75, 1);
		return NULL;
	}
	if (col == 5) {
		if (row < 8)
			return img[0];
		return img[1];
	}
	if (col == 7)
		return uiTableModelGiveInt(checkStates[row]);
	if (col == 8) {
		if (row == 0)
			return uiTableModelGiveInt(0);
		if (row == 13)
			return uiTableModelGiveInt(100);
		if (row == 14)
			return uiTableModelGiveInt(-1);
		return uiTableModelGiveInt(50);
	}
	switch (col) {
	case 0:
		sprintf(buf, "Row %d", row);
		break;
	case 2:
		if (row == 9)
			return uiTableModelStrdup(row9text);
		// fall through
	case 1:
		strcpy(buf, "Part");
		break;
	case 6:
		strcpy(buf, "Make Yellow");
		break;
	}
	return uiTableModelStrdup(buf);
}

__attribute__((used)) static void modelSetCellValue(uiTableModelHandler *mh, uiTableModel *m, int row, int col, const void *val)
{
	if (row == 9 && col == 2)
		strcpy(row9text, (const char *) val);
	if (col == 6)
		yellowRow = row;
	if (col == 7)
		checkStates[row] = uiTableModelTakeInt(val);
}

uiBox *makePage16(void)
{
	uiBox *page16;
	uiTableModel *m;
	uiTable *t;
	uiTableColumn *tc;

	img[0] = uiNewImage(16, 16);
	appendImageNamed(img[0], "andlabs_16x16test_24june2016.png");
	appendImageNamed(img[0], "andlabs_32x32test_24june2016.png");
	img[1] = uiNewImage(16, 16);
	appendImageNamed(img[1], "tango-icon-theme-0.8.90_16x16_x-office-spreadsheet.png");
	appendImageNamed(img[1], "tango-icon-theme-0.8.90_32x32_x-office-spreadsheet.png");

	strcpy(row9text, "Part");

	memset(checkStates, 0, 15 * sizeof (int));

	page16 = newVerticalBox();

	mh.NumColumns = modelNumColumns;
	mh.ColumnType = modelColumnType;
	mh.NumRows = modelNumRows;
	mh.CellValue = modelCellValue;
	mh.SetCellValue = modelSetCellValue;
	m = uiNewTableModel(&mh);

	t = uiNewTable(m);
	uiBoxAppend(page16, uiControl(t), 1);

	uiTableAppendTextColumn(t, "Column 1", 0);

	tc = uiTableAppendColumn(t, "Column 2");
	uiTableColumnAppendImagePart(tc, 5, 0);
	uiTableColumnAppendTextPart(tc, 1, 0);
	uiTableColumnAppendTextPart(tc, 2, 1);
	uiTableColumnPartSetTextColor(tc, 1, 4);
	uiTableColumnPartSetEditable(tc, 2, 1);

	uiTableSetRowBackgroundColorModelColumn(t, 3);

	tc = uiTableAppendColumn(t, "Buttons");
	uiTableColumnAppendCheckboxPart(tc, 7, 0);
	uiTableColumnAppendButtonPart(tc, 6, 1);

	tc = uiTableAppendColumn(t, "Progress Bar");
	uiTableColumnAppendProgressBarPart(tc, 8, 0);

	return page16;
}

