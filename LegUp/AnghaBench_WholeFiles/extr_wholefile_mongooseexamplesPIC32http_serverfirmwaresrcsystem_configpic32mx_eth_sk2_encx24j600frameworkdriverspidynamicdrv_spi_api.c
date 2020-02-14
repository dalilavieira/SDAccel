#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct DRV_SPI_DRIVER_OBJECT {int /*<<< orphan*/  baudRate; int /*<<< orphan*/  currentBaudRate; int /*<<< orphan*/  vfMainTask; } ;
typedef  int int32_t ;
struct TYPE_4__ {scalar_t__ spiMode; int taskMode; scalar_t__ bufferType; scalar_t__ commWidth; int clockMode; int spiProtocolType; int /*<<< orphan*/  baudRate; int /*<<< orphan*/  spiClk; scalar_t__ spiSlaveSSPin; int /*<<< orphan*/  inputSamplePhase; scalar_t__ allowIdleRun; int /*<<< orphan*/  spiId; } ;
typedef  int /*<<< orphan*/  SPI_MODULE_ID ;
typedef  TYPE_1__ DRV_SPI_INIT ;

/* Variables and functions */
 scalar_t__ DRV_SPI_BUFFER_TYPE_ENHANCED ; 
#define  DRV_SPI_CLOCK_MODE_IDLE_HIGH_EDGE_FALL 135 
#define  DRV_SPI_CLOCK_MODE_IDLE_HIGH_EDGE_RISE 134 
#define  DRV_SPI_CLOCK_MODE_IDLE_LOW_EDGE_FALL 133 
#define  DRV_SPI_CLOCK_MODE_IDLE_LOW_EDGE_RISE 132 
 int /*<<< orphan*/  DRV_SPI_ISRMasterEBM8BitTasks ; 
 scalar_t__ DRV_SPI_MODE_MASTER ; 
 scalar_t__ DRV_SPI_MODE_SLAVE ; 
