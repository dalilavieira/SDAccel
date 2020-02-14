#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct credential_operation {char* name; int (* op ) (struct credential*) ;} ;
struct credential {char* path; char* host; char* protocol; char* username; char* password; scalar_t__ port; } ;
typedef  int /*<<< orphan*/  guint32 ;
struct TYPE_10__ {scalar_t__ data; } ;
struct TYPE_9__ {char* password; char* user; int /*<<< orphan*/  item_id; int /*<<< orphan*/  keyring; } ;
struct TYPE_8__ {char* name; } ;
struct TYPE_7__ {char* name; } ;
typedef  int GnomeKeyringResult ;
typedef  TYPE_3__ GnomeKeyringNetworkPasswordData ;
typedef  TYPE_4__ GList ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 struct credential CREDENTIAL_INIT ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  GNOME_KEYRING_DEFAULT ; 
#define  GNOME_KEYRING_RESULT_ALREADY_EXISTS 136 
#define  GNOME_KEYRING_RESULT_ALREADY_UNLOCKED 135 
#define  GNOME_KEYRING_RESULT_BAD_ARGUMENTS 134 
#define  GNOME_KEYRING_RESULT_CANCELLED 133 
#define  GNOME_KEYRING_RESULT_DENIED 132 
#define  GNOME_KEYRING_RESULT_IO_ERROR 131 
#define  GNOME_KEYRING_RESULT_NO_KEYRING_DAEMON 130 
 int GNOME_KEYRING_RESULT_NO_MATCH ; 
