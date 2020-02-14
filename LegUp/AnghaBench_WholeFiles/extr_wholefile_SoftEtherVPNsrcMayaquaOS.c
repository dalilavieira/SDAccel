#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  UINT64 ;
typedef  int UINT ;
struct TYPE_3__ {void* (* NewSingleInstance ) (char*) ;char* (* GetProductId ) () ;int (* IsSupportedOs ) () ;int (* Run ) (char*,char*,int,int) ;int (* RunW ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ;int (* ThreadId ) () ;int (* FileRenameW ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* FileSeek ) (void*,int,int) ;int (* FileDeleteW ) (int /*<<< orphan*/ *) ;int (* MakeDirW ) (int /*<<< orphan*/ *) ;int (* DeleteDirW ) (int /*<<< orphan*/ *) ;void* (* FileOpenW ) (int /*<<< orphan*/ *,int,int) ;void* (* FileCreateW ) (int /*<<< orphan*/ *) ;int (* FileWrite ) (void*,void*,int) ;int (* FileRead ) (void*,void*,int) ;int (* GetCallStackSymbolInfo ) (int /*<<< orphan*/ *) ;int (* WaitThread ) (int /*<<< orphan*/ *) ;int (* InitThread ) (int /*<<< orphan*/ *) ;void* (* MemoryAlloc ) (int) ;void* (* MemoryReAlloc ) (void*,int) ;int (* GetTick ) () ;int (* Lock ) (int /*<<< orphan*/ *) ;int (* WaitEvent ) (int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* FreeEvent ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* SetEvent ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* InitEvent ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* DeleteLock ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* Unlock ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* NewLock ) () ;int /*<<< orphan*/  (* Sleep ) (int) ;int /*<<< orphan*/  (* GetSystemTime ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* MemoryFree ) (void*) ;int /*<<< orphan*/  (* FreeThread ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* GetCallStack ) () ;int /*<<< orphan*/  (* FileFlush ) (void*) ;int /*<<< orphan*/  (* FileClose ) (void*,int) ;int /*<<< orphan*/  (* FileSize ) (void*) ;int /*<<< orphan*/  (* AlertW ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* Alert ) (char*,char*) ;int /*<<< orphan*/  (* GetOsInfo ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* RestorePriority ) () ;int /*<<< orphan*/  (* SetHighPriority ) () ;int /*<<< orphan*/  (* FreeSingleInstance ) (void*) ;int /*<<< orphan*/  (* Yield ) () ;int /*<<< orphan*/  (* GetMemInfo ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* Free ) () ;int /*<<< orphan*/  (* Init ) () ;} ;
typedef  int /*<<< orphan*/  THREAD ;
typedef  int /*<<< orphan*/  SYSTEMTIME ;
typedef  int /*<<< orphan*/  OS_INFO ;
typedef  int /*<<< orphan*/  MEMINFO ;
typedef  int /*<<< orphan*/  LOCK ;
typedef  int /*<<< orphan*/  EVENT ;
typedef  int /*<<< orphan*/  CALLSTACK_DATA ;

/* Variables and functions */
#define  OSTYPE_BSD 168 
#define  OSTYPE_CYGWIN 167 
#define  OSTYPE_LINUX 166 
#define  OSTYPE_MACOS_X 165 
#define  OSTYPE_SOLARIS 164 
#define  OSTYPE_UNIX_UNKNOWN 163 
#define  OSTYPE_WINDOWS_10 162 
#define  OSTYPE_WINDOWS_11 161 
#define  OSTYPE_WINDOWS_2000_ADVANCED_SERVER 160 
#define  OSTYPE_WINDOWS_2000_BACKOFFICE 159 
#define  OSTYPE_WINDOWS_2000_DATACENTER_SERVER 158 
#define  OSTYPE_WINDOWS_2000_PROFESSIONAL 157 
#define  OSTYPE_WINDOWS_2000_SBS 156 
#define  OSTYPE_WINDOWS_2000_SERVER 155 
#define  OSTYPE_WINDOWS_2003_BACKOFFICE 154 
#define  OSTYPE_WINDOWS_2003_DATACENTER 153 
#define  OSTYPE_WINDOWS_2003_ENTERPRISE 152 
#define  OSTYPE_WINDOWS_2003_SBS 151 
#define  OSTYPE_WINDOWS_2003_STANDARD 150 
#define  OSTYPE_WINDOWS_2003_WEB 149 
#define  OSTYPE_WINDOWS_7 148 
#define  OSTYPE_WINDOWS_8 147 
#define  OSTYPE_WINDOWS_81 146 
#define  OSTYPE_WINDOWS_95 145 
#define  OSTYPE_WINDOWS_98 144 
#define  OSTYPE_WINDOWS_LONGHORN_PROFESSIONAL 143 
#define  OSTYPE_WINDOWS_LONGHORN_SERVER 142 
#define  OSTYPE_WINDOWS_ME 141 
#define  OSTYPE_WINDOWS_NT_4_BACKOFFICE 140 
#define  OSTYPE_WINDOWS_NT_4_SERVER 139 
#define  OSTYPE_WINDOWS_NT_4_SERVER_ENTERPRISE 138 
#define  OSTYPE_WINDOWS_NT_4_SMS 137 
#define  OSTYPE_WINDOWS_NT_4_WORKSTATION 136 
#define  OSTYPE_WINDOWS_SERVER_10 135 
#define  OSTYPE_WINDOWS_SERVER_11 134 
#define  OSTYPE_WINDOWS_SERVER_2008_R2 133 
#define  OSTYPE_WINDOWS_SERVER_8 132 
#define  OSTYPE_WINDOWS_SERVER_81 131 
#define  OSTYPE_WINDOWS_UNKNOWN 130 
#define  OSTYPE_WINDOWS_XP_HOME 129 
#define  OSTYPE_WINDOWS_XP_PROFESSIONAL 128 
 TYPE_1__* UnixGetDispatchTable () ; 
 TYPE_1__* os ; 
 int /*<<< orphan*/  stub1 () ; 
 int stub10 () ; 
 int /*<<< orphan*/  stub11 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub12 (char*,char*) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub14 (char*,char*,int,int) ; 
 int stub15 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ; 
 int stub16 () ; 
 int stub17 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub18 (void*) ; 
 int stub19 (void*,int,int) ; 
 int /*<<< orphan*/  stub2 () ; 
 int stub20 (int /*<<< orphan*/ *) ; 
 int stub21 (int /*<<< orphan*/ *) ; 
 int stub22 (int /*<<< orphan*/ *) ; 
 void* stub23 (int /*<<< orphan*/ *,int,int) ; 
 void* stub24 (int /*<<< orphan*/ *) ; 
 int stub25 (void*,void*,int) ; 
 int stub26 (void*,void*,int) ; 
 int /*<<< orphan*/  stub27 (void*,int) ; 
 int /*<<< orphan*/  stub28 (void*) ; 
 int /*<<< orphan*/ * stub29 () ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ *) ; 
 int stub30 (int /*<<< orphan*/ *) ; 
 int stub31 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub32 (int /*<<< orphan*/ *) ; 
 int stub33 (int /*<<< orphan*/ *) ; 
 void* stub34 (int) ; 
 void* stub35 (void*,int) ; 
 int /*<<< orphan*/  stub36 (void*) ; 
 int stub37 () ; 
 int /*<<< orphan*/  stub38 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub39 (int) ; 
 int /*<<< orphan*/  stub4 () ; 
 int /*<<< orphan*/ * stub40 () ; 
 int stub41 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub42 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub43 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub44 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub45 (int /*<<< orphan*/ *) ; 
 int stub46 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub47 (int /*<<< orphan*/ *) ; 
 void* stub5 (char*) ; 
 int /*<<< orphan*/  stub6 (void*) ; 
 int /*<<< orphan*/  stub7 () ; 
 int /*<<< orphan*/  stub8 () ; 
 char* stub9 () ; 

