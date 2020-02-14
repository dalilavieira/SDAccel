#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_26__ {scalar_t__ (* init ) (TYPE_1__*) ;int (* connect ) (TYPE_1__*,char const*,char const*,int) ;int (* set_timeout ) (TYPE_1__*,unsigned long) ;char const* (* errmsg ) (TYPE_1__*) ;int /*<<< orphan*/  (* close ) (TYPE_1__*) ;int /*<<< orphan*/  (* read ) (TYPE_1__*,char*,size_t) ;int /*<<< orphan*/  (* write ) (TYPE_1__*,char const*,size_t) ;int /*<<< orphan*/  size; } ;
struct TYPE_25__ {size_t type; TYPE_2__* ops; } ;
typedef  size_t ConnectionType ;
typedef  TYPE_1__ Connection ;
typedef  TYPE_2__ ConnOps ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  ERRCODE_FEATURE_NOT_SUPPORTED ; 
 int /*<<< orphan*/  ERRCODE_INTERNAL_ERROR ; 
 int /*<<< orphan*/  ERROR ; 
 size_t _CONNECTION_MAX ; 
 int /*<<< orphan*/ * conn_names ; 
 TYPE_2__** conn_ops ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errhint (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* palloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pfree (TYPE_1__*) ; 
 scalar_t__ stub1 (TYPE_1__*) ; 
 int stub2 (TYPE_1__*,char const*,char const*,int) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__*,char const*,size_t) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*,char*,size_t) ; 
 int /*<<< orphan*/  stub5 (TYPE_1__*) ; 
 int stub6 (TYPE_1__*,unsigned long) ; 
 char const* stub7 (TYPE_1__*) ; 

__attribute__((used)) static Connection *
connection_internal_create(ConnectionType type, ConnOps *ops)
{
	Connection *conn = palloc(ops->size);

	if (NULL == conn)
		return NULL;

	memset(conn, 0, ops->size);
	conn->ops = ops;
	conn->type = type;

	return conn;
}

Connection *
ts_connection_create(ConnectionType type)
{
	Connection *conn;

	if (type == _CONNECTION_MAX)
		elog(ERROR, "invalid connection type");

	if (NULL == conn_ops[type])
		ereport(ERROR,
				(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
				 errmsg("%s connections are not supported", conn_names[type]),
				 errhint("Enable %s support when compiling the extension.", conn_names[type])));

	conn = connection_internal_create(type, conn_ops[type]);

	Assert(NULL != conn);

	if (NULL != conn->ops->init)
		if (conn->ops->init(conn) < 0)
			ereport(ERROR,
					(errcode(ERRCODE_INTERNAL_ERROR),
					 errmsg("%s connection could not be initialized", conn_names[type])));

	return conn;
}

int
ts_connection_connect(Connection *conn, const char *host, const char *servname, int port)
{
/* Windows defines 'connect()' as a macro, so we need to undef it here to use it in ops->connect */
#ifdef WIN32
#undef connect
#endif
	return conn->ops->connect(conn, host, servname, port);
}

ssize_t
ts_connection_write(Connection *conn, const char *buf, size_t writelen)
{
	return conn->ops->write(conn, buf, writelen);
}

ssize_t
ts_connection_read(Connection *conn, char *buf, size_t buflen)
{
	return conn->ops->read(conn, buf, buflen);
}

void
ts_connection_close(Connection *conn)
{
	if (NULL != conn->ops)
		conn->ops->close(conn);
}

int
ts_connection_set_timeout_millis(Connection *conn, unsigned long millis)
{
	if (NULL != conn->ops->set_timeout)
		return conn->ops->set_timeout(conn, millis);

	return -1;
}

void
ts_connection_destroy(Connection *conn)
{
	if (conn == NULL)
		return;

	ts_connection_close(conn);
	conn->ops = NULL;
	pfree(conn);
}

int
ts_connection_register(ConnectionType type, ConnOps *ops)
{
	if (type == _CONNECTION_MAX)
		return -1;

	conn_ops[type] = ops;

	return 0;
}

const char *
ts_connection_get_and_clear_error(Connection *conn)
{
	if (NULL != conn->ops->errmsg)
		return conn->ops->errmsg(conn);

	return "unknown connection error";
}

