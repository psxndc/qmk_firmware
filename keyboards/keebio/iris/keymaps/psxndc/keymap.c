#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

#define _COLEMAKDH 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define SCLOWER LM(_LOWER, MOD_LSFT | MOD_LCTL)

enum custom_keycodes {
  COLEMAKDH = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
*/
/*
  [_COLEMAKDH] = LAYOUT(
  
     
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  , KC_Q   , KC_W   , KC_F   ,  KC_P  ,  KC_B  ,                            KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_SCLN,     
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  , KC_A   , KC_R   , KC_S   ,  KC_T  ,  KC_G  ,                            KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_ENT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO , KC_Z   , KC_X   , KC_C   ,  KC_D  ,  KC_V  ,   						   KC_M   , KC_H   , KC_COMM, KC_DOT , KC_UP  , KC_RSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE , KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC,  KC_DEL, KC_SPC,           KC_SPC , KC_HOME, KC_SLSH, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_APP  , LOWER  , KC_SPC ,                   KC_SPC ,  RAISE , KC_UNDS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
*/

[_COLEMAKDH] = LAYOUT(
  
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                       							 ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          					   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
<<<<<<< HEAD
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 LCTL_T(KC_BSPC),KC_A,  KC_R,    KC_S,    KC_T,    KC_G,                               KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    RALT_T(KC_SCLN),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, 	KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_DEL,          KC_ENT, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI , LOWER  , KC_SPC ,                   KC_SPC ,  RAISE , KC_RCTL 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
=======
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         							 ├────────┼────────┼────────┼────────┼────────┼────────┤
 LSFT_T(KC_TAB), KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          						├────────┼────────┼────────┼────────┼────────┼────────┤
 LCTL_T(KC_BSPC),KC_A,  KC_R,    KC_S,    KC_T,    KC_G,                               KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    RALT_T(KC_SCLN),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        							┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, 	KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_SPC, 			KC_SPC, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘       								 └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    SCLOWER , LOWER  , KC_SPC ,                   KC_SPC ,  RAISE , KC_RGUI
                                // └────────┴────────┴────────┘                			 └────────┴────────┴────────┘
>>>>>>> a355dd1b273e73e2083cfc88913bf371177dcbac
  ),

// pick back up here
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_F11,  KC_F12,  _______, _______, _______,                            KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,   KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS,                            KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______,         _______ , _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______,  _______,                  _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,         _______ , KC_CIRC, KC_AMPR, KC_ASTR, KC_RPRN, KC_LPRN, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,  _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),







  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, BL_STEP, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


void encoder_update_user(uint8_t index, bool clockwise) {
    if(IS_LAYER_ON(_RAISE)) {
		if (clockwise) {
		  tap_code(KC_VOLD);
	    } else {
		  tap_code(KC_VOLU);
	    }
	} else if (IS_LAYER_ON(_LOWER)){
		if (clockwise) {
		  tap_code(KC_MPRV);
		} else {
		  tap_code(KC_MNXT);
		}		
	} else {
      if (clockwise) {
		tap_code(KC_PGUP);
	  } else {
		tap_code(KC_PGDN);
	    }
	}
} 

	  


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAKDH);
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
 /*   case ADJUST:
         if (record->event.pressed) {
 		    rgblight_sethsv(HSV_RED);  
		    layer_on(_ADJUST);
	     } else {
            layer_off(_ADJUST);
         }
         return false;
         break;
*/
  }
  return true;
}
