#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_55__   TYPE_9__ ;
typedef  struct TYPE_54__   TYPE_8__ ;
typedef  struct TYPE_53__   TYPE_7__ ;
typedef  struct TYPE_52__   TYPE_6__ ;
typedef  struct TYPE_51__   TYPE_5__ ;
typedef  struct TYPE_50__   TYPE_4__ ;
typedef  struct TYPE_49__   TYPE_3__ ;
typedef  struct TYPE_48__   TYPE_2__ ;
typedef  struct TYPE_47__   TYPE_1__ ;
typedef  struct TYPE_46__   TYPE_10__ ;

/* Type definitions */
struct TYPE_55__ {int /*<<< orphan*/ * hEvent; } ;
struct TYPE_47__ {TYPE_9__ overlapped; } ;
struct TYPE_48__ {TYPE_1__ io; } ;
struct TYPE_51__ {TYPE_2__ u; } ;
typedef  TYPE_5__ uv_req_t ;
struct TYPE_49__ {void* QuadPart; } ;
struct TYPE_46__ {int NumberOfHandles; TYPE_4__* Handles; TYPE_3__ Timeout; void* Exclusive; } ;
struct TYPE_52__ {scalar_t__ submitted_events_1; int events; int mask_events_1; int mask_events_2; scalar_t__ submitted_events_2; scalar_t__ socket; int flags; scalar_t__ type; TYPE_7__* loop; int /*<<< orphan*/  (* poll_cb ) (TYPE_6__*,int /*<<< orphan*/ ,unsigned char) ;TYPE_10__ afd_poll_info_2; TYPE_5__ poll_req_2; TYPE_10__ afd_poll_info_1; TYPE_5__ poll_req_1; scalar_t__ peer_socket; } ;
typedef  TYPE_6__ uv_poll_t ;
struct TYPE_53__ {scalar_t__* poll_peer_sockets; int /*<<< orphan*/ * iocp; } ;
typedef  TYPE_7__ uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_54__ {int /*<<< orphan*/  ProviderId; int /*<<< orphan*/  iProtocol; int /*<<< orphan*/  iSocketType; int /*<<< orphan*/  iAddressFamily; } ;
typedef  TYPE_8__ WSAPROTOCOL_INFOW ;
typedef  int /*<<< orphan*/  ULONG_PTR ;
struct TYPE_50__ {int Events; scalar_t__ Status; int /*<<< orphan*/ * Handle; } ;
typedef  scalar_t__ SOCKET ;
typedef  TYPE_9__ OVERLAPPED ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  TYPE_10__ AFD_POLL_INFO ;

