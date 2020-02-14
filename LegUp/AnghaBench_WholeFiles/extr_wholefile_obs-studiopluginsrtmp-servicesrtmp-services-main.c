#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ array; } ;
struct file_download_data {TYPE_1__ buffer; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  proc_handler_t ;
typedef  int /*<<< orphan*/  obs_data_t ;
typedef  int /*<<< orphan*/  calldata_t ;
struct TYPE_7__ {char const* array; } ;

/* Variables and functions */
 int RTMP_SERVICES_FORMAT_VERSION ; 
 int /*<<< orphan*/  RTMP_SERVICES_LOG_STR ; 
 int /*<<< orphan*/  RTMP_SERVICES_URL ; 
 int /*<<< orphan*/  UNUSED_PARAMETER (void*) ; 
 scalar_t__ astrcmpi (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  bfree (char*) ; 
 scalar_t__ calldata_int (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dstr_cat (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dstr_copy (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dstr_free (TYPE_2__*) ; 
 int /*<<< orphan*/  init_twitch_data () ; 
 int /*<<< orphan*/  load_twitch_data () ; 
 TYPE_2__ module_name ; 
 int /*<<< orphan*/ * obs_data_create_from_json (char*) ; 
 scalar_t__ obs_data_get_int (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  obs_data_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * obs_get_proc_handler () ; 
 char* obs_get_version_string () ; 
 char* obs_module_config_path (char*) ; 
 char* obs_module_file (char*) ; 
 int /*<<< orphan*/  obs_register_service (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  proc_handler_add (int /*<<< orphan*/ *,char*,void (*) (void*,int /*<<< orphan*/ *),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtmp_common_service ; 
 int /*<<< orphan*/  rtmp_custom_service ; 
 int /*<<< orphan*/  twitch_ingests_refresh (int) ; 
 int /*<<< orphan*/  unload_twitch_data () ; 
 int /*<<< orphan*/  update_info ; 
 int /*<<< orphan*/  update_info_create (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,char*,char*,int (*) (void*,struct file_download_data*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  update_info_destroy (int /*<<< orphan*/ ) ; 

const char *get_module_name(void)
{
	return module_name.array;
}

__attribute__((used)) static bool confirm_service_file(void *param, struct file_download_data *file)
{
	if (astrcmpi(file->name, "services.json") == 0) {
		obs_data_t *data;
		int format_version;

		data = obs_data_create_from_json((char*)file->buffer.array);
		if (!data)
			return false;

		format_version = (int)obs_data_get_int(data, "format_version");
		obs_data_release(data);

		if (format_version != RTMP_SERVICES_FORMAT_VERSION)
			return false;
	}

	UNUSED_PARAMETER(param);
	return true;
}

__attribute__((used)) static void refresh_callback(void *unused, calldata_t *cd)
{
	int seconds = (int)calldata_int(cd, "seconds");
	if (seconds <= 0)
		seconds = 3;
	if (seconds > 10)
		seconds = 10;

	twitch_ingests_refresh(seconds);

	UNUSED_PARAMETER(unused);
}

bool obs_module_load(void)
{
	init_twitch_data();

	dstr_copy(&module_name, "rtmp-services plugin (libobs ");
	dstr_cat(&module_name, obs_get_version_string());
	dstr_cat(&module_name, ")");

	proc_handler_t *ph = obs_get_proc_handler();
	proc_handler_add(ph, "void twitch_ingests_refresh(int seconds)",
			refresh_callback, NULL);

#if !defined(_WIN32) || CHECK_FOR_SERVICE_UPDATES
	char *local_dir = obs_module_file("");
	char *cache_dir = obs_module_config_path("");

	if (cache_dir) {
		update_info = update_info_create(
				RTMP_SERVICES_LOG_STR,
				module_name.array,
				RTMP_SERVICES_URL,
				local_dir,
				cache_dir,
				confirm_service_file, NULL);
	}

	load_twitch_data();

	bfree(local_dir);
	bfree(cache_dir);
#endif

	obs_register_service(&rtmp_common_service);
	obs_register_service(&rtmp_custom_service);
	return true;
}

void obs_module_unload(void)
{
	update_info_destroy(update_info);
	unload_twitch_data();
	dstr_free(&module_name);
}

