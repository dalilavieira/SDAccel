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
struct timeval {int tv_sec; int tv_usec; } ;
struct pollfd {int fd; int events; int revents; } ;
typedef  size_t nfds_t ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  int /*<<< orphan*/  data ;

/* Variables and functions */
 int ECONNABORTED ; 
 int ECONNRESET ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENETRESET ; 
 int ENOTCONN ; 
 int ENOTSOCK ; 
 int EOVERFLOW ; 
 int ESHUTDOWN ; 
 scalar_t__ FD_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int FD_SETSIZE ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int INFTIM ; 
 int /*<<< orphan*/  MSG_PEEK ; 
 int POLLERR ; 
 int POLLHUP ; 
 int POLLIN ; 
 int POLLOUT ; 
 int POLLPRI ; 
 int POLLRDBAND ; 
 int POLLRDNORM ; 
 int POLLWRBAND ; 
 int POLLWRNORM ; 
 int errno ; 
 int recv (int,char*,int,int /*<<< orphan*/ ) ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timeval*) ; 

__attribute__((used)) static int
compute_revents (int fd, int sought, fd_set *rfds, fd_set *wfds, fd_set *efds)
{
  int happened = 0;
  if (FD_ISSET (fd, rfds))
    {
      int r;
      int socket_errno;

# if defined __MACH__ && defined __APPLE__
      /* There is a bug in Mac OS X that causes it to ignore MSG_PEEK
	 for some kinds of descriptors.  Detect if this descriptor is a
	 connected socket, a server socket, or something else using a
	 0-byte recv, and use ioctl(2) to detect POLLHUP.  */
      r = recv (fd, NULL, 0, MSG_PEEK);
      socket_errno = (r < 0) ? errno : 0;
      if (r == 0 || socket_errno == ENOTSOCK)
	ioctl (fd, FIONREAD, &r);
# else
      char data[64];
      r = recv (fd, data, sizeof (data), MSG_PEEK);
      socket_errno = (r < 0) ? errno : 0;
# endif
      if (r == 0)
	happened |= POLLHUP;

      /* If the event happened on an unconnected server socket,
	 that's fine. */
      else if (r > 0 || ( /* (r == -1) && */ socket_errno == ENOTCONN))
	happened |= (POLLIN | POLLRDNORM) & sought;

      /* Distinguish hung-up sockets from other errors.  */
      else if (socket_errno == ESHUTDOWN || socket_errno == ECONNRESET
	       || socket_errno == ECONNABORTED || socket_errno == ENETRESET)
	happened |= POLLHUP;

      /* some systems can't use recv() on non-socket, including HP NonStop */
      else if (/* (r == -1) && */ socket_errno == ENOTSOCK)
	happened |= (POLLIN | POLLRDNORM) & sought;

      else
	happened |= POLLERR;
    }

  if (FD_ISSET (fd, wfds))
    happened |= (POLLOUT | POLLWRNORM | POLLWRBAND) & sought;

  if (FD_ISSET (fd, efds))
    happened |= (POLLPRI | POLLRDBAND) & sought;

  return happened;
}