char *OsTypeToStr(UINT type)
{
	switch (type)
	{
	case 0:
		return "Unsupported OS by SoftEther VPN\0\n";
	case OSTYPE_WINDOWS_95:
		return "Windows 95\0\n";
	case OSTYPE_WINDOWS_98:
		return "Windows 98\0\n";
	case OSTYPE_WINDOWS_ME:
		return "Windows Millennium Edition\0\n";
	case OSTYPE_WINDOWS_UNKNOWN:
		return "Windows 9x Unknown Version\0\n";
	case OSTYPE_WINDOWS_NT_4_WORKSTATION:
		return "Windows NT 4.0 Workstation\0\n";
	case OSTYPE_WINDOWS_NT_4_SERVER:
		return "Windows NT 4.0 Server\0\n";
	case OSTYPE_WINDOWS_NT_4_SERVER_ENTERPRISE:
		return "Windows NT 4.0 Server, Enterprise Edition\0\n";
	case OSTYPE_WINDOWS_NT_4_BACKOFFICE:
		return "BackOffice Server 4.5\0\n";
	case OSTYPE_WINDOWS_NT_4_SMS:
		return "Small Business Server 4.5\0\n";
	case OSTYPE_WINDOWS_2000_PROFESSIONAL:
		return "Windows 2000 Professional\0\n";
	case OSTYPE_WINDOWS_2000_SERVER:
		return "Windows 2000 Server\0\n";
	case OSTYPE_WINDOWS_2000_ADVANCED_SERVER:
		return "Windows 2000 Advanced Server\0\n";
	case OSTYPE_WINDOWS_2000_DATACENTER_SERVER:
		return "Windows 2000 Datacenter Server\0\n";
	case OSTYPE_WINDOWS_2000_BACKOFFICE:
		return "BackOffice Server 2000\0\n";
	case OSTYPE_WINDOWS_2000_SBS:
		return "Small Business Server 2000\0\n";
	case OSTYPE_WINDOWS_XP_HOME:
		return "Windows XP Home Edition\0\n";
	case OSTYPE_WINDOWS_XP_PROFESSIONAL:
		return "Windows XP Professional\0\n";
	case OSTYPE_WINDOWS_2003_WEB:
		return "Windows Server 2003 Web Edition\0\n";
	case OSTYPE_WINDOWS_2003_STANDARD:
		return "Windows Server 2003 Standard Edition\0\n";
	case OSTYPE_WINDOWS_2003_ENTERPRISE:
		return "Windows Server 2003 Enterprise Edition\0\n";
	case OSTYPE_WINDOWS_2003_DATACENTER:
		return "Windows Server 2003 Datacenter Edition\0\n";
	case OSTYPE_WINDOWS_2003_BACKOFFICE:
		return "BackOffice Server 2003\0\n";
	case OSTYPE_WINDOWS_2003_SBS:
		return "Small Business Server 2003\0\n";
	case OSTYPE_WINDOWS_LONGHORN_PROFESSIONAL:
		return "Windows Vista\0\n";
	case OSTYPE_WINDOWS_LONGHORN_SERVER:
		return "Windows Server 2008\0\n";
	case OSTYPE_WINDOWS_7:
		return "Windows 7\0\n";
	case OSTYPE_WINDOWS_SERVER_2008_R2:
		return "Windows Server 2008 R2\0\n";
	case OSTYPE_WINDOWS_8:
		return "Windows 8\0\n";
	case OSTYPE_WINDOWS_SERVER_8:
		return "Windows Server 2012\0\n";
	case OSTYPE_WINDOWS_81:
		return "Windows 8.1\0\n";
	case OSTYPE_WINDOWS_SERVER_81:
		return "Windows Server 2012 R2\0\n";
	case OSTYPE_WINDOWS_10:
		return "Windows 10\0\n";
	case OSTYPE_WINDOWS_SERVER_10:
		return "Windows Server 2016\0\n";
	case OSTYPE_WINDOWS_11:
		return "Newer than Windows 10\0\n";
	case OSTYPE_WINDOWS_SERVER_11:
		return "Newer than Windows Server 2016\0\n";
	case OSTYPE_UNIX_UNKNOWN:
		return "UNIX System\0\n";
	case OSTYPE_LINUX:
		return "Linux\0\n";
	case OSTYPE_SOLARIS:
		return "Sun Solaris\0\n";
	case OSTYPE_CYGWIN:
		return "Gnu Cygwin\0\n";
	case OSTYPE_BSD:
		return "BSD System\0\n";
	case OSTYPE_MACOS_X:
		return "Mac OS X\0\n";
	}

	return "Unknown OS";
}

