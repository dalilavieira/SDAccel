#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {scalar_t__ internal_error; int /*<<< orphan*/  internal_data; } ;
typedef  TYPE_1__ result_t ;
typedef  scalar_t__ result_error_t ;
typedef  int /*<<< orphan*/  result_data_t ;

/* Variables and functions */
#define  result_error_compression_error 133 
#define  result_error_decompression_error 132 
#define  result_error_ok 131 
#define  result_error_round_trip_error 130 
#define  result_error_skip 129 
#define  result_error_system_error 128 
static  scalar_t__ result_get_error (TYPE_1__) ; 

__attribute__((used)) static result_t result_error(result_error_t error) {
    result_t result = {
        .internal_error = error,
    };
    return result;
}

__attribute__((used)) static result_t result_data(result_data_t data) {
    result_t result = {
        .internal_error = result_error_ok,
        .internal_data = data,
    };
    return result;
}

__attribute__((used)) static int result_is_error(result_t result) {
    return result_get_error(result) != result_error_ok;
}

__attribute__((used)) static int result_is_skip(result_t result) {
    return result_get_error(result) == result_error_skip;
}

__attribute__((used)) static result_error_t result_get_error(result_t result) {
    return result.internal_error;
}

__attribute__((used)) static result_data_t result_get_data(result_t result) {
    return result.internal_data;
}

char const* result_get_error_string(result_t result) {
    switch (result_get_error(result)) {
        case result_error_ok:
            return "okay";
        case result_error_skip:
            return "skip";
        case result_error_system_error:
            return "system error";
        case result_error_compression_error:
            return "compression error";
        case result_error_decompression_error:
            return "decompression error";
        case result_error_round_trip_error:
            return "round trip error";
    }
}

