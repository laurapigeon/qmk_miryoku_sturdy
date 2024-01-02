// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "keymap_uk.h"

#define KC_MAC_UNDO LGUI(UK_Z)
#define KC_MAC_CUT LGUI(UK_X)
#define KC_MAC_COPY LGUI(UK_C)
#define KC_MAC_PASTE LGUI(UK_V)
#define KC_PC_UNDO LCTL(UK_Z)
#define KC_PC_CUT LCTL(UK_X)
#define KC_PC_COPY LCTL(UK_C)
#define KC_PC_PASTE LCTL(UK_V)
#define ES_LESS_MAC UK_GRV
#define ES_GRTR_MAC LSFT(UK_GRV)
#define ES_BSLS_MAC ALGR(UK_6)
#define NO_PIPE_ALT UK_GRV
#define NO_BSLS_ALT UK_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(UK_8)
#define SE_SECT_MAC ALGR(UK_6)
#define MOON_LED_LEVEL LED_LEVEL

#define C_GUI_ESC LGUI_T(KC_ESC)
#define C_RSFT_ENT RSFT_T(KC_ENT)
#define C_LALT_ENT LALT_T(KC_ENT)
#define C_RCTL_MINS RCTL_T(UK_MINS)
#define C_LCTL_BSPC LCTL(KC_BSPC)


// Additional Features double tap guard

// Tap Dance keycodes
enum td_keycodes {
    U_TD_BOOT,
    #define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
    #undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    #define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
    MIRYOKU_LAYER_LIST
    #undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};



// shift functions

const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(U_SYM,KC_BSPC), KC_DEL);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COMM, UK_QUES);
const key_override_t period_key_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(UK_DOT), UK_EXLM);
const key_override_t apostrophe_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(U_BUTTON,UK_QUOT), UK_MINS);
const key_override_t one_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_1, KC_F1);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_2, KC_F2);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_3, KC_F3);
const key_override_t four_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_4, KC_F4);
const key_override_t five_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_5, KC_F5);
const key_override_t six_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_6, KC_F6);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_7, KC_F7);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_8, KC_F8);
const key_override_t nine_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_9, KC_F9);
const key_override_t ten_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_MINS, KC_F10);
const key_override_t eleven_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PLUS, KC_F11);
const key_override_t twelve_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PERC, KC_F12);
const key_override_t pound_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PND, UK_DLR);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_SLSH, UK_BSLS);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_SCLN, UK_COLN);
const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_QUOT);
const key_override_t leftparen_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_LPRN, UK_LABK);
const key_override_t rightparen_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_RPRN, UK_RABK);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PIPE, UK_NOT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &backspace_key_override,
    &comma_key_override,
    &period_key_override,
    &apostrophe_key_override,
    &one_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,
    &five_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    &ten_key_override,
    &eleven_key_override,
    &twelve_key_override,
    &pound_key_override,
    &slash_key_override,
    &colon_key_override,
    &quote_key_override,
    &leftparen_key_override,
    &rightparen_key_override,
    &pipe_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
    const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
    const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
    const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
    const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
    const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
    const uint16_t PROGMEM thumbcombos_num[] = {UK_0, UK_MINS, COMBO_END};
    #if defined (MIRYOKU_LAYERS_FLIP)
        const uint16_t PROGMEM thumbcombos_sym[] = {UK_UNDS, UK_LPRN, COMBO_END};
    #else
        const uint16_t PROGMEM thumbcombos_sym[] = {UK_RPRN, UK_UNDS, COMBO_END};
    #endif
    const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
    combo_t key_combos[] = {
    COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
    COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
    COMBO(thumbcombos_nav, KC_DEL),
    COMBO(thumbcombos_mouse, KC_BTN3),
    COMBO(thumbcombos_media, KC_MUTE),
    COMBO(thumbcombos_num, UK_DOT),
    #if defined (MIRYOKU_LAYERS_FLIP)
        COMBO(thumbcombos_sym, UK_RPRN),
    #else
        COMBO(thumbcombos_sym, UK_LPRN),
    #endif
    COMBO(thumbcombos_fun, KC_APP)
    };
#endif


