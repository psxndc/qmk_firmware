#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_arrow( /* Qwerty */
    KC_ESC,        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPC,
    CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_ENT,
    SFT_T(KC_Z),  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL,        KC_LGUI, MO(_L2),     KC_SPC,          KC_SPC,          MO(_L1),     KC_RALT, KC_RGUI,      KC_RCTL
  ),
  [_CM] = LAYOUT_arrow ( /* Colemak */
    KC_ESC,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,   KC_BSPC,
    CTL_T(KC_BSPC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,     KC_SCLN,
    SFT_T(KC_Z),   KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL,        KC_LGUI, MO(_L2),     KC_SPC,          KC_SPC,          MO(_L1),     KC_RALT, KC_RGUI,      KC_RCTL
  ),
  
   [_L1] = LAYOUT_arrow( /* LAYER 1 */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_DEL,
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          _______,
    _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MUTE, KC_MPLY,      _______,
    _______, _______, MO(_L3),           _______,         _______,           _______, _______, _______,       _______
  ),
  [_L2] = LAYOUT_arrow( /* LAYER 2 */
    KC_GRV,  _______, _______, _______, _______, _______, KC_PSCR, KC_P7,    KC_P8,    KC_P9,    KC_P0,         KC_DEL,
    KC_TAB,   _______, _______, _______, _______, _______, KC_NLCK, KC_P4,    KC_P5,    KC_P6,    _______,     _______,
    _______,   _______, _______, _______, _______, _______, _______, KC_P1,    KC_P2,    KC_P3,    _______,    _______,
    _______,  _______, _______,          _______,          _______,          MO(_L3), _______, _______,        _______
  ),

  
  [_L3] = LAYOUT_arrow( /* LAYER 3 */
    _______, QWERTY,  COLEMAK, _______, _______, _______, _______, _______,  _______,_______, _______,          RESET,
    _______,  _______, _______, _______, _______, _______, _______, _______,  _______,_______, _______,       _______,
    _______,   _______, _______, _______, _______, _______, _______, _______,  _______,_______, _______,      _______,
    _______, _______, _______,           _______,        _______,           _______, _______,_______,         _______
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          return false;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_CM);
          }
          return false;
        default:
          return true;
      }
    return true;
};
