/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
  GG = SAFE_RANGE,
  GRTHEALS,
  GLHF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_ENTER     , GLHF            , KC_MPLY,
        GG           , GRTHEALS        , RGB_MOD,
        LT(1, KC_TAB), LT(2, KC_ENTER) , RGB_TOG
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RESET  , KC_END,  KC_STOP,
        AU_TOG , BL_STEP, RGB_MOD,
        _______, KC_MPRV ,KC_MNXT
    ),
	
	[2] = LAYOUT(
        RESET  , RGB_HUI,  KC_STOP,
        RGB_SAI, RGB_HUD,  RGB_VAI,
        RGB_SAD, _______ , RGB_VAD
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code(KC_TAB);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

#ifdef AUDIO_ENABLE
float tone_home[][2] = SONG(QWERTY_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_HOME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_home);
        #endif
      }
      return false;
      break;
	case GG:
      if (record->event.pressed) {
        // when keycode GG is pressed
        SEND_STRING(SS_TAP(X_ENTER));
		_delay_ms(500);
		SEND_STRING("GG all. Well played!");
      } else {
        // when keycode GG is released
      } 
	  return false;
      break;
    case GRTHEALS:
      if (record->event.pressed) {
        // when keycode GRTHEALS is pressed
        SEND_STRING(SS_TAP(X_ENTER));
		_delay_ms(500);
		SEND_STRING("Thnx for the heals!");
      } else {
        // when keycode GRTHEALS is released
      }
	  return false;
      break;
	case GLHF:
      if (record->event.pressed) {
        // when keycode GLHF is pressed
        SEND_STRING(SS_TAP(X_ENTER));
		_delay_ms(500);
		SEND_STRING("Good luck and have fun!");
      } else {
        // when keycode GLHF is released
      } 
	  return false;
      break;
  }
  return true;
}