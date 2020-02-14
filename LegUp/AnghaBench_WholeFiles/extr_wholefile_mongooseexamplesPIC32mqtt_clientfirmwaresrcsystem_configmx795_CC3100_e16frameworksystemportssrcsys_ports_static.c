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
typedef  int /*<<< orphan*/  SYS_PORTS_PULLUP_PULLDOWN_STATUS ;
typedef  scalar_t__ SYS_PORTS_PIN_DIRECTION ;
typedef  int /*<<< orphan*/  PORTS_REMAP_OUTPUT_PIN ;
typedef  int /*<<< orphan*/  PORTS_REMAP_OUTPUT_FUNCTION ;
typedef  int /*<<< orphan*/  PORTS_REMAP_INPUT_PIN ;
typedef  int /*<<< orphan*/  PORTS_REMAP_INPUT_FUNCTION ;
typedef  int /*<<< orphan*/  PORTS_PIN_MODE ;
typedef  int /*<<< orphan*/  PORTS_MODULE_ID ;
typedef  int /*<<< orphan*/  PORTS_DATA_TYPE ;
typedef  int PORTS_DATA_MASK ;
typedef  int /*<<< orphan*/  PORTS_CHANNEL ;
typedef  int /*<<< orphan*/  PORTS_CHANGE_NOTICE_PIN ;
typedef  int /*<<< orphan*/  PORTS_BIT_POS ;
typedef  int /*<<< orphan*/  PORTS_ANALOG_PIN ;