void OSInit()
{
	// Get the dispatch table
#ifdef	OS_WIN32
	os = Win32GetDispatchTable();
#else	// OS_WIN32
	os = UnixGetDispatchTable();
#endif	// OS_WIN32

	// Calling the OS-specific initialization function
	os->Init();
}

void OSFree()
{
	os->Free();
}

void OSGetMemInfo(MEMINFO *info)
{
	// Validate arguments
	if (info == NULL)
	{
		return;
	}

	os->GetMemInfo(info);
}

void OSYield()
{
	os->Yield();
}

void *OSNewSingleInstance(char *instance_name)
{
	return os->NewSingleInstance(instance_name);
}

void OSFreeSingleInstance(void *data)
{
	os->FreeSingleInstance(data);
}

void OSSetHighPriority()
{
	os->SetHighPriority();
}

void OSRestorePriority()
{
	os->RestorePriority();
}

char* OSGetProductId()
{
	return os->GetProductId();
}

bool OSIsSupportedOs()
{
	return os->IsSupportedOs();
}

void OSGetOsInfo(OS_INFO *info)
{
	os->GetOsInfo(info);
}

void OSAlert(char *msg, char *caption)
{
	os->Alert(msg, caption);
}

void OSAlertW(wchar_t *msg, wchar_t *caption)
{
	os->AlertW(msg, caption);
}

