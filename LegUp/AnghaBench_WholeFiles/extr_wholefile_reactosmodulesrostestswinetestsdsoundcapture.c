#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_9__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wfx ;
typedef  int /*<<< orphan*/  state ;
typedef  int /*<<< orphan*/  dsccaps ;
typedef  int /*<<< orphan*/  dscbcaps ;
struct TYPE_13__ {int dwSize; int offset; int size; int buffer_size; int /*<<< orphan*/ * event; int /*<<< orphan*/ * notify; TYPE_9__* posnotify; TYPE_2__* wfx; int /*<<< orphan*/  dscbo; } ;
typedef  TYPE_1__ capture_state_t ;
typedef  int WORD ;
struct TYPE_14__ {int nSamplesPerSec; int wBitsPerSample; int nChannels; int wFormatTag; int /*<<< orphan*/  nBlockAlign; int /*<<< orphan*/  nAvgBytesPerSec; } ;
typedef  TYPE_2__ WAVEFORMATEX ;
struct TYPE_16__ {int dwOffset; int /*<<< orphan*/  hEventNotify; } ;
struct TYPE_15__ {int dwSize; int dwBufferBytes; int /*<<< orphan*/  dwFlags; } ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  LPDIRECTSOUNDCAPTUREBUFFER ;
typedef  int /*<<< orphan*/ * LPDIRECTSOUNDCAPTURE ;
typedef  int /*<<< orphan*/ * LPCLASSFACTORY ;
typedef  int /*<<< orphan*/ * LPCGUID ;
typedef  int /*<<< orphan*/  IUnknown ;
typedef  int /*<<< orphan*/  IDirectSoundCapture ;
typedef  scalar_t__ HRESULT ;
typedef  scalar_t__ DWORD ;
typedef  TYPE_1__ DSCCAPS ;
typedef  TYPE_4__ DSCBCAPS ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CLSCTX_INPROC_SERVER ; 
 int /*<<< orphan*/  CLSID_DirectSoundCapture ; 
 int /*<<< orphan*/  CLSID_DirectSoundPrivate ; 
 scalar_t__ CoCreateInstance (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 scalar_t__ CoGetClassObject (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/  CreateEvent (int /*<<< orphan*/ *,scalar_t__,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DSCBSTART_LOOPING ; 
 scalar_t__ DSCBSTATUS_CAPTURING ; 
 scalar_t__ DSCBSTATUS_LOOPING ; 
 int /*<<< orphan*/  DSDEVID_DefaultCapture ; 
 int /*<<< orphan*/  DSDEVID_DefaultVoiceCapture ; 
 int /*<<< orphan*/  DSDEVID_DefaultVoicePlayback ; 
 scalar_t__ DSERR_ALLOCATED ; 
 scalar_t__ DSERR_ALREADYINITIALIZED ; 
 scalar_t__ DSERR_INVALIDPARAM ; 
 scalar_t__ DSERR_NODRIVER ; 
 scalar_t__ DSERR_UNINITIALIZED ; 
 scalar_t__ DS_OK ; 
 scalar_t__ E_FAIL ; 
 scalar_t__ E_INVALIDARG ; 
 scalar_t__ E_NOINTERFACE ; 
 scalar_t__ FALSE ; 
 scalar_t__ IDirectSoundCaptureBuffer_GetCaps (int /*<<< orphan*/ ,TYPE_4__*) ; 
 scalar_t__ IDirectSoundCaptureBuffer_GetCurrentPosition (int /*<<< orphan*/ ,scalar_t__*,scalar_t__*) ; 
 scalar_t__ IDirectSoundCaptureBuffer_GetFormat (int /*<<< orphan*/ ,TYPE_2__*,int,scalar_t__*) ; 
 scalar_t__ IDirectSoundCaptureBuffer_GetStatus (int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ IDirectSoundCaptureBuffer_Lock (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ IDirectSoundCaptureBuffer_QueryInterface (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 scalar_t__ IDirectSoundCaptureBuffer_Start (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ IDirectSoundCaptureBuffer_Stop (int /*<<< orphan*/ ) ; 
 scalar_t__ IDirectSoundCaptureBuffer_Unlock (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ IDirectSoundCapture_GetCaps (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ IDirectSoundCapture_Initialize (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ IDirectSoundCapture_QueryInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int IDirectSoundCapture_Release (int /*<<< orphan*/ *) ; 
 int IDirectSoundNotify_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IDirectSoundNotify_SetNotificationPositions (int /*<<< orphan*/ *,int,TYPE_9__*) ; 
 scalar_t__ IDirectSound_GetCaps (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  IID_IClassFactory ; 
 int /*<<< orphan*/  IID_IDirectSoundCapture ; 
 int /*<<< orphan*/  IID_IDirectSoundNotify ; 
 int /*<<< orphan*/  IID_IUnknown ; 
 int NOTIFICATIONS ; 
 scalar_t__ REGDB_E_CLASSNOTREG ; 
 scalar_t__ S_OK ; 
 scalar_t__ TRUE ; 
 scalar_t__ WAIT_FAILED ; 
 int WAIT_OBJECT_0 ; 
 scalar_t__ WAIT_TIMEOUT ; 
#define  WAVE_FORMAT_ADPCM 169 
#define  WAVE_FORMAT_ALAW 168 
#define  WAVE_FORMAT_ANTEX_ADPCME 167 
#define  WAVE_FORMAT_APTX 166 
#define  WAVE_FORMAT_AUDIOFILE_AF10 165 
#define  WAVE_FORMAT_AUDIOFILE_AF36 164 
#define  WAVE_FORMAT_CONTROL_RES_CR10 163 
#define  WAVE_FORMAT_CONTROL_RES_VQLPC 162 
#define  WAVE_FORMAT_CREATIVE_ADPCM 161 
#define  WAVE_FORMAT_CREATIVE_FASTSPEECH10 160 
#define  WAVE_FORMAT_CREATIVE_FASTSPEECH8 159 
#define  WAVE_FORMAT_DEVELOPMENT 158 
#define  WAVE_FORMAT_DIALOGIC_OKI_ADPCM 157 
#define  WAVE_FORMAT_DIGIADPCM 156 
#define  WAVE_FORMAT_DIGIFIX 155 
#define  WAVE_FORMAT_DIGIREAL 154 
#define  WAVE_FORMAT_DIGISTD 153 
#define  WAVE_FORMAT_DOLBY_AC2 152 
#define  WAVE_FORMAT_DSPGROUP_TRUESPEECH 151 
#define  WAVE_FORMAT_ECHOSC1 150 
#define  WAVE_FORMAT_EXTENSIBLE 149 
#define  WAVE_FORMAT_FM_TOWNS_SND 148 
#define  WAVE_FORMAT_G721_ADPCM 147 
#define  WAVE_FORMAT_G723_ADPCM 146 
#define  WAVE_FORMAT_GSM610 145 
#define  WAVE_FORMAT_IBM_CVSD 144 
#define  WAVE_FORMAT_IMA_ADPCM 143 
#define  WAVE_FORMAT_MEDIASPACE_ADPCM 142 
#define  WAVE_FORMAT_MPEG 141 
#define  WAVE_FORMAT_MPEGLAYER3 140 
#define  WAVE_FORMAT_MULAW 139 
#define  WAVE_FORMAT_NMS_VBXADPCM 138 
#define  WAVE_FORMAT_OKI_ADPCM 137 
#define  WAVE_FORMAT_OLIADPCM 136 
#define  WAVE_FORMAT_OLICELP 135 
#define  WAVE_FORMAT_OLIGSM 134 
#define  WAVE_FORMAT_OLIOPR 133 
#define  WAVE_FORMAT_OLISBC 132 
#define  WAVE_FORMAT_PCM 131 
#define  WAVE_FORMAT_SIERRA_ADPCM 130 
#define  WAVE_FORMAT_SONARC 129 
#define  WAVE_FORMAT_YAMAHA_ADPCM 128 
 scalar_t__ WaitForMultipleObjects (int,int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 scalar_t__ broken (int) ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__,...) ; 
 scalar_t__ pDirectSoundCaptureCreate (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,...) ; 
 int /*<<< orphan*/  trace (char*,...) ; 
 int winetest_debug ; 

__attribute__((used)) static const char * get_format_str(WORD format)
{
    static char msg[32];
#define WAVE_FORMAT(f) case f: return #f
    switch (format) {
    WAVE_FORMAT(WAVE_FORMAT_PCM);
    WAVE_FORMAT(WAVE_FORMAT_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_IBM_CVSD);
    WAVE_FORMAT(WAVE_FORMAT_ALAW);
    WAVE_FORMAT(WAVE_FORMAT_MULAW);
    WAVE_FORMAT(WAVE_FORMAT_OKI_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_IMA_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_MEDIASPACE_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_SIERRA_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_G723_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_DIGISTD);
    WAVE_FORMAT(WAVE_FORMAT_DIGIFIX);
    WAVE_FORMAT(WAVE_FORMAT_DIALOGIC_OKI_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_YAMAHA_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_SONARC);
    WAVE_FORMAT(WAVE_FORMAT_DSPGROUP_TRUESPEECH);
    WAVE_FORMAT(WAVE_FORMAT_ECHOSC1);
    WAVE_FORMAT(WAVE_FORMAT_AUDIOFILE_AF36);
    WAVE_FORMAT(WAVE_FORMAT_APTX);
    WAVE_FORMAT(WAVE_FORMAT_AUDIOFILE_AF10);
    WAVE_FORMAT(WAVE_FORMAT_DOLBY_AC2);
    WAVE_FORMAT(WAVE_FORMAT_GSM610);
    WAVE_FORMAT(WAVE_FORMAT_ANTEX_ADPCME);
    WAVE_FORMAT(WAVE_FORMAT_CONTROL_RES_VQLPC);
    WAVE_FORMAT(WAVE_FORMAT_DIGIREAL);
    WAVE_FORMAT(WAVE_FORMAT_DIGIADPCM);
    WAVE_FORMAT(WAVE_FORMAT_CONTROL_RES_CR10);
    WAVE_FORMAT(WAVE_FORMAT_NMS_VBXADPCM);
    WAVE_FORMAT(WAVE_FORMAT_G721_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_MPEG);
    WAVE_FORMAT(WAVE_FORMAT_MPEGLAYER3);
    WAVE_FORMAT(WAVE_FORMAT_CREATIVE_ADPCM);
    WAVE_FORMAT(WAVE_FORMAT_CREATIVE_FASTSPEECH8);
    WAVE_FORMAT(WAVE_FORMAT_CREATIVE_FASTSPEECH10);
    WAVE_FORMAT(WAVE_FORMAT_FM_TOWNS_SND);
    WAVE_FORMAT(WAVE_FORMAT_OLIGSM);
    WAVE_FORMAT(WAVE_FORMAT_OLIADPCM);
    WAVE_FORMAT(WAVE_FORMAT_OLICELP);
    WAVE_FORMAT(WAVE_FORMAT_OLISBC);
    WAVE_FORMAT(WAVE_FORMAT_OLIOPR);
    WAVE_FORMAT(WAVE_FORMAT_DEVELOPMENT);
    WAVE_FORMAT(WAVE_FORMAT_EXTENSIBLE);
    }
#undef WAVE_FORMAT
    sprintf(msg, "Unknown(0x%04x)", format);
    return msg;
}

const char * format_string(const WAVEFORMATEX* wfx)
{
    static char str[64];

    sprintf(str, "%5dx%2dx%d %s",
	wfx->nSamplesPerSec, wfx->wBitsPerSample, wfx->nChannels,
        get_format_str(wfx->wFormatTag));

    return str;
}

__attribute__((used)) static void IDirectSoundCapture_test(LPDIRECTSOUNDCAPTURE dsco,
                                     BOOL initialized, LPCGUID lpGuid)
{
    HRESULT rc;
    DSCCAPS dsccaps;
    int ref;
    IUnknown * unknown;
    IDirectSoundCapture * dsc;

    /* Try to Query for objects */
    rc=IDirectSoundCapture_QueryInterface(dsco, &IID_IUnknown,
                                          (LPVOID*)&unknown);
    ok(rc==DS_OK, "IDirectSoundCapture_QueryInterface(IID_IUnknown) "
       "failed: %08x\n", rc);
    if (rc==DS_OK)
        IDirectSoundCapture_Release(unknown);

    rc=IDirectSoundCapture_QueryInterface(dsco, &IID_IDirectSoundCapture,
                                          (LPVOID*)&dsc);
    ok(rc==DS_OK, "IDirectSoundCapture_QueryInterface(IID_IDirectSoundCapture) "
       "failed: %08x\n", rc);
    if (rc==DS_OK)
        IDirectSoundCapture_Release(dsc);

    if (initialized == FALSE) {
        /* try uninitialized object */
        rc=IDirectSoundCapture_GetCaps(dsco,0);
        ok(rc==DSERR_UNINITIALIZED||rc==E_INVALIDARG,
           "IDirectSoundCapture_GetCaps(NULL) should have returned "
           "DSERR_UNINITIALIZED or E_INVALIDARG, returned: %08x\n", rc);

        rc=IDirectSoundCapture_GetCaps(dsco, &dsccaps);
        ok(rc==DSERR_UNINITIALIZED,"IDirectSoundCapture_GetCaps() "
           "should have returned DSERR_UNINITIALIZED, returned: %08x\n", rc);

        rc=IDirectSoundCapture_Initialize(dsco, lpGuid);
        ok(rc==DS_OK||rc==DSERR_NODRIVER||rc==DSERR_ALLOCATED||
           rc==E_FAIL||rc==E_INVALIDARG,
           "IDirectSoundCapture_Initialize() failed: %08x\n", rc);
        if (rc==DSERR_NODRIVER||rc==E_INVALIDARG) {
            trace("  No Driver\n");
            goto EXIT;
        } else if (rc==E_FAIL) {
            trace("  No Device\n");
            goto EXIT;
        } else if (rc==DSERR_ALLOCATED) {
            trace("  Already In Use\n");
            goto EXIT;
        }
    }

    rc=IDirectSoundCapture_Initialize(dsco, lpGuid);
    ok(rc==DSERR_ALREADYINITIALIZED, "IDirectSoundCapture_Initialize() "
       "should have returned DSERR_ALREADYINITIALIZED: %08x\n", rc);

    /* DSOUND: Error: Invalid caps buffer */
    rc=IDirectSoundCapture_GetCaps(dsco, 0);
    ok(rc==DSERR_INVALIDPARAM, "IDirectSoundCapture_GetCaps(NULL) "
       "should have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    ZeroMemory(&dsccaps, sizeof(dsccaps));

    /* DSOUND: Error: Invalid caps buffer */
    rc=IDirectSound_GetCaps(dsco, &dsccaps);
    ok(rc==DSERR_INVALIDPARAM, "IDirectSound_GetCaps() "
       "should have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    dsccaps.dwSize=sizeof(dsccaps);

    /* DSOUND: Running on a certified driver */
    rc=IDirectSoundCapture_GetCaps(dsco, &dsccaps);
    ok(rc==DS_OK, "IDirectSoundCapture_GetCaps() failed: %08x\n", rc);

EXIT:
    ref=IDirectSoundCapture_Release(dsco);
    ok(ref==0, "IDirectSoundCapture_Release() has %d references, "
       "should have 0\n", ref);
}

__attribute__((used)) static void test_capture(void)
{
    HRESULT rc;
    LPDIRECTSOUNDCAPTURE dsco=NULL;
    LPCLASSFACTORY cf=NULL;

    trace("Testing IDirectSoundCapture\n");

    rc=CoGetClassObject(&CLSID_DirectSoundCapture, CLSCTX_INPROC_SERVER, NULL,
                        &IID_IClassFactory, (void**)&cf);
    ok(rc==S_OK,"CoGetClassObject(CLSID_DirectSoundCapture, IID_IClassFactory) "
       "failed: %08x\n", rc);

    rc=CoGetClassObject(&CLSID_DirectSoundCapture, CLSCTX_INPROC_SERVER, NULL,
                        &IID_IUnknown, (void**)&cf);
    ok(rc==S_OK,"CoGetClassObject(CLSID_DirectSoundCapture, IID_IUnknown) "
       "failed: %08x\n", rc);

    /* try the COM class factory method of creation with no device specified */
    rc=CoCreateInstance(&CLSID_DirectSoundCapture, NULL, CLSCTX_INPROC_SERVER,
                        &IID_IDirectSoundCapture, (void**)&dsco);
    ok(rc==S_OK||rc==REGDB_E_CLASSNOTREG,"CoCreateInstance(CLSID_DirectSoundCapture) failed: %08x\n", rc);
    if (rc==REGDB_E_CLASSNOTREG) {
        trace("  Class Not Registered\n");
        return;
    }
    if (dsco)
        IDirectSoundCapture_test(dsco, FALSE, NULL);

    /* try the COM class factory method of creation with default capture
     * device specified */
    rc=CoCreateInstance(&CLSID_DirectSoundCapture, NULL, CLSCTX_INPROC_SERVER,
                        &IID_IDirectSoundCapture, (void**)&dsco);
    ok(rc==S_OK,"CoCreateInstance(CLSID_DirectSoundCapture) failed: %08x\n", rc);
    if (dsco)
        IDirectSoundCapture_test(dsco, FALSE, &DSDEVID_DefaultCapture);

    /* try the COM class factory method of creation with default voice
     * capture device specified */
    rc=CoCreateInstance(&CLSID_DirectSoundCapture, NULL, CLSCTX_INPROC_SERVER,
                        &IID_IDirectSoundCapture, (void**)&dsco);
    ok(rc==S_OK,"CoCreateInstance(CLSID_DirectSoundCapture) failed: %08x\n", rc);
    if (dsco)
        IDirectSoundCapture_test(dsco, FALSE, &DSDEVID_DefaultVoiceCapture);

    /* try the COM class factory method of creation with a bad
     * IID specified */
    rc=CoCreateInstance(&CLSID_DirectSoundCapture, NULL, CLSCTX_INPROC_SERVER,
                        &CLSID_DirectSoundPrivate, (void**)&dsco);
    ok(rc==E_NOINTERFACE,
       "CoCreateInstance(CLSID_DirectSoundCapture,CLSID_DirectSoundPrivate) "
       "should have failed: %08x\n",rc);

    /* try with no device specified */
    rc=pDirectSoundCaptureCreate(NULL,&dsco,NULL);
    ok(rc==DS_OK||rc==DSERR_NODRIVER||rc==DSERR_ALLOCATED||rc==E_FAIL,
       "DirectSoundCaptureCreate(NULL) failed: %08x\n",rc);
    if (rc==S_OK && dsco)
        IDirectSoundCapture_test(dsco, TRUE, NULL);

    /* try with default capture device specified */
    rc=pDirectSoundCaptureCreate(&DSDEVID_DefaultCapture,&dsco,NULL);
    ok(rc==DS_OK||rc==DSERR_NODRIVER||rc==DSERR_ALLOCATED||rc==E_FAIL,
       "DirectSoundCaptureCreate(DSDEVID_DefaultCapture) failed: %08x\n", rc);
    if (rc==DS_OK && dsco)
        IDirectSoundCapture_test(dsco, TRUE, NULL);

    /* try with default voice capture device specified */
    rc=pDirectSoundCaptureCreate(&DSDEVID_DefaultVoiceCapture,&dsco,NULL);
    ok(rc==DS_OK||rc==DSERR_NODRIVER||rc==DSERR_ALLOCATED||rc==E_FAIL,
       "DirectSoundCaptureCreate(DSDEVID_DefaultVoiceCapture) failed: %08x\n", rc);
    if (rc==DS_OK && dsco)
        IDirectSoundCapture_test(dsco, TRUE, NULL);

    /* try with a bad device specified */
    rc=pDirectSoundCaptureCreate(&DSDEVID_DefaultVoicePlayback,&dsco,NULL);
    ok(rc==DSERR_NODRIVER,
       "DirectSoundCaptureCreate(DSDEVID_DefaultVoicePlatback) "
       "should have failed: %08x\n",rc);
    if (rc==DS_OK && dsco)
        IDirectSoundCapture_Release(dsco);
}

__attribute__((used)) static int capture_buffer_service(capture_state_t* state)
{
    HRESULT rc;
    LPVOID ptr1,ptr2;
    DWORD len1,len2;
    DWORD capture_pos,read_pos;

    rc=IDirectSoundCaptureBuffer_GetCurrentPosition(state->dscbo,&capture_pos,
                                                    &read_pos);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_GetCurrentPosition() failed: %08x\n", rc);
    if (rc!=DS_OK)
	return 0;

    rc=IDirectSoundCaptureBuffer_Lock(state->dscbo,state->offset,state->size,
                                      &ptr1,&len1,&ptr2,&len2,0);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Lock() failed: %08x\n", rc);
    if (rc!=DS_OK)
	return 0;

    rc=IDirectSoundCaptureBuffer_Unlock(state->dscbo,ptr1,len1,ptr2,len2);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Unlock() failed: %08x\n", rc);
    if (rc!=DS_OK)
	return 0;

    state->offset = (state->offset + state->size) % state->buffer_size;

    return 1;
}

__attribute__((used)) static void test_capture_buffer(LPDIRECTSOUNDCAPTURE dsco,
				LPDIRECTSOUNDCAPTUREBUFFER dscbo, int record)
{
    HRESULT rc;
    DSCBCAPS dscbcaps;
    WAVEFORMATEX wfx;
    DWORD size,status;
    capture_state_t state;
    int i, ref;

    /* Private dsound.dll: Error: Invalid caps pointer */
    rc=IDirectSoundCaptureBuffer_GetCaps(dscbo,0);
    ok(rc==DSERR_INVALIDPARAM,"IDirectSoundCaptureBuffer_GetCaps() should "
       "have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    /* Private dsound.dll: Error: Invalid caps pointer */
    dscbcaps.dwSize=0;
    rc=IDirectSoundCaptureBuffer_GetCaps(dscbo,&dscbcaps);
    ok(rc==DSERR_INVALIDPARAM,"IDirectSoundCaptureBuffer_GetCaps() should "
       "have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    dscbcaps.dwSize=sizeof(dscbcaps);
    rc=IDirectSoundCaptureBuffer_GetCaps(dscbo,&dscbcaps);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_GetCaps() failed: %08x\n", rc);
    if (rc==DS_OK && winetest_debug > 1) {
	trace("    Caps: size = %d flags=0x%08x buffer size=%d\n",
	    dscbcaps.dwSize,dscbcaps.dwFlags,dscbcaps.dwBufferBytes);
    }

    /* Query the format size. Note that it may not match sizeof(wfx) */
    /* Private dsound.dll: Error: Either pwfxFormat or pdwSizeWritten must
     * be non-NULL */
    rc=IDirectSoundCaptureBuffer_GetFormat(dscbo,NULL,0,NULL);
    ok(rc==DSERR_INVALIDPARAM,"IDirectSoundCaptureBuffer_GetFormat() should "
       "have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    size=0;
    rc=IDirectSoundCaptureBuffer_GetFormat(dscbo,NULL,0,&size);
    ok(rc==DS_OK && size!=0,"IDirectSoundCaptureBuffer_GetFormat() should "
       "have returned the needed size: rc=%08x, size=%d\n", rc,size);

    rc=IDirectSoundCaptureBuffer_GetFormat(dscbo,&wfx,sizeof(wfx),NULL);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_GetFormat() failed: %08x\n", rc);
    if (rc==DS_OK && winetest_debug > 1) {
	trace("    Format: tag=0x%04x %dx%dx%d avg.B/s=%d align=%d\n",
	      wfx.wFormatTag,wfx.nSamplesPerSec,wfx.wBitsPerSample,
	      wfx.nChannels,wfx.nAvgBytesPerSec,wfx.nBlockAlign);
    }

    /* Private dsound.dll: Error: Invalid status pointer */
    rc=IDirectSoundCaptureBuffer_GetStatus(dscbo,0);
    ok(rc==DSERR_INVALIDPARAM,"IDirectSoundCaptureBuffer_GetStatus() should "
       "have returned DSERR_INVALIDPARAM, returned: %08x\n", rc);

    rc=IDirectSoundCaptureBuffer_GetStatus(dscbo,&status);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_GetStatus() failed: %08x\n", rc);
    if (rc==DS_OK && winetest_debug > 1) {
	trace("    Status=0x%04x\n",status);
    }

    ZeroMemory(&state, sizeof(state));
    state.dscbo=dscbo;
    state.wfx=&wfx;
    state.buffer_size = dscbcaps.dwBufferBytes;
    for (i = 0; i < NOTIFICATIONS; i++)
	state.event[i] = CreateEvent( NULL, FALSE, FALSE, NULL );
    state.size = dscbcaps.dwBufferBytes / NOTIFICATIONS;

    rc=IDirectSoundCaptureBuffer_QueryInterface(dscbo,&IID_IDirectSoundNotify,
                                                (void **)&(state.notify));
    ok((rc==DS_OK)&&(state.notify!=NULL),
       "IDirectSoundCaptureBuffer_QueryInterface() failed: %08x\n", rc);

    for (i = 0; i < NOTIFICATIONS; i++) {
	state.posnotify[i].dwOffset = (i * state.size) + state.size - 1;
	state.posnotify[i].hEventNotify = state.event[i];
    }

    rc=IDirectSoundNotify_SetNotificationPositions(state.notify,NOTIFICATIONS,
                                                   state.posnotify);
    ok(rc==DS_OK,"IDirectSoundNotify_SetNotificationPositions() failed: %08x\n", rc);

    ref=IDirectSoundNotify_Release(state.notify);
    ok(ref==0,"IDirectSoundNotify_Release(): has %d references, should have "
       "0\n",ref);

    rc=IDirectSoundCaptureBuffer_Start(dscbo,DSCBSTART_LOOPING);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Start() failed: %08x\n", rc);

    rc=IDirectSoundCaptureBuffer_Start(dscbo,0);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Start() failed: %08x\n", rc);

    rc=IDirectSoundCaptureBuffer_GetStatus(dscbo,&status);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_GetStatus() failed: %08x\n", rc);
    ok(status==(DSCBSTATUS_CAPTURING|DSCBSTATUS_LOOPING) || broken(status==DSCBSTATUS_CAPTURING),
       "GetStatus: bad status: %x\n",status);

    if (record) {
	/* wait for the notifications */
	for (i = 0; i < (NOTIFICATIONS * 2); i++) {
	    rc=WaitForMultipleObjects(NOTIFICATIONS,state.event,FALSE,3000);
	    ok(rc==(WAIT_OBJECT_0+(i%NOTIFICATIONS)),
               "WaitForMultipleObjects failed: 0x%x\n",rc);
	    if (rc!=(WAIT_OBJECT_0+(i%NOTIFICATIONS))) {
		ok((rc==WAIT_TIMEOUT)||(rc==WAIT_FAILED),
                   "Wrong notification: should be %d, got %d\n",
		    i%NOTIFICATIONS,rc-WAIT_OBJECT_0);
	    }
	    if (!capture_buffer_service(&state))
		break;
	}

    }
    rc=IDirectSoundCaptureBuffer_Stop(dscbo);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Stop() failed: %08x\n", rc);

    rc=IDirectSoundCaptureBuffer_Stop(dscbo);
    ok(rc==DS_OK,"IDirectSoundCaptureBuffer_Stop() failed: %08x\n", rc);
}