#define  DRV_SPI_PROTOCOL_TYPE_AUDIO 131 
#define  DRV_SPI_PROTOCOL_TYPE_FRAMED 130 
#define  DRV_SPI_PROTOCOL_TYPE_STANDARD 129 
 int DRV_SPI_TASK_MODE_ISR ; 
 int /*<<< orphan*/  PLIB_SPI_BaudRateSet (int /*<<< orphan*/  const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_BufferClear (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_ClockPolaritySelect (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_CommunicationWidthSelect (int /*<<< orphan*/  const,scalar_t__) ; 
 int /*<<< orphan*/  PLIB_SPI_Disable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_FIFOEnable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_FIFOInterruptModeSelect (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_FramedCommunicationDisable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_FramedCommunicationEnable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_InputSamplePhaseSelect (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_MasterEnable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_OutputDataPhaseSelect (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_PinDisable (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_PinEnable (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_SPI_ReceiverOverflowClear (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_StopInIdleDisable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PLIB_SPI_StopInIdleEnable (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  SPI_CLOCK_POLARITY_IDLE_HIGH ; 
 int /*<<< orphan*/  SPI_CLOCK_POLARITY_IDLE_LOW ; 
 scalar_t__ SPI_COMMUNICATION_WIDTH_8BITS ; 
 int /*<<< orphan*/  SPI_FIFO_INTERRUPT_WHEN_RECEIVE_BUFFER_IS_NOT_EMPTY ; 
 int /*<<< orphan*/  SPI_FIFO_INTERRUPT_WHEN_TRANSMIT_BUFFER_IS_COMPLETELY_EMPTY ; 
 int /*<<< orphan*/  SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK ; 
 int /*<<< orphan*/  SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK ; 
 int /*<<< orphan*/  SPI_PIN_SLAVE_SELECT ; 
 int /*<<< orphan*/  SYS_ASSERT (int,char*) ; 
 int /*<<< orphan*/  SYS_CLK_PeripheralFrequencyGet (int /*<<< orphan*/ ) ; 
 int _SPI_DRV_VTABLE_8BIT ; 
 int _SPI_DRV_VTABLE_EBM ; 
#define  _SPI_DRV_VTABLE_I_M_E_8 128 
 int _SPI_DRV_VTABLE_MASTER ; 

int32_t DRV_SPI_SetVTable(struct DRV_SPI_DRIVER_OBJECT * driverObject, const DRV_SPI_INIT * const pInit)
{
    uint8_t mode = 0;
    if (pInit->spiMode == DRV_SPI_MODE_MASTER)
    {
        mode = _SPI_DRV_VTABLE_MASTER;
    }
    else
    {
        SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
        return -1;
    }

    if (pInit->taskMode == DRV_SPI_TASK_MODE_ISR)
    {
        mode |= DRV_SPI_TASK_MODE_ISR;
    }
    else
    {
        SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
        return -1;
    }

    if (pInit->bufferType == DRV_SPI_BUFFER_TYPE_ENHANCED)
    {
        mode |= _SPI_DRV_VTABLE_EBM;
    }
    else
    {
        SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
        return -1;
    }

    if (pInit->commWidth == SPI_COMMUNICATION_WIDTH_8BITS)
    {
        mode |= _SPI_DRV_VTABLE_8BIT;
    }
    else
    {
        SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
        return -1;
    }
    switch (mode)
    {
    case _SPI_DRV_VTABLE_I_M_E_8:
        driverObject->vfMainTask = DRV_SPI_ISRMasterEBM8BitTasks;
        break;
    default:
        SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
        return -1;
    }
    return 0;
}

int32_t DRV_SPI_SetupHardware(struct DRV_SPI_DRIVER_OBJECT * driverObject, const DRV_SPI_INIT * const init)
{
    const register SPI_MODULE_ID spiId = init->spiId;

/* disable the SPI*/
    PLIB_SPI_Disable(spiId);

    /* Set up Master or Slave Mode*/
    PLIB_SPI_MasterEnable ( spiId  );

    /* Set up if the SPI is allowed to run while the rest of the CPU is in idle mode*/
    if (init->allowIdleRun)
    {
        PLIB_SPI_StopInIdleDisable( spiId  );
    }
    else
    {
        PLIB_SPI_StopInIdleEnable( spiId  );
    }

    /* Set up close Polarity and output data phase*/
    switch(init->clockMode)
    {
        case DRV_SPI_CLOCK_MODE_IDLE_LOW_EDGE_RISE:
            PLIB_SPI_ClockPolaritySelect( spiId, SPI_CLOCK_POLARITY_IDLE_LOW );
            PLIB_SPI_OutputDataPhaseSelect( spiId, SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK );
            break;
        case DRV_SPI_CLOCK_MODE_IDLE_LOW_EDGE_FALL:
            PLIB_SPI_ClockPolaritySelect( spiId, SPI_CLOCK_POLARITY_IDLE_LOW );
            PLIB_SPI_OutputDataPhaseSelect( spiId, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK );
            break;
        case DRV_SPI_CLOCK_MODE_IDLE_HIGH_EDGE_FALL: //TODO: Make sure these are right
            PLIB_SPI_ClockPolaritySelect( spiId, SPI_CLOCK_POLARITY_IDLE_HIGH );
            PLIB_SPI_OutputDataPhaseSelect( spiId, SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK );
            break;
        case DRV_SPI_CLOCK_MODE_IDLE_HIGH_EDGE_RISE:
            PLIB_SPI_ClockPolaritySelect( spiId, SPI_CLOCK_POLARITY_IDLE_HIGH );
            PLIB_SPI_OutputDataPhaseSelect( spiId, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK );
            break;
        default:
             SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
            return -1;
    }

    // Set up the  Input Sample Phase
    PLIB_SPI_InputSamplePhaseSelect ( spiId, init->inputSamplePhase);

    //Enable the SSx Pin on slave side if needed
    if(init->spiMode == DRV_SPI_MODE_SLAVE && (init->spiProtocolType == DRV_SPI_PROTOCOL_TYPE_FRAMED || init->spiSlaveSSPin))
    {
        PLIB_SPI_PinEnable(spiId, SPI_PIN_SLAVE_SELECT);
    }
    else
    {
        PLIB_SPI_PinDisable(spiId, SPI_PIN_SLAVE_SELECT);
    }

    /* Communication Width Selection */
    PLIB_SPI_CommunicationWidthSelect ( spiId, init->commWidth );

    /* Baudrate selection */
    PLIB_SPI_BaudRateSet( spiId , SYS_CLK_PeripheralFrequencyGet(init->spiClk), init->baudRate );
    driverObject->currentBaudRate = init->baudRate;
    driverObject->baudRate = init->baudRate;

    switch (init->spiProtocolType)
    {
        case DRV_SPI_PROTOCOL_TYPE_STANDARD:
             PLIB_SPI_FramedCommunicationDisable( spiId  );
             break;

        case DRV_SPI_PROTOCOL_TYPE_FRAMED:

            #if defined (PLIB_SPI_ExistsFrameSyncPulseDirection)
                if (PLIB_SPI_ExistsFrameSyncPulseDirection(spiId))
                {
                    PLIB_SPI_FrameSyncPulseDirectionSelect(spiId, init->framePulseDirection);
                }
            #endif
            #if defined (PLIB_SPI_ExistsFrameSyncPulsePolarity)
                if (PLIB_SPI_ExistsFrameSyncPulsePolarity(spiId))
                {
                    PLIB_SPI_FrameSyncPulsePolaritySelect(spiId, init->framePulsePolarity);
                }
            #endif
            #if defined (PLIB_SPI_ExistsFrameSyncPulseEdge)
                if (PLIB_SPI_ExistsFrameSyncPulseEdge(spiId))
                {
                    PLIB_SPI_FrameSyncPulseEdgeSelect(spiId, init->framePulseEdge);
                }
            #endif
            #if defined (PLIB_SPI_ExistsFrameSyncPulseWidth)
                if (PLIB_SPI_ExistsFrameSyncPulseWidth(spiId))
                {
                    PLIB_SPI_FrameSyncPulseWidthSelect(spiId, init->framePulseWidth);
                }
            #endif
            #if defined (PLIB_SPI_ExistsFrameSyncPulseCounter)
                if (PLIB_SPI_ExistsFrameSyncPulseCounter(spiId))
                {
                    PLIB_SPI_FrameSyncPulseCounterSelect(spiId, init->frameSyncPulse);
                }
            #endif


            PLIB_SPI_FramedCommunicationEnable( spiId  );
            break;

        case DRV_SPI_PROTOCOL_TYPE_AUDIO:
             PLIB_SPI_FramedCommunicationDisable( spiId  );

             {
                 SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
                return -1;
             }
             break;
        default:
             SYS_ASSERT(false, "\r\nInvalid SPI Configuration.");
            return -1;
    }

    PLIB_SPI_FIFOEnable( spiId  );
    PLIB_SPI_FIFOInterruptModeSelect(spiId, SPI_FIFO_INTERRUPT_WHEN_TRANSMIT_BUFFER_IS_COMPLETELY_EMPTY);
    PLIB_SPI_FIFOInterruptModeSelect(spiId, SPI_FIFO_INTERRUPT_WHEN_RECEIVE_BUFFER_IS_NOT_EMPTY);

    PLIB_SPI_BufferClear( spiId );
    PLIB_SPI_ReceiverOverflowClear ( spiId );

    // Note: We do not enable the SPI here, that will be done by the first client.
    return 0;
}

