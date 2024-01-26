#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define COMBO_TERM 200
#define EXTRA_SHORT_COMBOS

#define MIRYOKU_LAYER_BASE \
KC_V,              KC_M,              KC_L,              KC_C,              KC_P,              KC_B,              KC_F24,            KC_U,              KC_O,              KC_Q,              \
LGUI_T(KC_S),      LALT_T(KC_T),      LCTL_T(KC_R),      LSFT_T(KC_D),      KC_Y,              KC_F,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_A),      LGUI_T(KC_I),      \
LT(U_BUTTON,KC_X), ALGR_T(KC_K),      KC_J,              KC_G,              KC_W,              KC_Z,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_QUOT),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_F23),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_BSPC), LT(U_NUM,KC_SPC),  LT(U_FUN,KC_ENT),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
UK_PLUS,           KC_4,              KC_5,              KC_6,              UC(0xD7),          U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_MINS,           KC_1,              KC_2,              KC_3,              UC(0xF7),          U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UK_COLN,           KC_7,              KC_8,              KC_9,              UK_CIRC,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_EQL,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_CAPS,           KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_DEL,            KC_SPC,            KC_ENT,            U_NP,              U_NP

#define MIRYOKU_LAYER_SYM \
UK_PND,            UK_PERC,           KC_LBRC,           KC_RBRC,           KC_GRV,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UK_TILD,           UK_DQUO,           UK_LPRN,           UK_RPRN,           UK_ASTR,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UK_PIPE,           UK_AMPR,           KC_SLSH,           UK_BSLS,           KC_SCLN,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              UK_HASH,           UK_AT,             UK_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_INS,            KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              KC_SCRL,           KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
UC(0x1FD7),        UC(0x00B0),        UC(0x00B2),        UC(0x00B3),        UC(0x221E),        U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UC(0x2013),        UC(0x00B7),        UC(0x2661),        UC(0x2022),        UC(0x2260),        U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UC(0x2190),        UC(0x2193),        UC(0x2191),        UC(0x2192),        UC(0x03C9),        U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              UC(0x2717),        UC(0x2713),        UC(0x2248),        U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_PSCR,           KC_WBAK,           KC_BRID,           KC_BRIU,           KC_WFWD,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_APP,            KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              KC_PAUS,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
KC_V,              KC_M,              KC_L,              KC_C,              KC_P,              KC_B,              QK_AREP,           KC_U,              KC_O,              KC_Q,              \
KC_A,              KC_S,              KC_W,              KC_D,              KC_SPC,            TD(U_TD_U_BASE),   KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
LT(U_BUTTON,KC_X), ALGR_T(KC_K),      KC_J,              KC_G,              KC_W,              KC_Z,              KC_X,              KC_COMM,           KC_DOT,            KC_QUOT,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              KC_ESC,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             KC_TAB,            KC_SPC,            KC_WH_D,           KC_WH_U,           U_NA,             \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