// magic keys

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case KC_F21:
        case KC_F22:
        case KC_F23:
        case LT(U_NAV,KC_F24):
            return false;  // Ignore ALTREP keys.
    }

    return true;  // Other keys can be repeated.
}

static void process_magic_key(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case LGUI_T(UK_S): SEND_STRING(/*s*/"k"); break;
        case LALT_T(UK_T): SEND_STRING(/*t*/"ment"); break;
        case LCTL_T(UK_R): SEND_STRING(/*r*/"l"); break;
        case LSFT_T(UK_D): SEND_STRING(/*d*/"y"); break;
        case UK_Y: SEND_STRING(/*y*/"p"); break;
        case UK_F: SEND_STRING(/*f*/""); break;
        case LSFT_T(UK_N): SEND_STRING(/*n*/"ion"); break;
        case LCTL_T(UK_E): SEND_STRING(/*e*/"u"); break;
        case LALT_T(UK_A): SEND_STRING(/*a*/"o"); break;
        case LGUI_T(UK_I): SEND_STRING(/*i*/"on"); break;
        case UK_V: SEND_STRING(/*v*/"er"); break;
        case UK_M: SEND_STRING(/*m*/"ent"); break;
        case UK_L: SEND_STRING(/*l*/"k"); break;
        case UK_C: SEND_STRING(/*c*/"y"); break;
        case UK_P: SEND_STRING(/*p*/"y"); break;
        case UK_B: SEND_STRING(/*b*/"efore"); break;
        case UK_U: SEND_STRING(/*u*/"e"); break;
        case UK_O: SEND_STRING(/*o*/"a"); break;
        case UK_Q: SEND_STRING(/*q*/"ue"); break;
        case LT(U_BUTTON,UK_X): SEND_STRING(/*x*/"es"); break;
        case ALGR_T(UK_K): SEND_STRING(/*k*/"s"); break;
        case UK_J: SEND_STRING(/*j*/"ust"); break;
        case UK_G: SEND_STRING(/*g*/"y"); break;
        case UK_W: SEND_STRING(/*w*/"hich"); break;
        case UK_Z: SEND_STRING(/*z*/""); break;
        case UK_H: SEND_STRING(/*h*/""); break;
        case UK_COMM: SEND_STRING(/*,*/" but"); break;
        case ALGR_T(UK_DOT): SEND_STRING(/*.*/""); break;
        case LT(U_BUTTON,UK_QUOT): SEND_STRING(/*'*/""); break;
        case LT(U_NUM,KC_SPC): SEND_STRING(/* */"the"); break;
        default: SEND_STRING(""); break;
    }
}

static void process_altrepeat_key(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case LGUI_T(UK_S): SEND_STRING(/*s*/"s"); break;
        case LALT_T(UK_T): SEND_STRING(/*t*/"t"); break;
        case LCTL_T(UK_R): SEND_STRING(/*r*/"r"); break;
        case LSFT_T(UK_D): SEND_STRING(/*d*/"d"); break;
        case UK_Y: SEND_STRING(/*y*/"ou"); break;
        case UK_F: SEND_STRING(/*f*/"f"); break;
        case LSFT_T(UK_N): SEND_STRING(/*n*/"f"); break;
        case LCTL_T(UK_E): SEND_STRING(/*e*/"e"); break;
        case LALT_T(UK_A): SEND_STRING(/*a*/"nd"); break;
        case LGUI_T(UK_I): SEND_STRING(/*i*/"ng"); break;
        case UK_V: SEND_STRING(/*v*/""); break;
        case UK_M: SEND_STRING(/*m*/"m"); break;
        case UK_L: SEND_STRING(/*l*/"l"); break;
        case UK_C: SEND_STRING(/*c*/"c"); break;
        case UK_P: SEND_STRING(/*p*/"p"); break;
        case UK_B: SEND_STRING(/*b*/"ecause"); break;
        case UK_U: SEND_STRING(/*u*/""); break;
        case UK_O: SEND_STRING(/*o*/"o"); break;
        case UK_Q: SEND_STRING(/*q*/"ui"); break;
        case LT(U_BUTTON,UK_X): SEND_STRING(/*x*/""); break;
        case ALGR_T(UK_K): SEND_STRING(/*k*/""); break;
        case UK_J: SEND_STRING(/*j*/"udge"); break;
        case UK_G: SEND_STRING(/*g*/"g"); break;
        case UK_W: SEND_STRING(/*w*/"ould"); break;
        case UK_Z: SEND_STRING(/*z*/"z"); break;
        case UK_H: SEND_STRING(/*h*/""); break;
        case UK_COMM: SEND_STRING(/*,*/" and"); break;
        case ALGR_T(UK_DOT): SEND_STRING(/*.*/""); break;
        case LT(U_BUTTON,UK_QUOT): SEND_STRING(/*'*/""); break;
        case LT(U_NUM,KC_SPC): SEND_STRING(/* */"for"); break;
        default: SEND_STRING(""); break;
    }
}

