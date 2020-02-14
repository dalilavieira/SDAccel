#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sqliterk_value_type ;
typedef  int /*<<< orphan*/  sqliterk_type ;
typedef  int /*<<< orphan*/  sqliterk_table ;
typedef  int /*<<< orphan*/  sqliterk_page ;
typedef  int /*<<< orphan*/  sqliterk_os ;
typedef  int /*<<< orphan*/  sqliterk_notify ;
typedef  int /*<<< orphan*/  sqliterk_column ;
struct TYPE_5__ {int key_len; void const* key; } ;
typedef  TYPE_1__ sqliterk_cipher_conf ;
typedef  int /*<<< orphan*/  sqliterk_btree ;
typedef  int /*<<< orphan*/  sqliterk ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 char const* sqliterkBtreeGetName (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * sqliterkBtreeGetRootPage (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqliterkBtreeGetType (int /*<<< orphan*/ *) ; 
 void* sqliterkBtreeGetUserInfo (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqliterkBtreeSetUserInfo (int /*<<< orphan*/ *,void*) ; 
 int sqliterkClose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqliterkColumnGetRowId (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqliterkColumnGetValues (int /*<<< orphan*/ *) ; 
 unsigned int sqliterkGetIntegrity (int /*<<< orphan*/ *) ; 
 int sqliterkGetPageCount (int /*<<< orphan*/ *) ; 
 int sqliterkGetParsedPageCount (int /*<<< orphan*/ *) ; 
 char const* sqliterkGetResultCodeDescription (int) ; 
 void* sqliterkGetUserInfo (int /*<<< orphan*/ *) ; 
 int sqliterkGetValidPageCount (int /*<<< orphan*/ *) ; 
 int sqliterkOSRegister (int /*<<< orphan*/ ) ; 
 int sqliterkOpen (char const*,TYPE_1__ const*,int /*<<< orphan*/ **) ; 
 int sqliterkPageGetPageno (int /*<<< orphan*/ *) ; 
 int sqliterkParse (int /*<<< orphan*/ *) ; 
 int sqliterkParseMaster (int /*<<< orphan*/ *) ; 
 int sqliterkParsePage (int /*<<< orphan*/ *,int) ; 
 int sqliterkSetNotify (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqliterkSetUserInfo (int /*<<< orphan*/ *,void*) ; 
 void const* sqliterkValuesGetBinary (int /*<<< orphan*/ ,int) ; 
 int sqliterkValuesGetBytes (int /*<<< orphan*/ ,int) ; 
 int sqliterkValuesGetCount (int /*<<< orphan*/ ) ; 
 int sqliterkValuesGetInteger (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sqliterkValuesGetInteger64 (int /*<<< orphan*/ ,int) ; 
 double sqliterkValuesGetNumber (int /*<<< orphan*/ ,int) ; 
 char const* sqliterkValuesGetText (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sqliterkValuesGetType (int /*<<< orphan*/ ,int) ; 

int sqliterk_register_notify(sqliterk *rk, sqliterk_notify notify)
{
    return sqliterkSetNotify(rk, notify);
}

int sqliterk_open(const char *path,
                  const sqliterk_cipher_conf *cipher,
                  sqliterk **rk)
{
    return sqliterkOpen(path, cipher, rk);
}

void *sqliterk_user_info(sqliterk *rk)
{
    return sqliterkGetUserInfo(rk);
}

int sqliterk_parse(sqliterk *rk)
{
    return sqliterkParse(rk);
}

int sqliterk_parse_page(sqliterk *rk, int pageno)
{
    return sqliterkParsePage(rk, pageno);
}

int sqliterk_parse_master(sqliterk *rk)
{
    return sqliterkParseMaster(rk);
}

int sqliterk_close(sqliterk *rk)
{
    return sqliterkClose(rk);
}

void *sqliterk_get_user_info(sqliterk *rk)
{
    return sqliterkGetUserInfo(rk);
}

void sqliterk_set_user_info(sqliterk *rk, void *userInfo)
{
    sqliterkSetUserInfo(rk, userInfo);
}

int sqliterk_column_count(sqliterk_column *column)
{
    return sqliterkValuesGetCount(sqliterkColumnGetValues(column));
}

sqliterk_value_type sqliterk_column_type(sqliterk_column *column, int index)
{
    return sqliterkValuesGetType(sqliterkColumnGetValues(column), index);
}

int sqliterk_column_integer(sqliterk_column *column, int index)
{
    return sqliterkValuesGetInteger(sqliterkColumnGetValues(column), index);
}

int64_t sqliterk_column_integer64(sqliterk_column *column, int index)
{
    return sqliterkValuesGetInteger64(sqliterkColumnGetValues(column), index);
}

double sqliterk_column_number(sqliterk_column *column, int index)
{
    return sqliterkValuesGetNumber(sqliterkColumnGetValues(column), index);
}

const char *sqliterk_column_text(sqliterk_column *column, int index)
{
    return sqliterkValuesGetText(sqliterkColumnGetValues(column), index);
}

const void *sqliterk_column_binary(sqliterk_column *column, int index)
{
    return sqliterkValuesGetBinary(sqliterkColumnGetValues(column), index);
}

int sqliterk_column_bytes(sqliterk_column *column, int index)
{
    return sqliterkValuesGetBytes(sqliterkColumnGetValues(column), index);
}

int64_t sqliterk_column_rowid(sqliterk_column *column)
{
    return sqliterkColumnGetRowId(column);
}

const char *sqliterk_table_name(sqliterk_table *table)
{
    return sqliterkBtreeGetName((sqliterk_btree *) table);
}

void sqliterk_table_set_user_info(sqliterk_table *table, void *userInfo)
{
    sqliterkBtreeSetUserInfo((sqliterk_btree *) table, userInfo);
}

void *sqliterk_table_get_user_info(sqliterk_table *table)
{
    return sqliterkBtreeGetUserInfo((sqliterk_btree *) table);
}

sqliterk_type sqliterk_table_type(sqliterk_table *table)
{
    return (sqliterk_type) sqliterkBtreeGetType((sqliterk_btree *) table);
}

int sqliterk_register(sqliterk_os os)
{
    return sqliterkOSRegister(os);
}

int sqliterk_table_root(sqliterk_table *table)
{
    sqliterk_page *page = sqliterkBtreeGetRootPage((sqliterk_btree *) table);
    return sqliterkPageGetPageno(page);
}

const char *sqliterk_description(int result)
{
    return sqliterkGetResultCodeDescription(result);
}

int sqliterk_parsed_page_count(sqliterk *rk)
{
    return sqliterkGetParsedPageCount(rk);
}

int sqliterk_valid_page_count(sqliterk *rk)
{
    return sqliterkGetValidPageCount(rk);
}

int sqliterk_page_count(sqliterk *rk)
{
    return sqliterkGetPageCount(rk);
}

unsigned int sqliterk_integrity(sqliterk *rk)
{
    return sqliterkGetIntegrity(rk);
}

void sqliterk_cipher_conf_set_key(sqliterk_cipher_conf *conf, const void* key, int key_len)
{
    if (conf != NULL) {
        conf->key = key;
        conf->key_len = key_len;
    }
}

