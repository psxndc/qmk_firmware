#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 3
#define _RAISE 4
#define _WRD 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  WORD,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_ESC,  	KC_1,    		KC_2,        KC_3,   	  KC_4, 	   KC_5,    KC_6,   	KC_7,  		 KC_8,   	  KC_9,    		KC_0,   	 KC_DEL, \
  KC_TAB,   KC_Q,    		KC_W,   	 KC_F,    	  KC_P,    	   KC_B,    KC_J,   	KC_L,  		 KC_U,    	  KC_Y,		    KC_QUOT, 	 KC_BSPC, \
  KC_DEL,	KC_A,   		LALT_T(KC_R),LSFT_T(KC_S),LCTL_T(KC_T),KC_G,    KC_K,   	RCTL_T(KC_N),RSFT_T(KC_E),RALT_T(KC_I), KC_O,		 KC_SCLN, \
  KC_LSFT, 	KC_Z,    		KC_X, 		 KC_C,    	  KC_D,    	   KC_V,    KC_M,   	KC_H,  		 KC_COMM,	  KC_DOT,  		KC_SLSH, 	 KC_ENT,  \
  KC_LCTL, 	KC_LGUI, 		KC_LALT, 	 MO(_WRD),    LOWER,   	   KC_SPC, 	KC_SPC,		RAISE,		 KC_LEFT, 	  KC_DOWN, 		KC_UP,   	 KC_RGHT   \
),



/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT ( \
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_CAPS, KC_F11,  KC_F12,  _______, _______, _______, KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, \
  KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE, \
  _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
 ),
 
 /* Useful commands for MS Word
 * ,---------------------------------------------------------------------------------------------------------.
 * |      |  1   |  2   |   3  |  4   |  5   |  6   |   7            |    8    |   9           |  0   |      |
 * |------+------+------+------+------+-------------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Num7           | Shft+Up | Num9          |      |      |
 * |------+------+------+------+------+-------------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Ctrl+Shft+left |  Num5   | Ctrl+Shft+rght|      |      |
 * |------+------+------+------+------+------|------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Num1           | Shft+Dn | Num3          |      |      |
 * |------+------+------+------+------+------+------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |             |                |         |               |      |      |
 * `---------------------------------------------------------------------------------------------------------'
 */
 [_WRD] = LAYOUT ( \
/*,-----------------------------------------------------------------------------------------------------------------------.
 *|      |   1   |     2   |   3    |   4    |   5    |   6   |   7          |     8     |    9         |   0    |        |*/ 
  _______, _______, _______, _______, _______, _______,_______, _______      , _______   , _______      , _______, _______, \
  _______, _______, _______, _______, _______, _______,_______, KC_P7        , S(KC_UP)  , KC_P9        , _______, _______, \
  _______, _______, _______, _______, KC_LGUI, _______,_______, C(S(KC_LEFT)), KC_P5     , C(S(KC_RGHT)), _______, _______, \
  _______, _______, _______, _______, _______, _______,_______, KC_P1        , S(KC_DOWN), KC_P3        , _______, _______, \
  _______, _______, _______, _______, _______, _______,_______, _______      , _______   , _______      , _______, _______  \
 ),
 
 
 

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  1   |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  :   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      | Mute | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT ( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_MUTE, KC_MPLY, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT ( \
/*,-------------------------------------------------------------------------------------------------------.
* |  esc  |   1   |    2    |   3   |   4   |   5    |    6    |   7   |    8    |   9   |   0    |   Del |
* |-------+-------+---------+-------+-------+--------+---------+-------+---------+-------+--------+-------| */
  _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, EEP_RST, RESET,    \
  _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, DEBUG,    \
  _______, _______, _______, AU_ON  , AU_OFF, _______, _______, QWERTY,  COLEMAK, _______, _______, _______, \
  _______, _______, _______, _______,_______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD , \
  _______, _______, _______, _______,_______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG   \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
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
