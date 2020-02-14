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
typedef  int uint16_t ;
typedef  enum android_motionevent_buttons { ____Placeholder_android_motionevent_buttons } android_motionevent_buttons ;
typedef  enum android_motionevent_action { ____Placeholder_android_motionevent_action } android_motionevent_action ;
typedef  enum android_metastate { ____Placeholder_android_metastate } android_metastate ;
typedef  enum android_keyevent_action { ____Placeholder_android_keyevent_action } android_keyevent_action ;
typedef  enum android_keycode { ____Placeholder_android_keycode } android_keycode ;
typedef  int SDL_Keymod ;
typedef  int SDL_Keycode ;
typedef  int SDL_EventType ;

/* Variables and functions */
 int /*<<< orphan*/  AKEYCODE_A ; 
 int /*<<< orphan*/  AKEYCODE_B ; 
 int /*<<< orphan*/  AKEYCODE_C ; 
 int /*<<< orphan*/  AKEYCODE_D ; 
 int /*<<< orphan*/  AKEYCODE_DEL ; 
 int /*<<< orphan*/  AKEYCODE_DPAD_DOWN ; 
 int /*<<< orphan*/  AKEYCODE_DPAD_LEFT ; 
 int /*<<< orphan*/  AKEYCODE_DPAD_RIGHT ; 
 int /*<<< orphan*/  AKEYCODE_DPAD_UP ; 
 int /*<<< orphan*/  AKEYCODE_E ; 
 int /*<<< orphan*/  AKEYCODE_ENTER ; 
 int /*<<< orphan*/  AKEYCODE_ESCAPE ; 
 int /*<<< orphan*/  AKEYCODE_F ; 
 int /*<<< orphan*/  AKEYCODE_FORWARD_DEL ; 
 int /*<<< orphan*/  AKEYCODE_G ; 
 int /*<<< orphan*/  AKEYCODE_H ; 
 int /*<<< orphan*/  AKEYCODE_HOME ; 
 int /*<<< orphan*/  AKEYCODE_I ; 
 int /*<<< orphan*/  AKEYCODE_J ; 
 int /*<<< orphan*/  AKEYCODE_K ; 
 int /*<<< orphan*/  AKEYCODE_L ; 
 int /*<<< orphan*/  AKEYCODE_M ; 
 int /*<<< orphan*/  AKEYCODE_MOVE_END ; 
 int /*<<< orphan*/  AKEYCODE_N ; 
 int /*<<< orphan*/  AKEYCODE_NUMPAD_ENTER ; 
 int /*<<< orphan*/  AKEYCODE_O ; 
 int /*<<< orphan*/  AKEYCODE_P ; 
 int /*<<< orphan*/  AKEYCODE_PAGE_DOWN ; 
 int /*<<< orphan*/  AKEYCODE_PAGE_UP ; 
 int /*<<< orphan*/  AKEYCODE_Q ; 
 int /*<<< orphan*/  AKEYCODE_R ; 
 int /*<<< orphan*/  AKEYCODE_S ; 
 int /*<<< orphan*/  AKEYCODE_SPACE ; 
 int /*<<< orphan*/  AKEYCODE_T ; 
 int /*<<< orphan*/  AKEYCODE_TAB ; 
 int /*<<< orphan*/  AKEYCODE_U ; 
 int /*<<< orphan*/  AKEYCODE_V ; 
 int /*<<< orphan*/  AKEYCODE_W ; 
 int /*<<< orphan*/  AKEYCODE_X ; 
 int /*<<< orphan*/  AKEYCODE_Y ; 
 int /*<<< orphan*/  AKEYCODE_Z ; 
 int /*<<< orphan*/  AKEY_EVENT_ACTION_DOWN ; 
 int /*<<< orphan*/  AKEY_EVENT_ACTION_UP ; 
 int AMETA_ALT_LEFT_ON ; 
 int AMETA_ALT_ON ; 
 int AMETA_ALT_RIGHT_ON ; 
 int AMETA_CAPS_LOCK_ON ; 
 int AMETA_CTRL_LEFT_ON ; 
 int AMETA_CTRL_ON ; 
 int AMETA_CTRL_RIGHT_ON ; 
 int AMETA_META_LEFT_ON ; 
 int AMETA_META_ON ; 
 int AMETA_META_RIGHT_ON ; 
 int AMETA_NUM_LOCK_ON ; 
 int AMETA_SHIFT_LEFT_ON ; 
 int AMETA_SHIFT_ON ; 
 int AMETA_SHIFT_RIGHT_ON ; 
 int /*<<< orphan*/  AMOTION_EVENT_ACTION_DOWN ; 
 int /*<<< orphan*/  AMOTION_EVENT_ACTION_UP ; 
 int AMOTION_EVENT_BUTTON_BACK ; 
 int AMOTION_EVENT_BUTTON_FORWARD ; 
 int AMOTION_EVENT_BUTTON_PRIMARY ; 
 int AMOTION_EVENT_BUTTON_SECONDARY ; 
 int AMOTION_EVENT_BUTTON_TERTIARY ; 
 int /*<<< orphan*/  FAIL ; 
 int KMOD_CAPS ; 
 int KMOD_LALT ; 
 int KMOD_LCTRL ; 
 int KMOD_LGUI ; 
 int KMOD_LSHIFT ; 
 int KMOD_MODE ; 
 int KMOD_NUM ; 
 int KMOD_RALT ; 
 int KMOD_RCTRL ; 
 int KMOD_RGUI ; 
 int KMOD_RSHIFT ; 
 int /*<<< orphan*/  MAP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDLK_BACKSPACE ; 
 int /*<<< orphan*/  SDLK_DELETE ; 
 int /*<<< orphan*/  SDLK_DOWN ; 
 int /*<<< orphan*/  SDLK_END ; 
 int /*<<< orphan*/  SDLK_ESCAPE ; 
 int /*<<< orphan*/  SDLK_HOME ; 
 int /*<<< orphan*/  SDLK_KP_ENTER ; 
 int /*<<< orphan*/  SDLK_LEFT ; 
 int /*<<< orphan*/  SDLK_PAGEDOWN ; 
 int /*<<< orphan*/  SDLK_PAGEUP ; 
 int /*<<< orphan*/  SDLK_RETURN ; 
 int /*<<< orphan*/  SDLK_RIGHT ; 
 int /*<<< orphan*/  SDLK_SPACE ; 
 int /*<<< orphan*/  SDLK_TAB ; 
 int /*<<< orphan*/  SDLK_UP ; 
 int /*<<< orphan*/  SDLK_a ; 
 int /*<<< orphan*/  SDLK_b ; 
 int /*<<< orphan*/  SDLK_c ; 
 int /*<<< orphan*/  SDLK_d ; 
 int /*<<< orphan*/  SDLK_e ; 
 int /*<<< orphan*/  SDLK_f ; 
 int /*<<< orphan*/  SDLK_g ; 
 int /*<<< orphan*/  SDLK_h ; 
 int /*<<< orphan*/  SDLK_i ; 
 int /*<<< orphan*/  SDLK_j ; 
 int /*<<< orphan*/  SDLK_k ; 
 int /*<<< orphan*/  SDLK_l ; 
 int /*<<< orphan*/  SDLK_m ; 
 int /*<<< orphan*/  SDLK_n ; 
 int /*<<< orphan*/  SDLK_o ; 
 int /*<<< orphan*/  SDLK_p ; 
 int /*<<< orphan*/  SDLK_q ; 
 int /*<<< orphan*/  SDLK_r ; 
 int /*<<< orphan*/  SDLK_s ; 
 int /*<<< orphan*/  SDLK_t ; 
 int /*<<< orphan*/  SDLK_u ; 
 int /*<<< orphan*/  SDLK_v ; 
 int /*<<< orphan*/  SDLK_w ; 
 int /*<<< orphan*/  SDLK_x ; 
 int /*<<< orphan*/  SDLK_y ; 
 int /*<<< orphan*/  SDLK_z ; 
 int SDL_BUTTON_LMASK ; 
 int SDL_BUTTON_MMASK ; 
 int SDL_BUTTON_RMASK ; 
 int SDL_BUTTON_X1 ; 
 int SDL_BUTTON_X2 ; 
 int /*<<< orphan*/  SDL_KEYDOWN ; 
 int /*<<< orphan*/  SDL_KEYUP ; 
 int /*<<< orphan*/  SDL_MOUSEBUTTONDOWN ; 
 int /*<<< orphan*/  SDL_MOUSEBUTTONUP ; 

