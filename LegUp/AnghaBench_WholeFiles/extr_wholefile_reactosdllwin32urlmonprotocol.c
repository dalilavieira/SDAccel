#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  cache_file ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  scalar_t__ ULONG ;
struct TYPE_33__ {int /*<<< orphan*/  dwError; scalar_t__ dwResult; } ;
struct TYPE_32__ {int dwState; scalar_t__ pData; int cbSize; int dwOptions; } ;
struct TYPE_31__ {int flags; scalar_t__ current_position; scalar_t__ available_bytes; int bindf; scalar_t__ query_available; int /*<<< orphan*/ * post_stream; int /*<<< orphan*/ * connection; int /*<<< orphan*/ * request; TYPE_1__* vtbl; int /*<<< orphan*/ * protocol_sink; scalar_t__ lock; TYPE_3__ bind_info; int /*<<< orphan*/ * protocol; int /*<<< orphan*/  content_length; } ;
struct TYPE_30__ {scalar_t__ (* start_downloading ) (TYPE_2__*) ;scalar_t__ (* open_request ) (TYPE_2__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* close_connection ) (TYPE_2__*) ;int /*<<< orphan*/  (* on_error ) (TYPE_2__*,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_2__ Protocol ;
typedef  TYPE_3__ PROTOCOLDATA ;
typedef  int /*<<< orphan*/ * LPCWSTR ;
typedef  int /*<<< orphan*/  IUri ;
typedef  TYPE_4__ INTERNET_ASYNC_RESULT ;
typedef  int /*<<< orphan*/  IInternetProtocolSink ;
typedef  int /*<<< orphan*/  IInternetProtocol ;
typedef  int /*<<< orphan*/  IInternetBindInfo ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/ * HINTERNET ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int BOOL ;
typedef  int /*<<< orphan*/  BINDINFO ;

/* Variables and functions */
 int BINDF_FROMURLMON ; 
 int BINDF_NEEDFILE ; 
 int BINDF_NOWRITECACHE ; 
 int BINDINFO_OPTIONS_DISABLEAUTOREDIRECTS ; 
 scalar_t__ BINDSTATUS_CACHEFILENAMEAVAILABLE ; 
 scalar_t__ BINDSTATUS_DIRECTBIND ; 
 int /*<<< orphan*/  BINDSTATUS_DOWNLOADINGDATA ; 
 int /*<<< orphan*/  BINDSTATUS_ENDDOWNLOADCOMPONENTS ; 
 int BSCF_DATAFULLYAVAILABLE ; 
 int BSCF_FIRSTDATANOTIFICATION ; 
 int BSCF_INTERMEDIATEDATANOTIFICATION ; 
 int BSCF_LASTDATANOTIFICATION ; 
 scalar_t__ ERROR_IO_PENDING ; 
 scalar_t__ E_PENDING ; 
 scalar_t__ FAILED (scalar_t__) ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int FLAG_ALL_DATA_READ ; 
 int FLAG_ERROR ; 
 int FLAG_FIRST_CONTINUE_COMPLETE ; 
 int FLAG_FIRST_DATA_REPORTED ; 
 int FLAG_LAST_DATA_REPORTED ; 
 int FLAG_REQUEST_COMPLETE ; 
 int FLAG_RESULT_REPORTED ; 
 int FLAG_SYNC_READ ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ IInternetBindInfo_GetBindInfo (int /*<<< orphan*/ *,int*,TYPE_3__*) ; 
 int /*<<< orphan*/  IInternetProtocolSink_AddRef (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IInternetProtocolSink_ReportData (int /*<<< orphan*/ *,int,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ IInternetProtocolSink_ReportProgress (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IInternetProtocolSink_ReportResult (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IInternetProtocolSink_Switch (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ INET_E_DATA_NOT_AVAILABLE ; 
 scalar_t__ INET_E_DOWNLOAD_FAILURE ; 
 scalar_t__ INET_E_NO_SESSION ; 
 scalar_t__ INET_E_REDIRECT_FAILED ; 
 scalar_t__ INET_E_RESULT_DISPATCHED ; 
 int INTERNET_FLAG_KEEP_CONNECTION ; 
 int INTERNET_FLAG_NEED_FILE ; 
 int INTERNET_FLAG_NO_AUTO_REDIRECT ; 
 int INTERNET_FLAG_NO_CACHE_WRITE ; 
 int /*<<< orphan*/  INTERNET_OPTION_DATAFILE_NAME ; 
 int /*<<< orphan*/  INTERNET_OPTION_USER_AGENT ; 
 int /*<<< orphan*/  IStream_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ InterlockedCompareExchangePointer (void**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InterlockedDecrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InterlockedIncrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InternetCloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InternetLockRequestFile (int /*<<< orphan*/ *,scalar_t__*) ; 
 int InternetQueryDataAvailable (int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ InternetQueryOptionW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 
 int InternetReadFile (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  InternetSetOptionW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InternetUnlockRequestFile (scalar_t__) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  PtrToUlong (scalar_t__) ; 
 scalar_t__ S_FALSE ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  TRACE (char*,TYPE_2__*,...) ; 
 int /*<<< orphan*/  URLMON_refCount ; 
 scalar_t__ UlongToPtr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 int /*<<< orphan*/ * create_internet_session (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * internet_session ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 void protocol_close_connection (TYPE_2__*) ; 
 scalar_t__ protocol_continue (TYPE_2__*,TYPE_3__*) ; 
 int /*<<< orphan*/  strlenW (int /*<<< orphan*/ *) ; 
 scalar_t__ stub1 (TYPE_2__*) ; 
 scalar_t__ stub2 (TYPE_2__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*) ; 
 scalar_t__ write_post_stream (TYPE_2__*) ; 

__attribute__((used)) static inline void URLMON_LockModule(void) { InterlockedIncrement( &URLMON_refCount ); }

__attribute__((used)) static inline void URLMON_UnlockModule(void) { InterlockedDecrement( &URLMON_refCount ); }

__attribute__((used)) static inline HRESULT report_progress(Protocol *protocol, ULONG status_code, LPCWSTR status_text)
{
    return IInternetProtocolSink_ReportProgress(protocol->protocol_sink, status_code, status_text);
}

__attribute__((used)) static inline HRESULT report_result(Protocol *protocol, HRESULT hres)
{
    if (!(protocol->flags & FLAG_RESULT_REPORTED) && protocol->protocol_sink) {
        protocol->flags |= FLAG_RESULT_REPORTED;
        IInternetProtocolSink_ReportResult(protocol->protocol_sink, hres, 0, NULL);
    }

    return hres;
}

__attribute__((used)) static void report_data(Protocol *protocol)
{
    DWORD bscf;

    if((protocol->flags & FLAG_LAST_DATA_REPORTED) || !protocol->protocol_sink)
        return;

    if(protocol->flags & FLAG_FIRST_DATA_REPORTED) {
        bscf = BSCF_INTERMEDIATEDATANOTIFICATION;
    }else {
        protocol->flags |= FLAG_FIRST_DATA_REPORTED;
        bscf = BSCF_FIRSTDATANOTIFICATION;
    }

    if(protocol->flags & FLAG_ALL_DATA_READ && !(protocol->flags & FLAG_LAST_DATA_REPORTED)) {
        protocol->flags |= FLAG_LAST_DATA_REPORTED;
        bscf |= BSCF_LASTDATANOTIFICATION;
    }

    IInternetProtocolSink_ReportData(protocol->protocol_sink, bscf,
            protocol->current_position+protocol->available_bytes,
            protocol->content_length);
}

__attribute__((used)) static void all_data_read(Protocol *protocol)
{
    protocol->flags |= FLAG_ALL_DATA_READ;

    report_data(protocol);
    report_result(protocol, S_OK);
}

__attribute__((used)) static HRESULT start_downloading(Protocol *protocol)
{
    HRESULT hres;

    hres = protocol->vtbl->start_downloading(protocol);
    if(FAILED(hres)) {
        if(hres == INET_E_REDIRECT_FAILED)
            return S_OK;
        protocol_close_connection(protocol);
        report_result(protocol, hres);
        return hres;
    }

    if(protocol->bindf & BINDF_NEEDFILE) {
        WCHAR cache_file[MAX_PATH];
        DWORD buflen = sizeof(cache_file);

        if(InternetQueryOptionW(protocol->request, INTERNET_OPTION_DATAFILE_NAME, cache_file, &buflen)) {
            report_progress(protocol, BINDSTATUS_CACHEFILENAMEAVAILABLE, cache_file);
        }else {
            FIXME("Could not get cache file\n");
        }
    }

    protocol->flags |= FLAG_FIRST_CONTINUE_COMPLETE;
    return S_OK;
}

HRESULT protocol_syncbinding(Protocol *protocol)
{
    BOOL res;
    HRESULT hres;

    protocol->flags |= FLAG_SYNC_READ;

    hres = start_downloading(protocol);
    if(FAILED(hres))
        return hres;

    res = InternetQueryDataAvailable(protocol->request, &protocol->query_available, 0, 0);
    if(res)
        protocol->available_bytes = protocol->query_available;
    else
        WARN("InternetQueryDataAvailable failed: %u\n", GetLastError());

    protocol->flags |= FLAG_FIRST_DATA_REPORTED|FLAG_LAST_DATA_REPORTED;
    IInternetProtocolSink_ReportData(protocol->protocol_sink, BSCF_LASTDATANOTIFICATION|BSCF_DATAFULLYAVAILABLE,
            protocol->available_bytes, protocol->content_length);
    return S_OK;
}

__attribute__((used)) static void request_complete(Protocol *protocol, INTERNET_ASYNC_RESULT *ar)
{
    PROTOCOLDATA data;

    TRACE("(%p)->(%p)\n", protocol, ar);

    /* PROTOCOLDATA same as native */
    memset(&data, 0, sizeof(data));
    data.dwState = 0xf1000000;

    if(ar->dwResult) {
        protocol->flags |= FLAG_REQUEST_COMPLETE;

        if(!protocol->request) {
            TRACE("setting request handle %p\n", (HINTERNET)ar->dwResult);
            protocol->request = (HINTERNET)ar->dwResult;
        }

        if(protocol->flags & FLAG_FIRST_CONTINUE_COMPLETE)
            data.pData = UlongToPtr(BINDSTATUS_ENDDOWNLOADCOMPONENTS);
        else
            data.pData = UlongToPtr(BINDSTATUS_DOWNLOADINGDATA);

    }else {
        protocol->flags |= FLAG_ERROR;
        data.pData = UlongToPtr(ar->dwError);
    }

    if (protocol->bindf & BINDF_FROMURLMON)
        IInternetProtocolSink_Switch(protocol->protocol_sink, &data);
    else
        protocol_continue(protocol, &data);
}

HINTERNET get_internet_session(IInternetBindInfo *bind_info)
{
    HINTERNET new_session;

    if(internet_session)
        return internet_session;

    if(!bind_info)
        return NULL;

    new_session = create_internet_session(bind_info);
    if(new_session && InterlockedCompareExchangePointer((void**)&internet_session, new_session, NULL))
        InternetCloseHandle(new_session);

    return internet_session;
}

void update_user_agent(WCHAR *user_agent)
{
    if(internet_session)
        InternetSetOptionW(internet_session, INTERNET_OPTION_USER_AGENT, user_agent, strlenW(user_agent));
}

HRESULT protocol_start(Protocol *protocol, IInternetProtocol *prot, IUri *uri,
        IInternetProtocolSink *protocol_sink, IInternetBindInfo *bind_info)
{
    DWORD request_flags;
    HRESULT hres;

    protocol->protocol = prot;

    IInternetProtocolSink_AddRef(protocol_sink);
    protocol->protocol_sink = protocol_sink;

    memset(&protocol->bind_info, 0, sizeof(protocol->bind_info));
    protocol->bind_info.cbSize = sizeof(BINDINFO);
    hres = IInternetBindInfo_GetBindInfo(bind_info, &protocol->bindf, &protocol->bind_info);
    if(hres != S_OK) {
        WARN("GetBindInfo failed: %08x\n", hres);
        return report_result(protocol, hres);
    }

    if(!(protocol->bindf & BINDF_FROMURLMON))
        report_progress(protocol, BINDSTATUS_DIRECTBIND, NULL);

    if(!get_internet_session(bind_info))
        return report_result(protocol, INET_E_NO_SESSION);

    request_flags = INTERNET_FLAG_KEEP_CONNECTION;
    if(protocol->bindf & BINDF_NOWRITECACHE)
        request_flags |= INTERNET_FLAG_NO_CACHE_WRITE;
    if(protocol->bindf & BINDF_NEEDFILE)
        request_flags |= INTERNET_FLAG_NEED_FILE;
    if(protocol->bind_info.dwOptions & BINDINFO_OPTIONS_DISABLEAUTOREDIRECTS)
        request_flags |= INTERNET_FLAG_NO_AUTO_REDIRECT;

    hres = protocol->vtbl->open_request(protocol, uri, request_flags, internet_session, bind_info);
    if(FAILED(hres)) {
        protocol_close_connection(protocol);
        return report_result(protocol, hres);
    }

    return S_OK;
}

HRESULT protocol_continue(Protocol *protocol, PROTOCOLDATA *data)
{
    BOOL is_start;
    HRESULT hres;

    is_start = !data || data->pData == UlongToPtr(BINDSTATUS_DOWNLOADINGDATA);

    if(!protocol->request) {
        WARN("Expected request to be non-NULL\n");
        return S_OK;
    }

    if(!protocol->protocol_sink) {
        WARN("Expected IInternetProtocolSink pointer to be non-NULL\n");
        return S_OK;
    }

    if(protocol->flags & FLAG_ERROR) {
        protocol->flags &= ~FLAG_ERROR;
        protocol->vtbl->on_error(protocol, PtrToUlong(data->pData));
        return S_OK;
    }

    if(protocol->post_stream)
        return write_post_stream(protocol);

    if(is_start) {
        hres = start_downloading(protocol);
        if(FAILED(hres))
            return S_OK;
    }

    if(!data || data->pData >= UlongToPtr(BINDSTATUS_DOWNLOADINGDATA)) {
        if(!protocol->available_bytes) {
            if(protocol->query_available) {
                protocol->available_bytes = protocol->query_available;
            }else {
                BOOL res;

                /* InternetQueryDataAvailable may immediately fork and perform its asynchronous
                 * read, so clear the flag _before_ calling so it does not incorrectly get cleared
                 * after the status callback is called */
                protocol->flags &= ~FLAG_REQUEST_COMPLETE;
                res = InternetQueryDataAvailable(protocol->request, &protocol->query_available, 0, 0);
                if(res) {
                    TRACE("available %u bytes\n", protocol->query_available);
                    if(!protocol->query_available) {
                        all_data_read(protocol);
                        return S_OK;
                    }
                    protocol->available_bytes = protocol->query_available;
                }else if(GetLastError() != ERROR_IO_PENDING) {
                    protocol->flags |= FLAG_REQUEST_COMPLETE;
                    WARN("InternetQueryDataAvailable failed: %d\n", GetLastError());
                    report_result(protocol, INET_E_DATA_NOT_AVAILABLE);
                    return S_OK;
                }
            }

            protocol->flags |= FLAG_REQUEST_COMPLETE;
        }

        report_data(protocol);
    }

    return S_OK;
}

HRESULT protocol_read(Protocol *protocol, void *buf, ULONG size, ULONG *read_ret)
{
    ULONG read = 0;
    BOOL res;
    HRESULT hres = S_FALSE;

    if(protocol->flags & FLAG_ALL_DATA_READ) {
        *read_ret = 0;
        return S_FALSE;
    }

    if(!(protocol->flags & FLAG_SYNC_READ) && (!(protocol->flags & FLAG_REQUEST_COMPLETE) || !protocol->available_bytes)) {
        *read_ret = 0;
        return E_PENDING;
    }

    while(read < size && protocol->available_bytes) {
        ULONG len;

        res = InternetReadFile(protocol->request, ((BYTE *)buf)+read,
                protocol->available_bytes > size-read ? size-read : protocol->available_bytes, &len);
        if(!res) {
            WARN("InternetReadFile failed: %d\n", GetLastError());
            hres = INET_E_DOWNLOAD_FAILURE;
            report_result(protocol, hres);
            break;
        }

        if(!len) {
            all_data_read(protocol);
            break;
        }

        read += len;
        protocol->current_position += len;
        protocol->available_bytes -= len;

        TRACE("current_position %d, available_bytes %d\n", protocol->current_position, protocol->available_bytes);

        if(!protocol->available_bytes) {
            /* InternetQueryDataAvailable may immediately fork and perform its asynchronous
             * read, so clear the flag _before_ calling so it does not incorrectly get cleared
             * after the status callback is called */
            protocol->flags &= ~FLAG_REQUEST_COMPLETE;
            res = InternetQueryDataAvailable(protocol->request, &protocol->query_available, 0, 0);
            if(!res) {
                if (GetLastError() == ERROR_IO_PENDING) {
                    hres = E_PENDING;
                }else {
                    WARN("InternetQueryDataAvailable failed: %d\n", GetLastError());
                    hres = INET_E_DATA_NOT_AVAILABLE;
                    report_result(protocol, hres);
                }
                break;
            }

            if(!protocol->query_available) {
                all_data_read(protocol);
                break;
            }

            protocol->available_bytes = protocol->query_available;
        }
    }

    *read_ret = read;

    if (hres != E_PENDING)
        protocol->flags |= FLAG_REQUEST_COMPLETE;
    if(FAILED(hres))
        return hres;

    return read ? S_OK : S_FALSE;
}

HRESULT protocol_lock_request(Protocol *protocol)
{
    if (!InternetLockRequestFile(protocol->request, &protocol->lock))
        WARN("InternetLockRequest failed: %d\n", GetLastError());

    return S_OK;
}

HRESULT protocol_unlock_request(Protocol *protocol)
{
    if(!protocol->lock)
        return S_OK;

    if(!InternetUnlockRequestFile(protocol->lock))
        WARN("InternetUnlockRequest failed: %d\n", GetLastError());
    protocol->lock = 0;

    return S_OK;
}

HRESULT protocol_abort(Protocol *protocol, HRESULT reason)
{
    if(!protocol->protocol_sink)
        return S_OK;

    /* NOTE: IE10 returns S_OK here */
    if(protocol->flags & FLAG_RESULT_REPORTED)
        return INET_E_RESULT_DISPATCHED;

    report_result(protocol, reason);
    return S_OK;
}

void protocol_close_connection(Protocol *protocol)
{
    protocol->vtbl->close_connection(protocol);

    if(protocol->request)
        InternetCloseHandle(protocol->request);

    if(protocol->connection)
        InternetCloseHandle(protocol->connection);

    if(protocol->post_stream) {
        IStream_Release(protocol->post_stream);
        protocol->post_stream = NULL;
    }

    protocol->flags = 0;
}

