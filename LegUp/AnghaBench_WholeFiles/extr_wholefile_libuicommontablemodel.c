#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiTableValueType ;
typedef  int /*<<< orphan*/  uiTableValue ;
struct TYPE_8__ {int (* NumColumns ) (TYPE_1__*,int /*<<< orphan*/ *) ;int (* NumRows ) (TYPE_1__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* SetCellValue ) (TYPE_1__*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/  const*) ;int /*<<< orphan*/ * (* CellValue ) (TYPE_1__*,int /*<<< orphan*/ *,int,int) ;int /*<<< orphan*/  (* ColumnType ) (TYPE_1__*,int /*<<< orphan*/ *,int) ;} ;
typedef  TYPE_1__ uiTableModelHandler ;
typedef  int /*<<< orphan*/  uiTableModel ;

/* Variables and functions */
 int stub1 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int /*<<< orphan*/ *,int) ; 
 int stub3 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stub4 (TYPE_1__*,int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_1__*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  uiFreeTableValue (int /*<<< orphan*/ *) ; 
#define  uiTableModelColumnAlwaysEditable 129 
#define  uiTableModelColumnNeverEditable 128 
 int /*<<< orphan*/  uiTableValueColor (int /*<<< orphan*/ *,double*,double*,double*,double*) ; 
 int uiTableValueInt (int /*<<< orphan*/ *) ; 
 TYPE_1__* uiprivTableModelHandler (int /*<<< orphan*/ *) ; 

int uiprivTableModelNumColumns(uiTableModel *m)
{
	uiTableModelHandler *mh;

	mh = uiprivTableModelHandler(m);
	return (*(mh->NumColumns))(mh, m);
}

uiTableValueType uiprivTableModelColumnType(uiTableModel *m, int column)
{
	uiTableModelHandler *mh;

	mh = uiprivTableModelHandler(m);
	return (*(mh->ColumnType))(mh, m, column);
}

int uiprivTableModelNumRows(uiTableModel *m)
{
	uiTableModelHandler *mh;

	mh = uiprivTableModelHandler(m);
	return (*(mh->NumRows))(mh, m);
}

uiTableValue *uiprivTableModelCellValue(uiTableModel *m, int row, int column)
{
	uiTableModelHandler *mh;

	mh = uiprivTableModelHandler(m);
	return (*(mh->CellValue))(mh, m, row, column);
}

void uiprivTableModelSetCellValue(uiTableModel *m, int row, int column, const uiTableValue *value)
{
	uiTableModelHandler *mh;

	mh = uiprivTableModelHandler(m);
	(*(mh->SetCellValue))(mh, m, row, column, value);
}

int uiprivTableModelCellEditable(uiTableModel *m, int row, int column)
{
	uiTableValue *value;
	int editable;

	switch (column) {
	case uiTableModelColumnNeverEditable:
		return 0;
	case uiTableModelColumnAlwaysEditable:
		return 1;
	}
	value = uiprivTableModelCellValue(m, row, column);
	editable = uiTableValueInt(value);
	uiFreeTableValue(value);
	return editable;
}

int uiprivTableModelColorIfProvided(uiTableModel *m, int row, int column, double *r, double *g, double *b, double *a)
{
	uiTableValue *value;

	if (column == -1)
		return 0;
	value = uiprivTableModelCellValue(m, row, column);
	if (value == NULL)
		return 0;
	uiTableValueColor(value, r, g, b, a);
	uiFreeTableValue(value);
	return 1;
}

