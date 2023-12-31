// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "keymap_uk.h"


// Additional Features double tap guard

enum {
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
    const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
    #if defined (MIRYOKU_LAYERS_FLIP)
        const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
    #else
        const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
    #endif
    const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
    combo_t key_combos[] = {
    COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
    COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
    COMBO(thumbcombos_nav, KC_DEL),
    COMBO(thumbcombos_mouse, KC_BTN3),
    COMBO(thumbcombos_media, KC_MUTE),
    COMBO(thumbcombos_num, KC_DOT),
    #if defined (MIRYOKU_LAYERS_FLIP)
        COMBO(thumbcombos_sym, KC_RPRN),
    #else
        COMBO(thumbcombos_sym, KC_LPRN),
    #endif
    COMBO(thumbcombos_fun, KC_APP)
    };
#endif
