#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiTableModel ;
struct TYPE_5__ {char* Name; int Mutable; int ValueColumn; int /*<<< orphan*/  Type; } ;
typedef  TYPE_1__ uiTableColumnParams ;
typedef  int /*<<< orphan*/  uiTable ;
typedef  int /*<<< orphan*/  uiBox ;
typedef  int intmax_t ;
struct TYPE_6__ {int (* NumRows ) (int /*<<< orphan*/ *,void*) ;void* (* CellValue ) (int /*<<< orphan*/ *,void*,int,int) ;void (* SetCellValue ) (int /*<<< orphan*/ *,void*,int,int,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/ * coltypes ; 
 int nColumns ; 
 int nRows ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 TYPE_3__ spec ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiNewTable () ; 
 int /*<<< orphan*/ * uiNewTableModel (int,int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiTableAppendColumn (int /*<<< orphan*/ *,TYPE_1__*) ; 
 void* uiTableModelFromBool (int) ; 
 void* uiTableModelFromString (char*) ; 
 int /*<<< orphan*/  uiTableSetModel (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static intmax_t modelNumRows(uiTableModel *m, void *mData)
{
	return nRows;
}

void *modelCellValue(uiTableModel *m, void *mData, intmax_t row, intmax_t column)
{
	char line[20];

	line[0] = 'R';
	line[1] = 'o';
	line[2] = 'w';
	line[3] = ' ';
	line[4] = row + '0';
	line[5] = '\0';
	switch (column) {
	case 0:
	case 1:
		return uiTableModelFromString(line);
	case 2:
		return uiTableModelFromBool(row % 2 == 0);
	case 3:
		return uiTableModelFromBool(row % 3 == 0);
	}
	// TODO
	return NULL;
}

void modelSetCellValue(uiTableModel *m, void *mData, intmax_t row, intmax_t column, void *value)
{
	// TODO
}

uiBox *makePage9(void)
{
	uiBox *page9;
	uiTable *table;
	uiTableModel *model;
	uiTableColumnParams p;
	intmax_t i;

	page9 = newVerticalBox();

	table = uiNewTable();
	uiBoxAppend(page9, uiControl(table), 1);

	spec.NumRows = modelNumRows;
	spec.CellValue = modelCellValue;
	spec.SetCellValue = modelSetCellValue;
	model = uiNewTableModel(nColumns, coltypes, &spec, NULL);
	uiTableSetModel(table, model);

	for (i = 0; i < nColumns; i++) {
		p.Name = "Column";
		p.Type = coltypes[i];
		p.Mutable = i % 2 == 1;
		p.ValueColumn = i;
		uiTableAppendColumn(table, &p);
	}

	return page9;
}

