#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_9__ ;
typedef  struct TYPE_46__   TYPE_8__ ;
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_13__ ;
typedef  struct TYPE_37__   TYPE_11__ ;
typedef  struct TYPE_36__   TYPE_10__ ;

/* Type definitions */
struct TYPE_39__ {char const* member_0; TYPE_2__** playInterface; TYPE_9__** player; int /*<<< orphan*/ * uri; int /*<<< orphan*/ * member_2; int /*<<< orphan*/ * member_1; } ;
typedef  TYPE_1__ uri_player ;
struct TYPE_47__ {scalar_t__ (* Realize ) (TYPE_9__**,int /*<<< orphan*/  const) ;scalar_t__ (* GetInterface ) (TYPE_9__**,int /*<<< orphan*/ ,TYPE_2__***) ;int /*<<< orphan*/  (* Destroy ) (TYPE_9__**) ;} ;
struct TYPE_46__ {int /*<<< orphan*/  member_2; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_45__ {TYPE_10__** member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_44__ {int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_43__ {int /*<<< orphan*/ * member_1; TYPE_7__* member_0; } ;
struct TYPE_42__ {TYPE_8__* member_1; TYPE_6__* member_0; } ;
struct TYPE_41__ {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_40__ {scalar_t__ (* SetPlayState ) (TYPE_2__**,int /*<<< orphan*/ ) ;} ;
struct TYPE_38__ {scalar_t__ (* Realize ) (TYPE_13__**,int /*<<< orphan*/  const) ;scalar_t__ (* GetInterface ) (TYPE_13__**,int /*<<< orphan*/ ,TYPE_11__***) ;int /*<<< orphan*/  (* Destroy ) (TYPE_13__**) ;} ;
struct TYPE_37__ {scalar_t__ (* CreateAudioPlayer ) (TYPE_11__**,TYPE_9__***,TYPE_4__*,TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;scalar_t__ (* CreateOutputMix ) (TYPE_11__**,TYPE_10__***,int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;} ;
struct TYPE_36__ {scalar_t__ (* Realize ) (TYPE_10__**,int /*<<< orphan*/  const) ;int /*<<< orphan*/  (* Destroy ) (TYPE_10__**) ;} ;
typedef  scalar_t__ SLresult ;
typedef  int /*<<< orphan*/  SLchar ;
typedef  int /*<<< orphan*/  SLboolean ;
typedef  TYPE_2__** SLPlayItf ;
typedef  int /*<<< orphan*/  SLInterfaceID ;
typedef  TYPE_3__ SLEngineOption ;
typedef  TYPE_4__ SLDataSource ;
typedef  TYPE_5__ SLDataSink ;
typedef  TYPE_6__ SLDataLocator_URI ;
typedef  TYPE_7__ SLDataLocator_OutputMix ;
typedef  TYPE_8__ SLDataFormat_MIME ;

/* Variables and functions */
 int /*<<< orphan*/  const SL_BOOLEAN_FALSE ; 
 int /*<<< orphan*/  SL_BOOLEAN_TRUE ; 
 int /*<<< orphan*/  SL_CONTAINERTYPE_UNSPECIFIED ; 
 int /*<<< orphan*/  SL_DATAFORMAT_MIME ; 
 int /*<<< orphan*/  SL_DATALOCATOR_OUTPUTMIX ; 
 int /*<<< orphan*/  SL_DATALOCATOR_URI ; 
 int /*<<< orphan*/  SL_ENGINEOPTION_THREADSAFE ; 
 int /*<<< orphan*/  SL_IID_ENGINE ; 
 int /*<<< orphan*/  SL_IID_PLAY ; 
 int /*<<< orphan*/  const SL_IID_VOLUME ; 
 int /*<<< orphan*/  SL_PLAYSTATE_PAUSED ; 
 scalar_t__ SL_RESULT_SUCCESS ; 
 TYPE_13__** engine ; 
 TYPE_11__** engineInterface ; 
 scalar_t__ loop_start ; 
 TYPE_10__** outputMix ; 
 TYPE_1__* players ; 
 scalar_t__ slCreateEngine (TYPE_13__***,int,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char const*) ; 
 char* strdup (char*) ; 
 scalar_t__ stub1 (TYPE_11__**,TYPE_9__***,TYPE_4__*,TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub10 (TYPE_10__**) ; 
 int /*<<< orphan*/  stub11 (TYPE_13__**) ; 
 scalar_t__ stub12 (TYPE_2__**,int /*<<< orphan*/ ) ; 
 scalar_t__ stub2 (TYPE_9__**,int /*<<< orphan*/  const) ; 
 scalar_t__ stub3 (TYPE_9__**,int /*<<< orphan*/ ,TYPE_2__***) ; 
 scalar_t__ stub4 (TYPE_2__**,int /*<<< orphan*/ ) ; 
 scalar_t__ stub5 (TYPE_13__**,int /*<<< orphan*/  const) ; 
 scalar_t__ stub6 (TYPE_13__**,int /*<<< orphan*/ ,TYPE_11__***) ; 
 scalar_t__ stub7 (TYPE_11__**,TYPE_10__***,int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 scalar_t__ stub8 (TYPE_10__**,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  stub9 (TYPE_9__**) ; 

uri_player* get_player_by_uri(const char* uri) {
  for (uri_player *s = players; s->uri != NULL; s++) {
    if (strcmp(s->uri, uri) == 0) {
      return s;
    }
  }

  return NULL;
}

uri_player* slplay_create_player_for_uri(const char* uri, char **error) {
  uri_player player = { uri, NULL, NULL };

  SLresult result;
  SLDataLocator_URI locUri = {SL_DATALOCATOR_URI, (SLchar *) uri};
  SLDataFormat_MIME formatMime = {SL_DATAFORMAT_MIME, NULL, SL_CONTAINERTYPE_UNSPECIFIED};
  SLDataSource audioSrc = {&locUri, &formatMime};

  SLDataLocator_OutputMix outMix = {SL_DATALOCATOR_OUTPUTMIX, outputMix};
  SLDataSink audioSnk = {&outMix, NULL};

  result = (*engineInterface)->CreateAudioPlayer(engineInterface, &player.player, &audioSrc, &audioSnk, 0, NULL, NULL);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to create audio player");
    return NULL;
  }

  result = (*(player.player))->Realize(player.player, SL_BOOLEAN_FALSE);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to realize audio player");
    return NULL;
  }

  result = (*(player.player))->GetInterface(player.player, SL_IID_PLAY, &(player.playInterface));
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to get player interface");
    return NULL;
  }

  result = (*(player.playInterface))->SetPlayState(player.playInterface, SL_PLAYSTATE_PAUSED);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to initialize playstate to SL_PLAYSTATE_PAUSED");
    return NULL;
  }

  uri_player *p = players;
  while (p->uri != NULL) {
    p++;
  }
  *p = player;

  return p;
}

void slplay_setup(char **error) {
  SLresult result;
  SLEngineOption engineOptions[] = {{SL_ENGINEOPTION_THREADSAFE, SL_BOOLEAN_TRUE}};
  result = slCreateEngine(&engine, 1, engineOptions, 0, NULL, NULL);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to create OpenSL engine");
  }

