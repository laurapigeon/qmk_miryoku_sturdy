#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define COMBO_TERM 200
#define EXTRA_SHORT_COMBOS

#define MIRYOKU_LAYER_BASE \
KC_V,              KC_M,              KC_L,              KC_C,              KC_P,              KC_B,              KC_F24,            KC_U,              KC_O,              KC_Q,              \
LGUI_T(KC_S),      LALT_T(KC_T),      LCTL_T(KC_R),      LSFT_T(KC_D),      KC_Y,              KC_F,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_A),      LGUI_T(KC_I),      \
LT(U_BUTTON,KC_X), ALGR_T(KC_K),      KC_J,              KC_G,              KC_W,              KC_Z,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_QUOT),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_F23),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_BSPC), LT(U_NUM,KC_SPC),  LT(U_FUN,KC_ENT),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
UC(0xD7),          KC_4,              KC_5,              KC_6,              UC(0xF7),          U_NA,              U_NA,              TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UK_PLUS,           KC_1,              KC_2,              KC_3,              KC_MINS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UK_CIRC,           KC_7,              KC_8,              KC_9,              TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           TD(U_TD_U_BUTTON), \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_EQL,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  U_NA,              U_NA,              U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
TD(U_TD_U_BUTTON), KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_DEL,            KC_SPC,            KC_ENT,            U_NP,              U_NP

#define MIRYOKU_LAYER_SYM \
UK_ASTR,           UK_GRV,            KC_LBRC,           KC_RBRC,           KC_PIPE,           U_NA,              U_NA,              TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UK_SCLN,           UK_COLN,           UK_LPRN,           UK_RPRN,           UK_TILD,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_PERC,           UK_AMPR,           KC_SLSH,           UK_BSLS,           TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           TD(U_TD_U_BUTTON), \
U_NP,              U_NP,              UK_HASH,           UK_AT,             UK_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  U_NA,              U_NA,              U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_INS,            KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
TD(U_TD_U_BUTTON), KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   KC_SCRL,           KC_WH_D,           KC_WH_U,           KC_PAUS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
UK_PND,            UK_DLR,            KC_LCBR,           KC_RCBR,           UC(0x2661),        U_NA,              U_NA,              TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UC(0x00B7),        UC(0x2022),        KC_LABK,           KC_RABK,           UC(0x2013),        U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UC(0x2042),        UC(0x203D),        UC(0x00AB),        UC(0x00BB),        TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           TD(U_TD_U_BUTTON), \
U_NP,              U_NP,              UC(0x2717),        UC(0x2713),        UC(0x2248),        U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  U_NA,              U_NA,              KC_PSCR,           KC_WBAK,           KC_BRID,           KC_BRIU,           KC_WFWD,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_APP,            KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
TD(U_TD_U_BUTTON), KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   UC(0x2E2E),        UC(0x055E),        UC(0x055C),        UC(0x00A1),        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
KC_V,              KC_M,              KC_L,              KC_C,              KC_P,              KC_B,              QK_AREP,           KC_U,              KC_O,              KC_Q,              \
KC_A,              KC_S,              KC_W,              KC_D,              KC_SPC,            U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
LT(U_BUTTON,KC_X), ALGR_T(KC_K),      KC_J,              KC_G,              TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   KC_X,              KC_COMM,           KC_DOT,            KC_QUOT,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_X,              KC_Z,              KC_X,              U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA \
KC_V,              KC_M,              KC_L,              KC_C,              KC_P,              KC_B,              QK_AREP,           KC_U,              KC_O,              KC_Q,              \
KC_A,              KC_S,              KC_W,              KC_D,              KC_SPC,            U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
LT(U_BUTTON,KC_X), ALGR_T(KC_K),      KC_J,              KC_G,              TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   KC_X,              KC_COMM,           KC_DOT,            KC_QUOT,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_PST,             U_UND,             U_CPY,             U_CUT,             U_RDO,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              KC_ESC,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             TD(U_TD_U_BASE),   TD(U_TD_U_BASE),   KC_SPC,            KC_WH_D,           KC_WH_U,           U_NA,              \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
