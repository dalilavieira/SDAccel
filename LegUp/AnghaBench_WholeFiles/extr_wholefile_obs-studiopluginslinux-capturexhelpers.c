#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_20__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
struct TYPE_27__ {TYPE_1__* data; scalar_t__ rem; } ;
typedef  TYPE_2__ xcb_xinerama_screen_info_iterator_t ;
struct TYPE_28__ {scalar_t__ state; int number; } ;
typedef  TYPE_3__ xcb_xinerama_query_screens_reply_t ;
typedef  int /*<<< orphan*/  xcb_xinerama_query_screens_cookie_t ;
typedef  TYPE_3__ xcb_xinerama_is_active_reply_t ;
typedef  int /*<<< orphan*/  xcb_xinerama_is_active_cookie_t ;
struct TYPE_29__ {int shmid; scalar_t__ data; int /*<<< orphan*/  seg; int /*<<< orphan*/ * xcb; } ;
typedef  TYPE_5__ xcb_shm_t ;
struct TYPE_30__ {int width_in_pixels; int height_in_pixels; int /*<<< orphan*/  root; } ;
typedef  TYPE_6__ xcb_screen_t ;
struct TYPE_31__ {TYPE_6__* data; scalar_t__ rem; } ;
typedef  TYPE_7__ xcb_screen_iterator_t ;
typedef  int /*<<< orphan*/  xcb_randr_get_screen_resources_reply_t ;
typedef  int /*<<< orphan*/  xcb_randr_get_screen_resources_cookie_t ;
struct TYPE_32__ {int x; int y; int width; int height; } ;
typedef  TYPE_8__ xcb_randr_get_crtc_info_reply_t ;
typedef  int /*<<< orphan*/  xcb_randr_get_crtc_info_cookie_t ;
typedef  int /*<<< orphan*/  xcb_randr_crtc_t ;
typedef  int /*<<< orphan*/  xcb_connection_t ;
typedef  int int_fast32_t ;
struct TYPE_26__ {int /*<<< orphan*/  present; } ;
struct TYPE_25__ {int x_org; int y_org; int width; int height; } ;