bool OSRun(char *filename, char *arg, bool hide, bool wait)
{
	return os->Run(filename, arg, hide, wait);
}

bool OSRunW(wchar_t *filename, wchar_t *arg, bool hide, bool wait)
{
	return os->RunW(filename, arg, hide, wait);
}

UINT OSThreadId()
{
	return os->ThreadId();
}

bool OSFileRenameW(wchar_t *old_name, wchar_t *new_name)
{
	return os->FileRenameW(old_name, new_name);
}

UINT64 OSFileSize(void *pData)
{
	return os->FileSize(pData);
}

bool OSFileSeek(void *pData, UINT mode, int offset)
{
	return os->FileSeek(pData, mode, offset);
}

bool OSFileDeleteW(wchar_t *name)
{
	return os->FileDeleteW(name);
}

bool OSMakeDirW(wchar_t *name)
{
	return os->MakeDirW(name);
}

bool OSDeleteDirW(wchar_t *name)
{
	return os->DeleteDirW(name);
}

void *OSFileOpenW(wchar_t *name, bool write_mode, bool read_lock)
{
	return os->FileOpenW(name, write_mode, read_lock);
}

void *OSFileCreateW(wchar_t *name)
{
	return os->FileCreateW(name);
}

bool OSFileWrite(void *pData, void *buf, UINT size)
{
	return os->FileWrite(pData, buf, size);
}

bool OSFileRead(void *pData, void *buf, UINT size)
{
	return os->FileRead(pData, buf, size);
}

void OSFileClose(void *pData, bool no_flush)
{
	os->FileClose(pData, no_flush);
}

void OSFileFlush(void *pData)
{
	os->FileFlush(pData);
}

CALLSTACK_DATA *OSGetCallStack()
{
	return os->GetCallStack();
}

bool OSGetCallStackSymbolInfo(CALLSTACK_DATA *s)
{
	return os->GetCallStackSymbolInfo(s);
}

bool OSWaitThread(THREAD *t)
{
	return os->WaitThread(t);
}

void OSFreeThread(THREAD *t)
{
	os->FreeThread(t);
}

bool OSInitThread(THREAD *t)
{
	return os->InitThread(t);
}

void *OSMemoryAlloc(UINT size)
{
	return os->MemoryAlloc(size);
}

void *OSMemoryReAlloc(void *addr, UINT size)
{
	return os->MemoryReAlloc(addr, size);
}

void OSMemoryFree(void *addr)
{
	os->MemoryFree(addr);
}

UINT OSGetTick()
{
	return os->GetTick();
}

void OSGetSystemTime(SYSTEMTIME *system_time)
{
	os->GetSystemTime(system_time);
}

void OSSleep(UINT time)
{
	os->Sleep(time);
}

LOCK *OSNewLock()
{
	return os->NewLock();
}

bool OSLock(LOCK *lock)
{
	return os->Lock(lock);
}

void OSUnlock(LOCK *lock)
{
	os->Unlock(lock);
}

void OSDeleteLock(LOCK *lock)
{
	os->DeleteLock(lock);
}

void OSInitEvent(EVENT *event)
{
	os->InitEvent(event);
}

void OSSetEvent(EVENT *event)
{
	os->SetEvent(event);
}

bool OSWaitEvent(EVENT *event, UINT timeout)
{
	return os->WaitEvent(event, timeout);
}

void OSFreeEvent(EVENT *event)
{
	os->FreeEvent(event);
}

