// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LWR 1
#define _RAS 2
#define _WRD 3
#define _RESET 4

//#define CS_FUNC LM(_FUNC, MOD_LCTL | MOD_LSFT)
//#define CA_FUNC LM(_FUNC, MOD_LCTL | MOD_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
  [_DEFAULT] = LAYOUT( qwerty 
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC ,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC ,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_GRV,  MO(_NAV),KC_BSPC, KC_DELT,  KC_ENT,   KC_SPC,  KC_EQL,  KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI
  ),
*/

/* COLEMAKDH  */
[_DEFAULT] = LAYOUT( 
    KC_GESC,       KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                        KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_DELT ,
    KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                        KC_J,     KC_L,     KC_U,    KC_Y,    KC_QUOT, KC_SCLN ,
   LCTL_T(KC_BSPC),KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                        KC_K,     KC_N,     KC_E,    KC_I,    KC_O,    RALT_T(KC_SCLN),
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,                        KC_M,     KC_H,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL,       KC_LGUI, KC_LALT, KC_APP,  MO(_WRD), MO(_LWR), KC_SPC,  KC_SPC,  MO(_RAS),  MO(_WRD), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
  ),

  [_LWR] = LAYOUT(
    _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
    KC_CAPS,    KC_F11,  KC_F12,  _______, _______, _______,                     KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_DEL, \
    _______,    KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL,                      KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE, \
    _______,    KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_PLUS,                     _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, \
    _______,    _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
  ),

  [_RAS] = LAYOUT(
   _______, _______, _______, _______, _______, _______, 						_______, _______, _______, _______, _______, TO(_RESET), \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   						KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   							KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, 						KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_MUTE, KC_MPLY, \
  _______, _______, _______, _______, _______, _______,    _______, _______,    _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
  ),

 [_WRD] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,							_______, _______      , _______   , _______      , _______, _______, \
  _______, _______, _______, _______, _______, _______,							_______, KC_P7        , S(KC_UP)  , KC_P9        , _______, _______, \
  _______, _______, _______, _______, _______, _______,							_______, C(S(KC_LEFT)), KC_P5     , C(S(KC_RGHT)), _______, _______, \
  _______, _______, _______, _______, _______, _______,							_______, KC_P1        , S(KC_DOWN), KC_P3        , _______, _______, \
  _______, _______, _______, _______, _______, _______,	  _______, _______,		_______, _______      , _______   , _______      , _______, _______  \
 ),
 
 [_RESET] = LAYOUT(
    TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
  )

  /*
  [_TRNS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
  */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};