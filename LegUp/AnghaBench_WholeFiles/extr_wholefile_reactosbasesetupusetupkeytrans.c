#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  kip ;
typedef  int USHORT ;
typedef  size_t UINT ;
typedef  int UCHAR ;
struct TYPE_17__ {scalar_t__ ScanCode; int Enhanced; int NumLock; int Normal; int Shift; scalar_t__ bCAPS; } ;
struct TYPE_16__ {int LedFlags; scalar_t__ UnitId; } ;
struct TYPE_13__ {int AsciiChar; } ;
struct TYPE_15__ {int wRepeatCount; scalar_t__ wVirtualScanCode; int dwControlKeyState; int wVirtualKeyCode; TYPE_1__ uChar; scalar_t__ bKeyDown; } ;
struct TYPE_14__ {int Flags; int MakeCode; } ;
typedef  TYPE_2__* PKEYBOARD_INPUT_DATA ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int* LPDWORD ;
typedef  TYPE_3__ KEY_EVENT_RECORD ;
typedef  TYPE_4__ KEYBOARD_INDICATOR_PARAMETERS ;
typedef  int /*<<< orphan*/  IO_STATUS_BLOCK ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int DWORD ;

/* Variables and functions */
 int CAPSLOCK_ON ; 
 int /*<<< orphan*/  DPRINT (char*,int) ; 
 int /*<<< orphan*/  DPRINT1 (char*,int /*<<< orphan*/ ) ; 
 int ENHANCED_KEY ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  IOCTL_KEYBOARD_SET_INDICATORS ; 
 int KEYBOARD_CAPS_LOCK_ON ; 
 int KEYBOARD_NUM_LOCK_ON ; 
 int KEYBOARD_SCROLL_LOCK_ON ; 
 int KEY_BREAK ; 
 int KEY_E0 ; 
 int KEY_E1 ; 
 int* KeyTable ; 
 int* KeyTableEnhanced ; 
 int* KeyTableNumlock ; 
 int LEFT_ALT_PRESSED ; 
 int LEFT_CTRL_PRESSED ; 
 int /*<<< orphan*/  NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int NUMLOCK_ON ; 
 int /*<<< orphan*/  NtDeviceIoControlFile (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_4__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int RIGHT_ALT_PRESSED ; 
 int RIGHT_CTRL_PRESSED ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_3__*,int) ; 
 int SCROLLLOCK_ON ; 
 int SHIFT_PRESSED ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 TYPE_5__* ScanToAscii ; 
 scalar_t__ TRUE ; 

__attribute__((used)) static void
IntUpdateControlKeyState(HANDLE hConsoleInput, LPDWORD State, PKEYBOARD_INPUT_DATA InputData)
{
	DWORD Value = 0;
    DWORD oldState, newState;

	if (InputData->Flags & KEY_E1) /* Only the pause key has E1 */
		return;

    oldState = newState = *State;

	if (!(InputData->Flags & KEY_E0)) {
		switch (InputData->MakeCode) {
			case 0x2a:
			case 0x36:
				Value = SHIFT_PRESSED;
				break;

			case 0x1d:
				Value = LEFT_CTRL_PRESSED;
				break;

			case 0x38:
				Value = LEFT_ALT_PRESSED;
				break;

			case 0x3A:
				if (!(InputData->Flags & KEY_BREAK))
					newState ^= CAPSLOCK_ON;
				break;

			case 0x45:
				if (!(InputData->Flags & KEY_BREAK))
					newState ^= NUMLOCK_ON;
				break;

			case 0x46:
				if (!(InputData->Flags & KEY_BREAK))
					newState ^= SCROLLLOCK_ON;
				break;

			default:
				return;
		}
	} else {
		switch (InputData->MakeCode) {
			case 0x1d:
				Value = RIGHT_CTRL_PRESSED;
				break;

			case 0x38:
				Value = RIGHT_ALT_PRESSED;
				break;

			default:
				return;
		}
	}

    /* Check if the state of the indicators has been changed */
    if ((oldState ^ newState) & (NUMLOCK_ON | CAPSLOCK_ON | SCROLLLOCK_ON))
    {
        IO_STATUS_BLOCK               IoStatusBlock;
        NTSTATUS                      Status;
        KEYBOARD_INDICATOR_PARAMETERS kip;

        kip.LedFlags = 0;
        kip.UnitId   = 0;

        if ((newState & NUMLOCK_ON))
            kip.LedFlags |= KEYBOARD_NUM_LOCK_ON;

        if ((newState & CAPSLOCK_ON))
            kip.LedFlags |= KEYBOARD_CAPS_LOCK_ON;

        if ((newState & SCROLLLOCK_ON))
            kip.LedFlags |= KEYBOARD_SCROLL_LOCK_ON;

        /* Update the state of the leds on primary keyboard */
        DPRINT("NtDeviceIoControlFile dwLeds=%x\n", kip.LedFlags);

        Status = NtDeviceIoControlFile(
              hConsoleInput,
              NULL,
              NULL,
              NULL,
              &IoStatusBlock,
              IOCTL_KEYBOARD_SET_INDICATORS,
		      &kip,
              sizeof(kip),
		      NULL,
              0);

        if (!NT_SUCCESS(Status))
        {
            DPRINT1("NtDeviceIoControlFile(IOCTL_KEYBOARD_SET_INDICATORS) failed (Status %lx)\n", Status);
        }
    } else
    /* Normal press/release state handling */
	if (InputData->Flags & KEY_BREAK)
		newState &= ~Value;
	else
		newState |= Value;

    *State = newState;
}

