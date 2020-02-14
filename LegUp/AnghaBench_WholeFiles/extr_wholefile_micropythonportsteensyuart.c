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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int uint ;
typedef  int /*<<< orphan*/  pyb_uart_obj_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;

/* Variables and functions */

bool uart_init2(pyb_uart_obj_t *uart_obj) {
#if 0
    USART_TypeDef *UARTx = NULL;

    uint32_t GPIO_Pin = 0;
    uint8_t  GPIO_AF_UARTx = 0;
    GPIO_TypeDef* GPIO_Port = NULL;

    switch (uart_obj->uart_id) {
        // USART1 is on PA9/PA10 (CK on PA8), PB6/PB7
        case PYB_UART_1:
            UARTx = USART1;
            GPIO_AF_UARTx = GPIO_AF7_USART1;

#if defined (PYBV4) || defined(PYBV10)
            GPIO_Port = GPIOB;
            GPIO_Pin = GPIO_PIN_6 | GPIO_PIN_7;
#else
            GPIO_Port = GPIOA;
            GPIO_Pin = GPIO_PIN_9 | GPIO_PIN_10;
#endif

            __USART1_CLK_ENABLE();
            break;

        // USART2 is on PA2/PA3 (CK on PA4), PD5/PD6 (CK on PD7)
        case PYB_UART_2:
            UARTx = USART2;
            GPIO_AF_UARTx = GPIO_AF7_USART2;

            GPIO_Port = GPIOA;
            GPIO_Pin = GPIO_PIN_2 | GPIO_PIN_3;

            __USART2_CLK_ENABLE();
            break;

        // USART3 is on PB10/PB11 (CK on PB12), PC10/PC11 (CK on PC12), PD8/PD9 (CK on PD10)
        case PYB_UART_3:
            UARTx = USART3;
            GPIO_AF_UARTx = GPIO_AF7_USART3;

#if defined(PYBV3) || defined(PYBV4) | defined(PYBV10)
            GPIO_Port = GPIOB;
            GPIO_Pin = GPIO_PIN_10 | GPIO_PIN_11;
#else
            GPIO_Port = GPIOD;
            GPIO_Pin = GPIO_PIN_8 | GPIO_PIN_9;
#endif
            __USART3_CLK_ENABLE();
            break;

        // UART4 is on PA0/PA1, PC10/PC11
        case PYB_UART_4:
            UARTx = UART4;
            GPIO_AF_UARTx = GPIO_AF8_UART4;

            GPIO_Port = GPIOA;
            GPIO_Pin = GPIO_PIN_0 | GPIO_PIN_1;

            __UART4_CLK_ENABLE();
            break;

        // USART6 is on PC6/PC7 (CK on PC8)
        case PYB_UART_6:
            UARTx = USART6;
            GPIO_AF_UARTx = GPIO_AF8_USART6;

            GPIO_Port = GPIOC;
            GPIO_Pin = GPIO_PIN_6 | GPIO_PIN_7;

            __USART6_CLK_ENABLE();
            break;

        default:
            return false;
    }

    // init GPIO
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Pin = GPIO_Pin;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Alternate = GPIO_AF_UARTx;
    HAL_GPIO_Init(GPIO_Port, &GPIO_InitStructure);

    // init UARTx
    uart_obj->uart.Instance = UARTx;
    HAL_UART_Init(&uart_obj->uart);

    uart_obj->is_enabled = true;
#endif
    return true;
}

bool uart_init(pyb_uart_obj_t *uart_obj, uint32_t baudrate) {
#if 0
    UART_HandleTypeDef *uh = &uart_obj->uart;
    memset(uh, 0, sizeof(*uh));
    uh->Init.BaudRate = baudrate;
    uh->Init.WordLength = UART_WORDLENGTH_8B;
    uh->Init.StopBits = UART_STOPBITS_1;
    uh->Init.Parity = UART_PARITY_NONE;
    uh->Init.Mode = UART_MODE_TX_RX;
    uh->Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uh->Init.OverSampling = UART_OVERSAMPLING_16;
#endif
    return uart_init2(uart_obj);
}

mp_uint_t uart_rx_any(pyb_uart_obj_t *uart_obj) {
#if 0
    return __HAL_UART_GET_FLAG(&uart_obj->uart, UART_FLAG_RXNE);
#else
    return 0;
#endif
}

int uart_rx_char(pyb_uart_obj_t *uart_obj) {
    uint8_t ch;
#if 0
    if (HAL_UART_Receive(&uart_obj->uart, &ch, 1, 0) != HAL_OK) {
        ch = 0;
    }
#else
    ch = 'A';
#endif
    return ch;
}

void uart_tx_char(pyb_uart_obj_t *uart_obj, int c) {
#if 0
    uint8_t ch = c;
    HAL_UART_Transmit(&uart_obj->uart, &ch, 1, 100000);
#endif
}

void uart_tx_str(pyb_uart_obj_t *uart_obj, const char *str) {
#if 0
    HAL_UART_Transmit(&uart_obj->uart, (uint8_t*)str, strlen(str), 100000);
#endif
}

void uart_tx_strn(pyb_uart_obj_t *uart_obj, const char *str, uint len) {
#if 0
    HAL_UART_Transmit(&uart_obj->uart, (uint8_t*)str, len, 100000);
#endif
}

void uart_tx_strn_cooked(pyb_uart_obj_t *uart_obj, const char *str, uint len) {
    for (const char *top = str + len; str < top; str++) {
        if (*str == '\n') {
            uart_tx_char(uart_obj, '\r');
        }
        uart_tx_char(uart_obj, *str);
    }
}

