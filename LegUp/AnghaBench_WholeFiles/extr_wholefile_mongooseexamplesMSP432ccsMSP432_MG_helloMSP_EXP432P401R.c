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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  HwiP_Params ;
typedef  int /*<<< orphan*/ * HwiP_Handle ;

/* Variables and functions */
 int /*<<< orphan*/  DebugP_log0 (char*) ; 
 int /*<<< orphan*/  DebugP_log1 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_LOW_TO_HIGH_TRANSITION ; 
 int GPIO_PIN0 ; 
 int GPIO_PIN1 ; 
 int GPIO_PIN2 ; 
 int GPIO_PIN3 ; 
 int GPIO_PIN5 ; 
 int GPIO_PIN6 ; 
 int GPIO_PIN7 ; 
 int /*<<< orphan*/  GPIO_PORT_P1 ; 
 int /*<<< orphan*/  GPIO_PORT_P2 ; 
 int /*<<< orphan*/  GPIO_PORT_P3 ; 
 int /*<<< orphan*/  GPIO_PORT_P4 ; 
 int /*<<< orphan*/  GPIO_PRIMARY_MODULE_FUNCTION ; 
 int /*<<< orphan*/  GPIO_init () ; 
 int /*<<< orphan*/  HwiP_Params_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * HwiP_create (int /*<<< orphan*/ ,void (*) (uintptr_t),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  I2C_init () ; 
 int /*<<< orphan*/  INT_DMA_ERR ; 
 int /*<<< orphan*/  MAP_DMA_clearErrorStatus () ; 
 int /*<<< orphan*/  MAP_DMA_enableModule () ; 
 int /*<<< orphan*/  MAP_DMA_getErrorStatus () ; 
 int /*<<< orphan*/  MAP_DMA_setControlBase (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_GPIO_interruptEdgeSelect (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_GPIO_setAsInputPinWithPullDownResistor (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MAP_GPIO_setAsOutputPin (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MAP_GPIO_setAsPeripheralModuleFunctionInputPin (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_GPIO_setAsPeripheralModuleFunctionOutputPin (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_GPIO_setOutputHighOnPin (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MAP_GPIO_setOutputLowOnPin (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MAP_PMAP_configurePorts (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PMAP_DISABLE_RECONFIGURATION ; 
 int /*<<< orphan*/  PMAP_P2MAP ; 
 int /*<<< orphan*/  const PM_NONE ; 
 int /*<<< orphan*/  const PM_TA1CCR1A ; 
 int /*<<< orphan*/  const PM_TA1CCR2A ; 
 int /*<<< orphan*/  PWM_init () ; 
 int /*<<< orphan*/  Power_init () ; 
 int /*<<< orphan*/  SDSPI_init () ; 
 int /*<<< orphan*/  SPI_init () ; 
 int /*<<< orphan*/  UART_init () ; 
 int /*<<< orphan*/  Watchdog_init () ; 
 int /*<<< orphan*/  WiFi_init () ; 
 int /*<<< orphan*/  dmaControlTable ; 
 int dmaInitialized ; 

__attribute__((used)) static void dmaErrorHwi(uintptr_t arg)
{
    DebugP_log1("DMA error code: %d\n", MAP_DMA_getErrorStatus());
    MAP_DMA_clearErrorStatus();
    DebugP_log0("DMA error!!\n");
    while(1);
}

void MSP_EXP432P401R_initDMA(void)
{
    HwiP_Params hwiParams;
    HwiP_Handle dmaErrorHwiHandle;

    if (!dmaInitialized) {
        HwiP_Params_init(&hwiParams);
        dmaErrorHwiHandle = HwiP_create(INT_DMA_ERR, dmaErrorHwi, &hwiParams);
        if (dmaErrorHwiHandle == NULL) {
            DebugP_log0("Failed to create DMA error Hwi!!\n");
            while (1);
        }

        MAP_DMA_enableModule();
        MAP_DMA_setControlBase(dmaControlTable);

        dmaInitialized = true;
    }
}

void MSP_EXP432P401R_initGeneral(void)
{
    Power_init();
}

void MSP_EXP432P401R_initGPIO(void)
{
    /* Initialize peripheral and pins */
    GPIO_init();
}

void MSP_EXP432P401R_initI2C(void)
{
    /*
     * NOTE: TI-RTOS examples configure EUSCIB0 as either SPI or I2C.  Thus,
     * a conflict occurs when the I2C & SPI drivers are used simultaneously in
     * an application.  Modify the pin mux settings in this file and resolve the
     * conflict before running your the application.
     */
    /* Configure Pins 1.6 & 1.7 as SDA & SCL, respectively. */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
        GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initialize the I2C driver */
    I2C_init();
}

void MSP_EXP432P401R_initPWM(void)
{
    /* Use Port Map on Port2 get Timer outputs on pins with LEDs (2.1, 2.2) */
    const uint8_t portMap [] = {
        PM_NONE, PM_TA1CCR1A, PM_TA1CCR2A, PM_NONE,
        PM_NONE, PM_NONE,     PM_NONE,     PM_NONE
    };

    /* Mapping capture compare registers to Port 2 */
    MAP_PMAP_configurePorts((const uint8_t *) portMap, PMAP_P2MAP, 1,
        PMAP_DISABLE_RECONFIGURATION);

    /* Enable PWM output on GPIO pins */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2,
        GPIO_PIN1 | GPIO_PIN2, GPIO_PRIMARY_MODULE_FUNCTION);

    PWM_init();
}

void MSP_EXP432P401R_initSDSPI(void)
{
    SDSPI_init();
}

void MSP_EXP432P401R_initSPI(void)
{
    /*
     * NOTE: TI-RTOS examples configure EUSCIB0 as either SPI or I2C.  Thus,
     * a conflict occurs when the I2C & SPI drivers are used simultaneously in
     * an application.  Modify the pin mux settings in this file and resolve the
     * conflict before running your the application.
     */
    /* Configure CLK, MOSI & MISO for SPI0 (EUSCI_B0) */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1,
        GPIO_PIN5 | GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configure CLK, MOSI & MISO for SPI1 (EUSCI_B2) */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P3,
        GPIO_PIN5 | GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

    MSP_EXP432P401R_initDMA();
    SPI_init();
}

void MSP_EXP432P401R_initUART(void)
{
    /* Set P1.2 & P1.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
        GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Set P3.2 & P3.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3,
        GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initialize the UART driver */
    UART_init();
}

void MSP_EXP432P401R_initWatchdog(void)
{
    /* Initialize the Watchdog driver */
    Watchdog_init();
}

void MSP_EXP432P401R_initWiFi(void)
{
    /* Configure EN & CS pins to disable CC3100 */
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN1);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN0);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);

    /* Configure CLK, MOSI & MISO for SPI0 (EUSCI_B0) */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1,
        GPIO_PIN5 | GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configure IRQ pin */
    MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, GPIO_PIN5);
    MAP_GPIO_interruptEdgeSelect(GPIO_PORT_P2, GPIO_PIN5,
        GPIO_LOW_TO_HIGH_TRANSITION);

    /* Initialize SPI and WiFi drivers */
    MSP_EXP432P401R_initDMA();
    SPI_init();
    WiFi_init();
}

