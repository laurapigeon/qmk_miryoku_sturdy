#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define MIRYOKU_LAYER_BASE \
UK_V,              UK_M,              UK_L,              UK_C,              UK_P,              UK_B,              QK_REP,            UK_U,              UK_O,              UK_Q,              \
LGUI_T(UK_S),      LALT_T(UK_T),      LCTL_T(UK_R),      LSFT_T(UK_D),      UK_Y,              UK_F,              LSFT_T(UK_N),      LCTL_T(UK_E),      LALT_T(UK_A),      LGUI_T(UK_I),      \
LT(U_BUTTON,UK_X), ALGR_T(UK_K),      UK_J,              UK_G,              UK_W,              UK_Z,              UK_H,              UK_COMM,           ALGR_T(UK_DOT),    LT(U_BUTTON,UK_QUOT),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,QK_REP),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_BSPC), LT(U_NUM,KC_SPC),  LT(U_FUN,KC_ENT),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
UK_PLUS,           UK_4,              UK_5,              UK_6,              UC(0xD7),          U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UK_MINS,           UK_1,              UK_2,              UK_3,              UC(0xF7),          U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UK_PERC,           UK_7,              UK_8,              UK_9,              UK_CIRC,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
U_NP,              U_NP,              UK_DOT,            UK_0,              UK_EQL,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP

#define MIRYOKU_LAYER_SYM \
UK_PND,            UK_SLSH,           UK_LCBR,           UK_RCBR,           UK_GRV,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UK_SCLN,           UK_DQUO,           UK_LPRN,           UK_RPRN,           UK_ASTR,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UK_PIPE,           UK_AMPR,           UK_LBRC,           UK_RBRC,           UK_TILD,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              UK_HASH,           UK_AT,             UK_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_CAPS,           KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            QK_REP,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
UK_A,              UK_Z,              UK_E,              UK_R,              UK_T,              UK_Y,              UK_U,              UK_I,              UK_O,              UK_P,              \
UK_Q,              UK_S,              UK_D,              UK_F,              UK_G,              UK_H,              UK_J,              UK_K,              UK_L,              UK_M,              \
UK_W,              UK_X,              UK_C,              UK_V,              UK_B,              UK_N,              UK_COMM,           UK_DOT,            UK_SLSH,           UK_QUOT,           \
U_NP,              U_NP,              TD(U_TD_U_BASE),   QK_REP,            KC_LSFT,           KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP
