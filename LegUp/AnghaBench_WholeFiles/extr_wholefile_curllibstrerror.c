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
typedef  int CURLcode ;
typedef  int CURLSHcode ;
typedef  int CURLMcode ;

/* Variables and functions */
#define  CURLE_ABORTED_BY_CALLBACK 240 
#define  CURLE_AGAIN 239 
#define  CURLE_BAD_CONTENT_ENCODING 238 
#define  CURLE_BAD_DOWNLOAD_RESUME 237 
#define  CURLE_BAD_FUNCTION_ARGUMENT 236 
#define  CURLE_CHUNK_FAILED 235 
#define  CURLE_CONV_FAILED 234 
#define  CURLE_CONV_REQD 233 
#define  CURLE_COULDNT_CONNECT 232 
#define  CURLE_COULDNT_RESOLVE_HOST 231 
#define  CURLE_COULDNT_RESOLVE_PROXY 230 
#define  CURLE_FAILED_INIT 229 
#define  CURLE_FILESIZE_EXCEEDED 228 
#define  CURLE_FILE_COULDNT_READ_FILE 227 
#define  CURLE_FTP_ACCEPT_FAILED 226 
#define  CURLE_FTP_ACCEPT_TIMEOUT 225 
#define  CURLE_FTP_BAD_FILE_LIST 224 
#define  CURLE_FTP_CANT_GET_HOST 223 
#define  CURLE_FTP_COULDNT_RETR_FILE 222 
#define  CURLE_FTP_COULDNT_SET_TYPE 221 
#define  CURLE_FTP_COULDNT_USE_REST 220 
#define  CURLE_FTP_PORT_FAILED 219 
#define  CURLE_FTP_PRET_FAILED 218 
#define  CURLE_FTP_WEIRD_227_FORMAT 217 
#define  CURLE_FTP_WEIRD_PASS_REPLY 216 
#define  CURLE_FTP_WEIRD_PASV_REPLY 215 
#define  CURLE_FUNCTION_NOT_FOUND 214 
#define  CURLE_GOT_NOTHING 213 
#define  CURLE_HTTP2 212 
#define  CURLE_HTTP2_STREAM 211 
#define  CURLE_HTTP_POST_ERROR 210 
#define  CURLE_HTTP_RETURNED_ERROR 209 
#define  CURLE_INTERFACE_FAILED 208 
#define  CURLE_LDAP_CANNOT_BIND 207 
#define  CURLE_LDAP_INVALID_URL 206 
#define  CURLE_LDAP_SEARCH_FAILED 205 
#define  CURLE_LOGIN_DENIED 204 
#define  CURLE_NOT_BUILT_IN 203 
#define  CURLE_NO_CONNECTION_AVAILABLE 202 
#define  CURLE_OBSOLETE20 201 
#define  CURLE_OBSOLETE24 200 
#define  CURLE_OBSOLETE29 199 
#define  CURLE_OBSOLETE32 198 
#define  CURLE_OBSOLETE40 197 
#define  CURLE_OBSOLETE44 196 
#define  CURLE_OBSOLETE46 195 
#define  CURLE_OBSOLETE50 194 
#define  CURLE_OBSOLETE51 193 
#define  CURLE_OBSOLETE57 192 
#define  CURLE_OK 191 
#define  CURLE_OPERATION_TIMEDOUT 190 
#define  CURLE_OUT_OF_MEMORY 189 
#define  CURLE_PARTIAL_FILE 188 
#define  CURLE_PEER_FAILED_VERIFICATION 187 
#define  CURLE_QUOTE_ERROR 186 
#define  CURLE_RANGE_ERROR 185 
#define  CURLE_READ_ERROR 184 
#define  CURLE_RECURSIVE_API_CALL 183 
#define  CURLE_RECV_ERROR 182 
#define  CURLE_REMOTE_ACCESS_DENIED 181 
#define  CURLE_REMOTE_DISK_FULL 180 
#define  CURLE_REMOTE_FILE_EXISTS 179 
#define  CURLE_REMOTE_FILE_NOT_FOUND 178 
#define  CURLE_RTSP_CSEQ_ERROR 177 
#define  CURLE_RTSP_SESSION_ERROR 176 
#define  CURLE_SEND_ERROR 175 
#define  CURLE_SEND_FAIL_REWIND 174 
#define  CURLE_SSH 173 
#define  CURLE_SSL_CACERT_BADFILE 172 
#define  CURLE_SSL_CERTPROBLEM 171 
#define  CURLE_SSL_CIPHER 170 
#define  CURLE_SSL_CONNECT_ERROR 169 
#define  CURLE_SSL_CRL_BADFILE 168 
#define  CURLE_SSL_ENGINE_INITFAILED 167 
#define  CURLE_SSL_ENGINE_NOTFOUND 166 
#define  CURLE_SSL_ENGINE_SETFAILED 165 
#define  CURLE_SSL_INVALIDCERTSTATUS 164 
#define  CURLE_SSL_ISSUER_ERROR 163 
#define  CURLE_SSL_PINNEDPUBKEYNOTMATCH 162 
#define  CURLE_SSL_SHUTDOWN_FAILED 161 
#define  CURLE_TELNET_OPTION_SYNTAX 160 
#define  CURLE_TFTP_ILLEGAL 159 
#define  CURLE_TFTP_NOSUCHUSER 158 
#define  CURLE_TFTP_NOTFOUND 157 
#define  CURLE_TFTP_PERM 156 
#define  CURLE_TFTP_UNKNOWNID 155 
#define  CURLE_TOO_MANY_REDIRECTS 154 
#define  CURLE_UNKNOWN_OPTION 153 
#define  CURLE_UNSUPPORTED_PROTOCOL 152 
#define  CURLE_UPLOAD_FAILED 151 
#define  CURLE_URL_MALFORMAT 150 
#define  CURLE_USE_SSL_FAILED 149 
#define  CURLE_WEIRD_SERVER_REPLY 148 
#define  CURLE_WRITE_ERROR 147 
#define  CURLM_ADDED_ALREADY 146 
#define  CURLM_BAD_EASY_HANDLE 145 
#define  CURLM_BAD_HANDLE 144 
#define  CURLM_BAD_SOCKET 143 
#define  CURLM_CALL_MULTI_PERFORM 142 
#define  CURLM_INTERNAL_ERROR 141 
#define  CURLM_LAST 140 
#define  CURLM_OK 139 
#define  CURLM_OUT_OF_MEMORY 138 
#define  CURLM_RECURSIVE_API_CALL 137 
#define  CURLM_UNKNOWN_OPTION 136 
#define  CURLSHE_BAD_OPTION 135 
#define  CURLSHE_INVALID 134 
#define  CURLSHE_IN_USE 133 
#define  CURLSHE_LAST 132 
#define  CURLSHE_NOMEM 131 
#define  CURLSHE_NOT_BUILT_IN 130 
#define  CURLSHE_OK 129 
#define  CURL_LAST 128 
 int /*<<< orphan*/  DEBUGASSERT (int) ; 
 int errno ; 
 int /*<<< orphan*/  msnprintf (char*,size_t,char*,int) ; 
 char* strerror (int) ; 
 int /*<<< orphan*/  strncpy (char*,char*,size_t) ; 
 char* strrchr (char*,char) ; 

const char *
curl_easy_strerror(CURLcode error)
{
#ifndef CURL_DISABLE_VERBOSE_STRINGS
  switch(error) {
  case CURLE_OK:
    return "No error";

  case CURLE_UNSUPPORTED_PROTOCOL:
    return "Unsupported protocol";

  case CURLE_FAILED_INIT:
    return "Failed initialization";

  case CURLE_URL_MALFORMAT:
    return "URL using bad/illegal format or missing URL";

  case CURLE_NOT_BUILT_IN:
    return "A requested feature, protocol or option was not found built-in in"
      " this libcurl due to a build-time decision.";

  case CURLE_COULDNT_RESOLVE_PROXY:
    return "Couldn't resolve proxy name";

  case CURLE_COULDNT_RESOLVE_HOST:
    return "Couldn't resolve host name";

  case CURLE_COULDNT_CONNECT:
    return "Couldn't connect to server";

  case CURLE_WEIRD_SERVER_REPLY:
    return "Weird server reply";

  case CURLE_REMOTE_ACCESS_DENIED:
    return "Access denied to remote resource";

  case CURLE_FTP_ACCEPT_FAILED:
    return "FTP: The server failed to connect to data port";

  case CURLE_FTP_ACCEPT_TIMEOUT:
    return "FTP: Accepting server connect has timed out";

  case CURLE_FTP_PRET_FAILED:
    return "FTP: The server did not accept the PRET command.";

  case CURLE_FTP_WEIRD_PASS_REPLY:
    return "FTP: unknown PASS reply";

  case CURLE_FTP_WEIRD_PASV_REPLY:
    return "FTP: unknown PASV reply";

  case CURLE_FTP_WEIRD_227_FORMAT:
    return "FTP: unknown 227 response format";

  case CURLE_FTP_CANT_GET_HOST:
    return "FTP: can't figure out the host in the PASV response";

  case CURLE_HTTP2:
    return "Error in the HTTP2 framing layer";

  case CURLE_FTP_COULDNT_SET_TYPE:
    return "FTP: couldn't set file type";

  case CURLE_PARTIAL_FILE:
    return "Transferred a partial file";

  case CURLE_FTP_COULDNT_RETR_FILE:
    return "FTP: couldn't retrieve (RETR failed) the specified file";

  case CURLE_QUOTE_ERROR:
    return "Quote command returned error";

  case CURLE_HTTP_RETURNED_ERROR:
    return "HTTP response code said error";

  case CURLE_WRITE_ERROR:
    return "Failed writing received data to disk/application";

  case CURLE_UPLOAD_FAILED:
    return "Upload failed (at start/before it took off)";

  case CURLE_READ_ERROR:
    return "Failed to open/read local data from file/application";

  case CURLE_OUT_OF_MEMORY:
    return "Out of memory";

  case CURLE_OPERATION_TIMEDOUT:
    return "Timeout was reached";

  case CURLE_FTP_PORT_FAILED:
    return "FTP: command PORT failed";

  case CURLE_FTP_COULDNT_USE_REST:
    return "FTP: command REST failed";

  case CURLE_RANGE_ERROR:
    return "Requested range was not delivered by the server";

  case CURLE_HTTP_POST_ERROR:
    return "Internal problem setting up the POST";

  case CURLE_SSL_CONNECT_ERROR:
    return "SSL connect error";

  case CURLE_BAD_DOWNLOAD_RESUME:
    return "Couldn't resume download";

  case CURLE_FILE_COULDNT_READ_FILE:
    return "Couldn't read a file:// file";

  case CURLE_LDAP_CANNOT_BIND:
    return "LDAP: cannot bind";

  case CURLE_LDAP_SEARCH_FAILED:
    return "LDAP: search failed";

  case CURLE_FUNCTION_NOT_FOUND:
    return "A required function in the library was not found";

  case CURLE_ABORTED_BY_CALLBACK:
    return "Operation was aborted by an application callback";

  case CURLE_BAD_FUNCTION_ARGUMENT:
    return "A libcurl function was given a bad argument";

  case CURLE_INTERFACE_FAILED:
    return "Failed binding local connection end";

  case CURLE_TOO_MANY_REDIRECTS :
    return "Number of redirects hit maximum amount";

  case CURLE_UNKNOWN_OPTION:
    return "An unknown option was passed in to libcurl";

  case CURLE_TELNET_OPTION_SYNTAX :
    return "Malformed telnet option";

  case CURLE_GOT_NOTHING:
    return "Server returned nothing (no headers, no data)";

  case CURLE_SSL_ENGINE_NOTFOUND:
    return "SSL crypto engine not found";

  case CURLE_SSL_ENGINE_SETFAILED:
    return "Can not set SSL crypto engine as default";

  case CURLE_SSL_ENGINE_INITFAILED:
    return "Failed to initialise SSL crypto engine";

  case CURLE_SEND_ERROR:
    return "Failed sending data to the peer";

  case CURLE_RECV_ERROR:
    return "Failure when receiving data from the peer";

  case CURLE_SSL_CERTPROBLEM:
    return "Problem with the local SSL certificate";

  case CURLE_SSL_CIPHER:
    return "Couldn't use specified SSL cipher";

  case CURLE_PEER_FAILED_VERIFICATION:
    return "SSL peer certificate or SSH remote key was not OK";

  case CURLE_SSL_CACERT_BADFILE:
    return "Problem with the SSL CA cert (path? access rights?)";

  case CURLE_BAD_CONTENT_ENCODING:
    return "Unrecognized or bad HTTP Content or Transfer-Encoding";

  case CURLE_LDAP_INVALID_URL:
    return "Invalid LDAP URL";

  case CURLE_FILESIZE_EXCEEDED:
    return "Maximum file size exceeded";

  case CURLE_USE_SSL_FAILED:
    return "Requested SSL level failed";

  case CURLE_SSL_SHUTDOWN_FAILED:
    return "Failed to shut down the SSL connection";

  case CURLE_SSL_CRL_BADFILE:
    return "Failed to load CRL file (path? access rights?, format?)";

  case CURLE_SSL_ISSUER_ERROR:
    return "Issuer check against peer certificate failed";

  case CURLE_SEND_FAIL_REWIND:
    return "Send failed since rewinding of the data stream failed";

  case CURLE_LOGIN_DENIED:
    return "Login denied";

  case CURLE_TFTP_NOTFOUND:
    return "TFTP: File Not Found";

  case CURLE_TFTP_PERM:
    return "TFTP: Access Violation";

  case CURLE_REMOTE_DISK_FULL:
    return "Disk full or allocation exceeded";

  case CURLE_TFTP_ILLEGAL:
    return "TFTP: Illegal operation";

  case CURLE_TFTP_UNKNOWNID:
    return "TFTP: Unknown transfer ID";

  case CURLE_REMOTE_FILE_EXISTS:
    return "Remote file already exists";

  case CURLE_TFTP_NOSUCHUSER:
    return "TFTP: No such user";

  case CURLE_CONV_FAILED:
    return "Conversion failed";

  case CURLE_CONV_REQD:
    return "Caller must register CURLOPT_CONV_ callback options";

  case CURLE_REMOTE_FILE_NOT_FOUND:
    return "Remote file not found";

  case CURLE_SSH:
    return "Error in the SSH layer";

  case CURLE_AGAIN:
    return "Socket not ready for send/recv";

  case CURLE_RTSP_CSEQ_ERROR:
    return "RTSP CSeq mismatch or invalid CSeq";

  case CURLE_RTSP_SESSION_ERROR:
    return "RTSP session error";

  case CURLE_FTP_BAD_FILE_LIST:
    return "Unable to parse FTP file list";

  case CURLE_CHUNK_FAILED:
    return "Chunk callback failed";

  case CURLE_NO_CONNECTION_AVAILABLE:
    return "The max connection limit is reached";

  case CURLE_SSL_PINNEDPUBKEYNOTMATCH:
    return "SSL public key does not match pinned public key";

  case CURLE_SSL_INVALIDCERTSTATUS:
    return "SSL server certificate status verification FAILED";

  case CURLE_HTTP2_STREAM:
    return "Stream error in the HTTP/2 framing layer";

  case CURLE_RECURSIVE_API_CALL:
    return "API function called from within callback";

    /* error codes not used by current libcurl */
  case CURLE_OBSOLETE20:
  case CURLE_OBSOLETE24:
  case CURLE_OBSOLETE29:
  case CURLE_OBSOLETE32:
  case CURLE_OBSOLETE40:
  case CURLE_OBSOLETE44:
  case CURLE_OBSOLETE46:
  case CURLE_OBSOLETE50:
  case CURLE_OBSOLETE51:
  case CURLE_OBSOLETE57:
  case CURL_LAST:
    break;
  }
  /*
   * By using a switch, gcc -Wall will complain about enum values
   * which do not appear, helping keep this function up-to-date.
   * By using gcc -Wall -Werror, you can't forget.
   *
   * A table would not have the same benefit.  Most compilers will
   * generate code very similar to a table in any case, so there
   * is little performance gain from a table.  And something is broken
   * for the user's application, anyways, so does it matter how fast
   * it _doesn't_ work?
   *
   * The line number for the error will be near this comment, which
   * is why it is here, and not at the start of the switch.
   */
  return "Unknown error";
#else
  if(!error)
    return "No error";
  else
    return "Error";
#endif
}

