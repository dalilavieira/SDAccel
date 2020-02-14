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
typedef  int /*<<< orphan*/  sqlite3_stmt ;
typedef  int /*<<< orphan*/  sqlite3 ;
typedef  int /*<<< orphan*/  sql ;
typedef  void* gboolean ;
struct TYPE_11__ {char* client_name; char* http_proxy_type; char* http_proxy_addr; char* http_proxy_username; char* http_proxy_password; int http_proxy_port; int /*<<< orphan*/ * config_db; void* use_http_proxy; void* disable_verify_certificate; void* sync_extra_temp_file; } ;
typedef  TYPE_1__ SeafileSession ;

/* Variables and functions */
 void* FALSE ; 
 char* KEY_ALLOW_INVALID_WORKTREE ; 
 char* KEY_ALLOW_REPO_NOT_FOUND_ON_SERVER ; 
 char* KEY_CLIENT_NAME ; 
 char* KEY_DISABLE_VERIFY_CERTIFICATE ; 
 char* KEY_PROXY_ADDR ; 
 char* KEY_PROXY_PASSWORD ; 
 char* KEY_PROXY_PORT ; 
 char* KEY_PROXY_TYPE ; 
 char* KEY_PROXY_USERNAME ; 
 char* KEY_SYNC_EXTRA_TEMP_FILE ; 
 char* KEY_USE_PROXY ; 
 void* TRUE ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  g_free (char*) ; 
 scalar_t__ g_strcmp0 (char const*,char*) ; 
 char* g_strdup (char const*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*) ; 
 scalar_t__ sqlite3_column_text (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_snprintf (int,char*,char*,char const*,...) ; 
 void* sqlite_check_for_existence (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ sqlite_foreach_selected_row (int /*<<< orphan*/ *,char*,void* (*) (int /*<<< orphan*/ *,void*),char**) ; 
 scalar_t__ sqlite_open_db (char const*,int /*<<< orphan*/ **) ; 
 scalar_t__ sqlite_query_exec (int /*<<< orphan*/ *,char*) ; 

gboolean
seafile_session_config_exists (SeafileSession *session, const char *key)
{
    char sql[256];

    snprintf (sql, sizeof(sql),
              "SELECT 1 FROM Config WHERE key = '%s'",
              key);
    return sqlite_check_for_existence (session->config_db, sql);
}

__attribute__((used)) static gboolean
get_value (sqlite3_stmt *stmt, void *data)
{
    char **p_value = data;

    *p_value = g_strdup((char *) sqlite3_column_text (stmt, 0));
    /* Only one result. */
    return FALSE;
}

__attribute__((used)) static char *
config_get_string (sqlite3 *config_db, const char *key)
{
    char sql[256];
    char *value = NULL;

    snprintf (sql, sizeof(sql),
              "SELECT value FROM Config WHERE key='%s';",
              key);
    if (sqlite_foreach_selected_row (config_db, sql,
                                     get_value, &value) < 0)
        return NULL;

    return value;
}

char *
seafile_session_config_get_string (SeafileSession *session,
                                   const char *key)
{
    return (config_get_string (session->config_db, key));
}

int
seafile_session_config_get_int (SeafileSession *session,
                                const char *key,
                                gboolean *exists)
{
    char *value;
    int ret;

    value = config_get_string (session->config_db, key);
    if (!value) {
        if (exists)
            *exists = FALSE;
        return -1;
    }

    if (exists)
        *exists = TRUE;
    ret = atoi (value);
    g_free (value);
    return ret;
}

gboolean
seafile_session_config_get_bool (SeafileSession *session,
                                 const char *key)
{
    char *value;
    gboolean ret = FALSE;

    value = config_get_string (session->config_db, key);
    if (g_strcmp0(value, "true") == 0)
        ret = TRUE;

    g_free (value);
    return ret;
}

int
seafile_session_config_set_string (SeafileSession *session,
                                   const char *key,
                                   const char *value)
{
    char sql[256];

    sqlite3_snprintf (sizeof(sql), sql,
                      "REPLACE INTO Config VALUES ('%q', '%q');",
                      key, value);
    if (sqlite_query_exec (session->config_db, sql) < 0)
        return -1;

    if (g_strcmp0 (key, KEY_CLIENT_NAME) == 0) {
        g_free (session->client_name);
        session->client_name = g_strdup(value);
    }

    if (g_strcmp0(key, KEY_SYNC_EXTRA_TEMP_FILE) == 0) {
        if (g_strcmp0(value, "true") == 0)
            session->sync_extra_temp_file = TRUE;
        else
            session->sync_extra_temp_file = FALSE;
    }

    if (g_strcmp0(key, KEY_DISABLE_VERIFY_CERTIFICATE) == 0) {
        if (g_strcmp0(value, "true") == 0)
            session->disable_verify_certificate = TRUE;
        else
            session->disable_verify_certificate = FALSE;
    }

    if (g_strcmp0(key, KEY_USE_PROXY) == 0) {
        if (g_strcmp0(value, "true") == 0)
            session->use_http_proxy = TRUE;
        else
            session->use_http_proxy = FALSE;
    }

    if (g_strcmp0(key, KEY_PROXY_TYPE) == 0) {
        session->http_proxy_type =
            g_strcmp0(value, "none") == 0 ? NULL : g_strdup(value);
    }

    if (g_strcmp0(key, KEY_PROXY_ADDR) == 0) {
        session->http_proxy_addr = g_strdup(value);
    }

    if (g_strcmp0(key, KEY_PROXY_USERNAME) == 0) {
        session->http_proxy_username = g_strdup(value);
    }

    if (g_strcmp0(key, KEY_PROXY_PASSWORD) == 0) {
        session->http_proxy_password = g_strdup(value);
    }

    return 0;
}

int
seafile_session_config_set_int (SeafileSession *session,
                                const char *key,
                                int value)
{
    char sql[256];

    sqlite3_snprintf (sizeof(sql), sql,
                      "REPLACE INTO Config VALUES ('%q', %d);",
                      key, value);
    if (sqlite_query_exec (session->config_db, sql) < 0)
        return -1;

    if (g_strcmp0(key, KEY_PROXY_PORT) == 0) {
        session->http_proxy_port = value;
    }

    return 0;
}

sqlite3 *
seafile_session_config_open_db (const char *db_path)
{
    sqlite3 *db;

    if (sqlite_open_db (db_path, &db) < 0)
        return NULL;

    /*
     * Values are stored in text. You should convert it
     * back to integer if needed when you read it from
     * db.
     */
    char *sql = "CREATE TABLE IF NOT EXISTS Config ("
        "key TEXT PRIMARY KEY, "
        "value TEXT);";
    sqlite_query_exec (db, sql);

    return db;
}

int
seafile_session_config_set_allow_invalid_worktree(SeafileSession *session, gboolean val)
{
    return seafile_session_config_set_string(session, KEY_ALLOW_INVALID_WORKTREE,
                                             val ? "true" : "false");
}

gboolean
seafile_session_config_get_allow_invalid_worktree(SeafileSession *session)
{
    return seafile_session_config_get_bool (session, KEY_ALLOW_INVALID_WORKTREE);
}

gboolean
seafile_session_config_get_allow_repo_not_found_on_server(SeafileSession *session)
{
    return seafile_session_config_get_bool (session,
                                            KEY_ALLOW_REPO_NOT_FOUND_ON_SERVER);
}

