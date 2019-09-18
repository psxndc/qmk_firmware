#include QMK_KEYBOARD_H
#define _COLEMAKDH 0
#define _QWERTY 1
#define _FUNCTION 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
		
		[_COLEMAKDH] = LAYOUT_65_ansi( // colemak dh
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,   KC_HOME,\
		    KC_TAB,        KC_Q,     KC_W,      KC_F,  KC_P,  KC_B,  KC_J,    KC_L,  KC_U,    KC_Y,     KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_BSLASH, KC_END,\
			KC_BSPC,         KC_A,     KC_R,     KC_S,  KC_T,  KC_G,  KC_K,    KC_N,  KC_E,    KC_I,     KC_O,     KC_SCLN,           KC_ENT,    KC_PSCR,\
		    KC_LSPO,           KC_X,     KC_C,     KC_D,  KC_V,  KC_Z,  KC_M,    KC_H,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSPC,         KC_UP,     KC_DEL,\
		    KC_LCTL,      KC_LGUI, KC_LALT,                KC_SPC,                      KC_RALT, MO(_FUNCTION),     KC_RCTL,  KC_LEFT,KC_DOWN,   KC_RIGHT),
		
	
		/* QWERTY
		**	All we want to change when we switch to this layer is the alphas. 
		**	Since _COLEMAKDH is still on, and this is layered on top of it, 
		** 	we can make all the modifiers KC_TRANS for consistency.
		** 
		**	TODO: figure out the set_persistent_default function
		*/		
		[_QWERTY] = LAYOUT_65_ansi( // QWERTY 
			_______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,   _______,  _______,\
		    _______,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     _______,  _______,   _______,  _______,\
			_______,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           _______,  _______,\
		    _______,     KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,          _______,  _______,\
		    _______,  _______,  _______,                   _______,                   _______, _______,  _______,  _______,            _______,  _______),

					
		[_FUNCTION] = LAYOUT_65_ansi( /* FN */
			TO(_COLEMAKDH),   KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,    KC_DEL,   KC_PGUP,\
		    TO(_QWERTY),        RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI , _______, _______, _______, _______, KC_PSCR, KC_SLCK,  KC_PAUS, _______,KC_PGDN,\
			CTL_T(KC_CAPS),      RGB_SPI,  RGB_SPD, RGB_HUD,RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______,  _______,         EEP_RST,  RESET,\
		    KC_LSFT,              _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,        KC_VOLU,  KC_MUTE,\
		    _______,       _______,  _______,                  _______,                   _______, _______, _______,                 KC_MPRV,KC_VOLD,  KC_MNXT),
		
	

};

void rgb_matrix_indicators_user(void)
{
	    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
	    {
	      rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
	    }
}

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	  return true;
}