const char *
curl_multi_strerror(CURLMcode error)
{
#ifndef CURL_DISABLE_VERBOSE_STRINGS
  switch(error) {
  case CURLM_CALL_MULTI_PERFORM:
    return "Please call curl_multi_perform() soon";

  case CURLM_OK:
    return "No error";

  case CURLM_BAD_HANDLE:
    return "Invalid multi handle";

  case CURLM_BAD_EASY_HANDLE:
    return "Invalid easy handle";

  case CURLM_OUT_OF_MEMORY:
    return "Out of memory";

  case CURLM_INTERNAL_ERROR:
    return "Internal error";

  case CURLM_BAD_SOCKET:
    return "Invalid socket argument";

  case CURLM_UNKNOWN_OPTION:
    return "Unknown option";

  case CURLM_ADDED_ALREADY:
    return "The easy handle is already added to a multi handle";

  case CURLM_RECURSIVE_API_CALL:
    return "API function called from within callback";

  case CURLM_LAST:
    break;
  }

  return "Unknown error";
#else
  if(error == CURLM_OK)
    return "No error";
  else
    return "Error";
#endif
}

const char *
curl_share_strerror(CURLSHcode error)
{
#ifndef CURL_DISABLE_VERBOSE_STRINGS
  switch(error) {
  case CURLSHE_OK:
    return "No error";

  case CURLSHE_BAD_OPTION:
    return "Unknown share option";

  case CURLSHE_IN_USE:
    return "Share currently in use";

  case CURLSHE_INVALID:
    return "Invalid share handle";

  case CURLSHE_NOMEM:
    return "Out of memory";

  case CURLSHE_NOT_BUILT_IN:
    return "Feature not enabled in this library";

  case CURLSHE_LAST:
    break;
  }

  return "CURLSHcode unknown";
#else
  if(error == CURLSHE_OK)
    return "No error";
  else
    return "Error";
#endif
}

