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

enum custom_keycodes {
  C_MAG_2 = SAFE_RANGE,
  C_MAG_3,
  MK_DUND,
  MG_ENT,
  MG_MENT,
  MG_ER,
  MG_ES,
  MG_UST,
  MG_ON,
  MG_ION,
  MG_SP_BUT,
  MG_THE,
  MG_EFORE,
  MG_HICH,
  MG_UI,
  MG_QUOT_S,
};

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        // Ignore Custom Magic Keys
        case C_MAG_2:
        case C_MAG_3:
            return false;
        case UK_A ... UK_Z:
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;
    }

    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case LALT_T(UK_A): return UK_O;
        case UK_B: return MG_EFORE;
        case UK_C: return UK_Y;
        case LSFT_T(UK_D): return UK_Y;
        case LCTL_T(UK_E): return UK_U;
        case UK_G: return UK_Y;
        case LGUI_T(UK_I): return MG_ON;
        case UK_J: return MG_UST;
        case ALGR_T(UK_K): return UK_S;
        case UK_L: return UK_S;
        case UK_M: return MG_ENT;
        case LSFT_T(UK_N): return MG_ION;
        case UK_O: return UK_A;
        case UK_P: return UK_Y;
        case UK_Q: return MG_UI;
        case LCTL_T(UK_R): return UK_L;
        case LGUI_T(UK_S): return UK_K;
        case LALT_T(UK_T): return MG_MENT;
        case UK_U: return UK_E;
        case UK_V: return MG_ER;
        case UK_W: return MG_HICH;
        case LT(U_BUTTON,UK_X): return MG_ES;
        case UK_Y: return UK_P;
        case UK_COMM:
            if (mods & MOD_MASK_SHIFT) {
                return UK_EQL;
            } else {
                return MG_SP_BUT;
            }
        case ALGR_T(UK_DOT):
            if (mods & MOD_MASK_SHIFT) {
                return UK_EQL;
            } else {
                return UK_BSLS;
            }
    }

    return MG_THE;
}

bool process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case UK_B:
            SEND_STRING("ecome");
            return false;
        case UK_F:
            SEND_STRING("ollow");
            return false;
        case LSFT_T(UK_N):
            SEND_STRING("eighbor");
            return false;
        case UK_H:
            SEND_STRING("owever");
            return false;
        case UK_U:
            SEND_STRING("pgrade");
            return false;
        case UK_O:
            SEND_STRING("ther");
            return false;
        case LALT_T(UK_A):
            SEND_STRING("lready");
            return false;
        case UK_P:
            SEND_STRING("sych");
            return false;
        case LGUI_T(UK_I):
            SEND_STRING("'ll");
            return false;
        case ALGR_T(UK_K):
            SEND_STRING("now");
            return false;
        case LALT_T(UK_T):
            SEND_STRING("hough");
            return false;
        case UK_L:
            SEND_STRING("ittle");
            return false;
        case UK_M:
        case LCTL_T(UK_R):
            SEND_STRING("ight");
            return false;
        case UK_J:
            SEND_STRING("udge");
            return false;
        case UK_C:
            SEND_STRING("ould");
            return false;
        case LSFT_T(UK_D):
            SEND_STRING("evelop");
            return false;
        case UK_G:
            SEND_STRING("eneral");
            return false;
        case UK_W:
            SEND_STRING("here");
            return false;
        case LGUI_T(UK_S):
            SEND_STRING("hould");
            return false;
        case ALGR_T(UK_DOT):
            SEND_STRING("org");
            return false;
        case UK_COMM:
            SEND_STRING(" however");
            return false;
        default:
            SEND_STRING("'ll");
            return false;
    }
}