static void process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case LGUI_T(UK_S): SEND_STRING("hould"); break;
        case LALT_T(UK_T): SEND_STRING("hough"); break;
        case LCTL_T(UK_R): SEND_STRING("ight"); break;
        case LSFT_T(UK_D): SEND_STRING("evelop"); break;
        case UK_Y: break;
        case UK_F: SEND_STRING("ollow"); break;
        case LSFT_T(UK_N): SEND_STRING("eighbor"); break;
        case LCTL_T(UK_E): break;
        case LALT_T(UK_A): SEND_STRING("lready"); break;
        case LGUI_T(UK_I): SEND_STRING("'ll"); break;
        case UK_V: break;
        case UK_M: SEND_STRING("ight"); break;
        case UK_L: SEND_STRING("ittle"); break;
        case UK_C: SEND_STRING("ould"); break;
        case UK_P: SEND_STRING("sych"); break;
        case UK_B: SEND_STRING("ecome"); break;
        case UK_U: SEND_STRING("pgrade"); break;
        case UK_O: SEND_STRING("ther"); break;
        case UK_Q: break;
        case LT(U_BUTTON,UK_X): break;
        case ALGR_T(UK_K): SEND_STRING("now"); break;
        case UK_J: SEND_STRING("udge"); break;
        case UK_G: SEND_STRING("eneral"); break;
        case UK_W: SEND_STRING("here"); break;
        case UK_Z: break;
        case UK_H: SEND_STRING("owever"); break;
        case UK_COMM: SEND_STRING(" however"); break;
        case ALGR_T(UK_DOT): break;
        case LT(U_BUTTON,UK_QUOT): break;
        case LT(U_NUM,KC_SPC): SEND_STRING("the"); break;
        default: SEND_STRING("'ll"); break;
    }
}

static void process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case UK_B: SEND_STRING("etween"); break;
        case LSFT_T(UK_N): SEND_STRING("umber"); break;
        case UK_U: SEND_STRING("pdate"); break;
        case LALT_T(UK_A): SEND_STRING("bout"); break;
        case UK_W: SEND_STRING("orld"); break;
        case UK_G: SEND_STRING("overn"); break;
        case UK_P: SEND_STRING("rogram"); break;
        case UK_Q: SEND_STRING("uestion"); break;
        case UK_C: SEND_STRING("rowd"); break;
        case LGUI_T(UK_S): SEND_STRING("chool"); break;
        case LALT_T(UK_T): SEND_STRING("hrough"); break;
        case UK_M: SEND_STRING("anage"); break;
        case UK_O: SEND_STRING("xygen"); break;
        case LGUI_T(UK_I): SEND_STRING("'m"); break;
        case LCTL_T(UK_E): SEND_STRING("'re"); break;
        case UK_COMM: SEND_STRING(" since"); break;
        default: break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_F21: 
            if (record->event.pressed) {
                process_magic_key(get_last_keycode(), get_last_mods());
            }
            return false;

        case KC_F22: 
            if (record->event.pressed) {
                process_magic_key_2(get_last_keycode(), get_last_mods());
            }
            return false;

        case KC_F23: 
            if (record->event.pressed) {
                process_magic_key_3(get_last_keycode(), get_last_mods());
            }
            return false;

        case LT(U_NAV,KC_F24):
            if (record->event.pressed && record->tap.count) {
                process_altrepeat_key(get_last_keycode(), get_last_mods());
            }
            return true;
    }

    return true;
}