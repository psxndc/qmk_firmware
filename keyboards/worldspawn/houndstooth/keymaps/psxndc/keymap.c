#include QMK_KEYBOARD_H

#define SCLOWER LM(1, MOD_LCTL | MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	[0] = LAYOUT(  //QWERTY
		KC_TAB,  KC_Q,   KC_W,     KC_E,  KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC,  KC_A,   KC_S,     KC_D,  KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z,   KC_X,     KC_C,  KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
	*/
	
	
/* ColemakDH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   '  |  ;   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |  Up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower | Lower/Space | Raise/Space |Raise | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
	[0] = LAYOUT( //COLEMAK DH
	 LSFT_T(KC_TAB),   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,           KC_J,          KC_L,  KC_U,    KC_Y,    KC_QUOT, KC_BSPC, \
     LCTL_T(KC_BSPC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,           KC_K,          KC_N,  KC_E,    KC_I,    KC_O,    KC_SCLN, \
     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,           KC_M,          KC_H,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
     KC_LCTL,          KC_LGUI, KC_LALT, SCLOWER, MO(1),   KC_SPC,         KC_SPC,        MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT   \
	),	
		

	[1] = LAYOUT(
	   KC_TILD, KC_F11,  KC_F12,  _______, _______, _______, KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_DEL, \
       KC_DEL,  KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PIPE, \
       _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_UNDS, KC_EQL,  _______, KC_P1,   KC_P2,   KC_P3,   KC_BSLS, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
	),		

	[2] = LAYOUT(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,  \
		KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,  \
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MUTE, KC_MPLY, _______,  \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT   \
	),
};


