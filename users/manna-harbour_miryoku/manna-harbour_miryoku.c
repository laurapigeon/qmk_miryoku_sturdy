// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "keymap_uk.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

#define C_GUI_ESC LGUI_T(KC_ESC)
#define C_RSFT_ENT RSFT_T(KC_ENT)
#define C_LALT_ENT LALT_T(KC_ENT)
#define C_RCTL_MINS RCTL_T(KC_MINS)
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
    if (state->count == 1) { \
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

const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, UK_QUES);
const key_override_t period_key_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(KC_DOT), UK_EXLM);
const key_override_t apostrophe_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(U_BUTTON,KC_QUOT), UK_DQUO);

const key_override_t one_key_override = ko_make_basic(MOD_MASK_GUI, KC_1, KC_F1);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_GUI, KC_2, KC_F2);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_GUI, KC_3, KC_F3);
const key_override_t four_key_override = ko_make_basic(MOD_MASK_GUI, KC_4, KC_F4);
const key_override_t five_key_override = ko_make_basic(MOD_MASK_GUI, KC_5, KC_F5);
const key_override_t six_key_override = ko_make_basic(MOD_MASK_GUI, KC_6, KC_F6);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_GUI, KC_7, KC_F7);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_GUI, KC_8, KC_F8);
const key_override_t nine_key_override = ko_make_basic(MOD_MASK_GUI, KC_9, KC_F9);
const key_override_t ten_key_override = ko_make_basic(MOD_MASK_GUI, KC_MINS, KC_F10);
const key_override_t eleven_key_override = ko_make_basic(MOD_MASK_GUI, UK_PLUS, KC_F11);
const key_override_t twelve_key_override = ko_make_basic(MOD_MASK_GUI, UK_COLN, KC_F12);

const key_override_t pound_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PND, UK_DLR);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PIPE, UK_NOT);
const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, KC_QUOT);
const key_override_t leftbracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, UK_LCBR);
const key_override_t rightbracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, UK_RCBR);
const key_override_t leftparen_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_LPRN, UK_LABK);
const key_override_t rightparen_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_RPRN, UK_RABK);

const key_override_t **key_overrides = (const key_override_t *[]){
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
    &pipe_key_override,
    &quote_key_override,
    &leftbracket_key_override,
    &rightbracket_key_override,
    &leftparen_key_override,
    &rightparen_key_override,
    NULL
};


// thumb combos

