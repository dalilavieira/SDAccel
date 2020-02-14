#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zval ;
typedef  int /*<<< orphan*/  zend_ulong ;
typedef  int /*<<< orphan*/  zend_string ;
typedef  int zend_long ;
struct pdo_bound_param_data {int paramno; int /*<<< orphan*/  parameter; int /*<<< orphan*/  param_type; int /*<<< orphan*/  name; int /*<<< orphan*/  is_param; } ;
typedef  int /*<<< orphan*/  php_stream ;
struct TYPE_19__ {int column_count; scalar_t__ driver_data; TYPE_1__* columns; int /*<<< orphan*/  dbh; scalar_t__ executed; int /*<<< orphan*/  row_count; } ;
typedef  TYPE_3__ pdo_stmt_t ;
struct TYPE_20__ {int done; int pre_fetched; int /*<<< orphan*/ * stmt; TYPE_2__* H; } ;
typedef  TYPE_4__ pdo_sqlite_stmt ;
typedef  enum pdo_param_event { ____Placeholder_pdo_param_event } pdo_param_event ;
typedef  enum pdo_fetch_orientation { ____Placeholder_pdo_fetch_orientation } pdo_fetch_orientation ;
struct TYPE_18__ {int /*<<< orphan*/  db; } ;
struct TYPE_17__ {int maxlen; int param_type; scalar_t__ precision; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int FAILURE ; 
 int /*<<< orphan*/  IS_NULL ; 
 int /*<<< orphan*/  IS_RESOURCE ; 
#define  PDO_PARAM_BOOL 146 
#define  PDO_PARAM_EVT_EXEC_PRE 145 
#define  PDO_PARAM_INT 144 
#define  PDO_PARAM_LOB 143 
#define  PDO_PARAM_NULL 142 
#define  PDO_PARAM_STMT 141 
#define  PDO_PARAM_STR 140 
 int /*<<< orphan*/  PDO_PARAM_TYPE (int /*<<< orphan*/ ) ; 
#define  PDO_SQLITE_ATTR_READONLY_STATEMENT 139 
 int /*<<< orphan*/  PHP_STREAM_COPY_ALL ; 
#define  SQLITE3_TEXT 138 
#define  SQLITE_BLOB 137 
#define  SQLITE_BUSY 136 
#define  SQLITE_DONE 135 
#define  SQLITE_ERROR 134 
#define  SQLITE_FLOAT 133 
#define  SQLITE_INTEGER 132 
#define  SQLITE_MISUSE 131 
#define  SQLITE_NULL 130 
 int /*<<< orphan*/  SQLITE_OK ; 
#define  SQLITE_ROW 129 
 int /*<<< orphan*/  SQLITE_STATIC ; 
#define  SQLITE_TEXT 128 
 int SUCCESS ; 
 int /*<<< orphan*/ * ZSTR_EMPTY_ALLOC () ; 
 int /*<<< orphan*/  ZSTR_VAL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZVAL_FALSE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZVAL_STR (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Z_ISREF (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Z_LVAL_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * Z_REFVAL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Z_STRLEN_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Z_STRVAL_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Z_TYPE_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  add_assoc_string (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  add_assoc_zval (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  add_next_index_string (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  array_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  convert_to_long (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  convert_to_string (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efree (TYPE_4__*) ; 
 int /*<<< orphan*/  pdo_raise_impl_error (int /*<<< orphan*/ ,TYPE_3__*,char*,char*) ; 
 int /*<<< orphan*/  pdo_sqlite_error_stmt (TYPE_3__*) ; 
 int /*<<< orphan*/ * php_stream_copy_to_mem (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  php_stream_from_zval_no_verify (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3_bind_blob (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_bind_int (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_bind_null (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_bind_parameter_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_bind_text (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_changes (int /*<<< orphan*/ ) ; 
 scalar_t__ sqlite3_column_blob (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sqlite3_column_bytes (int /*<<< orphan*/ *,int) ; 
 int sqlite3_column_count (int /*<<< orphan*/ *) ; 
 char* sqlite3_column_decltype (int /*<<< orphan*/ *,int) ; 
 char* sqlite3_column_name (int /*<<< orphan*/ *,int) ; 
 scalar_t__ sqlite3_column_text (int /*<<< orphan*/ *,int) ; 
 int sqlite3_column_type (int /*<<< orphan*/ *,int) ; 
 int sqlite3_data_count (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3_finalize (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3_reset (int /*<<< orphan*/ *) ; 
 int sqlite3_step (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  zend_string_init (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zval_ptr_dtor (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pdo_sqlite_stmt_dtor(pdo_stmt_t *stmt)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;

	if (S->stmt) {
		sqlite3_finalize(S->stmt);
		S->stmt = NULL;
	}
	efree(S);
	return 1;
}

__attribute__((used)) static int pdo_sqlite_stmt_execute(pdo_stmt_t *stmt)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;

	if (stmt->executed && !S->done) {
		sqlite3_reset(S->stmt);
	}

	S->done = 0;
	switch (sqlite3_step(S->stmt)) {
		case SQLITE_ROW:
			S->pre_fetched = 1;
			stmt->column_count = sqlite3_data_count(S->stmt);
			return 1;

		case SQLITE_DONE:
			stmt->column_count = sqlite3_column_count(S->stmt);
			stmt->row_count = sqlite3_changes(S->H->db);
			sqlite3_reset(S->stmt);
			S->done = 1;
			return 1;

		case SQLITE_ERROR:
			sqlite3_reset(S->stmt);
		case SQLITE_MISUSE:
		case SQLITE_BUSY:
		default:
			pdo_sqlite_error_stmt(stmt);
			return 0;
	}
}

__attribute__((used)) static int pdo_sqlite_stmt_param_hook(pdo_stmt_t *stmt, struct pdo_bound_param_data *param,
		enum pdo_param_event event_type)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	zval *parameter;

	switch (event_type) {
		case PDO_PARAM_EVT_EXEC_PRE:
			if (stmt->executed && !S->done) {
				sqlite3_reset(S->stmt);
				S->done = 1;
			}

			if (param->is_param) {

				if (param->paramno == -1) {
					param->paramno = sqlite3_bind_parameter_index(S->stmt, ZSTR_VAL(param->name)) - 1;
				}

				switch (PDO_PARAM_TYPE(param->param_type)) {
					case PDO_PARAM_STMT:
						return 0;

					case PDO_PARAM_NULL:
						if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
							return 1;
						}
						pdo_sqlite_error_stmt(stmt);
						return 0;

					case PDO_PARAM_INT:
					case PDO_PARAM_BOOL:
						if (Z_ISREF(param->parameter)) {
							parameter = Z_REFVAL(param->parameter);
						} else {
							parameter = &param->parameter;
						}
						if (Z_TYPE_P(parameter) == IS_NULL) {
							if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
								return 1;
							}
						} else {
							convert_to_long(parameter);
#if ZEND_LONG_MAX > 2147483647
							if (SQLITE_OK == sqlite3_bind_int64(S->stmt, param->paramno + 1, Z_LVAL_P(parameter))) {
								return 1;
							}
#else
							if (SQLITE_OK == sqlite3_bind_int(S->stmt, param->paramno + 1, Z_LVAL_P(parameter))) {
								return 1;
							}
#endif
						}
						pdo_sqlite_error_stmt(stmt);
						return 0;

					case PDO_PARAM_LOB:
						if (Z_ISREF(param->parameter)) {
							parameter = Z_REFVAL(param->parameter);
						} else {
							parameter = &param->parameter;
						}
						if (Z_TYPE_P(parameter) == IS_RESOURCE) {
							php_stream *stm = NULL;
							php_stream_from_zval_no_verify(stm, parameter);
							if (stm) {
								zend_string *mem = php_stream_copy_to_mem(stm, PHP_STREAM_COPY_ALL, 0);
								zval_ptr_dtor(parameter);
								ZVAL_STR(parameter, mem ? mem : ZSTR_EMPTY_ALLOC());
							} else {
								pdo_raise_impl_error(stmt->dbh, stmt, "HY105", "Expected a stream resource");
								return 0;
							}
						} else if (Z_TYPE_P(parameter) == IS_NULL) {
							if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
								return 1;
							}
							pdo_sqlite_error_stmt(stmt);
							return 0;
						} else {
							convert_to_string(parameter);
						}

						if (SQLITE_OK == sqlite3_bind_blob(S->stmt, param->paramno + 1,
								Z_STRVAL_P(parameter),
								Z_STRLEN_P(parameter),
								SQLITE_STATIC)) {
							return 1;
						}
						return 0;

					case PDO_PARAM_STR:
					default:
						if (Z_ISREF(param->parameter)) {
							parameter = Z_REFVAL(param->parameter);
						} else {
							parameter = &param->parameter;
						}
						if (Z_TYPE_P(parameter) == IS_NULL) {
							if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
								return 1;
							}
						} else {
							convert_to_string(parameter);
							if (SQLITE_OK == sqlite3_bind_text(S->stmt, param->paramno + 1,
									Z_STRVAL_P(parameter),
									Z_STRLEN_P(parameter),
									SQLITE_STATIC)) {
								return 1;
							}
						}
						pdo_sqlite_error_stmt(stmt);
						return 0;
				}
			}
			break;

		default:
			;
	}
	return 1;
}

__attribute__((used)) static int pdo_sqlite_stmt_fetch(pdo_stmt_t *stmt,
	enum pdo_fetch_orientation ori, zend_long offset)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	int i;
	if (!S->stmt) {
		return 0;
	}
	if (S->pre_fetched) {
		S->pre_fetched = 0;
		return 1;
	}
	if (S->done) {
		return 0;
	}
	i = sqlite3_step(S->stmt);
	switch (i) {
		case SQLITE_ROW:
			return 1;

		case SQLITE_DONE:
			S->done = 1;
			sqlite3_reset(S->stmt);
			return 0;

		case SQLITE_ERROR:
			sqlite3_reset(S->stmt);
		default:
			pdo_sqlite_error_stmt(stmt);
			return 0;
	}
}

__attribute__((used)) static int pdo_sqlite_stmt_describe(pdo_stmt_t *stmt, int colno)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	const char *str;

	if(colno >= sqlite3_column_count(S->stmt)) {
		/* error invalid column */
		pdo_sqlite_error_stmt(stmt);
		return 0;
	}

	str = sqlite3_column_name(S->stmt, colno);
	stmt->columns[colno].name = zend_string_init(str, strlen(str), 0);
	stmt->columns[colno].maxlen = 0xffffffff;
	stmt->columns[colno].precision = 0;

	switch (sqlite3_column_type(S->stmt, colno)) {
		case SQLITE_INTEGER:
		case SQLITE_FLOAT:
		case SQLITE3_TEXT:
		case SQLITE_BLOB:
		case SQLITE_NULL:
		default:
			stmt->columns[colno].param_type = PDO_PARAM_STR;
			break;
	}

	return 1;
}

__attribute__((used)) static int pdo_sqlite_stmt_get_col(pdo_stmt_t *stmt, int colno, char **ptr, zend_ulong *len, int *caller_frees)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	if (!S->stmt) {
		return 0;
	}
	if(colno >= sqlite3_data_count(S->stmt)) {
		/* error invalid column */
		pdo_sqlite_error_stmt(stmt);
		return 0;
	}
	switch (sqlite3_column_type(S->stmt, colno)) {
		case SQLITE_NULL:
			*ptr = NULL;
			*len = 0;
			return 1;

		case SQLITE_BLOB:
			*ptr = (char*)sqlite3_column_blob(S->stmt, colno);
			*len = sqlite3_column_bytes(S->stmt, colno);
			return 1;

		default:
			*ptr = (char*)sqlite3_column_text(S->stmt, colno);
			*len = sqlite3_column_bytes(S->stmt, colno);
			return 1;
	}
}

__attribute__((used)) static int pdo_sqlite_stmt_col_meta(pdo_stmt_t *stmt, zend_long colno, zval *return_value)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	const char *str;
	zval flags;

	if (!S->stmt) {
		return FAILURE;
	}
	if(colno >= sqlite3_data_count(S->stmt)) {
		/* error invalid column */
		pdo_sqlite_error_stmt(stmt);
		return FAILURE;
	}

	array_init(return_value);
	array_init(&flags);

	switch (sqlite3_column_type(S->stmt, colno)) {
		case SQLITE_NULL:
			add_assoc_string(return_value, "native_type", "null");
			break;

		case SQLITE_FLOAT:
			add_assoc_string(return_value, "native_type", "double");
			break;

		case SQLITE_BLOB:
			add_next_index_string(&flags, "blob");
		case SQLITE_TEXT:
			add_assoc_string(return_value, "native_type", "string");
			break;

		case SQLITE_INTEGER:
			add_assoc_string(return_value, "native_type", "integer");
			break;
	}

	str = sqlite3_column_decltype(S->stmt, colno);
	if (str) {
		add_assoc_string(return_value, "sqlite:decl_type", (char *)str);
	}

#ifdef HAVE_SQLITE3_COLUMN_TABLE_NAME
	str = sqlite3_column_table_name(S->stmt, colno);
	if (str) {
		add_assoc_string(return_value, "table", (char *)str);
	}
#endif

	add_assoc_zval(return_value, "flags", &flags);

	return SUCCESS;
}

__attribute__((used)) static int pdo_sqlite_stmt_cursor_closer(pdo_stmt_t *stmt)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;
	sqlite3_reset(S->stmt);
	return 1;
}

__attribute__((used)) static int pdo_sqlite_stmt_get_attribute(pdo_stmt_t *stmt, zend_long attr, zval *val)
{
	pdo_sqlite_stmt *S = (pdo_sqlite_stmt*)stmt->driver_data;

	switch (attr) {
		case PDO_SQLITE_ATTR_READONLY_STATEMENT:
			ZVAL_FALSE(val);

#if SQLITE_VERSION_NUMBER >= 3007004
				if (sqlite3_stmt_readonly(S->stmt)) {
					ZVAL_TRUE(val);
				}
#endif
			break;

		default:
			return 0;
	}

	return 1;
}

