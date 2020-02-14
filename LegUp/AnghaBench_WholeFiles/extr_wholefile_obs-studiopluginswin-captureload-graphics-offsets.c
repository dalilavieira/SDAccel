#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  char wchar_t ;
typedef  void* uint32_t ;
struct win_version_info {int major; int minor; int build; int revis; } ;
struct hook_info {int dummy; } ;
struct TYPE_6__ {void* resize; void* present1; void* present; } ;
struct TYPE_5__ {void* is_d3d9ex_clsoff; void* d3d9_clsoff; void* present_swap; void* present_ex; void* present; } ;
struct TYPE_4__ {void* present; } ;
struct graphics_offsets {TYPE_3__ dxgi; TYPE_2__ d3d9; TYPE_1__ d3d8; } ;
typedef  int /*<<< orphan*/  config_t ;
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 scalar_t__ CONFIG_SUCCESS ; 
 int /*<<< orphan*/  CreateEventW (int /*<<< orphan*/ *,int,int,char const*) ; 
 int /*<<< orphan*/  CreateFileMappingW (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  CreateMutexW (int /*<<< orphan*/ *,int,char const*) ; 
 int /*<<< orphan*/  GC_EVENT_FLAGS ; 
 int /*<<< orphan*/  GC_MUTEX_FLAGS ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  GetSystemDirectoryW (char*,int) ; 
 int /*<<< orphan*/  INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LOG_ERROR ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  OpenEventW (int /*<<< orphan*/ ,int,char const*) ; 
 int /*<<< orphan*/  OpenMutexW (int /*<<< orphan*/ ,int,char const*) ; 
 int /*<<< orphan*/  PAGE_READWRITE ; 
 char const* SHMEM_HOOK_INFO ; 
 scalar_t__ WAIT_OBJECT_0 ; 
 scalar_t__ WaitForSingleObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _snwprintf (char*,int,char*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfree (char*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  config_close (int /*<<< orphan*/ *) ; 
 scalar_t__ config_get_int (int /*<<< orphan*/ *,char const*,char*) ; 
 scalar_t__ config_get_uint (int /*<<< orphan*/ *,char*,char*) ; 
 scalar_t__ config_open_string (int /*<<< orphan*/ **,char const*) ; 
 int /*<<< orphan*/  config_set_int (int /*<<< orphan*/ *,char const*,char*,int) ; 
 int get_dll_ver (char*,struct win_version_info*) ; 
 char* os_quick_read_utf8_file (char const*) ; 
 int /*<<< orphan*/  wcscat (char*,char const*) ; 

__attribute__((used)) static inline HANDLE create_event(const wchar_t *name)
{
	return CreateEventW(NULL, false, false, name);
}

__attribute__((used)) static inline HANDLE open_event(const wchar_t *name)
{
	return OpenEventW(GC_EVENT_FLAGS, false, name);
}

__attribute__((used)) static inline HANDLE create_mutex(const wchar_t *name)
{
	return CreateMutexW(NULL, false, name);
}

__attribute__((used)) static inline HANDLE open_mutex(const wchar_t *name)
{
	return OpenMutexW(GC_MUTEX_FLAGS, false, name);
}

__attribute__((used)) static inline HANDLE create_event_plus_id(const wchar_t *name, DWORD id)
{
	wchar_t new_name[64];
	_snwprintf(new_name, 64, L"%s%lu", name, id);
	return create_event(new_name);
}

__attribute__((used)) static inline HANDLE create_mutex_plus_id(const wchar_t *name, DWORD id)
{
	wchar_t new_name[64];
	_snwprintf(new_name, 64, L"%s%lu", name, id);
	return create_mutex(new_name);
}

__attribute__((used)) static inline bool object_signalled(HANDLE event)
{
	if (!event)
		return false;

	return WaitForSingleObject(event, 0) == WAIT_OBJECT_0;
}

__attribute__((used)) static inline HANDLE create_hook_info(DWORD id)
{
	wchar_t new_name[64];
	_snwprintf(new_name, 64, L"%s%lu", SHMEM_HOOK_INFO, id);

	return CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
			0, sizeof(struct hook_info), new_name);
}

__attribute__((used)) static inline bool load_offsets_from_string(struct graphics_offsets *offsets,
		const char *str)
{
	config_t *config;

	if (config_open_string(&config, str) != CONFIG_SUCCESS) {
		return false;
	}

	offsets->d3d8.present =
		(uint32_t)config_get_uint(config, "d3d8", "present");

	offsets->d3d9.present =
		(uint32_t)config_get_uint(config, "d3d9", "present");
	offsets->d3d9.present_ex =
		(uint32_t)config_get_uint(config, "d3d9", "present_ex");
	offsets->d3d9.present_swap =
		(uint32_t)config_get_uint(config, "d3d9", "present_swap");
	offsets->d3d9.d3d9_clsoff =
		(uint32_t)config_get_uint(config, "d3d9", "d3d9_clsoff");
	offsets->d3d9.is_d3d9ex_clsoff =
		(uint32_t)config_get_uint(config, "d3d9", "is_d3d9ex_clsoff");

	offsets->dxgi.present =
		(uint32_t)config_get_uint(config, "dxgi", "present");
	offsets->dxgi.present1 =
		(uint32_t)config_get_uint(config, "dxgi", "present1");
	offsets->dxgi.resize =
		(uint32_t)config_get_uint(config, "dxgi", "resize");

	config_close(config);
	return true;
}

__attribute__((used)) static inline bool load_offsets_from_file(struct graphics_offsets *offsets,
		const char *file)
{
	char *str = os_quick_read_utf8_file(file);
	bool success = false;
	if (str && *str)
		success = load_offsets_from_string(offsets, str);
	bfree(str);
	return success;
}

__attribute__((used)) static inline bool config_ver_mismatch(
		config_t *ver_config,
		const char *section,
		struct win_version_info *ver)
{
	struct win_version_info config_ver;
	bool mismatch = false;

#define get_sub_ver(subver) \
	config_ver.subver = (int)config_get_int(ver_config, section, #subver); \
	mismatch |= config_ver.subver != ver->subver;

	get_sub_ver(major);
	get_sub_ver(minor);
	get_sub_ver(build);
	get_sub_ver(revis);

#undef get_sub_ver

	return mismatch;
}

__attribute__((used)) static inline void write_config_ver(config_t *ver_config, const char *section,
		struct win_version_info *ver)
{
#define set_sub_ver(subver) \
	config_set_int(ver_config, section, #subver, ver->subver);

	set_sub_ver(major);
	set_sub_ver(minor);
	set_sub_ver(build);
	set_sub_ver(revis);

#undef set_sub_ver
}

__attribute__((used)) static bool get_32bit_system_dll_ver(const wchar_t *system_lib,
		struct win_version_info *ver)
{
	wchar_t path[MAX_PATH];
	UINT ret;

#ifdef _WIN64
	ret = GetSystemWow64DirectoryW(path, MAX_PATH);
#else
	ret = GetSystemDirectoryW(path, MAX_PATH);
#endif
	if (!ret) {
		blog(LOG_ERROR, "Failed to get windows 32bit system path: "
		                "%lu", GetLastError());
		return false;
	}

	wcscat(path, L"\\");
	wcscat(path, system_lib);
	return get_dll_ver(path, ver);
}