const char *Curl_strerror(int err, char *buf, size_t buflen)
{
#ifdef PRESERVE_WINDOWS_ERROR_CODE
  DWORD old_win_err = GetLastError();
#endif
  int old_errno = errno;
  char *p;
  size_t max;

  DEBUGASSERT(err >= 0);

  max = buflen - 1;
  *buf = '\0';

#ifdef USE_WINSOCK

#ifdef _WIN32_WCE
  {
    wchar_t wbuf[256];
    wbuf[0] = L'\0';

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err,
                  LANG_NEUTRAL, wbuf, sizeof(wbuf)/sizeof(wchar_t), NULL);
    wcstombs(buf, wbuf, max);
  }
#else
  /* 'sys_nerr' is the maximum errno number, it is not widely portable */
  if(err >= 0 && err < sys_nerr)
    strncpy(buf, strerror(err), max);
  else {
    if(!get_winsock_error(err, buf, max) &&
       !FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err,
                       LANG_NEUTRAL, buf, (DWORD)max, NULL))
      msnprintf(buf, max, "Unknown error %d (%#x)", err, err);
  }
#endif

#else /* not USE_WINSOCK coming up */

#if defined(HAVE_STRERROR_R) && defined(HAVE_POSIX_STRERROR_R)
 /*
  * The POSIX-style strerror_r() may set errno to ERANGE if insufficient
  * storage is supplied via 'strerrbuf' and 'buflen' to hold the generated
  * message string, or EINVAL if 'errnum' is not a valid error number.
  */
  if(0 != strerror_r(err, buf, max)) {
    if('\0' == buf[0])
      msnprintf(buf, max, "Unknown error %d", err);
  }