__attribute__((used)) static bool
convert_keycode_action(SDL_EventType from, enum android_keyevent_action *to) {
    switch (from) {
        MAP(SDL_KEYDOWN, AKEY_EVENT_ACTION_DOWN);
        MAP(SDL_KEYUP,   AKEY_EVENT_ACTION_UP);
        FAIL;
    }
}

__attribute__((used)) static enum android_metastate
autocomplete_metastate(enum android_metastate metastate) {
    // fill dependant flags
    if (metastate & (AMETA_SHIFT_LEFT_ON | AMETA_SHIFT_RIGHT_ON)) {
        metastate |= AMETA_SHIFT_ON;
    }
    if (metastate & (AMETA_CTRL_LEFT_ON | AMETA_CTRL_RIGHT_ON)) {
        metastate |= AMETA_CTRL_ON;
    }
    if (metastate & (AMETA_ALT_LEFT_ON | AMETA_ALT_RIGHT_ON)) {
        metastate |= AMETA_ALT_ON;
    }
    if (metastate & (AMETA_META_LEFT_ON | AMETA_META_RIGHT_ON)) {
        metastate |= AMETA_META_ON;
    }

    return metastate;
}

__attribute__((used)) static enum android_metastate
convert_meta_state(SDL_Keymod mod) {
    enum android_metastate metastate = 0;
    if (mod & KMOD_LSHIFT) {
        metastate |= AMETA_SHIFT_LEFT_ON;
    }
    if (mod & KMOD_RSHIFT) {
        metastate |= AMETA_SHIFT_RIGHT_ON;
    }
    if (mod & KMOD_LCTRL) {
        metastate |= AMETA_CTRL_LEFT_ON;
    }
    if (mod & KMOD_RCTRL) {
        metastate |= AMETA_CTRL_RIGHT_ON;
    }
    if (mod & KMOD_LALT) {
        metastate |= AMETA_ALT_LEFT_ON;
    }
    if (mod & KMOD_RALT) {
        metastate |= AMETA_ALT_RIGHT_ON;
    }
    if (mod & KMOD_LGUI) { // Windows key
        metastate |= AMETA_META_LEFT_ON;
    }
    if (mod & KMOD_RGUI) { // Windows key
        metastate |= AMETA_META_RIGHT_ON;
    }
    if (mod & KMOD_NUM) {
        metastate |= AMETA_NUM_LOCK_ON;
    }
    if (mod & KMOD_CAPS) {
        metastate |= AMETA_CAPS_LOCK_ON;
    }
    if (mod & KMOD_MODE) { // Alt Gr
        // no mapping?
    }

    // fill the dependent fields
    return autocomplete_metastate(metastate);
}

