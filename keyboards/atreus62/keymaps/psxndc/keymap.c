// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _FUNC 1
#define _NAV 2
#define _RESET 3


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
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_LBRC,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RBRC ,
    KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                        KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT ,
    KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,                        KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC ,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_GRV,  TT(_FUNC),KC_SPC,  KC_BSPC,  KC_ENT,   KC_SPC,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_END
  ),

  [_FUNC] = LAYOUT(
    TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL  ,
    TO(_RESET),    _______, _______, _______, _______, _______,                     KC_F12,  _______, _______, _______, _______, KC_RBRC ,
    KC_CAPS,       _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_GRV ,
    _______,       _______, _______, _______, _______, _______,                     _______, _______, _______, _______, KC_BSLS, _______ ,
    _______,       _______, _______, _______, _______, _______, KC_DELT,  _______,  _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_HOME
  ),

/*
 KC_BTN1,  KC_MS_U,   KC_BTN2, 
 KC_MS_L,  KC_MS_D,   KC_MS_R),*/


  [_NAV] = LAYOUT(
    TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    _______,       _______, _______, _______, _______, _______,                     KC_F12,  _______, KC_UP,   _______, _______, _______ ,
    _______,       _______, _______, _______, _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______ ,
    TO(_RESET),    _______, _______, _______, _______, _______,                     _______, _______, KC_BTN1, KC_BTN2, _______, _______ ,
    _______,       _______, _______, _______, _______, _______, _______,  _______,  _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______
  ),




  [_RESET] = LAYOUT(
    TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET
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