#define  GNOME_KEYRING_RESULT_NO_SUCH_KEYRING 129 
#define  GNOME_KEYRING_RESULT_OK 128 
 scalar_t__ atoi (char*) ; 
 struct credential_operation* credential_helper_ops ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fgets (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 int /*<<< orphan*/  g_critical (char*,char const*) ; 
 int /*<<< orphan*/  g_free (char*) ; 
 int /*<<< orphan*/  g_set_application_name (char*) ; 
 void* g_strdup (char*) ; 
 char* g_strdup_printf (char*,char*,char*,...) ; 
 int /*<<< orphan*/  g_warning (char*,char*) ; 
 int gnome_keyring_find_network_password_sync (char*,int /*<<< orphan*/ *,char*,char*,char*,int /*<<< orphan*/ *,scalar_t__,TYPE_4__**) ; 
 int gnome_keyring_item_delete_sync (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* gnome_keyring_memory_alloc (int) ; 
 int /*<<< orphan*/  gnome_keyring_memory_free (char*) ; 
 void* gnome_keyring_memory_strdup (char*) ; 
 int /*<<< orphan*/  gnome_keyring_network_password_list_free (TYPE_4__*) ; 
 int gnome_keyring_set_network_password_sync (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,char*,char*,char*,int /*<<< orphan*/ *,scalar_t__,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct credential*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/ * stdout ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (char*,char*) ; 
 size_t strlen (char*) ; 
 void* strrchr (char const*,char) ; 
 int stub1 (struct credential*) ; 

__attribute__((used)) static const char *gnome_keyring_result_to_message(GnomeKeyringResult result)
{
	switch (result) {
	case GNOME_KEYRING_RESULT_OK:
		return "OK";
	case GNOME_KEYRING_RESULT_DENIED:
		return "Denied";
	case GNOME_KEYRING_RESULT_NO_KEYRING_DAEMON:
		return "No Keyring Daemon";
	case GNOME_KEYRING_RESULT_ALREADY_UNLOCKED:
		return "Already UnLocked";
	case GNOME_KEYRING_RESULT_NO_SUCH_KEYRING:
		return "No Such Keyring";
	case GNOME_KEYRING_RESULT_BAD_ARGUMENTS:
		return "Bad Arguments";
	case GNOME_KEYRING_RESULT_IO_ERROR:
		return "IO Error";
	case GNOME_KEYRING_RESULT_CANCELLED:
		return "Cancelled";
	case GNOME_KEYRING_RESULT_ALREADY_EXISTS:
		return "Already Exists";
	default:
		return "Unknown Error";
	}
}

__attribute__((used)) static char *keyring_object(struct credential *c)
{
	if (!c->path)
		return NULL;

	if (c->port)
		return g_strdup_printf("%s:%hd/%s", c->host, c->port, c->path);

	return g_strdup_printf("%s/%s", c->host, c->path);
}

__attribute__((used)) static int keyring_get(struct credential *c)
{
	char *object = NULL;
	GList *entries;
	GnomeKeyringNetworkPasswordData *password_data;
	GnomeKeyringResult result;

	if (!c->protocol || !(c->host || c->path))
		return EXIT_FAILURE;

	object = keyring_object(c);

	result = gnome_keyring_find_network_password_sync(
				c->username,
				NULL /* domain */,
				c->host,
				object,
				c->protocol,
				NULL /* authtype */,
				c->port,
				&entries);

	g_free(object);

	if (result == GNOME_KEYRING_RESULT_NO_MATCH)
		return EXIT_SUCCESS;

	if (result == GNOME_KEYRING_RESULT_CANCELLED)
		return EXIT_SUCCESS;

	if (result != GNOME_KEYRING_RESULT_OK) {
		g_critical("%s", gnome_keyring_result_to_message(result));
		return EXIT_FAILURE;
	}

	/* pick the first one from the list */
	password_data = (GnomeKeyringNetworkPasswordData *)entries->data;

	gnome_keyring_memory_free(c->password);
	c->password = gnome_keyring_memory_strdup(password_data->password);

	if (!c->username)
		c->username = g_strdup(password_data->user);

	gnome_keyring_network_password_list_free(entries);

	return EXIT_SUCCESS;
}

__attribute__((used)) static int keyring_store(struct credential *c)
{
	guint32 item_id;
	char *object = NULL;
	GnomeKeyringResult result;

	/*
	 * Sanity check that what we are storing is actually sensible.
	 * In particular, we can't make a URL without a protocol field.
	 * Without either a host or pathname (depending on the scheme),
	 * we have no primary key. And without a username and password,
	 * we are not actually storing a credential.
	 */
	if (!c->protocol || !(c->host || c->path) ||
	    !c->username || !c->password)
		return EXIT_FAILURE;

	object = keyring_object(c);

	result = gnome_keyring_set_network_password_sync(
				GNOME_KEYRING_DEFAULT,
				c->username,
				NULL /* domain */,
				c->host,
				object,
				c->protocol,
				NULL /* authtype */,
				c->port,
				c->password,
				&item_id);

	g_free(object);

	if (result != GNOME_KEYRING_RESULT_OK &&
	    result != GNOME_KEYRING_RESULT_CANCELLED) {
		g_critical("%s", gnome_keyring_result_to_message(result));
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

__attribute__((used)) static int keyring_erase(struct credential *c)
{
	char *object = NULL;
	GList *entries;
	GnomeKeyringNetworkPasswordData *password_data;
	GnomeKeyringResult result;

	/*
	 * Sanity check that we actually have something to match
	 * against. The input we get is a restrictive pattern,
	 * so technically a blank credential means "erase everything".
	 * But it is too easy to accidentally send this, since it is equivalent
	 * to empty input. So explicitly disallow it, and require that the
	 * pattern have some actual content to match.
	 */
	if (!c->protocol && !c->host && !c->path && !c->username)
		return EXIT_FAILURE;

	object = keyring_object(c);

	result = gnome_keyring_find_network_password_sync(
				c->username,
				NULL /* domain */,
				c->host,
				object,
				c->protocol,
				NULL /* authtype */,
				c->port,
				&entries);

	g_free(object);

	if (result == GNOME_KEYRING_RESULT_NO_MATCH)
		return EXIT_SUCCESS;

	if (result == GNOME_KEYRING_RESULT_CANCELLED)
		return EXIT_SUCCESS;

	if (result != GNOME_KEYRING_RESULT_OK) {
		g_critical("%s", gnome_keyring_result_to_message(result));
		return EXIT_FAILURE;
	}

	/* pick the first one from the list (delete all matches?) */
	password_data = (GnomeKeyringNetworkPasswordData *)entries->data;

	result = gnome_keyring_item_delete_sync(
		password_data->keyring, password_data->item_id);

	gnome_keyring_network_password_list_free(entries);

	if (result != GNOME_KEYRING_RESULT_OK) {
		g_critical("%s", gnome_keyring_result_to_message(result));
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

__attribute__((used)) static void credential_init(struct credential *c)
{
	memset(c, 0, sizeof(*c));
}

__attribute__((used)) static void credential_clear(struct credential *c)
{
	g_free(c->protocol);
	g_free(c->host);
	g_free(c->path);
	g_free(c->username);
	gnome_keyring_memory_free(c->password);

	credential_init(c);
}

__attribute__((used)) static int credential_read(struct credential *c)
{
	char *buf;
	size_t line_len;
	char *key;
	char *value;

	key = buf = gnome_keyring_memory_alloc(1024);

	while (fgets(buf, 1024, stdin)) {
		line_len = strlen(buf);

		if (line_len && buf[line_len-1] == '\n')
			buf[--line_len] = '\0';

		if (!line_len)
			break;

		value = strchr(buf, '=');
		if (!value) {
			g_warning("invalid credential line: %s", key);
			gnome_keyring_memory_free(buf);
			return -1;
		}
		*value++ = '\0';

		if (!strcmp(key, "protocol")) {
			g_free(c->protocol);
			c->protocol = g_strdup(value);
		} else if (!strcmp(key, "host")) {
			g_free(c->host);
			c->host = g_strdup(value);
			value = strrchr(c->host, ':');
			if (value) {
				*value++ = '\0';
				c->port = atoi(value);
			}
		} else if (!strcmp(key, "path")) {
			g_free(c->path);
			c->path = g_strdup(value);
		} else if (!strcmp(key, "username")) {
			g_free(c->username);
			c->username = g_strdup(value);
		} else if (!strcmp(key, "password")) {
			gnome_keyring_memory_free(c->password);
			c->password = gnome_keyring_memory_strdup(value);
			while (*value)
				*value++ = '\0';
		}
		/*
		 * Ignore other lines; we don't know what they mean, but
		 * this future-proofs us when later versions of git do
		 * learn new lines, and the helpers are updated to match.
		 */
	}

	gnome_keyring_memory_free(buf);

	return 0;
}

__attribute__((used)) static void credential_write_item(FILE *fp, const char *key, const char *value)
{
	if (!value)
		return;
	fprintf(fp, "%s=%s\n", key, value);
}

__attribute__((used)) static void credential_write(const struct credential *c)
{
	/* only write username/password, if set */
	credential_write_item(stdout, "username", c->username);
	credential_write_item(stdout, "password", c->password);
}

__attribute__((used)) static void usage(const char *name)
{
	struct credential_operation const *try_op = credential_helper_ops;
	const char *basename = strrchr(name, '/');

	basename = (basename) ? basename + 1 : name;
	fprintf(stderr, "usage: %s <", basename);
	while (try_op->name) {
		fprintf(stderr, "%s", (try_op++)->name);
		if (try_op->name)
			fprintf(stderr, "%s", "|");
	}
	fprintf(stderr, "%s", ">\n");
}

int main(int argc, char *argv[])
{
	int ret = EXIT_SUCCESS;

	struct credential_operation const *try_op = credential_helper_ops;
	struct credential cred = CREDENTIAL_INIT;

	if (!argv[1]) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	g_set_application_name("Git Credential Helper");

	/* lookup operation callback */
	while (try_op->name && strcmp(argv[1], try_op->name))
		try_op++;

	/* unsupported operation given -- ignore silently */
	if (!try_op->name || !try_op->op)
		goto out;

	ret = credential_read(&cred);
	if (ret)
		goto out;

	/* perform credential operation */
	ret = (*try_op->op)(&cred);

	credential_write(&cred);

out:
	credential_clear(&cred);
	return ret;
}

