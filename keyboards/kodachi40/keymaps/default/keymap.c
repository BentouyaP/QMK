#include "kodachi40.h"
#include "action_layer.h"

//Ver.1.5 Update
extern keymap_config_t keymap_config;

// Layer 
#define _DEFAULT 0
#define _NUMPAD 1
#define _LOWER 2
#define _RAISE 3
#define _FUNCTION 4
#define _ADJUST 16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//CustomKey
//#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
//#define CTL_ENT CTL_T(KC_ENT)  // Tap for Enter, hold for Control
//#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
//#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
//#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
//#define SFT_DEL SFT_T(KC_DEL)  // Tap for Delete, hold for Shift
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)

//LayerChangeMod
//#define ENT_LW LT(_LOWER,KC_ENT)  	// Tap for Enter, hold for LOWER
//#define SPC_LW LT(_LOWER,KC_SPC)  	// Tap for Space, hold for LOWER
//#define BSP_LW LT(_LOWER,KC_BSPC)  	// Tap for Backspace, hold for LOWER
//#define ENT_RS LT(_RAISE,KC_ENT)  	// Tap for Enter, hold for RAISE
//#define SPC_RS LT(_RAISE,KC_SPC)  	// Tap for Space, hold for RAISE
//#define BSP_RS LT(_RAISE,KC_BSPC)  	// Tap for Backspace, hold for RAISE
#define ESC_FN LT(_FUNCTION,KC_ESC)  	// Tap for Escape, hold for FUNCTION
//#define ENT_FN LT(_FUNCTION,KC_ENT)  	// Tap for Enter, hold for FUNCTION
//#define FNC MO(_FUNCTION)  		// Hold for FUNCTION


enum layer_keycodes {
	DEFAULT = SAFE_RANGE,
	NUMPAD,// Toggle for NUMPAD(Numpad Mode)
	LOWER, 
	RAISE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


	/* Default Layer
	* .-------------------------------------------------------------------------.
	* | TAB   | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | \|  |
	* |-------------------------------------------------------------------------|
	* |ESC/FN| A   | S   | D   | F   | G   |xx| H   | J   | K   | L   |  ENTER  |
	* |-------------------------------------------------------------------------|
	* |LSFT | Z   | X   | C   | V   | B   | DEL | N   | M   | ,<  | ,<  |RSHIFT |
	* |-------------------------------------------------------------------------|
	* |LCTRL |LGUI |LALT  |LOWER|   SPACE    | BACKSPACE | RAISE | RALT  | RCTL |
 	* '-------------------------------------------------------------------------'
 	*/
	[_DEFAULT] = KEYMAP(
		HPR_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, 
		ESC_FN, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, 
		KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_BSPC, RAISE, KC_RALT, KC_RCTL),

