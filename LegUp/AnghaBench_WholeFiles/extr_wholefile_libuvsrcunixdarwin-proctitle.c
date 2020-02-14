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
typedef  int /*<<< orphan*/  namebuf ;
typedef  int /*<<< orphan*/  CFTypeRef ;

/* Variables and functions */
 int /*<<< orphan*/ * RTLD_DEFAULT ; 
 int RTLD_LAZY ; 
 int RTLD_LOCAL ; 
 int /*<<< orphan*/  S (char const*) ; 
 int /*<<< orphan*/ * application_services_handle ; 
 int /*<<< orphan*/ * core_foundation_handle ; 
 int /*<<< orphan*/ ** display_name_key ; 
 void* dlopen (char*,int) ; 
 void* dlsym (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dynamic_pthread_setname_np (char*) ; 
 int /*<<< orphan*/ * hi_services_bundle ; 
 int /*<<< orphan*/ * launch_services_bundle ; 
 scalar_t__ noErr ; 
 int /*<<< orphan*/ * pCFBundleGetBundleWithIdentifier (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ** pCFBundleGetDataPointerForName (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* pCFBundleGetFunctionPointerForName (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pCFBundleGetInfoDictionary (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pCFBundleGetMainBundle () ; 
 int /*<<< orphan*/ * pCFStringCreateWithCString ; 
 int /*<<< orphan*/  pLSApplicationCheckIn (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pLSGetCurrentApplicationASN () ; 
 int /*<<< orphan*/  pLSSetApplicationInformationItem (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pLSSetApplicationLaunchServicesServerConnectionStatus (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pSetApplicationIsDaemon (int) ; 
 int /*<<< orphan*/  uv__set_process_title_platform_fini () ; 
 int /*<<< orphan*/  uv__strscpy (char*,char const*,int) ; 

void uv__set_process_title_platform_init(void) {
  /* pthread_setname_np() first appeared in OS X 10.6 and iOS 3.2. */
  *(void **)(&dynamic_pthread_setname_np) =
      dlsym(RTLD_DEFAULT, "pthread_setname_np");

#if !TARGET_OS_IPHONE
  application_services_handle = dlopen("/System/Library/Frameworks/"
                                       "ApplicationServices.framework/"
                                       "Versions/A/ApplicationServices",
                                       RTLD_LAZY | RTLD_LOCAL);
  core_foundation_handle = dlopen("/System/Library/Frameworks/"
                                  "CoreFoundation.framework/"
                                  "Versions/A/CoreFoundation",
                                  RTLD_LAZY | RTLD_LOCAL);

  if (application_services_handle == NULL || core_foundation_handle == NULL)
    goto out;

  *(void **)(&pCFStringCreateWithCString) =
      dlsym(core_foundation_handle, "CFStringCreateWithCString");
  *(void **)(&pCFBundleGetBundleWithIdentifier) =
      dlsym(core_foundation_handle, "CFBundleGetBundleWithIdentifier");
  *(void **)(&pCFBundleGetDataPointerForName) =
      dlsym(core_foundation_handle, "CFBundleGetDataPointerForName");
  *(void **)(&pCFBundleGetFunctionPointerForName) =
      dlsym(core_foundation_handle, "CFBundleGetFunctionPointerForName");

  if (pCFStringCreateWithCString == NULL ||
      pCFBundleGetBundleWithIdentifier == NULL ||
      pCFBundleGetDataPointerForName == NULL ||
      pCFBundleGetFunctionPointerForName == NULL) {
    goto out;
  }

  launch_services_bundle =
      pCFBundleGetBundleWithIdentifier(S("com.apple.LaunchServices"));

  if (launch_services_bundle == NULL)
    goto out;

  *(void **)(&pLSGetCurrentApplicationASN) =
      pCFBundleGetFunctionPointerForName(launch_services_bundle,
                                         S("_LSGetCurrentApplicationASN"));

  if (pLSGetCurrentApplicationASN == NULL)
    goto out;

  *(void **)(&pLSSetApplicationInformationItem) =
      pCFBundleGetFunctionPointerForName(launch_services_bundle,
                                         S("_LSSetApplicationInformationItem"));

  if (pLSSetApplicationInformationItem == NULL)
    goto out;

  display_name_key = pCFBundleGetDataPointerForName(launch_services_bundle,
                                                    S("_kLSDisplayNameKey"));

  if (display_name_key == NULL || *display_name_key == NULL)
    goto out;

  *(void **)(&pCFBundleGetInfoDictionary) = dlsym(core_foundation_handle,
                                     "CFBundleGetInfoDictionary");
  *(void **)(&pCFBundleGetMainBundle) = dlsym(core_foundation_handle,
                                 "CFBundleGetMainBundle");

  if (pCFBundleGetInfoDictionary == NULL || pCFBundleGetMainBundle == NULL)
    goto out;

  /* Black 10.9 magic, to remove (Not responding) mark in Activity Monitor */
  hi_services_bundle =
      pCFBundleGetBundleWithIdentifier(S("com.apple.HIServices"));

  if (hi_services_bundle == NULL)
    goto out;

  *(void **)(&pSetApplicationIsDaemon) = pCFBundleGetFunctionPointerForName(
      hi_services_bundle,
      S("SetApplicationIsDaemon"));
  *(void **)(&pLSApplicationCheckIn) = pCFBundleGetFunctionPointerForName(
      launch_services_bundle,
      S("_LSApplicationCheckIn"));
  *(void **)(&pLSSetApplicationLaunchServicesServerConnectionStatus) =
      pCFBundleGetFunctionPointerForName(
          launch_services_bundle,
          S("_LSSetApplicationLaunchServicesServerConnectionStatus"));

  if (pSetApplicationIsDaemon == NULL ||
      pLSApplicationCheckIn == NULL ||
      pLSSetApplicationLaunchServicesServerConnectionStatus == NULL) {
    goto out;
  }

  return;

out:
  uv__set_process_title_platform_fini();
#endif  /* !TARGET_OS_IPHONE */
}

void uv__set_process_title(const char* title) {
#if !TARGET_OS_IPHONE
  if (core_foundation_handle != NULL && pSetApplicationIsDaemon(1) != noErr) {
    CFTypeRef asn;
    pLSSetApplicationLaunchServicesServerConnectionStatus(0, NULL);
    pLSApplicationCheckIn(/* Magic value */ -2,
                          pCFBundleGetInfoDictionary(pCFBundleGetMainBundle()));
    asn = pLSGetCurrentApplicationASN();
    pLSSetApplicationInformationItem(/* Magic value */ -2, asn,
                                     *display_name_key, S(title), NULL);
  }
#endif  /* !TARGET_OS_IPHONE */

  if (dynamic_pthread_setname_np != NULL) {
    char namebuf[64];  /* MAXTHREADNAMESIZE */
    uv__strscpy(namebuf, title, sizeof(namebuf));
    dynamic_pthread_setname_np(namebuf);
  }
}