const uint16_t PROGMEM thumbcombos_num[] = {KC_DOT, KC_EQL, COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_DEL, KC_ENT, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {UK_HASH, UK_UNDS, COMBO_END};
const uint16_t PROGMEM thumbcombos_mos[] = {KC_BTN2, KC_BTN3, COMBO_END};
combo_t key_combos[] = {
    COMBO(thumbcombos_num, TD(U_TD_U_BASE)),
    COMBO(thumbcombos_nav, TD(U_TD_U_BASE)),
    COMBO(thumbcombos_sym, TD(U_TD_U_BASE)),
    COMBO(thumbcombos_mos, TD(U_TD_U_BASE))
};


// magic keys

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    if (IS_QK_MOD_TAP(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (IS_QK_LAYER_TAP(keycode)) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }
    switch (keycode) {
        case KC_A ... KC_Z:
            if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;
        case KC_F23:
        case KC_F24:
            return false;  // Ignore keys.
    }
    return true;  // Other keys can be repeated.
}

static void process_rep_macro_key(uint16_t prev_keycode, uint8_t prev_mods) {
    if (IS_QK_MOD_TAP(prev_keycode)) {
        prev_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    if (IS_QK_LAYER_TAP(prev_keycode)) {
        prev_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    switch (prev_keycode) {
        case KC_A: SEND_STRING(/*a*/"nd"); break;
        case KC_B: SEND_STRING(/*b*/"ecause"); break;
        //case KC_C: SEND_STRING(/*c*/""); break;
        //case KC_D: SEND_STRING(/*d*/""); break;
        //case KC_E: SEND_STRING(/*e*/""); break;
        //case KC_F: SEND_STRING(/*f*/""); break;
        //case KC_G: SEND_STRING(/*g*/""); break;
        //case KC_H: SEND_STRING(/*h*/""); break;
        case KC_I: SEND_STRING(/*i*/"ng"); break;
        case KC_J: SEND_STRING(/*j*/"udge"); break;
        //case KC_K: SEND_STRING(/*k*/""); break;
        //case KC_L: SEND_STRING(/*l*/""); break;
        //case KC_M: SEND_STRING(/*m*/""); break;
        //case KC_N: SEND_STRING(/*n*/""); break;
        //case KC_O: SEND_STRING(/*o*/""); break;
        //case KC_P: SEND_STRING(/*p*/""); break;
        case KC_Q: SEND_STRING(/*q*/"ue"); break;
        //case KC_R: SEND_STRING(/*r*/""); break;
        //case KC_S: SEND_STRING(/*s*/""); break;
        //case KC_T: SEND_STRING(/*t*/""); break;
        //case KC_U: SEND_STRING(/*u*/""); break;
        //case KC_V: SEND_STRING(/*v*/""); break;
        case KC_W: SEND_STRING(/*w*/"ould"); break;
        //case KC_X: SEND_STRING(/*x*/"es"); break;
        case KC_Y: SEND_STRING(/*y*/"ou"); break;
        //case KC_Z: SEND_STRING(/*z*/""); break;
        case KC_COMM: SEND_STRING(/*,*/" and"); break;
        //case KC_DOT: SEND_STRING(/*.*/""); break;
        //case KC_QUOT: SEND_STRING(/*'*/""); break;
        case KC_SPC: SEND_STRING(/* */"for"); break;
        default:
            add_mods(prev_mods);
            tap_code16(prev_keycode);
            del_mods(prev_mods);
    }
}

static void process_altrep_macro_key(uint16_t prev_keycode, uint8_t prev_mods) {
    if (IS_QK_MOD_TAP(prev_keycode)) {
        prev_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    if (IS_QK_LAYER_TAP(prev_keycode)) {
        prev_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    switch (prev_keycode) {
        case KC_A: SEND_STRING(/*a*/"o"); break;
        case KC_B: SEND_STRING(/*b*/"efore"); break;
        case KC_C: SEND_STRING(/*c*/"k"); break;
        case KC_D: SEND_STRING(/*d*/"y"); break;
        case KC_E: SEND_STRING(/*e*/"u"); break;
        //case KC_F: SEND_STRING(/*f*/""); break;
        case KC_G: SEND_STRING(/*g*/"y"); break;
        //case KC_H: SEND_STRING(/*h*/""); break;
        case KC_I: SEND_STRING(/*i*/"on"); break;
        case KC_J: SEND_STRING(/*j*/"ust"); break;
        case KC_K: SEND_STRING(/*k*/"s"); break;
        case KC_L: SEND_STRING(/*l*/"k"); break;
        case KC_M: SEND_STRING(/*m*/"ent"); break;
        case KC_N: SEND_STRING(/*n*/"ion"); break;
        case KC_O: SEND_STRING(/*o*/"a"); break;
        case KC_P: SEND_STRING(/*p*/"y"); break;
        case KC_Q: SEND_STRING(/*q*/"ui"); break;
        case KC_R: SEND_STRING(/*r*/"l"); break;
        case KC_S: SEND_STRING(/*s*/"k"); break;
        case KC_T: SEND_STRING(/*t*/"ment"); break;
        case KC_U: SEND_STRING(/*u*/"e"); break;
        case KC_V: SEND_STRING(/*v*/"er"); break;
        case KC_W: SEND_STRING(/*w*/"hich"); break;
        case KC_X: SEND_STRING(/*x*/"es"); break;
        case KC_Y: SEND_STRING(/*y*/"p"); break;
        //case KC_Z: SEND_STRING(/*z*/""); break;
        case KC_COMM: SEND_STRING(/*,*/" but"); break;
        //case KC_DOT: SEND_STRING(/*.*/""); break;
        //case KC_QUOT: SEND_STRING(/*'*/""); break;
        case KC_SPC: SEND_STRING(/* */"the"); break;
        default:
            add_mods(prev_mods);
            tap_code16(prev_keycode);
            del_mods(prev_mods);
    }
}

static void process_rep_macro_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
    if (IS_QK_MOD_TAP(prev_keycode)) {
        prev_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    if (IS_QK_LAYER_TAP(prev_keycode)) {
        prev_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    switch (prev_keycode) {
        case KC_A: SEND_STRING(/*a*/"lready"); break;
        case KC_B: SEND_STRING(/*b*/"ecome"); break;
        case KC_C: SEND_STRING(/*c*/"ould"); break;
        case KC_D: SEND_STRING(/*d*/"evelop"); break;
        //case KC_E: SEND_STRING(/*e*/""); break;
        case KC_F: SEND_STRING(/*f*/"ollow"); break;
        case KC_G: SEND_STRING(/*g*/"eneral"); break;
        case KC_H: SEND_STRING(/*h*/"owever"); break;
        case KC_I: SEND_STRING(/*i*/"'ll"); break;
        case KC_J: SEND_STRING(/*j*/"udge"); break;
        case KC_K: SEND_STRING(/*k*/"now"); break;
        case KC_L: SEND_STRING(/*l*/"ittle"); break;
        case KC_M: SEND_STRING(/*m*/"ight"); break;
        case KC_N: SEND_STRING(/*n*/"eighbor"); break;
        case KC_O: SEND_STRING(/*o*/"ther"); break;
        case KC_P: SEND_STRING(/*p*/"sych"); break;
        //case KC_Q: SEND_STRING(/*q*/""); break;
        case KC_R: SEND_STRING(/*r*/"ight"); break;
        case KC_S: SEND_STRING(/*s*/"hould"); break;
        case KC_T: SEND_STRING(/*t*/"hough"); break;
        case KC_U: SEND_STRING(/*u*/"pgrade"); break;
        //case KC_V: SEND_STRING(/*v*/""); break;
        case KC_W: SEND_STRING(/*w*/"here"); break;
        //case KC_X: SEND_STRING(/*x*/""); break;
        //case KC_Y: SEND_STRING(/*y*/""); break;
        //case KC_Z: SEND_STRING(/*z*/""); break;
        case KC_COMM: SEND_STRING(/*,*/" however"); break;
        //case KC_DOT: SEND_STRING(/*.*/""); break;
        //case KC_QUOT: SEND_STRING(/*'*/""); break;
        case KC_SPC: SEND_STRING(/* */"the"); break;
        default:
            add_mods(prev_mods);
            tap_code16(prev_keycode);
            del_mods(prev_mods);
    }
}

static void process_altrep_macro_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
    if (IS_QK_MOD_TAP(prev_keycode)) {
        prev_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    if (IS_QK_LAYER_TAP(prev_keycode)) {
        prev_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(prev_keycode);
    }
    switch (prev_keycode) {
        case KC_A: SEND_STRING(/*a*/"bout"); break;
        case KC_B: SEND_STRING(/*b*/"etween"); break;
        case KC_C: SEND_STRING(/*c*/"rowd"); break;
        //case KC_D: SEND_STRING(/*d*/""); break;
        case KC_E: SEND_STRING(/*e*/"'re"); break;
        //case KC_F: SEND_STRING(/*f*/""); break;
        case KC_G: SEND_STRING(/*g*/"overn"); break;
        //case KC_H: SEND_STRING(/*h*/""); break;
        case KC_I: SEND_STRING(/*i*/"'m"); break;
        //case KC_J: SEND_STRING(/*j*/""); break;
        //case KC_K: SEND_STRING(/*k*/""); break;
        //case KC_L: SEND_STRING(/*l*/""); break;
        case KC_M: SEND_STRING(/*m*/"anage"); break;
        case KC_N: SEND_STRING(/*n*/"umber"); break;
        case KC_O: SEND_STRING(/*o*/"xygen"); break;
        case KC_P: SEND_STRING(/*p*/"rogram"); break;
        case KC_Q: SEND_STRING(/*q*/"uestion"); break;
        //case KC_R: SEND_STRING(/*r*/""); break;
        case KC_S: SEND_STRING(/*s*/"chool"); break;
        case KC_T: SEND_STRING(/*t*/"hrough"); break;
        case KC_U: SEND_STRING(/*u*/"pdate"); break;
        //case KC_V: SEND_STRING(/*v*/""); break;
        case KC_W: SEND_STRING(/*w*/"orld"); break;
        //case KC_X: SEND_STRING(/*x*/""); break;
        //case KC_Y: SEND_STRING(/*y*/""); break;
        //case KC_Z: SEND_STRING(/*z*/""); break;
        case KC_COMM: SEND_STRING(/*,*/" since"); break;
        //case KC_DOT: SEND_STRING(/*.*/""); break;
        //case KC_QUOT: SEND_STRING(/*'*/""); break;
        //case KC_SPC: SEND_STRING(/* */""); break;
        default:
            add_mods(prev_mods);
            tap_code16(prev_keycode);
            del_mods(prev_mods);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LT(U_NAV,KC_F23):
            if (record->event.pressed && record->tap.count) {
                uint8_t mods = get_mods();
                if ((mods & MOD_MASK_SHIFT) == 0) {
                    process_rep_macro_key(get_last_keycode(), get_last_mods());
                }
                else {
                    del_mods(MOD_MASK_SHIFT);
                    process_rep_macro_key_2(get_last_keycode(), get_last_mods());
                    set_mods(mods);
                }
                return false;
            }
            break;


        case KC_F24:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                if ((mods & MOD_MASK_SHIFT) == 0) {
                    process_altrep_macro_key(get_last_keycode(), get_last_mods());
                }
                else {
                    del_mods(MOD_MASK_SHIFT);
                    process_altrep_macro_key_2(get_last_keycode(), get_last_mods());
                    set_mods(mods);
                }
                return false;
            }
            break;
    }
    return true;
}
