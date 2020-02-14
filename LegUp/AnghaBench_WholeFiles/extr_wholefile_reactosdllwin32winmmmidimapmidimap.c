#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_18__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  port ;
typedef  int /*<<< orphan*/  out ;
typedef  int /*<<< orphan*/  mh ;
typedef  int /*<<< orphan*/  mask ;
typedef  int /*<<< orphan*/  buffer ;
typedef  int WORD ;
typedef  char WCHAR ;
typedef  int UINT ;
struct TYPE_30__ {int wMid; int wPid; int vDriverVersion; int wChannelMask; long dwSupport; scalar_t__ wNotes; scalar_t__ wVoices; int /*<<< orphan*/  wTechnology; int /*<<< orphan*/  szPname; } ;
struct TYPE_29__ {int dwFlags; } ;
struct TYPE_28__ {TYPE_18__** ChannelMap; struct TYPE_28__* self; } ;
struct TYPE_27__ {char const* name; int uDevID; scalar_t__ loaded; int* aChn; int* lpbPatch; scalar_t__ hMidi; } ;
typedef  TYPE_1__ MIDIMAPDATA ;
typedef  TYPE_2__ MIDIHDR ;
typedef  TYPE_3__* LPMIDIOUTCAPSW ;
typedef  int /*<<< orphan*/  LPMIDIOPENDESC ;
typedef  TYPE_2__* LPMIDIHDR ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int DWORD_PTR ;
typedef  int DWORD ;
typedef  int BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CALLBACK_NULL ; 
 int /*<<< orphan*/  ERR (char*,...) ; 
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int HIBYTE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 TYPE_1__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  IsBadReadPtr (TYPE_1__*,int) ; 
 int LOBYTE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOWORD (int) ; 
 int MHDR_ISSTRM ; 
 int MHDR_PREPARED ; 
 int MIDIERR_INVALIDSETUP ; 
 int MMSYSERR_ERROR ; 
 int MMSYSERR_INVALPARAM ; 
 int MMSYSERR_NOERROR ; 
 int MMSYSERR_NOMEM ; 
 int /*<<< orphan*/  MOD_MAPPER ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegEnumKeyW (int /*<<< orphan*/ ,unsigned int,char*,int) ; 
 scalar_t__ RegOpenKeyA (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ RegOpenKeyW (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueExA (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int*,void*,int*) ; 
 scalar_t__ RegQueryValueExW (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int*,void*,int*) ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 scalar_t__ TRACE_ON (int /*<<< orphan*/ ) ; 
 int TRUE ; 
 scalar_t__ isdigit (char const) ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/ ,char const*) ; 
 int midiOutClose (scalar_t__) ; 
 int midiOutLongMsg (scalar_t__,TYPE_2__*,int) ; 
 int midiOutOpen (scalar_t__*,int,long,long,int /*<<< orphan*/ ) ; 
 TYPE_18__* midiOutPorts ; 
 int /*<<< orphan*/  midiOutPrepareHeader (scalar_t__,TYPE_2__*,int) ; 
 int midiOutReset (scalar_t__) ; 
 int midiOutShortMsg (scalar_t__,int) ; 
 int /*<<< orphan*/  midiOutUnprepareHeader (scalar_t__,TYPE_2__*,int) ; 
 int /*<<< orphan*/  msacm ; 
 unsigned int numMidiOutPorts ; 
 scalar_t__ strcmpW (char const*,char const*) ; 
 int /*<<< orphan*/  wine_dbgstr_w (char const*) ; 

__attribute__((used)) static	BOOL	MIDIMAP_IsBadData(MIDIMAPDATA* mm)
{
    if (!IsBadReadPtr(mm, sizeof(MIDIMAPDATA)) && mm->self == mm)
	return FALSE;
    TRACE("Bad midimap data (%p)\n", mm);
    return TRUE;
}

__attribute__((used)) static BOOL	MIDIMAP_FindPort(const WCHAR* name, unsigned* dev)
{
    for (*dev = 0; *dev < numMidiOutPorts; (*dev)++)
    {
	TRACE("%s\n", wine_dbgstr_w(midiOutPorts[*dev].name));
	if (strcmpW(midiOutPorts[*dev].name, name) == 0)
	    return TRUE;
    }
    /* try the form #nnn */
    if (*name == '#' && isdigit(name[1]))
    {
        const WCHAR*  ptr = name + 1;
        *dev = 0;
        do
        {
            *dev = *dev * 10 + *ptr - '0';
        } while (isdigit(*++ptr));
	if (*dev < numMidiOutPorts)
	    return TRUE;
    }
    return FALSE;
}

__attribute__((used)) static BOOL	MIDIMAP_LoadSettingsDefault(MIDIMAPDATA* mom, const WCHAR* port)
{
    unsigned i, dev = 0;

    if (port != NULL && !MIDIMAP_FindPort(port, &dev))
    {
	ERR("Registry glitch: couldn't find midi out (%s)\n", wine_dbgstr_w(port));
	dev = 0;
    }

    /* this is necessary when no midi out ports are present */
    if (dev >= numMidiOutPorts)
	return FALSE;
    /* sets default */
    for (i = 0; i < 16; i++) mom->ChannelMap[i] = &midiOutPorts[dev];

    return TRUE;
}

__attribute__((used)) static BOOL	MIDIMAP_LoadSettingsScheme(MIDIMAPDATA* mom, const WCHAR* scheme)
{
    HKEY	hSchemesKey, hKey, hPortKey;
    unsigned	i, idx, dev;
    WCHAR       buffer[256], port[256];
    DWORD	type, size, mask;

    for (i = 0; i < 16; i++)	mom->ChannelMap[i] = NULL;

    if (RegOpenKeyA(HKEY_LOCAL_MACHINE,
		    "System\\CurrentControlSet\\Control\\MediaProperties\\PrivateProperties\\Midi\\Schemes",
		    &hSchemesKey))
    {
	return FALSE;
    }
    if (RegOpenKeyW(hSchemesKey, scheme, &hKey))
    {
	RegCloseKey(hSchemesKey);
	return FALSE;
    }

    for (idx = 0; !RegEnumKeyW(hKey, idx, buffer, sizeof(buffer)); idx++)
    {
	if (RegOpenKeyW(hKey, buffer, &hPortKey)) continue;

	size = sizeof(port);
	if (RegQueryValueExW(hPortKey, NULL, 0, &type, (void*)port, &size)) continue;

	if (!MIDIMAP_FindPort(port, &dev)) continue;

	size = sizeof(mask);
	if (RegQueryValueExA(hPortKey, "Channels", 0, &type, (void*)&mask, &size))
	    continue;

	for (i = 0; i < 16; i++)
	{
	    if (mask & (1 << i))
	    {
		if (mom->ChannelMap[i])
		    ERR("Quirks in registry, channel %u is mapped twice\n", i);
		mom->ChannelMap[i] = &midiOutPorts[dev];
	    }
	}
    }

    RegCloseKey(hSchemesKey);
    RegCloseKey(hKey);

    return TRUE;
}

__attribute__((used)) static BOOL	MIDIMAP_LoadSettings(MIDIMAPDATA* mom)
{
    HKEY 	hKey;
    BOOL	ret;

    if (RegOpenKeyA(HKEY_CURRENT_USER,
		    "Software\\Microsoft\\Windows\\CurrentVersion\\Multimedia\\MIDIMap", &hKey))
    {
	ret = MIDIMAP_LoadSettingsDefault(mom, NULL);
    }
    else
    {
	DWORD	type, size, out;
	WCHAR   buffer[256];

	ret = 2;
	size = sizeof(out);
	if (!RegQueryValueExA(hKey, "UseScheme", 0, &type, (void*)&out, &size) && out)
	{
            static const WCHAR cs[] = {'C','u','r','r','e','n','t','S','c','h','e','m','e',0};
	    size = sizeof(buffer);
	    if (!RegQueryValueExW(hKey, cs, 0, &type, (void*)buffer, &size))
	    {
		if (!(ret = MIDIMAP_LoadSettingsScheme(mom, buffer)))
		    ret = MIDIMAP_LoadSettingsDefault(mom, NULL);
	    }
	    else
	    {
		ERR("Wrong registry: UseScheme is active, but no CurrentScheme found\n");
	    }
	}
	if (ret == 2)
	{
            static const WCHAR ci[] = {'C','u','r','r','e','n','t','I','n','s','t','r','u','m','e','n','t',0};
	    size = sizeof(buffer);
	    if (!RegQueryValueExW(hKey, ci, 0, &type, (void*)buffer, &size) && *buffer)
	    {
		ret = MIDIMAP_LoadSettingsDefault(mom, buffer);
	    }
	    else if (!RegQueryValueExW(hKey, L"szPname", 0, &type, (void*)buffer, &size) && *buffer)
	    {
		/* Windows XP and higher setting */
		ret = MIDIMAP_LoadSettingsDefault(mom, buffer);
	    }
	    else
	    {
		ret = MIDIMAP_LoadSettingsDefault(mom, NULL);
	    }
	}
    }
    RegCloseKey(hKey);

    if (ret && TRACE_ON(msacm))
    {
	unsigned	i;

	for (i = 0; i < 16; i++)
	{
	    TRACE("chnMap[%2d] => %d\n",
		  i, mom->ChannelMap[i] ? mom->ChannelMap[i]->uDevID : -1);
	}
    }
    return ret;
}

__attribute__((used)) static	DWORD	modOpen(DWORD_PTR *lpdwUser, LPMIDIOPENDESC lpDesc, DWORD dwFlags)
{
    MIDIMAPDATA*	mom = HeapAlloc(GetProcessHeap(), 0, sizeof(MIDIMAPDATA));

    TRACE("(%p %p %08lx)\n", lpdwUser, lpDesc, dwFlags);

    if (!mom) return MMSYSERR_NOMEM;

    if (MIDIMAP_LoadSettings(mom))
    {
	*lpdwUser = (DWORD_PTR)mom;
	mom->self = mom;

	return MMSYSERR_NOERROR;
    }
    HeapFree(GetProcessHeap(), 0, mom);
    return MIDIERR_INVALIDSETUP;
}

__attribute__((used)) static	DWORD	modClose(MIDIMAPDATA* mom)
{
    UINT	i;
    DWORD	ret = MMSYSERR_NOERROR;

    if (MIDIMAP_IsBadData(mom)) 	return MMSYSERR_ERROR;

    for (i = 0; i < 16; i++)
    {
	DWORD	t;
	if (mom->ChannelMap[i] && mom->ChannelMap[i]->loaded > 0)
	{
	    t = midiOutClose(mom->ChannelMap[i]->hMidi);
	    if (t == MMSYSERR_NOERROR)
	    {
		mom->ChannelMap[i]->loaded = 0;
		mom->ChannelMap[i]->hMidi = 0;
	    }
	    else if (ret == MMSYSERR_NOERROR)
		ret = t;
	}
    }
    if (ret == MMSYSERR_NOERROR)
	HeapFree(GetProcessHeap(), 0, mom);
    return ret;
}

__attribute__((used)) static	DWORD	modLongData(MIDIMAPDATA* mom, LPMIDIHDR lpMidiHdr, DWORD_PTR dwParam2)
{
    WORD	chn;
    DWORD	ret = MMSYSERR_NOERROR;
    MIDIHDR	mh;

    if (MIDIMAP_IsBadData(mom))
	return MMSYSERR_ERROR;

    mh = *lpMidiHdr;
    for (chn = 0; chn < 16; chn++)
    {
	if (mom->ChannelMap[chn] && mom->ChannelMap[chn]->loaded > 0)
	{
	    mh.dwFlags = 0;
	    midiOutPrepareHeader(mom->ChannelMap[chn]->hMidi, &mh, sizeof(mh));
	    ret = midiOutLongMsg(mom->ChannelMap[chn]->hMidi, &mh, sizeof(mh));
	    midiOutUnprepareHeader(mom->ChannelMap[chn]->hMidi, &mh, sizeof(mh));
	    if (ret != MMSYSERR_NOERROR) break;
	}
    }
    return ret;
}

__attribute__((used)) static	DWORD	modData(MIDIMAPDATA* mom, DWORD_PTR dwParam)
{
    BYTE	lb = LOBYTE(LOWORD(dwParam));
    WORD	chn = lb & 0x0F;
    DWORD	ret = MMSYSERR_NOERROR;

    if (MIDIMAP_IsBadData(mom))
	return MMSYSERR_ERROR;

    if (!mom->ChannelMap[chn]) return MMSYSERR_NOERROR;

    switch (lb & 0xF0)
    {
    case 0x80:
    case 0x90:
    case 0xA0:
    case 0xB0:
    case 0xC0:
    case 0xD0:
    case 0xE0:
	if (mom->ChannelMap[chn]->loaded == 0)
	{
	    if (midiOutOpen(&mom->ChannelMap[chn]->hMidi, mom->ChannelMap[chn]->uDevID,
			    0L, 0L, CALLBACK_NULL) == MMSYSERR_NOERROR)
		mom->ChannelMap[chn]->loaded = 1;
	    else
		mom->ChannelMap[chn]->loaded = -1;
	    /* FIXME: should load here the IDF midi data... and allow channel and
	     * patch mappings
	     */
	}
	if (mom->ChannelMap[chn]->loaded > 0)
	{
	    /* change channel */
	    dwParam &= ~0x0F;
	    dwParam |= mom->ChannelMap[chn]->aChn[chn];

	    if ((LOBYTE(LOWORD(dwParam)) & 0xF0) == 0xC0 /* program change */ &&
		mom->ChannelMap[chn]->lpbPatch)
	    {
		BYTE patch = HIBYTE(LOWORD(dwParam));

		/* change patch */
		dwParam &= ~0x0000FF00;
		dwParam |= mom->ChannelMap[chn]->lpbPatch[patch];
	    }
	    ret = midiOutShortMsg(mom->ChannelMap[chn]->hMidi, dwParam);
	}
	break;
    case 0xF0:
	for (chn = 0; chn < 16; chn++)
	{
	    if (mom->ChannelMap[chn]->loaded > 0)
		ret = midiOutShortMsg(mom->ChannelMap[chn]->hMidi, dwParam);
	}
	break;
    default:
	FIXME("ooch %lu\n", dwParam);
    }

    return ret;
}

__attribute__((used)) static	DWORD	modPrepare(MIDIMAPDATA* mom, LPMIDIHDR lpMidiHdr, DWORD_PTR dwParam2)
{
    if (MIDIMAP_IsBadData(mom)) return MMSYSERR_ERROR;
    if (lpMidiHdr->dwFlags & (MHDR_ISSTRM|MHDR_PREPARED))
	return MMSYSERR_INVALPARAM;

    lpMidiHdr->dwFlags |= MHDR_PREPARED;
    return MMSYSERR_NOERROR;
}

__attribute__((used)) static	DWORD	modUnprepare(MIDIMAPDATA* mom, LPMIDIHDR lpMidiHdr, DWORD_PTR dwParam2)
{
    if (MIDIMAP_IsBadData(mom)) return MMSYSERR_ERROR;
    if ((lpMidiHdr->dwFlags & MHDR_ISSTRM) || !(lpMidiHdr->dwFlags & MHDR_PREPARED))
	return MMSYSERR_INVALPARAM;

    lpMidiHdr->dwFlags &= ~MHDR_PREPARED;
    return MMSYSERR_NOERROR;
}

__attribute__((used)) static	DWORD	modGetDevCaps(UINT wDevID, MIDIMAPDATA* mom, LPMIDIOUTCAPSW lpMidiCaps, DWORD_PTR size)
{
    static const WCHAR name[] = {'W','i','n','e',' ','m','i','d','i',' ','m','a','p','p','e','r',0};
    lpMidiCaps->wMid = 0x00FF;
    lpMidiCaps->wPid = 0x0001;
    lpMidiCaps->vDriverVersion = 0x0100;
    lstrcpyW(lpMidiCaps->szPname, name);
    lpMidiCaps->wTechnology = MOD_MAPPER;
    lpMidiCaps->wVoices = 0;
    lpMidiCaps->wNotes = 0;
    lpMidiCaps->wChannelMask = 0xFFFF;
    lpMidiCaps->dwSupport = 0L;

    return MMSYSERR_NOERROR;
}

__attribute__((used)) static	DWORD	modReset(MIDIMAPDATA* mom)
{
    WORD	chn;
    DWORD	ret = MMSYSERR_NOERROR;

    if (MIDIMAP_IsBadData(mom))
	return MMSYSERR_ERROR;

    for (chn = 0; chn < 16; chn++)
    {
	if (mom->ChannelMap[chn] && mom->ChannelMap[chn]->loaded > 0)
	{
	    ret = midiOutReset(mom->ChannelMap[chn]->hMidi);
	    if (ret != MMSYSERR_NOERROR) break;
	}
    }
    return ret;
}