bool process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case UK_B:
            SEND_STRING("etween");
            return false;
        case LSFT_T(UK_N):
            SEND_STRING("umber");
            return false;
        case UK_U:
            SEND_STRING("pdate");
            return false;
        case LALT_T(UK_A):
            SEND_STRING("bout");
            return false;
        case UK_W:
            SEND_STRING("orld");
            return false;
        case UK_G:
            SEND_STRING("overn");
            return false;
        case UK_P:
            SEND_STRING("rogram");
            return false;
        case UK_Q:
            SEND_STRING("uestion");
            return false;
        case UK_C:
            SEND_STRING("rowd");
            return false;
        case LGUI_T(UK_S):
            SEND_STRING("chool");
            return false;
        case LALT_T(UK_T):
            SEND_STRING("hrough");
            return false;
        case UK_M:
            SEND_STRING("anage");
            return false;
        case UK_O:
            SEND_STRING("xygen");
            return false;
        case LGUI_T(UK_I):
            SEND_STRING("'m");
            return false;
        case LCTL_T(UK_E):
            SEND_STRING("'re");
            return false;
        case ALGR_T(UK_DOT):
            SEND_STRING("com");
            return false;
        case UK_COMM:
            SEND_STRING(" since");
            return false;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        int rep_count = get_repeat_key_count();
        if (rep_count < -1 && keycode != MG_UST) {
            send_char('n');
            return false;
        }
        switch (keycode) {
            case C_MAG_2:
                //return process_magic_key_2(get_repeat_key_keycode(), get_repeat_key_mods());
            case C_MAG_3:
                //return process_magic_key_3(get_repeat_key_keycode(), get_repeat_key_mods());
            case MK_DUND:
                SEND_STRING(SS_LSFT(SS_TAP(X_4)) SS_DELAY(100) SS_LSFT(SS_TAP(X_MINUS)));
                return false;
            case MG_ENT:
                SEND_STRING("ent");
                return false;
            case MG_MENT:
                SEND_STRING("ment");
                return false;
            case MG_ER:
                SEND_STRING("er");
                return false;
            case MG_ES:
                SEND_STRING("es");
                return false;
            case MG_UST:
                if (rep_count < -1) {
                    SEND_STRING("ment");
                } else {
                    SEND_STRING("ust");
                }
                return false;
            case MG_ON:
                SEND_STRING("on");
                return false;
            case MG_ION:
                SEND_STRING("ion");
                return false;
            case MG_SP_BUT:
                SEND_STRING(" but");
                return false;
            case MG_THE:
                SEND_STRING("the");
                return false;
            case MG_EFORE:
                SEND_STRING("efore");
                return false;
            case MG_HICH:
                SEND_STRING("hich");
                return false;
            case MG_UI:
                SEND_STRING("ui");
                return false;
            case MG_QUOT_S:
                SEND_STRING("'s");
                return false;
        }

        if (rep_count > 0) {
            switch (keycode) {
                case KC_BSPC:
                case C_LCTL_BSPC:
                case UK_DQUO:
                case UK_LPRN:
                case KC_SPC:
                case KC_ENT:
                case C_LALT_ENT:
                case C_RSFT_ENT:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("for");
                    return false;
                case LGUI_T(UK_I):
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ng");
                    return false;
                case ALGR_T(UK_DOT):
                case UK_QUES:
                case UK_EXLM:
                case UK_COLN:
                case UK_SCLN:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char(' ');
                    add_oneshot_mods(MOD_MASK_SHIFT);
                    //set_repeat_key_keycode(KC_SPC);
                    return false;
                case UK_COMM:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING(" and");
                    return false;
                case LALT_T(UK_A):
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("nd");
                    return false;
                case LSFT_T(UK_N):
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char('f');
                    return false;
                case UK_B:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ecause");
                    return false;
                case UK_W:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ould");
                    return false;
                case UK_Y:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    if (rep_count > 2) {
                        SEND_STRING("ll");
                        return false;
                    }
                    if (rep_count > 1) {
                        send_char('\'');
                        return false;
                    }
                    SEND_STRING("ou");
                    return false;
                case UK_Q:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ue");
                    return false;
            }
        }
    }
    return true;
}