#elif defined(HAVE_STRERROR_R) && defined(HAVE_GLIBC_STRERROR_R)
 /*
  * The glibc-style strerror_r() only *might* use the buffer we pass to
  * the function, but it always returns the error message as a pointer,
  * so we must copy that string unconditionally (if non-NULL).
  */
  {
    char buffer[256];
    char *msg = strerror_r(err, buffer, sizeof(buffer));
    if(msg)
      strncpy(buf, msg, max);
    else
      msnprintf(buf, max, "Unknown error %d", err);
  }
#elif defined(HAVE_STRERROR_R) && defined(HAVE_VXWORKS_STRERROR_R)
 /*
  * The vxworks-style strerror_r() does use the buffer we pass to the function.
  * The buffer size should be at least NAME_MAX (256)
  */
  {
    char buffer[256];
    if(OK == strerror_r(err, buffer))
      strncpy(buf, buffer, max);
    else
      msnprintf(buf, max, "Unknown error %d", err);
  }
#else
  {
    char *msg = strerror(err);
    if(msg)
      strncpy(buf, msg, max);
    else
      msnprintf(buf, max, "Unknown error %d", err);
  }
#endif

#endif /* end of ! USE_WINSOCK */

  buf[max] = '\0'; /* make sure the string is zero terminated */

  /* strip trailing '\r\n' or '\n'. */
  p = strrchr(buf, '\n');
  if(p && (p - buf) >= 2)
    *p = '\0';
  p = strrchr(buf, '\r');
  if(p && (p - buf) >= 1)
    *p = '\0';

  if(errno != old_errno)
    errno = old_errno;

#ifdef PRESERVE_WINDOWS_ERROR_CODE
  if(old_win_err != GetLastError())
    SetLastError(old_win_err);
#endif

  return buf;
}

