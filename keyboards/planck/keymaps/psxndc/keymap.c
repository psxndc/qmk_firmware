/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under thpi
 e terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WRD,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
 };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_WRD),LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  cf  Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_1x2uC(
  KC_TAB,   KC_Q,    		KC_W,   	 KC_F,    	  KC_P,    	   KC_B,    KC_J,   	KC_L,  		 KC_U,    	  KC_Y,		    KC_QUOT, 	 KC_BSPC, \
  KC_DEL,	KC_A,   		LALT_T(KC_R),LSFT_T(KC_S),LCTL_T(KC_T),KC_G,    KC_K,   	RCTL_T(KC_N),RSFT_T(KC_E),RALT_T(KC_I), KC_O,		 KC_SCLN, \
  KC_LSFT, 	KC_Z,    		KC_X, 		 KC_C,    	  KC_D,    	   KC_V,    KC_M,   	KC_H,  		 KC_COMM,	  KC_DOT,  		KC_SLSH, 	 KC_ENT,  \
  KC_LCTL, 	KC_LGUI, 		KC_LALT, 	 MO(_WRD),    LOWER,   	  	 	KC_SPC,		    RAISE,		 KC_LEFT, 	  KC_DOWN, 		KC_UP,   	 KC_RGHT   \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_1x2uC(
  KC_CAPS, KC_F11,  KC_F12,  _______, _______, _______, KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, \
  KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE, \
  _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, \
  _______, _______, _______, _______, _______, 	   _______, 	 _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_1x2uC(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_MUTE, KC_MPLY, \
  _______, _______, _______, _______, _______, 	 _______, 		 _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_1x2uC(
  _______, _______, _______, _______,_______, _______, _______, TERM_ON, TERM_OFF,_______, EEP_RST, RESET ,    \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF, _______, _______, QWERTY,  COLEMAK, _______, _______, DEBUG, \
  _______, MUV_DE,  MUV_IN,  _______, _______, MI_ON,   MI_OFF, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD , \
  _______, _______, _______, _______,_______,     _______,  	_______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG   \
),

 /* Useful commands for MS Word
 * ,---------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |                |         |               |      |      |
 * |------+------+------+------+------+-------------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Num7           | Shft+Up | Num9          |      |      |
 * |------+------+------+------+------+-------------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Ctrl+Shft+left |  Num5   | Ctrl+Shft+rght|      |      |
 * |------+------+------+------+------+------|------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |      |      | Num1           | Shft+Dn | Num3          |      |      |
 * |------+------+------+------+------+------+------+----------------+---------+---------------+------+------|
 * |      |      |      |      |      |             |                |         |               |      |      |
 * `---------------------------------------------------------------------------------------------------------'
 
 [_WRD] = LAYOUT_planck_grid( \
  _______, _______, _______, _______, _______, _______,_______, KC_P7        , S(KC_UP)  , KC_P9        , C(KC_F7), _______, \
  _______, _______, _______, _______, KC_LGUI, _______,_______, C(S(KC_LEFT)), KC_P5     , C(S(KC_RGHT)), C(KC_1), _______, \
  _______, _______, _______, _______, _______, _______,_______, KC_P1        , S(KC_DOWN), KC_P3        , C(KC_2), _______, \
  _______, _______, _______, _______, _______,   	,_______, 	_______      , _______   , _______      , _______, _______  \
 ),
 */
  [_WRD] = LAYOUT_planck_1x2uC ( \
/*,-----------------------------------------------------------------------------------------------------------------------.
 *|      |   1   |     2   |   3    |   4    |   5    |   6   |   7          |     8     |    9         |   0    |        |*/ 
  _______, _______, _______, _______, _______, _______,_______, KC_P7        , S(KC_UP)  , KC_P9        , _______, _______, \
  _______, _______, _______, _______, KC_LGUI, _______,_______, C(S(KC_LEFT)), KC_P5     , C(S(KC_RGHT)), _______, _______, \
  _______, _______, _______, _______, _______, _______,_______, KC_P1        , S(KC_DOWN), KC_P3        , _______, _______, \
  _______, _______, _______, _______, _______, 	   _______, 	_______      , _______   , _______      , _______, _______  \
 ),



};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        //print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {

                layer_on(_ADJUST);
            } else {

                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