int
poll (struct pollfd *pfd, nfds_t nfd, int timeout)
{
#ifndef WIN32_NATIVE
  fd_set rfds, wfds, efds;
  struct timeval tv;
  struct timeval *ptv;
  int maxfd, rc;
  nfds_t i;

# ifdef _SC_OPEN_MAX
  static int sc_open_max = -1;

  if (nfd < 0
      || (nfd > sc_open_max
	  && (sc_open_max != -1
	      || nfd > (sc_open_max = sysconf (_SC_OPEN_MAX)))))
    {
      errno = EINVAL;
      return -1;
    }
# else /* !_SC_OPEN_MAX */
#  ifdef OPEN_MAX
  if (nfd < 0 || nfd > OPEN_MAX)
    {
      errno = EINVAL;
      return -1;
    }
#  endif /* OPEN_MAX -- else, no check is needed */
# endif /* !_SC_OPEN_MAX */

  /* EFAULT is not necessary to implement, but let's do it in the
     simplest case. */
  if (!pfd && nfd)
    {
      errno = EFAULT;
      return -1;
    }

  /* convert timeout number into a timeval structure */
  if (timeout == 0)
    {
      ptv = &tv;
      ptv->tv_sec = 0;
      ptv->tv_usec = 0;
    }
  else if (timeout > 0)
    {
      ptv = &tv;
      ptv->tv_sec = timeout / 1000;
      ptv->tv_usec = (timeout % 1000) * 1000;
    }
  else if (timeout == INFTIM)
    /* wait forever */
    ptv = NULL;
  else
    {
      errno = EINVAL;
      return -1;
    }

  /* create fd sets and determine max fd */
  maxfd = -1;
  FD_ZERO (&rfds);
  FD_ZERO (&wfds);
  FD_ZERO (&efds);
  for (i = 0; i < nfd; i++)
    {
      if (pfd[i].fd < 0)
	continue;

      if (pfd[i].events & (POLLIN | POLLRDNORM))
	FD_SET (pfd[i].fd, &rfds);

      /* see select(2): "the only exceptional condition detectable
	 is out-of-band data received on a socket", hence we push
	 POLLWRBAND events onto wfds instead of efds. */
      if (pfd[i].events & (POLLOUT | POLLWRNORM | POLLWRBAND))
	FD_SET (pfd[i].fd, &wfds);
      if (pfd[i].events & (POLLPRI | POLLRDBAND))
	FD_SET (pfd[i].fd, &efds);
      if (pfd[i].fd >= maxfd
	  && (pfd[i].events & (POLLIN | POLLOUT | POLLPRI
			       | POLLRDNORM | POLLRDBAND
			       | POLLWRNORM | POLLWRBAND)))
	{
	  maxfd = pfd[i].fd;
	  if (maxfd > FD_SETSIZE)
	    {
	      errno = EOVERFLOW;
	      return -1;
	    }
	}
    }

  /* examine fd sets */
  rc = select (maxfd + 1, &rfds, &wfds, &efds, ptv);
  if (rc < 0)
    return rc;

  /* establish results */
  rc = 0;
  for (i = 0; i < nfd; i++)
    if (pfd[i].fd < 0)
      pfd[i].revents = 0;
    else
      {
	int happened = compute_revents (pfd[i].fd, pfd[i].events,
					&rfds, &wfds, &efds);
	if (happened)
	  {
	    pfd[i].revents = happened;
	    rc++;
	  }
	else
	  {
	    pfd[i].revents = 0;
	  }
      }

  return rc;
#else
  static struct timeval tv0;
  static HANDLE hEvent;
  WSANETWORKEVENTS ev;
  HANDLE h, handle_array[FD_SETSIZE + 2];
  DWORD ret, wait_timeout, nhandles, orig_timeout = 0;
  ULONGLONG start = 0;
  fd_set rfds, wfds, xfds;
  BOOL poll_again;
  MSG msg;
  int rc = 0;
  nfds_t i;

  if (nfd < 0 || timeout < -1)
    {
      errno = EINVAL;
      return -1;
    }

  if (timeout != INFTIM)
    {
      orig_timeout = timeout;
      start = GetTickCount64();
    }

  if (!hEvent)
    hEvent = CreateEvent (NULL, FALSE, FALSE, NULL);

restart:
  handle_array[0] = hEvent;
  nhandles = 1;
  FD_ZERO (&rfds);
  FD_ZERO (&wfds);
  FD_ZERO (&xfds);

  /* Classify socket handles and create fd sets. */
  for (i = 0; i < nfd; i++)
    {
      int sought = pfd[i].events;
      pfd[i].revents = 0;
      if (pfd[i].fd < 0)
	continue;
      if (!(sought & (POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM | POLLWRBAND
		      | POLLPRI | POLLRDBAND)))
	continue;

      h = (HANDLE) _get_osfhandle (pfd[i].fd);
      assert (h != NULL);
      if (IsSocketHandle (h))
	{
	  int requested = FD_CLOSE;

	  /* see above; socket handles are mapped onto select.  */
	  if (sought & (POLLIN | POLLRDNORM))
	    {
	      requested |= FD_READ | FD_ACCEPT;
	      FD_SET ((SOCKET) h, &rfds);
	    }
	  if (sought & (POLLOUT | POLLWRNORM | POLLWRBAND))
	    {
	      requested |= FD_WRITE | FD_CONNECT;
	      FD_SET ((SOCKET) h, &wfds);
	    }
	  if (sought & (POLLPRI | POLLRDBAND))
	    {
	      requested |= FD_OOB;
	      FD_SET ((SOCKET) h, &xfds);
	    }

	  if (requested)
	    WSAEventSelect ((SOCKET) h, hEvent, requested);
	}
      else
	{
	  /* Poll now.  If we get an event, do not poll again.  Also,
	     screen buffer handles are waitable, and they'll block until
	     a character is available.  win32_compute_revents eliminates
	     bits for the "wrong" direction. */
	  pfd[i].revents = win32_compute_revents (h, &sought);
	  if (sought)
	    handle_array[nhandles++] = h;
	  if (pfd[i].revents)
	    timeout = 0;
	}
    }

  if (select (0, &rfds, &wfds, &xfds, &tv0) > 0)
    {
      /* Do MsgWaitForMultipleObjects anyway to dispatch messages, but
	 no need to call select again.  */
      poll_again = FALSE;
      wait_timeout = 0;
    }
  else
    {
      poll_again = TRUE;
      if (timeout == INFTIM)
	wait_timeout = INFINITE;
      else
	wait_timeout = timeout;
    }

  for (;;)
    {
      ret = MsgWaitForMultipleObjects (nhandles, handle_array, FALSE,
				       wait_timeout, QS_ALLINPUT);

      if (ret == WAIT_OBJECT_0 + nhandles)
	{
	  /* new input of some other kind */
	  BOOL bRet;
	  while ((bRet = PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)) != 0)
	    {
	      TranslateMessage (&msg);
	      DispatchMessage (&msg);
	    }
	}
      else
	break;
    }

  if (poll_again)
    select (0, &rfds, &wfds, &xfds, &tv0);

  /* Place a sentinel at the end of the array.  */
  handle_array[nhandles] = NULL;
  nhandles = 1;
  for (i = 0; i < nfd; i++)
    {
      int happened;

      if (pfd[i].fd < 0)
	continue;
      if (!(pfd[i].events & (POLLIN | POLLRDNORM |
			     POLLOUT | POLLWRNORM | POLLWRBAND)))
	continue;

      h = (HANDLE) _get_osfhandle (pfd[i].fd);
      if (h != handle_array[nhandles])
	{
	  /* It's a socket.  */
	  WSAEnumNetworkEvents ((SOCKET) h, NULL, &ev);
	  WSAEventSelect ((SOCKET) h, NULL, 0);

	  /* If we're lucky, WSAEnumNetworkEvents already provided a way
	     to distinguish FD_READ and FD_ACCEPT; this saves a recv later.  */
	  if (FD_ISSET ((SOCKET) h, &rfds)
	      && !(ev.lNetworkEvents & (FD_READ | FD_ACCEPT)))
	    ev.lNetworkEvents |= FD_READ | FD_ACCEPT;
	  if (FD_ISSET ((SOCKET) h, &wfds))
	    ev.lNetworkEvents |= FD_WRITE | FD_CONNECT;
	  if (FD_ISSET ((SOCKET) h, &xfds))
	    ev.lNetworkEvents |= FD_OOB;

	  happened = win32_compute_revents_socket ((SOCKET) h, pfd[i].events,
						   ev.lNetworkEvents);
	}
      else
	{
	  /* Not a socket.  */
	  int sought = pfd[i].events;
	  happened = win32_compute_revents (h, &sought);
	  nhandles++;
	}

       if ((pfd[i].revents |= happened) != 0)
	rc++;
    }

  if (!rc && orig_timeout && timeout != INFTIM)
    {
      ULONGLONG elapsed = GetTickCount64() - start;
      timeout = elapsed >= orig_timeout ? 0 : (int)(orig_timeout - elapsed);
    }

  if (!rc && timeout)
    {
      SleepEx (1, TRUE);
      goto restart;
    }

  return rc;
#endif
}

