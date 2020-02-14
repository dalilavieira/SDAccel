#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct skynet_config {int thread; char const* module_path; int harbor; char const* bootstrap; char const* daemon; char const* logger; char const* logservice; int profile; } ;
struct sigaction {int /*<<< orphan*/  sa_mask; scalar_t__ sa_flags; int /*<<< orphan*/  sa_handler; } ;
struct lua_State {int dummy; } ;
typedef  struct lua_State lua_State ;

/* Variables and functions */
 int LUA_OK ; 
 int LUA_TBOOLEAN ; 
 int LUA_TSTRING ; 
 int /*<<< orphan*/  SIGPIPE ; 
 int /*<<< orphan*/  SIG_IGN ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  load_config ; 
 int luaL_loadbufferx (struct lua_State*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 struct lua_State* luaL_newstate () ; 
 int /*<<< orphan*/  luaL_openlibs (struct lua_State*) ; 
 int /*<<< orphan*/  lua_close (struct lua_State*) ; 
 scalar_t__ lua_next (struct lua_State*,int) ; 
 int lua_pcall (struct lua_State*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (struct lua_State*,int) ; 
 int /*<<< orphan*/  lua_pushnil (struct lua_State*) ; 
 int /*<<< orphan*/  lua_pushstring (struct lua_State*,char const*) ; 
 int lua_toboolean (struct lua_State*,int) ; 
 char* lua_tostring (struct lua_State*,int) ; 
 int lua_type (struct lua_State*,int) ; 
 int /*<<< orphan*/  sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skynet_env_init () ; 
 char* skynet_getenv (char const*) ; 
 int /*<<< orphan*/  skynet_globalexit () ; 
 int /*<<< orphan*/  skynet_globalinit () ; 
 int /*<<< orphan*/  skynet_setenv (char const*,char const*) ; 
 int /*<<< orphan*/  skynet_start (struct skynet_config*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int strtol (char const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int luaS_shrinfo(lua_State *L) { return 0; }

__attribute__((used)) static inline void luaS_initshr() {}

__attribute__((used)) static inline void luaS_exitshr() {}

__attribute__((used)) static inline void luaS_expandshr(int n) {}

__attribute__((used)) static int
optint(const char *key, int opt) {
	const char * str = skynet_getenv(key);
	if (str == NULL) {
		char tmp[20];
		sprintf(tmp,"%d",opt);
		skynet_setenv(key, tmp);
		return opt;
	}
	return strtol(str, NULL, 10);
}

__attribute__((used)) static int
optboolean(const char *key, int opt) {
	const char * str = skynet_getenv(key);
	if (str == NULL) {
		skynet_setenv(key, opt ? "true" : "false");
		return opt;
	}
	return strcmp(str,"true")==0;
}

__attribute__((used)) static const char *
optstring(const char *key,const char * opt) {
	const char * str = skynet_getenv(key);
	if (str == NULL) {
		if (opt) {
			skynet_setenv(key, opt);
			opt = skynet_getenv(key);
		}
		return opt;
	}
	return str;
}

__attribute__((used)) static void
_init_env(lua_State *L) {
	lua_pushnil(L);  /* first key */
	while (lua_next(L, -2) != 0) {
		int keyt = lua_type(L, -2);
		if (keyt != LUA_TSTRING) {
			fprintf(stderr, "Invalid config table\n");
			exit(1);
		}
		const char * key = lua_tostring(L,-2);
		if (lua_type(L,-1) == LUA_TBOOLEAN) {
			int b = lua_toboolean(L,-1);
			skynet_setenv(key,b ? "true" : "false" );
		} else {
			const char * value = lua_tostring(L,-1);
			if (value == NULL) {
				fprintf(stderr, "Invalid config table key = %s\n", key);
				exit(1);
			}
			skynet_setenv(key,value);
		}
		lua_pop(L,1);
	}
	lua_pop(L,1);
}

int sigign() {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGPIPE, &sa, 0);
	return 0;
}

int
main(int argc, char *argv[]) {
	const char * config_file = NULL ;
	if (argc > 1) {
		config_file = argv[1];
	} else {
		fprintf(stderr, "Need a config file. Please read skynet wiki : https://github.com/cloudwu/skynet/wiki/Config\n"
			"usage: skynet configfilename\n");
		return 1;
	}

	luaS_initshr();
	skynet_globalinit();
	skynet_env_init();

	sigign();

	struct skynet_config config;

	struct lua_State *L = luaL_newstate();
	luaL_openlibs(L);	// link lua lib

	int err =  luaL_loadbufferx(L, load_config, strlen(load_config), "=[skynet config]", "t");
	assert(err == LUA_OK);
	lua_pushstring(L, config_file);

	err = lua_pcall(L, 1, 1, 0);
	if (err) {
		fprintf(stderr,"%s\n",lua_tostring(L,-1));
		lua_close(L);
		return 1;
	}
	_init_env(L);

	config.thread =  optint("thread",8);
	config.module_path = optstring("cpath","./cservice/?.so");
	config.harbor = optint("harbor", 1);
	config.bootstrap = optstring("bootstrap","snlua bootstrap");
	config.daemon = optstring("daemon", NULL);
	config.logger = optstring("logger", NULL);
	config.logservice = optstring("logservice", "logger");
	config.profile = optboolean("profile", 1);

	lua_close(L);

	skynet_start(&config);
	skynet_globalexit();
	luaS_exitshr();

	return 0;
}