__attribute__((used)) static bool
convert_keycode(SDL_Keycode from, enum android_keycode *to, uint16_t mod) {
    switch (from) {
        MAP(SDLK_RETURN,       AKEYCODE_ENTER);
        MAP(SDLK_KP_ENTER,     AKEYCODE_NUMPAD_ENTER);
        MAP(SDLK_ESCAPE,       AKEYCODE_ESCAPE);
        MAP(SDLK_BACKSPACE,    AKEYCODE_DEL);
        MAP(SDLK_TAB,          AKEYCODE_TAB);
        MAP(SDLK_HOME,         AKEYCODE_HOME);
        MAP(SDLK_PAGEUP,       AKEYCODE_PAGE_UP);
        MAP(SDLK_DELETE,       AKEYCODE_FORWARD_DEL);
        MAP(SDLK_END,          AKEYCODE_MOVE_END);
        MAP(SDLK_PAGEDOWN,     AKEYCODE_PAGE_DOWN);
        MAP(SDLK_RIGHT,        AKEYCODE_DPAD_RIGHT);
        MAP(SDLK_LEFT,         AKEYCODE_DPAD_LEFT);
        MAP(SDLK_DOWN,         AKEYCODE_DPAD_DOWN);
        MAP(SDLK_UP,           AKEYCODE_DPAD_UP);
    }
    if (mod & (KMOD_LALT | KMOD_RALT | KMOD_LGUI | KMOD_RGUI)) {
        return false;
    }
    // if ALT and META are not pressed, also handle letters and space
    switch (from) {
        MAP(SDLK_a,            AKEYCODE_A);
        MAP(SDLK_b,            AKEYCODE_B);
        MAP(SDLK_c,            AKEYCODE_C);
        MAP(SDLK_d,            AKEYCODE_D);
        MAP(SDLK_e,            AKEYCODE_E);
        MAP(SDLK_f,            AKEYCODE_F);
        MAP(SDLK_g,            AKEYCODE_G);
        MAP(SDLK_h,            AKEYCODE_H);
        MAP(SDLK_i,            AKEYCODE_I);
        MAP(SDLK_j,            AKEYCODE_J);
        MAP(SDLK_k,            AKEYCODE_K);
        MAP(SDLK_l,            AKEYCODE_L);
        MAP(SDLK_m,            AKEYCODE_M);
        MAP(SDLK_n,            AKEYCODE_N);
        MAP(SDLK_o,            AKEYCODE_O);
        MAP(SDLK_p,            AKEYCODE_P);
        MAP(SDLK_q,            AKEYCODE_Q);
        MAP(SDLK_r,            AKEYCODE_R);
        MAP(SDLK_s,            AKEYCODE_S);
        MAP(SDLK_t,            AKEYCODE_T);
        MAP(SDLK_u,            AKEYCODE_U);
        MAP(SDLK_v,            AKEYCODE_V);
        MAP(SDLK_w,            AKEYCODE_W);
        MAP(SDLK_x,            AKEYCODE_X);
        MAP(SDLK_y,            AKEYCODE_Y);
        MAP(SDLK_z,            AKEYCODE_Z);
        MAP(SDLK_SPACE,        AKEYCODE_SPACE);
        FAIL;
    }
}

__attribute__((used)) static bool
convert_mouse_action(SDL_EventType from, enum android_motionevent_action *to) {
    switch (from) {
        MAP(SDL_MOUSEBUTTONDOWN, AMOTION_EVENT_ACTION_DOWN);
        MAP(SDL_MOUSEBUTTONUP,   AMOTION_EVENT_ACTION_UP);
        FAIL;
    }
}

__attribute__((used)) static enum android_motionevent_buttons
convert_mouse_buttons(uint32_t state) {
    enum android_motionevent_buttons buttons = 0;
    if (state & SDL_BUTTON_LMASK) {
        buttons |= AMOTION_EVENT_BUTTON_PRIMARY;
    }
    if (state & SDL_BUTTON_RMASK) {
        buttons |= AMOTION_EVENT_BUTTON_SECONDARY;
    }
    if (state & SDL_BUTTON_MMASK) {
        buttons |= AMOTION_EVENT_BUTTON_TERTIARY;
    }
    if (state & SDL_BUTTON_X1) {
        buttons |= AMOTION_EVENT_BUTTON_BACK;
    }
    if (state & SDL_BUTTON_X2) {
        buttons |= AMOTION_EVENT_BUTTON_FORWARD;
    }
    return buttons;
}

