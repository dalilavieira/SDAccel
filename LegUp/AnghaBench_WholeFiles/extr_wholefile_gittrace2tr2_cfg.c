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
struct tr2_cfg_data {char const* member_0; int member_1; int /*<<< orphan*/  line; int /*<<< orphan*/  file; } ;
struct strbuf {int len; char* buf; } ;

/* Variables and functions */
 int /*<<< orphan*/  TR2_ENVVAR_CFG_PARAM ; 
 int /*<<< orphan*/  WM_CASEFOLD ; 
 int WM_MATCH ; 
 char* getenv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read_early_config (int (*) (char const*,char const*,void*),struct tr2_cfg_data*) ; 
 int /*<<< orphan*/  strbuf_list_free (struct strbuf**) ; 
 int /*<<< orphan*/  strbuf_setlen (struct strbuf*,int) ; 
 struct strbuf** strbuf_split_buf (char const*,int /*<<< orphan*/ ,char,int) ; 
 int /*<<< orphan*/  strbuf_trim (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_trim_trailing_newline (struct strbuf*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int tr2_cfg_count_patterns ; 
 int tr2_cfg_loaded ; 
 struct strbuf** tr2_cfg_patterns ; 
 int /*<<< orphan*/  trace2_def_param_fl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,char const*) ; 
 int wildmatch (char*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tr2_cfg_load_patterns(void)
{
	struct strbuf **s;
	const char *envvar;

	if (tr2_cfg_loaded)
		return tr2_cfg_count_patterns;
	tr2_cfg_loaded = 1;

	envvar = getenv(TR2_ENVVAR_CFG_PARAM);
	if (!envvar || !*envvar)
		return tr2_cfg_count_patterns;

	tr2_cfg_patterns = strbuf_split_buf(envvar, strlen(envvar), ',', -1);
	for (s = tr2_cfg_patterns; *s; s++) {
		struct strbuf *buf = *s;

		if (buf->len && buf->buf[buf->len - 1] == ',')
			strbuf_setlen(buf, buf->len - 1);
		strbuf_trim_trailing_newline(*s);
		strbuf_trim(*s);
	}

	tr2_cfg_count_patterns = s - tr2_cfg_patterns;
	return tr2_cfg_count_patterns;
}

void tr2_cfg_free_patterns(void)
{
	if (tr2_cfg_patterns)
		strbuf_list_free(tr2_cfg_patterns);
	tr2_cfg_count_patterns = 0;
	tr2_cfg_loaded = 0;
}

__attribute__((used)) static int tr2_cfg_cb(const char *key, const char *value, void *d)
{
	struct strbuf **s;
	struct tr2_cfg_data *data = (struct tr2_cfg_data *)d;

	for (s = tr2_cfg_patterns; *s; s++) {
		struct strbuf *buf = *s;
		int wm = wildmatch(buf->buf, key, WM_CASEFOLD);
		if (wm == WM_MATCH) {
			trace2_def_param_fl(data->file, data->line, key, value);
			return 0;
		}
	}

	return 0;
}

void tr2_cfg_list_config_fl(const char *file, int line)
{
	struct tr2_cfg_data data = { file, line };

	if (tr2_cfg_load_patterns() > 0)
		read_early_config(tr2_cfg_cb, &data);
}

void tr2_cfg_set_fl(const char *file, int line, const char *key,
		    const char *value)
{
	struct tr2_cfg_data data = { file, line };

	if (tr2_cfg_load_patterns() > 0)
		tr2_cfg_cb(key, value, &data);
}

