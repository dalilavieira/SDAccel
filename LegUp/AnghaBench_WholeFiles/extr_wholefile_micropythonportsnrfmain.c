#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_7__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  qstr ;
struct TYPE_8__ {scalar_t__ ret_val; } ;
typedef  TYPE_1__ nlr_buf_t ;
typedef  int /*<<< orphan*/  mp_parse_tree_t ;
typedef  int /*<<< orphan*/  mp_parse_input_kind_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
struct TYPE_9__ {int /*<<< orphan*/  source_name; } ;
typedef  TYPE_2__ mp_lexer_t ;
typedef  int /*<<< orphan*/  mp_import_stat_t ;
struct TYPE_10__ {int /*<<< orphan*/  (* make_new ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
typedef  int /*<<< orphan*/  MP_STATE_PORT ;

/* Variables and functions */
 int /*<<< orphan*/  MP_ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MP_EMIT_OPT_NONE ; 
 int /*<<< orphan*/  MP_ENOENT ; 
 int /*<<< orphan*/  MP_IMPORT_STAT_NO_EXIST ; 
 int /*<<< orphan*/  MP_OBJ_NEW_QSTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MP_OBJ_NEW_SMALL_INT (int) ; 
 int /*<<< orphan*/  MP_QSTR_ ; 
 int /*<<< orphan*/  MP_QSTR__lt_stdin_gt_ ; 
 scalar_t__ PYEXEC_MODE_RAW_REPL ; 
 int /*<<< orphan*/  _heap_end ; 
 int /*<<< orphan*/  _heap_start ; 
 int /*<<< orphan*/  _ram_end ; 
 int /*<<< orphan*/  gc_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_7__ machine_hard_uart_type ; 
 int /*<<< orphan*/  machine_init () ; 
 int /*<<< orphan*/  mp_call_function_0 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_compile (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mp_deinit () ; 
 int /*<<< orphan*/  mp_init () ; 
 TYPE_2__* mp_lexer_new_from_str_len (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_list_append (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_list_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_print_exception (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_parse (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_plat_print ; 
 int /*<<< orphan*/  mp_raise_OSError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_stack_set_limit (int) ; 
 int /*<<< orphan*/  mp_stack_set_top (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_sys_argv ; 
 int /*<<< orphan*/  mp_sys_path ; 
 int /*<<< orphan*/  nlr_pop () ; 
 scalar_t__ nlr_push (TYPE_1__*) ; 
 int /*<<< orphan*/  pin_init0 () ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  pyb_set_repl_info (int /*<<< orphan*/ ) ; 
 int pyexec_friendly_repl () ; 
 scalar_t__ pyexec_mode_kind ; 
 scalar_t__ pyexec_raw_repl () ; 
 int /*<<< orphan*/  readline_init0 () ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void do_str(const char *src, mp_parse_input_kind_t input_kind) {
    mp_lexer_t *lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, src, strlen(src), 0);
    if (lex == NULL) {
        printf("MemoryError: lexer could not allocate memory\n");
        return;
    }

    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0) {
        qstr source_name = lex->source_name;
        mp_parse_tree_t pn = mp_parse(lex, input_kind);
        mp_obj_t module_fun = mp_compile(&pn, source_name, MP_EMIT_OPT_NONE, true);
        mp_call_function_0(module_fun);
        nlr_pop();
    } else {
        // uncaught exception
        mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
    }
}

int main(int argc, char **argv) {
    
soft_reset:
    mp_stack_set_top(&_ram_end);

    // Stack limit should be less than real stack size, so we have a chance
    // to recover from limit hit.  (Limit is measured in bytes.)
    mp_stack_set_limit((char*)&_ram_end - (char*)&_heap_end - 400);

    machine_init();

    gc_init(&_heap_start, &_heap_end);

    mp_init();
    mp_obj_list_init(mp_sys_path, 0);
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR_)); // current dir (or base dir of the script)
    mp_obj_list_init(mp_sys_argv, 0);

    pyb_set_repl_info(MP_OBJ_NEW_SMALL_INT(0));

    readline_init0();

#if MICROPY_PY_MACHINE_HW_SPI
    spi_init0();
#endif

#if MICROPY_PY_MACHINE_I2C
    i2c_init0();
#endif

#if MICROPY_PY_MACHINE_ADC
    adc_init0();
#endif

#if MICROPY_PY_MACHINE_HW_PWM
    pwm_init0();
#endif

#if MICROPY_PY_MACHINE_RTCOUNTER
    rtc_init0();
#endif

#if MICROPY_PY_MACHINE_TIMER
    timer_init0();
#endif

#if MICROPY_PY_MACHINE_UART
    uart_init0();
#endif

#if (MICROPY_PY_BLE_NUS == 0)
    {
        mp_obj_t args[2] = {
            MP_OBJ_NEW_SMALL_INT(0),
            MP_OBJ_NEW_SMALL_INT(115200),
        };
        MP_STATE_PORT(board_stdio_uart) = machine_hard_uart_type.make_new((mp_obj_t)&machine_hard_uart_type, MP_ARRAY_SIZE(args), 0, args);
    }
#endif

pin_init0();

#if MICROPY_MBFS
    microbit_filesystem_init();
#endif

#if MICROPY_HW_HAS_SDCARD
    // if an SD card is present then mount it on /sd/
    if (sdcard_is_present()) {
        // create vfs object
        fs_user_mount_t *vfs = m_new_obj_maybe(fs_user_mount_t);
        if (vfs == NULL) {
            goto no_mem_for_sd;
        }
        vfs->str = "/sd";
        vfs->len = 3;
        vfs->flags = FSUSER_FREE_OBJ;
        sdcard_init_vfs(vfs);

        // put the sd device in slot 1 (it will be unused at this point)
        MP_STATE_PORT(fs_user_mount)[1] = vfs;

        FRESULT res = f_mount(&vfs->fatfs, vfs->str, 1);
        if (res != FR_OK) {
            printf("MPY: can't mount SD card\n");
            MP_STATE_PORT(fs_user_mount)[1] = NULL;
            m_del_obj(fs_user_mount_t, vfs);
        } else {
            // TODO these should go before the /flash entries in the path
            mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR__slash_sd));
            mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR__slash_sd_slash_lib));

			// use SD card as current directory
			f_chdrive("/sd");
        }
        no_mem_for_sd:;
    }
#endif

#if (MICROPY_HW_HAS_LED)
    led_init();

