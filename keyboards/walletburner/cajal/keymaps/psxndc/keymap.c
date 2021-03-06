/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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

#define LOWER MO(1)
#define RAISE MO(2)
#define ADJUST MO(3)
#define WORD MO(4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho(
        KC_TAB,   KC_Q,    		KC_W,   	 KC_F,    	  KC_P,    	   KC_B,    KC_J,   	KC_L,  		 KC_U,    	  KC_Y,		    KC_QUOT, 	 KC_BSPC,  KC_DEL, RGB_TOG,
        KC_DEL,	  KC_A,   		LALT_T(KC_R),LSFT_T(KC_S),LCTL_T(KC_T),KC_G,    KC_K,   	RCTL_T(KC_N),RSFT_T(KC_E),RALT_T(KC_I), KC_O,		 KC_SCLN,  KC_INS,
        KC_LSFT,  KC_Z,    		KC_X, 		 KC_C,    	  KC_D,    	   KC_V,    KC_M,   	KC_H,  		 KC_COMM,	  KC_DOT,  		KC_SLSH, 	 KC_ENT,   KC_UP,
        KC_LCTL,  KC_LGUI, 		KC_LALT, 	 WORD, 		  LOWER,   	   KC_SPC, 	KC_SPC,		RAISE,		 KC_RALT, 	  KC_RGUI, 		KC_RCTL,     KC_LEFT,  KC_DOWN, KC_RGHT 
	),
//LOWER
    [1] = LAYOUT_ortho(
        KC_CAPS, KC_F11,  KC_F12,  _______, _______, _______, KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,  _______, RGB_MOD,
        KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE,  _______,
        _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______,  KC_PGUP,
        _______, _______, _______, _______, _______,  _______,_______, ADJUST,_______,  _______, _______,  KC_HOME,  KC_PGDN, KC_END
    ),
//RAISE
    [2] = LAYOUT_ortho(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,
		KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN, _______,
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_MUTE, KC_MPLY, KC_VOLU, 
		_______, _______, _______, _______, ADJUST,  _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT   
    ),
//ADJUST
    [3] = LAYOUT_ortho(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI,  RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,	RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_SAI
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
	[4] = LAYOUT_ortho(
/*,-----------------------------------------------------------------------------------------------------------------------.
 *|      |   1    |    2   |    3   |   4    |   5    |   6   |   7          |     8     |    9         |   0    |        |*/ 
  _______, _______, _______, _______, _______, _______,_______, KC_P7        , S(KC_UP)  , KC_P9        , _______, _______,_______, _______,
  _______, _______, _______, _______, KC_LGUI, _______,_______, C(S(KC_LEFT)), KC_P5     , C(S(KC_RGHT)), _______, _______,_______, 
  _______, _______, _______, _______, _______, _______,_______, KC_P1        , S(KC_DOWN), KC_P3        , _______, _______,_______, 
  _______, _______, _______, _______, _______, _______,_______, _______      , _______   , _______      , _______, _______,_______, _______
  ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
