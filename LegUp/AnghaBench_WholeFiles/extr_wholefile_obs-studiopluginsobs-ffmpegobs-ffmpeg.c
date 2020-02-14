#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
struct log_context {void* context; char* str; int print_prefix; } ;
struct TYPE_8__ {size_t num; struct log_context** array; } ;
typedef  int /*<<< orphan*/  AVCodec ;

/* Variables and functions */
#define  AV_LOG_DEBUG 134 
#define  AV_LOG_ERROR 133 
#define  AV_LOG_FATAL 132 
#define  AV_LOG_INFO 131 
#define  AV_LOG_PANIC 130 
#define  AV_LOG_VERBOSE 129 
#define  AV_LOG_WARNING 128 
 int LOG_DEBUG ; 
 int LOG_ERROR ; 
 int LOG_INFO ; 
 int LOG_WARNING ; 
 int /*<<< orphan*/  aac_encoder_info ; 
 TYPE_1__ active_log_contexts ; 
 int /*<<< orphan*/  av_log_default_callback ; 
 int /*<<< orphan*/  av_log_format_line (void*,int,char const*,int /*<<< orphan*/ ,char*,int,int*) ; 
 int /*<<< orphan*/  av_log_set_callback (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_register_all () ; 
 int /*<<< orphan*/ * avcodec_find_encoder_by_name (char*) ; 
 int /*<<< orphan*/  bfree (struct log_context*) ; 
 int /*<<< orphan*/  blog (int,char*,...) ; 
 struct log_context* bzalloc (int) ; 
 TYPE_1__ cached_log_contexts ; 
 int /*<<< orphan*/  da_erase_item (TYPE_1__,struct log_context**) ; 
 int /*<<< orphan*/  da_free (TYPE_1__) ; 
 int /*<<< orphan*/  da_init (TYPE_1__) ; 
 int /*<<< orphan*/  da_pop_back (TYPE_1__) ; 
 int /*<<< orphan*/  da_push_back (TYPE_1__,struct log_context**) ; 
 int /*<<< orphan*/  ffmpeg_muxer ; 
 int /*<<< orphan*/  ffmpeg_output ; 
 int /*<<< orphan*/  ffmpeg_source ; 
 int /*<<< orphan*/  log_contexts_mutex ; 
 int /*<<< orphan*/  nvenc_check_name ; 
 int /*<<< orphan*/  nvenc_encoder_info ; 
 int /*<<< orphan*/  obs_register_encoder (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  obs_register_output (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  obs_register_source (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opus_encoder_info ; 
 int /*<<< orphan*/  os_dlclose (void*) ; 
 void* os_dlopen (char*) ; 
 int /*<<< orphan*/  profile_end (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  profile_start (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  replay_buffer ; 
 int strlen (char*) ; 

__attribute__((used)) static struct log_context *create_or_fetch_log_context(void *context)
{
	pthread_mutex_lock(&log_contexts_mutex);
	for (size_t i = 0; i < active_log_contexts.num; i++) {
		if (context == active_log_contexts.array[i]->context) {
			pthread_mutex_unlock(&log_contexts_mutex);
			return active_log_contexts.array[i];
		}
	}

	struct log_context *new_log_context = NULL;

	size_t cnt = cached_log_contexts.num;
	if (!!cnt) {
		new_log_context = cached_log_contexts.array[cnt - 1];
		da_pop_back(cached_log_contexts);
	}

	if (!new_log_context)
		new_log_context = bzalloc(sizeof(struct log_context));

	new_log_context->context = context;
	new_log_context->str[0] = '\0';
	new_log_context->print_prefix = 1;

	da_push_back(active_log_contexts, &new_log_context);

	pthread_mutex_unlock(&log_contexts_mutex);

	return new_log_context;
}

__attribute__((used)) static void destroy_log_context(struct log_context *log_context)
{
	pthread_mutex_lock(&log_contexts_mutex);
	da_erase_item(active_log_contexts, &log_context);
	da_push_back(cached_log_contexts, &log_context);
	pthread_mutex_unlock(&log_contexts_mutex);
}

__attribute__((used)) static void ffmpeg_log_callback(void* context, int level, const char* format,
	va_list args)
{
	if (format == NULL)
		return;

	struct log_context *log_context = create_or_fetch_log_context(context);

	char *str = log_context->str;

	av_log_format_line(context, level, format, args, str + strlen(str),
			(int)(sizeof(log_context->str) - strlen(str)),
			&log_context->print_prefix);

	int obs_level;
	switch (level) {
	case AV_LOG_PANIC:
	case AV_LOG_FATAL:
		obs_level = LOG_ERROR;
		break;
	case AV_LOG_ERROR:
	case AV_LOG_WARNING:
		obs_level = LOG_WARNING;
		break;
	case AV_LOG_INFO:
	case AV_LOG_VERBOSE:
		obs_level = LOG_INFO;
		break;
	case AV_LOG_DEBUG:
	default:
		obs_level = LOG_DEBUG;
	}

	if (!log_context->print_prefix)
		return;

	char *str_end = str + strlen(str) - 1;
	while(str < str_end) {
		if (*str_end != '\n')
			break;
		*str_end-- = '\0';
	}

	if (str_end <= str)
		goto cleanup;

	blog(obs_level, "[ffmpeg] %s", str);

cleanup:
	destroy_log_context(log_context);
}

__attribute__((used)) static bool nvenc_supported(void)
{
	av_register_all();

	profile_start(nvenc_check_name);

	AVCodec *nvenc = avcodec_find_encoder_by_name("nvenc_h264");
	void *lib = NULL;
	bool success = false;

	if (!nvenc) {
		goto cleanup;
	}

#if defined(_WIN32)
	if (!nvenc_device_available()) {
		goto cleanup;
	}
	if (load_nvenc_lib()) {
		success = true;
		goto finish;
	}
#else
	lib = os_dlopen("libnvidia-encode.so.1");
#endif

	/* ------------------------------------------- */

	success = !!lib;

cleanup:
	if (lib)
		os_dlclose(lib);
#if defined(_WIN32)
finish:
#endif
	profile_end(nvenc_check_name);
	return success;
}

bool obs_module_load(void)
{
	da_init(active_log_contexts);
	da_init(cached_log_contexts);

	//av_log_set_callback(ffmpeg_log_callback);

	obs_register_source(&ffmpeg_source);
	obs_register_output(&ffmpeg_output);
	obs_register_output(&ffmpeg_muxer);
	obs_register_output(&replay_buffer);
	obs_register_encoder(&aac_encoder_info);
	obs_register_encoder(&opus_encoder_info);
#ifndef __APPLE__
	if (nvenc_supported()) {
		blog(LOG_INFO, "NVENC supported");
#ifdef _WIN32
		if (get_win_ver_int() > 0x0601) {
			jim_nvenc_load();
		}
#endif
		obs_register_encoder(&nvenc_encoder_info);
	}
#if !defined(_WIN32) && defined(LIBAVUTIL_VAAPI_AVAILABLE)
	if (vaapi_supported()) {
		blog(LOG_INFO, "FFMPEG VAAPI supported");
		obs_register_encoder(&vaapi_encoder_info);
	}
#endif
#endif
	return true;
}

void obs_module_unload(void)
{
	av_log_set_callback(av_log_default_callback);

#ifdef _WIN32
	pthread_mutex_destroy(&log_contexts_mutex);
#endif

	for (size_t i = 0; i < active_log_contexts.num; i++) {
		bfree(active_log_contexts.array[i]);
	}
	for (size_t i = 0; i < cached_log_contexts.num; i++) {
		bfree(cached_log_contexts.array[i]);
	}

	da_free(active_log_contexts);
	da_free(cached_log_contexts);

#ifdef _WIN32
	jim_nvenc_unload();
#endif
}