    do_str("import board\r\n" \
           "board.LED(1).on()",
           MP_PARSE_FILE_INPUT);
#endif

    // Main script is finished, so now go into REPL mode.
    // The REPL mode can change, or it can request a soft reset.
    int ret_code = 0;

#if MICROPY_PY_BLE_NUS
    ble_uart_init0();
#endif

#if MICROPY_PY_MACHINE_SOFT_PWM
    ticker_init0();
    softpwm_init0();
#endif

#if MICROPY_PY_MUSIC
    microbit_music_init0();
#endif
#if BOARD_SPECIFIC_MODULES
    board_modules_init0();
#endif

#if MICROPY_PY_MACHINE_SOFT_PWM
    ticker_start();
    pwm_start();
#endif

#if MICROPY_VFS || MICROPY_MBFS
    // run boot.py and main.py if they exist.
    pyexec_file_if_exists("boot.py");
    pyexec_file_if_exists("main.py");
#endif

    for (;;) {
        if (pyexec_mode_kind == PYEXEC_MODE_RAW_REPL) {
            if (pyexec_raw_repl() != 0) {
                break;
            }
        } else {
            ret_code = pyexec_friendly_repl();
            if (ret_code != 0) {
                break;
            }
        }
    }

    mp_deinit();

    printf("MPY: soft reboot\n");

#if BLUETOOTH_SD
    sd_softdevice_disable();
#endif

    goto soft_reset;

    return 0;
}

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    mp_raise_OSError(MP_ENOENT);
}

mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

void HardFault_Handler(void)
{
#if defined(NRF52_SERIES)
	static volatile uint32_t reg;
	static volatile uint32_t reg2;
	static volatile uint32_t bfar;
	reg = SCB->HFSR;
	reg2 = SCB->CFSR;
	bfar = SCB->BFAR;
	for (int i = 0; i < 0; i++)
	{
		(void)reg;
		(void)reg2;
		(void)bfar;
	}
#endif
}