	/* Lower Layer
	 * .-------------------------------------------------------------------------.
	 * |       | !   | @   | #   | $   | %   | ^   | &   | *   | (   | )   |     |
	 * |-------------------------------------------------------------------------|
	 * |      |  `  |  \ |  -  |  =  |  [   |xx|  ]  |  ;  | '   |  /  |         |
	 * |-------------------------------------------------------------------------|
	 * |     |  ~  |  | |  _  |  +  |  {  |M(0) | }   | :   | "   |  ?   |       |
	 * |-------------------------------------------------------------------------|
	 * |NumPad|     |     |      |             |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	//M(0) //Ctrl + Alt + Delete
	[_LOWER] = KEYMAP(
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
		_______, KC_GRV, KC_BSLS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_SLSH, _______, 
		_______, KC_TILD, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, M(0), KC_RCBR, KC_COLN, KC_DQT, KC_QUES, _______, 
		NUMPAD, _______, _______, _______, _______, _______, _______, _______, _______),

	/* Raise Layer
	 * .-------------------------------------------------------------------------.
	 * |       | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   |     |
	 * |-------------------------------------------------------------------------|
	 * |      |SCRLK|PAUSE| F1  | F2  | F3  |xx| F4  | F5  | F6  |     |         |
	 * |-------------------------------------------------------------------------|
	 * |     |Caps |MENU | F7  | F8  | F9  |M(0) | F10 | F11 | F12 |     |       |
 	 * |-------------------------------------------------------------------------|
	 * |NumPad|     |     |      |             |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	//M(0) //Ctrl + Alt + Delete
	[_RAISE] = KEYMAP(
		_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, 
		_______, KC_SLCK, KC_PAUS, KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6, _______, _______, 
		_______, KC_CAPS, KC_APP,  KC_F7,   KC_F8,   KC_F9, M(0), KC_F10,  KC_F11,  KC_F12, _______, _______, 
		NUMPAD, _______, _______, _______, _______, _______, _______, _______, _______),

	/* Fnction Layer
	 * .-------------------------------------------------------------------------.
	 * |       | PGUP| UP  | PGDN| BS  | HOME|INS  | PGUP| UP  | PGDN|PRTSC|     |
	 * |-------------------------------------------------------------------------|
	 * |      | LEFT| DOWN|RIGHT| DEL | END |xx| HOME| LEFT| DOWN|RIGHT|   END   |
	 * |-------------------------------------------------------------------------|
	 * |     | Vol+| Mute| Vol-|     |     |     |     |Play |Prev |Next |       |
 	 * |-------------------------------------------------------------------------|
	 * |      |     |     |      |             |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_FUNCTION] = KEYMAP(
		_______, KC_PGUP, KC_UP, KC_PGDN, KC_BSPC, KC_HOME, KC_INS, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, _______, 
		_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, 
		_______, KC_VOLU, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______),

	/* Numpad Layer
	 * .-------------------------------------------------------------------------.
	 * |Default|     | UP  |     | ESC |     | P7  | P8  | P9  |  /  | TAB | BS  |
	 * |-------------------------------------------------------------------------|
	 * |      |LEFT | DOWN|RIGHT| NLCK|     |xx| P4  | P5  | P6  |  *  |  ENTER  |
	 * |-------------------------------------------------------------------------|
	 * |     |     |     |     |     |     |     | P1  | P2  | P3  |  -  |  =    |
 	 * |-------------------------------------------------------------------------|
	 * |      |     |     |      |             |     P0     |  .   |  +   |  ,   |
	 * '-------------------------------------------------------------------------'
	 */
	[_NUMPAD] = KEYMAP(
		DEFAULT, XXXXXXX, KC_UP, XXXXXXX, KC_ESC, XXXXXXX, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_TAB, KC_BSPC,
		XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_NLCK, XXXXXXX, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PENT, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PEQL,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0, KC_PDOT, KC_PPLS, KC_PCMM),

	/* Adjust Layer (Lower + Raise)
	 * .-------------------------------------------------------------------------.
	 * | RGBtog|RGBmod|RGBhui|RGBvai|RGBsai|     |BLtog|BL up|     |     |   |   |
	 * |-------------------------------------------------------------------------|
	 * |      |RGBrmd|RGBhud|RGBvad|RGBsad|     |xx|     |BL dn|     |     |     |
	 * |-------------------------------------------------------------------------|
	 * |     |     |     |     |     |     |RESET|     |     |     |     |       |
 	 * |-------------------------------------------------------------------------|
	 * |      |     |     |      |             |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_ADJUST] = KEYMAP(
		RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, _______, BL_TOGG, BL_INC, _______, _______, _______, _______, 
		_______, RGB_RMOD,RGB_HUD, RGB_VAD, RGB_SAD, _______, _______, BL_DEC, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, RESET, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0: //M(0) //Ctrl + Alt + Delete
        if (record->event.pressed) {// on keydown
            return MACRO(D(LCTL), D(LALT), T(DEL), U(LALT), U(LCTL), END);
        }
        break;
    }
    return MACRO_NONE;
}
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {// on keydown
         persistent_default_layer_set(1UL<<_DEFAULT);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {// on keydown
         persistent_default_layer_set(1UL<<_NUMPAD);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {// on keydown
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {// on keyup
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {// on keydown
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {// on keyup
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

