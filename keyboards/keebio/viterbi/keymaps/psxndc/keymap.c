#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAKDH 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  COLEMAKDH = SAFE_RANGE,
  LOWER,
  RAISE,
  QWERTY,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* COLEMAKDH
 * ,------------------------------------------------.   	 ,------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  | Home |        | PgUp |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------|    	 |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  | End  |        | PgDn |   J  |   L  |   U  |   Y  |   '  |   ;  | 
 * |------+------+------+------+------+------+------|    	 |------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   G  |  -   |        |   [  |   K  |   N  |   E  |   I  |   O  | Bksp |
 * |------+------+------+------+------+------+------|    	 |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |  +   |        |   ]  |   M  |   H  |   ,  |   .  |   /  | Enter| 
 * |------+------+------+------+------+------+------|    	 |------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |  APP | Lower|    Space    |     	 |    Space    | Raise| Left | Down | Up   | Right|
 * `------------------------------------------------'     	 `------------------------------------------------'
 */
  [_COLEMAKDH] = LAYOUT_ortho_5x14(
    KC_ESC,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5  ,  KC_HOME,   KC_PGUP, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL, 
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B  ,  KC_END,    KC_PGDN, KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_SCLN, 
    KC_BSPC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G  ,  KC_MINS,   KC_LBRC, KC_K   , KC_N   , KC_E   , KC_I  ,  KC_O,    KC_BSPC,  
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V  ,  KC_PLUS,   KC_RBRC, KC_M   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,   
    KC_LCTL, KC_LGUI, KC_LALT, KC_APP , LOWER  , KC_SPC,  KC_SPC ,   KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN ,KC_UP,   KC_RGHT 
  ),


/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Esc |  `   |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   [  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   -  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Bksp |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   '  | Home |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |  Up  | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Adjst| Ctrl |  OS  | Alt  |Lower |   Space     |      |    Space    |Raise | RAlt | Left | Down | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    _______,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,  _______ ,   _______ ,KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, 
    _______,  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,  _______ ,   _______ ,KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUOT, 
    _______,  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,  _______ ,   _______ ,KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______, 
    _______,  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  _______ ,   _______ ,KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______, 
    _______,  _______, _______, _______, _______, _______,  _______ ,   _______ ,_______, _______, _______, _______, _______, _______ 
  ),


/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   ]  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |  _   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |   }  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      | Play | Vol+ | Mute |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |    BKSPC    |      |     BKSPC   |      |      | Prev | Vol- | Next |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, _______, _______,     _______, KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PIPE, 
    _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, _______,     _______, KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_MUTE, 
    _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______,     _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, KC_MPLY, 
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC,     KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    COLEMAKDH, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,
    QWERTY,  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, BL_STEP, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAKDH);
      }
      return false;
      break;
	case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
