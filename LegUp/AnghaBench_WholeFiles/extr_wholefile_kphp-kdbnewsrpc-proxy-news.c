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

/* Variables and functions */
 int TL_CNEWS_GET_GROUPED_UPDATES ; 
 int TL_CNEWS_GET_GROUPED_USER_UPDATES ; 
 int TL_CNEWS_GET_RAW_UPDATES ; 
 int TL_CNEWS_GET_RAW_USER_UPDATES ; 
 int TL_NEWS_GET_GROUPED_UPDATES ; 
 int TL_NEWS_GET_RAW_UPDATES ; 
 int TL_NNEWS_DELETE_UPDATE ; 
 int TL_NNEWS_DELETE_UPDATES ; 
 int TL_NNEWS_UNDELETE_UPDATE ; 
 int TL_RNEWS_GET_GROUPED_UPDATES ; 
 int TL_RNEWS_GET_RAW_UPDATES ; 
 int TL_RNEWS_SET_RATE ; 
 int /*<<< orphan*/  cnews_gather_methods ; 
 int /*<<< orphan*/  cnews_raw_gather_methods ; 
 int /*<<< orphan*/  cnews_raw_user_gather_methods ; 
 int /*<<< orphan*/  cnews_user_gather_methods ; 
 int default_firstint_forward () ; 
 int /*<<< orphan*/  default_query_diagonal_forward () ; 
 int default_tuple_forward (int) ; 
 int /*<<< orphan*/  merge_forward (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rnews_gather_methods ; 
 int /*<<< orphan*/  rnews_raw_gather_methods ; 
 int tl_fetch_lookup_int () ; 
 int /*<<< orphan*/  ugnews_gather_methods ; 
 int /*<<< orphan*/  ugnews_raw_gather_methods ; 

int ug_news_forward (void) {
  int op = tl_fetch_lookup_int ();
  if (op == TL_NEWS_GET_GROUPED_UPDATES) {
    merge_forward (&ugnews_gather_methods);
    return 0;
  } else if (op == TL_NEWS_GET_RAW_UPDATES) {
    merge_forward (&ugnews_raw_gather_methods);
    return 0;
  } else {
    return default_firstint_forward ();
  }
}

int g_news_forward (void) {
  return ug_news_forward ();
}

int c_news_forward (void) {
  int op = tl_fetch_lookup_int ();
  if (op == TL_CNEWS_GET_GROUPED_UPDATES) {
    merge_forward (&cnews_gather_methods);
    return 0;
  } else if (op == TL_CNEWS_GET_RAW_UPDATES) {
    merge_forward (&cnews_raw_gather_methods);
    return 0;
  } else if (op == TL_CNEWS_GET_GROUPED_USER_UPDATES) {
    merge_forward (&cnews_user_gather_methods);
    return 0;
  } else if (op == TL_CNEWS_GET_RAW_USER_UPDATES) {
    merge_forward (&cnews_raw_user_gather_methods);
    return 0;
  } else {
    return default_tuple_forward (3);
  }
}

int r_news_forward (void) {
  int op = tl_fetch_lookup_int ();
  if (op == TL_RNEWS_SET_RATE) {
    default_query_diagonal_forward ();
    return 0;
  } else if (op == TL_RNEWS_GET_RAW_UPDATES) {
    merge_forward (&rnews_raw_gather_methods);
    return 0;
  } else if (op == TL_RNEWS_GET_GROUPED_UPDATES) {
    merge_forward (&rnews_gather_methods);
    return 0;
  } else {
    return default_firstint_forward ();
  }
}

int n_news_forward (void) {
  int op = tl_fetch_lookup_int ();
  if (op == TL_NNEWS_DELETE_UPDATES || op == TL_NNEWS_DELETE_UPDATE || op == TL_NNEWS_UNDELETE_UPDATE) {
    default_query_diagonal_forward ();
    return 0;
  } else {
    return default_firstint_forward ();
  }
}

