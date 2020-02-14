#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_7__ {int key_len; int value_len; scalar_t__ value; scalar_t__ key; } ;
struct TYPE_8__ {TYPE_1__ base; } ;
typedef  TYPE_2__ SdbKv ;
typedef  int /*<<< orphan*/  Rangstr ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 char* api_json_get (char*,char*) ; 
 char* api_json_set (char*,char*,char*) ; 
 int fread (char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  json_get (char*,char*) ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  rangstr_print (int /*<<< orphan*/ *) ; 
 char* sdb_json_indent (char*,char*) ; 
 char* sdb_json_unindent (char*) ; 
 int /*<<< orphan*/  stdin ; 

__attribute__((used)) static inline int seek_set(int fd, off_t pos) {
	return ((fd == -1) || (lseek (fd, (off_t) pos, SEEK_SET) == -1))? 0:1;
}

__attribute__((used)) static inline void ut32_pack(char s[4], ut32 u) {
	s[0] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	s[3] = u >> 8;
}

__attribute__((used)) static inline void ut32_pack_big(char s[4], ut32 u) {
	s[3] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	s[0] = u >> 8;
}

__attribute__((used)) static inline void ut32_unpack(char s[4], ut32 *u) {
	ut32 result = 0;
	result = (ut8) s[3];
	result <<= 8;
	result += (ut8) s[2];
	result <<= 8;
	result += (ut8) s[1];
	result <<= 8;
	result += (ut8) s[0];
	*u = result;
}

__attribute__((used)) static inline char *sdbkv_key(const SdbKv *kv) {
	return (char *)kv->base.key;
}

__attribute__((used)) static inline char *sdbkv_value(const SdbKv *kv) {
	return (char *)kv->base.value;
}

__attribute__((used)) static inline ut32 sdbkv_key_len(const SdbKv *kv) {
	return kv->base.key_len;
}

__attribute__((used)) static inline ut32 sdbkv_value_len(const SdbKv *kv) {
	return kv->base.value_len;
}

int test_main () {
	Rangstr rs ;

	rs = json_get ("{\"hello\":\"world\"}", "hello");
printf ("OUT: ");
rangstr_print (&rs);
printf ("\n");

printf ("--\n");
	rs = json_get ("{\"hello\":{\"world\":123}}", "hello.world");
printf ("OUT: ");
rangstr_print (&rs);
printf ("\n");
	return 0;
}

int test_glossary(char *buf) {
	char *path;
{
	path = "glossary.title";
	char *s= api_json_set (buf, path, "patata");
	if (s) {
		printf ("%s\n", s);
		free (s);
	} else printf ("set failed\n");
}
{
	path = "glossary.title";
	char *s= api_json_get (buf, path);
	if (s) {
		printf ("%s\n", s);
		free (s);
	} else printf ("set failed\n");
}
{
	path = "glossary.title";
	char *s= api_json_get (buf, path);
	if (s) {
		printf ("%s\n", s);
		free (s);
	} else printf ("set failed\n");
}
return 0;
}

int main(int argc, char **argv) {
	Rangstr rs;
	char buf[4096];
	int n = fread (buf, 1, sizeof (buf), stdin);
	buf[n] = 0;
//return test_glossary (buf);
//return test_main ();
	char *path = argv[1];

#if 1
	printf (">>>> %s <<<<\n", sdb_json_unindent (buf));
	printf (">>>> %s <<<<\n", sdb_json_indent (buf, "  "));
// set value //
	path = "glossary.title";
	char *s = api_json_set (buf, path, "patata");
	if (s) {
		printf ("%s\n", s);
		free (s);
	} else printf ("set failed\n");
#endif
//printf ("%s\n", str); return 0;

//	s = "[1,3,4]";
#if 0
	char *a = "{}";
	a = json_seti (a, "id", 123);
	a = json_seti (a, "user.name", "blah");
	printf ("id = %d\n", json_geti ("{'id':123}", "id"));
#endif
	//json_walk (buf);

	path = argv[1];
	rs = json_get (buf, path);
	printf ("-- output --\n");
	rangstr_print(&rs);
	printf ("\n");
	return 0;
}

