#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sqliterk_values ;
struct TYPE_11__ {int /*<<< orphan*/ * values; int /*<<< orphan*/ * overflowPages; scalar_t__ rowid; } ;
typedef  TYPE_1__ sqliterk_column ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int SQLITERK_MISUSE ; 
 int SQLITERK_NOMEM ; 
 int SQLITERK_OK ; 
 int sqliterkColumnFree (TYPE_1__*) ; 
 int /*<<< orphan*/  sqliterkOSFree (TYPE_1__*) ; 
 TYPE_1__* sqliterkOSMalloc (int) ; 
 int sqliterkValuesAlloc (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  sqliterkValuesClear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqliterkValuesFree (int /*<<< orphan*/ *) ; 

int sqliterkColumnAlloc(sqliterk_column **column)
{
    if (!column) {
        return SQLITERK_MISUSE;
    }
    int rc = SQLITERK_OK;
    sqliterk_column *theColumn = sqliterkOSMalloc(sizeof(sqliterk_column));
    if (!theColumn) {
        rc = SQLITERK_NOMEM;
        goto sqliterkColumnAlloc_Failed;
    }
    rc = sqliterkValuesAlloc(&theColumn->values);
    if (rc != SQLITERK_OK) {
        goto sqliterkColumnAlloc_Failed;
    }
    rc = sqliterkValuesAlloc(&theColumn->overflowPages);
    if (rc != SQLITERK_OK) {
        goto sqliterkColumnAlloc_Failed;
    }
    *column = theColumn;
    return SQLITERK_OK;

sqliterkColumnAlloc_Failed:
    if (theColumn) {
        sqliterkColumnFree(theColumn);
    }
    *column = NULL;
    return rc;
}

int sqliterkColumnFree(sqliterk_column *column)
{
    if (!column) {
        return SQLITERK_MISUSE;
    }
    if (column->overflowPages) {
        sqliterkValuesFree(column->overflowPages);
    }
    if (column->values) {
        sqliterkValuesFree(column->values);
    }
    sqliterkOSFree(column);
    return SQLITERK_OK;
}

sqliterk_values *sqliterkColumnGetValues(sqliterk_column *column)
{
    if (!column) {
        return NULL;
    }
    return column->values;
}

void sqliterkColumnSetRowId(sqliterk_column *column, int64_t rowid)
{
    if (column) {
        column->rowid = rowid;
    }
}

int64_t sqliterkColumnGetRowId(sqliterk_column *column)
{
    if (!column) {
        return 0;
    }
    return column->rowid;
}

sqliterk_values *sqliterkColumnGetOverflowPages(sqliterk_column *column)
{
    if (!column) {
        return NULL;
    }
    return column->overflowPages;
}

int sqliterkColumnClear(sqliterk_column *column)
{
    if (!column) {
        return SQLITERK_MISUSE;
    }
    column->rowid = 0;
    sqliterkValuesClear(column->overflowPages);
    sqliterkValuesClear(column->values);
    return SQLITERK_OK;
}