/* Variables and functions */
 int IPC_CREAT ; 
 int /*<<< orphan*/  IPC_PRIVATE ; 
 int /*<<< orphan*/  IPC_RMID ; 
 int /*<<< orphan*/  bfree (TYPE_5__*) ; 
 TYPE_5__* bzalloc (int) ; 
 int /*<<< orphan*/  free (TYPE_3__*) ; 
 scalar_t__ shmat (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shmctl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shmdt (scalar_t__) ; 
 int shmget (int /*<<< orphan*/ ,int const,int) ; 
 int /*<<< orphan*/  xcb_generate_id (int /*<<< orphan*/ *) ; 
 TYPE_20__* xcb_get_extension_data (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xcb_get_setup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xcb_randr_get_crtc_info (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_8__* xcb_randr_get_crtc_info_reply (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xcb_randr_get_screen_resources (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * xcb_randr_get_screen_resources_crtcs (int /*<<< orphan*/ *) ; 
 int xcb_randr_get_screen_resources_crtcs_length (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * xcb_randr_get_screen_resources_reply (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xcb_randr_id ; 
 int /*<<< orphan*/  xcb_screen_next (TYPE_7__*) ; 
 TYPE_7__ xcb_setup_roots_iterator (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xcb_shm_attach (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  xcb_shm_detach (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xcb_xinerama_id ; 
 TYPE_3__* xcb_xinerama_is_active_reply (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xcb_xinerama_is_active_unchecked (int /*<<< orphan*/ *) ; 
 TYPE_3__* xcb_xinerama_query_screens_reply (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_2__ xcb_xinerama_query_screens_screen_info_iterator (TYPE_3__*) ; 
 int /*<<< orphan*/  xcb_xinerama_query_screens_unchecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xcb_xinerama_screen_info_next (TYPE_2__*) ; 
 void xshm_xcb_detach (TYPE_5__*) ; 

bool xinerama_is_active(xcb_connection_t *xcb)
{
	if (!xcb || !xcb_get_extension_data(xcb, &xcb_xinerama_id)->present)
		return false;

	bool active = true;
	xcb_xinerama_is_active_cookie_t xnr_c;
	xcb_xinerama_is_active_reply_t  *xnr_r;

	xnr_c = xcb_xinerama_is_active_unchecked(xcb);
	xnr_r = xcb_xinerama_is_active_reply(xcb, xnr_c, NULL);
	if (!xnr_r || xnr_r->state == 0)
		active = false;
	free(xnr_r);

	return active;
}

int xinerama_screen_count(xcb_connection_t *xcb)
{
	if (!xcb)
		return 0;

	int screens = 0;
	xcb_xinerama_query_screens_cookie_t scr_c;
	xcb_xinerama_query_screens_reply_t  *scr_r;

	scr_c = xcb_xinerama_query_screens_unchecked(xcb);
	scr_r = xcb_xinerama_query_screens_reply(xcb, scr_c, NULL);
	if (scr_r)
		screens = scr_r->number;
	free(scr_r);

	return screens;
}

int xinerama_screen_geo(xcb_connection_t *xcb, int_fast32_t screen,
		int_fast32_t *x, int_fast32_t *y,
		int_fast32_t *w, int_fast32_t *h)
{
	if (!xcb)
		goto fail;

	bool success = false;
	xcb_xinerama_query_screens_cookie_t scr_c;
	xcb_xinerama_query_screens_reply_t  *scr_r;
	xcb_xinerama_screen_info_iterator_t iter;

	scr_c = xcb_xinerama_query_screens_unchecked(xcb);
	scr_r = xcb_xinerama_query_screens_reply(xcb, scr_c, NULL);
	if (!scr_r)
		goto fail;

	iter = xcb_xinerama_query_screens_screen_info_iterator(scr_r);
	for (; iter.rem; --screen, xcb_xinerama_screen_info_next(&iter)) {
		if (!screen) {
			*x = iter.data->x_org;
			*y = iter.data->y_org;
			*w = iter.data->width;
			*h = iter.data->height;
			success = true;
		}
	}
	free(scr_r);

	if (success)
		return 0;

fail:
	*x = *y = *w = *h = 0;
	return -1;
}

bool randr_is_active(xcb_connection_t *xcb)
{
	if (!xcb || !xcb_get_extension_data(xcb, &xcb_randr_id)->present)
		return false;

	return true;
}

int randr_screen_count(xcb_connection_t *xcb)
{
	if (!xcb)
		return 0;

	xcb_screen_t *screen;
	screen = xcb_setup_roots_iterator(xcb_get_setup(xcb)).data;

	xcb_randr_get_screen_resources_cookie_t res_c;
	xcb_randr_get_screen_resources_reply_t* res_r;

	res_c = xcb_randr_get_screen_resources(xcb, screen->root);
	res_r = xcb_randr_get_screen_resources_reply(xcb, res_c, 0);
	if (!res_r)
		return 0;

	return xcb_randr_get_screen_resources_crtcs_length(res_r);
}

int randr_screen_geo(xcb_connection_t *xcb, int_fast32_t screen,
		int_fast32_t *x, int_fast32_t *y,
		int_fast32_t *w, int_fast32_t *h,
		xcb_screen_t **rscreen)
{
	xcb_screen_t *xscreen;
	xscreen = xcb_setup_roots_iterator(xcb_get_setup(xcb)).data;

	xcb_randr_get_screen_resources_cookie_t res_c;
	xcb_randr_get_screen_resources_reply_t* res_r;

	res_c = xcb_randr_get_screen_resources(xcb, xscreen->root);
	res_r = xcb_randr_get_screen_resources_reply(xcb, res_c, 0);
	if (!res_r)
		goto fail;

	int screens = xcb_randr_get_screen_resources_crtcs_length(res_r);
	if (screen < 0 || screen >= screens)
		goto fail;

	xcb_randr_crtc_t *crtc = xcb_randr_get_screen_resources_crtcs(res_r);

	xcb_randr_get_crtc_info_cookie_t crtc_c;
	xcb_randr_get_crtc_info_reply_t *crtc_r;

	crtc_c = xcb_randr_get_crtc_info(xcb, *(crtc + screen), 0);
	crtc_r = xcb_randr_get_crtc_info_reply(xcb, crtc_c, 0);
	if (!crtc_r)
		goto fail;

	*x = crtc_r->x;
	*y = crtc_r->y;
	*w = crtc_r->width;
	*h = crtc_r->height;

	if (rscreen)
		*rscreen = xscreen;

	return 0;

fail:
	*x = *y = *w = *h = 0;
	return -1;
}

int x11_screen_geo(xcb_connection_t *xcb, int_fast32_t screen,
		int_fast32_t *w, int_fast32_t *h)
{
	if (!xcb)
		goto fail;

	bool success = false;
	xcb_screen_iterator_t iter;

	iter = xcb_setup_roots_iterator(xcb_get_setup(xcb));
	for (; iter.rem; --screen, xcb_screen_next(&iter)) {
		if (!screen) {
			*w = iter.data->width_in_pixels;
			*h = iter.data->height_in_pixels;
			success = true;
		}
	}

	if (success)
		return 0;

fail:
	*w = *h = 0;
	return -1;
}

xcb_shm_t* xshm_xcb_attach(xcb_connection_t *xcb, const int w, const int h)
{
	if (!xcb)
		return NULL;

	xcb_shm_t *shm = bzalloc(sizeof(xcb_shm_t));
	shm->xcb       = xcb;
	shm->seg       = xcb_generate_id(shm->xcb);

	shm->shmid = shmget(IPC_PRIVATE, w * h * 4, IPC_CREAT | 0777);
	if (shm->shmid == -1)
		goto fail;

	xcb_shm_attach(shm->xcb, shm->seg, shm->shmid, false);

	shm->data = shmat(shm->shmid, NULL, 0);

	return shm;
fail:
	xshm_xcb_detach(shm);
	return NULL;
}

void xshm_xcb_detach(xcb_shm_t *shm)
{
	if (!shm)
		return;

	xcb_shm_detach(shm->xcb, shm->seg);

	if ((char *) shm->data != (char *) -1)
		shmdt(shm->data);

	if (shm->shmid != -1)
		shmctl(shm->shmid, IPC_RMID, NULL);

	bfree(shm);
}

xcb_screen_t *xcb_get_screen(xcb_connection_t *xcb, int screen)
{
	xcb_screen_iterator_t iter;

	iter = xcb_setup_roots_iterator(xcb_get_setup(xcb));
	for (; iter.rem; --screen, xcb_screen_next(&iter)) {
		if (screen == 0)
			return iter.data;
	}

	return NULL;
}