/* Variables and functions */
 int AFD_POLL_ABORT ; 
 int AFD_POLL_ACCEPT ; 
 int AFD_POLL_ALL ; 
 int AFD_POLL_CONNECT_FAIL ; 
 int AFD_POLL_DISCONNECT ; 
 int AFD_POLL_LOCAL_CLOSE ; 
 int AFD_POLL_RECEIVE ; 
 int AFD_POLL_SEND ; 
 size_t ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateEvent (int /*<<< orphan*/ *,void*,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateIoCompletionPort (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GET_REQ_SOCK_ERROR (TYPE_5__*) ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  HANDLE_FLAG_INHERIT ; 
 void* INT64_MAX ; 
 scalar_t__ INVALID_SOCKET ; 
 int /*<<< orphan*/  REQ_SUCCESS (TYPE_5__*) ; 
 int /*<<< orphan*/  SET_REQ_ERROR (TYPE_5__*,scalar_t__) ; 
 int SOCKET_ERROR ; 
 int /*<<< orphan*/  SetHandleInformation (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 int UV_DISCONNECT ; 
 int UV_HANDLE_CLOSING ; 
 scalar_t__ UV_POLL ; 
 int UV_READABLE ; 
 int UV_WRITABLE ; 
 scalar_t__ WSAEINTR ; 
 scalar_t__ WSAGetLastError () ; 
 scalar_t__ WSASocketW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_8__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WSA_FLAG_OVERLAPPED ; 
 scalar_t__ WSA_IO_PENDING ; 
 TYPE_10__ afd_poll_info_dummy_ ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  closesocket (scalar_t__) ; 
 scalar_t__ memcmp (void*,void*,int) ; 
 int /*<<< orphan*/  memset (TYPE_9__*,int /*<<< orphan*/ ,int) ; 
 TYPE_9__ overlapped_dummy_ ; 
 int /*<<< orphan*/  overlapped_dummy_init_guard_ ; 
 int /*<<< orphan*/  stub1 (TYPE_6__*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  stub2 (TYPE_6__*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  uv__handle_closing (TYPE_6__*) ; 
 int /*<<< orphan*/  uv__handle_start (TYPE_6__*) ; 
 int /*<<< orphan*/  uv__handle_stop (TYPE_6__*) ; 
 scalar_t__ uv__is_active (TYPE_6__*) ; 
 int /*<<< orphan*/  uv_fatal_error (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  uv_insert_pending_req (TYPE_7__*,TYPE_5__*) ; 
 int uv_msafd_poll (scalar_t__,TYPE_10__*,TYPE_10__*,TYPE_9__*) ; 
 int /*<<< orphan*/ * uv_msafd_provider_ids ; 
 int /*<<< orphan*/  uv_once (int /*<<< orphan*/ *,void (*) ()) ; 
 int /*<<< orphan*/  uv_translate_sys_error (scalar_t__) ; 
 int /*<<< orphan*/  uv_want_endgame (TYPE_7__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void uv__init_overlapped_dummy(void) {
  HANDLE event;

  event = CreateEvent(NULL, TRUE, TRUE, NULL);
  if (event == NULL)
    uv_fatal_error(GetLastError(), "CreateEvent");

  memset(&overlapped_dummy_, 0, sizeof overlapped_dummy_);
  overlapped_dummy_.hEvent = (HANDLE) ((uintptr_t) event | 1);
}

__attribute__((used)) static OVERLAPPED* uv__get_overlapped_dummy(void) {
  uv_once(&overlapped_dummy_init_guard_, uv__init_overlapped_dummy);
  return &overlapped_dummy_;
}

__attribute__((used)) static AFD_POLL_INFO* uv__get_afd_poll_info_dummy(void) {
  return &afd_poll_info_dummy_;
}

__attribute__((used)) static void uv__fast_poll_submit_poll_req(uv_loop_t* loop, uv_poll_t* handle) {
  uv_req_t* req;
  AFD_POLL_INFO* afd_poll_info;
  int result;

  /* Find a yet unsubmitted req to submit. */
  if (handle->submitted_events_1 == 0) {
    req = &handle->poll_req_1;
    afd_poll_info = &handle->afd_poll_info_1;
    handle->submitted_events_1 = handle->events;
    handle->mask_events_1 = 0;
    handle->mask_events_2 = handle->events;
  } else if (handle->submitted_events_2 == 0) {
    req = &handle->poll_req_2;
    afd_poll_info = &handle->afd_poll_info_2;
    handle->submitted_events_2 = handle->events;
    handle->mask_events_1 = handle->events;
    handle->mask_events_2 = 0;
  } else {
    /* Just wait until there's an unsubmitted req. This will happen almost
     * immediately as one of the 2 outstanding requests is about to return.
     * When this happens, uv__fast_poll_process_poll_req will be called, and
     * the pending events, if needed, will be processed in a subsequent
     * request. */
    return;
  }

  /* Setting Exclusive to TRUE makes the other poll request return if there is
   * any. */
  afd_poll_info->Exclusive = TRUE;
  afd_poll_info->NumberOfHandles = 1;
  afd_poll_info->Timeout.QuadPart = INT64_MAX;
  afd_poll_info->Handles[0].Handle = (HANDLE) handle->socket;
  afd_poll_info->Handles[0].Status = 0;
  afd_poll_info->Handles[0].Events = 0;

  if (handle->events & UV_READABLE) {
    afd_poll_info->Handles[0].Events |= AFD_POLL_RECEIVE |
        AFD_POLL_DISCONNECT | AFD_POLL_ACCEPT | AFD_POLL_ABORT;
  } else {
    if (handle->events & UV_DISCONNECT) {
      afd_poll_info->Handles[0].Events |= AFD_POLL_DISCONNECT;
    }
  }
  if (handle->events & UV_WRITABLE) {
    afd_poll_info->Handles[0].Events |= AFD_POLL_SEND | AFD_POLL_CONNECT_FAIL;
  }

  memset(&req->u.io.overlapped, 0, sizeof req->u.io.overlapped);

  result = uv_msafd_poll((SOCKET) handle->peer_socket,
                         afd_poll_info,
                         afd_poll_info,
                         &req->u.io.overlapped);
  if (result != 0 && WSAGetLastError() != WSA_IO_PENDING) {
    /* Queue this req, reporting an error. */
    SET_REQ_ERROR(req, WSAGetLastError());
    uv_insert_pending_req(loop, req);
  }
}

__attribute__((used)) static int uv__fast_poll_cancel_poll_req(uv_loop_t* loop, uv_poll_t* handle) {
  AFD_POLL_INFO afd_poll_info;
  int result;

  afd_poll_info.Exclusive = TRUE;
  afd_poll_info.NumberOfHandles = 1;
  afd_poll_info.Timeout.QuadPart = INT64_MAX;
  afd_poll_info.Handles[0].Handle = (HANDLE) handle->socket;
  afd_poll_info.Handles[0].Status = 0;
  afd_poll_info.Handles[0].Events = AFD_POLL_ALL;

  result = uv_msafd_poll(handle->socket,
                         &afd_poll_info,
                         uv__get_afd_poll_info_dummy(),
                         uv__get_overlapped_dummy());

  if (result == SOCKET_ERROR) {
    DWORD error = WSAGetLastError();
    if (error != WSA_IO_PENDING)
      return error;
  }

  return 0;
}

__attribute__((used)) static void uv__fast_poll_process_poll_req(uv_loop_t* loop, uv_poll_t* handle,
    uv_req_t* req) {
  unsigned char mask_events;
  AFD_POLL_INFO* afd_poll_info;

  if (req == &handle->poll_req_1) {
    afd_poll_info = &handle->afd_poll_info_1;
    handle->submitted_events_1 = 0;
    mask_events = handle->mask_events_1;
  } else if (req == &handle->poll_req_2) {
    afd_poll_info = &handle->afd_poll_info_2;
    handle->submitted_events_2 = 0;
    mask_events = handle->mask_events_2;
  } else {
    assert(0);
    return;
  }

  /* Report an error unless the select was just interrupted. */
  if (!REQ_SUCCESS(req)) {
    DWORD error = GET_REQ_SOCK_ERROR(req);
    if (error != WSAEINTR && handle->events != 0) {
      handle->events = 0; /* Stop the watcher */
      handle->poll_cb(handle, uv_translate_sys_error(error), 0);
    }

  } else if (afd_poll_info->NumberOfHandles >= 1) {
    unsigned char events = 0;

    if ((afd_poll_info->Handles[0].Events & (AFD_POLL_RECEIVE |
        AFD_POLL_DISCONNECT | AFD_POLL_ACCEPT | AFD_POLL_ABORT)) != 0) {
      events |= UV_READABLE;
      if ((afd_poll_info->Handles[0].Events & AFD_POLL_DISCONNECT) != 0) {
        events |= UV_DISCONNECT;
      }
    }
    if ((afd_poll_info->Handles[0].Events & (AFD_POLL_SEND |
        AFD_POLL_CONNECT_FAIL)) != 0) {
      events |= UV_WRITABLE;
    }

    events &= handle->events & ~mask_events;

    if (afd_poll_info->Handles[0].Events & AFD_POLL_LOCAL_CLOSE) {
      /* Stop polling. */
      handle->events = 0;
      if (uv__is_active(handle))
        uv__handle_stop(handle);
    }

    if (events != 0) {
      handle->poll_cb(handle, 0, events);
    }
  }

  if ((handle->events & ~(handle->submitted_events_1 |
      handle->submitted_events_2)) != 0) {
    uv__fast_poll_submit_poll_req(loop, handle);
  } else if ((handle->flags & UV_HANDLE_CLOSING) &&
             handle->submitted_events_1 == 0 &&
             handle->submitted_events_2 == 0) {
    uv_want_endgame(loop, (uv_handle_t*) handle);
  }
}

__attribute__((used)) static int uv__fast_poll_set(uv_loop_t* loop, uv_poll_t* handle, int events) {
  assert(handle->type == UV_POLL);
  assert(!(handle->flags & UV_HANDLE_CLOSING));
  assert((events & ~(UV_READABLE | UV_WRITABLE | UV_DISCONNECT)) == 0);

  handle->events = events;

  if (handle->events != 0) {
    uv__handle_start(handle);
  } else {
    uv__handle_stop(handle);
  }

  if ((handle->events & ~(handle->submitted_events_1 |
      handle->submitted_events_2)) != 0) {
    uv__fast_poll_submit_poll_req(handle->loop, handle);
  }

  return 0;
}

__attribute__((used)) static int uv__fast_poll_close(uv_loop_t* loop, uv_poll_t* handle) {
  handle->events = 0;
  uv__handle_closing(handle);

  if (handle->submitted_events_1 == 0 &&
      handle->submitted_events_2 == 0) {
    uv_want_endgame(loop, (uv_handle_t*) handle);
    return 0;
  } else {
    /* Cancel outstanding poll requests by executing another, unique poll
     * request that forces the outstanding ones to return. */
    return uv__fast_poll_cancel_poll_req(loop, handle);
  }
}

__attribute__((used)) static SOCKET uv__fast_poll_create_peer_socket(HANDLE iocp,
    WSAPROTOCOL_INFOW* protocol_info) {
  SOCKET sock = 0;

  sock = WSASocketW(protocol_info->iAddressFamily,
                    protocol_info->iSocketType,
                    protocol_info->iProtocol,
                    protocol_info,
                    0,
                    WSA_FLAG_OVERLAPPED);
  if (sock == INVALID_SOCKET) {
    return INVALID_SOCKET;
  }

  if (!SetHandleInformation((HANDLE) sock, HANDLE_FLAG_INHERIT, 0)) {
    goto error;
  };

  if (CreateIoCompletionPort((HANDLE) sock,
                             iocp,
                             (ULONG_PTR) sock,
                             0) == NULL) {
    goto error;
  }

  return sock;

 error:
  closesocket(sock);
  return INVALID_SOCKET;
}

__attribute__((used)) static SOCKET uv__fast_poll_get_peer_socket(uv_loop_t* loop,
    WSAPROTOCOL_INFOW* protocol_info) {
  int index, i;
  SOCKET peer_socket;

  index = -1;
  for (i = 0; (size_t) i < ARRAY_SIZE(uv_msafd_provider_ids); i++) {
    if (memcmp((void*) &protocol_info->ProviderId,
               (void*) &uv_msafd_provider_ids[i],
               sizeof protocol_info->ProviderId) == 0) {
      index = i;
    }
  }

  /* Check if the protocol uses an msafd socket. */
  if (index < 0) {
    return INVALID_SOCKET;
  }

  /* If we didn't (try) to create a peer socket yet, try to make one. Don't try
   * again if the peer socket creation failed earlier for the same protocol. */
  peer_socket = loop->poll_peer_sockets[index];
  if (peer_socket == 0) {
    peer_socket = uv__fast_poll_create_peer_socket(loop->iocp, protocol_info);
    loop->poll_peer_sockets[index] = peer_socket;
  }

  return peer_socket;
}