  result = (*engine)->Realize(engine, SL_BOOLEAN_FALSE);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to realize OpenSL engine");
  }

  result = (*engine)->GetInterface(engine, SL_IID_ENGINE, &engineInterface);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to realize OpenSL engine");
  }

  const SLInterfaceID ids[1] = {SL_IID_VOLUME};
  const SLboolean req[1] = {SL_BOOLEAN_FALSE};
  result = (*engineInterface)->CreateOutputMix(engineInterface, &outputMix, 1, ids, req);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to create output mix");
  }

  result = (*outputMix)->Realize(outputMix, SL_BOOLEAN_FALSE);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to realize output mix");
  }
}

void slplay_destroy() {
  for (uri_player *player = players; player->uri != NULL; player++) {
    if (player->player) {
      (*(player->player))->Destroy(player->player);
    }
  }

  (*outputMix)->Destroy(outputMix);
  (*engine)->Destroy(engine);
}

void slplay_stop (uri_player* player, char **error) {
  SLPlayItf playInterface = player->playInterface;
  SLresult result;

  // stop a loop
  loop_start = 0;

  result = (*playInterface)->SetPlayState(playInterface, SL_PLAYSTATE_PAUSED);
  if (result != SL_RESULT_SUCCESS) {
    *error = strdup("Failed to set SL_PLAYSTATE_STOPPED");
    return;
  }
}

void slplay_stop_uri(const char* uri, char **error) {
  uri_player* player = get_player_by_uri(uri);
  slplay_stop(player, error);
}