__attribute__((used)) static DWORD
IntVKFromKbdInput(PKEYBOARD_INPUT_DATA InputData, DWORD KeyState)
{
	if (!(KeyState & ENHANCED_KEY)) {
		if ((KeyState & NUMLOCK_ON) &&
		    KeyTableNumlock[InputData->MakeCode & 0x7f]) {
			DPRINT("Numlock, using %x\n",
			       InputData->MakeCode & 0x7f);
			return KeyTableNumlock[InputData->MakeCode & 0x7f];
		}
		DPRINT("Not enhanced, using %x\n", InputData->MakeCode & 0x7f);
		return KeyTable[InputData->MakeCode & 0x7f];
	}

	DPRINT("Enhanced, using %x\n", InputData->MakeCode & 0x7f);
	return KeyTableEnhanced[InputData->MakeCode & 0x7f];
}

__attribute__((used)) static UCHAR
IntAsciiFromInput(PKEYBOARD_INPUT_DATA InputData, DWORD KeyState)
{
	UINT Counter = 0;
	USHORT Enhanced = 0;

	if (KeyState & ENHANCED_KEY) Enhanced = 1;

	while (ScanToAscii[Counter].ScanCode != 0) {
		if ((ScanToAscii[Counter].ScanCode == InputData->MakeCode)  &&
		    (ScanToAscii[Counter].Enhanced == Enhanced)) {
			if (ScanToAscii[Counter].NumLock) {
				if ((KeyState & NUMLOCK_ON) &&
				    !(KeyState & SHIFT_PRESSED)) {
					return ScanToAscii[Counter].NumLock;
				} else {
					return ScanToAscii[Counter].Normal;
				}
			}

			if ((KeyState & CAPSLOCK_ON) && ScanToAscii[Counter].bCAPS)
				KeyState ^= SHIFT_PRESSED;

			if (KeyState & SHIFT_PRESSED)
				return ScanToAscii[Counter].Shift;

			return ScanToAscii[Counter].Normal;
		}
		Counter++;
	}

	return 0;
}

NTSTATUS
IntTranslateKey(HANDLE hConsoleInput, PKEYBOARD_INPUT_DATA InputData, KEY_EVENT_RECORD *Event)
{
	static DWORD dwControlKeyState;

	RtlZeroMemory(Event, sizeof(KEY_EVENT_RECORD));

	if (!(InputData->Flags & KEY_BREAK))
		Event->bKeyDown = TRUE;
	else
		Event->bKeyDown = FALSE;

	Event->wRepeatCount = 1;
	Event->wVirtualScanCode = InputData->MakeCode;

	DPRINT("Translating: %x\n", InputData->MakeCode);

	IntUpdateControlKeyState(hConsoleInput, &dwControlKeyState, InputData);
	Event->dwControlKeyState = dwControlKeyState;

	if (InputData->Flags & KEY_E0)
		Event->dwControlKeyState |= ENHANCED_KEY;

	Event->wVirtualKeyCode = IntVKFromKbdInput(InputData,
	                                           Event->dwControlKeyState);

	DPRINT("Result: %x\n", Event->wVirtualKeyCode);

	if (Event->bKeyDown) {
		Event->uChar.AsciiChar =
		                   IntAsciiFromInput(InputData,
		                                     Event->dwControlKeyState);
		DPRINT("Char: %x\n", Event->uChar.AsciiChar);
	} else {
		Event->uChar.AsciiChar = 0;
	}

	return STATUS_SUCCESS;
}