/* Variables and functions */
 int /*<<< orphan*/  INT_ID_0 ; 
 int /*<<< orphan*/  INT_PRIORITY_LEVEL2 ; 
 int /*<<< orphan*/  INT_SOURCE_CHANGE_NOTICE ; 
 int /*<<< orphan*/  INT_SUBPRIORITY_LEVEL0 ; 
 int /*<<< orphan*/  INT_VECTOR_CN ; 
 int /*<<< orphan*/  PLIB_INT_SourceEnable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_INT_SourceFlagClear (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_INT_VectorPrioritySet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_INT_VectorSubPrioritySet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_AnPinsModeSelect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_ChangeNoticeEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_Clear (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_CnPinsEnable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_CnPinsPullUpEnable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int PLIB_PORTS_DirectionGet (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_DirectionInputSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_DirectionOutputSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_OpenDrainEnable (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinClear (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinDirectionInputSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinDirectionOutputSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int PLIB_PORTS_PinGet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinToggle (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinWrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_Read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_Set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_Toggle (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_PORTS_Write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PORTS_ID_0 ; 
 int /*<<< orphan*/  PORTS_PIN_MODE_DIGITAL ; 
 int /*<<< orphan*/  PORT_CHANNEL_D ; 
 scalar_t__ SYS_PORTS_DIRECTION_INPUT ; 
 scalar_t__ SYS_PORTS_DIRECTION_OUTPUT ; 
 int /*<<< orphan*/  SYS_PORT_AD1PCFG ; 
 int /*<<< orphan*/  SYS_PORT_CNEN ; 
 int /*<<< orphan*/  SYS_PORT_CNPUE ; 
 int /*<<< orphan*/  SYS_PORT_D_LAT ; 
 int /*<<< orphan*/  SYS_PORT_D_ODC ; 
 int SYS_PORT_D_TRIS ; 

void SYS_PORTS_Initialize(void)
{
    /* AN and CN Pins Initialization */
    PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
    PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
    PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
    PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);

    PLIB_PORTS_Read(PORTS_ID_0, PORT_CHANNEL_D);    
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_CHANGE_NOTICE);         
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_CHANGE_NOTICE);
    PLIB_INT_VectorPrioritySet(INT_ID_0, INT_VECTOR_CN, INT_PRIORITY_LEVEL2);
    PLIB_INT_VectorSubPrioritySet(INT_ID_0, INT_VECTOR_CN, INT_SUBPRIORITY_LEVEL0);          
    
    
    /* PORT D Initialization */
    PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_D, SYS_PORT_D_ODC);
    PLIB_PORTS_Write( PORTS_ID_0, PORT_CHANNEL_D,  SYS_PORT_D_LAT);
	PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_D,  SYS_PORT_D_TRIS ^ 0xFFFF);
    
}

PORTS_DATA_TYPE SYS_PORTS_Read( PORTS_MODULE_ID index, PORTS_CHANNEL channel )
{
    return PLIB_PORTS_Read( index, channel );
}

void SYS_PORTS_Write( PORTS_MODULE_ID index,
                      PORTS_CHANNEL channel,
                      PORTS_DATA_TYPE value )
{
    PLIB_PORTS_Write( index, channel, value );
}

void SYS_PORTS_Set( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                    PORTS_DATA_TYPE value,
                    PORTS_DATA_MASK mask )
{
    PLIB_PORTS_Set( index, channel, value, mask );
}

void SYS_PORTS_Clear ( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                           PORTS_DATA_MASK clearMask )
{
    PLIB_PORTS_Clear ( index, channel, clearMask );
}

void SYS_PORTS_DirectionSelect( PORTS_MODULE_ID index,
                             SYS_PORTS_PIN_DIRECTION pinDir,
                             PORTS_CHANNEL channel,
                             PORTS_DATA_MASK mask )
{
    if (pinDir == SYS_PORTS_DIRECTION_INPUT)
    {
        PLIB_PORTS_DirectionInputSet(index, channel, mask);
    }
    else
    {
        PLIB_PORTS_DirectionOutputSet(index, channel, mask);
    }
}

PORTS_DATA_MASK SYS_PORTS_DirectionGet( PORTS_MODULE_ID index, PORTS_CHANNEL channel )
{
    return PLIB_PORTS_DirectionGet( index, channel );
}

void SYS_PORTS_Toggle( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                       PORTS_DATA_MASK toggleMask )
{
    PLIB_PORTS_Toggle( index, channel, toggleMask );
}

void SYS_PORTS_OpenDrainEnable( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                                PORTS_DATA_MASK mask )
{
#if defined(PLIB_PORTS_ExistsPortsOpenDrain)
    if(PLIB_PORTS_ExistsPortsOpenDrain(index))
    {
        PLIB_PORTS_OpenDrainEnable( index, channel, mask );
    }
#endif
}

void SYS_PORTS_OpenDrainDisable( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                                 PORTS_DATA_MASK mask )
{
#if defined(PLIB_PORTS_ExistsPortsOpenDrain)
    if(PLIB_PORTS_ExistsPortsOpenDrain(index))
    {
        PLIB_PORTS_OpenDrainDisable( index, channel, mask );
    }
#endif
}

void SYS_PORTS_ChangeNotificationGlobalEnable( PORTS_MODULE_ID index )
{
#if defined(PLIB_PORTS_ExistsChangeNotice)
    if(PLIB_PORTS_ExistsChangeNotice(index))
    {
        PLIB_PORTS_ChangeNoticeEnable( index );
    }
#endif
}

void SYS_PORTS_ChangeNotificationGlobalDisable( PORTS_MODULE_ID index )
{
#if defined(PLIB_PORTS_ExistsChangeNotice)
    if(PLIB_PORTS_ExistsChangeNotice(index))
    {
        PLIB_PORTS_ChangeNoticeDisable( index );
    }
#endif
}

void SYS_PORTS_GlobalChangeNotificationDisable( PORTS_MODULE_ID index )
{
#if defined(PLIB_PORTS_ExistsChangeNotice)
    if(PLIB_PORTS_ExistsChangeNotice(index))
    {
        PLIB_PORTS_ChangeNoticeDisable( index );
    }
#endif
}

void SYS_PORTS_ChangeNotificationEnable( PORTS_MODULE_ID index,
                                         PORTS_CHANGE_NOTICE_PIN pinNum,
                                         SYS_PORTS_PULLUP_PULLDOWN_STATUS value )
{
#if defined(PLIB_PORTS_ExistsChangeNoticePullUp)
    if(PLIB_PORTS_ExistsChangeNoticePullUp(index))
    {
        switch(value)
        {
            case SYS_PORTS_PULLUP_DISABLE:
                PLIB_PORTS_ChangeNoticePullUpDisable(index, pinNum);
                break;
            case SYS_PORTS_PULLUP_ENABLE:
                PLIB_PORTS_ChangeNoticePullUpEnable(index, pinNum);
                break;
        }
    }
#endif

#if defined(PLIB_PORTS_ExistsPinChangeNotice)
    if(PLIB_PORTS_ExistsPinChangeNotice(index))
    {
        PLIB_PORTS_PinChangeNoticeEnable( index, pinNum );
    }
#endif
}

void SYS_PORTS_ChangeNotificationDisable( PORTS_MODULE_ID index,
                                          PORTS_CHANGE_NOTICE_PIN pinNum )
{
#if defined(PLIB_PORTS_ExistsPinChangeNotice)
    if(PLIB_PORTS_ExistsPinChangeNotice(index))
    {
        PLIB_PORTS_PinChangeNoticeDisable( index, pinNum );
    }
#endif
}

void SYS_PORTS_ChangeNotificationInIdleModeEnable( PORTS_MODULE_ID index )
{
#if defined(PLIB_PORTS_ExistsChangeNoticeInIdle)
    if(PLIB_PORTS_ExistsChangeNoticeInIdle(index))
    {
        PLIB_PORTS_ChangeNoticeInIdleEnable( index );
    }
#endif
}

void SYS_PORTS_ChangeNotificationInIdleModeDisable( PORTS_MODULE_ID index )
{
#if defined(PLIB_PORTS_ExistsChangeNoticeInIdle)
    if(PLIB_PORTS_ExistsChangeNoticeInIdle(index))
    {
        PLIB_PORTS_ChangeNoticeInIdleDisable( index );
    }
#endif
}

void SYS_PORTS_ChangeNotificationPullUpEnable ( PORTS_MODULE_ID         index,
                                                PORTS_CHANGE_NOTICE_PIN pinNum )
{
#if defined(PLIB_PORTS_ExistsChangeNoticePullUp)
    if(PLIB_PORTS_ExistsChangeNoticePullUp(index))
    {
        PLIB_PORTS_ChangeNoticePullUpEnable ( index, pinNum );
    }
#endif
}

void SYS_PORTS_ChangeNotificationPullUpDisable ( PORTS_MODULE_ID         index,
                                                PORTS_CHANGE_NOTICE_PIN pinNum )
{
#if defined(PLIB_PORTS_ExistsChangeNoticePullUp)
    if(PLIB_PORTS_ExistsChangeNoticePullUp(index))
    {
        PLIB_PORTS_ChangeNoticePullUpDisable ( index, pinNum );
    }
#endif
}

void SYS_PORTS_PinModeSelect ( PORTS_MODULE_ID index, PORTS_ANALOG_PIN pin,
								PORTS_PIN_MODE mode)
{
#if defined(PLIB_PORTS_ExistsPinMode)
    if(PLIB_PORTS_ExistsPinMode(index))
    {
        PLIB_PORTS_PinModeSelect ( index, pin, mode);
    }
#endif
}

void SYS_PORTS_PinWrite ( PORTS_MODULE_ID index,
                          PORTS_CHANNEL channel,
                          PORTS_BIT_POS bitPos,
                          bool value )
{
    PLIB_PORTS_PinWrite ( index, channel, bitPos, value );
}

bool SYS_PORTS_PinRead ( PORTS_MODULE_ID index,
                         PORTS_CHANNEL channel,
                         PORTS_BIT_POS bitPos )
{
    return PLIB_PORTS_PinGet ( index, channel, bitPos );
}

void SYS_PORTS_PinToggle ( PORTS_MODULE_ID index,
                           PORTS_CHANNEL channel,
                           PORTS_BIT_POS bitPos )
{
    PLIB_PORTS_PinToggle ( index, channel, bitPos );
}

void SYS_PORTS_PinSet( PORTS_MODULE_ID index,
                       PORTS_CHANNEL channel,
                       PORTS_BIT_POS bitPos )
{
    PLIB_PORTS_PinSet( index, channel, bitPos );
}

void SYS_PORTS_PinClear ( PORTS_MODULE_ID index,
                          PORTS_CHANNEL channel,
                          PORTS_BIT_POS bitPos )
{
    PLIB_PORTS_PinClear ( index, channel, bitPos );
}

void SYS_PORTS_PinDirectionSelect ( PORTS_MODULE_ID index,
                                 SYS_PORTS_PIN_DIRECTION pinDir,
                                 PORTS_CHANNEL channel,
                                 PORTS_BIT_POS bitPos )
{
    if (pinDir == SYS_PORTS_DIRECTION_OUTPUT)
    {
        PLIB_PORTS_PinDirectionOutputSet(index, channel, bitPos);
    }
    else
    {
        PLIB_PORTS_PinDirectionInputSet(index, channel, bitPos);
    }
}

void SYS_PORTS_PinOpenDrainEnable ( PORTS_MODULE_ID index,
                                    PORTS_CHANNEL channel,
                                    PORTS_BIT_POS bitPos )
{
#if defined(PLIB_PORTS_ExistsPortsOpenDrain)
    if(PLIB_PORTS_ExistsPortsOpenDrain(index))
    {
        PLIB_PORTS_PinOpenDrainEnable ( index, channel, bitPos );
    }
#endif
}

void SYS_PORTS_PinOpenDrainDisable ( PORTS_MODULE_ID index,
                                     PORTS_CHANNEL channel,
                                     PORTS_BIT_POS bitPos )
{
#if defined(PLIB_PORTS_ExistsPortsOpenDrain)
    if(PLIB_PORTS_ExistsPortsOpenDrain(index))
    {
        PLIB_PORTS_PinOpenDrainDisable ( index, channel, bitPos );
    }
#endif
}

void SYS_PORTS_RemapInput( PORTS_MODULE_ID      index,
						   PORTS_REMAP_INPUT_FUNCTION function,
						   PORTS_REMAP_INPUT_PIN      remapPin )
{
#if defined(PLIB_PORTS_ExistsRemapInput)
    if(PLIB_PORTS_ExistsRemapInput(index))
    {
        PLIB_DEVCON_SystemUnlock(DEVCON_ID_0);
        PLIB_DEVCON_DeviceRegistersUnlock(DEVCON_ID_0, DEVCON_PPS_REGISTERS);
        PLIB_PORTS_RemapInput( index, function, remapPin);
    }
#endif
}

void SYS_PORTS_RemapOutput( PORTS_MODULE_ID      index,
						    PORTS_REMAP_OUTPUT_FUNCTION function,
						    PORTS_REMAP_OUTPUT_PIN      remapPin )
{
#if defined(PLIB_PORTS_ExistsRemapOutput)
    if(PLIB_PORTS_ExistsRemapOutput(index))
    {
        PLIB_DEVCON_SystemUnlock(DEVCON_ID_0);
        PLIB_DEVCON_DeviceRegistersUnlock(DEVCON_ID_0, DEVCON_PPS_REGISTERS);
        PLIB_PORTS_RemapOutput( index, function, remapPin);
    }
#endif
}

