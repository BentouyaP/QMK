#include "kodachi40.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

// Layer 
#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCTION 3
#define _NUMPAD 4
#define _ADJUST 16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

// Custom
#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define CTL_ENT CTL_T(KC_ENT)  // Tap for Enter, hold for Control
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define SFT_DEL SFT_T(KC_DEL)  // Tap for Delete, hold for Shift
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)

//LayerChangeMod
#define ENT_LW LT(_LOWER,KC_ENT)  	// Tap for Enter, hold for LOWER
#define SPC_LW LT(_LOWER,KC_SPC)  	// Tap for Space, hold for LOWER
#define BSP_LW LT(_LOWER,KC_BSPC)  	// Tap for Backspace, hold for LOWER
#define ENT_RS LT(_RAISE,KC_ENT)  	// Tap for Enter, hold for RAISE
#define SPC_RS LT(_RAISE,KC_SPC)  	// Tap for Space, hold for RAISE
#define BSP_RS LT(_RAISE,KC_BSPC)  	// Tap for Backspace, hold for RAISE
#define ESC_FN LT(_FUNCTION,KC_ESC)  	// Tap for Escape, hold for FUNCTION
#define ENT_FN LT(_FUNCTION,KC_ENT)  	// Tap for Enter, hold for FUNCTION
#define ADJT MO(_ADJUST)  		// Hold for ADJUST
#define FNCN MO(_FUNCTION)  		// Hold for FUNCTION
#define NMPD TG(_NUMPAD)  		// Toggle for NUMPAD(Numpad Mode)
#define DFLT TG(_DEFAULT) 		// Toggle for DEFAULT(Normal Mode)


enum layer_keycodes {
	DEFAULT = SAFE_RANGE, 
	LOWER, 
	RAISE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


	/* Default Layer
	* .-------------------------------------------------------------------------.
	* |TAB    | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | BS  |
	* |-------------------------------------------------------------------------|
	* |LCTRL | A   | S   | D   | F   | G   |xx| H   | J   | K   | L   |ENTER/FN |
	* |-------------------------------------------------------------------------|
	* |LSFT | Z   | X   | C   | V   | B   | DEL | N   | M   | ,<  | ,<  |RSHIFT |
	* |-------------------------------------------------------------------------|
	* |ESC/FN|LGUI |MENU  |LALT | ENTER/LOWER | SPACE/RAISE | RALT |RGUI |RCTRL |
 	* '-------------------------------------------------------------------------'
 	*/
	[_DEFAULT] = KEYMAP(
		HPR_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, ENT_FN, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, 
		ESC_FN, KC_LGUI, KC_APP, KC_LALT, ENT_LW, SPC_RS, KC_RALT, KC_RGUI, KC_RCTL),

	/* Lower Layer
	 * .-------------------------------------------------------------------------.
	 * | ~     | !   | @   | #   | $   | %   | ^   | &   | *   | (   | )   | DEL |
	 * |-------------------------------------------------------------------------|
	 * |      |     |  \ |  -  |  =  |  [   |xx|  ]  |  ;  | '   |  /  |         |
	 * |-------------------------------------------------------------------------|
	 * |     |     |  | |  _  |  +  |  {  |     | }   | :   | "   |  ?   |       |
	 * |-------------------------------------------------------------------------|
	 * |NumPad|     |     |      |             |  ADJUST    |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_LOWER] = KEYMAP(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
		_______, _______, KC_BSLS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_SLSH, _______, 
		_______, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, _______, KC_RCBR, KC_COLN, KC_DQT, KC_QUES, _______, 
		NMPD, _______, _______, _______, _______, ADJT, _______, _______, _______),

	/* Raise Layer
	 * .-------------------------------------------------------------------------.
	 * | `     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | DEL |
	 * |-------------------------------------------------------------------------|
	 * |      |     |     | F1  | F2  | F3  |xx| F4  | F5  | F6  |     |         |
	 * |-------------------------------------------------------------------------|
	 * |     |     |     | F7  | F8  | F9  |     | F10 | F11 | F12 |     |       |
 	 * |-------------------------------------------------------------------------|
	 * |NumPad|     |     |      |    ADJUST   |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_RAISE] = KEYMAP(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, 
		_______, _______, _______, KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6, _______, _______, 
		_______, _______, _______, KC_F7,   KC_F8,   KC_F9, _______, KC_F10,  KC_F11,  KC_F12, _______, _______, 
		NMPD, _______, _______, _______, ADJT, _______, _______, _______, _______),

	/* Fnction Layer
	 * .-------------------------------------------------------------------------.
	 * |       | PGUP| UP  | PGDN| BS  | HOME|     | PGUP| UP  | PGDN|PRTSC| DEL |
	 * |-------------------------------------------------------------------------|
	 * |      | LEFT| DOWN|RIGHT| DEL | END |xx| HOME| LEFT| DOWN|RIGHT|         |
	 * |-------------------------------------------------------------------------|
	 * |     | Vol+| Mute| Vol-|     |     |     | END |Play |Prev |Next |       |
 	 * |-------------------------------------------------------------------------|
	 * |      |     |     |      |             |            |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_FUNCTION] = KEYMAP(
		_______, KC_PGUP, KC_UP, KC_PGDN, KC_BSPC, KC_HOME, _______, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_DEL, 
		_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, 
		_______, KC_VOLU, KC_MUTE, KC_VOLD, _______, _______, _______, KC_END, KC_MPLY, KC_MPRV, KC_MNXT, _______, 
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
		NMPD, _______, KC_UP, _______, KC_ESC, _______, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_TAB, KC_BSPC,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NLCK, _______, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PENT, 
		_______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PEQL,
		_______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PPLS, KC_PCMM),

	/* Adjust Layer
	 * .-------------------------------------------------------------------------.
	 * | RST   |     |PRTSC|SCRLK|PAUSE|     |RGBtog|RGBhud|RGBvad|RGBsad|   |   |
	 * |-------------------------------------------------------------------------|
	 * |      |     |Caps |INS  |     |     |xx|RGBmod|RGBhui|RGBvai|RGBsai|     |
	 * |-------------------------------------------------------------------------|
	 * |     |     |     |     |     |     |     |     |     |     |     |       |
 	 * |-------------------------------------------------------------------------|
	 * |      |     |     |      |    LOWER    |   RAISE    |      |      |      |
	 * '-------------------------------------------------------------------------'
	 */
	[_ADJUST] = KEYMAP(
		RESET, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, RGB_TOG, RGB_HUD, RGB_VAD, RGB_SAD, _______, _______, 
		_______, _______, KC_CAPS, KC_INS, _______, _______, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______)

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
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
  }
  return true;
}

