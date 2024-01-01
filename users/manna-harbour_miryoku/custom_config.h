#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define MIRYOKU_LAYER_BASE \
UK_V,              UK_M,              UK_L,              UK_C,              UK_P,              UK_B,              QK_AREP,           UK_U,              UK_O,              UK_Q,              \
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
UC(0x1FD7),        UC(0x00B0),        UC(0x00B2),        UC(0x00B3),        UC(0x221E),        U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
UC(0x2013),        UC(0x00B7),        UC(0x2665),        UC(0x2022),        UC(0x2260),        U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
UC(0x2190),        UC(0x2193),        UC(0x2191),        UC(0x2192),        UC(0x03C9),        U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              UC(0x2717),        UC(0x2713),        UC(0x2248),        U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_PSCR,           KC_APP,            U_NU,              U_NU,              U_NU,              \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_SCRL,           KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              KC_PAUS,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
UK_V,              UK_M,              UK_L,              UK_C,              UK_P,              UK_B,              QK_AREP,            UK_U,              UK_O,              UK_Q,              \
LGUI_T(UK_S),      LALT_T(UK_T),      LCTL_T(UK_R),      LSFT_T(UK_D),      UK_Y,              UK_F,              LSFT_T(UK_N),      LCTL_T(UK_E),      LALT_T(UK_A),      LGUI_T(UK_I),      \
LT(U_BUTTON,UK_X), ALGR_T(UK_K),      UK_J,              UK_G,              UK_W,              UK_Z,              UK_H,              UK_COMM,           ALGR_T(UK_DOT),    LT(U_BUTTON,UK_QUOT),\
U_NP,              U_NP,              TD(U_TD_U_BASE),   QK_REP,            KC_TAB,            KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP
