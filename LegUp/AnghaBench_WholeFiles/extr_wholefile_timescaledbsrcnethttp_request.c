#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_1__ ;

/* Type definitions */
struct TYPE_36__ {char* name; size_t name_len; char* value; size_t value_len; struct TYPE_36__* next; } ;
struct TYPE_35__ {char* uri; int uri_len; char* body; size_t body_len; TYPE_4__* headers; int /*<<< orphan*/  version; int /*<<< orphan*/  method; int /*<<< orphan*/  context; } ;
struct TYPE_34__ {size_t len; char const* data; } ;
typedef  TYPE_1__ StringInfoData ;
typedef  TYPE_1__* StringInfo ;
typedef  int /*<<< orphan*/  MemoryContext ;
typedef  int /*<<< orphan*/  HttpVersion ;
typedef  int /*<<< orphan*/  HttpRequestMethod ;
typedef  TYPE_3__ HttpRequest ;
typedef  TYPE_4__ HttpHeader ;

/* Variables and functions */
 int /*<<< orphan*/  ALLOCSET_DEFAULT_SIZES ; 
 int /*<<< orphan*/  AllocSetContextCreate (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Assert (int /*<<< orphan*/ ) ; 
 char CARRIAGE ; 
 char COLON ; 
 int /*<<< orphan*/  CurrentMemoryContext ; 
 int /*<<< orphan*/  HTTP_CONTENT_LENGTH ; 
 char* METHOD_STRING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MemoryContextDelete (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MemoryContextSwitchTo (int /*<<< orphan*/ ) ; 
 char NEW_LINE ; 
 char SPACE ; 
 char* VERSION_STRING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  appendBinaryStringInfo (TYPE_1__*,char const*,int) ; 
 int /*<<< orphan*/  appendStringInfoChar (TYPE_1__*,char) ; 
 int /*<<< orphan*/  appendStringInfoString (TYPE_1__*,char const*) ; 
 int /*<<< orphan*/  initStringInfo (TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 void* palloc (size_t) ; 
 TYPE_3__* palloc0 (int) ; 
 int /*<<< orphan*/  sscanf (char*,char*,int*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char*,int /*<<< orphan*/ ,int) ; 

HttpHeader *
ts_http_header_create(const char *name, size_t name_len, const char *value, size_t value_len,
					  HttpHeader *next)
{
	HttpHeader *new_header = palloc(sizeof(HttpHeader));

	memset(new_header, 0, sizeof(*new_header));
	new_header->name = palloc(name_len + 1);
	if (name_len > 0)
		memcpy(new_header->name, name, name_len);
	new_header->name[name_len] = '\0';
	new_header->name_len = name_len;

	new_header->value = palloc(value_len + 1);
	if (value_len > 0)
		memcpy(new_header->value, value, value_len);
	new_header->value[value_len] = '\0';
	new_header->value_len = value_len;

	new_header->next = next;
	return new_header;
}

__attribute__((used)) static void
appendOptionalBinaryStringInfo(StringInfo str, const char *data, int datalen)
{
	if (datalen <= 0)
		return;

	Assert(data != NULL);
	appendBinaryStringInfo(str, data, datalen);
}

void
ts_http_request_init(HttpRequest *req, HttpRequestMethod method)
{
	req->method = method;
}

HttpRequest *
ts_http_request_create(HttpRequestMethod method)
{
	MemoryContext request_context =
		AllocSetContextCreate(CurrentMemoryContext, "Http Request", ALLOCSET_DEFAULT_SIZES);
	MemoryContext old = MemoryContextSwitchTo(request_context);
	HttpRequest *req = palloc0(sizeof(HttpRequest));

	req->context = request_context;
	ts_http_request_init(req, method);

	MemoryContextSwitchTo(old);
	return req;
}

void
ts_http_request_destroy(HttpRequest *req)
{
	MemoryContextDelete(req->context);
}

void
ts_http_request_set_uri(HttpRequest *req, const char *uri)
{
	MemoryContext old = MemoryContextSwitchTo(req->context);
	int uri_len = strlen(uri);

	req->uri = palloc(uri_len + 1);
	memcpy(req->uri, uri, uri_len);
	req->uri[uri_len] = '\0';
	req->uri_len = uri_len;
	MemoryContextSwitchTo(old);
}

void
ts_http_request_set_version(HttpRequest *req, HttpVersion version)
{
	req->version = version;
}

void
ts_http_request_set_header(HttpRequest *req, const char *name, const char *value)
{
	MemoryContext old = MemoryContextSwitchTo(req->context);
	int name_len = strlen(name);
	int value_len = strlen(value);
	HttpHeader *new_header = ts_http_header_create(name, name_len, value, value_len, req->headers);

	req->headers = new_header;
	MemoryContextSwitchTo(old);
}

void
ts_http_request_set_body(HttpRequest *req, const char *body, size_t body_len)
{
	MemoryContext old = MemoryContextSwitchTo(req->context);

	req->body = palloc(body_len + 1);
	memcpy(req->body, body, body_len);
	req->body[body_len] = '\0';
	req->body_len = body_len;
	MemoryContextSwitchTo(old);
}

__attribute__((used)) static void
http_request_serialize_method(HttpRequest *req, StringInfo buf)
{
	const char *method = METHOD_STRING(req->method);

	appendStringInfoString(buf, method);
}

__attribute__((used)) static void
http_request_serialize_version(HttpRequest *req, StringInfo buf)
{
	const char *version = VERSION_STRING(req->version);

	appendStringInfoString(buf, version);
}

__attribute__((used)) static void
http_request_serialize_uri(HttpRequest *req, StringInfo buf)
{
	appendOptionalBinaryStringInfo(buf, req->uri, req->uri_len);
}

__attribute__((used)) static void
http_request_serialize_char(char to_serialize, StringInfo buf)
{
	appendStringInfoChar(buf, to_serialize);
}

__attribute__((used)) static void
http_request_serialize_body(HttpRequest *req, StringInfo buf)
{
	appendOptionalBinaryStringInfo(buf, req->body, req->body_len);
}

__attribute__((used)) static void
http_header_serialize(HttpHeader *header, StringInfo buf)
{
	appendOptionalBinaryStringInfo(buf, header->name, header->name_len);
	http_request_serialize_char(COLON, buf);
	http_request_serialize_char(SPACE, buf);
	appendOptionalBinaryStringInfo(buf, header->value, header->value_len);
}

__attribute__((used)) static int
http_header_get_content_length(HttpHeader *header)
{
	int content_length = -1;

	if (!strncmp(header->name, HTTP_CONTENT_LENGTH, header->name_len))
		sscanf(header->value, "%d", &content_length);
	return content_length;
}

const char *
ts_http_request_build(HttpRequest *req, size_t *buf_size)
{
	/* serialize into this buf, which is allocated on caller's memory context */
	StringInfoData buf;
	HttpHeader *cur_header;
	int content_length = 0;
	bool verified_content_length = false;

	initStringInfo(&buf);

	http_request_serialize_method(req, &buf);
	http_request_serialize_char(SPACE, &buf);

	http_request_serialize_uri(req, &buf);
	http_request_serialize_char(SPACE, &buf);

	http_request_serialize_version(req, &buf);
	http_request_serialize_char(CARRIAGE, &buf);
	http_request_serialize_char(NEW_LINE, &buf);

	cur_header = req->headers;

	while (cur_header != NULL)
	{
		content_length = http_header_get_content_length(cur_header);
		if (content_length != -1)
		{
			/* make sure it's equal to body_len */
			if (content_length != req->body_len)
			{
				return NULL;
			}
			else
				verified_content_length = true;
		}
		http_header_serialize(cur_header, &buf);
		http_request_serialize_char(CARRIAGE, &buf);
		http_request_serialize_char(NEW_LINE, &buf);

		cur_header = cur_header->next;
	}
	http_request_serialize_char(CARRIAGE, &buf);
	http_request_serialize_char(NEW_LINE, &buf);

	if (!verified_content_length)
	{
		/* Then there was no header field for Content-Length */
		if (req->body_len != 0)
		{
			return NULL;
		}
	}

	http_request_serialize_body(req, &buf);
	/* Now everything lives in buf.data */
	if (buf_size != NULL)
		*buf_size = buf.len;
	return buf.data;
}

