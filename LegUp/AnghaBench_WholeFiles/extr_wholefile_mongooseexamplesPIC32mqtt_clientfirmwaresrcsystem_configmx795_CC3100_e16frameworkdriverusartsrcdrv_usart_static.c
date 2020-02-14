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
typedef  int uint32_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  SYS_STATUS ;
typedef  int /*<<< orphan*/  SYS_MODULE_OBJ ;
typedef  int /*<<< orphan*/  SYS_MODULE_INDEX ;
typedef  int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS ;
typedef  int /*<<< orphan*/  DRV_USART_LINE_CONTROL_SET_RESULT ;
typedef  int /*<<< orphan*/  DRV_USART_LINE_CONTROL ;
typedef  int /*<<< orphan*/  DRV_USART_CLIENT_STATUS ;
typedef  int /*<<< orphan*/  DRV_USART_BAUD_SET_RESULT ;
typedef  int /*<<< orphan*/  DRV_IO_INTENT ;
typedef  int /*<<< orphan*/  DRV_HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_BUS_PERIPHERAL_1 ; 
 int /*<<< orphan*/  DRV_USART_BAUD_SET_ERROR ; 
 int /*<<< orphan*/  DRV_USART_BAUD_SET_SUCCESS ; 
 int /*<<< orphan*/  DRV_USART_CLIENT_STATUS_READY ; 
 scalar_t__ DRV_USART_INDEX_0 ; 
 int /*<<< orphan*/  DRV_USART_LINE_CONTROL_8NONE1 ; 
 int /*<<< orphan*/  DRV_USART_LINE_CONTROL_SET_SUCCESS ; 
 int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS_RECEIVER_DATA_PRESENT ; 
 int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS_RECEIVER_EMPTY ; 
 int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS_TRANSMIT_EMPTY ; 
 int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS_TRANSMIT_FULL ; 
 int /*<<< orphan*/  INT_SOURCE_USART_2_ERROR ; 
 int /*<<< orphan*/  INT_SOURCE_USART_2_RECEIVE ; 
 int /*<<< orphan*/  INT_SOURCE_USART_2_TRANSMIT ; 
 int /*<<< orphan*/  PLIB_USART_BaudRateHighDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_USART_BaudRateHighEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_USART_BaudRateHighSet (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  PLIB_USART_BaudRateSet (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  PLIB_USART_BaudSetAndEnable (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  PLIB_USART_Disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_USART_InitializeModeGeneral (int /*<<< orphan*/ ,int,int,int,int,int) ; 
 int /*<<< orphan*/  PLIB_USART_InitializeOperation (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_USART_LineControlModeSelect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ PLIB_USART_ReceiverDataIsAvailable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_USART_ReceiverOverrunErrorClear (int /*<<< orphan*/ ) ; 
 scalar_t__ PLIB_USART_ReceiverOverrunHasOccurred (int /*<<< orphan*/ ) ; 
 scalar_t__ PLIB_USART_TransmitterBufferIsFull (int /*<<< orphan*/ ) ; 
 scalar_t__ PLIB_USART_TransmitterIsEmpty (int /*<<< orphan*/ ) ; 
 int SYS_CLK_PeripheralFrequencyGet (int /*<<< orphan*/ ) ; 
 int SYS_INT_SourceDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYS_INT_SourceEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYS_INT_SourceStatusClear (int /*<<< orphan*/ ) ; 
 scalar_t__ SYS_INT_SourceStatusGet (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYS_STATUS_READY ; 
 int UINT16_MAX ; 
 int /*<<< orphan*/  USART_ENABLE_TX_RX_USED ; 
 int /*<<< orphan*/  USART_ID_2 ; 
 int /*<<< orphan*/  USART_RECEIVE_FIFO_ONE_CHAR ; 
 int /*<<< orphan*/  USART_TRANSMIT_FIFO_IDLE ; 

SYS_MODULE_OBJ DRV_USART0_Initialize(void)
{
    uint32_t clockSource;

    /* Disable the USART module to configure it*/
    PLIB_USART_Disable (USART_ID_2);

    /* Initialize the USART based on configuration settings */
    PLIB_USART_InitializeModeGeneral(USART_ID_2,
            false,  /*Auto baud*/
            false,  /*LoopBack mode*/
            false,  /*Auto wakeup on start*/
            false,  /*IRDA mode*/
            false);  /*Stop In Idle mode*/

    /* Set the line control mode */
    PLIB_USART_LineControlModeSelect(USART_ID_2, DRV_USART_LINE_CONTROL_8NONE1);

    /* We set the receive interrupt mode to receive an interrupt whenever FIFO
       is not empty */
    PLIB_USART_InitializeOperation(USART_ID_2,
            USART_RECEIVE_FIFO_ONE_CHAR,
            USART_TRANSMIT_FIFO_IDLE,
            USART_ENABLE_TX_RX_USED);

    /* Get the USART clock source value*/
    clockSource = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_PERIPHERAL_1 );

    /* Set the baud rate and enable the USART */
    PLIB_USART_BaudSetAndEnable(USART_ID_2,
            clockSource,
            115200);  /*Desired Baud rate value*/

    /* Clear the interrupts to be on the safer side*/
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_TRANSMIT);
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_RECEIVE);
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_ERROR);

    /* Enable the error interrupt source */
    SYS_INT_SourceEnable(INT_SOURCE_USART_2_ERROR);

    /* Enable the Receive interrupt source */
    SYS_INT_SourceEnable(INT_SOURCE_USART_2_RECEIVE);

    /* Return the driver instance value*/
    return (SYS_MODULE_OBJ)DRV_USART_INDEX_0;
}

void  DRV_USART0_Deinitialize(void)
{
    bool status;

    /* Disable the interrupts */
    status = SYS_INT_SourceDisable(INT_SOURCE_USART_2_TRANSMIT) ;
    status = SYS_INT_SourceDisable(INT_SOURCE_USART_2_RECEIVE) ;
    status = SYS_INT_SourceDisable(INT_SOURCE_USART_2_ERROR);
    /* Ignore the warning */
    (void)status;

    /* Disable USART module */
    PLIB_USART_Disable (USART_ID_2);

}

SYS_STATUS DRV_USART0_Status(void)
{
    /* Return the status as ready always */
    return SYS_STATUS_READY;
}

void DRV_USART0_TasksTransmit(void)
{
    /* This is the USART Driver Transmit tasks routine.
       In this function, the driver checks if a transmit
       interrupt is active and performs respective action*/

    /* Reading the transmit interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_2_TRANSMIT))
    {
        /* Disable the interrupt, to avoid calling ISR continuously*/
        SYS_INT_SourceDisable(INT_SOURCE_USART_2_TRANSMIT);

        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_TRANSMIT);
    }
}

