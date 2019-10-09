// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _FUNC 1
#define _RESET 2


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
    SFT_T(KC_BSPC),KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                        KC_K,     KC_N,     KC_E,    KC_I,    KC_O,    RSFT_T(KC_BSPC),
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,                        KC_M,     KC_H,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL,       KC_LGUI, KC_LALT, KC_APP,  KC_BSPC,  MO(_FUNC), KC_SPC,  KC_SPC,  MO(_FUNC),KC_BSPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
  ),

  [_FUNC] = LAYOUT(
    _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, TO(_RESET),
    KC_CAPS,    KC_F11,  KC_F12,  _______, _______, _______,                     KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,
    _______,    KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL,                      KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_MUTE,
    _______,    KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_PLUS,                     _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, KC_MPLY ,
    _______,    _______, _______, _______, _______, _______, _______,  _______,  _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT 
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