void DRV_USART0_TasksReceive(void)
{
    /* This is the USART Driver Receive tasks routine. If the receive
       interrupt flag is set, the tasks routines are executed.
     */

    /* Reading the receive interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_2_RECEIVE))
    {

        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_RECEIVE);
    }
}

void DRV_USART0_TasksError(void)
{
    /* This is the USART Driver Error tasks routine. In this function, the
     * driver checks if an error interrupt has occurred. If so the error
     * condition is cleared.  */

    /* Reading the error interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_2_ERROR))
    {
        /* This means an error has occurred */
        if(PLIB_USART_ReceiverOverrunHasOccurred(USART_ID_2))
        {
            PLIB_USART_ReceiverOverrunErrorClear(USART_ID_2);
        }

        /* Clear up the error interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_ERROR);
    }
}

DRV_HANDLE DRV_USART0_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent)
{

    /* Return the driver instance value*/
    return ((DRV_HANDLE)DRV_USART_INDEX_0 );
}

void DRV_USART0_Close(void)
{
    return;
}

DRV_USART_CLIENT_STATUS DRV_USART0_ClientStatus(void)
{
    /* Return the status as ready always*/
    return DRV_USART_CLIENT_STATUS_READY;
}

DRV_USART_TRANSFER_STATUS DRV_USART0_TransferStatus( void )
{
    DRV_USART_TRANSFER_STATUS result = 0;

    /* Check if RX data available */
    if(PLIB_USART_ReceiverDataIsAvailable(USART_ID_2))
    {
        result|= DRV_USART_TRANSFER_STATUS_RECEIVER_DATA_PRESENT;
    }
    else
    {
        result|= DRV_USART_TRANSFER_STATUS_RECEIVER_EMPTY;
    }

    /* Check if TX Buffer is empty */
    if(PLIB_USART_TransmitterIsEmpty(USART_ID_2))
    {
        result|= DRV_USART_TRANSFER_STATUS_TRANSMIT_EMPTY;
    }

    /* Check if the TX buffer is full */
    if(PLIB_USART_TransmitterBufferIsFull(USART_ID_2))
    {
        result|= DRV_USART_TRANSFER_STATUS_TRANSMIT_FULL;
    }

    return(result);
}

DRV_USART_BAUD_SET_RESULT DRV_USART0_BaudSet(uint32_t baud)
{
    uint32_t clockSource;
    int32_t brgValueLow=0;
    int32_t brgValueHigh=0;
    DRV_USART_BAUD_SET_RESULT retVal = DRV_USART_BAUD_SET_SUCCESS;
#if defined (PLIB_USART_ExistsModuleBusyStatus)
    bool isEnabled = false;
#endif

    /* Get the USART clock source value*/
    clockSource = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_PERIPHERAL_1 );

    /* Calculate low and high baud values */
    brgValueLow  = ( (clockSource/baud) >> 4 ) - 1;
    brgValueHigh = ( (clockSource/baud) >> 2 ) - 1;

#if defined (PLIB_USART_ExistsModuleBusyStatus)
        isEnabled = PLIB_USART_ModuleIsBusy (USART_ID_2);
        if (isEnabled)
        {
            PLIB_USART_Disable (USART_ID_2);
            while (PLIB_USART_ModuleIsBusy (USART_ID_2));
        }
#endif

    /* Check if the baud value can be set with high baud settings */
    if ((brgValueHigh >= 0) && (brgValueHigh <= UINT16_MAX))
    {
        PLIB_USART_BaudRateHighEnable(USART_ID_2);
        PLIB_USART_BaudRateHighSet(USART_ID_2,clockSource,baud);
    }
    
    /* Check if the baud value can be set with low baud settings */
    else if ((brgValueLow >= 0) && (brgValueLow <= UINT16_MAX))
    {
        PLIB_USART_BaudRateHighDisable(USART_ID_2);
        PLIB_USART_BaudRateSet(USART_ID_2, clockSource, baud);
    }
    else
    {
            retVal = DRV_USART_BAUD_SET_ERROR;
    }

#if defined (PLIB_USART_ExistsModuleBusyStatus)
    if (isEnabled)
    {
        PLIB_USART_Enable (USART_ID_2);
    }
#endif

    return retVal;
}

DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART0_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode)
{
#if defined (PLIB_USART_ExistsModuleBusyStatus)
    bool isEnabled = false;
#endif
#if defined (PLIB_USART_ExistsModuleBusyStatus)
        isEnabled = PLIB_USART_ModuleIsBusy (USART_ID_2);
        if (isEnabled)
        {
            PLIB_USART_Disable (USART_ID_2);
            while (PLIB_USART_ModuleIsBusy (USART_ID_2));
        }
#endif

    /* Set the Line Control Mode */
    PLIB_USART_LineControlModeSelect(USART_ID_2, lineControlMode);
    
#if defined (PLIB_USART_ExistsModuleBusyStatus)
        if (isEnabled)
        {
            PLIB_USART_Enable (USART_ID_2);
        }
#endif

    /* Return success */
    return(DRV_USART_LINE_CONTROL_SET_SUCCESS);
}

